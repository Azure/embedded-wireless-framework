/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Renesas RYZ014 adapter driver
 ****************************************************************************/

#ifndef __ewf_adapter_renesas_ryz014__h__included__
#define __ewf_adapter_renesas_ryz014__h__included__

#include "ewf_adapter.h"
#include "ewf_allocator.h"
#include "ewf_interface.h"
#include "ewf_adapter_api_modem.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_renesas_ryz014 The Renesas RYX014 adapter driver
 * @ingroup group_adapter
 * @brief The Renesas RYX014 adapter driver
 * @{
 ****************************************************************************/

/**
 * @defgroup group_adapter_renesas_ryz014_config Renesas RYZ014 adapter configuration
 * @ingroup group_configuration_adapter
 * @brief Renesas RYZ014 adapter configuration
 * @{
 */

#ifndef EWF_ADAPTER_RENESAS_RYZ014_NVM_ENABLED
#define EWF_ADAPTER_RENESAS_RYZ014_NVM_ENABLED (1)
#endif

#if !defined(EWF_ADAPTER_RENESAS_RYZ014_TLS_ENABLED) && !defined(EWF_ADAPTER_RENESAS_RYZ014_TLS_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_RENESAS_RYZ014_TLS_BASIC_ENABLED (1)
#define EWF_ADAPTER_RENESAS_RYZ014_TLS_ENABLED (0)
#else
#define EWF_ADAPTER_RENESAS_RYZ014_TLS_BASIC_ENABLED (0)
#define EWF_ADAPTER_RENESAS_RYZ014_TLS_ENABLED (1)
#endif
#endif

#ifndef EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED
#define EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED (1)
#endif

#ifndef EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED
#define EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED (1)
#endif

#if !defined(EWF_ADAPTER_RENESAS_RYZ014_MQTT_ENABLED) && !defined(EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED (1)
#define EWF_ADAPTER_RENESAS_RYZ014_MQTT_ENABLED (0)
#else
#define EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED (0)
#define EWF_ADAPTER_RENESAS_RYZ014_MQTT_ENABLED (1)
#endif
#endif

/** @brief The total number of supported Internet sockets in the adapter */
#define EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE (6)

/** @brief The Internet socket invalid value */
#define EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_INVALID (-1)

/** @brief The total number of supported MQTT sockets in the adapter.
 * Only one MQTT client is supported in RYZ014 */
#define EWF_ADAPTER_RENESAS_RYZ014_MQTT_SOCKET_POOL_SIZE (1)

/** @brief The MQTT socket invalid value */
#define EWF_ADAPTER_RENESAS_RYZ014_MQTT_SOCKET_INVALID (-1)

#define EWF_RYZ014_SOCKET_MAX_SEND_SIZE                        1460
#define EWF_RYZ014_SOCKET_MAX_RECEIVE_SIZE                     1500

/* Trusted Certificate Authority certificate index, range 0-19  */
#ifndef EWF_CA_CERTIFICATE_ID
#define EWF_CA_CERTIFICATE_ID                          ("10")
#endif

/* Client certificate ID, range 0-19. This index should be different that the CA certificate ID  */
#ifndef EWF_CLIENT_CERTIFICATE_ID
#define EWF_CLIENT_CERTIFICATE_ID                      ("11")
#endif

/* Client private key ID, range 0-19 */
#ifndef EWF_PRIVATE_KEY_ID
#define EWF_PRIVATE_KEY_ID                             ("11")
#endif

/* Security Profile Id , range 0-6 */
#ifndef EWF_SECURITY_PROFILE_ID
#define EWF_SECURITY_PROFILE_ID                        ("5")
#endif

/* Type of data, string */
#define  EWF_FILE_TYPE_CERTIFICATE                     ("certificate")
#define  EWF_FILE_TYPE_PRIVATEKEY                      ("privatekey")

/** @} *** group_adapter_renesas_ryz014_config */

#define EWF_CLOSE_LISTENING_SOCKET                     ("0")
#define EWF_OPEN_LISTNEING_IPV4_SOCKET                 ("1")
#define EWF_OPEN_LISTENING_IPV6_SOCKET                 ("2")
/**
 * @defgroup group_adapter_renesas_ryz014_control Adapter control
 * @brief Renesas RYZ014 adapter control API
 * @{
 */

extern ewf_adapter_api_control ewf_adapter_renesas_ryz014_api_control;

ewf_result ewf_adapter_renesas_ryz014_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_ryz014_stop(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_renesas_ryz014_control */

/**
 * @defgroup group_adapter_renesas_ryz014_info Adapter information
 * @brief The Renesas RYZ014 info API
 * @{
 */

extern ewf_adapter_api_info ewf_adapter_renesas_ryz014_api_info;

ewf_result ewf_adapter_renesas_ryz014_info(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_ryz014_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t* address_ptr);
ewf_result ewf_adapter_renesas_ryz014_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t* netmask_ptr);
ewf_result ewf_adapter_renesas_ryz014_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t* gateway_ptr);
ewf_result ewf_adapter_renesas_ryz014_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t* dns);

/** @} *** group_adapter_renesas_ryz014_info */

/**
 * @defgroup group_adapter_renesas_ryz014_urc URC handling
 * @brief Renesas RYZ014 adapter driver URC handling
 * @{
 */

ewf_result ewf_adapter_renesas_ryz014_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_renesas_ryz014_set_user_urc_callback(ewf_adapter* adapter_ptr, ewf_adapter_urc_user_callback callback);

/** @} *** group_adapter_renesas_ryz014_urc */

/**
 * @defgroup group_adapter_renesas_ryz014_tls_basic The Renesas RYZ014 adapter TLS basic API
 * @brief The Renesas RYZ014 adapter TLS basic API
 * @{
 */

#if EWF_ADAPTER_RENESAS_RYZ014_TLS_BASIC_ENABLED

extern ewf_adapter_api_tls_basic ewf_adapter_renesas_ryz014_api_tls_basic;

ewf_result ewf_adapter_renesas_ryz014_tls_basic_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_ryz014_tls_basic_stop(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_renesas_ryz014_tls_basic_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

ewf_result ewf_adapter_renesas_ryz014_tls_basic_init(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_ryz014_tls_basic_clean(ewf_adapter* adapter_ptr);

#endif /* EWF_ADAPTER_RENESAS_RYZ014_TLS_BASIC_ENABLED */

/** @} *** group_adapter_renesas_ryz014_tls_basic */

/**
 * @defgroup group_adapter_renesas_ryz014_internet Common internet functions (TCP+UDP)
 * @brief Functions common to TCP and UDP in the Quectel common internet implementation
 * @{
 */

#if EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED || EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED

ewf_result ewf_adapter_renesas_ryz014_internet_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_ryz014_internet_stop(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_renesas_ryz014_internet_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

#endif /* EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED || EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED */

/** @} *** group_adapter_renesas_ryz014_internet */

/**
 * @defgroup group_adapter_renesas_ryz014_tcp TCP API implementation
 * @brief Renesas RYZ014 adapter TCP API
 * @{
 */

#if EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED

extern ewf_adapter_api_tcp ewf_adapter_renesas_ryz014_api_tcp;

ewf_result ewf_adapter_renesas_ryz014_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_renesas_ryz014_tcp_close(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_renesas_ryz014_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);
ewf_result ewf_adapter_renesas_ryz014_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id);
ewf_result ewf_adapter_renesas_ryz014_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port);
ewf_result ewf_adapter_renesas_ryz014_tcp_listen(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_renesas_ryz014_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr);
ewf_result ewf_adapter_renesas_ryz014_tcp_connect(ewf_socket_tcp* socket_ptr, const char* const server, uint32_t port);
ewf_result ewf_adapter_renesas_ryz014_tcp_shutdown(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_renesas_ryz014_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_renesas_ryz014_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length, bool wait);

#endif /* EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED */

/** @} *** group_adapter_renesas_ryz014_tcp */

/**
 * @defgroup group_adapter_renesas_ryz014_udp UDP API implementation
 * @brief Renesas RYZ014 adapter UDP API
 * @{
 */

#if EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED

extern ewf_adapter_api_udp ewf_adapter_renesas_ryz014_api_udp;

ewf_result ewf_adapter_renesas_ryz014_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_renesas_ryz014_udp_close(ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_renesas_ryz014_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);
ewf_result ewf_adapter_renesas_ryz014_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id);
ewf_result ewf_adapter_renesas_ryz014_udp_bind(ewf_socket_udp* socket_ptr, uint32_t local_port);
ewf_result ewf_adapter_renesas_ryz014_udp_shutdown(ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_renesas_ryz014_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_renesas_ryz014_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address_str, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

#endif /* EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED */

/** @} *** group_adapter_renesas_ryz014_udp */

/**
 * @defgroup group_adapter_renesas_ryz014_mqtt MQTT API implementation
 * @brief Renesas RYZ014 adapter MQTT API
 * @{
 */

#if EWF_ADAPTER_RENESAS_RYZ014_MQTT_ENABLED

ewf_result ewf_adapter_renesas_ryz014_mqtt_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_ryz014_mqtt_stop(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_ryz014_mqtt_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

ewf_result ewf_adapter_renesas_ryz014_mqtt_connect(ewf_adapter* adapter_ptr, ewf_socket_mqtt* socket_ptr, char const* server_str, uint32_t port, char const* clientid, char const* username, char const* password);
ewf_result ewf_adapter_renesas_ryz014_mqtt_disconnect(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket);
ewf_result ewf_adapter_renesas_ryz014_mqtt_subscribe(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket, char const* topic);
ewf_result ewf_adapter_renesas_ryz014_mqtt_unsubscribe(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket, char const* topic);
ewf_result ewf_adapter_renesas_ryz014_mqtt_publish(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket, const char* topic, uint32_t length, const char* msg);
ewf_result ewf_adapter_renesas_ryz014_mqtt_default_publish_callback(ewf_adapter* adapter_ptr, ewf_socket_mqtt socket, const char* topic, const char* payload);

#endif /* EWF_ADAPTER_RENESAS_RYZ014_MQTT_ENABLED */

/** @} *** group_adapter_renesas_ryz014_mqtt */

/**
 * @defgroup group_adapter_renesas_ryz014_mqtt_basic MQTT basic API implementation
 * @brief The Renesas RYZ014 adapter MQTT basic API
 * @{
 */

#if EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED

extern ewf_adapter_api_mqtt_basic ewf_adapter_renesas_ryz014_api_mqtt_basic;

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_stop(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_default_state_callback(ewf_adapter* adapter_ptr, const char* state_cstr, const char* param_cstr);
ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_default_message_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr);

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_connect(ewf_adapter* adapter_ptr, char const* server_str, uint32_t port, char const* clientid, char const* username, char const* password);
ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_disconnect(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_subscribe(ewf_adapter* adapter_ptr, char const* topic);
ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_unsubscribe(ewf_adapter* adapter_ptr, char const* topic);
ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_publish(ewf_adapter* adapter_ptr, const char* topic, const char* msg_cstr);

#endif /* EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED */

/** @} *** group_adapter_renesas_ryz014_mqtt_basic */

/**
 * @defgroup group_adapter_renesas_ryz014_nvm NVM functions
 * @brief The Renesas RYZ014 adapter NVM functions
 * @{
 */

/**
 * @brief Start the NVM operation
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_ryz014_nvm_start(ewf_adapter* adapter_ptr);

/**
 * @brief Stop the NVM operation
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_ryz014_nvm_stop(ewf_adapter* adapter_ptr);

/**
 * @brief NVM URC callback
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_ryz014_nvm_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/**
 * @brief List the files in the NVM
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_ryz014_nvm_list(ewf_adapter* adapter_ptr);

/**
 * @brief Delete a file from the NVM
 * @param filename_str the file name of the file to be deleted.
 * @param index the index of the certificate or privatekey.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_ryz014_nvm_delete(ewf_adapter* adapter_ptr, const char* const filename_str, const char* index);

/**
 * @brief Upload a file to the NVM
 * @param filename_str the file name where the data will be uploaded.
 * @param data a pointer to a buffer with data to upload to the file system.
 * @param length the size of the data pointed by the buffer.
 * @param index the index of certificate or key in NVM.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_renesas_ryz014_nvm_upload(ewf_adapter* adapter_ptr, const char* filename_str, const uint8_t* data, uint32_t length, const char* index);

/** @} *** group_adapter_renesas_ryz014_NVM */

/******************************************************************************
 *
 * Internal data
 *
 ******************************************************************************/

/**
 * @defgroup group_adapter_renesas_ryz014_data Renesas RYZ014 driver internal data
 * @brief Renesas RYZ014 adapter data structure
 * @{
 */

/** @brief The socket service type  */
typedef enum _ewf_adapter_bg96_internet_socket_service_type
{
    ewf_adapter_renesas_ryz014_socket_service_type_not_initialized,
    ewf_adapter_renesas_ryz014_socket_service_type_tcp,
    ewf_adapter_renesas_ryz014_socket_service_type_udp,
    ewf_adapter_renesas_ryz014_socket_service_type_tcp_listener,
    ewf_adapter_renesas_ryz014_socket_service_type_udp_listener,

} ewf_adapter_renesas_ryz014_internet_socket_service_type;

/** @brief Internal structure for internet socket status  */
typedef struct _ewf_adapter_renesas_ryz014_socket
{
  uint32_t id;
  uint32_t port;
  volatile ewf_adapter_renesas_ryz014_internet_socket_service_type type;
  volatile bool used;
  volatile bool open;
  volatile bool open_error;
  volatile bool conn;
  volatile bool conn_error;
  volatile bool recv;

} ewf_adapter_renesas_ryz014_internet_socket;

/** @brief The Renesas RYZ014 adapter data structure */
typedef struct _ewf_adapter_renesas_ryz014
{
    /**< The user URC callback, called to process URC not handled by the driver */
    ewf_adapter_urc_user_callback user_urc_callback;

    /** @brief The current context ID  */
    volatile uint32_t current_context_id; /* 0 is uninitialize or invalid  */

#if EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED || EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED
    /**< The internal pool of internet sockets */
    ewf_adapter_renesas_ryz014_internet_socket internet_socket_pool [EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE];
#endif

#if EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED
    /** @brief Internal MQTT basic API socket 0 status  */
    volatile bool mqtt_basic_conn;
    volatile bool mqtt_basic_conn_error;
    volatile bool mqtt_basic_publish;
    volatile bool mqtt_basic_subscribe;

#endif /* EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED */

    /* Module status */
    volatile bool module_start;

    /**< The TCP receive callback */
    ewf_adapter_tcp_receive_callback tcp_receive_callback;

    /**< The UDP receive callback */
    ewf_adapter_udp_receive_callback udp_receive_callback;

    /**< The MQTT message callback */
    ewf_adapter_mqtt_message_callback mqtt_message_callback;

} ewf_adapter_renesas_ryz014;

/** @} *** group_adapter_renesas_ryz014_state */

/**
 * @defgroup group_adapter_ryz014_declaration Adapter declaration and initialization
 * @brief Renesas RYZ014 adapter declaration macros
 * @{
 */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_HEADER(adapter_ptr)                                                                                                   \
do {                                                                                                                                                                \
(adapter_ptr)->struct_magic = EWF_ADAPTER_STRUCT_MAGIC;                                                                                                             \
(adapter_ptr)->struct_size = EWF_ADAPTER_STRUCT_SIZE;                                                                                                               \
(adapter_ptr)->struct_version = EWF_ADAPTER_VERSION;                                                                                                                \
(adapter_ptr)->struct_type = EWF_ADAPTER_TYPE_RENESAS_RYZ014;                                                                                                       \
} while(0)
#else
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_HEADER(adapter_ptr)
#endif /* EWF_PARAMETER_CHECKING */

#if EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_TCP_API(adapter_ptr)                                                                                                  \
do {                                                                                                                                                                \
adapter_ptr->tcp_api_ptr = &ewf_adapter_renesas_ryz014_api_tcp;                                                                                                     \
} while(0)
#else
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_TCP_API(adapter_ptr)
#endif /* EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED */

#if EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_UDP_API(adapter_ptr)                                                                                                  \
do {                                                                                                                                                                \
adapter_ptr->udp_api_ptr = &ewf_adapter_renesas_ryz014_api_udp;                                                                                                     \
} while(0)
#else
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_UDP_API(adapter_ptr)
#endif /* EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED */

#if EWF_ADAPTER_RENESAS_RYZ014_TLS_BASIC_ENABLED
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_TLS_BASIC_API(adapter_ptr)                                                                                            \
do {                                                                                                                                                                \
adapter_ptr->tls_basic_api_ptr = &ewf_adapter_renesas_ryz014_api_tls_basic;                                                                                         \
} while(0)
#else
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_TLS_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_RENESAS_RYZ014_TLS_BASIC_ENABLED */

#if EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_MQTT_BASIC_API(adapter_ptr)                                                                                           \
do {                                                                                                                                                                \
adapter_ptr->mqtt_basic_api_ptr = &ewf_adapter_renesas_ryz014_api_mqtt_basic;                                                                                       \
} while(0)
#else
#define EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_MQTT_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED */

 /**
  * @brief Declare a Renesas RYZ014 adapter
  * @param[in,out] adapter_ptr a pointer to an adapter that will be initialized to point to the one statically declared by the macro
  * @param[in] adapter_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
  * @param[in] message_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate command and response buffers
  * @param[in] data_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate data buffers
  * @param[in] interface_ptr_param a pointer to an interface, used by the adapter to talk with the hardware
  */
#define EWF_ADAPTER_RENESAS_RYZ014_STATIC_DECLARE(adapter_ptr, adapter_name_symb, message_allocator_ptr_param, data_allocator_ptr_param, interface_ptr_param)       \
do {                                                                                                                                                                \
static ewf_adapter_renesas_ryz014 ewf_adapter_renesas_ryz014__implementation__##adapter_name_symb = {0};                                                            \
static ewf_adapter ewf_adapter_renesas_ryz014__adapter__##adapter_name_symb = {0};                                                                                  \
interface_ptr_param->message_allocator_ptr = message_allocator_ptr_param;                                                                                           \
interface_ptr_param->data_allocator_ptr = data_allocator_ptr_param;                                                                                                 \
interface_ptr_param->urc_callback = ewf_adapter_renesas_ryz014_urc_callback;                                                                                        \
ewf_adapter_renesas_ryz014__adapter__##adapter_name_symb.interface_ptr = interface_ptr_param;                                                                       \
ewf_adapter_renesas_ryz014__adapter__##adapter_name_symb.implementation_ptr = &(ewf_adapter_renesas_ryz014__implementation__##adapter_name_symb);                   \
adapter_ptr = &(ewf_adapter_renesas_ryz014__adapter__##adapter_name_symb);                                                                                          \
interface_ptr_param->adapter_ptr = adapter_ptr;                                                                                                                     \
ewf_adapter_renesas_ryz014__adapter__##adapter_name_symb.control_api_ptr = &ewf_adapter_renesas_ryz014_api_control;                                                 \
ewf_adapter_renesas_ryz014__adapter__##adapter_name_symb.info_api_ptr = &ewf_adapter_renesas_ryz014_api_info;                                                       \
EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_TCP_API(adapter_ptr);                                                                                                         \
EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_UDP_API(adapter_ptr);                                                                                                         \
EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_HEADER(adapter_ptr);                                                                                                          \
EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_TLS_BASIC_API(adapter_ptr);                                                                                                   \
EWF_ADAPTER_RENESAS_RYZ014_INITIALIZE_MQTT_BASIC_API(adapter_ptr);                                                                                                  \
} while(0)

/** @} *** group_adapter_renesas_ryz014_declaration */

/************************************************************************//**
 * @} *** group_adapter_renesas_ryz014
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_renesas_ryz014__h__included__ */
