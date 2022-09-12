/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Microchip SAM UART HOST interface API
 ****************************************************************************/


#include "ewf_interface_microchip_pic_uart.h"
#include "peripheral/sercom/usart/plib_sercom2_usart.h"

/******************************************************************************
 *
 * Hardware interface functions
 *
 ******************************************************************************/

ewf_result ewf_interface_microchip_pic_uart_hardware_start(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_MICROCHIP_PIC_UART);

    /* Initialize UART channel with baud rate 115200 */
    SERCOM2_USART_Initialize();
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_microchip_pic_uart_hardware_stop(ewf_interface* interface_ptr)
{

    /* Disable RX event notifications */
    SERCOM2_USART_ReadNotificationEnable(false, false);

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_microchip_pic_uart_hardware_send(ewf_interface* interface_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    /* Expect a valid buffer */
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (buffer_length  < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    {
      uint32_t local_timeout = (buffer_length * UINT16_MAX);

      /* Writing to terminal */
      if (!SERCOM2_USART_Write ((uint8_t *) buffer_ptr, (size_t)buffer_length))
      {
          return EWF_RESULT_INTERFACE_SEND_FAILED;
      }

      /* Check for event transfer complete */
      while ((!SERCOM2_USART_TransmitComplete()) && (--local_timeout))
      {
          /* Check if any error event occurred */
          if (SERCOM2_USART_ErrorGet())
          {
              return EWF_RESULT_INTERFACE_SEND_FAILED;
          }
      }

      if(0 == local_timeout)
      {
          return EWF_RESULT_TIMEOUT;
      }
    }

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_microchip_pic_uart_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
	EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

	/* Expect a valid buffer */
	if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	if (!buffer_length_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	if (*buffer_length_ptr < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    size_t bytesread;
	/* Receive */
	if(wait)
	{
		for (uint32_t i = 0; i < *buffer_length_ptr; i++)
		{
			do
			{
                bytesread = SERCOM2_USART_Read(&buffer_ptr[i],sizeof(uint8_t));
                if(!bytesread)
                {
					ewf_platform_sleep(1);                    
                }
			}
			while(bytesread == 0);
		}
	}
	else
	{
		for (uint32_t i = 0; i < *buffer_length_ptr; i++)
		{
			
            bytesread = SERCOM2_USART_Read(&buffer_ptr[i],sizeof(uint8_t));
            if(!bytesread)
            {
                // No data available in the UART ring buffer
                return EWF_RESULT_EMPTY_QUEUE;
            }
		}
	}

	/* All ok! */
	return EWF_RESULT_OK;
}
