/*
 * Component description for EVSYS
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
#ifndef _PIC32CMLS60_EVSYS_COMPONENT_H_
#define _PIC32CMLS60_EVSYS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR EVSYS                                        */
/* ************************************************************************** */

/* -------- EVSYS_CHANNEL : (EVSYS Offset: 0x00) (R/W 32) Channel n Control -------- */
#define EVSYS_CHANNEL_RESETVALUE              _UINT32_(0x8000)                                     /*  (EVSYS_CHANNEL) Channel n Control  Reset Value */

#define EVSYS_CHANNEL_EVGEN_Pos               _UINT32_(0)                                          /* (EVSYS_CHANNEL) Event Generator Selection Position */
#define EVSYS_CHANNEL_EVGEN_Msk               (_UINT32_(0x7F) << EVSYS_CHANNEL_EVGEN_Pos)          /* (EVSYS_CHANNEL) Event Generator Selection Mask */
#define EVSYS_CHANNEL_EVGEN(value)            (EVSYS_CHANNEL_EVGEN_Msk & (_UINT32_(value) << EVSYS_CHANNEL_EVGEN_Pos)) /* Assigment of value for EVGEN in the EVSYS_CHANNEL register */
#define EVSYS_CHANNEL_PATH_Pos                _UINT32_(8)                                          /* (EVSYS_CHANNEL) Path Selection Position */
#define EVSYS_CHANNEL_PATH_Msk                (_UINT32_(0x3) << EVSYS_CHANNEL_PATH_Pos)            /* (EVSYS_CHANNEL) Path Selection Mask */
#define EVSYS_CHANNEL_PATH(value)             (EVSYS_CHANNEL_PATH_Msk & (_UINT32_(value) << EVSYS_CHANNEL_PATH_Pos)) /* Assigment of value for PATH in the EVSYS_CHANNEL register */
#define   EVSYS_CHANNEL_PATH_SYNCHRONOUS_Val  _UINT32_(0x0)                                        /* (EVSYS_CHANNEL) Synchronous path  */
#define   EVSYS_CHANNEL_PATH_RESYNCHRONIZED_Val _UINT32_(0x1)                                        /* (EVSYS_CHANNEL) Resynchronized path  */
#define   EVSYS_CHANNEL_PATH_ASYNCHRONOUS_Val _UINT32_(0x2)                                        /* (EVSYS_CHANNEL) Asynchronous path  */
#define EVSYS_CHANNEL_PATH_SYNCHRONOUS        (EVSYS_CHANNEL_PATH_SYNCHRONOUS_Val << EVSYS_CHANNEL_PATH_Pos) /* (EVSYS_CHANNEL) Synchronous path Position  */
#define EVSYS_CHANNEL_PATH_RESYNCHRONIZED     (EVSYS_CHANNEL_PATH_RESYNCHRONIZED_Val << EVSYS_CHANNEL_PATH_Pos) /* (EVSYS_CHANNEL) Resynchronized path Position  */
#define EVSYS_CHANNEL_PATH_ASYNCHRONOUS       (EVSYS_CHANNEL_PATH_ASYNCHRONOUS_Val << EVSYS_CHANNEL_PATH_Pos) /* (EVSYS_CHANNEL) Asynchronous path Position  */
#define EVSYS_CHANNEL_EDGSEL_Pos              _UINT32_(10)                                         /* (EVSYS_CHANNEL) Edge Detection Selection Position */
#define EVSYS_CHANNEL_EDGSEL_Msk              (_UINT32_(0x3) << EVSYS_CHANNEL_EDGSEL_Pos)          /* (EVSYS_CHANNEL) Edge Detection Selection Mask */
#define EVSYS_CHANNEL_EDGSEL(value)           (EVSYS_CHANNEL_EDGSEL_Msk & (_UINT32_(value) << EVSYS_CHANNEL_EDGSEL_Pos)) /* Assigment of value for EDGSEL in the EVSYS_CHANNEL register */
#define   EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT_Val _UINT32_(0x0)                                        /* (EVSYS_CHANNEL) No event output when using the resynchronized or synchronous path  */
#define   EVSYS_CHANNEL_EDGSEL_RISING_EDGE_Val _UINT32_(0x1)                                        /* (EVSYS_CHANNEL) Event detection only on the rising edge of the signal from the event generator when using the resynchronized or synchronous path  */
#define   EVSYS_CHANNEL_EDGSEL_FALLING_EDGE_Val _UINT32_(0x2)                                        /* (EVSYS_CHANNEL) Event detection only on the falling edge of the signal from the event generator when using the resynchronized or synchronous path  */
#define   EVSYS_CHANNEL_EDGSEL_BOTH_EDGES_Val _UINT32_(0x3)                                        /* (EVSYS_CHANNEL) Event detection on rising and falling edges of the signal from the event generator when using the resynchronized or synchronous path  */
#define EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT    (EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT_Val << EVSYS_CHANNEL_EDGSEL_Pos) /* (EVSYS_CHANNEL) No event output when using the resynchronized or synchronous path Position  */
#define EVSYS_CHANNEL_EDGSEL_RISING_EDGE      (EVSYS_CHANNEL_EDGSEL_RISING_EDGE_Val << EVSYS_CHANNEL_EDGSEL_Pos) /* (EVSYS_CHANNEL) Event detection only on the rising edge of the signal from the event generator when using the resynchronized or synchronous path Position  */
#define EVSYS_CHANNEL_EDGSEL_FALLING_EDGE     (EVSYS_CHANNEL_EDGSEL_FALLING_EDGE_Val << EVSYS_CHANNEL_EDGSEL_Pos) /* (EVSYS_CHANNEL) Event detection only on the falling edge of the signal from the event generator when using the resynchronized or synchronous path Position  */
#define EVSYS_CHANNEL_EDGSEL_BOTH_EDGES       (EVSYS_CHANNEL_EDGSEL_BOTH_EDGES_Val << EVSYS_CHANNEL_EDGSEL_Pos) /* (EVSYS_CHANNEL) Event detection on rising and falling edges of the signal from the event generator when using the resynchronized or synchronous path Position  */
#define EVSYS_CHANNEL_RUNSTDBY_Pos            _UINT32_(14)                                         /* (EVSYS_CHANNEL) Run in standby Position */
#define EVSYS_CHANNEL_RUNSTDBY_Msk            (_UINT32_(0x1) << EVSYS_CHANNEL_RUNSTDBY_Pos)        /* (EVSYS_CHANNEL) Run in standby Mask */
#define EVSYS_CHANNEL_RUNSTDBY(value)         (EVSYS_CHANNEL_RUNSTDBY_Msk & (_UINT32_(value) << EVSYS_CHANNEL_RUNSTDBY_Pos)) /* Assigment of value for RUNSTDBY in the EVSYS_CHANNEL register */
#define EVSYS_CHANNEL_ONDEMAND_Pos            _UINT32_(15)                                         /* (EVSYS_CHANNEL) Generic Clock On Demand Position */
#define EVSYS_CHANNEL_ONDEMAND_Msk            (_UINT32_(0x1) << EVSYS_CHANNEL_ONDEMAND_Pos)        /* (EVSYS_CHANNEL) Generic Clock On Demand Mask */
#define EVSYS_CHANNEL_ONDEMAND(value)         (EVSYS_CHANNEL_ONDEMAND_Msk & (_UINT32_(value) << EVSYS_CHANNEL_ONDEMAND_Pos)) /* Assigment of value for ONDEMAND in the EVSYS_CHANNEL register */
#define EVSYS_CHANNEL_Msk                     _UINT32_(0x0000CF7F)                                 /* (EVSYS_CHANNEL) Register Mask  */


/* -------- EVSYS_CHINTENCLR : (EVSYS Offset: 0x04) (R/W 8) Channel n Interrupt Enable Clear -------- */
#define EVSYS_CHINTENCLR_RESETVALUE           _UINT8_(0x00)                                        /*  (EVSYS_CHINTENCLR) Channel n Interrupt Enable Clear  Reset Value */

#define EVSYS_CHINTENCLR_OVR_Pos              _UINT8_(0)                                           /* (EVSYS_CHINTENCLR) Channel Overrun Interrupt Disable Position */
#define EVSYS_CHINTENCLR_OVR_Msk              (_UINT8_(0x1) << EVSYS_CHINTENCLR_OVR_Pos)           /* (EVSYS_CHINTENCLR) Channel Overrun Interrupt Disable Mask */
#define EVSYS_CHINTENCLR_OVR(value)           (EVSYS_CHINTENCLR_OVR_Msk & (_UINT8_(value) << EVSYS_CHINTENCLR_OVR_Pos)) /* Assigment of value for OVR in the EVSYS_CHINTENCLR register */
#define EVSYS_CHINTENCLR_EVD_Pos              _UINT8_(1)                                           /* (EVSYS_CHINTENCLR) Channel Event Detected Interrupt Disable Position */
#define EVSYS_CHINTENCLR_EVD_Msk              (_UINT8_(0x1) << EVSYS_CHINTENCLR_EVD_Pos)           /* (EVSYS_CHINTENCLR) Channel Event Detected Interrupt Disable Mask */
#define EVSYS_CHINTENCLR_EVD(value)           (EVSYS_CHINTENCLR_EVD_Msk & (_UINT8_(value) << EVSYS_CHINTENCLR_EVD_Pos)) /* Assigment of value for EVD in the EVSYS_CHINTENCLR register */
#define EVSYS_CHINTENCLR_Msk                  _UINT8_(0x03)                                        /* (EVSYS_CHINTENCLR) Register Mask  */


/* -------- EVSYS_CHINTENSET : (EVSYS Offset: 0x05) (R/W 8) Channel n Interrupt Enable Set -------- */
#define EVSYS_CHINTENSET_RESETVALUE           _UINT8_(0x00)                                        /*  (EVSYS_CHINTENSET) Channel n Interrupt Enable Set  Reset Value */

#define EVSYS_CHINTENSET_OVR_Pos              _UINT8_(0)                                           /* (EVSYS_CHINTENSET) Channel Overrun Interrupt Enable Position */
#define EVSYS_CHINTENSET_OVR_Msk              (_UINT8_(0x1) << EVSYS_CHINTENSET_OVR_Pos)           /* (EVSYS_CHINTENSET) Channel Overrun Interrupt Enable Mask */
#define EVSYS_CHINTENSET_OVR(value)           (EVSYS_CHINTENSET_OVR_Msk & (_UINT8_(value) << EVSYS_CHINTENSET_OVR_Pos)) /* Assigment of value for OVR in the EVSYS_CHINTENSET register */
#define EVSYS_CHINTENSET_EVD_Pos              _UINT8_(1)                                           /* (EVSYS_CHINTENSET) Channel Event Detected Interrupt Enable Position */
#define EVSYS_CHINTENSET_EVD_Msk              (_UINT8_(0x1) << EVSYS_CHINTENSET_EVD_Pos)           /* (EVSYS_CHINTENSET) Channel Event Detected Interrupt Enable Mask */
#define EVSYS_CHINTENSET_EVD(value)           (EVSYS_CHINTENSET_EVD_Msk & (_UINT8_(value) << EVSYS_CHINTENSET_EVD_Pos)) /* Assigment of value for EVD in the EVSYS_CHINTENSET register */
#define EVSYS_CHINTENSET_Msk                  _UINT8_(0x03)                                        /* (EVSYS_CHINTENSET) Register Mask  */


/* -------- EVSYS_CHINTFLAG : (EVSYS Offset: 0x06) (R/W 8) Channel n Interrupt Flag Status and Clear -------- */
#define EVSYS_CHINTFLAG_RESETVALUE            _UINT8_(0x00)                                        /*  (EVSYS_CHINTFLAG) Channel n Interrupt Flag Status and Clear  Reset Value */

#define EVSYS_CHINTFLAG_OVR_Pos               _UINT8_(0)                                           /* (EVSYS_CHINTFLAG) Channel Overrun Position */
#define EVSYS_CHINTFLAG_OVR_Msk               (_UINT8_(0x1) << EVSYS_CHINTFLAG_OVR_Pos)            /* (EVSYS_CHINTFLAG) Channel Overrun Mask */
#define EVSYS_CHINTFLAG_OVR(value)            (EVSYS_CHINTFLAG_OVR_Msk & (_UINT8_(value) << EVSYS_CHINTFLAG_OVR_Pos)) /* Assigment of value for OVR in the EVSYS_CHINTFLAG register */
#define EVSYS_CHINTFLAG_EVD_Pos               _UINT8_(1)                                           /* (EVSYS_CHINTFLAG) Channel Event Detected Position */
#define EVSYS_CHINTFLAG_EVD_Msk               (_UINT8_(0x1) << EVSYS_CHINTFLAG_EVD_Pos)            /* (EVSYS_CHINTFLAG) Channel Event Detected Mask */
#define EVSYS_CHINTFLAG_EVD(value)            (EVSYS_CHINTFLAG_EVD_Msk & (_UINT8_(value) << EVSYS_CHINTFLAG_EVD_Pos)) /* Assigment of value for EVD in the EVSYS_CHINTFLAG register */
#define EVSYS_CHINTFLAG_Msk                   _UINT8_(0x03)                                        /* (EVSYS_CHINTFLAG) Register Mask  */


/* -------- EVSYS_CHSTATUS : (EVSYS Offset: 0x07) ( R/ 8) Channel n Status -------- */
#define EVSYS_CHSTATUS_RESETVALUE             _UINT8_(0x01)                                        /*  (EVSYS_CHSTATUS) Channel n Status  Reset Value */

#define EVSYS_CHSTATUS_RDYUSR_Pos             _UINT8_(0)                                           /* (EVSYS_CHSTATUS) Ready User Position */
#define EVSYS_CHSTATUS_RDYUSR_Msk             (_UINT8_(0x1) << EVSYS_CHSTATUS_RDYUSR_Pos)          /* (EVSYS_CHSTATUS) Ready User Mask */
#define EVSYS_CHSTATUS_RDYUSR(value)          (EVSYS_CHSTATUS_RDYUSR_Msk & (_UINT8_(value) << EVSYS_CHSTATUS_RDYUSR_Pos)) /* Assigment of value for RDYUSR in the EVSYS_CHSTATUS register */
#define EVSYS_CHSTATUS_BUSYCH_Pos             _UINT8_(1)                                           /* (EVSYS_CHSTATUS) Busy Channel Position */
#define EVSYS_CHSTATUS_BUSYCH_Msk             (_UINT8_(0x1) << EVSYS_CHSTATUS_BUSYCH_Pos)          /* (EVSYS_CHSTATUS) Busy Channel Mask */
#define EVSYS_CHSTATUS_BUSYCH(value)          (EVSYS_CHSTATUS_BUSYCH_Msk & (_UINT8_(value) << EVSYS_CHSTATUS_BUSYCH_Pos)) /* Assigment of value for BUSYCH in the EVSYS_CHSTATUS register */
#define EVSYS_CHSTATUS_Msk                    _UINT8_(0x03)                                        /* (EVSYS_CHSTATUS) Register Mask  */


/* -------- EVSYS_CTRLA : (EVSYS Offset: 0x00) ( /W 8) Control -------- */
#define EVSYS_CTRLA_RESETVALUE                _UINT8_(0x00)                                        /*  (EVSYS_CTRLA) Control  Reset Value */

#define EVSYS_CTRLA_SWRST_Pos                 _UINT8_(0)                                           /* (EVSYS_CTRLA) Software Reset Position */
#define EVSYS_CTRLA_SWRST_Msk                 (_UINT8_(0x1) << EVSYS_CTRLA_SWRST_Pos)              /* (EVSYS_CTRLA) Software Reset Mask */
#define EVSYS_CTRLA_SWRST(value)              (EVSYS_CTRLA_SWRST_Msk & (_UINT8_(value) << EVSYS_CTRLA_SWRST_Pos)) /* Assigment of value for SWRST in the EVSYS_CTRLA register */
#define EVSYS_CTRLA_Msk                       _UINT8_(0x01)                                        /* (EVSYS_CTRLA) Register Mask  */


/* -------- EVSYS_SWEVT : (EVSYS Offset: 0x04) ( /W 32) Software Event -------- */
#define EVSYS_SWEVT_RESETVALUE                _UINT32_(0x00)                                       /*  (EVSYS_SWEVT) Software Event  Reset Value */

#define EVSYS_SWEVT_CHANNEL0_Pos              _UINT32_(0)                                          /* (EVSYS_SWEVT) Channel 0 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL0_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL0_Pos)          /* (EVSYS_SWEVT) Channel 0 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL0(value)           (EVSYS_SWEVT_CHANNEL0_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL0_Pos)) /* Assigment of value for CHANNEL0 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL1_Pos              _UINT32_(1)                                          /* (EVSYS_SWEVT) Channel 1 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL1_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL1_Pos)          /* (EVSYS_SWEVT) Channel 1 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL1(value)           (EVSYS_SWEVT_CHANNEL1_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL1_Pos)) /* Assigment of value for CHANNEL1 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL2_Pos              _UINT32_(2)                                          /* (EVSYS_SWEVT) Channel 2 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL2_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL2_Pos)          /* (EVSYS_SWEVT) Channel 2 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL2(value)           (EVSYS_SWEVT_CHANNEL2_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL2_Pos)) /* Assigment of value for CHANNEL2 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL3_Pos              _UINT32_(3)                                          /* (EVSYS_SWEVT) Channel 3 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL3_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL3_Pos)          /* (EVSYS_SWEVT) Channel 3 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL3(value)           (EVSYS_SWEVT_CHANNEL3_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL3_Pos)) /* Assigment of value for CHANNEL3 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL4_Pos              _UINT32_(4)                                          /* (EVSYS_SWEVT) Channel 4 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL4_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL4_Pos)          /* (EVSYS_SWEVT) Channel 4 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL4(value)           (EVSYS_SWEVT_CHANNEL4_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL4_Pos)) /* Assigment of value for CHANNEL4 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL5_Pos              _UINT32_(5)                                          /* (EVSYS_SWEVT) Channel 5 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL5_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL5_Pos)          /* (EVSYS_SWEVT) Channel 5 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL5(value)           (EVSYS_SWEVT_CHANNEL5_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL5_Pos)) /* Assigment of value for CHANNEL5 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL6_Pos              _UINT32_(6)                                          /* (EVSYS_SWEVT) Channel 6 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL6_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL6_Pos)          /* (EVSYS_SWEVT) Channel 6 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL6(value)           (EVSYS_SWEVT_CHANNEL6_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL6_Pos)) /* Assigment of value for CHANNEL6 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL7_Pos              _UINT32_(7)                                          /* (EVSYS_SWEVT) Channel 7 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL7_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL7_Pos)          /* (EVSYS_SWEVT) Channel 7 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL7(value)           (EVSYS_SWEVT_CHANNEL7_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL7_Pos)) /* Assigment of value for CHANNEL7 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL8_Pos              _UINT32_(8)                                          /* (EVSYS_SWEVT) Channel 8 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL8_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL8_Pos)          /* (EVSYS_SWEVT) Channel 8 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL8(value)           (EVSYS_SWEVT_CHANNEL8_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL8_Pos)) /* Assigment of value for CHANNEL8 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL9_Pos              _UINT32_(9)                                          /* (EVSYS_SWEVT) Channel 9 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL9_Msk              (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL9_Pos)          /* (EVSYS_SWEVT) Channel 9 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL9(value)           (EVSYS_SWEVT_CHANNEL9_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL9_Pos)) /* Assigment of value for CHANNEL9 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL10_Pos             _UINT32_(10)                                         /* (EVSYS_SWEVT) Channel 10 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL10_Msk             (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL10_Pos)         /* (EVSYS_SWEVT) Channel 10 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL10(value)          (EVSYS_SWEVT_CHANNEL10_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL10_Pos)) /* Assigment of value for CHANNEL10 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_CHANNEL11_Pos             _UINT32_(11)                                         /* (EVSYS_SWEVT) Channel 11 Software Selection Position */
#define EVSYS_SWEVT_CHANNEL11_Msk             (_UINT32_(0x1) << EVSYS_SWEVT_CHANNEL11_Pos)         /* (EVSYS_SWEVT) Channel 11 Software Selection Mask */
#define EVSYS_SWEVT_CHANNEL11(value)          (EVSYS_SWEVT_CHANNEL11_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL11_Pos)) /* Assigment of value for CHANNEL11 in the EVSYS_SWEVT register */
#define EVSYS_SWEVT_Msk                       _UINT32_(0x00000FFF)                                 /* (EVSYS_SWEVT) Register Mask  */

#define EVSYS_SWEVT_CHANNEL_Pos               _UINT32_(0)                                          /* (EVSYS_SWEVT Position) Channel xx Software Selection */
#define EVSYS_SWEVT_CHANNEL_Msk               (_UINT32_(0xFFF) << EVSYS_SWEVT_CHANNEL_Pos)         /* (EVSYS_SWEVT Mask) CHANNEL */
#define EVSYS_SWEVT_CHANNEL(value)            (EVSYS_SWEVT_CHANNEL_Msk & (_UINT32_(value) << EVSYS_SWEVT_CHANNEL_Pos)) 

/* -------- EVSYS_PRICTRL : (EVSYS Offset: 0x08) (R/W 8) Priority Control -------- */
#define EVSYS_PRICTRL_RESETVALUE              _UINT8_(0x00)                                        /*  (EVSYS_PRICTRL) Priority Control  Reset Value */

#define EVSYS_PRICTRL_PRI_Pos                 _UINT8_(0)                                           /* (EVSYS_PRICTRL) Channel Priority Number Position */
#define EVSYS_PRICTRL_PRI_Msk                 (_UINT8_(0x7) << EVSYS_PRICTRL_PRI_Pos)              /* (EVSYS_PRICTRL) Channel Priority Number Mask */
#define EVSYS_PRICTRL_PRI(value)              (EVSYS_PRICTRL_PRI_Msk & (_UINT8_(value) << EVSYS_PRICTRL_PRI_Pos)) /* Assigment of value for PRI in the EVSYS_PRICTRL register */
#define EVSYS_PRICTRL_RREN_Pos                _UINT8_(7)                                           /* (EVSYS_PRICTRL) Round-Robin Scheduling Enable Position */
#define EVSYS_PRICTRL_RREN_Msk                (_UINT8_(0x1) << EVSYS_PRICTRL_RREN_Pos)             /* (EVSYS_PRICTRL) Round-Robin Scheduling Enable Mask */
#define EVSYS_PRICTRL_RREN(value)             (EVSYS_PRICTRL_RREN_Msk & (_UINT8_(value) << EVSYS_PRICTRL_RREN_Pos)) /* Assigment of value for RREN in the EVSYS_PRICTRL register */
#define EVSYS_PRICTRL_Msk                     _UINT8_(0x87)                                        /* (EVSYS_PRICTRL) Register Mask  */


/* -------- EVSYS_INTPEND : (EVSYS Offset: 0x10) (R/W 16) Channel Pending Interrupt -------- */
#define EVSYS_INTPEND_RESETVALUE              _UINT16_(0x4000)                                     /*  (EVSYS_INTPEND) Channel Pending Interrupt  Reset Value */

#define EVSYS_INTPEND_ID_Pos                  _UINT16_(0)                                          /* (EVSYS_INTPEND) Channel ID Position */
#define EVSYS_INTPEND_ID_Msk                  (_UINT16_(0x7) << EVSYS_INTPEND_ID_Pos)              /* (EVSYS_INTPEND) Channel ID Mask */
#define EVSYS_INTPEND_ID(value)               (EVSYS_INTPEND_ID_Msk & (_UINT16_(value) << EVSYS_INTPEND_ID_Pos)) /* Assigment of value for ID in the EVSYS_INTPEND register */
#define EVSYS_INTPEND_OVR_Pos                 _UINT16_(8)                                          /* (EVSYS_INTPEND) Channel Overrun Position */
#define EVSYS_INTPEND_OVR_Msk                 (_UINT16_(0x1) << EVSYS_INTPEND_OVR_Pos)             /* (EVSYS_INTPEND) Channel Overrun Mask */
#define EVSYS_INTPEND_OVR(value)              (EVSYS_INTPEND_OVR_Msk & (_UINT16_(value) << EVSYS_INTPEND_OVR_Pos)) /* Assigment of value for OVR in the EVSYS_INTPEND register */
#define EVSYS_INTPEND_EVD_Pos                 _UINT16_(9)                                          /* (EVSYS_INTPEND) Channel Event Detected Position */
#define EVSYS_INTPEND_EVD_Msk                 (_UINT16_(0x1) << EVSYS_INTPEND_EVD_Pos)             /* (EVSYS_INTPEND) Channel Event Detected Mask */
#define EVSYS_INTPEND_EVD(value)              (EVSYS_INTPEND_EVD_Msk & (_UINT16_(value) << EVSYS_INTPEND_EVD_Pos)) /* Assigment of value for EVD in the EVSYS_INTPEND register */
#define EVSYS_INTPEND_READY_Pos               _UINT16_(14)                                         /* (EVSYS_INTPEND) Ready Position */
#define EVSYS_INTPEND_READY_Msk               (_UINT16_(0x1) << EVSYS_INTPEND_READY_Pos)           /* (EVSYS_INTPEND) Ready Mask */
#define EVSYS_INTPEND_READY(value)            (EVSYS_INTPEND_READY_Msk & (_UINT16_(value) << EVSYS_INTPEND_READY_Pos)) /* Assigment of value for READY in the EVSYS_INTPEND register */
#define EVSYS_INTPEND_BUSY_Pos                _UINT16_(15)                                         /* (EVSYS_INTPEND) Busy Position */
#define EVSYS_INTPEND_BUSY_Msk                (_UINT16_(0x1) << EVSYS_INTPEND_BUSY_Pos)            /* (EVSYS_INTPEND) Busy Mask */
#define EVSYS_INTPEND_BUSY(value)             (EVSYS_INTPEND_BUSY_Msk & (_UINT16_(value) << EVSYS_INTPEND_BUSY_Pos)) /* Assigment of value for BUSY in the EVSYS_INTPEND register */
#define EVSYS_INTPEND_Msk                     _UINT16_(0xC307)                                     /* (EVSYS_INTPEND) Register Mask  */


/* -------- EVSYS_INTSTATUS : (EVSYS Offset: 0x14) ( R/ 32) Interrupt Status -------- */
#define EVSYS_INTSTATUS_RESETVALUE            _UINT32_(0x00)                                       /*  (EVSYS_INTSTATUS) Interrupt Status  Reset Value */

#define EVSYS_INTSTATUS_CHINT0_Pos            _UINT32_(0)                                          /* (EVSYS_INTSTATUS) Channel 0 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT0_Msk            (_UINT32_(0x1) << EVSYS_INTSTATUS_CHINT0_Pos)        /* (EVSYS_INTSTATUS) Channel 0 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT0(value)         (EVSYS_INTSTATUS_CHINT0_Msk & (_UINT32_(value) << EVSYS_INTSTATUS_CHINT0_Pos)) /* Assigment of value for CHINT0 in the EVSYS_INTSTATUS register */
#define EVSYS_INTSTATUS_CHINT1_Pos            _UINT32_(1)                                          /* (EVSYS_INTSTATUS) Channel 1 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT1_Msk            (_UINT32_(0x1) << EVSYS_INTSTATUS_CHINT1_Pos)        /* (EVSYS_INTSTATUS) Channel 1 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT1(value)         (EVSYS_INTSTATUS_CHINT1_Msk & (_UINT32_(value) << EVSYS_INTSTATUS_CHINT1_Pos)) /* Assigment of value for CHINT1 in the EVSYS_INTSTATUS register */
#define EVSYS_INTSTATUS_CHINT2_Pos            _UINT32_(2)                                          /* (EVSYS_INTSTATUS) Channel 2 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT2_Msk            (_UINT32_(0x1) << EVSYS_INTSTATUS_CHINT2_Pos)        /* (EVSYS_INTSTATUS) Channel 2 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT2(value)         (EVSYS_INTSTATUS_CHINT2_Msk & (_UINT32_(value) << EVSYS_INTSTATUS_CHINT2_Pos)) /* Assigment of value for CHINT2 in the EVSYS_INTSTATUS register */
#define EVSYS_INTSTATUS_CHINT3_Pos            _UINT32_(3)                                          /* (EVSYS_INTSTATUS) Channel 3 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT3_Msk            (_UINT32_(0x1) << EVSYS_INTSTATUS_CHINT3_Pos)        /* (EVSYS_INTSTATUS) Channel 3 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT3(value)         (EVSYS_INTSTATUS_CHINT3_Msk & (_UINT32_(value) << EVSYS_INTSTATUS_CHINT3_Pos)) /* Assigment of value for CHINT3 in the EVSYS_INTSTATUS register */
#define EVSYS_INTSTATUS_CHINT4_Pos            _UINT32_(4)                                          /* (EVSYS_INTSTATUS) Channel 4 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT4_Msk            (_UINT32_(0x1) << EVSYS_INTSTATUS_CHINT4_Pos)        /* (EVSYS_INTSTATUS) Channel 4 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT4(value)         (EVSYS_INTSTATUS_CHINT4_Msk & (_UINT32_(value) << EVSYS_INTSTATUS_CHINT4_Pos)) /* Assigment of value for CHINT4 in the EVSYS_INTSTATUS register */
#define EVSYS_INTSTATUS_CHINT5_Pos            _UINT32_(5)                                          /* (EVSYS_INTSTATUS) Channel 5 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT5_Msk            (_UINT32_(0x1) << EVSYS_INTSTATUS_CHINT5_Pos)        /* (EVSYS_INTSTATUS) Channel 5 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT5(value)         (EVSYS_INTSTATUS_CHINT5_Msk & (_UINT32_(value) << EVSYS_INTSTATUS_CHINT5_Pos)) /* Assigment of value for CHINT5 in the EVSYS_INTSTATUS register */
#define EVSYS_INTSTATUS_CHINT6_Pos            _UINT32_(6)                                          /* (EVSYS_INTSTATUS) Channel 6 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT6_Msk            (_UINT32_(0x1) << EVSYS_INTSTATUS_CHINT6_Pos)        /* (EVSYS_INTSTATUS) Channel 6 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT6(value)         (EVSYS_INTSTATUS_CHINT6_Msk & (_UINT32_(value) << EVSYS_INTSTATUS_CHINT6_Pos)) /* Assigment of value for CHINT6 in the EVSYS_INTSTATUS register */
#define EVSYS_INTSTATUS_CHINT7_Pos            _UINT32_(7)                                          /* (EVSYS_INTSTATUS) Channel 7 Pending Interrupt Position */
#define EVSYS_INTSTATUS_CHINT7_Msk            (_UINT32_(0x1) << EVSYS_INTSTATUS_CHINT7_Pos)        /* (EVSYS_INTSTATUS) Channel 7 Pending Interrupt Mask */
#define EVSYS_INTSTATUS_CHINT7(value)         (EVSYS_INTSTATUS_CHINT7_Msk & (_UINT32_(value) << EVSYS_INTSTATUS_CHINT7_Pos)) /* Assigment of value for CHINT7 in the EVSYS_INTSTATUS register */
#define EVSYS_INTSTATUS_Msk                   _UINT32_(0x000000FF)                                 /* (EVSYS_INTSTATUS) Register Mask  */

#define EVSYS_INTSTATUS_CHINT_Pos             _UINT32_(0)                                          /* (EVSYS_INTSTATUS Position) Channel 7 Pending Interrupt */
#define EVSYS_INTSTATUS_CHINT_Msk             (_UINT32_(0xFF) << EVSYS_INTSTATUS_CHINT_Pos)        /* (EVSYS_INTSTATUS Mask) CHINT */
#define EVSYS_INTSTATUS_CHINT(value)          (EVSYS_INTSTATUS_CHINT_Msk & (_UINT32_(value) << EVSYS_INTSTATUS_CHINT_Pos)) 

/* -------- EVSYS_BUSYCH : (EVSYS Offset: 0x18) ( R/ 32) Busy Channels -------- */
#define EVSYS_BUSYCH_RESETVALUE               _UINT32_(0x00)                                       /*  (EVSYS_BUSYCH) Busy Channels  Reset Value */

#define EVSYS_BUSYCH_BUSYCH0_Pos              _UINT32_(0)                                          /* (EVSYS_BUSYCH) Busy Channel 0 Position */
#define EVSYS_BUSYCH_BUSYCH0_Msk              (_UINT32_(0x1) << EVSYS_BUSYCH_BUSYCH0_Pos)          /* (EVSYS_BUSYCH) Busy Channel 0 Mask */
#define EVSYS_BUSYCH_BUSYCH0(value)           (EVSYS_BUSYCH_BUSYCH0_Msk & (_UINT32_(value) << EVSYS_BUSYCH_BUSYCH0_Pos)) /* Assigment of value for BUSYCH0 in the EVSYS_BUSYCH register */
#define EVSYS_BUSYCH_BUSYCH1_Pos              _UINT32_(1)                                          /* (EVSYS_BUSYCH) Busy Channel 1 Position */
#define EVSYS_BUSYCH_BUSYCH1_Msk              (_UINT32_(0x1) << EVSYS_BUSYCH_BUSYCH1_Pos)          /* (EVSYS_BUSYCH) Busy Channel 1 Mask */
#define EVSYS_BUSYCH_BUSYCH1(value)           (EVSYS_BUSYCH_BUSYCH1_Msk & (_UINT32_(value) << EVSYS_BUSYCH_BUSYCH1_Pos)) /* Assigment of value for BUSYCH1 in the EVSYS_BUSYCH register */
#define EVSYS_BUSYCH_BUSYCH2_Pos              _UINT32_(2)                                          /* (EVSYS_BUSYCH) Busy Channel 2 Position */
#define EVSYS_BUSYCH_BUSYCH2_Msk              (_UINT32_(0x1) << EVSYS_BUSYCH_BUSYCH2_Pos)          /* (EVSYS_BUSYCH) Busy Channel 2 Mask */
#define EVSYS_BUSYCH_BUSYCH2(value)           (EVSYS_BUSYCH_BUSYCH2_Msk & (_UINT32_(value) << EVSYS_BUSYCH_BUSYCH2_Pos)) /* Assigment of value for BUSYCH2 in the EVSYS_BUSYCH register */
#define EVSYS_BUSYCH_BUSYCH3_Pos              _UINT32_(3)                                          /* (EVSYS_BUSYCH) Busy Channel 3 Position */
#define EVSYS_BUSYCH_BUSYCH3_Msk              (_UINT32_(0x1) << EVSYS_BUSYCH_BUSYCH3_Pos)          /* (EVSYS_BUSYCH) Busy Channel 3 Mask */
#define EVSYS_BUSYCH_BUSYCH3(value)           (EVSYS_BUSYCH_BUSYCH3_Msk & (_UINT32_(value) << EVSYS_BUSYCH_BUSYCH3_Pos)) /* Assigment of value for BUSYCH3 in the EVSYS_BUSYCH register */
#define EVSYS_BUSYCH_BUSYCH4_Pos              _UINT32_(4)                                          /* (EVSYS_BUSYCH) Busy Channel 4 Position */
#define EVSYS_BUSYCH_BUSYCH4_Msk              (_UINT32_(0x1) << EVSYS_BUSYCH_BUSYCH4_Pos)          /* (EVSYS_BUSYCH) Busy Channel 4 Mask */
#define EVSYS_BUSYCH_BUSYCH4(value)           (EVSYS_BUSYCH_BUSYCH4_Msk & (_UINT32_(value) << EVSYS_BUSYCH_BUSYCH4_Pos)) /* Assigment of value for BUSYCH4 in the EVSYS_BUSYCH register */
#define EVSYS_BUSYCH_BUSYCH5_Pos              _UINT32_(5)                                          /* (EVSYS_BUSYCH) Busy Channel 5 Position */
#define EVSYS_BUSYCH_BUSYCH5_Msk              (_UINT32_(0x1) << EVSYS_BUSYCH_BUSYCH5_Pos)          /* (EVSYS_BUSYCH) Busy Channel 5 Mask */
#define EVSYS_BUSYCH_BUSYCH5(value)           (EVSYS_BUSYCH_BUSYCH5_Msk & (_UINT32_(value) << EVSYS_BUSYCH_BUSYCH5_Pos)) /* Assigment of value for BUSYCH5 in the EVSYS_BUSYCH register */
#define EVSYS_BUSYCH_BUSYCH6_Pos              _UINT32_(6)                                          /* (EVSYS_BUSYCH) Busy Channel 6 Position */
#define EVSYS_BUSYCH_BUSYCH6_Msk              (_UINT32_(0x1) << EVSYS_BUSYCH_BUSYCH6_Pos)          /* (EVSYS_BUSYCH) Busy Channel 6 Mask */
#define EVSYS_BUSYCH_BUSYCH6(value)           (EVSYS_BUSYCH_BUSYCH6_Msk & (_UINT32_(value) << EVSYS_BUSYCH_BUSYCH6_Pos)) /* Assigment of value for BUSYCH6 in the EVSYS_BUSYCH register */
#define EVSYS_BUSYCH_BUSYCH7_Pos              _UINT32_(7)                                          /* (EVSYS_BUSYCH) Busy Channel 7 Position */
#define EVSYS_BUSYCH_BUSYCH7_Msk              (_UINT32_(0x1) << EVSYS_BUSYCH_BUSYCH7_Pos)          /* (EVSYS_BUSYCH) Busy Channel 7 Mask */
#define EVSYS_BUSYCH_BUSYCH7(value)           (EVSYS_BUSYCH_BUSYCH7_Msk & (_UINT32_(value) << EVSYS_BUSYCH_BUSYCH7_Pos)) /* Assigment of value for BUSYCH7 in the EVSYS_BUSYCH register */
#define EVSYS_BUSYCH_Msk                      _UINT32_(0x000000FF)                                 /* (EVSYS_BUSYCH) Register Mask  */

#define EVSYS_BUSYCH_BUSYCH_Pos               _UINT32_(0)                                          /* (EVSYS_BUSYCH Position) Busy Channel 7 */
#define EVSYS_BUSYCH_BUSYCH_Msk               (_UINT32_(0xFF) << EVSYS_BUSYCH_BUSYCH_Pos)          /* (EVSYS_BUSYCH Mask) BUSYCH */
#define EVSYS_BUSYCH_BUSYCH(value)            (EVSYS_BUSYCH_BUSYCH_Msk & (_UINT32_(value) << EVSYS_BUSYCH_BUSYCH_Pos)) 

/* -------- EVSYS_READYUSR : (EVSYS Offset: 0x1C) ( R/ 32) Ready Users -------- */
#define EVSYS_READYUSR_RESETVALUE             _UINT32_(0xFFFFFFFF)                                 /*  (EVSYS_READYUSR) Ready Users  Reset Value */

#define EVSYS_READYUSR_READYUSR0_Pos          _UINT32_(0)                                          /* (EVSYS_READYUSR) Ready User for Channel 0 Position */
#define EVSYS_READYUSR_READYUSR0_Msk          (_UINT32_(0x1) << EVSYS_READYUSR_READYUSR0_Pos)      /* (EVSYS_READYUSR) Ready User for Channel 0 Mask */
#define EVSYS_READYUSR_READYUSR0(value)       (EVSYS_READYUSR_READYUSR0_Msk & (_UINT32_(value) << EVSYS_READYUSR_READYUSR0_Pos)) /* Assigment of value for READYUSR0 in the EVSYS_READYUSR register */
#define EVSYS_READYUSR_READYUSR1_Pos          _UINT32_(1)                                          /* (EVSYS_READYUSR) Ready User for Channel 1 Position */
#define EVSYS_READYUSR_READYUSR1_Msk          (_UINT32_(0x1) << EVSYS_READYUSR_READYUSR1_Pos)      /* (EVSYS_READYUSR) Ready User for Channel 1 Mask */
#define EVSYS_READYUSR_READYUSR1(value)       (EVSYS_READYUSR_READYUSR1_Msk & (_UINT32_(value) << EVSYS_READYUSR_READYUSR1_Pos)) /* Assigment of value for READYUSR1 in the EVSYS_READYUSR register */
#define EVSYS_READYUSR_READYUSR2_Pos          _UINT32_(2)                                          /* (EVSYS_READYUSR) Ready User for Channel 2 Position */
#define EVSYS_READYUSR_READYUSR2_Msk          (_UINT32_(0x1) << EVSYS_READYUSR_READYUSR2_Pos)      /* (EVSYS_READYUSR) Ready User for Channel 2 Mask */
#define EVSYS_READYUSR_READYUSR2(value)       (EVSYS_READYUSR_READYUSR2_Msk & (_UINT32_(value) << EVSYS_READYUSR_READYUSR2_Pos)) /* Assigment of value for READYUSR2 in the EVSYS_READYUSR register */
#define EVSYS_READYUSR_READYUSR3_Pos          _UINT32_(3)                                          /* (EVSYS_READYUSR) Ready User for Channel 3 Position */
#define EVSYS_READYUSR_READYUSR3_Msk          (_UINT32_(0x1) << EVSYS_READYUSR_READYUSR3_Pos)      /* (EVSYS_READYUSR) Ready User for Channel 3 Mask */
#define EVSYS_READYUSR_READYUSR3(value)       (EVSYS_READYUSR_READYUSR3_Msk & (_UINT32_(value) << EVSYS_READYUSR_READYUSR3_Pos)) /* Assigment of value for READYUSR3 in the EVSYS_READYUSR register */
#define EVSYS_READYUSR_READYUSR4_Pos          _UINT32_(4)                                          /* (EVSYS_READYUSR) Ready User for Channel 4 Position */
#define EVSYS_READYUSR_READYUSR4_Msk          (_UINT32_(0x1) << EVSYS_READYUSR_READYUSR4_Pos)      /* (EVSYS_READYUSR) Ready User for Channel 4 Mask */
#define EVSYS_READYUSR_READYUSR4(value)       (EVSYS_READYUSR_READYUSR4_Msk & (_UINT32_(value) << EVSYS_READYUSR_READYUSR4_Pos)) /* Assigment of value for READYUSR4 in the EVSYS_READYUSR register */
#define EVSYS_READYUSR_READYUSR5_Pos          _UINT32_(5)                                          /* (EVSYS_READYUSR) Ready User for Channel 5 Position */
#define EVSYS_READYUSR_READYUSR5_Msk          (_UINT32_(0x1) << EVSYS_READYUSR_READYUSR5_Pos)      /* (EVSYS_READYUSR) Ready User for Channel 5 Mask */
#define EVSYS_READYUSR_READYUSR5(value)       (EVSYS_READYUSR_READYUSR5_Msk & (_UINT32_(value) << EVSYS_READYUSR_READYUSR5_Pos)) /* Assigment of value for READYUSR5 in the EVSYS_READYUSR register */
#define EVSYS_READYUSR_READYUSR6_Pos          _UINT32_(6)                                          /* (EVSYS_READYUSR) Ready User for Channel 6 Position */
#define EVSYS_READYUSR_READYUSR6_Msk          (_UINT32_(0x1) << EVSYS_READYUSR_READYUSR6_Pos)      /* (EVSYS_READYUSR) Ready User for Channel 6 Mask */
#define EVSYS_READYUSR_READYUSR6(value)       (EVSYS_READYUSR_READYUSR6_Msk & (_UINT32_(value) << EVSYS_READYUSR_READYUSR6_Pos)) /* Assigment of value for READYUSR6 in the EVSYS_READYUSR register */
#define EVSYS_READYUSR_READYUSR7_Pos          _UINT32_(7)                                          /* (EVSYS_READYUSR) Ready User for Channel 7 Position */
#define EVSYS_READYUSR_READYUSR7_Msk          (_UINT32_(0x1) << EVSYS_READYUSR_READYUSR7_Pos)      /* (EVSYS_READYUSR) Ready User for Channel 7 Mask */
#define EVSYS_READYUSR_READYUSR7(value)       (EVSYS_READYUSR_READYUSR7_Msk & (_UINT32_(value) << EVSYS_READYUSR_READYUSR7_Pos)) /* Assigment of value for READYUSR7 in the EVSYS_READYUSR register */
#define EVSYS_READYUSR_Msk                    _UINT32_(0x000000FF)                                 /* (EVSYS_READYUSR) Register Mask  */

#define EVSYS_READYUSR_READYUSR_Pos           _UINT32_(0)                                          /* (EVSYS_READYUSR Position) Ready User for Channel 7 */
#define EVSYS_READYUSR_READYUSR_Msk           (_UINT32_(0xFF) << EVSYS_READYUSR_READYUSR_Pos)      /* (EVSYS_READYUSR Mask) READYUSR */
#define EVSYS_READYUSR_READYUSR(value)        (EVSYS_READYUSR_READYUSR_Msk & (_UINT32_(value) << EVSYS_READYUSR_READYUSR_Pos)) 

/* -------- EVSYS_USER : (EVSYS Offset: 0x120) (R/W 8) User Multiplexer n -------- */
#define EVSYS_USER_RESETVALUE                 _UINT8_(0x00)                                        /*  (EVSYS_USER) User Multiplexer n  Reset Value */

#define EVSYS_USER_CHANNEL_Pos                _UINT8_(0)                                           /* (EVSYS_USER) Channel Event Selection Position */
#define EVSYS_USER_CHANNEL_Msk                (_UINT8_(0xF) << EVSYS_USER_CHANNEL_Pos)             /* (EVSYS_USER) Channel Event Selection Mask */
#define EVSYS_USER_CHANNEL(value)             (EVSYS_USER_CHANNEL_Msk & (_UINT8_(value) << EVSYS_USER_CHANNEL_Pos)) /* Assigment of value for CHANNEL in the EVSYS_USER register */
#define EVSYS_USER_Msk                        _UINT8_(0x0F)                                        /* (EVSYS_USER) Register Mask  */


/* -------- EVSYS_INTENCLR : (EVSYS Offset: 0x1D4) (R/W 8) Interrupt Enable Clear -------- */
#define EVSYS_INTENCLR_RESETVALUE             _UINT8_(0x00)                                        /*  (EVSYS_INTENCLR) Interrupt Enable Clear  Reset Value */

#define EVSYS_INTENCLR_NSCHK_Pos              _UINT8_(0)                                           /* (EVSYS_INTENCLR) Non-Secure Check Interrupt Enable Position */
#define EVSYS_INTENCLR_NSCHK_Msk              (_UINT8_(0x1) << EVSYS_INTENCLR_NSCHK_Pos)           /* (EVSYS_INTENCLR) Non-Secure Check Interrupt Enable Mask */
#define EVSYS_INTENCLR_NSCHK(value)           (EVSYS_INTENCLR_NSCHK_Msk & (_UINT8_(value) << EVSYS_INTENCLR_NSCHK_Pos)) /* Assigment of value for NSCHK in the EVSYS_INTENCLR register */
#define EVSYS_INTENCLR_Msk                    _UINT8_(0x01)                                        /* (EVSYS_INTENCLR) Register Mask  */


/* -------- EVSYS_INTENSET : (EVSYS Offset: 0x1D5) (R/W 8) Interrupt Enable Set -------- */
#define EVSYS_INTENSET_RESETVALUE             _UINT8_(0x00)                                        /*  (EVSYS_INTENSET) Interrupt Enable Set  Reset Value */

#define EVSYS_INTENSET_NSCHK_Pos              _UINT8_(0)                                           /* (EVSYS_INTENSET) Non-Secure Check Interrupt Enable Position */
#define EVSYS_INTENSET_NSCHK_Msk              (_UINT8_(0x1) << EVSYS_INTENSET_NSCHK_Pos)           /* (EVSYS_INTENSET) Non-Secure Check Interrupt Enable Mask */
#define EVSYS_INTENSET_NSCHK(value)           (EVSYS_INTENSET_NSCHK_Msk & (_UINT8_(value) << EVSYS_INTENSET_NSCHK_Pos)) /* Assigment of value for NSCHK in the EVSYS_INTENSET register */
#define EVSYS_INTENSET_Msk                    _UINT8_(0x01)                                        /* (EVSYS_INTENSET) Register Mask  */


/* -------- EVSYS_INTFLAG : (EVSYS Offset: 0x1D6) (R/W 8) Interrupt Flag Status and Clear -------- */
#define EVSYS_INTFLAG_RESETVALUE              _UINT8_(0x00)                                        /*  (EVSYS_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define EVSYS_INTFLAG_NSCHK_Pos               _UINT8_(0)                                           /* (EVSYS_INTFLAG) Non-Secure Check Position */
#define EVSYS_INTFLAG_NSCHK_Msk               (_UINT8_(0x1) << EVSYS_INTFLAG_NSCHK_Pos)            /* (EVSYS_INTFLAG) Non-Secure Check Mask */
#define EVSYS_INTFLAG_NSCHK(value)            (EVSYS_INTFLAG_NSCHK_Msk & (_UINT8_(value) << EVSYS_INTFLAG_NSCHK_Pos)) /* Assigment of value for NSCHK in the EVSYS_INTFLAG register */
#define EVSYS_INTFLAG_Msk                     _UINT8_(0x01)                                        /* (EVSYS_INTFLAG) Register Mask  */


/* -------- EVSYS_NONSECCHAN : (EVSYS Offset: 0x1D8) (R/W 32) Channels Security Attribution -------- */
#define EVSYS_NONSECCHAN_RESETVALUE           _UINT32_(0x00)                                       /*  (EVSYS_NONSECCHAN) Channels Security Attribution  Reset Value */

#define EVSYS_NONSECCHAN_CHANNEL0_Pos         _UINT32_(0)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 0 Position */
#define EVSYS_NONSECCHAN_CHANNEL0_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL0_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 0 Mask */
#define EVSYS_NONSECCHAN_CHANNEL0(value)      (EVSYS_NONSECCHAN_CHANNEL0_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL0_Pos)) /* Assigment of value for CHANNEL0 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL1_Pos         _UINT32_(1)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 1 Position */
#define EVSYS_NONSECCHAN_CHANNEL1_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL1_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 1 Mask */
#define EVSYS_NONSECCHAN_CHANNEL1(value)      (EVSYS_NONSECCHAN_CHANNEL1_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL1_Pos)) /* Assigment of value for CHANNEL1 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL2_Pos         _UINT32_(2)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 2 Position */
#define EVSYS_NONSECCHAN_CHANNEL2_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL2_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 2 Mask */
#define EVSYS_NONSECCHAN_CHANNEL2(value)      (EVSYS_NONSECCHAN_CHANNEL2_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL2_Pos)) /* Assigment of value for CHANNEL2 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL3_Pos         _UINT32_(3)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 3 Position */
#define EVSYS_NONSECCHAN_CHANNEL3_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL3_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 3 Mask */
#define EVSYS_NONSECCHAN_CHANNEL3(value)      (EVSYS_NONSECCHAN_CHANNEL3_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL3_Pos)) /* Assigment of value for CHANNEL3 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL4_Pos         _UINT32_(4)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 4 Position */
#define EVSYS_NONSECCHAN_CHANNEL4_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL4_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 4 Mask */
#define EVSYS_NONSECCHAN_CHANNEL4(value)      (EVSYS_NONSECCHAN_CHANNEL4_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL4_Pos)) /* Assigment of value for CHANNEL4 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL5_Pos         _UINT32_(5)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 5 Position */
#define EVSYS_NONSECCHAN_CHANNEL5_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL5_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 5 Mask */
#define EVSYS_NONSECCHAN_CHANNEL5(value)      (EVSYS_NONSECCHAN_CHANNEL5_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL5_Pos)) /* Assigment of value for CHANNEL5 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL6_Pos         _UINT32_(6)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 6 Position */
#define EVSYS_NONSECCHAN_CHANNEL6_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL6_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 6 Mask */
#define EVSYS_NONSECCHAN_CHANNEL6(value)      (EVSYS_NONSECCHAN_CHANNEL6_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL6_Pos)) /* Assigment of value for CHANNEL6 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL7_Pos         _UINT32_(7)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 7 Position */
#define EVSYS_NONSECCHAN_CHANNEL7_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL7_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 7 Mask */
#define EVSYS_NONSECCHAN_CHANNEL7(value)      (EVSYS_NONSECCHAN_CHANNEL7_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL7_Pos)) /* Assigment of value for CHANNEL7 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL8_Pos         _UINT32_(8)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 8 Position */
#define EVSYS_NONSECCHAN_CHANNEL8_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL8_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 8 Mask */
#define EVSYS_NONSECCHAN_CHANNEL8(value)      (EVSYS_NONSECCHAN_CHANNEL8_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL8_Pos)) /* Assigment of value for CHANNEL8 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL9_Pos         _UINT32_(9)                                          /* (EVSYS_NONSECCHAN) Non-Secure for Channel 9 Position */
#define EVSYS_NONSECCHAN_CHANNEL9_Msk         (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL9_Pos)     /* (EVSYS_NONSECCHAN) Non-Secure for Channel 9 Mask */
#define EVSYS_NONSECCHAN_CHANNEL9(value)      (EVSYS_NONSECCHAN_CHANNEL9_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL9_Pos)) /* Assigment of value for CHANNEL9 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL10_Pos        _UINT32_(10)                                         /* (EVSYS_NONSECCHAN) Non-Secure for Channel 10 Position */
#define EVSYS_NONSECCHAN_CHANNEL10_Msk        (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL10_Pos)    /* (EVSYS_NONSECCHAN) Non-Secure for Channel 10 Mask */
#define EVSYS_NONSECCHAN_CHANNEL10(value)     (EVSYS_NONSECCHAN_CHANNEL10_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL10_Pos)) /* Assigment of value for CHANNEL10 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_CHANNEL11_Pos        _UINT32_(11)                                         /* (EVSYS_NONSECCHAN) Non-Secure for Channel 11 Position */
#define EVSYS_NONSECCHAN_CHANNEL11_Msk        (_UINT32_(0x1) << EVSYS_NONSECCHAN_CHANNEL11_Pos)    /* (EVSYS_NONSECCHAN) Non-Secure for Channel 11 Mask */
#define EVSYS_NONSECCHAN_CHANNEL11(value)     (EVSYS_NONSECCHAN_CHANNEL11_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL11_Pos)) /* Assigment of value for CHANNEL11 in the EVSYS_NONSECCHAN register */
#define EVSYS_NONSECCHAN_Msk                  _UINT32_(0x00000FFF)                                 /* (EVSYS_NONSECCHAN) Register Mask  */

#define EVSYS_NONSECCHAN_CHANNEL_Pos          _UINT32_(0)                                          /* (EVSYS_NONSECCHAN Position) Non-Secure for Channel xx */
#define EVSYS_NONSECCHAN_CHANNEL_Msk          (_UINT32_(0xFFF) << EVSYS_NONSECCHAN_CHANNEL_Pos)    /* (EVSYS_NONSECCHAN Mask) CHANNEL */
#define EVSYS_NONSECCHAN_CHANNEL(value)       (EVSYS_NONSECCHAN_CHANNEL_Msk & (_UINT32_(value) << EVSYS_NONSECCHAN_CHANNEL_Pos)) 

/* -------- EVSYS_NSCHKCHAN : (EVSYS Offset: 0x1DC) (R/W 32) Non-Secure Channels Check -------- */
#define EVSYS_NSCHKCHAN_RESETVALUE            _UINT32_(0x00)                                       /*  (EVSYS_NSCHKCHAN) Non-Secure Channels Check  Reset Value */

#define EVSYS_NSCHKCHAN_CHANNEL0_Pos          _UINT32_(0)                                          /* (EVSYS_NSCHKCHAN) Channel 0 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL0_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL0_Pos)      /* (EVSYS_NSCHKCHAN) Channel 0 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL0(value)       (EVSYS_NSCHKCHAN_CHANNEL0_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL0_Pos)) /* Assigment of value for CHANNEL0 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL1_Pos          _UINT32_(1)                                          /* (EVSYS_NSCHKCHAN) Channel 1 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL1_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL1_Pos)      /* (EVSYS_NSCHKCHAN) Channel 1 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL1(value)       (EVSYS_NSCHKCHAN_CHANNEL1_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL1_Pos)) /* Assigment of value for CHANNEL1 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL2_Pos          _UINT32_(2)                                          /* (EVSYS_NSCHKCHAN) Channel 2 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL2_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL2_Pos)      /* (EVSYS_NSCHKCHAN) Channel 2 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL2(value)       (EVSYS_NSCHKCHAN_CHANNEL2_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL2_Pos)) /* Assigment of value for CHANNEL2 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL3_Pos          _UINT32_(3)                                          /* (EVSYS_NSCHKCHAN) Channel 3 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL3_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL3_Pos)      /* (EVSYS_NSCHKCHAN) Channel 3 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL3(value)       (EVSYS_NSCHKCHAN_CHANNEL3_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL3_Pos)) /* Assigment of value for CHANNEL3 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL4_Pos          _UINT32_(4)                                          /* (EVSYS_NSCHKCHAN) Channel 4 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL4_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL4_Pos)      /* (EVSYS_NSCHKCHAN) Channel 4 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL4(value)       (EVSYS_NSCHKCHAN_CHANNEL4_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL4_Pos)) /* Assigment of value for CHANNEL4 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL5_Pos          _UINT32_(5)                                          /* (EVSYS_NSCHKCHAN) Channel 5 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL5_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL5_Pos)      /* (EVSYS_NSCHKCHAN) Channel 5 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL5(value)       (EVSYS_NSCHKCHAN_CHANNEL5_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL5_Pos)) /* Assigment of value for CHANNEL5 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL6_Pos          _UINT32_(6)                                          /* (EVSYS_NSCHKCHAN) Channel 6 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL6_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL6_Pos)      /* (EVSYS_NSCHKCHAN) Channel 6 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL6(value)       (EVSYS_NSCHKCHAN_CHANNEL6_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL6_Pos)) /* Assigment of value for CHANNEL6 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL7_Pos          _UINT32_(7)                                          /* (EVSYS_NSCHKCHAN) Channel 7 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL7_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL7_Pos)      /* (EVSYS_NSCHKCHAN) Channel 7 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL7(value)       (EVSYS_NSCHKCHAN_CHANNEL7_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL7_Pos)) /* Assigment of value for CHANNEL7 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL8_Pos          _UINT32_(8)                                          /* (EVSYS_NSCHKCHAN) Channel 8 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL8_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL8_Pos)      /* (EVSYS_NSCHKCHAN) Channel 8 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL8(value)       (EVSYS_NSCHKCHAN_CHANNEL8_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL8_Pos)) /* Assigment of value for CHANNEL8 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL9_Pos          _UINT32_(9)                                          /* (EVSYS_NSCHKCHAN) Channel 9 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL9_Msk          (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL9_Pos)      /* (EVSYS_NSCHKCHAN) Channel 9 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL9(value)       (EVSYS_NSCHKCHAN_CHANNEL9_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL9_Pos)) /* Assigment of value for CHANNEL9 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL10_Pos         _UINT32_(10)                                         /* (EVSYS_NSCHKCHAN) Channel 10 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL10_Msk         (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL10_Pos)     /* (EVSYS_NSCHKCHAN) Channel 10 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL10(value)      (EVSYS_NSCHKCHAN_CHANNEL10_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL10_Pos)) /* Assigment of value for CHANNEL10 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_CHANNEL11_Pos         _UINT32_(11)                                         /* (EVSYS_NSCHKCHAN) Channel 11 to be checked as non-secured Position */
#define EVSYS_NSCHKCHAN_CHANNEL11_Msk         (_UINT32_(0x1) << EVSYS_NSCHKCHAN_CHANNEL11_Pos)     /* (EVSYS_NSCHKCHAN) Channel 11 to be checked as non-secured Mask */
#define EVSYS_NSCHKCHAN_CHANNEL11(value)      (EVSYS_NSCHKCHAN_CHANNEL11_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL11_Pos)) /* Assigment of value for CHANNEL11 in the EVSYS_NSCHKCHAN register */
#define EVSYS_NSCHKCHAN_Msk                   _UINT32_(0x00000FFF)                                 /* (EVSYS_NSCHKCHAN) Register Mask  */

#define EVSYS_NSCHKCHAN_CHANNEL_Pos           _UINT32_(0)                                          /* (EVSYS_NSCHKCHAN Position) Channel xx to be checked as non-secured */
#define EVSYS_NSCHKCHAN_CHANNEL_Msk           (_UINT32_(0xFFF) << EVSYS_NSCHKCHAN_CHANNEL_Pos)     /* (EVSYS_NSCHKCHAN Mask) CHANNEL */
#define EVSYS_NSCHKCHAN_CHANNEL(value)        (EVSYS_NSCHKCHAN_CHANNEL_Msk & (_UINT32_(value) << EVSYS_NSCHKCHAN_CHANNEL_Pos)) 

/* -------- EVSYS_NONSECUSER0 : (EVSYS Offset: 0x1E0) (R/W 32) Users Security Attribution -------- */
#define EVSYS_NONSECUSER0_RESETVALUE          _UINT32_(0x00)                                       /*  (EVSYS_NONSECUSER0) Users Security Attribution  Reset Value */

#define EVSYS_NONSECUSER0_USER0_Pos           _UINT32_(0)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 0 Position */
#define EVSYS_NONSECUSER0_USER0_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER0_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 0 Mask */
#define EVSYS_NONSECUSER0_USER0(value)        (EVSYS_NONSECUSER0_USER0_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER0_Pos)) /* Assigment of value for USER0 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER1_Pos           _UINT32_(1)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 1 Position */
#define EVSYS_NONSECUSER0_USER1_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER1_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 1 Mask */
#define EVSYS_NONSECUSER0_USER1(value)        (EVSYS_NONSECUSER0_USER1_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER1_Pos)) /* Assigment of value for USER1 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER2_Pos           _UINT32_(2)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 2 Position */
#define EVSYS_NONSECUSER0_USER2_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER2_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 2 Mask */
#define EVSYS_NONSECUSER0_USER2(value)        (EVSYS_NONSECUSER0_USER2_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER2_Pos)) /* Assigment of value for USER2 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER3_Pos           _UINT32_(3)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 3 Position */
#define EVSYS_NONSECUSER0_USER3_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER3_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 3 Mask */
#define EVSYS_NONSECUSER0_USER3(value)        (EVSYS_NONSECUSER0_USER3_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER3_Pos)) /* Assigment of value for USER3 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER4_Pos           _UINT32_(4)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 4 Position */
#define EVSYS_NONSECUSER0_USER4_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER4_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 4 Mask */
#define EVSYS_NONSECUSER0_USER4(value)        (EVSYS_NONSECUSER0_USER4_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER4_Pos)) /* Assigment of value for USER4 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER5_Pos           _UINT32_(5)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 5 Position */
#define EVSYS_NONSECUSER0_USER5_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER5_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 5 Mask */
#define EVSYS_NONSECUSER0_USER5(value)        (EVSYS_NONSECUSER0_USER5_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER5_Pos)) /* Assigment of value for USER5 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER6_Pos           _UINT32_(6)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 6 Position */
#define EVSYS_NONSECUSER0_USER6_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER6_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 6 Mask */
#define EVSYS_NONSECUSER0_USER6(value)        (EVSYS_NONSECUSER0_USER6_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER6_Pos)) /* Assigment of value for USER6 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER7_Pos           _UINT32_(7)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 7 Position */
#define EVSYS_NONSECUSER0_USER7_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER7_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 7 Mask */
#define EVSYS_NONSECUSER0_USER7(value)        (EVSYS_NONSECUSER0_USER7_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER7_Pos)) /* Assigment of value for USER7 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER8_Pos           _UINT32_(8)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 8 Position */
#define EVSYS_NONSECUSER0_USER8_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER8_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 8 Mask */
#define EVSYS_NONSECUSER0_USER8(value)        (EVSYS_NONSECUSER0_USER8_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER8_Pos)) /* Assigment of value for USER8 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER9_Pos           _UINT32_(9)                                          /* (EVSYS_NONSECUSER0) Non-Secure for User 9 Position */
#define EVSYS_NONSECUSER0_USER9_Msk           (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER9_Pos)       /* (EVSYS_NONSECUSER0) Non-Secure for User 9 Mask */
#define EVSYS_NONSECUSER0_USER9(value)        (EVSYS_NONSECUSER0_USER9_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER9_Pos)) /* Assigment of value for USER9 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER10_Pos          _UINT32_(10)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 10 Position */
#define EVSYS_NONSECUSER0_USER10_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER10_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 10 Mask */
#define EVSYS_NONSECUSER0_USER10(value)       (EVSYS_NONSECUSER0_USER10_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER10_Pos)) /* Assigment of value for USER10 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER11_Pos          _UINT32_(11)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 11 Position */
#define EVSYS_NONSECUSER0_USER11_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER11_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 11 Mask */
#define EVSYS_NONSECUSER0_USER11(value)       (EVSYS_NONSECUSER0_USER11_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER11_Pos)) /* Assigment of value for USER11 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER12_Pos          _UINT32_(12)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 12 Position */
#define EVSYS_NONSECUSER0_USER12_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER12_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 12 Mask */
#define EVSYS_NONSECUSER0_USER12(value)       (EVSYS_NONSECUSER0_USER12_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER12_Pos)) /* Assigment of value for USER12 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER13_Pos          _UINT32_(13)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 13 Position */
#define EVSYS_NONSECUSER0_USER13_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER13_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 13 Mask */
#define EVSYS_NONSECUSER0_USER13(value)       (EVSYS_NONSECUSER0_USER13_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER13_Pos)) /* Assigment of value for USER13 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER14_Pos          _UINT32_(14)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 14 Position */
#define EVSYS_NONSECUSER0_USER14_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER14_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 14 Mask */
#define EVSYS_NONSECUSER0_USER14(value)       (EVSYS_NONSECUSER0_USER14_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER14_Pos)) /* Assigment of value for USER14 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER15_Pos          _UINT32_(15)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 15 Position */
#define EVSYS_NONSECUSER0_USER15_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER15_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 15 Mask */
#define EVSYS_NONSECUSER0_USER15(value)       (EVSYS_NONSECUSER0_USER15_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER15_Pos)) /* Assigment of value for USER15 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER16_Pos          _UINT32_(16)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 16 Position */
#define EVSYS_NONSECUSER0_USER16_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER16_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 16 Mask */
#define EVSYS_NONSECUSER0_USER16(value)       (EVSYS_NONSECUSER0_USER16_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER16_Pos)) /* Assigment of value for USER16 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER17_Pos          _UINT32_(17)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 17 Position */
#define EVSYS_NONSECUSER0_USER17_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER17_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 17 Mask */
#define EVSYS_NONSECUSER0_USER17(value)       (EVSYS_NONSECUSER0_USER17_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER17_Pos)) /* Assigment of value for USER17 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER18_Pos          _UINT32_(18)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 18 Position */
#define EVSYS_NONSECUSER0_USER18_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER18_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 18 Mask */
#define EVSYS_NONSECUSER0_USER18(value)       (EVSYS_NONSECUSER0_USER18_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER18_Pos)) /* Assigment of value for USER18 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER19_Pos          _UINT32_(19)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 19 Position */
#define EVSYS_NONSECUSER0_USER19_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER19_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 19 Mask */
#define EVSYS_NONSECUSER0_USER19(value)       (EVSYS_NONSECUSER0_USER19_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER19_Pos)) /* Assigment of value for USER19 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER20_Pos          _UINT32_(20)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 20 Position */
#define EVSYS_NONSECUSER0_USER20_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER20_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 20 Mask */
#define EVSYS_NONSECUSER0_USER20(value)       (EVSYS_NONSECUSER0_USER20_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER20_Pos)) /* Assigment of value for USER20 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER21_Pos          _UINT32_(21)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 21 Position */
#define EVSYS_NONSECUSER0_USER21_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER21_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 21 Mask */
#define EVSYS_NONSECUSER0_USER21(value)       (EVSYS_NONSECUSER0_USER21_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER21_Pos)) /* Assigment of value for USER21 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER22_Pos          _UINT32_(22)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 22 Position */
#define EVSYS_NONSECUSER0_USER22_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER22_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 22 Mask */
#define EVSYS_NONSECUSER0_USER22(value)       (EVSYS_NONSECUSER0_USER22_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER22_Pos)) /* Assigment of value for USER22 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER23_Pos          _UINT32_(23)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 23 Position */
#define EVSYS_NONSECUSER0_USER23_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER23_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 23 Mask */
#define EVSYS_NONSECUSER0_USER23(value)       (EVSYS_NONSECUSER0_USER23_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER23_Pos)) /* Assigment of value for USER23 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER24_Pos          _UINT32_(24)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 24 Position */
#define EVSYS_NONSECUSER0_USER24_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER24_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 24 Mask */
#define EVSYS_NONSECUSER0_USER24(value)       (EVSYS_NONSECUSER0_USER24_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER24_Pos)) /* Assigment of value for USER24 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER25_Pos          _UINT32_(25)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 25 Position */
#define EVSYS_NONSECUSER0_USER25_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER25_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 25 Mask */
#define EVSYS_NONSECUSER0_USER25(value)       (EVSYS_NONSECUSER0_USER25_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER25_Pos)) /* Assigment of value for USER25 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER26_Pos          _UINT32_(26)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 26 Position */
#define EVSYS_NONSECUSER0_USER26_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER26_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 26 Mask */
#define EVSYS_NONSECUSER0_USER26(value)       (EVSYS_NONSECUSER0_USER26_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER26_Pos)) /* Assigment of value for USER26 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER27_Pos          _UINT32_(27)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 27 Position */
#define EVSYS_NONSECUSER0_USER27_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER27_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 27 Mask */
#define EVSYS_NONSECUSER0_USER27(value)       (EVSYS_NONSECUSER0_USER27_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER27_Pos)) /* Assigment of value for USER27 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER28_Pos          _UINT32_(28)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 28 Position */
#define EVSYS_NONSECUSER0_USER28_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER28_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 28 Mask */
#define EVSYS_NONSECUSER0_USER28(value)       (EVSYS_NONSECUSER0_USER28_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER28_Pos)) /* Assigment of value for USER28 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER29_Pos          _UINT32_(29)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 29 Position */
#define EVSYS_NONSECUSER0_USER29_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER29_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 29 Mask */
#define EVSYS_NONSECUSER0_USER29(value)       (EVSYS_NONSECUSER0_USER29_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER29_Pos)) /* Assigment of value for USER29 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER30_Pos          _UINT32_(30)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 30 Position */
#define EVSYS_NONSECUSER0_USER30_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER30_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 30 Mask */
#define EVSYS_NONSECUSER0_USER30(value)       (EVSYS_NONSECUSER0_USER30_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER30_Pos)) /* Assigment of value for USER30 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_USER31_Pos          _UINT32_(31)                                         /* (EVSYS_NONSECUSER0) Non-Secure for User 31 Position */
#define EVSYS_NONSECUSER0_USER31_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER0_USER31_Pos)      /* (EVSYS_NONSECUSER0) Non-Secure for User 31 Mask */
#define EVSYS_NONSECUSER0_USER31(value)       (EVSYS_NONSECUSER0_USER31_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER31_Pos)) /* Assigment of value for USER31 in the EVSYS_NONSECUSER0 register */
#define EVSYS_NONSECUSER0_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (EVSYS_NONSECUSER0) Register Mask  */

#define EVSYS_NONSECUSER0_USER_Pos            _UINT32_(0)                                          /* (EVSYS_NONSECUSER0 Position) Non-Secure for User 3x */
#define EVSYS_NONSECUSER0_USER_Msk            (_UINT32_(0xFFFFFFFF) << EVSYS_NONSECUSER0_USER_Pos) /* (EVSYS_NONSECUSER0 Mask) USER */
#define EVSYS_NONSECUSER0_USER(value)         (EVSYS_NONSECUSER0_USER_Msk & (_UINT32_(value) << EVSYS_NONSECUSER0_USER_Pos)) 

/* -------- EVSYS_NONSECUSER1 : (EVSYS Offset: 0x1E4) (R/W 32) Users Security Attribution -------- */
#define EVSYS_NONSECUSER1_RESETVALUE          _UINT32_(0x00)                                       /*  (EVSYS_NONSECUSER1) Users Security Attribution  Reset Value */

#define EVSYS_NONSECUSER1_USER32_Pos          _UINT32_(0)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 32 Position */
#define EVSYS_NONSECUSER1_USER32_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER32_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 32 Mask */
#define EVSYS_NONSECUSER1_USER32(value)       (EVSYS_NONSECUSER1_USER32_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER32_Pos)) /* Assigment of value for USER32 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER33_Pos          _UINT32_(1)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 33 Position */
#define EVSYS_NONSECUSER1_USER33_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER33_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 33 Mask */
#define EVSYS_NONSECUSER1_USER33(value)       (EVSYS_NONSECUSER1_USER33_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER33_Pos)) /* Assigment of value for USER33 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER34_Pos          _UINT32_(2)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 34 Position */
#define EVSYS_NONSECUSER1_USER34_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER34_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 34 Mask */
#define EVSYS_NONSECUSER1_USER34(value)       (EVSYS_NONSECUSER1_USER34_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER34_Pos)) /* Assigment of value for USER34 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER35_Pos          _UINT32_(3)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 35 Position */
#define EVSYS_NONSECUSER1_USER35_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER35_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 35 Mask */
#define EVSYS_NONSECUSER1_USER35(value)       (EVSYS_NONSECUSER1_USER35_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER35_Pos)) /* Assigment of value for USER35 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER36_Pos          _UINT32_(4)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 36 Position */
#define EVSYS_NONSECUSER1_USER36_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER36_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 36 Mask */
#define EVSYS_NONSECUSER1_USER36(value)       (EVSYS_NONSECUSER1_USER36_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER36_Pos)) /* Assigment of value for USER36 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER37_Pos          _UINT32_(5)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 37 Position */
#define EVSYS_NONSECUSER1_USER37_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER37_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 37 Mask */
#define EVSYS_NONSECUSER1_USER37(value)       (EVSYS_NONSECUSER1_USER37_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER37_Pos)) /* Assigment of value for USER37 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER38_Pos          _UINT32_(6)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 38 Position */
#define EVSYS_NONSECUSER1_USER38_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER38_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 38 Mask */
#define EVSYS_NONSECUSER1_USER38(value)       (EVSYS_NONSECUSER1_USER38_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER38_Pos)) /* Assigment of value for USER38 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER39_Pos          _UINT32_(7)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 39 Position */
#define EVSYS_NONSECUSER1_USER39_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER39_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 39 Mask */
#define EVSYS_NONSECUSER1_USER39(value)       (EVSYS_NONSECUSER1_USER39_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER39_Pos)) /* Assigment of value for USER39 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER40_Pos          _UINT32_(8)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 40 Position */
#define EVSYS_NONSECUSER1_USER40_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER40_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 40 Mask */
#define EVSYS_NONSECUSER1_USER40(value)       (EVSYS_NONSECUSER1_USER40_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER40_Pos)) /* Assigment of value for USER40 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER41_Pos          _UINT32_(9)                                          /* (EVSYS_NONSECUSER1) Non-Secure for User 41 Position */
#define EVSYS_NONSECUSER1_USER41_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER41_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 41 Mask */
#define EVSYS_NONSECUSER1_USER41(value)       (EVSYS_NONSECUSER1_USER41_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER41_Pos)) /* Assigment of value for USER41 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER42_Pos          _UINT32_(10)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 42 Position */
#define EVSYS_NONSECUSER1_USER42_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER42_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 42 Mask */
#define EVSYS_NONSECUSER1_USER42(value)       (EVSYS_NONSECUSER1_USER42_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER42_Pos)) /* Assigment of value for USER42 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER43_Pos          _UINT32_(11)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 43 Position */
#define EVSYS_NONSECUSER1_USER43_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER43_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 43 Mask */
#define EVSYS_NONSECUSER1_USER43(value)       (EVSYS_NONSECUSER1_USER43_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER43_Pos)) /* Assigment of value for USER43 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER44_Pos          _UINT32_(12)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 44 Position */
#define EVSYS_NONSECUSER1_USER44_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER44_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 44 Mask */
#define EVSYS_NONSECUSER1_USER44(value)       (EVSYS_NONSECUSER1_USER44_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER44_Pos)) /* Assigment of value for USER44 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER45_Pos          _UINT32_(13)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 45 Position */
#define EVSYS_NONSECUSER1_USER45_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER45_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 45 Mask */
#define EVSYS_NONSECUSER1_USER45(value)       (EVSYS_NONSECUSER1_USER45_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER45_Pos)) /* Assigment of value for USER45 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER46_Pos          _UINT32_(14)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 46 Position */
#define EVSYS_NONSECUSER1_USER46_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER46_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 46 Mask */
#define EVSYS_NONSECUSER1_USER46(value)       (EVSYS_NONSECUSER1_USER46_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER46_Pos)) /* Assigment of value for USER46 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER47_Pos          _UINT32_(15)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 47 Position */
#define EVSYS_NONSECUSER1_USER47_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER47_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 47 Mask */
#define EVSYS_NONSECUSER1_USER47(value)       (EVSYS_NONSECUSER1_USER47_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER47_Pos)) /* Assigment of value for USER47 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER48_Pos          _UINT32_(16)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 48 Position */
#define EVSYS_NONSECUSER1_USER48_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER48_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 48 Mask */
#define EVSYS_NONSECUSER1_USER48(value)       (EVSYS_NONSECUSER1_USER48_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER48_Pos)) /* Assigment of value for USER48 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER49_Pos          _UINT32_(17)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 49 Position */
#define EVSYS_NONSECUSER1_USER49_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER49_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 49 Mask */
#define EVSYS_NONSECUSER1_USER49(value)       (EVSYS_NONSECUSER1_USER49_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER49_Pos)) /* Assigment of value for USER49 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER50_Pos          _UINT32_(18)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 50 Position */
#define EVSYS_NONSECUSER1_USER50_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER50_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 50 Mask */
#define EVSYS_NONSECUSER1_USER50(value)       (EVSYS_NONSECUSER1_USER50_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER50_Pos)) /* Assigment of value for USER50 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_USER51_Pos          _UINT32_(19)                                         /* (EVSYS_NONSECUSER1) Non-Secure for User 51 Position */
#define EVSYS_NONSECUSER1_USER51_Msk          (_UINT32_(0x1) << EVSYS_NONSECUSER1_USER51_Pos)      /* (EVSYS_NONSECUSER1) Non-Secure for User 51 Mask */
#define EVSYS_NONSECUSER1_USER51(value)       (EVSYS_NONSECUSER1_USER51_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER51_Pos)) /* Assigment of value for USER51 in the EVSYS_NONSECUSER1 register */
#define EVSYS_NONSECUSER1_Msk                 _UINT32_(0x000FFFFF)                                 /* (EVSYS_NONSECUSER1) Register Mask  */

#define EVSYS_NONSECUSER1_USER_Pos            _UINT32_(0)                                          /* (EVSYS_NONSECUSER1 Position) Non-Secure for User 5x */
#define EVSYS_NONSECUSER1_USER_Msk            (_UINT32_(0xFFFFF) << EVSYS_NONSECUSER1_USER_Pos)    /* (EVSYS_NONSECUSER1 Mask) USER */
#define EVSYS_NONSECUSER1_USER(value)         (EVSYS_NONSECUSER1_USER_Msk & (_UINT32_(value) << EVSYS_NONSECUSER1_USER_Pos)) 

/* -------- EVSYS_NSCHKUSER0 : (EVSYS Offset: 0x1F0) (R/W 32) Non-Secure Users Check -------- */
#define EVSYS_NSCHKUSER0_RESETVALUE           _UINT32_(0x00)                                       /*  (EVSYS_NSCHKUSER0) Non-Secure Users Check  Reset Value */

#define EVSYS_NSCHKUSER0_USER0_Pos            _UINT32_(0)                                          /* (EVSYS_NSCHKUSER0) User 0 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER0_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER0_Pos)        /* (EVSYS_NSCHKUSER0) User 0 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER0(value)         (EVSYS_NSCHKUSER0_USER0_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER0_Pos)) /* Assigment of value for USER0 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER1_Pos            _UINT32_(1)                                          /* (EVSYS_NSCHKUSER0) User 1 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER1_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER1_Pos)        /* (EVSYS_NSCHKUSER0) User 1 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER1(value)         (EVSYS_NSCHKUSER0_USER1_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER1_Pos)) /* Assigment of value for USER1 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER2_Pos            _UINT32_(2)                                          /* (EVSYS_NSCHKUSER0) User 2 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER2_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER2_Pos)        /* (EVSYS_NSCHKUSER0) User 2 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER2(value)         (EVSYS_NSCHKUSER0_USER2_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER2_Pos)) /* Assigment of value for USER2 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER3_Pos            _UINT32_(3)                                          /* (EVSYS_NSCHKUSER0) User 3 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER3_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER3_Pos)        /* (EVSYS_NSCHKUSER0) User 3 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER3(value)         (EVSYS_NSCHKUSER0_USER3_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER3_Pos)) /* Assigment of value for USER3 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER4_Pos            _UINT32_(4)                                          /* (EVSYS_NSCHKUSER0) User 4 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER4_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER4_Pos)        /* (EVSYS_NSCHKUSER0) User 4 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER4(value)         (EVSYS_NSCHKUSER0_USER4_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER4_Pos)) /* Assigment of value for USER4 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER5_Pos            _UINT32_(5)                                          /* (EVSYS_NSCHKUSER0) User 5 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER5_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER5_Pos)        /* (EVSYS_NSCHKUSER0) User 5 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER5(value)         (EVSYS_NSCHKUSER0_USER5_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER5_Pos)) /* Assigment of value for USER5 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER6_Pos            _UINT32_(6)                                          /* (EVSYS_NSCHKUSER0) User 6 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER6_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER6_Pos)        /* (EVSYS_NSCHKUSER0) User 6 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER6(value)         (EVSYS_NSCHKUSER0_USER6_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER6_Pos)) /* Assigment of value for USER6 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER7_Pos            _UINT32_(7)                                          /* (EVSYS_NSCHKUSER0) User 7 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER7_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER7_Pos)        /* (EVSYS_NSCHKUSER0) User 7 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER7(value)         (EVSYS_NSCHKUSER0_USER7_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER7_Pos)) /* Assigment of value for USER7 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER8_Pos            _UINT32_(8)                                          /* (EVSYS_NSCHKUSER0) User 8 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER8_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER8_Pos)        /* (EVSYS_NSCHKUSER0) User 8 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER8(value)         (EVSYS_NSCHKUSER0_USER8_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER8_Pos)) /* Assigment of value for USER8 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER9_Pos            _UINT32_(9)                                          /* (EVSYS_NSCHKUSER0) User 9 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER9_Msk            (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER9_Pos)        /* (EVSYS_NSCHKUSER0) User 9 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER9(value)         (EVSYS_NSCHKUSER0_USER9_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER9_Pos)) /* Assigment of value for USER9 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER10_Pos           _UINT32_(10)                                         /* (EVSYS_NSCHKUSER0) User 10 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER10_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER10_Pos)       /* (EVSYS_NSCHKUSER0) User 10 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER10(value)        (EVSYS_NSCHKUSER0_USER10_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER10_Pos)) /* Assigment of value for USER10 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER11_Pos           _UINT32_(11)                                         /* (EVSYS_NSCHKUSER0) User 11 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER11_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER11_Pos)       /* (EVSYS_NSCHKUSER0) User 11 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER11(value)        (EVSYS_NSCHKUSER0_USER11_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER11_Pos)) /* Assigment of value for USER11 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER12_Pos           _UINT32_(12)                                         /* (EVSYS_NSCHKUSER0) User 12 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER12_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER12_Pos)       /* (EVSYS_NSCHKUSER0) User 12 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER12(value)        (EVSYS_NSCHKUSER0_USER12_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER12_Pos)) /* Assigment of value for USER12 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER13_Pos           _UINT32_(13)                                         /* (EVSYS_NSCHKUSER0) User 13 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER13_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER13_Pos)       /* (EVSYS_NSCHKUSER0) User 13 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER13(value)        (EVSYS_NSCHKUSER0_USER13_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER13_Pos)) /* Assigment of value for USER13 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER14_Pos           _UINT32_(14)                                         /* (EVSYS_NSCHKUSER0) User 14 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER14_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER14_Pos)       /* (EVSYS_NSCHKUSER0) User 14 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER14(value)        (EVSYS_NSCHKUSER0_USER14_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER14_Pos)) /* Assigment of value for USER14 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER15_Pos           _UINT32_(15)                                         /* (EVSYS_NSCHKUSER0) User 15 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER15_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER15_Pos)       /* (EVSYS_NSCHKUSER0) User 15 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER15(value)        (EVSYS_NSCHKUSER0_USER15_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER15_Pos)) /* Assigment of value for USER15 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER16_Pos           _UINT32_(16)                                         /* (EVSYS_NSCHKUSER0) User 16 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER16_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER16_Pos)       /* (EVSYS_NSCHKUSER0) User 16 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER16(value)        (EVSYS_NSCHKUSER0_USER16_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER16_Pos)) /* Assigment of value for USER16 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER17_Pos           _UINT32_(17)                                         /* (EVSYS_NSCHKUSER0) User 17 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER17_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER17_Pos)       /* (EVSYS_NSCHKUSER0) User 17 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER17(value)        (EVSYS_NSCHKUSER0_USER17_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER17_Pos)) /* Assigment of value for USER17 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER18_Pos           _UINT32_(18)                                         /* (EVSYS_NSCHKUSER0) User 18 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER18_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER18_Pos)       /* (EVSYS_NSCHKUSER0) User 18 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER18(value)        (EVSYS_NSCHKUSER0_USER18_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER18_Pos)) /* Assigment of value for USER18 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER19_Pos           _UINT32_(19)                                         /* (EVSYS_NSCHKUSER0) User 19 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER19_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER19_Pos)       /* (EVSYS_NSCHKUSER0) User 19 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER19(value)        (EVSYS_NSCHKUSER0_USER19_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER19_Pos)) /* Assigment of value for USER19 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER20_Pos           _UINT32_(20)                                         /* (EVSYS_NSCHKUSER0) User 20 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER20_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER20_Pos)       /* (EVSYS_NSCHKUSER0) User 20 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER20(value)        (EVSYS_NSCHKUSER0_USER20_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER20_Pos)) /* Assigment of value for USER20 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER21_Pos           _UINT32_(21)                                         /* (EVSYS_NSCHKUSER0) User 21 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER21_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER21_Pos)       /* (EVSYS_NSCHKUSER0) User 21 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER21(value)        (EVSYS_NSCHKUSER0_USER21_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER21_Pos)) /* Assigment of value for USER21 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER22_Pos           _UINT32_(22)                                         /* (EVSYS_NSCHKUSER0) User 22 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER22_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER22_Pos)       /* (EVSYS_NSCHKUSER0) User 22 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER22(value)        (EVSYS_NSCHKUSER0_USER22_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER22_Pos)) /* Assigment of value for USER22 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER23_Pos           _UINT32_(23)                                         /* (EVSYS_NSCHKUSER0) User 23 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER23_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER23_Pos)       /* (EVSYS_NSCHKUSER0) User 23 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER23(value)        (EVSYS_NSCHKUSER0_USER23_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER23_Pos)) /* Assigment of value for USER23 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER24_Pos           _UINT32_(24)                                         /* (EVSYS_NSCHKUSER0) User 24 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER24_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER24_Pos)       /* (EVSYS_NSCHKUSER0) User 24 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER24(value)        (EVSYS_NSCHKUSER0_USER24_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER24_Pos)) /* Assigment of value for USER24 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER25_Pos           _UINT32_(25)                                         /* (EVSYS_NSCHKUSER0) User 25 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER25_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER25_Pos)       /* (EVSYS_NSCHKUSER0) User 25 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER25(value)        (EVSYS_NSCHKUSER0_USER25_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER25_Pos)) /* Assigment of value for USER25 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER26_Pos           _UINT32_(26)                                         /* (EVSYS_NSCHKUSER0) User 26 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER26_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER26_Pos)       /* (EVSYS_NSCHKUSER0) User 26 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER26(value)        (EVSYS_NSCHKUSER0_USER26_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER26_Pos)) /* Assigment of value for USER26 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER27_Pos           _UINT32_(27)                                         /* (EVSYS_NSCHKUSER0) User 27 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER27_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER27_Pos)       /* (EVSYS_NSCHKUSER0) User 27 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER27(value)        (EVSYS_NSCHKUSER0_USER27_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER27_Pos)) /* Assigment of value for USER27 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER28_Pos           _UINT32_(28)                                         /* (EVSYS_NSCHKUSER0) User 28 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER28_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER28_Pos)       /* (EVSYS_NSCHKUSER0) User 28 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER28(value)        (EVSYS_NSCHKUSER0_USER28_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER28_Pos)) /* Assigment of value for USER28 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER29_Pos           _UINT32_(29)                                         /* (EVSYS_NSCHKUSER0) User 29 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER29_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER29_Pos)       /* (EVSYS_NSCHKUSER0) User 29 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER29(value)        (EVSYS_NSCHKUSER0_USER29_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER29_Pos)) /* Assigment of value for USER29 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER30_Pos           _UINT32_(30)                                         /* (EVSYS_NSCHKUSER0) User 30 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER30_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER30_Pos)       /* (EVSYS_NSCHKUSER0) User 30 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER30(value)        (EVSYS_NSCHKUSER0_USER30_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER30_Pos)) /* Assigment of value for USER30 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_USER31_Pos           _UINT32_(31)                                         /* (EVSYS_NSCHKUSER0) User 31 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER0_USER31_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER0_USER31_Pos)       /* (EVSYS_NSCHKUSER0) User 31 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER0_USER31(value)        (EVSYS_NSCHKUSER0_USER31_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER31_Pos)) /* Assigment of value for USER31 in the EVSYS_NSCHKUSER0 register */
#define EVSYS_NSCHKUSER0_Msk                  _UINT32_(0xFFFFFFFF)                                 /* (EVSYS_NSCHKUSER0) Register Mask  */

#define EVSYS_NSCHKUSER0_USER_Pos             _UINT32_(0)                                          /* (EVSYS_NSCHKUSER0 Position) User 3x to be checked as non-secured */
#define EVSYS_NSCHKUSER0_USER_Msk             (_UINT32_(0xFFFFFFFF) << EVSYS_NSCHKUSER0_USER_Pos)  /* (EVSYS_NSCHKUSER0 Mask) USER */
#define EVSYS_NSCHKUSER0_USER(value)          (EVSYS_NSCHKUSER0_USER_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER0_USER_Pos)) 

/* -------- EVSYS_NSCHKUSER1 : (EVSYS Offset: 0x1F4) (R/W 32) Non-Secure Users Check -------- */
#define EVSYS_NSCHKUSER1_RESETVALUE           _UINT32_(0x00)                                       /*  (EVSYS_NSCHKUSER1) Non-Secure Users Check  Reset Value */

#define EVSYS_NSCHKUSER1_USER32_Pos           _UINT32_(0)                                          /* (EVSYS_NSCHKUSER1) User 32 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER32_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER32_Pos)       /* (EVSYS_NSCHKUSER1) User 32 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER32(value)        (EVSYS_NSCHKUSER1_USER32_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER32_Pos)) /* Assigment of value for USER32 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER33_Pos           _UINT32_(1)                                          /* (EVSYS_NSCHKUSER1) User 33 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER33_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER33_Pos)       /* (EVSYS_NSCHKUSER1) User 33 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER33(value)        (EVSYS_NSCHKUSER1_USER33_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER33_Pos)) /* Assigment of value for USER33 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER34_Pos           _UINT32_(2)                                          /* (EVSYS_NSCHKUSER1) User 34 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER34_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER34_Pos)       /* (EVSYS_NSCHKUSER1) User 34 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER34(value)        (EVSYS_NSCHKUSER1_USER34_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER34_Pos)) /* Assigment of value for USER34 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER35_Pos           _UINT32_(3)                                          /* (EVSYS_NSCHKUSER1) User 35 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER35_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER35_Pos)       /* (EVSYS_NSCHKUSER1) User 35 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER35(value)        (EVSYS_NSCHKUSER1_USER35_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER35_Pos)) /* Assigment of value for USER35 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER36_Pos           _UINT32_(4)                                          /* (EVSYS_NSCHKUSER1) User 36 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER36_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER36_Pos)       /* (EVSYS_NSCHKUSER1) User 36 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER36(value)        (EVSYS_NSCHKUSER1_USER36_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER36_Pos)) /* Assigment of value for USER36 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER37_Pos           _UINT32_(5)                                          /* (EVSYS_NSCHKUSER1) User 37 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER37_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER37_Pos)       /* (EVSYS_NSCHKUSER1) User 37 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER37(value)        (EVSYS_NSCHKUSER1_USER37_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER37_Pos)) /* Assigment of value for USER37 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER38_Pos           _UINT32_(6)                                          /* (EVSYS_NSCHKUSER1) User 38 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER38_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER38_Pos)       /* (EVSYS_NSCHKUSER1) User 38 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER38(value)        (EVSYS_NSCHKUSER1_USER38_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER38_Pos)) /* Assigment of value for USER38 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER39_Pos           _UINT32_(7)                                          /* (EVSYS_NSCHKUSER1) User 39 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER39_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER39_Pos)       /* (EVSYS_NSCHKUSER1) User 39 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER39(value)        (EVSYS_NSCHKUSER1_USER39_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER39_Pos)) /* Assigment of value for USER39 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER40_Pos           _UINT32_(8)                                          /* (EVSYS_NSCHKUSER1) User 40 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER40_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER40_Pos)       /* (EVSYS_NSCHKUSER1) User 40 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER40(value)        (EVSYS_NSCHKUSER1_USER40_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER40_Pos)) /* Assigment of value for USER40 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER41_Pos           _UINT32_(9)                                          /* (EVSYS_NSCHKUSER1) User 41 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER41_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER41_Pos)       /* (EVSYS_NSCHKUSER1) User 41 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER41(value)        (EVSYS_NSCHKUSER1_USER41_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER41_Pos)) /* Assigment of value for USER41 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER42_Pos           _UINT32_(10)                                         /* (EVSYS_NSCHKUSER1) User 42 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER42_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER42_Pos)       /* (EVSYS_NSCHKUSER1) User 42 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER42(value)        (EVSYS_NSCHKUSER1_USER42_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER42_Pos)) /* Assigment of value for USER42 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER43_Pos           _UINT32_(11)                                         /* (EVSYS_NSCHKUSER1) User 43 to be checked as non-secured  Position */
#define EVSYS_NSCHKUSER1_USER43_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER43_Pos)       /* (EVSYS_NSCHKUSER1) User 43 to be checked as non-secured  Mask */
#define EVSYS_NSCHKUSER1_USER43(value)        (EVSYS_NSCHKUSER1_USER43_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER43_Pos)) /* Assigment of value for USER43 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER44_Pos           _UINT32_(12)                                         /* (EVSYS_NSCHKUSER1) User 44 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER44_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER44_Pos)       /* (EVSYS_NSCHKUSER1) User 44 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER44(value)        (EVSYS_NSCHKUSER1_USER44_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER44_Pos)) /* Assigment of value for USER44 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER45_Pos           _UINT32_(13)                                         /* (EVSYS_NSCHKUSER1) User 45 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER45_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER45_Pos)       /* (EVSYS_NSCHKUSER1) User 45 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER45(value)        (EVSYS_NSCHKUSER1_USER45_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER45_Pos)) /* Assigment of value for USER45 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER46_Pos           _UINT32_(14)                                         /* (EVSYS_NSCHKUSER1) User 46 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER46_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER46_Pos)       /* (EVSYS_NSCHKUSER1) User 46 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER46(value)        (EVSYS_NSCHKUSER1_USER46_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER46_Pos)) /* Assigment of value for USER46 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER47_Pos           _UINT32_(15)                                         /* (EVSYS_NSCHKUSER1) User 47 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER47_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER47_Pos)       /* (EVSYS_NSCHKUSER1) User 47 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER47(value)        (EVSYS_NSCHKUSER1_USER47_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER47_Pos)) /* Assigment of value for USER47 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER48_Pos           _UINT32_(16)                                         /* (EVSYS_NSCHKUSER1) User 48 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER48_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER48_Pos)       /* (EVSYS_NSCHKUSER1) User 48 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER48(value)        (EVSYS_NSCHKUSER1_USER48_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER48_Pos)) /* Assigment of value for USER48 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER49_Pos           _UINT32_(17)                                         /* (EVSYS_NSCHKUSER1) User 49 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER49_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER49_Pos)       /* (EVSYS_NSCHKUSER1) User 49 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER49(value)        (EVSYS_NSCHKUSER1_USER49_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER49_Pos)) /* Assigment of value for USER49 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER50_Pos           _UINT32_(18)                                         /* (EVSYS_NSCHKUSER1) User 50 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER50_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER50_Pos)       /* (EVSYS_NSCHKUSER1) User 50 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER50(value)        (EVSYS_NSCHKUSER1_USER50_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER50_Pos)) /* Assigment of value for USER50 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_USER51_Pos           _UINT32_(19)                                         /* (EVSYS_NSCHKUSER1) User 51 to be checked as non-secured Position */
#define EVSYS_NSCHKUSER1_USER51_Msk           (_UINT32_(0x1) << EVSYS_NSCHKUSER1_USER51_Pos)       /* (EVSYS_NSCHKUSER1) User 51 to be checked as non-secured Mask */
#define EVSYS_NSCHKUSER1_USER51(value)        (EVSYS_NSCHKUSER1_USER51_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER51_Pos)) /* Assigment of value for USER51 in the EVSYS_NSCHKUSER1 register */
#define EVSYS_NSCHKUSER1_Msk                  _UINT32_(0x000FFFFF)                                 /* (EVSYS_NSCHKUSER1) Register Mask  */

#define EVSYS_NSCHKUSER1_USER_Pos             _UINT32_(0)                                          /* (EVSYS_NSCHKUSER1 Position) User 5x to be checked as non-secured */
#define EVSYS_NSCHKUSER1_USER_Msk             (_UINT32_(0xFFFFF) << EVSYS_NSCHKUSER1_USER_Pos)     /* (EVSYS_NSCHKUSER1 Mask) USER */
#define EVSYS_NSCHKUSER1_USER(value)          (EVSYS_NSCHKUSER1_USER_Msk & (_UINT32_(value) << EVSYS_NSCHKUSER1_USER_Pos)) 

/** \brief EVSYS register offsets definitions */
#define EVSYS_CHANNEL_REG_OFST         _UINT32_(0x00)      /* (EVSYS_CHANNEL) Channel n Control Offset */
#define EVSYS_CHINTENCLR_REG_OFST      _UINT32_(0x04)      /* (EVSYS_CHINTENCLR) Channel n Interrupt Enable Clear Offset */
#define EVSYS_CHINTENSET_REG_OFST      _UINT32_(0x05)      /* (EVSYS_CHINTENSET) Channel n Interrupt Enable Set Offset */
#define EVSYS_CHINTFLAG_REG_OFST       _UINT32_(0x06)      /* (EVSYS_CHINTFLAG) Channel n Interrupt Flag Status and Clear Offset */
#define EVSYS_CHSTATUS_REG_OFST        _UINT32_(0x07)      /* (EVSYS_CHSTATUS) Channel n Status Offset */
#define EVSYS_CTRLA_REG_OFST           _UINT32_(0x00)      /* (EVSYS_CTRLA) Control Offset */
#define EVSYS_SWEVT_REG_OFST           _UINT32_(0x04)      /* (EVSYS_SWEVT) Software Event Offset */
#define EVSYS_PRICTRL_REG_OFST         _UINT32_(0x08)      /* (EVSYS_PRICTRL) Priority Control Offset */
#define EVSYS_INTPEND_REG_OFST         _UINT32_(0x10)      /* (EVSYS_INTPEND) Channel Pending Interrupt Offset */
#define EVSYS_INTSTATUS_REG_OFST       _UINT32_(0x14)      /* (EVSYS_INTSTATUS) Interrupt Status Offset */
#define EVSYS_BUSYCH_REG_OFST          _UINT32_(0x18)      /* (EVSYS_BUSYCH) Busy Channels Offset */
#define EVSYS_READYUSR_REG_OFST        _UINT32_(0x1C)      /* (EVSYS_READYUSR) Ready Users Offset */
#define EVSYS_USER_REG_OFST            _UINT32_(0x120)     /* (EVSYS_USER) User Multiplexer n Offset */
#define EVSYS_USER0_REG_OFST           _UINT32_(0x120)     /* (EVSYS_USER0) User Multiplexer n Offset */
#define EVSYS_USER1_REG_OFST           _UINT32_(0x121)     /* (EVSYS_USER1) User Multiplexer n Offset */
#define EVSYS_USER2_REG_OFST           _UINT32_(0x122)     /* (EVSYS_USER2) User Multiplexer n Offset */
#define EVSYS_USER3_REG_OFST           _UINT32_(0x123)     /* (EVSYS_USER3) User Multiplexer n Offset */
#define EVSYS_USER4_REG_OFST           _UINT32_(0x124)     /* (EVSYS_USER4) User Multiplexer n Offset */
#define EVSYS_USER5_REG_OFST           _UINT32_(0x125)     /* (EVSYS_USER5) User Multiplexer n Offset */
#define EVSYS_USER6_REG_OFST           _UINT32_(0x126)     /* (EVSYS_USER6) User Multiplexer n Offset */
#define EVSYS_USER7_REG_OFST           _UINT32_(0x127)     /* (EVSYS_USER7) User Multiplexer n Offset */
#define EVSYS_USER8_REG_OFST           _UINT32_(0x128)     /* (EVSYS_USER8) User Multiplexer n Offset */
#define EVSYS_USER9_REG_OFST           _UINT32_(0x129)     /* (EVSYS_USER9) User Multiplexer n Offset */
#define EVSYS_USER10_REG_OFST          _UINT32_(0x12A)     /* (EVSYS_USER10) User Multiplexer n Offset */
#define EVSYS_USER11_REG_OFST          _UINT32_(0x12B)     /* (EVSYS_USER11) User Multiplexer n Offset */
#define EVSYS_USER12_REG_OFST          _UINT32_(0x12C)     /* (EVSYS_USER12) User Multiplexer n Offset */
#define EVSYS_USER13_REG_OFST          _UINT32_(0x12D)     /* (EVSYS_USER13) User Multiplexer n Offset */
#define EVSYS_USER14_REG_OFST          _UINT32_(0x12E)     /* (EVSYS_USER14) User Multiplexer n Offset */
#define EVSYS_USER15_REG_OFST          _UINT32_(0x12F)     /* (EVSYS_USER15) User Multiplexer n Offset */
#define EVSYS_USER16_REG_OFST          _UINT32_(0x130)     /* (EVSYS_USER16) User Multiplexer n Offset */
#define EVSYS_USER17_REG_OFST          _UINT32_(0x131)     /* (EVSYS_USER17) User Multiplexer n Offset */
#define EVSYS_USER18_REG_OFST          _UINT32_(0x132)     /* (EVSYS_USER18) User Multiplexer n Offset */
#define EVSYS_USER19_REG_OFST          _UINT32_(0x133)     /* (EVSYS_USER19) User Multiplexer n Offset */
#define EVSYS_USER20_REG_OFST          _UINT32_(0x134)     /* (EVSYS_USER20) User Multiplexer n Offset */
#define EVSYS_USER21_REG_OFST          _UINT32_(0x135)     /* (EVSYS_USER21) User Multiplexer n Offset */
#define EVSYS_USER22_REG_OFST          _UINT32_(0x136)     /* (EVSYS_USER22) User Multiplexer n Offset */
#define EVSYS_USER23_REG_OFST          _UINT32_(0x137)     /* (EVSYS_USER23) User Multiplexer n Offset */
#define EVSYS_USER24_REG_OFST          _UINT32_(0x138)     /* (EVSYS_USER24) User Multiplexer n Offset */
#define EVSYS_USER25_REG_OFST          _UINT32_(0x139)     /* (EVSYS_USER25) User Multiplexer n Offset */
#define EVSYS_USER26_REG_OFST          _UINT32_(0x13A)     /* (EVSYS_USER26) User Multiplexer n Offset */
#define EVSYS_USER27_REG_OFST          _UINT32_(0x13B)     /* (EVSYS_USER27) User Multiplexer n Offset */
#define EVSYS_USER28_REG_OFST          _UINT32_(0x13C)     /* (EVSYS_USER28) User Multiplexer n Offset */
#define EVSYS_USER29_REG_OFST          _UINT32_(0x13D)     /* (EVSYS_USER29) User Multiplexer n Offset */
#define EVSYS_USER30_REG_OFST          _UINT32_(0x13E)     /* (EVSYS_USER30) User Multiplexer n Offset */
#define EVSYS_USER31_REG_OFST          _UINT32_(0x13F)     /* (EVSYS_USER31) User Multiplexer n Offset */
#define EVSYS_USER32_REG_OFST          _UINT32_(0x140)     /* (EVSYS_USER32) User Multiplexer n Offset */
#define EVSYS_USER33_REG_OFST          _UINT32_(0x141)     /* (EVSYS_USER33) User Multiplexer n Offset */
#define EVSYS_USER34_REG_OFST          _UINT32_(0x142)     /* (EVSYS_USER34) User Multiplexer n Offset */
#define EVSYS_USER35_REG_OFST          _UINT32_(0x143)     /* (EVSYS_USER35) User Multiplexer n Offset */
#define EVSYS_USER36_REG_OFST          _UINT32_(0x144)     /* (EVSYS_USER36) User Multiplexer n Offset */
#define EVSYS_USER37_REG_OFST          _UINT32_(0x145)     /* (EVSYS_USER37) User Multiplexer n Offset */
#define EVSYS_USER38_REG_OFST          _UINT32_(0x146)     /* (EVSYS_USER38) User Multiplexer n Offset */
#define EVSYS_USER39_REG_OFST          _UINT32_(0x147)     /* (EVSYS_USER39) User Multiplexer n Offset */
#define EVSYS_USER40_REG_OFST          _UINT32_(0x148)     /* (EVSYS_USER40) User Multiplexer n Offset */
#define EVSYS_USER41_REG_OFST          _UINT32_(0x149)     /* (EVSYS_USER41) User Multiplexer n Offset */
#define EVSYS_USER42_REG_OFST          _UINT32_(0x14A)     /* (EVSYS_USER42) User Multiplexer n Offset */
#define EVSYS_USER43_REG_OFST          _UINT32_(0x14B)     /* (EVSYS_USER43) User Multiplexer n Offset */
#define EVSYS_USER44_REG_OFST          _UINT32_(0x14C)     /* (EVSYS_USER44) User Multiplexer n Offset */
#define EVSYS_USER45_REG_OFST          _UINT32_(0x14D)     /* (EVSYS_USER45) User Multiplexer n Offset */
#define EVSYS_USER46_REG_OFST          _UINT32_(0x14E)     /* (EVSYS_USER46) User Multiplexer n Offset */
#define EVSYS_USER47_REG_OFST          _UINT32_(0x14F)     /* (EVSYS_USER47) User Multiplexer n Offset */
#define EVSYS_USER48_REG_OFST          _UINT32_(0x150)     /* (EVSYS_USER48) User Multiplexer n Offset */
#define EVSYS_USER49_REG_OFST          _UINT32_(0x151)     /* (EVSYS_USER49) User Multiplexer n Offset */
#define EVSYS_USER50_REG_OFST          _UINT32_(0x152)     /* (EVSYS_USER50) User Multiplexer n Offset */
#define EVSYS_USER51_REG_OFST          _UINT32_(0x153)     /* (EVSYS_USER51) User Multiplexer n Offset */
#define EVSYS_INTENCLR_REG_OFST        _UINT32_(0x1D4)     /* (EVSYS_INTENCLR) Interrupt Enable Clear Offset */
#define EVSYS_INTENSET_REG_OFST        _UINT32_(0x1D5)     /* (EVSYS_INTENSET) Interrupt Enable Set Offset */
#define EVSYS_INTFLAG_REG_OFST         _UINT32_(0x1D6)     /* (EVSYS_INTFLAG) Interrupt Flag Status and Clear Offset */
#define EVSYS_NONSECCHAN_REG_OFST      _UINT32_(0x1D8)     /* (EVSYS_NONSECCHAN) Channels Security Attribution Offset */
#define EVSYS_NSCHKCHAN_REG_OFST       _UINT32_(0x1DC)     /* (EVSYS_NSCHKCHAN) Non-Secure Channels Check Offset */
#define EVSYS_NONSECUSER0_REG_OFST     _UINT32_(0x1E0)     /* (EVSYS_NONSECUSER0) Users Security Attribution Offset */
#define EVSYS_NONSECUSER1_REG_OFST     _UINT32_(0x1E4)     /* (EVSYS_NONSECUSER1) Users Security Attribution Offset */
#define EVSYS_NSCHKUSER0_REG_OFST      _UINT32_(0x1F0)     /* (EVSYS_NSCHKUSER0) Non-Secure Users Check Offset */
#define EVSYS_NSCHKUSER1_REG_OFST      _UINT32_(0x1F4)     /* (EVSYS_NSCHKUSER1) Non-Secure Users Check Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CHANNEL register API structure */
typedef struct
{
  __IO  uint32_t                       EVSYS_CHANNEL;      /**< Offset: 0x00 (R/W  32) Channel n Control */
  __IO  uint8_t                        EVSYS_CHINTENCLR;   /**< Offset: 0x04 (R/W  8) Channel n Interrupt Enable Clear */
  __IO  uint8_t                        EVSYS_CHINTENSET;   /**< Offset: 0x05 (R/W  8) Channel n Interrupt Enable Set */
  __IO  uint8_t                        EVSYS_CHINTFLAG;    /**< Offset: 0x06 (R/W  8) Channel n Interrupt Flag Status and Clear */
  __I   uint8_t                        EVSYS_CHSTATUS;     /**< Offset: 0x07 (R/   8) Channel n Status */
} evsys_channel_registers_t;

#define EVSYS_CHANNEL_NUMBER 12

/** \brief EVSYS register API structure */
typedef struct
{  /* Event System Interface */
  __O   uint8_t                        EVSYS_CTRLA;        /**< Offset: 0x00 ( /W  8) Control */
  __I   uint8_t                        Reserved1[0x03];
  __O   uint32_t                       EVSYS_SWEVT;        /**< Offset: 0x04 ( /W  32) Software Event */
  __IO  uint8_t                        EVSYS_PRICTRL;      /**< Offset: 0x08 (R/W  8) Priority Control */
  __I   uint8_t                        Reserved2[0x07];
  __IO  uint16_t                       EVSYS_INTPEND;      /**< Offset: 0x10 (R/W  16) Channel Pending Interrupt */
  __I   uint8_t                        Reserved3[0x02];
  __I   uint32_t                       EVSYS_INTSTATUS;    /**< Offset: 0x14 (R/   32) Interrupt Status */
  __I   uint32_t                       EVSYS_BUSYCH;       /**< Offset: 0x18 (R/   32) Busy Channels */
  __I   uint32_t                       EVSYS_READYUSR;     /**< Offset: 0x1C (R/   32) Ready Users */
        evsys_channel_registers_t      CHANNEL[EVSYS_CHANNEL_NUMBER]; /**< Offset: 0x20  */
  __I   uint8_t                        Reserved4[0xA0];
  __IO  uint8_t                        EVSYS_USER[52];     /**< Offset: 0x120 (R/W  8) User Multiplexer n */
  __I   uint8_t                        Reserved5[0x80];
  __IO  uint8_t                        EVSYS_INTENCLR;     /**< Offset: 0x1D4 (R/W  8) Interrupt Enable Clear */
  __IO  uint8_t                        EVSYS_INTENSET;     /**< Offset: 0x1D5 (R/W  8) Interrupt Enable Set */
  __IO  uint8_t                        EVSYS_INTFLAG;      /**< Offset: 0x1D6 (R/W  8) Interrupt Flag Status and Clear */
  __I   uint8_t                        Reserved6[0x01];
  __IO  uint32_t                       EVSYS_NONSECCHAN;   /**< Offset: 0x1D8 (R/W  32) Channels Security Attribution */
  __IO  uint32_t                       EVSYS_NSCHKCHAN;    /**< Offset: 0x1DC (R/W  32) Non-Secure Channels Check */
  __IO  uint32_t                       EVSYS_NONSECUSER0;  /**< Offset: 0x1E0 (R/W  32) Users Security Attribution */
  __IO  uint32_t                       EVSYS_NONSECUSER1;  /**< Offset: 0x1E4 (R/W  32) Users Security Attribution */
  __I   uint8_t                        Reserved7[0x08];
  __IO  uint32_t                       EVSYS_NSCHKUSER0;   /**< Offset: 0x1F0 (R/W  32) Non-Secure Users Check */
  __IO  uint32_t                       EVSYS_NSCHKUSER1;   /**< Offset: 0x1F4 (R/W  32) Non-Secure Users Check */
} evsys_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMLS60_EVSYS_COMPONENT_H_ */
