/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Seeed LoRa-E5 adapter driver
 ****************************************************************************/

#ifndef __ewf_adapter_seeed_seeed_lora_e5__config__h__included__
#define __ewf_adapter_seeed_seeed_lora_e5__config__h__included__

#include "ewf_adapter.h"
#include "ewf_allocator.h"
#include "ewf_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_adapter_seeed_lora_e5 Seeed LoRa-E5 adapter configuration
 * @ingroup group_configuration_adapter
 * @ingroup group_adapter_seeed_lora_e5
 * @brief Seeed LoRa-E5 adapter configuration
 * @{
 ****************************************************************************/

/************************************************************************//**
 * @} *** group_configuration_adapter_seeed_lora_e5
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_adapter_seeed_lora_e5 The Seeed LoRa-E5 adapter driver
 * @ingroup group_adapter
 * @{
 ****************************************************************************/

/**
 * @defgroup group_adapter_seeed_lora_e5_control The Seeed LoRa-E5 adapter control API
 * @brief The Seeed LoRa-E5 adapter control API
 * @{
 */

extern ewf_adapter_api_control ewf_adapter_seeed_lora_e5_api_control;

ewf_result ewf_adapter_seeed_lora_e5_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_seeed_lora_e5_stop(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_seeed_lora_e5_control */

/**
 * @defgroup group_adapter_seeed_lora_e5_urc URC handling
 * @brief SSeeed LoRa-E5 adapter driver URC handling
 * @{
 */

ewf_result ewf_adapter_seeed_lora_e5_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/** @} *** group_adapter_seeed_lora_e5_urc */

/**
 * @defgroup group_adapter_seeed_lora_e5_info The Seeed LoRa-E5 adapter info API
 * @brief The Seeed LoRa-E5 adapter info API
 * @{
 */

extern ewf_adapter_api_info ewf_adapter_seeed_lora_e5_api_info;

ewf_result ewf_adapter_seeed_lora_e5_info(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_seeed_lora_e5_info */

/******************************************************************************
 *
 * Internal data
 *
 ******************************************************************************/

/**
 * @defgroup group_adapter_seeed_lora_e5_data The Seeed LoRa-E5 adapter driver internal data
 * @brief The Seeed LoRa-E5 adapter driver data structures
 * @{
 */

/** @brief The Seeed LoRa-E5 adapter driver data structure */
typedef struct _ewf_adapter_seeed_lora_e5
{
    int dummy;

} ewf_adapter_seeed_lora_e5;

/** @} *** group_adapter_seeed_lora_e5_data */

/**
 * @defgroup group_adapter_seeed_lora_e5_declaration Adapter declaration and initialization
 * @brief Seeed LoRa-E5 adapter declaration macros
 * @{
 */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_HEADER(adapter_ptr)                                                                                            \
do {                                                                                                                                                        \
(adapter_ptr)->struct_magic = EWF_ADAPTER_STRUCT_MAGIC;                                                                                                     \
(adapter_ptr)->struct_size = EWF_ADAPTER_STRUCT_SIZE;                                                                                                       \
(adapter_ptr)->struct_version = EWF_ADAPTER_VERSION;                                                                                                        \
(adapter_ptr)->struct_type = EWF_ADAPTER_TYPE_SEEED_LORA_E5;                                                                                                \
} while(0)
#else
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_HEADER(adapter_ptr)
#endif /* EWF_PARAMETER_CHECKING */

#if EWF_ADAPTER_SEEED_LORA_E5_TCP_ENABLED
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_TCP_API(adapter_ptr)                                                                                           \
do {                                                                                                                                                        \
adapter_ptr->tcp_api_ptr = &ewf_adapter_seeed_lora_e5_api_tcp;                                                                                              \
} while(0)
#else
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_TCP_API(adapter_ptr)
#endif /* EWF_ADAPTER_SEEED_LORA_E5_TCP_ENABLED */

#if EWF_ADAPTER_SEEED_LORA_E5_UDP_ENABLED
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_UDP_API(adapter_ptr)                                                                                           \
do {                                                                                                                                                        \
adapter_ptr->udp_api_ptr = &ewf_adapter_seeed_lora_e5_api_udp;                                                                                              \
} while(0)
#else
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_UDP_API(adapter_ptr)
#endif /* EWF_ADAPTER_SEEED_LORA_E5_UDP_ENABLED */

#if EWF_ADAPTER_SEEED_LORA_E5_TLS_BASIC_ENABLED
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_TLS_BASIC_API(adapter_ptr)                                                                                     \
do {                                                                                                                                                        \
adapter_ptr->tls_basic_api_ptr = &ewf_adapter_seeed_lora_e5_api_tls_basic;                                                                                  \
} while(0)
#else
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_TLS_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_SEEED_LORA_E5_TLS_BASIC_ENABLED */

#if EWF_ADAPTER_SEEED_LORA_E5_MQTT_BASIC_ENABLED
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_MQTT_BASIC_API(adapter_ptr)                                                                                    \
do {                                                                                                                                                        \
adapter_ptr->mqtt_basic_api_ptr = &ewf_adapter_seeed_lora_e5_api_mqtt_basic;                                                                                \
} while(0)
#else
#define EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_MQTT_BASIC_API(adapter_ptr)
#endif /* EWF_ADAPTER_SEEED_LORA_E5_MQTT_BASIC_ENABLED */

/**
 * @brief Declare a Seeed LoRa-E5 adapter
 * @param[in,out] adapter_ptr a pointer to an adapter that will be initialized to point to the one statically declared by the macro
 * @param[in] adapter_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 * @param[in] message_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate command and response buffers
 * @param[in] data_allocator_ptr_param a pointer to an allocator, used by the adapter to allocate data buffers
 * @param[in] interface_ptr_param a pointer to an interface, used by the adapter to talk with the hardware
 */
#define EWF_ADAPTER_SEEED_LORA_E5_STATIC_DECLARE(adapter_ptr, adapter_name_symb, message_allocator_ptr_param, data_allocator_ptr_param, interface_ptr_param) \
do {                                                                                                                                                        \
static ewf_adapter_seeed_lora_e5 ewf_adapter_seeed_lora_e5__implementation__##adapter_name_symb = {0};                                                      \
static ewf_adapter ewf_adapter_seeed_lora_e5__##adapter_name_symb = {0};                                                                                    \
interface_ptr_param->message_allocator_ptr = message_allocator_ptr_param;                                                                                   \
interface_ptr_param->data_allocator_ptr = data_allocator_ptr_param;                                                                                         \
interface_ptr_param->urc_callback = ewf_adapter_seeed_lora_e5_urc_callback;                                                                                 \
ewf_adapter_seeed_lora_e5__##adapter_name_symb.interface_ptr = interface_ptr_param;                                                                         \
ewf_adapter_seeed_lora_e5__##adapter_name_symb.implementation_ptr = &(ewf_adapter_seeed_lora_e5__implementation__##adapter_name_symb);                      \
adapter_ptr = &(ewf_adapter_seeed_lora_e5__##adapter_name_symb);                                                                                            \
interface_ptr_param->adapter_ptr = adapter_ptr;                                                                                                             \
EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_HEADER(adapter_ptr);                                                                                                   \
ewf_adapter_seeed_lora_e5__##adapter_name_symb.control_api_ptr = &ewf_adapter_seeed_lora_e5_api_control;                                                    \
ewf_adapter_seeed_lora_e5__##adapter_name_symb.info_api_ptr = &ewf_adapter_seeed_lora_e5_api_info;                                                          \
EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_TCP_API(adapter_ptr);                                                                                                  \
EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_UDP_API(adapter_ptr);                                                                                                  \
EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_TLS_BASIC_API(adapter_ptr);                                                                                            \
EWF_ADAPTER_SEEED_LORA_E5_INITIALIZE_MQTT_BASIC_API(adapter_ptr);                                                                                           \
} while(0)

/** @} *** group_adapter_seeed_lora_e5_data */

/************************************************************************//**
 * @} *** group_adapter_seeed_lora_e5
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_seeed_seeed_lora_e5__config__h__included__ */
