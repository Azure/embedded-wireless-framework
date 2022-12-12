/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework MX-CHIP EMW3080B adapter driver
 ****************************************************************************/

#ifndef __ewf_adapter_mxchip_emw3080b__h__included__
#define __ewf_adapter_mxchip_emw3080b__h__included__

#include "ewf_adapter.h"
#include "ewf_allocator.h"
#include "ewf_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_adapter_mxchip_emw3080b MX-CHIP 8266 adapter configuration
 * @ingroup group_configuration
 * @brief MX-CHIP 8266 adapter configuration
 * @{
 ****************************************************************************/

#define EWF_ADAPTER_MXCHIP_EMW3080B_TLS_BASIC_ENABLED (0)
#define EWF_ADAPTER_MXCHIP_EMW3080B_MQTT_BASIC_ENABLED (0)

#if !defined(EWF_ADAPTER_MXCHIP_EMW3080B_TLS_ENABLED) && !defined(EWF_ADAPTER_MXCHIP_EMW3080B_TLS_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_MXCHIP_EMW3080B_TLS_BASIC_ENABLED (1)
#define EWF_ADAPTER_MXCHIP_EMW3080B_TLS_ENABLED (0)
#else
#define EWF_ADAPTER_MXCHIP_EMW3080B_TLS_BASIC_ENABLED (0)
#define EWF_ADAPTER_MXCHIP_EMW3080B_TLS_ENABLED (1)
#endif
#endif

#ifndef EWF_ADAPTER_MXCHIP_EMW3080B_TCP_ENABLED
#define EWF_ADAPTER_MXCHIP_EMW3080B_TCP_ENABLED (1)
#endif

#ifndef EWF_ADAPTER_MXCHIP_EMW3080B_UDP_ENABLED
#define EWF_ADAPTER_MXCHIP_EMW3080B_UDP_ENABLED (1)
#endif

#if !defined(EWF_ADAPTER_MXCHIP_EMW3080B_MQTT_ENABLED) && !defined(EWF_ADAPTER_MXCHIP_EMW3080B_MQTT_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_MXCHIP_EMW3080B_MQTT_BASIC_ENABLED (1)
#define EWF_ADAPTER_MXCHIP_EMW3080B_MQTT_ENABLED (0)
#else
#define EWF_ADAPTER_MXCHIP_EMW3080B_MQTT_BASIC_ENABLED (0)
#define EWF_ADAPTER_MXCHIP_EMW3080B_MQTT_ENABLED (1)
#endif
#endif

/************************************************************************//**
 * @} *** group_configuration_adapter_mxchip_emw3080b
 ****************************************************************************/

/* Include the MX-CHIP common header here, to take the above configuration macros into account */
#include "ewf_adapter_mxchip_common.h"

/************************************************************************//**
 * @defgroup group_adapter_mxchip_emw3080b The MX-CHIP ESP8266 adapter driver
 * @ingroup group_adapter
 * @{
 ****************************************************************************/

/**
 * @defgroup group_adapter_mxchip_emw3080b_control Adapter control
 * @brief MX-CHIP ESP8266 adapter control API
 * @{
 */

extern ewf_adapter_api_control ewf_adapter_mxchip_emw3080b_api_control;

ewf_result ewf_adapter_mxchip_emw3080b_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_mxchip_emw3080b_stop(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_mxchip_emw3080b_control */

/**
 * @defgroup group_adapter_mxchip_emw3080b_urc URC handling
 * @brief MX-CHIP ESP8266 adapter driver URC handling
 * @{
 */

ewf_result ewf_adapter_mxchip_emw3080b_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/** @} *** group_adapter_mxchip_emw3080b_urc */

/**
 * @defgroup group_adapter_mxchip_emw3080b_info Adapter information
 * @brief MX-CHIP ESP8266 adapter driver info API
 * @{
 */

#define ewf_adapter_mxchip_emw3080b_info                          ewf_adapter_mxchip_common_info
#define ewf_adapter_mxchip_emw3080b_get_ipv4_address              ewf_adapter_mxchip_common_get_ipv4_address
#define ewf_adapter_mxchip_emw3080b_get_ipv4_netmask              ewf_adapter_mxchip_common_get_ipv4_netmask
#define ewf_adapter_mxchip_emw3080b_get_ipv4_gateway              ewf_adapter_mxchip_common_get_ipv4_gateway
#define ewf_adapter_mxchip_emw3080b_get_ipv4_dns                  ewf_adapter_mxchip_common_get_ipv4_dns

/** @} *** group_adapter_mxchip_emw3080b_info */

/**
 * @defgroup group_adapter_mxchip_emw3080b_wifi_station Adapter information
 * @brief MX-CHIP ESP8266 adapter driver WiFi station API
 * @{
 */

#define ewf_adapter_mxchip_emw3080b_wifi_station_connect          ewf_adapter_mxchip_common_wifi_station_connect
#define ewf_adapter_mxchip_emw3080b_wifi_station_disconnect       ewf_adapter_mxchip_common_wifi_station_disconnect

/** @} *** group_adapter_mxchip_emw3080b_wifi_station */

/**
 * @defgroup group_adapter_mxchip_emw3080b_internet Common internet functions (TCP+UDP)
 * @brief Functions common to TCP and UDP in the Espressif ESP8266
 * @{
 */

#define ewf_adapter_mxchip_emw3080b_internet_start                ewf_adapter_mxchip_common_internet_start
#define ewf_adapter_mxchip_emw3080b_internet_stop                 ewf_adapter_mxchip_common_internet_stop

#define ewf_adapter_mxchip_emw3080b_internet_urc_callback         ewf_adapter_mxchip_common_internet_urc_callback

/** @} *** group_adapter_mxchip_emw3080b_internet */

/**
 * @defgroup group_adapter_mxchip_emw3080b_tcp TCP API implementation
 * @brief Espressif ESP8266 adapter TCP API
 * @{
 */

#if EWF_ADAPTER_MXCHIP_EMW3080B_TCP_ENABLED

#define ewf_adapter_mxchip_emw3080b_tcp_open                      ewf_adapter_mxchip_common_tcp_open
#define ewf_adapter_mxchip_emw3080b_tcp_close                     ewf_adapter_mxchip_common_tcp_close
#define ewf_adapter_mxchip_emw3080b_tcp_control                   ewf_adapter_mxchip_common_tcp_control
#define ewf_adapter_mxchip_emw3080b_tcp_set_tls_configuration     ewf_adapter_mxchip_common_tcp_set_tls_configuration
#define ewf_adapter_mxchip_emw3080b_tcp_bind                      ewf_adapter_mxchip_common_tcp_bind
#define ewf_adapter_mxchip_emw3080b_tcp_listen                    ewf_adapter_mxchip_common_tcp_listen
#define ewf_adapter_mxchip_emw3080b_tcp_accept                    ewf_adapter_mxchip_common_tcp_accept
#define ewf_adapter_mxchip_emw3080b_tcp_connect                   ewf_adapter_mxchip_common_tcp_connect
#define ewf_adapter_mxchip_emw3080b_tcp_shutdown                  ewf_adapter_mxchip_common_tcp_shutdown
#define ewf_adapter_mxchip_emw3080b_tcp_send                      ewf_adapter_mxchip_common_tcp_send
#define ewf_adapter_mxchip_emw3080b_tcp_receive                   ewf_adapter_mxchip_common_tcp_receive

#endif /* EWF_ADAPTER_MXCHIP_EMW3080B_TCP_ENABLED */

/** @} *** group_adapter_mxchip_emw3080b_tcp */

/**
 * @defgroup group_adapter_mxchip_emw3080b_udp UDP API implementation
 * @brief Espressif ESP8266 adapter UDP API
 * @{
 */

#if EWF_ADAPTER_MXCHIP_EMW3080B_UDP_ENABLED

#define ewf_adapter_mxchip_emw3080b_udp_open                      ewf_adapter_mxchip_common_udp_open
#define ewf_adapter_mxchip_emw3080b_udp_close                     ewf_adapter_mxchip_common_udp_close
#define ewf_adapter_mxchip_emw3080b_udp_control                   ewf_adapter_mxchip_common_udp_control
#define ewf_adapter_mxchip_emw3080b_udp_set_dtls_configuration    ewf_adapter_mxchip_common_udp_set_dtls_configuration
#define ewf_adapter_mxchip_emw3080b_udp_bind                      ewf_adapter_mxchip_common_udp_bind
#define ewf_adapter_mxchip_emw3080b_udp_send_to                   ewf_adapter_mxchip_common_udp_send_to
#define ewf_adapter_mxchip_emw3080b_udp_receive_from              ewf_adapter_mxchip_common_udp_receive_from

#endif /* EWF_ADAPTER_MXCHIP_EMW3080B_UDP_ENABLED */

/** @} *** group_adapter_mxchip_emw3080b_udp */

/******************************************************************************
 *
 * Internal data
 *
 ******************************************************************************/

/**
 * @defgroup group_adapter_mxchip_emw3080b_data MX-CHIP 8266 driver internal data
 * @brief The MX-CHIP 8266 adapter internal data structure
 * @{
 */

/** @brief The MX-CHIP 8266 adapter driver data structure */
typedef struct _ewf_adapter_mxchip_emw3080b
{
    /** The MX-CHIP common data, it must be the first in the implementation structure */
    ewf_adapter_mxchip_common common_implementation_data;

} ewf_adapter_mxchip_emw3080b;

/** @} *** group_adapter_mxchip_emw3080b_data */

/**
 * @defgroup group_adapter_mxchip_emw3080b_declaration Adapter declaration and initialization
 * @brief MX-CHIP 8266 adapter declaration macros
 * @{
 */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_HEADER(adapter_ptr)                                                                                          \
do {                                                                                                                                                        \
(adapter_ptr)->struct_magic = EWF_ADAPTER_STRUCT_MAGIC;                                                                                                     \
(adapter_ptr)->struct_size = EWF_ADAPTER_STRUCT_SIZE;                                                                                                       \
(adapter_ptr)->struct_version = EWF_ADAPTER_VERSION;                                                                                                        \
(adapter_ptr)->struct_type = EWF_ADAPTER_TYPE_MXCHIP_EMW3080B;                                                                                              \
} while(0)
#else
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_HEADER(adapter_ptr)
#endif /* EWF_PARAMETER_CHECKING */

#if EWF_ADAPTER_MXCHIP_EMW3080B_TCP_ENABLED
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_TCP_API(adapter_ptr)                                                                                         \
do {                                                                                                                                                        \
adapter_ptr->tcp_api_ptr = &ewf_adapter_mxchip_common_api_tcp;                                                                                              \
} while(0)
#else
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_TCP_API(adapter_ptr)
#endif /* EWF_ADAPTER_MXCHIP_EMW3080B_TCP_ENABLED */

#if EWF_ADAPTER_MXCHIP_EMW3080B_UDP_ENABLED
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_UDP_API(adapter_ptr)                                                                                         \
do {                                                                                                                                                        \
adapter_ptr->udp_api_ptr = &ewf_adapter_mxchip_common_api_udp;                                                                                              \
} while(0)
#else
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_UDP_API(adapter_ptr)
#endif /* EWF_ADAPTER_MXCHIP_EMW3080B_UDP_ENABLED */

#if EWF_ADAPTER_MXCHIP_EMW3080B_TLS_BASIC_ENABLED
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_TLS_BASIC_API(adapter_ptr)                                                                                   \
do {                                                                                                                                                        \
adapter_ptr->tls_basic_api_ptr = &ewf_adapter_mxchip_common_api_tls_basic;                                                                                  \
} while(0)
#else
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_TLS_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_MXCHIP_EMW3080B_TLS_BASIC_ENABLED */

#if EWF_ADAPTER_MXCHIP_EMW3080B_MQTT_BASIC_ENABLED
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_MQTT_BASIC_API(adapter_ptr)                                                                                  \
do {                                                                                                                                                        \
adapter_ptr->mqtt_basic_api_ptr = &ewf_adapter_mxchip_common_api_mqtt_basic;                                                                                \
} while(0)
#else
#define EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_MQTT_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_MXCHIP_EMW3080B_MQTT_BASIC_ENABLED */

/**
 * @brief Declare a MX-CHIP 8266 adapter
 * @param[in,out] adapter_ptr a pointer to an adapter that will be initialized to point to the one statically declared by the macro
 * @param[in] adapter_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 * @param[in] message_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate command and response buffers
 * @param[in] data_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate data buffers
 * @param[in] interface_ptr_param a pointer to an interface, used by the adapter to talk with the hardware
 */
#define EWF_ADAPTER_MXCHIP_EMW3080B_STATIC_DECLARE(adapter_ptr, adapter_name_symb, message_allocator_ptr_param, data_allocator_ptr_param, interface_ptr_param) \
do {                                                                                                                                                    \
static ewf_adapter_mxchip_emw3080b ewf_adapter_mxchip_emw3080b__implementation__##adapter_name_symb = {0};                                              \
static ewf_adapter ewf_adapter_mxchip_emw3080b__##adapter_name_symb = {0};                                                                              \
interface_ptr_param->message_allocator_ptr = message_allocator_ptr_param;                                                                               \
interface_ptr_param->data_allocator_ptr = data_allocator_ptr_param;                                                                                     \
interface_ptr_param->urc_callback = ewf_adapter_mxchip_emw3080b_urc_callback;                                                                           \
ewf_adapter_mxchip_emw3080b__##adapter_name_symb.interface_ptr = interface_ptr_param;                                                                   \
ewf_adapter_mxchip_emw3080b__##adapter_name_symb.implementation_ptr = &(ewf_adapter_mxchip_emw3080b__implementation__##adapter_name_symb);              \
adapter_ptr = &(ewf_adapter_mxchip_emw3080b__##adapter_name_symb);                                                                                      \
interface_ptr_param->adapter_ptr = adapter_ptr;                                                                                                         \
EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_HEADER(adapter_ptr);                                                                                             \
ewf_adapter_mxchip_emw3080b__##adapter_name_symb.control_api_ptr = &ewf_adapter_mxchip_emw3080b_api_control;                                            \
ewf_adapter_mxchip_emw3080b__##adapter_name_symb.wifi_station_api_ptr = &ewf_adapter_mxchip_common_api_wifi_station;                                    \
ewf_adapter_mxchip_emw3080b__##adapter_name_symb.info_api_ptr = &ewf_adapter_mxchip_common_api_info;                                                    \
EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_TCP_API(adapter_ptr);                                                                                            \
EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_UDP_API(adapter_ptr);                                                                                            \
EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_TLS_BASIC_API(adapter_ptr);                                                                                      \
EWF_ADAPTER_MXCHIP_EMW3080B_INITIALIZE_MQTT_BASIC_API(adapter_ptr);                                                                                     \
} while(0)

/** @} *** group_adapter_mxchip_emw3080b_declaration */

/************************************************************************//**
 * @} *** group_adapter_mxchip_emw3080b
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_mxchip_emw3080b__h__included__ */
