/*******************************************************************************
  Non-Volatile Memory Controller(NVMCTRL) PLIB.

  Company:
    Microchip Technology Inc.

  File Name:
    plib_nvmctrl.c

  Summary:
    Interface definition of NVMCTRL Plib.

  Description:
    This file defines the interface for the NVMCTRL Plib.
    It allows user to Program, Erase and lock the on-chip Non Volatile Flash
    Memory.
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

#include <string.h>
#include "plib_nvmctrl.h"
#include "interrupts.h"

static volatile uint16_t nvm_error;

// *****************************************************************************
// *****************************************************************************
// Section: NVMCTRL Implementation
// *****************************************************************************
// *****************************************************************************



void NVMCTRL_Initialize(void)
{
   NVMCTRL_REGS->NVMCTRL_CTRLA = (uint16_t)NVMCTRL_CTRLA_RWS(5U) | NVMCTRL_CTRLA_AUTOWS_Msk;
}

bool NVMCTRL_Read( uint32_t *data, uint32_t length, const uint32_t address )
{
    uint32_t* paddress = (uint32_t*)address;
    (void)memcpy(data, paddress, length);
    return true;
}

void NVMCTRL_SetWriteMode(NVMCTRL_WRITEMODE mode)
{
    NVMCTRL_REGS->NVMCTRL_CTRLA = (uint16_t)((NVMCTRL_REGS->NVMCTRL_CTRLA & (~NVMCTRL_CTRLA_WMODE_Msk)) | (uint16_t)mode);
}

bool NVMCTRL_QuadWordWrite(const uint32_t *data, const uint32_t address)
{
    uint8_t i = 0U;
    bool wr_status = false;
    uint32_t * paddress = (uint32_t *)address;
    uint16_t wr_mode = (NVMCTRL_REGS->NVMCTRL_CTRLA & NVMCTRL_CTRLA_WMODE_Msk);

    /* Clear global error flag */
    nvm_error = 0U;

    /* If the address is not a quad word address, return error */
    if((address & 0x0fU) != 0U)
    {
        wr_status = false;
    }
    else
    {
        /* Configure Quad Word Write */
        NVMCTRL_SetWriteMode(NVMCTRL_WMODE_AQW);

        /* Writing 32-bit data into the given address.  Writes to the page buffer must be 32 bits. */
        for (i = 0U; i <= 3U; i++)
        {
            *paddress = data[i];
             paddress++;
        }
        /* Restore the write mode */
        NVMCTRL_SetWriteMode(wr_mode);
        wr_status = true;
    }
    return wr_status;
}

bool NVMCTRL_DoubleWordWrite(const uint32_t *data, const uint32_t address)
{
    uint8_t i = 0U;
    bool wr_status = false;
    uint32_t * paddress = (uint32_t *)address;
    uint16_t wr_mode = (NVMCTRL_REGS->NVMCTRL_CTRLA & NVMCTRL_CTRLA_WMODE_Msk);

    /* Clear global error flag */
    nvm_error = 0U;

    /* If the address is not a double word address, return error */
    if((address & 0x07U) != 0U)
    {
        wr_status = false;
    }
    else
    {
        /* Configure Double Word Write */
        NVMCTRL_SetWriteMode(NVMCTRL_WMODE_ADW);

        /* Writing 32-bit data into the given address.  Writes to the page buffer must be 32 bits. */
        for (i = 0U; i <= 1U; i++)
        {
            *paddress = data[i];
             paddress++;
        }
        /* Restore the write mode */
        NVMCTRL_SetWriteMode(wr_mode);
        wr_status = true;
    }
    return wr_status;
}

/* This function only loads the internal NVM page buffer. This function must be used when multiple updates
 * to the same page are expected. Once all the updates are done, call the NVMCTRL_PageBufferCommit API
 * to write the contents of the page buffer to the NVM memory. This functionality only works in manual write mode.
 */
bool NVMCTRL_PageBufferWrite( const uint32_t *data, const uint32_t address)
{
    uint32_t i = 0U;
    uint32_t * paddress = (uint32_t *)address;

    /* Clear global error flag */
    nvm_error = 0U;

    /* writing 32-bit data into the given address.  Writes to the page buffer must be 32 bits */
    for (i = 0U; i < (NVMCTRL_FLASH_PAGESIZE/4U); i++)
    {
        *paddress = data[i];
         paddress++;
    }

    return true;
}

/* This API must be used to write the contents of the page buffer to the NVM memory when the manual write mode is enabled */
bool NVMCTRL_PageBufferCommit(  const uint32_t address )
{
    /* Clear global error flag */
    nvm_error = 0U;

    /* Set address and command */
    NVMCTRL_REGS->NVMCTRL_ADDR = address;

    /* If write mode is manual, */
    if ((NVMCTRL_REGS->NVMCTRL_CTRLA & NVMCTRL_CTRLA_WMODE_Msk) == NVMCTRL_CTRLA_WMODE_MAN)
    {
        /* Set address and command */
        NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_WP | NVMCTRL_CTRLB_CMDEX_KEY;
    }

    return true;
}

/* This function assumes that the page written is fresh or it is erased by
 * calling NVMCTRL_BlockErase
 */
bool NVMCTRL_PageWrite( const uint32_t *data, const uint32_t address )
{
    uint32_t i = 0U;
    uint32_t * paddress = (uint32_t *)address;

    /* Clear global error flag */
    nvm_error = 0U;

    /* writing 32-bit data into the given address.  Writes to the page buffer must be 32 bits */
    for (i = 0U; i < (NVMCTRL_FLASH_PAGESIZE/4U); i++)
    {
        *paddress = data[i];
         paddress++;
    }

    /* If write mode is manual, */
    if ((NVMCTRL_REGS->NVMCTRL_CTRLA & NVMCTRL_CTRLA_WMODE_Msk) == NVMCTRL_CTRLA_WMODE_MAN)
    {
        /* Set address and command */
        NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_WP | NVMCTRL_CTRLB_CMDEX_KEY;
    }

    return true;
}

bool NVMCTRL_BlockErase( uint32_t address )
{
    /* Clear global error flag */
    nvm_error = 0U;

    /* Set address and command */
    NVMCTRL_REGS->NVMCTRL_ADDR = address;
    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_EB | NVMCTRL_CTRLB_CMDEX_KEY;

    return true;
}

bool NVMCTRL_USER_ROW_PageWrite( uint32_t *data, const uint32_t address )
{
    uint32_t i = 0U;
    uint32_t wr_count = 0U;
    uint32_t * paddress = (uint32_t *)address;
    uint32_t * pdata = data;
    bool rowwrite = false;

    if ((address >= NVMCTRL_USERROW_START_ADDRESS) && (address <= ((NVMCTRL_USERROW_START_ADDRESS + NVMCTRL_USERROW_SIZE) - NVMCTRL_USERROW_PAGESIZE)))
    {
        /* Clear global error flag */
        nvm_error = 0U;

        for (wr_count = 0U; wr_count < (NVMCTRL_USERROW_PAGESIZE / NVMCTRL_USERROW_WQW_SIZE); wr_count++)
        {
            /* writing 32-bit data into the given address */
            for (i = 0U; i < (NVMCTRL_USERROW_WQW_SIZE / 4U); i++)
            {
                *paddress = *pdata;
                paddress++;
                pdata++;
            }

            /* Set address */
            NVMCTRL_REGS->NVMCTRL_ADDR = (address + (wr_count * NVMCTRL_USERROW_WQW_SIZE));

            /* Set command */
            NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_WQW | NVMCTRL_CTRLB_CMDEX_KEY;

            while (NVMCTRL_IsBusy() == true)
            {
                // Wait for write complete
            }
        }

        rowwrite = true;
    }

    return rowwrite;
}

bool NVMCTRL_USER_ROW_RowErase( uint32_t address )
{
    bool rowerase = false;

    if ((address >= NVMCTRL_USERROW_START_ADDRESS) && (address <= (NVMCTRL_USERROW_START_ADDRESS + NVMCTRL_USERROW_SIZE)))
    {
        /* Clear global error flag */
        nvm_error = 0U;

        /* Set address and command */
        NVMCTRL_REGS->NVMCTRL_ADDR = address;

        NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_EP | NVMCTRL_CTRLB_CMDEX_KEY;

        rowerase = true;
    }

    return rowerase;
}

uint16_t NVMCTRL_ErrorGet( void )
{
    uint16_t temp;
    /* Store previous and current error flags */
    temp = NVMCTRL_REGS->NVMCTRL_INTFLAG;

    nvm_error |= temp;

    /* Clear NVMCTRL INTFLAG register */
    NVMCTRL_REGS->NVMCTRL_INTFLAG = nvm_error;

    return nvm_error;
}

uint16_t NVMCTRL_StatusGet( void )
{
    uint16_t nvm_status;

    nvm_status = NVMCTRL_REGS->NVMCTRL_STATUS;

    return nvm_status;
}

bool NVMCTRL_IsBusy(void)
{
    return ((NVMCTRL_REGS->NVMCTRL_STATUS & NVMCTRL_STATUS_READY_Msk) == 0U);
}

void NVMCTRL_RegionLock(uint32_t address)
{
    /* Set address and command */
    NVMCTRL_REGS->NVMCTRL_ADDR = address;

    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_LR | NVMCTRL_CTRLB_CMDEX_KEY;
}

void NVMCTRL_RegionUnlock(uint32_t address)
{
    /* Set address and command */
    NVMCTRL_REGS->NVMCTRL_ADDR = address;

    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_UR | NVMCTRL_CTRLB_CMDEX_KEY;
}

uint32_t NVMCTRL_RegionLockStatusGet (void)
{
    return (NVMCTRL_REGS->NVMCTRL_RUNLOCK);
}

void NVMCTRL_SecurityBitSet(void)
{
    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_SSB | NVMCTRL_CTRLB_CMDEX_KEY;
}

bool NVMCTRL_SmartEEPROM_IsBusy(void)
{
    return ((NVMCTRL_REGS->NVMCTRL_SEESTAT & NVMCTRL_SEESTAT_BUSY_Msk) != 0U);
}

uint32_t NVMCTRL_SmartEEPROMStatusGet( void )
{
    uint32_t smart_eep_status;

    smart_eep_status = NVMCTRL_REGS->NVMCTRL_SEESTAT;

    return smart_eep_status;
}

bool NVMCTRL_SmartEEPROM_IsActiveSectorFull(void)
{
    return ((NVMCTRL_REGS->NVMCTRL_INTFLAG & NVMCTRL_INTFLAG_SEESFULL_Msk) != 0U);
}

/* Use BankSwap only when there are valid applications in both NVM Banks */
void NVMCTRL_BankSwap(void)
{
    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_BKSWRST | NVMCTRL_CTRLB_CMDEX_KEY;
}

void NVMCTRL_SmartEEPROMSectorReallocate(void)
{
    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_SEERALOC | NVMCTRL_CTRLB_CMDEX_KEY;
}

void NVMCTRL_SmartEEPROMFlushPageBuffer(void)
{
    /* Clear global error flag */
    nvm_error = 0U;

    NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_CMD_SEEFLUSH | NVMCTRL_CTRLB_CMDEX_KEY;
}



