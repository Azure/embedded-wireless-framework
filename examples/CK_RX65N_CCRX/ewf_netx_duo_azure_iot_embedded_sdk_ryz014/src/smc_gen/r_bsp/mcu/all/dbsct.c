/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : dbsct.c
* Description  : Defines the structure of the ROM and RAM areas.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 28.02.2019 3.00     Merged processing of all devices.
*                               Added support for GNUC and ICCRX.
*                               Fixed coding style.
*                               Added definition for section of D_8, B_8, and C_8.
*         : 08.10.2019 3.01     Added section for Renesas RTOS (RI600V4 or RI600PX).
*         : 14.02.2020 3.02     Corrected pragma declaration of unpack.
*         : 25.11.2022 3.03     Added definition for section of DEXRAM, DEXRAM_2, DEXRAM_1, DEXRAM_8, REXRAM, REXRAM_2,
*                               REXRAM_1, REXRAM_8, BEXRAM, BEXRAM_2, BEXRAM_1 and BEXRAM_8.
***********************************************************************************************************************/

#if defined(__CCRX__)
/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "platform.h"

/* When using the user startup program, disable the following code. */
#if BSP_CFG_STARTUP_DISABLE == 0

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/* Preprocessor directive */
#pragma unpack

/* MCU ROM and RAM structure definition */
typedef struct
{
    uint8_t *rom_s;       /* Start address of the initialized data section in ROM */
    uint8_t *rom_e;       /* End address of the initialized data section in ROM */
    uint8_t *ram_s;       /* Start address of the initialized data section in RAM */
} st_dtbl_t;

typedef struct
{
    uint8_t *b_s;         /* Start address of non-initialized data section */
    uint8_t *b_e;         /* End address of non-initialized data section */
} st_btbl_t;

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/

/* Section start */
#pragma section C C$DSEC

extern st_dtbl_t const _DTBL[] = {
#ifdef BSP_MCU_DOUBLE_PRECISION_FLOATING_POINT
    { __sectop("D_8"), __secend("D_8"), __sectop("R_8") },
#endif
    { __sectop("D"), __secend("D"), __sectop("R") },
    { __sectop("D_2"), __secend("D_2"), __sectop("R_2") },
    { __sectop("D_1"), __secend("D_1"), __sectop("R_1") }
#if (defined(BSP_CFG_EXPANSION_RAM_ENABLE) && (BSP_CFG_EXPANSION_RAM_ENABLE == 1))
#ifdef BSP_EXPANSION_RAM
#ifdef BSP_MCU_DOUBLE_PRECISION_FLOATING_POINT
   ,{ __sectop("DEXRAM_8"), __secend("DEXRAM_8"), __sectop("REXRAM_8") }
#endif
   ,{ __sectop("DEXRAM"), __secend("DEXRAM"), __sectop("REXRAM") },
    { __sectop("DEXRAM_2"), __secend("DEXRAM_2"), __sectop("REXRAM_2") },
    { __sectop("DEXRAM_1"), __secend("DEXRAM_1"), __sectop("REXRAM_1") }
#endif
#endif
#if (BSP_CFG_RTOS_USED == 4) && (BSP_CFG_RENESAS_RTOS_USED == RENESAS_RI600PX)
   ,{ __sectop("DRI_ROM"), __secend("DRI_ROM"), __sectop("RRI_RAM") }
#endif /* Renesas RI600PX */
};

/* Section start */
#pragma section C C$BSEC

extern st_btbl_t const _BTBL[] = {
#ifdef BSP_MCU_DOUBLE_PRECISION_FLOATING_POINT
    { __sectop("B_8"), __secend("B_8") },
#endif
    { __sectop("B"), __secend("B") },
    { __sectop("B_2"), __secend("B_2") },
    { __sectop("B_1"), __secend("B_1") }
#if (defined(BSP_CFG_EXPANSION_RAM_ENABLE) && (BSP_CFG_EXPANSION_RAM_ENABLE == 1))
#ifdef BSP_EXPANSION_RAM
#ifdef BSP_MCU_DOUBLE_PRECISION_FLOATING_POINT
   ,{ __sectop("BEXRAM_8"), __secend("BEXRAM_8") }
#endif
   ,{ __sectop("BEXRAM"), __secend("BEXRAM") },
    { __sectop("BEXRAM_2"), __secend("BEXRAM_2") },
    { __sectop("BEXRAM_1"), __secend("BEXRAM_1") }
#endif
#endif
#if (BSP_CFG_RTOS_USED == 4) && (BSP_CFG_RENESAS_RTOS_USED == RENESAS_RI600V4)
   ,{ __sectop("BRI_RAM"), __secend("BRI_RAM") }
#endif /* Renesas RI600V4 */
};

/* Section start */
#pragma section

#if (BSP_CFG_RTOS_USED == 4) && (BSP_CFG_RENESAS_RTOS_USED == RENESAS_RI600PX)
#pragma section C CS
#endif /* Renesas RI600PX */

/* CTBL prevents excessive output of L1100 messages when linking.
   Even if CTBL is deleted, the operation of the program does not change. */
uint8_t * const _CTBL[] = {
    __sectop("C_1"), __sectop("C_2"), __sectop("C"),
#ifdef BSP_MCU_DOUBLE_PRECISION_FLOATING_POINT
    __sectop("C_8"),
#endif
    __sectop("W_1"), __sectop("W_2"), __sectop("W")
};

/* Preprocessor directive */
#pragma packoption

/* This is to ensure compatibility with new L section in version 1.1 and up of the RXC compiler.  Do not remove! */
#pragma section C L
const uint32_t deadSpace = 0xDEADDEAD;
#pragma section

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/

#endif /* BSP_CFG_STARTUP_DISABLE == 0 */

#endif /* defined(__CCRX__) */

