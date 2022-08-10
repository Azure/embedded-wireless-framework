/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework SIMCom SIM868 adapter driver
 ****************************************************************************/

#ifndef __ewf_adapter_simcom_sim868__h__included__
#define __ewf_adapter_simcom_sim868__h__included__

#include "ewf_adapter.h"
#include "ewf_allocator.h"
#include "ewf_interface.h"
#include "ewf_adapter_api_modem.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_adapter_simcom_sim868 SIMCom SIM868 adapter configuration
 * @ingroup group_configuration
 * @brief SIMCom SIM868 adapter configuration
 * @{
 ****************************************************************************/
 
#define EWF_ADAPTER_SIMCOM_SIM868_TLS_BASIC_ENABLED (0)
#define EWF_ADAPTER_SIMCOM_SIM868_TCP_ENABLED (0)
#define EWF_ADAPTER_SIMCOM_SIM868_UDP_ENABLED (0)
#define EWF_ADAPTER_SIMCOM_SIM868_MQTT_BASIC_ENABLED (0)

#if !defined(EWF_ADAPTER_SIMCOM_SIM868_TLS_ENABLED) && !defined(EWF_ADAPTER_SIMCOM_SIM868_TLS_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_SIMCOM_SIM868_TLS_BASIC_ENABLED (1)
#define EWF_ADAPTER_SIMCOM_SIM868_TLS_ENABLED (0)
#else
#define EWF_ADAPTER_SIMCOM_SIM868_TLS_BASIC_ENABLED (0)
#define EWF_ADAPTER_SIMCOM_SIM868_TLS_ENABLED (1)
#endif
#endif

#ifndef EWF_ADAPTER_SIMCOM_SIM868_TCP_ENABLED
#define EWF_ADAPTER_SIMCOM_SIM868_TCP_ENABLED (1)
#endif

#ifndef EWF_ADAPTER_SIMCOM_SIM868_UDP_ENABLED
#define EWF_ADAPTER_SIMCOM_SIM868_UDP_ENABLED (1)
#endif

#if !defined(EWF_ADAPTER_SIMCOM_SIM868_MQTT_ENABLED) && !defined(EWF_ADAPTER_SIMCOM_SIM868_MQTT_BASIC_ENABLED)
#if 1
#define EWF_ADAPTER_SIMCOM_SIM868_MQTT_BASIC_ENABLED (1)
#define EWF_ADAPTER_SIMCOM_SIM868_MQTT_ENABLED (0)
#else
#define EWF_ADAPTER_SIMCOM_SIM868_MQTT_BASIC_ENABLED (0)
#define EWF_ADAPTER_SIMCOM_SIM868_MQTT_ENABLED (1)
#endif
#endif

/************************************************************************//**
 * @} *** group_configuration_adapter_quectel_bg96
 ****************************************************************************/
/* Include the SIMCom common header here, to take the above configuration macros into account */
#include "ewf_adapter_simcom_common.h"

/************************************************************************//**
 * @defgroup group_adapter_simcom_sim868 The SIMCom SIM868 modem adapter driver
 * @ingroup group_adapter
 * @{
 ****************************************************************************/

/**
 * @defgroup group_adapter_simcom_sim868_control Adapter control
 * @brief SIMCom SIM868 adapter control API
 * @{
 */

extern ewf_adapter_api_control ewf_adapter_simcom_sim868_api_control;

ewf_result ewf_adapter_simcom_sim868_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_simcom_sim868_stop(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_simcom_sim868_control */

/**
 * @defgroup group_adapter_simcom_sim868_urc URC handling
 * @brief SIMCom SIM868 adapter driver URC handling
 * @{
 */

ewf_result ewf_adapter_simcom_sim868_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/** @} *** group_adapter_simcom_sim868_urc */

/**
 * @defgroup group_adapter_simcom_sim868_info Adapter information
 * @brief SIMCom SIM868 adapter driver info API
 * @{
 */


#define ewf_adapter_simcom_sim868_info                     ewf_adapter_simcom_common_info
#define ewf_adapter_simcom_sim868_get_ipv4_address         ewf_adapter_simcom_common_get_ipv4_address
#define ewf_adapter_simcom_sim868_get_ipv4_netmask         ewf_adapter_simcom_common_get_ipv4_netmask
#define ewf_adapter_simcom_sim868_get_ipv4_gateway         ewf_adapter_simcom_common_get_ipv4_gateway
#define ewf_adapter_simcom_sim868_get_ipv4_dns             ewf_adapter_simcom_common_get_ipv4_dns

/** @} *** group_adapter_simcom_sim868_info */


/******************************************************************************
 *
 * Internal data
 *
 ******************************************************************************/

/**
 * @defgroup group_adapter_simcom_sim868_data SIMCom SIM868 driver internal data
 * @brief The SIMCom SIM868 adapter internal data structure
 * @{
 */

/** @brief The SIMCom SIM868 adapter data structure */
typedef struct _ewf_adapter_simcom_sim868
{
    /** The SIMCom common data, it must be the first in the implementation structure */
    ewf_adapter_simcom_common common_implementation_data;

} ewf_adapter_simcom_sim868;

/** @} *** group_adapter_simcom_sim868_data */

/**
 * @defgroup group_adapter_simcom_sim868_declaration Adapter declaration and initialization
 * @brief SIMCom SIM868 adapter declaration macros
 * @{
 */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_HEADER(adapter_ptr)                                                                                                \
do {                                                                                                                                                            \
(adapter_ptr)->struct_magic = EWF_ADAPTER_STRUCT_MAGIC;                                                                                                         \
(adapter_ptr)->struct_size = EWF_ADAPTER_STRUCT_SIZE;                                                                                                           \
(adapter_ptr)->struct_version = EWF_ADAPTER_VERSION;                                                                                                            \
(adapter_ptr)->struct_type = EWF_ADAPTER_TYPE_SIMCOM_SIM868;                                                                                                    \
} while(0)
#else
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_HEADER(adapter_ptr)
#endif /* EWF_PARAMETER_CHECKING */

#if EWF_ADAPTER_SIMCOM_SIM868_TCP_ENABLED
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_TCP_API(adapter_ptr)                                                                                               \
do {                                                                                                                                                            \
adapter_ptr->tcp_api_ptr = &ewf_adapter_simcom_common_api_tcp;                                                                                                  \
} while(0)
#else
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_TCP_API(adapter_ptr)
#endif /* EWF_ADAPTER_SIMCOM_SIM868_TCP_ENABLED */

#if EWF_ADAPTER_SIMCOM_SIM868_UDP_ENABLED
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_UDP_API(adapter_ptr)                                                                                               \
do {                                                                                                                                                            \
adapter_ptr->udp_api_ptr = &ewf_adapter_simcom_common_api_udp;                                                                                                  \
} while(0)
#else
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_UDP_API(adapter_ptr)
#endif /* EWF_ADAPTER_SIMCOM_SIM868_UDP_ENABLED */

#if EWF_ADAPTER_SIMCOM_SIM868_TLS_BASIC_ENABLED
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_TLS_BASIC_API(adapter_ptr)                                                                                         \
do {                                                                                                                                                            \
adapter_ptr->tls_basic_api_ptr = &ewf_adapter_simcom_common_api_tls_basic;                                                                                      \
} while(0)
#else
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_TLS_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_SIMCOM_SIM868_TLS_BASIC_ENABLED */

#if EWF_ADAPTER_SIMCOM_SIM868_MQTT_BASIC_ENABLED
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_MQTT_BASIC_API(adapter_ptr)                                                                                        \
do {                                                                                                                                                            \
adapter_ptr->mqtt_basic_api_ptr = &ewf_adapter_simcom_common_api_mqtt_basic;                                                                                    \
} while(0)
#else
#define EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_MQTT_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_SIMCOM_SIM868_MQTT_BASIC_ENABLED */

 /**
  * @brief Declare a SIMCom SIM868 adapter
  * @param[in,out] adapter_ptr a pointer to an adapter that will be initialized to point to the one statically declared by the macro
  * @param[in] adapter_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
  * @param[in] message_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate command and response buffers
  * @param[in] data_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate data buffers
  * @param[in] interface_ptr_param a pointer to an interface, used by the adapter to talk with the hardware
  */
#define EWF_ADAPTER_SIMCOM_SIM868_STATIC_DECLARE(adapter_ptr, adapter_name_symb, message_allocator_ptr_param, data_allocator_ptr_param, interface_ptr_param)   \
do {                                                                                                                                                           \
static ewf_adapter_simcom_sim868 ewf_adapter_simcom_sim868__implementation__##adapter_name_symb = {0};                                                         \
static ewf_adapter ewf_adapter_simcom_sim868__##adapter_name_symb = {0};                                                                                       \
interface_ptr_param->message_allocator_ptr = message_allocator_ptr_param;                                                                                      \
interface_ptr_param->data_allocator_ptr = data_allocator_ptr_param;                                                                                            \
interface_ptr_param->urc_callback = ewf_adapter_simcom_sim868_urc_callback;                                                                                    \
ewf_adapter_simcom_sim868__##adapter_name_symb.interface_ptr = interface_ptr_param;                                                                            \
ewf_adapter_simcom_sim868__##adapter_name_symb.implementation_ptr = &(ewf_adapter_simcom_sim868__implementation__##adapter_name_symb);                         \
adapter_ptr = &(ewf_adapter_simcom_sim868__##adapter_name_symb);                                                                                               \
interface_ptr_param->adapter_ptr = adapter_ptr;                                                                                                                \
EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_HEADER(adapter_ptr);                                                                                                      \
ewf_adapter_simcom_sim868__##adapter_name_symb.control_api_ptr = &ewf_adapter_simcom_sim868_api_control;                                                       \
ewf_adapter_simcom_sim868__##adapter_name_symb.info_api_ptr = &ewf_adapter_simcom_common_api_info;                                                             \
EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_TCP_API(adapter_ptr);                                                                                                     \
EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_UDP_API(adapter_ptr);                                                                                                     \
EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_TLS_BASIC_API(adapter_ptr);                                                                                               \
EWF_ADAPTER_SIMCOM_SIM868_INITIALIZE_MQTT_BASIC_API(adapter_ptr);                                                                                              \
} while(0)

/** @} *** group_adapter_simcom_sim868_declaration */

/************************************************************************//**
 * @} *** group_adapter_simcom_sim868
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_simcom_sim868__h__included__ */
