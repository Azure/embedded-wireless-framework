/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Espressif common adapter API
 ****************************************************************************/

#ifndef __ewf_adapter_espressif_common__h__included__
#define __ewf_adapter_espressif_common__h__included__

#include "ewf_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_espressif_common Espressif generic adapter functions
 * @ingroup group_adapter
 * @{
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_configuration_adapter_espressif_common Espressif common configuration
 * @ingroup group_configuration
 * @brief Espressif common adapter configuration
 * @{
 ****************************************************************************/

#define EWF_ADAPTER_ESPRESSIF_COMMON_TLS_BASIC_ENABLED (0)
#define EWF_ADAPTER_ESPRESSIF_COMMON_MQTT_BASIC_ENABLED (0)

#if !defined(EWF_ADAPTER_ESPRESSIF_COMMON_TLS_ENABLED) && !defined(EWF_ADAPTER_ESPRESSIF_COMMON_TLS_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_ESPRESSIF_COMMON_TLS_BASIC_ENABLED (1)
#define EWF_ADAPTER_ESPRESSIF_COMMON_TLS_ENABLED (0)
#else
#define EWF_ADAPTER_ESPRESSIF_COMMON_TLS_BASIC_ENABLED (0)
#define EWF_ADAPTER_ESPRESSIF_COMMON_TLS_ENABLED (1)
#endif
#endif

#ifndef EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED
#define EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED (1)
#endif

#ifndef EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED
#define EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED (1)
#endif

#ifndef EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_POOL_SIZE
/** @brief The total number of supported internet sockets in the adapter */
#define EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_POOL_SIZE (5)
#endif

#ifndef EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE
/** @brief The total number of supported internet sockets in the adapter */
#define EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE (1500)
#endif

#ifndef EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_INVALID
/** @brief The internet socket invalid value */
#define EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_INVALID (-1)
#endif

/************************************************************************//**
 * @} *** group_configuration_adapter_espressif_common
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_adapter_espressif_common_data Espressif common driver internal data
 * @brief Espressif common adapter data structure
 * @{
 ****************************************************************************/

/** @brief The socket service type  */
typedef enum _ewf_adapter_common_internet_socket_service_type
{
    ewf_adapter_espressif_common_internet_socket_service_type_not_initialized,
    ewf_adapter_espressif_common_internet_socket_service_type_tcp,
    ewf_adapter_espressif_common_internet_socket_service_type_udp,
    ewf_adapter_espressif_common_internet_socket_service_type_tcp_listener,
    ewf_adapter_espressif_common_internet_socket_service_type_udp_listener,

} ewf_adapter_espressif_common_internet_socket_service_type;

/** @brief Internal structure for internet socket status  */
typedef struct _ewf_adapter_espressif_common_internet_socket
{
    uint32_t id;
    uint32_t port;
    volatile ewf_adapter_espressif_common_internet_socket_service_type type;
    volatile bool used;
    volatile bool open;
    volatile bool open_error;
    volatile bool conn;
    volatile bool conn_error;
    volatile bool recv;
    uint32_t recv_size;
    uint8_t recv_buffer[EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE];

} ewf_adapter_espressif_common_internet_socket;

/** @brief The ESPRESSIF common adapter data structure */
typedef struct _ewf_adapter_espressif_common
{
    int dummy;

#if EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED || EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED
    /**< true if passive mode is supported and enabled */
    bool passive_mode;
    /**< The internal pool of internet sockets */
    ewf_adapter_espressif_common_internet_socket internet_socket_pool[EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_POOL_SIZE];
#endif

} ewf_adapter_espressif_common;

/************************************************************************//**
 * @} *** group_adapter_espressif_common_data
 ****************************************************************************/

/**
 * @defgroup group_adapter_espressif_common_control Adapter control
 * @brief Espressif adapter control API
 * @{
 */

extern ewf_adapter_api_control ewf_adapter_espressif_common_api_control;

ewf_result ewf_adapter_espressif_common_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_espressif_common_stop(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_espressif_common_control */

/**
 * @defgroup group_adapter_espressif_common_info Adapter information
 * @brief Espressif adapter driver info API
 * @{
 */

extern ewf_adapter_api_info ewf_adapter_espressif_common_api_info;

ewf_result ewf_adapter_espressif_common_info(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_espressif_common_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t* address_ptr);
ewf_result ewf_adapter_espressif_common_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t* netmask_ptr);
ewf_result ewf_adapter_espressif_common_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t* gateway_ptr);
ewf_result ewf_adapter_espressif_common_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t* dns);

/** @} *** group_adapter_espressif_common_info */

/**
 * @defgroup group_adapter_espressif_common_urc URC handling
 * @brief Espressif adapter driver URC handling
 * @{
 */

ewf_result ewf_adapter_espressif_common_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/** @} *** group_adapter_espressif_common_urc */

/**
 * @defgroup group_adapter_espressif_common_wifi_station Espressif WiFi adapter station API
 * @brief Espressif WiFi adapter driver station API
 * @{
 */

extern ewf_adapter_wifi_station_api ewf_adapter_espressif_common_api_wifi_station;

ewf_result ewf_adapter_espressif_common_wifi_station_connect(ewf_adapter* adapter_ptr, const char* ssid_str, const char* password_str);
ewf_result ewf_adapter_espressif_common_wifi_station_disconnect(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_espressif_common_wifi_station */

/**
 * @defgroup group_adapter_espressif_common_internet Common internet functions (TCP+UDP)
 * @brief Functions common to TCP and UDP in the Espressif common internet implementation
 * @{
 */

#if EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED || EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED

ewf_result ewf_adapter_espressif_common_internet_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_espressif_common_internet_stop(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_espressif_common_internet_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

#endif /* EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED || EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED */

/** @} *** group_adapter_espressif_common_internet */

/**
 * @defgroup group_adapter_espressif_common_tcp TCP API implementation
 * @brief Espressif common adapter TCP API
 * @{
 */

#if EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED

extern ewf_adapter_api_tcp ewf_adapter_espressif_common_api_tcp;

ewf_result ewf_adapter_espressif_common_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_espressif_common_tcp_close(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_espressif_common_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);
ewf_result ewf_adapter_espressif_common_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id);
ewf_result ewf_adapter_espressif_common_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port);
ewf_result ewf_adapter_espressif_common_tcp_listen(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_espressif_common_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr);
ewf_result ewf_adapter_espressif_common_tcp_connect(ewf_socket_tcp* socket_ptr, const char* const server, uint32_t port);
ewf_result ewf_adapter_espressif_common_tcp_shutdown(ewf_socket_tcp* socket_ptr);
ewf_result ewf_adapter_espressif_common_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_espressif_common_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length, bool wait);

#endif /* EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED */

/** @} *** group_adapter_espressif_common_tcp */

/**
 * @defgroup group_adapter_espressif_common_udp UDP API implementation
 * @brief Espressif common adapter UDP API
 * @{
 */

#if EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED

extern ewf_adapter_api_udp ewf_adapter_espressif_common_api_udp;

ewf_result ewf_adapter_espressif_common_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_espressif_common_udp_close(ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_espressif_common_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);
ewf_result ewf_adapter_espressif_common_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id);
ewf_result ewf_adapter_espressif_common_udp_bind(ewf_socket_udp* socket_ptr, uint32_t port);
ewf_result ewf_adapter_espressif_common_udp_shutdown(ewf_socket_udp* socket_ptr);
ewf_result ewf_adapter_espressif_common_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_espressif_common_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

#endif /* EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED */

/** @} *** group_adapter_espressif_common_udp */

/************************************************************************//**
 * @} *** group_adapter_espressif_common
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_espressif_common__h__included__ */
