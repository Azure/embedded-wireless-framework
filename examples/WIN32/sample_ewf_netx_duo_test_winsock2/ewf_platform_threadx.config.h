/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework configuration template.
 ****************************************************************************/

#ifndef __ewf_platform_threadx__config__h__included__
#define __ewf_platform_threadx__config__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_platform_threadx Platform configuration
 * @ingroup group_configuration
 * @brief The definitions used to configure the Azure SD-NET platform.
 * @{
 ****************************************************************************/

/** Define the number of ticks per second in the platform; this is used to calculate absolute times.  */
#define EWF_PLATFORM_TICKS_PER_SECOND          (TX_TIMER_TICKS_PER_SECOND)

/** Define the thread priorities */
#define EWF_PLATFORM_THREAD_PRIORITY_HIGH      (1)
#define EWF_PLATFORM_THREAD_PRIORITY_MEDIUM    (7)
#define EWF_PLATFORM_THREAD_PRIORITY_LOW       (15)

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_platform_threadx__config__h__included__ */
