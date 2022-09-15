/*
 * Component description for DMAC
 *
 * Copyright (c) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2022-05-25T15:38:03Z */
#ifndef _PIC32CMLS60_DMAC_COMPONENT_H_
#define _PIC32CMLS60_DMAC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR DMAC                                         */
/* ************************************************************************** */

/* -------- DMAC_BTCTRL : (DMAC Offset: 0x00) (R/W 16) Block Transfer Control -------- */
#define DMAC_BTCTRL_RESETVALUE                _UINT16_(0x00)                                       /*  (DMAC_BTCTRL) Block Transfer Control  Reset Value */

#define DMAC_BTCTRL_VALID_Pos                 _UINT16_(0)                                          /* (DMAC_BTCTRL) Descriptor Valid Position */
#define DMAC_BTCTRL_VALID_Msk                 (_UINT16_(0x1) << DMAC_BTCTRL_VALID_Pos)             /* (DMAC_BTCTRL) Descriptor Valid Mask */
#define DMAC_BTCTRL_VALID(value)              (DMAC_BTCTRL_VALID_Msk & (_UINT16_(value) << DMAC_BTCTRL_VALID_Pos)) /* Assigment of value for VALID in the DMAC_BTCTRL register */
#define DMAC_BTCTRL_EVOSEL_Pos                _UINT16_(1)                                          /* (DMAC_BTCTRL) Event Output Selection Position */
#define DMAC_BTCTRL_EVOSEL_Msk                (_UINT16_(0x3) << DMAC_BTCTRL_EVOSEL_Pos)            /* (DMAC_BTCTRL) Event Output Selection Mask */
#define DMAC_BTCTRL_EVOSEL(value)             (DMAC_BTCTRL_EVOSEL_Msk & (_UINT16_(value) << DMAC_BTCTRL_EVOSEL_Pos)) /* Assigment of value for EVOSEL in the DMAC_BTCTRL register */
#define   DMAC_BTCTRL_EVOSEL_DISABLE_Val      _UINT16_(0x0)                                        /* (DMAC_BTCTRL) Event generation disabled  */
#define   DMAC_BTCTRL_EVOSEL_BLOCK_Val        _UINT16_(0x1)                                        /* (DMAC_BTCTRL) Event strobe when block transfer complete  */
#define   DMAC_BTCTRL_EVOSEL_BEAT_Val         _UINT16_(0x3)                                        /* (DMAC_BTCTRL) Event strobe when beat transfer complete  */
#define DMAC_BTCTRL_EVOSEL_DISABLE            (DMAC_BTCTRL_EVOSEL_DISABLE_Val << DMAC_BTCTRL_EVOSEL_Pos) /* (DMAC_BTCTRL) Event generation disabled Position  */
#define DMAC_BTCTRL_EVOSEL_BLOCK              (DMAC_BTCTRL_EVOSEL_BLOCK_Val << DMAC_BTCTRL_EVOSEL_Pos) /* (DMAC_BTCTRL) Event strobe when block transfer complete Position  */
#define DMAC_BTCTRL_EVOSEL_BEAT               (DMAC_BTCTRL_EVOSEL_BEAT_Val << DMAC_BTCTRL_EVOSEL_Pos) /* (DMAC_BTCTRL) Event strobe when beat transfer complete Position  */
#define DMAC_BTCTRL_BLOCKACT_Pos              _UINT16_(3)                                          /* (DMAC_BTCTRL) Block Action Position */
#define DMAC_BTCTRL_BLOCKACT_Msk              (_UINT16_(0x3) << DMAC_BTCTRL_BLOCKACT_Pos)          /* (DMAC_BTCTRL) Block Action Mask */
#define DMAC_BTCTRL_BLOCKACT(value)           (DMAC_BTCTRL_BLOCKACT_Msk & (_UINT16_(value) << DMAC_BTCTRL_BLOCKACT_Pos)) /* Assigment of value for BLOCKACT in the DMAC_BTCTRL register */
#define   DMAC_BTCTRL_BLOCKACT_NOACT_Val      _UINT16_(0x0)                                        /* (DMAC_BTCTRL) Channel will be disabled if it is the last block transfer in the transaction  */
#define   DMAC_BTCTRL_BLOCKACT_INT_Val        _UINT16_(0x1)                                        /* (DMAC_BTCTRL) Channel will be disabled if it is the last block transfer in the transaction and block interrupt  */
#define   DMAC_BTCTRL_BLOCKACT_SUSPEND_Val    _UINT16_(0x2)                                        /* (DMAC_BTCTRL) Channel suspend operation is completed  */
#define   DMAC_BTCTRL_BLOCKACT_BOTH_Val       _UINT16_(0x3)                                        /* (DMAC_BTCTRL) Both channel suspend operation and block interrupt  */
#define DMAC_BTCTRL_BLOCKACT_NOACT            (DMAC_BTCTRL_BLOCKACT_NOACT_Val << DMAC_BTCTRL_BLOCKACT_Pos) /* (DMAC_BTCTRL) Channel will be disabled if it is the last block transfer in the transaction Position  */
#define DMAC_BTCTRL_BLOCKACT_INT              (DMAC_BTCTRL_BLOCKACT_INT_Val << DMAC_BTCTRL_BLOCKACT_Pos) /* (DMAC_BTCTRL) Channel will be disabled if it is the last block transfer in the transaction and block interrupt Position  */
#define DMAC_BTCTRL_BLOCKACT_SUSPEND          (DMAC_BTCTRL_BLOCKACT_SUSPEND_Val << DMAC_BTCTRL_BLOCKACT_Pos) /* (DMAC_BTCTRL) Channel suspend operation is completed Position  */
#define DMAC_BTCTRL_BLOCKACT_BOTH             (DMAC_BTCTRL_BLOCKACT_BOTH_Val << DMAC_BTCTRL_BLOCKACT_Pos) /* (DMAC_BTCTRL) Both channel suspend operation and block interrupt Position  */
#define DMAC_BTCTRL_BEATSIZE_Pos              _UINT16_(8)                                          /* (DMAC_BTCTRL) Beat Size Position */
#define DMAC_BTCTRL_BEATSIZE_Msk              (_UINT16_(0x3) << DMAC_BTCTRL_BEATSIZE_Pos)          /* (DMAC_BTCTRL) Beat Size Mask */
#define DMAC_BTCTRL_BEATSIZE(value)           (DMAC_BTCTRL_BEATSIZE_Msk & (_UINT16_(value) << DMAC_BTCTRL_BEATSIZE_Pos)) /* Assigment of value for BEATSIZE in the DMAC_BTCTRL register */
#define   DMAC_BTCTRL_BEATSIZE_BYTE_Val       _UINT16_(0x0)                                        /* (DMAC_BTCTRL) 8-bit bus transfer  */
#define   DMAC_BTCTRL_BEATSIZE_HWORD_Val      _UINT16_(0x1)                                        /* (DMAC_BTCTRL) 16-bit bus transfer  */
#define   DMAC_BTCTRL_BEATSIZE_WORD_Val       _UINT16_(0x2)                                        /* (DMAC_BTCTRL) 32-bit bus transfer  */
#define DMAC_BTCTRL_BEATSIZE_BYTE             (DMAC_BTCTRL_BEATSIZE_BYTE_Val << DMAC_BTCTRL_BEATSIZE_Pos) /* (DMAC_BTCTRL) 8-bit bus transfer Position  */
#define DMAC_BTCTRL_BEATSIZE_HWORD            (DMAC_BTCTRL_BEATSIZE_HWORD_Val << DMAC_BTCTRL_BEATSIZE_Pos) /* (DMAC_BTCTRL) 16-bit bus transfer Position  */
#define DMAC_BTCTRL_BEATSIZE_WORD             (DMAC_BTCTRL_BEATSIZE_WORD_Val << DMAC_BTCTRL_BEATSIZE_Pos) /* (DMAC_BTCTRL) 32-bit bus transfer Position  */
#define DMAC_BTCTRL_SRCINC_Pos                _UINT16_(10)                                         /* (DMAC_BTCTRL) Source Address Increment Enable Position */
#define DMAC_BTCTRL_SRCINC_Msk                (_UINT16_(0x1) << DMAC_BTCTRL_SRCINC_Pos)            /* (DMAC_BTCTRL) Source Address Increment Enable Mask */
#define DMAC_BTCTRL_SRCINC(value)             (DMAC_BTCTRL_SRCINC_Msk & (_UINT16_(value) << DMAC_BTCTRL_SRCINC_Pos)) /* Assigment of value for SRCINC in the DMAC_BTCTRL register */
#define DMAC_BTCTRL_DSTINC_Pos                _UINT16_(11)                                         /* (DMAC_BTCTRL) Destination Address Increment Enable Position */
#define DMAC_BTCTRL_DSTINC_Msk                (_UINT16_(0x1) << DMAC_BTCTRL_DSTINC_Pos)            /* (DMAC_BTCTRL) Destination Address Increment Enable Mask */
#define DMAC_BTCTRL_DSTINC(value)             (DMAC_BTCTRL_DSTINC_Msk & (_UINT16_(value) << DMAC_BTCTRL_DSTINC_Pos)) /* Assigment of value for DSTINC in the DMAC_BTCTRL register */
#define DMAC_BTCTRL_STEPSEL_Pos               _UINT16_(12)                                         /* (DMAC_BTCTRL) Step Selection Position */
#define DMAC_BTCTRL_STEPSEL_Msk               (_UINT16_(0x1) << DMAC_BTCTRL_STEPSEL_Pos)           /* (DMAC_BTCTRL) Step Selection Mask */
#define DMAC_BTCTRL_STEPSEL(value)            (DMAC_BTCTRL_STEPSEL_Msk & (_UINT16_(value) << DMAC_BTCTRL_STEPSEL_Pos)) /* Assigment of value for STEPSEL in the DMAC_BTCTRL register */
#define   DMAC_BTCTRL_STEPSEL_DST_Val         _UINT16_(0x0)                                        /* (DMAC_BTCTRL) Step size settings apply to the destination address  */
#define   DMAC_BTCTRL_STEPSEL_SRC_Val         _UINT16_(0x1)                                        /* (DMAC_BTCTRL) Step size settings apply to the source address  */
#define DMAC_BTCTRL_STEPSEL_DST               (DMAC_BTCTRL_STEPSEL_DST_Val << DMAC_BTCTRL_STEPSEL_Pos) /* (DMAC_BTCTRL) Step size settings apply to the destination address Position  */
#define DMAC_BTCTRL_STEPSEL_SRC               (DMAC_BTCTRL_STEPSEL_SRC_Val << DMAC_BTCTRL_STEPSEL_Pos) /* (DMAC_BTCTRL) Step size settings apply to the source address Position  */
#define DMAC_BTCTRL_STEPSIZE_Pos              _UINT16_(13)                                         /* (DMAC_BTCTRL) Address Increment Step Size Position */
#define DMAC_BTCTRL_STEPSIZE_Msk              (_UINT16_(0x7) << DMAC_BTCTRL_STEPSIZE_Pos)          /* (DMAC_BTCTRL) Address Increment Step Size Mask */
#define DMAC_BTCTRL_STEPSIZE(value)           (DMAC_BTCTRL_STEPSIZE_Msk & (_UINT16_(value) << DMAC_BTCTRL_STEPSIZE_Pos)) /* Assigment of value for STEPSIZE in the DMAC_BTCTRL register */
#define   DMAC_BTCTRL_STEPSIZE_X1_Val         _UINT16_(0x0)                                        /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 1  */
#define   DMAC_BTCTRL_STEPSIZE_X2_Val         _UINT16_(0x1)                                        /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 2  */
#define   DMAC_BTCTRL_STEPSIZE_X4_Val         _UINT16_(0x2)                                        /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 4  */
#define   DMAC_BTCTRL_STEPSIZE_X8_Val         _UINT16_(0x3)                                        /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 8  */
#define   DMAC_BTCTRL_STEPSIZE_X16_Val        _UINT16_(0x4)                                        /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 16  */
#define   DMAC_BTCTRL_STEPSIZE_X32_Val        _UINT16_(0x5)                                        /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 32  */
#define   DMAC_BTCTRL_STEPSIZE_X64_Val        _UINT16_(0x6)                                        /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 64  */
#define   DMAC_BTCTRL_STEPSIZE_X128_Val       _UINT16_(0x7)                                        /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 128  */
#define DMAC_BTCTRL_STEPSIZE_X1               (DMAC_BTCTRL_STEPSIZE_X1_Val << DMAC_BTCTRL_STEPSIZE_Pos) /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 1 Position  */
#define DMAC_BTCTRL_STEPSIZE_X2               (DMAC_BTCTRL_STEPSIZE_X2_Val << DMAC_BTCTRL_STEPSIZE_Pos) /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 2 Position  */
#define DMAC_BTCTRL_STEPSIZE_X4               (DMAC_BTCTRL_STEPSIZE_X4_Val << DMAC_BTCTRL_STEPSIZE_Pos) /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 4 Position  */
#define DMAC_BTCTRL_STEPSIZE_X8               (DMAC_BTCTRL_STEPSIZE_X8_Val << DMAC_BTCTRL_STEPSIZE_Pos) /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 8 Position  */
#define DMAC_BTCTRL_STEPSIZE_X16              (DMAC_BTCTRL_STEPSIZE_X16_Val << DMAC_BTCTRL_STEPSIZE_Pos) /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 16 Position  */
#define DMAC_BTCTRL_STEPSIZE_X32              (DMAC_BTCTRL_STEPSIZE_X32_Val << DMAC_BTCTRL_STEPSIZE_Pos) /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 32 Position  */
#define DMAC_BTCTRL_STEPSIZE_X64              (DMAC_BTCTRL_STEPSIZE_X64_Val << DMAC_BTCTRL_STEPSIZE_Pos) /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 64 Position  */
#define DMAC_BTCTRL_STEPSIZE_X128             (DMAC_BTCTRL_STEPSIZE_X128_Val << DMAC_BTCTRL_STEPSIZE_Pos) /* (DMAC_BTCTRL) Next ADDR = ADDR + (Beat Size in byte) * 128 Position  */
#define DMAC_BTCTRL_Msk                       _UINT16_(0xFF1F)                                     /* (DMAC_BTCTRL) Register Mask  */


/* -------- DMAC_BTCNT : (DMAC Offset: 0x02) (R/W 16) Block Transfer Count -------- */
#define DMAC_BTCNT_BTCNT_Pos                  _UINT16_(0)                                          /* (DMAC_BTCNT) Block Transfer Count Position */
#define DMAC_BTCNT_BTCNT_Msk                  (_UINT16_(0xFFFF) << DMAC_BTCNT_BTCNT_Pos)           /* (DMAC_BTCNT) Block Transfer Count Mask */
#define DMAC_BTCNT_BTCNT(value)               (DMAC_BTCNT_BTCNT_Msk & (_UINT16_(value) << DMAC_BTCNT_BTCNT_Pos)) /* Assigment of value for BTCNT in the DMAC_BTCNT register */
#define DMAC_BTCNT_Msk                        _UINT16_(0xFFFF)                                     /* (DMAC_BTCNT) Register Mask  */


/* -------- DMAC_SRCADDR : (DMAC Offset: 0x04) (R/W 32) Block Transfer Source Address -------- */
#define DMAC_SRCADDR_SRCADDR_Pos              _UINT32_(0)                                          /* (DMAC_SRCADDR) Transfer Source Address Position */
#define DMAC_SRCADDR_SRCADDR_Msk              (_UINT32_(0xFFFFFFFF) << DMAC_SRCADDR_SRCADDR_Pos)   /* (DMAC_SRCADDR) Transfer Source Address Mask */
#define DMAC_SRCADDR_SRCADDR(value)           (DMAC_SRCADDR_SRCADDR_Msk & (_UINT32_(value) << DMAC_SRCADDR_SRCADDR_Pos)) /* Assigment of value for SRCADDR in the DMAC_SRCADDR register */
#define DMAC_SRCADDR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (DMAC_SRCADDR) Register Mask  */


/* -------- DMAC_DSTADDR : (DMAC Offset: 0x08) (R/W 32) Block Transfer Destination Address -------- */
#define DMAC_DSTADDR_DSTADDR_Pos              _UINT32_(0)                                          /* (DMAC_DSTADDR) Transfer Destination Address Position */
#define DMAC_DSTADDR_DSTADDR_Msk              (_UINT32_(0xFFFFFFFF) << DMAC_DSTADDR_DSTADDR_Pos)   /* (DMAC_DSTADDR) Transfer Destination Address Mask */
#define DMAC_DSTADDR_DSTADDR(value)           (DMAC_DSTADDR_DSTADDR_Msk & (_UINT32_(value) << DMAC_DSTADDR_DSTADDR_Pos)) /* Assigment of value for DSTADDR in the DMAC_DSTADDR register */
#define DMAC_DSTADDR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (DMAC_DSTADDR) Register Mask  */


/* -------- DMAC_DESCADDR : (DMAC Offset: 0x0C) (R/W 32) Next Descriptor Address -------- */
#define DMAC_DESCADDR_DESCADDR_Pos            _UINT32_(0)                                          /* (DMAC_DESCADDR) Next Descriptor Address Position */
#define DMAC_DESCADDR_DESCADDR_Msk            (_UINT32_(0xFFFFFFFF) << DMAC_DESCADDR_DESCADDR_Pos) /* (DMAC_DESCADDR) Next Descriptor Address Mask */
#define DMAC_DESCADDR_DESCADDR(value)         (DMAC_DESCADDR_DESCADDR_Msk & (_UINT32_(value) << DMAC_DESCADDR_DESCADDR_Pos)) /* Assigment of value for DESCADDR in the DMAC_DESCADDR register */
#define DMAC_DESCADDR_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (DMAC_DESCADDR) Register Mask  */


/* -------- DMAC_CTRL : (DMAC Offset: 0x00) (R/W 16) Control -------- */
#define DMAC_CTRL_RESETVALUE                  _UINT16_(0x00)                                       /*  (DMAC_CTRL) Control  Reset Value */

#define DMAC_CTRL_SWRST_Pos                   _UINT16_(0)                                          /* (DMAC_CTRL) Software Reset Position */
#define DMAC_CTRL_SWRST_Msk                   (_UINT16_(0x1) << DMAC_CTRL_SWRST_Pos)               /* (DMAC_CTRL) Software Reset Mask */
#define DMAC_CTRL_SWRST(value)                (DMAC_CTRL_SWRST_Msk & (_UINT16_(value) << DMAC_CTRL_SWRST_Pos)) /* Assigment of value for SWRST in the DMAC_CTRL register */
#define DMAC_CTRL_DMAENABLE_Pos               _UINT16_(1)                                          /* (DMAC_CTRL) DMA Enable Position */
#define DMAC_CTRL_DMAENABLE_Msk               (_UINT16_(0x1) << DMAC_CTRL_DMAENABLE_Pos)           /* (DMAC_CTRL) DMA Enable Mask */
#define DMAC_CTRL_DMAENABLE(value)            (DMAC_CTRL_DMAENABLE_Msk & (_UINT16_(value) << DMAC_CTRL_DMAENABLE_Pos)) /* Assigment of value for DMAENABLE in the DMAC_CTRL register */
#define DMAC_CTRL_CRCENABLE_Pos               _UINT16_(2)                                          /* (DMAC_CTRL) CRC Enable Position */
#define DMAC_CTRL_CRCENABLE_Msk               (_UINT16_(0x1) << DMAC_CTRL_CRCENABLE_Pos)           /* (DMAC_CTRL) CRC Enable Mask */
#define DMAC_CTRL_CRCENABLE(value)            (DMAC_CTRL_CRCENABLE_Msk & (_UINT16_(value) << DMAC_CTRL_CRCENABLE_Pos)) /* Assigment of value for CRCENABLE in the DMAC_CTRL register */
#define DMAC_CTRL_LVLEN0_Pos                  _UINT16_(8)                                          /* (DMAC_CTRL) Priority Level 0 Enable Position */
#define DMAC_CTRL_LVLEN0_Msk                  (_UINT16_(0x1) << DMAC_CTRL_LVLEN0_Pos)              /* (DMAC_CTRL) Priority Level 0 Enable Mask */
#define DMAC_CTRL_LVLEN0(value)               (DMAC_CTRL_LVLEN0_Msk & (_UINT16_(value) << DMAC_CTRL_LVLEN0_Pos)) /* Assigment of value for LVLEN0 in the DMAC_CTRL register */
#define DMAC_CTRL_LVLEN1_Pos                  _UINT16_(9)                                          /* (DMAC_CTRL) Priority Level 1 Enable Position */
#define DMAC_CTRL_LVLEN1_Msk                  (_UINT16_(0x1) << DMAC_CTRL_LVLEN1_Pos)              /* (DMAC_CTRL) Priority Level 1 Enable Mask */
#define DMAC_CTRL_LVLEN1(value)               (DMAC_CTRL_LVLEN1_Msk & (_UINT16_(value) << DMAC_CTRL_LVLEN1_Pos)) /* Assigment of value for LVLEN1 in the DMAC_CTRL register */
#define DMAC_CTRL_LVLEN2_Pos                  _UINT16_(10)                                         /* (DMAC_CTRL) Priority Level 2 Enable Position */
#define DMAC_CTRL_LVLEN2_Msk                  (_UINT16_(0x1) << DMAC_CTRL_LVLEN2_Pos)              /* (DMAC_CTRL) Priority Level 2 Enable Mask */
#define DMAC_CTRL_LVLEN2(value)               (DMAC_CTRL_LVLEN2_Msk & (_UINT16_(value) << DMAC_CTRL_LVLEN2_Pos)) /* Assigment of value for LVLEN2 in the DMAC_CTRL register */
#define DMAC_CTRL_LVLEN3_Pos                  _UINT16_(11)                                         /* (DMAC_CTRL) Priority Level 3 Enable Position */
#define DMAC_CTRL_LVLEN3_Msk                  (_UINT16_(0x1) << DMAC_CTRL_LVLEN3_Pos)              /* (DMAC_CTRL) Priority Level 3 Enable Mask */
#define DMAC_CTRL_LVLEN3(value)               (DMAC_CTRL_LVLEN3_Msk & (_UINT16_(value) << DMAC_CTRL_LVLEN3_Pos)) /* Assigment of value for LVLEN3 in the DMAC_CTRL register */
#define DMAC_CTRL_Msk                         _UINT16_(0x0F07)                                     /* (DMAC_CTRL) Register Mask  */

#define DMAC_CTRL_LVLEN_Pos                   _UINT16_(8)                                          /* (DMAC_CTRL Position) Priority Level 3 Enable */
#define DMAC_CTRL_LVLEN_Msk                   (_UINT16_(0xF) << DMAC_CTRL_LVLEN_Pos)               /* (DMAC_CTRL Mask) LVLEN */
#define DMAC_CTRL_LVLEN(value)                (DMAC_CTRL_LVLEN_Msk & (_UINT16_(value) << DMAC_CTRL_LVLEN_Pos)) 

/* -------- DMAC_CRCCTRL : (DMAC Offset: 0x02) (R/W 16) CRC Control -------- */
#define DMAC_CRCCTRL_RESETVALUE               _UINT16_(0x00)                                       /*  (DMAC_CRCCTRL) CRC Control  Reset Value */

#define DMAC_CRCCTRL_CRCBEATSIZE_Pos          _UINT16_(0)                                          /* (DMAC_CRCCTRL) CRC Beat Size Position */
#define DMAC_CRCCTRL_CRCBEATSIZE_Msk          (_UINT16_(0x3) << DMAC_CRCCTRL_CRCBEATSIZE_Pos)      /* (DMAC_CRCCTRL) CRC Beat Size Mask */
#define DMAC_CRCCTRL_CRCBEATSIZE(value)       (DMAC_CRCCTRL_CRCBEATSIZE_Msk & (_UINT16_(value) << DMAC_CRCCTRL_CRCBEATSIZE_Pos)) /* Assigment of value for CRCBEATSIZE in the DMAC_CRCCTRL register */
#define   DMAC_CRCCTRL_CRCBEATSIZE_BYTE_Val   _UINT16_(0x0)                                        /* (DMAC_CRCCTRL) 8-bit bus transfer  */
#define   DMAC_CRCCTRL_CRCBEATSIZE_HWORD_Val  _UINT16_(0x1)                                        /* (DMAC_CRCCTRL) 16-bit bus transfer  */
#define   DMAC_CRCCTRL_CRCBEATSIZE_WORD_Val   _UINT16_(0x2)                                        /* (DMAC_CRCCTRL) 32-bit bus transfer  */
#define DMAC_CRCCTRL_CRCBEATSIZE_BYTE         (DMAC_CRCCTRL_CRCBEATSIZE_BYTE_Val << DMAC_CRCCTRL_CRCBEATSIZE_Pos) /* (DMAC_CRCCTRL) 8-bit bus transfer Position  */
#define DMAC_CRCCTRL_CRCBEATSIZE_HWORD        (DMAC_CRCCTRL_CRCBEATSIZE_HWORD_Val << DMAC_CRCCTRL_CRCBEATSIZE_Pos) /* (DMAC_CRCCTRL) 16-bit bus transfer Position  */
#define DMAC_CRCCTRL_CRCBEATSIZE_WORD         (DMAC_CRCCTRL_CRCBEATSIZE_WORD_Val << DMAC_CRCCTRL_CRCBEATSIZE_Pos) /* (DMAC_CRCCTRL) 32-bit bus transfer Position  */
#define DMAC_CRCCTRL_CRCPOLY_Pos              _UINT16_(2)                                          /* (DMAC_CRCCTRL) CRC Polynomial Type Position */
#define DMAC_CRCCTRL_CRCPOLY_Msk              (_UINT16_(0x3) << DMAC_CRCCTRL_CRCPOLY_Pos)          /* (DMAC_CRCCTRL) CRC Polynomial Type Mask */
#define DMAC_CRCCTRL_CRCPOLY(value)           (DMAC_CRCCTRL_CRCPOLY_Msk & (_UINT16_(value) << DMAC_CRCCTRL_CRCPOLY_Pos)) /* Assigment of value for CRCPOLY in the DMAC_CRCCTRL register */
#define   DMAC_CRCCTRL_CRCPOLY_CRC16_Val      _UINT16_(0x0)                                        /* (DMAC_CRCCTRL) CRC-16 (CRC-CCITT)  */
#define   DMAC_CRCCTRL_CRCPOLY_CRC32_Val      _UINT16_(0x1)                                        /* (DMAC_CRCCTRL) CRC32 (IEEE 802.3)  */
#define DMAC_CRCCTRL_CRCPOLY_CRC16            (DMAC_CRCCTRL_CRCPOLY_CRC16_Val << DMAC_CRCCTRL_CRCPOLY_Pos) /* (DMAC_CRCCTRL) CRC-16 (CRC-CCITT) Position  */
#define DMAC_CRCCTRL_CRCPOLY_CRC32            (DMAC_CRCCTRL_CRCPOLY_CRC32_Val << DMAC_CRCCTRL_CRCPOLY_Pos) /* (DMAC_CRCCTRL) CRC32 (IEEE 802.3) Position  */
#define DMAC_CRCCTRL_CRCSRC_Pos               _UINT16_(8)                                          /* (DMAC_CRCCTRL) CRC Input Source Position */
#define DMAC_CRCCTRL_CRCSRC_Msk               (_UINT16_(0x3F) << DMAC_CRCCTRL_CRCSRC_Pos)          /* (DMAC_CRCCTRL) CRC Input Source Mask */
#define DMAC_CRCCTRL_CRCSRC(value)            (DMAC_CRCCTRL_CRCSRC_Msk & (_UINT16_(value) << DMAC_CRCCTRL_CRCSRC_Pos)) /* Assigment of value for CRCSRC in the DMAC_CRCCTRL register */
#define   DMAC_CRCCTRL_CRCSRC_NOACT_Val       _UINT16_(0x0)                                        /* (DMAC_CRCCTRL) No action  */
#define   DMAC_CRCCTRL_CRCSRC_IO_Val          _UINT16_(0x1)                                        /* (DMAC_CRCCTRL) I/O interface  */
#define   DMAC_CRCCTRL_CRCSRC_CHN0_Val        _UINT16_(0x20)                                       /* (DMAC_CRCCTRL) DMA Channel 0  */
#define   DMAC_CRCCTRL_CRCSRC_CHN1_Val        _UINT16_(0x21)                                       /* (DMAC_CRCCTRL) DMA Channel 1  */
#define   DMAC_CRCCTRL_CRCSRC_CHN2_Val        _UINT16_(0x22)                                       /* (DMAC_CRCCTRL) DMA Channel 2  */
#define   DMAC_CRCCTRL_CRCSRC_CHN3_Val        _UINT16_(0x23)                                       /* (DMAC_CRCCTRL) DMA Channel 3  */
#define   DMAC_CRCCTRL_CRCSRC_CHN4_Val        _UINT16_(0x24)                                       /* (DMAC_CRCCTRL) DMA Channel 4  */
#define   DMAC_CRCCTRL_CRCSRC_CHN5_Val        _UINT16_(0x25)                                       /* (DMAC_CRCCTRL) DMA Channel 5  */
#define   DMAC_CRCCTRL_CRCSRC_CHN6_Val        _UINT16_(0x26)                                       /* (DMAC_CRCCTRL) DMA Channel 6  */
#define   DMAC_CRCCTRL_CRCSRC_CHN7_Val        _UINT16_(0x27)                                       /* (DMAC_CRCCTRL) DMA Channel 7  */
#define   DMAC_CRCCTRL_CRCSRC_CHN8_Val        _UINT16_(0x28)                                       /* (DMAC_CRCCTRL) DMA Channel 8  */
#define   DMAC_CRCCTRL_CRCSRC_CHN9_Val        _UINT16_(0x29)                                       /* (DMAC_CRCCTRL) DMA Channel 9  */
#define   DMAC_CRCCTRL_CRCSRC_CHN10_Val       _UINT16_(0x2A)                                       /* (DMAC_CRCCTRL) DMA Channel 10  */
#define   DMAC_CRCCTRL_CRCSRC_CHN11_Val       _UINT16_(0x2B)                                       /* (DMAC_CRCCTRL) DMA Channel 11  */
#define   DMAC_CRCCTRL_CRCSRC_CHN12_Val       _UINT16_(0x2C)                                       /* (DMAC_CRCCTRL) DMA Channel 12  */
#define   DMAC_CRCCTRL_CRCSRC_CHN13_Val       _UINT16_(0x2D)                                       /* (DMAC_CRCCTRL) DMA Channel 13  */
#define   DMAC_CRCCTRL_CRCSRC_CHN14_Val       _UINT16_(0x2E)                                       /* (DMAC_CRCCTRL) DMA Channel 14  */
#define   DMAC_CRCCTRL_CRCSRC_CHN15_Val       _UINT16_(0x2F)                                       /* (DMAC_CRCCTRL) DMA Channel 15  */
#define DMAC_CRCCTRL_CRCSRC_NOACT             (DMAC_CRCCTRL_CRCSRC_NOACT_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) No action Position  */
#define DMAC_CRCCTRL_CRCSRC_IO                (DMAC_CRCCTRL_CRCSRC_IO_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) I/O interface Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN0              (DMAC_CRCCTRL_CRCSRC_CHN0_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 0 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN1              (DMAC_CRCCTRL_CRCSRC_CHN1_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 1 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN2              (DMAC_CRCCTRL_CRCSRC_CHN2_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 2 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN3              (DMAC_CRCCTRL_CRCSRC_CHN3_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 3 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN4              (DMAC_CRCCTRL_CRCSRC_CHN4_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 4 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN5              (DMAC_CRCCTRL_CRCSRC_CHN5_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 5 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN6              (DMAC_CRCCTRL_CRCSRC_CHN6_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 6 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN7              (DMAC_CRCCTRL_CRCSRC_CHN7_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 7 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN8              (DMAC_CRCCTRL_CRCSRC_CHN8_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 8 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN9              (DMAC_CRCCTRL_CRCSRC_CHN9_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 9 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN10             (DMAC_CRCCTRL_CRCSRC_CHN10_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 10 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN11             (DMAC_CRCCTRL_CRCSRC_CHN11_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 11 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN12             (DMAC_CRCCTRL_CRCSRC_CHN12_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 12 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN13             (DMAC_CRCCTRL_CRCSRC_CHN13_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 13 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN14             (DMAC_CRCCTRL_CRCSRC_CHN14_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 14 Position  */
#define DMAC_CRCCTRL_CRCSRC_CHN15             (DMAC_CRCCTRL_CRCSRC_CHN15_Val << DMAC_CRCCTRL_CRCSRC_Pos) /* (DMAC_CRCCTRL) DMA Channel 15 Position  */
#define DMAC_CRCCTRL_Msk                      _UINT16_(0x3F0F)                                     /* (DMAC_CRCCTRL) Register Mask  */


/* -------- DMAC_CRCDATAIN : (DMAC Offset: 0x04) (R/W 32) CRC Data Input -------- */
#define DMAC_CRCDATAIN_RESETVALUE             _UINT32_(0x00)                                       /*  (DMAC_CRCDATAIN) CRC Data Input  Reset Value */

#define DMAC_CRCDATAIN_CRCDATAIN_Pos          _UINT32_(0)                                          /* (DMAC_CRCDATAIN) CRC Data Input Position */
#define DMAC_CRCDATAIN_CRCDATAIN_Msk          (_UINT32_(0xFFFFFFFF) << DMAC_CRCDATAIN_CRCDATAIN_Pos) /* (DMAC_CRCDATAIN) CRC Data Input Mask */
#define DMAC_CRCDATAIN_CRCDATAIN(value)       (DMAC_CRCDATAIN_CRCDATAIN_Msk & (_UINT32_(value) << DMAC_CRCDATAIN_CRCDATAIN_Pos)) /* Assigment of value for CRCDATAIN in the DMAC_CRCDATAIN register */
#define DMAC_CRCDATAIN_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (DMAC_CRCDATAIN) Register Mask  */


/* -------- DMAC_CRCCHKSUM : (DMAC Offset: 0x08) (R/W 32) CRC Checksum -------- */
#define DMAC_CRCCHKSUM_RESETVALUE             _UINT32_(0x00)                                       /*  (DMAC_CRCCHKSUM) CRC Checksum  Reset Value */

#define DMAC_CRCCHKSUM_CRCCHKSUM_Pos          _UINT32_(0)                                          /* (DMAC_CRCCHKSUM) CRC Checksum Position */
#define DMAC_CRCCHKSUM_CRCCHKSUM_Msk          (_UINT32_(0xFFFFFFFF) << DMAC_CRCCHKSUM_CRCCHKSUM_Pos) /* (DMAC_CRCCHKSUM) CRC Checksum Mask */
#define DMAC_CRCCHKSUM_CRCCHKSUM(value)       (DMAC_CRCCHKSUM_CRCCHKSUM_Msk & (_UINT32_(value) << DMAC_CRCCHKSUM_CRCCHKSUM_Pos)) /* Assigment of value for CRCCHKSUM in the DMAC_CRCCHKSUM register */
#define DMAC_CRCCHKSUM_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (DMAC_CRCCHKSUM) Register Mask  */


/* -------- DMAC_CRCSTATUS : (DMAC Offset: 0x0C) (R/W 8) CRC Status -------- */
#define DMAC_CRCSTATUS_RESETVALUE             _UINT8_(0x00)                                        /*  (DMAC_CRCSTATUS) CRC Status  Reset Value */

#define DMAC_CRCSTATUS_CRCBUSY_Pos            _UINT8_(0)                                           /* (DMAC_CRCSTATUS) CRC Module Busy Position */
#define DMAC_CRCSTATUS_CRCBUSY_Msk            (_UINT8_(0x1) << DMAC_CRCSTATUS_CRCBUSY_Pos)         /* (DMAC_CRCSTATUS) CRC Module Busy Mask */
#define DMAC_CRCSTATUS_CRCBUSY(value)         (DMAC_CRCSTATUS_CRCBUSY_Msk & (_UINT8_(value) << DMAC_CRCSTATUS_CRCBUSY_Pos)) /* Assigment of value for CRCBUSY in the DMAC_CRCSTATUS register */
#define DMAC_CRCSTATUS_CRCZERO_Pos            _UINT8_(1)                                           /* (DMAC_CRCSTATUS) CRC Zero Position */
#define DMAC_CRCSTATUS_CRCZERO_Msk            (_UINT8_(0x1) << DMAC_CRCSTATUS_CRCZERO_Pos)         /* (DMAC_CRCSTATUS) CRC Zero Mask */
#define DMAC_CRCSTATUS_CRCZERO(value)         (DMAC_CRCSTATUS_CRCZERO_Msk & (_UINT8_(value) << DMAC_CRCSTATUS_CRCZERO_Pos)) /* Assigment of value for CRCZERO in the DMAC_CRCSTATUS register */
#define DMAC_CRCSTATUS_Msk                    _UINT8_(0x03)                                        /* (DMAC_CRCSTATUS) Register Mask  */


/* -------- DMAC_DBGCTRL : (DMAC Offset: 0x0D) (R/W 8) Debug Control -------- */
#define DMAC_DBGCTRL_RESETVALUE               _UINT8_(0x00)                                        /*  (DMAC_DBGCTRL) Debug Control  Reset Value */

#define DMAC_DBGCTRL_DBGRUN_Pos               _UINT8_(0)                                           /* (DMAC_DBGCTRL) Debug Run Position */
#define DMAC_DBGCTRL_DBGRUN_Msk               (_UINT8_(0x1) << DMAC_DBGCTRL_DBGRUN_Pos)            /* (DMAC_DBGCTRL) Debug Run Mask */
#define DMAC_DBGCTRL_DBGRUN(value)            (DMAC_DBGCTRL_DBGRUN_Msk & (_UINT8_(value) << DMAC_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the DMAC_DBGCTRL register */
#define DMAC_DBGCTRL_Msk                      _UINT8_(0x01)                                        /* (DMAC_DBGCTRL) Register Mask  */


/* -------- DMAC_QOSCTRL : (DMAC Offset: 0x0E) (R/W 8) QOS Control -------- */
#define DMAC_QOSCTRL_RESETVALUE               _UINT8_(0x2A)                                        /*  (DMAC_QOSCTRL) QOS Control  Reset Value */

#define DMAC_QOSCTRL_WRBQOS_Pos               _UINT8_(0)                                           /* (DMAC_QOSCTRL) Write-Back Quality of Service Position */
#define DMAC_QOSCTRL_WRBQOS_Msk               (_UINT8_(0x3) << DMAC_QOSCTRL_WRBQOS_Pos)            /* (DMAC_QOSCTRL) Write-Back Quality of Service Mask */
#define DMAC_QOSCTRL_WRBQOS(value)            (DMAC_QOSCTRL_WRBQOS_Msk & (_UINT8_(value) << DMAC_QOSCTRL_WRBQOS_Pos)) /* Assigment of value for WRBQOS in the DMAC_QOSCTRL register */
#define   DMAC_QOSCTRL_WRBQOS_DISABLE_Val     _UINT8_(0x0)                                         /* (DMAC_QOSCTRL) Background (no sensitive operation)  */
#define   DMAC_QOSCTRL_WRBQOS_LOW_Val         _UINT8_(0x1)                                         /* (DMAC_QOSCTRL) Sensitive Bandwidth  */
#define   DMAC_QOSCTRL_WRBQOS_MEDIUM_Val      _UINT8_(0x2)                                         /* (DMAC_QOSCTRL) Sensitive Latency  */
#define   DMAC_QOSCTRL_WRBQOS_HIGH_Val        _UINT8_(0x3)                                         /* (DMAC_QOSCTRL) Critical Latency  */
#define DMAC_QOSCTRL_WRBQOS_DISABLE           (DMAC_QOSCTRL_WRBQOS_DISABLE_Val << DMAC_QOSCTRL_WRBQOS_Pos) /* (DMAC_QOSCTRL) Background (no sensitive operation) Position  */
#define DMAC_QOSCTRL_WRBQOS_LOW               (DMAC_QOSCTRL_WRBQOS_LOW_Val << DMAC_QOSCTRL_WRBQOS_Pos) /* (DMAC_QOSCTRL) Sensitive Bandwidth Position  */
#define DMAC_QOSCTRL_WRBQOS_MEDIUM            (DMAC_QOSCTRL_WRBQOS_MEDIUM_Val << DMAC_QOSCTRL_WRBQOS_Pos) /* (DMAC_QOSCTRL) Sensitive Latency Position  */
#define DMAC_QOSCTRL_WRBQOS_HIGH              (DMAC_QOSCTRL_WRBQOS_HIGH_Val << DMAC_QOSCTRL_WRBQOS_Pos) /* (DMAC_QOSCTRL) Critical Latency Position  */
#define DMAC_QOSCTRL_FQOS_Pos                 _UINT8_(2)                                           /* (DMAC_QOSCTRL) Fetch Quality of Service Position */
#define DMAC_QOSCTRL_FQOS_Msk                 (_UINT8_(0x3) << DMAC_QOSCTRL_FQOS_Pos)              /* (DMAC_QOSCTRL) Fetch Quality of Service Mask */
#define DMAC_QOSCTRL_FQOS(value)              (DMAC_QOSCTRL_FQOS_Msk & (_UINT8_(value) << DMAC_QOSCTRL_FQOS_Pos)) /* Assigment of value for FQOS in the DMAC_QOSCTRL register */
#define   DMAC_QOSCTRL_FQOS_DISABLE_Val       _UINT8_(0x0)                                         /* (DMAC_QOSCTRL) Background (no sensitive operation)  */
#define   DMAC_QOSCTRL_FQOS_LOW_Val           _UINT8_(0x1)                                         /* (DMAC_QOSCTRL) Sensitive Bandwidth  */
#define   DMAC_QOSCTRL_FQOS_MEDIUM_Val        _UINT8_(0x2)                                         /* (DMAC_QOSCTRL) Sensitive Latency  */
#define   DMAC_QOSCTRL_FQOS_HIGH_Val          _UINT8_(0x3)                                         /* (DMAC_QOSCTRL) Critical Latency  */
#define DMAC_QOSCTRL_FQOS_DISABLE             (DMAC_QOSCTRL_FQOS_DISABLE_Val << DMAC_QOSCTRL_FQOS_Pos) /* (DMAC_QOSCTRL) Background (no sensitive operation) Position  */
#define DMAC_QOSCTRL_FQOS_LOW                 (DMAC_QOSCTRL_FQOS_LOW_Val << DMAC_QOSCTRL_FQOS_Pos) /* (DMAC_QOSCTRL) Sensitive Bandwidth Position  */
#define DMAC_QOSCTRL_FQOS_MEDIUM              (DMAC_QOSCTRL_FQOS_MEDIUM_Val << DMAC_QOSCTRL_FQOS_Pos) /* (DMAC_QOSCTRL) Sensitive Latency Position  */
#define DMAC_QOSCTRL_FQOS_HIGH                (DMAC_QOSCTRL_FQOS_HIGH_Val << DMAC_QOSCTRL_FQOS_Pos) /* (DMAC_QOSCTRL) Critical Latency Position  */
#define DMAC_QOSCTRL_DQOS_Pos                 _UINT8_(4)                                           /* (DMAC_QOSCTRL) Data Transfer Quality of Service Position */
#define DMAC_QOSCTRL_DQOS_Msk                 (_UINT8_(0x3) << DMAC_QOSCTRL_DQOS_Pos)              /* (DMAC_QOSCTRL) Data Transfer Quality of Service Mask */
#define DMAC_QOSCTRL_DQOS(value)              (DMAC_QOSCTRL_DQOS_Msk & (_UINT8_(value) << DMAC_QOSCTRL_DQOS_Pos)) /* Assigment of value for DQOS in the DMAC_QOSCTRL register */
#define   DMAC_QOSCTRL_DQOS_DISABLE_Val       _UINT8_(0x0)                                         /* (DMAC_QOSCTRL) Background (no sensitive operation)  */
#define   DMAC_QOSCTRL_DQOS_LOW_Val           _UINT8_(0x1)                                         /* (DMAC_QOSCTRL) Sensitive Bandwidth  */
#define   DMAC_QOSCTRL_DQOS_MEDIUM_Val        _UINT8_(0x2)                                         /* (DMAC_QOSCTRL) Sensitive Latency  */
#define   DMAC_QOSCTRL_DQOS_HIGH_Val          _UINT8_(0x3)                                         /* (DMAC_QOSCTRL) Critical Latency  */
#define DMAC_QOSCTRL_DQOS_DISABLE             (DMAC_QOSCTRL_DQOS_DISABLE_Val << DMAC_QOSCTRL_DQOS_Pos) /* (DMAC_QOSCTRL) Background (no sensitive operation) Position  */
#define DMAC_QOSCTRL_DQOS_LOW                 (DMAC_QOSCTRL_DQOS_LOW_Val << DMAC_QOSCTRL_DQOS_Pos) /* (DMAC_QOSCTRL) Sensitive Bandwidth Position  */
#define DMAC_QOSCTRL_DQOS_MEDIUM              (DMAC_QOSCTRL_DQOS_MEDIUM_Val << DMAC_QOSCTRL_DQOS_Pos) /* (DMAC_QOSCTRL) Sensitive Latency Position  */
#define DMAC_QOSCTRL_DQOS_HIGH                (DMAC_QOSCTRL_DQOS_HIGH_Val << DMAC_QOSCTRL_DQOS_Pos) /* (DMAC_QOSCTRL) Critical Latency Position  */
#define DMAC_QOSCTRL_Msk                      _UINT8_(0x3F)                                        /* (DMAC_QOSCTRL) Register Mask  */


/* -------- DMAC_SWTRIGCTRL : (DMAC Offset: 0x10) (R/W 32) Software Trigger Control -------- */
#define DMAC_SWTRIGCTRL_RESETVALUE            _UINT32_(0x00)                                       /*  (DMAC_SWTRIGCTRL) Software Trigger Control  Reset Value */

#define DMAC_SWTRIGCTRL_SWTRIG0_Pos           _UINT32_(0)                                          /* (DMAC_SWTRIGCTRL) Channel 0 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG0_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG0_Pos)       /* (DMAC_SWTRIGCTRL) Channel 0 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG0(value)        (DMAC_SWTRIGCTRL_SWTRIG0_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG0_Pos)) /* Assigment of value for SWTRIG0 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG1_Pos           _UINT32_(1)                                          /* (DMAC_SWTRIGCTRL) Channel 1 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG1_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG1_Pos)       /* (DMAC_SWTRIGCTRL) Channel 1 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG1(value)        (DMAC_SWTRIGCTRL_SWTRIG1_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG1_Pos)) /* Assigment of value for SWTRIG1 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG2_Pos           _UINT32_(2)                                          /* (DMAC_SWTRIGCTRL) Channel 2 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG2_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG2_Pos)       /* (DMAC_SWTRIGCTRL) Channel 2 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG2(value)        (DMAC_SWTRIGCTRL_SWTRIG2_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG2_Pos)) /* Assigment of value for SWTRIG2 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG3_Pos           _UINT32_(3)                                          /* (DMAC_SWTRIGCTRL) Channel 3 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG3_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG3_Pos)       /* (DMAC_SWTRIGCTRL) Channel 3 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG3(value)        (DMAC_SWTRIGCTRL_SWTRIG3_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG3_Pos)) /* Assigment of value for SWTRIG3 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG4_Pos           _UINT32_(4)                                          /* (DMAC_SWTRIGCTRL) Channel 4 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG4_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG4_Pos)       /* (DMAC_SWTRIGCTRL) Channel 4 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG4(value)        (DMAC_SWTRIGCTRL_SWTRIG4_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG4_Pos)) /* Assigment of value for SWTRIG4 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG5_Pos           _UINT32_(5)                                          /* (DMAC_SWTRIGCTRL) Channel 5 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG5_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG5_Pos)       /* (DMAC_SWTRIGCTRL) Channel 5 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG5(value)        (DMAC_SWTRIGCTRL_SWTRIG5_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG5_Pos)) /* Assigment of value for SWTRIG5 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG6_Pos           _UINT32_(6)                                          /* (DMAC_SWTRIGCTRL) Channel 6 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG6_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG6_Pos)       /* (DMAC_SWTRIGCTRL) Channel 6 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG6(value)        (DMAC_SWTRIGCTRL_SWTRIG6_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG6_Pos)) /* Assigment of value for SWTRIG6 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG7_Pos           _UINT32_(7)                                          /* (DMAC_SWTRIGCTRL) Channel 7 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG7_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG7_Pos)       /* (DMAC_SWTRIGCTRL) Channel 7 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG7(value)        (DMAC_SWTRIGCTRL_SWTRIG7_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG7_Pos)) /* Assigment of value for SWTRIG7 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG8_Pos           _UINT32_(8)                                          /* (DMAC_SWTRIGCTRL) Channel 8 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG8_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG8_Pos)       /* (DMAC_SWTRIGCTRL) Channel 8 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG8(value)        (DMAC_SWTRIGCTRL_SWTRIG8_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG8_Pos)) /* Assigment of value for SWTRIG8 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG9_Pos           _UINT32_(9)                                          /* (DMAC_SWTRIGCTRL) Channel 9 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG9_Msk           (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG9_Pos)       /* (DMAC_SWTRIGCTRL) Channel 9 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG9(value)        (DMAC_SWTRIGCTRL_SWTRIG9_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG9_Pos)) /* Assigment of value for SWTRIG9 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG10_Pos          _UINT32_(10)                                         /* (DMAC_SWTRIGCTRL) Channel 10 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG10_Msk          (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG10_Pos)      /* (DMAC_SWTRIGCTRL) Channel 10 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG10(value)       (DMAC_SWTRIGCTRL_SWTRIG10_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG10_Pos)) /* Assigment of value for SWTRIG10 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG11_Pos          _UINT32_(11)                                         /* (DMAC_SWTRIGCTRL) Channel 11 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG11_Msk          (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG11_Pos)      /* (DMAC_SWTRIGCTRL) Channel 11 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG11(value)       (DMAC_SWTRIGCTRL_SWTRIG11_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG11_Pos)) /* Assigment of value for SWTRIG11 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG12_Pos          _UINT32_(12)                                         /* (DMAC_SWTRIGCTRL) Channel 12 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG12_Msk          (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG12_Pos)      /* (DMAC_SWTRIGCTRL) Channel 12 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG12(value)       (DMAC_SWTRIGCTRL_SWTRIG12_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG12_Pos)) /* Assigment of value for SWTRIG12 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG13_Pos          _UINT32_(13)                                         /* (DMAC_SWTRIGCTRL) Channel 13 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG13_Msk          (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG13_Pos)      /* (DMAC_SWTRIGCTRL) Channel 13 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG13(value)       (DMAC_SWTRIGCTRL_SWTRIG13_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG13_Pos)) /* Assigment of value for SWTRIG13 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG14_Pos          _UINT32_(14)                                         /* (DMAC_SWTRIGCTRL) Channel 14 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG14_Msk          (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG14_Pos)      /* (DMAC_SWTRIGCTRL) Channel 14 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG14(value)       (DMAC_SWTRIGCTRL_SWTRIG14_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG14_Pos)) /* Assigment of value for SWTRIG14 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_SWTRIG15_Pos          _UINT32_(15)                                         /* (DMAC_SWTRIGCTRL) Channel 15 Software Trigger Position */
#define DMAC_SWTRIGCTRL_SWTRIG15_Msk          (_UINT32_(0x1) << DMAC_SWTRIGCTRL_SWTRIG15_Pos)      /* (DMAC_SWTRIGCTRL) Channel 15 Software Trigger Mask */
#define DMAC_SWTRIGCTRL_SWTRIG15(value)       (DMAC_SWTRIGCTRL_SWTRIG15_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG15_Pos)) /* Assigment of value for SWTRIG15 in the DMAC_SWTRIGCTRL register */
#define DMAC_SWTRIGCTRL_Msk                   _UINT32_(0x0000FFFF)                                 /* (DMAC_SWTRIGCTRL) Register Mask  */

#define DMAC_SWTRIGCTRL_SWTRIG_Pos            _UINT32_(0)                                          /* (DMAC_SWTRIGCTRL Position) Channel x5 Software Trigger */
#define DMAC_SWTRIGCTRL_SWTRIG_Msk            (_UINT32_(0xFFFF) << DMAC_SWTRIGCTRL_SWTRIG_Pos)     /* (DMAC_SWTRIGCTRL Mask) SWTRIG */
#define DMAC_SWTRIGCTRL_SWTRIG(value)         (DMAC_SWTRIGCTRL_SWTRIG_Msk & (_UINT32_(value) << DMAC_SWTRIGCTRL_SWTRIG_Pos)) 

/* -------- DMAC_PRICTRL0 : (DMAC Offset: 0x14) (R/W 32) Priority Control -------- */
#define DMAC_PRICTRL0_RESETVALUE              _UINT32_(0x00)                                       /*  (DMAC_PRICTRL0) Priority Control  Reset Value */

#define DMAC_PRICTRL0_LVLPRI0_Pos             _UINT32_(0)                                          /* (DMAC_PRICTRL0) Level 0 Channel Priority Number Position */
#define DMAC_PRICTRL0_LVLPRI0_Msk             (_UINT32_(0xF) << DMAC_PRICTRL0_LVLPRI0_Pos)         /* (DMAC_PRICTRL0) Level 0 Channel Priority Number Mask */
#define DMAC_PRICTRL0_LVLPRI0(value)          (DMAC_PRICTRL0_LVLPRI0_Msk & (_UINT32_(value) << DMAC_PRICTRL0_LVLPRI0_Pos)) /* Assigment of value for LVLPRI0 in the DMAC_PRICTRL0 register */
#define DMAC_PRICTRL0_RRLVLEN0_Pos            _UINT32_(7)                                          /* (DMAC_PRICTRL0) Level 0 Round-Robin Scheduling Enable Position */
#define DMAC_PRICTRL0_RRLVLEN0_Msk            (_UINT32_(0x1) << DMAC_PRICTRL0_RRLVLEN0_Pos)        /* (DMAC_PRICTRL0) Level 0 Round-Robin Scheduling Enable Mask */
#define DMAC_PRICTRL0_RRLVLEN0(value)         (DMAC_PRICTRL0_RRLVLEN0_Msk & (_UINT32_(value) << DMAC_PRICTRL0_RRLVLEN0_Pos)) /* Assigment of value for RRLVLEN0 in the DMAC_PRICTRL0 register */
#define   DMAC_PRICTRL0_RRLVLEN0_STATIC_LVL_Val _UINT32_(0x0)                                        /* (DMAC_PRICTRL0) Static arbitration scheme for channels with level 0 priority  */
#define   DMAC_PRICTRL0_RRLVLEN0_ROUND_ROBIN_LVL_Val _UINT32_(0x1)                                        /* (DMAC_PRICTRL0) Round-robin arbitration scheme for channels with level 0 priority  */
#define DMAC_PRICTRL0_RRLVLEN0_STATIC_LVL     (DMAC_PRICTRL0_RRLVLEN0_STATIC_LVL_Val << DMAC_PRICTRL0_RRLVLEN0_Pos) /* (DMAC_PRICTRL0) Static arbitration scheme for channels with level 0 priority Position  */
#define DMAC_PRICTRL0_RRLVLEN0_ROUND_ROBIN_LVL (DMAC_PRICTRL0_RRLVLEN0_ROUND_ROBIN_LVL_Val << DMAC_PRICTRL0_RRLVLEN0_Pos) /* (DMAC_PRICTRL0) Round-robin arbitration scheme for channels with level 0 priority Position  */
#define DMAC_PRICTRL0_LVLPRI1_Pos             _UINT32_(8)                                          /* (DMAC_PRICTRL0) Level 1 Channel Priority Number Position */
#define DMAC_PRICTRL0_LVLPRI1_Msk             (_UINT32_(0xF) << DMAC_PRICTRL0_LVLPRI1_Pos)         /* (DMAC_PRICTRL0) Level 1 Channel Priority Number Mask */
#define DMAC_PRICTRL0_LVLPRI1(value)          (DMAC_PRICTRL0_LVLPRI1_Msk & (_UINT32_(value) << DMAC_PRICTRL0_LVLPRI1_Pos)) /* Assigment of value for LVLPRI1 in the DMAC_PRICTRL0 register */
#define DMAC_PRICTRL0_RRLVLEN1_Pos            _UINT32_(15)                                         /* (DMAC_PRICTRL0) Level 1 Round-Robin Scheduling Enable Position */
#define DMAC_PRICTRL0_RRLVLEN1_Msk            (_UINT32_(0x1) << DMAC_PRICTRL0_RRLVLEN1_Pos)        /* (DMAC_PRICTRL0) Level 1 Round-Robin Scheduling Enable Mask */
#define DMAC_PRICTRL0_RRLVLEN1(value)         (DMAC_PRICTRL0_RRLVLEN1_Msk & (_UINT32_(value) << DMAC_PRICTRL0_RRLVLEN1_Pos)) /* Assigment of value for RRLVLEN1 in the DMAC_PRICTRL0 register */
#define   DMAC_PRICTRL0_RRLVLEN1_STATIC_LVL_Val _UINT32_(0x0)                                        /* (DMAC_PRICTRL0) Static arbitration scheme for channels with level 1 priority  */
#define   DMAC_PRICTRL0_RRLVLEN1_ROUND_ROBIN_LVL_Val _UINT32_(0x1)                                        /* (DMAC_PRICTRL0) Round-robin arbitration scheme for channels with level 1 priority  */
#define DMAC_PRICTRL0_RRLVLEN1_STATIC_LVL     (DMAC_PRICTRL0_RRLVLEN1_STATIC_LVL_Val << DMAC_PRICTRL0_RRLVLEN1_Pos) /* (DMAC_PRICTRL0) Static arbitration scheme for channels with level 1 priority Position  */
#define DMAC_PRICTRL0_RRLVLEN1_ROUND_ROBIN_LVL (DMAC_PRICTRL0_RRLVLEN1_ROUND_ROBIN_LVL_Val << DMAC_PRICTRL0_RRLVLEN1_Pos) /* (DMAC_PRICTRL0) Round-robin arbitration scheme for channels with level 1 priority Position  */
#define DMAC_PRICTRL0_LVLPRI2_Pos             _UINT32_(16)                                         /* (DMAC_PRICTRL0) Level 2 Channel Priority Number Position */
#define DMAC_PRICTRL0_LVLPRI2_Msk             (_UINT32_(0xF) << DMAC_PRICTRL0_LVLPRI2_Pos)         /* (DMAC_PRICTRL0) Level 2 Channel Priority Number Mask */
#define DMAC_PRICTRL0_LVLPRI2(value)          (DMAC_PRICTRL0_LVLPRI2_Msk & (_UINT32_(value) << DMAC_PRICTRL0_LVLPRI2_Pos)) /* Assigment of value for LVLPRI2 in the DMAC_PRICTRL0 register */
#define DMAC_PRICTRL0_RRLVLEN2_Pos            _UINT32_(23)                                         /* (DMAC_PRICTRL0) Level 2 Round-Robin Scheduling Enable Position */
#define DMAC_PRICTRL0_RRLVLEN2_Msk            (_UINT32_(0x1) << DMAC_PRICTRL0_RRLVLEN2_Pos)        /* (DMAC_PRICTRL0) Level 2 Round-Robin Scheduling Enable Mask */
#define DMAC_PRICTRL0_RRLVLEN2(value)         (DMAC_PRICTRL0_RRLVLEN2_Msk & (_UINT32_(value) << DMAC_PRICTRL0_RRLVLEN2_Pos)) /* Assigment of value for RRLVLEN2 in the DMAC_PRICTRL0 register */
#define   DMAC_PRICTRL0_RRLVLEN2_STATIC_LVL_Val _UINT32_(0x0)                                        /* (DMAC_PRICTRL0) Static arbitration scheme for channels with level 2 priority  */
#define   DMAC_PRICTRL0_RRLVLEN2_ROUND_ROBIN_LVL_Val _UINT32_(0x1)                                        /* (DMAC_PRICTRL0) Round-robin arbitration scheme for channels with level 2 priority  */
#define DMAC_PRICTRL0_RRLVLEN2_STATIC_LVL     (DMAC_PRICTRL0_RRLVLEN2_STATIC_LVL_Val << DMAC_PRICTRL0_RRLVLEN2_Pos) /* (DMAC_PRICTRL0) Static arbitration scheme for channels with level 2 priority Position  */
#define DMAC_PRICTRL0_RRLVLEN2_ROUND_ROBIN_LVL (DMAC_PRICTRL0_RRLVLEN2_ROUND_ROBIN_LVL_Val << DMAC_PRICTRL0_RRLVLEN2_Pos) /* (DMAC_PRICTRL0) Round-robin arbitration scheme for channels with level 2 priority Position  */
#define DMAC_PRICTRL0_LVLPRI3_Pos             _UINT32_(24)                                         /* (DMAC_PRICTRL0) Level 3 Channel Priority Number Position */
#define DMAC_PRICTRL0_LVLPRI3_Msk             (_UINT32_(0xF) << DMAC_PRICTRL0_LVLPRI3_Pos)         /* (DMAC_PRICTRL0) Level 3 Channel Priority Number Mask */
#define DMAC_PRICTRL0_LVLPRI3(value)          (DMAC_PRICTRL0_LVLPRI3_Msk & (_UINT32_(value) << DMAC_PRICTRL0_LVLPRI3_Pos)) /* Assigment of value for LVLPRI3 in the DMAC_PRICTRL0 register */
#define DMAC_PRICTRL0_RRLVLEN3_Pos            _UINT32_(31)                                         /* (DMAC_PRICTRL0) Level 3 Round-Robin Scheduling Enable Position */
#define DMAC_PRICTRL0_RRLVLEN3_Msk            (_UINT32_(0x1) << DMAC_PRICTRL0_RRLVLEN3_Pos)        /* (DMAC_PRICTRL0) Level 3 Round-Robin Scheduling Enable Mask */
#define DMAC_PRICTRL0_RRLVLEN3(value)         (DMAC_PRICTRL0_RRLVLEN3_Msk & (_UINT32_(value) << DMAC_PRICTRL0_RRLVLEN3_Pos)) /* Assigment of value for RRLVLEN3 in the DMAC_PRICTRL0 register */
#define   DMAC_PRICTRL0_RRLVLEN3_STATIC_LVL_Val _UINT32_(0x0)                                        /* (DMAC_PRICTRL0) Static arbitration scheme for channels with level 3 priority  */
#define   DMAC_PRICTRL0_RRLVLEN3_ROUND_ROBIN_LVL_Val _UINT32_(0x1)                                        /* (DMAC_PRICTRL0) Round-robin arbitration scheme for channels with level 3 priority  */
#define DMAC_PRICTRL0_RRLVLEN3_STATIC_LVL     (DMAC_PRICTRL0_RRLVLEN3_STATIC_LVL_Val << DMAC_PRICTRL0_RRLVLEN3_Pos) /* (DMAC_PRICTRL0) Static arbitration scheme for channels with level 3 priority Position  */
#define DMAC_PRICTRL0_RRLVLEN3_ROUND_ROBIN_LVL (DMAC_PRICTRL0_RRLVLEN3_ROUND_ROBIN_LVL_Val << DMAC_PRICTRL0_RRLVLEN3_Pos) /* (DMAC_PRICTRL0) Round-robin arbitration scheme for channels with level 3 priority Position  */
#define DMAC_PRICTRL0_Msk                     _UINT32_(0x8F8F8F8F)                                 /* (DMAC_PRICTRL0) Register Mask  */


/* -------- DMAC_INTPEND : (DMAC Offset: 0x20) (R/W 16) Interrupt Pending -------- */
#define DMAC_INTPEND_RESETVALUE               _UINT16_(0x00)                                       /*  (DMAC_INTPEND) Interrupt Pending  Reset Value */

#define DMAC_INTPEND_ID_Pos                   _UINT16_(0)                                          /* (DMAC_INTPEND) Channel ID Position */
#define DMAC_INTPEND_ID_Msk                   (_UINT16_(0xF) << DMAC_INTPEND_ID_Pos)               /* (DMAC_INTPEND) Channel ID Mask */
#define DMAC_INTPEND_ID(value)                (DMAC_INTPEND_ID_Msk & (_UINT16_(value) << DMAC_INTPEND_ID_Pos)) /* Assigment of value for ID in the DMAC_INTPEND register */
#define DMAC_INTPEND_TERR_Pos                 _UINT16_(8)                                          /* (DMAC_INTPEND) Transfer Error Position */
#define DMAC_INTPEND_TERR_Msk                 (_UINT16_(0x1) << DMAC_INTPEND_TERR_Pos)             /* (DMAC_INTPEND) Transfer Error Mask */
#define DMAC_INTPEND_TERR(value)              (DMAC_INTPEND_TERR_Msk & (_UINT16_(value) << DMAC_INTPEND_TERR_Pos)) /* Assigment of value for TERR in the DMAC_INTPEND register */
#define DMAC_INTPEND_TCMPL_Pos                _UINT16_(9)                                          /* (DMAC_INTPEND) Transfer Complete Position */
#define DMAC_INTPEND_TCMPL_Msk                (_UINT16_(0x1) << DMAC_INTPEND_TCMPL_Pos)            /* (DMAC_INTPEND) Transfer Complete Mask */
#define DMAC_INTPEND_TCMPL(value)             (DMAC_INTPEND_TCMPL_Msk & (_UINT16_(value) << DMAC_INTPEND_TCMPL_Pos)) /* Assigment of value for TCMPL in the DMAC_INTPEND register */
#define DMAC_INTPEND_SUSP_Pos                 _UINT16_(10)                                         /* (DMAC_INTPEND) Channel Suspend Position */
#define DMAC_INTPEND_SUSP_Msk                 (_UINT16_(0x1) << DMAC_INTPEND_SUSP_Pos)             /* (DMAC_INTPEND) Channel Suspend Mask */
#define DMAC_INTPEND_SUSP(value)              (DMAC_INTPEND_SUSP_Msk & (_UINT16_(value) << DMAC_INTPEND_SUSP_Pos)) /* Assigment of value for SUSP in the DMAC_INTPEND register */
#define DMAC_INTPEND_FERR_Pos                 _UINT16_(13)                                         /* (DMAC_INTPEND) Fetch Error Position */
#define DMAC_INTPEND_FERR_Msk                 (_UINT16_(0x1) << DMAC_INTPEND_FERR_Pos)             /* (DMAC_INTPEND) Fetch Error Mask */
#define DMAC_INTPEND_FERR(value)              (DMAC_INTPEND_FERR_Msk & (_UINT16_(value) << DMAC_INTPEND_FERR_Pos)) /* Assigment of value for FERR in the DMAC_INTPEND register */
#define DMAC_INTPEND_BUSY_Pos                 _UINT16_(14)                                         /* (DMAC_INTPEND) Busy Position */
#define DMAC_INTPEND_BUSY_Msk                 (_UINT16_(0x1) << DMAC_INTPEND_BUSY_Pos)             /* (DMAC_INTPEND) Busy Mask */
#define DMAC_INTPEND_BUSY(value)              (DMAC_INTPEND_BUSY_Msk & (_UINT16_(value) << DMAC_INTPEND_BUSY_Pos)) /* Assigment of value for BUSY in the DMAC_INTPEND register */
#define DMAC_INTPEND_PEND_Pos                 _UINT16_(15)                                         /* (DMAC_INTPEND) Pending Position */
#define DMAC_INTPEND_PEND_Msk                 (_UINT16_(0x1) << DMAC_INTPEND_PEND_Pos)             /* (DMAC_INTPEND) Pending Mask */
#define DMAC_INTPEND_PEND(value)              (DMAC_INTPEND_PEND_Msk & (_UINT16_(value) << DMAC_INTPEND_PEND_Pos)) /* Assigment of value for PEND in the DMAC_INTPEND register */
#define DMAC_INTPEND_Msk                      _UINT16_(0xE70F)                                     /* (DMAC_INTPEND) Register Mask  */


/* -------- DMAC_INTSTATUS : (DMAC Offset: 0x24) ( R/ 32) Interrupt Status -------- */
#define DMAC_INTSTATUS_RESETVALUE             _UINT32_(0x00)                                       /*  (DMAC_INTSTATUS) Interrupt Status  Reset Value */

#define DMAC_INTSTATUS_CHINT0_Pos             _UINT32_(0)                                          /* (DMAC_INTSTATUS) Channel 0 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT0_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT0_Pos)         /* (DMAC_INTSTATUS) Channel 0 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT0(value)          (DMAC_INTSTATUS_CHINT0_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT0_Pos)) /* Assigment of value for CHINT0 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT1_Pos             _UINT32_(1)                                          /* (DMAC_INTSTATUS) Channel 1 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT1_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT1_Pos)         /* (DMAC_INTSTATUS) Channel 1 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT1(value)          (DMAC_INTSTATUS_CHINT1_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT1_Pos)) /* Assigment of value for CHINT1 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT2_Pos             _UINT32_(2)                                          /* (DMAC_INTSTATUS) Channel 2 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT2_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT2_Pos)         /* (DMAC_INTSTATUS) Channel 2 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT2(value)          (DMAC_INTSTATUS_CHINT2_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT2_Pos)) /* Assigment of value for CHINT2 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT3_Pos             _UINT32_(3)                                          /* (DMAC_INTSTATUS) Channel 3 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT3_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT3_Pos)         /* (DMAC_INTSTATUS) Channel 3 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT3(value)          (DMAC_INTSTATUS_CHINT3_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT3_Pos)) /* Assigment of value for CHINT3 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT4_Pos             _UINT32_(4)                                          /* (DMAC_INTSTATUS) Channel 4 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT4_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT4_Pos)         /* (DMAC_INTSTATUS) Channel 4 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT4(value)          (DMAC_INTSTATUS_CHINT4_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT4_Pos)) /* Assigment of value for CHINT4 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT5_Pos             _UINT32_(5)                                          /* (DMAC_INTSTATUS) Channel 5 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT5_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT5_Pos)         /* (DMAC_INTSTATUS) Channel 5 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT5(value)          (DMAC_INTSTATUS_CHINT5_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT5_Pos)) /* Assigment of value for CHINT5 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT6_Pos             _UINT32_(6)                                          /* (DMAC_INTSTATUS) Channel 6 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT6_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT6_Pos)         /* (DMAC_INTSTATUS) Channel 6 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT6(value)          (DMAC_INTSTATUS_CHINT6_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT6_Pos)) /* Assigment of value for CHINT6 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT7_Pos             _UINT32_(7)                                          /* (DMAC_INTSTATUS) Channel 7 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT7_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT7_Pos)         /* (DMAC_INTSTATUS) Channel 7 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT7(value)          (DMAC_INTSTATUS_CHINT7_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT7_Pos)) /* Assigment of value for CHINT7 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT8_Pos             _UINT32_(8)                                          /* (DMAC_INTSTATUS) Channel 8 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT8_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT8_Pos)         /* (DMAC_INTSTATUS) Channel 8 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT8(value)          (DMAC_INTSTATUS_CHINT8_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT8_Pos)) /* Assigment of value for CHINT8 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT9_Pos             _UINT32_(9)                                          /* (DMAC_INTSTATUS) Channel 9 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT9_Msk             (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT9_Pos)         /* (DMAC_INTSTATUS) Channel 9 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT9(value)          (DMAC_INTSTATUS_CHINT9_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT9_Pos)) /* Assigment of value for CHINT9 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT10_Pos            _UINT32_(10)                                         /* (DMAC_INTSTATUS) Channel 10 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT10_Msk            (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT10_Pos)        /* (DMAC_INTSTATUS) Channel 10 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT10(value)         (DMAC_INTSTATUS_CHINT10_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT10_Pos)) /* Assigment of value for CHINT10 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT11_Pos            _UINT32_(11)                                         /* (DMAC_INTSTATUS) Channel 11 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT11_Msk            (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT11_Pos)        /* (DMAC_INTSTATUS) Channel 11 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT11(value)         (DMAC_INTSTATUS_CHINT11_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT11_Pos)) /* Assigment of value for CHINT11 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT12_Pos            _UINT32_(12)                                         /* (DMAC_INTSTATUS) Channel 12 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT12_Msk            (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT12_Pos)        /* (DMAC_INTSTATUS) Channel 12 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT12(value)         (DMAC_INTSTATUS_CHINT12_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT12_Pos)) /* Assigment of value for CHINT12 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT13_Pos            _UINT32_(13)                                         /* (DMAC_INTSTATUS) Channel 13 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT13_Msk            (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT13_Pos)        /* (DMAC_INTSTATUS) Channel 13 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT13(value)         (DMAC_INTSTATUS_CHINT13_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT13_Pos)) /* Assigment of value for CHINT13 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT14_Pos            _UINT32_(14)                                         /* (DMAC_INTSTATUS) Channel 14 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT14_Msk            (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT14_Pos)        /* (DMAC_INTSTATUS) Channel 14 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT14(value)         (DMAC_INTSTATUS_CHINT14_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT14_Pos)) /* Assigment of value for CHINT14 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_CHINT15_Pos            _UINT32_(15)                                         /* (DMAC_INTSTATUS) Channel 15 Pending Interrupt Position */
#define DMAC_INTSTATUS_CHINT15_Msk            (_UINT32_(0x1) << DMAC_INTSTATUS_CHINT15_Pos)        /* (DMAC_INTSTATUS) Channel 15 Pending Interrupt Mask */
#define DMAC_INTSTATUS_CHINT15(value)         (DMAC_INTSTATUS_CHINT15_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT15_Pos)) /* Assigment of value for CHINT15 in the DMAC_INTSTATUS register */
#define DMAC_INTSTATUS_Msk                    _UINT32_(0x0000FFFF)                                 /* (DMAC_INTSTATUS) Register Mask  */

#define DMAC_INTSTATUS_CHINT_Pos              _UINT32_(0)                                          /* (DMAC_INTSTATUS Position) Channel x5 Pending Interrupt */
#define DMAC_INTSTATUS_CHINT_Msk              (_UINT32_(0xFFFF) << DMAC_INTSTATUS_CHINT_Pos)       /* (DMAC_INTSTATUS Mask) CHINT */
#define DMAC_INTSTATUS_CHINT(value)           (DMAC_INTSTATUS_CHINT_Msk & (_UINT32_(value) << DMAC_INTSTATUS_CHINT_Pos)) 

/* -------- DMAC_BUSYCH : (DMAC Offset: 0x28) ( R/ 32) Busy Channels -------- */
#define DMAC_BUSYCH_RESETVALUE                _UINT32_(0x00)                                       /*  (DMAC_BUSYCH) Busy Channels  Reset Value */

#define DMAC_BUSYCH_BUSYCH0_Pos               _UINT32_(0)                                          /* (DMAC_BUSYCH) Busy Channel 0 Position */
#define DMAC_BUSYCH_BUSYCH0_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH0_Pos)           /* (DMAC_BUSYCH) Busy Channel 0 Mask */
#define DMAC_BUSYCH_BUSYCH0(value)            (DMAC_BUSYCH_BUSYCH0_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH0_Pos)) /* Assigment of value for BUSYCH0 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH1_Pos               _UINT32_(1)                                          /* (DMAC_BUSYCH) Busy Channel 1 Position */
#define DMAC_BUSYCH_BUSYCH1_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH1_Pos)           /* (DMAC_BUSYCH) Busy Channel 1 Mask */
#define DMAC_BUSYCH_BUSYCH1(value)            (DMAC_BUSYCH_BUSYCH1_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH1_Pos)) /* Assigment of value for BUSYCH1 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH2_Pos               _UINT32_(2)                                          /* (DMAC_BUSYCH) Busy Channel 2 Position */
#define DMAC_BUSYCH_BUSYCH2_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH2_Pos)           /* (DMAC_BUSYCH) Busy Channel 2 Mask */
#define DMAC_BUSYCH_BUSYCH2(value)            (DMAC_BUSYCH_BUSYCH2_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH2_Pos)) /* Assigment of value for BUSYCH2 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH3_Pos               _UINT32_(3)                                          /* (DMAC_BUSYCH) Busy Channel 3 Position */
#define DMAC_BUSYCH_BUSYCH3_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH3_Pos)           /* (DMAC_BUSYCH) Busy Channel 3 Mask */
#define DMAC_BUSYCH_BUSYCH3(value)            (DMAC_BUSYCH_BUSYCH3_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH3_Pos)) /* Assigment of value for BUSYCH3 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH4_Pos               _UINT32_(4)                                          /* (DMAC_BUSYCH) Busy Channel 4 Position */
#define DMAC_BUSYCH_BUSYCH4_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH4_Pos)           /* (DMAC_BUSYCH) Busy Channel 4 Mask */
#define DMAC_BUSYCH_BUSYCH4(value)            (DMAC_BUSYCH_BUSYCH4_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH4_Pos)) /* Assigment of value for BUSYCH4 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH5_Pos               _UINT32_(5)                                          /* (DMAC_BUSYCH) Busy Channel 5 Position */
#define DMAC_BUSYCH_BUSYCH5_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH5_Pos)           /* (DMAC_BUSYCH) Busy Channel 5 Mask */
#define DMAC_BUSYCH_BUSYCH5(value)            (DMAC_BUSYCH_BUSYCH5_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH5_Pos)) /* Assigment of value for BUSYCH5 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH6_Pos               _UINT32_(6)                                          /* (DMAC_BUSYCH) Busy Channel 6 Position */
#define DMAC_BUSYCH_BUSYCH6_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH6_Pos)           /* (DMAC_BUSYCH) Busy Channel 6 Mask */
#define DMAC_BUSYCH_BUSYCH6(value)            (DMAC_BUSYCH_BUSYCH6_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH6_Pos)) /* Assigment of value for BUSYCH6 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH7_Pos               _UINT32_(7)                                          /* (DMAC_BUSYCH) Busy Channel 7 Position */
#define DMAC_BUSYCH_BUSYCH7_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH7_Pos)           /* (DMAC_BUSYCH) Busy Channel 7 Mask */
#define DMAC_BUSYCH_BUSYCH7(value)            (DMAC_BUSYCH_BUSYCH7_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH7_Pos)) /* Assigment of value for BUSYCH7 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH8_Pos               _UINT32_(8)                                          /* (DMAC_BUSYCH) Busy Channel 8 Position */
#define DMAC_BUSYCH_BUSYCH8_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH8_Pos)           /* (DMAC_BUSYCH) Busy Channel 8 Mask */
#define DMAC_BUSYCH_BUSYCH8(value)            (DMAC_BUSYCH_BUSYCH8_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH8_Pos)) /* Assigment of value for BUSYCH8 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH9_Pos               _UINT32_(9)                                          /* (DMAC_BUSYCH) Busy Channel 9 Position */
#define DMAC_BUSYCH_BUSYCH9_Msk               (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH9_Pos)           /* (DMAC_BUSYCH) Busy Channel 9 Mask */
#define DMAC_BUSYCH_BUSYCH9(value)            (DMAC_BUSYCH_BUSYCH9_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH9_Pos)) /* Assigment of value for BUSYCH9 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH10_Pos              _UINT32_(10)                                         /* (DMAC_BUSYCH) Busy Channel 10 Position */
#define DMAC_BUSYCH_BUSYCH10_Msk              (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH10_Pos)          /* (DMAC_BUSYCH) Busy Channel 10 Mask */
#define DMAC_BUSYCH_BUSYCH10(value)           (DMAC_BUSYCH_BUSYCH10_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH10_Pos)) /* Assigment of value for BUSYCH10 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH11_Pos              _UINT32_(11)                                         /* (DMAC_BUSYCH) Busy Channel 11 Position */
#define DMAC_BUSYCH_BUSYCH11_Msk              (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH11_Pos)          /* (DMAC_BUSYCH) Busy Channel 11 Mask */
#define DMAC_BUSYCH_BUSYCH11(value)           (DMAC_BUSYCH_BUSYCH11_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH11_Pos)) /* Assigment of value for BUSYCH11 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH12_Pos              _UINT32_(12)                                         /* (DMAC_BUSYCH) Busy Channel 12 Position */
#define DMAC_BUSYCH_BUSYCH12_Msk              (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH12_Pos)          /* (DMAC_BUSYCH) Busy Channel 12 Mask */
#define DMAC_BUSYCH_BUSYCH12(value)           (DMAC_BUSYCH_BUSYCH12_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH12_Pos)) /* Assigment of value for BUSYCH12 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH13_Pos              _UINT32_(13)                                         /* (DMAC_BUSYCH) Busy Channel 13 Position */
#define DMAC_BUSYCH_BUSYCH13_Msk              (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH13_Pos)          /* (DMAC_BUSYCH) Busy Channel 13 Mask */
#define DMAC_BUSYCH_BUSYCH13(value)           (DMAC_BUSYCH_BUSYCH13_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH13_Pos)) /* Assigment of value for BUSYCH13 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH14_Pos              _UINT32_(14)                                         /* (DMAC_BUSYCH) Busy Channel 14 Position */
#define DMAC_BUSYCH_BUSYCH14_Msk              (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH14_Pos)          /* (DMAC_BUSYCH) Busy Channel 14 Mask */
#define DMAC_BUSYCH_BUSYCH14(value)           (DMAC_BUSYCH_BUSYCH14_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH14_Pos)) /* Assigment of value for BUSYCH14 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_BUSYCH15_Pos              _UINT32_(15)                                         /* (DMAC_BUSYCH) Busy Channel 15 Position */
#define DMAC_BUSYCH_BUSYCH15_Msk              (_UINT32_(0x1) << DMAC_BUSYCH_BUSYCH15_Pos)          /* (DMAC_BUSYCH) Busy Channel 15 Mask */
#define DMAC_BUSYCH_BUSYCH15(value)           (DMAC_BUSYCH_BUSYCH15_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH15_Pos)) /* Assigment of value for BUSYCH15 in the DMAC_BUSYCH register */
#define DMAC_BUSYCH_Msk                       _UINT32_(0x0000FFFF)                                 /* (DMAC_BUSYCH) Register Mask  */

#define DMAC_BUSYCH_BUSYCH_Pos                _UINT32_(0)                                          /* (DMAC_BUSYCH Position) Busy Channel x5 */
#define DMAC_BUSYCH_BUSYCH_Msk                (_UINT32_(0xFFFF) << DMAC_BUSYCH_BUSYCH_Pos)         /* (DMAC_BUSYCH Mask) BUSYCH */
#define DMAC_BUSYCH_BUSYCH(value)             (DMAC_BUSYCH_BUSYCH_Msk & (_UINT32_(value) << DMAC_BUSYCH_BUSYCH_Pos)) 

/* -------- DMAC_PENDCH : (DMAC Offset: 0x2C) ( R/ 32) Pending Channels -------- */
#define DMAC_PENDCH_RESETVALUE                _UINT32_(0x00)                                       /*  (DMAC_PENDCH) Pending Channels  Reset Value */

#define DMAC_PENDCH_PENDCH0_Pos               _UINT32_(0)                                          /* (DMAC_PENDCH) Pending Channel 0 Position */
#define DMAC_PENDCH_PENDCH0_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH0_Pos)           /* (DMAC_PENDCH) Pending Channel 0 Mask */
#define DMAC_PENDCH_PENDCH0(value)            (DMAC_PENDCH_PENDCH0_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH0_Pos)) /* Assigment of value for PENDCH0 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH1_Pos               _UINT32_(1)                                          /* (DMAC_PENDCH) Pending Channel 1 Position */
#define DMAC_PENDCH_PENDCH1_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH1_Pos)           /* (DMAC_PENDCH) Pending Channel 1 Mask */
#define DMAC_PENDCH_PENDCH1(value)            (DMAC_PENDCH_PENDCH1_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH1_Pos)) /* Assigment of value for PENDCH1 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH2_Pos               _UINT32_(2)                                          /* (DMAC_PENDCH) Pending Channel 2 Position */
#define DMAC_PENDCH_PENDCH2_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH2_Pos)           /* (DMAC_PENDCH) Pending Channel 2 Mask */
#define DMAC_PENDCH_PENDCH2(value)            (DMAC_PENDCH_PENDCH2_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH2_Pos)) /* Assigment of value for PENDCH2 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH3_Pos               _UINT32_(3)                                          /* (DMAC_PENDCH) Pending Channel 3 Position */
#define DMAC_PENDCH_PENDCH3_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH3_Pos)           /* (DMAC_PENDCH) Pending Channel 3 Mask */
#define DMAC_PENDCH_PENDCH3(value)            (DMAC_PENDCH_PENDCH3_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH3_Pos)) /* Assigment of value for PENDCH3 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH4_Pos               _UINT32_(4)                                          /* (DMAC_PENDCH) Pending Channel 4 Position */
#define DMAC_PENDCH_PENDCH4_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH4_Pos)           /* (DMAC_PENDCH) Pending Channel 4 Mask */
#define DMAC_PENDCH_PENDCH4(value)            (DMAC_PENDCH_PENDCH4_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH4_Pos)) /* Assigment of value for PENDCH4 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH5_Pos               _UINT32_(5)                                          /* (DMAC_PENDCH) Pending Channel 5 Position */
#define DMAC_PENDCH_PENDCH5_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH5_Pos)           /* (DMAC_PENDCH) Pending Channel 5 Mask */
#define DMAC_PENDCH_PENDCH5(value)            (DMAC_PENDCH_PENDCH5_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH5_Pos)) /* Assigment of value for PENDCH5 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH6_Pos               _UINT32_(6)                                          /* (DMAC_PENDCH) Pending Channel 6 Position */
#define DMAC_PENDCH_PENDCH6_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH6_Pos)           /* (DMAC_PENDCH) Pending Channel 6 Mask */
#define DMAC_PENDCH_PENDCH6(value)            (DMAC_PENDCH_PENDCH6_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH6_Pos)) /* Assigment of value for PENDCH6 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH7_Pos               _UINT32_(7)                                          /* (DMAC_PENDCH) Pending Channel 7 Position */
#define DMAC_PENDCH_PENDCH7_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH7_Pos)           /* (DMAC_PENDCH) Pending Channel 7 Mask */
#define DMAC_PENDCH_PENDCH7(value)            (DMAC_PENDCH_PENDCH7_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH7_Pos)) /* Assigment of value for PENDCH7 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH8_Pos               _UINT32_(8)                                          /* (DMAC_PENDCH) Pending Channel 8 Position */
#define DMAC_PENDCH_PENDCH8_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH8_Pos)           /* (DMAC_PENDCH) Pending Channel 8 Mask */
#define DMAC_PENDCH_PENDCH8(value)            (DMAC_PENDCH_PENDCH8_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH8_Pos)) /* Assigment of value for PENDCH8 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH9_Pos               _UINT32_(9)                                          /* (DMAC_PENDCH) Pending Channel 9 Position */
#define DMAC_PENDCH_PENDCH9_Msk               (_UINT32_(0x1) << DMAC_PENDCH_PENDCH9_Pos)           /* (DMAC_PENDCH) Pending Channel 9 Mask */
#define DMAC_PENDCH_PENDCH9(value)            (DMAC_PENDCH_PENDCH9_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH9_Pos)) /* Assigment of value for PENDCH9 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH10_Pos              _UINT32_(10)                                         /* (DMAC_PENDCH) Pending Channel 10 Position */
#define DMAC_PENDCH_PENDCH10_Msk              (_UINT32_(0x1) << DMAC_PENDCH_PENDCH10_Pos)          /* (DMAC_PENDCH) Pending Channel 10 Mask */
#define DMAC_PENDCH_PENDCH10(value)           (DMAC_PENDCH_PENDCH10_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH10_Pos)) /* Assigment of value for PENDCH10 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH11_Pos              _UINT32_(11)                                         /* (DMAC_PENDCH) Pending Channel 11 Position */
#define DMAC_PENDCH_PENDCH11_Msk              (_UINT32_(0x1) << DMAC_PENDCH_PENDCH11_Pos)          /* (DMAC_PENDCH) Pending Channel 11 Mask */
#define DMAC_PENDCH_PENDCH11(value)           (DMAC_PENDCH_PENDCH11_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH11_Pos)) /* Assigment of value for PENDCH11 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH12_Pos              _UINT32_(12)                                         /* (DMAC_PENDCH) Pending Channel 12 Position */
#define DMAC_PENDCH_PENDCH12_Msk              (_UINT32_(0x1) << DMAC_PENDCH_PENDCH12_Pos)          /* (DMAC_PENDCH) Pending Channel 12 Mask */
#define DMAC_PENDCH_PENDCH12(value)           (DMAC_PENDCH_PENDCH12_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH12_Pos)) /* Assigment of value for PENDCH12 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH13_Pos              _UINT32_(13)                                         /* (DMAC_PENDCH) Pending Channel 13 Position */
#define DMAC_PENDCH_PENDCH13_Msk              (_UINT32_(0x1) << DMAC_PENDCH_PENDCH13_Pos)          /* (DMAC_PENDCH) Pending Channel 13 Mask */
#define DMAC_PENDCH_PENDCH13(value)           (DMAC_PENDCH_PENDCH13_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH13_Pos)) /* Assigment of value for PENDCH13 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH14_Pos              _UINT32_(14)                                         /* (DMAC_PENDCH) Pending Channel 14 Position */
#define DMAC_PENDCH_PENDCH14_Msk              (_UINT32_(0x1) << DMAC_PENDCH_PENDCH14_Pos)          /* (DMAC_PENDCH) Pending Channel 14 Mask */
#define DMAC_PENDCH_PENDCH14(value)           (DMAC_PENDCH_PENDCH14_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH14_Pos)) /* Assigment of value for PENDCH14 in the DMAC_PENDCH register */
#define DMAC_PENDCH_PENDCH15_Pos              _UINT32_(15)                                         /* (DMAC_PENDCH) Pending Channel 15 Position */
#define DMAC_PENDCH_PENDCH15_Msk              (_UINT32_(0x1) << DMAC_PENDCH_PENDCH15_Pos)          /* (DMAC_PENDCH) Pending Channel 15 Mask */
#define DMAC_PENDCH_PENDCH15(value)           (DMAC_PENDCH_PENDCH15_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH15_Pos)) /* Assigment of value for PENDCH15 in the DMAC_PENDCH register */
#define DMAC_PENDCH_Msk                       _UINT32_(0x0000FFFF)                                 /* (DMAC_PENDCH) Register Mask  */

#define DMAC_PENDCH_PENDCH_Pos                _UINT32_(0)                                          /* (DMAC_PENDCH Position) Pending Channel x5 */
#define DMAC_PENDCH_PENDCH_Msk                (_UINT32_(0xFFFF) << DMAC_PENDCH_PENDCH_Pos)         /* (DMAC_PENDCH Mask) PENDCH */
#define DMAC_PENDCH_PENDCH(value)             (DMAC_PENDCH_PENDCH_Msk & (_UINT32_(value) << DMAC_PENDCH_PENDCH_Pos)) 

/* -------- DMAC_ACTIVE : (DMAC Offset: 0x30) ( R/ 32) Active Channel and Levels -------- */
#define DMAC_ACTIVE_RESETVALUE                _UINT32_(0x00)                                       /*  (DMAC_ACTIVE) Active Channel and Levels  Reset Value */

#define DMAC_ACTIVE_LVLEX0_Pos                _UINT32_(0)                                          /* (DMAC_ACTIVE) Level 0 Channel Trigger Request Executing Position */
#define DMAC_ACTIVE_LVLEX0_Msk                (_UINT32_(0x1) << DMAC_ACTIVE_LVLEX0_Pos)            /* (DMAC_ACTIVE) Level 0 Channel Trigger Request Executing Mask */
#define DMAC_ACTIVE_LVLEX0(value)             (DMAC_ACTIVE_LVLEX0_Msk & (_UINT32_(value) << DMAC_ACTIVE_LVLEX0_Pos)) /* Assigment of value for LVLEX0 in the DMAC_ACTIVE register */
#define DMAC_ACTIVE_LVLEX1_Pos                _UINT32_(1)                                          /* (DMAC_ACTIVE) Level 1 Channel Trigger Request Executing Position */
#define DMAC_ACTIVE_LVLEX1_Msk                (_UINT32_(0x1) << DMAC_ACTIVE_LVLEX1_Pos)            /* (DMAC_ACTIVE) Level 1 Channel Trigger Request Executing Mask */
#define DMAC_ACTIVE_LVLEX1(value)             (DMAC_ACTIVE_LVLEX1_Msk & (_UINT32_(value) << DMAC_ACTIVE_LVLEX1_Pos)) /* Assigment of value for LVLEX1 in the DMAC_ACTIVE register */
#define DMAC_ACTIVE_LVLEX2_Pos                _UINT32_(2)                                          /* (DMAC_ACTIVE) Level 2 Channel Trigger Request Executing Position */
#define DMAC_ACTIVE_LVLEX2_Msk                (_UINT32_(0x1) << DMAC_ACTIVE_LVLEX2_Pos)            /* (DMAC_ACTIVE) Level 2 Channel Trigger Request Executing Mask */
#define DMAC_ACTIVE_LVLEX2(value)             (DMAC_ACTIVE_LVLEX2_Msk & (_UINT32_(value) << DMAC_ACTIVE_LVLEX2_Pos)) /* Assigment of value for LVLEX2 in the DMAC_ACTIVE register */
#define DMAC_ACTIVE_LVLEX3_Pos                _UINT32_(3)                                          /* (DMAC_ACTIVE) Level 3 Channel Trigger Request Executing Position */
#define DMAC_ACTIVE_LVLEX3_Msk                (_UINT32_(0x1) << DMAC_ACTIVE_LVLEX3_Pos)            /* (DMAC_ACTIVE) Level 3 Channel Trigger Request Executing Mask */
#define DMAC_ACTIVE_LVLEX3(value)             (DMAC_ACTIVE_LVLEX3_Msk & (_UINT32_(value) << DMAC_ACTIVE_LVLEX3_Pos)) /* Assigment of value for LVLEX3 in the DMAC_ACTIVE register */
#define DMAC_ACTIVE_ID_Pos                    _UINT32_(8)                                          /* (DMAC_ACTIVE) Active Channel ID Position */
#define DMAC_ACTIVE_ID_Msk                    (_UINT32_(0x1F) << DMAC_ACTIVE_ID_Pos)               /* (DMAC_ACTIVE) Active Channel ID Mask */
#define DMAC_ACTIVE_ID(value)                 (DMAC_ACTIVE_ID_Msk & (_UINT32_(value) << DMAC_ACTIVE_ID_Pos)) /* Assigment of value for ID in the DMAC_ACTIVE register */
#define DMAC_ACTIVE_ABUSY_Pos                 _UINT32_(15)                                         /* (DMAC_ACTIVE) Active Channel Busy Position */
#define DMAC_ACTIVE_ABUSY_Msk                 (_UINT32_(0x1) << DMAC_ACTIVE_ABUSY_Pos)             /* (DMAC_ACTIVE) Active Channel Busy Mask */
#define DMAC_ACTIVE_ABUSY(value)              (DMAC_ACTIVE_ABUSY_Msk & (_UINT32_(value) << DMAC_ACTIVE_ABUSY_Pos)) /* Assigment of value for ABUSY in the DMAC_ACTIVE register */
#define DMAC_ACTIVE_BTCNT_Pos                 _UINT32_(16)                                         /* (DMAC_ACTIVE) Active Channel Block Transfer Count Position */
#define DMAC_ACTIVE_BTCNT_Msk                 (_UINT32_(0xFFFF) << DMAC_ACTIVE_BTCNT_Pos)          /* (DMAC_ACTIVE) Active Channel Block Transfer Count Mask */
#define DMAC_ACTIVE_BTCNT(value)              (DMAC_ACTIVE_BTCNT_Msk & (_UINT32_(value) << DMAC_ACTIVE_BTCNT_Pos)) /* Assigment of value for BTCNT in the DMAC_ACTIVE register */
#define DMAC_ACTIVE_Msk                       _UINT32_(0xFFFF9F0F)                                 /* (DMAC_ACTIVE) Register Mask  */

#define DMAC_ACTIVE_LVLEX_Pos                 _UINT32_(0)                                          /* (DMAC_ACTIVE Position) Level x Channel Trigger Request Executing */
#define DMAC_ACTIVE_LVLEX_Msk                 (_UINT32_(0xF) << DMAC_ACTIVE_LVLEX_Pos)             /* (DMAC_ACTIVE Mask) LVLEX */
#define DMAC_ACTIVE_LVLEX(value)              (DMAC_ACTIVE_LVLEX_Msk & (_UINT32_(value) << DMAC_ACTIVE_LVLEX_Pos)) 

/* -------- DMAC_BASEADDR : (DMAC Offset: 0x34) (R/W 32) Descriptor Memory Section Base Address -------- */
#define DMAC_BASEADDR_RESETVALUE              _UINT32_(0x00)                                       /*  (DMAC_BASEADDR) Descriptor Memory Section Base Address  Reset Value */

#define DMAC_BASEADDR_BASEADDR_Pos            _UINT32_(0)                                          /* (DMAC_BASEADDR) Descriptor Memory Base Address Position */
#define DMAC_BASEADDR_BASEADDR_Msk            (_UINT32_(0xFFFFFFFF) << DMAC_BASEADDR_BASEADDR_Pos) /* (DMAC_BASEADDR) Descriptor Memory Base Address Mask */
#define DMAC_BASEADDR_BASEADDR(value)         (DMAC_BASEADDR_BASEADDR_Msk & (_UINT32_(value) << DMAC_BASEADDR_BASEADDR_Pos)) /* Assigment of value for BASEADDR in the DMAC_BASEADDR register */
#define DMAC_BASEADDR_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (DMAC_BASEADDR) Register Mask  */


/* -------- DMAC_WRBADDR : (DMAC Offset: 0x38) (R/W 32) Write-Back Memory Section Base Address -------- */
#define DMAC_WRBADDR_RESETVALUE               _UINT32_(0x00)                                       /*  (DMAC_WRBADDR) Write-Back Memory Section Base Address  Reset Value */

#define DMAC_WRBADDR_WRBADDR_Pos              _UINT32_(0)                                          /* (DMAC_WRBADDR) Write-Back Memory Base Address Position */
#define DMAC_WRBADDR_WRBADDR_Msk              (_UINT32_(0xFFFFFFFF) << DMAC_WRBADDR_WRBADDR_Pos)   /* (DMAC_WRBADDR) Write-Back Memory Base Address Mask */
#define DMAC_WRBADDR_WRBADDR(value)           (DMAC_WRBADDR_WRBADDR_Msk & (_UINT32_(value) << DMAC_WRBADDR_WRBADDR_Pos)) /* Assigment of value for WRBADDR in the DMAC_WRBADDR register */
#define DMAC_WRBADDR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (DMAC_WRBADDR) Register Mask  */


/* -------- DMAC_CHID : (DMAC Offset: 0x3F) (R/W 8) Channel ID -------- */
#define DMAC_CHID_RESETVALUE                  _UINT8_(0x00)                                        /*  (DMAC_CHID) Channel ID  Reset Value */

#define DMAC_CHID_ID_Pos                      _UINT8_(0)                                           /* (DMAC_CHID) Channel ID Position */
#define DMAC_CHID_ID_Msk                      (_UINT8_(0xF) << DMAC_CHID_ID_Pos)                   /* (DMAC_CHID) Channel ID Mask */
#define DMAC_CHID_ID(value)                   (DMAC_CHID_ID_Msk & (_UINT8_(value) << DMAC_CHID_ID_Pos)) /* Assigment of value for ID in the DMAC_CHID register */
#define DMAC_CHID_Msk                         _UINT8_(0x0F)                                        /* (DMAC_CHID) Register Mask  */


/* -------- DMAC_CHCTRLA : (DMAC Offset: 0x40) (R/W 8) Channel Control A -------- */
#define DMAC_CHCTRLA_RESETVALUE               _UINT8_(0x00)                                        /*  (DMAC_CHCTRLA) Channel Control A  Reset Value */

#define DMAC_CHCTRLA_SWRST_Pos                _UINT8_(0)                                           /* (DMAC_CHCTRLA) Channel Software Reset Position */
#define DMAC_CHCTRLA_SWRST_Msk                (_UINT8_(0x1) << DMAC_CHCTRLA_SWRST_Pos)             /* (DMAC_CHCTRLA) Channel Software Reset Mask */
#define DMAC_CHCTRLA_SWRST(value)             (DMAC_CHCTRLA_SWRST_Msk & (_UINT8_(value) << DMAC_CHCTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the DMAC_CHCTRLA register */
#define DMAC_CHCTRLA_ENABLE_Pos               _UINT8_(1)                                           /* (DMAC_CHCTRLA) Channel Enable Position */
#define DMAC_CHCTRLA_ENABLE_Msk               (_UINT8_(0x1) << DMAC_CHCTRLA_ENABLE_Pos)            /* (DMAC_CHCTRLA) Channel Enable Mask */
#define DMAC_CHCTRLA_ENABLE(value)            (DMAC_CHCTRLA_ENABLE_Msk & (_UINT8_(value) << DMAC_CHCTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the DMAC_CHCTRLA register */
#define DMAC_CHCTRLA_RUNSTDBY_Pos             _UINT8_(6)                                           /* (DMAC_CHCTRLA) Channel run in standby Position */
#define DMAC_CHCTRLA_RUNSTDBY_Msk             (_UINT8_(0x1) << DMAC_CHCTRLA_RUNSTDBY_Pos)          /* (DMAC_CHCTRLA) Channel run in standby Mask */
#define DMAC_CHCTRLA_RUNSTDBY(value)          (DMAC_CHCTRLA_RUNSTDBY_Msk & (_UINT8_(value) << DMAC_CHCTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the DMAC_CHCTRLA register */
#define DMAC_CHCTRLA_Msk                      _UINT8_(0x43)                                        /* (DMAC_CHCTRLA) Register Mask  */


/* -------- DMAC_CHCTRLB : (DMAC Offset: 0x44) (R/W 32) Channel Control B -------- */
#define DMAC_CHCTRLB_RESETVALUE               _UINT32_(0x00)                                       /*  (DMAC_CHCTRLB) Channel Control B  Reset Value */

#define DMAC_CHCTRLB_EVACT_Pos                _UINT32_(0)                                          /* (DMAC_CHCTRLB) Event Input Action Position */
#define DMAC_CHCTRLB_EVACT_Msk                (_UINT32_(0x7) << DMAC_CHCTRLB_EVACT_Pos)            /* (DMAC_CHCTRLB) Event Input Action Mask */
#define DMAC_CHCTRLB_EVACT(value)             (DMAC_CHCTRLB_EVACT_Msk & (_UINT32_(value) << DMAC_CHCTRLB_EVACT_Pos)) /* Assigment of value for EVACT in the DMAC_CHCTRLB register */
#define   DMAC_CHCTRLB_EVACT_NOACT_Val        _UINT32_(0x0)                                        /* (DMAC_CHCTRLB) No action  */
#define   DMAC_CHCTRLB_EVACT_TRIG_Val         _UINT32_(0x1)                                        /* (DMAC_CHCTRLB) Transfer and periodic transfer trigger  */
#define   DMAC_CHCTRLB_EVACT_CTRIG_Val        _UINT32_(0x2)                                        /* (DMAC_CHCTRLB) Conditional transfer trigger  */
#define   DMAC_CHCTRLB_EVACT_CBLOCK_Val       _UINT32_(0x3)                                        /* (DMAC_CHCTRLB) Conditional block transfer  */
#define   DMAC_CHCTRLB_EVACT_SUSPEND_Val      _UINT32_(0x4)                                        /* (DMAC_CHCTRLB) Channel suspend operation  */
#define   DMAC_CHCTRLB_EVACT_RESUME_Val       _UINT32_(0x5)                                        /* (DMAC_CHCTRLB) Channel resume operation  */
#define   DMAC_CHCTRLB_EVACT_SSKIP_Val        _UINT32_(0x6)                                        /* (DMAC_CHCTRLB) Skip next block suspend action  */
#define DMAC_CHCTRLB_EVACT_NOACT              (DMAC_CHCTRLB_EVACT_NOACT_Val << DMAC_CHCTRLB_EVACT_Pos) /* (DMAC_CHCTRLB) No action Position  */
#define DMAC_CHCTRLB_EVACT_TRIG               (DMAC_CHCTRLB_EVACT_TRIG_Val << DMAC_CHCTRLB_EVACT_Pos) /* (DMAC_CHCTRLB) Transfer and periodic transfer trigger Position  */
#define DMAC_CHCTRLB_EVACT_CTRIG              (DMAC_CHCTRLB_EVACT_CTRIG_Val << DMAC_CHCTRLB_EVACT_Pos) /* (DMAC_CHCTRLB) Conditional transfer trigger Position  */
#define DMAC_CHCTRLB_EVACT_CBLOCK             (DMAC_CHCTRLB_EVACT_CBLOCK_Val << DMAC_CHCTRLB_EVACT_Pos) /* (DMAC_CHCTRLB) Conditional block transfer Position  */
#define DMAC_CHCTRLB_EVACT_SUSPEND            (DMAC_CHCTRLB_EVACT_SUSPEND_Val << DMAC_CHCTRLB_EVACT_Pos) /* (DMAC_CHCTRLB) Channel suspend operation Position  */
#define DMAC_CHCTRLB_EVACT_RESUME             (DMAC_CHCTRLB_EVACT_RESUME_Val << DMAC_CHCTRLB_EVACT_Pos) /* (DMAC_CHCTRLB) Channel resume operation Position  */
#define DMAC_CHCTRLB_EVACT_SSKIP              (DMAC_CHCTRLB_EVACT_SSKIP_Val << DMAC_CHCTRLB_EVACT_Pos) /* (DMAC_CHCTRLB) Skip next block suspend action Position  */
#define DMAC_CHCTRLB_EVIE_Pos                 _UINT32_(3)                                          /* (DMAC_CHCTRLB) Channel Event Input Enable Position */
#define DMAC_CHCTRLB_EVIE_Msk                 (_UINT32_(0x1) << DMAC_CHCTRLB_EVIE_Pos)             /* (DMAC_CHCTRLB) Channel Event Input Enable Mask */
#define DMAC_CHCTRLB_EVIE(value)              (DMAC_CHCTRLB_EVIE_Msk & (_UINT32_(value) << DMAC_CHCTRLB_EVIE_Pos)) /* Assigment of value for EVIE in the DMAC_CHCTRLB register */
#define DMAC_CHCTRLB_EVOE_Pos                 _UINT32_(4)                                          /* (DMAC_CHCTRLB) Channel Event Output Enable Position */
#define DMAC_CHCTRLB_EVOE_Msk                 (_UINT32_(0x1) << DMAC_CHCTRLB_EVOE_Pos)             /* (DMAC_CHCTRLB) Channel Event Output Enable Mask */
#define DMAC_CHCTRLB_EVOE(value)              (DMAC_CHCTRLB_EVOE_Msk & (_UINT32_(value) << DMAC_CHCTRLB_EVOE_Pos)) /* Assigment of value for EVOE in the DMAC_CHCTRLB register */
#define DMAC_CHCTRLB_LVL_Pos                  _UINT32_(5)                                          /* (DMAC_CHCTRLB) Channel Arbitration Level Position */
#define DMAC_CHCTRLB_LVL_Msk                  (_UINT32_(0x3) << DMAC_CHCTRLB_LVL_Pos)              /* (DMAC_CHCTRLB) Channel Arbitration Level Mask */
#define DMAC_CHCTRLB_LVL(value)               (DMAC_CHCTRLB_LVL_Msk & (_UINT32_(value) << DMAC_CHCTRLB_LVL_Pos)) /* Assigment of value for LVL in the DMAC_CHCTRLB register */
#define   DMAC_CHCTRLB_LVL_LVL0_Val           _UINT32_(0x0)                                        /* (DMAC_CHCTRLB) Channel Priority Level 0  */
#define   DMAC_CHCTRLB_LVL_LVL1_Val           _UINT32_(0x1)                                        /* (DMAC_CHCTRLB) Channel Priority Level 1  */
#define   DMAC_CHCTRLB_LVL_LVL2_Val           _UINT32_(0x2)                                        /* (DMAC_CHCTRLB) Channel Priority Level 2  */
#define   DMAC_CHCTRLB_LVL_LVL3_Val           _UINT32_(0x3)                                        /* (DMAC_CHCTRLB) Channel Priority Level 3  */
#define DMAC_CHCTRLB_LVL_LVL0                 (DMAC_CHCTRLB_LVL_LVL0_Val << DMAC_CHCTRLB_LVL_Pos)  /* (DMAC_CHCTRLB) Channel Priority Level 0 Position  */
#define DMAC_CHCTRLB_LVL_LVL1                 (DMAC_CHCTRLB_LVL_LVL1_Val << DMAC_CHCTRLB_LVL_Pos)  /* (DMAC_CHCTRLB) Channel Priority Level 1 Position  */
#define DMAC_CHCTRLB_LVL_LVL2                 (DMAC_CHCTRLB_LVL_LVL2_Val << DMAC_CHCTRLB_LVL_Pos)  /* (DMAC_CHCTRLB) Channel Priority Level 2 Position  */
#define DMAC_CHCTRLB_LVL_LVL3                 (DMAC_CHCTRLB_LVL_LVL3_Val << DMAC_CHCTRLB_LVL_Pos)  /* (DMAC_CHCTRLB) Channel Priority Level 3 Position  */
#define DMAC_CHCTRLB_TRIGSRC_Pos              _UINT32_(8)                                          /* (DMAC_CHCTRLB) Trigger Source Position */
#define DMAC_CHCTRLB_TRIGSRC_Msk              (_UINT32_(0x3F) << DMAC_CHCTRLB_TRIGSRC_Pos)         /* (DMAC_CHCTRLB) Trigger Source Mask */
#define DMAC_CHCTRLB_TRIGSRC(value)           (DMAC_CHCTRLB_TRIGSRC_Msk & (_UINT32_(value) << DMAC_CHCTRLB_TRIGSRC_Pos)) /* Assigment of value for TRIGSRC in the DMAC_CHCTRLB register */
#define   DMAC_CHCTRLB_TRIGSRC_DISABLE_Val    _UINT32_(0x0)                                        /* (DMAC_CHCTRLB) Only software/event triggers  */
#define   DMAC_CHCTRLB_TRIGSRC_RTC_TIMESTAMP_Val _UINT32_(0x1)                                        /* (DMAC_CHCTRLB) RTC Timestamp Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_DSU_DCC0_Val   _UINT32_(0x2)                                        /* (DMAC_CHCTRLB) ID for DCC0 register  */
#define   DMAC_CHCTRLB_TRIGSRC_DSU_DCC1_Val   _UINT32_(0x3)                                        /* (DMAC_CHCTRLB) ID for DCC1 register  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM0_RX_Val _UINT32_(0x4)                                        /* (DMAC_CHCTRLB) SERCOM0 RX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM0_TX_Val _UINT32_(0x5)                                        /* (DMAC_CHCTRLB) SERCOM0 TX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM1_RX_Val _UINT32_(0x6)                                        /* (DMAC_CHCTRLB) SERCOM1 RX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM1_TX_Val _UINT32_(0x7)                                        /* (DMAC_CHCTRLB) SERCOM1 TX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM2_RX_Val _UINT32_(0x8)                                        /* (DMAC_CHCTRLB) SERCOM2 RX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM2_TX_Val _UINT32_(0x9)                                        /* (DMAC_CHCTRLB) SERCOM2 TX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM3_RX_Val _UINT32_(0xA)                                        /* (DMAC_CHCTRLB) SERCOM3 RX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM3_TX_Val _UINT32_(0xB)                                        /* (DMAC_CHCTRLB) SERCOM3 TX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM4_RX_Val _UINT32_(0xC)                                        /* (DMAC_CHCTRLB) SERCOM4 RX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM4_TX_Val _UINT32_(0xD)                                        /* (DMAC_CHCTRLB) SERCOM4 TX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM5_RX_Val _UINT32_(0xE)                                        /* (DMAC_CHCTRLB) SERCOM5 RX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_SERCOM5_TX_Val _UINT32_(0xF)                                        /* (DMAC_CHCTRLB) SERCOM5 TX Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TC0_OVF_Val    _UINT32_(0x10)                                       /* (DMAC_CHCTRLB) TC0 Overflow Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TC0_MC0_Val    _UINT32_(0x11)                                       /* (DMAC_CHCTRLB) TC0 Match/Compare 0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TC0_MC1_Val    _UINT32_(0x12)                                       /* (DMAC_CHCTRLB) TC0 Match/Compare 1 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TC1_OVF_Val    _UINT32_(0x13)                                       /* (DMAC_CHCTRLB) TC1 Overflow Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TC1_MC0_Val    _UINT32_(0x14)                                       /* (DMAC_CHCTRLB) TC1 Match/Compare 0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TC1_MC1_Val    _UINT32_(0x15)                                       /* (DMAC_CHCTRLB) TC1 Match/Compare 1 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TC2_OVF_Val    _UINT32_(0x16)                                       /* (DMAC_CHCTRLB) TC2 Overflow Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TC2_MC0_Val    _UINT32_(0x17)                                       /* (DMAC_CHCTRLB) TC2 Match/Compare 0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TC2_MC1_Val    _UINT32_(0x18)                                       /* (DMAC_CHCTRLB) TC2 Match/Compare 1 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC0_OVF_Val   _UINT32_(0x19)                                       /* (DMAC_CHCTRLB) TCC0 Overflow Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC0_MC0_Val   _UINT32_(0x1A)                                       /* (DMAC_CHCTRLB) TCC0 Match/Compare 0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC0_MC1_Val   _UINT32_(0x1B)                                       /* (DMAC_CHCTRLB) TCC0 Match/Compare 1 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC0_MC2_Val   _UINT32_(0x1C)                                       /* (DMAC_CHCTRLB) TCC0 Match/Compare 2 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC0_MC3_Val   _UINT32_(0x1D)                                       /* (DMAC_CHCTRLB) TCC0 Match/Compare 3 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC1_OVF_Val   _UINT32_(0x1E)                                       /* (DMAC_CHCTRLB) TCC1 Overflow Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC1_MC0_Val   _UINT32_(0x1F)                                       /* (DMAC_CHCTRLB) TCC1 Match/Compare 0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC1_MC1_Val   _UINT32_(0x20)                                       /* (DMAC_CHCTRLB) TCC1 Match/Compare 1 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC2_OVF_Val   _UINT32_(0x21)                                       /* (DMAC_CHCTRLB) TCC2 Overflow Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC2_MC0_Val   _UINT32_(0x22)                                       /* (DMAC_CHCTRLB) TCC2 Match/Compare 0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC2_MC1_Val   _UINT32_(0x23)                                       /* (DMAC_CHCTRLB) TCC2 Match/Compare 1 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC3_OVF_Val   _UINT32_(0x24)                                       /* (DMAC_CHCTRLB) TCC3 Overflow Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC3_MC0_Val   _UINT32_(0x25)                                       /* (DMAC_CHCTRLB) TCC3 Match/Compare 0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC3_MC1_Val   _UINT32_(0x26)                                       /* (DMAC_CHCTRLB) TCC3 Match/Compare 1 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC3_MC2_Val   _UINT32_(0x27)                                       /* (DMAC_CHCTRLB) TCC3 Match/Compare 2 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_TCC3_MC3_Val   _UINT32_(0x28)                                       /* (DMAC_CHCTRLB) TCC3 Match/Compare 3 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_ADC_RESRDY_Val _UINT32_(0x29)                                       /* (DMAC_CHCTRLB) ADC Result Ready Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_DAC_EMPTY0_Val _UINT32_(0x2A)                                       /* (DMAC_CHCTRLB) DAC Empty 0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_DAC_EMPTY1_Val _UINT32_(0x2B)                                       /* (DMAC_CHCTRLB) DAC Empty 1 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_PTC_EOC_Val    _UINT32_(0x2C)                                       /* (DMAC_CHCTRLB) PTC End of Conversion Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_PTC_SEQ_Val    _UINT32_(0x2D)                                       /* (DMAC_CHCTRLB) PTC Sequence Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_PTC_WCOMP_Val  _UINT32_(0x2E)                                       /* (DMAC_CHCTRLB) PTC Window Compare Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_I2S_RX0_Val    _UINT32_(0x2F)                                       /* (DMAC_CHCTRLB) I2S RX0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_I2S_RX1_Val    _UINT32_(0x30)                                       /* (DMAC_CHCTRLB) I2S RX1 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_I2S_TX0_Val    _UINT32_(0x31)                                       /* (DMAC_CHCTRLB) I2S TX0 Trigger  */
#define   DMAC_CHCTRLB_TRIGSRC_I2S_TX1_Val    _UINT32_(0x32)                                       /* (DMAC_CHCTRLB) I2S TX1 Trigger  */
#define DMAC_CHCTRLB_TRIGSRC_DISABLE          (DMAC_CHCTRLB_TRIGSRC_DISABLE_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) Only software/event triggers Position  */
#define DMAC_CHCTRLB_TRIGSRC_RTC_TIMESTAMP    (DMAC_CHCTRLB_TRIGSRC_RTC_TIMESTAMP_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) RTC Timestamp Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_DSU_DCC0         (DMAC_CHCTRLB_TRIGSRC_DSU_DCC0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) ID for DCC0 register Position  */
#define DMAC_CHCTRLB_TRIGSRC_DSU_DCC1         (DMAC_CHCTRLB_TRIGSRC_DSU_DCC1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) ID for DCC1 register Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM0_RX       (DMAC_CHCTRLB_TRIGSRC_SERCOM0_RX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM0 RX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM0_TX       (DMAC_CHCTRLB_TRIGSRC_SERCOM0_TX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM0 TX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM1_RX       (DMAC_CHCTRLB_TRIGSRC_SERCOM1_RX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM1 RX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM1_TX       (DMAC_CHCTRLB_TRIGSRC_SERCOM1_TX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM1 TX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM2_RX       (DMAC_CHCTRLB_TRIGSRC_SERCOM2_RX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM2 RX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM2_TX       (DMAC_CHCTRLB_TRIGSRC_SERCOM2_TX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM2 TX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM3_RX       (DMAC_CHCTRLB_TRIGSRC_SERCOM3_RX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM3 RX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM3_TX       (DMAC_CHCTRLB_TRIGSRC_SERCOM3_TX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM3 TX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM4_RX       (DMAC_CHCTRLB_TRIGSRC_SERCOM4_RX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM4 RX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM4_TX       (DMAC_CHCTRLB_TRIGSRC_SERCOM4_TX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM4 TX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM5_RX       (DMAC_CHCTRLB_TRIGSRC_SERCOM5_RX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM5 RX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_SERCOM5_TX       (DMAC_CHCTRLB_TRIGSRC_SERCOM5_TX_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) SERCOM5 TX Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TC0_OVF          (DMAC_CHCTRLB_TRIGSRC_TC0_OVF_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TC0 Overflow Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TC0_MC0          (DMAC_CHCTRLB_TRIGSRC_TC0_MC0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TC0 Match/Compare 0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TC0_MC1          (DMAC_CHCTRLB_TRIGSRC_TC0_MC1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TC0 Match/Compare 1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TC1_OVF          (DMAC_CHCTRLB_TRIGSRC_TC1_OVF_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TC1 Overflow Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TC1_MC0          (DMAC_CHCTRLB_TRIGSRC_TC1_MC0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TC1 Match/Compare 0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TC1_MC1          (DMAC_CHCTRLB_TRIGSRC_TC1_MC1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TC1 Match/Compare 1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TC2_OVF          (DMAC_CHCTRLB_TRIGSRC_TC2_OVF_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TC2 Overflow Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TC2_MC0          (DMAC_CHCTRLB_TRIGSRC_TC2_MC0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TC2 Match/Compare 0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TC2_MC1          (DMAC_CHCTRLB_TRIGSRC_TC2_MC1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TC2 Match/Compare 1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC0_OVF         (DMAC_CHCTRLB_TRIGSRC_TCC0_OVF_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC0 Overflow Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC0_MC0         (DMAC_CHCTRLB_TRIGSRC_TCC0_MC0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC0 Match/Compare 0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC0_MC1         (DMAC_CHCTRLB_TRIGSRC_TCC0_MC1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC0 Match/Compare 1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC0_MC2         (DMAC_CHCTRLB_TRIGSRC_TCC0_MC2_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC0 Match/Compare 2 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC0_MC3         (DMAC_CHCTRLB_TRIGSRC_TCC0_MC3_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC0 Match/Compare 3 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC1_OVF         (DMAC_CHCTRLB_TRIGSRC_TCC1_OVF_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC1 Overflow Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC1_MC0         (DMAC_CHCTRLB_TRIGSRC_TCC1_MC0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC1 Match/Compare 0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC1_MC1         (DMAC_CHCTRLB_TRIGSRC_TCC1_MC1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC1 Match/Compare 1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC2_OVF         (DMAC_CHCTRLB_TRIGSRC_TCC2_OVF_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC2 Overflow Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC2_MC0         (DMAC_CHCTRLB_TRIGSRC_TCC2_MC0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC2 Match/Compare 0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC2_MC1         (DMAC_CHCTRLB_TRIGSRC_TCC2_MC1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC2 Match/Compare 1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC3_OVF         (DMAC_CHCTRLB_TRIGSRC_TCC3_OVF_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC3 Overflow Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC3_MC0         (DMAC_CHCTRLB_TRIGSRC_TCC3_MC0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC3 Match/Compare 0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC3_MC1         (DMAC_CHCTRLB_TRIGSRC_TCC3_MC1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC3 Match/Compare 1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC3_MC2         (DMAC_CHCTRLB_TRIGSRC_TCC3_MC2_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC3 Match/Compare 2 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_TCC3_MC3         (DMAC_CHCTRLB_TRIGSRC_TCC3_MC3_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) TCC3 Match/Compare 3 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_ADC_RESRDY       (DMAC_CHCTRLB_TRIGSRC_ADC_RESRDY_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) ADC Result Ready Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_DAC_EMPTY0       (DMAC_CHCTRLB_TRIGSRC_DAC_EMPTY0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) DAC Empty 0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_DAC_EMPTY1       (DMAC_CHCTRLB_TRIGSRC_DAC_EMPTY1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) DAC Empty 1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_PTC_EOC          (DMAC_CHCTRLB_TRIGSRC_PTC_EOC_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) PTC End of Conversion Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_PTC_SEQ          (DMAC_CHCTRLB_TRIGSRC_PTC_SEQ_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) PTC Sequence Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_PTC_WCOMP        (DMAC_CHCTRLB_TRIGSRC_PTC_WCOMP_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) PTC Window Compare Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_I2S_RX0          (DMAC_CHCTRLB_TRIGSRC_I2S_RX0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) I2S RX0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_I2S_RX1          (DMAC_CHCTRLB_TRIGSRC_I2S_RX1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) I2S RX1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_I2S_TX0          (DMAC_CHCTRLB_TRIGSRC_I2S_TX0_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) I2S TX0 Trigger Position  */
#define DMAC_CHCTRLB_TRIGSRC_I2S_TX1          (DMAC_CHCTRLB_TRIGSRC_I2S_TX1_Val << DMAC_CHCTRLB_TRIGSRC_Pos) /* (DMAC_CHCTRLB) I2S TX1 Trigger Position  */
#define DMAC_CHCTRLB_TRIGACT_Pos              _UINT32_(22)                                         /* (DMAC_CHCTRLB) Trigger Action Position */
#define DMAC_CHCTRLB_TRIGACT_Msk              (_UINT32_(0x3) << DMAC_CHCTRLB_TRIGACT_Pos)          /* (DMAC_CHCTRLB) Trigger Action Mask */
#define DMAC_CHCTRLB_TRIGACT(value)           (DMAC_CHCTRLB_TRIGACT_Msk & (_UINT32_(value) << DMAC_CHCTRLB_TRIGACT_Pos)) /* Assigment of value for TRIGACT in the DMAC_CHCTRLB register */
#define   DMAC_CHCTRLB_TRIGACT_BLOCK_Val      _UINT32_(0x0)                                        /* (DMAC_CHCTRLB) One trigger required for each block transfer  */
#define   DMAC_CHCTRLB_TRIGACT_BEAT_Val       _UINT32_(0x2)                                        /* (DMAC_CHCTRLB) One trigger required for each beat transfer  */
#define   DMAC_CHCTRLB_TRIGACT_TRANSACTION_Val _UINT32_(0x3)                                        /* (DMAC_CHCTRLB) One trigger required for each transaction  */
#define DMAC_CHCTRLB_TRIGACT_BLOCK            (DMAC_CHCTRLB_TRIGACT_BLOCK_Val << DMAC_CHCTRLB_TRIGACT_Pos) /* (DMAC_CHCTRLB) One trigger required for each block transfer Position  */
#define DMAC_CHCTRLB_TRIGACT_BEAT             (DMAC_CHCTRLB_TRIGACT_BEAT_Val << DMAC_CHCTRLB_TRIGACT_Pos) /* (DMAC_CHCTRLB) One trigger required for each beat transfer Position  */
#define DMAC_CHCTRLB_TRIGACT_TRANSACTION      (DMAC_CHCTRLB_TRIGACT_TRANSACTION_Val << DMAC_CHCTRLB_TRIGACT_Pos) /* (DMAC_CHCTRLB) One trigger required for each transaction Position  */
#define DMAC_CHCTRLB_CMD_Pos                  _UINT32_(24)                                         /* (DMAC_CHCTRLB) Software Command Position */
#define DMAC_CHCTRLB_CMD_Msk                  (_UINT32_(0x3) << DMAC_CHCTRLB_CMD_Pos)              /* (DMAC_CHCTRLB) Software Command Mask */
#define DMAC_CHCTRLB_CMD(value)               (DMAC_CHCTRLB_CMD_Msk & (_UINT32_(value) << DMAC_CHCTRLB_CMD_Pos)) /* Assigment of value for CMD in the DMAC_CHCTRLB register */
#define   DMAC_CHCTRLB_CMD_NOACT_Val          _UINT32_(0x0)                                        /* (DMAC_CHCTRLB) No action  */
#define   DMAC_CHCTRLB_CMD_SUSPEND_Val        _UINT32_(0x1)                                        /* (DMAC_CHCTRLB) Channel suspend operation  */
#define   DMAC_CHCTRLB_CMD_RESUME_Val         _UINT32_(0x2)                                        /* (DMAC_CHCTRLB) Channel resume operation  */
#define DMAC_CHCTRLB_CMD_NOACT                (DMAC_CHCTRLB_CMD_NOACT_Val << DMAC_CHCTRLB_CMD_Pos) /* (DMAC_CHCTRLB) No action Position  */
#define DMAC_CHCTRLB_CMD_SUSPEND              (DMAC_CHCTRLB_CMD_SUSPEND_Val << DMAC_CHCTRLB_CMD_Pos) /* (DMAC_CHCTRLB) Channel suspend operation Position  */
#define DMAC_CHCTRLB_CMD_RESUME               (DMAC_CHCTRLB_CMD_RESUME_Val << DMAC_CHCTRLB_CMD_Pos) /* (DMAC_CHCTRLB) Channel resume operation Position  */
#define DMAC_CHCTRLB_Msk                      _UINT32_(0x03C03F7F)                                 /* (DMAC_CHCTRLB) Register Mask  */


/* -------- DMAC_CHINTENCLR : (DMAC Offset: 0x4C) (R/W 8) Channel Interrupt Enable Clear -------- */
#define DMAC_CHINTENCLR_RESETVALUE            _UINT8_(0x00)                                        /*  (DMAC_CHINTENCLR) Channel Interrupt Enable Clear  Reset Value */

#define DMAC_CHINTENCLR_TERR_Pos              _UINT8_(0)                                           /* (DMAC_CHINTENCLR) Channel Transfer Error Interrupt Enable Position */
#define DMAC_CHINTENCLR_TERR_Msk              (_UINT8_(0x1) << DMAC_CHINTENCLR_TERR_Pos)           /* (DMAC_CHINTENCLR) Channel Transfer Error Interrupt Enable Mask */
#define DMAC_CHINTENCLR_TERR(value)           (DMAC_CHINTENCLR_TERR_Msk & (_UINT8_(value) << DMAC_CHINTENCLR_TERR_Pos)) /* Assigment of value for TERR in the DMAC_CHINTENCLR register */
#define DMAC_CHINTENCLR_TCMPL_Pos             _UINT8_(1)                                           /* (DMAC_CHINTENCLR) Channel Transfer Complete Interrupt Enable Position */
#define DMAC_CHINTENCLR_TCMPL_Msk             (_UINT8_(0x1) << DMAC_CHINTENCLR_TCMPL_Pos)          /* (DMAC_CHINTENCLR) Channel Transfer Complete Interrupt Enable Mask */
#define DMAC_CHINTENCLR_TCMPL(value)          (DMAC_CHINTENCLR_TCMPL_Msk & (_UINT8_(value) << DMAC_CHINTENCLR_TCMPL_Pos)) /* Assigment of value for TCMPL in the DMAC_CHINTENCLR register */
#define DMAC_CHINTENCLR_SUSP_Pos              _UINT8_(2)                                           /* (DMAC_CHINTENCLR) Channel Suspend Interrupt Enable Position */
#define DMAC_CHINTENCLR_SUSP_Msk              (_UINT8_(0x1) << DMAC_CHINTENCLR_SUSP_Pos)           /* (DMAC_CHINTENCLR) Channel Suspend Interrupt Enable Mask */
#define DMAC_CHINTENCLR_SUSP(value)           (DMAC_CHINTENCLR_SUSP_Msk & (_UINT8_(value) << DMAC_CHINTENCLR_SUSP_Pos)) /* Assigment of value for SUSP in the DMAC_CHINTENCLR register */
#define DMAC_CHINTENCLR_Msk                   _UINT8_(0x07)                                        /* (DMAC_CHINTENCLR) Register Mask  */


/* -------- DMAC_CHINTENSET : (DMAC Offset: 0x4D) (R/W 8) Channel Interrupt Enable Set -------- */
#define DMAC_CHINTENSET_RESETVALUE            _UINT8_(0x00)                                        /*  (DMAC_CHINTENSET) Channel Interrupt Enable Set  Reset Value */

#define DMAC_CHINTENSET_TERR_Pos              _UINT8_(0)                                           /* (DMAC_CHINTENSET) Channel Transfer Error Interrupt Enable Position */
#define DMAC_CHINTENSET_TERR_Msk              (_UINT8_(0x1) << DMAC_CHINTENSET_TERR_Pos)           /* (DMAC_CHINTENSET) Channel Transfer Error Interrupt Enable Mask */
#define DMAC_CHINTENSET_TERR(value)           (DMAC_CHINTENSET_TERR_Msk & (_UINT8_(value) << DMAC_CHINTENSET_TERR_Pos)) /* Assigment of value for TERR in the DMAC_CHINTENSET register */
#define DMAC_CHINTENSET_TCMPL_Pos             _UINT8_(1)                                           /* (DMAC_CHINTENSET) Channel Transfer Complete Interrupt Enable Position */
#define DMAC_CHINTENSET_TCMPL_Msk             (_UINT8_(0x1) << DMAC_CHINTENSET_TCMPL_Pos)          /* (DMAC_CHINTENSET) Channel Transfer Complete Interrupt Enable Mask */
#define DMAC_CHINTENSET_TCMPL(value)          (DMAC_CHINTENSET_TCMPL_Msk & (_UINT8_(value) << DMAC_CHINTENSET_TCMPL_Pos)) /* Assigment of value for TCMPL in the DMAC_CHINTENSET register */
#define DMAC_CHINTENSET_SUSP_Pos              _UINT8_(2)                                           /* (DMAC_CHINTENSET) Channel Suspend Interrupt Enable Position */
#define DMAC_CHINTENSET_SUSP_Msk              (_UINT8_(0x1) << DMAC_CHINTENSET_SUSP_Pos)           /* (DMAC_CHINTENSET) Channel Suspend Interrupt Enable Mask */
#define DMAC_CHINTENSET_SUSP(value)           (DMAC_CHINTENSET_SUSP_Msk & (_UINT8_(value) << DMAC_CHINTENSET_SUSP_Pos)) /* Assigment of value for SUSP in the DMAC_CHINTENSET register */
#define DMAC_CHINTENSET_Msk                   _UINT8_(0x07)                                        /* (DMAC_CHINTENSET) Register Mask  */


/* -------- DMAC_CHINTFLAG : (DMAC Offset: 0x4E) (R/W 8) Channel Interrupt Flag Status and Clear -------- */
#define DMAC_CHINTFLAG_RESETVALUE             _UINT8_(0x00)                                        /*  (DMAC_CHINTFLAG) Channel Interrupt Flag Status and Clear  Reset Value */

#define DMAC_CHINTFLAG_TERR_Pos               _UINT8_(0)                                           /* (DMAC_CHINTFLAG) Channel Transfer Error Position */
#define DMAC_CHINTFLAG_TERR_Msk               (_UINT8_(0x1) << DMAC_CHINTFLAG_TERR_Pos)            /* (DMAC_CHINTFLAG) Channel Transfer Error Mask */
#define DMAC_CHINTFLAG_TERR(value)            (DMAC_CHINTFLAG_TERR_Msk & (_UINT8_(value) << DMAC_CHINTFLAG_TERR_Pos)) /* Assigment of value for TERR in the DMAC_CHINTFLAG register */
#define DMAC_CHINTFLAG_TCMPL_Pos              _UINT8_(1)                                           /* (DMAC_CHINTFLAG) Channel Transfer Complete Position */
#define DMAC_CHINTFLAG_TCMPL_Msk              (_UINT8_(0x1) << DMAC_CHINTFLAG_TCMPL_Pos)           /* (DMAC_CHINTFLAG) Channel Transfer Complete Mask */
#define DMAC_CHINTFLAG_TCMPL(value)           (DMAC_CHINTFLAG_TCMPL_Msk & (_UINT8_(value) << DMAC_CHINTFLAG_TCMPL_Pos)) /* Assigment of value for TCMPL in the DMAC_CHINTFLAG register */
#define DMAC_CHINTFLAG_SUSP_Pos               _UINT8_(2)                                           /* (DMAC_CHINTFLAG) Channel Suspend Position */
#define DMAC_CHINTFLAG_SUSP_Msk               (_UINT8_(0x1) << DMAC_CHINTFLAG_SUSP_Pos)            /* (DMAC_CHINTFLAG) Channel Suspend Mask */
#define DMAC_CHINTFLAG_SUSP(value)            (DMAC_CHINTFLAG_SUSP_Msk & (_UINT8_(value) << DMAC_CHINTFLAG_SUSP_Pos)) /* Assigment of value for SUSP in the DMAC_CHINTFLAG register */
#define DMAC_CHINTFLAG_Msk                    _UINT8_(0x07)                                        /* (DMAC_CHINTFLAG) Register Mask  */


/* -------- DMAC_CHSTATUS : (DMAC Offset: 0x4F) ( R/ 8) Channel Status -------- */
#define DMAC_CHSTATUS_RESETVALUE              _UINT8_(0x00)                                        /*  (DMAC_CHSTATUS) Channel Status  Reset Value */

#define DMAC_CHSTATUS_PEND_Pos                _UINT8_(0)                                           /* (DMAC_CHSTATUS) Channel Pending Position */
#define DMAC_CHSTATUS_PEND_Msk                (_UINT8_(0x1) << DMAC_CHSTATUS_PEND_Pos)             /* (DMAC_CHSTATUS) Channel Pending Mask */
#define DMAC_CHSTATUS_PEND(value)             (DMAC_CHSTATUS_PEND_Msk & (_UINT8_(value) << DMAC_CHSTATUS_PEND_Pos)) /* Assigment of value for PEND in the DMAC_CHSTATUS register */
#define DMAC_CHSTATUS_BUSY_Pos                _UINT8_(1)                                           /* (DMAC_CHSTATUS) Channel Busy Position */
#define DMAC_CHSTATUS_BUSY_Msk                (_UINT8_(0x1) << DMAC_CHSTATUS_BUSY_Pos)             /* (DMAC_CHSTATUS) Channel Busy Mask */
#define DMAC_CHSTATUS_BUSY(value)             (DMAC_CHSTATUS_BUSY_Msk & (_UINT8_(value) << DMAC_CHSTATUS_BUSY_Pos)) /* Assigment of value for BUSY in the DMAC_CHSTATUS register */
#define DMAC_CHSTATUS_FERR_Pos                _UINT8_(2)                                           /* (DMAC_CHSTATUS) Channel Fetch Error Position */
#define DMAC_CHSTATUS_FERR_Msk                (_UINT8_(0x1) << DMAC_CHSTATUS_FERR_Pos)             /* (DMAC_CHSTATUS) Channel Fetch Error Mask */
#define DMAC_CHSTATUS_FERR(value)             (DMAC_CHSTATUS_FERR_Msk & (_UINT8_(value) << DMAC_CHSTATUS_FERR_Pos)) /* Assigment of value for FERR in the DMAC_CHSTATUS register */
#define DMAC_CHSTATUS_Msk                     _UINT8_(0x07)                                        /* (DMAC_CHSTATUS) Register Mask  */


/** \brief DMAC register offsets definitions */
#define DMAC_BTCTRL_REG_OFST           _UINT32_(0x00)      /* (DMAC_BTCTRL) Block Transfer Control Offset */
#define DMAC_BTCNT_REG_OFST            _UINT32_(0x02)      /* (DMAC_BTCNT) Block Transfer Count Offset */
#define DMAC_SRCADDR_REG_OFST          _UINT32_(0x04)      /* (DMAC_SRCADDR) Block Transfer Source Address Offset */
#define DMAC_DSTADDR_REG_OFST          _UINT32_(0x08)      /* (DMAC_DSTADDR) Block Transfer Destination Address Offset */
#define DMAC_DESCADDR_REG_OFST         _UINT32_(0x0C)      /* (DMAC_DESCADDR) Next Descriptor Address Offset */
#define DMAC_CTRL_REG_OFST             _UINT32_(0x00)      /* (DMAC_CTRL) Control Offset */
#define DMAC_CRCCTRL_REG_OFST          _UINT32_(0x02)      /* (DMAC_CRCCTRL) CRC Control Offset */
#define DMAC_CRCDATAIN_REG_OFST        _UINT32_(0x04)      /* (DMAC_CRCDATAIN) CRC Data Input Offset */
#define DMAC_CRCCHKSUM_REG_OFST        _UINT32_(0x08)      /* (DMAC_CRCCHKSUM) CRC Checksum Offset */
#define DMAC_CRCSTATUS_REG_OFST        _UINT32_(0x0C)      /* (DMAC_CRCSTATUS) CRC Status Offset */
#define DMAC_DBGCTRL_REG_OFST          _UINT32_(0x0D)      /* (DMAC_DBGCTRL) Debug Control Offset */
#define DMAC_QOSCTRL_REG_OFST          _UINT32_(0x0E)      /* (DMAC_QOSCTRL) QOS Control Offset */
#define DMAC_SWTRIGCTRL_REG_OFST       _UINT32_(0x10)      /* (DMAC_SWTRIGCTRL) Software Trigger Control Offset */
#define DMAC_PRICTRL0_REG_OFST         _UINT32_(0x14)      /* (DMAC_PRICTRL0) Priority Control Offset */
#define DMAC_INTPEND_REG_OFST          _UINT32_(0x20)      /* (DMAC_INTPEND) Interrupt Pending Offset */
#define DMAC_INTSTATUS_REG_OFST        _UINT32_(0x24)      /* (DMAC_INTSTATUS) Interrupt Status Offset */
#define DMAC_BUSYCH_REG_OFST           _UINT32_(0x28)      /* (DMAC_BUSYCH) Busy Channels Offset */
#define DMAC_PENDCH_REG_OFST           _UINT32_(0x2C)      /* (DMAC_PENDCH) Pending Channels Offset */
#define DMAC_ACTIVE_REG_OFST           _UINT32_(0x30)      /* (DMAC_ACTIVE) Active Channel and Levels Offset */
#define DMAC_BASEADDR_REG_OFST         _UINT32_(0x34)      /* (DMAC_BASEADDR) Descriptor Memory Section Base Address Offset */
#define DMAC_WRBADDR_REG_OFST          _UINT32_(0x38)      /* (DMAC_WRBADDR) Write-Back Memory Section Base Address Offset */
#define DMAC_CHID_REG_OFST             _UINT32_(0x3F)      /* (DMAC_CHID) Channel ID Offset */
#define DMAC_CHCTRLA_REG_OFST          _UINT32_(0x40)      /* (DMAC_CHCTRLA) Channel Control A Offset */
#define DMAC_CHCTRLB_REG_OFST          _UINT32_(0x44)      /* (DMAC_CHCTRLB) Channel Control B Offset */
#define DMAC_CHINTENCLR_REG_OFST       _UINT32_(0x4C)      /* (DMAC_CHINTENCLR) Channel Interrupt Enable Clear Offset */
#define DMAC_CHINTENSET_REG_OFST       _UINT32_(0x4D)      /* (DMAC_CHINTENSET) Channel Interrupt Enable Set Offset */
#define DMAC_CHINTFLAG_REG_OFST        _UINT32_(0x4E)      /* (DMAC_CHINTFLAG) Channel Interrupt Flag Status and Clear Offset */
#define DMAC_CHSTATUS_REG_OFST         _UINT32_(0x4F)      /* (DMAC_CHSTATUS) Channel Status Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief DMAC_DESCRIPTOR register API structure */
typedef struct
{  /* Direct Memory Access Controller */
  __IO  uint16_t                       DMAC_BTCTRL;        /**< Offset: 0x00 (R/W  16) Block Transfer Control */
  __IO  uint16_t                       DMAC_BTCNT;         /**< Offset: 0x02 (R/W  16) Block Transfer Count */
  __IO  uint32_t                       DMAC_SRCADDR;       /**< Offset: 0x04 (R/W  32) Block Transfer Source Address */
  __IO  uint32_t                       DMAC_DSTADDR;       /**< Offset: 0x08 (R/W  32) Block Transfer Destination Address */
  __IO  uint32_t                       DMAC_DESCADDR;      /**< Offset: 0x0C (R/W  32) Next Descriptor Address */
} dmac_descriptor_registers_t
#ifdef __GNUC__
  __attribute__ ((aligned (8)))
#endif
;

/** \brief DMAC register API structure */
typedef struct
{  /* Direct Memory Access Controller */
  __IO  uint16_t                       DMAC_CTRL;          /**< Offset: 0x00 (R/W  16) Control */
  __IO  uint16_t                       DMAC_CRCCTRL;       /**< Offset: 0x02 (R/W  16) CRC Control */
  __IO  uint32_t                       DMAC_CRCDATAIN;     /**< Offset: 0x04 (R/W  32) CRC Data Input */
  __IO  uint32_t                       DMAC_CRCCHKSUM;     /**< Offset: 0x08 (R/W  32) CRC Checksum */
  __IO  uint8_t                        DMAC_CRCSTATUS;     /**< Offset: 0x0C (R/W  8) CRC Status */
  __IO  uint8_t                        DMAC_DBGCTRL;       /**< Offset: 0x0D (R/W  8) Debug Control */
  __IO  uint8_t                        DMAC_QOSCTRL;       /**< Offset: 0x0E (R/W  8) QOS Control */
  __I   uint8_t                        Reserved1[0x01];
  __IO  uint32_t                       DMAC_SWTRIGCTRL;    /**< Offset: 0x10 (R/W  32) Software Trigger Control */
  __IO  uint32_t                       DMAC_PRICTRL0;      /**< Offset: 0x14 (R/W  32) Priority Control */
  __I   uint8_t                        Reserved2[0x08];
  __IO  uint16_t                       DMAC_INTPEND;       /**< Offset: 0x20 (R/W  16) Interrupt Pending */
  __I   uint8_t                        Reserved3[0x02];
  __I   uint32_t                       DMAC_INTSTATUS;     /**< Offset: 0x24 (R/   32) Interrupt Status */
  __I   uint32_t                       DMAC_BUSYCH;        /**< Offset: 0x28 (R/   32) Busy Channels */
  __I   uint32_t                       DMAC_PENDCH;        /**< Offset: 0x2C (R/   32) Pending Channels */
  __I   uint32_t                       DMAC_ACTIVE;        /**< Offset: 0x30 (R/   32) Active Channel and Levels */
  __IO  uint32_t                       DMAC_BASEADDR;      /**< Offset: 0x34 (R/W  32) Descriptor Memory Section Base Address */
  __IO  uint32_t                       DMAC_WRBADDR;       /**< Offset: 0x38 (R/W  32) Write-Back Memory Section Base Address */
  __I   uint8_t                        Reserved4[0x03];
  __IO  uint8_t                        DMAC_CHID;          /**< Offset: 0x3F (R/W  8) Channel ID */
  __IO  uint8_t                        DMAC_CHCTRLA;       /**< Offset: 0x40 (R/W  8) Channel Control A */
  __I   uint8_t                        Reserved5[0x03];
  __IO  uint32_t                       DMAC_CHCTRLB;       /**< Offset: 0x44 (R/W  32) Channel Control B */
  __I   uint8_t                        Reserved6[0x04];
  __IO  uint8_t                        DMAC_CHINTENCLR;    /**< Offset: 0x4C (R/W  8) Channel Interrupt Enable Clear */
  __IO  uint8_t                        DMAC_CHINTENSET;    /**< Offset: 0x4D (R/W  8) Channel Interrupt Enable Set */
  __IO  uint8_t                        DMAC_CHINTFLAG;     /**< Offset: 0x4E (R/W  8) Channel Interrupt Flag Status and Clear */
  __I   uint8_t                        DMAC_CHSTATUS;      /**< Offset: 0x4F (R/   8) Channel Status */
} dmac_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** \brief DMAC_DESCRIPTOR memory section attribute */
#define SECTION_DMAC_DESCRIPTOR

#endif /* _PIC32CMLS60_DMAC_COMPONENT_H_ */
