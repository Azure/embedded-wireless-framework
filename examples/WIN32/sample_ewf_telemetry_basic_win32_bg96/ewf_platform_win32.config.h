/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework configuration template.
 ****************************************************************************/

#ifndef __ewf_platform_win32__config__h__included__
#define __ewf_platform_win32__config__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_platform_win32 WIN32 platform configuration
 * @ingroup group_configuration
 * @brief The definitions used to configure the Azure SD-NET WIN32 platform.
 * @{
 ****************************************************************************/

/** Define the number of ticks per second in the platform; this is used to calculate absolute times.  */
#define EWF_PLATFORM_TICKS_PER_SECOND (1000)

/** Define the thread priorities */
#define EWF_THREAD_PRIORITY_HIGH       (THREAD_PRIORITY_ABOVE_NORMAL)
#define EWF_THREAD_PRIORITY_MEDIUM     (THREAD_PRIORITY_NORMAL)
#define EWF_THREAD_PRIORITY_LOW        (THREAD_PRIORITY_IDLE)

/************************************************************************//**
 * @} *** group_configuration_platform_win32
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_platform_win32__config__h__included__ */
