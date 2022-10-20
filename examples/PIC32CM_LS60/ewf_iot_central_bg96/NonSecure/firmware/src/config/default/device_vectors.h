/*******************************************************************************
 Cortex-M device vectors file

  Company:
    Microchip Technology Inc.

  File Name:
    device_vectors.h

  Summary:
    Harmony3 device handler structure for cortex-M devices

  Description:
    This file contains Harmony3 device handler structure for cortex-M devices
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

#ifndef DEVICE_VECTORS_H
#define DEVICE_VECTORS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/* Function pointer type for vector handlers */
typedef void (*pfn_handler_t)(void);

/* Structure defining device vector types */
typedef struct H3DeviceVectorsTag
{
  /* Stack pointer */
  uint32_t* pvStack;

  /* CORTEX-M23 handlers */ 
  pfn_handler_t pfnReset_Handler;                   /* -15 Reset Vector, invoked on Power up and warm reset */
  pfn_handler_t pfnNonMaskableInt_Handler;          /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  pfn_handler_t pfnHardFault_Handler;               /* -13 Hard Fault, all classes of Fault */
  pfn_handler_t pfnReservedC12;
  pfn_handler_t pfnReservedC11;
  pfn_handler_t pfnReservedC10;
  pfn_handler_t pfnReservedC9;
  pfn_handler_t pfnReservedC8;
  pfn_handler_t pfnReservedC7;
  pfn_handler_t pfnReservedC6;
  pfn_handler_t pfnSVCall_Handler;                  /* -5 System Service Call via SVC instruction */
  pfn_handler_t pfnReservedC4;
  pfn_handler_t pfnReservedC3;
  pfn_handler_t pfnPendSV_Handler;                  /* -2 Pendable request for system service */
  pfn_handler_t pfnSysTick_Handler;                 /* -1 System Tick Timer */

  /* Peripheral handlers */
  pfn_handler_t pfnSYSTEM_Handler;                  /* 0 System peripherals shared interrupt */
  pfn_handler_t pfnWDT_Handler;                     /* 1 Watchdog Timer */
  pfn_handler_t pfnRTC_Handler;                     /* 2 Real Time Counter */
  pfn_handler_t pfnEIC_EXTINT_0_Handler;            /* 3 External Channel 0 */
  pfn_handler_t pfnEIC_EXTINT_1_Handler;            /* 4 External Channel 1 */
  pfn_handler_t pfnEIC_EXTINT_2_Handler;            /* 5 External Channel 2 */
  pfn_handler_t pfnEIC_EXTINT_3_Handler;            /* 6 External Channel 3 */
  pfn_handler_t pfnEIC_EXTINT_4_Handler;            /* 7 External Channel 4 */
  pfn_handler_t pfnEIC_EXTINT_5_Handler;            /* 8 External Channel 5 */
  pfn_handler_t pfnEIC_EXTINT_6_Handler;            /* 9 External Channel 6 */
  pfn_handler_t pfnEIC_EXTINT_7_Handler;            /* 10 External Channel 7 */
  pfn_handler_t pfnEIC_OTHER_Handler;               /* 11 External Channel 8..X */
  pfn_handler_t pfnFREQM_Handler;                   /* 12 Frequency Meter */
  pfn_handler_t pfnNVMCTRL_Handler;                 /* 13 Non-Volatile Memory Controller */
  pfn_handler_t pfnPORT_Handler;                    /* 14 Port Non-Secure Check */
  pfn_handler_t pfnDMAC_0_Handler;                  /* 15 DMA Channel 0 */
  pfn_handler_t pfnDMAC_1_Handler;                  /* 16 DMA Channel 1 */
  pfn_handler_t pfnDMAC_2_Handler;                  /* 17 DMA Channel 2 */
  pfn_handler_t pfnDMAC_3_Handler;                  /* 18 DMA Channel 3 */
  pfn_handler_t pfnDMAC_OTHER_Handler;              /* 19 DMA Channel 4..X */
  pfn_handler_t pfnUSB_Handler;                     /* 20 Universal Serial Bus */
  pfn_handler_t pfnEVSYS_0_Handler;                 /* 21 Event System Channel 0 */
  pfn_handler_t pfnEVSYS_1_Handler;                 /* 22 Event System Channel 1 */
  pfn_handler_t pfnEVSYS_2_Handler;                 /* 23 Event System Channel 2 */
  pfn_handler_t pfnEVSYS_3_Handler;                 /* 24 Event System Channel 3 */
  pfn_handler_t pfnEVSYS_4_Handler;                 /* 25 Event System Channel 4 */
  pfn_handler_t pfnEVSYS_5_Handler;                 /* 26 Event System Channel 5 */
  pfn_handler_t pfnEVSYS_6_Handler;                 /* 27 Event System Channel 6 */
  pfn_handler_t pfnEVSYS_7_Handler;                 /* 28 Event System Channel 7 */
  pfn_handler_t pfnEVSYS_NSCHK_Handler;             /* 29 Event System Non-Secure Check */
  pfn_handler_t pfnPAC_Handler;                     /* 30 Peripheral Access Controller */
  pfn_handler_t pfnSERCOM0_0_Handler;               /* 31 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_1_Handler;               /* 32 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_2_Handler;               /* 33 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_OTHER_Handler;           /* 34 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM1_0_Handler;               /* 35 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_1_Handler;               /* 36 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_2_Handler;               /* 37 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_OTHER_Handler;           /* 38 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM2_0_Handler;               /* 39 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_1_Handler;               /* 40 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_2_Handler;               /* 41 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_OTHER_Handler;           /* 42 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM3_0_Handler;               /* 43 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_1_Handler;               /* 44 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_2_Handler;               /* 45 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_OTHER_Handler;           /* 46 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM4_0_Handler;               /* 47 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_1_Handler;               /* 48 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_2_Handler;               /* 49 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_OTHER_Handler;           /* 50 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM5_0_Handler;               /* 51 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_1_Handler;               /* 52 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_2_Handler;               /* 53 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_OTHER_Handler;           /* 54 Serial Communication Interface 5 */
  pfn_handler_t pfnTC0_Handler;                     /* 55 Timer Counter 0 */
  pfn_handler_t pfnTC1_Handler;                     /* 56 Timer Counter 1 */
  pfn_handler_t pfnTC2_Handler;                     /* 57 Timer Counter 2 */
  pfn_handler_t pfnTCC0_Handler;                    /* 58 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC1_Handler;                    /* 59 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC2_Handler;                    /* 60 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC3_Handler;                    /* 61 TCC Match/Compare 3 */
  pfn_handler_t pfnADC_OTHER_Handler;               /* 62 Analog To Digital Converter */
  pfn_handler_t pfnADC_RESRDY_Handler;              /* 63 ADC Result Ready */
  pfn_handler_t pfnAC_Handler;                      /* 64 Analog Comparator */
  pfn_handler_t pfnDAC_UNDERRUN_Handler;            /* 65 Digital to Analog Converter */
  pfn_handler_t pfnDAC_EMPTY_Handler;               /* 66 DAC Buffer 0 Empty */
  pfn_handler_t pfnPTC_Handler;                     /* 67 Peripheral Touch Controller */
  pfn_handler_t pfnTRNG_Handler;                    /* 68 True Random Generator */
  pfn_handler_t pfnI2S_Handler;                     /* 69 Inter-IC Sound Interface */
  pfn_handler_t pfnTRAM_Handler;                    /* 70 Trust Ram */
}H3DeviceVectors;

#endif //DEVICE_VECTORS_H
