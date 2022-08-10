/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework configuration template.
 ****************************************************************************/

#ifndef __ewf_inteface_win32_com__config__h__included__
#define __ewf_inteface_win32_com__config__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_inteface_win32_com Inteface configuration
 * @ingroup group_configuration
 * @ingroup group_interface_win32_com
 * @brief The definitions used to configure the Azure SD-NET interface.
 * @{
 ****************************************************************************/

/**
 * @def EWF_INTERFACE_WIN32_COM_PORT
 * @brief Define the serial port to use for the WIN32 COM port interface
 */
#define EWF_INTERFACE_WIN32_COM_PORT TEXT("\\\\.\\COM26")

/**
 * @def EWF_INTERFACE_WIN32_COM_PORT_BAUD_RATE
 * @brief Define the serial port baud rate for the WIN32 COM port interface
 */
#define EWF_INTERFACE_WIN32_COM_PORT_BAUD_RATE (CBR_115200)

/**
 * @def EWF_INTERFACE_URC_THREAD_STACK_SIZE
 * @brief The stack size for the URC thread
 */
#define EWF_INTERFACE_URC_THREAD_STACK_SIZE (1024)

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_inteface_win32_com__config__h__included__ */
