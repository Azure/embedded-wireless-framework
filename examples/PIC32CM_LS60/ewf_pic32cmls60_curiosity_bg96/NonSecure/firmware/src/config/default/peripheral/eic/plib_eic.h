/******************************************************************************* External Interrupt Controller (EIC) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_eic.h

  Summary
    EIC PLIB Header File.

  Description
    This file defines the interface to the EIC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.
*******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

/* Guards against multiple inclusion */
#ifndef PLIB_EIC_H
#define PLIB_EIC_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "device.h"
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* The following data type definitions are used by the functions in this
    interface and should be considered part of it.
*/

/* EIC Pin Count */
#define EXTINT_COUNT                        (16U)

// *****************************************************************************
/* EIC Pins

  Summary:
    Identifies the available EIC pins.

  Description:
    This enumeration identifies all the available EIC pins. Not all pins will be
    implemented in a device. The pins described here are for documentation
    purposes only. The MHC will generate this enumeration with the enabled EIC
    pins only. The application should not use the constant value that are
    assigned to enumeration constants as this may vary between devices.

  Remarks:
    None.
*/

typedef enum
{
    /* External Interrupt Controller Pin 4 */
    EIC_PIN_4 = 4,
    /* External Interrupt Controller Pin 12 */
    EIC_PIN_12 = 12,
    EIC_PIN_MAX = 16

} EIC_PIN;


typedef void (*EIC_CALLBACK) (uintptr_t context);

typedef struct
{
    /* External Interrupt Pin Callback Handler */
    EIC_CALLBACK    callback;

    /* External Interrupt Pin Client context */
    uintptr_t       context;

    /* External Interrupt Pin number */
    EIC_PIN         eicPinNo;

} EIC_CALLBACK_OBJ;

void EIC_Initialize (void);
void EIC_InterruptEnable (EIC_PIN pin);
void EIC_InterruptDisable (EIC_PIN pin);
void EIC_CallbackRegister(EIC_PIN pin, EIC_CALLBACK callback, uintptr_t context);



#ifdef __cplusplus // Provide C++ Compatibility
}
#endif

#endif /* PLIB_EIC_H */
