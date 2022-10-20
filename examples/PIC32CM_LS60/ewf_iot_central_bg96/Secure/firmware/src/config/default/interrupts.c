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
#include "device_vectors.h"
#include "interrupts.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

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
/* Device vectors list dummy definition*/
extern void SVCall_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PendSV_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SysTick_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SYSTEM_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
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
extern void EIC_OTHER_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void FREQM_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void NVMCTRL_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PORT_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_0_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_1_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_2_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_3_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_OTHER_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USB_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_3_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_4_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_5_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_6_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_7_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_NSCHK_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PAC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM0_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM0_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM0_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM0_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM4_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_1_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_2_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM5_OTHER_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC0_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC1_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC2_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC3_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_OTHER_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_RESRDY_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void AC_Handler                 ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DAC_UNDERRUN_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DAC_EMPTY_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PTC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TRNG_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void I2S_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TRAM_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));



/* Multiple handlers for vector */



__attribute__ ((section(".vectors")))
const H3DeviceVectors exception_table=
{
    /* Configure Initial Stack Pointer, using linker-generated symbols */
    .pvStack = &_stack,

    .pfnReset_Handler              = Reset_Handler,
    .pfnNonMaskableInt_Handler     = NonMaskableInt_Handler,
    .pfnHardFault_Handler          = HardFault_Handler,
    .pfnSVCall_Handler             = SVCall_Handler,
    .pfnPendSV_Handler             = PendSV_Handler,
    .pfnSysTick_Handler            = SysTick_Handler,
    .pfnSYSTEM_Handler             = SYSTEM_Handler,
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
    .pfnEIC_OTHER_Handler          = EIC_OTHER_Handler,
    .pfnFREQM_Handler              = FREQM_Handler,
    .pfnNVMCTRL_Handler            = NVMCTRL_Handler,
    .pfnPORT_Handler               = PORT_Handler,
    .pfnDMAC_0_Handler             = DMAC_0_Handler,
    .pfnDMAC_1_Handler             = DMAC_1_Handler,
    .pfnDMAC_2_Handler             = DMAC_2_Handler,
    .pfnDMAC_3_Handler             = DMAC_3_Handler,
    .pfnDMAC_OTHER_Handler         = DMAC_OTHER_Handler,
    .pfnUSB_Handler                = USB_Handler,
    .pfnEVSYS_0_Handler            = EVSYS_0_Handler,
    .pfnEVSYS_1_Handler            = EVSYS_1_Handler,
    .pfnEVSYS_2_Handler            = EVSYS_2_Handler,
    .pfnEVSYS_3_Handler            = EVSYS_3_Handler,
    .pfnEVSYS_4_Handler            = EVSYS_4_Handler,
    .pfnEVSYS_5_Handler            = EVSYS_5_Handler,
    .pfnEVSYS_6_Handler            = EVSYS_6_Handler,
    .pfnEVSYS_7_Handler            = EVSYS_7_Handler,
    .pfnEVSYS_NSCHK_Handler        = EVSYS_NSCHK_Handler,
    .pfnPAC_Handler                = PAC_Handler,
    .pfnSERCOM0_0_Handler          = SERCOM0_0_Handler,
    .pfnSERCOM0_1_Handler          = SERCOM0_1_Handler,
    .pfnSERCOM0_2_Handler          = SERCOM0_2_Handler,
    .pfnSERCOM0_OTHER_Handler      = SERCOM0_OTHER_Handler,
    .pfnSERCOM1_0_Handler          = SERCOM1_0_Handler,
    .pfnSERCOM1_1_Handler          = SERCOM1_1_Handler,
    .pfnSERCOM1_2_Handler          = SERCOM1_2_Handler,
    .pfnSERCOM1_OTHER_Handler      = SERCOM1_OTHER_Handler,
    .pfnSERCOM4_0_Handler          = SERCOM4_0_Handler,
    .pfnSERCOM4_1_Handler          = SERCOM4_1_Handler,
    .pfnSERCOM4_2_Handler          = SERCOM4_2_Handler,
    .pfnSERCOM4_OTHER_Handler      = SERCOM4_OTHER_Handler,
    .pfnSERCOM5_0_Handler          = SERCOM5_0_Handler,
    .pfnSERCOM5_1_Handler          = SERCOM5_1_Handler,
    .pfnSERCOM5_2_Handler          = SERCOM5_2_Handler,
    .pfnSERCOM5_OTHER_Handler      = SERCOM5_OTHER_Handler,
    .pfnTC0_Handler                = TC0_Handler,
    .pfnTC1_Handler                = TC1_Handler,
    .pfnTC2_Handler                = TC2_Handler,
    .pfnTCC0_Handler               = TCC0_Handler,
    .pfnTCC1_Handler               = TCC1_Handler,
    .pfnTCC2_Handler               = TCC2_Handler,
    .pfnTCC3_Handler               = TCC3_Handler,
    .pfnADC_OTHER_Handler          = ADC_OTHER_Handler,
    .pfnADC_RESRDY_Handler         = ADC_RESRDY_Handler,
    .pfnAC_Handler                 = AC_Handler,
    .pfnDAC_UNDERRUN_Handler       = DAC_UNDERRUN_Handler,
    .pfnDAC_EMPTY_Handler          = DAC_EMPTY_Handler,
    .pfnPTC_Handler                = PTC_Handler,
    .pfnTRNG_Handler               = TRNG_Handler,
    .pfnI2S_Handler                = I2S_Handler,
    .pfnTRAM_Handler               = TRAM_Handler,


};

/*******************************************************************************
 End of File
*/
