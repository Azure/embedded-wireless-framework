/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework RX UART HOST interface API
 ****************************************************************************/

#include "ewf_interface_rx_uart.h"
#include "ewf_lib.h"



/******************************************************************************
 * Internal functions
 ******************************************************************************/

#define UART_ERROR_EVENTS (SCI_EVT_FRAMING_ERR | \
		SCI_EVT_RXBUF_OVFL | SCI_EVT_OVFL_ERR)    /* UART Error event bits mapped in registers */

/* Flag for user callback */
static volatile uint8_t g_uart_event = {0};
static ewf_interface* g_interface_ptr = NULL;

void my_sci_callback(void *pArgs);

/* Handle storage. Needs to persist as long as SCI calls are going to be made.*/
static sci_hdl_t   g_my_sci_handle;


/*****************************************************************************
 * Function Name: my_sci_callback
 * Description  : This is a template for an SCI Async Mode callback function.
 * Arguments    : pArgs -
 *                    pointer to sci_cb_args_t structure cast to a void. Structure
 *                    contains event and associated data.
 * Return Value : none
 ******************************************************************************/
void my_sci_callback(void *pArgs)
{
	sci_cb_args_t   *args;

	args = (sci_cb_args_t *)pArgs;

	/* Logged the event in global variable */
	g_uart_event = (uint8_t)args->event;
}


/******************************************************************************
 *
 * Hardware interface functions
 *
 ******************************************************************************/

ewf_result ewf_interface_rx_uart_hardware_start(ewf_interface* interface_ptr)
{
	EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
	EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_RX_UART);

	ewf_result result;

	sci_cfg_t   my_sci_config;
	sci_err_t   my_sci_err;
	uint32_t    my_version;
	uint8_t     my_char;
	uint8_t version_str[12] = {0};
#if defined(EWF_RENESAS_RX_INTERFACE_RYZ014_ENABLE)
#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
	uint8_t     priority = 3-1;
#endif
#endif
	/* Initialize the I/O port pins for communication on this SCI channel.
	 * This is specific to the MCU and ports chosen. For the RSKRX65N-2M we will use the
	 * SCI channel connected to the USB serial port emulation. */

	R_SCI_PinSet_SCI0();

	/* Set up the configuration data structure for asynchronous (UART) operation. */
#if (EWF_RENESAS_RX_INTERFACE_RYZ014_ENABLE==1)
	my_sci_config.async.baud_rate    = 921600;
#else
	my_sci_config.async.baud_rate    = 115200;
#endif
	my_sci_config.async.clk_src      = SCI_CLK_INT;
	my_sci_config.async.data_size    = SCI_DATA_8BIT;
	my_sci_config.async.parity_en    = SCI_PARITY_OFF;
	my_sci_config.async.parity_type  = SCI_EVEN_PARITY;
	my_sci_config.async.stop_bits    = SCI_STOPBITS_1;
	my_sci_config.async.int_priority = 4;    // 1=lowest, 15=highest

	/* OPEN ASYNC CHANNEL
	 *  Provide address of the config structure,
	 *  the callback function to be assigned,
	 *  and the location for the handle to be stored.*/
	my_sci_err = R_SCI_Open(SCI_CH0, SCI_MODE_ASYNC, &my_sci_config, my_sci_callback, &g_my_sci_handle);

	/* If there were an error this would demonstrate error detection of API calls. */
	if (SCI_SUCCESS != my_sci_err)
	{
		return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
	}
#if (EWF_RENESAS_RX_INTERFACE_RYZ014_ENABLE==1)
	else
	{
		R_SCI_Control(g_my_sci_handle, SCI_CMD_EN_CTS_IN, NULL);
#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
		R_SCI_Control(g_my_sci_handle, SCI_CMD_SET_TXI_PRIORITY, &priority);
#endif
		PORT2.PODR.BIT.B2= 0;
		PORT2.PDR.BIT.B2= 1;
	}
#endif
	return EWF_RESULT_OK;
}


ewf_result ewf_interface_rx_uart_hardware_stop(ewf_interface* interface_ptr)
{
	EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_SUPPORTS_THREADING
	ewf_interface_rx_uart* implementation_ptr = interface_ptr->implementation_ptr;
	ewf_platform_mutex_destroy(&implementation_ptr->mutex);
#endif

	R_SCI_Close(SCI_CH0);

	return EWF_RESULT_OK;
}


ewf_result ewf_interface_rx_uart_hardware_send(ewf_interface* interface_ptr, const uint8_t * const buffer, uint32_t length)
{
	EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

	/* Expect a valid buffer */
	if (!buffer) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	if (length  < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

	/* Save the interface pointer */
	g_interface_ptr = interface_ptr;

	sci_err_t err = SCI_SUCCESS;
	uint32_t local_timeout = (length * UINT16_MAX);

	err = R_SCI_Send(g_my_sci_handle, (uint8_t*)buffer, length);
	if (SCI_SUCCESS != err)
	{
		return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
	}

	/* Check for event transfer complete */
	while ((SCI_EVT_TEI != g_uart_event) && (--local_timeout))
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


ewf_result ewf_interface_rx_uart_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
	EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

	/* Expect a valid buffer */
	if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	if (!buffer_length_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	if (*buffer_length_ptr < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

	sci_err_t err;

	/* Receive */
	if(wait)
	{
		for (uint32_t i = 0; i < *buffer_length_ptr; i++)
		{
			do
			{
				err = R_SCI_Receive(g_my_sci_handle, &(buffer_ptr[i]), sizeof(uint8_t));
				if (err == SCI_ERR_INSUFFICIENT_DATA)
				{
					ewf_platform_sleep(1);
				}
				else if(err != SCI_SUCCESS)
				{
					EWF_LOG_ERROR("Failed to receieve a byte from RX UART, sci_err_t %d.\n", err);
					return EWF_RESULT_IRRECOVERABLE_ERROR;
				}
			}
			while(err == SCI_ERR_INSUFFICIENT_DATA);
		}
	}
	else
	{
		for (uint32_t i = 0; i < *buffer_length_ptr; i++)
		{
			err = R_SCI_Receive(g_my_sci_handle, &(buffer_ptr[i]), sizeof(uint8_t));
			if (err == SCI_ERR_INSUFFICIENT_DATA)
			{
				return EWF_RESULT_EMPTY_QUEUE;
			}
			else if (err != SCI_SUCCESS)
			{
				EWF_LOG_ERROR("Failed to receieve a byte from RX UART, sci_err_t %d.\n", err);
				return EWF_RESULT_IRRECOVERABLE_ERROR;
			}
		}
	}

	/* All ok! */
	return EWF_RESULT_OK;
}

