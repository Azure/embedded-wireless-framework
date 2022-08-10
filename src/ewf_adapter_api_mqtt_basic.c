/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework MQTT basic API
 ****************************************************************************/

#include "ewf_adapter.h"

#define EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_POINTER(adapter_ptr)                    \
do {                                                                                \
    if ((adapter_ptr->mqtt_basic_api_ptr == NULL))                                  \
    {                                                                               \
        EWF_LOG_ERROR("The API is not implemented.");                               \
        return EWF_RESULT_NOT_SUPPORTED;                                            \
    }                                                                               \
} while(0)

#define EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_FUNCTION_POINTER(adapter_ptr, function_ptr) \
do {                                                                                \
    if ((adapter_ptr->mqtt_basic_api_ptr == NULL) ||                                \
        (adapter_ptr->mqtt_basic_api_ptr->function_ptr == NULL))                    \
    {                                                                               \
        EWF_LOG_ERROR("The function is not implemented.");                          \
        return EWF_RESULT_NOT_SUPPORTED;                                            \
    }                                                                               \
} while(0)

ewf_result ewf_adapter_mqtt_basic_state_callback_set(ewf_adapter * adapter_ptr, ewf_adapter_mqtt_basic_state_callback callback)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_POINTER(adapter_ptr);
    adapter_ptr->mqtt_basic_api_ptr->state_callback = callback;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_mqtt_basic_message_callback_set(ewf_adapter * adapter_ptr, ewf_adapter_mqtt_basic_message_callback callback)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_POINTER(adapter_ptr);
    adapter_ptr->mqtt_basic_api_ptr->message_callback = callback;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_mqtt_basic_control(ewf_adapter* adapter_ptr, const char* command_cstr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_FUNCTION_POINTER(adapter_ptr, control);
    return adapter_ptr->mqtt_basic_api_ptr->control(adapter_ptr, command_cstr, buffer_ptr, buffer_length_ptr);
}

ewf_result ewf_adapter_mqtt_basic_connect(ewf_adapter * adapter_ptr, char const* server_cstr, uint32_t port, char const* clientid_cstr, char const* username_cstr, char const* password_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_FUNCTION_POINTER(adapter_ptr, connect);
    return adapter_ptr->mqtt_basic_api_ptr->connect(adapter_ptr, server_cstr, port, clientid_cstr, username_cstr, password_cstr);
}

ewf_result ewf_adapter_mqtt_basic_disconnect(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_FUNCTION_POINTER(adapter_ptr, disconnect);
    return adapter_ptr->mqtt_basic_api_ptr->disconnect(adapter_ptr);
}

ewf_result ewf_adapter_mqtt_basic_subscribe(ewf_adapter* adapter_ptr, char const* topic_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_FUNCTION_POINTER(adapter_ptr, subscribe);
    return adapter_ptr->mqtt_basic_api_ptr->subscribe(adapter_ptr, topic_cstr);
}

ewf_result ewf_adapter_mqtt_basic_unsubscribe(ewf_adapter* adapter_ptr, char const* topic_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_FUNCTION_POINTER(adapter_ptr, unsubscribe);
    return adapter_ptr->mqtt_basic_api_ptr->unsubscribe(adapter_ptr, topic_cstr);
}

ewf_result ewf_adapter_mqtt_basic_publish(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* message_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_MQTT_BASIC_API_FUNCTION_POINTER(adapter_ptr, publish);
    return adapter_ptr->mqtt_basic_api_ptr->publish(adapter_ptr, topic_cstr, message_cstr);
}
