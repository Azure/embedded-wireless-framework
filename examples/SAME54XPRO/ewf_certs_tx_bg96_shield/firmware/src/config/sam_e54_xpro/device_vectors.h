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

  /* CORTEX-M4 handlers */ 
  pfn_handler_t pfnReset_Handler;                   /* -15 Reset Vector, invoked on Power up and warm reset */
  pfn_handler_t pfnNonMaskableInt_Handler;          /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  pfn_handler_t pfnHardFault_Handler;               /* -13 Hard Fault, all classes of Fault */
  pfn_handler_t pfnMemoryManagement_Handler;        /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  pfn_handler_t pfnBusFault_Handler;                /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  pfn_handler_t pfnUsageFault_Handler;              /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  pfn_handler_t pfnReservedC9;
  pfn_handler_t pfnReservedC8;
  pfn_handler_t pfnReservedC7;
  pfn_handler_t pfnReservedC6;
  pfn_handler_t pfnSVCall_Handler;                  /* -5 System Service Call via SVC instruction */
  pfn_handler_t pfnDebugMonitor_Handler;            /* -4 Debug Monitor */
  pfn_handler_t pfnReservedC3;
  pfn_handler_t pfnPendSV_Handler;                  /* -2 Pendable request for system service */
  pfn_handler_t pfnSysTick_Handler;                 /* -1 System Tick Timer */

  /* Peripheral handlers */
  pfn_handler_t pfnPM_Handler;                      /* 0 Power Manager */
  pfn_handler_t pfnMCLK_Handler;                    /* 1 Main Clock */
  pfn_handler_t pfnOSCCTRL_XOSC0_Handler;           /* 2 External Oscillator 0 */
  pfn_handler_t pfnOSCCTRL_XOSC1_Handler;           /* 3 External Oscillator 1 */
  pfn_handler_t pfnOSCCTRL_DFLL_Handler;            /* 4 Digital Frequency Locked Loop */
  pfn_handler_t pfnOSCCTRL_DPLL0_Handler;           /* 5 Digital Phase Locked Loop 0 */
  pfn_handler_t pfnOSCCTRL_DPLL1_Handler;           /* 6 Digital Phase Locked Loop 1 */
  pfn_handler_t pfnOSC32KCTRL_Handler;              /* 7 32Khz Oscillator Controller */
  pfn_handler_t pfnSUPC_OTHER_Handler;              /* 8 Suppyly controller */
  pfn_handler_t pfnSUPC_BODDET_Handler;             /* 9 Brown Out Detection */
  pfn_handler_t pfnWDT_Handler;                     /* 10 Watch Dog Timer */
  pfn_handler_t pfnRTC_Handler;                     /* 11 Real Time Counter */
  pfn_handler_t pfnEIC_EXTINT_0_Handler;            /* 12 EIC Channel 0 */
  pfn_handler_t pfnEIC_EXTINT_1_Handler;            /* 13 EIC Channel 1 */
  pfn_handler_t pfnEIC_EXTINT_2_Handler;            /* 14 EIC Channel 2 */
  pfn_handler_t pfnEIC_EXTINT_3_Handler;            /* 15 EIC Channel 3 */
  pfn_handler_t pfnEIC_EXTINT_4_Handler;            /* 16 EIC Channel 4 */
  pfn_handler_t pfnEIC_EXTINT_5_Handler;            /* 17 EIC Channel 5 */
  pfn_handler_t pfnEIC_EXTINT_6_Handler;            /* 18 EIC Channel 6 */
  pfn_handler_t pfnEIC_EXTINT_7_Handler;            /* 19 EIC Channel 7 */
  pfn_handler_t pfnEIC_EXTINT_8_Handler;            /* 20 EIC Channel 8 */
  pfn_handler_t pfnEIC_EXTINT_9_Handler;            /* 21 EIC Channel 9 */
  pfn_handler_t pfnEIC_EXTINT_10_Handler;           /* 22 EIC Channel 10 */
  pfn_handler_t pfnEIC_EXTINT_11_Handler;           /* 23 EIC Channel 11 */
  pfn_handler_t pfnEIC_EXTINT_12_Handler;           /* 24 EIC Channel 12 */
  pfn_handler_t pfnEIC_EXTINT_13_Handler;           /* 25 EIC Channel 13 */
  pfn_handler_t pfnEIC_EXTINT_14_Handler;           /* 26 EIC Channel 14 */
  pfn_handler_t pfnEIC_EXTINT_15_Handler;           /* 27 EIC Channel 15 */
  pfn_handler_t pfnFREQM_Handler;                   /* 28 Frequency Meter */
  pfn_handler_t pfnNVMCTRL_0_Handler;               /* 29 Non-Volatile Memory Controller */
  pfn_handler_t pfnNVMCTRL_1_Handler;               /* 30 NVMCTRL SmartEEPROM Interrupts */
  pfn_handler_t pfnDMAC_0_Handler;                  /* 31 DMA Channel 0 */
  pfn_handler_t pfnDMAC_1_Handler;                  /* 32 DMA Channel 1 */
  pfn_handler_t pfnDMAC_2_Handler;                  /* 33 DMA Channel 2 */
  pfn_handler_t pfnDMAC_3_Handler;                  /* 34 DMA Channel 3 */
  pfn_handler_t pfnDMAC_OTHER_Handler;              /* 35 DMA Channel 4..X */
  pfn_handler_t pfnEVSYS_0_Handler;                 /* 36 Event System Channel 0 */
  pfn_handler_t pfnEVSYS_1_Handler;                 /* 37 Event System Channel 1 */
  pfn_handler_t pfnEVSYS_2_Handler;                 /* 38 Event System Channel 2 */
  pfn_handler_t pfnEVSYS_3_Handler;                 /* 39 Event System Channel 3 */
  pfn_handler_t pfnEVSYS_OTHER_Handler;             /* 40 Event System Channel 4..X */
  pfn_handler_t pfnPAC_Handler;                     /* 41 Peripheral Access Controller */
  pfn_handler_t pfnReserved42;
  pfn_handler_t pfnReserved43;
  pfn_handler_t pfnReserved44;
  pfn_handler_t pfnRAMECC_Handler;                  /* 45 RAM Error Correction Code */
  pfn_handler_t pfnSERCOM0_0_Handler;               /* 46 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_1_Handler;               /* 47 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_2_Handler;               /* 48 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM0_OTHER_Handler;           /* 49 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM1_0_Handler;               /* 50 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_1_Handler;               /* 51 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_2_Handler;               /* 52 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM1_OTHER_Handler;           /* 53 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM2_0_Handler;               /* 54 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_1_Handler;               /* 55 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_2_Handler;               /* 56 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM2_OTHER_Handler;           /* 57 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM3_0_Handler;               /* 58 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_1_Handler;               /* 59 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_2_Handler;               /* 60 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM3_OTHER_Handler;           /* 61 Serial Communication Interface 3 */
  pfn_handler_t pfnSERCOM4_0_Handler;               /* 62 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_1_Handler;               /* 63 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_2_Handler;               /* 64 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM4_OTHER_Handler;           /* 65 Serial Communication Interface 4 */
  pfn_handler_t pfnSERCOM5_0_Handler;               /* 66 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_1_Handler;               /* 67 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_2_Handler;               /* 68 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM5_OTHER_Handler;           /* 69 Serial Communication Interface 5 */
  pfn_handler_t pfnSERCOM6_0_Handler;               /* 70 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM6_1_Handler;               /* 71 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM6_2_Handler;               /* 72 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM6_OTHER_Handler;           /* 73 Serial Communication Interface 6 */
  pfn_handler_t pfnSERCOM7_0_Handler;               /* 74 Serial Communication Interface 7 */
  pfn_handler_t pfnSERCOM7_1_Handler;               /* 75 Serial Communication Interface 7 */
  pfn_handler_t pfnSERCOM7_2_Handler;               /* 76 Serial Communication Interface 7 */
  pfn_handler_t pfnSERCOM7_OTHER_Handler;           /* 77 Serial Communication Interface 7 */
  pfn_handler_t pfnCAN0_Handler;                    /* 78 Controller Area Network 0 */
  pfn_handler_t pfnCAN1_Handler;                    /* 79 Controller Area Network 1 */
  pfn_handler_t pfnUSB_OTHER_Handler;               /* 80 Universal Serial Bus */
  pfn_handler_t pfnUSB_SOF_HSOF_Handler;            /* 81 USB Start of Frame */
  pfn_handler_t pfnUSB_TRCPT0_Handler;              /* 82 USB Transfer Complete 0 */
  pfn_handler_t pfnUSB_TRCPT1_Handler;              /* 83 USB Transfer Complete 1 */
  pfn_handler_t pfnGMAC_Handler;                    /* 84 Ethernet MAC */
  pfn_handler_t pfnTCC0_OTHER_Handler;              /* 85 Timer Counter Control 0 */
  pfn_handler_t pfnTCC0_MC0_Handler;                /* 86 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC0_MC1_Handler;                /* 87 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC0_MC2_Handler;                /* 88 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC0_MC3_Handler;                /* 89 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC0_MC4_Handler;                /* 90 TCC Match/Compare 4 */
  pfn_handler_t pfnTCC0_MC5_Handler;                /* 91 TCC Match/Compare 5 */
  pfn_handler_t pfnTCC1_OTHER_Handler;              /* 92 Timer Counter Control 1 */
  pfn_handler_t pfnTCC1_MC0_Handler;                /* 93 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC1_MC1_Handler;                /* 94 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC1_MC2_Handler;                /* 95 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC1_MC3_Handler;                /* 96 TCC Match/Compare 3 */
  pfn_handler_t pfnTCC2_OTHER_Handler;              /* 97 Timer Counter Control 2 */
  pfn_handler_t pfnTCC2_MC0_Handler;                /* 98 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC2_MC1_Handler;                /* 99 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC2_MC2_Handler;                /* 100 TCC Match/Compare 2 */
  pfn_handler_t pfnTCC3_OTHER_Handler;              /* 101 Timer Counter Control 3 */
  pfn_handler_t pfnTCC3_MC0_Handler;                /* 102 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC3_MC1_Handler;                /* 103 TCC Match/Compare 1 */
  pfn_handler_t pfnTCC4_OTHER_Handler;              /* 104 Timer Counter Control 4 */
  pfn_handler_t pfnTCC4_MC0_Handler;                /* 105 TCC Match/Compare 0 */
  pfn_handler_t pfnTCC4_MC1_Handler;                /* 106 TCC Match/Compare 1 */
  pfn_handler_t pfnTC0_Handler;                     /* 107 Timer Counter 0 */
  pfn_handler_t pfnTC1_Handler;                     /* 108 Timer Counter 1 */
  pfn_handler_t pfnTC2_Handler;                     /* 109 Timer Counter 2 */
  pfn_handler_t pfnTC3_Handler;                     /* 110 Timer Counter 3 */
  pfn_handler_t pfnTC4_Handler;                     /* 111 Timer Counter 4 */
  pfn_handler_t pfnTC5_Handler;                     /* 112 Timer Counter 5 */
  pfn_handler_t pfnTC6_Handler;                     /* 113 Timer Counter 6 */
  pfn_handler_t pfnTC7_Handler;                     /* 114 Timer Counter 7 */
  pfn_handler_t pfnPDEC_OTHER_Handler;              /* 115 Position Decoder */
  pfn_handler_t pfnPDEC_MC0_Handler;                /* 116 PDEC Match/Compare 0 */
  pfn_handler_t pfnPDEC_MC1_Handler;                /* 117 PDEC Match Compare 1 */
  pfn_handler_t pfnADC0_OTHER_Handler;              /* 118 Analog To Digital Converter 0 */
  pfn_handler_t pfnADC0_RESRDY_Handler;             /* 119 ADC0 Result Ready */
  pfn_handler_t pfnADC1_OTHER_Handler;              /* 120 Analog To Digital Converter 1 */
  pfn_handler_t pfnADC1_RESRDY_Handler;             /* 121 ADC1 Result Ready */
  pfn_handler_t pfnAC_Handler;                      /* 122 Analog Comparator */
  pfn_handler_t pfnDAC_OTHER_Handler;               /* 123 Digital to Analog Converter */
  pfn_handler_t pfnDAC_EMPTY_0_Handler;             /* 124 DAC Buffer 0 Empty */
  pfn_handler_t pfnDAC_EMPTY_1_Handler;             /* 125 DAC Buffer 1 Empty */
  pfn_handler_t pfnDAC_RESRDY_0_Handler;            /* 126 DAC Filter 0 Result Ready */
  pfn_handler_t pfnDAC_RESRDY_1_Handler;            /* 127 DAC Filter 1 Result Ready */
  pfn_handler_t pfnI2S_Handler;                     /* 128 Inter-IC Sound Interface */
  pfn_handler_t pfnPCC_Handler;                     /* 129 Parallel Capture Controller */
  pfn_handler_t pfnAES_Handler;                     /* 130 Advanced Encryption Standard */
  pfn_handler_t pfnTRNG_Handler;                    /* 131 True Random Generator */
  pfn_handler_t pfnICM_Handler;                     /* 132 Integrity Check Monitor */
  pfn_handler_t pfnPUKCC_Handler;                   /* 133 Public-Key Cryptography Controller */
  pfn_handler_t pfnQSPI_Handler;                    /* 134 Quad SPI interface */
  pfn_handler_t pfnSDHC0_Handler;                   /* 135 SD/MMC Host Controller 0 */
  pfn_handler_t pfnSDHC1_Handler;                   /* 136 SD/MMC Host Controller 1 */
}H3DeviceVectors;

#endif //DEVICE_VECTORS_H
