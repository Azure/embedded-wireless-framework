/************************************************************************//**
 * @file
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter control API
 ****************************************************************************/

#ifndef __ewf_adapter_control__h__included__
#define __ewf_adapter_control__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_control Adapter control API
 * @ingroup group_adapter_api
 * @brief The adapter's start and stop functions
 * @{
 ****************************************************************************/

/**
 * @brief The adapter control API type
 */
typedef struct _ewf_adapter_api_control
{
    ewf_result(*start)(ewf_adapter* adapter_ptr);
    ewf_result(*stop)(ewf_adapter* adapter_ptr);

} ewf_adapter_api_control;

/**
 * @brief Starts the adapter
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_start(ewf_adapter* adapter_ptr);

/**
 * @brief Stops the adapter
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_stop(ewf_adapter* adapter_ptr);

/************************************************************************//**
 * @} *** group_adapter_control
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_control__h__included__ */
