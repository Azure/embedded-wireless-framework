/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework NetX-Duo PPP test common code
 ****************************************************************************/

#ifndef __ewf_example_lwip_ppp_test__h__included__
#define __ewf_example_lwip_ppp_test__h__included__

#include "../lwip/src/include/lwip/opt.h"
#include "../lwip/src/include/lwip/init.h"
#include "../lwip/src/include/lwip/netif.h"
#include "../lwip/src/include/lwip/timeouts.h"
#include "../lwip/src/include/lwip/netif.h"
#include "../lwip/src/include/netif/ppp/ppp_impl.h"

#include "ewf.h"
#include "ewf_example.config.h"
#include "ewf_lwip_ppp.h"

#ifdef __cplusplus
extern "C" {
#endif

ewf_result ewf_example_lwip_ppp_test(ewf_adapter* adapter_ptr);

/************************************************************************//**
 * @defgroup group_example_lwip_ppp_test EWF adapter with LWIP over PPP test.
 * @brief The definitions and functions to test EWF with LWIP over PPP implementations.
 * @{
 ****************************************************************************/

/************************************************************************//**
 * @} *** group_example_lwip_ppp_test
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_lwip_ppp_test__h__included__ */
