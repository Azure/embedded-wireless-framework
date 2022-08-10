/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter URC API
 ****************************************************************************/

#ifndef __ewf_adapter_urc__h__included__
#define __ewf_adapter_urc__h__included__

#include "ewf.h"
#include "ewf_interface.h"
#include "ewf_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_urc Adapter URC API
 * @ingroup group_adapter_api
 * @brief The adapter's URC types and functions
 * @{
 *
 ****************************************************************************/

/**
 * @brief The adapter's URC user callback function pointer type
 * @param[in,out] buffer_ptr The buffer
 * @param[in] length The buffer length
 * @return #ewf_result status code
 */
typedef ewf_result (*ewf_adapter_urc_user_callback)(ewf_interface* interface_ptr, uint8_t * buffer_ptr, uint32_t buffer_length);

/**
 * @brief Sets the user defined URC callback for the adapter
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_set_user_urc_callback(ewf_adapter* adapter_ptr, ewf_adapter_urc_user_callback callback);

/************************************************************************//**
 * @} *** group_adapter_urc
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_urc__h__included__ */
