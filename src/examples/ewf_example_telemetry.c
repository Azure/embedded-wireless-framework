/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework telemetry to IoT Hub example
 * @details The Embedded Wireless Framework telemetry to IoT Hub example
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

/* Work buffers */
static char iot_hub_username_buffer[EWF_CONFIG_TELEMETRY_USERNAME_LENGTH];
static char iot_hub_client_id_buffer[EWF_CONFIG_TELEMETRY_CLIENT_ID_LENGTH];
static char telemetry_topic_buffer[EWF_CONFIG_TELEMETRY_TOPIC_LENGTH];

/* The IoT Hub client */
static az_iot_hub_client hub_client;

ewf_result ewf_example_telemetry(ewf_adapter* adapter_ptr)
{
    az_result result;
    ewf_result ewf_result;
    ewf_socket_mqtt socket;

    EWF_LOG("IoT hub hostname: %s\n", EWF_CONFIG_IOT_HUB_HOSTNAME);
    EWF_LOG("IoT hub device id: %s\n", EWF_CONFIG_IOT_HUB_DEVICEID);

    // Initialize the hub client with the default connection options.
    result = az_iot_hub_client_init(&hub_client, AZ_SPAN_FROM_STR(EWF_CONFIG_IOT_HUB_HOSTNAME), AZ_SPAN_FROM_STR(EWF_CONFIG_IOT_HUB_DEVICEID), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to initialize hub client: ewf_result return code 0x%08lx.", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    // Get the MQTT client ID used for the MQTT connection.
    result = az_iot_hub_client_get_client_id(
        &hub_client, iot_hub_client_id_buffer, sizeof(iot_hub_client_id_buffer), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get MQTT client ID: ewf_result return code 0x%08lx.", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    EWF_LOG("IoT Hub client ID: %s\n", iot_hub_client_id_buffer);

    // Get the MQTT client username.
    result = az_iot_hub_client_get_user_name(
        &hub_client, iot_hub_username_buffer, sizeof(iot_hub_username_buffer), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get MQTT client username: ewf_result return code 0x%08lx.", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    EWF_LOG("IoT Hub user name: %s\n", iot_hub_username_buffer);

    // Connect to the MQTT server
    ewf_result = adapter_ptr->mqtt_api_ptr->connect(
        adapter_ptr,
        &socket,
        EWF_CONFIG_IOT_HUB_HOSTNAME,
        8883,
        iot_hub_client_id_buffer,
        iot_hub_username_buffer,
        NULL);
    if (ewf_result_failed(ewf_result))
    {
        EWF_LOG_ERROR("Failed to MQTT connect: ewf_result return code 0x%08lx.", ewf_result);
        return ewf_result;
    }

    // Get the Telemetry topic to publish the telemetry messages.
    result = az_iot_hub_client_telemetry_get_publish_topic(
        &hub_client, NULL, telemetry_topic_buffer, sizeof(telemetry_topic_buffer), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get the Telemetry topic: ewf_result return code 0x%08lx.", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    for (int mqtt_count = 0; mqtt_count < 10; mqtt_count++)
    {
        unsigned length;
        char * str;
        char buffer[16];

        {
            str = "Hello World!";
            length = strlen(str);
            ewf_result = adapter_ptr->mqtt_api_ptr->publish(adapter_ptr, socket, telemetry_topic_buffer, length, str);
            if (ewf_result_failed(ewf_result))
            {
            EWF_LOG_ERROR("Failed to publish telemetry: ewf_result return code 0x%08lx.", ewf_result);
            }
        }

        /* Sleep one second */
        ewf_platform_sleep(1 * EWF_PLATFORM_TICKS_PER_SECOND);

        {
            str = ewfl_unsigned_to_str(mqtt_count, buffer, sizeof(buffer));
            length = strlen(str);
            ewf_result = adapter_ptr->mqtt_api_ptr->publish(adapter_ptr, socket, telemetry_topic_buffer, length, str);
            if (ewf_result_failed(ewf_result))
            {
            EWF_LOG_ERROR("Failed to publish telemetry: ewf_result return code 0x%08lx.", ewf_result);
            }
        }

        /* Sleep one second */
        ewf_platform_sleep(1 * EWF_PLATFORM_TICKS_PER_SECOND);
    }

    /* Subscribe to the C2D topic */
    ewf_result = adapter_ptr->mqtt_api_ptr->subscribe(adapter_ptr, socket, AZ_IOT_HUB_CLIENT_C2D_SUBSCRIBE_TOPIC);
    if (ewf_result_failed(ewf_result))
    {
        EWF_LOG_ERROR("Failed to subscribe to a topic: ewf_result return code 0x%08lx.", ewf_result);
    }

    /* Wait a minute for more C2D messages */
    ewf_platform_sleep(60 * EWF_PLATFORM_TICKS_PER_SECOND);

    /* Unsubscribe to the C2D topic */
    ewf_result = adapter_ptr->mqtt_api_ptr->unsubscribe(adapter_ptr, socket, AZ_IOT_HUB_CLIENT_C2D_SUBSCRIBE_TOPIC);
    if (ewf_result_failed(ewf_result))
    {
        EWF_LOG_ERROR("Failed to unsubscribe to a topic: ewf_result return code 0x%08lx.", ewf_result);
    }

    /* Wait a minute for more C2D messages */
    ewf_platform_sleep(60 * EWF_PLATFORM_TICKS_PER_SECOND);

    // Disconnect from the MQTT server
    ewf_result = adapter_ptr->mqtt_api_ptr->disconnect(adapter_ptr, socket);
    if (ewf_result_failed(ewf_result))
    {
        EWF_LOG_ERROR("Failed to MQTT disconnect: ewf_result return code 0x%08lx.", ewf_result);
    }

    return EWF_RESULT_OK;
}
