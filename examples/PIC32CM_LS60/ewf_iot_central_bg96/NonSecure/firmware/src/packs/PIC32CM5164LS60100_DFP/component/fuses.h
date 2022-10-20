/*
 * Component description for FUSES
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
#ifndef _PIC32CMLS60_FUSES_COMPONENT_H_
#define _PIC32CMLS60_FUSES_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FUSES                                        */
/* ************************************************************************** */

/* -------- FUSES_SW_CALIB_WORD_0 : (FUSES Offset: 0x00) ( R/ 32) SW_CALIB Page Word 0 -------- */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Pos _UINT32_(0)                                          /* (FUSES_SW_CALIB_WORD_0) ADC Bias Reference Buffer Scaling Position */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Msk (_UINT32_(0x7) << FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Pos) /* (FUSES_SW_CALIB_WORD_0) ADC Bias Reference Buffer Scaling Mask */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF(value) (FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_ADC_BIASREFBUF_Pos)) /* Assigment of value for ADC_BIASREFBUF in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Pos _UINT32_(3)                                          /* (FUSES_SW_CALIB_WORD_0) ADC Comparator Scaling Position */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Msk (_UINT32_(0x7) << FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Pos) /* (FUSES_SW_CALIB_WORD_0) ADC Comparator Scaling Mask */
#define FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP(value) (FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_ADC_BIASCOMP_Pos)) /* Assigment of value for ADC_BIASCOMP in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Pos _UINT32_(6)                                          /* (FUSES_SW_CALIB_WORD_0) DFLLULP DIV at PL0 Position */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Msk (_UINT32_(0x7) << FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Pos) /* (FUSES_SW_CALIB_WORD_0) DFLLULP DIV at PL0 Mask */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0(value) (FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL0_Pos)) /* Assigment of value for DFLLULP_DIV_PL0 in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Pos _UINT32_(9)                                          /* (FUSES_SW_CALIB_WORD_0) DFLLULP DIV at PL2 Position */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Msk (_UINT32_(0x7) << FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Pos) /* (FUSES_SW_CALIB_WORD_0) DFLLULP DIV at PL2 Mask */
#define FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2(value) (FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_DFLLULP_DIV_PL2_Pos)) /* Assigment of value for DFLLULP_DIV_PL2 in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_USB_TRANSN_Pos  _UINT32_(12)                                         /* (FUSES_SW_CALIB_WORD_0) USB pad Transn calibration Position */
#define FUSES_SW_CALIB_WORD_0_USB_TRANSN_Msk  (_UINT32_(0x1F) << FUSES_SW_CALIB_WORD_0_USB_TRANSN_Pos) /* (FUSES_SW_CALIB_WORD_0) USB pad Transn calibration Mask */
#define FUSES_SW_CALIB_WORD_0_USB_TRANSN(value) (FUSES_SW_CALIB_WORD_0_USB_TRANSN_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_USB_TRANSN_Pos)) /* Assigment of value for USB_TRANSN in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_USB_TRANSP_Pos  _UINT32_(17)                                         /* (FUSES_SW_CALIB_WORD_0) USB pad Transp calibration Position */
#define FUSES_SW_CALIB_WORD_0_USB_TRANSP_Msk  (_UINT32_(0x1F) << FUSES_SW_CALIB_WORD_0_USB_TRANSP_Pos) /* (FUSES_SW_CALIB_WORD_0) USB pad Transp calibration Mask */
#define FUSES_SW_CALIB_WORD_0_USB_TRANSP(value) (FUSES_SW_CALIB_WORD_0_USB_TRANSP_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_USB_TRANSP_Pos)) /* Assigment of value for USB_TRANSP in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_USB_TRIM_Pos    _UINT32_(22)                                         /* (FUSES_SW_CALIB_WORD_0) USB pad Trim calibration Position */
#define FUSES_SW_CALIB_WORD_0_USB_TRIM_Msk    (_UINT32_(0x7) << FUSES_SW_CALIB_WORD_0_USB_TRIM_Pos) /* (FUSES_SW_CALIB_WORD_0) USB pad Trim calibration Mask */
#define FUSES_SW_CALIB_WORD_0_USB_TRIM(value) (FUSES_SW_CALIB_WORD_0_USB_TRIM_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_USB_TRIM_Pos)) /* Assigment of value for USB_TRIM in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_DFLL48M_COARSE_CAL_Pos _UINT32_(25)                                         /* (FUSES_SW_CALIB_WORD_0) DFLL48M Coarse Calibration Position */
#define FUSES_SW_CALIB_WORD_0_DFLL48M_COARSE_CAL_Msk (_UINT32_(0x3F) << FUSES_SW_CALIB_WORD_0_DFLL48M_COARSE_CAL_Pos) /* (FUSES_SW_CALIB_WORD_0) DFLL48M Coarse Calibration Mask */
#define FUSES_SW_CALIB_WORD_0_DFLL48M_COARSE_CAL(value) (FUSES_SW_CALIB_WORD_0_DFLL48M_COARSE_CAL_Msk & (_UINT32_(value) << FUSES_SW_CALIB_WORD_0_DFLL48M_COARSE_CAL_Pos)) /* Assigment of value for DFLL48M_COARSE_CAL in the FUSES_SW_CALIB_WORD_0 register */
#define FUSES_SW_CALIB_WORD_0_Msk             _UINT32_(0x7FFFFFFF)                                 /* (FUSES_SW_CALIB_WORD_0) Register Mask  */


/* -------- FUSES_BOCOR_WORD_0 : (FUSES Offset: 0x00) (R/W 32) BOCOR Page Word 0 -------- */
#define FUSES_BOCOR_WORD_0_RESETVALUE         _UINT32_(0xF007FFFF)                                 /*  (FUSES_BOCOR_WORD_0) BOCOR Page Word 0  Reset Value */

#define FUSES_BOCOR_WORD_0_IDAU_BNSC_Pos      _UINT32_(19)                                         /* (FUSES_BOCOR_WORD_0) Boot Non-Secure Callable Position */
#define FUSES_BOCOR_WORD_0_IDAU_BNSC_Msk      (_UINT32_(0x1FF) << FUSES_BOCOR_WORD_0_IDAU_BNSC_Pos) /* (FUSES_BOCOR_WORD_0) Boot Non-Secure Callable Mask */
#define FUSES_BOCOR_WORD_0_IDAU_BNSC(value)   (FUSES_BOCOR_WORD_0_IDAU_BNSC_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_0_IDAU_BNSC_Pos)) /* Assigment of value for IDAU_BNSC in the FUSES_BOCOR_WORD_0 register */
#define FUSES_BOCOR_WORD_0_Msk                _UINT32_(0x0FF80000)                                 /* (FUSES_BOCOR_WORD_0) Register Mask  */


/* -------- FUSES_BOCOR_WORD_1 : (FUSES Offset: 0x04) (R/W 32) BOCOR Page Word 1 -------- */
#define FUSES_BOCOR_WORD_1_RESETVALUE         _UINT32_(0xFFE80000)                                 /*  (FUSES_BOCOR_WORD_1) BOCOR Page Word 1  Reset Value */

#define FUSES_BOCOR_WORD_1_BOOTROM_BOOTOPT_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_1) Boot Option Position */
#define FUSES_BOCOR_WORD_1_BOOTROM_BOOTOPT_Msk (_UINT32_(0xFF) << FUSES_BOCOR_WORD_1_BOOTROM_BOOTOPT_Pos) /* (FUSES_BOCOR_WORD_1) Boot Option Mask */
#define FUSES_BOCOR_WORD_1_BOOTROM_BOOTOPT(value) (FUSES_BOCOR_WORD_1_BOOTROM_BOOTOPT_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_1_BOOTROM_BOOTOPT_Pos)) /* Assigment of value for BOOTROM_BOOTOPT in the FUSES_BOCOR_WORD_1 register */
#define FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Pos  _UINT32_(8)                                          /* (FUSES_BOCOR_WORD_1) Boot Protection Position */
#define FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Msk  (_UINT32_(0x7FF) << FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Pos) /* (FUSES_BOCOR_WORD_1) Boot Protection Mask */
#define FUSES_BOCOR_WORD_1_IDAU_BOOTPROT(value) (FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_1_IDAU_BOOTPROT_Pos)) /* Assigment of value for IDAU_BOOTPROT in the FUSES_BOCOR_WORD_1 register */
#define FUSES_BOCOR_WORD_1_BOOTROM_SECCFGLOCK_Pos _UINT32_(19)                                         /* (FUSES_BOCOR_WORD_1) Security Configuration Lock Position */
#define FUSES_BOCOR_WORD_1_BOOTROM_SECCFGLOCK_Msk (_UINT32_(0x1) << FUSES_BOCOR_WORD_1_BOOTROM_SECCFGLOCK_Pos) /* (FUSES_BOCOR_WORD_1) Security Configuration Lock Mask */
#define FUSES_BOCOR_WORD_1_BOOTROM_SECCFGLOCK(value) (FUSES_BOCOR_WORD_1_BOOTROM_SECCFGLOCK_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_1_BOOTROM_SECCFGLOCK_Pos)) /* Assigment of value for BOOTROM_SECCFGLOCK in the FUSES_BOCOR_WORD_1 register */
#define FUSES_BOCOR_WORD_1_BOOTROM_DICEEN_Pos _UINT32_(20)                                         /* (FUSES_BOCOR_WORD_1) DICE Enable Position */
#define FUSES_BOCOR_WORD_1_BOOTROM_DICEEN_Msk (_UINT32_(0x1) << FUSES_BOCOR_WORD_1_BOOTROM_DICEEN_Pos) /* (FUSES_BOCOR_WORD_1) DICE Enable Mask */
#define FUSES_BOCOR_WORD_1_BOOTROM_DICEEN(value) (FUSES_BOCOR_WORD_1_BOOTROM_DICEEN_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_1_BOOTROM_DICEEN_Pos)) /* Assigment of value for BOOTROM_DICEEN in the FUSES_BOCOR_WORD_1 register */
#define FUSES_BOCOR_WORD_1_NVMCTRL_BCWEN_Pos  _UINT32_(24)                                         /* (FUSES_BOCOR_WORD_1) Boot Configuration Write Enable Position */
#define FUSES_BOCOR_WORD_1_NVMCTRL_BCWEN_Msk  (_UINT32_(0x1) << FUSES_BOCOR_WORD_1_NVMCTRL_BCWEN_Pos) /* (FUSES_BOCOR_WORD_1) Boot Configuration Write Enable Mask */
#define FUSES_BOCOR_WORD_1_NVMCTRL_BCWEN(value) (FUSES_BOCOR_WORD_1_NVMCTRL_BCWEN_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_1_NVMCTRL_BCWEN_Pos)) /* Assigment of value for NVMCTRL_BCWEN in the FUSES_BOCOR_WORD_1 register */
#define FUSES_BOCOR_WORD_1_NVMCTRL_BCREN_Pos  _UINT32_(25)                                         /* (FUSES_BOCOR_WORD_1) Boot Configuration Read Enable Position */
#define FUSES_BOCOR_WORD_1_NVMCTRL_BCREN_Msk  (_UINT32_(0x1) << FUSES_BOCOR_WORD_1_NVMCTRL_BCREN_Pos) /* (FUSES_BOCOR_WORD_1) Boot Configuration Read Enable Mask */
#define FUSES_BOCOR_WORD_1_NVMCTRL_BCREN(value) (FUSES_BOCOR_WORD_1_NVMCTRL_BCREN_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_1_NVMCTRL_BCREN_Pos)) /* Assigment of value for NVMCTRL_BCREN in the FUSES_BOCOR_WORD_1 register */
#define FUSES_BOCOR_WORD_1_Msk                _UINT32_(0x031FFFFF)                                 /* (FUSES_BOCOR_WORD_1) Register Mask  */


/* -------- FUSES_BOCOR_WORD_2 : (FUSES Offset: 0x08) (R/W 32) BOCOR Page Word 2 -------- */
#define FUSES_BOCOR_WORD_2_RESETVALUE         _UINT32_(0xC0349ACC)                                 /*  (FUSES_BOCOR_WORD_2) BOCOR Page Word 2  Reset Value */

#define FUSES_BOCOR_WORD_2_BOOTROM_BOCORCRC_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_2) CRC for BOCOR0 DWORD Position */
#define FUSES_BOCOR_WORD_2_BOOTROM_BOCORCRC_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_2_BOOTROM_BOCORCRC_Pos) /* (FUSES_BOCOR_WORD_2) CRC for BOCOR0 DWORD Mask */
#define FUSES_BOCOR_WORD_2_BOOTROM_BOCORCRC(value) (FUSES_BOCOR_WORD_2_BOOTROM_BOCORCRC_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_2_BOOTROM_BOCORCRC_Pos)) /* Assigment of value for BOOTROM_BOCORCRC in the FUSES_BOCOR_WORD_2 register */
#define FUSES_BOCOR_WORD_2_Msk                _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_2) Register Mask  */


/* -------- FUSES_BOCOR_WORD_4 : (FUSES Offset: 0x10) (R/W 32) BOCOR Page Word 4 -------- */
#define FUSES_BOCOR_WORD_4_RESETVALUE         _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_4) BOCOR Page Word 4  Reset Value */

#define FUSES_BOCOR_WORD_4_BOOTROM_CEKEY0_0_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_4) Chip Erase Key 0 bits 31:0 Position */
#define FUSES_BOCOR_WORD_4_BOOTROM_CEKEY0_0_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_4_BOOTROM_CEKEY0_0_Pos) /* (FUSES_BOCOR_WORD_4) Chip Erase Key 0 bits 31:0 Mask */
#define FUSES_BOCOR_WORD_4_BOOTROM_CEKEY0_0(value) (FUSES_BOCOR_WORD_4_BOOTROM_CEKEY0_0_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_4_BOOTROM_CEKEY0_0_Pos)) /* Assigment of value for BOOTROM_CEKEY0_0 in the FUSES_BOCOR_WORD_4 register */
#define FUSES_BOCOR_WORD_4_Msk                _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_4) Register Mask  */


/* -------- FUSES_BOCOR_WORD_5 : (FUSES Offset: 0x14) (R/W 32) BOCOR Page Word 5 -------- */
#define FUSES_BOCOR_WORD_5_RESETVALUE         _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_5) BOCOR Page Word 5  Reset Value */

#define FUSES_BOCOR_WORD_5_BOOTROM_CEKEY0_1_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_5) Chip Erase Key 0 bits 63:32 Position */
#define FUSES_BOCOR_WORD_5_BOOTROM_CEKEY0_1_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_5_BOOTROM_CEKEY0_1_Pos) /* (FUSES_BOCOR_WORD_5) Chip Erase Key 0 bits 63:32 Mask */
#define FUSES_BOCOR_WORD_5_BOOTROM_CEKEY0_1(value) (FUSES_BOCOR_WORD_5_BOOTROM_CEKEY0_1_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_5_BOOTROM_CEKEY0_1_Pos)) /* Assigment of value for BOOTROM_CEKEY0_1 in the FUSES_BOCOR_WORD_5 register */
#define FUSES_BOCOR_WORD_5_Msk                _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_5) Register Mask  */


/* -------- FUSES_BOCOR_WORD_6 : (FUSES Offset: 0x18) (R/W 32) BOCOR Page Word 6 -------- */
#define FUSES_BOCOR_WORD_6_RESETVALUE         _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_6) BOCOR Page Word 6  Reset Value */

#define FUSES_BOCOR_WORD_6_BOOTROM_CEKEY0_2_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_6) Chip Erase Key 0 bits 95:64 Position */
#define FUSES_BOCOR_WORD_6_BOOTROM_CEKEY0_2_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_6_BOOTROM_CEKEY0_2_Pos) /* (FUSES_BOCOR_WORD_6) Chip Erase Key 0 bits 95:64 Mask */
#define FUSES_BOCOR_WORD_6_BOOTROM_CEKEY0_2(value) (FUSES_BOCOR_WORD_6_BOOTROM_CEKEY0_2_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_6_BOOTROM_CEKEY0_2_Pos)) /* Assigment of value for BOOTROM_CEKEY0_2 in the FUSES_BOCOR_WORD_6 register */
#define FUSES_BOCOR_WORD_6_Msk                _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_6) Register Mask  */


/* -------- FUSES_BOCOR_WORD_7 : (FUSES Offset: 0x1C) (R/W 32) BOCOR Page Word 7 -------- */
#define FUSES_BOCOR_WORD_7_RESETVALUE         _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_7) BOCOR Page Word 7  Reset Value */

#define FUSES_BOCOR_WORD_7_BOOTROM_CEKEY0_3_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_7) Chip Erase Key 0 bits 127:96 Position */
#define FUSES_BOCOR_WORD_7_BOOTROM_CEKEY0_3_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_7_BOOTROM_CEKEY0_3_Pos) /* (FUSES_BOCOR_WORD_7) Chip Erase Key 0 bits 127:96 Mask */
#define FUSES_BOCOR_WORD_7_BOOTROM_CEKEY0_3(value) (FUSES_BOCOR_WORD_7_BOOTROM_CEKEY0_3_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_7_BOOTROM_CEKEY0_3_Pos)) /* Assigment of value for BOOTROM_CEKEY0_3 in the FUSES_BOCOR_WORD_7 register */
#define FUSES_BOCOR_WORD_7_Msk                _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_7) Register Mask  */


/* -------- FUSES_BOCOR_WORD_8 : (FUSES Offset: 0x20) (R/W 32) BOCOR Page Word 8 -------- */
#define FUSES_BOCOR_WORD_8_RESETVALUE         _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_8) BOCOR Page Word 8  Reset Value */

#define FUSES_BOCOR_WORD_8_BOOTROM_CEKEY1_0_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_8) Chip Erase Key 1 bits 31:0 Position */
#define FUSES_BOCOR_WORD_8_BOOTROM_CEKEY1_0_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_8_BOOTROM_CEKEY1_0_Pos) /* (FUSES_BOCOR_WORD_8) Chip Erase Key 1 bits 31:0 Mask */
#define FUSES_BOCOR_WORD_8_BOOTROM_CEKEY1_0(value) (FUSES_BOCOR_WORD_8_BOOTROM_CEKEY1_0_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_8_BOOTROM_CEKEY1_0_Pos)) /* Assigment of value for BOOTROM_CEKEY1_0 in the FUSES_BOCOR_WORD_8 register */
#define FUSES_BOCOR_WORD_8_Msk                _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_8) Register Mask  */


/* -------- FUSES_BOCOR_WORD_9 : (FUSES Offset: 0x24) (R/W 32) BOCOR Page Word 9 -------- */
#define FUSES_BOCOR_WORD_9_RESETVALUE         _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_9) BOCOR Page Word 9  Reset Value */

#define FUSES_BOCOR_WORD_9_BOOTROM_CEKEY1_1_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_9) Chip Erase Key 1 bits 63:32 Position */
#define FUSES_BOCOR_WORD_9_BOOTROM_CEKEY1_1_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_9_BOOTROM_CEKEY1_1_Pos) /* (FUSES_BOCOR_WORD_9) Chip Erase Key 1 bits 63:32 Mask */
#define FUSES_BOCOR_WORD_9_BOOTROM_CEKEY1_1(value) (FUSES_BOCOR_WORD_9_BOOTROM_CEKEY1_1_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_9_BOOTROM_CEKEY1_1_Pos)) /* Assigment of value for BOOTROM_CEKEY1_1 in the FUSES_BOCOR_WORD_9 register */
#define FUSES_BOCOR_WORD_9_Msk                _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_9) Register Mask  */


/* -------- FUSES_BOCOR_WORD_10 : (FUSES Offset: 0x28) (R/W 32) BOCOR Page Word 10 -------- */
#define FUSES_BOCOR_WORD_10_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_10) BOCOR Page Word 10  Reset Value */

#define FUSES_BOCOR_WORD_10_BOOTROM_CEKEY1_2_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_10) Chip Erase Key 1 bits 95:64 Position */
#define FUSES_BOCOR_WORD_10_BOOTROM_CEKEY1_2_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_10_BOOTROM_CEKEY1_2_Pos) /* (FUSES_BOCOR_WORD_10) Chip Erase Key 1 bits 95:64 Mask */
#define FUSES_BOCOR_WORD_10_BOOTROM_CEKEY1_2(value) (FUSES_BOCOR_WORD_10_BOOTROM_CEKEY1_2_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_10_BOOTROM_CEKEY1_2_Pos)) /* Assigment of value for BOOTROM_CEKEY1_2 in the FUSES_BOCOR_WORD_10 register */
#define FUSES_BOCOR_WORD_10_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_10) Register Mask  */


/* -------- FUSES_BOCOR_WORD_11 : (FUSES Offset: 0x2C) (R/W 32) BOCOR Page Word 11 -------- */
#define FUSES_BOCOR_WORD_11_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_11) BOCOR Page Word 11  Reset Value */

#define FUSES_BOCOR_WORD_11_BOOTROM_CEKEY1_3_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_11) Chip Erase Key 1 bits 127:96 Position */
#define FUSES_BOCOR_WORD_11_BOOTROM_CEKEY1_3_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_11_BOOTROM_CEKEY1_3_Pos) /* (FUSES_BOCOR_WORD_11) Chip Erase Key 1 bits 127:96 Mask */
#define FUSES_BOCOR_WORD_11_BOOTROM_CEKEY1_3(value) (FUSES_BOCOR_WORD_11_BOOTROM_CEKEY1_3_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_11_BOOTROM_CEKEY1_3_Pos)) /* Assigment of value for BOOTROM_CEKEY1_3 in the FUSES_BOCOR_WORD_11 register */
#define FUSES_BOCOR_WORD_11_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_11) Register Mask  */


/* -------- FUSES_BOCOR_WORD_12 : (FUSES Offset: 0x30) (R/W 32) BOCOR Page Word 12 -------- */
#define FUSES_BOCOR_WORD_12_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_12) BOCOR Page Word 12  Reset Value */

#define FUSES_BOCOR_WORD_12_BOOTROM_CEKEY2_0_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_12) Chip Erase Key 2 bits 31:0 Position */
#define FUSES_BOCOR_WORD_12_BOOTROM_CEKEY2_0_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_12_BOOTROM_CEKEY2_0_Pos) /* (FUSES_BOCOR_WORD_12) Chip Erase Key 2 bits 31:0 Mask */
#define FUSES_BOCOR_WORD_12_BOOTROM_CEKEY2_0(value) (FUSES_BOCOR_WORD_12_BOOTROM_CEKEY2_0_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_12_BOOTROM_CEKEY2_0_Pos)) /* Assigment of value for BOOTROM_CEKEY2_0 in the FUSES_BOCOR_WORD_12 register */
#define FUSES_BOCOR_WORD_12_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_12) Register Mask  */


/* -------- FUSES_BOCOR_WORD_13 : (FUSES Offset: 0x34) (R/W 32) BOCOR Page Word 13 -------- */
#define FUSES_BOCOR_WORD_13_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_13) BOCOR Page Word 13  Reset Value */

#define FUSES_BOCOR_WORD_13_BOOTROM_CEKEY2_1_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_13) Chip Erase Key 2 bits 63:32 Position */
#define FUSES_BOCOR_WORD_13_BOOTROM_CEKEY2_1_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_13_BOOTROM_CEKEY2_1_Pos) /* (FUSES_BOCOR_WORD_13) Chip Erase Key 2 bits 63:32 Mask */
#define FUSES_BOCOR_WORD_13_BOOTROM_CEKEY2_1(value) (FUSES_BOCOR_WORD_13_BOOTROM_CEKEY2_1_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_13_BOOTROM_CEKEY2_1_Pos)) /* Assigment of value for BOOTROM_CEKEY2_1 in the FUSES_BOCOR_WORD_13 register */
#define FUSES_BOCOR_WORD_13_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_13) Register Mask  */


/* -------- FUSES_BOCOR_WORD_14 : (FUSES Offset: 0x38) (R/W 32) BOCOR Page Word 14 -------- */
#define FUSES_BOCOR_WORD_14_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_14) BOCOR Page Word 14  Reset Value */

#define FUSES_BOCOR_WORD_14_BOOTROM_CEKEY2_2_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_14) Chip Erase Key 2 bits 95:64 Position */
#define FUSES_BOCOR_WORD_14_BOOTROM_CEKEY2_2_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_14_BOOTROM_CEKEY2_2_Pos) /* (FUSES_BOCOR_WORD_14) Chip Erase Key 2 bits 95:64 Mask */
#define FUSES_BOCOR_WORD_14_BOOTROM_CEKEY2_2(value) (FUSES_BOCOR_WORD_14_BOOTROM_CEKEY2_2_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_14_BOOTROM_CEKEY2_2_Pos)) /* Assigment of value for BOOTROM_CEKEY2_2 in the FUSES_BOCOR_WORD_14 register */
#define FUSES_BOCOR_WORD_14_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_14) Register Mask  */


/* -------- FUSES_BOCOR_WORD_15 : (FUSES Offset: 0x3C) (R/W 32) BOCOR Page Word 15 -------- */
#define FUSES_BOCOR_WORD_15_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_15) BOCOR Page Word 15  Reset Value */

#define FUSES_BOCOR_WORD_15_BOOTROM_CEKEY2_3_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_15) Chip Erase Key 2 bits 127:96 Position */
#define FUSES_BOCOR_WORD_15_BOOTROM_CEKEY2_3_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_15_BOOTROM_CEKEY2_3_Pos) /* (FUSES_BOCOR_WORD_15) Chip Erase Key 2 bits 127:96 Mask */
#define FUSES_BOCOR_WORD_15_BOOTROM_CEKEY2_3(value) (FUSES_BOCOR_WORD_15_BOOTROM_CEKEY2_3_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_15_BOOTROM_CEKEY2_3_Pos)) /* Assigment of value for BOOTROM_CEKEY2_3 in the FUSES_BOCOR_WORD_15 register */
#define FUSES_BOCOR_WORD_15_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_15) Register Mask  */


/* -------- FUSES_BOCOR_WORD_16 : (FUSES Offset: 0x40) (R/W 32) BOCOR Page Word 16 -------- */
#define FUSES_BOCOR_WORD_16_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_16) BOCOR Page Word 16  Reset Value */

#define FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_16) Crc Key bits 31:0 Position */
#define FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Pos) /* (FUSES_BOCOR_WORD_16) Crc Key bits 31:0 Mask */
#define FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0(value) (FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_16_BOOTROM_CRCKEY_0_Pos)) /* Assigment of value for BOOTROM_CRCKEY_0 in the FUSES_BOCOR_WORD_16 register */
#define FUSES_BOCOR_WORD_16_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_16) Register Mask  */


/* -------- FUSES_BOCOR_WORD_17 : (FUSES Offset: 0x44) (R/W 32) BOCOR Page Word 17 -------- */
#define FUSES_BOCOR_WORD_17_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_17) BOCOR Page Word 17  Reset Value */

#define FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_17) Crc Key bits 63:32 Position */
#define FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Pos) /* (FUSES_BOCOR_WORD_17) Crc Key bits 63:32 Mask */
#define FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1(value) (FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_17_BOOTROM_CRCKEY_1_Pos)) /* Assigment of value for BOOTROM_CRCKEY_1 in the FUSES_BOCOR_WORD_17 register */
#define FUSES_BOCOR_WORD_17_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_17) Register Mask  */


/* -------- FUSES_BOCOR_WORD_18 : (FUSES Offset: 0x48) (R/W 32) BOCOR Page Word 18 -------- */
#define FUSES_BOCOR_WORD_18_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_18) BOCOR Page Word 18  Reset Value */

#define FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_18) Crc Key bits 95:64 Position */
#define FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Pos) /* (FUSES_BOCOR_WORD_18) Crc Key bits 95:64 Mask */
#define FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2(value) (FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_18_BOOTROM_CRCKEY_2_Pos)) /* Assigment of value for BOOTROM_CRCKEY_2 in the FUSES_BOCOR_WORD_18 register */
#define FUSES_BOCOR_WORD_18_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_18) Register Mask  */


/* -------- FUSES_BOCOR_WORD_19 : (FUSES Offset: 0x4C) (R/W 32) BOCOR Page Word 19 -------- */
#define FUSES_BOCOR_WORD_19_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_19) BOCOR Page Word 19  Reset Value */

#define FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_19) Crc Key bits 127:96 Position */
#define FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Pos) /* (FUSES_BOCOR_WORD_19) Crc Key bits 127:96 Mask */
#define FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3(value) (FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_19_BOOTROM_CRCKEY_3_Pos)) /* Assigment of value for BOOTROM_CRCKEY_3 in the FUSES_BOCOR_WORD_19 register */
#define FUSES_BOCOR_WORD_19_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_19) Register Mask  */


/* -------- FUSES_BOCOR_WORD_20 : (FUSES Offset: 0x50) (R/W 32) BOCOR Page Word 20 -------- */
#define FUSES_BOCOR_WORD_20_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_20) BOCOR Page Word 20  Reset Value */

#define FUSES_BOCOR_WORD_20_BOOTROM_BOOTKEY_0_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_20) Secure Boot Key bits 31:0 Position */
#define FUSES_BOCOR_WORD_20_BOOTROM_BOOTKEY_0_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_20_BOOTROM_BOOTKEY_0_Pos) /* (FUSES_BOCOR_WORD_20) Secure Boot Key bits 31:0 Mask */
#define FUSES_BOCOR_WORD_20_BOOTROM_BOOTKEY_0(value) (FUSES_BOCOR_WORD_20_BOOTROM_BOOTKEY_0_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_20_BOOTROM_BOOTKEY_0_Pos)) /* Assigment of value for BOOTROM_BOOTKEY_0 in the FUSES_BOCOR_WORD_20 register */
#define FUSES_BOCOR_WORD_20_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_20) Register Mask  */


/* -------- FUSES_BOCOR_WORD_21 : (FUSES Offset: 0x54) (R/W 32) BOCOR Page Word 21 -------- */
#define FUSES_BOCOR_WORD_21_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_21) BOCOR Page Word 21  Reset Value */

#define FUSES_BOCOR_WORD_21_BOOTROM_BOOTKEY_1_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_21) Secure Boot Key bits 63:32 Position */
#define FUSES_BOCOR_WORD_21_BOOTROM_BOOTKEY_1_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_21_BOOTROM_BOOTKEY_1_Pos) /* (FUSES_BOCOR_WORD_21) Secure Boot Key bits 63:32 Mask */
#define FUSES_BOCOR_WORD_21_BOOTROM_BOOTKEY_1(value) (FUSES_BOCOR_WORD_21_BOOTROM_BOOTKEY_1_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_21_BOOTROM_BOOTKEY_1_Pos)) /* Assigment of value for BOOTROM_BOOTKEY_1 in the FUSES_BOCOR_WORD_21 register */
#define FUSES_BOCOR_WORD_21_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_21) Register Mask  */


/* -------- FUSES_BOCOR_WORD_22 : (FUSES Offset: 0x58) (R/W 32) BOCOR Page Word 22 -------- */
#define FUSES_BOCOR_WORD_22_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_22) BOCOR Page Word 22  Reset Value */

#define FUSES_BOCOR_WORD_22_BOOTROM_BOOTKEY_2_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_22) Secure Boot Key bits 95:64 Position */
#define FUSES_BOCOR_WORD_22_BOOTROM_BOOTKEY_2_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_22_BOOTROM_BOOTKEY_2_Pos) /* (FUSES_BOCOR_WORD_22) Secure Boot Key bits 95:64 Mask */
#define FUSES_BOCOR_WORD_22_BOOTROM_BOOTKEY_2(value) (FUSES_BOCOR_WORD_22_BOOTROM_BOOTKEY_2_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_22_BOOTROM_BOOTKEY_2_Pos)) /* Assigment of value for BOOTROM_BOOTKEY_2 in the FUSES_BOCOR_WORD_22 register */
#define FUSES_BOCOR_WORD_22_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_22) Register Mask  */


/* -------- FUSES_BOCOR_WORD_23 : (FUSES Offset: 0x5C) (R/W 32) BOCOR Page Word 23 -------- */
#define FUSES_BOCOR_WORD_23_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_23) BOCOR Page Word 23  Reset Value */

#define FUSES_BOCOR_WORD_23_BOOTROM_BOOTKEY_3_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_23) Secure Boot Key bits 127:96 Position */
#define FUSES_BOCOR_WORD_23_BOOTROM_BOOTKEY_3_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_23_BOOTROM_BOOTKEY_3_Pos) /* (FUSES_BOCOR_WORD_23) Secure Boot Key bits 127:96 Mask */
#define FUSES_BOCOR_WORD_23_BOOTROM_BOOTKEY_3(value) (FUSES_BOCOR_WORD_23_BOOTROM_BOOTKEY_3_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_23_BOOTROM_BOOTKEY_3_Pos)) /* Assigment of value for BOOTROM_BOOTKEY_3 in the FUSES_BOCOR_WORD_23 register */
#define FUSES_BOCOR_WORD_23_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_23) Register Mask  */


/* -------- FUSES_BOCOR_WORD_24 : (FUSES Offset: 0x60) (R/W 32) BOCOR Page Word 24 -------- */
#define FUSES_BOCOR_WORD_24_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_24) BOCOR Page Word 24  Reset Value */

#define FUSES_BOCOR_WORD_24_BOOTROM_BOOTKEY_4_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_24) Secure Boot Key bits 159:128 Position */
#define FUSES_BOCOR_WORD_24_BOOTROM_BOOTKEY_4_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_24_BOOTROM_BOOTKEY_4_Pos) /* (FUSES_BOCOR_WORD_24) Secure Boot Key bits 159:128 Mask */
#define FUSES_BOCOR_WORD_24_BOOTROM_BOOTKEY_4(value) (FUSES_BOCOR_WORD_24_BOOTROM_BOOTKEY_4_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_24_BOOTROM_BOOTKEY_4_Pos)) /* Assigment of value for BOOTROM_BOOTKEY_4 in the FUSES_BOCOR_WORD_24 register */
#define FUSES_BOCOR_WORD_24_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_24) Register Mask  */


/* -------- FUSES_BOCOR_WORD_25 : (FUSES Offset: 0x64) (R/W 32) BOCOR Page Word 25 -------- */
#define FUSES_BOCOR_WORD_25_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_25) BOCOR Page Word 25  Reset Value */

#define FUSES_BOCOR_WORD_25_BOOTROM_BOOTKEY_5_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_25) Secure Boot Key bits 191:160 Position */
#define FUSES_BOCOR_WORD_25_BOOTROM_BOOTKEY_5_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_25_BOOTROM_BOOTKEY_5_Pos) /* (FUSES_BOCOR_WORD_25) Secure Boot Key bits 191:160 Mask */
#define FUSES_BOCOR_WORD_25_BOOTROM_BOOTKEY_5(value) (FUSES_BOCOR_WORD_25_BOOTROM_BOOTKEY_5_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_25_BOOTROM_BOOTKEY_5_Pos)) /* Assigment of value for BOOTROM_BOOTKEY_5 in the FUSES_BOCOR_WORD_25 register */
#define FUSES_BOCOR_WORD_25_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_25) Register Mask  */


/* -------- FUSES_BOCOR_WORD_26 : (FUSES Offset: 0x68) (R/W 32) BOCOR Page Word 26 -------- */
#define FUSES_BOCOR_WORD_26_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_26) BOCOR Page Word 26  Reset Value */

#define FUSES_BOCOR_WORD_26_BOOTROM_BOOTKEY_6_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_26) Secure Boot Key bits 223:192 Position */
#define FUSES_BOCOR_WORD_26_BOOTROM_BOOTKEY_6_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_26_BOOTROM_BOOTKEY_6_Pos) /* (FUSES_BOCOR_WORD_26) Secure Boot Key bits 223:192 Mask */
#define FUSES_BOCOR_WORD_26_BOOTROM_BOOTKEY_6(value) (FUSES_BOCOR_WORD_26_BOOTROM_BOOTKEY_6_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_26_BOOTROM_BOOTKEY_6_Pos)) /* Assigment of value for BOOTROM_BOOTKEY_6 in the FUSES_BOCOR_WORD_26 register */
#define FUSES_BOCOR_WORD_26_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_26) Register Mask  */


/* -------- FUSES_BOCOR_WORD_27 : (FUSES Offset: 0x6C) (R/W 32) BOCOR Page Word 27 -------- */
#define FUSES_BOCOR_WORD_27_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_27) BOCOR Page Word 27  Reset Value */

#define FUSES_BOCOR_WORD_27_BOOTROM_BOOTKEY_7_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_27) Secure Boot Key bits 255:224 Position */
#define FUSES_BOCOR_WORD_27_BOOTROM_BOOTKEY_7_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_27_BOOTROM_BOOTKEY_7_Pos) /* (FUSES_BOCOR_WORD_27) Secure Boot Key bits 255:224 Mask */
#define FUSES_BOCOR_WORD_27_BOOTROM_BOOTKEY_7(value) (FUSES_BOCOR_WORD_27_BOOTROM_BOOTKEY_7_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_27_BOOTROM_BOOTKEY_7_Pos)) /* Assigment of value for BOOTROM_BOOTKEY_7 in the FUSES_BOCOR_WORD_27 register */
#define FUSES_BOCOR_WORD_27_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_27) Register Mask  */


/* -------- FUSES_BOCOR_WORD_28 : (FUSES Offset: 0x70) (R/W 32) BOCOR Page Word 28 -------- */
#define FUSES_BOCOR_WORD_28_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_28) BOCOR Page Word 28  Reset Value */

#define FUSES_BOCOR_WORD_28_BOOTROM_UDS_0_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_28) DICE UDS Key bits 31:0 Position */
#define FUSES_BOCOR_WORD_28_BOOTROM_UDS_0_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_28_BOOTROM_UDS_0_Pos) /* (FUSES_BOCOR_WORD_28) DICE UDS Key bits 31:0 Mask */
#define FUSES_BOCOR_WORD_28_BOOTROM_UDS_0(value) (FUSES_BOCOR_WORD_28_BOOTROM_UDS_0_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_28_BOOTROM_UDS_0_Pos)) /* Assigment of value for BOOTROM_UDS_0 in the FUSES_BOCOR_WORD_28 register */
#define FUSES_BOCOR_WORD_28_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_28) Register Mask  */


/* -------- FUSES_BOCOR_WORD_29 : (FUSES Offset: 0x74) (R/W 32) BOCOR Page Word 29 -------- */
#define FUSES_BOCOR_WORD_29_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_29) BOCOR Page Word 29  Reset Value */

#define FUSES_BOCOR_WORD_29_BOOTROM_UDS_1_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_29) DICE UDS Key bits 63:32 Position */
#define FUSES_BOCOR_WORD_29_BOOTROM_UDS_1_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_29_BOOTROM_UDS_1_Pos) /* (FUSES_BOCOR_WORD_29) DICE UDS Key bits 63:32 Mask */
#define FUSES_BOCOR_WORD_29_BOOTROM_UDS_1(value) (FUSES_BOCOR_WORD_29_BOOTROM_UDS_1_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_29_BOOTROM_UDS_1_Pos)) /* Assigment of value for BOOTROM_UDS_1 in the FUSES_BOCOR_WORD_29 register */
#define FUSES_BOCOR_WORD_29_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_29) Register Mask  */


/* -------- FUSES_BOCOR_WORD_30 : (FUSES Offset: 0x78) (R/W 32) BOCOR Page Word 30 -------- */
#define FUSES_BOCOR_WORD_30_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_30) BOCOR Page Word 30  Reset Value */

#define FUSES_BOCOR_WORD_30_BOOTROM_UDS_2_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_30) DICE UDS Key bits 95:64 Position */
#define FUSES_BOCOR_WORD_30_BOOTROM_UDS_2_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_30_BOOTROM_UDS_2_Pos) /* (FUSES_BOCOR_WORD_30) DICE UDS Key bits 95:64 Mask */
#define FUSES_BOCOR_WORD_30_BOOTROM_UDS_2(value) (FUSES_BOCOR_WORD_30_BOOTROM_UDS_2_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_30_BOOTROM_UDS_2_Pos)) /* Assigment of value for BOOTROM_UDS_2 in the FUSES_BOCOR_WORD_30 register */
#define FUSES_BOCOR_WORD_30_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_30) Register Mask  */


/* -------- FUSES_BOCOR_WORD_31 : (FUSES Offset: 0x7C) (R/W 32) BOCOR Page Word 31 -------- */
#define FUSES_BOCOR_WORD_31_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_31) BOCOR Page Word 31  Reset Value */

#define FUSES_BOCOR_WORD_31_BOOTROM_UDS_3_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_31) DICE UDS Key bits 127:96 Position */
#define FUSES_BOCOR_WORD_31_BOOTROM_UDS_3_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_31_BOOTROM_UDS_3_Pos) /* (FUSES_BOCOR_WORD_31) DICE UDS Key bits 127:96 Mask */
#define FUSES_BOCOR_WORD_31_BOOTROM_UDS_3(value) (FUSES_BOCOR_WORD_31_BOOTROM_UDS_3_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_31_BOOTROM_UDS_3_Pos)) /* Assigment of value for BOOTROM_UDS_3 in the FUSES_BOCOR_WORD_31 register */
#define FUSES_BOCOR_WORD_31_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_31) Register Mask  */


/* -------- FUSES_BOCOR_WORD_32 : (FUSES Offset: 0x80) (R/W 32) BOCOR Page Word 32 -------- */
#define FUSES_BOCOR_WORD_32_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_32) BOCOR Page Word 32  Reset Value */

#define FUSES_BOCOR_WORD_32_BOOTROM_UDS_4_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_32) DICE UDS Key bits 159:128 Position */
#define FUSES_BOCOR_WORD_32_BOOTROM_UDS_4_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_32_BOOTROM_UDS_4_Pos) /* (FUSES_BOCOR_WORD_32) DICE UDS Key bits 159:128 Mask */
#define FUSES_BOCOR_WORD_32_BOOTROM_UDS_4(value) (FUSES_BOCOR_WORD_32_BOOTROM_UDS_4_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_32_BOOTROM_UDS_4_Pos)) /* Assigment of value for BOOTROM_UDS_4 in the FUSES_BOCOR_WORD_32 register */
#define FUSES_BOCOR_WORD_32_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_32) Register Mask  */


/* -------- FUSES_BOCOR_WORD_33 : (FUSES Offset: 0x84) (R/W 32) BOCOR Page Word 33 -------- */
#define FUSES_BOCOR_WORD_33_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_33) BOCOR Page Word 33  Reset Value */

#define FUSES_BOCOR_WORD_33_BOOTROM_UDS_5_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_33) DICE UDS Key bits 191:160 Position */
#define FUSES_BOCOR_WORD_33_BOOTROM_UDS_5_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_33_BOOTROM_UDS_5_Pos) /* (FUSES_BOCOR_WORD_33) DICE UDS Key bits 191:160 Mask */
#define FUSES_BOCOR_WORD_33_BOOTROM_UDS_5(value) (FUSES_BOCOR_WORD_33_BOOTROM_UDS_5_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_33_BOOTROM_UDS_5_Pos)) /* Assigment of value for BOOTROM_UDS_5 in the FUSES_BOCOR_WORD_33 register */
#define FUSES_BOCOR_WORD_33_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_33) Register Mask  */


/* -------- FUSES_BOCOR_WORD_34 : (FUSES Offset: 0x88) (R/W 32) BOCOR Page Word 34 -------- */
#define FUSES_BOCOR_WORD_34_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_34) BOCOR Page Word 34  Reset Value */

#define FUSES_BOCOR_WORD_34_BOOTROM_UDS_6_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_34) DICE UDS Key bits 223:192 Position */
#define FUSES_BOCOR_WORD_34_BOOTROM_UDS_6_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_34_BOOTROM_UDS_6_Pos) /* (FUSES_BOCOR_WORD_34) DICE UDS Key bits 223:192 Mask */
#define FUSES_BOCOR_WORD_34_BOOTROM_UDS_6(value) (FUSES_BOCOR_WORD_34_BOOTROM_UDS_6_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_34_BOOTROM_UDS_6_Pos)) /* Assigment of value for BOOTROM_UDS_6 in the FUSES_BOCOR_WORD_34 register */
#define FUSES_BOCOR_WORD_34_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_34) Register Mask  */


/* -------- FUSES_BOCOR_WORD_35 : (FUSES Offset: 0x8C) (R/W 32) BOCOR Page Word 35 -------- */
#define FUSES_BOCOR_WORD_35_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_35) BOCOR Page Word 35  Reset Value */

#define FUSES_BOCOR_WORD_35_BOOTROM_UDS_7_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_35) DICE UDS Key bits 255:224 Position */
#define FUSES_BOCOR_WORD_35_BOOTROM_UDS_7_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_35_BOOTROM_UDS_7_Pos) /* (FUSES_BOCOR_WORD_35) DICE UDS Key bits 255:224 Mask */
#define FUSES_BOCOR_WORD_35_BOOTROM_UDS_7(value) (FUSES_BOCOR_WORD_35_BOOTROM_UDS_7_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_35_BOOTROM_UDS_7_Pos)) /* Assigment of value for BOOTROM_UDS_7 in the FUSES_BOCOR_WORD_35 register */
#define FUSES_BOCOR_WORD_35_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_35) Register Mask  */


/* -------- FUSES_BOCOR_WORD_36 : (FUSES Offset: 0x90) (R/W 32) BOCOR Page Word 36 -------- */
#define FUSES_BOCOR_WORD_36_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_36) BOCOR Page Word 36  Reset Value */

#define FUSES_BOCOR_WORD_36_BOOTROM_IOPROTKEY_0_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_36) ECC608 IO Protection Key bits 31:0 Position */
#define FUSES_BOCOR_WORD_36_BOOTROM_IOPROTKEY_0_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_36_BOOTROM_IOPROTKEY_0_Pos) /* (FUSES_BOCOR_WORD_36) ECC608 IO Protection Key bits 31:0 Mask */
#define FUSES_BOCOR_WORD_36_BOOTROM_IOPROTKEY_0(value) (FUSES_BOCOR_WORD_36_BOOTROM_IOPROTKEY_0_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_36_BOOTROM_IOPROTKEY_0_Pos)) /* Assigment of value for BOOTROM_IOPROTKEY_0 in the FUSES_BOCOR_WORD_36 register */
#define FUSES_BOCOR_WORD_36_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_36) Register Mask  */


/* -------- FUSES_BOCOR_WORD_37 : (FUSES Offset: 0x94) (R/W 32) BOCOR Page Word 37 -------- */
#define FUSES_BOCOR_WORD_37_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_37) BOCOR Page Word 37  Reset Value */

#define FUSES_BOCOR_WORD_37_BOOTROM_IOPROTKEY_1_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_37) ECC608 IO Protection Key bits 63:32 Position */
#define FUSES_BOCOR_WORD_37_BOOTROM_IOPROTKEY_1_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_37_BOOTROM_IOPROTKEY_1_Pos) /* (FUSES_BOCOR_WORD_37) ECC608 IO Protection Key bits 63:32 Mask */
#define FUSES_BOCOR_WORD_37_BOOTROM_IOPROTKEY_1(value) (FUSES_BOCOR_WORD_37_BOOTROM_IOPROTKEY_1_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_37_BOOTROM_IOPROTKEY_1_Pos)) /* Assigment of value for BOOTROM_IOPROTKEY_1 in the FUSES_BOCOR_WORD_37 register */
#define FUSES_BOCOR_WORD_37_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_37) Register Mask  */


/* -------- FUSES_BOCOR_WORD_38 : (FUSES Offset: 0x98) (R/W 32) BOCOR Page Word 38 -------- */
#define FUSES_BOCOR_WORD_38_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_38) BOCOR Page Word 38  Reset Value */

#define FUSES_BOCOR_WORD_38_BOOTROM_IOPROTKEY_2_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_38) ECC608 IO Protection Key bits 95:64 Position */
#define FUSES_BOCOR_WORD_38_BOOTROM_IOPROTKEY_2_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_38_BOOTROM_IOPROTKEY_2_Pos) /* (FUSES_BOCOR_WORD_38) ECC608 IO Protection Key bits 95:64 Mask */
#define FUSES_BOCOR_WORD_38_BOOTROM_IOPROTKEY_2(value) (FUSES_BOCOR_WORD_38_BOOTROM_IOPROTKEY_2_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_38_BOOTROM_IOPROTKEY_2_Pos)) /* Assigment of value for BOOTROM_IOPROTKEY_2 in the FUSES_BOCOR_WORD_38 register */
#define FUSES_BOCOR_WORD_38_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_38) Register Mask  */


/* -------- FUSES_BOCOR_WORD_39 : (FUSES Offset: 0x9C) (R/W 32) BOCOR Page Word 39 -------- */
#define FUSES_BOCOR_WORD_39_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_39) BOCOR Page Word 39  Reset Value */

#define FUSES_BOCOR_WORD_39_BOOTROM_IOPROTKEY_3_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_39) ECC608 IO Protection Key bits 127:96 Position */
#define FUSES_BOCOR_WORD_39_BOOTROM_IOPROTKEY_3_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_39_BOOTROM_IOPROTKEY_3_Pos) /* (FUSES_BOCOR_WORD_39) ECC608 IO Protection Key bits 127:96 Mask */
#define FUSES_BOCOR_WORD_39_BOOTROM_IOPROTKEY_3(value) (FUSES_BOCOR_WORD_39_BOOTROM_IOPROTKEY_3_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_39_BOOTROM_IOPROTKEY_3_Pos)) /* Assigment of value for BOOTROM_IOPROTKEY_3 in the FUSES_BOCOR_WORD_39 register */
#define FUSES_BOCOR_WORD_39_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_39) Register Mask  */


/* -------- FUSES_BOCOR_WORD_40 : (FUSES Offset: 0xA0) (R/W 32) BOCOR Page Word 40 -------- */
#define FUSES_BOCOR_WORD_40_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_40) BOCOR Page Word 40  Reset Value */

#define FUSES_BOCOR_WORD_40_BOOTROM_IOPROTKEY_4_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_40) ECC608 IO Protection Key bits 159:128 Position */
#define FUSES_BOCOR_WORD_40_BOOTROM_IOPROTKEY_4_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_40_BOOTROM_IOPROTKEY_4_Pos) /* (FUSES_BOCOR_WORD_40) ECC608 IO Protection Key bits 159:128 Mask */
#define FUSES_BOCOR_WORD_40_BOOTROM_IOPROTKEY_4(value) (FUSES_BOCOR_WORD_40_BOOTROM_IOPROTKEY_4_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_40_BOOTROM_IOPROTKEY_4_Pos)) /* Assigment of value for BOOTROM_IOPROTKEY_4 in the FUSES_BOCOR_WORD_40 register */
#define FUSES_BOCOR_WORD_40_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_40) Register Mask  */


/* -------- FUSES_BOCOR_WORD_41 : (FUSES Offset: 0xA4) (R/W 32) BOCOR Page Word 41 -------- */
#define FUSES_BOCOR_WORD_41_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_41) BOCOR Page Word 41  Reset Value */

#define FUSES_BOCOR_WORD_41_BOOTROM_IOPROTKEY_5_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_41) ECC608 IO Protection Key bits 191:160 Position */
#define FUSES_BOCOR_WORD_41_BOOTROM_IOPROTKEY_5_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_41_BOOTROM_IOPROTKEY_5_Pos) /* (FUSES_BOCOR_WORD_41) ECC608 IO Protection Key bits 191:160 Mask */
#define FUSES_BOCOR_WORD_41_BOOTROM_IOPROTKEY_5(value) (FUSES_BOCOR_WORD_41_BOOTROM_IOPROTKEY_5_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_41_BOOTROM_IOPROTKEY_5_Pos)) /* Assigment of value for BOOTROM_IOPROTKEY_5 in the FUSES_BOCOR_WORD_41 register */
#define FUSES_BOCOR_WORD_41_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_41) Register Mask  */


/* -------- FUSES_BOCOR_WORD_42 : (FUSES Offset: 0xA8) (R/W 32) BOCOR Page Word 42 -------- */
#define FUSES_BOCOR_WORD_42_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_42) BOCOR Page Word 42  Reset Value */

#define FUSES_BOCOR_WORD_42_BOOTROM_IOPROTKEY_6_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_42) ECC608 IO Protection Key bits 223:192 Position */
#define FUSES_BOCOR_WORD_42_BOOTROM_IOPROTKEY_6_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_42_BOOTROM_IOPROTKEY_6_Pos) /* (FUSES_BOCOR_WORD_42) ECC608 IO Protection Key bits 223:192 Mask */
#define FUSES_BOCOR_WORD_42_BOOTROM_IOPROTKEY_6(value) (FUSES_BOCOR_WORD_42_BOOTROM_IOPROTKEY_6_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_42_BOOTROM_IOPROTKEY_6_Pos)) /* Assigment of value for BOOTROM_IOPROTKEY_6 in the FUSES_BOCOR_WORD_42 register */
#define FUSES_BOCOR_WORD_42_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_42) Register Mask  */


/* -------- FUSES_BOCOR_WORD_43 : (FUSES Offset: 0xAC) (R/W 32) BOCOR Page Word 43 -------- */
#define FUSES_BOCOR_WORD_43_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_43) BOCOR Page Word 43  Reset Value */

#define FUSES_BOCOR_WORD_43_BOOTROM_IOPROTKEY_7_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_43) ECC608 IO Protection Key bits 255:224 Position */
#define FUSES_BOCOR_WORD_43_BOOTROM_IOPROTKEY_7_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_43_BOOTROM_IOPROTKEY_7_Pos) /* (FUSES_BOCOR_WORD_43) ECC608 IO Protection Key bits 255:224 Mask */
#define FUSES_BOCOR_WORD_43_BOOTROM_IOPROTKEY_7(value) (FUSES_BOCOR_WORD_43_BOOTROM_IOPROTKEY_7_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_43_BOOTROM_IOPROTKEY_7_Pos)) /* Assigment of value for BOOTROM_IOPROTKEY_7 in the FUSES_BOCOR_WORD_43 register */
#define FUSES_BOCOR_WORD_43_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_43) Register Mask  */


/* -------- FUSES_BOCOR_WORD_56 : (FUSES Offset: 0xE0) (R/W 32) BOCOR Page Word 56 -------- */
#define FUSES_BOCOR_WORD_56_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_56) BOCOR Page Word 56  Reset Value */

#define FUSES_BOCOR_WORD_56_BOOTROM_BOCORHASH_0_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_56) Boot Configuration Row Hash bits 31:0 Position */
#define FUSES_BOCOR_WORD_56_BOOTROM_BOCORHASH_0_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_56_BOOTROM_BOCORHASH_0_Pos) /* (FUSES_BOCOR_WORD_56) Boot Configuration Row Hash bits 31:0 Mask */
#define FUSES_BOCOR_WORD_56_BOOTROM_BOCORHASH_0(value) (FUSES_BOCOR_WORD_56_BOOTROM_BOCORHASH_0_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_56_BOOTROM_BOCORHASH_0_Pos)) /* Assigment of value for BOOTROM_BOCORHASH_0 in the FUSES_BOCOR_WORD_56 register */
#define FUSES_BOCOR_WORD_56_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_56) Register Mask  */


/* -------- FUSES_BOCOR_WORD_57 : (FUSES Offset: 0xE4) (R/W 32) BOCOR Page Word 57 -------- */
#define FUSES_BOCOR_WORD_57_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_57) BOCOR Page Word 57  Reset Value */

#define FUSES_BOCOR_WORD_57_BOOTROM_BOCORHASH_1_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_57) Boot Configuration Row Hash bits 63:32 Position */
#define FUSES_BOCOR_WORD_57_BOOTROM_BOCORHASH_1_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_57_BOOTROM_BOCORHASH_1_Pos) /* (FUSES_BOCOR_WORD_57) Boot Configuration Row Hash bits 63:32 Mask */
#define FUSES_BOCOR_WORD_57_BOOTROM_BOCORHASH_1(value) (FUSES_BOCOR_WORD_57_BOOTROM_BOCORHASH_1_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_57_BOOTROM_BOCORHASH_1_Pos)) /* Assigment of value for BOOTROM_BOCORHASH_1 in the FUSES_BOCOR_WORD_57 register */
#define FUSES_BOCOR_WORD_57_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_57) Register Mask  */


/* -------- FUSES_BOCOR_WORD_58 : (FUSES Offset: 0xE8) (R/W 32) BOCOR Page Word 58 -------- */
#define FUSES_BOCOR_WORD_58_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_58) BOCOR Page Word 58  Reset Value */

#define FUSES_BOCOR_WORD_58_BOOTROM_BOCORHASH_2_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_58) Boot Configuration Row Hash bits 95:64 Position */
#define FUSES_BOCOR_WORD_58_BOOTROM_BOCORHASH_2_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_58_BOOTROM_BOCORHASH_2_Pos) /* (FUSES_BOCOR_WORD_58) Boot Configuration Row Hash bits 95:64 Mask */
#define FUSES_BOCOR_WORD_58_BOOTROM_BOCORHASH_2(value) (FUSES_BOCOR_WORD_58_BOOTROM_BOCORHASH_2_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_58_BOOTROM_BOCORHASH_2_Pos)) /* Assigment of value for BOOTROM_BOCORHASH_2 in the FUSES_BOCOR_WORD_58 register */
#define FUSES_BOCOR_WORD_58_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_58) Register Mask  */


/* -------- FUSES_BOCOR_WORD_59 : (FUSES Offset: 0xEC) (R/W 32) BOCOR Page Word 59 -------- */
#define FUSES_BOCOR_WORD_59_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_59) BOCOR Page Word 59  Reset Value */

#define FUSES_BOCOR_WORD_59_BOOTROM_BOCORHASH_3_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_59) Boot Configuration Row Hash bits 127:96 Position */
#define FUSES_BOCOR_WORD_59_BOOTROM_BOCORHASH_3_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_59_BOOTROM_BOCORHASH_3_Pos) /* (FUSES_BOCOR_WORD_59) Boot Configuration Row Hash bits 127:96 Mask */
#define FUSES_BOCOR_WORD_59_BOOTROM_BOCORHASH_3(value) (FUSES_BOCOR_WORD_59_BOOTROM_BOCORHASH_3_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_59_BOOTROM_BOCORHASH_3_Pos)) /* Assigment of value for BOOTROM_BOCORHASH_3 in the FUSES_BOCOR_WORD_59 register */
#define FUSES_BOCOR_WORD_59_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_59) Register Mask  */


/* -------- FUSES_BOCOR_WORD_60 : (FUSES Offset: 0xF0) (R/W 32) BOCOR Page Word 60 -------- */
#define FUSES_BOCOR_WORD_60_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_60) BOCOR Page Word 60  Reset Value */

#define FUSES_BOCOR_WORD_60_BOOTROM_BOCORHASH_4_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_60) Boot Configuration Row Hash bits 159:128 Position */
#define FUSES_BOCOR_WORD_60_BOOTROM_BOCORHASH_4_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_60_BOOTROM_BOCORHASH_4_Pos) /* (FUSES_BOCOR_WORD_60) Boot Configuration Row Hash bits 159:128 Mask */
#define FUSES_BOCOR_WORD_60_BOOTROM_BOCORHASH_4(value) (FUSES_BOCOR_WORD_60_BOOTROM_BOCORHASH_4_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_60_BOOTROM_BOCORHASH_4_Pos)) /* Assigment of value for BOOTROM_BOCORHASH_4 in the FUSES_BOCOR_WORD_60 register */
#define FUSES_BOCOR_WORD_60_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_60) Register Mask  */


/* -------- FUSES_BOCOR_WORD_61 : (FUSES Offset: 0xF4) (R/W 32) BOCOR Page Word 61 -------- */
#define FUSES_BOCOR_WORD_61_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_61) BOCOR Page Word 61  Reset Value */

#define FUSES_BOCOR_WORD_61_BOOTROM_BOCORHASH_5_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_61) Boot Configuration Row Hash bits 191:160 Position */
#define FUSES_BOCOR_WORD_61_BOOTROM_BOCORHASH_5_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_61_BOOTROM_BOCORHASH_5_Pos) /* (FUSES_BOCOR_WORD_61) Boot Configuration Row Hash bits 191:160 Mask */
#define FUSES_BOCOR_WORD_61_BOOTROM_BOCORHASH_5(value) (FUSES_BOCOR_WORD_61_BOOTROM_BOCORHASH_5_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_61_BOOTROM_BOCORHASH_5_Pos)) /* Assigment of value for BOOTROM_BOCORHASH_5 in the FUSES_BOCOR_WORD_61 register */
#define FUSES_BOCOR_WORD_61_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_61) Register Mask  */


/* -------- FUSES_BOCOR_WORD_62 : (FUSES Offset: 0xF8) (R/W 32) BOCOR Page Word 62 -------- */
#define FUSES_BOCOR_WORD_62_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_62) BOCOR Page Word 62  Reset Value */

#define FUSES_BOCOR_WORD_62_BOOTROM_BOCORHASH_6_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_62) Boot Configuration Row Hash bits 223:192 Position */
#define FUSES_BOCOR_WORD_62_BOOTROM_BOCORHASH_6_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_62_BOOTROM_BOCORHASH_6_Pos) /* (FUSES_BOCOR_WORD_62) Boot Configuration Row Hash bits 223:192 Mask */
#define FUSES_BOCOR_WORD_62_BOOTROM_BOCORHASH_6(value) (FUSES_BOCOR_WORD_62_BOOTROM_BOCORHASH_6_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_62_BOOTROM_BOCORHASH_6_Pos)) /* Assigment of value for BOOTROM_BOCORHASH_6 in the FUSES_BOCOR_WORD_62 register */
#define FUSES_BOCOR_WORD_62_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_62) Register Mask  */


/* -------- FUSES_BOCOR_WORD_63 : (FUSES Offset: 0xFC) (R/W 32) BOCOR Page Word 63 -------- */
#define FUSES_BOCOR_WORD_63_RESETVALUE        _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_BOCOR_WORD_63) BOCOR Page Word 63  Reset Value */

#define FUSES_BOCOR_WORD_63_BOOTROM_BOCORHASH_7_Pos _UINT32_(0)                                          /* (FUSES_BOCOR_WORD_63) Boot Configuration Row Hash bits 255:224 Position */
#define FUSES_BOCOR_WORD_63_BOOTROM_BOCORHASH_7_Msk (_UINT32_(0xFFFFFFFF) << FUSES_BOCOR_WORD_63_BOOTROM_BOCORHASH_7_Pos) /* (FUSES_BOCOR_WORD_63) Boot Configuration Row Hash bits 255:224 Mask */
#define FUSES_BOCOR_WORD_63_BOOTROM_BOCORHASH_7(value) (FUSES_BOCOR_WORD_63_BOOTROM_BOCORHASH_7_Msk & (_UINT32_(value) << FUSES_BOCOR_WORD_63_BOOTROM_BOCORHASH_7_Pos)) /* Assigment of value for BOOTROM_BOCORHASH_7 in the FUSES_BOCOR_WORD_63 register */
#define FUSES_BOCOR_WORD_63_Msk               _UINT32_(0xFFFFFFFF)                                 /* (FUSES_BOCOR_WORD_63) Register Mask  */


/* -------- FUSES_OTP1_WORD_0 : (FUSES Offset: 0x00) ( R/ 32) OTP1 Page Word 0 -------- */
#define FUSES_OTP1_WORD_0_BOOTROM_SECEN_Pos   _UINT32_(10)                                         /* (FUSES_OTP1_WORD_0) Security Enable Fuse Position */
#define FUSES_OTP1_WORD_0_BOOTROM_SECEN_Msk   (_UINT32_(0x1) << FUSES_OTP1_WORD_0_BOOTROM_SECEN_Pos) /* (FUSES_OTP1_WORD_0) Security Enable Fuse Mask */
#define FUSES_OTP1_WORD_0_BOOTROM_SECEN(value) (FUSES_OTP1_WORD_0_BOOTROM_SECEN_Msk & (_UINT32_(value) << FUSES_OTP1_WORD_0_BOOTROM_SECEN_Pos)) /* Assigment of value for BOOTROM_SECEN in the FUSES_OTP1_WORD_0 register */
#define FUSES_OTP1_WORD_0_Msk                 _UINT32_(0x00000400)                                 /* (FUSES_OTP1_WORD_0) Register Mask  */


/* -------- FUSES_OTP1_WORD_1 : (FUSES Offset: 0x04) ( R/ 32) OTP1 Page Word 1 -------- */
#define FUSES_OTP1_WORD_1_BOOTROM_NVMCRC_Pos  _UINT32_(0)                                          /* (FUSES_OTP1_WORD_1) CRC for NVM DWORD Position */
#define FUSES_OTP1_WORD_1_BOOTROM_NVMCRC_Msk  (_UINT32_(0xFFFFFFFF) << FUSES_OTP1_WORD_1_BOOTROM_NVMCRC_Pos) /* (FUSES_OTP1_WORD_1) CRC for NVM DWORD Mask */
#define FUSES_OTP1_WORD_1_BOOTROM_NVMCRC(value) (FUSES_OTP1_WORD_1_BOOTROM_NVMCRC_Msk & (_UINT32_(value) << FUSES_OTP1_WORD_1_BOOTROM_NVMCRC_Pos)) /* Assigment of value for BOOTROM_NVMCRC in the FUSES_OTP1_WORD_1 register */
#define FUSES_OTP1_WORD_1_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (FUSES_OTP1_WORD_1) Register Mask  */


/* -------- FUSES_OTP2_WORD_1 : (FUSES Offset: 0x04) ( R/ 32) OTP2 Page Word 1 -------- */
#define FUSES_OTP2_WORD_1_PM_NVM3VSWDIS_Pos   _UINT32_(15)                                         /* (FUSES_OTP2_WORD_1) 3V NVM switch disable Position */
#define FUSES_OTP2_WORD_1_PM_NVM3VSWDIS_Msk   (_UINT32_(0x1) << FUSES_OTP2_WORD_1_PM_NVM3VSWDIS_Pos) /* (FUSES_OTP2_WORD_1) 3V NVM switch disable Mask */
#define FUSES_OTP2_WORD_1_PM_NVM3VSWDIS(value) (FUSES_OTP2_WORD_1_PM_NVM3VSWDIS_Msk & (_UINT32_(value) << FUSES_OTP2_WORD_1_PM_NVM3VSWDIS_Pos)) /* Assigment of value for PM_NVM3VSWDIS in the FUSES_OTP2_WORD_1 register */
#define FUSES_OTP2_WORD_1_Msk                 _UINT32_(0x00008000)                                 /* (FUSES_OTP2_WORD_1) Register Mask  */


/* -------- FUSES_USER_WORD_0 : (FUSES Offset: 0x00) (R/W 32) USER Page Word 0 -------- */
#define FUSES_USER_WORD_0_RESETVALUE          _UINT32_(0xB08F4377)                                 /*  (FUSES_USER_WORD_0) USER Page Word 0  Reset Value */

#define FUSES_USER_WORD_0_NVMCTRL_SULCK_Pos   _UINT32_(0)                                          /* (FUSES_USER_WORD_0) NVM Secure Region Locks Position */
#define FUSES_USER_WORD_0_NVMCTRL_SULCK_Msk   (_UINT32_(0x7) << FUSES_USER_WORD_0_NVMCTRL_SULCK_Pos) /* (FUSES_USER_WORD_0) NVM Secure Region Locks Mask */
#define FUSES_USER_WORD_0_NVMCTRL_SULCK(value) (FUSES_USER_WORD_0_NVMCTRL_SULCK_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_NVMCTRL_SULCK_Pos)) /* Assigment of value for NVMCTRL_SULCK in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_NVMCTRL_NSULCK_Pos  _UINT32_(3)                                          /* (FUSES_USER_WORD_0) NVM Non-Secure Region Locks Position */
#define FUSES_USER_WORD_0_NVMCTRL_NSULCK_Msk  (_UINT32_(0x7) << FUSES_USER_WORD_0_NVMCTRL_NSULCK_Pos) /* (FUSES_USER_WORD_0) NVM Non-Secure Region Locks Mask */
#define FUSES_USER_WORD_0_NVMCTRL_NSULCK(value) (FUSES_USER_WORD_0_NVMCTRL_NSULCK_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_NVMCTRL_NSULCK_Pos)) /* Assigment of value for NVMCTRL_NSULCK in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_BOD33USERLEVEL_Pos  _UINT32_(7)                                          /* (FUSES_USER_WORD_0) BOD33 User Level Position */
#define FUSES_USER_WORD_0_BOD33USERLEVEL_Msk  (_UINT32_(0x3F) << FUSES_USER_WORD_0_BOD33USERLEVEL_Pos) /* (FUSES_USER_WORD_0) BOD33 User Level Mask */
#define FUSES_USER_WORD_0_BOD33USERLEVEL(value) (FUSES_USER_WORD_0_BOD33USERLEVEL_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33USERLEVEL_Pos)) /* Assigment of value for BOD33USERLEVEL in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_BOD33_DIS_Pos       _UINT32_(13)                                         /* (FUSES_USER_WORD_0) BOD33 Disable Position */
#define FUSES_USER_WORD_0_BOD33_DIS_Msk       (_UINT32_(0x1) << FUSES_USER_WORD_0_BOD33_DIS_Pos)   /* (FUSES_USER_WORD_0) BOD33 Disable Mask */
#define FUSES_USER_WORD_0_BOD33_DIS(value)    (FUSES_USER_WORD_0_BOD33_DIS_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33_DIS_Pos)) /* Assigment of value for BOD33_DIS in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_BOD33_ACTION_Pos    _UINT32_(14)                                         /* (FUSES_USER_WORD_0) BOD33 Action Position */
#define FUSES_USER_WORD_0_BOD33_ACTION_Msk    (_UINT32_(0x3) << FUSES_USER_WORD_0_BOD33_ACTION_Pos) /* (FUSES_USER_WORD_0) BOD33 Action Mask */
#define FUSES_USER_WORD_0_BOD33_ACTION(value) (FUSES_USER_WORD_0_BOD33_ACTION_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_BOD33_ACTION_Pos)) /* Assigment of value for BOD33_ACTION in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_WDT_RUNSTDBY_Pos    _UINT32_(25)                                         /* (FUSES_USER_WORD_0) WDT Run During Standby Position */
#define FUSES_USER_WORD_0_WDT_RUNSTDBY_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_0_WDT_RUNSTDBY_Pos) /* (FUSES_USER_WORD_0) WDT Run During Standby Mask */
#define FUSES_USER_WORD_0_WDT_RUNSTDBY(value) (FUSES_USER_WORD_0_WDT_RUNSTDBY_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_RUNSTDBY_Pos)) /* Assigment of value for WDT_RUNSTDBY in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_WDT_ENABLE_Pos      _UINT32_(26)                                         /* (FUSES_USER_WORD_0) WDT Enable Position */
#define FUSES_USER_WORD_0_WDT_ENABLE_Msk      (_UINT32_(0x1) << FUSES_USER_WORD_0_WDT_ENABLE_Pos)  /* (FUSES_USER_WORD_0) WDT Enable Mask */
#define FUSES_USER_WORD_0_WDT_ENABLE(value)   (FUSES_USER_WORD_0_WDT_ENABLE_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_ENABLE_Pos)) /* Assigment of value for WDT_ENABLE in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_WDT_ALWAYSON_Pos    _UINT32_(27)                                         /* (FUSES_USER_WORD_0) WDT Always On Position */
#define FUSES_USER_WORD_0_WDT_ALWAYSON_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_0_WDT_ALWAYSON_Pos) /* (FUSES_USER_WORD_0) WDT Always On Mask */
#define FUSES_USER_WORD_0_WDT_ALWAYSON(value) (FUSES_USER_WORD_0_WDT_ALWAYSON_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_ALWAYSON_Pos)) /* Assigment of value for WDT_ALWAYSON in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_WDT_PER_Pos         _UINT32_(28)                                         /* (FUSES_USER_WORD_0) WDT Period Position */
#define FUSES_USER_WORD_0_WDT_PER_Msk         (_UINT32_(0xF) << FUSES_USER_WORD_0_WDT_PER_Pos)     /* (FUSES_USER_WORD_0) WDT Period Mask */
#define FUSES_USER_WORD_0_WDT_PER(value)      (FUSES_USER_WORD_0_WDT_PER_Msk & (_UINT32_(value) << FUSES_USER_WORD_0_WDT_PER_Pos)) /* Assigment of value for WDT_PER in the FUSES_USER_WORD_0 register */
#define FUSES_USER_WORD_0_Msk                 _UINT32_(0xFE00FFBF)                                 /* (FUSES_USER_WORD_0) Register Mask  */


/* -------- FUSES_USER_WORD_1 : (FUSES Offset: 0x04) (R/W 32) USER Page Word 1 -------- */
#define FUSES_USER_WORD_1_RESETVALUE          _UINT32_(0xFFFFF0BB)                                 /*  (FUSES_USER_WORD_1) USER Page Word 1  Reset Value */

#define FUSES_USER_WORD_1_WDT_WINDOW_Pos      _UINT32_(0)                                          /* (FUSES_USER_WORD_1) WDT Window Position */
#define FUSES_USER_WORD_1_WDT_WINDOW_Msk      (_UINT32_(0xF) << FUSES_USER_WORD_1_WDT_WINDOW_Pos)  /* (FUSES_USER_WORD_1) WDT Window Mask */
#define FUSES_USER_WORD_1_WDT_WINDOW(value)   (FUSES_USER_WORD_1_WDT_WINDOW_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_WINDOW_Pos)) /* Assigment of value for WDT_WINDOW in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_Pos    _UINT32_(4)                                          /* (FUSES_USER_WORD_1) WDT Early Warning Offset Position */
#define FUSES_USER_WORD_1_WDT_EWOFFSET_Msk    (_UINT32_(0xF) << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos) /* (FUSES_USER_WORD_1) WDT Early Warning Offset Mask */
#define FUSES_USER_WORD_1_WDT_EWOFFSET(value) (FUSES_USER_WORD_1_WDT_EWOFFSET_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_EWOFFSET_Pos)) /* Assigment of value for WDT_EWOFFSET in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_WDT_WEN_Pos         _UINT32_(8)                                          /* (FUSES_USER_WORD_1) WDT Window Mode Enable Position */
#define FUSES_USER_WORD_1_WDT_WEN_Msk         (_UINT32_(0x1) << FUSES_USER_WORD_1_WDT_WEN_Pos)     /* (FUSES_USER_WORD_1) WDT Window Mode Enable Mask */
#define FUSES_USER_WORD_1_WDT_WEN(value)      (FUSES_USER_WORD_1_WDT_WEN_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_WDT_WEN_Pos)) /* Assigment of value for WDT_WEN in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_BOD33_HYST_Pos      _UINT32_(9)                                          /* (FUSES_USER_WORD_1) BOD33 Hysteresis Position */
#define FUSES_USER_WORD_1_BOD33_HYST_Msk      (_UINT32_(0x1) << FUSES_USER_WORD_1_BOD33_HYST_Pos)  /* (FUSES_USER_WORD_1) BOD33 Hysteresis Mask */
#define FUSES_USER_WORD_1_BOD33_HYST(value)   (FUSES_USER_WORD_1_BOD33_HYST_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_BOD33_HYST_Pos)) /* Assigment of value for BOD33_HYST in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_IDAU_RXN_Pos        _UINT32_(11)                                         /* (FUSES_USER_WORD_1) RAM is eXecute Never Position */
#define FUSES_USER_WORD_1_IDAU_RXN_Msk        (_UINT32_(0x1) << FUSES_USER_WORD_1_IDAU_RXN_Pos)    /* (FUSES_USER_WORD_1) RAM is eXecute Never Mask */
#define FUSES_USER_WORD_1_IDAU_RXN(value)     (FUSES_USER_WORD_1_IDAU_RXN_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_IDAU_RXN_Pos)) /* Assigment of value for IDAU_RXN in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_NVMCTRL_DXN_Pos     _UINT32_(12)                                         /* (FUSES_USER_WORD_1) DATA FLASH is eXecute Never Position */
#define FUSES_USER_WORD_1_NVMCTRL_DXN_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_1_NVMCTRL_DXN_Pos) /* (FUSES_USER_WORD_1) DATA FLASH is eXecute Never Mask */
#define FUSES_USER_WORD_1_NVMCTRL_DXN(value)  (FUSES_USER_WORD_1_NVMCTRL_DXN_Msk & (_UINT32_(value) << FUSES_USER_WORD_1_NVMCTRL_DXN_Pos)) /* Assigment of value for NVMCTRL_DXN in the FUSES_USER_WORD_1 register */
#define FUSES_USER_WORD_1_Msk                 _UINT32_(0x00001BFF)                                 /* (FUSES_USER_WORD_1) Register Mask  */


/* -------- FUSES_USER_WORD_2 : (FUSES Offset: 0x08) (R/W 32) USER Page Word 2 -------- */
#define FUSES_USER_WORD_2_RESETVALUE          _UINT32_(0xF03007FF)                                 /*  (FUSES_USER_WORD_2) USER Page Word 2  Reset Value */

#define FUSES_USER_WORD_2_IDAU_AS_Pos         _UINT32_(0)                                          /* (FUSES_USER_WORD_2) Application Secure Position */
#define FUSES_USER_WORD_2_IDAU_AS_Msk         (_UINT32_(0x7FF) << FUSES_USER_WORD_2_IDAU_AS_Pos)   /* (FUSES_USER_WORD_2) Application Secure Mask */
#define FUSES_USER_WORD_2_IDAU_AS(value)      (FUSES_USER_WORD_2_IDAU_AS_Msk & (_UINT32_(value) << FUSES_USER_WORD_2_IDAU_AS_Pos)) /* Assigment of value for IDAU_AS in the FUSES_USER_WORD_2 register */
#define FUSES_USER_WORD_2_IDAU_ANSC_Pos       _UINT32_(11)                                         /* (FUSES_USER_WORD_2) Application Non-Secure Callable Position */
#define FUSES_USER_WORD_2_IDAU_ANSC_Msk       (_UINT32_(0x1FF) << FUSES_USER_WORD_2_IDAU_ANSC_Pos) /* (FUSES_USER_WORD_2) Application Non-Secure Callable Mask */
#define FUSES_USER_WORD_2_IDAU_ANSC(value)    (FUSES_USER_WORD_2_IDAU_ANSC_Msk & (_UINT32_(value) << FUSES_USER_WORD_2_IDAU_ANSC_Pos)) /* Assigment of value for IDAU_ANSC in the FUSES_USER_WORD_2 register */
#define FUSES_USER_WORD_2_IDAU_DS_Pos         _UINT32_(22)                                         /* (FUSES_USER_WORD_2) Data Secure Position */
#define FUSES_USER_WORD_2_IDAU_DS_Msk         (_UINT32_(0x7F) << FUSES_USER_WORD_2_IDAU_DS_Pos)    /* (FUSES_USER_WORD_2) Data Secure Mask */
#define FUSES_USER_WORD_2_IDAU_DS(value)      (FUSES_USER_WORD_2_IDAU_DS_Msk & (_UINT32_(value) << FUSES_USER_WORD_2_IDAU_DS_Pos)) /* Assigment of value for IDAU_DS in the FUSES_USER_WORD_2 register */
#define FUSES_USER_WORD_2_Msk                 _UINT32_(0x1FCFFFFF)                                 /* (FUSES_USER_WORD_2) Register Mask  */


/* -------- FUSES_USER_WORD_3 : (FUSES Offset: 0x0C) (R/W 32) USER Page Word 3 -------- */
#define FUSES_USER_WORD_3_RESETVALUE          _UINT32_(0xFFFFFFFF)                                 /*  (FUSES_USER_WORD_3) USER Page Word 3  Reset Value */

#define FUSES_USER_WORD_3_IDAU_RS_Pos         _UINT32_(0)                                          /* (FUSES_USER_WORD_3) RAM Secure Position */
#define FUSES_USER_WORD_3_IDAU_RS_Msk         (_UINT32_(0x1FF) << FUSES_USER_WORD_3_IDAU_RS_Pos)   /* (FUSES_USER_WORD_3) RAM Secure Mask */
#define FUSES_USER_WORD_3_IDAU_RS(value)      (FUSES_USER_WORD_3_IDAU_RS_Msk & (_UINT32_(value) << FUSES_USER_WORD_3_IDAU_RS_Pos)) /* Assigment of value for IDAU_RS in the FUSES_USER_WORD_3 register */
#define FUSES_USER_WORD_3_NVMCTRL_URWEN_Pos   _UINT32_(10)                                         /* (FUSES_USER_WORD_3) User Row Write Enable Position */
#define FUSES_USER_WORD_3_NVMCTRL_URWEN_Msk   (_UINT32_(0x1) << FUSES_USER_WORD_3_NVMCTRL_URWEN_Pos) /* (FUSES_USER_WORD_3) User Row Write Enable Mask */
#define FUSES_USER_WORD_3_NVMCTRL_URWEN(value) (FUSES_USER_WORD_3_NVMCTRL_URWEN_Msk & (_UINT32_(value) << FUSES_USER_WORD_3_NVMCTRL_URWEN_Pos)) /* Assigment of value for NVMCTRL_URWEN in the FUSES_USER_WORD_3 register */
#define FUSES_USER_WORD_3_Msk                 _UINT32_(0x000005FF)                                 /* (FUSES_USER_WORD_3) Register Mask  */


/* -------- FUSES_USER_WORD_4 : (FUSES Offset: 0x10) (R/W 32) USER Page Word 4 -------- */
#define FUSES_USER_WORD_4_RESETVALUE          _UINT32_(0x00)                                       /*  (FUSES_USER_WORD_4) USER Page Word 4  Reset Value */

#define FUSES_USER_WORD_4_NONSECA_PAC_Pos     _UINT32_(0)                                          /* (FUSES_USER_WORD_4) PAC Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_PAC_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_PAC_Pos) /* (FUSES_USER_WORD_4) PAC Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_PAC(value)  (FUSES_USER_WORD_4_NONSECA_PAC_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_PAC_Pos)) /* Assigment of value for NONSECA_PAC in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_PM_Pos      _UINT32_(1)                                          /* (FUSES_USER_WORD_4) PM Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_PM_Msk      (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_PM_Pos)  /* (FUSES_USER_WORD_4) PM Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_PM(value)   (FUSES_USER_WORD_4_NONSECA_PM_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_PM_Pos)) /* Assigment of value for NONSECA_PM in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_MCLK_Pos    _UINT32_(2)                                          /* (FUSES_USER_WORD_4) MCLK Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_MCLK_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_MCLK_Pos) /* (FUSES_USER_WORD_4) MCLK Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_MCLK(value) (FUSES_USER_WORD_4_NONSECA_MCLK_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_MCLK_Pos)) /* Assigment of value for NONSECA_MCLK in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_RSTC_Pos    _UINT32_(3)                                          /* (FUSES_USER_WORD_4) RSTC Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_RSTC_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_RSTC_Pos) /* (FUSES_USER_WORD_4) RSTC Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_RSTC(value) (FUSES_USER_WORD_4_NONSECA_RSTC_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_RSTC_Pos)) /* Assigment of value for NONSECA_RSTC in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_OSCCTRL_Pos _UINT32_(4)                                          /* (FUSES_USER_WORD_4) OSCCTRL Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_OSCCTRL_Msk (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_OSCCTRL_Pos) /* (FUSES_USER_WORD_4) OSCCTRL Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_OSCCTRL(value) (FUSES_USER_WORD_4_NONSECA_OSCCTRL_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_OSCCTRL_Pos)) /* Assigment of value for NONSECA_OSCCTRL in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_OSC32KCTRL_Pos _UINT32_(5)                                          /* (FUSES_USER_WORD_4) OSC32KCTRL Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_OSC32KCTRL_Msk (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_OSC32KCTRL_Pos) /* (FUSES_USER_WORD_4) OSC32KCTRL Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_OSC32KCTRL(value) (FUSES_USER_WORD_4_NONSECA_OSC32KCTRL_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_OSC32KCTRL_Pos)) /* Assigment of value for NONSECA_OSC32KCTRL in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_SUPC_Pos    _UINT32_(6)                                          /* (FUSES_USER_WORD_4) SUPC Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_SUPC_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_SUPC_Pos) /* (FUSES_USER_WORD_4) SUPC Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_SUPC(value) (FUSES_USER_WORD_4_NONSECA_SUPC_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_SUPC_Pos)) /* Assigment of value for NONSECA_SUPC in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_GCLK_Pos    _UINT32_(7)                                          /* (FUSES_USER_WORD_4) GCLK Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_GCLK_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_GCLK_Pos) /* (FUSES_USER_WORD_4) GCLK Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_GCLK(value) (FUSES_USER_WORD_4_NONSECA_GCLK_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_GCLK_Pos)) /* Assigment of value for NONSECA_GCLK in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_WDT_Pos     _UINT32_(8)                                          /* (FUSES_USER_WORD_4) WDT Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_WDT_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_WDT_Pos) /* (FUSES_USER_WORD_4) WDT Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_WDT(value)  (FUSES_USER_WORD_4_NONSECA_WDT_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_WDT_Pos)) /* Assigment of value for NONSECA_WDT in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_RTC_Pos     _UINT32_(9)                                          /* (FUSES_USER_WORD_4) RTC Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_RTC_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_RTC_Pos) /* (FUSES_USER_WORD_4) RTC Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_RTC(value)  (FUSES_USER_WORD_4_NONSECA_RTC_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_RTC_Pos)) /* Assigment of value for NONSECA_RTC in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_EIC_Pos     _UINT32_(10)                                         /* (FUSES_USER_WORD_4) EIC Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_EIC_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_EIC_Pos) /* (FUSES_USER_WORD_4) EIC Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_EIC(value)  (FUSES_USER_WORD_4_NONSECA_EIC_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_EIC_Pos)) /* Assigment of value for NONSECA_EIC in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_FREQM_Pos   _UINT32_(11)                                         /* (FUSES_USER_WORD_4) FREQM Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_FREQM_Msk   (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_FREQM_Pos) /* (FUSES_USER_WORD_4) FREQM Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_FREQM(value) (FUSES_USER_WORD_4_NONSECA_FREQM_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_FREQM_Pos)) /* Assigment of value for NONSECA_FREQM in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_PORT_Pos    _UINT32_(12)                                         /* (FUSES_USER_WORD_4) PORT Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_PORT_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_PORT_Pos) /* (FUSES_USER_WORD_4) PORT Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_PORT(value) (FUSES_USER_WORD_4_NONSECA_PORT_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_PORT_Pos)) /* Assigment of value for NONSECA_PORT in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_NONSECA_AC_Pos      _UINT32_(13)                                         /* (FUSES_USER_WORD_4) AC Non-Secure Position */
#define FUSES_USER_WORD_4_NONSECA_AC_Msk      (_UINT32_(0x1) << FUSES_USER_WORD_4_NONSECA_AC_Pos)  /* (FUSES_USER_WORD_4) AC Non-Secure Mask */
#define FUSES_USER_WORD_4_NONSECA_AC(value)   (FUSES_USER_WORD_4_NONSECA_AC_Msk & (_UINT32_(value) << FUSES_USER_WORD_4_NONSECA_AC_Pos)) /* Assigment of value for NONSECA_AC in the FUSES_USER_WORD_4 register */
#define FUSES_USER_WORD_4_Msk                 _UINT32_(0x00003FFF)                                 /* (FUSES_USER_WORD_4) Register Mask  */


/* -------- FUSES_USER_WORD_5 : (FUSES Offset: 0x14) (R/W 32) USER Page Word 5 -------- */
#define FUSES_USER_WORD_5_RESETVALUE          _UINT32_(0x00)                                       /*  (FUSES_USER_WORD_5) USER Page Word 5  Reset Value */

#define FUSES_USER_WORD_5_NONSECB_IDAU_Pos    _UINT32_(0)                                          /* (FUSES_USER_WORD_5) IDAU Non-Secure Position */
#define FUSES_USER_WORD_5_NONSECB_IDAU_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_5_NONSECB_IDAU_Pos) /* (FUSES_USER_WORD_5) IDAU Non-Secure Mask */
#define FUSES_USER_WORD_5_NONSECB_IDAU(value) (FUSES_USER_WORD_5_NONSECB_IDAU_Msk & (_UINT32_(value) << FUSES_USER_WORD_5_NONSECB_IDAU_Pos)) /* Assigment of value for NONSECB_IDAU in the FUSES_USER_WORD_5 register */
#define FUSES_USER_WORD_5_NONSECB_DSU_Pos     _UINT32_(1)                                          /* (FUSES_USER_WORD_5) DSU Non-Secure Position */
#define FUSES_USER_WORD_5_NONSECB_DSU_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_5_NONSECB_DSU_Pos) /* (FUSES_USER_WORD_5) DSU Non-Secure Mask */
#define FUSES_USER_WORD_5_NONSECB_DSU(value)  (FUSES_USER_WORD_5_NONSECB_DSU_Msk & (_UINT32_(value) << FUSES_USER_WORD_5_NONSECB_DSU_Pos)) /* Assigment of value for NONSECB_DSU in the FUSES_USER_WORD_5 register */
#define FUSES_USER_WORD_5_NONSECB_NVMCTRL_Pos _UINT32_(2)                                          /* (FUSES_USER_WORD_5) NVMCTRL Non-Secure Position */
#define FUSES_USER_WORD_5_NONSECB_NVMCTRL_Msk (_UINT32_(0x1) << FUSES_USER_WORD_5_NONSECB_NVMCTRL_Pos) /* (FUSES_USER_WORD_5) NVMCTRL Non-Secure Mask */
#define FUSES_USER_WORD_5_NONSECB_NVMCTRL(value) (FUSES_USER_WORD_5_NONSECB_NVMCTRL_Msk & (_UINT32_(value) << FUSES_USER_WORD_5_NONSECB_NVMCTRL_Pos)) /* Assigment of value for NONSECB_NVMCTRL in the FUSES_USER_WORD_5 register */
#define FUSES_USER_WORD_5_NONSECB_DMAC_Pos    _UINT32_(3)                                          /* (FUSES_USER_WORD_5) DMAC Non-Secure Position */
#define FUSES_USER_WORD_5_NONSECB_DMAC_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_5_NONSECB_DMAC_Pos) /* (FUSES_USER_WORD_5) DMAC Non-Secure Mask */
#define FUSES_USER_WORD_5_NONSECB_DMAC(value) (FUSES_USER_WORD_5_NONSECB_DMAC_Msk & (_UINT32_(value) << FUSES_USER_WORD_5_NONSECB_DMAC_Pos)) /* Assigment of value for NONSECB_DMAC in the FUSES_USER_WORD_5 register */
#define FUSES_USER_WORD_5_NONSECB_USB_Pos     _UINT32_(5)                                          /* (FUSES_USER_WORD_5) USB Non-Secure Position */
#define FUSES_USER_WORD_5_NONSECB_USB_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_5_NONSECB_USB_Pos) /* (FUSES_USER_WORD_5) USB Non-Secure Mask */
#define FUSES_USER_WORD_5_NONSECB_USB(value)  (FUSES_USER_WORD_5_NONSECB_USB_Msk & (_UINT32_(value) << FUSES_USER_WORD_5_NONSECB_USB_Pos)) /* Assigment of value for NONSECB_USB in the FUSES_USER_WORD_5 register */
#define FUSES_USER_WORD_5_Msk                 _UINT32_(0x0000002F)                                 /* (FUSES_USER_WORD_5) Register Mask  */


/* -------- FUSES_USER_WORD_6 : (FUSES Offset: 0x18) (R/W 32) USER Page Word 6 -------- */
#define FUSES_USER_WORD_6_RESETVALUE          _UINT32_(0x00)                                       /*  (FUSES_USER_WORD_6) USER Page Word 6  Reset Value */

#define FUSES_USER_WORD_6_NONSECC_EVSYS_Pos   _UINT32_(0)                                          /* (FUSES_USER_WORD_6) EVSYS Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_EVSYS_Msk   (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_EVSYS_Pos) /* (FUSES_USER_WORD_6) EVSYS Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_EVSYS(value) (FUSES_USER_WORD_6_NONSECC_EVSYS_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_EVSYS_Pos)) /* Assigment of value for NONSECC_EVSYS in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_SERCOM0_Pos _UINT32_(1)                                          /* (FUSES_USER_WORD_6) SERCOM0 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_SERCOM0_Msk (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_SERCOM0_Pos) /* (FUSES_USER_WORD_6) SERCOM0 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_SERCOM0(value) (FUSES_USER_WORD_6_NONSECC_SERCOM0_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_SERCOM0_Pos)) /* Assigment of value for NONSECC_SERCOM0 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_SERCOM1_Pos _UINT32_(2)                                          /* (FUSES_USER_WORD_6) SERCOM1 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_SERCOM1_Msk (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_SERCOM1_Pos) /* (FUSES_USER_WORD_6) SERCOM1 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_SERCOM1(value) (FUSES_USER_WORD_6_NONSECC_SERCOM1_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_SERCOM1_Pos)) /* Assigment of value for NONSECC_SERCOM1 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_SERCOM2_Pos _UINT32_(3)                                          /* (FUSES_USER_WORD_6) SERCOM2 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_SERCOM2_Msk (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_SERCOM2_Pos) /* (FUSES_USER_WORD_6) SERCOM2 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_SERCOM2(value) (FUSES_USER_WORD_6_NONSECC_SERCOM2_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_SERCOM2_Pos)) /* Assigment of value for NONSECC_SERCOM2 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_SERCOM3_Pos _UINT32_(4)                                          /* (FUSES_USER_WORD_6) SERCOM3 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_SERCOM3_Msk (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_SERCOM3_Pos) /* (FUSES_USER_WORD_6) SERCOM3 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_SERCOM3(value) (FUSES_USER_WORD_6_NONSECC_SERCOM3_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_SERCOM3_Pos)) /* Assigment of value for NONSECC_SERCOM3 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_SERCOM4_Pos _UINT32_(5)                                          /* (FUSES_USER_WORD_6) SERCOM4 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_SERCOM4_Msk (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_SERCOM4_Pos) /* (FUSES_USER_WORD_6) SERCOM4 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_SERCOM4(value) (FUSES_USER_WORD_6_NONSECC_SERCOM4_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_SERCOM4_Pos)) /* Assigment of value for NONSECC_SERCOM4 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_SERCOM5_Pos _UINT32_(6)                                          /* (FUSES_USER_WORD_6) SERCOM5 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_SERCOM5_Msk (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_SERCOM5_Pos) /* (FUSES_USER_WORD_6) SERCOM5 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_SERCOM5(value) (FUSES_USER_WORD_6_NONSECC_SERCOM5_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_SERCOM5_Pos)) /* Assigment of value for NONSECC_SERCOM5 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_TC0_Pos     _UINT32_(7)                                          /* (FUSES_USER_WORD_6) TC0 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_TC0_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_TC0_Pos) /* (FUSES_USER_WORD_6) TC0 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_TC0(value)  (FUSES_USER_WORD_6_NONSECC_TC0_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TC0_Pos)) /* Assigment of value for NONSECC_TC0 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_TC1_Pos     _UINT32_(8)                                          /* (FUSES_USER_WORD_6) TC1 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_TC1_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_TC1_Pos) /* (FUSES_USER_WORD_6) TC1 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_TC1(value)  (FUSES_USER_WORD_6_NONSECC_TC1_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TC1_Pos)) /* Assigment of value for NONSECC_TC1 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_TC2_Pos     _UINT32_(9)                                          /* (FUSES_USER_WORD_6) TC2 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_TC2_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_TC2_Pos) /* (FUSES_USER_WORD_6) TC2 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_TC2(value)  (FUSES_USER_WORD_6_NONSECC_TC2_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TC2_Pos)) /* Assigment of value for NONSECC_TC2 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_TCC0_Pos    _UINT32_(10)                                         /* (FUSES_USER_WORD_6) TCC0 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_TCC0_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_TCC0_Pos) /* (FUSES_USER_WORD_6) TCC0 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_TCC0(value) (FUSES_USER_WORD_6_NONSECC_TCC0_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TCC0_Pos)) /* Assigment of value for NONSECC_TCC0 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_TCC1_Pos    _UINT32_(11)                                         /* (FUSES_USER_WORD_6) TCC1 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_TCC1_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_TCC1_Pos) /* (FUSES_USER_WORD_6) TCC1 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_TCC1(value) (FUSES_USER_WORD_6_NONSECC_TCC1_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TCC1_Pos)) /* Assigment of value for NONSECC_TCC1 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_TCC2_Pos    _UINT32_(12)                                         /* (FUSES_USER_WORD_6) TCC2 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_TCC2_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_TCC2_Pos) /* (FUSES_USER_WORD_6) TCC2 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_TCC2(value) (FUSES_USER_WORD_6_NONSECC_TCC2_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TCC2_Pos)) /* Assigment of value for NONSECC_TCC2 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_TCC3_Pos    _UINT32_(13)                                         /* (FUSES_USER_WORD_6) TCC3 Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_TCC3_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_TCC3_Pos) /* (FUSES_USER_WORD_6) TCC3 Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_TCC3(value) (FUSES_USER_WORD_6_NONSECC_TCC3_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TCC3_Pos)) /* Assigment of value for NONSECC_TCC3 in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_ADC_Pos     _UINT32_(14)                                         /* (FUSES_USER_WORD_6) ADC Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_ADC_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_ADC_Pos) /* (FUSES_USER_WORD_6) ADC Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_ADC(value)  (FUSES_USER_WORD_6_NONSECC_ADC_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_ADC_Pos)) /* Assigment of value for NONSECC_ADC in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_DAC_Pos     _UINT32_(15)                                         /* (FUSES_USER_WORD_6) DAC Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_DAC_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_DAC_Pos) /* (FUSES_USER_WORD_6) DAC Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_DAC(value)  (FUSES_USER_WORD_6_NONSECC_DAC_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_DAC_Pos)) /* Assigment of value for NONSECC_DAC in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_PTC_Pos     _UINT32_(16)                                         /* (FUSES_USER_WORD_6) PTC Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_PTC_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_PTC_Pos) /* (FUSES_USER_WORD_6) PTC Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_PTC(value)  (FUSES_USER_WORD_6_NONSECC_PTC_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_PTC_Pos)) /* Assigment of value for NONSECC_PTC in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_TRNG_Pos    _UINT32_(17)                                         /* (FUSES_USER_WORD_6) TRNG Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_TRNG_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_TRNG_Pos) /* (FUSES_USER_WORD_6) TRNG Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_TRNG(value) (FUSES_USER_WORD_6_NONSECC_TRNG_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TRNG_Pos)) /* Assigment of value for NONSECC_TRNG in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_CCL_Pos     _UINT32_(18)                                         /* (FUSES_USER_WORD_6) CCL Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_CCL_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_CCL_Pos) /* (FUSES_USER_WORD_6) CCL Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_CCL(value)  (FUSES_USER_WORD_6_NONSECC_CCL_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_CCL_Pos)) /* Assigment of value for NONSECC_CCL in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_I2S_Pos     _UINT32_(19)                                         /* (FUSES_USER_WORD_6) I2S Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_I2S_Msk     (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_I2S_Pos) /* (FUSES_USER_WORD_6) I2S Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_I2S(value)  (FUSES_USER_WORD_6_NONSECC_I2S_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_I2S_Pos)) /* Assigment of value for NONSECC_I2S in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_OPAMP_Pos   _UINT32_(20)                                         /* (FUSES_USER_WORD_6) OPAMP Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_OPAMP_Msk   (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_OPAMP_Pos) /* (FUSES_USER_WORD_6) OPAMP Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_OPAMP(value) (FUSES_USER_WORD_6_NONSECC_OPAMP_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_OPAMP_Pos)) /* Assigment of value for NONSECC_OPAMP in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_NONSECC_TRAM_Pos    _UINT32_(21)                                         /* (FUSES_USER_WORD_6) TRAM Non-Secure Position */
#define FUSES_USER_WORD_6_NONSECC_TRAM_Msk    (_UINT32_(0x1) << FUSES_USER_WORD_6_NONSECC_TRAM_Pos) /* (FUSES_USER_WORD_6) TRAM Non-Secure Mask */
#define FUSES_USER_WORD_6_NONSECC_TRAM(value) (FUSES_USER_WORD_6_NONSECC_TRAM_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TRAM_Pos)) /* Assigment of value for NONSECC_TRAM in the FUSES_USER_WORD_6 register */
#define FUSES_USER_WORD_6_Msk                 _UINT32_(0x003FFFFF)                                 /* (FUSES_USER_WORD_6) Register Mask  */

#define FUSES_USER_WORD_6_NONSECC_SERCOM_Pos  _UINT32_(1)                                          /* (FUSES_USER_WORD_6 Position) SERCOMx Non-Secure */
#define FUSES_USER_WORD_6_NONSECC_SERCOM_Msk  (_UINT32_(0x3F) << FUSES_USER_WORD_6_NONSECC_SERCOM_Pos) /* (FUSES_USER_WORD_6 Mask) NONSECC_SERCOM */
#define FUSES_USER_WORD_6_NONSECC_SERCOM(value) (FUSES_USER_WORD_6_NONSECC_SERCOM_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_SERCOM_Pos)) 
#define FUSES_USER_WORD_6_NONSECC_TC_Pos      _UINT32_(7)                                          /* (FUSES_USER_WORD_6 Position) TCx Non-Secure */
#define FUSES_USER_WORD_6_NONSECC_TC_Msk      (_UINT32_(0x7) << FUSES_USER_WORD_6_NONSECC_TC_Pos)  /* (FUSES_USER_WORD_6 Mask) NONSECC_TC */
#define FUSES_USER_WORD_6_NONSECC_TC(value)   (FUSES_USER_WORD_6_NONSECC_TC_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TC_Pos)) 
#define FUSES_USER_WORD_6_NONSECC_TCC_Pos     _UINT32_(10)                                         /* (FUSES_USER_WORD_6 Position) TCCx Non-Secure */
#define FUSES_USER_WORD_6_NONSECC_TCC_Msk     (_UINT32_(0xF) << FUSES_USER_WORD_6_NONSECC_TCC_Pos) /* (FUSES_USER_WORD_6 Mask) NONSECC_TCC */
#define FUSES_USER_WORD_6_NONSECC_TCC(value)  (FUSES_USER_WORD_6_NONSECC_TCC_Msk & (_UINT32_(value) << FUSES_USER_WORD_6_NONSECC_TCC_Pos)) 

/* -------- FUSES_USER_WORD_7 : (FUSES Offset: 0x1C) (R/W 32) USER Page Word 7 -------- */
#define FUSES_USER_WORD_7_RESETVALUE          _UINT32_(0x00)                                       /*  (FUSES_USER_WORD_7) USER Page Word 7  Reset Value */

#define FUSES_USER_WORD_7_BOOTROM_CDIROFFSET_Pos _UINT32_(0)                                          /* (FUSES_USER_WORD_7) Location of CDI value when DICE is programmed Position */
#define FUSES_USER_WORD_7_BOOTROM_CDIROFFSET_Msk (_UINT32_(0xFFFFFFFF) << FUSES_USER_WORD_7_BOOTROM_CDIROFFSET_Pos) /* (FUSES_USER_WORD_7) Location of CDI value when DICE is programmed Mask */
#define FUSES_USER_WORD_7_BOOTROM_CDIROFFSET(value) (FUSES_USER_WORD_7_BOOTROM_CDIROFFSET_Msk & (_UINT32_(value) << FUSES_USER_WORD_7_BOOTROM_CDIROFFSET_Pos)) /* Assigment of value for BOOTROM_CDIROFFSET in the FUSES_USER_WORD_7 register */
#define FUSES_USER_WORD_7_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (FUSES_USER_WORD_7) Register Mask  */


/* -------- FUSES_USER_WORD_8 : (FUSES Offset: 0x20) (R/W 32) USER Page Word 8 -------- */
#define FUSES_USER_WORD_8_RESETVALUE          _UINT32_(0xE87673B6)                                 /*  (FUSES_USER_WORD_8) USER Page Word 8  Reset Value */

#define FUSES_USER_WORD_8_BOOTROM_USERCRC_Pos _UINT32_(0)                                          /* (FUSES_USER_WORD_8) CRC for USER[1,2,3] DWORDS Position */
#define FUSES_USER_WORD_8_BOOTROM_USERCRC_Msk (_UINT32_(0xFFFFFFFF) << FUSES_USER_WORD_8_BOOTROM_USERCRC_Pos) /* (FUSES_USER_WORD_8) CRC for USER[1,2,3] DWORDS Mask */
#define FUSES_USER_WORD_8_BOOTROM_USERCRC(value) (FUSES_USER_WORD_8_BOOTROM_USERCRC_Msk & (_UINT32_(value) << FUSES_USER_WORD_8_BOOTROM_USERCRC_Pos)) /* Assigment of value for BOOTROM_USERCRC in the FUSES_USER_WORD_8 register */
#define FUSES_USER_WORD_8_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (FUSES_USER_WORD_8) Register Mask  */


/** \brief FUSES register offsets definitions */
#define FUSES_SW_CALIB_WORD_0_REG_OFST _UINT32_(0x00)      /* (FUSES_SW_CALIB_WORD_0) SW_CALIB Page Word 0 Offset */
#define FUSES_BOCOR_WORD_0_REG_OFST    _UINT32_(0x00)      /* (FUSES_BOCOR_WORD_0) BOCOR Page Word 0 Offset */
#define FUSES_BOCOR_WORD_1_REG_OFST    _UINT32_(0x04)      /* (FUSES_BOCOR_WORD_1) BOCOR Page Word 1 Offset */
#define FUSES_BOCOR_WORD_2_REG_OFST    _UINT32_(0x08)      /* (FUSES_BOCOR_WORD_2) BOCOR Page Word 2 Offset */
#define FUSES_BOCOR_WORD_4_REG_OFST    _UINT32_(0x10)      /* (FUSES_BOCOR_WORD_4) BOCOR Page Word 4 Offset */
#define FUSES_BOCOR_WORD_5_REG_OFST    _UINT32_(0x14)      /* (FUSES_BOCOR_WORD_5) BOCOR Page Word 5 Offset */
#define FUSES_BOCOR_WORD_6_REG_OFST    _UINT32_(0x18)      /* (FUSES_BOCOR_WORD_6) BOCOR Page Word 6 Offset */
#define FUSES_BOCOR_WORD_7_REG_OFST    _UINT32_(0x1C)      /* (FUSES_BOCOR_WORD_7) BOCOR Page Word 7 Offset */
#define FUSES_BOCOR_WORD_8_REG_OFST    _UINT32_(0x20)      /* (FUSES_BOCOR_WORD_8) BOCOR Page Word 8 Offset */
#define FUSES_BOCOR_WORD_9_REG_OFST    _UINT32_(0x24)      /* (FUSES_BOCOR_WORD_9) BOCOR Page Word 9 Offset */
#define FUSES_BOCOR_WORD_10_REG_OFST   _UINT32_(0x28)      /* (FUSES_BOCOR_WORD_10) BOCOR Page Word 10 Offset */
#define FUSES_BOCOR_WORD_11_REG_OFST   _UINT32_(0x2C)      /* (FUSES_BOCOR_WORD_11) BOCOR Page Word 11 Offset */
#define FUSES_BOCOR_WORD_12_REG_OFST   _UINT32_(0x30)      /* (FUSES_BOCOR_WORD_12) BOCOR Page Word 12 Offset */
#define FUSES_BOCOR_WORD_13_REG_OFST   _UINT32_(0x34)      /* (FUSES_BOCOR_WORD_13) BOCOR Page Word 13 Offset */
#define FUSES_BOCOR_WORD_14_REG_OFST   _UINT32_(0x38)      /* (FUSES_BOCOR_WORD_14) BOCOR Page Word 14 Offset */
#define FUSES_BOCOR_WORD_15_REG_OFST   _UINT32_(0x3C)      /* (FUSES_BOCOR_WORD_15) BOCOR Page Word 15 Offset */
#define FUSES_BOCOR_WORD_16_REG_OFST   _UINT32_(0x40)      /* (FUSES_BOCOR_WORD_16) BOCOR Page Word 16 Offset */
#define FUSES_BOCOR_WORD_17_REG_OFST   _UINT32_(0x44)      /* (FUSES_BOCOR_WORD_17) BOCOR Page Word 17 Offset */
#define FUSES_BOCOR_WORD_18_REG_OFST   _UINT32_(0x48)      /* (FUSES_BOCOR_WORD_18) BOCOR Page Word 18 Offset */
#define FUSES_BOCOR_WORD_19_REG_OFST   _UINT32_(0x4C)      /* (FUSES_BOCOR_WORD_19) BOCOR Page Word 19 Offset */
#define FUSES_BOCOR_WORD_20_REG_OFST   _UINT32_(0x50)      /* (FUSES_BOCOR_WORD_20) BOCOR Page Word 20 Offset */
#define FUSES_BOCOR_WORD_21_REG_OFST   _UINT32_(0x54)      /* (FUSES_BOCOR_WORD_21) BOCOR Page Word 21 Offset */
#define FUSES_BOCOR_WORD_22_REG_OFST   _UINT32_(0x58)      /* (FUSES_BOCOR_WORD_22) BOCOR Page Word 22 Offset */
#define FUSES_BOCOR_WORD_23_REG_OFST   _UINT32_(0x5C)      /* (FUSES_BOCOR_WORD_23) BOCOR Page Word 23 Offset */
#define FUSES_BOCOR_WORD_24_REG_OFST   _UINT32_(0x60)      /* (FUSES_BOCOR_WORD_24) BOCOR Page Word 24 Offset */
#define FUSES_BOCOR_WORD_25_REG_OFST   _UINT32_(0x64)      /* (FUSES_BOCOR_WORD_25) BOCOR Page Word 25 Offset */
#define FUSES_BOCOR_WORD_26_REG_OFST   _UINT32_(0x68)      /* (FUSES_BOCOR_WORD_26) BOCOR Page Word 26 Offset */
#define FUSES_BOCOR_WORD_27_REG_OFST   _UINT32_(0x6C)      /* (FUSES_BOCOR_WORD_27) BOCOR Page Word 27 Offset */
#define FUSES_BOCOR_WORD_28_REG_OFST   _UINT32_(0x70)      /* (FUSES_BOCOR_WORD_28) BOCOR Page Word 28 Offset */
#define FUSES_BOCOR_WORD_29_REG_OFST   _UINT32_(0x74)      /* (FUSES_BOCOR_WORD_29) BOCOR Page Word 29 Offset */
#define FUSES_BOCOR_WORD_30_REG_OFST   _UINT32_(0x78)      /* (FUSES_BOCOR_WORD_30) BOCOR Page Word 30 Offset */
#define FUSES_BOCOR_WORD_31_REG_OFST   _UINT32_(0x7C)      /* (FUSES_BOCOR_WORD_31) BOCOR Page Word 31 Offset */
#define FUSES_BOCOR_WORD_32_REG_OFST   _UINT32_(0x80)      /* (FUSES_BOCOR_WORD_32) BOCOR Page Word 32 Offset */
#define FUSES_BOCOR_WORD_33_REG_OFST   _UINT32_(0x84)      /* (FUSES_BOCOR_WORD_33) BOCOR Page Word 33 Offset */
#define FUSES_BOCOR_WORD_34_REG_OFST   _UINT32_(0x88)      /* (FUSES_BOCOR_WORD_34) BOCOR Page Word 34 Offset */
#define FUSES_BOCOR_WORD_35_REG_OFST   _UINT32_(0x8C)      /* (FUSES_BOCOR_WORD_35) BOCOR Page Word 35 Offset */
#define FUSES_BOCOR_WORD_36_REG_OFST   _UINT32_(0x90)      /* (FUSES_BOCOR_WORD_36) BOCOR Page Word 36 Offset */
#define FUSES_BOCOR_WORD_37_REG_OFST   _UINT32_(0x94)      /* (FUSES_BOCOR_WORD_37) BOCOR Page Word 37 Offset */
#define FUSES_BOCOR_WORD_38_REG_OFST   _UINT32_(0x98)      /* (FUSES_BOCOR_WORD_38) BOCOR Page Word 38 Offset */
#define FUSES_BOCOR_WORD_39_REG_OFST   _UINT32_(0x9C)      /* (FUSES_BOCOR_WORD_39) BOCOR Page Word 39 Offset */
#define FUSES_BOCOR_WORD_40_REG_OFST   _UINT32_(0xA0)      /* (FUSES_BOCOR_WORD_40) BOCOR Page Word 40 Offset */
#define FUSES_BOCOR_WORD_41_REG_OFST   _UINT32_(0xA4)      /* (FUSES_BOCOR_WORD_41) BOCOR Page Word 41 Offset */
#define FUSES_BOCOR_WORD_42_REG_OFST   _UINT32_(0xA8)      /* (FUSES_BOCOR_WORD_42) BOCOR Page Word 42 Offset */
#define FUSES_BOCOR_WORD_43_REG_OFST   _UINT32_(0xAC)      /* (FUSES_BOCOR_WORD_43) BOCOR Page Word 43 Offset */
#define FUSES_BOCOR_WORD_56_REG_OFST   _UINT32_(0xE0)      /* (FUSES_BOCOR_WORD_56) BOCOR Page Word 56 Offset */
#define FUSES_BOCOR_WORD_57_REG_OFST   _UINT32_(0xE4)      /* (FUSES_BOCOR_WORD_57) BOCOR Page Word 57 Offset */
#define FUSES_BOCOR_WORD_58_REG_OFST   _UINT32_(0xE8)      /* (FUSES_BOCOR_WORD_58) BOCOR Page Word 58 Offset */
#define FUSES_BOCOR_WORD_59_REG_OFST   _UINT32_(0xEC)      /* (FUSES_BOCOR_WORD_59) BOCOR Page Word 59 Offset */
#define FUSES_BOCOR_WORD_60_REG_OFST   _UINT32_(0xF0)      /* (FUSES_BOCOR_WORD_60) BOCOR Page Word 60 Offset */
#define FUSES_BOCOR_WORD_61_REG_OFST   _UINT32_(0xF4)      /* (FUSES_BOCOR_WORD_61) BOCOR Page Word 61 Offset */
#define FUSES_BOCOR_WORD_62_REG_OFST   _UINT32_(0xF8)      /* (FUSES_BOCOR_WORD_62) BOCOR Page Word 62 Offset */
#define FUSES_BOCOR_WORD_63_REG_OFST   _UINT32_(0xFC)      /* (FUSES_BOCOR_WORD_63) BOCOR Page Word 63 Offset */
#define FUSES_OTP1_WORD_0_REG_OFST     _UINT32_(0x00)      /* (FUSES_OTP1_WORD_0) OTP1 Page Word 0 Offset */
#define FUSES_OTP1_WORD_1_REG_OFST     _UINT32_(0x04)      /* (FUSES_OTP1_WORD_1) OTP1 Page Word 1 Offset */
#define FUSES_OTP2_WORD_1_REG_OFST     _UINT32_(0x04)      /* (FUSES_OTP2_WORD_1) OTP2 Page Word 1 Offset */
#define FUSES_USER_WORD_0_REG_OFST     _UINT32_(0x00)      /* (FUSES_USER_WORD_0) USER Page Word 0 Offset */
#define FUSES_USER_WORD_1_REG_OFST     _UINT32_(0x04)      /* (FUSES_USER_WORD_1) USER Page Word 1 Offset */
#define FUSES_USER_WORD_2_REG_OFST     _UINT32_(0x08)      /* (FUSES_USER_WORD_2) USER Page Word 2 Offset */
#define FUSES_USER_WORD_3_REG_OFST     _UINT32_(0x0C)      /* (FUSES_USER_WORD_3) USER Page Word 3 Offset */
#define FUSES_USER_WORD_4_REG_OFST     _UINT32_(0x10)      /* (FUSES_USER_WORD_4) USER Page Word 4 Offset */
#define FUSES_USER_WORD_5_REG_OFST     _UINT32_(0x14)      /* (FUSES_USER_WORD_5) USER Page Word 5 Offset */
#define FUSES_USER_WORD_6_REG_OFST     _UINT32_(0x18)      /* (FUSES_USER_WORD_6) USER Page Word 6 Offset */
#define FUSES_USER_WORD_7_REG_OFST     _UINT32_(0x1C)      /* (FUSES_USER_WORD_7) USER Page Word 7 Offset */
#define FUSES_USER_WORD_8_REG_OFST     _UINT32_(0x20)      /* (FUSES_USER_WORD_8) USER Page Word 8 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SW_CALIB_FUSES register API structure */
typedef struct
{
  __I   uint32_t                       FUSES_SW_CALIB_WORD_0; /**< Offset: 0x00 (R/   32) SW_CALIB Page Word 0 */
} fuses_sw_calib_fuses_registers_t;

/** \brief BOCOR_FUSES register API structure */
typedef struct
{
  __IO  uint32_t                       FUSES_BOCOR_WORD_0; /**< Offset: 0x00 (R/W  32) BOCOR Page Word 0 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_1; /**< Offset: 0x04 (R/W  32) BOCOR Page Word 1 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_2; /**< Offset: 0x08 (R/W  32) BOCOR Page Word 2 */
  __I   uint8_t                        Reserved1[0x04];
  __IO  uint32_t                       FUSES_BOCOR_WORD_4; /**< Offset: 0x10 (R/W  32) BOCOR Page Word 4 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_5; /**< Offset: 0x14 (R/W  32) BOCOR Page Word 5 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_6; /**< Offset: 0x18 (R/W  32) BOCOR Page Word 6 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_7; /**< Offset: 0x1C (R/W  32) BOCOR Page Word 7 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_8; /**< Offset: 0x20 (R/W  32) BOCOR Page Word 8 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_9; /**< Offset: 0x24 (R/W  32) BOCOR Page Word 9 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_10; /**< Offset: 0x28 (R/W  32) BOCOR Page Word 10 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_11; /**< Offset: 0x2C (R/W  32) BOCOR Page Word 11 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_12; /**< Offset: 0x30 (R/W  32) BOCOR Page Word 12 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_13; /**< Offset: 0x34 (R/W  32) BOCOR Page Word 13 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_14; /**< Offset: 0x38 (R/W  32) BOCOR Page Word 14 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_15; /**< Offset: 0x3C (R/W  32) BOCOR Page Word 15 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_16; /**< Offset: 0x40 (R/W  32) BOCOR Page Word 16 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_17; /**< Offset: 0x44 (R/W  32) BOCOR Page Word 17 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_18; /**< Offset: 0x48 (R/W  32) BOCOR Page Word 18 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_19; /**< Offset: 0x4C (R/W  32) BOCOR Page Word 19 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_20; /**< Offset: 0x50 (R/W  32) BOCOR Page Word 20 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_21; /**< Offset: 0x54 (R/W  32) BOCOR Page Word 21 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_22; /**< Offset: 0x58 (R/W  32) BOCOR Page Word 22 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_23; /**< Offset: 0x5C (R/W  32) BOCOR Page Word 23 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_24; /**< Offset: 0x60 (R/W  32) BOCOR Page Word 24 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_25; /**< Offset: 0x64 (R/W  32) BOCOR Page Word 25 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_26; /**< Offset: 0x68 (R/W  32) BOCOR Page Word 26 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_27; /**< Offset: 0x6C (R/W  32) BOCOR Page Word 27 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_28; /**< Offset: 0x70 (R/W  32) BOCOR Page Word 28 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_29; /**< Offset: 0x74 (R/W  32) BOCOR Page Word 29 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_30; /**< Offset: 0x78 (R/W  32) BOCOR Page Word 30 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_31; /**< Offset: 0x7C (R/W  32) BOCOR Page Word 31 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_32; /**< Offset: 0x80 (R/W  32) BOCOR Page Word 32 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_33; /**< Offset: 0x84 (R/W  32) BOCOR Page Word 33 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_34; /**< Offset: 0x88 (R/W  32) BOCOR Page Word 34 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_35; /**< Offset: 0x8C (R/W  32) BOCOR Page Word 35 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_36; /**< Offset: 0x90 (R/W  32) BOCOR Page Word 36 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_37; /**< Offset: 0x94 (R/W  32) BOCOR Page Word 37 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_38; /**< Offset: 0x98 (R/W  32) BOCOR Page Word 38 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_39; /**< Offset: 0x9C (R/W  32) BOCOR Page Word 39 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_40; /**< Offset: 0xA0 (R/W  32) BOCOR Page Word 40 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_41; /**< Offset: 0xA4 (R/W  32) BOCOR Page Word 41 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_42; /**< Offset: 0xA8 (R/W  32) BOCOR Page Word 42 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_43; /**< Offset: 0xAC (R/W  32) BOCOR Page Word 43 */
  __I   uint8_t                        Reserved2[0x30];
  __IO  uint32_t                       FUSES_BOCOR_WORD_56; /**< Offset: 0xE0 (R/W  32) BOCOR Page Word 56 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_57; /**< Offset: 0xE4 (R/W  32) BOCOR Page Word 57 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_58; /**< Offset: 0xE8 (R/W  32) BOCOR Page Word 58 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_59; /**< Offset: 0xEC (R/W  32) BOCOR Page Word 59 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_60; /**< Offset: 0xF0 (R/W  32) BOCOR Page Word 60 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_61; /**< Offset: 0xF4 (R/W  32) BOCOR Page Word 61 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_62; /**< Offset: 0xF8 (R/W  32) BOCOR Page Word 62 */
  __IO  uint32_t                       FUSES_BOCOR_WORD_63; /**< Offset: 0xFC (R/W  32) BOCOR Page Word 63 */
} fuses_bocor_fuses_registers_t;

/** \brief OTP1_FUSES register API structure */
typedef struct
{
  __I   uint32_t                       FUSES_OTP1_WORD_0;  /**< Offset: 0x00 (R/   32) OTP1 Page Word 0 */
  __I   uint32_t                       FUSES_OTP1_WORD_1;  /**< Offset: 0x04 (R/   32) OTP1 Page Word 1 */
} fuses_otp1_fuses_registers_t;

/** \brief OTP2_FUSES register API structure */
typedef struct
{
  __I   uint8_t                        Reserved1[0x04];
  __I   uint32_t                       FUSES_OTP2_WORD_1;  /**< Offset: 0x04 (R/   32) OTP2 Page Word 1 */
} fuses_otp2_fuses_registers_t;

/** \brief USER_FUSES register API structure */
typedef struct
{
  __IO  uint32_t                       FUSES_USER_WORD_0;  /**< Offset: 0x00 (R/W  32) USER Page Word 0 */
  __IO  uint32_t                       FUSES_USER_WORD_1;  /**< Offset: 0x04 (R/W  32) USER Page Word 1 */
  __IO  uint32_t                       FUSES_USER_WORD_2;  /**< Offset: 0x08 (R/W  32) USER Page Word 2 */
  __IO  uint32_t                       FUSES_USER_WORD_3;  /**< Offset: 0x0C (R/W  32) USER Page Word 3 */
  __IO  uint32_t                       FUSES_USER_WORD_4;  /**< Offset: 0x10 (R/W  32) USER Page Word 4 */
  __IO  uint32_t                       FUSES_USER_WORD_5;  /**< Offset: 0x14 (R/W  32) USER Page Word 5 */
  __IO  uint32_t                       FUSES_USER_WORD_6;  /**< Offset: 0x18 (R/W  32) USER Page Word 6 */
  __IO  uint32_t                       FUSES_USER_WORD_7;  /**< Offset: 0x1C (R/W  32) USER Page Word 7 */
  __IO  uint32_t                       FUSES_USER_WORD_8;  /**< Offset: 0x20 (R/W  32) USER Page Word 8 */
} fuses_user_fuses_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMLS60_FUSES_COMPONENT_H_ */
