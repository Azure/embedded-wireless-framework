/*******************************************************************************
  Power Manager(PM) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_pm.c

  Summary
    PM PLIB Implementation File.

  Description
    This file defines the interface to the PM peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "device.h"
#include "plib_pm.h"
void PM_Initialize( void )
{
    /* Configure PM */
    PM_REGS->PM_STDBYCFG = (uint16_t)(PM_STDBYCFG_VREGSMOD(0UL));

    /* Clear INTFLAG.PLRDY */
    PM_REGS->PM_INTFLAG |= (uint8_t)PM_INTENCLR_PLRDY_Msk;

    if ((PM_REGS->PM_PLCFG & PM_PLCFG_PLSEL_Msk) != PM_PLCFG_PLSEL_PL2)
    {
        /* Configure performance level */
        PM_REGS->PM_PLCFG = (uint8_t)PM_PLCFG_PLSEL_PL2;

        while((PM_REGS->PM_INTFLAG & PM_INTFLAG_PLRDY_Msk) == 0U)
        {
            /* Wait for performance level transition to complete */
        }
    }
}

void PM_IdleModeEnter( void )
{
    /* Configure Idle Sleep mode */
    PM_REGS->PM_SLEEPCFG = (uint8_t)PM_SLEEPCFG_SLEEPMODE_IDLE_Val;

    while ((PM_REGS->PM_SLEEPCFG & PM_SLEEPCFG_SLEEPMODE_IDLE_Val) == 0U)
    {
        /* Ensure that SLEEPMODE bits are configured with the given value */
    }
    /* Wait for interrupt instruction execution */
    __WFI();
}

void PM_StandbyModeEnter( void )
{
    /* Configure Standby Sleep */
    PM_REGS->PM_SLEEPCFG = (uint8_t)PM_SLEEPCFG_SLEEPMODE_STANDBY_Val;
  
    while ((PM_REGS->PM_SLEEPCFG & PM_SLEEPCFG_SLEEPMODE_STANDBY_Val) == 0U)
    {
        /* Ensure that SLEEPMODE bits are configured with the given value */
    }

    /* Wait for interrupt instruction execution */
    __WFI();
}


void PM_OffModeEnter( void )
{
    /* Configure Off Sleep */
    PM_REGS->PM_SLEEPCFG = (uint8_t)PM_SLEEPCFG_SLEEPMODE_OFF_Val;

    while ((PM_REGS->PM_SLEEPCFG & PM_SLEEPCFG_SLEEPMODE_OFF_Val) == 0U)
    {
        /* Ensure that SLEEPMODE bits are configured with the given value */
    }

    /* Wait for interrupt instruction execution */
    __WFI();
}

bool PM_ConfigurePerformanceLevel(PLCFG_PLSEL plsel)
{
    bool status = false;

    /* Write the value only if Performance Level Disable is not set */
    if ((PM_REGS->PM_PLCFG & PM_PLCFG_PLDIS_Msk) == 0U)
    {
        if((PM_REGS->PM_PLCFG & PM_PLCFG_PLSEL_Msk) != (uint8_t)plsel)
        {
            /* Clear INTFLAG.PLRDY */
            PM_REGS->PM_INTFLAG |= (uint8_t)PM_INTENCLR_PLRDY_Msk;

            /* Write PLSEL bits */
            PM_REGS->PM_PLCFG  = (uint8_t)plsel;

            while((PM_REGS->PM_INTFLAG & PM_INTFLAG_PLRDY_Msk) == 0U)
            {
                /* Wait for performance level transition to complete */
            }

            status = true;
        }
    }

    return status;
}

