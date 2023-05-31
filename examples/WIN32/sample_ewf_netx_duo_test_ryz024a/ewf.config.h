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
#define EWF_DEBUG

/** Define this symbol to enable verbose logging */
//#define EWF_LOG_VERBOSE

/** Define this symbol to enable checking of function parameters. When this symbol is not defined, parameter checking code is not present and the footprint is reduced.  */
#define EWF_PARAMETER_CHECKING

/* Define the platform to be used, only one is valid */
//#define EWF_PLATFORM_BARE_METAL
#define EWF_PLATFORM_THREADX
//#define EWF_PLATFORM_FREERTOS
//#define EWF_PLATFORM_WIN32

/** @brief Enable EWF usage with Azure RTOS NETX */
#define EWF_CONFIG_AZURE_RTOS_NETX (1)

/************************************************************************//**
 * @} *** group_configuration
 ****************************************************************************/

#include <stdbool.h>
#include "tx_api.h"

extern volatile bool ewf_log_initialized;
extern TX_MUTEX ewf_log_mutex;

#ifndef EWF_DEBUG
#define EWF_LOG(...)
#else
#define EWF_LOG(...)                                                            \
do {                                                                            \
    if (!ewf_log_initialized)                                                   \
    {                                                                           \
        ewf_log_initialized = true;                                             \
        (void)tx_mutex_create(&ewf_log_mutex, "EWF log mutex", TX_INHERIT);     \
    }                                                                           \
    (void)tx_mutex_get(&ewf_log_mutex, TX_WAIT_FOREVER);                        \
    (void)fprintf(stdout, __VA_ARGS__);                                         \
    (void)fflush(stdout);                                                       \
    (void)tx_mutex_put(&ewf_log_mutex);                                         \
} while (0)
#endif

#ifdef __cplusplus
}
#endif

#endif /* __ewf__config__h__included__ */
