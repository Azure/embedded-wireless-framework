/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel certificate provisioning example
 * @details EWF certificate provisioning example for all Quectel cellular modems with SSL/TLS support
 ****************************************************************************/

/**
 * @brief Certificate & Key header file include section
 * @details Include the certificate and key header files that will be
 * provisioned on the adapter/modem
 */
#include "root_ca_cert.pem.h"
#include "ca_cert.pem.h"
#include "device_cert.pem.h"
#include "device_key.pem.h"

#include "ewf_adapter_quectel_common.h"

ewf_result ewf_example_certs_basic_quectel_common(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_list(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to list the UFS, ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_delete(adapter_ptr,
        EWF_CONFIG_ADAPTER_QUECTEL_COMMON_ROOT_CA_CERTIFICATE_FILE_NAME)))
    {
        EWF_LOG("Failed to delete file, ewf_result %d.\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_delete(adapter_ptr,
        EWF_CONFIG_ADAPTER_QUECTEL_COMMON_USER_CA_CERTIFICATE_FILE_NAME)))
    {
        EWF_LOG("Failed to delete file, ewf_result %d.\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_delete(adapter_ptr,
        EWF_CONFIG_ADAPTER_QUECTEL_COMMON_CLIENT_CERTIFICATE_FILE_NAME)))
    {
        EWF_LOG("Failed to delete file, ewf_result %d.\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_delete(adapter_ptr,
        EWF_CONFIG_ADAPTER_QUECTEL_COMMON_CLIENT_PRIVATE_KEY_FILE_NAME)))
    {
        EWF_LOG("Failed to delete file, ewf_result %d.\n", result);
    }

    /**
     * @note This configuration is only for demo purposes. The application can always do both
     * or even add more CA certificates and decide between them for the required secure connection configuration.
     * Refer to the Telemetry demo for example usage of this configuration in the TLS basic start 
     */
#if defined(EWF_CONFIG_ADAPTER_QUECTEL_COMMON_ROOT_CA_CERTIFICATE_FILE_NAME) && defined(EWF_CONFIG_ADAPTER_QUECTEL_COMMON_ROOT_CA_CERTIFICATE_BUFFER_NAME)
    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_upload(adapter_ptr,
        EWF_CONFIG_ADAPTER_QUECTEL_COMMON_ROOT_CA_CERTIFICATE_FILE_NAME,
        (const uint8_t*) EWF_CONFIG_ADAPTER_QUECTEL_COMMON_ROOT_CA_CERTIFICATE_BUFFER_NAME,
        sizeof(EWF_CONFIG_ADAPTER_QUECTEL_COMMON_ROOT_CA_CERTIFICATE_BUFFER_NAME) -1 )))
    {
        EWF_LOG_ERROR("Failed to upload, ewf_result %d.\n", result);
        return result;
    }
#endif

#if defined(EWF_CONFIG_ADAPTER_QUECTEL_COMMON_USER_CA_CERTIFICATE_FILE_NAME) && defined(EWF_CONFIG_ADAPTER_QUECTEL_COMMON_ROOT_CA_CERTIFICATE_BUFFER_NAME)

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_upload(adapter_ptr,
        EWF_CONFIG_ADAPTER_QUECTEL_COMMON_USER_CA_CERTIFICATE_FILE_NAME,
        (const uint8_t*) EWF_CONFIG_ADAPTER_QUECTEL_COMMON_USER_CA_CERTIFICATE_BUFFER_NAME,
        sizeof(EWF_CONFIG_ADAPTER_QUECTEL_COMMON_USER_CA_CERTIFICATE_BUFFER_NAME) - 1)))
    {
        EWF_LOG_ERROR("Failed to upload, ewf_result %d.\n", result);
        return result;
    }
#endif

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_upload(adapter_ptr,
        EWF_CONFIG_ADAPTER_QUECTEL_COMMON_CLIENT_CERTIFICATE_FILE_NAME,
        (const uint8_t*) EWF_CONFIG_ADAPTER_QUECTEL_COMMON_CLIENT_CERTIFICATE_BUFFER_NAME,
        sizeof(EWF_CONFIG_ADAPTER_QUECTEL_COMMON_CLIENT_CERTIFICATE_BUFFER_NAME) - 1)))
    {
        EWF_LOG_ERROR("Failed to upload, ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_upload(adapter_ptr,
        EWF_CONFIG_ADAPTER_QUECTEL_COMMON_CLIENT_PRIVATE_KEY_FILE_NAME,
        (const uint8_t*)EWF_CONFIG_ADAPTER_QUECTEL_COMMON_CLIENT_PRIVATE_KEY_BUFFER_NAME,
        sizeof(EWF_CONFIG_ADAPTER_QUECTEL_COMMON_CLIENT_PRIVATE_KEY_BUFFER_NAME) - 1)))
    {
        EWF_LOG_ERROR("Failed to upload, ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_list(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to list the UFS, ewf_result %d.\n", result);
    }

    EWF_LOG("\nCompleted successfully!\n");

    return EWF_RESULT_OK;
}
