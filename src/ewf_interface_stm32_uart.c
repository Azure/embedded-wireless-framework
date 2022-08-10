/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework STM32 UART Host Interface API.
 ****************************************************************************/

#include "ewf_interface_stm32_uart.h"

/******************************************************************************
 *
 * Internal data
 *
 ******************************************************************************/

static ewf_interface* _interface_ptr;

/******************************************************************************
 *
 * Internal functions
 *
 ******************************************************************************/

static void _ewf_interface_stm32_uart_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (_interface_ptr)
    {
        ewf_interface_stm32_uart* implementation_ptr = _interface_ptr->implementation_ptr;
        if (implementation_ptr->uart_handle_ptr == huart)
        {
            ewf_result result = ewf_platform_queue_enqueue(implementation_ptr->rx_queue_ptr, implementation_ptr->rx_buffer, sizeof(uint8_t), false);
            if (ewf_result_failed(result))
            {
                EWF_LOG_ERROR("Failed to enqueue a received byte on the STM32 UART RX completion callback, ewf_result %d.\n", result);
                // continue, try again...
            }

            /* re-set the reception interrupt */
            HAL_UART_Receive_IT(implementation_ptr->uart_handle_ptr, implementation_ptr->rx_buffer, sizeof(uint8_t));
        }
    }
}

/******************************************************************************
 *
 * Hardware interface functions
 *
 ******************************************************************************/

ewf_result ewf_interface_stm32_uart_hardware_start(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_interface_stm32_uart* implementation_ptr = interface_ptr->implementation_ptr;

    _interface_ptr = interface_ptr;

    ewf_result result = ewf_platform_queue_create(implementation_ptr->rx_queue_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to create the STM32 UART reception queue, ewf_result %d.\n", result);
        return result;
    }

    HAL_UART_RegisterCallback(implementation_ptr->uart_handle_ptr, HAL_UART_RX_COMPLETE_CB_ID, _ewf_interface_stm32_uart_RxCpltCallback);

    /* Start the reception interrupt cycle */
    HAL_UART_Receive_IT(implementation_ptr->uart_handle_ptr, implementation_ptr->rx_buffer, sizeof(uint8_t));

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_stm32_uart_hardware_stop(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_interface_stm32_uart* implementation_ptr = interface_ptr->implementation_ptr;

    ewf_result result = ewf_platform_queue_destroy(implementation_ptr->rx_queue_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to destroy the STM32 UART reception queue, ewf_result %d.\n", result);
        return result;
    }

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_stm32_uart_hardware_send(ewf_interface* interface_ptr, const uint8_t * buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_interface_stm32_uart* implementation_ptr = interface_ptr->implementation_ptr;

    /* Expect a valid buffer */
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (buffer_length  < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    /* Transmit the buffer in blocking mode */
    HAL_UART_Transmit(implementation_ptr->uart_handle_ptr, (uint8_t*)buffer_ptr, buffer_length, HAL_MAX_DELAY);

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_stm32_uart_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_STM32_UART);
    ewf_interface_stm32_uart* implementation_ptr = interface_ptr->implementation_ptr;

    /* Expect a valid buffer */
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!buffer_length_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (*buffer_length_ptr < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    /* Receive */
    for (int i = 0; i < *buffer_length_ptr; i++)
    {
        uint32_t dequeue_size = sizeof(uint8_t);
        ewf_result result = ewf_platform_queue_dequeue(implementation_ptr->rx_queue_ptr, &(buffer_ptr[i]), &dequeue_size, wait);
        if (result == EWF_RESULT_EMPTY_QUEUE)
        {
            return result;
        }
        else if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Failed to dequeue a byte from STM32 UART reception queue, ewf_result %d.\n", result);
            return result;
        }
    }

    /* All ok! */
    return EWF_RESULT_OK;
}
