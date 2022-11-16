/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework basic telemetry to IoT Hub example
 * @details The Embedded Wireless Framework basic telemetry to IoT Hub example
 ****************************************************************************/

#include "azure/az_core.h"
#include "azure/az_iot.h"

#include "ewf_adapter.h"
#include "ewf_lib.h"
#include "ewf_platform.h"
#include "ewf_example.config.h"

#ifndef EWF_CONFIG_TELEMETRY_USERNAME_LENGTH
#define EWF_CONFIG_TELEMETRY_USERNAME_LENGTH        (256)
#endif

#ifndef EWF_CONFIG_TELEMETRY_CLIENT_ID_LENGTH
#define EWF_CONFIG_TELEMETRY_CLIENT_ID_LENGTH       (64)
#endif

#ifndef EWF_CONFIG_TELEMETRY_TOPIC_LENGTH
#define EWF_CONFIG_TELEMETRY_TOPIC_LENGTH           (256)
#endif

#ifndef EWF_CONFIG_TELEMETRY_LOOP_MINUTES
#define EWF_CONFIG_TELEMETRY_LOOP_MINUTES           (60)
#endif

/* Prototypes */
ewf_result ewf_example_telemetry_basic_with_message_callback(ewf_adapter* adapter_ptr, char* (*callback)());
ewf_result ewf_example_telemetry_basic(ewf_adapter* adapter_ptr);

/* Telemetry message callback */
static char* (*telemetry_message_callback)() = NULL;

/* Work buffers */
static char iot_hub_username_buffer[EWF_CONFIG_TELEMETRY_USERNAME_LENGTH];
static char iot_hub_client_id_buffer[EWF_CONFIG_TELEMETRY_CLIENT_ID_LENGTH];
static char telemetry_topic_buffer[EWF_CONFIG_TELEMETRY_TOPIC_LENGTH];

/* The IoT Hub client */
static az_iot_hub_client hub_client;

/* The MQTT message user sturcture*/
typedef struct _ewf_mqtt_receive_message {
    char ewf_mqtt_recv_topic[256];
    uint32_t ewf_mqtt_recv_topic_length;
    char ewf_mqtt_recv_message_buffer[1024];
    uint32_t ewf_mqtt_recv_message_length;
} ewf_mqtt_receive_message;

static ewf_mqtt_receive_message ewf_mqtt_recv_message = { 0 };

/* Message receive flag */
uint8_t ewf_mqtt_rx_flag = 0;

ewf_result ewf_mqtt_receive_message_user_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr);

/**
 * @brief The MQTT message user callback example
 * @description This user callback will provide MQTT topic and payload information if
 * provided by the adapter modem, else the information will be NULL. If the payload
 * in the callback is NULL,the application must use the ewf_adapter_mqtt_basic_message_get()
 * to get the payload associated with the Topic received. For eg. Topic and Payload
 * information is available for Quectel modems, while only Topic information is
 * available for Renesas/Sequans adapter modem.
 */
ewf_result ewf_mqtt_receive_message_user_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_mqtt_rx_flag++;

    ewf_mqtt_recv_message.ewf_mqtt_recv_topic_length = ewfl_str_length(topic_cstr);
    ewfl_str_n_cpy(ewf_mqtt_recv_message.ewf_mqtt_recv_topic, topic_cstr, ewf_mqtt_recv_message.ewf_mqtt_recv_topic_length);

    /* Not all modems will receive payload in the MQTT message URC.
     Some message will have to query the modem using the topic information to get the payload */
    if (payload_cstr)
    {
        ewf_mqtt_recv_message.ewf_mqtt_recv_message_length = ewfl_str_length(payload_cstr);
        ewfl_str_n_cpy(ewf_mqtt_recv_message.ewf_mqtt_recv_message_buffer, payload_cstr, ewf_mqtt_recv_message.ewf_mqtt_recv_message_length);
        EWF_LOG("[MQTT-Basic][Message callback:][TOPIC:][%s][Payload:][%s]\r\n", topic_cstr, payload_cstr);
        return EWF_RESULT_OK;
    }
    EWF_LOG("[MQTT-Basic][Message callback:][TOPIC:][%s]\r\n", topic_cstr);
    return EWF_RESULT_OK;


}

/**
 * @brief The telemetry basic example
 */
ewf_result ewf_example_telemetry_basic_with_message_callback(ewf_adapter* adapter_ptr, char* (*callback)())
{
    telemetry_message_callback = callback;

    return ewf_example_telemetry_basic(adapter_ptr);
}

/**
 * @brief The telemetry basic example
 */
ewf_result ewf_example_telemetry_basic(ewf_adapter* adapter_ptr)
{
    az_result result;
    ewf_result ewf_status;

    EWF_LOG("IoT hub hostname: %s\n", EWF_CONFIG_IOT_HUB_HOSTNAME);
    EWF_LOG("IoT hub device id: %s\n", EWF_CONFIG_IOT_HUB_DEVICEID);

    /* Initialize the hub client with the default connection options. */
    result = az_iot_hub_client_init(&hub_client, AZ_SPAN_FROM_STR(EWF_CONFIG_IOT_HUB_HOSTNAME), AZ_SPAN_FROM_STR(EWF_CONFIG_IOT_HUB_DEVICEID), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to initialize hub client: az_result %ld.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    /* Get the MQTT client ID used for the MQTT connection. */
    result = az_iot_hub_client_get_client_id(
        &hub_client, iot_hub_client_id_buffer, sizeof(iot_hub_client_id_buffer), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get MQTT client ID: az_result %ld.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    EWF_LOG("IoT Hub client ID: %s\n", iot_hub_client_id_buffer);

    /* Get the MQTT client username. */
    result = az_iot_hub_client_get_user_name(
        &hub_client, iot_hub_username_buffer, sizeof(iot_hub_username_buffer), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get MQTT client username: az_result %ld.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    EWF_LOG("IoT Hub user name: %s\n", iot_hub_username_buffer);

    /* Connect to the MQTT server */
    ewf_status = ewf_adapter_mqtt_basic_connect(
        adapter_ptr,
        EWF_CONFIG_IOT_HUB_HOSTNAME,
        8883,
        iot_hub_client_id_buffer,
        iot_hub_username_buffer,
        NULL);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG_ERROR("Failed to MQTT connect: ewf_status %d.", ewf_status);
        return ewf_status;
    }

    EWF_LOG("[INFO][CONNECTED!]\n");

    EWF_LOG("[INFO][Listening for cloud to device messages...]\n");

    /* Subscribe to the C2D topic */
    ewf_status = ewf_adapter_mqtt_basic_subscribe(adapter_ptr, AZ_IOT_HUB_CLIENT_C2D_SUBSCRIBE_TOPIC);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG_ERROR("Failed to subscribe to a topic: ewf_status %d.\n", ewf_status);
    }

    /* Get the Telemetry topic to publish the telemetry messages. */
    result = az_iot_hub_client_telemetry_get_publish_topic(
        &hub_client, NULL, telemetry_topic_buffer, sizeof(telemetry_topic_buffer), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get the Telemetry topic: az_result %ld.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    if (EWF_CONFIG_TELEMETRY_LOOP_MINUTES == 0)
    {
    	EWF_LOG("[INFO] Running forever...\n\n");
    }
    else
    {
    	EWF_LOG("[INFO] Running for %d minutes...\n\n", EWF_CONFIG_TELEMETRY_LOOP_MINUTES);
    }

    /* Configure callback for MQTT message reception */
    ewf_status = ewf_adapter_mqtt_basic_message_callback_set(adapter_ptr, ewf_mqtt_receive_message_user_callback);
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to set MQTT callback: ewf_status %d.", ewf_status);
        return ewf_status;
    }

    int mqtt_count = 0;
    unsigned char message_buffer[512] = { 0 };

    int minutes_counter;
    int seconds_counter;

    for (minutes_counter = 0;
        (EWF_CONFIG_TELEMETRY_LOOP_MINUTES == 0) || (EWF_CONFIG_TELEMETRY_LOOP_MINUTES != 0 && minutes_counter < EWF_CONFIG_TELEMETRY_LOOP_MINUTES);
        minutes_counter++)
    {
        for (seconds_counter = 0; seconds_counter < 60; seconds_counter++)
        {
            mqtt_count++;

            EWF_LOG("\n[INFO][Running time: %02d:%02d:%02d]\n\n", minutes_counter / 60, minutes_counter % 60, seconds_counter);

            if (telemetry_message_callback)
            {
                char *str = telemetry_message_callback();
                ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, telemetry_topic_buffer, str);
                if (ewf_result_failed(ewf_status))
                {
                    EWF_LOG_ERROR("Failed to publish telemetry: ewf_status %d.\n", ewf_status);
                }
            }

            {
                char buffer[16];
                sprintf(buffer, "Count %d", mqtt_count);
                ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, telemetry_topic_buffer, buffer);
                if (ewf_result_failed(ewf_status))
                {
                    EWF_LOG_ERROR("Failed to publish telemetry: ewf_status %d.\n", ewf_status);
                }
            }
            if (ewf_mqtt_rx_flag)
            {
                ewf_mqtt_rx_flag--;
                ewf_status = ewf_adapter_mqtt_basic_message_get(adapter_ptr, ewf_mqtt_recv_message.ewf_mqtt_recv_topic, (char*)message_buffer);
                if (ewf_status == EWF_RESULT_NOT_SUPPORTED)
                {
                    continue;
                }
                else if (ewf_result_failed(ewf_status))
                {
                    EWF_LOG_ERROR("Failed to get MQTT message from the modem: ewf_status %d.\n", ewf_status);
                }
                else if(ewf_result_succeeded(ewf_status))
                {
                    EWF_LOG("[MQTT RECIEVE][TOPIC: %s]\r\n", ewf_mqtt_recv_message.ewf_mqtt_recv_topic);
                    EWF_LOG("[MQTT RECIEVE][Payload: %s]\r\n", message_buffer);
                }
            }

            /* Sleep one second */
            ewf_platform_sleep(1 * EWF_PLATFORM_TICKS_PER_SECOND);
        }
    }

    EWF_LOG("\nStop listening to cloud to device messages...\n");

    /* Unsubscribe to the C2D topic */
    ewf_status = ewf_adapter_mqtt_basic_unsubscribe(adapter_ptr, AZ_IOT_HUB_CLIENT_C2D_SUBSCRIBE_TOPIC);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG_ERROR("Failed to unsubscribe to a topic: ewf_status %d.\n", ewf_status);
    }

    /* Disconnect from the MQTT server */
    ewf_status = ewf_adapter_mqtt_basic_disconnect(adapter_ptr);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG_ERROR("Failed to MQTT disconnect: ewf_status %d.\n", ewf_status);
    }

    EWF_LOG("\nBye!\n");

    return EWF_RESULT_OK;
}
