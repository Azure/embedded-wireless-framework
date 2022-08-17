/*******************************************************************************
  Console System Service Local Data Structures

  Company:
    Microchip Technology Inc.

  File Name:
    sys_console_uart.h

  Summary:
    Console System Service local declarations and definitions for UART I/O
    device.

  Description:
    This file contains the Console System Service local declarations and
    definitions for UART I/O device.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef SYS_CONSOLE_UART_H
#define SYS_CONSOLE_UART_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include "sys_console_local.h"
#include "osal/osal.h"
#include "system/console/src/sys_console_uart_definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Type Definitions
// *****************************************************************************
// *****************************************************************************

typedef struct
{
    /* Pointer to USART APIs used by the console system service*/
    const SYS_CONSOLE_UART_PLIB_INTERFACE* uartPLIB;

    SYS_CONSOLE_STATUS status;

    /* Mutex to protect access to the transfer objects */
    OSAL_MUTEX_DECLARE(mutexTransferObjects);

} CONSOLE_UART_DATA;

void Console_UART_Initialize(uint32_t index, const void* initData);
SYS_CONSOLE_STATUS Console_UART_Status(uint32_t index);
void Console_UART_Tasks(uint32_t index, SYS_MODULE_OBJ object);
ssize_t Console_UART_Read(uint32_t index, void* pRdBuffer, size_t count);
ssize_t Console_UART_ReadCountGet(uint32_t index);
ssize_t Console_UART_ReadFreeBufferCountGet(uint32_t index);
ssize_t Console_UART_Write(uint32_t index, const void* pWrBuffer, size_t count );
ssize_t Console_UART_WriteFreeBufferCountGet(uint32_t index);
ssize_t Console_UART_WriteCountGet(uint32_t index);
bool Console_UART_Flush(uint32_t index);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus

    }

#endif
// DOM-IGNORE-END

#endif //#ifndef SYS_CONSOLE_UART_H