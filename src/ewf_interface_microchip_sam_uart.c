/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Microchip SAM UART HOST interface API
 ****************************************************************************/


#include "ewf_interface_microchip_sam_uart.h"
#include "peripheral/sercom/usart/plib_sercom0_usart.h"

#ifdef EWF_PLATFORM_THREADX
#include "tx_api.h"
#endif

/******************************************************************************
 *
 * Hardware interface functions
 *
 ******************************************************************************/


ewf_result ewf_interface_microchip_sam_uart_hardware_start(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_MICROCHIP_SAM_UART);
    
    /* Initialize UART channel with baud rate 115200 */
    SERCOM0_USART_Initialize();
    
    return EWF_RESULT_OK;
}


ewf_result ewf_interface_microchip_sam_uart_hardware_stop(ewf_interface* interface_ptr)
{

    /* Disable RX event notifications */
    SERCOM0_USART_ReadNotificationEnable(false, false);

    return EWF_RESULT_OK;
}


ewf_result ewf_interface_microchip_sam_uart_hardware_send(ewf_interface* interface_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    /* Expect a valid buffer */
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (buffer_length  < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    {
      uint32_t local_timeout = (buffer_length * UINT16_MAX);

      /* Writing to terminal */
      if (!SERCOM0_USART_Write ((uint8_t *) buffer_ptr, (size_t)buffer_length))
      {
          return EWF_RESULT_INTERFACE_SEND_FAILED;
      }

      /* Check for event transfer complete */
      while ((!SERCOM0_USART_TransmitComplete()) && (--local_timeout))
      {
          /* Check if any error event occurred */
          if (SERCOM0_USART_ErrorGet())
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

ewf_result ewf_interface_microchip_sam_uart_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
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
                bytesread = SERCOM0_USART_Read(&buffer_ptr[i],sizeof(uint8_t));
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
            
            bytesread = SERCOM0_USART_Read(&buffer_ptr[i],sizeof(uint8_t));
            if(!bytesread)
            {
                return EWF_RESULT_INTERFACE_RECEIVE_FAILED;
            }
        }
    }

    /* All ok! */
    return EWF_RESULT_OK;
}

