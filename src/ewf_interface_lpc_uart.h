/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework LPC UART Host Interface API.
 ****************************************************************************/

#ifndef __ewf_interface_lpc_uart__h__included__
#define __ewf_interface_lpc_uart__h__included__

#include "ewf_interface.h"

#if FSL_FEATURE_SOC_LPUART_COUNT > 0
#include "fsl_lpuart.h"
#elif FSL_FEATURE_SOC_USART_COUNT > 0
#include "fsl_usart.h"
#else
#error "Do not have a supported UART peripheral."
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_interface_lpc_uart LPC UART host interface
 * @ingroup group_interface
 * @brief LPC UART host interface
 * @{
 ****************************************************************************/

/**
 * @defgroup group_interface_lpc_uart_config LPC UART configuration
 * @{
 */

#define EWF_INTERFACE_LPC_UART_RING_BUFFER_SIZE                 (128U)


#ifndef EWF_INTERFACE_LPC_UART_CONFIG_UART_RX_QUEUE_SIZE
#define EWF_INTERFACE_LPC_UART_CONFIG_UART_RX_QUEUE_SIZE        (32)
#endif

#ifndef EWF_INTERFACE_LPC_UART_CONFIG_RESPONSE_QUEUE_SIZE
#define EWF_INTERFACE_LPC_UART_CONFIG_RESPONSE_QUEUE_SIZE       (8)
#endif

#ifndef EWF_INTERFACE_LPC_UART_CONFIG_URC_QUEUE_SIZE
#define EWF_INTERFACE_LPC_UART_CONFIG_URC_QUEUE_SIZE            (8)
#endif

/** @} *** group_interface_lpc_uart_config */

/**
 * @brief The LPC UART host interface implementation data structure type
 */
typedef struct _ewf_interface_lpc_uart
{
#if FSL_FEATURE_SOC_LPUART_COUNT > 0
    LPUART_Type *base;                  /*!< UART base address */
    lpuart_handle_t handle;             /*!< LPUART handle */
    lpuart_transfer_t tx_transfer;      /*!< TX transfer structure */
    lpuart_transfer_t rx_transfer;      /*!< RX transfer structure */
#elif FSL_FEATURE_SOC_USART_COUNT > 0
    USART_Type *base;                   /*!< USART base address */
    usart_handle_t handle;              /*!< USART handle structure */
    usart_transfer_t tx_transfer;       /*!< TX transfer structure */
    usart_transfer_t rx_transfer;       /*!< RX transfer structure */
#endif

    uint32_t baud_rate;

    usart_config_t config;

    uint8_t ring_buffer[EWF_INTERFACE_LPC_UART_RING_BUFFER_SIZE];  /*!< ring buffer for background reception */
    uint32_t buffer_size;               /*!< Size of the ring buffer for background reception */

    ewf_platform_mutex* rx_mutex_ptr;

    usart_transfer_t xfer;

} ewf_interface_lpc_uart;

/**
 * @brief Start the LPC UART hardware interface
 */
ewf_result ewf_interface_lpc_uart_hardware_start(ewf_interface* interface_ptr);

/**
 * @brief Stop the LPC UART hardware interface
 */
ewf_result ewf_interface_lpc_uart_hardware_stop(ewf_interface* interface_ptr);

/**
 * @brief Send a buffer using the LPC UART hardware interface
 */
ewf_result ewf_interface_lpc_uart_hardware_send(ewf_interface* interface_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);

/**
 * @brief Receive a buffer using the LPC UART hardware interface
 */
ewf_result ewf_interface_lpc_uart_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

#ifdef EWF_PARAMETER_CHECKING
#define EWF_INTERFACE_LPC_UART_INITIALIZE_HEADER(interface_ptr)                                                                                     \
do {                                                                                                                                                \
(interface_ptr)->struct_magic = EWF_INTERFACE_STRUCT_MAGIC;                                                                                         \
(interface_ptr)->struct_size = EWF_INTERFACE_STRUCT_SIZE;                                                                                           \
(interface_ptr)->struct_version = EWF_INTERFACE_VERSION;                                                                                            \
(interface_ptr)->struct_type = EWF_INTERFACE_TYPE_LPC_UART;                                                                                         \
} while(0)
#else
#define EWF_INTERFACE_LPC_UART_INITIALIZE_HEADER(interface_ptr)
#endif /* EWF_PARAMETER_CHECKING */

/**
 * @brief Declare a LPC UART host interface
 * @param[in,out] interface_ptr a pointer to an interface that will be initialized to point to the one statically declared by the macro
 * @param[in] interface_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 */
#define EWF_INTERFACE_LPC_UART_STATIC_DECLARE(interface_ptr, interface_name_symb, uart_base_ptr_param, baud_rate_param)                             \
do {                                                                                                                                                \
static ewf_interface_lpc_uart ewf_interface_lpc_uart__implementation__##interface_name_symb = {0};                                                  \
static ewf_interface ewf_interface_lpc_uart__interface__##interface_name_symb = {0};                                                                \
ewf_interface_lpc_uart__implementation__##interface_name_symb.base = uart_base_ptr_param;                                                           \
ewf_interface_lpc_uart__implementation__##interface_name_symb.buffer_size = EWF_INTERFACE_LPC_UART_RING_BUFFER_SIZE;                                \
ewf_interface_lpc_uart__implementation__##interface_name_symb.baud_rate = baud_rate_param;                                                          \
EWF_PLATFORM_MUTEX_STATIC_DECLARE(                                                                                                                  \
    ewf_interface_lpc_uart__implementation__##interface_name_symb.rx_mutex_ptr,                                                                     \
    ewf_interface_lpc_uart__uart_rx_mutex__##interface_name_symb);                                                                                  \
EWF_PLATFORM_QUEUE_STATIC_DECLARE(                                                                                                                  \
    ewf_interface_lpc_uart__interface__##interface_name_symb.response_queue_ptr,                                                                    \
    ewf_interface_lpc_uart__response_queue__##interface_name_symb,                                                                                  \
    ewf_interface_message,                                                                                                                          \
    EWF_INTERFACE_LPC_UART_CONFIG_RESPONSE_QUEUE_SIZE);                                                                                             \
EWF_PLATFORM_QUEUE_STATIC_DECLARE(                                                                                                                  \
    ewf_interface_lpc_uart__interface__##interface_name_symb.urc_queue_ptr,                                                                         \
    ewf_interface_lpc_uart__urc_queue__##interface_name_symb,                                                                                       \
    ewf_interface_message,                                                                                                                          \
    EWF_INTERFACE_LPC_UART_CONFIG_URC_QUEUE_SIZE);                                                                                                  \
ewf_interface_lpc_uart__interface__##interface_name_symb.hardware_start = ewf_interface_lpc_uart_hardware_start;                                    \
ewf_interface_lpc_uart__interface__##interface_name_symb.hardware_stop = ewf_interface_lpc_uart_hardware_stop;                                      \
ewf_interface_lpc_uart__interface__##interface_name_symb.hardware_send = ewf_interface_lpc_uart_hardware_send;                                      \
ewf_interface_lpc_uart__interface__##interface_name_symb.hardware_receive = ewf_interface_lpc_uart_hardware_receive;                                \
ewf_interface_lpc_uart__interface__##interface_name_symb.implementation_ptr = &(ewf_interface_lpc_uart__implementation__##interface_name_symb);     \
interface_ptr = &(ewf_interface_lpc_uart__interface__##interface_name_symb);                                                                        \
EWF_INTERFACE_LPC_UART_INITIALIZE_HEADER(interface_ptr);                                                                                            \
} while(0)

/************************************************************************//**
 * @} *** group_interface_lpc_uart
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_interface_lpc_uart__h__included__ */
