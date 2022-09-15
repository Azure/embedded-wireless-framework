/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework WinSock2 adapter driver
 ****************************************************************************/

#ifndef __ewf_adapter_winsock2__h__included__
#define __ewf_adapter_winsock2__h__included__

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#include <WindowsX.h>
#include <iphlpapi.h>

#include "ewf_adapter.h"
#include "ewf_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_adapter_winsock2 WinSock2 adapter configuration
 * @ingroup group_configuration_adapter
 * @ingroup group_adapter_winsock2
 * @brief WinSock2 adapter configuration
 * @{
 ****************************************************************************/

#ifndef EWF_ADAPTER_WINSOCK2_TCP_ENABLED
#define EWF_ADAPTER_WINSOCK2_TCP_ENABLED        (1)
#endif

#ifndef EWF_ADAPTER_WINSOCK2_UDP_ENABLED
#define EWF_ADAPTER_WINSOCK2_UDP_ENABLED        (1)
#endif

/************************************************************************//**
 * @} *** group_configuration_adapter_winsock2
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_adapter_winsock2 The WinSock2 adapter driver
 * @ingroup group_adapter
 * @{
 ****************************************************************************/

/**
 * @defgroup group_adapter_winsock2_control The WinSock2 adapter control API
 * @brief The WinSock2 adapter control API
 * @{
 */

extern ewf_adapter_api_control ewf_adapter_winsock2_api_control;

ewf_result ewf_adapter_winsock2_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_winsock2_stop(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_winsock2_control */

/**
 * @defgroup group_adapter_winsock2_info The WinSock2 adapter info API
 * @brief The WinSock2 adapter info API
 * @{
 */

extern ewf_adapter_api_info ewf_adapter_winsock2_api_info;

ewf_result ewf_adapter_winsock2_info(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_winsock2_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t* address_ptr);
ewf_result ewf_adapter_winsock2_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t* netmask_ptr);
ewf_result ewf_adapter_winsock2_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t* gateway_ptr);
ewf_result ewf_adapter_winsock2_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t* dns);

/** @} *** group_adapter_winsock2_info */

/**
 * @defgroup group_adapter_winsock2_tcp TCP API implementation
 * @brief WinSock2 adapter TCP API
 * @{
 */

#if EWF_ADAPTER_WINSOCK2_TCP_ENABLED

extern ewf_adapter_api_tcp ewf_adapter_winsock2_api_tcp;

ewf_result ewf_adapter_winsock2_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_winsock2_tcp_close(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_winsock2_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);
ewf_result ewf_adapter_winsock2_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id);
ewf_result ewf_adapter_winsock2_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port);
ewf_result ewf_adapter_winsock2_tcp_listen(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_winsock2_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr);
ewf_result ewf_adapter_winsock2_tcp_connect(ewf_socket_tcp* socket_ptr, const char* const server, uint32_t port);
ewf_result ewf_adapter_winsock2_tcp_shutdown(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_winsock2_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_winsock2_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length, bool wait);

#endif /* EWF_ADAPTER_WINSOCK2_TCP_ENABLED */

/** @} *** group_adapter_winsock2_tcp */

/**
 * @defgroup group_adapter_winsock2_udp UDP API implementation
 * @brief WinSock2 adapter UDP API
 * @{
 */

#if EWF_ADAPTER_WINSOCK2_UDP_ENABLED

extern ewf_adapter_api_udp ewf_adapter_winsock2_api_udp;

ewf_result ewf_adapter_winsock2_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_winsock2_udp_close(ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_winsock2_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);
ewf_result ewf_adapter_winsock2_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id);
ewf_result ewf_adapter_winsock2_udp_bind(ewf_socket_udp* socket_ptr, uint32_t port);
ewf_result ewf_adapter_winsock2_udp_shutdown(ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_winsock2_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_winsock2_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

#endif /* EWF_ADAPTER_WINSOCK2_UDP_ENABLED */

/** @} *** group_adapter_winsock2_udp */

/******************************************************************************
 *
 * Internal data
 *
 ******************************************************************************/

/**
 * @defgroup group_adapter_winsock2_data The WinSock2 adapter driver internal data
 * @brief The WinSock2 adapter driver data structures
 * @{
 */

/** @brief Internal structure for socket status  */
typedef struct _ewf_adapter_winsock2_socket
{
    volatile SOCKET s;

} ewf_adapter_winsock2_socket;

/** @brief The WinSock2 adapter driver data structure */
typedef struct _ewf_adapter_winsock2
{
    WSADATA wsaData;
    IN_ADDR ipv4_address;
    IN_ADDR ipv4_netmask;
    IN_ADDR ipv4_gateway;
    IN_ADDR ipv4_dns;

} ewf_adapter_winsock2;

/** @} *** group_adapter_winsock2_data */

/**
 * @defgroup group_adapter_winsock2_declaration Adapter declaration and initialization
 * @brief WinSock2 adapter declaration macros
 * @{
 */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_HEADER(adapter_ptr)                                                                                                     \
do {                                                                                                                                                            \
(adapter_ptr)->struct_magic = EWF_ADAPTER_STRUCT_MAGIC;                                                                                                         \
(adapter_ptr)->struct_size = EWF_ADAPTER_STRUCT_SIZE;                                                                                                           \
(adapter_ptr)->struct_version = EWF_ADAPTER_VERSION;                                                                                                            \
(adapter_ptr)->struct_type = EWF_ADAPTER_TYPE_WINSOCK2;                                                                                                         \
} while(0)
#else
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_HEADER(adapter_ptr)
#endif /* EWF_PARAMETER_CHECKING */

#if EWF_ADAPTER_WINSOCK2_TCP_ENABLED
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_TCP_API(adapter_ptr)                                                                                                    \
do {                                                                                                                                                            \
adapter_ptr->tcp_api_ptr = &ewf_adapter_winsock2_api_tcp;                                                                                                       \
} while(0)
#else
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_TCP_API(adapter_ptr)
#endif /* EWF_ADAPTER_WINSOCK2_TCP_ENABLED */

#if EWF_ADAPTER_WINSOCK2_UDP_ENABLED
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_UDP_API(adapter_ptr)                                                                                                    \
do {                                                                                                                                                            \
adapter_ptr->udp_api_ptr = &ewf_adapter_winsock2_api_udp;                                                                                                       \
} while(0)
#else
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_UDP_API(adapter_ptr)
#endif /* EWF_ADAPTER_WINSOCK2_UDP_ENABLED */

#if EWF_ADAPTER_WINSOCK2_TLS_BASIC_ENABLED
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_TLS_BASIC_API(adapter_ptr)                                                                                              \
do {                                                                                                                                                            \
adapter_ptr->tls_basic_api_ptr = &ewf_adapter_winsock2_api_tls_basic;                                                                                           \
} while(0)
#else
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_TLS_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_WINSOCK2_TLS_BASIC_ENABLED */

#if EWF_ADAPTER_WINSOCK2_MQTT_BASIC_ENABLED
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_MQTT_BASIC_API(adapter_ptr)                                                                                             \
do {                                                                                                                                                            \
adapter_ptr->mqtt_basic_api_ptr = &ewf_adapter_winsock2_api_mqtt_basic;                                                                                         \
} while(0)
#else
#define EWF_ADAPTER_WINSOCK2_INITIALIZE_MQTT_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_WINSOCK2_MQTT_BASIC_ENABLED */

/**
 * @brief Declare a WinSock2 adapter
 * @param[in,out] adapter_ptr a pointer to an adapter that will be initialized to point to the one statically declared by the macro
 * @param[in] adapter_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 * @param[in] data_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate data buffers
 */
#define EWF_ADAPTER_WINSOCK2_STATIC_DECLARE(adapter_ptr, adapter_name_symb, data_allocator_ptr_param)                                                           \
do {                                                                                                                                                            \
static ewf_adapter_winsock2 ewf_adapter_winsock2__implementation__##adapter_name_symb = {0};                                                                    \
static ewf_adapter ewf_adapter_winsock2__##adapter_name_symb = {0};                                                                                             \
ewf_adapter_winsock2__##adapter_name_symb.implementation_ptr = &(ewf_adapter_winsock2__implementation__##adapter_name_symb);                                    \
adapter_ptr = &(ewf_adapter_winsock2__##adapter_name_symb);                                                                                                     \
EWF_ADAPTER_WINSOCK2_INITIALIZE_HEADER(adapter_ptr);                                                                                                            \
ewf_adapter_winsock2__##adapter_name_symb.control_api_ptr = &ewf_adapter_winsock2_api_control;                                                                  \
ewf_adapter_winsock2__##adapter_name_symb.info_api_ptr = &ewf_adapter_winsock2_api_info;                                                                        \
EWF_ADAPTER_WINSOCK2_INITIALIZE_TCP_API(adapter_ptr);                                                                                                           \
EWF_ADAPTER_WINSOCK2_INITIALIZE_UDP_API(adapter_ptr);                                                                                                           \
EWF_ADAPTER_WINSOCK2_INITIALIZE_TLS_BASIC_API(adapter_ptr);                                                                                                     \
EWF_ADAPTER_WINSOCK2_INITIALIZE_MQTT_BASIC_API(adapter_ptr);                                                                                                    \
} while(0)

/** @} *** group_adapter_winsock2_data */

/************************************************************************//**
 * @} *** group_adapter_winsock2
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_winsock2__h__included__ */
