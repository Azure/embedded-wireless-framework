/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework WIN32 COM port Host Interface API.
 ****************************************************************************/

#ifndef __ewf_interface_win32_com__h__included__
#define __ewf_interface_win32_com__h__included__

#include "ewf_interface.h"

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_interface_win32_com WIN32 COM port host interface
 * @ingroup group_interface
 * @brief WIN32 COM port host interface
 * @{
 ****************************************************************************/

/**
 * @defgroup group_interface_win32_com_config WIN32 COM configuration
 * @{
 */

#ifndef EWF_INTERFACE_WIN32_COM_CONFIG_RX_BUFFER_SIZE
#define EWF_INTERFACE_WIN32_COM_CONFIG_RX_BUFFER_SIZE           (1)
#endif

#ifndef EWF_INTERFACE_WIN32_COM_CONFIG_RESPONSE_QUEUE_SIZE
#define EWF_INTERFACE_WIN32_COM_CONFIG_RESPONSE_QUEUE_SIZE      (8)
#endif

#ifndef EWF_INTERFACE_WIN32_COM_CONFIG_URC_QUEUE_SIZE
#define EWF_INTERFACE_WIN32_COM_CONFIG_URC_QUEUE_SIZE           (8)
#endif

/** @} *** group_interface_win32_com_config */

/**
 * @brief the WIN32 COM host interface implementation data structure type
 */
typedef struct _ewf_interface_win32_com
{
    HANDLE hComm;
    const char* com_port_cstr;
    BYTE buffer[EWF_INTERFACE_WIN32_COM_CONFIG_RX_BUFFER_SIZE];
    DWORD BaudRate;
    BYTE ByteSize;
    BYTE Parity;
    BYTE StopBits;
    OVERLAPPED osReader;
    OVERLAPPED osWrite;

} ewf_interface_win32_com;

/**
 * @brief Start the WIN32 COM hardware interface
 */
ewf_result ewf_interface_win32_com_hardware_start(ewf_interface* interface_ptr);

/**
 * @brief Stop the WIN32 COM hardware interface
 */
ewf_result ewf_interface_win32_com_hardware_stop(ewf_interface* interface_ptr);

/**
 * @brief Send a buffer using the WIN32 COM hardware interface
 */
ewf_result ewf_interface_win32_com_hardware_send(ewf_interface* interface_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);

/**
 * @brief Receive a buffer using the WIN32 COM hardware interface
 */
ewf_result ewf_interface_win32_com_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

#ifdef EWF_PARAMETER_CHECKING
#define EWF_INTERFACE_WIN32_COM_INITIALIZE_HEADER(interface_ptr)                                                                                    \
do {                                                                                                                                                \
(interface_ptr)->struct_magic = EWF_INTERFACE_STRUCT_MAGIC;                                                                                         \
(interface_ptr)->struct_size = EWF_INTERFACE_STRUCT_SIZE;                                                                                           \
(interface_ptr)->struct_version = EWF_INTERFACE_VERSION;                                                                                            \
(interface_ptr)->struct_type = EWF_INTERFACE_TYPE_WIN32_COM;                                                                                        \
} while(0)
#else
#define EWF_INTERFACE_WIN32_COM_INITIALIZE_HEADER(interface_ptr)
#endif /* EWF_PARAMETER_CHECKING */

/**
 * @brief Declare a WIN32 COM host interface
 * @param[in,out] interface_ptr a pointer to an interface that will be initialized to point to the one statically declared by the macro
 * @param[in] interface_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 * @param[in] com_port_cstr_param The constant string with the file name of the COM port, for example "\\\\.\\COM1"
 * @param[in] BaudRate_param The baud rate of the COM port, for example 115200
 * @param[in] ByteSize_param The number of data bits, typically 8
 * @param[in] Parity_param The number of parity bits, it can be: NOPARITY, ODDPARITY, SPACEPARITY, EVENPARITY or MARKPARITY
 * @param[in] StopBits_param The number of stop bits, it can be either: ONESTOPBIT, ONE5STOPBITS or TWOSTOPBITS
 */
#define EWF_INTERFACE_WIN32_COM_STATIC_DECLARE(interface_ptr, interface_name_symb, com_port_cstr_param, BaudRate_param, ByteSize_param, Parity_param, StopBits_param) \
do {                                                                                                                                                \
static ewf_interface_win32_com ewf_interface_win32_com__implementation__##interface_name_symb = {0};                                                \
static ewf_interface ewf_interface_win32_com__interface__##interface_name_symb = {0};                                                               \
ewf_interface_win32_com__implementation__##interface_name_symb.hComm = NULL;                                                                        \
ewf_interface_win32_com__implementation__##interface_name_symb.com_port_cstr =  com_port_cstr_param;                                                \
ewf_interface_win32_com__implementation__##interface_name_symb.BaudRate = BaudRate_param;                                                           \
ewf_interface_win32_com__implementation__##interface_name_symb.ByteSize = ByteSize_param;                                                           \
ewf_interface_win32_com__implementation__##interface_name_symb.Parity = Parity_param;                                                               \
ewf_interface_win32_com__implementation__##interface_name_symb.StopBits = StopBits_param;                                                           \
EWF_PLATFORM_QUEUE_STATIC_DECLARE(                                                                                                                  \
    ewf_interface_win32_com__interface__##interface_name_symb.response_queue_ptr,                                                                   \
    ewf_interface_win32_com__response_queue__##interface_name_symb,                                                                                 \
    ewf_interface_message,                                                                                                                          \
    EWF_INTERFACE_WIN32_COM_CONFIG_RESPONSE_QUEUE_SIZE);                                                                                            \
EWF_PLATFORM_QUEUE_STATIC_DECLARE(                                                                                                                  \
    ewf_interface_win32_com__interface__##interface_name_symb.urc_queue_ptr,                                                                        \
    ewf_interface_win32_com__urc_queue__##interface_name_symb,                                                                                      \
    ewf_interface_message,                                                                                                                          \
    EWF_INTERFACE_WIN32_COM_CONFIG_URC_QUEUE_SIZE);                                                                                                 \
ewf_interface_win32_com__interface__##interface_name_symb.hardware_start = ewf_interface_win32_com_hardware_start;                                  \
ewf_interface_win32_com__interface__##interface_name_symb.hardware_stop = ewf_interface_win32_com_hardware_stop;                                    \
ewf_interface_win32_com__interface__##interface_name_symb.hardware_send = ewf_interface_win32_com_hardware_send;                                    \
ewf_interface_win32_com__interface__##interface_name_symb.hardware_receive = ewf_interface_win32_com_hardware_receive;                              \
ewf_interface_win32_com__interface__##interface_name_symb.implementation_ptr = &(ewf_interface_win32_com__implementation__##interface_name_symb);   \
interface_ptr = &(ewf_interface_win32_com__interface__##interface_name_symb);                                                                       \
EWF_INTERFACE_WIN32_COM_INITIALIZE_HEADER(interface_ptr);                                                                                           \
} while(0)

/************************************************************************//**
 * @} *** group_interface_win32_com
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_interface_win32_com__h__included__ */
