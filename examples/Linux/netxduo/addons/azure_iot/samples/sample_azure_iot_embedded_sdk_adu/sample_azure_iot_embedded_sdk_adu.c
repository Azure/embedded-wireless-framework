/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

#include <stdio.h>

#include "azure/core/az_json.h"
#include "nx_api.h"
#include "nx_azure_iot_hub_client.h"
#include "nx_azure_iot_provisioning_client.h"

/* These are sample files, user can build their own certificate and ciphersuites.  */
#include "nx_azure_iot_cert.h"
#include "nx_azure_iot_ciphersuites.h"
#include "sample_config.h"
#include "nx_azure_iot_pnp_helpers.h"


#ifdef DISABLE_DEVICE_TWIN_SAMPLE
#error "Device Twin feature must be enabled for ADU.  "
#endif /* DISABLE_DEVICE_TWIN_SAMPLE */

/* Define Azure RTOS TLS info.  */
static NX_SECURE_X509_CERT root_ca_cert;
static UCHAR nx_azure_iot_tls_metadata_buffer[NX_AZURE_IOT_TLS_METADATA_BUFFER_SIZE];
static ULONG nx_azure_iot_thread_stack[NX_AZURE_IOT_STACK_SIZE / sizeof(ULONG)];

/* Define the prototypes for AZ IoT.  */
static NX_AZURE_IOT             nx_azure_iot;
static NX_AZURE_IOT_HUB_CLIENT  iothub_client;

/* ADU model id.  */
static const CHAR sample_model_id[] = "dtmi:azureiot:AzureDeviceUpdateCore;1";
/* Twin desired properties.  */
static const CHAR desired_Orchestrator_Property_Name[] = "Orchestrator";
static const CHAR desired_Action_PropertyName[] = "Action";
static const CHAR desired_TargetVersion_PropertyName[] = "TargetVersion";
static const CHAR desired_Files_PropertyName[] = "Files";
static const CHAR desired_ExpectedContentId_PropertyName[] = "ExpectedContentId";
static const CHAR desired_InstalledCriteria_PropertyName[] = "InstalledCriteria";

/* Twin report properties.  */
static const CHAR report_Client_PropertyName[] = "Client";
static const CHAR report_ResultCode_PropertyName[] = "ResultCode";
static const CHAR report_ExtendedResultCode_PropertyName[] = "ExtendedResultCode";
static const CHAR report_State_PropertyName[] = "State";
static const CHAR report_InstalledContentId_PropertyName[] = "InstalledContentId";

static const CHAR temp_response_description_success[] = "success";
static const CHAR temp_response_description_failed[] = "failed";

#ifndef SAMPLE_ADU_FILE_HASH_SIZE
#define SAMPLE_ADU_FILE_HASH_SIZE               256
#endif /* SAMPLE_ADU_FILE_HASH_SIZE */

#ifndef SAMPLE_ADU_FILE_DOWNLOAD_URI_SIZE
#define SAMPLE_ADU_FILE_DOWNLOAD_URI_SIZE       256
#endif /* SAMPLE_ADU_FILE_DOWNLOAD_URI_SIZE */

#ifndef SAMPLE_ADU_EXPECTED_CONTENT_ID_SIZE
#define SAMPLE_ADU_EXPECTED_CONTENT_ID_SIZE     64
#endif /* SAMPLE_ADU_EXPECTED_CONTENT_ID_SIZE */

#ifndef SAMPLE_ADU_INSTALLED_CRITERIA_SIZE
#define SAMPLE_ADU_INSTALLED_CRITERIA_SIZE      64
#endif /* SAMPLE_ADU_INSTALLED_CRITERIA_SIZE */

typedef struct SAMPLE_ADU_ORCHESTRATOR_STRUCT
{

    /* Action.  */
    INT action;

    /* Target version.  */
    INT target_version;

    /* File hash.  */
    UCHAR file_hash[SAMPLE_ADU_FILE_HASH_SIZE];
    UINT file_hash_size;

    /* File download uri.  */
    UCHAR file_download_uri[SAMPLE_ADU_FILE_DOWNLOAD_URI_SIZE];
    UINT file_download_uri_size;

    /* Expected content id.  */
    UCHAR expected_content_id[SAMPLE_ADU_EXPECTED_CONTENT_ID_SIZE];
    UINT expected_content_id_size;

    /* Installed criteria.  */
    UCHAR installed_criteria[SAMPLE_ADU_INSTALLED_CRITERIA_SIZE];
    UINT installed_criteria_size;


    /* Response info.  */
    /* Status code.  */
    INT status_code;

    /* Version.  */
    UINT version;

    /* Description.  */
    const CHAR *description;

} SAMPLE_ADU_ORCHESTRATOR;

static SAMPLE_ADU_ORCHESTRATOR adu_orchestrator;

/* Buffer for appending/processing json data.  */
#ifndef SAMPLE_ADU_SCRATCH_BUFFER_SIZE
#define SAMPLE_ADU_SCRATCH_BUFFER_SIZE          1024
#endif /* SAMPLE_ADU_SCRATCH_BUFFER_SIZE */
static UCHAR scratch_buffer[SAMPLE_ADU_SCRATCH_BUFFER_SIZE];

VOID sample_entry(NX_IP *ip_ptr, NX_PACKET_POOL *pool_ptr, NX_DNS *dns_ptr, UINT (*unix_time_callback)(ULONG *unix_time));

static VOID printf_packet(NX_PACKET *packet_ptr)
{
    while (packet_ptr != NX_NULL)
    {
        printf("%.*s", (INT)(packet_ptr -> nx_packet_append_ptr - packet_ptr -> nx_packet_prepend_ptr),
               (CHAR *)packet_ptr -> nx_packet_prepend_ptr);
        packet_ptr = packet_ptr -> nx_packet_next;
    }
}

static VOID connection_status_callback(NX_AZURE_IOT_HUB_CLIENT *hub_client_ptr, UINT status)
{
    NX_PARAMETER_NOT_USED(hub_client_ptr);
    if (status)
    {
        printf("Disconnected from IoTHub!: error code = 0x%08x\r\n", status);
    }
    else
    {
        printf("Connected to IoTHub.\r\n");
    }
}

static UINT sample_initialize_iothub(NX_AZURE_IOT_HUB_CLIENT *iothub_client_ptr)
{
UINT status;
UCHAR *iothub_hostname = (UCHAR *)HOST_NAME;
UCHAR *iothub_device_id = (UCHAR *)DEVICE_ID;
UINT iothub_hostname_length = sizeof(HOST_NAME) - 1;
UINT iothub_device_id_length = sizeof(DEVICE_ID) - 1;


    /* Initialize IoTHub client.  */
    if ((status = nx_azure_iot_hub_client_initialize(iothub_client_ptr, &nx_azure_iot,
                                                     iothub_hostname, iothub_hostname_length,
                                                     iothub_device_id, iothub_device_id_length,
                                                     (UCHAR *)MODULE_ID, sizeof(MODULE_ID) - 1,
                                                     _nx_azure_iot_tls_supported_crypto,
                                                     _nx_azure_iot_tls_supported_crypto_size,
                                                     _nx_azure_iot_tls_ciphersuite_map,
                                                     _nx_azure_iot_tls_ciphersuite_map_size,
                                                     nx_azure_iot_tls_metadata_buffer,
                                                     sizeof(nx_azure_iot_tls_metadata_buffer),
                                                     &root_ca_cert)))
    {
        printf("Failed on nx_azure_iot_hub_client_initialize!: error code = 0x%08x\r\n", status);
        return(status);
    }

    /* Set symmetric key.  */
    if ((status = nx_azure_iot_hub_client_symmetric_key_set(iothub_client_ptr,
                                                            (UCHAR *)DEVICE_SYMMETRIC_KEY,
                                                            sizeof(DEVICE_SYMMETRIC_KEY) - 1)))
    {
        printf("Failed on nx_azure_iot_hub_client_symmetric_key_set!\r\n");
    }

    /* Set connection status callback.  */
    else if ((status = nx_azure_iot_hub_client_connection_status_callback_set(iothub_client_ptr,
                                                                              connection_status_callback)))
    {
        printf("Failed on connection_status_callback!\r\n");
    }
    else if ((status = nx_azure_iot_hub_client_device_twin_enable(iothub_client_ptr)))
    {
        printf("device twin enabled failed!: error code = 0x%08x\r\n", status);
    }

    else if ((status = nx_azure_iot_hub_client_model_id_set(iothub_client_ptr, (UCHAR *)sample_model_id, sizeof(sample_model_id) - 1)))
    {
        printf("digital twin modelId set!: error code = 0x%08x\r\n", status);
    }

    if (status)
    {
        nx_azure_iot_hub_client_deinitialize(iothub_client_ptr);
    }

    return(status);
}

static void log_callback(az_log_classification classification, UCHAR *msg, UINT msg_len)
{
    if (classification == AZ_LOG_IOT_AZURERTOS)
    {
        printf("%.*s", msg_len, (CHAR *)msg);
    }
}

static void sample_pnp_adu_client_object_send()
{
const CHAR content_id[] = "Inst-ContId-1234";
NX_AZURE_IOT_JSON_WRITER json_builder;
UINT response_status;
UINT request_id;
UINT status;
UINT payload_len;
ULONG reported_property_version;

    /* Client properties format:

        "Client": {
            "ResultCode": 0,
            "ExtendedResultCode": 123,
            "State": 4,
            "InstalledContentId": "Inst-ContId-1234"
        },

    */
    if (nx_azure_iot_json_writer_with_buffer_init(&json_builder, scratch_buffer, sizeof(scratch_buffer)))
    {
        printf("Failed to build client property!\r\n");
        return;
    }

    if (nx_azure_iot_json_writer_append_begin_object(&json_builder) ||
        nx_azure_iot_json_writer_append_property_name(&json_builder,
                                                      (UCHAR *)report_Client_PropertyName,
                                                      sizeof(report_Client_PropertyName) - 1) ||
        nx_azure_iot_json_writer_append_begin_object(&json_builder) ||
        nx_azure_iot_json_writer_append_property_with_int32_value(&json_builder,
                                                                  (UCHAR *)report_ResultCode_PropertyName,
                                                                  sizeof(report_ResultCode_PropertyName) - 1, 0) ||
        nx_azure_iot_json_writer_append_property_with_int32_value(&json_builder,
                                                                  (UCHAR *)report_ExtendedResultCode_PropertyName,
                                                                  sizeof(report_ExtendedResultCode_PropertyName) - 1, 123) ||
        nx_azure_iot_json_writer_append_property_with_int32_value(&json_builder,
                                                                  (UCHAR *)report_State_PropertyName,
                                                                  sizeof(report_State_PropertyName) - 1, 4) ||
        nx_azure_iot_json_writer_append_property_with_string_value(&json_builder,
                                                                   (UCHAR *)report_InstalledContentId_PropertyName,
                                                                   sizeof(report_InstalledContentId_PropertyName) - 1,
                                                                   (UCHAR *)content_id, sizeof(content_id) - 1) ||
        nx_azure_iot_json_writer_append_end_object(&json_builder) ||
        nx_azure_iot_json_writer_append_end_object(&json_builder))
    {
        printf("Failed to build client property!\r\n");
        nx_azure_iot_json_writer_deinit(&json_builder);
        return;
    }
    else
    {
        payload_len = nx_azure_iot_json_writer_get_bytes_used(&json_builder);
    }

    if ((status = nx_azure_iot_hub_client_device_twin_reported_properties_send(&iothub_client,
                                                                               scratch_buffer,
                                                                               payload_len,
                                                                               &request_id, &response_status,
                                                                               &reported_property_version,
                                                                               (5 * NX_IP_PERIODIC_RATE))))
    {
        printf("Failed to send client property\r\n");
        nx_azure_iot_json_writer_deinit(&json_builder);
        return;
    }

    nx_azure_iot_json_writer_deinit(&json_builder);

    if ((response_status < 200) || (response_status >= 300))
    {
        printf("Report client failed! response status = %d\r\n", response_status);
        return;
    }

    printf("Report client properties succeeded! Properties Data: %.*s\r\n", payload_len, scratch_buffer);
}

static UINT append_orchestrator_value(NX_AZURE_IOT_JSON_WRITER *json_writer_ptr, VOID *context)
{
    NX_PARAMETER_NOT_USED(context);

    if (nx_azure_iot_json_writer_append_begin_object(json_writer_ptr) ||
        nx_azure_iot_json_writer_append_property_with_int32_value(json_writer_ptr,
                                                                  (UCHAR *)desired_Action_PropertyName,
                                                                  sizeof(desired_Action_PropertyName) - 1,
                                                                  adu_orchestrator.action) ||
        nx_azure_iot_json_writer_append_property_with_int32_value(json_writer_ptr,
                                                                  (UCHAR *)desired_TargetVersion_PropertyName,
                                                                  sizeof(desired_TargetVersion_PropertyName) - 1,
                                                                  adu_orchestrator.target_version) ||
        nx_azure_iot_json_writer_append_property_name(json_writer_ptr,
                                                      (UCHAR *)desired_Files_PropertyName,
                                                      sizeof(desired_Files_PropertyName) - 1) ||
        nx_azure_iot_json_writer_append_begin_object(json_writer_ptr) ||
        nx_azure_iot_json_writer_append_property_with_string_value(json_writer_ptr,
                                                                   adu_orchestrator.file_hash,
                                                                   adu_orchestrator.file_hash_size,
                                                                   adu_orchestrator.file_download_uri,
                                                                   adu_orchestrator.file_download_uri_size) ||
        nx_azure_iot_json_writer_append_end_object(json_writer_ptr) ||
        nx_azure_iot_json_writer_append_property_with_string_value(json_writer_ptr,
                                                                   (UCHAR *)desired_ExpectedContentId_PropertyName,
                                                                   sizeof(desired_ExpectedContentId_PropertyName) - 1,
                                                                   adu_orchestrator.expected_content_id,
                                                                   adu_orchestrator.expected_content_id_size) ||
        nx_azure_iot_json_writer_append_property_with_string_value(json_writer_ptr,
                                                                   (UCHAR *)desired_InstalledCriteria_PropertyName,
                                                                   sizeof(desired_InstalledCriteria_PropertyName) - 1,
                                                                   adu_orchestrator.installed_criteria,
                                                                   adu_orchestrator.installed_criteria_size) ||
        nx_azure_iot_json_writer_append_end_object(json_writer_ptr))
    {
        return(NX_NOT_SUCCESSFUL);
    }

    return(NX_AZURE_IOT_SUCCESS);
}

static UINT visit_files_object(NX_AZURE_IOT_JSON_READER *property_value_reader_ptr)
{
    while (nx_azure_iot_json_reader_next_token(property_value_reader_ptr) == NX_AZURE_IOT_SUCCESS)
    {
        if (nx_azure_iot_json_reader_token_type(property_value_reader_ptr) ==
                NX_AZURE_IOT_READER_TOKEN_PROPERTY_NAME)
        {

            /* FileHash.  */
            if (nx_azure_iot_json_reader_token_string_get(property_value_reader_ptr,
                                                          adu_orchestrator.file_hash,
                                                          sizeof(adu_orchestrator.file_hash),
                                                          &adu_orchestrator.file_hash_size))
            {
                return(NX_NOT_SUCCESSFUL);
            }

            /* Get file download URI.  */
            if (nx_azure_iot_json_reader_next_token(property_value_reader_ptr) ||
                nx_azure_iot_json_reader_token_string_get(property_value_reader_ptr,
                                                          (UCHAR *)adu_orchestrator.file_download_uri,
                                                          sizeof(adu_orchestrator.file_download_uri),
                                                          &adu_orchestrator.file_download_uri_size))
            {
                return(NX_NOT_SUCCESSFUL);
            }
        }
        else if (nx_azure_iot_json_reader_token_type(property_value_reader_ptr) ==
                    NX_AZURE_IOT_READER_TOKEN_BEGIN_OBJECT)
        {
            if (nx_azure_iot_json_reader_skip_children(property_value_reader_ptr))
            {
                return(NX_NOT_SUCCESSFUL);
            }
        }
        else if (nx_azure_iot_json_reader_token_type(property_value_reader_ptr) ==
                    NX_AZURE_IOT_READER_TOKEN_END_OBJECT)
        {
            break;
        }
    }

    return(NX_AZURE_IOT_SUCCESS);
}

static VOID sample_pnp_adu_orchestrator_update(UCHAR *component_name_ptr, UINT component_name_len,
                                               UCHAR *property_name_ptr, UINT property_name_len,
                                               NX_AZURE_IOT_JSON_READER property_value_reader, UINT version,
                                               VOID *userContextCallback)
{
UINT status = NX_AZURE_IOT_SUCCESS;

    /* Orchestrator properties format:

        "Orchestrator": {
            "Action": 1,
            "TargetVersion": 2,
            "Files": {
                "FileHash": "DownloadUri"
            },
        "ExpectedContentId": "expected-content-1",
        "InstalledCriteria": "installed-criteria-1"
        },

    */

    NX_PARAMETER_NOT_USED(userContextCallback);

    /* Default component is only valid.  */
    if (component_name_ptr != NX_NULL || component_name_len != 0)
    {
        return;
    }

    /* Orchestrator.  */
    if ((property_name_len == sizeof(desired_Orchestrator_Property_Name) - 1) &&
        memcmp((VOID *)desired_Orchestrator_Property_Name, (VOID *)property_name_ptr, property_name_len) == 0)
    {
        /* Update version.  */
        adu_orchestrator.version = version;

        while (nx_azure_iot_json_reader_next_token(&property_value_reader) == NX_AZURE_IOT_SUCCESS)
        {
            if (nx_azure_iot_json_reader_token_type(&property_value_reader) ==
                    NX_AZURE_IOT_READER_TOKEN_PROPERTY_NAME)
            {

                /* Action.  */
                if (nx_azure_iot_json_reader_token_is_text_equal(&property_value_reader,
                                                                 (UCHAR *)desired_Action_PropertyName,
                                                                 sizeof(desired_Action_PropertyName) - 1))
                {

                    /* Get action data.  */
                    if (nx_azure_iot_json_reader_next_token(&property_value_reader) ||
                        nx_azure_iot_json_reader_token_int32_get(&property_value_reader, &adu_orchestrator.action))
                    {
                        status = NX_NOT_SUCCESSFUL;
                        break;
                    }
                }

                /* TargetVersion.  */
                else if (nx_azure_iot_json_reader_token_is_text_equal(&property_value_reader,
                                                                      (UCHAR *)desired_TargetVersion_PropertyName,
                                                                      sizeof(desired_TargetVersion_PropertyName) - 1))
                {

                    /* Get target version.  */
                    if (nx_azure_iot_json_reader_next_token(&property_value_reader) ||
                        nx_azure_iot_json_reader_token_int32_get(&property_value_reader, &adu_orchestrator.target_version))
                    {
                        status = NX_NOT_SUCCESSFUL;
                        break;
                    }
                }

                /* Files.  */
                else if (nx_azure_iot_json_reader_token_is_text_equal(&property_value_reader,
                                                                      (UCHAR *)desired_Files_PropertyName,
                                                                      sizeof(desired_Files_PropertyName) - 1))
                {

                    /* Get filehash and download uri.  */
                    if (nx_azure_iot_json_reader_next_token(&property_value_reader) ||
                        visit_files_object(&property_value_reader))
                    {
                        status = NX_NOT_SUCCESSFUL;
                        break;
                    }
                }

                /* ExpectedContentId.  */
                else if (nx_azure_iot_json_reader_token_is_text_equal(&property_value_reader,
                                                                      (UCHAR *)desired_ExpectedContentId_PropertyName,
                                                                      sizeof(desired_ExpectedContentId_PropertyName) - 1))
                {

                    /* Get expected content id.  */
                    if (nx_azure_iot_json_reader_next_token(&property_value_reader) ||
                        nx_azure_iot_json_reader_token_string_get(&property_value_reader, adu_orchestrator.expected_content_id,
                                                                  sizeof(adu_orchestrator.expected_content_id),
                                                                  &adu_orchestrator.expected_content_id_size))
                    {
                        status = NX_NOT_SUCCESSFUL;
                        break;
                    }
                }

                /* InstalledCriteria.  */
                else if (nx_azure_iot_json_reader_token_is_text_equal(&property_value_reader,
                                                                      (UCHAR *)desired_InstalledCriteria_PropertyName,
                                                                      sizeof(desired_InstalledCriteria_PropertyName) - 1))
                {

                    /* Get installed criteris.  */
                    if (nx_azure_iot_json_reader_next_token(&property_value_reader) ||
                        nx_azure_iot_json_reader_token_string_get(&property_value_reader,
                                                                  (UCHAR *)adu_orchestrator.installed_criteria,
                                                                  sizeof(adu_orchestrator.installed_criteria),
                                                                  &adu_orchestrator.installed_criteria_size))
                    {
                        status = NX_NOT_SUCCESSFUL;
                        break;
                    }
                }

                /* Unknown property in value.  */
                else
                {
                    status = NX_NOT_SUCCESSFUL;
                    break;
                }
            }
            else if (nx_azure_iot_json_reader_token_type(&property_value_reader) ==
                        NX_AZURE_IOT_READER_TOKEN_BEGIN_OBJECT)
            {
                if (nx_azure_iot_json_reader_skip_children(&property_value_reader))
                {
                    status = NX_NOT_SUCCESSFUL;
                    break;
                }
            }
            else if (nx_azure_iot_json_reader_token_type(&property_value_reader) ==
                        NX_AZURE_IOT_READER_TOKEN_END_OBJECT)
            {
                break;
            }
        }

        if (status)
        {
            adu_orchestrator.status_code = 401;
            adu_orchestrator.description = temp_response_description_failed;
        }
    }
}

/* Listen for Orchestrator data.  */

static UINT sample_pnp_adu_orchestrator_listen()
{
UINT status;
NX_PACKET *packet_ptr;
UINT bytes_copied = 0;
UINT response_status;
UINT request_id;
NX_AZURE_IOT_JSON_READER json_reader;
NX_AZURE_IOT_JSON_WRITER json_writer;
ULONG reported_property_version;

    /* Receive desired properties.  */
    if ((status = nx_azure_iot_hub_client_device_twin_desired_properties_receive(&iothub_client, &packet_ptr,
                                                                                 NX_WAIT_FOREVER)))
    {
        printf("Receive desired property receive failed!: error code = 0x%08x\r\n", status);
        return(status);
    }

    printf("Receive desired property call: ");
    printf_packet(packet_ptr);
    printf("\r\n");

    /* Initialize.  */
    adu_orchestrator.status_code = 200;
    adu_orchestrator.description = temp_response_description_success;

    if ((status = nx_azure_iot_json_reader_init(&json_reader, packet_ptr)))
    {
        printf("Failed to initialize json reader: error code = 0x%08x\r\n", status);
        nx_packet_release(packet_ptr);
    }
    /* Parse twin data.  */
    else
    {
        if ((status = (UINT)nx_azure_iot_pnp_helper_twin_data_parse(&json_reader, NX_TRUE,
                                                                    NX_NULL, 0,
                                                                    scratch_buffer, sizeof(scratch_buffer),
                                                                    sample_pnp_adu_orchestrator_update,
                                                                    NX_NULL)))
        {
            printf("Failed to parse twin data!: error code = 0x%08x\r\n", status);
        }

        nx_azure_iot_json_reader_deinit(&json_reader);
    }

    /* Output orchestrator info.  */
    printf("\r\nOrchestrator:\r\n");
    printf("Action: %d\r\n", adu_orchestrator.action);
    printf("TargetVersion: %d\r\n", adu_orchestrator.target_version);
    printf("FileHash: %s\r\n", adu_orchestrator.file_hash);
    printf("DownloadUri: %s\r\n", adu_orchestrator.file_download_uri);
    printf("ExpectedContentId: %s\r\n", adu_orchestrator.expected_content_id);
    printf("InstalledCriteria: %s\r\n\r\n", adu_orchestrator.installed_criteria);

    /* Build telemetry JSON payload.  */
    if ((status = nx_azure_iot_json_writer_with_buffer_init(&json_writer,
                                                            scratch_buffer,
                                                            sizeof(scratch_buffer))))
    {
        printf("Failed to create json writer\r\n");
        return(status);
    }

    /* Build orchestrator response.  */
    if ((status = nx_azure_iot_pnp_helper_build_reported_property_with_status(NX_NULL, 0,
                                                                              (UCHAR *)desired_Orchestrator_Property_Name,
                                                                              sizeof(desired_Orchestrator_Property_Name) - 1,
                                                                              append_orchestrator_value, (void *)&adu_orchestrator,
                                                                              adu_orchestrator.status_code,
                                                                              (UCHAR *)adu_orchestrator.description, strlen(adu_orchestrator.description),
                                                                              adu_orchestrator.version,
                                                                              &json_writer)))
    {
        printf("Failed to create orchestrator response\r\n");
        nx_azure_iot_json_writer_deinit(&json_writer);
        return (status);
    }

    bytes_copied = nx_azure_iot_json_writer_get_bytes_used(&json_writer);

    /* Send orchestrator response.  */
    if ((status = nx_azure_iot_hub_client_device_twin_reported_properties_send(&iothub_client,
                                                                               scratch_buffer,
                                                                               bytes_copied,
                                                                               &request_id, &response_status,
                                                                               &reported_property_version,
                                                                               (5 * NX_IP_PERIODIC_RATE))))
    {
        printf("Failed to send orchestrator response\r\n");
        nx_azure_iot_json_writer_deinit(&json_writer);
        return (status);
    }

    nx_azure_iot_json_writer_deinit(&json_writer);

    if ((response_status < 200) || (response_status >= 300))
    {
        printf("Report orchestrator response failed! response status = %d\r\n", response_status);
        return (NX_NOT_SUCCESSFUL);
    }

    /* Action: Download, Install and Apply.  */

    return(NX_AZURE_IOT_SUCCESS);
}

void sample_entry(NX_IP *ip_ptr, NX_PACKET_POOL *pool_ptr, NX_DNS *dns_ptr, UINT (*unix_time_callback)(ULONG *unix_time))
{
UINT status = 0;
UINT loop = NX_TRUE;

    nx_azure_iot_log_init(log_callback);

    /* Create Azure IoT handler.  */
    if ((status = nx_azure_iot_create(&nx_azure_iot, (UCHAR *)"Azure IoT", ip_ptr, pool_ptr, dns_ptr,
                                      nx_azure_iot_thread_stack, sizeof(nx_azure_iot_thread_stack),
                                      NX_AZURE_IOT_THREAD_PRIORITY, unix_time_callback)))
    {
        printf("Failed on nx_azure_iot_create!: error code = 0x%08x\r\n", status);
        return;
    }

    /* Initialize CA certificate.  */
    if ((status = nx_secure_x509_certificate_initialize(&root_ca_cert, (UCHAR *)_nx_azure_iot_root_cert,
                                                        (USHORT)_nx_azure_iot_root_cert_size,
                                                        NX_NULL, 0, NULL, 0, NX_SECURE_X509_KEY_TYPE_NONE)))
    {
        printf("Failed to initialize ROOT CA certificate!: error code = 0x%08x\r\n", status);
        nx_azure_iot_delete(&nx_azure_iot);
        return;
    }

    if ((status = sample_initialize_iothub(&iothub_client)))
    {
        printf("Failed to initialize iothub client: error code = 0x%08x\r\n", status);
        nx_azure_iot_delete(&nx_azure_iot);
        return;
    }

    if (nx_azure_iot_hub_client_connect(&iothub_client, NX_TRUE, NX_WAIT_FOREVER))
    {
        printf("Failed on nx_azure_iot_hub_client_connect!\r\n");
        nx_azure_iot_hub_client_deinitialize(&iothub_client);
        nx_azure_iot_delete(&nx_azure_iot);
        return;
    }


    /* --------PnP ADU-------- */

    /* Send ADU "Client" object.  */
    sample_pnp_adu_client_object_send();

    /* Process ADU "Orchestrator" property updates.  */
    while (loop)
    {
        sample_pnp_adu_orchestrator_listen();
    }

    nx_azure_iot_hub_client_disconnect(&iothub_client);
    nx_azure_iot_hub_client_deinitialize(&iothub_client);
    nx_azure_iot_delete(&nx_azure_iot);
}

