/*
 * Component description for RTC
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
#ifndef _PIC32CMLS60_RTC_COMPONENT_H_
#define _PIC32CMLS60_RTC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR RTC                                          */
/* ************************************************************************** */

/* -------- RTC_MODE0_CTRLA : (RTC Offset: 0x00) (R/W 16) MODE0 Control A -------- */
#define RTC_MODE0_CTRLA_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE0_CTRLA) MODE0 Control A  Reset Value */

#define RTC_MODE0_CTRLA_SWRST_Pos             _UINT16_(0)                                          /* (RTC_MODE0_CTRLA) Software Reset Position */
#define RTC_MODE0_CTRLA_SWRST_Msk             (_UINT16_(0x1) << RTC_MODE0_CTRLA_SWRST_Pos)         /* (RTC_MODE0_CTRLA) Software Reset Mask */
#define RTC_MODE0_CTRLA_SWRST(value)          (RTC_MODE0_CTRLA_SWRST_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the RTC_MODE0_CTRLA register */
#define RTC_MODE0_CTRLA_ENABLE_Pos            _UINT16_(1)                                          /* (RTC_MODE0_CTRLA) Enable Position */
#define RTC_MODE0_CTRLA_ENABLE_Msk            (_UINT16_(0x1) << RTC_MODE0_CTRLA_ENABLE_Pos)        /* (RTC_MODE0_CTRLA) Enable Mask */
#define RTC_MODE0_CTRLA_ENABLE(value)         (RTC_MODE0_CTRLA_ENABLE_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the RTC_MODE0_CTRLA register */
#define RTC_MODE0_CTRLA_MODE_Pos              _UINT16_(2)                                          /* (RTC_MODE0_CTRLA) Operating Mode Position */
#define RTC_MODE0_CTRLA_MODE_Msk              (_UINT16_(0x3) << RTC_MODE0_CTRLA_MODE_Pos)          /* (RTC_MODE0_CTRLA) Operating Mode Mask */
#define RTC_MODE0_CTRLA_MODE(value)           (RTC_MODE0_CTRLA_MODE_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_MODE_Pos)) /* Assigment of value for MODE in the RTC_MODE0_CTRLA register */
#define   RTC_MODE0_CTRLA_MODE_COUNT32_Val    _UINT16_(0x0)                                        /* (RTC_MODE0_CTRLA) Mode 0: 32-bit Counter  */
#define   RTC_MODE0_CTRLA_MODE_COUNT16_Val    _UINT16_(0x1)                                        /* (RTC_MODE0_CTRLA) Mode 1: 16-bit Counter  */
#define   RTC_MODE0_CTRLA_MODE_CLOCK_Val      _UINT16_(0x2)                                        /* (RTC_MODE0_CTRLA) Mode 2: Clock/Calendar  */
#define RTC_MODE0_CTRLA_MODE_COUNT32          (RTC_MODE0_CTRLA_MODE_COUNT32_Val << RTC_MODE0_CTRLA_MODE_Pos) /* (RTC_MODE0_CTRLA) Mode 0: 32-bit Counter Position  */
#define RTC_MODE0_CTRLA_MODE_COUNT16          (RTC_MODE0_CTRLA_MODE_COUNT16_Val << RTC_MODE0_CTRLA_MODE_Pos) /* (RTC_MODE0_CTRLA) Mode 1: 16-bit Counter Position  */
#define RTC_MODE0_CTRLA_MODE_CLOCK            (RTC_MODE0_CTRLA_MODE_CLOCK_Val << RTC_MODE0_CTRLA_MODE_Pos) /* (RTC_MODE0_CTRLA) Mode 2: Clock/Calendar Position  */
#define RTC_MODE0_CTRLA_MATCHCLR_Pos          _UINT16_(7)                                          /* (RTC_MODE0_CTRLA) Clear on Match Position */
#define RTC_MODE0_CTRLA_MATCHCLR_Msk          (_UINT16_(0x1) << RTC_MODE0_CTRLA_MATCHCLR_Pos)      /* (RTC_MODE0_CTRLA) Clear on Match Mask */
#define RTC_MODE0_CTRLA_MATCHCLR(value)       (RTC_MODE0_CTRLA_MATCHCLR_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_MATCHCLR_Pos)) /* Assigment of value for MATCHCLR in the RTC_MODE0_CTRLA register */
#define RTC_MODE0_CTRLA_PRESCALER_Pos         _UINT16_(8)                                          /* (RTC_MODE0_CTRLA) Prescaler Position */
#define RTC_MODE0_CTRLA_PRESCALER_Msk         (_UINT16_(0xF) << RTC_MODE0_CTRLA_PRESCALER_Pos)     /* (RTC_MODE0_CTRLA) Prescaler Mask */
#define RTC_MODE0_CTRLA_PRESCALER(value)      (RTC_MODE0_CTRLA_PRESCALER_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_PRESCALER_Pos)) /* Assigment of value for PRESCALER in the RTC_MODE0_CTRLA register */
#define   RTC_MODE0_CTRLA_PRESCALER_OFF_Val   _UINT16_(0x0)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV1_Val  _UINT16_(0x1)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV2_Val  _UINT16_(0x2)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/2  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV4_Val  _UINT16_(0x3)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/4  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV8_Val  _UINT16_(0x4)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/8  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV16_Val _UINT16_(0x5)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/16  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV32_Val _UINT16_(0x6)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/32  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV64_Val _UINT16_(0x7)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/64  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV128_Val _UINT16_(0x8)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/128  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV256_Val _UINT16_(0x9)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/256  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV512_Val _UINT16_(0xA)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/512  */
#define   RTC_MODE0_CTRLA_PRESCALER_DIV1024_Val _UINT16_(0xB)                                        /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024  */
#define RTC_MODE0_CTRLA_PRESCALER_OFF         (RTC_MODE0_CTRLA_PRESCALER_OFF_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV1        (RTC_MODE0_CTRLA_PRESCALER_DIV1_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV2        (RTC_MODE0_CTRLA_PRESCALER_DIV2_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/2 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV4        (RTC_MODE0_CTRLA_PRESCALER_DIV4_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/4 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV8        (RTC_MODE0_CTRLA_PRESCALER_DIV8_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/8 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV16       (RTC_MODE0_CTRLA_PRESCALER_DIV16_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/16 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV32       (RTC_MODE0_CTRLA_PRESCALER_DIV32_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/32 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV64       (RTC_MODE0_CTRLA_PRESCALER_DIV64_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/64 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV128      (RTC_MODE0_CTRLA_PRESCALER_DIV128_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/128 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV256      (RTC_MODE0_CTRLA_PRESCALER_DIV256_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/256 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV512      (RTC_MODE0_CTRLA_PRESCALER_DIV512_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/512 Position  */
#define RTC_MODE0_CTRLA_PRESCALER_DIV1024     (RTC_MODE0_CTRLA_PRESCALER_DIV1024_Val << RTC_MODE0_CTRLA_PRESCALER_Pos) /* (RTC_MODE0_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024 Position  */
#define RTC_MODE0_CTRLA_GPTRST_Pos            _UINT16_(14)                                         /* (RTC_MODE0_CTRLA) GP Registers Reset On Tamper Enable Position */
#define RTC_MODE0_CTRLA_GPTRST_Msk            (_UINT16_(0x1) << RTC_MODE0_CTRLA_GPTRST_Pos)        /* (RTC_MODE0_CTRLA) GP Registers Reset On Tamper Enable Mask */
#define RTC_MODE0_CTRLA_GPTRST(value)         (RTC_MODE0_CTRLA_GPTRST_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_GPTRST_Pos)) /* Assigment of value for GPTRST in the RTC_MODE0_CTRLA register */
#define RTC_MODE0_CTRLA_COUNTSYNC_Pos         _UINT16_(15)                                         /* (RTC_MODE0_CTRLA) Count Read Synchronization Enable Position */
#define RTC_MODE0_CTRLA_COUNTSYNC_Msk         (_UINT16_(0x1) << RTC_MODE0_CTRLA_COUNTSYNC_Pos)     /* (RTC_MODE0_CTRLA) Count Read Synchronization Enable Mask */
#define RTC_MODE0_CTRLA_COUNTSYNC(value)      (RTC_MODE0_CTRLA_COUNTSYNC_Msk & (_UINT16_(value) << RTC_MODE0_CTRLA_COUNTSYNC_Pos)) /* Assigment of value for COUNTSYNC in the RTC_MODE0_CTRLA register */
#define RTC_MODE0_CTRLA_Msk                   _UINT16_(0xCF8F)                                     /* (RTC_MODE0_CTRLA) Register Mask  */


/* -------- RTC_MODE1_CTRLA : (RTC Offset: 0x00) (R/W 16) MODE1 Control A -------- */
#define RTC_MODE1_CTRLA_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE1_CTRLA) MODE1 Control A  Reset Value */

#define RTC_MODE1_CTRLA_SWRST_Pos             _UINT16_(0)                                          /* (RTC_MODE1_CTRLA) Software Reset Position */
#define RTC_MODE1_CTRLA_SWRST_Msk             (_UINT16_(0x1) << RTC_MODE1_CTRLA_SWRST_Pos)         /* (RTC_MODE1_CTRLA) Software Reset Mask */
#define RTC_MODE1_CTRLA_SWRST(value)          (RTC_MODE1_CTRLA_SWRST_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the RTC_MODE1_CTRLA register */
#define RTC_MODE1_CTRLA_ENABLE_Pos            _UINT16_(1)                                          /* (RTC_MODE1_CTRLA) Enable Position */
#define RTC_MODE1_CTRLA_ENABLE_Msk            (_UINT16_(0x1) << RTC_MODE1_CTRLA_ENABLE_Pos)        /* (RTC_MODE1_CTRLA) Enable Mask */
#define RTC_MODE1_CTRLA_ENABLE(value)         (RTC_MODE1_CTRLA_ENABLE_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the RTC_MODE1_CTRLA register */
#define RTC_MODE1_CTRLA_MODE_Pos              _UINT16_(2)                                          /* (RTC_MODE1_CTRLA) Operating Mode Position */
#define RTC_MODE1_CTRLA_MODE_Msk              (_UINT16_(0x3) << RTC_MODE1_CTRLA_MODE_Pos)          /* (RTC_MODE1_CTRLA) Operating Mode Mask */
#define RTC_MODE1_CTRLA_MODE(value)           (RTC_MODE1_CTRLA_MODE_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_MODE_Pos)) /* Assigment of value for MODE in the RTC_MODE1_CTRLA register */
#define   RTC_MODE1_CTRLA_MODE_COUNT32_Val    _UINT16_(0x0)                                        /* (RTC_MODE1_CTRLA) Mode 0: 32-bit Counter  */
#define   RTC_MODE1_CTRLA_MODE_COUNT16_Val    _UINT16_(0x1)                                        /* (RTC_MODE1_CTRLA) Mode 1: 16-bit Counter  */
#define   RTC_MODE1_CTRLA_MODE_CLOCK_Val      _UINT16_(0x2)                                        /* (RTC_MODE1_CTRLA) Mode 2: Clock/Calendar  */
#define RTC_MODE1_CTRLA_MODE_COUNT32          (RTC_MODE1_CTRLA_MODE_COUNT32_Val << RTC_MODE1_CTRLA_MODE_Pos) /* (RTC_MODE1_CTRLA) Mode 0: 32-bit Counter Position  */
#define RTC_MODE1_CTRLA_MODE_COUNT16          (RTC_MODE1_CTRLA_MODE_COUNT16_Val << RTC_MODE1_CTRLA_MODE_Pos) /* (RTC_MODE1_CTRLA) Mode 1: 16-bit Counter Position  */
#define RTC_MODE1_CTRLA_MODE_CLOCK            (RTC_MODE1_CTRLA_MODE_CLOCK_Val << RTC_MODE1_CTRLA_MODE_Pos) /* (RTC_MODE1_CTRLA) Mode 2: Clock/Calendar Position  */
#define RTC_MODE1_CTRLA_PRESCALER_Pos         _UINT16_(8)                                          /* (RTC_MODE1_CTRLA) Prescaler Position */
#define RTC_MODE1_CTRLA_PRESCALER_Msk         (_UINT16_(0xF) << RTC_MODE1_CTRLA_PRESCALER_Pos)     /* (RTC_MODE1_CTRLA) Prescaler Mask */
#define RTC_MODE1_CTRLA_PRESCALER(value)      (RTC_MODE1_CTRLA_PRESCALER_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_PRESCALER_Pos)) /* Assigment of value for PRESCALER in the RTC_MODE1_CTRLA register */
#define   RTC_MODE1_CTRLA_PRESCALER_OFF_Val   _UINT16_(0x0)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV1_Val  _UINT16_(0x1)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV2_Val  _UINT16_(0x2)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/2  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV4_Val  _UINT16_(0x3)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/4  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV8_Val  _UINT16_(0x4)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/8  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV16_Val _UINT16_(0x5)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/16  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV32_Val _UINT16_(0x6)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/32  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV64_Val _UINT16_(0x7)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/64  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV128_Val _UINT16_(0x8)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/128  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV256_Val _UINT16_(0x9)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/256  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV512_Val _UINT16_(0xA)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/512  */
#define   RTC_MODE1_CTRLA_PRESCALER_DIV1024_Val _UINT16_(0xB)                                        /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024  */
#define RTC_MODE1_CTRLA_PRESCALER_OFF         (RTC_MODE1_CTRLA_PRESCALER_OFF_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV1        (RTC_MODE1_CTRLA_PRESCALER_DIV1_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV2        (RTC_MODE1_CTRLA_PRESCALER_DIV2_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/2 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV4        (RTC_MODE1_CTRLA_PRESCALER_DIV4_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/4 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV8        (RTC_MODE1_CTRLA_PRESCALER_DIV8_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/8 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV16       (RTC_MODE1_CTRLA_PRESCALER_DIV16_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/16 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV32       (RTC_MODE1_CTRLA_PRESCALER_DIV32_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/32 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV64       (RTC_MODE1_CTRLA_PRESCALER_DIV64_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/64 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV128      (RTC_MODE1_CTRLA_PRESCALER_DIV128_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/128 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV256      (RTC_MODE1_CTRLA_PRESCALER_DIV256_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/256 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV512      (RTC_MODE1_CTRLA_PRESCALER_DIV512_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/512 Position  */
#define RTC_MODE1_CTRLA_PRESCALER_DIV1024     (RTC_MODE1_CTRLA_PRESCALER_DIV1024_Val << RTC_MODE1_CTRLA_PRESCALER_Pos) /* (RTC_MODE1_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024 Position  */
#define RTC_MODE1_CTRLA_GPTRST_Pos            _UINT16_(14)                                         /* (RTC_MODE1_CTRLA) GP Registers Reset On Tamper Enable Position */
#define RTC_MODE1_CTRLA_GPTRST_Msk            (_UINT16_(0x1) << RTC_MODE1_CTRLA_GPTRST_Pos)        /* (RTC_MODE1_CTRLA) GP Registers Reset On Tamper Enable Mask */
#define RTC_MODE1_CTRLA_GPTRST(value)         (RTC_MODE1_CTRLA_GPTRST_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_GPTRST_Pos)) /* Assigment of value for GPTRST in the RTC_MODE1_CTRLA register */
#define RTC_MODE1_CTRLA_COUNTSYNC_Pos         _UINT16_(15)                                         /* (RTC_MODE1_CTRLA) Count Read Synchronization Enable Position */
#define RTC_MODE1_CTRLA_COUNTSYNC_Msk         (_UINT16_(0x1) << RTC_MODE1_CTRLA_COUNTSYNC_Pos)     /* (RTC_MODE1_CTRLA) Count Read Synchronization Enable Mask */
#define RTC_MODE1_CTRLA_COUNTSYNC(value)      (RTC_MODE1_CTRLA_COUNTSYNC_Msk & (_UINT16_(value) << RTC_MODE1_CTRLA_COUNTSYNC_Pos)) /* Assigment of value for COUNTSYNC in the RTC_MODE1_CTRLA register */
#define RTC_MODE1_CTRLA_Msk                   _UINT16_(0xCF0F)                                     /* (RTC_MODE1_CTRLA) Register Mask  */


/* -------- RTC_MODE2_CTRLA : (RTC Offset: 0x00) (R/W 16) MODE2 Control A -------- */
#define RTC_MODE2_CTRLA_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE2_CTRLA) MODE2 Control A  Reset Value */

#define RTC_MODE2_CTRLA_SWRST_Pos             _UINT16_(0)                                          /* (RTC_MODE2_CTRLA) Software Reset Position */
#define RTC_MODE2_CTRLA_SWRST_Msk             (_UINT16_(0x1) << RTC_MODE2_CTRLA_SWRST_Pos)         /* (RTC_MODE2_CTRLA) Software Reset Mask */
#define RTC_MODE2_CTRLA_SWRST(value)          (RTC_MODE2_CTRLA_SWRST_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_ENABLE_Pos            _UINT16_(1)                                          /* (RTC_MODE2_CTRLA) Enable Position */
#define RTC_MODE2_CTRLA_ENABLE_Msk            (_UINT16_(0x1) << RTC_MODE2_CTRLA_ENABLE_Pos)        /* (RTC_MODE2_CTRLA) Enable Mask */
#define RTC_MODE2_CTRLA_ENABLE(value)         (RTC_MODE2_CTRLA_ENABLE_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_MODE_Pos              _UINT16_(2)                                          /* (RTC_MODE2_CTRLA) Operating Mode Position */
#define RTC_MODE2_CTRLA_MODE_Msk              (_UINT16_(0x3) << RTC_MODE2_CTRLA_MODE_Pos)          /* (RTC_MODE2_CTRLA) Operating Mode Mask */
#define RTC_MODE2_CTRLA_MODE(value)           (RTC_MODE2_CTRLA_MODE_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_MODE_Pos)) /* Assigment of value for MODE in the RTC_MODE2_CTRLA register */
#define   RTC_MODE2_CTRLA_MODE_COUNT32_Val    _UINT16_(0x0)                                        /* (RTC_MODE2_CTRLA) Mode 0: 32-bit Counter  */
#define   RTC_MODE2_CTRLA_MODE_COUNT16_Val    _UINT16_(0x1)                                        /* (RTC_MODE2_CTRLA) Mode 1: 16-bit Counter  */
#define   RTC_MODE2_CTRLA_MODE_CLOCK_Val      _UINT16_(0x2)                                        /* (RTC_MODE2_CTRLA) Mode 2: Clock/Calendar  */
#define RTC_MODE2_CTRLA_MODE_COUNT32          (RTC_MODE2_CTRLA_MODE_COUNT32_Val << RTC_MODE2_CTRLA_MODE_Pos) /* (RTC_MODE2_CTRLA) Mode 0: 32-bit Counter Position  */
#define RTC_MODE2_CTRLA_MODE_COUNT16          (RTC_MODE2_CTRLA_MODE_COUNT16_Val << RTC_MODE2_CTRLA_MODE_Pos) /* (RTC_MODE2_CTRLA) Mode 1: 16-bit Counter Position  */
#define RTC_MODE2_CTRLA_MODE_CLOCK            (RTC_MODE2_CTRLA_MODE_CLOCK_Val << RTC_MODE2_CTRLA_MODE_Pos) /* (RTC_MODE2_CTRLA) Mode 2: Clock/Calendar Position  */
#define RTC_MODE2_CTRLA_CLKREP_Pos            _UINT16_(6)                                          /* (RTC_MODE2_CTRLA) Clock Representation Position */
#define RTC_MODE2_CTRLA_CLKREP_Msk            (_UINT16_(0x1) << RTC_MODE2_CTRLA_CLKREP_Pos)        /* (RTC_MODE2_CTRLA) Clock Representation Mask */
#define RTC_MODE2_CTRLA_CLKREP(value)         (RTC_MODE2_CTRLA_CLKREP_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_CLKREP_Pos)) /* Assigment of value for CLKREP in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_MATCHCLR_Pos          _UINT16_(7)                                          /* (RTC_MODE2_CTRLA) Clear on Match Position */
#define RTC_MODE2_CTRLA_MATCHCLR_Msk          (_UINT16_(0x1) << RTC_MODE2_CTRLA_MATCHCLR_Pos)      /* (RTC_MODE2_CTRLA) Clear on Match Mask */
#define RTC_MODE2_CTRLA_MATCHCLR(value)       (RTC_MODE2_CTRLA_MATCHCLR_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_MATCHCLR_Pos)) /* Assigment of value for MATCHCLR in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_PRESCALER_Pos         _UINT16_(8)                                          /* (RTC_MODE2_CTRLA) Prescaler Position */
#define RTC_MODE2_CTRLA_PRESCALER_Msk         (_UINT16_(0xF) << RTC_MODE2_CTRLA_PRESCALER_Pos)     /* (RTC_MODE2_CTRLA) Prescaler Mask */
#define RTC_MODE2_CTRLA_PRESCALER(value)      (RTC_MODE2_CTRLA_PRESCALER_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_PRESCALER_Pos)) /* Assigment of value for PRESCALER in the RTC_MODE2_CTRLA register */
#define   RTC_MODE2_CTRLA_PRESCALER_OFF_Val   _UINT16_(0x0)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV1_Val  _UINT16_(0x1)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV2_Val  _UINT16_(0x2)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/2  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV4_Val  _UINT16_(0x3)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/4  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV8_Val  _UINT16_(0x4)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/8  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV16_Val _UINT16_(0x5)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/16  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV32_Val _UINT16_(0x6)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/32  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV64_Val _UINT16_(0x7)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/64  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV128_Val _UINT16_(0x8)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/128  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV256_Val _UINT16_(0x9)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/256  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV512_Val _UINT16_(0xA)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/512  */
#define   RTC_MODE2_CTRLA_PRESCALER_DIV1024_Val _UINT16_(0xB)                                        /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024  */
#define RTC_MODE2_CTRLA_PRESCALER_OFF         (RTC_MODE2_CTRLA_PRESCALER_OFF_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV1        (RTC_MODE2_CTRLA_PRESCALER_DIV1_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV2        (RTC_MODE2_CTRLA_PRESCALER_DIV2_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/2 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV4        (RTC_MODE2_CTRLA_PRESCALER_DIV4_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/4 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV8        (RTC_MODE2_CTRLA_PRESCALER_DIV8_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/8 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV16       (RTC_MODE2_CTRLA_PRESCALER_DIV16_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/16 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV32       (RTC_MODE2_CTRLA_PRESCALER_DIV32_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/32 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV64       (RTC_MODE2_CTRLA_PRESCALER_DIV64_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/64 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV128      (RTC_MODE2_CTRLA_PRESCALER_DIV128_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/128 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV256      (RTC_MODE2_CTRLA_PRESCALER_DIV256_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/256 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV512      (RTC_MODE2_CTRLA_PRESCALER_DIV512_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/512 Position  */
#define RTC_MODE2_CTRLA_PRESCALER_DIV1024     (RTC_MODE2_CTRLA_PRESCALER_DIV1024_Val << RTC_MODE2_CTRLA_PRESCALER_Pos) /* (RTC_MODE2_CTRLA) CLK_RTC_CNT = GCLK_RTC/1024 Position  */
#define RTC_MODE2_CTRLA_GPTRST_Pos            _UINT16_(14)                                         /* (RTC_MODE2_CTRLA) GP Registers Reset On Tamper Enable Position */
#define RTC_MODE2_CTRLA_GPTRST_Msk            (_UINT16_(0x1) << RTC_MODE2_CTRLA_GPTRST_Pos)        /* (RTC_MODE2_CTRLA) GP Registers Reset On Tamper Enable Mask */
#define RTC_MODE2_CTRLA_GPTRST(value)         (RTC_MODE2_CTRLA_GPTRST_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_GPTRST_Pos)) /* Assigment of value for GPTRST in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_CLOCKSYNC_Pos         _UINT16_(15)                                         /* (RTC_MODE2_CTRLA) Clock Read Synchronization Enable Position */
#define RTC_MODE2_CTRLA_CLOCKSYNC_Msk         (_UINT16_(0x1) << RTC_MODE2_CTRLA_CLOCKSYNC_Pos)     /* (RTC_MODE2_CTRLA) Clock Read Synchronization Enable Mask */
#define RTC_MODE2_CTRLA_CLOCKSYNC(value)      (RTC_MODE2_CTRLA_CLOCKSYNC_Msk & (_UINT16_(value) << RTC_MODE2_CTRLA_CLOCKSYNC_Pos)) /* Assigment of value for CLOCKSYNC in the RTC_MODE2_CTRLA register */
#define RTC_MODE2_CTRLA_Msk                   _UINT16_(0xCFCF)                                     /* (RTC_MODE2_CTRLA) Register Mask  */


/* -------- RTC_MODE0_CTRLB : (RTC Offset: 0x02) (R/W 16) MODE0 Control B -------- */
#define RTC_MODE0_CTRLB_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE0_CTRLB) MODE0 Control B  Reset Value */

#define RTC_MODE0_CTRLB_GP0EN_Pos             _UINT16_(0)                                          /* (RTC_MODE0_CTRLB) General Purpose 0 Enable Position */
#define RTC_MODE0_CTRLB_GP0EN_Msk             (_UINT16_(0x1) << RTC_MODE0_CTRLB_GP0EN_Pos)         /* (RTC_MODE0_CTRLB) General Purpose 0 Enable Mask */
#define RTC_MODE0_CTRLB_GP0EN(value)          (RTC_MODE0_CTRLB_GP0EN_Msk & (_UINT16_(value) << RTC_MODE0_CTRLB_GP0EN_Pos)) /* Assigment of value for GP0EN in the RTC_MODE0_CTRLB register */
#define RTC_MODE0_CTRLB_DEBMAJ_Pos            _UINT16_(4)                                          /* (RTC_MODE0_CTRLB) Debouncer Majority Enable Position */
#define RTC_MODE0_CTRLB_DEBMAJ_Msk            (_UINT16_(0x1) << RTC_MODE0_CTRLB_DEBMAJ_Pos)        /* (RTC_MODE0_CTRLB) Debouncer Majority Enable Mask */
#define RTC_MODE0_CTRLB_DEBMAJ(value)         (RTC_MODE0_CTRLB_DEBMAJ_Msk & (_UINT16_(value) << RTC_MODE0_CTRLB_DEBMAJ_Pos)) /* Assigment of value for DEBMAJ in the RTC_MODE0_CTRLB register */
#define RTC_MODE0_CTRLB_DEBASYNC_Pos          _UINT16_(5)                                          /* (RTC_MODE0_CTRLB) Debouncer Asynchronous Enable Position */
#define RTC_MODE0_CTRLB_DEBASYNC_Msk          (_UINT16_(0x1) << RTC_MODE0_CTRLB_DEBASYNC_Pos)      /* (RTC_MODE0_CTRLB) Debouncer Asynchronous Enable Mask */
#define RTC_MODE0_CTRLB_DEBASYNC(value)       (RTC_MODE0_CTRLB_DEBASYNC_Msk & (_UINT16_(value) << RTC_MODE0_CTRLB_DEBASYNC_Pos)) /* Assigment of value for DEBASYNC in the RTC_MODE0_CTRLB register */
#define RTC_MODE0_CTRLB_RTCOUT_Pos            _UINT16_(6)                                          /* (RTC_MODE0_CTRLB) RTC Output Enable Position */
#define RTC_MODE0_CTRLB_RTCOUT_Msk            (_UINT16_(0x1) << RTC_MODE0_CTRLB_RTCOUT_Pos)        /* (RTC_MODE0_CTRLB) RTC Output Enable Mask */
#define RTC_MODE0_CTRLB_RTCOUT(value)         (RTC_MODE0_CTRLB_RTCOUT_Msk & (_UINT16_(value) << RTC_MODE0_CTRLB_RTCOUT_Pos)) /* Assigment of value for RTCOUT in the RTC_MODE0_CTRLB register */
#define RTC_MODE0_CTRLB_DMAEN_Pos             _UINT16_(7)                                          /* (RTC_MODE0_CTRLB) DMA Enable Position */
#define RTC_MODE0_CTRLB_DMAEN_Msk             (_UINT16_(0x1) << RTC_MODE0_CTRLB_DMAEN_Pos)         /* (RTC_MODE0_CTRLB) DMA Enable Mask */
#define RTC_MODE0_CTRLB_DMAEN(value)          (RTC_MODE0_CTRLB_DMAEN_Msk & (_UINT16_(value) << RTC_MODE0_CTRLB_DMAEN_Pos)) /* Assigment of value for DMAEN in the RTC_MODE0_CTRLB register */
#define RTC_MODE0_CTRLB_DEBF_Pos              _UINT16_(8)                                          /* (RTC_MODE0_CTRLB) Debounce Frequency Position */
#define RTC_MODE0_CTRLB_DEBF_Msk              (_UINT16_(0x7) << RTC_MODE0_CTRLB_DEBF_Pos)          /* (RTC_MODE0_CTRLB) Debounce Frequency Mask */
#define RTC_MODE0_CTRLB_DEBF(value)           (RTC_MODE0_CTRLB_DEBF_Msk & (_UINT16_(value) << RTC_MODE0_CTRLB_DEBF_Pos)) /* Assigment of value for DEBF in the RTC_MODE0_CTRLB register */
#define   RTC_MODE0_CTRLB_DEBF_DIV2_Val       _UINT16_(0x0)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/2  */
#define   RTC_MODE0_CTRLB_DEBF_DIV4_Val       _UINT16_(0x1)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/4  */
#define   RTC_MODE0_CTRLB_DEBF_DIV8_Val       _UINT16_(0x2)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/8  */
#define   RTC_MODE0_CTRLB_DEBF_DIV16_Val      _UINT16_(0x3)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/16  */
#define   RTC_MODE0_CTRLB_DEBF_DIV32_Val      _UINT16_(0x4)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/32  */
#define   RTC_MODE0_CTRLB_DEBF_DIV64_Val      _UINT16_(0x5)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/64  */
#define   RTC_MODE0_CTRLB_DEBF_DIV128_Val     _UINT16_(0x6)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/128  */
#define   RTC_MODE0_CTRLB_DEBF_DIV256_Val     _UINT16_(0x7)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/256  */
#define RTC_MODE0_CTRLB_DEBF_DIV2             (RTC_MODE0_CTRLB_DEBF_DIV2_Val << RTC_MODE0_CTRLB_DEBF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/2 Position  */
#define RTC_MODE0_CTRLB_DEBF_DIV4             (RTC_MODE0_CTRLB_DEBF_DIV4_Val << RTC_MODE0_CTRLB_DEBF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/4 Position  */
#define RTC_MODE0_CTRLB_DEBF_DIV8             (RTC_MODE0_CTRLB_DEBF_DIV8_Val << RTC_MODE0_CTRLB_DEBF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/8 Position  */
#define RTC_MODE0_CTRLB_DEBF_DIV16            (RTC_MODE0_CTRLB_DEBF_DIV16_Val << RTC_MODE0_CTRLB_DEBF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/16 Position  */
#define RTC_MODE0_CTRLB_DEBF_DIV32            (RTC_MODE0_CTRLB_DEBF_DIV32_Val << RTC_MODE0_CTRLB_DEBF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/32 Position  */
#define RTC_MODE0_CTRLB_DEBF_DIV64            (RTC_MODE0_CTRLB_DEBF_DIV64_Val << RTC_MODE0_CTRLB_DEBF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/64 Position  */
#define RTC_MODE0_CTRLB_DEBF_DIV128           (RTC_MODE0_CTRLB_DEBF_DIV128_Val << RTC_MODE0_CTRLB_DEBF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/128 Position  */
#define RTC_MODE0_CTRLB_DEBF_DIV256           (RTC_MODE0_CTRLB_DEBF_DIV256_Val << RTC_MODE0_CTRLB_DEBF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_DEB = CLK_RTC/256 Position  */
#define RTC_MODE0_CTRLB_ACTF_Pos              _UINT16_(12)                                         /* (RTC_MODE0_CTRLB) Active Layer Frequency Position */
#define RTC_MODE0_CTRLB_ACTF_Msk              (_UINT16_(0x7) << RTC_MODE0_CTRLB_ACTF_Pos)          /* (RTC_MODE0_CTRLB) Active Layer Frequency Mask */
#define RTC_MODE0_CTRLB_ACTF(value)           (RTC_MODE0_CTRLB_ACTF_Msk & (_UINT16_(value) << RTC_MODE0_CTRLB_ACTF_Pos)) /* Assigment of value for ACTF in the RTC_MODE0_CTRLB register */
#define   RTC_MODE0_CTRLB_ACTF_DIV2_Val       _UINT16_(0x0)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/2  */
#define   RTC_MODE0_CTRLB_ACTF_DIV4_Val       _UINT16_(0x1)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/4  */
#define   RTC_MODE0_CTRLB_ACTF_DIV8_Val       _UINT16_(0x2)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/8  */
#define   RTC_MODE0_CTRLB_ACTF_DIV16_Val      _UINT16_(0x3)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/16  */
#define   RTC_MODE0_CTRLB_ACTF_DIV32_Val      _UINT16_(0x4)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/32  */
#define   RTC_MODE0_CTRLB_ACTF_DIV64_Val      _UINT16_(0x5)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/64  */
#define   RTC_MODE0_CTRLB_ACTF_DIV128_Val     _UINT16_(0x6)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/128  */
#define   RTC_MODE0_CTRLB_ACTF_DIV256_Val     _UINT16_(0x7)                                        /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/256  */
#define RTC_MODE0_CTRLB_ACTF_DIV2             (RTC_MODE0_CTRLB_ACTF_DIV2_Val << RTC_MODE0_CTRLB_ACTF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/2 Position  */
#define RTC_MODE0_CTRLB_ACTF_DIV4             (RTC_MODE0_CTRLB_ACTF_DIV4_Val << RTC_MODE0_CTRLB_ACTF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/4 Position  */
#define RTC_MODE0_CTRLB_ACTF_DIV8             (RTC_MODE0_CTRLB_ACTF_DIV8_Val << RTC_MODE0_CTRLB_ACTF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/8 Position  */
#define RTC_MODE0_CTRLB_ACTF_DIV16            (RTC_MODE0_CTRLB_ACTF_DIV16_Val << RTC_MODE0_CTRLB_ACTF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/16 Position  */
#define RTC_MODE0_CTRLB_ACTF_DIV32            (RTC_MODE0_CTRLB_ACTF_DIV32_Val << RTC_MODE0_CTRLB_ACTF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/32 Position  */
#define RTC_MODE0_CTRLB_ACTF_DIV64            (RTC_MODE0_CTRLB_ACTF_DIV64_Val << RTC_MODE0_CTRLB_ACTF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/64 Position  */
#define RTC_MODE0_CTRLB_ACTF_DIV128           (RTC_MODE0_CTRLB_ACTF_DIV128_Val << RTC_MODE0_CTRLB_ACTF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/128 Position  */
#define RTC_MODE0_CTRLB_ACTF_DIV256           (RTC_MODE0_CTRLB_ACTF_DIV256_Val << RTC_MODE0_CTRLB_ACTF_Pos) /* (RTC_MODE0_CTRLB) CLK_RTC_OUT = CLK_RTC/256 Position  */
#define RTC_MODE0_CTRLB_SEPTO_Pos             _UINT16_(15)                                         /* (RTC_MODE0_CTRLB) Separate Tamper Outputs Position */
#define RTC_MODE0_CTRLB_SEPTO_Msk             (_UINT16_(0x1) << RTC_MODE0_CTRLB_SEPTO_Pos)         /* (RTC_MODE0_CTRLB) Separate Tamper Outputs Mask */
#define RTC_MODE0_CTRLB_SEPTO(value)          (RTC_MODE0_CTRLB_SEPTO_Msk & (_UINT16_(value) << RTC_MODE0_CTRLB_SEPTO_Pos)) /* Assigment of value for SEPTO in the RTC_MODE0_CTRLB register */
#define RTC_MODE0_CTRLB_Msk                   _UINT16_(0xF7F1)                                     /* (RTC_MODE0_CTRLB) Register Mask  */


/* -------- RTC_MODE1_CTRLB : (RTC Offset: 0x02) (R/W 16) MODE1 Control B -------- */
#define RTC_MODE1_CTRLB_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE1_CTRLB) MODE1 Control B  Reset Value */

#define RTC_MODE1_CTRLB_GP0EN_Pos             _UINT16_(0)                                          /* (RTC_MODE1_CTRLB) General Purpose 0 Enable Position */
#define RTC_MODE1_CTRLB_GP0EN_Msk             (_UINT16_(0x1) << RTC_MODE1_CTRLB_GP0EN_Pos)         /* (RTC_MODE1_CTRLB) General Purpose 0 Enable Mask */
#define RTC_MODE1_CTRLB_GP0EN(value)          (RTC_MODE1_CTRLB_GP0EN_Msk & (_UINT16_(value) << RTC_MODE1_CTRLB_GP0EN_Pos)) /* Assigment of value for GP0EN in the RTC_MODE1_CTRLB register */
#define RTC_MODE1_CTRLB_DEBMAJ_Pos            _UINT16_(4)                                          /* (RTC_MODE1_CTRLB) Debouncer Majority Enable Position */
#define RTC_MODE1_CTRLB_DEBMAJ_Msk            (_UINT16_(0x1) << RTC_MODE1_CTRLB_DEBMAJ_Pos)        /* (RTC_MODE1_CTRLB) Debouncer Majority Enable Mask */
#define RTC_MODE1_CTRLB_DEBMAJ(value)         (RTC_MODE1_CTRLB_DEBMAJ_Msk & (_UINT16_(value) << RTC_MODE1_CTRLB_DEBMAJ_Pos)) /* Assigment of value for DEBMAJ in the RTC_MODE1_CTRLB register */
#define RTC_MODE1_CTRLB_DEBASYNC_Pos          _UINT16_(5)                                          /* (RTC_MODE1_CTRLB) Debouncer Asynchronous Enable Position */
#define RTC_MODE1_CTRLB_DEBASYNC_Msk          (_UINT16_(0x1) << RTC_MODE1_CTRLB_DEBASYNC_Pos)      /* (RTC_MODE1_CTRLB) Debouncer Asynchronous Enable Mask */
#define RTC_MODE1_CTRLB_DEBASYNC(value)       (RTC_MODE1_CTRLB_DEBASYNC_Msk & (_UINT16_(value) << RTC_MODE1_CTRLB_DEBASYNC_Pos)) /* Assigment of value for DEBASYNC in the RTC_MODE1_CTRLB register */
#define RTC_MODE1_CTRLB_RTCOUT_Pos            _UINT16_(6)                                          /* (RTC_MODE1_CTRLB) RTC Output Enable Position */
#define RTC_MODE1_CTRLB_RTCOUT_Msk            (_UINT16_(0x1) << RTC_MODE1_CTRLB_RTCOUT_Pos)        /* (RTC_MODE1_CTRLB) RTC Output Enable Mask */
#define RTC_MODE1_CTRLB_RTCOUT(value)         (RTC_MODE1_CTRLB_RTCOUT_Msk & (_UINT16_(value) << RTC_MODE1_CTRLB_RTCOUT_Pos)) /* Assigment of value for RTCOUT in the RTC_MODE1_CTRLB register */
#define RTC_MODE1_CTRLB_DMAEN_Pos             _UINT16_(7)                                          /* (RTC_MODE1_CTRLB) DMA Enable Position */
#define RTC_MODE1_CTRLB_DMAEN_Msk             (_UINT16_(0x1) << RTC_MODE1_CTRLB_DMAEN_Pos)         /* (RTC_MODE1_CTRLB) DMA Enable Mask */
#define RTC_MODE1_CTRLB_DMAEN(value)          (RTC_MODE1_CTRLB_DMAEN_Msk & (_UINT16_(value) << RTC_MODE1_CTRLB_DMAEN_Pos)) /* Assigment of value for DMAEN in the RTC_MODE1_CTRLB register */
#define RTC_MODE1_CTRLB_DEBF_Pos              _UINT16_(8)                                          /* (RTC_MODE1_CTRLB) Debounce Frequency Position */
#define RTC_MODE1_CTRLB_DEBF_Msk              (_UINT16_(0x7) << RTC_MODE1_CTRLB_DEBF_Pos)          /* (RTC_MODE1_CTRLB) Debounce Frequency Mask */
#define RTC_MODE1_CTRLB_DEBF(value)           (RTC_MODE1_CTRLB_DEBF_Msk & (_UINT16_(value) << RTC_MODE1_CTRLB_DEBF_Pos)) /* Assigment of value for DEBF in the RTC_MODE1_CTRLB register */
#define   RTC_MODE1_CTRLB_DEBF_DIV2_Val       _UINT16_(0x0)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/2  */
#define   RTC_MODE1_CTRLB_DEBF_DIV4_Val       _UINT16_(0x1)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/4  */
#define   RTC_MODE1_CTRLB_DEBF_DIV8_Val       _UINT16_(0x2)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/8  */
#define   RTC_MODE1_CTRLB_DEBF_DIV16_Val      _UINT16_(0x3)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/16  */
#define   RTC_MODE1_CTRLB_DEBF_DIV32_Val      _UINT16_(0x4)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/32  */
#define   RTC_MODE1_CTRLB_DEBF_DIV64_Val      _UINT16_(0x5)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/64  */
#define   RTC_MODE1_CTRLB_DEBF_DIV128_Val     _UINT16_(0x6)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/128  */
#define   RTC_MODE1_CTRLB_DEBF_DIV256_Val     _UINT16_(0x7)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/256  */
#define RTC_MODE1_CTRLB_DEBF_DIV2             (RTC_MODE1_CTRLB_DEBF_DIV2_Val << RTC_MODE1_CTRLB_DEBF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/2 Position  */
#define RTC_MODE1_CTRLB_DEBF_DIV4             (RTC_MODE1_CTRLB_DEBF_DIV4_Val << RTC_MODE1_CTRLB_DEBF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/4 Position  */
#define RTC_MODE1_CTRLB_DEBF_DIV8             (RTC_MODE1_CTRLB_DEBF_DIV8_Val << RTC_MODE1_CTRLB_DEBF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/8 Position  */
#define RTC_MODE1_CTRLB_DEBF_DIV16            (RTC_MODE1_CTRLB_DEBF_DIV16_Val << RTC_MODE1_CTRLB_DEBF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/16 Position  */
#define RTC_MODE1_CTRLB_DEBF_DIV32            (RTC_MODE1_CTRLB_DEBF_DIV32_Val << RTC_MODE1_CTRLB_DEBF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/32 Position  */
#define RTC_MODE1_CTRLB_DEBF_DIV64            (RTC_MODE1_CTRLB_DEBF_DIV64_Val << RTC_MODE1_CTRLB_DEBF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/64 Position  */
#define RTC_MODE1_CTRLB_DEBF_DIV128           (RTC_MODE1_CTRLB_DEBF_DIV128_Val << RTC_MODE1_CTRLB_DEBF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/128 Position  */
#define RTC_MODE1_CTRLB_DEBF_DIV256           (RTC_MODE1_CTRLB_DEBF_DIV256_Val << RTC_MODE1_CTRLB_DEBF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_DEB = CLK_RTC/256 Position  */
#define RTC_MODE1_CTRLB_ACTF_Pos              _UINT16_(12)                                         /* (RTC_MODE1_CTRLB) Active Layer Frequency Position */
#define RTC_MODE1_CTRLB_ACTF_Msk              (_UINT16_(0x7) << RTC_MODE1_CTRLB_ACTF_Pos)          /* (RTC_MODE1_CTRLB) Active Layer Frequency Mask */
#define RTC_MODE1_CTRLB_ACTF(value)           (RTC_MODE1_CTRLB_ACTF_Msk & (_UINT16_(value) << RTC_MODE1_CTRLB_ACTF_Pos)) /* Assigment of value for ACTF in the RTC_MODE1_CTRLB register */
#define   RTC_MODE1_CTRLB_ACTF_DIV2_Val       _UINT16_(0x0)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/2  */
#define   RTC_MODE1_CTRLB_ACTF_DIV4_Val       _UINT16_(0x1)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/4  */
#define   RTC_MODE1_CTRLB_ACTF_DIV8_Val       _UINT16_(0x2)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/8  */
#define   RTC_MODE1_CTRLB_ACTF_DIV16_Val      _UINT16_(0x3)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/16  */
#define   RTC_MODE1_CTRLB_ACTF_DIV32_Val      _UINT16_(0x4)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/32  */
#define   RTC_MODE1_CTRLB_ACTF_DIV64_Val      _UINT16_(0x5)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/64  */
#define   RTC_MODE1_CTRLB_ACTF_DIV128_Val     _UINT16_(0x6)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/128  */
#define   RTC_MODE1_CTRLB_ACTF_DIV256_Val     _UINT16_(0x7)                                        /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/256  */
#define RTC_MODE1_CTRLB_ACTF_DIV2             (RTC_MODE1_CTRLB_ACTF_DIV2_Val << RTC_MODE1_CTRLB_ACTF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/2 Position  */
#define RTC_MODE1_CTRLB_ACTF_DIV4             (RTC_MODE1_CTRLB_ACTF_DIV4_Val << RTC_MODE1_CTRLB_ACTF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/4 Position  */
#define RTC_MODE1_CTRLB_ACTF_DIV8             (RTC_MODE1_CTRLB_ACTF_DIV8_Val << RTC_MODE1_CTRLB_ACTF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/8 Position  */
#define RTC_MODE1_CTRLB_ACTF_DIV16            (RTC_MODE1_CTRLB_ACTF_DIV16_Val << RTC_MODE1_CTRLB_ACTF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/16 Position  */
#define RTC_MODE1_CTRLB_ACTF_DIV32            (RTC_MODE1_CTRLB_ACTF_DIV32_Val << RTC_MODE1_CTRLB_ACTF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/32 Position  */
#define RTC_MODE1_CTRLB_ACTF_DIV64            (RTC_MODE1_CTRLB_ACTF_DIV64_Val << RTC_MODE1_CTRLB_ACTF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/64 Position  */
#define RTC_MODE1_CTRLB_ACTF_DIV128           (RTC_MODE1_CTRLB_ACTF_DIV128_Val << RTC_MODE1_CTRLB_ACTF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/128 Position  */
#define RTC_MODE1_CTRLB_ACTF_DIV256           (RTC_MODE1_CTRLB_ACTF_DIV256_Val << RTC_MODE1_CTRLB_ACTF_Pos) /* (RTC_MODE1_CTRLB) CLK_RTC_OUT = CLK_RTC/256 Position  */
#define RTC_MODE1_CTRLB_SEPTO_Pos             _UINT16_(15)                                         /* (RTC_MODE1_CTRLB) Separate Tamper Outputs Position */
#define RTC_MODE1_CTRLB_SEPTO_Msk             (_UINT16_(0x1) << RTC_MODE1_CTRLB_SEPTO_Pos)         /* (RTC_MODE1_CTRLB) Separate Tamper Outputs Mask */
#define RTC_MODE1_CTRLB_SEPTO(value)          (RTC_MODE1_CTRLB_SEPTO_Msk & (_UINT16_(value) << RTC_MODE1_CTRLB_SEPTO_Pos)) /* Assigment of value for SEPTO in the RTC_MODE1_CTRLB register */
#define RTC_MODE1_CTRLB_Msk                   _UINT16_(0xF7F1)                                     /* (RTC_MODE1_CTRLB) Register Mask  */


/* -------- RTC_MODE2_CTRLB : (RTC Offset: 0x02) (R/W 16) MODE2 Control B -------- */
#define RTC_MODE2_CTRLB_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE2_CTRLB) MODE2 Control B  Reset Value */

#define RTC_MODE2_CTRLB_GP0EN_Pos             _UINT16_(0)                                          /* (RTC_MODE2_CTRLB) General Purpose 0 Enable Position */
#define RTC_MODE2_CTRLB_GP0EN_Msk             (_UINT16_(0x1) << RTC_MODE2_CTRLB_GP0EN_Pos)         /* (RTC_MODE2_CTRLB) General Purpose 0 Enable Mask */
#define RTC_MODE2_CTRLB_GP0EN(value)          (RTC_MODE2_CTRLB_GP0EN_Msk & (_UINT16_(value) << RTC_MODE2_CTRLB_GP0EN_Pos)) /* Assigment of value for GP0EN in the RTC_MODE2_CTRLB register */
#define RTC_MODE2_CTRLB_DEBMAJ_Pos            _UINT16_(4)                                          /* (RTC_MODE2_CTRLB) Debouncer Majority Enable Position */
#define RTC_MODE2_CTRLB_DEBMAJ_Msk            (_UINT16_(0x1) << RTC_MODE2_CTRLB_DEBMAJ_Pos)        /* (RTC_MODE2_CTRLB) Debouncer Majority Enable Mask */
#define RTC_MODE2_CTRLB_DEBMAJ(value)         (RTC_MODE2_CTRLB_DEBMAJ_Msk & (_UINT16_(value) << RTC_MODE2_CTRLB_DEBMAJ_Pos)) /* Assigment of value for DEBMAJ in the RTC_MODE2_CTRLB register */
#define RTC_MODE2_CTRLB_DEBASYNC_Pos          _UINT16_(5)                                          /* (RTC_MODE2_CTRLB) Debouncer Asynchronous Enable Position */
#define RTC_MODE2_CTRLB_DEBASYNC_Msk          (_UINT16_(0x1) << RTC_MODE2_CTRLB_DEBASYNC_Pos)      /* (RTC_MODE2_CTRLB) Debouncer Asynchronous Enable Mask */
#define RTC_MODE2_CTRLB_DEBASYNC(value)       (RTC_MODE2_CTRLB_DEBASYNC_Msk & (_UINT16_(value) << RTC_MODE2_CTRLB_DEBASYNC_Pos)) /* Assigment of value for DEBASYNC in the RTC_MODE2_CTRLB register */
#define RTC_MODE2_CTRLB_RTCOUT_Pos            _UINT16_(6)                                          /* (RTC_MODE2_CTRLB) RTC Output Enable Position */
#define RTC_MODE2_CTRLB_RTCOUT_Msk            (_UINT16_(0x1) << RTC_MODE2_CTRLB_RTCOUT_Pos)        /* (RTC_MODE2_CTRLB) RTC Output Enable Mask */
#define RTC_MODE2_CTRLB_RTCOUT(value)         (RTC_MODE2_CTRLB_RTCOUT_Msk & (_UINT16_(value) << RTC_MODE2_CTRLB_RTCOUT_Pos)) /* Assigment of value for RTCOUT in the RTC_MODE2_CTRLB register */
#define RTC_MODE2_CTRLB_DMAEN_Pos             _UINT16_(7)                                          /* (RTC_MODE2_CTRLB) DMA Enable Position */
#define RTC_MODE2_CTRLB_DMAEN_Msk             (_UINT16_(0x1) << RTC_MODE2_CTRLB_DMAEN_Pos)         /* (RTC_MODE2_CTRLB) DMA Enable Mask */
#define RTC_MODE2_CTRLB_DMAEN(value)          (RTC_MODE2_CTRLB_DMAEN_Msk & (_UINT16_(value) << RTC_MODE2_CTRLB_DMAEN_Pos)) /* Assigment of value for DMAEN in the RTC_MODE2_CTRLB register */
#define RTC_MODE2_CTRLB_DEBF_Pos              _UINT16_(8)                                          /* (RTC_MODE2_CTRLB) Debounce Frequency Position */
#define RTC_MODE2_CTRLB_DEBF_Msk              (_UINT16_(0x7) << RTC_MODE2_CTRLB_DEBF_Pos)          /* (RTC_MODE2_CTRLB) Debounce Frequency Mask */
#define RTC_MODE2_CTRLB_DEBF(value)           (RTC_MODE2_CTRLB_DEBF_Msk & (_UINT16_(value) << RTC_MODE2_CTRLB_DEBF_Pos)) /* Assigment of value for DEBF in the RTC_MODE2_CTRLB register */
#define   RTC_MODE2_CTRLB_DEBF_DIV2_Val       _UINT16_(0x0)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/2  */
#define   RTC_MODE2_CTRLB_DEBF_DIV4_Val       _UINT16_(0x1)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/4  */
#define   RTC_MODE2_CTRLB_DEBF_DIV8_Val       _UINT16_(0x2)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/8  */
#define   RTC_MODE2_CTRLB_DEBF_DIV16_Val      _UINT16_(0x3)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/16  */
#define   RTC_MODE2_CTRLB_DEBF_DIV32_Val      _UINT16_(0x4)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/32  */
#define   RTC_MODE2_CTRLB_DEBF_DIV64_Val      _UINT16_(0x5)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/64  */
#define   RTC_MODE2_CTRLB_DEBF_DIV128_Val     _UINT16_(0x6)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/128  */
#define   RTC_MODE2_CTRLB_DEBF_DIV256_Val     _UINT16_(0x7)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/256  */
#define RTC_MODE2_CTRLB_DEBF_DIV2             (RTC_MODE2_CTRLB_DEBF_DIV2_Val << RTC_MODE2_CTRLB_DEBF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/2 Position  */
#define RTC_MODE2_CTRLB_DEBF_DIV4             (RTC_MODE2_CTRLB_DEBF_DIV4_Val << RTC_MODE2_CTRLB_DEBF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/4 Position  */
#define RTC_MODE2_CTRLB_DEBF_DIV8             (RTC_MODE2_CTRLB_DEBF_DIV8_Val << RTC_MODE2_CTRLB_DEBF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/8 Position  */
#define RTC_MODE2_CTRLB_DEBF_DIV16            (RTC_MODE2_CTRLB_DEBF_DIV16_Val << RTC_MODE2_CTRLB_DEBF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/16 Position  */
#define RTC_MODE2_CTRLB_DEBF_DIV32            (RTC_MODE2_CTRLB_DEBF_DIV32_Val << RTC_MODE2_CTRLB_DEBF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/32 Position  */
#define RTC_MODE2_CTRLB_DEBF_DIV64            (RTC_MODE2_CTRLB_DEBF_DIV64_Val << RTC_MODE2_CTRLB_DEBF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/64 Position  */
#define RTC_MODE2_CTRLB_DEBF_DIV128           (RTC_MODE2_CTRLB_DEBF_DIV128_Val << RTC_MODE2_CTRLB_DEBF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/128 Position  */
#define RTC_MODE2_CTRLB_DEBF_DIV256           (RTC_MODE2_CTRLB_DEBF_DIV256_Val << RTC_MODE2_CTRLB_DEBF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_DEB = CLK_RTC/256 Position  */
#define RTC_MODE2_CTRLB_ACTF_Pos              _UINT16_(12)                                         /* (RTC_MODE2_CTRLB) Active Layer Frequency Position */
#define RTC_MODE2_CTRLB_ACTF_Msk              (_UINT16_(0x7) << RTC_MODE2_CTRLB_ACTF_Pos)          /* (RTC_MODE2_CTRLB) Active Layer Frequency Mask */
#define RTC_MODE2_CTRLB_ACTF(value)           (RTC_MODE2_CTRLB_ACTF_Msk & (_UINT16_(value) << RTC_MODE2_CTRLB_ACTF_Pos)) /* Assigment of value for ACTF in the RTC_MODE2_CTRLB register */
#define   RTC_MODE2_CTRLB_ACTF_DIV2_Val       _UINT16_(0x0)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/2  */
#define   RTC_MODE2_CTRLB_ACTF_DIV4_Val       _UINT16_(0x1)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/4  */
#define   RTC_MODE2_CTRLB_ACTF_DIV8_Val       _UINT16_(0x2)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/8  */
#define   RTC_MODE2_CTRLB_ACTF_DIV16_Val      _UINT16_(0x3)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/16  */
#define   RTC_MODE2_CTRLB_ACTF_DIV32_Val      _UINT16_(0x4)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/32  */
#define   RTC_MODE2_CTRLB_ACTF_DIV64_Val      _UINT16_(0x5)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/64  */
#define   RTC_MODE2_CTRLB_ACTF_DIV128_Val     _UINT16_(0x6)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/128  */
#define   RTC_MODE2_CTRLB_ACTF_DIV256_Val     _UINT16_(0x7)                                        /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/256  */
#define RTC_MODE2_CTRLB_ACTF_DIV2             (RTC_MODE2_CTRLB_ACTF_DIV2_Val << RTC_MODE2_CTRLB_ACTF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/2 Position  */
#define RTC_MODE2_CTRLB_ACTF_DIV4             (RTC_MODE2_CTRLB_ACTF_DIV4_Val << RTC_MODE2_CTRLB_ACTF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/4 Position  */
#define RTC_MODE2_CTRLB_ACTF_DIV8             (RTC_MODE2_CTRLB_ACTF_DIV8_Val << RTC_MODE2_CTRLB_ACTF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/8 Position  */
#define RTC_MODE2_CTRLB_ACTF_DIV16            (RTC_MODE2_CTRLB_ACTF_DIV16_Val << RTC_MODE2_CTRLB_ACTF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/16 Position  */
#define RTC_MODE2_CTRLB_ACTF_DIV32            (RTC_MODE2_CTRLB_ACTF_DIV32_Val << RTC_MODE2_CTRLB_ACTF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/32 Position  */
#define RTC_MODE2_CTRLB_ACTF_DIV64            (RTC_MODE2_CTRLB_ACTF_DIV64_Val << RTC_MODE2_CTRLB_ACTF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/64 Position  */
#define RTC_MODE2_CTRLB_ACTF_DIV128           (RTC_MODE2_CTRLB_ACTF_DIV128_Val << RTC_MODE2_CTRLB_ACTF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/128 Position  */
#define RTC_MODE2_CTRLB_ACTF_DIV256           (RTC_MODE2_CTRLB_ACTF_DIV256_Val << RTC_MODE2_CTRLB_ACTF_Pos) /* (RTC_MODE2_CTRLB) CLK_RTC_OUT = CLK_RTC/256 Position  */
#define RTC_MODE2_CTRLB_SEPTO_Pos             _UINT16_(15)                                         /* (RTC_MODE2_CTRLB) Separate Tamper Outputs Position */
#define RTC_MODE2_CTRLB_SEPTO_Msk             (_UINT16_(0x1) << RTC_MODE2_CTRLB_SEPTO_Pos)         /* (RTC_MODE2_CTRLB) Separate Tamper Outputs Mask */
#define RTC_MODE2_CTRLB_SEPTO(value)          (RTC_MODE2_CTRLB_SEPTO_Msk & (_UINT16_(value) << RTC_MODE2_CTRLB_SEPTO_Pos)) /* Assigment of value for SEPTO in the RTC_MODE2_CTRLB register */
#define RTC_MODE2_CTRLB_Msk                   _UINT16_(0xF7F1)                                     /* (RTC_MODE2_CTRLB) Register Mask  */


/* -------- RTC_MODE0_EVCTRL : (RTC Offset: 0x04) (R/W 32) MODE0 Event Control -------- */
#define RTC_MODE0_EVCTRL_RESETVALUE           _UINT32_(0x00)                                       /*  (RTC_MODE0_EVCTRL) MODE0 Event Control  Reset Value */

#define RTC_MODE0_EVCTRL_PEREO0_Pos           _UINT32_(0)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 0 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO0_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO0_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 0 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO0(value)        (RTC_MODE0_EVCTRL_PEREO0_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO0_Pos)) /* Assigment of value for PEREO0 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO1_Pos           _UINT32_(1)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 1 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO1_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO1_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 1 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO1(value)        (RTC_MODE0_EVCTRL_PEREO1_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO1_Pos)) /* Assigment of value for PEREO1 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO2_Pos           _UINT32_(2)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 2 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO2_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO2_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 2 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO2(value)        (RTC_MODE0_EVCTRL_PEREO2_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO2_Pos)) /* Assigment of value for PEREO2 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO3_Pos           _UINT32_(3)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 3 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO3_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO3_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 3 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO3(value)        (RTC_MODE0_EVCTRL_PEREO3_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO3_Pos)) /* Assigment of value for PEREO3 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO4_Pos           _UINT32_(4)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 4 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO4_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO4_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 4 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO4(value)        (RTC_MODE0_EVCTRL_PEREO4_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO4_Pos)) /* Assigment of value for PEREO4 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO5_Pos           _UINT32_(5)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 5 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO5_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO5_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 5 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO5(value)        (RTC_MODE0_EVCTRL_PEREO5_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO5_Pos)) /* Assigment of value for PEREO5 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO6_Pos           _UINT32_(6)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 6 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO6_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO6_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 6 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO6(value)        (RTC_MODE0_EVCTRL_PEREO6_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO6_Pos)) /* Assigment of value for PEREO6 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PEREO7_Pos           _UINT32_(7)                                          /* (RTC_MODE0_EVCTRL) Periodic Interval 7 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PEREO7_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PEREO7_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval 7 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PEREO7(value)        (RTC_MODE0_EVCTRL_PEREO7_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO7_Pos)) /* Assigment of value for PEREO7 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_CMPEO0_Pos           _UINT32_(8)                                          /* (RTC_MODE0_EVCTRL) Compare 0 Event Output Enable Position */
#define RTC_MODE0_EVCTRL_CMPEO0_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_CMPEO0_Pos)       /* (RTC_MODE0_EVCTRL) Compare 0 Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_CMPEO0(value)        (RTC_MODE0_EVCTRL_CMPEO0_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_CMPEO0_Pos)) /* Assigment of value for CMPEO0 in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_TAMPEREO_Pos         _UINT32_(14)                                         /* (RTC_MODE0_EVCTRL) Tamper Event Output Enable Position */
#define RTC_MODE0_EVCTRL_TAMPEREO_Msk         (_UINT32_(0x1) << RTC_MODE0_EVCTRL_TAMPEREO_Pos)     /* (RTC_MODE0_EVCTRL) Tamper Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_TAMPEREO(value)      (RTC_MODE0_EVCTRL_TAMPEREO_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_TAMPEREO_Pos)) /* Assigment of value for TAMPEREO in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_OVFEO_Pos            _UINT32_(15)                                         /* (RTC_MODE0_EVCTRL) Overflow Event Output Enable Position */
#define RTC_MODE0_EVCTRL_OVFEO_Msk            (_UINT32_(0x1) << RTC_MODE0_EVCTRL_OVFEO_Pos)        /* (RTC_MODE0_EVCTRL) Overflow Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_OVFEO(value)         (RTC_MODE0_EVCTRL_OVFEO_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_OVFEO_Pos)) /* Assigment of value for OVFEO in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_TAMPEVEI_Pos         _UINT32_(16)                                         /* (RTC_MODE0_EVCTRL) Tamper Event Input Enable Position */
#define RTC_MODE0_EVCTRL_TAMPEVEI_Msk         (_UINT32_(0x1) << RTC_MODE0_EVCTRL_TAMPEVEI_Pos)     /* (RTC_MODE0_EVCTRL) Tamper Event Input Enable Mask */
#define RTC_MODE0_EVCTRL_TAMPEVEI(value)      (RTC_MODE0_EVCTRL_TAMPEVEI_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_TAMPEVEI_Pos)) /* Assigment of value for TAMPEVEI in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_PERDEO_Pos           _UINT32_(24)                                         /* (RTC_MODE0_EVCTRL) Periodic Interval Daily Event Output Enable Position */
#define RTC_MODE0_EVCTRL_PERDEO_Msk           (_UINT32_(0x1) << RTC_MODE0_EVCTRL_PERDEO_Pos)       /* (RTC_MODE0_EVCTRL) Periodic Interval Daily Event Output Enable Mask */
#define RTC_MODE0_EVCTRL_PERDEO(value)        (RTC_MODE0_EVCTRL_PERDEO_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PERDEO_Pos)) /* Assigment of value for PERDEO in the RTC_MODE0_EVCTRL register */
#define RTC_MODE0_EVCTRL_Msk                  _UINT32_(0x0101C1FF)                                 /* (RTC_MODE0_EVCTRL) Register Mask  */

#define RTC_MODE0_EVCTRL_PEREO_Pos            _UINT32_(0)                                          /* (RTC_MODE0_EVCTRL Position) Periodic Interval x Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO_Msk            (_UINT32_(0xFF) << RTC_MODE0_EVCTRL_PEREO_Pos)       /* (RTC_MODE0_EVCTRL Mask) PEREO */
#define RTC_MODE0_EVCTRL_PEREO(value)         (RTC_MODE0_EVCTRL_PEREO_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_PEREO_Pos)) 
#define RTC_MODE0_EVCTRL_CMPEO_Pos            _UINT32_(8)                                          /* (RTC_MODE0_EVCTRL Position) Compare x Event Output Enable */
#define RTC_MODE0_EVCTRL_CMPEO_Msk            (_UINT32_(0x1) << RTC_MODE0_EVCTRL_CMPEO_Pos)        /* (RTC_MODE0_EVCTRL Mask) CMPEO */
#define RTC_MODE0_EVCTRL_CMPEO(value)         (RTC_MODE0_EVCTRL_CMPEO_Msk & (_UINT32_(value) << RTC_MODE0_EVCTRL_CMPEO_Pos)) 

/* -------- RTC_MODE1_EVCTRL : (RTC Offset: 0x04) (R/W 32) MODE1 Event Control -------- */
#define RTC_MODE1_EVCTRL_RESETVALUE           _UINT32_(0x00)                                       /*  (RTC_MODE1_EVCTRL) MODE1 Event Control  Reset Value */

#define RTC_MODE1_EVCTRL_PEREO0_Pos           _UINT32_(0)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 0 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO0_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO0_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 0 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO0(value)        (RTC_MODE1_EVCTRL_PEREO0_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO0_Pos)) /* Assigment of value for PEREO0 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO1_Pos           _UINT32_(1)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 1 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO1_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO1_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 1 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO1(value)        (RTC_MODE1_EVCTRL_PEREO1_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO1_Pos)) /* Assigment of value for PEREO1 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO2_Pos           _UINT32_(2)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 2 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO2_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO2_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 2 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO2(value)        (RTC_MODE1_EVCTRL_PEREO2_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO2_Pos)) /* Assigment of value for PEREO2 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO3_Pos           _UINT32_(3)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 3 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO3_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO3_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 3 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO3(value)        (RTC_MODE1_EVCTRL_PEREO3_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO3_Pos)) /* Assigment of value for PEREO3 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO4_Pos           _UINT32_(4)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 4 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO4_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO4_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 4 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO4(value)        (RTC_MODE1_EVCTRL_PEREO4_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO4_Pos)) /* Assigment of value for PEREO4 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO5_Pos           _UINT32_(5)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 5 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO5_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO5_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 5 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO5(value)        (RTC_MODE1_EVCTRL_PEREO5_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO5_Pos)) /* Assigment of value for PEREO5 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO6_Pos           _UINT32_(6)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 6 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO6_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO6_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 6 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO6(value)        (RTC_MODE1_EVCTRL_PEREO6_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO6_Pos)) /* Assigment of value for PEREO6 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PEREO7_Pos           _UINT32_(7)                                          /* (RTC_MODE1_EVCTRL) Periodic Interval 7 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PEREO7_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PEREO7_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval 7 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PEREO7(value)        (RTC_MODE1_EVCTRL_PEREO7_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO7_Pos)) /* Assigment of value for PEREO7 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_CMPEO0_Pos           _UINT32_(8)                                          /* (RTC_MODE1_EVCTRL) Compare 0 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_CMPEO0_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_CMPEO0_Pos)       /* (RTC_MODE1_EVCTRL) Compare 0 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_CMPEO0(value)        (RTC_MODE1_EVCTRL_CMPEO0_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_CMPEO0_Pos)) /* Assigment of value for CMPEO0 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_CMPEO1_Pos           _UINT32_(9)                                          /* (RTC_MODE1_EVCTRL) Compare 1 Event Output Enable Position */
#define RTC_MODE1_EVCTRL_CMPEO1_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_CMPEO1_Pos)       /* (RTC_MODE1_EVCTRL) Compare 1 Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_CMPEO1(value)        (RTC_MODE1_EVCTRL_CMPEO1_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_CMPEO1_Pos)) /* Assigment of value for CMPEO1 in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_TAMPEREO_Pos         _UINT32_(14)                                         /* (RTC_MODE1_EVCTRL) Tamper Event Output Enable Position */
#define RTC_MODE1_EVCTRL_TAMPEREO_Msk         (_UINT32_(0x1) << RTC_MODE1_EVCTRL_TAMPEREO_Pos)     /* (RTC_MODE1_EVCTRL) Tamper Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_TAMPEREO(value)      (RTC_MODE1_EVCTRL_TAMPEREO_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_TAMPEREO_Pos)) /* Assigment of value for TAMPEREO in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_OVFEO_Pos            _UINT32_(15)                                         /* (RTC_MODE1_EVCTRL) Overflow Event Output Enable Position */
#define RTC_MODE1_EVCTRL_OVFEO_Msk            (_UINT32_(0x1) << RTC_MODE1_EVCTRL_OVFEO_Pos)        /* (RTC_MODE1_EVCTRL) Overflow Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_OVFEO(value)         (RTC_MODE1_EVCTRL_OVFEO_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_OVFEO_Pos)) /* Assigment of value for OVFEO in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_TAMPEVEI_Pos         _UINT32_(16)                                         /* (RTC_MODE1_EVCTRL) Tamper Event Input Enable Position */
#define RTC_MODE1_EVCTRL_TAMPEVEI_Msk         (_UINT32_(0x1) << RTC_MODE1_EVCTRL_TAMPEVEI_Pos)     /* (RTC_MODE1_EVCTRL) Tamper Event Input Enable Mask */
#define RTC_MODE1_EVCTRL_TAMPEVEI(value)      (RTC_MODE1_EVCTRL_TAMPEVEI_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_TAMPEVEI_Pos)) /* Assigment of value for TAMPEVEI in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_PERDEO_Pos           _UINT32_(24)                                         /* (RTC_MODE1_EVCTRL) Periodic Interval Daily Event Output Enable Position */
#define RTC_MODE1_EVCTRL_PERDEO_Msk           (_UINT32_(0x1) << RTC_MODE1_EVCTRL_PERDEO_Pos)       /* (RTC_MODE1_EVCTRL) Periodic Interval Daily Event Output Enable Mask */
#define RTC_MODE1_EVCTRL_PERDEO(value)        (RTC_MODE1_EVCTRL_PERDEO_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PERDEO_Pos)) /* Assigment of value for PERDEO in the RTC_MODE1_EVCTRL register */
#define RTC_MODE1_EVCTRL_Msk                  _UINT32_(0x0101C3FF)                                 /* (RTC_MODE1_EVCTRL) Register Mask  */

#define RTC_MODE1_EVCTRL_PEREO_Pos            _UINT32_(0)                                          /* (RTC_MODE1_EVCTRL Position) Periodic Interval x Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO_Msk            (_UINT32_(0xFF) << RTC_MODE1_EVCTRL_PEREO_Pos)       /* (RTC_MODE1_EVCTRL Mask) PEREO */
#define RTC_MODE1_EVCTRL_PEREO(value)         (RTC_MODE1_EVCTRL_PEREO_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_PEREO_Pos)) 
#define RTC_MODE1_EVCTRL_CMPEO_Pos            _UINT32_(8)                                          /* (RTC_MODE1_EVCTRL Position) Compare x Event Output Enable */
#define RTC_MODE1_EVCTRL_CMPEO_Msk            (_UINT32_(0x3) << RTC_MODE1_EVCTRL_CMPEO_Pos)        /* (RTC_MODE1_EVCTRL Mask) CMPEO */
#define RTC_MODE1_EVCTRL_CMPEO(value)         (RTC_MODE1_EVCTRL_CMPEO_Msk & (_UINT32_(value) << RTC_MODE1_EVCTRL_CMPEO_Pos)) 

/* -------- RTC_MODE2_EVCTRL : (RTC Offset: 0x04) (R/W 32) MODE2 Event Control -------- */
#define RTC_MODE2_EVCTRL_RESETVALUE           _UINT32_(0x00)                                       /*  (RTC_MODE2_EVCTRL) MODE2 Event Control  Reset Value */

#define RTC_MODE2_EVCTRL_PEREO0_Pos           _UINT32_(0)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 0 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO0_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO0_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 0 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO0(value)        (RTC_MODE2_EVCTRL_PEREO0_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO0_Pos)) /* Assigment of value for PEREO0 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO1_Pos           _UINT32_(1)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 1 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO1_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO1_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 1 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO1(value)        (RTC_MODE2_EVCTRL_PEREO1_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO1_Pos)) /* Assigment of value for PEREO1 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO2_Pos           _UINT32_(2)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 2 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO2_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO2_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 2 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO2(value)        (RTC_MODE2_EVCTRL_PEREO2_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO2_Pos)) /* Assigment of value for PEREO2 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO3_Pos           _UINT32_(3)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 3 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO3_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO3_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 3 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO3(value)        (RTC_MODE2_EVCTRL_PEREO3_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO3_Pos)) /* Assigment of value for PEREO3 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO4_Pos           _UINT32_(4)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 4 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO4_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO4_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 4 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO4(value)        (RTC_MODE2_EVCTRL_PEREO4_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO4_Pos)) /* Assigment of value for PEREO4 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO5_Pos           _UINT32_(5)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 5 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO5_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO5_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 5 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO5(value)        (RTC_MODE2_EVCTRL_PEREO5_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO5_Pos)) /* Assigment of value for PEREO5 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO6_Pos           _UINT32_(6)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 6 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO6_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO6_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 6 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO6(value)        (RTC_MODE2_EVCTRL_PEREO6_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO6_Pos)) /* Assigment of value for PEREO6 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PEREO7_Pos           _UINT32_(7)                                          /* (RTC_MODE2_EVCTRL) Periodic Interval 7 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PEREO7_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PEREO7_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval 7 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PEREO7(value)        (RTC_MODE2_EVCTRL_PEREO7_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO7_Pos)) /* Assigment of value for PEREO7 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_ALARMEO0_Pos         _UINT32_(8)                                          /* (RTC_MODE2_EVCTRL) Alarm 0 Event Output Enable Position */
#define RTC_MODE2_EVCTRL_ALARMEO0_Msk         (_UINT32_(0x1) << RTC_MODE2_EVCTRL_ALARMEO0_Pos)     /* (RTC_MODE2_EVCTRL) Alarm 0 Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_ALARMEO0(value)      (RTC_MODE2_EVCTRL_ALARMEO0_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_ALARMEO0_Pos)) /* Assigment of value for ALARMEO0 in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_TAMPEREO_Pos         _UINT32_(14)                                         /* (RTC_MODE2_EVCTRL) Tamper Event Output Enable Position */
#define RTC_MODE2_EVCTRL_TAMPEREO_Msk         (_UINT32_(0x1) << RTC_MODE2_EVCTRL_TAMPEREO_Pos)     /* (RTC_MODE2_EVCTRL) Tamper Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_TAMPEREO(value)      (RTC_MODE2_EVCTRL_TAMPEREO_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_TAMPEREO_Pos)) /* Assigment of value for TAMPEREO in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_OVFEO_Pos            _UINT32_(15)                                         /* (RTC_MODE2_EVCTRL) Overflow Event Output Enable Position */
#define RTC_MODE2_EVCTRL_OVFEO_Msk            (_UINT32_(0x1) << RTC_MODE2_EVCTRL_OVFEO_Pos)        /* (RTC_MODE2_EVCTRL) Overflow Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_OVFEO(value)         (RTC_MODE2_EVCTRL_OVFEO_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_OVFEO_Pos)) /* Assigment of value for OVFEO in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_TAMPEVEI_Pos         _UINT32_(16)                                         /* (RTC_MODE2_EVCTRL) Tamper Event Input Enable Position */
#define RTC_MODE2_EVCTRL_TAMPEVEI_Msk         (_UINT32_(0x1) << RTC_MODE2_EVCTRL_TAMPEVEI_Pos)     /* (RTC_MODE2_EVCTRL) Tamper Event Input Enable Mask */
#define RTC_MODE2_EVCTRL_TAMPEVEI(value)      (RTC_MODE2_EVCTRL_TAMPEVEI_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_TAMPEVEI_Pos)) /* Assigment of value for TAMPEVEI in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_PERDEO_Pos           _UINT32_(24)                                         /* (RTC_MODE2_EVCTRL) Periodic Interval Daily Event Output Enable Position */
#define RTC_MODE2_EVCTRL_PERDEO_Msk           (_UINT32_(0x1) << RTC_MODE2_EVCTRL_PERDEO_Pos)       /* (RTC_MODE2_EVCTRL) Periodic Interval Daily Event Output Enable Mask */
#define RTC_MODE2_EVCTRL_PERDEO(value)        (RTC_MODE2_EVCTRL_PERDEO_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PERDEO_Pos)) /* Assigment of value for PERDEO in the RTC_MODE2_EVCTRL register */
#define RTC_MODE2_EVCTRL_Msk                  _UINT32_(0x0101C1FF)                                 /* (RTC_MODE2_EVCTRL) Register Mask  */

#define RTC_MODE2_EVCTRL_PEREO_Pos            _UINT32_(0)                                          /* (RTC_MODE2_EVCTRL Position) Periodic Interval x Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO_Msk            (_UINT32_(0xFF) << RTC_MODE2_EVCTRL_PEREO_Pos)       /* (RTC_MODE2_EVCTRL Mask) PEREO */
#define RTC_MODE2_EVCTRL_PEREO(value)         (RTC_MODE2_EVCTRL_PEREO_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_PEREO_Pos)) 
#define RTC_MODE2_EVCTRL_ALARMEO_Pos          _UINT32_(8)                                          /* (RTC_MODE2_EVCTRL Position) Alarm x Event Output Enable */
#define RTC_MODE2_EVCTRL_ALARMEO_Msk          (_UINT32_(0x1) << RTC_MODE2_EVCTRL_ALARMEO_Pos)      /* (RTC_MODE2_EVCTRL Mask) ALARMEO */
#define RTC_MODE2_EVCTRL_ALARMEO(value)       (RTC_MODE2_EVCTRL_ALARMEO_Msk & (_UINT32_(value) << RTC_MODE2_EVCTRL_ALARMEO_Pos)) 

/* -------- RTC_MODE0_INTENCLR : (RTC Offset: 0x08) (R/W 16) MODE0 Interrupt Enable Clear -------- */
#define RTC_MODE0_INTENCLR_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE0_INTENCLR) MODE0 Interrupt Enable Clear  Reset Value */

#define RTC_MODE0_INTENCLR_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER0_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER0_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER0(value)        (RTC_MODE0_INTENCLR_PER0_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER0_Pos)) /* Assigment of value for PER0 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER1_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER1_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER1(value)        (RTC_MODE0_INTENCLR_PER1_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER1_Pos)) /* Assigment of value for PER1 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER2_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER2_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER2(value)        (RTC_MODE0_INTENCLR_PER2_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER2_Pos)) /* Assigment of value for PER2 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER3_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER3_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER3(value)        (RTC_MODE0_INTENCLR_PER3_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER3_Pos)) /* Assigment of value for PER3 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER4_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER4_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER4(value)        (RTC_MODE0_INTENCLR_PER4_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER4_Pos)) /* Assigment of value for PER4 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER5_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER5_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER5(value)        (RTC_MODE0_INTENCLR_PER5_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER5_Pos)) /* Assigment of value for PER5 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER6_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER6_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER6(value)        (RTC_MODE0_INTENCLR_PER6_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER6_Pos)) /* Assigment of value for PER6 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE0_INTENCLR) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_PER7_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_PER7_Pos)       /* (RTC_MODE0_INTENCLR) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_PER7(value)        (RTC_MODE0_INTENCLR_PER7_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER7_Pos)) /* Assigment of value for PER7 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_CMP0_Pos           _UINT16_(8)                                          /* (RTC_MODE0_INTENCLR) Compare 0 Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_CMP0_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENCLR_CMP0_Pos)       /* (RTC_MODE0_INTENCLR) Compare 0 Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_CMP0(value)        (RTC_MODE0_INTENCLR_CMP0_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_CMP0_Pos)) /* Assigment of value for CMP0 in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_TAMPER_Pos         _UINT16_(14)                                         /* (RTC_MODE0_INTENCLR) Tamper Enable Position */
#define RTC_MODE0_INTENCLR_TAMPER_Msk         (_UINT16_(0x1) << RTC_MODE0_INTENCLR_TAMPER_Pos)     /* (RTC_MODE0_INTENCLR) Tamper Enable Mask */
#define RTC_MODE0_INTENCLR_TAMPER(value)      (RTC_MODE0_INTENCLR_TAMPER_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_TAMPER_Pos)) /* Assigment of value for TAMPER in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE0_INTENCLR) Overflow Interrupt Enable Position */
#define RTC_MODE0_INTENCLR_OVF_Msk            (_UINT16_(0x1) << RTC_MODE0_INTENCLR_OVF_Pos)        /* (RTC_MODE0_INTENCLR) Overflow Interrupt Enable Mask */
#define RTC_MODE0_INTENCLR_OVF(value)         (RTC_MODE0_INTENCLR_OVF_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_OVF_Pos)) /* Assigment of value for OVF in the RTC_MODE0_INTENCLR register */
#define RTC_MODE0_INTENCLR_Msk                _UINT16_(0xC1FF)                                     /* (RTC_MODE0_INTENCLR) Register Mask  */

#define RTC_MODE0_INTENCLR_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE0_INTENCLR Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE0_INTENCLR_PER_Msk            (_UINT16_(0xFF) << RTC_MODE0_INTENCLR_PER_Pos)       /* (RTC_MODE0_INTENCLR Mask) PER */
#define RTC_MODE0_INTENCLR_PER(value)         (RTC_MODE0_INTENCLR_PER_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_PER_Pos)) 
#define RTC_MODE0_INTENCLR_CMP_Pos            _UINT16_(8)                                          /* (RTC_MODE0_INTENCLR Position) Compare x Interrupt Enable */
#define RTC_MODE0_INTENCLR_CMP_Msk            (_UINT16_(0x1) << RTC_MODE0_INTENCLR_CMP_Pos)        /* (RTC_MODE0_INTENCLR Mask) CMP */
#define RTC_MODE0_INTENCLR_CMP(value)         (RTC_MODE0_INTENCLR_CMP_Msk & (_UINT16_(value) << RTC_MODE0_INTENCLR_CMP_Pos)) 

/* -------- RTC_MODE1_INTENCLR : (RTC Offset: 0x08) (R/W 16) MODE1 Interrupt Enable Clear -------- */
#define RTC_MODE1_INTENCLR_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE1_INTENCLR) MODE1 Interrupt Enable Clear  Reset Value */

#define RTC_MODE1_INTENCLR_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER0_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER0_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER0(value)        (RTC_MODE1_INTENCLR_PER0_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER0_Pos)) /* Assigment of value for PER0 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER1_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER1_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER1(value)        (RTC_MODE1_INTENCLR_PER1_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER1_Pos)) /* Assigment of value for PER1 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER2_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER2_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER2(value)        (RTC_MODE1_INTENCLR_PER2_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER2_Pos)) /* Assigment of value for PER2 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER3_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER3_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER3(value)        (RTC_MODE1_INTENCLR_PER3_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER3_Pos)) /* Assigment of value for PER3 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER4_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER4_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER4(value)        (RTC_MODE1_INTENCLR_PER4_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER4_Pos)) /* Assigment of value for PER4 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER5_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER5_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER5(value)        (RTC_MODE1_INTENCLR_PER5_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER5_Pos)) /* Assigment of value for PER5 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER6_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER6_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER6(value)        (RTC_MODE1_INTENCLR_PER6_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER6_Pos)) /* Assigment of value for PER6 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE1_INTENCLR) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_PER7_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_PER7_Pos)       /* (RTC_MODE1_INTENCLR) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_PER7(value)        (RTC_MODE1_INTENCLR_PER7_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER7_Pos)) /* Assigment of value for PER7 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_CMP0_Pos           _UINT16_(8)                                          /* (RTC_MODE1_INTENCLR) Compare 0 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_CMP0_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_CMP0_Pos)       /* (RTC_MODE1_INTENCLR) Compare 0 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_CMP0(value)        (RTC_MODE1_INTENCLR_CMP0_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_CMP0_Pos)) /* Assigment of value for CMP0 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_CMP1_Pos           _UINT16_(9)                                          /* (RTC_MODE1_INTENCLR) Compare 1 Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_CMP1_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENCLR_CMP1_Pos)       /* (RTC_MODE1_INTENCLR) Compare 1 Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_CMP1(value)        (RTC_MODE1_INTENCLR_CMP1_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_CMP1_Pos)) /* Assigment of value for CMP1 in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_TAMPER_Pos         _UINT16_(14)                                         /* (RTC_MODE1_INTENCLR) Tamper Enable Position */
#define RTC_MODE1_INTENCLR_TAMPER_Msk         (_UINT16_(0x1) << RTC_MODE1_INTENCLR_TAMPER_Pos)     /* (RTC_MODE1_INTENCLR) Tamper Enable Mask */
#define RTC_MODE1_INTENCLR_TAMPER(value)      (RTC_MODE1_INTENCLR_TAMPER_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_TAMPER_Pos)) /* Assigment of value for TAMPER in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE1_INTENCLR) Overflow Interrupt Enable Position */
#define RTC_MODE1_INTENCLR_OVF_Msk            (_UINT16_(0x1) << RTC_MODE1_INTENCLR_OVF_Pos)        /* (RTC_MODE1_INTENCLR) Overflow Interrupt Enable Mask */
#define RTC_MODE1_INTENCLR_OVF(value)         (RTC_MODE1_INTENCLR_OVF_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_OVF_Pos)) /* Assigment of value for OVF in the RTC_MODE1_INTENCLR register */
#define RTC_MODE1_INTENCLR_Msk                _UINT16_(0xC3FF)                                     /* (RTC_MODE1_INTENCLR) Register Mask  */

#define RTC_MODE1_INTENCLR_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE1_INTENCLR Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE1_INTENCLR_PER_Msk            (_UINT16_(0xFF) << RTC_MODE1_INTENCLR_PER_Pos)       /* (RTC_MODE1_INTENCLR Mask) PER */
#define RTC_MODE1_INTENCLR_PER(value)         (RTC_MODE1_INTENCLR_PER_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_PER_Pos)) 
#define RTC_MODE1_INTENCLR_CMP_Pos            _UINT16_(8)                                          /* (RTC_MODE1_INTENCLR Position) Compare x Interrupt Enable */
#define RTC_MODE1_INTENCLR_CMP_Msk            (_UINT16_(0x3) << RTC_MODE1_INTENCLR_CMP_Pos)        /* (RTC_MODE1_INTENCLR Mask) CMP */
#define RTC_MODE1_INTENCLR_CMP(value)         (RTC_MODE1_INTENCLR_CMP_Msk & (_UINT16_(value) << RTC_MODE1_INTENCLR_CMP_Pos)) 

/* -------- RTC_MODE2_INTENCLR : (RTC Offset: 0x08) (R/W 16) MODE2 Interrupt Enable Clear -------- */
#define RTC_MODE2_INTENCLR_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE2_INTENCLR) MODE2 Interrupt Enable Clear  Reset Value */

#define RTC_MODE2_INTENCLR_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER0_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER0_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER0(value)        (RTC_MODE2_INTENCLR_PER0_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER0_Pos)) /* Assigment of value for PER0 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER1_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER1_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER1(value)        (RTC_MODE2_INTENCLR_PER1_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER1_Pos)) /* Assigment of value for PER1 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER2_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER2_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER2(value)        (RTC_MODE2_INTENCLR_PER2_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER2_Pos)) /* Assigment of value for PER2 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER3_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER3_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER3(value)        (RTC_MODE2_INTENCLR_PER3_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER3_Pos)) /* Assigment of value for PER3 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER4_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER4_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER4(value)        (RTC_MODE2_INTENCLR_PER4_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER4_Pos)) /* Assigment of value for PER4 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER5_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER5_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER5(value)        (RTC_MODE2_INTENCLR_PER5_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER5_Pos)) /* Assigment of value for PER5 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER6_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER6_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER6(value)        (RTC_MODE2_INTENCLR_PER6_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER6_Pos)) /* Assigment of value for PER6 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE2_INTENCLR) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_PER7_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENCLR_PER7_Pos)       /* (RTC_MODE2_INTENCLR) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_PER7(value)        (RTC_MODE2_INTENCLR_PER7_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER7_Pos)) /* Assigment of value for PER7 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_ALARM0_Pos         _UINT16_(8)                                          /* (RTC_MODE2_INTENCLR) Alarm 0 Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_ALARM0_Msk         (_UINT16_(0x1) << RTC_MODE2_INTENCLR_ALARM0_Pos)     /* (RTC_MODE2_INTENCLR) Alarm 0 Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_ALARM0(value)      (RTC_MODE2_INTENCLR_ALARM0_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_ALARM0_Pos)) /* Assigment of value for ALARM0 in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_TAMPER_Pos         _UINT16_(14)                                         /* (RTC_MODE2_INTENCLR) Tamper Enable Position */
#define RTC_MODE2_INTENCLR_TAMPER_Msk         (_UINT16_(0x1) << RTC_MODE2_INTENCLR_TAMPER_Pos)     /* (RTC_MODE2_INTENCLR) Tamper Enable Mask */
#define RTC_MODE2_INTENCLR_TAMPER(value)      (RTC_MODE2_INTENCLR_TAMPER_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_TAMPER_Pos)) /* Assigment of value for TAMPER in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE2_INTENCLR) Overflow Interrupt Enable Position */
#define RTC_MODE2_INTENCLR_OVF_Msk            (_UINT16_(0x1) << RTC_MODE2_INTENCLR_OVF_Pos)        /* (RTC_MODE2_INTENCLR) Overflow Interrupt Enable Mask */
#define RTC_MODE2_INTENCLR_OVF(value)         (RTC_MODE2_INTENCLR_OVF_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_OVF_Pos)) /* Assigment of value for OVF in the RTC_MODE2_INTENCLR register */
#define RTC_MODE2_INTENCLR_Msk                _UINT16_(0xC1FF)                                     /* (RTC_MODE2_INTENCLR) Register Mask  */

#define RTC_MODE2_INTENCLR_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE2_INTENCLR Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE2_INTENCLR_PER_Msk            (_UINT16_(0xFF) << RTC_MODE2_INTENCLR_PER_Pos)       /* (RTC_MODE2_INTENCLR Mask) PER */
#define RTC_MODE2_INTENCLR_PER(value)         (RTC_MODE2_INTENCLR_PER_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_PER_Pos)) 
#define RTC_MODE2_INTENCLR_ALARM_Pos          _UINT16_(8)                                          /* (RTC_MODE2_INTENCLR Position) Alarm x Interrupt Enable */
#define RTC_MODE2_INTENCLR_ALARM_Msk          (_UINT16_(0x1) << RTC_MODE2_INTENCLR_ALARM_Pos)      /* (RTC_MODE2_INTENCLR Mask) ALARM */
#define RTC_MODE2_INTENCLR_ALARM(value)       (RTC_MODE2_INTENCLR_ALARM_Msk & (_UINT16_(value) << RTC_MODE2_INTENCLR_ALARM_Pos)) 

/* -------- RTC_MODE0_INTENSET : (RTC Offset: 0x0A) (R/W 16) MODE0 Interrupt Enable Set -------- */
#define RTC_MODE0_INTENSET_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE0_INTENSET) MODE0 Interrupt Enable Set  Reset Value */

#define RTC_MODE0_INTENSET_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER0_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER0_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER0(value)        (RTC_MODE0_INTENSET_PER0_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER0_Pos)) /* Assigment of value for PER0 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER1_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER1_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER1(value)        (RTC_MODE0_INTENSET_PER1_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER1_Pos)) /* Assigment of value for PER1 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER2_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER2_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER2(value)        (RTC_MODE0_INTENSET_PER2_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER2_Pos)) /* Assigment of value for PER2 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER3_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER3_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER3(value)        (RTC_MODE0_INTENSET_PER3_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER3_Pos)) /* Assigment of value for PER3 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER4_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER4_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER4(value)        (RTC_MODE0_INTENSET_PER4_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER4_Pos)) /* Assigment of value for PER4 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER5_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER5_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER5(value)        (RTC_MODE0_INTENSET_PER5_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER5_Pos)) /* Assigment of value for PER5 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER6_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER6_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER6(value)        (RTC_MODE0_INTENSET_PER6_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER6_Pos)) /* Assigment of value for PER6 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE0_INTENSET) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_PER7_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_PER7_Pos)       /* (RTC_MODE0_INTENSET) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_PER7(value)        (RTC_MODE0_INTENSET_PER7_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER7_Pos)) /* Assigment of value for PER7 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_CMP0_Pos           _UINT16_(8)                                          /* (RTC_MODE0_INTENSET) Compare 0 Interrupt Enable Position */
#define RTC_MODE0_INTENSET_CMP0_Msk           (_UINT16_(0x1) << RTC_MODE0_INTENSET_CMP0_Pos)       /* (RTC_MODE0_INTENSET) Compare 0 Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_CMP0(value)        (RTC_MODE0_INTENSET_CMP0_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_CMP0_Pos)) /* Assigment of value for CMP0 in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_TAMPER_Pos         _UINT16_(14)                                         /* (RTC_MODE0_INTENSET) Tamper Enable Position */
#define RTC_MODE0_INTENSET_TAMPER_Msk         (_UINT16_(0x1) << RTC_MODE0_INTENSET_TAMPER_Pos)     /* (RTC_MODE0_INTENSET) Tamper Enable Mask */
#define RTC_MODE0_INTENSET_TAMPER(value)      (RTC_MODE0_INTENSET_TAMPER_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_TAMPER_Pos)) /* Assigment of value for TAMPER in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE0_INTENSET) Overflow Interrupt Enable Position */
#define RTC_MODE0_INTENSET_OVF_Msk            (_UINT16_(0x1) << RTC_MODE0_INTENSET_OVF_Pos)        /* (RTC_MODE0_INTENSET) Overflow Interrupt Enable Mask */
#define RTC_MODE0_INTENSET_OVF(value)         (RTC_MODE0_INTENSET_OVF_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_OVF_Pos)) /* Assigment of value for OVF in the RTC_MODE0_INTENSET register */
#define RTC_MODE0_INTENSET_Msk                _UINT16_(0xC1FF)                                     /* (RTC_MODE0_INTENSET) Register Mask  */

#define RTC_MODE0_INTENSET_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE0_INTENSET Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE0_INTENSET_PER_Msk            (_UINT16_(0xFF) << RTC_MODE0_INTENSET_PER_Pos)       /* (RTC_MODE0_INTENSET Mask) PER */
#define RTC_MODE0_INTENSET_PER(value)         (RTC_MODE0_INTENSET_PER_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_PER_Pos)) 
#define RTC_MODE0_INTENSET_CMP_Pos            _UINT16_(8)                                          /* (RTC_MODE0_INTENSET Position) Compare x Interrupt Enable */
#define RTC_MODE0_INTENSET_CMP_Msk            (_UINT16_(0x1) << RTC_MODE0_INTENSET_CMP_Pos)        /* (RTC_MODE0_INTENSET Mask) CMP */
#define RTC_MODE0_INTENSET_CMP(value)         (RTC_MODE0_INTENSET_CMP_Msk & (_UINT16_(value) << RTC_MODE0_INTENSET_CMP_Pos)) 

/* -------- RTC_MODE1_INTENSET : (RTC Offset: 0x0A) (R/W 16) MODE1 Interrupt Enable Set -------- */
#define RTC_MODE1_INTENSET_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE1_INTENSET) MODE1 Interrupt Enable Set  Reset Value */

#define RTC_MODE1_INTENSET_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 0 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER0_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER0_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 0 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER0(value)        (RTC_MODE1_INTENSET_PER0_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER0_Pos)) /* Assigment of value for PER0 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 1 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER1_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER1_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 1 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER1(value)        (RTC_MODE1_INTENSET_PER1_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER1_Pos)) /* Assigment of value for PER1 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 2 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER2_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER2_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 2 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER2(value)        (RTC_MODE1_INTENSET_PER2_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER2_Pos)) /* Assigment of value for PER2 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 3 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER3_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER3_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 3 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER3(value)        (RTC_MODE1_INTENSET_PER3_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER3_Pos)) /* Assigment of value for PER3 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 4 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER4_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER4_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 4 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER4(value)        (RTC_MODE1_INTENSET_PER4_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER4_Pos)) /* Assigment of value for PER4 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 5 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER5_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER5_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 5 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER5(value)        (RTC_MODE1_INTENSET_PER5_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER5_Pos)) /* Assigment of value for PER5 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 6 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER6_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER6_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 6 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER6(value)        (RTC_MODE1_INTENSET_PER6_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER6_Pos)) /* Assigment of value for PER6 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE1_INTENSET) Periodic Interval 7 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_PER7_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_PER7_Pos)       /* (RTC_MODE1_INTENSET) Periodic Interval 7 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_PER7(value)        (RTC_MODE1_INTENSET_PER7_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER7_Pos)) /* Assigment of value for PER7 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_CMP0_Pos           _UINT16_(8)                                          /* (RTC_MODE1_INTENSET) Compare 0 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_CMP0_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_CMP0_Pos)       /* (RTC_MODE1_INTENSET) Compare 0 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_CMP0(value)        (RTC_MODE1_INTENSET_CMP0_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_CMP0_Pos)) /* Assigment of value for CMP0 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_CMP1_Pos           _UINT16_(9)                                          /* (RTC_MODE1_INTENSET) Compare 1 Interrupt Enable Position */
#define RTC_MODE1_INTENSET_CMP1_Msk           (_UINT16_(0x1) << RTC_MODE1_INTENSET_CMP1_Pos)       /* (RTC_MODE1_INTENSET) Compare 1 Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_CMP1(value)        (RTC_MODE1_INTENSET_CMP1_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_CMP1_Pos)) /* Assigment of value for CMP1 in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_TAMPER_Pos         _UINT16_(14)                                         /* (RTC_MODE1_INTENSET) Tamper Enable Position */
#define RTC_MODE1_INTENSET_TAMPER_Msk         (_UINT16_(0x1) << RTC_MODE1_INTENSET_TAMPER_Pos)     /* (RTC_MODE1_INTENSET) Tamper Enable Mask */
#define RTC_MODE1_INTENSET_TAMPER(value)      (RTC_MODE1_INTENSET_TAMPER_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_TAMPER_Pos)) /* Assigment of value for TAMPER in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE1_INTENSET) Overflow Interrupt Enable Position */
#define RTC_MODE1_INTENSET_OVF_Msk            (_UINT16_(0x1) << RTC_MODE1_INTENSET_OVF_Pos)        /* (RTC_MODE1_INTENSET) Overflow Interrupt Enable Mask */
#define RTC_MODE1_INTENSET_OVF(value)         (RTC_MODE1_INTENSET_OVF_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_OVF_Pos)) /* Assigment of value for OVF in the RTC_MODE1_INTENSET register */
#define RTC_MODE1_INTENSET_Msk                _UINT16_(0xC3FF)                                     /* (RTC_MODE1_INTENSET) Register Mask  */

#define RTC_MODE1_INTENSET_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE1_INTENSET Position) Periodic Interval x Interrupt Enable */
#define RTC_MODE1_INTENSET_PER_Msk            (_UINT16_(0xFF) << RTC_MODE1_INTENSET_PER_Pos)       /* (RTC_MODE1_INTENSET Mask) PER */
#define RTC_MODE1_INTENSET_PER(value)         (RTC_MODE1_INTENSET_PER_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_PER_Pos)) 
#define RTC_MODE1_INTENSET_CMP_Pos            _UINT16_(8)                                          /* (RTC_MODE1_INTENSET Position) Compare x Interrupt Enable */
#define RTC_MODE1_INTENSET_CMP_Msk            (_UINT16_(0x3) << RTC_MODE1_INTENSET_CMP_Pos)        /* (RTC_MODE1_INTENSET Mask) CMP */
#define RTC_MODE1_INTENSET_CMP(value)         (RTC_MODE1_INTENSET_CMP_Msk & (_UINT16_(value) << RTC_MODE1_INTENSET_CMP_Pos)) 

/* -------- RTC_MODE2_INTENSET : (RTC Offset: 0x0A) (R/W 16) MODE2 Interrupt Enable Set -------- */
#define RTC_MODE2_INTENSET_RESETVALUE         _UINT16_(0x00)                                       /*  (RTC_MODE2_INTENSET) MODE2 Interrupt Enable Set  Reset Value */

#define RTC_MODE2_INTENSET_PER0_Pos           _UINT16_(0)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 0 Enable Position */
#define RTC_MODE2_INTENSET_PER0_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER0_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 0 Enable Mask */
#define RTC_MODE2_INTENSET_PER0(value)        (RTC_MODE2_INTENSET_PER0_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER0_Pos)) /* Assigment of value for PER0 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER1_Pos           _UINT16_(1)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 1 Enable Position */
#define RTC_MODE2_INTENSET_PER1_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER1_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 1 Enable Mask */
#define RTC_MODE2_INTENSET_PER1(value)        (RTC_MODE2_INTENSET_PER1_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER1_Pos)) /* Assigment of value for PER1 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER2_Pos           _UINT16_(2)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 2 Enable Position */
#define RTC_MODE2_INTENSET_PER2_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER2_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 2 Enable Mask */
#define RTC_MODE2_INTENSET_PER2(value)        (RTC_MODE2_INTENSET_PER2_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER2_Pos)) /* Assigment of value for PER2 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER3_Pos           _UINT16_(3)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 3 Enable Position */
#define RTC_MODE2_INTENSET_PER3_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER3_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 3 Enable Mask */
#define RTC_MODE2_INTENSET_PER3(value)        (RTC_MODE2_INTENSET_PER3_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER3_Pos)) /* Assigment of value for PER3 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER4_Pos           _UINT16_(4)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 4 Enable Position */
#define RTC_MODE2_INTENSET_PER4_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER4_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 4 Enable Mask */
#define RTC_MODE2_INTENSET_PER4(value)        (RTC_MODE2_INTENSET_PER4_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER4_Pos)) /* Assigment of value for PER4 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER5_Pos           _UINT16_(5)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 5 Enable Position */
#define RTC_MODE2_INTENSET_PER5_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER5_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 5 Enable Mask */
#define RTC_MODE2_INTENSET_PER5(value)        (RTC_MODE2_INTENSET_PER5_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER5_Pos)) /* Assigment of value for PER5 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER6_Pos           _UINT16_(6)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 6 Enable Position */
#define RTC_MODE2_INTENSET_PER6_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER6_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 6 Enable Mask */
#define RTC_MODE2_INTENSET_PER6(value)        (RTC_MODE2_INTENSET_PER6_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER6_Pos)) /* Assigment of value for PER6 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_PER7_Pos           _UINT16_(7)                                          /* (RTC_MODE2_INTENSET) Periodic Interval 7 Enable Position */
#define RTC_MODE2_INTENSET_PER7_Msk           (_UINT16_(0x1) << RTC_MODE2_INTENSET_PER7_Pos)       /* (RTC_MODE2_INTENSET) Periodic Interval 7 Enable Mask */
#define RTC_MODE2_INTENSET_PER7(value)        (RTC_MODE2_INTENSET_PER7_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER7_Pos)) /* Assigment of value for PER7 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_ALARM0_Pos         _UINT16_(8)                                          /* (RTC_MODE2_INTENSET) Alarm 0 Interrupt Enable Position */
#define RTC_MODE2_INTENSET_ALARM0_Msk         (_UINT16_(0x1) << RTC_MODE2_INTENSET_ALARM0_Pos)     /* (RTC_MODE2_INTENSET) Alarm 0 Interrupt Enable Mask */
#define RTC_MODE2_INTENSET_ALARM0(value)      (RTC_MODE2_INTENSET_ALARM0_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_ALARM0_Pos)) /* Assigment of value for ALARM0 in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_TAMPER_Pos         _UINT16_(14)                                         /* (RTC_MODE2_INTENSET) Tamper Enable Position */
#define RTC_MODE2_INTENSET_TAMPER_Msk         (_UINT16_(0x1) << RTC_MODE2_INTENSET_TAMPER_Pos)     /* (RTC_MODE2_INTENSET) Tamper Enable Mask */
#define RTC_MODE2_INTENSET_TAMPER(value)      (RTC_MODE2_INTENSET_TAMPER_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_TAMPER_Pos)) /* Assigment of value for TAMPER in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_OVF_Pos            _UINT16_(15)                                         /* (RTC_MODE2_INTENSET) Overflow Interrupt Enable Position */
#define RTC_MODE2_INTENSET_OVF_Msk            (_UINT16_(0x1) << RTC_MODE2_INTENSET_OVF_Pos)        /* (RTC_MODE2_INTENSET) Overflow Interrupt Enable Mask */
#define RTC_MODE2_INTENSET_OVF(value)         (RTC_MODE2_INTENSET_OVF_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_OVF_Pos)) /* Assigment of value for OVF in the RTC_MODE2_INTENSET register */
#define RTC_MODE2_INTENSET_Msk                _UINT16_(0xC1FF)                                     /* (RTC_MODE2_INTENSET) Register Mask  */

#define RTC_MODE2_INTENSET_PER_Pos            _UINT16_(0)                                          /* (RTC_MODE2_INTENSET Position) Periodic Interval x Enable */
#define RTC_MODE2_INTENSET_PER_Msk            (_UINT16_(0xFF) << RTC_MODE2_INTENSET_PER_Pos)       /* (RTC_MODE2_INTENSET Mask) PER */
#define RTC_MODE2_INTENSET_PER(value)         (RTC_MODE2_INTENSET_PER_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_PER_Pos)) 
#define RTC_MODE2_INTENSET_ALARM_Pos          _UINT16_(8)                                          /* (RTC_MODE2_INTENSET Position) Alarm x Interrupt Enable */
#define RTC_MODE2_INTENSET_ALARM_Msk          (_UINT16_(0x1) << RTC_MODE2_INTENSET_ALARM_Pos)      /* (RTC_MODE2_INTENSET Mask) ALARM */
#define RTC_MODE2_INTENSET_ALARM(value)       (RTC_MODE2_INTENSET_ALARM_Msk & (_UINT16_(value) << RTC_MODE2_INTENSET_ALARM_Pos)) 

/* -------- RTC_MODE0_INTFLAG : (RTC Offset: 0x0C) (R/W 16) MODE0 Interrupt Flag Status and Clear -------- */
#define RTC_MODE0_INTFLAG_RESETVALUE          _UINT16_(0x00)                                       /*  (RTC_MODE0_INTFLAG) MODE0 Interrupt Flag Status and Clear  Reset Value */

#define RTC_MODE0_INTFLAG_PER0_Pos            _UINT16_(0)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 0 Position */
#define RTC_MODE0_INTFLAG_PER0_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER0_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 0 Mask */
#define RTC_MODE0_INTFLAG_PER0(value)         (RTC_MODE0_INTFLAG_PER0_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER0_Pos)) /* Assigment of value for PER0 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER1_Pos            _UINT16_(1)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 1 Position */
#define RTC_MODE0_INTFLAG_PER1_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER1_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 1 Mask */
#define RTC_MODE0_INTFLAG_PER1(value)         (RTC_MODE0_INTFLAG_PER1_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER1_Pos)) /* Assigment of value for PER1 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER2_Pos            _UINT16_(2)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 2 Position */
#define RTC_MODE0_INTFLAG_PER2_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER2_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 2 Mask */
#define RTC_MODE0_INTFLAG_PER2(value)         (RTC_MODE0_INTFLAG_PER2_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER2_Pos)) /* Assigment of value for PER2 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER3_Pos            _UINT16_(3)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 3 Position */
#define RTC_MODE0_INTFLAG_PER3_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER3_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 3 Mask */
#define RTC_MODE0_INTFLAG_PER3(value)         (RTC_MODE0_INTFLAG_PER3_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER3_Pos)) /* Assigment of value for PER3 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER4_Pos            _UINT16_(4)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 4 Position */
#define RTC_MODE0_INTFLAG_PER4_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER4_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 4 Mask */
#define RTC_MODE0_INTFLAG_PER4(value)         (RTC_MODE0_INTFLAG_PER4_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER4_Pos)) /* Assigment of value for PER4 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER5_Pos            _UINT16_(5)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 5 Position */
#define RTC_MODE0_INTFLAG_PER5_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER5_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 5 Mask */
#define RTC_MODE0_INTFLAG_PER5(value)         (RTC_MODE0_INTFLAG_PER5_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER5_Pos)) /* Assigment of value for PER5 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER6_Pos            _UINT16_(6)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 6 Position */
#define RTC_MODE0_INTFLAG_PER6_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER6_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 6 Mask */
#define RTC_MODE0_INTFLAG_PER6(value)         (RTC_MODE0_INTFLAG_PER6_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER6_Pos)) /* Assigment of value for PER6 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_PER7_Pos            _UINT16_(7)                                          /* (RTC_MODE0_INTFLAG) Periodic Interval 7 Position */
#define RTC_MODE0_INTFLAG_PER7_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_PER7_Pos)        /* (RTC_MODE0_INTFLAG) Periodic Interval 7 Mask */
#define RTC_MODE0_INTFLAG_PER7(value)         (RTC_MODE0_INTFLAG_PER7_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER7_Pos)) /* Assigment of value for PER7 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_CMP0_Pos            _UINT16_(8)                                          /* (RTC_MODE0_INTFLAG) Compare 0 Position */
#define RTC_MODE0_INTFLAG_CMP0_Msk            (_UINT16_(0x1) << RTC_MODE0_INTFLAG_CMP0_Pos)        /* (RTC_MODE0_INTFLAG) Compare 0 Mask */
#define RTC_MODE0_INTFLAG_CMP0(value)         (RTC_MODE0_INTFLAG_CMP0_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_CMP0_Pos)) /* Assigment of value for CMP0 in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_TAMPER_Pos          _UINT16_(14)                                         /* (RTC_MODE0_INTFLAG) Tamper Position */
#define RTC_MODE0_INTFLAG_TAMPER_Msk          (_UINT16_(0x1) << RTC_MODE0_INTFLAG_TAMPER_Pos)      /* (RTC_MODE0_INTFLAG) Tamper Mask */
#define RTC_MODE0_INTFLAG_TAMPER(value)       (RTC_MODE0_INTFLAG_TAMPER_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_TAMPER_Pos)) /* Assigment of value for TAMPER in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_OVF_Pos             _UINT16_(15)                                         /* (RTC_MODE0_INTFLAG) Overflow Position */
#define RTC_MODE0_INTFLAG_OVF_Msk             (_UINT16_(0x1) << RTC_MODE0_INTFLAG_OVF_Pos)         /* (RTC_MODE0_INTFLAG) Overflow Mask */
#define RTC_MODE0_INTFLAG_OVF(value)          (RTC_MODE0_INTFLAG_OVF_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_OVF_Pos)) /* Assigment of value for OVF in the RTC_MODE0_INTFLAG register */
#define RTC_MODE0_INTFLAG_Msk                 _UINT16_(0xC1FF)                                     /* (RTC_MODE0_INTFLAG) Register Mask  */

#define RTC_MODE0_INTFLAG_PER_Pos             _UINT16_(0)                                          /* (RTC_MODE0_INTFLAG Position) Periodic Interval x */
#define RTC_MODE0_INTFLAG_PER_Msk             (_UINT16_(0xFF) << RTC_MODE0_INTFLAG_PER_Pos)        /* (RTC_MODE0_INTFLAG Mask) PER */
#define RTC_MODE0_INTFLAG_PER(value)          (RTC_MODE0_INTFLAG_PER_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_PER_Pos)) 
#define RTC_MODE0_INTFLAG_CMP_Pos             _UINT16_(8)                                          /* (RTC_MODE0_INTFLAG Position) Compare x */
#define RTC_MODE0_INTFLAG_CMP_Msk             (_UINT16_(0x1) << RTC_MODE0_INTFLAG_CMP_Pos)         /* (RTC_MODE0_INTFLAG Mask) CMP */
#define RTC_MODE0_INTFLAG_CMP(value)          (RTC_MODE0_INTFLAG_CMP_Msk & (_UINT16_(value) << RTC_MODE0_INTFLAG_CMP_Pos)) 

/* -------- RTC_MODE1_INTFLAG : (RTC Offset: 0x0C) (R/W 16) MODE1 Interrupt Flag Status and Clear -------- */
#define RTC_MODE1_INTFLAG_RESETVALUE          _UINT16_(0x00)                                       /*  (RTC_MODE1_INTFLAG) MODE1 Interrupt Flag Status and Clear  Reset Value */

#define RTC_MODE1_INTFLAG_PER0_Pos            _UINT16_(0)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 0 Position */
#define RTC_MODE1_INTFLAG_PER0_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER0_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 0 Mask */
#define RTC_MODE1_INTFLAG_PER0(value)         (RTC_MODE1_INTFLAG_PER0_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER0_Pos)) /* Assigment of value for PER0 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER1_Pos            _UINT16_(1)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 1 Position */
#define RTC_MODE1_INTFLAG_PER1_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER1_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 1 Mask */
#define RTC_MODE1_INTFLAG_PER1(value)         (RTC_MODE1_INTFLAG_PER1_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER1_Pos)) /* Assigment of value for PER1 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER2_Pos            _UINT16_(2)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 2 Position */
#define RTC_MODE1_INTFLAG_PER2_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER2_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 2 Mask */
#define RTC_MODE1_INTFLAG_PER2(value)         (RTC_MODE1_INTFLAG_PER2_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER2_Pos)) /* Assigment of value for PER2 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER3_Pos            _UINT16_(3)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 3 Position */
#define RTC_MODE1_INTFLAG_PER3_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER3_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 3 Mask */
#define RTC_MODE1_INTFLAG_PER3(value)         (RTC_MODE1_INTFLAG_PER3_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER3_Pos)) /* Assigment of value for PER3 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER4_Pos            _UINT16_(4)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 4 Position */
#define RTC_MODE1_INTFLAG_PER4_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER4_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 4 Mask */
#define RTC_MODE1_INTFLAG_PER4(value)         (RTC_MODE1_INTFLAG_PER4_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER4_Pos)) /* Assigment of value for PER4 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER5_Pos            _UINT16_(5)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 5 Position */
#define RTC_MODE1_INTFLAG_PER5_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER5_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 5 Mask */
#define RTC_MODE1_INTFLAG_PER5(value)         (RTC_MODE1_INTFLAG_PER5_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER5_Pos)) /* Assigment of value for PER5 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER6_Pos            _UINT16_(6)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 6 Position */
#define RTC_MODE1_INTFLAG_PER6_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER6_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 6 Mask */
#define RTC_MODE1_INTFLAG_PER6(value)         (RTC_MODE1_INTFLAG_PER6_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER6_Pos)) /* Assigment of value for PER6 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_PER7_Pos            _UINT16_(7)                                          /* (RTC_MODE1_INTFLAG) Periodic Interval 7 Position */
#define RTC_MODE1_INTFLAG_PER7_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_PER7_Pos)        /* (RTC_MODE1_INTFLAG) Periodic Interval 7 Mask */
#define RTC_MODE1_INTFLAG_PER7(value)         (RTC_MODE1_INTFLAG_PER7_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER7_Pos)) /* Assigment of value for PER7 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_CMP0_Pos            _UINT16_(8)                                          /* (RTC_MODE1_INTFLAG) Compare 0 Position */
#define RTC_MODE1_INTFLAG_CMP0_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_CMP0_Pos)        /* (RTC_MODE1_INTFLAG) Compare 0 Mask */
#define RTC_MODE1_INTFLAG_CMP0(value)         (RTC_MODE1_INTFLAG_CMP0_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_CMP0_Pos)) /* Assigment of value for CMP0 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_CMP1_Pos            _UINT16_(9)                                          /* (RTC_MODE1_INTFLAG) Compare 1 Position */
#define RTC_MODE1_INTFLAG_CMP1_Msk            (_UINT16_(0x1) << RTC_MODE1_INTFLAG_CMP1_Pos)        /* (RTC_MODE1_INTFLAG) Compare 1 Mask */
#define RTC_MODE1_INTFLAG_CMP1(value)         (RTC_MODE1_INTFLAG_CMP1_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_CMP1_Pos)) /* Assigment of value for CMP1 in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_TAMPER_Pos          _UINT16_(14)                                         /* (RTC_MODE1_INTFLAG) Tamper Position */
#define RTC_MODE1_INTFLAG_TAMPER_Msk          (_UINT16_(0x1) << RTC_MODE1_INTFLAG_TAMPER_Pos)      /* (RTC_MODE1_INTFLAG) Tamper Mask */
#define RTC_MODE1_INTFLAG_TAMPER(value)       (RTC_MODE1_INTFLAG_TAMPER_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_TAMPER_Pos)) /* Assigment of value for TAMPER in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_OVF_Pos             _UINT16_(15)                                         /* (RTC_MODE1_INTFLAG) Overflow Position */
#define RTC_MODE1_INTFLAG_OVF_Msk             (_UINT16_(0x1) << RTC_MODE1_INTFLAG_OVF_Pos)         /* (RTC_MODE1_INTFLAG) Overflow Mask */
#define RTC_MODE1_INTFLAG_OVF(value)          (RTC_MODE1_INTFLAG_OVF_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_OVF_Pos)) /* Assigment of value for OVF in the RTC_MODE1_INTFLAG register */
#define RTC_MODE1_INTFLAG_Msk                 _UINT16_(0xC3FF)                                     /* (RTC_MODE1_INTFLAG) Register Mask  */

#define RTC_MODE1_INTFLAG_PER_Pos             _UINT16_(0)                                          /* (RTC_MODE1_INTFLAG Position) Periodic Interval x */
#define RTC_MODE1_INTFLAG_PER_Msk             (_UINT16_(0xFF) << RTC_MODE1_INTFLAG_PER_Pos)        /* (RTC_MODE1_INTFLAG Mask) PER */
#define RTC_MODE1_INTFLAG_PER(value)          (RTC_MODE1_INTFLAG_PER_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_PER_Pos)) 
#define RTC_MODE1_INTFLAG_CMP_Pos             _UINT16_(8)                                          /* (RTC_MODE1_INTFLAG Position) Compare x */
#define RTC_MODE1_INTFLAG_CMP_Msk             (_UINT16_(0x3) << RTC_MODE1_INTFLAG_CMP_Pos)         /* (RTC_MODE1_INTFLAG Mask) CMP */
#define RTC_MODE1_INTFLAG_CMP(value)          (RTC_MODE1_INTFLAG_CMP_Msk & (_UINT16_(value) << RTC_MODE1_INTFLAG_CMP_Pos)) 

/* -------- RTC_MODE2_INTFLAG : (RTC Offset: 0x0C) (R/W 16) MODE2 Interrupt Flag Status and Clear -------- */
#define RTC_MODE2_INTFLAG_RESETVALUE          _UINT16_(0x00)                                       /*  (RTC_MODE2_INTFLAG) MODE2 Interrupt Flag Status and Clear  Reset Value */

#define RTC_MODE2_INTFLAG_PER0_Pos            _UINT16_(0)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 0 Position */
#define RTC_MODE2_INTFLAG_PER0_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER0_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 0 Mask */
#define RTC_MODE2_INTFLAG_PER0(value)         (RTC_MODE2_INTFLAG_PER0_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER0_Pos)) /* Assigment of value for PER0 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER1_Pos            _UINT16_(1)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 1 Position */
#define RTC_MODE2_INTFLAG_PER1_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER1_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 1 Mask */
#define RTC_MODE2_INTFLAG_PER1(value)         (RTC_MODE2_INTFLAG_PER1_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER1_Pos)) /* Assigment of value for PER1 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER2_Pos            _UINT16_(2)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 2 Position */
#define RTC_MODE2_INTFLAG_PER2_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER2_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 2 Mask */
#define RTC_MODE2_INTFLAG_PER2(value)         (RTC_MODE2_INTFLAG_PER2_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER2_Pos)) /* Assigment of value for PER2 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER3_Pos            _UINT16_(3)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 3 Position */
#define RTC_MODE2_INTFLAG_PER3_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER3_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 3 Mask */
#define RTC_MODE2_INTFLAG_PER3(value)         (RTC_MODE2_INTFLAG_PER3_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER3_Pos)) /* Assigment of value for PER3 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER4_Pos            _UINT16_(4)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 4 Position */
#define RTC_MODE2_INTFLAG_PER4_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER4_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 4 Mask */
#define RTC_MODE2_INTFLAG_PER4(value)         (RTC_MODE2_INTFLAG_PER4_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER4_Pos)) /* Assigment of value for PER4 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER5_Pos            _UINT16_(5)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 5 Position */
#define RTC_MODE2_INTFLAG_PER5_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER5_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 5 Mask */
#define RTC_MODE2_INTFLAG_PER5(value)         (RTC_MODE2_INTFLAG_PER5_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER5_Pos)) /* Assigment of value for PER5 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER6_Pos            _UINT16_(6)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 6 Position */
#define RTC_MODE2_INTFLAG_PER6_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER6_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 6 Mask */
#define RTC_MODE2_INTFLAG_PER6(value)         (RTC_MODE2_INTFLAG_PER6_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER6_Pos)) /* Assigment of value for PER6 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_PER7_Pos            _UINT16_(7)                                          /* (RTC_MODE2_INTFLAG) Periodic Interval 7 Position */
#define RTC_MODE2_INTFLAG_PER7_Msk            (_UINT16_(0x1) << RTC_MODE2_INTFLAG_PER7_Pos)        /* (RTC_MODE2_INTFLAG) Periodic Interval 7 Mask */
#define RTC_MODE2_INTFLAG_PER7(value)         (RTC_MODE2_INTFLAG_PER7_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER7_Pos)) /* Assigment of value for PER7 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_ALARM0_Pos          _UINT16_(8)                                          /* (RTC_MODE2_INTFLAG) Alarm 0 Position */
#define RTC_MODE2_INTFLAG_ALARM0_Msk          (_UINT16_(0x1) << RTC_MODE2_INTFLAG_ALARM0_Pos)      /* (RTC_MODE2_INTFLAG) Alarm 0 Mask */
#define RTC_MODE2_INTFLAG_ALARM0(value)       (RTC_MODE2_INTFLAG_ALARM0_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_ALARM0_Pos)) /* Assigment of value for ALARM0 in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_TAMPER_Pos          _UINT16_(14)                                         /* (RTC_MODE2_INTFLAG) Tamper Position */
#define RTC_MODE2_INTFLAG_TAMPER_Msk          (_UINT16_(0x1) << RTC_MODE2_INTFLAG_TAMPER_Pos)      /* (RTC_MODE2_INTFLAG) Tamper Mask */
#define RTC_MODE2_INTFLAG_TAMPER(value)       (RTC_MODE2_INTFLAG_TAMPER_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_TAMPER_Pos)) /* Assigment of value for TAMPER in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_OVF_Pos             _UINT16_(15)                                         /* (RTC_MODE2_INTFLAG) Overflow Position */
#define RTC_MODE2_INTFLAG_OVF_Msk             (_UINT16_(0x1) << RTC_MODE2_INTFLAG_OVF_Pos)         /* (RTC_MODE2_INTFLAG) Overflow Mask */
#define RTC_MODE2_INTFLAG_OVF(value)          (RTC_MODE2_INTFLAG_OVF_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_OVF_Pos)) /* Assigment of value for OVF in the RTC_MODE2_INTFLAG register */
#define RTC_MODE2_INTFLAG_Msk                 _UINT16_(0xC1FF)                                     /* (RTC_MODE2_INTFLAG) Register Mask  */

#define RTC_MODE2_INTFLAG_PER_Pos             _UINT16_(0)                                          /* (RTC_MODE2_INTFLAG Position) Periodic Interval x */
#define RTC_MODE2_INTFLAG_PER_Msk             (_UINT16_(0xFF) << RTC_MODE2_INTFLAG_PER_Pos)        /* (RTC_MODE2_INTFLAG Mask) PER */
#define RTC_MODE2_INTFLAG_PER(value)          (RTC_MODE2_INTFLAG_PER_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_PER_Pos)) 
#define RTC_MODE2_INTFLAG_ALARM_Pos           _UINT16_(8)                                          /* (RTC_MODE2_INTFLAG Position) Alarm x */
#define RTC_MODE2_INTFLAG_ALARM_Msk           (_UINT16_(0x1) << RTC_MODE2_INTFLAG_ALARM_Pos)       /* (RTC_MODE2_INTFLAG Mask) ALARM */
#define RTC_MODE2_INTFLAG_ALARM(value)        (RTC_MODE2_INTFLAG_ALARM_Msk & (_UINT16_(value) << RTC_MODE2_INTFLAG_ALARM_Pos)) 

/* -------- RTC_DBGCTRL : (RTC Offset: 0x0E) (R/W 8) Debug Control -------- */
#define RTC_DBGCTRL_RESETVALUE                _UINT8_(0x00)                                        /*  (RTC_DBGCTRL) Debug Control  Reset Value */

#define RTC_DBGCTRL_DBGRUN_Pos                _UINT8_(0)                                           /* (RTC_DBGCTRL) Run During Debug Position */
#define RTC_DBGCTRL_DBGRUN_Msk                (_UINT8_(0x1) << RTC_DBGCTRL_DBGRUN_Pos)             /* (RTC_DBGCTRL) Run During Debug Mask */
#define RTC_DBGCTRL_DBGRUN(value)             (RTC_DBGCTRL_DBGRUN_Msk & (_UINT8_(value) << RTC_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the RTC_DBGCTRL register */
#define RTC_DBGCTRL_Msk                       _UINT8_(0x01)                                        /* (RTC_DBGCTRL) Register Mask  */


/* -------- RTC_MODE0_SYNCBUSY : (RTC Offset: 0x10) ( R/ 32) MODE0 Synchronization Busy Status -------- */
#define RTC_MODE0_SYNCBUSY_RESETVALUE         _UINT32_(0x00)                                       /*  (RTC_MODE0_SYNCBUSY) MODE0 Synchronization Busy Status  Reset Value */

#define RTC_MODE0_SYNCBUSY_SWRST_Pos          _UINT32_(0)                                          /* (RTC_MODE0_SYNCBUSY) Software Reset Busy Position */
#define RTC_MODE0_SYNCBUSY_SWRST_Msk          (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_SWRST_Pos)      /* (RTC_MODE0_SYNCBUSY) Software Reset Busy Mask */
#define RTC_MODE0_SYNCBUSY_SWRST(value)       (RTC_MODE0_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_ENABLE_Pos         _UINT32_(1)                                          /* (RTC_MODE0_SYNCBUSY) Enable Bit Busy Position */
#define RTC_MODE0_SYNCBUSY_ENABLE_Msk         (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_ENABLE_Pos)     /* (RTC_MODE0_SYNCBUSY) Enable Bit Busy Mask */
#define RTC_MODE0_SYNCBUSY_ENABLE(value)      (RTC_MODE0_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_FREQCORR_Pos       _UINT32_(2)                                          /* (RTC_MODE0_SYNCBUSY) FREQCORR Register Busy Position */
#define RTC_MODE0_SYNCBUSY_FREQCORR_Msk       (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_FREQCORR_Pos)   /* (RTC_MODE0_SYNCBUSY) FREQCORR Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_FREQCORR(value)    (RTC_MODE0_SYNCBUSY_FREQCORR_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_FREQCORR_Pos)) /* Assigment of value for FREQCORR in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_COUNT_Pos          _UINT32_(3)                                          /* (RTC_MODE0_SYNCBUSY) COUNT Register Busy Position */
#define RTC_MODE0_SYNCBUSY_COUNT_Msk          (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_COUNT_Pos)      /* (RTC_MODE0_SYNCBUSY) COUNT Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_COUNT(value)       (RTC_MODE0_SYNCBUSY_COUNT_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_COUNT_Pos)) /* Assigment of value for COUNT in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_COMP0_Pos          _UINT32_(5)                                          /* (RTC_MODE0_SYNCBUSY) COMP 0 Register Busy Position */
#define RTC_MODE0_SYNCBUSY_COMP0_Msk          (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_COMP0_Pos)      /* (RTC_MODE0_SYNCBUSY) COMP 0 Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_COMP0(value)       (RTC_MODE0_SYNCBUSY_COMP0_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_COMP0_Pos)) /* Assigment of value for COMP0 in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_COUNTSYNC_Pos      _UINT32_(15)                                         /* (RTC_MODE0_SYNCBUSY) Count Synchronization Enable Bit Busy Position */
#define RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk      (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_COUNTSYNC_Pos)  /* (RTC_MODE0_SYNCBUSY) Count Synchronization Enable Bit Busy Mask */
#define RTC_MODE0_SYNCBUSY_COUNTSYNC(value)   (RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_COUNTSYNC_Pos)) /* Assigment of value for COUNTSYNC in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_GP0_Pos            _UINT32_(16)                                         /* (RTC_MODE0_SYNCBUSY) General Purpose 0 Register Busy Position */
#define RTC_MODE0_SYNCBUSY_GP0_Msk            (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_GP0_Pos)        /* (RTC_MODE0_SYNCBUSY) General Purpose 0 Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_GP0(value)         (RTC_MODE0_SYNCBUSY_GP0_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_GP0_Pos)) /* Assigment of value for GP0 in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_GP1_Pos            _UINT32_(17)                                         /* (RTC_MODE0_SYNCBUSY) General Purpose 1 Register Busy Position */
#define RTC_MODE0_SYNCBUSY_GP1_Msk            (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_GP1_Pos)        /* (RTC_MODE0_SYNCBUSY) General Purpose 1 Register Busy Mask */
#define RTC_MODE0_SYNCBUSY_GP1(value)         (RTC_MODE0_SYNCBUSY_GP1_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_GP1_Pos)) /* Assigment of value for GP1 in the RTC_MODE0_SYNCBUSY register */
#define RTC_MODE0_SYNCBUSY_Msk                _UINT32_(0x0003802F)                                 /* (RTC_MODE0_SYNCBUSY) Register Mask  */

#define RTC_MODE0_SYNCBUSY_COMP_Pos           _UINT32_(5)                                          /* (RTC_MODE0_SYNCBUSY Position) COMP x Register Busy */
#define RTC_MODE0_SYNCBUSY_COMP_Msk           (_UINT32_(0x1) << RTC_MODE0_SYNCBUSY_COMP_Pos)       /* (RTC_MODE0_SYNCBUSY Mask) COMP */
#define RTC_MODE0_SYNCBUSY_COMP(value)        (RTC_MODE0_SYNCBUSY_COMP_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_COMP_Pos)) 
#define RTC_MODE0_SYNCBUSY_GP_Pos             _UINT32_(16)                                         /* (RTC_MODE0_SYNCBUSY Position) General Purpose x Register Busy */
#define RTC_MODE0_SYNCBUSY_GP_Msk             (_UINT32_(0x3) << RTC_MODE0_SYNCBUSY_GP_Pos)         /* (RTC_MODE0_SYNCBUSY Mask) GP */
#define RTC_MODE0_SYNCBUSY_GP(value)          (RTC_MODE0_SYNCBUSY_GP_Msk & (_UINT32_(value) << RTC_MODE0_SYNCBUSY_GP_Pos)) 

/* -------- RTC_MODE1_SYNCBUSY : (RTC Offset: 0x10) ( R/ 32) MODE1 Synchronization Busy Status -------- */
#define RTC_MODE1_SYNCBUSY_RESETVALUE         _UINT32_(0x00)                                       /*  (RTC_MODE1_SYNCBUSY) MODE1 Synchronization Busy Status  Reset Value */

#define RTC_MODE1_SYNCBUSY_SWRST_Pos          _UINT32_(0)                                          /* (RTC_MODE1_SYNCBUSY) Software Reset Bit Busy Position */
#define RTC_MODE1_SYNCBUSY_SWRST_Msk          (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_SWRST_Pos)      /* (RTC_MODE1_SYNCBUSY) Software Reset Bit Busy Mask */
#define RTC_MODE1_SYNCBUSY_SWRST(value)       (RTC_MODE1_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_ENABLE_Pos         _UINT32_(1)                                          /* (RTC_MODE1_SYNCBUSY) Enable Bit Busy Position */
#define RTC_MODE1_SYNCBUSY_ENABLE_Msk         (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_ENABLE_Pos)     /* (RTC_MODE1_SYNCBUSY) Enable Bit Busy Mask */
#define RTC_MODE1_SYNCBUSY_ENABLE(value)      (RTC_MODE1_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_FREQCORR_Pos       _UINT32_(2)                                          /* (RTC_MODE1_SYNCBUSY) FREQCORR Register Busy Position */
#define RTC_MODE1_SYNCBUSY_FREQCORR_Msk       (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_FREQCORR_Pos)   /* (RTC_MODE1_SYNCBUSY) FREQCORR Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_FREQCORR(value)    (RTC_MODE1_SYNCBUSY_FREQCORR_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_FREQCORR_Pos)) /* Assigment of value for FREQCORR in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_COUNT_Pos          _UINT32_(3)                                          /* (RTC_MODE1_SYNCBUSY) COUNT Register Busy Position */
#define RTC_MODE1_SYNCBUSY_COUNT_Msk          (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_COUNT_Pos)      /* (RTC_MODE1_SYNCBUSY) COUNT Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_COUNT(value)       (RTC_MODE1_SYNCBUSY_COUNT_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COUNT_Pos)) /* Assigment of value for COUNT in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_PER_Pos            _UINT32_(4)                                          /* (RTC_MODE1_SYNCBUSY) PER Register Busy Position */
#define RTC_MODE1_SYNCBUSY_PER_Msk            (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_PER_Pos)        /* (RTC_MODE1_SYNCBUSY) PER Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_PER(value)         (RTC_MODE1_SYNCBUSY_PER_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_PER_Pos)) /* Assigment of value for PER in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_COMP0_Pos          _UINT32_(5)                                          /* (RTC_MODE1_SYNCBUSY) COMP 0 Register Busy Position */
#define RTC_MODE1_SYNCBUSY_COMP0_Msk          (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_COMP0_Pos)      /* (RTC_MODE1_SYNCBUSY) COMP 0 Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_COMP0(value)       (RTC_MODE1_SYNCBUSY_COMP0_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COMP0_Pos)) /* Assigment of value for COMP0 in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_COMP1_Pos          _UINT32_(6)                                          /* (RTC_MODE1_SYNCBUSY) COMP 1 Register Busy Position */
#define RTC_MODE1_SYNCBUSY_COMP1_Msk          (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_COMP1_Pos)      /* (RTC_MODE1_SYNCBUSY) COMP 1 Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_COMP1(value)       (RTC_MODE1_SYNCBUSY_COMP1_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COMP1_Pos)) /* Assigment of value for COMP1 in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_COUNTSYNC_Pos      _UINT32_(15)                                         /* (RTC_MODE1_SYNCBUSY) Count Synchronization Enable Bit Busy Position */
#define RTC_MODE1_SYNCBUSY_COUNTSYNC_Msk      (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_COUNTSYNC_Pos)  /* (RTC_MODE1_SYNCBUSY) Count Synchronization Enable Bit Busy Mask */
#define RTC_MODE1_SYNCBUSY_COUNTSYNC(value)   (RTC_MODE1_SYNCBUSY_COUNTSYNC_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COUNTSYNC_Pos)) /* Assigment of value for COUNTSYNC in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_GP0_Pos            _UINT32_(16)                                         /* (RTC_MODE1_SYNCBUSY) General Purpose 0 Register Busy Position */
#define RTC_MODE1_SYNCBUSY_GP0_Msk            (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_GP0_Pos)        /* (RTC_MODE1_SYNCBUSY) General Purpose 0 Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_GP0(value)         (RTC_MODE1_SYNCBUSY_GP0_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_GP0_Pos)) /* Assigment of value for GP0 in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_GP1_Pos            _UINT32_(17)                                         /* (RTC_MODE1_SYNCBUSY) General Purpose 1 Register Busy Position */
#define RTC_MODE1_SYNCBUSY_GP1_Msk            (_UINT32_(0x1) << RTC_MODE1_SYNCBUSY_GP1_Pos)        /* (RTC_MODE1_SYNCBUSY) General Purpose 1 Register Busy Mask */
#define RTC_MODE1_SYNCBUSY_GP1(value)         (RTC_MODE1_SYNCBUSY_GP1_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_GP1_Pos)) /* Assigment of value for GP1 in the RTC_MODE1_SYNCBUSY register */
#define RTC_MODE1_SYNCBUSY_Msk                _UINT32_(0x0003807F)                                 /* (RTC_MODE1_SYNCBUSY) Register Mask  */

#define RTC_MODE1_SYNCBUSY_COMP_Pos           _UINT32_(5)                                          /* (RTC_MODE1_SYNCBUSY Position) COMP x Register Busy */
#define RTC_MODE1_SYNCBUSY_COMP_Msk           (_UINT32_(0x3) << RTC_MODE1_SYNCBUSY_COMP_Pos)       /* (RTC_MODE1_SYNCBUSY Mask) COMP */
#define RTC_MODE1_SYNCBUSY_COMP(value)        (RTC_MODE1_SYNCBUSY_COMP_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_COMP_Pos)) 
#define RTC_MODE1_SYNCBUSY_GP_Pos             _UINT32_(16)                                         /* (RTC_MODE1_SYNCBUSY Position) General Purpose x Register Busy */
#define RTC_MODE1_SYNCBUSY_GP_Msk             (_UINT32_(0x3) << RTC_MODE1_SYNCBUSY_GP_Pos)         /* (RTC_MODE1_SYNCBUSY Mask) GP */
#define RTC_MODE1_SYNCBUSY_GP(value)          (RTC_MODE1_SYNCBUSY_GP_Msk & (_UINT32_(value) << RTC_MODE1_SYNCBUSY_GP_Pos)) 

/* -------- RTC_MODE2_SYNCBUSY : (RTC Offset: 0x10) ( R/ 32) MODE2 Synchronization Busy Status -------- */
#define RTC_MODE2_SYNCBUSY_RESETVALUE         _UINT32_(0x00)                                       /*  (RTC_MODE2_SYNCBUSY) MODE2 Synchronization Busy Status  Reset Value */

#define RTC_MODE2_SYNCBUSY_SWRST_Pos          _UINT32_(0)                                          /* (RTC_MODE2_SYNCBUSY) Software Reset Bit Busy Position */
#define RTC_MODE2_SYNCBUSY_SWRST_Msk          (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_SWRST_Pos)      /* (RTC_MODE2_SYNCBUSY) Software Reset Bit Busy Mask */
#define RTC_MODE2_SYNCBUSY_SWRST(value)       (RTC_MODE2_SYNCBUSY_SWRST_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_ENABLE_Pos         _UINT32_(1)                                          /* (RTC_MODE2_SYNCBUSY) Enable Bit Busy Position */
#define RTC_MODE2_SYNCBUSY_ENABLE_Msk         (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_ENABLE_Pos)     /* (RTC_MODE2_SYNCBUSY) Enable Bit Busy Mask */
#define RTC_MODE2_SYNCBUSY_ENABLE(value)      (RTC_MODE2_SYNCBUSY_ENABLE_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_FREQCORR_Pos       _UINT32_(2)                                          /* (RTC_MODE2_SYNCBUSY) FREQCORR Register Busy Position */
#define RTC_MODE2_SYNCBUSY_FREQCORR_Msk       (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_FREQCORR_Pos)   /* (RTC_MODE2_SYNCBUSY) FREQCORR Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_FREQCORR(value)    (RTC_MODE2_SYNCBUSY_FREQCORR_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_FREQCORR_Pos)) /* Assigment of value for FREQCORR in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_CLOCK_Pos          _UINT32_(3)                                          /* (RTC_MODE2_SYNCBUSY) CLOCK Register Busy Position */
#define RTC_MODE2_SYNCBUSY_CLOCK_Msk          (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_CLOCK_Pos)      /* (RTC_MODE2_SYNCBUSY) CLOCK Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_CLOCK(value)       (RTC_MODE2_SYNCBUSY_CLOCK_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_CLOCK_Pos)) /* Assigment of value for CLOCK in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_ALARM0_Pos         _UINT32_(5)                                          /* (RTC_MODE2_SYNCBUSY) ALARM Register Busy Position */
#define RTC_MODE2_SYNCBUSY_ALARM0_Msk         (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_ALARM0_Pos)     /* (RTC_MODE2_SYNCBUSY) ALARM Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_ALARM0(value)      (RTC_MODE2_SYNCBUSY_ALARM0_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_ALARM0_Pos)) /* Assigment of value for ALARM0 in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_MASK0_Pos          _UINT32_(11)                                         /* (RTC_MODE2_SYNCBUSY) MASK Register Busy Position */
#define RTC_MODE2_SYNCBUSY_MASK0_Msk          (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_MASK0_Pos)      /* (RTC_MODE2_SYNCBUSY) MASK Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_MASK0(value)       (RTC_MODE2_SYNCBUSY_MASK0_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_MASK0_Pos)) /* Assigment of value for MASK0 in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_CLOCKSYNC_Pos      _UINT32_(15)                                         /* (RTC_MODE2_SYNCBUSY) Clock Synchronization Enable Bit Busy Position */
#define RTC_MODE2_SYNCBUSY_CLOCKSYNC_Msk      (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_CLOCKSYNC_Pos)  /* (RTC_MODE2_SYNCBUSY) Clock Synchronization Enable Bit Busy Mask */
#define RTC_MODE2_SYNCBUSY_CLOCKSYNC(value)   (RTC_MODE2_SYNCBUSY_CLOCKSYNC_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_CLOCKSYNC_Pos)) /* Assigment of value for CLOCKSYNC in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_GP0_Pos            _UINT32_(16)                                         /* (RTC_MODE2_SYNCBUSY) General Purpose 0 Register Busy Position */
#define RTC_MODE2_SYNCBUSY_GP0_Msk            (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_GP0_Pos)        /* (RTC_MODE2_SYNCBUSY) General Purpose 0 Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_GP0(value)         (RTC_MODE2_SYNCBUSY_GP0_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_GP0_Pos)) /* Assigment of value for GP0 in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_GP1_Pos            _UINT32_(17)                                         /* (RTC_MODE2_SYNCBUSY) General Purpose 1 Register Busy Position */
#define RTC_MODE2_SYNCBUSY_GP1_Msk            (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_GP1_Pos)        /* (RTC_MODE2_SYNCBUSY) General Purpose 1 Register Busy Mask */
#define RTC_MODE2_SYNCBUSY_GP1(value)         (RTC_MODE2_SYNCBUSY_GP1_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_GP1_Pos)) /* Assigment of value for GP1 in the RTC_MODE2_SYNCBUSY register */
#define RTC_MODE2_SYNCBUSY_Msk                _UINT32_(0x0003882F)                                 /* (RTC_MODE2_SYNCBUSY) Register Mask  */

#define RTC_MODE2_SYNCBUSY_ALARM_Pos          _UINT32_(5)                                          /* (RTC_MODE2_SYNCBUSY Position) ALARM Register Busy */
#define RTC_MODE2_SYNCBUSY_ALARM_Msk          (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_ALARM_Pos)      /* (RTC_MODE2_SYNCBUSY Mask) ALARM */
#define RTC_MODE2_SYNCBUSY_ALARM(value)       (RTC_MODE2_SYNCBUSY_ALARM_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_ALARM_Pos)) 
#define RTC_MODE2_SYNCBUSY_MASK_Pos           _UINT32_(11)                                         /* (RTC_MODE2_SYNCBUSY Position) MASK Register Busy */
#define RTC_MODE2_SYNCBUSY_MASK_Msk           (_UINT32_(0x1) << RTC_MODE2_SYNCBUSY_MASK_Pos)       /* (RTC_MODE2_SYNCBUSY Mask) MASK */
#define RTC_MODE2_SYNCBUSY_MASK(value)        (RTC_MODE2_SYNCBUSY_MASK_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_MASK_Pos)) 
#define RTC_MODE2_SYNCBUSY_GP_Pos             _UINT32_(16)                                         /* (RTC_MODE2_SYNCBUSY Position) General Purpose x Register Busy */
#define RTC_MODE2_SYNCBUSY_GP_Msk             (_UINT32_(0x3) << RTC_MODE2_SYNCBUSY_GP_Pos)         /* (RTC_MODE2_SYNCBUSY Mask) GP */
#define RTC_MODE2_SYNCBUSY_GP(value)          (RTC_MODE2_SYNCBUSY_GP_Msk & (_UINT32_(value) << RTC_MODE2_SYNCBUSY_GP_Pos)) 

/* -------- RTC_FREQCORR : (RTC Offset: 0x14) (R/W 8) Frequency Correction -------- */
#define RTC_FREQCORR_RESETVALUE               _UINT8_(0x00)                                        /*  (RTC_FREQCORR) Frequency Correction  Reset Value */

#define RTC_FREQCORR_VALUE_Pos                _UINT8_(0)                                           /* (RTC_FREQCORR) Correction Value Position */
#define RTC_FREQCORR_VALUE_Msk                (_UINT8_(0x7F) << RTC_FREQCORR_VALUE_Pos)            /* (RTC_FREQCORR) Correction Value Mask */
#define RTC_FREQCORR_VALUE(value)             (RTC_FREQCORR_VALUE_Msk & (_UINT8_(value) << RTC_FREQCORR_VALUE_Pos)) /* Assigment of value for VALUE in the RTC_FREQCORR register */
#define RTC_FREQCORR_SIGN_Pos                 _UINT8_(7)                                           /* (RTC_FREQCORR) Correction Sign Position */
#define RTC_FREQCORR_SIGN_Msk                 (_UINT8_(0x1) << RTC_FREQCORR_SIGN_Pos)              /* (RTC_FREQCORR) Correction Sign Mask */
#define RTC_FREQCORR_SIGN(value)              (RTC_FREQCORR_SIGN_Msk & (_UINT8_(value) << RTC_FREQCORR_SIGN_Pos)) /* Assigment of value for SIGN in the RTC_FREQCORR register */
#define RTC_FREQCORR_Msk                      _UINT8_(0xFF)                                        /* (RTC_FREQCORR) Register Mask  */


/* -------- RTC_MODE0_COUNT : (RTC Offset: 0x18) (R/W 32) MODE0 Counter Value -------- */
#define RTC_MODE0_COUNT_RESETVALUE            _UINT32_(0x00)                                       /*  (RTC_MODE0_COUNT) MODE0 Counter Value  Reset Value */

#define RTC_MODE0_COUNT_COUNT_Pos             _UINT32_(0)                                          /* (RTC_MODE0_COUNT) Counter Value Position */
#define RTC_MODE0_COUNT_COUNT_Msk             (_UINT32_(0xFFFFFFFF) << RTC_MODE0_COUNT_COUNT_Pos)  /* (RTC_MODE0_COUNT) Counter Value Mask */
#define RTC_MODE0_COUNT_COUNT(value)          (RTC_MODE0_COUNT_COUNT_Msk & (_UINT32_(value) << RTC_MODE0_COUNT_COUNT_Pos)) /* Assigment of value for COUNT in the RTC_MODE0_COUNT register */
#define RTC_MODE0_COUNT_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE0_COUNT) Register Mask  */


/* -------- RTC_MODE1_COUNT : (RTC Offset: 0x18) (R/W 16) MODE1 Counter Value -------- */
#define RTC_MODE1_COUNT_RESETVALUE            _UINT16_(0x00)                                       /*  (RTC_MODE1_COUNT) MODE1 Counter Value  Reset Value */

#define RTC_MODE1_COUNT_COUNT_Pos             _UINT16_(0)                                          /* (RTC_MODE1_COUNT) Counter Value Position */
#define RTC_MODE1_COUNT_COUNT_Msk             (_UINT16_(0xFFFF) << RTC_MODE1_COUNT_COUNT_Pos)      /* (RTC_MODE1_COUNT) Counter Value Mask */
#define RTC_MODE1_COUNT_COUNT(value)          (RTC_MODE1_COUNT_COUNT_Msk & (_UINT16_(value) << RTC_MODE1_COUNT_COUNT_Pos)) /* Assigment of value for COUNT in the RTC_MODE1_COUNT register */
#define RTC_MODE1_COUNT_Msk                   _UINT16_(0xFFFF)                                     /* (RTC_MODE1_COUNT) Register Mask  */


/* -------- RTC_MODE2_CLOCK : (RTC Offset: 0x18) (R/W 32) MODE2 Clock Value -------- */
#define RTC_MODE2_CLOCK_RESETVALUE            _UINT32_(0x00)                                       /*  (RTC_MODE2_CLOCK) MODE2 Clock Value  Reset Value */

#define RTC_MODE2_CLOCK_SECOND_Pos            _UINT32_(0)                                          /* (RTC_MODE2_CLOCK) Second Position */
#define RTC_MODE2_CLOCK_SECOND_Msk            (_UINT32_(0x3F) << RTC_MODE2_CLOCK_SECOND_Pos)       /* (RTC_MODE2_CLOCK) Second Mask */
#define RTC_MODE2_CLOCK_SECOND(value)         (RTC_MODE2_CLOCK_SECOND_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_SECOND_Pos)) /* Assigment of value for SECOND in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_MINUTE_Pos            _UINT32_(6)                                          /* (RTC_MODE2_CLOCK) Minute Position */
#define RTC_MODE2_CLOCK_MINUTE_Msk            (_UINT32_(0x3F) << RTC_MODE2_CLOCK_MINUTE_Pos)       /* (RTC_MODE2_CLOCK) Minute Mask */
#define RTC_MODE2_CLOCK_MINUTE(value)         (RTC_MODE2_CLOCK_MINUTE_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_MINUTE_Pos)) /* Assigment of value for MINUTE in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_HOUR_Pos              _UINT32_(12)                                         /* (RTC_MODE2_CLOCK) Hour Position */
#define RTC_MODE2_CLOCK_HOUR_Msk              (_UINT32_(0x1F) << RTC_MODE2_CLOCK_HOUR_Pos)         /* (RTC_MODE2_CLOCK) Hour Mask */
#define RTC_MODE2_CLOCK_HOUR(value)           (RTC_MODE2_CLOCK_HOUR_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_HOUR_Pos)) /* Assigment of value for HOUR in the RTC_MODE2_CLOCK register */
#define   RTC_MODE2_CLOCK_HOUR_AM_Val         _UINT32_(0x0)                                        /* (RTC_MODE2_CLOCK) AM when CTRLA.CLKREP in 12-hour (AM/PM) mode  */
#define   RTC_MODE2_CLOCK_HOUR_PM_Val         _UINT32_(0x10)                                       /* (RTC_MODE2_CLOCK) PM when CTRLA.CLKREP in 12-hour (AM/PM) mode  */
#define RTC_MODE2_CLOCK_HOUR_AM               (RTC_MODE2_CLOCK_HOUR_AM_Val << RTC_MODE2_CLOCK_HOUR_Pos) /* (RTC_MODE2_CLOCK) AM when CTRLA.CLKREP in 12-hour (AM/PM) mode Position  */
#define RTC_MODE2_CLOCK_HOUR_PM               (RTC_MODE2_CLOCK_HOUR_PM_Val << RTC_MODE2_CLOCK_HOUR_Pos) /* (RTC_MODE2_CLOCK) PM when CTRLA.CLKREP in 12-hour (AM/PM) mode Position  */
#define RTC_MODE2_CLOCK_DAY_Pos               _UINT32_(17)                                         /* (RTC_MODE2_CLOCK) Day Position */
#define RTC_MODE2_CLOCK_DAY_Msk               (_UINT32_(0x1F) << RTC_MODE2_CLOCK_DAY_Pos)          /* (RTC_MODE2_CLOCK) Day Mask */
#define RTC_MODE2_CLOCK_DAY(value)            (RTC_MODE2_CLOCK_DAY_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_DAY_Pos)) /* Assigment of value for DAY in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_MONTH_Pos             _UINT32_(22)                                         /* (RTC_MODE2_CLOCK) Month Position */
#define RTC_MODE2_CLOCK_MONTH_Msk             (_UINT32_(0xF) << RTC_MODE2_CLOCK_MONTH_Pos)         /* (RTC_MODE2_CLOCK) Month Mask */
#define RTC_MODE2_CLOCK_MONTH(value)          (RTC_MODE2_CLOCK_MONTH_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_MONTH_Pos)) /* Assigment of value for MONTH in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_YEAR_Pos              _UINT32_(26)                                         /* (RTC_MODE2_CLOCK) Year Position */
#define RTC_MODE2_CLOCK_YEAR_Msk              (_UINT32_(0x3F) << RTC_MODE2_CLOCK_YEAR_Pos)         /* (RTC_MODE2_CLOCK) Year Mask */
#define RTC_MODE2_CLOCK_YEAR(value)           (RTC_MODE2_CLOCK_YEAR_Msk & (_UINT32_(value) << RTC_MODE2_CLOCK_YEAR_Pos)) /* Assigment of value for YEAR in the RTC_MODE2_CLOCK register */
#define RTC_MODE2_CLOCK_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE2_CLOCK) Register Mask  */


/* -------- RTC_MODE1_PER : (RTC Offset: 0x1C) (R/W 16) MODE1 Counter Period -------- */
#define RTC_MODE1_PER_RESETVALUE              _UINT16_(0x00)                                       /*  (RTC_MODE1_PER) MODE1 Counter Period  Reset Value */

#define RTC_MODE1_PER_PER_Pos                 _UINT16_(0)                                          /* (RTC_MODE1_PER) Counter Period Position */
#define RTC_MODE1_PER_PER_Msk                 (_UINT16_(0xFFFF) << RTC_MODE1_PER_PER_Pos)          /* (RTC_MODE1_PER) Counter Period Mask */
#define RTC_MODE1_PER_PER(value)              (RTC_MODE1_PER_PER_Msk & (_UINT16_(value) << RTC_MODE1_PER_PER_Pos)) /* Assigment of value for PER in the RTC_MODE1_PER register */
#define RTC_MODE1_PER_Msk                     _UINT16_(0xFFFF)                                     /* (RTC_MODE1_PER) Register Mask  */


/* -------- RTC_MODE0_COMP0 : (RTC Offset: 0x20) (R/W 32) MODE0 Compare Value -------- */
#define RTC_MODE0_COMP0_RESETVALUE            _UINT32_(0x00)                                       /*  (RTC_MODE0_COMP0) MODE0 Compare Value  Reset Value */

#define RTC_MODE0_COMP0_COMP_Pos              _UINT32_(0)                                          /* (RTC_MODE0_COMP0) Compare Value Position */
#define RTC_MODE0_COMP0_COMP_Msk              (_UINT32_(0xFFFFFFFF) << RTC_MODE0_COMP0_COMP_Pos)   /* (RTC_MODE0_COMP0) Compare Value Mask */
#define RTC_MODE0_COMP0_COMP(value)           (RTC_MODE0_COMP0_COMP_Msk & (_UINT32_(value) << RTC_MODE0_COMP0_COMP_Pos)) /* Assigment of value for COMP in the RTC_MODE0_COMP0 register */
#define RTC_MODE0_COMP0_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE0_COMP0) Register Mask  */


/* -------- RTC_MODE1_COMP : (RTC Offset: 0x20) (R/W 16) MODE1 Compare n Value -------- */
#define RTC_MODE1_COMP_RESETVALUE             _UINT16_(0x00)                                       /*  (RTC_MODE1_COMP) MODE1 Compare n Value  Reset Value */

#define RTC_MODE1_COMP_COMP_Pos               _UINT16_(0)                                          /* (RTC_MODE1_COMP) Compare Value Position */
#define RTC_MODE1_COMP_COMP_Msk               (_UINT16_(0xFFFF) << RTC_MODE1_COMP_COMP_Pos)        /* (RTC_MODE1_COMP) Compare Value Mask */
#define RTC_MODE1_COMP_COMP(value)            (RTC_MODE1_COMP_COMP_Msk & (_UINT16_(value) << RTC_MODE1_COMP_COMP_Pos)) /* Assigment of value for COMP in the RTC_MODE1_COMP register */
#define RTC_MODE1_COMP_Msk                    _UINT16_(0xFFFF)                                     /* (RTC_MODE1_COMP) Register Mask  */


/* -------- RTC_MODE2_ALARM0 : (RTC Offset: 0x20) (R/W 32) MODE2 Alarm Value -------- */
#define RTC_MODE2_ALARM0_RESETVALUE           _UINT32_(0x00)                                       /*  (RTC_MODE2_ALARM0) MODE2 Alarm Value  Reset Value */

#define RTC_MODE2_ALARM0_SECOND_Pos           _UINT32_(0)                                          /* (RTC_MODE2_ALARM0) Second Position */
#define RTC_MODE2_ALARM0_SECOND_Msk           (_UINT32_(0x3F) << RTC_MODE2_ALARM0_SECOND_Pos)      /* (RTC_MODE2_ALARM0) Second Mask */
#define RTC_MODE2_ALARM0_SECOND(value)        (RTC_MODE2_ALARM0_SECOND_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_SECOND_Pos)) /* Assigment of value for SECOND in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_MINUTE_Pos           _UINT32_(6)                                          /* (RTC_MODE2_ALARM0) Minute Position */
#define RTC_MODE2_ALARM0_MINUTE_Msk           (_UINT32_(0x3F) << RTC_MODE2_ALARM0_MINUTE_Pos)      /* (RTC_MODE2_ALARM0) Minute Mask */
#define RTC_MODE2_ALARM0_MINUTE(value)        (RTC_MODE2_ALARM0_MINUTE_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_MINUTE_Pos)) /* Assigment of value for MINUTE in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_HOUR_Pos             _UINT32_(12)                                         /* (RTC_MODE2_ALARM0) Hour Position */
#define RTC_MODE2_ALARM0_HOUR_Msk             (_UINT32_(0x1F) << RTC_MODE2_ALARM0_HOUR_Pos)        /* (RTC_MODE2_ALARM0) Hour Mask */
#define RTC_MODE2_ALARM0_HOUR(value)          (RTC_MODE2_ALARM0_HOUR_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_HOUR_Pos)) /* Assigment of value for HOUR in the RTC_MODE2_ALARM0 register */
#define   RTC_MODE2_ALARM0_HOUR_AM_Val        _UINT32_(0x0)                                        /* (RTC_MODE2_ALARM0) AM when CTRLA.CLKREP in 12-hour (AM/PM) mode  */
#define   RTC_MODE2_ALARM0_HOUR_PM_Val        _UINT32_(0x10)                                       /* (RTC_MODE2_ALARM0) PM when CTRLA.CLKREP in 12-hour (AM/PM) mode  */
#define RTC_MODE2_ALARM0_HOUR_AM              (RTC_MODE2_ALARM0_HOUR_AM_Val << RTC_MODE2_ALARM0_HOUR_Pos) /* (RTC_MODE2_ALARM0) AM when CTRLA.CLKREP in 12-hour (AM/PM) mode Position  */
#define RTC_MODE2_ALARM0_HOUR_PM              (RTC_MODE2_ALARM0_HOUR_PM_Val << RTC_MODE2_ALARM0_HOUR_Pos) /* (RTC_MODE2_ALARM0) PM when CTRLA.CLKREP in 12-hour (AM/PM) mode Position  */
#define RTC_MODE2_ALARM0_DAY_Pos              _UINT32_(17)                                         /* (RTC_MODE2_ALARM0) Day Position */
#define RTC_MODE2_ALARM0_DAY_Msk              (_UINT32_(0x1F) << RTC_MODE2_ALARM0_DAY_Pos)         /* (RTC_MODE2_ALARM0) Day Mask */
#define RTC_MODE2_ALARM0_DAY(value)           (RTC_MODE2_ALARM0_DAY_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_DAY_Pos)) /* Assigment of value for DAY in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_MONTH_Pos            _UINT32_(22)                                         /* (RTC_MODE2_ALARM0) Month Position */
#define RTC_MODE2_ALARM0_MONTH_Msk            (_UINT32_(0xF) << RTC_MODE2_ALARM0_MONTH_Pos)        /* (RTC_MODE2_ALARM0) Month Mask */
#define RTC_MODE2_ALARM0_MONTH(value)         (RTC_MODE2_ALARM0_MONTH_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_MONTH_Pos)) /* Assigment of value for MONTH in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_YEAR_Pos             _UINT32_(26)                                         /* (RTC_MODE2_ALARM0) Year Position */
#define RTC_MODE2_ALARM0_YEAR_Msk             (_UINT32_(0x3F) << RTC_MODE2_ALARM0_YEAR_Pos)        /* (RTC_MODE2_ALARM0) Year Mask */
#define RTC_MODE2_ALARM0_YEAR(value)          (RTC_MODE2_ALARM0_YEAR_Msk & (_UINT32_(value) << RTC_MODE2_ALARM0_YEAR_Pos)) /* Assigment of value for YEAR in the RTC_MODE2_ALARM0 register */
#define RTC_MODE2_ALARM0_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE2_ALARM0) Register Mask  */


/* -------- RTC_MODE2_MASK0 : (RTC Offset: 0x24) (R/W 8) MODE2 Alarm Mask -------- */
#define RTC_MODE2_MASK0_RESETVALUE            _UINT8_(0x00)                                        /*  (RTC_MODE2_MASK0) MODE2 Alarm Mask  Reset Value */

#define RTC_MODE2_MASK0_SEL_Pos               _UINT8_(0)                                           /* (RTC_MODE2_MASK0) Alarm Mask Selection Position */
#define RTC_MODE2_MASK0_SEL_Msk               (_UINT8_(0x7) << RTC_MODE2_MASK0_SEL_Pos)            /* (RTC_MODE2_MASK0) Alarm Mask Selection Mask */
#define RTC_MODE2_MASK0_SEL(value)            (RTC_MODE2_MASK0_SEL_Msk & (_UINT8_(value) << RTC_MODE2_MASK0_SEL_Pos)) /* Assigment of value for SEL in the RTC_MODE2_MASK0 register */
#define   RTC_MODE2_MASK0_SEL_OFF_Val         _UINT8_(0x0)                                         /* (RTC_MODE2_MASK0) Alarm Disabled  */
#define   RTC_MODE2_MASK0_SEL_SS_Val          _UINT8_(0x1)                                         /* (RTC_MODE2_MASK0) Match seconds only  */
#define   RTC_MODE2_MASK0_SEL_MMSS_Val        _UINT8_(0x2)                                         /* (RTC_MODE2_MASK0) Match seconds and minutes only  */
#define   RTC_MODE2_MASK0_SEL_HHMMSS_Val      _UINT8_(0x3)                                         /* (RTC_MODE2_MASK0) Match seconds, minutes, and hours only  */
#define   RTC_MODE2_MASK0_SEL_DDHHMMSS_Val    _UINT8_(0x4)                                         /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, and days only  */
#define   RTC_MODE2_MASK0_SEL_MMDDHHMMSS_Val  _UINT8_(0x5)                                         /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, days, and months only  */
#define   RTC_MODE2_MASK0_SEL_YYMMDDHHMMSS_Val _UINT8_(0x6)                                         /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, days, months, and years  */
#define RTC_MODE2_MASK0_SEL_OFF               (RTC_MODE2_MASK0_SEL_OFF_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Alarm Disabled Position  */
#define RTC_MODE2_MASK0_SEL_SS                (RTC_MODE2_MASK0_SEL_SS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds only Position  */
#define RTC_MODE2_MASK0_SEL_MMSS              (RTC_MODE2_MASK0_SEL_MMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds and minutes only Position  */
#define RTC_MODE2_MASK0_SEL_HHMMSS            (RTC_MODE2_MASK0_SEL_HHMMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds, minutes, and hours only Position  */
#define RTC_MODE2_MASK0_SEL_DDHHMMSS          (RTC_MODE2_MASK0_SEL_DDHHMMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, and days only Position  */
#define RTC_MODE2_MASK0_SEL_MMDDHHMMSS        (RTC_MODE2_MASK0_SEL_MMDDHHMMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, days, and months only Position  */
#define RTC_MODE2_MASK0_SEL_YYMMDDHHMMSS      (RTC_MODE2_MASK0_SEL_YYMMDDHHMMSS_Val << RTC_MODE2_MASK0_SEL_Pos) /* (RTC_MODE2_MASK0) Match seconds, minutes, hours, days, months, and years Position  */
#define RTC_MODE2_MASK0_Msk                   _UINT8_(0x07)                                        /* (RTC_MODE2_MASK0) Register Mask  */


/* -------- RTC_GP : (RTC Offset: 0x40) (R/W 32) General Purpose -------- */
#define RTC_GP_RESETVALUE                     _UINT32_(0x00)                                       /*  (RTC_GP) General Purpose  Reset Value */

#define RTC_GP_GP_Pos                         _UINT32_(0)                                          /* (RTC_GP) General Purpose Position */
#define RTC_GP_GP_Msk                         (_UINT32_(0xFFFFFFFF) << RTC_GP_GP_Pos)              /* (RTC_GP) General Purpose Mask */
#define RTC_GP_GP(value)                      (RTC_GP_GP_Msk & (_UINT32_(value) << RTC_GP_GP_Pos)) /* Assigment of value for GP in the RTC_GP register */
#define RTC_GP_Msk                            _UINT32_(0xFFFFFFFF)                                 /* (RTC_GP) Register Mask  */


/* -------- RTC_TAMPCTRL : (RTC Offset: 0x60) (R/W 32) Tamper Control -------- */
#define RTC_TAMPCTRL_RESETVALUE               _UINT32_(0x00)                                       /*  (RTC_TAMPCTRL) Tamper Control  Reset Value */

#define RTC_TAMPCTRL_IN0ACT_Pos               _UINT32_(0)                                          /* (RTC_TAMPCTRL) Tamper Input 0 Action Position */
#define RTC_TAMPCTRL_IN0ACT_Msk               (_UINT32_(0x3) << RTC_TAMPCTRL_IN0ACT_Pos)           /* (RTC_TAMPCTRL) Tamper Input 0 Action Mask */
#define RTC_TAMPCTRL_IN0ACT(value)            (RTC_TAMPCTRL_IN0ACT_Msk & (_UINT32_(value) << RTC_TAMPCTRL_IN0ACT_Pos)) /* Assigment of value for IN0ACT in the RTC_TAMPCTRL register */
#define   RTC_TAMPCTRL_IN0ACT_OFF_Val         _UINT32_(0x0)                                        /* (RTC_TAMPCTRL) Off (Disabled)  */
#define   RTC_TAMPCTRL_IN0ACT_WAKE_Val        _UINT32_(0x1)                                        /* (RTC_TAMPCTRL) Wake and set Tamper flag  */
#define   RTC_TAMPCTRL_IN0ACT_CAPTURE_Val     _UINT32_(0x2)                                        /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag  */
#define   RTC_TAMPCTRL_IN0ACT_ACTL_Val        _UINT32_(0x3)                                        /* (RTC_TAMPCTRL) Compare IN0 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag  */
#define RTC_TAMPCTRL_IN0ACT_OFF               (RTC_TAMPCTRL_IN0ACT_OFF_Val << RTC_TAMPCTRL_IN0ACT_Pos) /* (RTC_TAMPCTRL) Off (Disabled) Position  */
#define RTC_TAMPCTRL_IN0ACT_WAKE              (RTC_TAMPCTRL_IN0ACT_WAKE_Val << RTC_TAMPCTRL_IN0ACT_Pos) /* (RTC_TAMPCTRL) Wake and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN0ACT_CAPTURE           (RTC_TAMPCTRL_IN0ACT_CAPTURE_Val << RTC_TAMPCTRL_IN0ACT_Pos) /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN0ACT_ACTL              (RTC_TAMPCTRL_IN0ACT_ACTL_Val << RTC_TAMPCTRL_IN0ACT_Pos) /* (RTC_TAMPCTRL) Compare IN0 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN1ACT_Pos               _UINT32_(2)                                          /* (RTC_TAMPCTRL) Tamper Input 1 Action Position */
#define RTC_TAMPCTRL_IN1ACT_Msk               (_UINT32_(0x3) << RTC_TAMPCTRL_IN1ACT_Pos)           /* (RTC_TAMPCTRL) Tamper Input 1 Action Mask */
#define RTC_TAMPCTRL_IN1ACT(value)            (RTC_TAMPCTRL_IN1ACT_Msk & (_UINT32_(value) << RTC_TAMPCTRL_IN1ACT_Pos)) /* Assigment of value for IN1ACT in the RTC_TAMPCTRL register */
#define   RTC_TAMPCTRL_IN1ACT_OFF_Val         _UINT32_(0x0)                                        /* (RTC_TAMPCTRL) Off (Disabled)  */
#define   RTC_TAMPCTRL_IN1ACT_WAKE_Val        _UINT32_(0x1)                                        /* (RTC_TAMPCTRL) Wake and set Tamper flag  */
#define   RTC_TAMPCTRL_IN1ACT_CAPTURE_Val     _UINT32_(0x2)                                        /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag  */
#define   RTC_TAMPCTRL_IN1ACT_ACTL_Val        _UINT32_(0x3)                                        /* (RTC_TAMPCTRL) Compare IN1 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag  */
#define RTC_TAMPCTRL_IN1ACT_OFF               (RTC_TAMPCTRL_IN1ACT_OFF_Val << RTC_TAMPCTRL_IN1ACT_Pos) /* (RTC_TAMPCTRL) Off (Disabled) Position  */
#define RTC_TAMPCTRL_IN1ACT_WAKE              (RTC_TAMPCTRL_IN1ACT_WAKE_Val << RTC_TAMPCTRL_IN1ACT_Pos) /* (RTC_TAMPCTRL) Wake and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN1ACT_CAPTURE           (RTC_TAMPCTRL_IN1ACT_CAPTURE_Val << RTC_TAMPCTRL_IN1ACT_Pos) /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN1ACT_ACTL              (RTC_TAMPCTRL_IN1ACT_ACTL_Val << RTC_TAMPCTRL_IN1ACT_Pos) /* (RTC_TAMPCTRL) Compare IN1 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN2ACT_Pos               _UINT32_(4)                                          /* (RTC_TAMPCTRL) Tamper Input 2 Action Position */
#define RTC_TAMPCTRL_IN2ACT_Msk               (_UINT32_(0x3) << RTC_TAMPCTRL_IN2ACT_Pos)           /* (RTC_TAMPCTRL) Tamper Input 2 Action Mask */
#define RTC_TAMPCTRL_IN2ACT(value)            (RTC_TAMPCTRL_IN2ACT_Msk & (_UINT32_(value) << RTC_TAMPCTRL_IN2ACT_Pos)) /* Assigment of value for IN2ACT in the RTC_TAMPCTRL register */
#define   RTC_TAMPCTRL_IN2ACT_OFF_Val         _UINT32_(0x0)                                        /* (RTC_TAMPCTRL) Off (Disabled)  */
#define   RTC_TAMPCTRL_IN2ACT_WAKE_Val        _UINT32_(0x1)                                        /* (RTC_TAMPCTRL) Wake and set Tamper flag  */
#define   RTC_TAMPCTRL_IN2ACT_CAPTURE_Val     _UINT32_(0x2)                                        /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag  */
#define   RTC_TAMPCTRL_IN2ACT_ACTL_Val        _UINT32_(0x3)                                        /* (RTC_TAMPCTRL) Compare IN2 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag  */
#define RTC_TAMPCTRL_IN2ACT_OFF               (RTC_TAMPCTRL_IN2ACT_OFF_Val << RTC_TAMPCTRL_IN2ACT_Pos) /* (RTC_TAMPCTRL) Off (Disabled) Position  */
#define RTC_TAMPCTRL_IN2ACT_WAKE              (RTC_TAMPCTRL_IN2ACT_WAKE_Val << RTC_TAMPCTRL_IN2ACT_Pos) /* (RTC_TAMPCTRL) Wake and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN2ACT_CAPTURE           (RTC_TAMPCTRL_IN2ACT_CAPTURE_Val << RTC_TAMPCTRL_IN2ACT_Pos) /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN2ACT_ACTL              (RTC_TAMPCTRL_IN2ACT_ACTL_Val << RTC_TAMPCTRL_IN2ACT_Pos) /* (RTC_TAMPCTRL) Compare IN2 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN3ACT_Pos               _UINT32_(6)                                          /* (RTC_TAMPCTRL) Tamper Input 3 Action Position */
#define RTC_TAMPCTRL_IN3ACT_Msk               (_UINT32_(0x3) << RTC_TAMPCTRL_IN3ACT_Pos)           /* (RTC_TAMPCTRL) Tamper Input 3 Action Mask */
#define RTC_TAMPCTRL_IN3ACT(value)            (RTC_TAMPCTRL_IN3ACT_Msk & (_UINT32_(value) << RTC_TAMPCTRL_IN3ACT_Pos)) /* Assigment of value for IN3ACT in the RTC_TAMPCTRL register */
#define   RTC_TAMPCTRL_IN3ACT_OFF_Val         _UINT32_(0x0)                                        /* (RTC_TAMPCTRL) Off (Disabled)  */
#define   RTC_TAMPCTRL_IN3ACT_WAKE_Val        _UINT32_(0x1)                                        /* (RTC_TAMPCTRL) Wake and set Tamper flag  */
#define   RTC_TAMPCTRL_IN3ACT_CAPTURE_Val     _UINT32_(0x2)                                        /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag  */
#define   RTC_TAMPCTRL_IN3ACT_ACTL_Val        _UINT32_(0x3)                                        /* (RTC_TAMPCTRL) Compare IN3 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag  */
#define RTC_TAMPCTRL_IN3ACT_OFF               (RTC_TAMPCTRL_IN3ACT_OFF_Val << RTC_TAMPCTRL_IN3ACT_Pos) /* (RTC_TAMPCTRL) Off (Disabled) Position  */
#define RTC_TAMPCTRL_IN3ACT_WAKE              (RTC_TAMPCTRL_IN3ACT_WAKE_Val << RTC_TAMPCTRL_IN3ACT_Pos) /* (RTC_TAMPCTRL) Wake and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN3ACT_CAPTURE           (RTC_TAMPCTRL_IN3ACT_CAPTURE_Val << RTC_TAMPCTRL_IN3ACT_Pos) /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN3ACT_ACTL              (RTC_TAMPCTRL_IN3ACT_ACTL_Val << RTC_TAMPCTRL_IN3ACT_Pos) /* (RTC_TAMPCTRL) Compare IN3 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN4ACT_Pos               _UINT32_(8)                                          /* (RTC_TAMPCTRL) Tamper Input 4 Action Position */
#define RTC_TAMPCTRL_IN4ACT_Msk               (_UINT32_(0x3) << RTC_TAMPCTRL_IN4ACT_Pos)           /* (RTC_TAMPCTRL) Tamper Input 4 Action Mask */
#define RTC_TAMPCTRL_IN4ACT(value)            (RTC_TAMPCTRL_IN4ACT_Msk & (_UINT32_(value) << RTC_TAMPCTRL_IN4ACT_Pos)) /* Assigment of value for IN4ACT in the RTC_TAMPCTRL register */
#define   RTC_TAMPCTRL_IN4ACT_OFF_Val         _UINT32_(0x0)                                        /* (RTC_TAMPCTRL) Off (Disabled)  */
#define   RTC_TAMPCTRL_IN4ACT_WAKE_Val        _UINT32_(0x1)                                        /* (RTC_TAMPCTRL) Wake and set Tamper flag  */
#define   RTC_TAMPCTRL_IN4ACT_CAPTURE_Val     _UINT32_(0x2)                                        /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag  */
#define   RTC_TAMPCTRL_IN4ACT_ACTL_Val        _UINT32_(0x3)                                        /* (RTC_TAMPCTRL) Compare IN4 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag  */
#define RTC_TAMPCTRL_IN4ACT_OFF               (RTC_TAMPCTRL_IN4ACT_OFF_Val << RTC_TAMPCTRL_IN4ACT_Pos) /* (RTC_TAMPCTRL) Off (Disabled) Position  */
#define RTC_TAMPCTRL_IN4ACT_WAKE              (RTC_TAMPCTRL_IN4ACT_WAKE_Val << RTC_TAMPCTRL_IN4ACT_Pos) /* (RTC_TAMPCTRL) Wake and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN4ACT_CAPTURE           (RTC_TAMPCTRL_IN4ACT_CAPTURE_Val << RTC_TAMPCTRL_IN4ACT_Pos) /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN4ACT_ACTL              (RTC_TAMPCTRL_IN4ACT_ACTL_Val << RTC_TAMPCTRL_IN4ACT_Pos) /* (RTC_TAMPCTRL) Compare IN4 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN5ACT_Pos               _UINT32_(10)                                         /* (RTC_TAMPCTRL) Tamper Input 5 Action Position */
#define RTC_TAMPCTRL_IN5ACT_Msk               (_UINT32_(0x3) << RTC_TAMPCTRL_IN5ACT_Pos)           /* (RTC_TAMPCTRL) Tamper Input 5 Action Mask */
#define RTC_TAMPCTRL_IN5ACT(value)            (RTC_TAMPCTRL_IN5ACT_Msk & (_UINT32_(value) << RTC_TAMPCTRL_IN5ACT_Pos)) /* Assigment of value for IN5ACT in the RTC_TAMPCTRL register */
#define   RTC_TAMPCTRL_IN5ACT_OFF_Val         _UINT32_(0x0)                                        /* (RTC_TAMPCTRL) Off (Disabled)  */
#define   RTC_TAMPCTRL_IN5ACT_WAKE_Val        _UINT32_(0x1)                                        /* (RTC_TAMPCTRL) Wake and set Tamper flag  */
#define   RTC_TAMPCTRL_IN5ACT_CAPTURE_Val     _UINT32_(0x2)                                        /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag  */
#define   RTC_TAMPCTRL_IN5ACT_ACTL_Val        _UINT32_(0x3)                                        /* (RTC_TAMPCTRL) Compare IN5 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag  */
#define RTC_TAMPCTRL_IN5ACT_OFF               (RTC_TAMPCTRL_IN5ACT_OFF_Val << RTC_TAMPCTRL_IN5ACT_Pos) /* (RTC_TAMPCTRL) Off (Disabled) Position  */
#define RTC_TAMPCTRL_IN5ACT_WAKE              (RTC_TAMPCTRL_IN5ACT_WAKE_Val << RTC_TAMPCTRL_IN5ACT_Pos) /* (RTC_TAMPCTRL) Wake and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN5ACT_CAPTURE           (RTC_TAMPCTRL_IN5ACT_CAPTURE_Val << RTC_TAMPCTRL_IN5ACT_Pos) /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN5ACT_ACTL              (RTC_TAMPCTRL_IN5ACT_ACTL_Val << RTC_TAMPCTRL_IN5ACT_Pos) /* (RTC_TAMPCTRL) Compare IN5 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN6ACT_Pos               _UINT32_(12)                                         /* (RTC_TAMPCTRL) Tamper Input 6 Action Position */
#define RTC_TAMPCTRL_IN6ACT_Msk               (_UINT32_(0x3) << RTC_TAMPCTRL_IN6ACT_Pos)           /* (RTC_TAMPCTRL) Tamper Input 6 Action Mask */
#define RTC_TAMPCTRL_IN6ACT(value)            (RTC_TAMPCTRL_IN6ACT_Msk & (_UINT32_(value) << RTC_TAMPCTRL_IN6ACT_Pos)) /* Assigment of value for IN6ACT in the RTC_TAMPCTRL register */
#define   RTC_TAMPCTRL_IN6ACT_OFF_Val         _UINT32_(0x0)                                        /* (RTC_TAMPCTRL) Off (Disabled)  */
#define   RTC_TAMPCTRL_IN6ACT_WAKE_Val        _UINT32_(0x1)                                        /* (RTC_TAMPCTRL) Wake and set Tamper flag  */
#define   RTC_TAMPCTRL_IN6ACT_CAPTURE_Val     _UINT32_(0x2)                                        /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag  */
#define   RTC_TAMPCTRL_IN6ACT_ACTL_Val        _UINT32_(0x3)                                        /* (RTC_TAMPCTRL) Compare IN6 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag  */
#define RTC_TAMPCTRL_IN6ACT_OFF               (RTC_TAMPCTRL_IN6ACT_OFF_Val << RTC_TAMPCTRL_IN6ACT_Pos) /* (RTC_TAMPCTRL) Off (Disabled) Position  */
#define RTC_TAMPCTRL_IN6ACT_WAKE              (RTC_TAMPCTRL_IN6ACT_WAKE_Val << RTC_TAMPCTRL_IN6ACT_Pos) /* (RTC_TAMPCTRL) Wake and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN6ACT_CAPTURE           (RTC_TAMPCTRL_IN6ACT_CAPTURE_Val << RTC_TAMPCTRL_IN6ACT_Pos) /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN6ACT_ACTL              (RTC_TAMPCTRL_IN6ACT_ACTL_Val << RTC_TAMPCTRL_IN6ACT_Pos) /* (RTC_TAMPCTRL) Compare IN6 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN7ACT_Pos               _UINT32_(14)                                         /* (RTC_TAMPCTRL) Tamper Input 7 Action Position */
#define RTC_TAMPCTRL_IN7ACT_Msk               (_UINT32_(0x3) << RTC_TAMPCTRL_IN7ACT_Pos)           /* (RTC_TAMPCTRL) Tamper Input 7 Action Mask */
#define RTC_TAMPCTRL_IN7ACT(value)            (RTC_TAMPCTRL_IN7ACT_Msk & (_UINT32_(value) << RTC_TAMPCTRL_IN7ACT_Pos)) /* Assigment of value for IN7ACT in the RTC_TAMPCTRL register */
#define   RTC_TAMPCTRL_IN7ACT_OFF_Val         _UINT32_(0x0)                                        /* (RTC_TAMPCTRL) Off (Disabled)  */
#define   RTC_TAMPCTRL_IN7ACT_WAKE_Val        _UINT32_(0x1)                                        /* (RTC_TAMPCTRL) Wake and set Tamper flag  */
#define   RTC_TAMPCTRL_IN7ACT_CAPTURE_Val     _UINT32_(0x2)                                        /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag  */
#define   RTC_TAMPCTRL_IN7ACT_ACTL_Val        _UINT32_(0x3)                                        /* (RTC_TAMPCTRL) Compare IN7 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag  */
#define RTC_TAMPCTRL_IN7ACT_OFF               (RTC_TAMPCTRL_IN7ACT_OFF_Val << RTC_TAMPCTRL_IN7ACT_Pos) /* (RTC_TAMPCTRL) Off (Disabled) Position  */
#define RTC_TAMPCTRL_IN7ACT_WAKE              (RTC_TAMPCTRL_IN7ACT_WAKE_Val << RTC_TAMPCTRL_IN7ACT_Pos) /* (RTC_TAMPCTRL) Wake and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN7ACT_CAPTURE           (RTC_TAMPCTRL_IN7ACT_CAPTURE_Val << RTC_TAMPCTRL_IN7ACT_Pos) /* (RTC_TAMPCTRL) Capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_IN7ACT_ACTL              (RTC_TAMPCTRL_IN7ACT_ACTL_Val << RTC_TAMPCTRL_IN7ACT_Pos) /* (RTC_TAMPCTRL) Compare IN7 to OUT. When a mismatch occurs, capture timestamp and set Tamper flag Position  */
#define RTC_TAMPCTRL_TAMLVL0_Pos              _UINT32_(16)                                         /* (RTC_TAMPCTRL) Tamper Level Select 0 Position */
#define RTC_TAMPCTRL_TAMLVL0_Msk              (_UINT32_(0x1) << RTC_TAMPCTRL_TAMLVL0_Pos)          /* (RTC_TAMPCTRL) Tamper Level Select 0 Mask */
#define RTC_TAMPCTRL_TAMLVL0(value)           (RTC_TAMPCTRL_TAMLVL0_Msk & (_UINT32_(value) << RTC_TAMPCTRL_TAMLVL0_Pos)) /* Assigment of value for TAMLVL0 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_TAMLVL1_Pos              _UINT32_(17)                                         /* (RTC_TAMPCTRL) Tamper Level Select 1 Position */
#define RTC_TAMPCTRL_TAMLVL1_Msk              (_UINT32_(0x1) << RTC_TAMPCTRL_TAMLVL1_Pos)          /* (RTC_TAMPCTRL) Tamper Level Select 1 Mask */
#define RTC_TAMPCTRL_TAMLVL1(value)           (RTC_TAMPCTRL_TAMLVL1_Msk & (_UINT32_(value) << RTC_TAMPCTRL_TAMLVL1_Pos)) /* Assigment of value for TAMLVL1 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_TAMLVL2_Pos              _UINT32_(18)                                         /* (RTC_TAMPCTRL) Tamper Level Select 2 Position */
#define RTC_TAMPCTRL_TAMLVL2_Msk              (_UINT32_(0x1) << RTC_TAMPCTRL_TAMLVL2_Pos)          /* (RTC_TAMPCTRL) Tamper Level Select 2 Mask */
#define RTC_TAMPCTRL_TAMLVL2(value)           (RTC_TAMPCTRL_TAMLVL2_Msk & (_UINT32_(value) << RTC_TAMPCTRL_TAMLVL2_Pos)) /* Assigment of value for TAMLVL2 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_TAMLVL3_Pos              _UINT32_(19)                                         /* (RTC_TAMPCTRL) Tamper Level Select 3 Position */
#define RTC_TAMPCTRL_TAMLVL3_Msk              (_UINT32_(0x1) << RTC_TAMPCTRL_TAMLVL3_Pos)          /* (RTC_TAMPCTRL) Tamper Level Select 3 Mask */
#define RTC_TAMPCTRL_TAMLVL3(value)           (RTC_TAMPCTRL_TAMLVL3_Msk & (_UINT32_(value) << RTC_TAMPCTRL_TAMLVL3_Pos)) /* Assigment of value for TAMLVL3 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_TAMLVL4_Pos              _UINT32_(20)                                         /* (RTC_TAMPCTRL) Tamper Level Select 4 Position */
#define RTC_TAMPCTRL_TAMLVL4_Msk              (_UINT32_(0x1) << RTC_TAMPCTRL_TAMLVL4_Pos)          /* (RTC_TAMPCTRL) Tamper Level Select 4 Mask */
#define RTC_TAMPCTRL_TAMLVL4(value)           (RTC_TAMPCTRL_TAMLVL4_Msk & (_UINT32_(value) << RTC_TAMPCTRL_TAMLVL4_Pos)) /* Assigment of value for TAMLVL4 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_TAMLVL5_Pos              _UINT32_(21)                                         /* (RTC_TAMPCTRL) Tamper Level Select 5 Position */
#define RTC_TAMPCTRL_TAMLVL5_Msk              (_UINT32_(0x1) << RTC_TAMPCTRL_TAMLVL5_Pos)          /* (RTC_TAMPCTRL) Tamper Level Select 5 Mask */
#define RTC_TAMPCTRL_TAMLVL5(value)           (RTC_TAMPCTRL_TAMLVL5_Msk & (_UINT32_(value) << RTC_TAMPCTRL_TAMLVL5_Pos)) /* Assigment of value for TAMLVL5 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_TAMLVL6_Pos              _UINT32_(22)                                         /* (RTC_TAMPCTRL) Tamper Level Select 6 Position */
#define RTC_TAMPCTRL_TAMLVL6_Msk              (_UINT32_(0x1) << RTC_TAMPCTRL_TAMLVL6_Pos)          /* (RTC_TAMPCTRL) Tamper Level Select 6 Mask */
#define RTC_TAMPCTRL_TAMLVL6(value)           (RTC_TAMPCTRL_TAMLVL6_Msk & (_UINT32_(value) << RTC_TAMPCTRL_TAMLVL6_Pos)) /* Assigment of value for TAMLVL6 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_TAMLVL7_Pos              _UINT32_(23)                                         /* (RTC_TAMPCTRL) Tamper Level Select 7 Position */
#define RTC_TAMPCTRL_TAMLVL7_Msk              (_UINT32_(0x1) << RTC_TAMPCTRL_TAMLVL7_Pos)          /* (RTC_TAMPCTRL) Tamper Level Select 7 Mask */
#define RTC_TAMPCTRL_TAMLVL7(value)           (RTC_TAMPCTRL_TAMLVL7_Msk & (_UINT32_(value) << RTC_TAMPCTRL_TAMLVL7_Pos)) /* Assigment of value for TAMLVL7 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_DEBNC0_Pos               _UINT32_(24)                                         /* (RTC_TAMPCTRL) Debouncer Enable 0 Position */
#define RTC_TAMPCTRL_DEBNC0_Msk               (_UINT32_(0x1) << RTC_TAMPCTRL_DEBNC0_Pos)           /* (RTC_TAMPCTRL) Debouncer Enable 0 Mask */
#define RTC_TAMPCTRL_DEBNC0(value)            (RTC_TAMPCTRL_DEBNC0_Msk & (_UINT32_(value) << RTC_TAMPCTRL_DEBNC0_Pos)) /* Assigment of value for DEBNC0 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_DEBNC1_Pos               _UINT32_(25)                                         /* (RTC_TAMPCTRL) Debouncer Enable 1 Position */
#define RTC_TAMPCTRL_DEBNC1_Msk               (_UINT32_(0x1) << RTC_TAMPCTRL_DEBNC1_Pos)           /* (RTC_TAMPCTRL) Debouncer Enable 1 Mask */
#define RTC_TAMPCTRL_DEBNC1(value)            (RTC_TAMPCTRL_DEBNC1_Msk & (_UINT32_(value) << RTC_TAMPCTRL_DEBNC1_Pos)) /* Assigment of value for DEBNC1 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_DEBNC2_Pos               _UINT32_(26)                                         /* (RTC_TAMPCTRL) Debouncer Enable 2 Position */
#define RTC_TAMPCTRL_DEBNC2_Msk               (_UINT32_(0x1) << RTC_TAMPCTRL_DEBNC2_Pos)           /* (RTC_TAMPCTRL) Debouncer Enable 2 Mask */
#define RTC_TAMPCTRL_DEBNC2(value)            (RTC_TAMPCTRL_DEBNC2_Msk & (_UINT32_(value) << RTC_TAMPCTRL_DEBNC2_Pos)) /* Assigment of value for DEBNC2 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_DEBNC3_Pos               _UINT32_(27)                                         /* (RTC_TAMPCTRL) Debouncer Enable 3 Position */
#define RTC_TAMPCTRL_DEBNC3_Msk               (_UINT32_(0x1) << RTC_TAMPCTRL_DEBNC3_Pos)           /* (RTC_TAMPCTRL) Debouncer Enable 3 Mask */
#define RTC_TAMPCTRL_DEBNC3(value)            (RTC_TAMPCTRL_DEBNC3_Msk & (_UINT32_(value) << RTC_TAMPCTRL_DEBNC3_Pos)) /* Assigment of value for DEBNC3 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_DEBNC4_Pos               _UINT32_(28)                                         /* (RTC_TAMPCTRL) Debouncer Enable 4 Position */
#define RTC_TAMPCTRL_DEBNC4_Msk               (_UINT32_(0x1) << RTC_TAMPCTRL_DEBNC4_Pos)           /* (RTC_TAMPCTRL) Debouncer Enable 4 Mask */
#define RTC_TAMPCTRL_DEBNC4(value)            (RTC_TAMPCTRL_DEBNC4_Msk & (_UINT32_(value) << RTC_TAMPCTRL_DEBNC4_Pos)) /* Assigment of value for DEBNC4 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_DEBNC5_Pos               _UINT32_(29)                                         /* (RTC_TAMPCTRL) Debouncer Enable 5 Position */
#define RTC_TAMPCTRL_DEBNC5_Msk               (_UINT32_(0x1) << RTC_TAMPCTRL_DEBNC5_Pos)           /* (RTC_TAMPCTRL) Debouncer Enable 5 Mask */
#define RTC_TAMPCTRL_DEBNC5(value)            (RTC_TAMPCTRL_DEBNC5_Msk & (_UINT32_(value) << RTC_TAMPCTRL_DEBNC5_Pos)) /* Assigment of value for DEBNC5 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_DEBNC6_Pos               _UINT32_(30)                                         /* (RTC_TAMPCTRL) Debouncer Enable 6 Position */
#define RTC_TAMPCTRL_DEBNC6_Msk               (_UINT32_(0x1) << RTC_TAMPCTRL_DEBNC6_Pos)           /* (RTC_TAMPCTRL) Debouncer Enable 6 Mask */
#define RTC_TAMPCTRL_DEBNC6(value)            (RTC_TAMPCTRL_DEBNC6_Msk & (_UINT32_(value) << RTC_TAMPCTRL_DEBNC6_Pos)) /* Assigment of value for DEBNC6 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_DEBNC7_Pos               _UINT32_(31)                                         /* (RTC_TAMPCTRL) Debouncer Enable 7 Position */
#define RTC_TAMPCTRL_DEBNC7_Msk               (_UINT32_(0x1) << RTC_TAMPCTRL_DEBNC7_Pos)           /* (RTC_TAMPCTRL) Debouncer Enable 7 Mask */
#define RTC_TAMPCTRL_DEBNC7(value)            (RTC_TAMPCTRL_DEBNC7_Msk & (_UINT32_(value) << RTC_TAMPCTRL_DEBNC7_Pos)) /* Assigment of value for DEBNC7 in the RTC_TAMPCTRL register */
#define RTC_TAMPCTRL_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (RTC_TAMPCTRL) Register Mask  */

#define RTC_TAMPCTRL_TAMLVL_Pos               _UINT32_(16)                                         /* (RTC_TAMPCTRL Position) Tamper Level Select x */
#define RTC_TAMPCTRL_TAMLVL_Msk               (_UINT32_(0xFF) << RTC_TAMPCTRL_TAMLVL_Pos)          /* (RTC_TAMPCTRL Mask) TAMLVL */
#define RTC_TAMPCTRL_TAMLVL(value)            (RTC_TAMPCTRL_TAMLVL_Msk & (_UINT32_(value) << RTC_TAMPCTRL_TAMLVL_Pos)) 
#define RTC_TAMPCTRL_DEBNC_Pos                _UINT32_(24)                                         /* (RTC_TAMPCTRL Position) Debouncer Enable 7 */
#define RTC_TAMPCTRL_DEBNC_Msk                (_UINT32_(0xFF) << RTC_TAMPCTRL_DEBNC_Pos)           /* (RTC_TAMPCTRL Mask) DEBNC */
#define RTC_TAMPCTRL_DEBNC(value)             (RTC_TAMPCTRL_DEBNC_Msk & (_UINT32_(value) << RTC_TAMPCTRL_DEBNC_Pos)) 

/* -------- RTC_MODE0_TIMESTAMP : (RTC Offset: 0x64) ( R/ 32) MODE0 Timestamp -------- */
#define RTC_MODE0_TIMESTAMP_RESETVALUE        _UINT32_(0x00)                                       /*  (RTC_MODE0_TIMESTAMP) MODE0 Timestamp  Reset Value */

#define RTC_MODE0_TIMESTAMP_COUNT_Pos         _UINT32_(0)                                          /* (RTC_MODE0_TIMESTAMP) Count Timestamp Value Position */
#define RTC_MODE0_TIMESTAMP_COUNT_Msk         (_UINT32_(0xFFFFFFFF) << RTC_MODE0_TIMESTAMP_COUNT_Pos) /* (RTC_MODE0_TIMESTAMP) Count Timestamp Value Mask */
#define RTC_MODE0_TIMESTAMP_COUNT(value)      (RTC_MODE0_TIMESTAMP_COUNT_Msk & (_UINT32_(value) << RTC_MODE0_TIMESTAMP_COUNT_Pos)) /* Assigment of value for COUNT in the RTC_MODE0_TIMESTAMP register */
#define RTC_MODE0_TIMESTAMP_Msk               _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE0_TIMESTAMP) Register Mask  */


/* -------- RTC_MODE1_TIMESTAMP : (RTC Offset: 0x64) ( R/ 32) MODE1 Timestamp -------- */
#define RTC_MODE1_TIMESTAMP_RESETVALUE        _UINT32_(0x00)                                       /*  (RTC_MODE1_TIMESTAMP) MODE1 Timestamp  Reset Value */

#define RTC_MODE1_TIMESTAMP_COUNT_Pos         _UINT32_(0)                                          /* (RTC_MODE1_TIMESTAMP) Count Timestamp Value Position */
#define RTC_MODE1_TIMESTAMP_COUNT_Msk         (_UINT32_(0xFFFF) << RTC_MODE1_TIMESTAMP_COUNT_Pos)  /* (RTC_MODE1_TIMESTAMP) Count Timestamp Value Mask */
#define RTC_MODE1_TIMESTAMP_COUNT(value)      (RTC_MODE1_TIMESTAMP_COUNT_Msk & (_UINT32_(value) << RTC_MODE1_TIMESTAMP_COUNT_Pos)) /* Assigment of value for COUNT in the RTC_MODE1_TIMESTAMP register */
#define RTC_MODE1_TIMESTAMP_Msk               _UINT32_(0x0000FFFF)                                 /* (RTC_MODE1_TIMESTAMP) Register Mask  */


/* -------- RTC_MODE2_TIMESTAMP : (RTC Offset: 0x64) ( R/ 32) MODE2 Timestamp -------- */
#define RTC_MODE2_TIMESTAMP_RESETVALUE        _UINT32_(0x00)                                       /*  (RTC_MODE2_TIMESTAMP) MODE2 Timestamp  Reset Value */

#define RTC_MODE2_TIMESTAMP_SECOND_Pos        _UINT32_(0)                                          /* (RTC_MODE2_TIMESTAMP) Second Timestamp Value Position */
#define RTC_MODE2_TIMESTAMP_SECOND_Msk        (_UINT32_(0x3F) << RTC_MODE2_TIMESTAMP_SECOND_Pos)   /* (RTC_MODE2_TIMESTAMP) Second Timestamp Value Mask */
#define RTC_MODE2_TIMESTAMP_SECOND(value)     (RTC_MODE2_TIMESTAMP_SECOND_Msk & (_UINT32_(value) << RTC_MODE2_TIMESTAMP_SECOND_Pos)) /* Assigment of value for SECOND in the RTC_MODE2_TIMESTAMP register */
#define RTC_MODE2_TIMESTAMP_MINUTE_Pos        _UINT32_(6)                                          /* (RTC_MODE2_TIMESTAMP) Minute Timestamp Value Position */
#define RTC_MODE2_TIMESTAMP_MINUTE_Msk        (_UINT32_(0x3F) << RTC_MODE2_TIMESTAMP_MINUTE_Pos)   /* (RTC_MODE2_TIMESTAMP) Minute Timestamp Value Mask */
#define RTC_MODE2_TIMESTAMP_MINUTE(value)     (RTC_MODE2_TIMESTAMP_MINUTE_Msk & (_UINT32_(value) << RTC_MODE2_TIMESTAMP_MINUTE_Pos)) /* Assigment of value for MINUTE in the RTC_MODE2_TIMESTAMP register */
#define RTC_MODE2_TIMESTAMP_HOUR_Pos          _UINT32_(12)                                         /* (RTC_MODE2_TIMESTAMP) Hour Timestamp Value Position */
#define RTC_MODE2_TIMESTAMP_HOUR_Msk          (_UINT32_(0x1F) << RTC_MODE2_TIMESTAMP_HOUR_Pos)     /* (RTC_MODE2_TIMESTAMP) Hour Timestamp Value Mask */
#define RTC_MODE2_TIMESTAMP_HOUR(value)       (RTC_MODE2_TIMESTAMP_HOUR_Msk & (_UINT32_(value) << RTC_MODE2_TIMESTAMP_HOUR_Pos)) /* Assigment of value for HOUR in the RTC_MODE2_TIMESTAMP register */
#define RTC_MODE2_TIMESTAMP_DAY_Pos           _UINT32_(17)                                         /* (RTC_MODE2_TIMESTAMP) Day Timestamp Value Position */
#define RTC_MODE2_TIMESTAMP_DAY_Msk           (_UINT32_(0x1F) << RTC_MODE2_TIMESTAMP_DAY_Pos)      /* (RTC_MODE2_TIMESTAMP) Day Timestamp Value Mask */
#define RTC_MODE2_TIMESTAMP_DAY(value)        (RTC_MODE2_TIMESTAMP_DAY_Msk & (_UINT32_(value) << RTC_MODE2_TIMESTAMP_DAY_Pos)) /* Assigment of value for DAY in the RTC_MODE2_TIMESTAMP register */
#define RTC_MODE2_TIMESTAMP_MONTH_Pos         _UINT32_(22)                                         /* (RTC_MODE2_TIMESTAMP) Month Timestamp Value Position */
#define RTC_MODE2_TIMESTAMP_MONTH_Msk         (_UINT32_(0xF) << RTC_MODE2_TIMESTAMP_MONTH_Pos)     /* (RTC_MODE2_TIMESTAMP) Month Timestamp Value Mask */
#define RTC_MODE2_TIMESTAMP_MONTH(value)      (RTC_MODE2_TIMESTAMP_MONTH_Msk & (_UINT32_(value) << RTC_MODE2_TIMESTAMP_MONTH_Pos)) /* Assigment of value for MONTH in the RTC_MODE2_TIMESTAMP register */
#define RTC_MODE2_TIMESTAMP_YEAR_Pos          _UINT32_(26)                                         /* (RTC_MODE2_TIMESTAMP) Year Timestamp Value Position */
#define RTC_MODE2_TIMESTAMP_YEAR_Msk          (_UINT32_(0x3F) << RTC_MODE2_TIMESTAMP_YEAR_Pos)     /* (RTC_MODE2_TIMESTAMP) Year Timestamp Value Mask */
#define RTC_MODE2_TIMESTAMP_YEAR(value)       (RTC_MODE2_TIMESTAMP_YEAR_Msk & (_UINT32_(value) << RTC_MODE2_TIMESTAMP_YEAR_Pos)) /* Assigment of value for YEAR in the RTC_MODE2_TIMESTAMP register */
#define RTC_MODE2_TIMESTAMP_Msk               _UINT32_(0xFFFFFFFF)                                 /* (RTC_MODE2_TIMESTAMP) Register Mask  */


/* -------- RTC_TAMPID : (RTC Offset: 0x68) (R/W 32) Tamper ID -------- */
#define RTC_TAMPID_RESETVALUE                 _UINT32_(0x00)                                       /*  (RTC_TAMPID) Tamper ID  Reset Value */

#define RTC_TAMPID_TAMPID0_Pos                _UINT32_(0)                                          /* (RTC_TAMPID) Tamper Input 0 Detected Position */
#define RTC_TAMPID_TAMPID0_Msk                (_UINT32_(0x1) << RTC_TAMPID_TAMPID0_Pos)            /* (RTC_TAMPID) Tamper Input 0 Detected Mask */
#define RTC_TAMPID_TAMPID0(value)             (RTC_TAMPID_TAMPID0_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPID0_Pos)) /* Assigment of value for TAMPID0 in the RTC_TAMPID register */
#define RTC_TAMPID_TAMPID1_Pos                _UINT32_(1)                                          /* (RTC_TAMPID) Tamper Input 1 Detected Position */
#define RTC_TAMPID_TAMPID1_Msk                (_UINT32_(0x1) << RTC_TAMPID_TAMPID1_Pos)            /* (RTC_TAMPID) Tamper Input 1 Detected Mask */
#define RTC_TAMPID_TAMPID1(value)             (RTC_TAMPID_TAMPID1_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPID1_Pos)) /* Assigment of value for TAMPID1 in the RTC_TAMPID register */
#define RTC_TAMPID_TAMPID2_Pos                _UINT32_(2)                                          /* (RTC_TAMPID) Tamper Input 2 Detected Position */
#define RTC_TAMPID_TAMPID2_Msk                (_UINT32_(0x1) << RTC_TAMPID_TAMPID2_Pos)            /* (RTC_TAMPID) Tamper Input 2 Detected Mask */
#define RTC_TAMPID_TAMPID2(value)             (RTC_TAMPID_TAMPID2_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPID2_Pos)) /* Assigment of value for TAMPID2 in the RTC_TAMPID register */
#define RTC_TAMPID_TAMPID3_Pos                _UINT32_(3)                                          /* (RTC_TAMPID) Tamper Input 3 Detected Position */
#define RTC_TAMPID_TAMPID3_Msk                (_UINT32_(0x1) << RTC_TAMPID_TAMPID3_Pos)            /* (RTC_TAMPID) Tamper Input 3 Detected Mask */
#define RTC_TAMPID_TAMPID3(value)             (RTC_TAMPID_TAMPID3_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPID3_Pos)) /* Assigment of value for TAMPID3 in the RTC_TAMPID register */
#define RTC_TAMPID_TAMPID4_Pos                _UINT32_(4)                                          /* (RTC_TAMPID) Tamper Input 4 Detected Position */
#define RTC_TAMPID_TAMPID4_Msk                (_UINT32_(0x1) << RTC_TAMPID_TAMPID4_Pos)            /* (RTC_TAMPID) Tamper Input 4 Detected Mask */
#define RTC_TAMPID_TAMPID4(value)             (RTC_TAMPID_TAMPID4_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPID4_Pos)) /* Assigment of value for TAMPID4 in the RTC_TAMPID register */
#define RTC_TAMPID_TAMPID5_Pos                _UINT32_(5)                                          /* (RTC_TAMPID) Tamper Input 5 Detected Position */
#define RTC_TAMPID_TAMPID5_Msk                (_UINT32_(0x1) << RTC_TAMPID_TAMPID5_Pos)            /* (RTC_TAMPID) Tamper Input 5 Detected Mask */
#define RTC_TAMPID_TAMPID5(value)             (RTC_TAMPID_TAMPID5_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPID5_Pos)) /* Assigment of value for TAMPID5 in the RTC_TAMPID register */
#define RTC_TAMPID_TAMPID6_Pos                _UINT32_(6)                                          /* (RTC_TAMPID) Tamper Input 6 Detected Position */
#define RTC_TAMPID_TAMPID6_Msk                (_UINT32_(0x1) << RTC_TAMPID_TAMPID6_Pos)            /* (RTC_TAMPID) Tamper Input 6 Detected Mask */
#define RTC_TAMPID_TAMPID6(value)             (RTC_TAMPID_TAMPID6_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPID6_Pos)) /* Assigment of value for TAMPID6 in the RTC_TAMPID register */
#define RTC_TAMPID_TAMPID7_Pos                _UINT32_(7)                                          /* (RTC_TAMPID) Tamper Input 7 Detected Position */
#define RTC_TAMPID_TAMPID7_Msk                (_UINT32_(0x1) << RTC_TAMPID_TAMPID7_Pos)            /* (RTC_TAMPID) Tamper Input 7 Detected Mask */
#define RTC_TAMPID_TAMPID7(value)             (RTC_TAMPID_TAMPID7_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPID7_Pos)) /* Assigment of value for TAMPID7 in the RTC_TAMPID register */
#define RTC_TAMPID_TAMPEVT_Pos                _UINT32_(31)                                         /* (RTC_TAMPID) Tamper Event Detected Position */
#define RTC_TAMPID_TAMPEVT_Msk                (_UINT32_(0x1) << RTC_TAMPID_TAMPEVT_Pos)            /* (RTC_TAMPID) Tamper Event Detected Mask */
#define RTC_TAMPID_TAMPEVT(value)             (RTC_TAMPID_TAMPEVT_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPEVT_Pos)) /* Assigment of value for TAMPEVT in the RTC_TAMPID register */
#define RTC_TAMPID_Msk                        _UINT32_(0x800000FF)                                 /* (RTC_TAMPID) Register Mask  */

#define RTC_TAMPID_TAMPID_Pos                 _UINT32_(0)                                          /* (RTC_TAMPID Position) Tamper Input x Detected */
#define RTC_TAMPID_TAMPID_Msk                 (_UINT32_(0xFF) << RTC_TAMPID_TAMPID_Pos)            /* (RTC_TAMPID Mask) TAMPID */
#define RTC_TAMPID_TAMPID(value)              (RTC_TAMPID_TAMPID_Msk & (_UINT32_(value) << RTC_TAMPID_TAMPID_Pos)) 

/* -------- RTC_TAMPCTRLB : (RTC Offset: 0x6C) (R/W 32) Tamper Control B -------- */
#define RTC_TAMPCTRLB_RESETVALUE              _UINT32_(0x00)                                       /*  (RTC_TAMPCTRLB) Tamper Control B  Reset Value */

#define RTC_TAMPCTRLB_ALSI0_Pos               _UINT32_(0)                                          /* (RTC_TAMPCTRLB) Active Layer Select Internal 0 Position */
#define RTC_TAMPCTRLB_ALSI0_Msk               (_UINT32_(0x1) << RTC_TAMPCTRLB_ALSI0_Pos)           /* (RTC_TAMPCTRLB) Active Layer Select Internal 0 Mask */
#define RTC_TAMPCTRLB_ALSI0(value)            (RTC_TAMPCTRLB_ALSI0_Msk & (_UINT32_(value) << RTC_TAMPCTRLB_ALSI0_Pos)) /* Assigment of value for ALSI0 in the RTC_TAMPCTRLB register */
#define RTC_TAMPCTRLB_ALSI1_Pos               _UINT32_(1)                                          /* (RTC_TAMPCTRLB) Active Layer Select Internal 1 Position */
#define RTC_TAMPCTRLB_ALSI1_Msk               (_UINT32_(0x1) << RTC_TAMPCTRLB_ALSI1_Pos)           /* (RTC_TAMPCTRLB) Active Layer Select Internal 1 Mask */
#define RTC_TAMPCTRLB_ALSI1(value)            (RTC_TAMPCTRLB_ALSI1_Msk & (_UINT32_(value) << RTC_TAMPCTRLB_ALSI1_Pos)) /* Assigment of value for ALSI1 in the RTC_TAMPCTRLB register */
#define RTC_TAMPCTRLB_ALSI2_Pos               _UINT32_(2)                                          /* (RTC_TAMPCTRLB) Active Layer Select Internal 2 Position */
#define RTC_TAMPCTRLB_ALSI2_Msk               (_UINT32_(0x1) << RTC_TAMPCTRLB_ALSI2_Pos)           /* (RTC_TAMPCTRLB) Active Layer Select Internal 2 Mask */
#define RTC_TAMPCTRLB_ALSI2(value)            (RTC_TAMPCTRLB_ALSI2_Msk & (_UINT32_(value) << RTC_TAMPCTRLB_ALSI2_Pos)) /* Assigment of value for ALSI2 in the RTC_TAMPCTRLB register */
#define RTC_TAMPCTRLB_ALSI3_Pos               _UINT32_(3)                                          /* (RTC_TAMPCTRLB) Active Layer Select Internal 3 Position */
#define RTC_TAMPCTRLB_ALSI3_Msk               (_UINT32_(0x1) << RTC_TAMPCTRLB_ALSI3_Pos)           /* (RTC_TAMPCTRLB) Active Layer Select Internal 3 Mask */
#define RTC_TAMPCTRLB_ALSI3(value)            (RTC_TAMPCTRLB_ALSI3_Msk & (_UINT32_(value) << RTC_TAMPCTRLB_ALSI3_Pos)) /* Assigment of value for ALSI3 in the RTC_TAMPCTRLB register */
#define RTC_TAMPCTRLB_ALSI4_Pos               _UINT32_(4)                                          /* (RTC_TAMPCTRLB) Active Layer Select Internal 4 Position */
#define RTC_TAMPCTRLB_ALSI4_Msk               (_UINT32_(0x1) << RTC_TAMPCTRLB_ALSI4_Pos)           /* (RTC_TAMPCTRLB) Active Layer Select Internal 4 Mask */
#define RTC_TAMPCTRLB_ALSI4(value)            (RTC_TAMPCTRLB_ALSI4_Msk & (_UINT32_(value) << RTC_TAMPCTRLB_ALSI4_Pos)) /* Assigment of value for ALSI4 in the RTC_TAMPCTRLB register */
#define RTC_TAMPCTRLB_ALSI5_Pos               _UINT32_(5)                                          /* (RTC_TAMPCTRLB) Active Layer Select Internal 5 Position */
#define RTC_TAMPCTRLB_ALSI5_Msk               (_UINT32_(0x1) << RTC_TAMPCTRLB_ALSI5_Pos)           /* (RTC_TAMPCTRLB) Active Layer Select Internal 5 Mask */
#define RTC_TAMPCTRLB_ALSI5(value)            (RTC_TAMPCTRLB_ALSI5_Msk & (_UINT32_(value) << RTC_TAMPCTRLB_ALSI5_Pos)) /* Assigment of value for ALSI5 in the RTC_TAMPCTRLB register */
#define RTC_TAMPCTRLB_ALSI6_Pos               _UINT32_(6)                                          /* (RTC_TAMPCTRLB) Active Layer Select Internal 6 Position */
#define RTC_TAMPCTRLB_ALSI6_Msk               (_UINT32_(0x1) << RTC_TAMPCTRLB_ALSI6_Pos)           /* (RTC_TAMPCTRLB) Active Layer Select Internal 6 Mask */
#define RTC_TAMPCTRLB_ALSI6(value)            (RTC_TAMPCTRLB_ALSI6_Msk & (_UINT32_(value) << RTC_TAMPCTRLB_ALSI6_Pos)) /* Assigment of value for ALSI6 in the RTC_TAMPCTRLB register */
#define RTC_TAMPCTRLB_ALSI7_Pos               _UINT32_(7)                                          /* (RTC_TAMPCTRLB) Active Layer Select Internal 7 Position */
#define RTC_TAMPCTRLB_ALSI7_Msk               (_UINT32_(0x1) << RTC_TAMPCTRLB_ALSI7_Pos)           /* (RTC_TAMPCTRLB) Active Layer Select Internal 7 Mask */
#define RTC_TAMPCTRLB_ALSI7(value)            (RTC_TAMPCTRLB_ALSI7_Msk & (_UINT32_(value) << RTC_TAMPCTRLB_ALSI7_Pos)) /* Assigment of value for ALSI7 in the RTC_TAMPCTRLB register */
#define RTC_TAMPCTRLB_Msk                     _UINT32_(0x000000FF)                                 /* (RTC_TAMPCTRLB) Register Mask  */

#define RTC_TAMPCTRLB_ALSI_Pos                _UINT32_(0)                                          /* (RTC_TAMPCTRLB Position) Active Layer Select Internal 7 */
#define RTC_TAMPCTRLB_ALSI_Msk                (_UINT32_(0xFF) << RTC_TAMPCTRLB_ALSI_Pos)           /* (RTC_TAMPCTRLB Mask) ALSI */
#define RTC_TAMPCTRLB_ALSI(value)             (RTC_TAMPCTRLB_ALSI_Msk & (_UINT32_(value) << RTC_TAMPCTRLB_ALSI_Pos)) 

/** \brief RTC register offsets definitions */
#define RTC_MODE0_CTRLA_REG_OFST       _UINT32_(0x00)      /* (RTC_MODE0_CTRLA) MODE0 Control A Offset */
#define RTC_MODE1_CTRLA_REG_OFST       _UINT32_(0x00)      /* (RTC_MODE1_CTRLA) MODE1 Control A Offset */
#define RTC_MODE2_CTRLA_REG_OFST       _UINT32_(0x00)      /* (RTC_MODE2_CTRLA) MODE2 Control A Offset */
#define RTC_MODE0_CTRLB_REG_OFST       _UINT32_(0x02)      /* (RTC_MODE0_CTRLB) MODE0 Control B Offset */
#define RTC_MODE1_CTRLB_REG_OFST       _UINT32_(0x02)      /* (RTC_MODE1_CTRLB) MODE1 Control B Offset */
#define RTC_MODE2_CTRLB_REG_OFST       _UINT32_(0x02)      /* (RTC_MODE2_CTRLB) MODE2 Control B Offset */
#define RTC_MODE0_EVCTRL_REG_OFST      _UINT32_(0x04)      /* (RTC_MODE0_EVCTRL) MODE0 Event Control Offset */
#define RTC_MODE1_EVCTRL_REG_OFST      _UINT32_(0x04)      /* (RTC_MODE1_EVCTRL) MODE1 Event Control Offset */
#define RTC_MODE2_EVCTRL_REG_OFST      _UINT32_(0x04)      /* (RTC_MODE2_EVCTRL) MODE2 Event Control Offset */
#define RTC_MODE0_INTENCLR_REG_OFST    _UINT32_(0x08)      /* (RTC_MODE0_INTENCLR) MODE0 Interrupt Enable Clear Offset */
#define RTC_MODE1_INTENCLR_REG_OFST    _UINT32_(0x08)      /* (RTC_MODE1_INTENCLR) MODE1 Interrupt Enable Clear Offset */
#define RTC_MODE2_INTENCLR_REG_OFST    _UINT32_(0x08)      /* (RTC_MODE2_INTENCLR) MODE2 Interrupt Enable Clear Offset */
#define RTC_MODE0_INTENSET_REG_OFST    _UINT32_(0x0A)      /* (RTC_MODE0_INTENSET) MODE0 Interrupt Enable Set Offset */
#define RTC_MODE1_INTENSET_REG_OFST    _UINT32_(0x0A)      /* (RTC_MODE1_INTENSET) MODE1 Interrupt Enable Set Offset */
#define RTC_MODE2_INTENSET_REG_OFST    _UINT32_(0x0A)      /* (RTC_MODE2_INTENSET) MODE2 Interrupt Enable Set Offset */
#define RTC_MODE0_INTFLAG_REG_OFST     _UINT32_(0x0C)      /* (RTC_MODE0_INTFLAG) MODE0 Interrupt Flag Status and Clear Offset */
#define RTC_MODE1_INTFLAG_REG_OFST     _UINT32_(0x0C)      /* (RTC_MODE1_INTFLAG) MODE1 Interrupt Flag Status and Clear Offset */
#define RTC_MODE2_INTFLAG_REG_OFST     _UINT32_(0x0C)      /* (RTC_MODE2_INTFLAG) MODE2 Interrupt Flag Status and Clear Offset */
#define RTC_DBGCTRL_REG_OFST           _UINT32_(0x0E)      /* (RTC_DBGCTRL) Debug Control Offset */
#define RTC_MODE0_SYNCBUSY_REG_OFST    _UINT32_(0x10)      /* (RTC_MODE0_SYNCBUSY) MODE0 Synchronization Busy Status Offset */
#define RTC_MODE1_SYNCBUSY_REG_OFST    _UINT32_(0x10)      /* (RTC_MODE1_SYNCBUSY) MODE1 Synchronization Busy Status Offset */
#define RTC_MODE2_SYNCBUSY_REG_OFST    _UINT32_(0x10)      /* (RTC_MODE2_SYNCBUSY) MODE2 Synchronization Busy Status Offset */
#define RTC_FREQCORR_REG_OFST          _UINT32_(0x14)      /* (RTC_FREQCORR) Frequency Correction Offset */
#define RTC_MODE0_COUNT_REG_OFST       _UINT32_(0x18)      /* (RTC_MODE0_COUNT) MODE0 Counter Value Offset */
#define RTC_MODE1_COUNT_REG_OFST       _UINT32_(0x18)      /* (RTC_MODE1_COUNT) MODE1 Counter Value Offset */
#define RTC_MODE2_CLOCK_REG_OFST       _UINT32_(0x18)      /* (RTC_MODE2_CLOCK) MODE2 Clock Value Offset */
#define RTC_MODE1_PER_REG_OFST         _UINT32_(0x1C)      /* (RTC_MODE1_PER) MODE1 Counter Period Offset */
#define RTC_MODE0_COMP0_REG_OFST       _UINT32_(0x20)      /* (RTC_MODE0_COMP0) MODE0 Compare Value Offset */
#define RTC_MODE1_COMP_REG_OFST        _UINT32_(0x20)      /* (RTC_MODE1_COMP) MODE1 Compare n Value Offset */
#define RTC_MODE1_COMP0_REG_OFST       _UINT32_(0x20)      /* (RTC_MODE1_COMP0) MODE1 Compare n Value Offset */
#define RTC_MODE1_COMP1_REG_OFST       _UINT32_(0x22)      /* (RTC_MODE1_COMP1) MODE1 Compare n Value Offset */
#define RTC_MODE2_ALARM0_REG_OFST      _UINT32_(0x20)      /* (RTC_MODE2_ALARM0) MODE2 Alarm Value Offset */
#define RTC_MODE2_MASK0_REG_OFST       _UINT32_(0x24)      /* (RTC_MODE2_MASK0) MODE2 Alarm Mask Offset */
#define RTC_GP_REG_OFST                _UINT32_(0x40)      /* (RTC_GP) General Purpose Offset */
#define RTC_GP0_REG_OFST               _UINT32_(0x40)      /* (RTC_GP0) General Purpose Offset */
#define RTC_GP1_REG_OFST               _UINT32_(0x44)      /* (RTC_GP1) General Purpose Offset */
#define RTC_TAMPCTRL_REG_OFST          _UINT32_(0x60)      /* (RTC_TAMPCTRL) Tamper Control Offset */
#define RTC_MODE0_TIMESTAMP_REG_OFST   _UINT32_(0x64)      /* (RTC_MODE0_TIMESTAMP) MODE0 Timestamp Offset */
#define RTC_MODE1_TIMESTAMP_REG_OFST   _UINT32_(0x64)      /* (RTC_MODE1_TIMESTAMP) MODE1 Timestamp Offset */
#define RTC_MODE2_TIMESTAMP_REG_OFST   _UINT32_(0x64)      /* (RTC_MODE2_TIMESTAMP) MODE2 Timestamp Offset */
#define RTC_TAMPID_REG_OFST            _UINT32_(0x68)      /* (RTC_TAMPID) Tamper ID Offset */
#define RTC_TAMPCTRLB_REG_OFST         _UINT32_(0x6C)      /* (RTC_TAMPCTRLB) Tamper Control B Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief RTC register API structure */
typedef struct
{  /* Real-Time Counter */
  __IO  uint16_t                       RTC_CTRLA;          /**< Offset: 0x00 (R/W  16) MODE0 Control A */
  __IO  uint16_t                       RTC_CTRLB;          /**< Offset: 0x02 (R/W  16) MODE0 Control B */
  __IO  uint32_t                       RTC_EVCTRL;         /**< Offset: 0x04 (R/W  32) MODE0 Event Control */
  __IO  uint16_t                       RTC_INTENCLR;       /**< Offset: 0x08 (R/W  16) MODE0 Interrupt Enable Clear */
  __IO  uint16_t                       RTC_INTENSET;       /**< Offset: 0x0A (R/W  16) MODE0 Interrupt Enable Set */
  __IO  uint16_t                       RTC_INTFLAG;        /**< Offset: 0x0C (R/W  16) MODE0 Interrupt Flag Status and Clear */
  __IO  uint8_t                        RTC_DBGCTRL;        /**< Offset: 0x0E (R/W  8) Debug Control */
  __I   uint8_t                        Reserved1[0x01];
  __I   uint32_t                       RTC_SYNCBUSY;       /**< Offset: 0x10 (R/   32) MODE0 Synchronization Busy Status */
  __IO  uint8_t                        RTC_FREQCORR;       /**< Offset: 0x14 (R/W  8) Frequency Correction */
  __I   uint8_t                        Reserved2[0x03];
  __IO  uint32_t                       RTC_COUNT;          /**< Offset: 0x18 (R/W  32) MODE0 Counter Value */
  __I   uint8_t                        Reserved3[0x04];
  __IO  uint32_t                       RTC_COMP0;          /**< Offset: 0x20 (R/W  32) MODE0 Compare Value */
  __I   uint8_t                        Reserved4[0x1C];
  __IO  uint32_t                       RTC_GP[2];          /**< Offset: 0x40 (R/W  32) General Purpose */
  __I   uint8_t                        Reserved5[0x18];
  __IO  uint32_t                       RTC_TAMPCTRL;       /**< Offset: 0x60 (R/W  32) Tamper Control */
  __I   uint32_t                       RTC_TIMESTAMP;      /**< Offset: 0x64 (R/   32) MODE0 Timestamp */
  __IO  uint32_t                       RTC_TAMPID;         /**< Offset: 0x68 (R/W  32) Tamper ID */
  __IO  uint32_t                       RTC_TAMPCTRLB;      /**< Offset: 0x6C (R/W  32) Tamper Control B */
} rtc_mode0_registers_t;

/** \brief RTC register API structure */
typedef struct
{  /* Real-Time Counter */
  __IO  uint16_t                       RTC_CTRLA;          /**< Offset: 0x00 (R/W  16) MODE1 Control A */
  __IO  uint16_t                       RTC_CTRLB;          /**< Offset: 0x02 (R/W  16) MODE1 Control B */
  __IO  uint32_t                       RTC_EVCTRL;         /**< Offset: 0x04 (R/W  32) MODE1 Event Control */
  __IO  uint16_t                       RTC_INTENCLR;       /**< Offset: 0x08 (R/W  16) MODE1 Interrupt Enable Clear */
  __IO  uint16_t                       RTC_INTENSET;       /**< Offset: 0x0A (R/W  16) MODE1 Interrupt Enable Set */
  __IO  uint16_t                       RTC_INTFLAG;        /**< Offset: 0x0C (R/W  16) MODE1 Interrupt Flag Status and Clear */
  __IO  uint8_t                        RTC_DBGCTRL;        /**< Offset: 0x0E (R/W  8) Debug Control */
  __I   uint8_t                        Reserved1[0x01];
  __I   uint32_t                       RTC_SYNCBUSY;       /**< Offset: 0x10 (R/   32) MODE1 Synchronization Busy Status */
  __IO  uint8_t                        RTC_FREQCORR;       /**< Offset: 0x14 (R/W  8) Frequency Correction */
  __I   uint8_t                        Reserved2[0x03];
  __IO  uint16_t                       RTC_COUNT;          /**< Offset: 0x18 (R/W  16) MODE1 Counter Value */
  __I   uint8_t                        Reserved3[0x02];
  __IO  uint16_t                       RTC_PER;            /**< Offset: 0x1C (R/W  16) MODE1 Counter Period */
  __I   uint8_t                        Reserved4[0x02];
  __IO  uint16_t                       RTC_COMP[2];        /**< Offset: 0x20 (R/W  16) MODE1 Compare n Value */
  __I   uint8_t                        Reserved5[0x1C];
  __IO  uint32_t                       RTC_GP[2];          /**< Offset: 0x40 (R/W  32) General Purpose */
  __I   uint8_t                        Reserved6[0x18];
  __IO  uint32_t                       RTC_TAMPCTRL;       /**< Offset: 0x60 (R/W  32) Tamper Control */
  __I   uint32_t                       RTC_TIMESTAMP;      /**< Offset: 0x64 (R/   32) MODE1 Timestamp */
  __IO  uint32_t                       RTC_TAMPID;         /**< Offset: 0x68 (R/W  32) Tamper ID */
  __IO  uint32_t                       RTC_TAMPCTRLB;      /**< Offset: 0x6C (R/W  32) Tamper Control B */
} rtc_mode1_registers_t;

/** \brief RTC register API structure */
typedef struct
{  /* Real-Time Counter */
  __IO  uint16_t                       RTC_CTRLA;          /**< Offset: 0x00 (R/W  16) MODE2 Control A */
  __IO  uint16_t                       RTC_CTRLB;          /**< Offset: 0x02 (R/W  16) MODE2 Control B */
  __IO  uint32_t                       RTC_EVCTRL;         /**< Offset: 0x04 (R/W  32) MODE2 Event Control */
  __IO  uint16_t                       RTC_INTENCLR;       /**< Offset: 0x08 (R/W  16) MODE2 Interrupt Enable Clear */
  __IO  uint16_t                       RTC_INTENSET;       /**< Offset: 0x0A (R/W  16) MODE2 Interrupt Enable Set */
  __IO  uint16_t                       RTC_INTFLAG;        /**< Offset: 0x0C (R/W  16) MODE2 Interrupt Flag Status and Clear */
  __IO  uint8_t                        RTC_DBGCTRL;        /**< Offset: 0x0E (R/W  8) Debug Control */
  __I   uint8_t                        Reserved1[0x01];
  __I   uint32_t                       RTC_SYNCBUSY;       /**< Offset: 0x10 (R/   32) MODE2 Synchronization Busy Status */
  __IO  uint8_t                        RTC_FREQCORR;       /**< Offset: 0x14 (R/W  8) Frequency Correction */
  __I   uint8_t                        Reserved2[0x03];
  __IO  uint32_t                       RTC_CLOCK;          /**< Offset: 0x18 (R/W  32) MODE2 Clock Value */
  __I   uint8_t                        Reserved3[0x04];
  __IO  uint32_t                       RTC_ALARM0;         /**< Offset: 0x20 (R/W  32) MODE2 Alarm Value */
  __IO  uint8_t                        RTC_MASK0;          /**< Offset: 0x24 (R/W  8) MODE2 Alarm Mask */
  __I   uint8_t                        Reserved4[0x1B];
  __IO  uint32_t                       RTC_GP[2];          /**< Offset: 0x40 (R/W  32) General Purpose */
  __I   uint8_t                        Reserved5[0x18];
  __IO  uint32_t                       RTC_TAMPCTRL;       /**< Offset: 0x60 (R/W  32) Tamper Control */
  __I   uint32_t                       RTC_TIMESTAMP;      /**< Offset: 0x64 (R/   32) MODE2 Timestamp */
  __IO  uint32_t                       RTC_TAMPID;         /**< Offset: 0x68 (R/W  32) Tamper ID */
  __IO  uint32_t                       RTC_TAMPCTRLB;      /**< Offset: 0x6C (R/W  32) Tamper Control B */
} rtc_mode2_registers_t;

/** \brief RTC hardware registers */
typedef union
{  /* Real-Time Counter */
       rtc_mode0_registers_t          MODE0;          /**< 32-bit Counter with Single 32-bit Compare */
       rtc_mode1_registers_t          MODE1;          /**< 16-bit Counter with Two 16-bit Compares */
       rtc_mode2_registers_t          MODE2;          /**< Clock/Calendar with Alarm */
} rtc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMLS60_RTC_COMPONENT_H_ */
