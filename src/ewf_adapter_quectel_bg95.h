/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel BG95 adapter driver
 ****************************************************************************/

#ifndef __ewf_adapter_quectel_bg95__h__included__
#define __ewf_adapter_quectel_bg95__h__included__

#include "ewf_adapter.h"
#include "ewf_allocator.h"
#include "ewf_interface.h"
#include "ewf_adapter_api_modem.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_adapter_quectel_bg95 Quectel BG95 adapter configuration
 * @ingroup group_adapter_quectel_bg95
 * @ingroup group_configuration
 * @brief Quectel BG95 adapter configuration
 * @{
 ****************************************************************************/

#ifndef EWF_ADAPTER_QUECTEL_BG95_UFS_ENABLED
#define EWF_ADAPTER_QUECTEL_BG95_UFS_ENABLED (1)
#endif

#if !defined(EWF_ADAPTER_QUECTEL_BG95_TLS_ENABLED) && !defined(EWF_ADAPTER_QUECTEL_BG95_TLS_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_QUECTEL_BG95_TLS_BASIC_ENABLED (1)
#define EWF_ADAPTER_QUECTEL_BG95_TLS_ENABLED (0)
#else
#define EWF_ADAPTER_QUECTEL_BG95_TLS_BASIC_ENABLED (0)
#define EWF_ADAPTER_QUECTEL_BG95_TLS_ENABLED (1)
#endif
#endif

#ifndef EWF_ADAPTER_QUECTEL_BG95_TCP_ENABLED
#define EWF_ADAPTER_QUECTEL_BG95_TCP_ENABLED (1)
#endif

#ifndef EWF_ADAPTER_QUECTEL_BG95_UDP_ENABLED
#define EWF_ADAPTER_QUECTEL_BG95_UDP_ENABLED (1)
#endif

#if !defined(EWF_ADAPTER_QUECTEL_BG95_MQTT_ENABLED) && !defined(EWF_ADAPTER_QUECTEL_BG95_MQTT_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_QUECTEL_BG95_MQTT_BASIC_ENABLED (1)
#define EWF_ADAPTER_QUECTEL_BG95_MQTT_ENABLED (0)
#else
#define EWF_ADAPTER_QUECTEL_BG95_MQTT_BASIC_ENABLED (0)
#define EWF_ADAPTER_QUECTEL_BG95_MQTT_ENABLED (1)
#endif
#endif

/************************************************************************//**
 * @} *** group_configuration_adapter_quectel_bg95
 ****************************************************************************/

/* Include the Quectel common header here, to take the above configuration macros into account */
#include "ewf_adapter_quectel_common.h"

/************************************************************************//**
 * @defgroup group_adapter_quectel_bg95 The Quectel BG95 modem adapter driver
 * @ingroup group_adapter
 * @{
 ****************************************************************************/

/**
 * @defgroup group_adapter_quectel_bg95_control Adapter control
 * @brief Quectel BG95 adapter control API
 * @{
 */

extern ewf_adapter_api_control ewf_adapter_quectel_bg95_api_control;

ewf_result ewf_adapter_quectel_bg95_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_quectel_bg95_stop(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_quectel_bg95_control */

/**
 * @defgroup group_adapter_quectel_bg95_urc URC handling
 * @brief Quectel BG95 adapter driver URC handling
 * @{
 */

ewf_result ewf_adapter_quectel_bg95_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/** @} *** group_adapter_quectel_bg95_urc */

/**
 * @defgroup group_adapter_quectel_bg95_info Adapter information
 * @brief Quectel BG95 adapter driver info API
 * @{
 */

#define ewf_adapter_quectel_bg95_info                       ewf_adapter_quectel_common_info
#define ewf_adapter_quectel_bg95_get_ipv4_address           ewf_adapter_quectel_common_get_ipv4_address
#define ewf_adapter_quectel_bg95_get_ipv4_netmask           ewf_adapter_quectel_common_get_ipv4_netmask
#define ewf_adapter_quectel_bg95_get_ipv4_gateway           ewf_adapter_quectel_common_get_ipv4_gateway
#define ewf_adapter_quectel_bg95_get_ipv4_dns               ewf_adapter_quectel_common_get_ipv4_dns

/** @} *** group_adapter_quectel_bg95_info */

/**
 * @defgroup group_adapter_quectel_bg95_context Context activation, deactivation and configuration
 * @brief Quectel adapter driver context API
 * @{
 */

#define ewf_adapter_quectel_bg95_context_start              ewf_adapter_quectel_common_context_start
#define ewf_adapter_quectel_bg95_context_stop               ewf_adapter_quectel_common_context_stop

#define ewf_adapter_quectel_bg95_context_urc_callback       ewf_adapter_quectel_common_context_urc_callback

#define ewf_adapter_quectel_bg95_context_activate           ewf_adapter_quectel_common_context_activate
#define ewf_adapter_quectel_bg95_context_deactivate         ewf_adapter_quectel_common_context_deactivate
#define ewf_adapter_quectel_bg95_context_configure          ewf_adapter_quectel_common_context_configure
#define ewf_adapter_quectel_bg95_context_configure_dns      ewf_adapter_quectel_common_context_configure_dns

/** @} *** group_adapter_quectel_bg95_context */

/**
 * @defgroup group_adapter_quectel_bg95_ufs User File System (UFS) API
 * @brief Functions to use the modem's User File System (UFS)
 * @{
 */

#if EWF_ADAPTER_QUECTEL_BG95_UFS_ENABLED

#define ewf_adapter_quectel_bg95_ufs_start                  ewf_adapter_quectel_common_ufs_start
#define ewf_adapter_quectel_bg95_ufs_stop                   ewf_adapter_quectel_common_ufs_stop

#define ewf_adapter_quectel_bg95_ufs_urc_callback           ewf_adapter_quectel_common_ufs_urc_callback

#define ewf_adapter_quectel_bg95_ufs_list                   ewf_adapter_quectel_common_ufs_list
#define ewf_adapter_quectel_bg95_ufs_delete                 ewf_adapter_quectel_common_ufs_delete
#define ewf_adapter_quectel_bg95_ufs_upload                 ewf_adapter_quectel_common_ufs_upload

#endif /* EWF_ADAPTER_QUECTEL_BG95_UFS_ENABLED */

/** @} *** group_adapter_quectel_bg95_ufs */

/**
 * @defgroup group_adapter_quectel_bg95_tls_basic The Quectel BG95 adapter TLS basic API
 * @brief The Quectel BG95 adapter TLS basic API
 * @{
 */

#if EWF_ADAPTER_QUECTEL_BG95_TLS_BASIC_ENABLED

#define ewf_adapter_quectel_bg95_tls_basic_start            ewf_adapter_quectel_common_tls_basic_start
#define ewf_adapter_quectel_bg95_tls_basic_stop             ewf_adapter_quectel_common_tls_basic_stop

#define ewf_adapter_quectel_bg95_tls_basic_urc_callback     ewf_adapter_quectel_common_tls_basic_urc_callback

#define ewf_adapter_quectel_bg95_tls_basic_init             ewf_adapter_quectel_common_tls_basic_init
#define ewf_adapter_quectel_bg95_tls_basic_clean            ewf_adapter_quectel_common_tls_basic_clean

#endif /* EWF_ADAPTER_QUECTEL_BG95_TLS_BASIC_ENABLED */

/** @} *** group_adapter_quectel_bg95_tls_basic */

/**
 * @defgroup group_adapter_quectel_bg95_internet Common internet functions (TCP+UDP)
 * @brief Functions common to TCP and UDP in the Quectel BG95
 * @{
 */

#define ewf_adapter_quectel_bg95_internet_start             ewf_adapter_quectel_common_internet_start
#define ewf_adapter_quectel_bg95_internet_stop              ewf_adapter_quectel_common_internet_stop

#define ewf_adapter_quectel_bg95_internet_urc_callback      ewf_adapter_quectel_common_internet_urc_callback

/** @} *** group_adapter_quectel_bg95_internet */

/**
 * @defgroup group_adapter_quectel_bg95_tcp TCP API implementation
 * @brief Quectel BG95 adapter TCP API
 * @{
 */

#if EWF_ADAPTER_QUECTEL_BG95_TCP_ENABLED

#define ewf_adapter_quectel_bg95_tcp_open                   ewf_adapter_quectel_common_tcp_open
#define ewf_adapter_quectel_bg95_tcp_close                  ewf_adapter_quectel_common_tcp_close
#define ewf_adapter_quectel_bg95_tcp_control                ewf_adapter_quectel_common_tcp_control
#define ewf_adapter_quectel_bg95_tcp_set_tls_configuration  ewf_adapter_quectel_common_tcp_set_tls_configuration
#define ewf_adapter_quectel_bg95_tcp_bind                   ewf_adapter_quectel_common_tcp_bind
#define ewf_adapter_quectel_bg95_tcp_listen                 ewf_adapter_quectel_common_tcp_listen
#define ewf_adapter_quectel_bg95_tcp_accept                 ewf_adapter_quectel_common_tcp_accept
#define ewf_adapter_quectel_bg95_tcp_connect                ewf_adapter_quectel_common_tcp_connect
#define ewf_adapter_quectel_bg95_tcp_shutdown               ewf_adapter_quectel_common_tcp_shutdown
#define ewf_adapter_quectel_bg95_tcp_send                   ewf_adapter_quectel_common_tcp_send
#define ewf_adapter_quectel_bg95_tcp_receive                ewf_adapter_quectel_common_tcp_receive

#endif /* EWF_ADAPTER_QUECTEL_BG95_TCP_ENABLED */

/** @} *** group_adapter_quectel_bg95_tcp */

/**
 * @defgroup group_adapter_quectel_bg95_udp UDP API implementation
 * @brief Quectel BG95 adapter UDP API
 * @{
 */

#if EWF_ADAPTER_QUECTEL_BG95_UDP_ENABLED

#define ewf_adapter_quectel_bg95_udp_open                   ewf_adapter_quectel_common_udp_open
#define ewf_adapter_quectel_bg95_udp_close                  ewf_adapter_quectel_common_udp_close
#define ewf_adapter_quectel_bg95_udp_control                ewf_adapter_quectel_common_udp_control
#define ewf_adapter_quectel_bg95_udp_set_dtls_configuration ewf_adapter_quectel_common_udp_set_dtls_configuration
#define ewf_adapter_quectel_bg95_udp_bind                   ewf_adapter_quectel_common_udp_bind
#define ewf_adapter_quectel_bg95_udp_send_to                ewf_adapter_quectel_common_udp_send_to
#define ewf_adapter_quectel_bg95_udp_receive_from           ewf_adapter_quectel_common_udp_receive_from

#endif /* EWF_ADAPTER_QUECTEL_BG95_UDP_ENABLED */

/** @} *** group_adapter_quectel_bg95_udp */

/**
 * @defgroup group_adapter_quectel_bg95_mqtt MQTT API implementation
 * @brief Quectel BG95 adapter MQTT API
 * @{
 */

#if EWF_ADAPTER_QUECTEL_BG95_MQTT_ENABLED

ewf_result ewf_adapter_quectel_bg95_mqtt_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_quectel_bg95_mqtt_stop(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_quectel_bg95_mqtt_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

#endif /* EWF_ADAPTER_QUECTEL_BG95_MQTT_ENABLED */

/** @} *** group_adapter_quectel_bg95_mqtt */

/**
 * @defgroup group_adapter_quectel_bg95_mqtt_basic MQTT basic API implementation
 * @brief Quectel BG95 adapter MQTT basic API
 * @{
 */

#if EWF_ADAPTER_QUECTEL_BG95_MQTT_BASIC_ENABLED

#define ewf_adapter_quectel_bg95_mqtt_basic_start                           ewf_adapter_quectel_common_mqtt_basic_start
#define ewf_adapter_quectel_bg95_mqtt_basic_stop                            ewf_adapter_quectel_common_mqtt_basic_stop

#define ewf_adapter_quectel_bg95_mqtt_basic_urc_callback                    ewf_adapter_quectel_common_mqtt_basic_urc_callback

#define ewf_adapter_quectel_bg95_mqtt_basic_default_state_callback          ewf_adapter_quectel_common_mqtt_basic_default_state_callback
#define ewf_adapter_quectel_bg95_mqtt_basic_default_message_callback        ewf_adapter_quectel_common_mqtt_basic_default_message_callback

#define ewf_adapter_quectel_bg95_mqtt_basic_connect                         ewf_adapter_quectel_common_mqtt_basic_connect
#define ewf_adapter_quectel_bg95_mqtt_basic_disconnect                      ewf_adapter_quectel_common_mqtt_basic_disconnect
#define ewf_adapter_quectel_bg95_mqtt_basic_subscribe                       ewf_adapter_quectel_common_mqtt_basic_subscribe
#define ewf_adapter_quectel_bg95_mqtt_basic_unsubscribe                     ewf_adapter_quectel_common_mqtt_basic_unsubscribe
#define ewf_adapter_quectel_bg95_mqtt_basic_publish                         ewf_adapter_quectel_common_mqtt_basic_publish

#endif /* EWF_ADAPTER_QUECTEL_BG95_MQTT_BASIC_ENABLED */

/** @} *** group_adapter_quectel_bg95_mqtt_basic */

/******************************************************************************
 *
 * Internal data
 *
 ******************************************************************************/

/**
 * @defgroup group_adapter_quectel_bg95_data Quectel BG95 driver internal data
 * @brief The Quectel BG95 adapter internal data structure
 * @{
 */

/** @brief The Quectel BG95 adapter data structure */
typedef struct _ewf_adapter_quectel_bg95
{
    /** The Quectel common data, it must be the first in the implementation structure */
    ewf_adapter_quectel_common common_implementation_data;

} ewf_adapter_quectel_bg95;

/** @} *** group_adapter_quectel_bg95_data */

/**
 * @defgroup group_adapter_quectel_bg95_declaration Adapter declaration and initialization
 * @brief Quectel BG95 adapter declaration macros
 * @{
 */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_HEADER(adapter_ptr)                                                                                                 \
do {                                                                                                                                                            \
(adapter_ptr)->struct_magic = EWF_ADAPTER_STRUCT_MAGIC;                                                                                                         \
(adapter_ptr)->struct_size = EWF_ADAPTER_STRUCT_SIZE;                                                                                                           \
(adapter_ptr)->struct_version = EWF_ADAPTER_VERSION;                                                                                                            \
(adapter_ptr)->struct_type = EWF_ADAPTER_TYPE_QUECTEL_BG95;                                                                                                     \
} while(0)
#else
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_HEADER(adapter_ptr)
#endif /* EWF_PARAMETER_CHECKING */

#if EWF_ADAPTER_QUECTEL_BG95_TCP_ENABLED
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_TCP_API(adapter_ptr)                                                                                                \
do {                                                                                                                                                            \
adapter_ptr->tcp_api_ptr = &ewf_adapter_quectel_common_api_tcp;                                                                                                 \
} while(0)
#else
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_TCP_API(adapter_ptr)
#endif /* EWF_ADAPTER_QUECTEL_BG95_TCP_ENABLED */

#if EWF_ADAPTER_QUECTEL_BG95_UDP_ENABLED
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_UDP_API(adapter_ptr)                                                                                                \
do {                                                                                                                                                            \
adapter_ptr->udp_api_ptr = &ewf_adapter_quectel_common_api_udp;                                                                                                 \
} while(0)
#else
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_UDP_API(adapter_ptr)
#endif /* EWF_ADAPTER_QUECTEL_BG95_UDP_ENABLED */

#if EWF_ADAPTER_QUECTEL_BG95_TLS_BASIC_ENABLED
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_TLS_BASIC_API(adapter_ptr)                                                                                          \
do {                                                                                                                                                            \
adapter_ptr->tls_basic_api_ptr = &ewf_adapter_quectel_common_api_tls_basic;                                                                                     \
} while(0)
#else
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_TLS_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_QUECTEL_BG95_TLS_BASIC_ENABLED */

#if EWF_ADAPTER_QUECTEL_BG95_MQTT_BASIC_ENABLED
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_MQTT_BASIC_API(adapter_ptr)                                                                                         \
do {                                                                                                                                                            \
adapter_ptr->mqtt_basic_api_ptr = &ewf_adapter_quectel_common_api_mqtt_basic;                                                                                   \
} while(0)
#else
#define EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_MQTT_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_QUECTEL_BG95_MQTT_BASIC_ENABLED */

/**
 * @brief Declare a Quectel BG95 adapter
 * @param[in,out] adapter_ptr a pointer to an adapter that will be initialized to point to the one statically declared by the macro
 * @param[in] adapter_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 * @param[in] message_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate command and response buffers
 * @param[in] data_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate data buffers
 * @param[in] interface_ptr_param a pointer to an interface, used by the adapter to talk with the hardware
 */
#define EWF_ADAPTER_QUECTEL_BG95_STATIC_DECLARE(adapter_ptr, adapter_name_symb, message_allocator_ptr_param, data_allocator_ptr_param, interface_ptr_param)     \
do {                                                                                                                                                            \
static ewf_adapter_quectel_bg95 ewf_adapter_quectel_bg95__implementation__##adapter_name_symb = {0};                                                            \
static ewf_adapter ewf_adapter_quectel_bg95__##adapter_name_symb = {0};                                                                                         \
interface_ptr_param->message_allocator_ptr = message_allocator_ptr_param;                                                                                       \
interface_ptr_param->data_allocator_ptr = data_allocator_ptr_param;                                                                                             \
interface_ptr_param->urc_callback = ewf_adapter_quectel_bg95_urc_callback;                                                                                      \
ewf_adapter_quectel_bg95__##adapter_name_symb.interface_ptr = interface_ptr_param;                                                                              \
ewf_adapter_quectel_bg95__##adapter_name_symb.implementation_ptr = &(ewf_adapter_quectel_bg95__implementation__##adapter_name_symb);                            \
adapter_ptr = &(ewf_adapter_quectel_bg95__##adapter_name_symb);                                                                                                 \
interface_ptr_param->adapter_ptr = adapter_ptr;                                                                                                                 \
EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_HEADER(adapter_ptr);                                                                                                        \
ewf_adapter_quectel_bg95__##adapter_name_symb.control_api_ptr = &ewf_adapter_quectel_bg95_api_control;                                                          \
ewf_adapter_quectel_bg95__##adapter_name_symb.info_api_ptr = &ewf_adapter_quectel_common_api_info;                                                              \
EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_TCP_API(adapter_ptr);                                                                                                       \
EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_UDP_API(adapter_ptr);                                                                                                       \
EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_TLS_BASIC_API(adapter_ptr);                                                                                                 \
EWF_ADAPTER_QUECTEL_BG95_INITIALIZE_MQTT_BASIC_API(adapter_ptr);                                                                                                \
} while(0)

/** @} *** group_adapter_quectel_bg95_declaration */

/************************************************************************//**
 * @} *** group_adapter_quectel_bg95
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_quectel_bg95__h__included__ */
