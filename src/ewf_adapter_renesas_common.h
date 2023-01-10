/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework generic Renesas adapter functionality.
 *     Renesas adapter common definitions are defined here.
 *     for eg. the application should define
 *     EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_ID/
 *     EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_ID,
 *     EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_PRIVATE_KEY_ID,
 *     EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_CERTIFICATE_ID while provisioning
 *     certificates onto the device. EWF_CONFIG_ADAPTER_RENESAS_COMMON_SECURITY_PROFILE_ID
 *     and EWF_CONFIG_ADAPTER_RENESAS_COMMON_CA_CERTIFICATE_ID must be defined
 *     when using MQTT connection. If not defined, the adapter has default 
 *     definitions to be used.
 ****************************************************************************/

#ifndef __ewf_adapter_renesas_common__h__included__
#define __ewf_adapter_renesas_common__h__included__

#include "ewf_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_adapter_renesas_common Renesas common configuration
 * @ingroup group_configuration
 * @brief Renesas common adapter configuration
 * @{
 ****************************************************************************/

#ifndef EWF_ADAPTER_RENESAS_COMMON_NVM_ENABLED
#define EWF_ADAPTER_RENESAS_COMMON_NVM_ENABLED                                 (1)
#endif

#if !defined(EWF_ADAPTER_RENESAS_COMMON_TLS_ENABLED) &&                        \
             !defined(EWF_ADAPTER_RENESAS_COMMON_TLS_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_RENESAS_COMMON_TLS_BASIC_ENABLED                           (1)
#define EWF_ADAPTER_RENESAS_COMMON_TLS_ENABLED                                 (0)
#else
#define EWF_ADAPTER_RENESAS_COMMON_TLS_BASIC_ENABLED 						   (0)
#define EWF_ADAPTER_RENESAS_COMMON_TLS_ENABLED 								   (1)
#endif
#endif

#ifndef EWF_ADAPTER_RENESAS_COMMON_TCP_ENABLED
#define EWF_ADAPTER_RENESAS_COMMON_TCP_ENABLED                                 (1)
#endif

#ifndef EWF_ADAPTER_RENESAS_COMMON_UDP_ENABLED
#define EWF_ADAPTER_RENESAS_COMMON_UDP_ENABLED                                 (1)
#endif

#if !defined(EWF_ADAPTER_RENESAS_COMMON_MQTT_ENABLED) &&                       \
            !defined(EWF_ADAPTER_RENESAS_COMMON_MQTT_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_RENESAS_COMMON_MQTT_BASIC_ENABLED                          (1)
#define EWF_ADAPTER_RENESAS_COMMON_MQTT_ENABLED                                (0)
#else
#define EWF_ADAPTER_RENESAS_COMMON_MQTT_BASIC_ENABLED                          (0)
#define EWF_ADAPTER_RENESAS_COMMON_MQTT_ENABLED                                (1)
#endif
#endif

/** @brief The total number of supported Internet sockets in the adapter */
#define EWF_ADAPTER_RENESAS_COMMON_INTERNET_SOCKET_POOL_SIZE                   (6)

/** @brief The Internet socket invalid value */
#define EWF_ADAPTER_RENESAS_COMMON_INTERNET_SOCKET_INVALID                     (-1)

/** @brief The Internet socket transmission protocol values */
#define EWF_ADAPTER_RENESAS_COMMON_INTERNET_SOCKET_TCP                         (0)
#define EWF_ADAPTER_RENESAS_COMMON_INTERNET_SOCKET_UDP                         (1)

/** @brief The total number of supported MQTT sockets in the adapter.
 * Only one MQTT client is supported in Renesas RYZ adapters */
#define EWF_ADAPTER_RENESAS_COMMON_MQTT_SOCKET_POOL_SIZE                       (1)

/** @brief The MQTT socket invalid value */
#define EWF_ADAPTER_RENESAS_COMMON_MQTT_SOCKET_INVALID (-1)

#define EWF_ADAPTER_RENESAS_COMMON_SOCKET_MAX_SEND_SIZE                        (1460)
#define EWF_ADAPTER_RENESAS_COMMON_SOCKET_MAX_RECEIVE_SIZE                     (1500)
#define EWF_ADAPTER_RENESAS_COMMON_SOCKET_COMMAND_MODE                         ("1")
#define EWF_ADAPTER_RENESAS_COMMON_SOCKET_ONLINE_DATA_MODE                     ("0")

/**
 * @brief Trusted Certificate Authority certificate index number(0-19)
 * The index in the non volatile memory where the root CA certificate will be stored
 *
 */
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_ID
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_ID               ("11")
#endif

/**
 * @brief User Certificate Authority certificate index number(0-19)
 * The index in the non volatile memory where the user CA certificate will be stored
 *
 */
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_ID
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_ID               ("12")
#endif

/**
 * @brief CA certificate index that will be used in the security/TLS profile configuration
 * This number will either be EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_ID or
 * EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_ID
 * Default to Root CA.
 */
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_CA_CERTIFICATE_ID
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_CA_CERTIFICATE_ID                    ("11")
#endif

/**
 * @brief Client certificate index number(0-19)
 * The index in the non volatile memory where the client certificate will be stored
 *
 */
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_CERTIFICATE_ID
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_CERTIFICATE_ID                ("13")
#endif

/**
 * @brief Client Key index number(0-19)
 * The index in the non volatile memory where the client key will be stored
 *
 */
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_PRIVATE_KEY_ID
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_PRIVATE_KEY_ID                ("13")
#endif

/**
 * @brief Security Profile ID (0-6)
 * The id number for the security profile configuration
 *
 */
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_SECURITY_PROFILE_ID
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_SECURITY_PROFILE_ID                  ("5")
#endif

/** @brief Trusted Certificate Authority certificate pointer name*/
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_BUFFER_NAME
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_BUFFER_NAME      (root_ca_cert_pem)
#endif

/** @brief User Certificate Authority certificate pointing buffer name */
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_BUFFER_NAME
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_BUFFER_NAME      (ca_cert_pem)
#endif

/** @brief Client certificate pointing buffer name */
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_CERTIFICATE_BUFFER_NAME
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_CERTIFICATE_BUFFER_NAME       (device_cert_pem)
#endif

/** @brief Client private key filename  */
#ifndef EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_PRIVATE_KEY_BUFFER_NAME
#define EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_PRIVATE_KEY_BUFFER_NAME       (device_key_pem)
#endif

/* Type of data, string */
#define EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_CERTIFICATE                       ("certificate")
#define EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_PRIVATEKEY                        ("privatekey")

#define EWF_ADAPTER_RENESAS_COMMON_CLOSE_LISTENING_SOCKET                      ("0")
#define EWF_ADAPTER_RENESAS_COMMON_OPEN_LISTNEING_IPV4_SOCKET                  ("1")
#define EWF_ADAPTER_RENESAS_COMMON_OPEN_LISTENING_IPV6_SOCKET                  ("2")

/************************************************************************//**
 * @} *** group_configuration_adapter_renesas_common
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_adapter_renesas_common Renesas common driver implementation
 * @ingroup group_adapter
 * @brief Renesas common adapter implementation
 * @{
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_adapter_renesas_common_data Renesas common driver internal data
 * @brief Renesas common adapter data structure
 * @{
 ****************************************************************************/

/** @brief The socket service type  */
typedef enum _ewf_adapter_bg96_internet_socket_service_type
{
    ewf_adapter_renesas_common_socket_service_type_not_initialized,
    ewf_adapter_renesas_common_socket_service_type_tcp,
    ewf_adapter_renesas_common_socket_service_type_udp,
    ewf_adapter_renesas_common_socket_service_type_tcp_listener,
    ewf_adapter_renesas_common_socket_service_type_udp_listener,

} ewf_adapter_renesas_common_internet_socket_service_type;

/** @brief Internal structure for internet socket status  */
typedef struct _ewf_adapter_renesas_common_socket
{
  void* socket_ptr;
  uint32_t id;
  uint32_t local_port;
  volatile ewf_adapter_renesas_common_internet_socket_service_type type;
  volatile bool used;
  volatile bool open;
  volatile bool open_error;
  volatile bool conn;
  volatile bool conn_error;
  volatile bool recv;

} ewf_adapter_renesas_common_internet_socket;

/** @brief The Renesas adapter data structure */
typedef struct _ewf_adapter_renesas_common
{
    /**< The user URC callback, called to process URC not handled by the driver */
    ewf_interface_urc_callback user_urc_callback;

#if EWF_ADAPTER_RENESAS_COMMON_TCP_ENABLED || EWF_ADAPTER_RENESAS_COMMON_UDP_ENABLED
    /**< The internal pool of internet sockets */
    ewf_adapter_renesas_common_internet_socket internet_socket_pool [EWF_ADAPTER_RENESAS_COMMON_INTERNET_SOCKET_POOL_SIZE];
#endif

#if EWF_ADAPTER_RENESAS_COMMON_MQTT_BASIC_ENABLED
    /** @brief Internal MQTT basic API socket 0 status  */
    volatile bool mqtt_basic_conn;
    volatile uint8_t mqtt_basic_conn_error;
    volatile bool mqtt_basic_publish;
    volatile uint8_t mqtt_basic_publish_error;
    volatile bool mqtt_basic_subscribe;
    volatile uint8_t mqtt_basic_subscribe_error;
#endif /* EWF_ADAPTER_RENESAS_COMMON_MQTT_BASIC_ENABLED */

    /* Module status */
    volatile bool module_start;

    /**< The TCP receive callback */
    ewf_adapter_tcp_receive_callback tcp_receive_callback;

    /**< The UDP receive callback */
    ewf_adapter_udp_receive_callback udp_receive_callback;

    /**< The MQTT message callback */
    ewf_adapter_mqtt_message_callback mqtt_message_callback;

} ewf_adapter_renesas_common;

/************************************************************************//**
 * @} *** group_adapter_renesas_common_data
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_adapter_renesas_common_functions Renesas generic adapter functions
 * @brief Renesas generic adapter functions
 * @{
 ****************************************************************************/

/**
 * @defgroup group_adapter_renesas_common_control Adapter control
 * @brief Renesas adapter control API
 * @{
 */

extern ewf_adapter_api_control ewf_adapter_renesas_common_api_control;

ewf_result ewf_adapter_renesas_common_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_stop(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_renesas_common_control */

/**
 * @defgroup group_adapter_renesas_common_info Adapter information
 * @brief The Renesas info API
 * @{
 */

extern ewf_adapter_api_info ewf_adapter_renesas_common_api_info;

ewf_result ewf_adapter_renesas_common_info(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t* address_ptr);
ewf_result ewf_adapter_renesas_common_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t* netmask_ptr);
ewf_result ewf_adapter_renesas_common_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t* gateway_ptr);
ewf_result ewf_adapter_renesas_common_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t* dns);

/** @} *** group_adapter_renesas_common_info */

/**
 * @defgroup group_adapter_renesas_common_urc URC handling
 * @brief Renesas adapter driver URC handling
 * @{
 */

ewf_result ewf_adapter_renesas_common_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_renesas_common_set_user_urc_callback(ewf_adapter* adapter_ptr, ewf_interface_urc_callback callback);

/** @} *** group_adapter_renesas_common_urc */

/**
 * @defgroup group_adapter_renesas_common_tls_basic The Renesas adapter TLS basic API
 * @brief The Renesas adapter TLS basic API
 * @{
 */

#if EWF_ADAPTER_RENESAS_COMMON_TLS_BASIC_ENABLED

extern ewf_adapter_api_tls_basic ewf_adapter_renesas_common_api_tls_basic;

ewf_result ewf_adapter_renesas_common_tls_basic_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_tls_basic_stop(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_renesas_common_tls_basic_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

ewf_result ewf_adapter_renesas_common_tls_basic_init(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_tls_basic_clean(ewf_adapter* adapter_ptr);

#endif /* EWF_ADAPTER_RENESAS_COMMON_TLS_BASIC_ENABLED */

/** @} *** group_adapter_renesas_common_tls_basic */

/**
 * @defgroup group_adapter_renesas_common_internet Common internet functions (TCP+UDP)
 * @brief Functions common to TCP and UDP in the Renesas common internet implementation
 * @{
 */

#if EWF_ADAPTER_RENESAS_COMMON_TCP_ENABLED || EWF_ADAPTER_RENESAS_COMMON_UDP_ENABLED

ewf_result ewf_adapter_renesas_common_internet_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_internet_stop(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_renesas_common_internet_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

#endif /* EWF_ADAPTER_RENESAS_COMMON_TCP_ENABLED || EWF_ADAPTER_RENESAS_COMMON_UDP_ENABLED */

/** @} *** group_adapter_renesas_common_internet */

/**
 * @defgroup group_adapter_renesas_common_tcp TCP API implementation
 * @brief Renesas adapter TCP API
 * @{
 */

#if EWF_ADAPTER_RENESAS_COMMON_TCP_ENABLED

extern ewf_adapter_api_tcp ewf_adapter_renesas_common_api_tcp;

ewf_result ewf_adapter_renesas_common_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_renesas_common_tcp_close(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_renesas_common_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);
ewf_result ewf_adapter_renesas_common_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id);
ewf_result ewf_adapter_renesas_common_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t local_port);
ewf_result ewf_adapter_renesas_common_tcp_listen(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_renesas_common_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr);
ewf_result ewf_adapter_renesas_common_tcp_connect(ewf_socket_tcp* socket_ptr, const char* const server, uint32_t remote_port);
ewf_result ewf_adapter_renesas_common_tcp_shutdown(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_renesas_common_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_renesas_common_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length, bool wait);

#endif /* EWF_ADAPTER_RENESAS_COMMON_TCP_ENABLED */

/** @} *** group_adapter_renesas_common_tcp */

/**
 * @defgroup group_adapter_renesas_common_udp UDP API implementation
 * @brief Renesas adapter UDP API
 * @{
 */

#if EWF_ADAPTER_RENESAS_COMMON_UDP_ENABLED

extern ewf_adapter_api_udp ewf_adapter_renesas_common_api_udp;

ewf_result ewf_adapter_renesas_common_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_renesas_common_udp_close(ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_renesas_common_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);
ewf_result ewf_adapter_renesas_common_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id);
ewf_result ewf_adapter_renesas_common_udp_bind(ewf_socket_udp* socket_ptr, uint32_t local_port);
ewf_result ewf_adapter_renesas_common_udp_shutdown(ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_renesas_common_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_renesas_common_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address_str, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

#endif /* EWF_ADAPTER_RENESAS_COMMON_UDP_ENABLED */

/** @} *** group_adapter_renesas_common_udp */

/**
 * @defgroup group_adapter_renesas_common_mqtt MQTT API implementation
 * @brief Renesas adapter MQTT API
 * @{
 */

#if EWF_ADAPTER_RENESAS_COMMON_MQTT_ENABLED

ewf_result ewf_adapter_renesas_common_mqtt_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_mqtt_stop(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_mqtt_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

ewf_result ewf_adapter_renesas_common_mqtt_connect(ewf_adapter* adapter_ptr, ewf_socket_mqtt* socket_ptr, char const* server_str, uint32_t port, char const* clientid, char const* username, char const* password);
ewf_result ewf_adapter_renesas_common_mqtt_disconnect(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket);
ewf_result ewf_adapter_renesas_common_mqtt_subscribe(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket, char const* topic);
ewf_result ewf_adapter_renesas_common_mqtt_unsubscribe(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket, char const* topic);
ewf_result ewf_adapter_renesas_common_mqtt_publish(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket, const char* topic, uint32_t length, const char* msg);
ewf_result ewf_adapter_renesas_common_mqtt_default_publish_callback(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket, const char* topic, const char* payload);

#endif /* EWF_ADAPTER_RENESAS_COMMON_MQTT_ENABLED */

/** @} *** group_adapter_renesas_common_mqtt */

/**
 * @defgroup group_adapter_renesas_common_mqtt_basic MQTT basic API implementation
 * @brief The Renesas adapter MQTT basic API
 * @{
 */

#if EWF_ADAPTER_RENESAS_COMMON_MQTT_BASIC_ENABLED

extern ewf_adapter_api_mqtt_basic ewf_adapter_renesas_common_api_mqtt_basic;

ewf_result ewf_adapter_renesas_common_mqtt_basic_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_mqtt_basic_stop(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_renesas_common_mqtt_basic_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

ewf_result ewf_adapter_renesas_common_mqtt_basic_default_state_callback(ewf_adapter* adapter_ptr, const char* state_cstr, const char* param_cstr);
ewf_result ewf_adapter_renesas_common_mqtt_basic_default_message_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr);

ewf_result ewf_adapter_renesas_common_mqtt_basic_connect(ewf_adapter* adapter_ptr, char const* server_str, uint32_t port, char const* clientid, char const* username, char const* password);
ewf_result ewf_adapter_renesas_common_mqtt_basic_disconnect(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_mqtt_basic_subscribe(ewf_adapter* adapter_ptr, char const* topic);
ewf_result ewf_adapter_renesas_common_mqtt_basic_unsubscribe(ewf_adapter* adapter_ptr, char const* topic);
ewf_result ewf_adapter_renesas_common_mqtt_basic_publish(ewf_adapter* adapter_ptr, const char* topic, const char* msg_cstr);
ewf_result ewf_adapter_renesas_common_mqtt_basic_message_get(ewf_adapter* adapter_ptr, const char* topic, char* message_buffer_ptr);

#endif /* EWF_ADAPTER_RENESAS_COMMON_MQTT_BASIC_ENABLED */

/** @} *** group_adapter_renesas_common_mqtt_basic */

/**
 * @defgroup group_adapter_renesas_common_nvm NVM functions
 * @brief The Renesas adapter NVM functions
 * @{
 */

/**
 * @brief Start the NVM operation
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_common_nvm_start(ewf_adapter* adapter_ptr);

/**
 * @brief Stop the NVM operation
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_common_nvm_stop(ewf_adapter* adapter_ptr);

/**
 * @brief NVM URC callback
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_common_nvm_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/**
 * @brief List the files in the NVM
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_common_nvm_list(ewf_adapter* adapter_ptr);

/**
 * @brief Delete a file from the NVM
 * @param filename_str the file name of the file to be deleted.
 * @param index the index of the certificate or privatekey.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_common_nvm_delete(ewf_adapter* adapter_ptr, const char* const filename_str, const char* index);

/**
 * @brief Upload a file to the NVM
 * @param filename_str the file name where the data will be uploaded.
 * @param data a pointer to a buffer with data to upload to the file system.
 * @param length the size of the data pointed by the buffer.
 * @param index the index of certificate or key in NVM.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_common_nvm_upload(ewf_adapter* adapter_ptr, const char* filename_str, const uint8_t* data, uint32_t length, const char* index);

/** @} *** group_adapter_renesas_common_nvm */

/************************************************************************//**
 * @} *** group_adapter_renesas_common_functions
 ****************************************************************************/

/************************************************************************//**
 * @} *** group_adapter_renesas_common
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_renesas_common__h__included__ */
