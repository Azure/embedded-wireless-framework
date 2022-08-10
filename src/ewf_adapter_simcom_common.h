/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework SIMCom common adapter API
 ****************************************************************************/

#ifndef __ewf_adapter_simcom_common__h__included__
#define __ewf_adapter_simcom_common__h__included__

#include "ewf_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_simcom_common SIMCom generic adapter functions
 * @ingroup group_adapter
 * @{
 ****************************************************************************/


/************************************************************************//**
 * @defgroup group_adapter_simcom_common_data SIMCom common driver internal data
 * @brief SIMCom common adapter data structure
 * @{
 ****************************************************************************/

/** @brief The SIMCom common adapter data structure */
typedef struct _ewf_adapter_simcom_common
{
    uint8_t dummy;
    
} ewf_adapter_simcom_common;

/************************************************************************//**
 * @} *** group_adapter_simcom_common_data
 ****************************************************************************/

/**
 * @defgroup group_adapter_simcom_common_control Adapter control
 * @brief SIMCom adapter control API
 * @{
 */

extern ewf_adapter_api_control ewf_adapter_simcom_common_api_control;

ewf_result ewf_adapter_simcom_common_start(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_simcom_common_stop(ewf_adapter* adapter_ptr);

/** @} *** group_adapter_simcom_common_control */

/**
 * @defgroup group_adapter_simcom_common_info Adapter information
 * @brief SIMCom adapter driver info API
 * @{
 */

extern ewf_adapter_api_info ewf_adapter_simcom_common_api_info;

ewf_result ewf_adapter_simcom_common_info(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_simcom_common_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t* address_ptr);
ewf_result ewf_adapter_simcom_common_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t* netmask_ptr);
ewf_result ewf_adapter_simcom_common_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t* gateway_ptr);
ewf_result ewf_adapter_simcom_common_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t* dns);

/** @} *** group_adapter_simcom_common_info */

/**
 * @defgroup group_adapter_simcom_common_urc URC handling
 * @brief SIMCom adapter driver URC handling
 * @{
 */

ewf_result ewf_adapter_simcom_common_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/** @} *** group_adapter_simcom_common_urc */


/************************************************************************//**
 * @} *** group_adapter_simcom_common
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_simcom_common__h__included__ */
