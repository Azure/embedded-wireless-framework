/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter MQTT API
 ****************************************************************************/

#ifndef __ewf_adapter_mqtt__h__included__
#define __ewf_adapter_mqtt__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_mqtt Adapter MQTT API
 * @ingroup group_adapter_api
 * @brief MQTT functions for connecting, disconnecting. publishing and subscribing.
 * @{
 *
 ****************************************************************************/

struct ewf_socket_mqtt;
typedef struct ewf_socket_mqtt ewf_socket_mqtt;

enum _ewf_adapter_mqtt_qos;
typedef enum _ewf_adapter_mqtt_qos ewf_adapter_mqtt_qos;

struct _ewf_adapter_mqtt_message;
typedef struct _ewf_adapter_mqtt_message ewf_adapter_mqtt_message;

/**
 * @brief A function pointer type for MQTT basic API state callbacks
 * @param[in] adapter_ptr a pointer to an adapter structure
 * @param[in] state_cstr a pointer to the state string
 * @param[in] param_cstr a pointer to the state param string
 * @return #ewf_result success and error conditions
 */
typedef ewf_result(*ewf_adapter_mqtt_state_callback)(ewf_socket_mqtt* socket_ptr, const char* state_cstr, const char* param_cstr);

/**
 * @brief A function pointer type for MQTT message callbacks
 * @param[in] adapter_ptr a pointer to an adapter structure
 * @return #ewf_result success and error conditions
 */
typedef ewf_result(*ewf_adapter_mqtt_message_callback)(ewf_socket_mqtt* socket_ptr, const char* topic_str, ewf_adapter_mqtt_message* message_ptr);

/** @brief The MQTT socket structure definition */
struct ewf_socket_mqtt
{
    void* data_ptr;
    ewf_adapter* adapter_ptr;
    ewf_adapter_mqtt_state_callback state_callback;
    ewf_adapter_mqtt_message_callback message_callback;
};

/** @brief The MQTT QoS enumeration definition */
enum _ewf_adapter_mqtt_qos
{
    ewf_adapter_mqtt_qos_0 = 0,
    ewf_adapter_mqtt_qos_1 = 1,
    ewf_adapter_mqtt_qos_2 = 2,

    ewf_adapter_mqtt_qos_error = -1,
};

/** @brief The MQTT Message structure definition */
struct _ewf_adapter_mqtt_message
{
    uint16_t ID;
    uint8_t DUP;
    ewf_adapter_mqtt_qos QoS;
    uint8_t RETAIN;
    uint32_t payload_length;
    void* payload_ptr;
};

/** @breif the MQTT API type */
typedef struct _ewf_adapter_api_mqtt
{
    ewf_result(*control)(ewf_socket_mqtt* socket_ptr, const char* command_cstr, const char* param_cstr);
    ewf_result(*query)(ewf_socket_mqtt* socket_ptr, const char* command_cstr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);

    ewf_result(*open)(ewf_adapter* adapter_ptr, ewf_socket_mqtt* socket_ptr);
    ewf_result(*close)(ewf_socket_mqtt* socket_ptr);
    ewf_result(*set_tls_configuration)(ewf_socket_mqtt* socket_ptr, uint32_t tls_configuration_id);
    ewf_result(*connect)(ewf_socket_mqtt* socket_ptr, const char* server_str, uint32_t port, const char* clientid_str, const char* username_str, const char* password_str);
    ewf_result(*disconnect)(ewf_socket_mqtt* socket_ptr);
    ewf_result(*publish_string)(ewf_socket_mqtt* socket_ptr, const char* topic_str, const char* message_str);
    ewf_result(*publish_buffer)(ewf_socket_mqtt* socket_ptr, const char* topic_str, const uint8_t* message_ptr, uint32_t message_size);
    ewf_result(*publish_message)(ewf_socket_mqtt* socket_ptr, const char* topic_str, const ewf_adapter_mqtt_message* message_ptr);
    ewf_result(*subscribe)(ewf_socket_mqtt* socket_ptr, const char* topic);
    ewf_result(*unsubscribe)(ewf_socket_mqtt* socket_ptr, const char* topic);

    ewf_result(*set_message_state)(ewf_socket_mqtt* socket_ptr, ewf_adapter_mqtt_state_callback callback);
    ewf_result(*set_message_callback)(ewf_socket_mqtt* socket_ptr, ewf_adapter_mqtt_message_callback callback);

} ewf_adapter_api_mqtt;

/**
 * @brief Open an MQTT socket
 * @param[in] adapter_ptr a pointer to an adapter structure
 * @param[in,out] socket a pointer to a variable that will hold the MQTT socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_open(ewf_adapter* adapter_ptr, ewf_socket_mqtt* socket_ptr);

/**
 * @brief Close an MQTT socket
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_close(ewf_socket_mqtt* socket_ptr);

/**
 * @brief Set the TLS context for the socket
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_set_tls_configuration(ewf_socket_mqtt* socket_ptr, uint32_t tls_configuration_id);

/**
 * @brief Connect to an MQTT server
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_connect(ewf_socket_mqtt* socket_ptr, const char * server_str, uint32_t port, const char * clientid_str, const char * username_str, const char * password_str);

/**
 * @brief Disconnect from an MQTT server
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_disconnect(ewf_socket_mqtt* socket_ptr);

/**
 * @brief Publish a message to to a topic
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_publish_string(ewf_socket_mqtt* socket_ptr, const char* topic_str, const char* message_str);

/**
 * @brief Publish a message to to a topic
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_publish_buffer(ewf_socket_mqtt* socket_ptr, const char* topic_str, const uint8_t* message_ptr, uint32_t message_size);

/**
 * @brief Publish a message to to a topic
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_publish_message(ewf_socket_mqtt* socket_ptr, const char* topic_str, const ewf_adapter_mqtt_message* message_ptr);

/**
 * @brief Subscribe to a topic
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @param[in] topic_str a pointer to a topic string to subscribe to
 * @param[in] qos a requested QoS
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_subscribe(ewf_socket_mqtt* socket_ptr, const char * topic_str, ewf_adapter_mqtt_qos qos);

/**
 * @brief Subscribe to a topic
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @param[in] topic_str a pointer to a topic string to subscribe to
 * @param[in,out] qos_ptr a pointer to a requested QoS, on exit the granted QoS
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_subscribe_with_result(ewf_socket_mqtt* socket_ptr, const char* topic_str, ewf_adapter_mqtt_qos* qos_ptr);

/**
 * @brief Unsubscribe from a topic
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_unsubscribe(ewf_socket_mqtt* socket_ptr, const char * topic_str);

/**
 * @brief Register a callback for state changes
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @param[in] callback a pointer to the callback
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_state_callback_set(ewf_socket_mqtt* socket_ptr, ewf_adapter_mqtt_state_callback callback);

/**
 * @brief Register a callback for subscribed messages
 * @param[in] socket_ptr a pointer to an MQTT socket structure
 * @param[in] callback a pointer to the callback
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_mqtt_message_callback_set(ewf_socket_mqtt* socket_ptr, ewf_adapter_mqtt_message_callback callback);

/************************************************************************//**
 * @} *** group_adapter_mqtt
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_mqtt__h__included__ */
