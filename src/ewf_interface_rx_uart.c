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

/* Flag for transmission complete */
volatile uint8_t tx_end_flag = 0;

void ewf_rx_uart_callback(void *pArgs);

/* Handle storage. Needs to persist as long as SCI calls are going to be made.*/
static sci_hdl_t   ewf_rx_sci_handle;

/*****************************************************************************
 * Function Name: ewf_rx_uart_callback
 * Description  : This is a template for an SCI Async Mode callback function.
 * Arguments    : pArgs -
 *                    pointer to sci_cb_args_t structure cast to a void. Structure
 *                    contains event and associated data.
 * Return Value : none
 ******************************************************************************/
void ewf_rx_uart_callback(void *pArgs)
{
    sci_cb_args_t   *args = (sci_cb_args_t *)pArgs;

    switch((args->event))
    {
        case SCI_EVT_RX_CHAR:
        {
            /* Do Nothing */
            break;
        }
        case SCI_EVT_TEI:
        {
            tx_end_flag = 1;
            break;
        }
        case SCI_EVT_XFER_DONE:
        {
#ifdef EWF_DEBUG
            EWF_LOG("SCI_EVT_XFER_DONE\n");
#endif
            break;
        }
        case SCI_EVT_XFER_ABORTED:
        {
#ifdef EWF_DEBUG
            EWF_LOG("SCI_EVT_XFER_ABORTED\n");
#endif
            break;
        }
        case SCI_EVT_OVFL_ERR:
        {
#ifdef EWF_DEBUG
            EWF_LOG("SCI_EVT_OVFL_ERR\n");
#endif
            break;
        }
        default:
        {
            break;
        }
    }
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
    ewf_interface_rx_uart* implementation_ptr = (ewf_interface_rx_uart*)interface_ptr->implementation_ptr;

    sci_cfg_t   ewf_rx_sci_config = {0};
    sci_err_t   sci_err;
#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
    /* UART Transmit Interrupt priority */
    uint8_t     priority = 14;
#endif

    R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL();

    /* Set up the configuration data structure for asynchronous (UART) operation. */
    ewf_rx_sci_config.async.baud_rate    = implementation_ptr->baudrate;
    ewf_rx_sci_config.async.clk_src      = SCI_CLK_INT;
    ewf_rx_sci_config.async.data_size    = SCI_DATA_8BIT;
    ewf_rx_sci_config.async.parity_en    = SCI_PARITY_OFF;
    ewf_rx_sci_config.async.parity_type  = SCI_EVEN_PARITY;
    ewf_rx_sci_config.async.stop_bits    = SCI_STOPBITS_1;
    ewf_rx_sci_config.async.int_priority = 15;    // 1=lowest, 15=highest

    /* OPEN ASYNC CHANNEL
     *  Provide address of the config structure,
     *  the callback function to be assigned,
     *  and the location for the handle to be stored.*/
#ifdef EWF_RENESAS_RX65N_CK_ENABLE
    sci_err = R_SCI_Open(R_SCI_CFG_EWF_CELLULAR_SERIAL_CH, SCI_MODE_ASYNC, &ewf_rx_sci_config, ewf_rx_uart_callback, &ewf_rx_sci_handle);
#else
    /* Cloud kit for RX65N */
    sci_err = R_SCI_Open(SCI_CH0, SCI_MODE_ASYNC, &ewf_rx_sci_config, ewf_rx_uart_callback, &ewf_rx_sci_handle);
#endif

    /* If there were an error this would demonstrate error detection of API calls. */
    if (SCI_SUCCESS != sci_err)
    {
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
    else
    {
        R_SCI_Control(ewf_rx_sci_handle, SCI_CMD_EN_CTS_IN, NULL);
#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
        R_SCI_Control(ewf_rx_sci_handle, SCI_CMD_SET_TXI_PRIORITY, &priority);
#endif

#ifdef EWF_RENESAS_RX65N_CK_ENABLE
        EWF_CELLULAR_SET_PODR(EWF_CELLULAR_CFG_RTS_PORT, EWF_CELLULAR_CFG_RTS_PIN) = 0;
        EWF_CELLULAR_SET_PDR(EWF_CELLULAR_CFG_RTS_PORT, EWF_CELLULAR_CFG_RTS_PIN) = EWF_CELLULAR_PIN_DIRECTION_MODE_OUTPUT;
#else
        /* Cloud KIT RX65N */
        PORT2.PODR.BIT.B2= 0;
        PORT2.PDR.BIT.B2= 1;
#endif

    }
    return EWF_RESULT_OK;
}


ewf_result ewf_interface_rx_uart_hardware_stop(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    R_SCI_Close(ewf_rx_sci_handle);

    return EWF_RESULT_OK;
}


ewf_result ewf_interface_rx_uart_hardware_send(ewf_interface* interface_ptr, const uint8_t * const buffer, uint32_t length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    /* Expect a valid buffer */
    if (!buffer) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (length  < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    sci_err_t err = SCI_SUCCESS;
    uint32_t local_timeout = (length * INT8_MAX);
    uint32_t byteq_unused_length = 0;

    R_SCI_Control(ewf_rx_sci_handle, SCI_CMD_TX_Q_BYTES_FREE, &byteq_unused_length);

    /* Wait for Tx buffer free */
    while((byteq_unused_length < length) && (--local_timeout))
    {
        R_SCI_Control(ewf_rx_sci_handle, SCI_CMD_TX_Q_BYTES_FREE, &byteq_unused_length);
    }

    local_timeout = (length * UINT16_MAX);
    tx_end_flag = 0;

    err = R_SCI_Send(ewf_rx_sci_handle, (uint8_t*)buffer, length);
    if (SCI_SUCCESS != err)
    {
        return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
    }

    /* Check for event transfer complete */
    while (--local_timeout)
    {
        /* Check if transmit end flag is set*/
        if (tx_end_flag == 1)
        {
            break;
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
                err = R_SCI_Receive(ewf_rx_sci_handle, &(buffer_ptr[i]), sizeof(uint8_t));
                if (err == SCI_ERR_INSUFFICIENT_DATA)
                {
                    if(i>0)
                    {
                        return EWF_RESULT_EMPTY_QUEUE;
                    }
                    ewf_platform_sleep(1);
                }
            }
            while(err == SCI_ERR_INSUFFICIENT_DATA);
        }
    }
    else
    {
        for (uint32_t i = 0; i < *buffer_length_ptr; i++)
        {
            err = R_SCI_Receive(ewf_rx_sci_handle, &(buffer_ptr[i]), sizeof(uint8_t));
            if (err == SCI_ERR_INSUFFICIENT_DATA)
            {
                return EWF_RESULT_EMPTY_QUEUE;
            }
        }
    }

    /* All ok! */
    return EWF_RESULT_OK;
}

