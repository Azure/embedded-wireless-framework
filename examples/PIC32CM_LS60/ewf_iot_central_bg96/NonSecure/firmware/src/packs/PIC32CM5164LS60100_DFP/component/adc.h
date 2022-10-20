/*
 * Component description for ADC
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
#ifndef _PIC32CMLS60_ADC_COMPONENT_H_
#define _PIC32CMLS60_ADC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR ADC                                          */
/* ************************************************************************** */

/* -------- ADC_CTRLA : (ADC Offset: 0x00) (R/W 8) Control A -------- */
#define ADC_CTRLA_RESETVALUE                  _UINT8_(0x00)                                        /*  (ADC_CTRLA) Control A  Reset Value */

#define ADC_CTRLA_SWRST_Pos                   _UINT8_(0)                                           /* (ADC_CTRLA) Software Reset Position */
#define ADC_CTRLA_SWRST_Msk                   (_UINT8_(0x1) << ADC_CTRLA_SWRST_Pos)                /* (ADC_CTRLA) Software Reset Mask */
#define ADC_CTRLA_SWRST(value)                (ADC_CTRLA_SWRST_Msk & (_UINT8_(value) << ADC_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the ADC_CTRLA register */
#define ADC_CTRLA_ENABLE_Pos                  _UINT8_(1)                                           /* (ADC_CTRLA) Enable Position */
#define ADC_CTRLA_ENABLE_Msk                  (_UINT8_(0x1) << ADC_CTRLA_ENABLE_Pos)               /* (ADC_CTRLA) Enable Mask */
#define ADC_CTRLA_ENABLE(value)               (ADC_CTRLA_ENABLE_Msk & (_UINT8_(value) << ADC_CTRLA_ENABLE_Pos)) /* Assigment of value for ENABLE in the ADC_CTRLA register */
#define ADC_CTRLA_RUNSTDBY_Pos                _UINT8_(6)                                           /* (ADC_CTRLA) Run During Standby Position */
#define ADC_CTRLA_RUNSTDBY_Msk                (_UINT8_(0x1) << ADC_CTRLA_RUNSTDBY_Pos)             /* (ADC_CTRLA) Run During Standby Mask */
#define ADC_CTRLA_RUNSTDBY(value)             (ADC_CTRLA_RUNSTDBY_Msk & (_UINT8_(value) << ADC_CTRLA_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the ADC_CTRLA register */
#define ADC_CTRLA_ONDEMAND_Pos                _UINT8_(7)                                           /* (ADC_CTRLA) On Demand Control Position */
#define ADC_CTRLA_ONDEMAND_Msk                (_UINT8_(0x1) << ADC_CTRLA_ONDEMAND_Pos)             /* (ADC_CTRLA) On Demand Control Mask */
#define ADC_CTRLA_ONDEMAND(value)             (ADC_CTRLA_ONDEMAND_Msk & (_UINT8_(value) << ADC_CTRLA_ONDEMAND_Pos)) /* Assigment of value for ONDEMAND in the ADC_CTRLA register */
#define ADC_CTRLA_Msk                         _UINT8_(0xC3)                                        /* (ADC_CTRLA) Register Mask  */


/* -------- ADC_CTRLB : (ADC Offset: 0x01) (R/W 8) Control B -------- */
#define ADC_CTRLB_RESETVALUE                  _UINT8_(0x00)                                        /*  (ADC_CTRLB) Control B  Reset Value */

#define ADC_CTRLB_PRESCALER_Pos               _UINT8_(0)                                           /* (ADC_CTRLB) Prescaler Configuration Position */
#define ADC_CTRLB_PRESCALER_Msk               (_UINT8_(0x7) << ADC_CTRLB_PRESCALER_Pos)            /* (ADC_CTRLB) Prescaler Configuration Mask */
#define ADC_CTRLB_PRESCALER(value)            (ADC_CTRLB_PRESCALER_Msk & (_UINT8_(value) << ADC_CTRLB_PRESCALER_Pos)) /* Assigment of value for PRESCALER in the ADC_CTRLB register */
#define   ADC_CTRLB_PRESCALER_DIV2_Val        _UINT8_(0x0)                                         /* (ADC_CTRLB) Peripheral clock divided by 2  */
#define   ADC_CTRLB_PRESCALER_DIV4_Val        _UINT8_(0x1)                                         /* (ADC_CTRLB) Peripheral clock divided by 4  */
#define   ADC_CTRLB_PRESCALER_DIV8_Val        _UINT8_(0x2)                                         /* (ADC_CTRLB) Peripheral clock divided by 8  */
#define   ADC_CTRLB_PRESCALER_DIV16_Val       _UINT8_(0x3)                                         /* (ADC_CTRLB) Peripheral clock divided by 16  */
#define   ADC_CTRLB_PRESCALER_DIV32_Val       _UINT8_(0x4)                                         /* (ADC_CTRLB) Peripheral clock divided by 32  */
#define   ADC_CTRLB_PRESCALER_DIV64_Val       _UINT8_(0x5)                                         /* (ADC_CTRLB) Peripheral clock divided by 64  */
#define   ADC_CTRLB_PRESCALER_DIV128_Val      _UINT8_(0x6)                                         /* (ADC_CTRLB) Peripheral clock divided by 128  */
#define   ADC_CTRLB_PRESCALER_DIV256_Val      _UINT8_(0x7)                                         /* (ADC_CTRLB) Peripheral clock divided by 256  */
#define ADC_CTRLB_PRESCALER_DIV2              (ADC_CTRLB_PRESCALER_DIV2_Val << ADC_CTRLB_PRESCALER_Pos) /* (ADC_CTRLB) Peripheral clock divided by 2 Position  */
#define ADC_CTRLB_PRESCALER_DIV4              (ADC_CTRLB_PRESCALER_DIV4_Val << ADC_CTRLB_PRESCALER_Pos) /* (ADC_CTRLB) Peripheral clock divided by 4 Position  */
#define ADC_CTRLB_PRESCALER_DIV8              (ADC_CTRLB_PRESCALER_DIV8_Val << ADC_CTRLB_PRESCALER_Pos) /* (ADC_CTRLB) Peripheral clock divided by 8 Position  */
#define ADC_CTRLB_PRESCALER_DIV16             (ADC_CTRLB_PRESCALER_DIV16_Val << ADC_CTRLB_PRESCALER_Pos) /* (ADC_CTRLB) Peripheral clock divided by 16 Position  */
#define ADC_CTRLB_PRESCALER_DIV32             (ADC_CTRLB_PRESCALER_DIV32_Val << ADC_CTRLB_PRESCALER_Pos) /* (ADC_CTRLB) Peripheral clock divided by 32 Position  */
#define ADC_CTRLB_PRESCALER_DIV64             (ADC_CTRLB_PRESCALER_DIV64_Val << ADC_CTRLB_PRESCALER_Pos) /* (ADC_CTRLB) Peripheral clock divided by 64 Position  */
#define ADC_CTRLB_PRESCALER_DIV128            (ADC_CTRLB_PRESCALER_DIV128_Val << ADC_CTRLB_PRESCALER_Pos) /* (ADC_CTRLB) Peripheral clock divided by 128 Position  */
#define ADC_CTRLB_PRESCALER_DIV256            (ADC_CTRLB_PRESCALER_DIV256_Val << ADC_CTRLB_PRESCALER_Pos) /* (ADC_CTRLB) Peripheral clock divided by 256 Position  */
#define ADC_CTRLB_Msk                         _UINT8_(0x07)                                        /* (ADC_CTRLB) Register Mask  */


/* -------- ADC_REFCTRL : (ADC Offset: 0x02) (R/W 8) Reference Control -------- */
#define ADC_REFCTRL_RESETVALUE                _UINT8_(0x00)                                        /*  (ADC_REFCTRL) Reference Control  Reset Value */

#define ADC_REFCTRL_REFSEL_Pos                _UINT8_(0)                                           /* (ADC_REFCTRL) Reference Selection Position */
#define ADC_REFCTRL_REFSEL_Msk                (_UINT8_(0xF) << ADC_REFCTRL_REFSEL_Pos)             /* (ADC_REFCTRL) Reference Selection Mask */
#define ADC_REFCTRL_REFSEL(value)             (ADC_REFCTRL_REFSEL_Msk & (_UINT8_(value) << ADC_REFCTRL_REFSEL_Pos)) /* Assigment of value for REFSEL in the ADC_REFCTRL register */
#define   ADC_REFCTRL_REFSEL_INTREF_Val       _UINT8_(0x0)                                         /* (ADC_REFCTRL) Internal Voltage Reference  */
#define   ADC_REFCTRL_REFSEL_INTVCC0_Val      _UINT8_(0x1)                                         /* (ADC_REFCTRL) 1/1.6 AVDD  */
#define   ADC_REFCTRL_REFSEL_INTVCC1_Val      _UINT8_(0x2)                                         /* (ADC_REFCTRL) 1/2 AVDD  */
#define   ADC_REFCTRL_REFSEL_VREFA_Val        _UINT8_(0x3)                                         /* (ADC_REFCTRL) External Voltage Reference A (shared with DAC)  */
#define   ADC_REFCTRL_REFSEL_VREFB_Val        _UINT8_(0x4)                                         /* (ADC_REFCTRL) External Voltage Reference B  */
#define   ADC_REFCTRL_REFSEL_INTVCC2_Val      _UINT8_(0x5)                                         /* (ADC_REFCTRL) AVDD  */
#define ADC_REFCTRL_REFSEL_INTREF             (ADC_REFCTRL_REFSEL_INTREF_Val << ADC_REFCTRL_REFSEL_Pos) /* (ADC_REFCTRL) Internal Voltage Reference Position  */
#define ADC_REFCTRL_REFSEL_INTVCC0            (ADC_REFCTRL_REFSEL_INTVCC0_Val << ADC_REFCTRL_REFSEL_Pos) /* (ADC_REFCTRL) 1/1.6 AVDD Position  */
#define ADC_REFCTRL_REFSEL_INTVCC1            (ADC_REFCTRL_REFSEL_INTVCC1_Val << ADC_REFCTRL_REFSEL_Pos) /* (ADC_REFCTRL) 1/2 AVDD Position  */
#define ADC_REFCTRL_REFSEL_VREFA              (ADC_REFCTRL_REFSEL_VREFA_Val << ADC_REFCTRL_REFSEL_Pos) /* (ADC_REFCTRL) External Voltage Reference A (shared with DAC) Position  */
#define ADC_REFCTRL_REFSEL_VREFB              (ADC_REFCTRL_REFSEL_VREFB_Val << ADC_REFCTRL_REFSEL_Pos) /* (ADC_REFCTRL) External Voltage Reference B Position  */
#define ADC_REFCTRL_REFSEL_INTVCC2            (ADC_REFCTRL_REFSEL_INTVCC2_Val << ADC_REFCTRL_REFSEL_Pos) /* (ADC_REFCTRL) AVDD Position  */
#define ADC_REFCTRL_REFCOMP_Pos               _UINT8_(7)                                           /* (ADC_REFCTRL) Reference Buffer Offset Compensation Enable Position */
#define ADC_REFCTRL_REFCOMP_Msk               (_UINT8_(0x1) << ADC_REFCTRL_REFCOMP_Pos)            /* (ADC_REFCTRL) Reference Buffer Offset Compensation Enable Mask */
#define ADC_REFCTRL_REFCOMP(value)            (ADC_REFCTRL_REFCOMP_Msk & (_UINT8_(value) << ADC_REFCTRL_REFCOMP_Pos)) /* Assigment of value for REFCOMP in the ADC_REFCTRL register */
#define ADC_REFCTRL_Msk                       _UINT8_(0x8F)                                        /* (ADC_REFCTRL) Register Mask  */


/* -------- ADC_EVCTRL : (ADC Offset: 0x03) (R/W 8) Event Control -------- */
#define ADC_EVCTRL_RESETVALUE                 _UINT8_(0x00)                                        /*  (ADC_EVCTRL) Event Control  Reset Value */

#define ADC_EVCTRL_FLUSHEI_Pos                _UINT8_(0)                                           /* (ADC_EVCTRL) Flush Event Input Enable Position */
#define ADC_EVCTRL_FLUSHEI_Msk                (_UINT8_(0x1) << ADC_EVCTRL_FLUSHEI_Pos)             /* (ADC_EVCTRL) Flush Event Input Enable Mask */
#define ADC_EVCTRL_FLUSHEI(value)             (ADC_EVCTRL_FLUSHEI_Msk & (_UINT8_(value) << ADC_EVCTRL_FLUSHEI_Pos)) /* Assigment of value for FLUSHEI in the ADC_EVCTRL register */
#define ADC_EVCTRL_STARTEI_Pos                _UINT8_(1)                                           /* (ADC_EVCTRL) Start Conversion Event Input Enable Position */
#define ADC_EVCTRL_STARTEI_Msk                (_UINT8_(0x1) << ADC_EVCTRL_STARTEI_Pos)             /* (ADC_EVCTRL) Start Conversion Event Input Enable Mask */
#define ADC_EVCTRL_STARTEI(value)             (ADC_EVCTRL_STARTEI_Msk & (_UINT8_(value) << ADC_EVCTRL_STARTEI_Pos)) /* Assigment of value for STARTEI in the ADC_EVCTRL register */
#define ADC_EVCTRL_FLUSHINV_Pos               _UINT8_(2)                                           /* (ADC_EVCTRL) Flush Event Invert Enable Position */
#define ADC_EVCTRL_FLUSHINV_Msk               (_UINT8_(0x1) << ADC_EVCTRL_FLUSHINV_Pos)            /* (ADC_EVCTRL) Flush Event Invert Enable Mask */
#define ADC_EVCTRL_FLUSHINV(value)            (ADC_EVCTRL_FLUSHINV_Msk & (_UINT8_(value) << ADC_EVCTRL_FLUSHINV_Pos)) /* Assigment of value for FLUSHINV in the ADC_EVCTRL register */
#define ADC_EVCTRL_STARTINV_Pos               _UINT8_(3)                                           /* (ADC_EVCTRL) Start Event Invert Enable Position */
#define ADC_EVCTRL_STARTINV_Msk               (_UINT8_(0x1) << ADC_EVCTRL_STARTINV_Pos)            /* (ADC_EVCTRL) Start Event Invert Enable Mask */
#define ADC_EVCTRL_STARTINV(value)            (ADC_EVCTRL_STARTINV_Msk & (_UINT8_(value) << ADC_EVCTRL_STARTINV_Pos)) /* Assigment of value for STARTINV in the ADC_EVCTRL register */
#define ADC_EVCTRL_RESRDYEO_Pos               _UINT8_(4)                                           /* (ADC_EVCTRL) Result Ready Event Out Position */
#define ADC_EVCTRL_RESRDYEO_Msk               (_UINT8_(0x1) << ADC_EVCTRL_RESRDYEO_Pos)            /* (ADC_EVCTRL) Result Ready Event Out Mask */
#define ADC_EVCTRL_RESRDYEO(value)            (ADC_EVCTRL_RESRDYEO_Msk & (_UINT8_(value) << ADC_EVCTRL_RESRDYEO_Pos)) /* Assigment of value for RESRDYEO in the ADC_EVCTRL register */
#define ADC_EVCTRL_WINMONEO_Pos               _UINT8_(5)                                           /* (ADC_EVCTRL) Window Monitor Event Out Position */
#define ADC_EVCTRL_WINMONEO_Msk               (_UINT8_(0x1) << ADC_EVCTRL_WINMONEO_Pos)            /* (ADC_EVCTRL) Window Monitor Event Out Mask */
#define ADC_EVCTRL_WINMONEO(value)            (ADC_EVCTRL_WINMONEO_Msk & (_UINT8_(value) << ADC_EVCTRL_WINMONEO_Pos)) /* Assigment of value for WINMONEO in the ADC_EVCTRL register */
#define ADC_EVCTRL_Msk                        _UINT8_(0x3F)                                        /* (ADC_EVCTRL) Register Mask  */


/* -------- ADC_INTENCLR : (ADC Offset: 0x04) (R/W 8) Interrupt Enable Clear -------- */
#define ADC_INTENCLR_RESETVALUE               _UINT8_(0x00)                                        /*  (ADC_INTENCLR) Interrupt Enable Clear  Reset Value */

#define ADC_INTENCLR_RESRDY_Pos               _UINT8_(0)                                           /* (ADC_INTENCLR) Result Ready Interrupt Disable Position */
#define ADC_INTENCLR_RESRDY_Msk               (_UINT8_(0x1) << ADC_INTENCLR_RESRDY_Pos)            /* (ADC_INTENCLR) Result Ready Interrupt Disable Mask */
#define ADC_INTENCLR_RESRDY(value)            (ADC_INTENCLR_RESRDY_Msk & (_UINT8_(value) << ADC_INTENCLR_RESRDY_Pos)) /* Assigment of value for RESRDY in the ADC_INTENCLR register */
#define ADC_INTENCLR_OVERRUN_Pos              _UINT8_(1)                                           /* (ADC_INTENCLR) Overrun Interrupt Disable Position */
#define ADC_INTENCLR_OVERRUN_Msk              (_UINT8_(0x1) << ADC_INTENCLR_OVERRUN_Pos)           /* (ADC_INTENCLR) Overrun Interrupt Disable Mask */
#define ADC_INTENCLR_OVERRUN(value)           (ADC_INTENCLR_OVERRUN_Msk & (_UINT8_(value) << ADC_INTENCLR_OVERRUN_Pos)) /* Assigment of value for OVERRUN in the ADC_INTENCLR register */
#define ADC_INTENCLR_WINMON_Pos               _UINT8_(2)                                           /* (ADC_INTENCLR) Window Monitor Interrupt Disable Position */
#define ADC_INTENCLR_WINMON_Msk               (_UINT8_(0x1) << ADC_INTENCLR_WINMON_Pos)            /* (ADC_INTENCLR) Window Monitor Interrupt Disable Mask */
#define ADC_INTENCLR_WINMON(value)            (ADC_INTENCLR_WINMON_Msk & (_UINT8_(value) << ADC_INTENCLR_WINMON_Pos)) /* Assigment of value for WINMON in the ADC_INTENCLR register */
#define ADC_INTENCLR_Msk                      _UINT8_(0x07)                                        /* (ADC_INTENCLR) Register Mask  */


/* -------- ADC_INTENSET : (ADC Offset: 0x05) (R/W 8) Interrupt Enable Set -------- */
#define ADC_INTENSET_RESETVALUE               _UINT8_(0x00)                                        /*  (ADC_INTENSET) Interrupt Enable Set  Reset Value */

#define ADC_INTENSET_RESRDY_Pos               _UINT8_(0)                                           /* (ADC_INTENSET) Result Ready Interrupt Enable Position */
#define ADC_INTENSET_RESRDY_Msk               (_UINT8_(0x1) << ADC_INTENSET_RESRDY_Pos)            /* (ADC_INTENSET) Result Ready Interrupt Enable Mask */
#define ADC_INTENSET_RESRDY(value)            (ADC_INTENSET_RESRDY_Msk & (_UINT8_(value) << ADC_INTENSET_RESRDY_Pos)) /* Assigment of value for RESRDY in the ADC_INTENSET register */
#define ADC_INTENSET_OVERRUN_Pos              _UINT8_(1)                                           /* (ADC_INTENSET) Overrun Interrupt Enable Position */
#define ADC_INTENSET_OVERRUN_Msk              (_UINT8_(0x1) << ADC_INTENSET_OVERRUN_Pos)           /* (ADC_INTENSET) Overrun Interrupt Enable Mask */
#define ADC_INTENSET_OVERRUN(value)           (ADC_INTENSET_OVERRUN_Msk & (_UINT8_(value) << ADC_INTENSET_OVERRUN_Pos)) /* Assigment of value for OVERRUN in the ADC_INTENSET register */
#define ADC_INTENSET_WINMON_Pos               _UINT8_(2)                                           /* (ADC_INTENSET) Window Monitor Interrupt Enable Position */
#define ADC_INTENSET_WINMON_Msk               (_UINT8_(0x1) << ADC_INTENSET_WINMON_Pos)            /* (ADC_INTENSET) Window Monitor Interrupt Enable Mask */
#define ADC_INTENSET_WINMON(value)            (ADC_INTENSET_WINMON_Msk & (_UINT8_(value) << ADC_INTENSET_WINMON_Pos)) /* Assigment of value for WINMON in the ADC_INTENSET register */
#define ADC_INTENSET_Msk                      _UINT8_(0x07)                                        /* (ADC_INTENSET) Register Mask  */


/* -------- ADC_INTFLAG : (ADC Offset: 0x06) (R/W 8) Interrupt Flag Status and Clear -------- */
#define ADC_INTFLAG_RESETVALUE                _UINT8_(0x00)                                        /*  (ADC_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define ADC_INTFLAG_RESRDY_Pos                _UINT8_(0)                                           /* (ADC_INTFLAG) Result Ready Interrupt Flag Position */
#define ADC_INTFLAG_RESRDY_Msk                (_UINT8_(0x1) << ADC_INTFLAG_RESRDY_Pos)             /* (ADC_INTFLAG) Result Ready Interrupt Flag Mask */
#define ADC_INTFLAG_RESRDY(value)             (ADC_INTFLAG_RESRDY_Msk & (_UINT8_(value) << ADC_INTFLAG_RESRDY_Pos)) /* Assigment of value for RESRDY in the ADC_INTFLAG register */
#define ADC_INTFLAG_OVERRUN_Pos               _UINT8_(1)                                           /* (ADC_INTFLAG) Overrun Interrupt Flag Position */
#define ADC_INTFLAG_OVERRUN_Msk               (_UINT8_(0x1) << ADC_INTFLAG_OVERRUN_Pos)            /* (ADC_INTFLAG) Overrun Interrupt Flag Mask */
#define ADC_INTFLAG_OVERRUN(value)            (ADC_INTFLAG_OVERRUN_Msk & (_UINT8_(value) << ADC_INTFLAG_OVERRUN_Pos)) /* Assigment of value for OVERRUN in the ADC_INTFLAG register */
#define ADC_INTFLAG_WINMON_Pos                _UINT8_(2)                                           /* (ADC_INTFLAG) Window Monitor Interrupt Flag Position */
#define ADC_INTFLAG_WINMON_Msk                (_UINT8_(0x1) << ADC_INTFLAG_WINMON_Pos)             /* (ADC_INTFLAG) Window Monitor Interrupt Flag Mask */
#define ADC_INTFLAG_WINMON(value)             (ADC_INTFLAG_WINMON_Msk & (_UINT8_(value) << ADC_INTFLAG_WINMON_Pos)) /* Assigment of value for WINMON in the ADC_INTFLAG register */
#define ADC_INTFLAG_Msk                       _UINT8_(0x07)                                        /* (ADC_INTFLAG) Register Mask  */


/* -------- ADC_SEQSTATUS : (ADC Offset: 0x07) ( R/ 8) Sequence Status -------- */
#define ADC_SEQSTATUS_RESETVALUE              _UINT8_(0x00)                                        /*  (ADC_SEQSTATUS) Sequence Status  Reset Value */

#define ADC_SEQSTATUS_SEQSTATE_Pos            _UINT8_(0)                                           /* (ADC_SEQSTATUS) Sequence State Position */
#define ADC_SEQSTATUS_SEQSTATE_Msk            (_UINT8_(0x1F) << ADC_SEQSTATUS_SEQSTATE_Pos)        /* (ADC_SEQSTATUS) Sequence State Mask */
#define ADC_SEQSTATUS_SEQSTATE(value)         (ADC_SEQSTATUS_SEQSTATE_Msk & (_UINT8_(value) << ADC_SEQSTATUS_SEQSTATE_Pos)) /* Assigment of value for SEQSTATE in the ADC_SEQSTATUS register */
#define ADC_SEQSTATUS_SEQBUSY_Pos             _UINT8_(7)                                           /* (ADC_SEQSTATUS) Sequence Busy Position */
#define ADC_SEQSTATUS_SEQBUSY_Msk             (_UINT8_(0x1) << ADC_SEQSTATUS_SEQBUSY_Pos)          /* (ADC_SEQSTATUS) Sequence Busy Mask */
#define ADC_SEQSTATUS_SEQBUSY(value)          (ADC_SEQSTATUS_SEQBUSY_Msk & (_UINT8_(value) << ADC_SEQSTATUS_SEQBUSY_Pos)) /* Assigment of value for SEQBUSY in the ADC_SEQSTATUS register */
#define ADC_SEQSTATUS_Msk                     _UINT8_(0x9F)                                        /* (ADC_SEQSTATUS) Register Mask  */


/* -------- ADC_INPUTCTRL : (ADC Offset: 0x08) (R/W 16) Input Control -------- */
#define ADC_INPUTCTRL_RESETVALUE              _UINT16_(0x00)                                       /*  (ADC_INPUTCTRL) Input Control  Reset Value */

#define ADC_INPUTCTRL_MUXPOS_Pos              _UINT16_(0)                                          /* (ADC_INPUTCTRL) Positive Mux Input Selection Position */
#define ADC_INPUTCTRL_MUXPOS_Msk              (_UINT16_(0x1F) << ADC_INPUTCTRL_MUXPOS_Pos)         /* (ADC_INPUTCTRL) Positive Mux Input Selection Mask */
#define ADC_INPUTCTRL_MUXPOS(value)           (ADC_INPUTCTRL_MUXPOS_Msk & (_UINT16_(value) << ADC_INPUTCTRL_MUXPOS_Pos)) /* Assigment of value for MUXPOS in the ADC_INPUTCTRL register */
#define   ADC_INPUTCTRL_MUXPOS_AIN0_Val       _UINT16_(0x0)                                        /* (ADC_INPUTCTRL) ADC AIN0 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN1_Val       _UINT16_(0x1)                                        /* (ADC_INPUTCTRL) ADC AIN1 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN2_Val       _UINT16_(0x2)                                        /* (ADC_INPUTCTRL) ADC AIN2 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN3_Val       _UINT16_(0x3)                                        /* (ADC_INPUTCTRL) ADC AIN3 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN4_Val       _UINT16_(0x4)                                        /* (ADC_INPUTCTRL) ADC AIN4 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN5_Val       _UINT16_(0x5)                                        /* (ADC_INPUTCTRL) ADC AIN5 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN6_Val       _UINT16_(0x6)                                        /* (ADC_INPUTCTRL) ADC AIN6 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN7_Val       _UINT16_(0x7)                                        /* (ADC_INPUTCTRL) ADC AIN7 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN8_Val       _UINT16_(0x8)                                        /* (ADC_INPUTCTRL) ADC AIN8 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN9_Val       _UINT16_(0x9)                                        /* (ADC_INPUTCTRL) ADC AIN9 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN10_Val      _UINT16_(0xA)                                        /* (ADC_INPUTCTRL) ADC AIN10 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN11_Val      _UINT16_(0xB)                                        /* (ADC_INPUTCTRL) ADC AIN11 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN12_Val      _UINT16_(0xC)                                        /* (ADC_INPUTCTRL) ADC AIN12 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN13_Val      _UINT16_(0xD)                                        /* (ADC_INPUTCTRL) ADC AIN13 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN14_Val      _UINT16_(0xE)                                        /* (ADC_INPUTCTRL) ADC AIN14 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN15_Val      _UINT16_(0xF)                                        /* (ADC_INPUTCTRL) ADC AIN15 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN16_Val      _UINT16_(0x10)                                       /* (ADC_INPUTCTRL) ADC AIN16 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN17_Val      _UINT16_(0x11)                                       /* (ADC_INPUTCTRL) ADC AIN17 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN18_Val      _UINT16_(0x12)                                       /* (ADC_INPUTCTRL) ADC AIN18 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN19_Val      _UINT16_(0x13)                                       /* (ADC_INPUTCTRL) ADC AIN19 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN20_Val      _UINT16_(0x14)                                       /* (ADC_INPUTCTRL) ADC AIN20 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN21_Val      _UINT16_(0x15)                                       /* (ADC_INPUTCTRL) ADC AIN21 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN22_Val      _UINT16_(0x16)                                       /* (ADC_INPUTCTRL) ADC AIN22 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_AIN23_Val      _UINT16_(0x17)                                       /* (ADC_INPUTCTRL) ADC AIN23 Pin  */
#define   ADC_INPUTCTRL_MUXPOS_BANDGAP_Val    _UINT16_(0x19)                                       /* (ADC_INPUTCTRL) Internal Bandgap Voltage  */
#define   ADC_INPUTCTRL_MUXPOS_SCALEDVDDCORE_Val _UINT16_(0x1A)                                       /* (ADC_INPUTCTRL) 1/4 Scaled VDDCORE Supply  */
#define   ADC_INPUTCTRL_MUXPOS_SCALEDAVDD_Val _UINT16_(0x1B)                                       /* (ADC_INPUTCTRL) 1/4 Scaled AVDD Supply  */
#define   ADC_INPUTCTRL_MUXPOS_DAC0_Val       _UINT16_(0x1C)                                       /* (ADC_INPUTCTRL) DAC0 Output  */
#define   ADC_INPUTCTRL_MUXPOS_SCALEDVDD_Val  _UINT16_(0x1D)                                       /* (ADC_INPUTCTRL) 1/4 Scaled VDD Supply  */
#define   ADC_INPUTCTRL_MUXPOS_OPAMP01_Val    _UINT16_(0x1E)                                       /* (ADC_INPUTCTRL) OPAMP0 or OPAMP1 output  */
#define   ADC_INPUTCTRL_MUXPOS_OPAMP2_Val     _UINT16_(0x1F)                                       /* (ADC_INPUTCTRL) OPAMP2 output  */
#define ADC_INPUTCTRL_MUXPOS_AIN0             (ADC_INPUTCTRL_MUXPOS_AIN0_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN0 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN1             (ADC_INPUTCTRL_MUXPOS_AIN1_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN1 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN2             (ADC_INPUTCTRL_MUXPOS_AIN2_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN2 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN3             (ADC_INPUTCTRL_MUXPOS_AIN3_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN3 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN4             (ADC_INPUTCTRL_MUXPOS_AIN4_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN4 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN5             (ADC_INPUTCTRL_MUXPOS_AIN5_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN5 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN6             (ADC_INPUTCTRL_MUXPOS_AIN6_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN6 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN7             (ADC_INPUTCTRL_MUXPOS_AIN7_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN7 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN8             (ADC_INPUTCTRL_MUXPOS_AIN8_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN8 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN9             (ADC_INPUTCTRL_MUXPOS_AIN9_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN9 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN10            (ADC_INPUTCTRL_MUXPOS_AIN10_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN10 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN11            (ADC_INPUTCTRL_MUXPOS_AIN11_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN11 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN12            (ADC_INPUTCTRL_MUXPOS_AIN12_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN12 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN13            (ADC_INPUTCTRL_MUXPOS_AIN13_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN13 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN14            (ADC_INPUTCTRL_MUXPOS_AIN14_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN14 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN15            (ADC_INPUTCTRL_MUXPOS_AIN15_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN15 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN16            (ADC_INPUTCTRL_MUXPOS_AIN16_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN16 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN17            (ADC_INPUTCTRL_MUXPOS_AIN17_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN17 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN18            (ADC_INPUTCTRL_MUXPOS_AIN18_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN18 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN19            (ADC_INPUTCTRL_MUXPOS_AIN19_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN19 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN20            (ADC_INPUTCTRL_MUXPOS_AIN20_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN20 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN21            (ADC_INPUTCTRL_MUXPOS_AIN21_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN21 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN22            (ADC_INPUTCTRL_MUXPOS_AIN22_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN22 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_AIN23            (ADC_INPUTCTRL_MUXPOS_AIN23_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) ADC AIN23 Pin Position  */
#define ADC_INPUTCTRL_MUXPOS_BANDGAP          (ADC_INPUTCTRL_MUXPOS_BANDGAP_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) Internal Bandgap Voltage Position  */
#define ADC_INPUTCTRL_MUXPOS_SCALEDVDDCORE    (ADC_INPUTCTRL_MUXPOS_SCALEDVDDCORE_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) 1/4 Scaled VDDCORE Supply Position  */
#define ADC_INPUTCTRL_MUXPOS_SCALEDAVDD       (ADC_INPUTCTRL_MUXPOS_SCALEDAVDD_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) 1/4 Scaled AVDD Supply Position  */
#define ADC_INPUTCTRL_MUXPOS_DAC0             (ADC_INPUTCTRL_MUXPOS_DAC0_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) DAC0 Output Position  */
#define ADC_INPUTCTRL_MUXPOS_SCALEDVDD        (ADC_INPUTCTRL_MUXPOS_SCALEDVDD_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) 1/4 Scaled VDD Supply Position  */
#define ADC_INPUTCTRL_MUXPOS_OPAMP01          (ADC_INPUTCTRL_MUXPOS_OPAMP01_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) OPAMP0 or OPAMP1 output Position  */
#define ADC_INPUTCTRL_MUXPOS_OPAMP2           (ADC_INPUTCTRL_MUXPOS_OPAMP2_Val << ADC_INPUTCTRL_MUXPOS_Pos) /* (ADC_INPUTCTRL) OPAMP2 output Position  */
#define ADC_INPUTCTRL_MUXNEG_Pos              _UINT16_(8)                                          /* (ADC_INPUTCTRL) Negative Mux Input Selection Position */
#define ADC_INPUTCTRL_MUXNEG_Msk              (_UINT16_(0x1F) << ADC_INPUTCTRL_MUXNEG_Pos)         /* (ADC_INPUTCTRL) Negative Mux Input Selection Mask */
#define ADC_INPUTCTRL_MUXNEG(value)           (ADC_INPUTCTRL_MUXNEG_Msk & (_UINT16_(value) << ADC_INPUTCTRL_MUXNEG_Pos)) /* Assigment of value for MUXNEG in the ADC_INPUTCTRL register */
#define   ADC_INPUTCTRL_MUXNEG_AIN0_Val       _UINT16_(0x0)                                        /* (ADC_INPUTCTRL) ADC AIN0 Pin  */
#define   ADC_INPUTCTRL_MUXNEG_AIN1_Val       _UINT16_(0x1)                                        /* (ADC_INPUTCTRL) ADC AIN1 Pin  */
#define   ADC_INPUTCTRL_MUXNEG_AIN2_Val       _UINT16_(0x2)                                        /* (ADC_INPUTCTRL) ADC AIN2 Pin  */
#define   ADC_INPUTCTRL_MUXNEG_AIN3_Val       _UINT16_(0x3)                                        /* (ADC_INPUTCTRL) ADC AIN3 Pin  */
#define   ADC_INPUTCTRL_MUXNEG_AIN4_Val       _UINT16_(0x4)                                        /* (ADC_INPUTCTRL) ADC AIN4 Pin  */
#define   ADC_INPUTCTRL_MUXNEG_AIN5_Val       _UINT16_(0x5)                                        /* (ADC_INPUTCTRL) ADC AIN5 Pin  */
#define   ADC_INPUTCTRL_MUXNEG_AIN6_Val       _UINT16_(0x6)                                        /* (ADC_INPUTCTRL) ADC AIN6 Pin  */
#define   ADC_INPUTCTRL_MUXNEG_AIN7_Val       _UINT16_(0x7)                                        /* (ADC_INPUTCTRL) ADC AIN7 Pin  */
#define   ADC_INPUTCTRL_MUXNEG_AVSS_Val       _UINT16_(0x18)                                       /* (ADC_INPUTCTRL) Internal Ground  */
#define ADC_INPUTCTRL_MUXNEG_AIN0             (ADC_INPUTCTRL_MUXNEG_AIN0_Val << ADC_INPUTCTRL_MUXNEG_Pos) /* (ADC_INPUTCTRL) ADC AIN0 Pin Position  */
#define ADC_INPUTCTRL_MUXNEG_AIN1             (ADC_INPUTCTRL_MUXNEG_AIN1_Val << ADC_INPUTCTRL_MUXNEG_Pos) /* (ADC_INPUTCTRL) ADC AIN1 Pin Position  */
#define ADC_INPUTCTRL_MUXNEG_AIN2             (ADC_INPUTCTRL_MUXNEG_AIN2_Val << ADC_INPUTCTRL_MUXNEG_Pos) /* (ADC_INPUTCTRL) ADC AIN2 Pin Position  */
#define ADC_INPUTCTRL_MUXNEG_AIN3             (ADC_INPUTCTRL_MUXNEG_AIN3_Val << ADC_INPUTCTRL_MUXNEG_Pos) /* (ADC_INPUTCTRL) ADC AIN3 Pin Position  */
#define ADC_INPUTCTRL_MUXNEG_AIN4             (ADC_INPUTCTRL_MUXNEG_AIN4_Val << ADC_INPUTCTRL_MUXNEG_Pos) /* (ADC_INPUTCTRL) ADC AIN4 Pin Position  */
#define ADC_INPUTCTRL_MUXNEG_AIN5             (ADC_INPUTCTRL_MUXNEG_AIN5_Val << ADC_INPUTCTRL_MUXNEG_Pos) /* (ADC_INPUTCTRL) ADC AIN5 Pin Position  */
#define ADC_INPUTCTRL_MUXNEG_AIN6             (ADC_INPUTCTRL_MUXNEG_AIN6_Val << ADC_INPUTCTRL_MUXNEG_Pos) /* (ADC_INPUTCTRL) ADC AIN6 Pin Position  */
#define ADC_INPUTCTRL_MUXNEG_AIN7             (ADC_INPUTCTRL_MUXNEG_AIN7_Val << ADC_INPUTCTRL_MUXNEG_Pos) /* (ADC_INPUTCTRL) ADC AIN7 Pin Position  */
#define ADC_INPUTCTRL_MUXNEG_AVSS             (ADC_INPUTCTRL_MUXNEG_AVSS_Val << ADC_INPUTCTRL_MUXNEG_Pos) /* (ADC_INPUTCTRL) Internal Ground Position  */
#define ADC_INPUTCTRL_Msk                     _UINT16_(0x1F1F)                                     /* (ADC_INPUTCTRL) Register Mask  */


/* -------- ADC_CTRLC : (ADC Offset: 0x0A) (R/W 16) Control C -------- */
#define ADC_CTRLC_RESETVALUE                  _UINT16_(0x00)                                       /*  (ADC_CTRLC) Control C  Reset Value */

#define ADC_CTRLC_DIFFMODE_Pos                _UINT16_(0)                                          /* (ADC_CTRLC) Differential Mode Position */
#define ADC_CTRLC_DIFFMODE_Msk                (_UINT16_(0x1) << ADC_CTRLC_DIFFMODE_Pos)            /* (ADC_CTRLC) Differential Mode Mask */
#define ADC_CTRLC_DIFFMODE(value)             (ADC_CTRLC_DIFFMODE_Msk & (_UINT16_(value) << ADC_CTRLC_DIFFMODE_Pos)) /* Assigment of value for DIFFMODE in the ADC_CTRLC register */
#define ADC_CTRLC_LEFTADJ_Pos                 _UINT16_(1)                                          /* (ADC_CTRLC) Left-Adjusted Result Position */
#define ADC_CTRLC_LEFTADJ_Msk                 (_UINT16_(0x1) << ADC_CTRLC_LEFTADJ_Pos)             /* (ADC_CTRLC) Left-Adjusted Result Mask */
#define ADC_CTRLC_LEFTADJ(value)              (ADC_CTRLC_LEFTADJ_Msk & (_UINT16_(value) << ADC_CTRLC_LEFTADJ_Pos)) /* Assigment of value for LEFTADJ in the ADC_CTRLC register */
#define ADC_CTRLC_FREERUN_Pos                 _UINT16_(2)                                          /* (ADC_CTRLC) Free Running Mode Position */
#define ADC_CTRLC_FREERUN_Msk                 (_UINT16_(0x1) << ADC_CTRLC_FREERUN_Pos)             /* (ADC_CTRLC) Free Running Mode Mask */
#define ADC_CTRLC_FREERUN(value)              (ADC_CTRLC_FREERUN_Msk & (_UINT16_(value) << ADC_CTRLC_FREERUN_Pos)) /* Assigment of value for FREERUN in the ADC_CTRLC register */
#define ADC_CTRLC_CORREN_Pos                  _UINT16_(3)                                          /* (ADC_CTRLC) Digital Correction Logic Enable Position */
#define ADC_CTRLC_CORREN_Msk                  (_UINT16_(0x1) << ADC_CTRLC_CORREN_Pos)              /* (ADC_CTRLC) Digital Correction Logic Enable Mask */
#define ADC_CTRLC_CORREN(value)               (ADC_CTRLC_CORREN_Msk & (_UINT16_(value) << ADC_CTRLC_CORREN_Pos)) /* Assigment of value for CORREN in the ADC_CTRLC register */
#define ADC_CTRLC_RESSEL_Pos                  _UINT16_(4)                                          /* (ADC_CTRLC) Conversion Result Resolution Position */
#define ADC_CTRLC_RESSEL_Msk                  (_UINT16_(0x3) << ADC_CTRLC_RESSEL_Pos)              /* (ADC_CTRLC) Conversion Result Resolution Mask */
#define ADC_CTRLC_RESSEL(value)               (ADC_CTRLC_RESSEL_Msk & (_UINT16_(value) << ADC_CTRLC_RESSEL_Pos)) /* Assigment of value for RESSEL in the ADC_CTRLC register */
#define   ADC_CTRLC_RESSEL_12BIT_Val          _UINT16_(0x0)                                        /* (ADC_CTRLC) 12-bit result  */
#define   ADC_CTRLC_RESSEL_16BIT_Val          _UINT16_(0x1)                                        /* (ADC_CTRLC) Accumulation or Oversampling and Decimation modes  */
#define   ADC_CTRLC_RESSEL_10BIT_Val          _UINT16_(0x2)                                        /* (ADC_CTRLC) 10-bit result  */
#define   ADC_CTRLC_RESSEL_8BIT_Val           _UINT16_(0x3)                                        /* (ADC_CTRLC) 8-bit result  */
#define ADC_CTRLC_RESSEL_12BIT                (ADC_CTRLC_RESSEL_12BIT_Val << ADC_CTRLC_RESSEL_Pos) /* (ADC_CTRLC) 12-bit result Position  */
#define ADC_CTRLC_RESSEL_16BIT                (ADC_CTRLC_RESSEL_16BIT_Val << ADC_CTRLC_RESSEL_Pos) /* (ADC_CTRLC) Accumulation or Oversampling and Decimation modes Position  */
#define ADC_CTRLC_RESSEL_10BIT                (ADC_CTRLC_RESSEL_10BIT_Val << ADC_CTRLC_RESSEL_Pos) /* (ADC_CTRLC) 10-bit result Position  */
#define ADC_CTRLC_RESSEL_8BIT                 (ADC_CTRLC_RESSEL_8BIT_Val << ADC_CTRLC_RESSEL_Pos)  /* (ADC_CTRLC) 8-bit result Position  */
#define ADC_CTRLC_WINMODE_Pos                 _UINT16_(8)                                          /* (ADC_CTRLC) Window Monitor Mode Position */
#define ADC_CTRLC_WINMODE_Msk                 (_UINT16_(0x7) << ADC_CTRLC_WINMODE_Pos)             /* (ADC_CTRLC) Window Monitor Mode Mask */
#define ADC_CTRLC_WINMODE(value)              (ADC_CTRLC_WINMODE_Msk & (_UINT16_(value) << ADC_CTRLC_WINMODE_Pos)) /* Assigment of value for WINMODE in the ADC_CTRLC register */
#define   ADC_CTRLC_WINMODE_DISABLE_Val       _UINT16_(0x0)                                        /* (ADC_CTRLC) No window mode (default)  */
#define   ADC_CTRLC_WINMODE_MODE1_Val         _UINT16_(0x1)                                        /* (ADC_CTRLC) RESULT > WINLT  */
#define   ADC_CTRLC_WINMODE_MODE2_Val         _UINT16_(0x2)                                        /* (ADC_CTRLC) RESULT < WINUT  */
#define   ADC_CTRLC_WINMODE_MODE3_Val         _UINT16_(0x3)                                        /* (ADC_CTRLC) WINLT < RESULT < WINUT  */
#define   ADC_CTRLC_WINMODE_MODE4_Val         _UINT16_(0x4)                                        /* (ADC_CTRLC) !(WINLT < RESULT < WINUT)  */
#define ADC_CTRLC_WINMODE_DISABLE             (ADC_CTRLC_WINMODE_DISABLE_Val << ADC_CTRLC_WINMODE_Pos) /* (ADC_CTRLC) No window mode (default) Position  */
#define ADC_CTRLC_WINMODE_MODE1               (ADC_CTRLC_WINMODE_MODE1_Val << ADC_CTRLC_WINMODE_Pos) /* (ADC_CTRLC) RESULT > WINLT Position  */
#define ADC_CTRLC_WINMODE_MODE2               (ADC_CTRLC_WINMODE_MODE2_Val << ADC_CTRLC_WINMODE_Pos) /* (ADC_CTRLC) RESULT < WINUT Position  */
#define ADC_CTRLC_WINMODE_MODE3               (ADC_CTRLC_WINMODE_MODE3_Val << ADC_CTRLC_WINMODE_Pos) /* (ADC_CTRLC) WINLT < RESULT < WINUT Position  */
#define ADC_CTRLC_WINMODE_MODE4               (ADC_CTRLC_WINMODE_MODE4_Val << ADC_CTRLC_WINMODE_Pos) /* (ADC_CTRLC) !(WINLT < RESULT < WINUT) Position  */
#define ADC_CTRLC_Msk                         _UINT16_(0x073F)                                     /* (ADC_CTRLC) Register Mask  */


/* -------- ADC_AVGCTRL : (ADC Offset: 0x0C) (R/W 8) Average Control -------- */
#define ADC_AVGCTRL_RESETVALUE                _UINT8_(0x00)                                        /*  (ADC_AVGCTRL) Average Control  Reset Value */

#define ADC_AVGCTRL_SAMPLENUM_Pos             _UINT8_(0)                                           /* (ADC_AVGCTRL) Number of Samples to be Collected Position */
#define ADC_AVGCTRL_SAMPLENUM_Msk             (_UINT8_(0xF) << ADC_AVGCTRL_SAMPLENUM_Pos)          /* (ADC_AVGCTRL) Number of Samples to be Collected Mask */
#define ADC_AVGCTRL_SAMPLENUM(value)          (ADC_AVGCTRL_SAMPLENUM_Msk & (_UINT8_(value) << ADC_AVGCTRL_SAMPLENUM_Pos)) /* Assigment of value for SAMPLENUM in the ADC_AVGCTRL register */
#define   ADC_AVGCTRL_SAMPLENUM_1_Val         _UINT8_(0x0)                                         /* (ADC_AVGCTRL) 1 sample  */
#define   ADC_AVGCTRL_SAMPLENUM_2_Val         _UINT8_(0x1)                                         /* (ADC_AVGCTRL) 2 samples  */
#define   ADC_AVGCTRL_SAMPLENUM_4_Val         _UINT8_(0x2)                                         /* (ADC_AVGCTRL) 4 samples  */
#define   ADC_AVGCTRL_SAMPLENUM_8_Val         _UINT8_(0x3)                                         /* (ADC_AVGCTRL) 8 samples  */
#define   ADC_AVGCTRL_SAMPLENUM_16_Val        _UINT8_(0x4)                                         /* (ADC_AVGCTRL) 16 samples  */
#define   ADC_AVGCTRL_SAMPLENUM_32_Val        _UINT8_(0x5)                                         /* (ADC_AVGCTRL) 32 samples  */
#define   ADC_AVGCTRL_SAMPLENUM_64_Val        _UINT8_(0x6)                                         /* (ADC_AVGCTRL) 64 samples  */
#define   ADC_AVGCTRL_SAMPLENUM_128_Val       _UINT8_(0x7)                                         /* (ADC_AVGCTRL) 128 samples  */
#define   ADC_AVGCTRL_SAMPLENUM_256_Val       _UINT8_(0x8)                                         /* (ADC_AVGCTRL) 256 samples  */
#define   ADC_AVGCTRL_SAMPLENUM_512_Val       _UINT8_(0x9)                                         /* (ADC_AVGCTRL) 512 samples  */
#define   ADC_AVGCTRL_SAMPLENUM_1024_Val      _UINT8_(0xA)                                         /* (ADC_AVGCTRL) 1024 samples  */
#define ADC_AVGCTRL_SAMPLENUM_1               (ADC_AVGCTRL_SAMPLENUM_1_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 1 sample Position  */
#define ADC_AVGCTRL_SAMPLENUM_2               (ADC_AVGCTRL_SAMPLENUM_2_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 2 samples Position  */
#define ADC_AVGCTRL_SAMPLENUM_4               (ADC_AVGCTRL_SAMPLENUM_4_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 4 samples Position  */
#define ADC_AVGCTRL_SAMPLENUM_8               (ADC_AVGCTRL_SAMPLENUM_8_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 8 samples Position  */
#define ADC_AVGCTRL_SAMPLENUM_16              (ADC_AVGCTRL_SAMPLENUM_16_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 16 samples Position  */
#define ADC_AVGCTRL_SAMPLENUM_32              (ADC_AVGCTRL_SAMPLENUM_32_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 32 samples Position  */
#define ADC_AVGCTRL_SAMPLENUM_64              (ADC_AVGCTRL_SAMPLENUM_64_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 64 samples Position  */
#define ADC_AVGCTRL_SAMPLENUM_128             (ADC_AVGCTRL_SAMPLENUM_128_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 128 samples Position  */
#define ADC_AVGCTRL_SAMPLENUM_256             (ADC_AVGCTRL_SAMPLENUM_256_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 256 samples Position  */
#define ADC_AVGCTRL_SAMPLENUM_512             (ADC_AVGCTRL_SAMPLENUM_512_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 512 samples Position  */
#define ADC_AVGCTRL_SAMPLENUM_1024            (ADC_AVGCTRL_SAMPLENUM_1024_Val << ADC_AVGCTRL_SAMPLENUM_Pos) /* (ADC_AVGCTRL) 1024 samples Position  */
#define ADC_AVGCTRL_ADJRES_Pos                _UINT8_(4)                                           /* (ADC_AVGCTRL) Adjusting Result / Division Coefficient Position */
#define ADC_AVGCTRL_ADJRES_Msk                (_UINT8_(0x7) << ADC_AVGCTRL_ADJRES_Pos)             /* (ADC_AVGCTRL) Adjusting Result / Division Coefficient Mask */
#define ADC_AVGCTRL_ADJRES(value)             (ADC_AVGCTRL_ADJRES_Msk & (_UINT8_(value) << ADC_AVGCTRL_ADJRES_Pos)) /* Assigment of value for ADJRES in the ADC_AVGCTRL register */
#define ADC_AVGCTRL_Msk                       _UINT8_(0x7F)                                        /* (ADC_AVGCTRL) Register Mask  */


/* -------- ADC_SAMPCTRL : (ADC Offset: 0x0D) (R/W 8) Sample Time Control -------- */
#define ADC_SAMPCTRL_RESETVALUE               _UINT8_(0x00)                                        /*  (ADC_SAMPCTRL) Sample Time Control  Reset Value */

#define ADC_SAMPCTRL_SAMPLEN_Pos              _UINT8_(0)                                           /* (ADC_SAMPCTRL) Sampling Time Length Position */
#define ADC_SAMPCTRL_SAMPLEN_Msk              (_UINT8_(0x3F) << ADC_SAMPCTRL_SAMPLEN_Pos)          /* (ADC_SAMPCTRL) Sampling Time Length Mask */
#define ADC_SAMPCTRL_SAMPLEN(value)           (ADC_SAMPCTRL_SAMPLEN_Msk & (_UINT8_(value) << ADC_SAMPCTRL_SAMPLEN_Pos)) /* Assigment of value for SAMPLEN in the ADC_SAMPCTRL register */
#define ADC_SAMPCTRL_OFFCOMP_Pos              _UINT8_(7)                                           /* (ADC_SAMPCTRL) Comparator Offset Compensation Enable Position */
#define ADC_SAMPCTRL_OFFCOMP_Msk              (_UINT8_(0x1) << ADC_SAMPCTRL_OFFCOMP_Pos)           /* (ADC_SAMPCTRL) Comparator Offset Compensation Enable Mask */
#define ADC_SAMPCTRL_OFFCOMP(value)           (ADC_SAMPCTRL_OFFCOMP_Msk & (_UINT8_(value) << ADC_SAMPCTRL_OFFCOMP_Pos)) /* Assigment of value for OFFCOMP in the ADC_SAMPCTRL register */
#define ADC_SAMPCTRL_Msk                      _UINT8_(0xBF)                                        /* (ADC_SAMPCTRL) Register Mask  */


/* -------- ADC_WINLT : (ADC Offset: 0x0E) (R/W 16) Window Monitor Lower Threshold -------- */
#define ADC_WINLT_RESETVALUE                  _UINT16_(0x00)                                       /*  (ADC_WINLT) Window Monitor Lower Threshold  Reset Value */

#define ADC_WINLT_WINLT_Pos                   _UINT16_(0)                                          /* (ADC_WINLT) Window Lower Threshold Position */
#define ADC_WINLT_WINLT_Msk                   (_UINT16_(0xFFFF) << ADC_WINLT_WINLT_Pos)            /* (ADC_WINLT) Window Lower Threshold Mask */
#define ADC_WINLT_WINLT(value)                (ADC_WINLT_WINLT_Msk & (_UINT16_(value) << ADC_WINLT_WINLT_Pos)) /* Assigment of value for WINLT in the ADC_WINLT register */
#define ADC_WINLT_Msk                         _UINT16_(0xFFFF)                                     /* (ADC_WINLT) Register Mask  */


/* -------- ADC_WINUT : (ADC Offset: 0x10) (R/W 16) Window Monitor Upper Threshold -------- */
#define ADC_WINUT_RESETVALUE                  _UINT16_(0x00)                                       /*  (ADC_WINUT) Window Monitor Upper Threshold  Reset Value */

#define ADC_WINUT_WINUT_Pos                   _UINT16_(0)                                          /* (ADC_WINUT) Window Upper Threshold Position */
#define ADC_WINUT_WINUT_Msk                   (_UINT16_(0xFFFF) << ADC_WINUT_WINUT_Pos)            /* (ADC_WINUT) Window Upper Threshold Mask */
#define ADC_WINUT_WINUT(value)                (ADC_WINUT_WINUT_Msk & (_UINT16_(value) << ADC_WINUT_WINUT_Pos)) /* Assigment of value for WINUT in the ADC_WINUT register */
#define ADC_WINUT_Msk                         _UINT16_(0xFFFF)                                     /* (ADC_WINUT) Register Mask  */


/* -------- ADC_GAINCORR : (ADC Offset: 0x12) (R/W 16) Gain Correction -------- */
#define ADC_GAINCORR_RESETVALUE               _UINT16_(0x00)                                       /*  (ADC_GAINCORR) Gain Correction  Reset Value */

#define ADC_GAINCORR_GAINCORR_Pos             _UINT16_(0)                                          /* (ADC_GAINCORR) Gain Correction Value Position */
#define ADC_GAINCORR_GAINCORR_Msk             (_UINT16_(0xFFF) << ADC_GAINCORR_GAINCORR_Pos)       /* (ADC_GAINCORR) Gain Correction Value Mask */
#define ADC_GAINCORR_GAINCORR(value)          (ADC_GAINCORR_GAINCORR_Msk & (_UINT16_(value) << ADC_GAINCORR_GAINCORR_Pos)) /* Assigment of value for GAINCORR in the ADC_GAINCORR register */
#define ADC_GAINCORR_Msk                      _UINT16_(0x0FFF)                                     /* (ADC_GAINCORR) Register Mask  */


/* -------- ADC_OFFSETCORR : (ADC Offset: 0x14) (R/W 16) Offset Correction -------- */
#define ADC_OFFSETCORR_RESETVALUE             _UINT16_(0x00)                                       /*  (ADC_OFFSETCORR) Offset Correction  Reset Value */

#define ADC_OFFSETCORR_OFFSETCORR_Pos         _UINT16_(0)                                          /* (ADC_OFFSETCORR) Offset Correction Value Position */
#define ADC_OFFSETCORR_OFFSETCORR_Msk         (_UINT16_(0xFFF) << ADC_OFFSETCORR_OFFSETCORR_Pos)   /* (ADC_OFFSETCORR) Offset Correction Value Mask */
#define ADC_OFFSETCORR_OFFSETCORR(value)      (ADC_OFFSETCORR_OFFSETCORR_Msk & (_UINT16_(value) << ADC_OFFSETCORR_OFFSETCORR_Pos)) /* Assigment of value for OFFSETCORR in the ADC_OFFSETCORR register */
#define ADC_OFFSETCORR_Msk                    _UINT16_(0x0FFF)                                     /* (ADC_OFFSETCORR) Register Mask  */


/* -------- ADC_SWTRIG : (ADC Offset: 0x18) (R/W 8) Software Trigger -------- */
#define ADC_SWTRIG_RESETVALUE                 _UINT8_(0x00)                                        /*  (ADC_SWTRIG) Software Trigger  Reset Value */

#define ADC_SWTRIG_FLUSH_Pos                  _UINT8_(0)                                           /* (ADC_SWTRIG) ADC Flush Position */
#define ADC_SWTRIG_FLUSH_Msk                  (_UINT8_(0x1) << ADC_SWTRIG_FLUSH_Pos)               /* (ADC_SWTRIG) ADC Flush Mask */
#define ADC_SWTRIG_FLUSH(value)               (ADC_SWTRIG_FLUSH_Msk & (_UINT8_(value) << ADC_SWTRIG_FLUSH_Pos)) /* Assigment of value for FLUSH in the ADC_SWTRIG register */
#define ADC_SWTRIG_START_Pos                  _UINT8_(1)                                           /* (ADC_SWTRIG) Start ADC Conversion Position */
#define ADC_SWTRIG_START_Msk                  (_UINT8_(0x1) << ADC_SWTRIG_START_Pos)               /* (ADC_SWTRIG) Start ADC Conversion Mask */
#define ADC_SWTRIG_START(value)               (ADC_SWTRIG_START_Msk & (_UINT8_(value) << ADC_SWTRIG_START_Pos)) /* Assigment of value for START in the ADC_SWTRIG register */
#define ADC_SWTRIG_Msk                        _UINT8_(0x03)                                        /* (ADC_SWTRIG) Register Mask  */


/* -------- ADC_DBGCTRL : (ADC Offset: 0x1C) (R/W 8) Debug Control -------- */
#define ADC_DBGCTRL_RESETVALUE                _UINT8_(0x00)                                        /*  (ADC_DBGCTRL) Debug Control  Reset Value */

#define ADC_DBGCTRL_DBGRUN_Pos                _UINT8_(0)                                           /* (ADC_DBGCTRL) Debug Run Position */
#define ADC_DBGCTRL_DBGRUN_Msk                (_UINT8_(0x1) << ADC_DBGCTRL_DBGRUN_Pos)             /* (ADC_DBGCTRL) Debug Run Mask */
#define ADC_DBGCTRL_DBGRUN(value)             (ADC_DBGCTRL_DBGRUN_Msk & (_UINT8_(value) << ADC_DBGCTRL_DBGRUN_Pos)) /* Assigment of value for DBGRUN in the ADC_DBGCTRL register */
#define ADC_DBGCTRL_Msk                       _UINT8_(0x01)                                        /* (ADC_DBGCTRL) Register Mask  */


/* -------- ADC_SYNCBUSY : (ADC Offset: 0x20) ( R/ 16) Synchronization Busy -------- */
#define ADC_SYNCBUSY_RESETVALUE               _UINT16_(0x00)                                       /*  (ADC_SYNCBUSY) Synchronization Busy  Reset Value */

#define ADC_SYNCBUSY_SWRST_Pos                _UINT16_(0)                                          /* (ADC_SYNCBUSY) SWRST Synchronization Busy Position */
#define ADC_SYNCBUSY_SWRST_Msk                (_UINT16_(0x1) << ADC_SYNCBUSY_SWRST_Pos)            /* (ADC_SYNCBUSY) SWRST Synchronization Busy Mask */
#define ADC_SYNCBUSY_SWRST(value)             (ADC_SYNCBUSY_SWRST_Msk & (_UINT16_(value) << ADC_SYNCBUSY_SWRST_Pos)) /* Assigment of value for SWRST in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_ENABLE_Pos               _UINT16_(1)                                          /* (ADC_SYNCBUSY) ENABLE Synchronization Busy Position */
#define ADC_SYNCBUSY_ENABLE_Msk               (_UINT16_(0x1) << ADC_SYNCBUSY_ENABLE_Pos)           /* (ADC_SYNCBUSY) ENABLE Synchronization Busy Mask */
#define ADC_SYNCBUSY_ENABLE(value)            (ADC_SYNCBUSY_ENABLE_Msk & (_UINT16_(value) << ADC_SYNCBUSY_ENABLE_Pos)) /* Assigment of value for ENABLE in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_INPUTCTRL_Pos            _UINT16_(2)                                          /* (ADC_SYNCBUSY) INPUTCTRL Synchronization Busy Position */
#define ADC_SYNCBUSY_INPUTCTRL_Msk            (_UINT16_(0x1) << ADC_SYNCBUSY_INPUTCTRL_Pos)        /* (ADC_SYNCBUSY) INPUTCTRL Synchronization Busy Mask */
#define ADC_SYNCBUSY_INPUTCTRL(value)         (ADC_SYNCBUSY_INPUTCTRL_Msk & (_UINT16_(value) << ADC_SYNCBUSY_INPUTCTRL_Pos)) /* Assigment of value for INPUTCTRL in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_CTRLC_Pos                _UINT16_(3)                                          /* (ADC_SYNCBUSY) CTRLC Synchronization Busy Position */
#define ADC_SYNCBUSY_CTRLC_Msk                (_UINT16_(0x1) << ADC_SYNCBUSY_CTRLC_Pos)            /* (ADC_SYNCBUSY) CTRLC Synchronization Busy Mask */
#define ADC_SYNCBUSY_CTRLC(value)             (ADC_SYNCBUSY_CTRLC_Msk & (_UINT16_(value) << ADC_SYNCBUSY_CTRLC_Pos)) /* Assigment of value for CTRLC in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_AVGCTRL_Pos              _UINT16_(4)                                          /* (ADC_SYNCBUSY) AVGCTRL Synchronization Busy Position */
#define ADC_SYNCBUSY_AVGCTRL_Msk              (_UINT16_(0x1) << ADC_SYNCBUSY_AVGCTRL_Pos)          /* (ADC_SYNCBUSY) AVGCTRL Synchronization Busy Mask */
#define ADC_SYNCBUSY_AVGCTRL(value)           (ADC_SYNCBUSY_AVGCTRL_Msk & (_UINT16_(value) << ADC_SYNCBUSY_AVGCTRL_Pos)) /* Assigment of value for AVGCTRL in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_SAMPCTRL_Pos             _UINT16_(5)                                          /* (ADC_SYNCBUSY) SAMPCTRL Synchronization Busy Position */
#define ADC_SYNCBUSY_SAMPCTRL_Msk             (_UINT16_(0x1) << ADC_SYNCBUSY_SAMPCTRL_Pos)         /* (ADC_SYNCBUSY) SAMPCTRL Synchronization Busy Mask */
#define ADC_SYNCBUSY_SAMPCTRL(value)          (ADC_SYNCBUSY_SAMPCTRL_Msk & (_UINT16_(value) << ADC_SYNCBUSY_SAMPCTRL_Pos)) /* Assigment of value for SAMPCTRL in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_WINLT_Pos                _UINT16_(6)                                          /* (ADC_SYNCBUSY) WINLT Synchronization Busy Position */
#define ADC_SYNCBUSY_WINLT_Msk                (_UINT16_(0x1) << ADC_SYNCBUSY_WINLT_Pos)            /* (ADC_SYNCBUSY) WINLT Synchronization Busy Mask */
#define ADC_SYNCBUSY_WINLT(value)             (ADC_SYNCBUSY_WINLT_Msk & (_UINT16_(value) << ADC_SYNCBUSY_WINLT_Pos)) /* Assigment of value for WINLT in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_WINUT_Pos                _UINT16_(7)                                          /* (ADC_SYNCBUSY) WINUT Synchronization Busy Position */
#define ADC_SYNCBUSY_WINUT_Msk                (_UINT16_(0x1) << ADC_SYNCBUSY_WINUT_Pos)            /* (ADC_SYNCBUSY) WINUT Synchronization Busy Mask */
#define ADC_SYNCBUSY_WINUT(value)             (ADC_SYNCBUSY_WINUT_Msk & (_UINT16_(value) << ADC_SYNCBUSY_WINUT_Pos)) /* Assigment of value for WINUT in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_GAINCORR_Pos             _UINT16_(8)                                          /* (ADC_SYNCBUSY) GAINCORR Synchronization Busy Position */
#define ADC_SYNCBUSY_GAINCORR_Msk             (_UINT16_(0x1) << ADC_SYNCBUSY_GAINCORR_Pos)         /* (ADC_SYNCBUSY) GAINCORR Synchronization Busy Mask */
#define ADC_SYNCBUSY_GAINCORR(value)          (ADC_SYNCBUSY_GAINCORR_Msk & (_UINT16_(value) << ADC_SYNCBUSY_GAINCORR_Pos)) /* Assigment of value for GAINCORR in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_OFFSETCORR_Pos           _UINT16_(9)                                          /* (ADC_SYNCBUSY) OFFSETCTRL Synchronization Busy Position */
#define ADC_SYNCBUSY_OFFSETCORR_Msk           (_UINT16_(0x1) << ADC_SYNCBUSY_OFFSETCORR_Pos)       /* (ADC_SYNCBUSY) OFFSETCTRL Synchronization Busy Mask */
#define ADC_SYNCBUSY_OFFSETCORR(value)        (ADC_SYNCBUSY_OFFSETCORR_Msk & (_UINT16_(value) << ADC_SYNCBUSY_OFFSETCORR_Pos)) /* Assigment of value for OFFSETCORR in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_SWTRIG_Pos               _UINT16_(10)                                         /* (ADC_SYNCBUSY) SWTRG Synchronization Busy Position */
#define ADC_SYNCBUSY_SWTRIG_Msk               (_UINT16_(0x1) << ADC_SYNCBUSY_SWTRIG_Pos)           /* (ADC_SYNCBUSY) SWTRG Synchronization Busy Mask */
#define ADC_SYNCBUSY_SWTRIG(value)            (ADC_SYNCBUSY_SWTRIG_Msk & (_UINT16_(value) << ADC_SYNCBUSY_SWTRIG_Pos)) /* Assigment of value for SWTRIG in the ADC_SYNCBUSY register */
#define ADC_SYNCBUSY_Msk                      _UINT16_(0x07FF)                                     /* (ADC_SYNCBUSY) Register Mask  */


/* -------- ADC_RESULT : (ADC Offset: 0x24) ( R/ 16) Result -------- */
#define ADC_RESULT_RESETVALUE                 _UINT16_(0x00)                                       /*  (ADC_RESULT) Result  Reset Value */

#define ADC_RESULT_RESULT_Pos                 _UINT16_(0)                                          /* (ADC_RESULT) Result Value Position */
#define ADC_RESULT_RESULT_Msk                 (_UINT16_(0xFFFF) << ADC_RESULT_RESULT_Pos)          /* (ADC_RESULT) Result Value Mask */
#define ADC_RESULT_RESULT(value)              (ADC_RESULT_RESULT_Msk & (_UINT16_(value) << ADC_RESULT_RESULT_Pos)) /* Assigment of value for RESULT in the ADC_RESULT register */
#define ADC_RESULT_Msk                        _UINT16_(0xFFFF)                                     /* (ADC_RESULT) Register Mask  */


/* -------- ADC_SEQCTRL : (ADC Offset: 0x28) (R/W 32) Sequence Control -------- */
#define ADC_SEQCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (ADC_SEQCTRL) Sequence Control  Reset Value */

#define ADC_SEQCTRL_SEQEN_Pos                 _UINT32_(0)                                          /* (ADC_SEQCTRL) Enable Positive Input in the Sequence Position */
#define ADC_SEQCTRL_SEQEN_Msk                 (_UINT32_(0xFFFFFFFF) << ADC_SEQCTRL_SEQEN_Pos)      /* (ADC_SEQCTRL) Enable Positive Input in the Sequence Mask */
#define ADC_SEQCTRL_SEQEN(value)              (ADC_SEQCTRL_SEQEN_Msk & (_UINT32_(value) << ADC_SEQCTRL_SEQEN_Pos)) /* Assigment of value for SEQEN in the ADC_SEQCTRL register */
#define ADC_SEQCTRL_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (ADC_SEQCTRL) Register Mask  */


/* -------- ADC_CALIB : (ADC Offset: 0x2C) (R/W 16) Calibration -------- */
#define ADC_CALIB_RESETVALUE                  _UINT16_(0x00)                                       /*  (ADC_CALIB) Calibration  Reset Value */

#define ADC_CALIB_BIASCOMP_Pos                _UINT16_(0)                                          /* (ADC_CALIB) Bias Comparator Scaling Position */
#define ADC_CALIB_BIASCOMP_Msk                (_UINT16_(0x7) << ADC_CALIB_BIASCOMP_Pos)            /* (ADC_CALIB) Bias Comparator Scaling Mask */
#define ADC_CALIB_BIASCOMP(value)             (ADC_CALIB_BIASCOMP_Msk & (_UINT16_(value) << ADC_CALIB_BIASCOMP_Pos)) /* Assigment of value for BIASCOMP in the ADC_CALIB register */
#define ADC_CALIB_BIASREFBUF_Pos              _UINT16_(8)                                          /* (ADC_CALIB) Bias Reference Buffer Scaling Position */
#define ADC_CALIB_BIASREFBUF_Msk              (_UINT16_(0x7) << ADC_CALIB_BIASREFBUF_Pos)          /* (ADC_CALIB) Bias Reference Buffer Scaling Mask */
#define ADC_CALIB_BIASREFBUF(value)           (ADC_CALIB_BIASREFBUF_Msk & (_UINT16_(value) << ADC_CALIB_BIASREFBUF_Pos)) /* Assigment of value for BIASREFBUF in the ADC_CALIB register */
#define ADC_CALIB_Msk                         _UINT16_(0x0707)                                     /* (ADC_CALIB) Register Mask  */


/** \brief ADC register offsets definitions */
#define ADC_CTRLA_REG_OFST             _UINT32_(0x00)      /* (ADC_CTRLA) Control A Offset */
#define ADC_CTRLB_REG_OFST             _UINT32_(0x01)      /* (ADC_CTRLB) Control B Offset */
#define ADC_REFCTRL_REG_OFST           _UINT32_(0x02)      /* (ADC_REFCTRL) Reference Control Offset */
#define ADC_EVCTRL_REG_OFST            _UINT32_(0x03)      /* (ADC_EVCTRL) Event Control Offset */
#define ADC_INTENCLR_REG_OFST          _UINT32_(0x04)      /* (ADC_INTENCLR) Interrupt Enable Clear Offset */
#define ADC_INTENSET_REG_OFST          _UINT32_(0x05)      /* (ADC_INTENSET) Interrupt Enable Set Offset */
#define ADC_INTFLAG_REG_OFST           _UINT32_(0x06)      /* (ADC_INTFLAG) Interrupt Flag Status and Clear Offset */
#define ADC_SEQSTATUS_REG_OFST         _UINT32_(0x07)      /* (ADC_SEQSTATUS) Sequence Status Offset */
#define ADC_INPUTCTRL_REG_OFST         _UINT32_(0x08)      /* (ADC_INPUTCTRL) Input Control Offset */
#define ADC_CTRLC_REG_OFST             _UINT32_(0x0A)      /* (ADC_CTRLC) Control C Offset */
#define ADC_AVGCTRL_REG_OFST           _UINT32_(0x0C)      /* (ADC_AVGCTRL) Average Control Offset */
#define ADC_SAMPCTRL_REG_OFST          _UINT32_(0x0D)      /* (ADC_SAMPCTRL) Sample Time Control Offset */
#define ADC_WINLT_REG_OFST             _UINT32_(0x0E)      /* (ADC_WINLT) Window Monitor Lower Threshold Offset */
#define ADC_WINUT_REG_OFST             _UINT32_(0x10)      /* (ADC_WINUT) Window Monitor Upper Threshold Offset */
#define ADC_GAINCORR_REG_OFST          _UINT32_(0x12)      /* (ADC_GAINCORR) Gain Correction Offset */
#define ADC_OFFSETCORR_REG_OFST        _UINT32_(0x14)      /* (ADC_OFFSETCORR) Offset Correction Offset */
#define ADC_SWTRIG_REG_OFST            _UINT32_(0x18)      /* (ADC_SWTRIG) Software Trigger Offset */
#define ADC_DBGCTRL_REG_OFST           _UINT32_(0x1C)      /* (ADC_DBGCTRL) Debug Control Offset */
#define ADC_SYNCBUSY_REG_OFST          _UINT32_(0x20)      /* (ADC_SYNCBUSY) Synchronization Busy Offset */
#define ADC_RESULT_REG_OFST            _UINT32_(0x24)      /* (ADC_RESULT) Result Offset */
#define ADC_SEQCTRL_REG_OFST           _UINT32_(0x28)      /* (ADC_SEQCTRL) Sequence Control Offset */
#define ADC_CALIB_REG_OFST             _UINT32_(0x2C)      /* (ADC_CALIB) Calibration Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief ADC register API structure */
typedef struct
{  /* Analog Digital Converter */
  __IO  uint8_t                        ADC_CTRLA;          /**< Offset: 0x00 (R/W  8) Control A */
  __IO  uint8_t                        ADC_CTRLB;          /**< Offset: 0x01 (R/W  8) Control B */
  __IO  uint8_t                        ADC_REFCTRL;        /**< Offset: 0x02 (R/W  8) Reference Control */
  __IO  uint8_t                        ADC_EVCTRL;         /**< Offset: 0x03 (R/W  8) Event Control */
  __IO  uint8_t                        ADC_INTENCLR;       /**< Offset: 0x04 (R/W  8) Interrupt Enable Clear */
  __IO  uint8_t                        ADC_INTENSET;       /**< Offset: 0x05 (R/W  8) Interrupt Enable Set */
  __IO  uint8_t                        ADC_INTFLAG;        /**< Offset: 0x06 (R/W  8) Interrupt Flag Status and Clear */
  __I   uint8_t                        ADC_SEQSTATUS;      /**< Offset: 0x07 (R/   8) Sequence Status */
  __IO  uint16_t                       ADC_INPUTCTRL;      /**< Offset: 0x08 (R/W  16) Input Control */
  __IO  uint16_t                       ADC_CTRLC;          /**< Offset: 0x0A (R/W  16) Control C */
  __IO  uint8_t                        ADC_AVGCTRL;        /**< Offset: 0x0C (R/W  8) Average Control */
  __IO  uint8_t                        ADC_SAMPCTRL;       /**< Offset: 0x0D (R/W  8) Sample Time Control */
  __IO  uint16_t                       ADC_WINLT;          /**< Offset: 0x0E (R/W  16) Window Monitor Lower Threshold */
  __IO  uint16_t                       ADC_WINUT;          /**< Offset: 0x10 (R/W  16) Window Monitor Upper Threshold */
  __IO  uint16_t                       ADC_GAINCORR;       /**< Offset: 0x12 (R/W  16) Gain Correction */
  __IO  uint16_t                       ADC_OFFSETCORR;     /**< Offset: 0x14 (R/W  16) Offset Correction */
  __I   uint8_t                        Reserved1[0x02];
  __IO  uint8_t                        ADC_SWTRIG;         /**< Offset: 0x18 (R/W  8) Software Trigger */
  __I   uint8_t                        Reserved2[0x03];
  __IO  uint8_t                        ADC_DBGCTRL;        /**< Offset: 0x1C (R/W  8) Debug Control */
  __I   uint8_t                        Reserved3[0x03];
  __I   uint16_t                       ADC_SYNCBUSY;       /**< Offset: 0x20 (R/   16) Synchronization Busy */
  __I   uint8_t                        Reserved4[0x02];
  __I   uint16_t                       ADC_RESULT;         /**< Offset: 0x24 (R/   16) Result */
  __I   uint8_t                        Reserved5[0x02];
  __IO  uint32_t                       ADC_SEQCTRL;        /**< Offset: 0x28 (R/W  32) Sequence Control */
  __IO  uint16_t                       ADC_CALIB;          /**< Offset: 0x2C (R/W  16) Calibration */
} adc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMLS60_ADC_COMPONENT_H_ */
