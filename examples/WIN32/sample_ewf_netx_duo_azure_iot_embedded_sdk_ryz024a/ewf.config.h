/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework configuration.
 ****************************************************************************/

#ifndef __ewf__config__h__included__
#define __ewf__config__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration EWF configuration
 * @brief The definitions to configure the Azure SD-NET.
 * @{
 ****************************************************************************/

/** Define this symbol to enable compilation of debug code. When this symbol is not defined, debug code is not present and the footprint is reduced.  */
//#define EWF_DEBUG

/** Define this symbol to enable verbose logging */
//#define EWF_LOG_VERBOSE

/** Define this symbol to enable checking of function parameters. When this symbol is not defined, parameter checking code is not present and the footprint is reduced.  */
#define EWF_PARAMETER_CHECKING

/* Define the platform to be used, only one is valid */
//#define EWF_PLATFORM_BARE_METAL
#define EWF_PLATFORM_THREADX
//#define EWF_PLATFORM_FREERTOS
//#define EWF_PLATFORM_WIN32

/**
 * @defgroup group_example_configuration_netx_duo NetX Duo driver configuration
 * @brief NetX Duo Driver configuration settings used in middleware driver
 * @{
 */

 /** @brief Enable EWF usage with Azure RTOS NETX */
#define EWF_CONFIG_AZURE_RTOS_NETX                                   (1)

/* MTU size should be equal to the modems maximum socket send size */
#define EWF_CONFIG_ADAPTER_MTU                                       (1460)

/** @} */

/************************************************************************//**
 * @} *** group_configuration
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf__config__h__included__ */
