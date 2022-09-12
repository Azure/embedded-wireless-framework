/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter basic MQTT API
 ****************************************************************************/

#ifndef __ewf_adapter_mqtt_basic__h__included__
#define __ewf_adapter_mqtt_basic__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_mqtt_basic Adapter MQTT basic API
 * @ingroup group_adapter_api
 * @brief MQTT basic API functions for connecting, disconnecting. publishing and subscribing.
 * @{
 *
 ****************************************************************************/

/**
 * @brief A function pointer type for MQTT basic API state callbacks
 * @param[in] adapter_ptr a pointer to an adapter structure
 * @param[in] state_cstr a pointer to the state string
 * @param[in] param_cstr a pointer to the state param string
 * @return #ewf_result success and error conditions
 */
typedef ewf_result(*ewf_adapter_mqtt_basic_state_callback)(ewf_adapter* adapter_ptr, const char* state_cstr, const char* param_cstr);

/**
 * @brief A function pointer type for MQTT basic API message callbacks
 * @param[in] adapter_ptr a pointer to an adapter structure
 * @param[in] topic_cstr a pointer to the topic string
 * @param[in] payload_cstr a pointer to the payload string
 * @return #ewf_result success and error conditions
 */
typedef ewf_result(*ewf_adapter_mqtt_basic_message_callback)(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr);

/** @breif the MQTT basic API type */
typedef struct _ewf_adapter_api_mqtt_basic
{
    ewf_adapter_mqtt_basic_state_callback state_callback;
    ewf_adapter_mqtt_basic_message_callback message_callback;

    ewf_result(*urc_callback)(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

    ewf_result(*control)(ewf_adapter* adapter_ptr, const char* command_cstr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);

    ewf_result(*connect)(ewf_adapter* adapter_ptr, char const* server_cstr, uint32_t port, char const* clientid_cstr, char const* username_cstr, char const* password_cstr);
    ewf_result(*disconnect)(ewf_adapter* adapter_ptr);

    ewf_result(*subscribe)(ewf_adapter* adapter_ptr, char const* topic_cstr);
    ewf_result(*unsubscribe)(ewf_adapter* adapter_ptr, char const* topic_cstr);

    ewf_result(*publish)(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* message_cstr);

} ewf_adapter_api_mqtt_basic;

ewf_result ewf_adapter_mqtt_basic_control(ewf_adapter* adapter_ptr, const char* command_cstr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);

ewf_result ewf_adapter_mqtt_basic_connect(ewf_adapter* adapter_ptr, char const* server_cstr, uint32_t port, char const* clientid_cstrs, char const* username_cstr, char const* password_cstr);
ewf_result ewf_adapter_mqtt_basic_disconnect(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_mqtt_basic_subscribe(ewf_adapter* adapter_ptr, char const* topic_cstr);
ewf_result ewf_adapter_mqtt_basic_unsubscribe(ewf_adapter* adapter_ptr, char const* topic_cstr);

ewf_result ewf_adapter_mqtt_basic_publish(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* message_cstr);

ewf_result ewf_adapter_mqtt_basic_state_callback_set(ewf_adapter * adapter_ptr, ewf_adapter_mqtt_basic_state_callback callback);
ewf_result ewf_adapter_mqtt_basic_message_callback_set(ewf_adapter * adapter_ptr, ewf_adapter_mqtt_basic_message_callback callback);

/************************************************************************//**
 * @} *** group_adapter_mqtt_basic
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_mqtt_basic__h__included__ */
