/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework LPC UART HOST interface API
 ****************************************************************************/

#include "ewf_interface_lpc_uart.h"
#include "board.h"
#include "fsl_common.h"

/******************************************************************************
 *
 * Internal functions
 *
 ******************************************************************************/

#if FSL_FEATURE_SOC_LPUART_COUNT > 0
static void _ewf_interface_lpc_uart_callback(LPUART_Type *base, lpuart_handle_t *state, status_t status, void* user_data_ptr)
#elif FSL_FEATURE_SOC_USART_COUNT > 0
static void _ewf_interface_lpc_uart_callback(USART_Type *base, usart_handle_t *state, status_t status, void* user_data_ptr)
#endif
{
	if (!user_data_ptr) return;
    ewf_interface* interface_ptr = (ewf_interface*) user_data_ptr;
    ewf_interface_lpc_uart* implementation_ptr = interface_ptr->implementation_ptr;

    switch (status)
    {
#if FSL_FEATURE_SOC_LPUART_COUNT > 0
        case kStatus_LPUART_TxIdle:
#elif FSL_FEATURE_SOC_USART_COUNT > 0
        case kStatus_USART_TxIdle:
#endif
        {
        	// TX complete
        }
		break;

#if FSL_FEATURE_SOC_LPUART_COUNT > 0
        case kStatus_LPUART_RxIdle:
#elif FSL_FEATURE_SOC_USART_COUNT > 0
        case kStatus_USART_RxIdle:
#endif
        {
            ewf_platform_mutex_put(implementation_ptr->rx_mutex_ptr);
        	// RX complete
        }
		break;

#if FSL_FEATURE_SOC_LPUART_COUNT > 0
        case kStatus_LPUART_RxRingBufferOverrun:
#elif FSL_FEATURE_SOC_USART_COUNT > 0
        case kStatus_USART_RxRingBufferOverrun:
#endif
        {
        	// RX overrun
        }
		break;

        default:
        {
        	// Something else happened
        }
        break;
    }
}

/******************************************************************************
 *
 * Hardware interface functions
 *
 ******************************************************************************/

ewf_result ewf_interface_lpc_uart_hardware_start(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_LPC_UART);
    ewf_interface_lpc_uart* implementation_ptr = interface_ptr->implementation_ptr;

    ewf_result result;

    result = ewf_platform_mutex_create(implementation_ptr->rx_mutex_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to create the LPC UART reception mutex, ewf_result %d.\n", result);
        return result;
    }

    status_t ret;

#if FSL_FEATURE_SOC_LPUART_COUNT > 0
    LPUART_GetDefaultConfig(&implementation_ptr->config);
#elif FSL_FEATURE_SOC_USART_COUNT > 0
    USART_GetDefaultConfig(&implementation_ptr->config);
#endif

    implementation_ptr->config.baudRate_Bps = implementation_ptr->baud_rate;
    implementation_ptr->config.enableTx     = true;
    implementation_ptr->config.enableRx     = true;

#if FSL_FEATURE_SOC_LPUART_COUNT > 0
    ret = LPUART_Init(implementation_ptr->base, &implementation_ptr->config, BOARD_DEBUG_UART_CLK_FREQ);
#elif FSL_FEATURE_SOC_USART_COUNT > 0
    ret = USART_Init(implementation_ptr->base, &implementation_ptr->config, BOARD_DEBUG_UART_CLK_FREQ);
#endif
    if (ret != kStatus_Success)
    {
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

#if FSL_FEATURE_SOC_LPUART_COUNT > 0
    LPUART_TransferCreateHandle(
		implementation_ptr->base,
		&implementation_ptr->handle,
		_ewf_interface_lpc_uart_callback,
		interface_ptr);
#elif FSL_FEATURE_SOC_USART_COUNT > 0
    ret = USART_TransferCreateHandle(
		implementation_ptr->base,
		&implementation_ptr->handle,
		_ewf_interface_lpc_uart_callback,
		interface_ptr);
    if (ret != kStatus_Success)
    {
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if FSL_FEATURE_SOC_LPUART_COUNT > 0
    LPUART_TransferStartRingBuffer(
		implementation_ptr->base,
		&implementation_ptr->handle,
		implementation_ptr->ring_buffer,
		implementation_ptr->buffer_size);
#elif FSL_FEATURE_SOC_USART_COUNT > 0
    USART_TransferStartRingBuffer(
		implementation_ptr->base,
		&implementation_ptr->handle,
		implementation_ptr->ring_buffer,
		implementation_ptr->buffer_size);
#endif

    ewf_platform_mutex_get(implementation_ptr->rx_mutex_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_lpc_uart_hardware_stop(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_LPC_UART);
    ewf_interface_lpc_uart* implementation_ptr = interface_ptr->implementation_ptr;

    ewf_result result;

    result = ewf_platform_mutex_destroy(implementation_ptr->rx_mutex_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to destroy the LPC UART reception mutex, ewf_result %d.\n", result);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_lpc_uart_hardware_send(ewf_interface* interface_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_LPC_UART);
    ewf_interface_lpc_uart* implementation_ptr = interface_ptr->implementation_ptr;

    UINT status;

    /* Expect a valid buffer */
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (buffer_length < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    /* Send the data */
#if FSL_FEATURE_SOC_LPUART_COUNT > 0
    LPUART_WriteBlocking(implementation_ptr->base, buffer_ptr, buffer_length);
#elif FSL_FEATURE_SOC_USART_COUNT > 0
    USART_WriteBlocking(implementation_ptr->base, buffer_ptr, buffer_length);
#endif

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_lpc_uart_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_LPC_UART);
    ewf_interface_lpc_uart* implementation_ptr = interface_ptr->implementation_ptr;

    UINT status;

    /* Expect a valid buffer */
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!buffer_length_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (*buffer_length_ptr < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (wait)
    {
    	implementation_ptr->xfer.data = buffer_ptr;
    	implementation_ptr->xfer.dataSize = *buffer_length_ptr;

    	size_t receivedBytes;
#if FSL_FEATURE_SOC_LPUART_COUNT > 0
    	LPUART_TransferReceiveNonBlocking(
			implementation_ptr->base,
			&implementation_ptr->handle,
			&implementation_ptr->xfer,
			&receivedBytes);
#elif FSL_FEATURE_SOC_USART_COUNT > 0
    	USART_TransferReceiveNonBlocking(
			implementation_ptr->base,
			&implementation_ptr->handle,
			&implementation_ptr->xfer,
			&receivedBytes);
#endif

		*buffer_length_ptr = receivedBytes;

		ewf_platform_mutex_get(implementation_ptr->rx_mutex_ptr);
    }
    else
    {
#if FSL_FEATURE_SOC_LPUART_COUNT > 0
    	size_t rx_length = LPUART_TransferGetRxRingBufferLength(implementation_ptr->base, &implementation_ptr->handle);
#elif FSL_FEATURE_SOC_USART_COUNT > 0
    	size_t rx_length = USART_TransferGetRxRingBufferLength(&implementation_ptr->handle);
#endif
    	if (rx_length == 0)
    	{
    		return EWF_RESULT_NO_DATA_AVAILABLE;
    	}

    	implementation_ptr->xfer.data = buffer_ptr;
    	implementation_ptr->xfer.dataSize = *buffer_length_ptr;

    	size_t receivedBytes;
#if FSL_FEATURE_SOC_LPUART_COUNT > 0
    	LPUART_TransferReceiveNonBlocking(
			implementation_ptr->base,
			&implementation_ptr->handle,
			&implementation_ptr->xfer,
			&receivedBytes);
#elif FSL_FEATURE_SOC_USART_COUNT > 0
    	USART_TransferReceiveNonBlocking(
			implementation_ptr->base,
			&implementation_ptr->handle,
			&implementation_ptr->xfer,
			&receivedBytes);
#endif

		*buffer_length_ptr = receivedBytes;

        ewf_platform_mutex_get(implementation_ptr->rx_mutex_ptr);
    }

    /* All ok! */
    return EWF_RESULT_OK;
}
