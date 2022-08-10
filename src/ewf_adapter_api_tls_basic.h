/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter TLS basic API
 ****************************************************************************/

#ifndef __ewf_adapter_tls_basic__h__included__
#define __ewf_adapter_tls_basic__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_tls_basic Adapter TLS basic API
 * @ingroup group_adapter_api
 * @brief The adapter's TLS basic API functions
 * @{
 *
 ****************************************************************************/

/** @brief The TLS basic API structure */
typedef struct _ewf_adapter_api_tls_basic
{
    ewf_result(*init)(ewf_adapter* adapter_ptr);
    ewf_result(*clean)(ewf_adapter* adapter_ptr);

} ewf_adapter_api_tls_basic;

/**
 * @brief Initialize TLS basic API status
 */
ewf_result ewf_adapter_tls_basic_init(ewf_adapter* adapter_ptr);

/**
 * @brief Cleanup the TLS basic API status
 */
ewf_result ewf_adapter_tls_basic_clean(ewf_adapter* adapter_ptr);

/************************************************************************//**
 * @} *** group_adapter_tls_basic
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_tls__h__included__ */
