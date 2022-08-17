/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework SAM UART port Host Interface API.
 ****************************************************************************/

#ifndef __ewf_interface_microchip_sam_uart__h__included__
#define __ewf_interface_microchip_sam_uart__h__included__

#include "ewf_interface.h"

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


/************************************************************************//**
 * @defgroup group_interface_microchip_sam_uart SAM UART port interface
 * @ingroup group_interface
 * @brief SAM UART port interface
 * @{
 ****************************************************************************/

/**
 * @defgroup group_interface_microchip_sam_uart MICROCHIP_SAM UART configuration
 * @{
 */

#ifndef EWF_INTERFACE_MICROCHIP_SAM_UART_CONFIG_RX_THREAD_STACK_SIZE
/** This is the stack size for the reception thread, the default is conservative, you can reduce this in your application */
#define EWF_INTERFACE_MICROCHIP_SAM_UART_CONFIG_RX_THREAD_STACK_SIZE    (1024 * 2)
#endif

#ifndef EWF_INTERFACE_MICROCHIP_SAM_UART_CONFIG_RESPONSE_QUEUE_SIZE
#define EWF_INTERFACE_MICROCHIP_SAM_UART_CONFIG_RESPONSE_QUEUE_SIZE     (8)
#endif

#ifndef EWF_INTERFACE_MICROCHIP_SAM_UART_CONFIG_URC_QUEUE_SIZE
#define EWF_INTERFACE_MICROCHIP_SAM_UART_CONFIG_URC_QUEUE_SIZE          (8)
#endif

/**
 * @brief the SAM UART interface implementation data structure type
 */
typedef struct _ewf_interface_microchip_sam_uart
{
    ewf_platform_thread* thread_ptr;

#ifdef EWF_PLATFORM_SUPPORTS_THREADING
    ewf_platform_mutex mutex;
    ewf_platform_thread* receive_thread_ptr;
#endif
} ewf_interface_microchip_sam_uart;


/**
 * @brief Start the SAM UART hardware interface
 */
ewf_result ewf_interface_microchip_sam_uart_hardware_start(ewf_interface* interface_ptr);

/**
 * @brief Stop the SAM UART hardware interface
 */
ewf_result ewf_interface_microchip_sam_uart_hardware_stop(ewf_interface* interface_ptr);

/**
 * @brief Send a buffer using the RX UART hardware interface
 */
ewf_result ewf_interface_microchip_sam_hardware_send(ewf_interface* interface_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);

/**
 * @brief Receive a buffer using the RX UART hardware interface
 */
ewf_result ewf_interface_microchip_sam_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);


#ifdef EWF_PARAMETER_CHECKING
#define EWF_INTERFACE_MICROCHIP_SAM_UART_INITIALIZE_HEADER(global_interface_ptr)                                                                                    \
do {                                                                                                                                                                \
(global_interface_ptr)->struct_magic = EWF_INTERFACE_STRUCT_MAGIC;                                                                                                  \
(global_interface_ptr)->struct_size = EWF_INTERFACE_STRUCT_SIZE;                                                                                                    \
(global_interface_ptr)->struct_version = EWF_INTERFACE_VERSION;                                                                                                     \
(global_interface_ptr)->struct_type = EWF_INTERFACE_TYPE_MICROCHIP_SAM_UART;                                                                                        \
} while(0)
#else
#define EWF_INTERFACE_MICROCHIP_SAM_UART_INITIALIZE_HEADER(interface_ptr)
#endif /* EWF_PARXMETER_CHECKING */

/**
 * @brief Declare a SAM UART interface
 * @param[in,out] interface_ptr a pointer to an interface that will be initialized to point to the one statically declared by the macro
 * @param[in] interface_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 */
#define EWF_INTERFACE_MICROCHIP_SAM_UART_STATIC_DECLARE(interface_ptr, interface_name_symb)                                                                         \
do {                                                                                                                                                                \
static ewf_interface_microchip_sam_uart ewf_interface_microchip_sam_uart__implementation__##interface_name_symb = {0};                                              \
static ewf_interface ewf_interface_microchip_sam_uart__interface__##interface_name_symb = {0};                                                                      \
EWF_PLATFORM_THREAD_STATIC_DECLARE(                                                                                                                                 \
    ewf_interface_microchip_sam_uart__interface__##interface_name_symb.receive_thread_ptr,                                                                          \
    ewf_interface_microchip_sam_uart__receive_thread__##interface_name_symb,                                                                                        \
    ewf_interface_receive_thread,                                                                                                                                   \
    &(ewf_interface_microchip_sam_uart__interface__##interface_name_symb),                                                                                          \
    EWF_INTERFACE_MICROCHIP_SAM_UART_CONFIG_RX_THREAD_STACK_SIZE,                                                                                                                                                     \
    EWF_PLATFORM_THREAD_PRIORITY_HIGH);                                                                                                                             \
EWF_PLATFORM_QUEUE_STATIC_DECLARE(                                                                                                                                  \
    ewf_interface_microchip_sam_uart__interface__##interface_name_symb.response_queue_ptr,                                                                          \
    ewf_interface_microchip_sam_uart__response_queue__##interface_name_symb,                                                                                        \
    ewf_interface_message,                                                                                                                                          \
    EWF_INTERFACE_MICROCHIP_SAM_UART_CONFIG_RESPONSE_QUEUE_SIZE);                                                                                                                                                             \
EWF_PLATFORM_QUEUE_STATIC_DECLARE(                                                                                                                                  \
    ewf_interface_microchip_sam_uart__interface__##interface_name_symb.urc_queue_ptr,                                                                               \
    ewf_interface_microchip_sam_uart__urc_queue__##interface_name_symb,                                                                                             \
    ewf_interface_message,                                                                                                                                          \
    EWF_INTERFACE_MICROCHIP_SAM_UART_CONFIG_URC_QUEUE_SIZE);                                                                                                                                                             \
ewf_interface_microchip_sam_uart__interface__##interface_name_symb.hardware_start = ewf_interface_microchip_sam_uart_hardware_start;                                \
ewf_interface_microchip_sam_uart__interface__##interface_name_symb.hardware_stop = ewf_interface_microchip_sam_uart_hardware_stop;                                  \
ewf_interface_microchip_sam_uart__interface__##interface_name_symb.hardware_send = ewf_interface_microchip_sam_uart_hardware_send;                                  \
ewf_interface_microchip_sam_uart__interface__##interface_name_symb.hardware_receive = ewf_interface_microchip_sam_uart_hardware_receive;                            \
ewf_interface_microchip_sam_uart__interface__##interface_name_symb.implementation_ptr = &(ewf_interface_microchip_sam_uart__implementation__##interface_name_symb); \
interface_ptr = &(ewf_interface_microchip_sam_uart__interface__##interface_name_symb);                                                                              \
EWF_INTERFACE_MICROCHIP_SAM_UART_INITIALIZE_HEADER(interface_ptr);                                                                                                  \
} while(0)

/************************************************************************//**
 * @} *** group_interface_microchip_sam_uart
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_interface_microchip_sam_uart__h__included__ */
