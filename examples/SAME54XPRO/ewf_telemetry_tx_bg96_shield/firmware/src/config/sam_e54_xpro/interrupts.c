/*******************************************************************************
 System Interrupts File

  Company:
    Microchip Technology Inc.

  File Name:
    interrupt.c

  Summary:
    Interrupt vectors mapping

  Description:
    This file maps all the interrupt vectors to their corresponding
    implementations. If a particular module interrupt is used, then its ISR
    definition can be found in corresponding PLIB source file. If a module
    interrupt is not used, then its ISR implementation is mapped to dummy
    handler.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "device_vectors.h"
#include "interrupts.h"
#include "definitions.h"


// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

/* MISRA C-2012 Rule 8.6 deviated below. Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
extern uint32_t _stack;
extern const H3DeviceVectors exception_table;

extern void Dummy_Handler(void);

/* Brief default interrupt handler for unused IRQs.*/
void __attribute__((optimize("-O1"),section(".text.Dummy_Handler"),long_call, noreturn))Dummy_Handler(void)
{
#if defined(__DEBUG) || defined(__DEBUG_D) && defined(__XC32)
    __builtin_software_breakpoint();
#endif
    while (true)
    {
    }
}

/* MISRAC 2012 deviation block start */
/* MISRA C-2012 Rule 8.6 deviated 128 times.  Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
/* Device vectors list dummy definition*/
extern void __tx_SVCallHandler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void __tx_PendSVHandler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PM_Handler                 ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void MCLK_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_XOSC0_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_XOSC1_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_DFLL_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_DPLL0_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSCCTRL_DPLL1_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void OSC32KCTRL_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SUPC_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SUPC_BODDET_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void WDT_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void RTC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_0_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_1_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_2_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_3_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_4_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_5_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_6_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_7_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_8_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_9_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_10_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_11_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_12_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_13_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_14_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EIC_EXTINT_15_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void FREQM_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void NVMCTRL_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void NVMCTRL_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_0_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_1_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_2_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_3_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_3_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_OTHER_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PAC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void RAMECC_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM6_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM7_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CAN0_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CAN1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USB_OTHER_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USB_SOF_HSOF_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USB_TRCPT0_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USB_TRCPT1_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void GMAC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC2_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC3_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC4_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_MC5_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC2_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_MC3_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_MC2_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC3_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC3_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC3_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC4_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC4_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC4_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC0_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC1_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC2_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC3_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC4_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC5_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC6_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC7_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PDEC_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PDEC_MC0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PDEC_MC1_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC0_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC0_RESRDY_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC1_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC1_RESRDY_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void AC_Handler                 ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DAC_OTHER_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DAC_EMPTY_0_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DAC_EMPTY_1_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DAC_RESRDY_0_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DAC_RESRDY_1_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void I2S_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PCC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void AES_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TRNG_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ICM_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PUKCC_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void QSPI_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SDHC0_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SDHC1_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));


/* MISRAC 2012 deviation block end */

/* Multiple handlers for vector */



__attribute__ ((section(".vectors")))
const H3DeviceVectors exception_table=
{
    /* Configure Initial Stack Pointer, using linker-generated symbols */
    .pvStack = &_stack,

    .pfnReset_Handler              = Reset_Handler,
    .pfnNonMaskableInt_Handler     = NonMaskableInt_Handler,
    .pfnHardFault_Handler          = HardFault_Handler,
    .pfnMemoryManagement_Handler   = MemoryManagement_Handler,
    .pfnBusFault_Handler           = BusFault_Handler,
    .pfnUsageFault_Handler         = UsageFault_Handler,
    .pfnSVCall_Handler             = __tx_SVCallHandler,
    .pfnDebugMonitor_Handler       = DebugMonitor_Handler,
    .pfnPendSV_Handler             = __tx_PendSVHandler,
    .pfnSysTick_Handler            = __tx_SysTickHandler,
    .pfnPM_Handler                 = PM_Handler,
    .pfnMCLK_Handler               = MCLK_Handler,
    .pfnOSCCTRL_XOSC0_Handler      = OSCCTRL_XOSC0_Handler,
    .pfnOSCCTRL_XOSC1_Handler      = OSCCTRL_XOSC1_Handler,
    .pfnOSCCTRL_DFLL_Handler       = OSCCTRL_DFLL_Handler,
    .pfnOSCCTRL_DPLL0_Handler      = OSCCTRL_DPLL0_Handler,
    .pfnOSCCTRL_DPLL1_Handler      = OSCCTRL_DPLL1_Handler,
    .pfnOSC32KCTRL_Handler         = OSC32KCTRL_Handler,
    .pfnSUPC_OTHER_Handler         = SUPC_OTHER_Handler,
    .pfnSUPC_BODDET_Handler        = SUPC_BODDET_Handler,
    .pfnWDT_Handler                = WDT_Handler,
    .pfnRTC_Handler                = RTC_Handler,
    .pfnEIC_EXTINT_0_Handler       = EIC_EXTINT_0_Handler,
    .pfnEIC_EXTINT_1_Handler       = EIC_EXTINT_1_Handler,
    .pfnEIC_EXTINT_2_Handler       = EIC_EXTINT_2_Handler,
    .pfnEIC_EXTINT_3_Handler       = EIC_EXTINT_3_Handler,
    .pfnEIC_EXTINT_4_Handler       = EIC_EXTINT_4_Handler,
    .pfnEIC_EXTINT_5_Handler       = EIC_EXTINT_5_Handler,
    .pfnEIC_EXTINT_6_Handler       = EIC_EXTINT_6_Handler,
    .pfnEIC_EXTINT_7_Handler       = EIC_EXTINT_7_Handler,
    .pfnEIC_EXTINT_8_Handler       = EIC_EXTINT_8_Handler,
    .pfnEIC_EXTINT_9_Handler       = EIC_EXTINT_9_Handler,
    .pfnEIC_EXTINT_10_Handler      = EIC_EXTINT_10_Handler,
    .pfnEIC_EXTINT_11_Handler      = EIC_EXTINT_11_Handler,
    .pfnEIC_EXTINT_12_Handler      = EIC_EXTINT_12_Handler,
    .pfnEIC_EXTINT_13_Handler      = EIC_EXTINT_13_Handler,
    .pfnEIC_EXTINT_14_Handler      = EIC_EXTINT_14_Handler,
    .pfnEIC_EXTINT_15_Handler      = EIC_EXTINT_15_Handler,
    .pfnFREQM_Handler              = FREQM_Handler,
    .pfnNVMCTRL_0_Handler          = NVMCTRL_0_Handler,
    .pfnNVMCTRL_1_Handler          = NVMCTRL_1_Handler,
    .pfnDMAC_0_Handler             = DMAC_0_Handler,
    .pfnDMAC_1_Handler             = DMAC_1_Handler,
    .pfnDMAC_2_Handler             = DMAC_2_Handler,
    .pfnDMAC_3_Handler             = DMAC_3_Handler,
    .pfnDMAC_OTHER_Handler         = DMAC_OTHER_Handler,
    .pfnEVSYS_0_Handler            = EVSYS_0_Handler,
    .pfnEVSYS_1_Handler            = EVSYS_1_Handler,
    .pfnEVSYS_2_Handler            = EVSYS_2_Handler,
    .pfnEVSYS_3_Handler            = EVSYS_3_Handler,
    .pfnEVSYS_OTHER_Handler        = EVSYS_OTHER_Handler,
    .pfnPAC_Handler                = PAC_Handler,
    .pfnRAMECC_Handler             = RAMECC_Handler,
    .pfnSERCOM0_0_Handler          = SERCOM0_USART_InterruptHandler,
    .pfnSERCOM0_1_Handler          = SERCOM0_USART_InterruptHandler,
    .pfnSERCOM0_2_Handler          = SERCOM0_USART_InterruptHandler,
    .pfnSERCOM0_OTHER_Handler      = SERCOM0_USART_InterruptHandler,
    .pfnSERCOM1_0_Handler          = SERCOM1_0_Handler,
    .pfnSERCOM1_1_Handler          = SERCOM1_1_Handler,
    .pfnSERCOM1_2_Handler          = SERCOM1_2_Handler,
    .pfnSERCOM1_OTHER_Handler      = SERCOM1_OTHER_Handler,
    .pfnSERCOM2_0_Handler          = SERCOM2_USART_InterruptHandler,
    .pfnSERCOM2_1_Handler          = SERCOM2_USART_InterruptHandler,
    .pfnSERCOM2_2_Handler          = SERCOM2_USART_InterruptHandler,
    .pfnSERCOM2_OTHER_Handler      = SERCOM2_USART_InterruptHandler,
    .pfnSERCOM3_0_Handler          = SERCOM3_0_Handler,
    .pfnSERCOM3_1_Handler          = SERCOM3_1_Handler,
    .pfnSERCOM3_2_Handler          = SERCOM3_2_Handler,
    .pfnSERCOM3_OTHER_Handler      = SERCOM3_OTHER_Handler,
    .pfnSERCOM4_0_Handler          = SERCOM4_0_Handler,
    .pfnSERCOM4_1_Handler          = SERCOM4_1_Handler,
    .pfnSERCOM4_2_Handler          = SERCOM4_2_Handler,
    .pfnSERCOM4_OTHER_Handler      = SERCOM4_OTHER_Handler,
    .pfnSERCOM5_0_Handler          = SERCOM5_0_Handler,
    .pfnSERCOM5_1_Handler          = SERCOM5_1_Handler,
    .pfnSERCOM5_2_Handler          = SERCOM5_2_Handler,
    .pfnSERCOM5_OTHER_Handler      = SERCOM5_OTHER_Handler,
    .pfnSERCOM6_0_Handler          = SERCOM6_0_Handler,
    .pfnSERCOM6_1_Handler          = SERCOM6_1_Handler,
    .pfnSERCOM6_2_Handler          = SERCOM6_2_Handler,
    .pfnSERCOM6_OTHER_Handler      = SERCOM6_OTHER_Handler,
    .pfnSERCOM7_0_Handler          = SERCOM7_0_Handler,
    .pfnSERCOM7_1_Handler          = SERCOM7_1_Handler,
    .pfnSERCOM7_2_Handler          = SERCOM7_2_Handler,
    .pfnSERCOM7_OTHER_Handler      = SERCOM7_OTHER_Handler,
    .pfnCAN0_Handler               = CAN0_Handler,
    .pfnCAN1_Handler               = CAN1_Handler,
    .pfnUSB_OTHER_Handler          = USB_OTHER_Handler,
    .pfnUSB_SOF_HSOF_Handler       = USB_SOF_HSOF_Handler,
    .pfnUSB_TRCPT0_Handler         = USB_TRCPT0_Handler,
    .pfnUSB_TRCPT1_Handler         = USB_TRCPT1_Handler,
    .pfnGMAC_Handler               = GMAC_Handler,
    .pfnTCC0_OTHER_Handler         = TCC0_OTHER_Handler,
    .pfnTCC0_MC0_Handler           = TCC0_MC0_Handler,
    .pfnTCC0_MC1_Handler           = TCC0_MC1_Handler,
    .pfnTCC0_MC2_Handler           = TCC0_MC2_Handler,
    .pfnTCC0_MC3_Handler           = TCC0_MC3_Handler,
    .pfnTCC0_MC4_Handler           = TCC0_MC4_Handler,
    .pfnTCC0_MC5_Handler           = TCC0_MC5_Handler,
    .pfnTCC1_OTHER_Handler         = TCC1_OTHER_Handler,
    .pfnTCC1_MC0_Handler           = TCC1_MC0_Handler,
    .pfnTCC1_MC1_Handler           = TCC1_MC1_Handler,
    .pfnTCC1_MC2_Handler           = TCC1_MC2_Handler,
    .pfnTCC1_MC3_Handler           = TCC1_MC3_Handler,
    .pfnTCC2_OTHER_Handler         = TCC2_OTHER_Handler,
    .pfnTCC2_MC0_Handler           = TCC2_MC0_Handler,
    .pfnTCC2_MC1_Handler           = TCC2_MC1_Handler,
    .pfnTCC2_MC2_Handler           = TCC2_MC2_Handler,
    .pfnTCC3_OTHER_Handler         = TCC3_OTHER_Handler,
    .pfnTCC3_MC0_Handler           = TCC3_MC0_Handler,
    .pfnTCC3_MC1_Handler           = TCC3_MC1_Handler,
    .pfnTCC4_OTHER_Handler         = TCC4_OTHER_Handler,
    .pfnTCC4_MC0_Handler           = TCC4_MC0_Handler,
    .pfnTCC4_MC1_Handler           = TCC4_MC1_Handler,
    .pfnTC0_Handler                = TC0_Handler,
    .pfnTC1_Handler                = TC1_Handler,
    .pfnTC2_Handler                = TC2_Handler,
    .pfnTC3_Handler                = TC3_Handler,
    .pfnTC4_Handler                = TC4_Handler,
    .pfnTC5_Handler                = TC5_Handler,
    .pfnTC6_Handler                = TC6_Handler,
    .pfnTC7_Handler                = TC7_Handler,
    .pfnPDEC_OTHER_Handler         = PDEC_OTHER_Handler,
    .pfnPDEC_MC0_Handler           = PDEC_MC0_Handler,
    .pfnPDEC_MC1_Handler           = PDEC_MC1_Handler,
    .pfnADC0_OTHER_Handler         = ADC0_OTHER_Handler,
    .pfnADC0_RESRDY_Handler        = ADC0_RESRDY_Handler,
    .pfnADC1_OTHER_Handler         = ADC1_OTHER_Handler,
    .pfnADC1_RESRDY_Handler        = ADC1_RESRDY_Handler,
    .pfnAC_Handler                 = AC_Handler,
    .pfnDAC_OTHER_Handler          = DAC_OTHER_Handler,
    .pfnDAC_EMPTY_0_Handler        = DAC_EMPTY_0_Handler,
    .pfnDAC_EMPTY_1_Handler        = DAC_EMPTY_1_Handler,
    .pfnDAC_RESRDY_0_Handler       = DAC_RESRDY_0_Handler,
    .pfnDAC_RESRDY_1_Handler       = DAC_RESRDY_1_Handler,
    .pfnI2S_Handler                = I2S_Handler,
    .pfnPCC_Handler                = PCC_Handler,
    .pfnAES_Handler                = AES_Handler,
    .pfnTRNG_Handler               = TRNG_Handler,
    .pfnICM_Handler                = ICM_Handler,
    .pfnPUKCC_Handler              = PUKCC_Handler,
    .pfnQSPI_Handler               = QSPI_Handler,
    .pfnSDHC0_Handler              = SDHC0_Handler,
    .pfnSDHC1_Handler              = SDHC1_Handler,


};

/*******************************************************************************
 End of File
*/
