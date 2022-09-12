/*
 * Component description for IDAU
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
#ifndef _PIC32CMLS60_IDAU_COMPONENT_H_
#define _PIC32CMLS60_IDAU_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR IDAU                                         */
/* ************************************************************************** */

/* -------- IDAU_CTRL : (IDAU Offset: 0x00) (R/W 8) Control -------- */
#define IDAU_CTRL_RESETVALUE                  _UINT8_(0x00)                                        /*  (IDAU_CTRL) Control  Reset Value */

#define IDAU_CTRL_ENABLE_Pos                  _UINT8_(1)                                           /* (IDAU_CTRL) Enable Position */
#define IDAU_CTRL_ENABLE_Msk                  (_UINT8_(0x1) << IDAU_CTRL_ENABLE_Pos)               /* (IDAU_CTRL) Enable Mask */
#define IDAU_CTRL_ENABLE(value)               (IDAU_CTRL_ENABLE_Msk & (_UINT8_(value) << IDAU_CTRL_ENABLE_Pos)) /* Assigment of value for ENABLE in the IDAU_CTRL register */
#define IDAU_CTRL_Msk                         _UINT8_(0x02)                                        /* (IDAU_CTRL) Register Mask  */


/* -------- IDAU_SECCTRL : (IDAU Offset: 0x01) (R/W 8) SECCTRL -------- */
#define IDAU_SECCTRL_RESETVALUE               _UINT8_(0x03)                                        /*  (IDAU_SECCTRL) SECCTRL  Reset Value */

#define IDAU_SECCTRL_SCFGWEN_Pos              _UINT8_(0)                                           /* (IDAU_SECCTRL) Security Configuration Write Enable Position */
#define IDAU_SECCTRL_SCFGWEN_Msk              (_UINT8_(0x1) << IDAU_SECCTRL_SCFGWEN_Pos)           /* (IDAU_SECCTRL) Security Configuration Write Enable Mask */
#define IDAU_SECCTRL_SCFGWEN(value)           (IDAU_SECCTRL_SCFGWEN_Msk & (_UINT8_(value) << IDAU_SECCTRL_SCFGWEN_Pos)) /* Assigment of value for SCFGWEN in the IDAU_SECCTRL register */
#define IDAU_SECCTRL_RXN_Pos                  _UINT8_(2)                                           /* (IDAU_SECCTRL) SRAM eXecute Never Position */
#define IDAU_SECCTRL_RXN_Msk                  (_UINT8_(0x1) << IDAU_SECCTRL_RXN_Pos)               /* (IDAU_SECCTRL) SRAM eXecute Never Mask */
#define IDAU_SECCTRL_RXN(value)               (IDAU_SECCTRL_RXN_Msk & (_UINT8_(value) << IDAU_SECCTRL_RXN_Pos)) /* Assigment of value for RXN in the IDAU_SECCTRL register */
#define IDAU_SECCTRL_Msk                      _UINT8_(0x05)                                        /* (IDAU_SECCTRL) Register Mask  */


/* -------- IDAU_SCFGB : (IDAU Offset: 0x04) (R/W 32) SCFGB -------- */
#define IDAU_SCFGB_RESETVALUE                 _UINT32_(0x00)                                       /*  (IDAU_SCFGB) SCFGB  Reset Value */

#define IDAU_SCFGB_BNSC_Pos                   _UINT32_(11)                                         /* (IDAU_SCFGB) Non-Secure Callable (NSC) Flash (BNSC region) size Position */
#define IDAU_SCFGB_BNSC_Msk                   (_UINT32_(0x1FF) << IDAU_SCFGB_BNSC_Pos)             /* (IDAU_SCFGB) Non-Secure Callable (NSC) Flash (BNSC region) size Mask */
#define IDAU_SCFGB_BNSC(value)                (IDAU_SCFGB_BNSC_Msk & (_UINT32_(value) << IDAU_SCFGB_BNSC_Pos)) /* Assigment of value for BNSC in the IDAU_SCFGB register */
#define IDAU_SCFGB_BOOTPROT_Pos               _UINT32_(20)                                         /* (IDAU_SCFGB) Secure Flash (BOOTPROT/BS region) size Position */
#define IDAU_SCFGB_BOOTPROT_Msk               (_UINT32_(0x7FF) << IDAU_SCFGB_BOOTPROT_Pos)         /* (IDAU_SCFGB) Secure Flash (BOOTPROT/BS region) size Mask */
#define IDAU_SCFGB_BOOTPROT(value)            (IDAU_SCFGB_BOOTPROT_Msk & (_UINT32_(value) << IDAU_SCFGB_BOOTPROT_Pos)) /* Assigment of value for BOOTPROT in the IDAU_SCFGB register */
#define IDAU_SCFGB_Msk                        _UINT32_(0x7FFFF800)                                 /* (IDAU_SCFGB) Register Mask  */


/* -------- IDAU_SCFGA : (IDAU Offset: 0x08) (R/W 32) SCFGA -------- */
#define IDAU_SCFGA_RESETVALUE                 _UINT32_(0x00)                                       /*  (IDAU_SCFGA) SCFGA  Reset Value */

#define IDAU_SCFGA_AS_Pos                     _UINT32_(0)                                          /* (IDAU_SCFGA) Secure Flash (AS region) size Position */
#define IDAU_SCFGA_AS_Msk                     (_UINT32_(0x7FF) << IDAU_SCFGA_AS_Pos)               /* (IDAU_SCFGA) Secure Flash (AS region) size Mask */
#define IDAU_SCFGA_AS(value)                  (IDAU_SCFGA_AS_Msk & (_UINT32_(value) << IDAU_SCFGA_AS_Pos)) /* Assigment of value for AS in the IDAU_SCFGA register */
#define IDAU_SCFGA_ANSC_Pos                   _UINT32_(11)                                         /* (IDAU_SCFGA) Non-Secure Callable (NSC) Flash (ANSC region) size Position */
#define IDAU_SCFGA_ANSC_Msk                   (_UINT32_(0x1FF) << IDAU_SCFGA_ANSC_Pos)             /* (IDAU_SCFGA) Non-Secure Callable (NSC) Flash (ANSC region) size Mask */
#define IDAU_SCFGA_ANSC(value)                (IDAU_SCFGA_ANSC_Msk & (_UINT32_(value) << IDAU_SCFGA_ANSC_Pos)) /* Assigment of value for ANSC in the IDAU_SCFGA register */
#define IDAU_SCFGA_DS_Pos                     _UINT32_(20)                                         /* (IDAU_SCFGA) Secure Data Flash (DS region) size Position */
#define IDAU_SCFGA_DS_Msk                     (_UINT32_(0x7F) << IDAU_SCFGA_DS_Pos)                /* (IDAU_SCFGA) Secure Data Flash (DS region) size Mask */
#define IDAU_SCFGA_DS(value)                  (IDAU_SCFGA_DS_Msk & (_UINT32_(value) << IDAU_SCFGA_DS_Pos)) /* Assigment of value for DS in the IDAU_SCFGA register */
#define IDAU_SCFGA_Msk                        _UINT32_(0x07FFFFFF)                                 /* (IDAU_SCFGA) Register Mask  */


/* -------- IDAU_SCFGR : (IDAU Offset: 0x0C) (R/W 16) SCFGR -------- */
#define IDAU_SCFGR_RESETVALUE                 _UINT16_(0x00)                                       /*  (IDAU_SCFGR) SCFGR  Reset Value */

#define IDAU_SCFGR_RS_Pos                     _UINT16_(0)                                          /* (IDAU_SCFGR) Secure SRAM (RS region) Size Position */
#define IDAU_SCFGR_RS_Msk                     (_UINT16_(0x1FF) << IDAU_SCFGR_RS_Pos)               /* (IDAU_SCFGR) Secure SRAM (RS region) Size Mask */
#define IDAU_SCFGR_RS(value)                  (IDAU_SCFGR_RS_Msk & (_UINT16_(value) << IDAU_SCFGR_RS_Pos)) /* Assigment of value for RS in the IDAU_SCFGR register */
#define IDAU_SCFGR_Msk                        _UINT16_(0x01FF)                                     /* (IDAU_SCFGR) Register Mask  */


/** \brief IDAU register offsets definitions */
#define IDAU_CTRL_REG_OFST             _UINT32_(0x00)      /* (IDAU_CTRL) Control Offset */
#define IDAU_SECCTRL_REG_OFST          _UINT32_(0x01)      /* (IDAU_SECCTRL) SECCTRL Offset */
#define IDAU_SCFGB_REG_OFST            _UINT32_(0x04)      /* (IDAU_SCFGB) SCFGB Offset */
#define IDAU_SCFGA_REG_OFST            _UINT32_(0x08)      /* (IDAU_SCFGA) SCFGA Offset */
#define IDAU_SCFGR_REG_OFST            _UINT32_(0x0C)      /* (IDAU_SCFGR) SCFGR Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief IDAU register API structure */
typedef struct
{  /* Implementation Defined Attribution Unit */
  __IO  uint8_t                        IDAU_CTRL;          /**< Offset: 0x00 (R/W  8) Control */
  __IO  uint8_t                        IDAU_SECCTRL;       /**< Offset: 0x01 (R/W  8) SECCTRL */
  __I   uint8_t                        Reserved1[0x02];
  __IO  uint32_t                       IDAU_SCFGB;         /**< Offset: 0x04 (R/W  32) SCFGB */
  __IO  uint32_t                       IDAU_SCFGA;         /**< Offset: 0x08 (R/W  32) SCFGA */
  __IO  uint16_t                       IDAU_SCFGR;         /**< Offset: 0x0C (R/W  16) SCFGR */
} idau_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMLS60_IDAU_COMPONENT_H_ */
