/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework RA UART Host Interface API.
 ****************************************************************************/

#include "ewf_interface_ra_uart.h"
#include "ewf_lib.h"

/******************************************************************************
 *
 * Internal functions
 *
 ******************************************************************************/

#define UART_ERROR_EVENTS (UART_EVENT_BREAK_DETECT | UART_EVENT_ERR_OVERFLOW | UART_EVENT_ERR_FRAMING | \
                                    UART_EVENT_ERR_PARITY)    /* UART Error event bits mapped in registers */

/* Flag for user callback */
static volatile uint8_t g_uart_event = {0};

static ewf_interface* g_interface_ptr = NULL;
static uint8_t _rx_buffer[sizeof(uint8_t)];

/**
 *  @brief UART user callback
 *  @param[in] p_args The UART callback arguments
 */
void user_uart_callback(uart_callback_args_t *p_args)
{
	/* Logged the event in global variable */
	g_uart_event = (uint8_t) p_args->event;
	if (g_interface_ptr)
	{
		ewf_interface_ra_uart *implementation_ptr = g_interface_ptr->implementation_ptr;

		/* If received a character, process it */
		if (UART_EVENT_RX_CHAR & p_args->event)
		{
			/* Read Received character. RXNE flag is cleared by reading of RDR register */
			_rx_buffer[0] = (uint8_t ) p_args->data;

			ewf_result result = ewf_platform_queue_enqueue(implementation_ptr->rx_queue_ptr, _rx_buffer,
					sizeof(uint8_t), false);
			if (ewf_result_failed(result))
			{
				EWF_LOG_ERROR("Failed to enqueue a received byte on the RA UART callback, ewf_result %d.\n",result);
				// continue, try again...
			}
		}
	}
}

/******************************************************************************
 *
 * Hardware interface functions
 *
 ******************************************************************************/

ewf_result ewf_interface_ra_uart_hardware_start(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_interface_ra_uart* implementation_ptr = interface_ptr->implementation_ptr;

    fsp_err_t status = FSP_SUCCESS;

    ewf_result result = ewf_platform_queue_create(implementation_ptr->rx_queue_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to create the RA UART reception queue, ewf_result %d.\n", result);
        return result;
    }

    /* Save the interface pointer */
    g_interface_ptr = interface_ptr;

    /* Initialize UART channel */
    status = R_SCI_UART_Open (&g_uart0_ctrl, &g_uart0_cfg);
    if (FSP_SUCCESS != status)
      return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;

   return EWF_RESULT_OK;
}

ewf_result ewf_interface_ra_uart_hardware_stop(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_SUPPORTS_THREADING
    ewf_interface_ra_uart* implementation_ptr = interface_ptr->implementation_ptr;
    ewf_platform_mutex_destroy(&implementation_ptr->mutex);
#endif

    /* Close module */
    R_SCI_UART_Close (&g_uart0_ctrl);

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_ra_uart_hardware_send(ewf_interface* interface_ptr, const uint8_t * const buffer, uint32_t length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    /* Expect a valid buffer */
    if (!buffer) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (length  < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    fsp_err_t err = FSP_SUCCESS;
    uint32_t local_timeout = (length * UINT16_MAX);

    /* Reset callback capture variable */
    g_uart_event = 0;

    /* Writing to terminal */
    err = R_SCI_UART_Write (&g_uart0_ctrl, (uint8_t *) buffer, length);
    if (FSP_SUCCESS != err)
    {
        return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
    }

    /* Check for event transfer complete */
    while ((UART_EVENT_TX_COMPLETE != g_uart_event) && (--local_timeout))
    {
        /* Check if any error event occurred */
        if (UART_ERROR_EVENTS == g_uart_event)
        {
            return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
        }
    }

    if (0 == local_timeout)
    {
        return EWF_RESULT_TIMEOUT;
    }

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_ra_uart_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_interface_ra_uart* implementation_ptr = interface_ptr->implementation_ptr;

    /* Expect a valid buffer */
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!buffer_length_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (*buffer_length_ptr < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    /* Receive */
    for (uint32_t i = 0; i < *buffer_length_ptr; i++)
    {
    	uint32_t dequeue_size = sizeof(uint8_t);
    	ewf_result result = ewf_platform_queue_dequeue(implementation_ptr->rx_queue_ptr, &(buffer_ptr[i]), &dequeue_size, wait);
        if (result == EWF_RESULT_EMPTY_QUEUE)
        {
            return result;
        }
        else if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Failed to dequeue a byte from RA UART reception queue, ewf_result %d.\n", result);
            return result;
        }
    }

    /* All ok! */
    return EWF_RESULT_OK;
}
