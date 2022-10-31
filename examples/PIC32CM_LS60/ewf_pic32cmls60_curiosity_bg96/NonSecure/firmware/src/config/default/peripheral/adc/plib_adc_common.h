/*******************************************************************************
  Analog-to-Digital Converter(ADC) Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_adc_common.h

  Summary
    ADC Peripheral Library Interface Header File.

  Description
    This file defines the common types for the ADC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PLIB_ADC_COMMON_H    // Guards against multiple inclusion
#define PLIB_ADC_COMMON_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Preprocessor macros
// *****************************************************************************
// *****************************************************************************
#define ADC_STATUS_NONE 0U
#define ADC_STATUS_RESRDY ADC_INTFLAG_RESRDY_Msk
#define ADC_STATUS_WINMON ADC_INTFLAG_WINMON_Msk
#define ADC_STATUS_MASK (ADC_STATUS_RESRDY | ADC_STATUS_OVERRUN | ADC_STATUS_WINMON)    
#define ADC_STATUS_INVALID 0xFFFFFFFFU

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* The following data type definitions are used by the functions in this
    interface and should be considered part it.
*/

typedef enum
{
    ADC_POSINPUT_AIN0 = ADC_INPUTCTRL_MUXPOS_AIN0,
    ADC_POSINPUT_AIN1 = ADC_INPUTCTRL_MUXPOS_AIN1,
    ADC_POSINPUT_AIN2 = ADC_INPUTCTRL_MUXPOS_AIN2,
    ADC_POSINPUT_AIN3 = ADC_INPUTCTRL_MUXPOS_AIN3,
    ADC_POSINPUT_AIN4 = ADC_INPUTCTRL_MUXPOS_AIN4,
    ADC_POSINPUT_AIN5 = ADC_INPUTCTRL_MUXPOS_AIN5,
    ADC_POSINPUT_AIN6 = ADC_INPUTCTRL_MUXPOS_AIN6,
    ADC_POSINPUT_AIN7 = ADC_INPUTCTRL_MUXPOS_AIN7,
    ADC_POSINPUT_AIN8 = ADC_INPUTCTRL_MUXPOS_AIN8,
    ADC_POSINPUT_AIN9 = ADC_INPUTCTRL_MUXPOS_AIN9,
    ADC_POSINPUT_AIN10 = ADC_INPUTCTRL_MUXPOS_AIN10,
    ADC_POSINPUT_AIN11 = ADC_INPUTCTRL_MUXPOS_AIN11,
    ADC_POSINPUT_AIN12 = ADC_INPUTCTRL_MUXPOS_AIN12,
    ADC_POSINPUT_AIN13 = ADC_INPUTCTRL_MUXPOS_AIN13,
    ADC_POSINPUT_AIN14 = ADC_INPUTCTRL_MUXPOS_AIN14,
    ADC_POSINPUT_AIN15 = ADC_INPUTCTRL_MUXPOS_AIN15,
    ADC_POSINPUT_AIN16 = ADC_INPUTCTRL_MUXPOS_AIN16,
    ADC_POSINPUT_AIN17 = ADC_INPUTCTRL_MUXPOS_AIN17,
    ADC_POSINPUT_AIN18 = ADC_INPUTCTRL_MUXPOS_AIN18,
    ADC_POSINPUT_AIN19 = ADC_INPUTCTRL_MUXPOS_AIN19,
    ADC_POSINPUT_AIN20 = ADC_INPUTCTRL_MUXPOS_AIN20,
    ADC_POSINPUT_AIN21 = ADC_INPUTCTRL_MUXPOS_AIN21,
    ADC_POSINPUT_AIN22 = ADC_INPUTCTRL_MUXPOS_AIN22,
    ADC_POSINPUT_AIN23 = ADC_INPUTCTRL_MUXPOS_AIN23,
    ADC_POSINPUT_BANDGAP = ADC_INPUTCTRL_MUXPOS_BANDGAP,
    ADC_POSINPUT_SCALEDVDDCORE = ADC_INPUTCTRL_MUXPOS_SCALEDVDDCORE,
    ADC_POSINPUT_SCALEDAVDD = ADC_INPUTCTRL_MUXPOS_SCALEDAVDD,
    ADC_POSINPUT_DAC0 = ADC_INPUTCTRL_MUXPOS_DAC0,
    ADC_POSINPUT_SCALEDVDD = ADC_INPUTCTRL_MUXPOS_SCALEDVDD,
    ADC_POSINPUT_OPAMP01 = ADC_INPUTCTRL_MUXPOS_OPAMP01,
    ADC_POSINPUT_OPAMP2 = ADC_INPUTCTRL_MUXPOS_OPAMP2,
}ADC_POSINPUT;

// *****************************************************************************

typedef enum
{
    ADC_NEGINPUT_AIN0 = ADC_INPUTCTRL_MUXNEG_AIN0,
    ADC_NEGINPUT_AIN1 = ADC_INPUTCTRL_MUXNEG_AIN1,
    ADC_NEGINPUT_AIN2 = ADC_INPUTCTRL_MUXNEG_AIN2,
    ADC_NEGINPUT_AIN3 = ADC_INPUTCTRL_MUXNEG_AIN3,
    ADC_NEGINPUT_AIN4 = ADC_INPUTCTRL_MUXNEG_AIN4,
    ADC_NEGINPUT_AIN5 = ADC_INPUTCTRL_MUXNEG_AIN5,
    ADC_NEGINPUT_AIN6 = ADC_INPUTCTRL_MUXNEG_AIN6,
    ADC_NEGINPUT_AIN7 = ADC_INPUTCTRL_MUXNEG_AIN7,
    ADC_NEGINPUT_AVSS = ADC_INPUTCTRL_MUXNEG_AVSS,
}ADC_NEGINPUT;

typedef uint32_t ADC_STATUS;
typedef enum
{
    ADC_WINMODE_DISABLED = ADC_CTRLC_WINMODE_DISABLE_Val,
    ADC_WINMODE_GREATER_THAN_WINLT = ADC_CTRLC_WINMODE_MODE1_Val,
    ADC_WINMODE_LESS_THAN_WINUT = ADC_CTRLC_WINMODE_MODE2_Val,
    ADC_WINMODE_BETWEEN_WINLT_AND_WINUT = ADC_CTRLC_WINMODE_MODE3_Val,
    ADC_WINMODE_OUTSIDE_WINLT_AND_WINUT = ADC_CTRLC_WINMODE_MODE4_Val
}ADC_WINMODE;


// *****************************************************************************


typedef void (*ADC_CALLBACK)(ADC_STATUS status, uintptr_t context);


typedef struct
{
    ADC_CALLBACK callback;

    uintptr_t context;

} ADC_CALLBACK_OBJ;



// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END

#endif /* PLIB_ADC_COMMON_H*/
