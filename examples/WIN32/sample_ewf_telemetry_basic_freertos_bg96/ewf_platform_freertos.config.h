/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework configuration template.
 ****************************************************************************/

#ifndef __ewf_platform_freertos__config__h__included__
#define __ewf_platform_freertos__config__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_platform_freertos Platform configuration (FreeRTOS)
 * @ingroup group_configuration
 * @ingroup group_platform
 * @brief The definitions used to configure the Azure SD-NET platform.
 * @{
 ****************************************************************************/

/** Define the number of ticks per second in the platform; this is used to calculate absolute times.  */
#define EWF_PLATFORM_TICKS_PER_SECOND          (configTICK_RATE_HZ)

/** Define the thread priorities */
#define EWF_PLATFORM_THREAD_PRIORITY_HIGH      (configMAX_PRIORITIES - 1)
#define EWF_PLATFORM_THREAD_PRIORITY_MEDIUM    (configMAX_PRIORITIES / 2)
#define EWF_PLATFORM_THREAD_PRIORITY_LOW       (1)

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_platform_freertos__config__h__included__ */
