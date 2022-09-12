/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework RX UART Host Interface API.
 ****************************************************************************/

#ifndef __ewf_interface_rx_uart__h__included__
#define __ewf_interface_rx_uart__h__included__

#include "ewf_interface.h"

#include "r_smc_entry.h"
#include "platform.h"           // Located in the FIT BSP module
#include "r_sci_rx_if.h"        // The SCI module API interface file.
#include "r_byteq_if.h"         // The BYTEQ module API interface file.
#include "r_sci_rx_config.h"    // User configurable options for the SCI module
#include "r_sci_rx_pinset.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_interface_rx_uart RX UART interface
 * @ingroup group_interface
 * @brief RX UART interface
 * @{
 ****************************************************************************/

/**
 * @brief The RX UART interface implementation data structure type
 */
typedef struct _ewf_interface_rx_uart
{
    ewf_platform_thread* thread_ptr;

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_platform_mutex mutex;
    ewf_platform_thread* receive_thread_ptr;
#endif

} ewf_interface_rx_uart;

/* Default RYZ014 is enabled in RX interface. Change to 0 if alternate UART configuration is used */
#ifndef EWF_RENESAS_RX_INTERFACE_RYZ014_ENABLE
#define EWF_RENESAS_RX_INTERFACE_RYZ014_ENABLE          (1)
#endif

/**
 * @brief Start the RX UART hardware interface
 */
ewf_result ewf_interface_rx_uart_hardware_start(ewf_interface* interface_ptr);

/**
 * @brief Stop the RX UART hardware interface
 */
ewf_result ewf_interface_rx_uart_hardware_stop(ewf_interface* interface_ptr);

/**
 * @brief Send a buffer using the RX UART hardware interface
 */
ewf_result ewf_interface_rx_uart_hardware_send(ewf_interface* interface_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);

/**
 * @brief Receive a buffer using the RX UART hardware interface
 */
ewf_result ewf_interface_rx_uart_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

#ifdef EWF_PARAMETER_CHECKING
#define EWF_INTERFACE_RX_UART_INITIALIZE_HEADER(interface_ptr)                                                                                     \
do {                                                                                                                                                    \
(interface_ptr)->struct_magic = EWF_INTERFACE_STRUCT_MAGIC;                                                                                        \
(interface_ptr)->struct_size = EWF_INTERFACE_STRUCT_SIZE;                                                                                          \
(interface_ptr)->struct_version = EWF_INTERFACE_VERSION;                                                                                           \
(interface_ptr)->struct_type = EWF_INTERFACE_TYPE_RX_UART;                                                                                         \
} while(0)
#else
#define EWF_INTERFACE_RX_UART_INITIALIZE_HEADER(interface_ptr)
#endif /* EWF_PARXMETER_CHECKING */

/**
 * @brief Declare a RX UART HOST interface
 * @param[in,out] interface_ptr a pointer to an interface that will be initialized to point to the one statically declared by the macro
 * @param[in] interface_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 */
#define EWF_INTERFACE_RX_UART_STATIC_DECLARE(interface_ptr, interface_name_symb)                                                                   \
do {                                                                                                                                                    \
static ewf_interface_rx_uart ewf_interface_rx_uart__implementation__##interface_name_symb = {0};                                              \
static ewf_interface ewf_interface_rx_uart__interface__##interface_name_symb = {0};                                                           \
EWF_PLATFORM_QUEUE_STATIC_DECLARE(                                                                                                                 \
    ewf_interface_rx_uart__interface__##interface_name_symb.response_queue_ptr,                                                                    \
    ewf_interface_rx_uart__response_queue__##interface_name_symb,                                                                                  \
    ewf_interface_message,                                                                                                                         \
    8);                                                                                                                                                 \
EWF_PLATFORM_QUEUE_STATIC_DECLARE(                                                                                                                 \
    ewf_interface_rx_uart__interface__##interface_name_symb.urc_queue_ptr,                                                                         \
    ewf_interface_rx_uart__urc_queue__##interface_name_symb,                                                                                       \
    ewf_interface_message,                                                                                                                         \
    8);                                                                                                                                                 \
ewf_interface_rx_uart__interface__##interface_name_symb.hardware_start = ewf_interface_rx_uart_hardware_start;                              \
ewf_interface_rx_uart__interface__##interface_name_symb.hardware_stop = ewf_interface_rx_uart_hardware_stop;                                \
ewf_interface_rx_uart__interface__##interface_name_symb.hardware_send = ewf_interface_rx_uart_hardware_send;                                \
ewf_interface_rx_uart__interface__##interface_name_symb.hardware_receive = ewf_interface_rx_uart_hardware_receive;                            \
ewf_interface_rx_uart__interface__##interface_name_symb.implementation_ptr = &(ewf_interface_rx_uart__implementation__##interface_name_symb); \
interface_ptr = &(ewf_interface_rx_uart__interface__##interface_name_symb);                                                                        \
EWF_INTERFACE_RX_UART_INITIALIZE_HEADER(interface_ptr);                                                                                            \
} while(0)

/************************************************************************//**
 * @} *** group_interface_rx_uart
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_interface_rx_uart__h__included__ */
