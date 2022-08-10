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
    ewf_result (*connect)(ewf_adapter* adapter_ptr, char const* server_str, uint32_t port, char const* clientid, char const* username, char const* password);
    ewf_result (*disconnect)(ewf_adapter* adapter_ptr);
    ewf_result (*subscribe)(ewf_adapter* adapter_ptr, char const* topic_cstr);
    ewf_result (*unsubscribe)(ewf_adapter* adapter_ptr, char const* topic_cstr);
    ewf_result (*publish)(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* msg_cstr);

} ewf_adapter_api_mqtt_basic;

/************************************************************************//**
 * @} *** group_adapter_mqtt_basic
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_mqtt_basic__h__included__ */
