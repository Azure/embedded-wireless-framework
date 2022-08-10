/************************************************************************//**
 *
 * @file
 * @version Preview
 * SPDX-License-Identifier: MIT
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * @brief The Embedded Wireless Framework configuration template.
 * Copy this file into your own project, remove the .template extension
 * and customize its contents.
 *
 ****************************************************************************/


#ifndef __EWF__config__h__included__
#define __EWF__config__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration EWF configuration
 * @brief The definitions to configure the Embedded Wireless Framework.
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

/* Override the EWF_LOG definition to change formating for the logs on Renesas RA */
extern char ewf_log_buffer[256];
unsigned SEGGER_RTT_WriteString(unsigned BufferIndex, const char* s);
#define EWF_LOG(...)                                                          \
		do {                                                                  \
			snprintf(ewf_log_buffer, sizeof(ewf_log_buffer), __VA_ARGS__);    \
			SEGGER_RTT_WriteString(0, ewf_log_buffer);                        \
		} while(0)

/************************************************************************//**
 * @} *** group_configuration
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __EWF__config__h__included__ */
