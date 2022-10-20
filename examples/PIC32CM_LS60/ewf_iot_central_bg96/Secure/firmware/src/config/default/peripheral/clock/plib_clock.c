/*******************************************************************************
 CLOCK PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_clock.c

  Summary:
    CLOCK PLIB Implementation File.

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_clock.h"
#include "device.h"
#include "interrupts.h"




static void OSCCTRL_Initialize(void)
{
    /**************** OSC16M IniTialization *************/
    OSCCTRL_REGS->OSCCTRL_OSC16MCTRL = OSCCTRL_OSC16MCTRL_FSEL(0x0U) | OSCCTRL_OSC16MCTRL_ENABLE_Msk;
}

static void OSC32KCTRL_Initialize(void)
{
    OSC32KCTRL_REGS->OSC32KCTRL_RTCCTRL = OSC32KCTRL_RTCCTRL_RTCSEL(0U);
}

static void DFLL48M_Initialize(void)
{
    /****************** DFLL Initialization  *********************************/
    OSCCTRL_REGS->OSCCTRL_DFLLCTRL = 0U ;

    while((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_DFLLRDY_Msk) != OSCCTRL_STATUS_DFLLRDY_Msk)
    {
        /* Waiting for the Ready state */
    }

    /*Load Calibration Value*/
    uint8_t calibCoarse = (uint8_t)(((*(uint32_t*)0x806020U) >> 25U ) & 0x3fU);

    OSCCTRL_REGS->OSCCTRL_DFLLVAL = OSCCTRL_DFLLVAL_COARSE((uint32_t)calibCoarse) | OSCCTRL_DFLLVAL_FINE((uint32_t)512U);

    while((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_DFLLRDY_Msk) != OSCCTRL_STATUS_DFLLRDY_Msk)
    {
        /* Waiting for the Ready state */
    }

    /* Configure DFLL    */
    OSCCTRL_REGS->OSCCTRL_DFLLCTRL = OSCCTRL_DFLLCTRL_ENABLE_Msk ;

    while((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_DFLLRDY_Msk) != OSCCTRL_STATUS_DFLLRDY_Msk)
    {
        /* Waiting for DFLL to be ready */
    }
}




static void GCLK0_Initialize(void)
{

    GCLK_REGS->GCLK_GENCTRL[0] = GCLK_GENCTRL_DIV(1U) | GCLK_GENCTRL_SRC(7U) | GCLK_GENCTRL_GENEN_Msk;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL0_Msk) == GCLK_SYNCBUSY_GENCTRL0_Msk)
    {
        /* wait for the Generator 0 synchronization */
    }
}

void CLOCK_Initialize (void)
{
    /* Function to Initialize the Oscillators */
    OSCCTRL_Initialize();

    /* Function to Initialize the 32KHz Oscillators */
    OSC32KCTRL_Initialize();

    SUPC_REGS->SUPC_VREGPLL = SUPC_VREGPLL_ENABLE_Msk;
    DFLL48M_Initialize();
    GCLK0_Initialize();



    /* Selection of the Generator and write Lock for SERCOM2_CORE */
    GCLK_REGS->GCLK_PCHCTRL[19] = GCLK_PCHCTRL_GEN(0x0)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[19] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for SERCOM3_CORE */
    GCLK_REGS->GCLK_PCHCTRL[20] = GCLK_PCHCTRL_GEN(0x0)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[20] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }


}



