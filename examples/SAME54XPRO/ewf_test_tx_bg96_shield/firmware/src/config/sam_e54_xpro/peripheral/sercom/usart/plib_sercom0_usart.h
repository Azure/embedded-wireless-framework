/*******************************************************************************
  SERCOM Universal Synchronous/Asynchrnous Receiver/Transmitter PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_sercom0_usart.h

  Summary
    USART peripheral library interface.

  Description
    This file defines the interface to the USART peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.
*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef PLIB_SERCOM0_USART_H // Guards against multiple inclusion
#define PLIB_SERCOM0_USART_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "plib_sercom_usart_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

void SERCOM0_USART_Initialize( void );

bool SERCOM0_USART_SerialSetup( USART_SERIAL_SETUP * serialSetup, uint32_t clkFrequency );

USART_ERROR SERCOM0_USART_ErrorGet( void );

uint32_t SERCOM0_USART_FrequencyGet( void );


bool SERCOM0_USART_TransmitComplete( void );

size_t SERCOM0_USART_Write(uint8_t* pWrBuffer, const size_t size );

size_t SERCOM0_USART_WriteCountGet(void);

size_t SERCOM0_USART_WriteFreeBufferCountGet(void);

size_t SERCOM0_USART_WriteBufferSizeGet(void);

bool SERCOM0_USART_WriteNotificationEnable(bool isEnabled, bool isPersistent);

void SERCOM0_USART_WriteThresholdSet(uint32_t nBytesThreshold);

void SERCOM0_USART_WriteCallbackRegister( SERCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context);



size_t SERCOM0_USART_Read(uint8_t* pRdBuffer, const size_t size);

size_t SERCOM0_USART_ReadCountGet(void);

size_t SERCOM0_USART_ReadFreeBufferCountGet(void);

size_t SERCOM0_USART_ReadBufferSizeGet(void);

bool SERCOM0_USART_ReadNotificationEnable(bool isEnabled, bool isPersistent);

void SERCOM0_USART_ReadThresholdSet(uint32_t nBytesThreshold);

void SERCOM0_USART_ReadCallbackRegister( SERCOM_USART_RING_BUFFER_CALLBACK callback, uintptr_t context);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END

#endif //PLIB_SERCOM0_USART_H