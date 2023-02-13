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
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/**********************************************************************************************************************
* File Name    : r_sci_rx65n_data.c
* Description  : Functions for using SCI on the RX65N device.
***********************************************************************************************************************
* History : DD.MM.YYYY Version Description
*           01.10.2016 1.00    Initial Release.
*           07.03.2017 2.00    Fixed a bug that the new FIFO threshold was retained only on first receive.
*           01.02.2019 2.20    Fixed GSCE Code Checker errors.
*           20.05.2019 3.00    Added support for GNUC and ICCRX.
*           25.08.2020 3.60    Added feature using DTC/DMAC in SCI transfer.
*           31.03.2021 3.80    Updated macro definition enable and disable TXI, RXI, ERI, TEI.
*           31.03.2022 4.40    Added receive flag when using DTC/DMAC.
*                              Updated channel variables in struct st_sci_ch_rom.
***********************************************************************************************************************/

/*****************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "platform.h"

#include "r_sci_rx65n_private.h"

/*****************************************************************************
Typedef definitions
******************************************************************************/

/*****************************************************************************
Macro definitions
******************************************************************************/

/*****************************************************************************
Private global variables and functions
******************************************************************************/

/* BAUD DIVISOR INFO */

/* Asynchronous */
/* BRR = (PCLK/(divisor * baud)) - 1 */
/* when abcs=0 & bgdm=0, divisor = 64*pow(2,2n-1) */
/* when abcs=1 & bgdm=0 OR abcs=0 & bgdm=1, divisor = 32*pow(2,2n-1) */
/* when abcs=1 & bgdm=1, divisor = 16*pow(2,2n-1) */

#if (SCI_CFG_ASYNC_INCLUDED)
/* NOTE: diff than SCI async baud table, but should provide same results */
const baud_divisor_t async_baud[NUM_DIVISORS_ASYNC]=
{
    /* divisor result, abcs, bgdm, n */
    {8,    1, 1, 0},
    {16,   0, 1, 0},
    {32,   0, 0, 0},
    {64,   0, 1, 1},
    {128,  0, 0, 1},
    {256,  0, 1, 2},
    {512,  0, 0, 2},
    {1024, 0, 1, 3},
    {2048, 0, 0, 3}
};
#endif

/* Synchronous and Simple SPI */
/* BRR = (PCLK/(divisor * baud)) - 1 */
/* abcs=0, bdgm=0, divisor = 8*pow(2,2n-1) */

#if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
/* NOTE: Identical to SCI sync baud table */
const baud_divisor_t sync_baud[NUM_DIVISORS_SYNC]=
{
    /* divisor result, abcs, bgdm, n */
    {4,   0, 0, 0},
    {16,  0, 0, 1},
    {64,  0, 0, 2},
    {256, 0, 0, 3}
};
#endif


/* CHANNEL MEMORY ALLOCATIONS */

#if SCI_CFG_CH0_INCLUDED

/* rom info */
const sci_ch_rom_t  ch0_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI0,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRB.LONG, BIT31_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL0_SCI0_TEI0, sci0_tei0_isr,
                                #endif
                                BSP_INT_SRC_BL0_SCI0_ERI0, sci0_eri0_isr,
                                SCI_BIT0, SCI_BIT1,
                                &ICU.IPR[IPR_SCI0_RXI0].BYTE,
                                &ICU.IPR[IPR_SCI0_TXI0].BYTE,
                                &ICU.IR[IR_SCI0_RXI0].BYTE,
                                &ICU.IR[IR_SCI0_TXI0].BYTE,
                                &ICU.IER[IER_SCI0_RXI0].BYTE,
                                &ICU.IER[IER_SCI0_TXI0].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL0.LONG,
                                SCI_BIT2, SCI_BIT3,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH0_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH0_RX_DTC_DMACA_ENABLE,
                                0,
                                0,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI0_TXI0,
                                DTCE_SCI0_RXI0,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI0_TXI0,
                                IR_SCI0_RXI0,
                                (uint8_t)SCI_CFG_CH0_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH0_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH0
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch0_ctrl = {&ch0_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif /* End of SCI_CFG_CH0_INCLUDED */


#if SCI_CFG_CH1_INCLUDED

/* rom info */
const sci_ch_rom_t  ch1_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI1,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRB.LONG, BIT30_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL0_SCI1_TEI1, sci1_tei1_isr,
                                #endif
                                BSP_INT_SRC_BL0_SCI1_ERI1, sci1_eri1_isr,
                                SCI_BIT2, SCI_BIT3,
                                &ICU.IPR[IPR_SCI1_RXI1].BYTE,
                                &ICU.IPR[IPR_SCI1_TXI1].BYTE,
                                &ICU.IR[IR_SCI1_RXI1].BYTE,
                                &ICU.IR[IR_SCI1_TXI1].BYTE,
                                &ICU.IER[IER_SCI1_RXI1].BYTE,
                                &ICU.IER[IER_SCI1_TXI1].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL0.LONG,
                                SCI_BIT4, SCI_BIT5,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH1_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH1_RX_DTC_DMACA_ENABLE,
                                0,
                                0,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI1_TXI1,
                                DTCE_SCI1_RXI1,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI1_TXI1,
                                IR_SCI1_RXI1,
                                (uint8_t)SCI_CFG_CH1_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH1_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH1
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch1_ctrl = {&ch1_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif /* End of SCI_CFG_CH1_INCLUDED */


#if SCI_CFG_CH2_INCLUDED

/* rom info */
const sci_ch_rom_t  ch2_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI2,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRB.LONG, BIT29_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL0_SCI2_TEI2, sci2_tei2_isr,
                                #endif
                                BSP_INT_SRC_BL0_SCI2_ERI2, sci2_eri2_isr,
                                SCI_BIT4, SCI_BIT5,
                                &ICU.IPR[IPR_SCI2_RXI2].BYTE,
                                &ICU.IPR[IPR_SCI2_TXI2].BYTE,
                                &ICU.IR[IR_SCI2_RXI2].BYTE,
                                &ICU.IR[IR_SCI2_TXI2].BYTE,
                                &ICU.IER[IER_SCI2_RXI2].BYTE,
                                &ICU.IER[IER_SCI2_TXI2].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL0.LONG,
                                SCI_BIT6, SCI_BIT7,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH2_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH2_RX_DTC_DMACA_ENABLE,
                                0,
                                0,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI2_TXI2,
                                DTCE_SCI2_RXI2,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI2_TXI2,
                                IR_SCI2_RXI2,
                                (uint8_t)SCI_CFG_CH2_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH2_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH2
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch2_ctrl = {&ch2_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif /* End of SCI_CFG_CH2_INCLUDED */


#if SCI_CFG_CH3_INCLUDED

/* rom info */
const sci_ch_rom_t  ch3_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI3,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRB.LONG, BIT28_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL0_SCI3_TEI3, sci3_tei3_isr,
                                #endif
                                BSP_INT_SRC_BL0_SCI3_ERI3, sci3_eri3_isr,
                                SCI_BIT6, SCI_BIT7,
                                &ICU.IPR[IPR_SCI3_RXI3].BYTE,
                                &ICU.IPR[IPR_SCI3_TXI3].BYTE,
                                &ICU.IR[IR_SCI3_RXI3].BYTE,
                                &ICU.IR[IR_SCI3_TXI3].BYTE,
                                &ICU.IER[IER_SCI3_RXI3].BYTE,
                                &ICU.IER[IER_SCI3_TXI3].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL0.LONG,
                                SCI_BIT0, SCI_BIT1,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH3_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH3_RX_DTC_DMACA_ENABLE,
                                0,
                                0,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI3_TXI3,
                                DTCE_SCI3_RXI3,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI3_TXI3,
                                IR_SCI3_RXI3,
                                (uint8_t)SCI_CFG_CH3_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH3_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH3
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch3_ctrl = {&ch3_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif  /* End of SCI_CFG_CH3_INCLUDED */


#if SCI_CFG_CH4_INCLUDED

/* rom info */
const sci_ch_rom_t  ch4_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI4,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRB.LONG, BIT27_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL0_SCI4_TEI4, sci4_tei4_isr,
                                #endif
                                BSP_INT_SRC_BL0_SCI4_ERI4, sci4_eri4_isr,
                                SCI_BIT8, SCI_BIT9,
                                &ICU.IPR[IPR_SCI4_RXI4].BYTE,
                                &ICU.IPR[IPR_SCI4_TXI4].BYTE,
                                &ICU.IR[IR_SCI4_RXI4].BYTE,
                                &ICU.IR[IR_SCI4_TXI4].BYTE,
                                &ICU.IER[IER_SCI4_RXI4].BYTE,
                                &ICU.IER[IER_SCI4_TXI4].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL0.LONG,
                                SCI_BIT2, SCI_BIT3,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH4_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH4_RX_DTC_DMACA_ENABLE,
                                0,
                                0,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI4_TXI4,
                                DTCE_SCI4_RXI4,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI4_TXI4,
                                IR_SCI4_RXI4,
                                (uint8_t)SCI_CFG_CH4_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH4_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH4
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch4_ctrl = {&ch4_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif  /* End of SCI_CFG_CH4_INCLUDED */


#if SCI_CFG_CH5_INCLUDED

/* rom info */
const sci_ch_rom_t  ch5_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI5,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRB.LONG, BIT26_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL0_SCI5_TEI5, sci5_tei5_isr,
                                #endif
                                BSP_INT_SRC_BL0_SCI5_ERI5, sci5_eri5_isr,
                                SCI_BIT10, SCI_BIT11,
                                &ICU.IPR[IPR_SCI5_RXI5].BYTE,
                                &ICU.IPR[IPR_SCI5_TXI5].BYTE,
                                &ICU.IR[IR_SCI5_RXI5].BYTE,
                                &ICU.IR[IR_SCI5_TXI5].BYTE,
                                &ICU.IER[IER_SCI5_RXI5].BYTE,
                                &ICU.IER[IER_SCI5_TXI5].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL0.LONG,
                                SCI_BIT4, SCI_BIT5,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH5_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH5_RX_DTC_DMACA_ENABLE,
                                0,
                                0,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI5_TXI5,
                                DTCE_SCI5_RXI5,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI5_TXI5,
                                IR_SCI5_RXI5,
                                (uint8_t)SCI_CFG_CH5_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH5_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH5
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch5_ctrl = {&ch5_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif /* End of SCI_CFG_CH5_INCLUDED */


#if SCI_CFG_CH6_INCLUDED

/* rom info */
const sci_ch_rom_t  ch6_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI6,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRB.LONG, BIT25_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL0_SCI6_TEI6, sci6_tei6_isr,
                                #endif
                                BSP_INT_SRC_BL0_SCI6_ERI6, sci6_eri6_isr,
                                SCI_BIT12, SCI_BIT13,
                                &ICU.IPR[IPR_SCI6_RXI6].BYTE,
                                &ICU.IPR[IPR_SCI6_TXI6].BYTE,
                                &ICU.IR[IR_SCI6_RXI6].BYTE,
                                &ICU.IR[IR_SCI6_TXI6].BYTE,
                                &ICU.IER[IER_SCI6_RXI6].BYTE,
                                &ICU.IER[IER_SCI6_TXI6].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL0.LONG,
                                SCI_BIT6, SCI_BIT7,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH6_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH6_RX_DTC_DMACA_ENABLE,
                                0,
                                0,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI6_TXI6,
                                DTCE_SCI6_RXI6,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI6_TXI6,
                                IR_SCI6_RXI6,
                                (uint8_t)SCI_CFG_CH6_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH6_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH6
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch6_ctrl = {&ch6_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif /* End of SCI_CFG_CH6_INCLUDED */


#if SCI_CFG_CH7_INCLUDED

/* rom info */
const sci_ch_rom_t  ch7_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI7,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRB.LONG, BIT24_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL0_SCI7_TEI7, sci7_tei7_isr,
                                #endif
                                BSP_INT_SRC_BL0_SCI7_ERI7, sci7_eri7_isr,
                                SCI_BIT14, SCI_BIT15,
                                &ICU.IPR[IPR_SCI7_RXI7].BYTE,
                                &ICU.IPR[IPR_SCI7_TXI7].BYTE,
                                &ICU.IR[IR_SCI7_RXI7].BYTE,
                                &ICU.IR[IR_SCI7_TXI7].BYTE,
                                &ICU.IER[IER_SCI7_RXI7].BYTE,
                                &ICU.IER[IER_SCI7_TXI7].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL0.LONG,
                                SCI_BIT2, SCI_BIT3,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH7_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH7_RX_DTC_DMACA_ENABLE,
                                (16 - SCI_CFG_CH7_TX_FIFO_THRESH),
                                SCI_CFG_CH7_RX_FIFO_THRESH,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI7_TXI7,
                                DTCE_SCI7_RXI7,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI7_TXI7,
                                IR_SCI7_RXI7,
                                (uint8_t)SCI_CFG_CH7_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH7_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH7
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch7_ctrl = {&ch7_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif /* End of SCI_CFG_CH7_INCLUDED */


#if SCI_CFG_CH8_INCLUDED

/* rom info */
const sci_ch_rom_t  ch8_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI8,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRC.LONG, BIT27_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL1_SCI8_TEI8, sci8_tei8_isr,
                                #endif
                                BSP_INT_SRC_BL1_SCI8_ERI8, sci8_eri8_isr,
                                SCI_BIT24, SCI_BIT25,
                                &ICU.IPR[IPR_SCI8_RXI8].BYTE,
                                &ICU.IPR[IPR_SCI8_TXI8].BYTE,
                                &ICU.IR[IR_SCI8_RXI8].BYTE,
                                &ICU.IR[IR_SCI8_TXI8].BYTE,
                                &ICU.IER[IER_SCI8_RXI8].BYTE,
                                &ICU.IER[IER_SCI8_TXI8].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL1.LONG,
                                SCI_BIT4, SCI_BIT5,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH8_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH8_RX_DTC_DMACA_ENABLE,
                                (16 - SCI_CFG_CH8_TX_FIFO_THRESH),
                                SCI_CFG_CH8_RX_FIFO_THRESH,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI8_TXI8,
                                DTCE_SCI8_RXI8,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI8_TXI8,
                                IR_SCI8_RXI8,
                                (uint8_t)SCI_CFG_CH8_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH8_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH8
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch8_ctrl = {&ch8_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif /* End of SCI_CFG_CH8_INCLUDED */


#if SCI_CFG_CH9_INCLUDED

/* rom info */
const sci_ch_rom_t  ch9_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI9,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRC.LONG, BIT26_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL1_SCI9_TEI9, sci9_tei9_isr,
                                #endif
                                BSP_INT_SRC_BL1_SCI9_ERI9, sci9_eri9_isr,
                                SCI_BIT26, SCI_BIT27,
                                &ICU.IPR[IPR_SCI9_RXI9].BYTE,
                                &ICU.IPR[IPR_SCI9_TXI9].BYTE,
                                &ICU.IR[IR_SCI9_RXI9].BYTE,
                                &ICU.IR[IR_SCI9_TXI9].BYTE,
                                &ICU.IER[IER_SCI9_RXI9].BYTE,
                                &ICU.IER[IER_SCI9_TXI9].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL1.LONG,
                                SCI_BIT6, SCI_BIT7,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH9_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH9_RX_DTC_DMACA_ENABLE,
                                (16 - SCI_CFG_CH9_TX_FIFO_THRESH),
                                SCI_CFG_CH9_RX_FIFO_THRESH,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI9_TXI9,
                                DTCE_SCI9_RXI9,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI9_TXI9,
                                IR_SCI9_RXI9,
                                (uint8_t)SCI_CFG_CH9_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH9_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH9
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch9_ctrl = {&ch9_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                            #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                            , true, 0, 0, false
                            #endif
                            , BSP_PCLKB_HZ
                            #if SCI_CFG_FIFO_INCLUDED
                            , false
                            , 0
                            , 0
                            , 0
                            , 0
                            #endif
                            #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                            , true, 0, 0, 0, 0, 0
                            #endif
                           };
#endif /* End of SCI_CFG_CH9_INCLUDED */


#if SCI_CFG_CH10_INCLUDED

/* rom info */
const sci_ch_rom_t  ch10_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI10,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRC.LONG, BIT25_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_AL0_SCI10_TEI10, sci10_tei10_isr,
                                #endif
                                BSP_INT_SRC_AL0_SCI10_ERI10, sci10_eri10_isr,
                                SCI_BIT8, SCI_BIT9,
                                &ICU.IPR[IPR_SCI10_RXI10].BYTE,
                                &ICU.IPR[IPR_SCI10_TXI10].BYTE,
                                &ICU.IR[IR_SCI10_RXI10].BYTE,
                                &ICU.IR[IR_SCI10_TXI10].BYTE,
                                &ICU.IER[IER_SCI10_RXI10].BYTE,
                                &ICU.IER[IER_SCI10_TXI10].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENAL0.LONG,
                                SCI_BIT0, SCI_BIT1,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH10_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH10_RX_DTC_DMACA_ENABLE,
                                (16 - SCI_CFG_CH10_TX_FIFO_THRESH),
                                SCI_CFG_CH10_RX_FIFO_THRESH,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI10_TXI10,
                                DTCE_SCI10_RXI10,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI10_TXI10,
                                IR_SCI10_RXI10,
                                (uint8_t)SCI_CFG_CH10_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH10_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH10
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch10_ctrl = {&ch10_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                             #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                             , true, 0, 0, false
                             #endif
                             , BSP_PCLKA_HZ
                             #if SCI_CFG_FIFO_INCLUDED
                             , SCI_CFG_CH10_FIFO_INCLUDED
                             , SCI_CFG_CH10_RX_FIFO_THRESH
                             , SCI_CFG_CH10_RX_FIFO_THRESH
                             , SCI_CFG_CH10_TX_FIFO_THRESH
                             , SCI_CFG_CH10_TX_FIFO_THRESH
                             #endif
                             #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                             , true, 0, 0, 0, 0, 0
                             #endif
                            };
#endif /* End of SCI_CFG_CH10_INCLUDED */


#if SCI_CFG_CH11_INCLUDED

/* rom info */
const sci_ch_rom_t  ch11_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI11,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRC.LONG, BIT24_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_AL0_SCI11_TEI11, sci11_tei11_isr,
                                #endif
                                BSP_INT_SRC_AL0_SCI11_ERI11, sci11_eri11_isr,
                                SCI_BIT12, SCI_BIT13,
                                &ICU.IPR[IPR_SCI11_RXI11].BYTE,
                                &ICU.IPR[IPR_SCI11_TXI11].BYTE,
                                &ICU.IR[IR_SCI11_RXI11].BYTE,
                                &ICU.IR[IR_SCI11_TXI11].BYTE,
                                &ICU.IER[IER_SCI11_RXI11].BYTE,
                                &ICU.IER[IER_SCI11_TXI11].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENAL0.LONG,
                                SCI_BIT2, SCI_BIT3,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH11_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH11_RX_DTC_DMACA_ENABLE,
                                (16 - SCI_CFG_CH11_TX_FIFO_THRESH),
                                SCI_CFG_CH11_RX_FIFO_THRESH,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI11_TXI11,
                                DTCE_SCI11_RXI11,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI11_TXI11,
                                IR_SCI11_RXI11,
                                (uint8_t)SCI_CFG_CH11_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH11_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH11
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch11_ctrl = {&ch11_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                             #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                             , true, 0, 0, false
                             #endif
                             , BSP_PCLKA_HZ
                             #if SCI_CFG_FIFO_INCLUDED
                             , SCI_CFG_CH11_FIFO_INCLUDED
                             , SCI_CFG_CH11_RX_FIFO_THRESH
                             , SCI_CFG_CH11_RX_FIFO_THRESH
                             , SCI_CFG_CH11_TX_FIFO_THRESH
                             , SCI_CFG_CH11_TX_FIFO_THRESH
                             #endif
                             #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                             , true, 0, 0, 0, 0, 0
                             #endif
                            };
#endif /* End of SCI_CFG_CH11_INCLUDED */


#if SCI_CFG_CH12_INCLUDED

/* rom info */
const sci_ch_rom_t  ch12_rom = {(volatile struct st_sci10 R_BSP_EVENACCESS_SFR *)&SCI12,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&SYSTEM.MSTPCRB.LONG, BIT4_MASK,
                                #if SCI_CFG_TEI_INCLUDED
                                    BSP_INT_SRC_BL0_SCI12_TEI12, sci12_tei12_isr,
                                #endif
                                BSP_INT_SRC_BL0_SCI12_ERI12, sci12_eri12_isr,
                                SCI_BIT16, SCI_BIT17,
                                &ICU.IPR[IPR_SCI12_RXI12].BYTE,
                                &ICU.IPR[IPR_SCI12_TXI12].BYTE,
                                &ICU.IR[IR_SCI12_RXI12].BYTE,
                                &ICU.IR[IR_SCI12_TXI12].BYTE,
                                &ICU.IER[IER_SCI12_RXI12].BYTE,
                                &ICU.IER[IER_SCI12_TXI12].BYTE,
                                (volatile uint32_t R_BSP_EVENACCESS_SFR*)&ICU.GENBL0.LONG,
                                SCI_BIT4, SCI_BIT5,
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                SCI_CFG_CH12_TX_DTC_DMACA_ENABLE,
                                SCI_CFG_CH12_RX_DTC_DMACA_ENABLE,
                                0,
                                0,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
                                DTCE_SCI12_TXI12,
                                DTCE_SCI12_RXI12,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE & 0x02) || (RX_DTC_DMACA_ENABLE & 0x02))
                                IR_SCI12_TXI12,
                                IR_SCI12_RXI12,
                                (uint8_t)SCI_CFG_CH12_TX_DMACA_CH_NUM,
                                (uint8_t)SCI_CFG_CH12_RX_DMACA_CH_NUM,
                                #endif
                                #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                                (uint8_t)SCI_CH12
                                #endif
                                };

/* channel control block */
sci_ch_ctrl_t   ch12_ctrl = {&ch12_rom, SCI_MODE_OFF, 0, NULL, NULL, NULL, true
                             #if (SCI_CFG_SSPI_INCLUDED || SCI_CFG_SYNC_INCLUDED)
                             , true, 0, 0, false
                             #endif
                             , BSP_PCLKB_HZ
                             #if SCI_CFG_FIFO_INCLUDED
                             , false
                             , 0
                             , 0
                             , 0
                             , 0
                             #endif
                             #if ((TX_DTC_DMACA_ENABLE || RX_DTC_DMACA_ENABLE))
                             , true, 0, 0, 0, 0, 0
                             #endif
                            };
#endif /* End of SCI_CFG_CH12_INCLUDED */


/* SCI HANDLE-ARRAY DECLARATION */

const sci_hdl_t g_handles[SCI_NUM_CH] =
{
#if SCI_CFG_CH0_INCLUDED
            &ch0_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH1_INCLUDED
            &ch1_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH2_INCLUDED
            &ch2_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH3_INCLUDED
            &ch3_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH4_INCLUDED
            &ch4_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH5_INCLUDED
            &ch5_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH6_INCLUDED
            &ch6_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH7_INCLUDED
            &ch7_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH8_INCLUDED
            &ch8_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH9_INCLUDED
            &ch9_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH10_INCLUDED
            &ch10_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH11_INCLUDED
            &ch11_ctrl,
#else
            NULL,
#endif
#if SCI_CFG_CH12_INCLUDED
            &ch12_ctrl
#else
            NULL
#endif
};

