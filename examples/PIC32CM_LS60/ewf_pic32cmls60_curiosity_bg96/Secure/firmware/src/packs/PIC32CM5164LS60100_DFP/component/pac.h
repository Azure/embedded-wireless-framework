/*
 * Component description for PAC
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
#ifndef _PIC32CMLS60_PAC_COMPONENT_H_
#define _PIC32CMLS60_PAC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PAC                                          */
/* ************************************************************************** */

/* -------- PAC_WRCTRL : (PAC Offset: 0x00) (R/W 32) Write control -------- */
#define PAC_WRCTRL_RESETVALUE                 _UINT32_(0x20021)                                    /*  (PAC_WRCTRL) Write control  Reset Value */

#define PAC_WRCTRL_PERID_Pos                  _UINT32_(0)                                          /* (PAC_WRCTRL) Peripheral identifier Position */
#define PAC_WRCTRL_PERID_Msk                  (_UINT32_(0xFFFF) << PAC_WRCTRL_PERID_Pos)           /* (PAC_WRCTRL) Peripheral identifier Mask */
#define PAC_WRCTRL_PERID(value)               (PAC_WRCTRL_PERID_Msk & (_UINT32_(value) << PAC_WRCTRL_PERID_Pos)) /* Assigment of value for PERID in the PAC_WRCTRL register */
#define PAC_WRCTRL_KEY_Pos                    _UINT32_(16)                                         /* (PAC_WRCTRL) Peripheral access control key Position */
#define PAC_WRCTRL_KEY_Msk                    (_UINT32_(0xFF) << PAC_WRCTRL_KEY_Pos)               /* (PAC_WRCTRL) Peripheral access control key Mask */
#define PAC_WRCTRL_KEY(value)                 (PAC_WRCTRL_KEY_Msk & (_UINT32_(value) << PAC_WRCTRL_KEY_Pos)) /* Assigment of value for KEY in the PAC_WRCTRL register */
#define   PAC_WRCTRL_KEY_OFF_Val              _UINT32_(0x0)                                        /* (PAC_WRCTRL) No action  */
#define   PAC_WRCTRL_KEY_CLR_Val              _UINT32_(0x1)                                        /* (PAC_WRCTRL) Clear protection  */
#define   PAC_WRCTRL_KEY_SET_Val              _UINT32_(0x2)                                        /* (PAC_WRCTRL) Set protection  */
#define   PAC_WRCTRL_KEY_SETLCK_Val           _UINT32_(0x3)                                        /* (PAC_WRCTRL) Set and lock protection  */
#define   PAC_WRCTRL_KEY_SETSEC_Val           _UINT32_(0x4)                                        /* (PAC_WRCTRL) Set IP secure  */
#define   PAC_WRCTRL_KEY_SETNONSEC_Val        _UINT32_(0x5)                                        /* (PAC_WRCTRL) Set IP non-secure  */
#define   PAC_WRCTRL_KEY_SECLOCK_Val          _UINT32_(0x6)                                        /* (PAC_WRCTRL) Lock IP security value  */
#define PAC_WRCTRL_KEY_OFF                    (PAC_WRCTRL_KEY_OFF_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) No action Position  */
#define PAC_WRCTRL_KEY_CLR                    (PAC_WRCTRL_KEY_CLR_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Clear protection Position  */
#define PAC_WRCTRL_KEY_SET                    (PAC_WRCTRL_KEY_SET_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Set protection Position  */
#define PAC_WRCTRL_KEY_SETLCK                 (PAC_WRCTRL_KEY_SETLCK_Val << PAC_WRCTRL_KEY_Pos)    /* (PAC_WRCTRL) Set and lock protection Position  */
#define PAC_WRCTRL_KEY_SETSEC                 (PAC_WRCTRL_KEY_SETSEC_Val << PAC_WRCTRL_KEY_Pos)    /* (PAC_WRCTRL) Set IP secure Position  */
#define PAC_WRCTRL_KEY_SETNONSEC              (PAC_WRCTRL_KEY_SETNONSEC_Val << PAC_WRCTRL_KEY_Pos) /* (PAC_WRCTRL) Set IP non-secure Position  */
#define PAC_WRCTRL_KEY_SECLOCK                (PAC_WRCTRL_KEY_SECLOCK_Val << PAC_WRCTRL_KEY_Pos)   /* (PAC_WRCTRL) Lock IP security value Position  */
#define PAC_WRCTRL_Msk                        _UINT32_(0x00FFFFFF)                                 /* (PAC_WRCTRL) Register Mask  */


/* -------- PAC_EVCTRL : (PAC Offset: 0x04) (R/W 8) Event control -------- */
#define PAC_EVCTRL_RESETVALUE                 _UINT8_(0x00)                                        /*  (PAC_EVCTRL) Event control  Reset Value */

#define PAC_EVCTRL_ERREO_Pos                  _UINT8_(0)                                           /* (PAC_EVCTRL) Peripheral acess error event output Position */
#define PAC_EVCTRL_ERREO_Msk                  (_UINT8_(0x1) << PAC_EVCTRL_ERREO_Pos)               /* (PAC_EVCTRL) Peripheral acess error event output Mask */
#define PAC_EVCTRL_ERREO(value)               (PAC_EVCTRL_ERREO_Msk & (_UINT8_(value) << PAC_EVCTRL_ERREO_Pos)) /* Assigment of value for ERREO in the PAC_EVCTRL register */
#define PAC_EVCTRL_Msk                        _UINT8_(0x01)                                        /* (PAC_EVCTRL) Register Mask  */


/* -------- PAC_INTENCLR : (PAC Offset: 0x08) (R/W 8) Interrupt enable clear -------- */
#define PAC_INTENCLR_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENCLR) Interrupt enable clear  Reset Value */

#define PAC_INTENCLR_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENCLR) Peripheral access error interrupt disable Position */
#define PAC_INTENCLR_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENCLR_ERR_Pos)               /* (PAC_INTENCLR) Peripheral access error interrupt disable Mask */
#define PAC_INTENCLR_ERR(value)               (PAC_INTENCLR_ERR_Msk & (_UINT8_(value) << PAC_INTENCLR_ERR_Pos)) /* Assigment of value for ERR in the PAC_INTENCLR register */
#define PAC_INTENCLR_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENCLR) Register Mask  */


/* -------- PAC_INTENSET : (PAC Offset: 0x09) (R/W 8) Interrupt enable set -------- */
#define PAC_INTENSET_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENSET) Interrupt enable set  Reset Value */

#define PAC_INTENSET_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENSET) Peripheral access error interrupt enable Position */
#define PAC_INTENSET_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENSET_ERR_Pos)               /* (PAC_INTENSET) Peripheral access error interrupt enable Mask */
#define PAC_INTENSET_ERR(value)               (PAC_INTENSET_ERR_Msk & (_UINT8_(value) << PAC_INTENSET_ERR_Pos)) /* Assigment of value for ERR in the PAC_INTENSET register */
#define PAC_INTENSET_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENSET) Register Mask  */


/* -------- PAC_INTFLAGAHB : (PAC Offset: 0x10) (R/W 32) Bridge interrupt flag status -------- */
#define PAC_INTFLAGAHB_RESETVALUE             _UINT32_(0x00)                                       /*  (PAC_INTFLAGAHB) Bridge interrupt flag status  Reset Value */

#define PAC_INTFLAGAHB_FLASH_Pos              _UINT32_(0)                                          /* (PAC_INTFLAGAHB) FLASH Position */
#define PAC_INTFLAGAHB_FLASH_Msk              (_UINT32_(0x1) << PAC_INTFLAGAHB_FLASH_Pos)          /* (PAC_INTFLAGAHB) FLASH Mask */
#define PAC_INTFLAGAHB_FLASH(value)           (PAC_INTFLAGAHB_FLASH_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_FLASH_Pos)) /* Assigment of value for FLASH in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_APBA_Pos               _UINT32_(1)                                          /* (PAC_INTFLAGAHB) APBA Position */
#define PAC_INTFLAGAHB_APBA_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_APBA_Pos)           /* (PAC_INTFLAGAHB) APBA Mask */
#define PAC_INTFLAGAHB_APBA(value)            (PAC_INTFLAGAHB_APBA_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_APBA_Pos)) /* Assigment of value for APBA in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_APBB_Pos               _UINT32_(2)                                          /* (PAC_INTFLAGAHB) APBB Position */
#define PAC_INTFLAGAHB_APBB_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_APBB_Pos)           /* (PAC_INTFLAGAHB) APBB Mask */
#define PAC_INTFLAGAHB_APBB(value)            (PAC_INTFLAGAHB_APBB_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_APBB_Pos)) /* Assigment of value for APBB in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_APBC_Pos               _UINT32_(3)                                          /* (PAC_INTFLAGAHB) APBC Position */
#define PAC_INTFLAGAHB_APBC_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_APBC_Pos)           /* (PAC_INTFLAGAHB) APBC Mask */
#define PAC_INTFLAGAHB_APBC(value)            (PAC_INTFLAGAHB_APBC_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_APBC_Pos)) /* Assigment of value for APBC in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HSRAMCPU_Pos           _UINT32_(4)                                          /* (PAC_INTFLAGAHB) HSRAMCPU Position */
#define PAC_INTFLAGAHB_HSRAMCPU_Msk           (_UINT32_(0x1) << PAC_INTFLAGAHB_HSRAMCPU_Pos)       /* (PAC_INTFLAGAHB) HSRAMCPU Mask */
#define PAC_INTFLAGAHB_HSRAMCPU(value)        (PAC_INTFLAGAHB_HSRAMCPU_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HSRAMCPU_Pos)) /* Assigment of value for HSRAMCPU in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HSRAMDMAC_Pos          _UINT32_(5)                                          /* (PAC_INTFLAGAHB) HSRAMDMAC Position */
#define PAC_INTFLAGAHB_HSRAMDMAC_Msk          (_UINT32_(0x1) << PAC_INTFLAGAHB_HSRAMDMAC_Pos)      /* (PAC_INTFLAGAHB) HSRAMDMAC Mask */
#define PAC_INTFLAGAHB_HSRAMDMAC(value)       (PAC_INTFLAGAHB_HSRAMDMAC_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HSRAMDMAC_Pos)) /* Assigment of value for HSRAMDMAC in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HSRAMDSU_Pos           _UINT32_(6)                                          /* (PAC_INTFLAGAHB) HSRAMDSU Position */
#define PAC_INTFLAGAHB_HSRAMDSU_Msk           (_UINT32_(0x1) << PAC_INTFLAGAHB_HSRAMDSU_Pos)       /* (PAC_INTFLAGAHB) HSRAMDSU Mask */
#define PAC_INTFLAGAHB_HSRAMDSU(value)        (PAC_INTFLAGAHB_HSRAMDSU_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HSRAMDSU_Pos)) /* Assigment of value for HSRAMDSU in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_BROM_Pos               _UINT32_(7)                                          /* (PAC_INTFLAGAHB) BROM Position */
#define PAC_INTFLAGAHB_BROM_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_BROM_Pos)           /* (PAC_INTFLAGAHB) BROM Mask */
#define PAC_INTFLAGAHB_BROM(value)            (PAC_INTFLAGAHB_BROM_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_BROM_Pos)) /* Assigment of value for BROM in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_Msk                    _UINT32_(0x000000FF)                                 /* (PAC_INTFLAGAHB) Register Mask  */


/* -------- PAC_INTFLAGA : (PAC Offset: 0x14) (R/W 32) Peripheral interrupt flag status - Bridge A -------- */
#define PAC_INTFLAGA_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A  Reset Value */

#define PAC_INTFLAGA_PAC_Pos                  _UINT32_(0)                                          /* (PAC_INTFLAGA) PAC Position */
#define PAC_INTFLAGA_PAC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_PAC_Pos)              /* (PAC_INTFLAGA) PAC Mask */
#define PAC_INTFLAGA_PAC(value)               (PAC_INTFLAGA_PAC_Msk & (_UINT32_(value) << PAC_INTFLAGA_PAC_Pos)) /* Assigment of value for PAC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_PM_Pos                   _UINT32_(1)                                          /* (PAC_INTFLAGA) PM Position */
#define PAC_INTFLAGA_PM_Msk                   (_UINT32_(0x1) << PAC_INTFLAGA_PM_Pos)               /* (PAC_INTFLAGA) PM Mask */
#define PAC_INTFLAGA_PM(value)                (PAC_INTFLAGA_PM_Msk & (_UINT32_(value) << PAC_INTFLAGA_PM_Pos)) /* Assigment of value for PM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_MCLK_Pos                 _UINT32_(2)                                          /* (PAC_INTFLAGA) MCLK Position */
#define PAC_INTFLAGA_MCLK_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_MCLK_Pos)             /* (PAC_INTFLAGA) MCLK Mask */
#define PAC_INTFLAGA_MCLK(value)              (PAC_INTFLAGA_MCLK_Msk & (_UINT32_(value) << PAC_INTFLAGA_MCLK_Pos)) /* Assigment of value for MCLK in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_RSTC_Pos                 _UINT32_(3)                                          /* (PAC_INTFLAGA) RSTC Position */
#define PAC_INTFLAGA_RSTC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_RSTC_Pos)             /* (PAC_INTFLAGA) RSTC Mask */
#define PAC_INTFLAGA_RSTC(value)              (PAC_INTFLAGA_RSTC_Msk & (_UINT32_(value) << PAC_INTFLAGA_RSTC_Pos)) /* Assigment of value for RSTC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_OSCCTRL_Pos              _UINT32_(4)                                          /* (PAC_INTFLAGA) OSCCTRL Position */
#define PAC_INTFLAGA_OSCCTRL_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_OSCCTRL_Pos)          /* (PAC_INTFLAGA) OSCCTRL Mask */
#define PAC_INTFLAGA_OSCCTRL(value)           (PAC_INTFLAGA_OSCCTRL_Msk & (_UINT32_(value) << PAC_INTFLAGA_OSCCTRL_Pos)) /* Assigment of value for OSCCTRL in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_OSC32KCTRL_Pos           _UINT32_(5)                                          /* (PAC_INTFLAGA) OSC32KCTRL Position */
#define PAC_INTFLAGA_OSC32KCTRL_Msk           (_UINT32_(0x1) << PAC_INTFLAGA_OSC32KCTRL_Pos)       /* (PAC_INTFLAGA) OSC32KCTRL Mask */
#define PAC_INTFLAGA_OSC32KCTRL(value)        (PAC_INTFLAGA_OSC32KCTRL_Msk & (_UINT32_(value) << PAC_INTFLAGA_OSC32KCTRL_Pos)) /* Assigment of value for OSC32KCTRL in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SUPC_Pos                 _UINT32_(6)                                          /* (PAC_INTFLAGA) SUPC Position */
#define PAC_INTFLAGA_SUPC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_SUPC_Pos)             /* (PAC_INTFLAGA) SUPC Mask */
#define PAC_INTFLAGA_SUPC(value)              (PAC_INTFLAGA_SUPC_Msk & (_UINT32_(value) << PAC_INTFLAGA_SUPC_Pos)) /* Assigment of value for SUPC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_GCLK_Pos                 _UINT32_(7)                                          /* (PAC_INTFLAGA) GCLK Position */
#define PAC_INTFLAGA_GCLK_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_GCLK_Pos)             /* (PAC_INTFLAGA) GCLK Mask */
#define PAC_INTFLAGA_GCLK(value)              (PAC_INTFLAGA_GCLK_Msk & (_UINT32_(value) << PAC_INTFLAGA_GCLK_Pos)) /* Assigment of value for GCLK in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_WDT_Pos                  _UINT32_(8)                                          /* (PAC_INTFLAGA) WDT Position */
#define PAC_INTFLAGA_WDT_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_WDT_Pos)              /* (PAC_INTFLAGA) WDT Mask */
#define PAC_INTFLAGA_WDT(value)               (PAC_INTFLAGA_WDT_Msk & (_UINT32_(value) << PAC_INTFLAGA_WDT_Pos)) /* Assigment of value for WDT in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_RTC_Pos                  _UINT32_(9)                                          /* (PAC_INTFLAGA) RTC Position */
#define PAC_INTFLAGA_RTC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_RTC_Pos)              /* (PAC_INTFLAGA) RTC Mask */
#define PAC_INTFLAGA_RTC(value)               (PAC_INTFLAGA_RTC_Msk & (_UINT32_(value) << PAC_INTFLAGA_RTC_Pos)) /* Assigment of value for RTC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_EIC_Pos                  _UINT32_(10)                                         /* (PAC_INTFLAGA) EIC Position */
#define PAC_INTFLAGA_EIC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_EIC_Pos)              /* (PAC_INTFLAGA) EIC Mask */
#define PAC_INTFLAGA_EIC(value)               (PAC_INTFLAGA_EIC_Msk & (_UINT32_(value) << PAC_INTFLAGA_EIC_Pos)) /* Assigment of value for EIC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_FREQM_Pos                _UINT32_(11)                                         /* (PAC_INTFLAGA) FREQM Position */
#define PAC_INTFLAGA_FREQM_Msk                (_UINT32_(0x1) << PAC_INTFLAGA_FREQM_Pos)            /* (PAC_INTFLAGA) FREQM Mask */
#define PAC_INTFLAGA_FREQM(value)             (PAC_INTFLAGA_FREQM_Msk & (_UINT32_(value) << PAC_INTFLAGA_FREQM_Pos)) /* Assigment of value for FREQM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_PORT_Pos                 _UINT32_(12)                                         /* (PAC_INTFLAGA) PORT Position */
#define PAC_INTFLAGA_PORT_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_PORT_Pos)             /* (PAC_INTFLAGA) PORT Mask */
#define PAC_INTFLAGA_PORT(value)              (PAC_INTFLAGA_PORT_Msk & (_UINT32_(value) << PAC_INTFLAGA_PORT_Pos)) /* Assigment of value for PORT in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_AC_Pos                   _UINT32_(13)                                         /* (PAC_INTFLAGA) AC Position */
#define PAC_INTFLAGA_AC_Msk                   (_UINT32_(0x1) << PAC_INTFLAGA_AC_Pos)               /* (PAC_INTFLAGA) AC Mask */
#define PAC_INTFLAGA_AC(value)                (PAC_INTFLAGA_AC_Msk & (_UINT32_(value) << PAC_INTFLAGA_AC_Pos)) /* Assigment of value for AC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_Msk                      _UINT32_(0x00003FFF)                                 /* (PAC_INTFLAGA) Register Mask  */


/* -------- PAC_INTFLAGB : (PAC Offset: 0x18) (R/W 32) Peripheral interrupt flag status - Bridge B -------- */
#define PAC_INTFLAGB_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B  Reset Value */

#define PAC_INTFLAGB_IDAU_Pos                 _UINT32_(0)                                          /* (PAC_INTFLAGB) IDAU Position */
#define PAC_INTFLAGB_IDAU_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_IDAU_Pos)             /* (PAC_INTFLAGB) IDAU Mask */
#define PAC_INTFLAGB_IDAU(value)              (PAC_INTFLAGB_IDAU_Msk & (_UINT32_(value) << PAC_INTFLAGB_IDAU_Pos)) /* Assigment of value for IDAU in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_DSU_Pos                  _UINT32_(1)                                          /* (PAC_INTFLAGB) DSU Position */
#define PAC_INTFLAGB_DSU_Msk                  (_UINT32_(0x1) << PAC_INTFLAGB_DSU_Pos)              /* (PAC_INTFLAGB) DSU Mask */
#define PAC_INTFLAGB_DSU(value)               (PAC_INTFLAGB_DSU_Msk & (_UINT32_(value) << PAC_INTFLAGB_DSU_Pos)) /* Assigment of value for DSU in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_NVMCTRL_Pos              _UINT32_(2)                                          /* (PAC_INTFLAGB) NVMCTRL Position */
#define PAC_INTFLAGB_NVMCTRL_Msk              (_UINT32_(0x1) << PAC_INTFLAGB_NVMCTRL_Pos)          /* (PAC_INTFLAGB) NVMCTRL Mask */
#define PAC_INTFLAGB_NVMCTRL(value)           (PAC_INTFLAGB_NVMCTRL_Msk & (_UINT32_(value) << PAC_INTFLAGB_NVMCTRL_Pos)) /* Assigment of value for NVMCTRL in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_DMAC_Pos                 _UINT32_(3)                                          /* (PAC_INTFLAGB) DMAC Position */
#define PAC_INTFLAGB_DMAC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_DMAC_Pos)             /* (PAC_INTFLAGB) DMAC Mask */
#define PAC_INTFLAGB_DMAC(value)              (PAC_INTFLAGB_DMAC_Msk & (_UINT32_(value) << PAC_INTFLAGB_DMAC_Pos)) /* Assigment of value for DMAC in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_HMATRIXHS_Pos            _UINT32_(4)                                          /* (PAC_INTFLAGB) HMATRIXHS Position */
#define PAC_INTFLAGB_HMATRIXHS_Msk            (_UINT32_(0x1) << PAC_INTFLAGB_HMATRIXHS_Pos)        /* (PAC_INTFLAGB) HMATRIXHS Mask */
#define PAC_INTFLAGB_HMATRIXHS(value)         (PAC_INTFLAGB_HMATRIXHS_Msk & (_UINT32_(value) << PAC_INTFLAGB_HMATRIXHS_Pos)) /* Assigment of value for HMATRIXHS in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_USB_Pos                  _UINT32_(5)                                          /* (PAC_INTFLAGB) USB Position */
#define PAC_INTFLAGB_USB_Msk                  (_UINT32_(0x1) << PAC_INTFLAGB_USB_Pos)              /* (PAC_INTFLAGB) USB Mask */
#define PAC_INTFLAGB_USB(value)               (PAC_INTFLAGB_USB_Msk & (_UINT32_(value) << PAC_INTFLAGB_USB_Pos)) /* Assigment of value for USB in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_Msk                      _UINT32_(0x0000003F)                                 /* (PAC_INTFLAGB) Register Mask  */


/* -------- PAC_INTFLAGC : (PAC Offset: 0x1C) (R/W 32) Peripheral interrupt flag status - Bridge C -------- */
#define PAC_INTFLAGC_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C  Reset Value */

#define PAC_INTFLAGC_EVSYS_Pos                _UINT32_(0)                                          /* (PAC_INTFLAGC) EVSYS Position */
#define PAC_INTFLAGC_EVSYS_Msk                (_UINT32_(0x1) << PAC_INTFLAGC_EVSYS_Pos)            /* (PAC_INTFLAGC) EVSYS Mask */
#define PAC_INTFLAGC_EVSYS(value)             (PAC_INTFLAGC_EVSYS_Msk & (_UINT32_(value) << PAC_INTFLAGC_EVSYS_Pos)) /* Assigment of value for EVSYS in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM0_Pos              _UINT32_(1)                                          /* (PAC_INTFLAGC) SERCOM0 Position */
#define PAC_INTFLAGC_SERCOM0_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM0_Pos)          /* (PAC_INTFLAGC) SERCOM0 Mask */
#define PAC_INTFLAGC_SERCOM0(value)           (PAC_INTFLAGC_SERCOM0_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM0_Pos)) /* Assigment of value for SERCOM0 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM1_Pos              _UINT32_(2)                                          /* (PAC_INTFLAGC) SERCOM1 Position */
#define PAC_INTFLAGC_SERCOM1_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM1_Pos)          /* (PAC_INTFLAGC) SERCOM1 Mask */
#define PAC_INTFLAGC_SERCOM1(value)           (PAC_INTFLAGC_SERCOM1_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM1_Pos)) /* Assigment of value for SERCOM1 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM2_Pos              _UINT32_(3)                                          /* (PAC_INTFLAGC) SERCOM2 Position */
#define PAC_INTFLAGC_SERCOM2_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM2_Pos)          /* (PAC_INTFLAGC) SERCOM2 Mask */
#define PAC_INTFLAGC_SERCOM2(value)           (PAC_INTFLAGC_SERCOM2_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM2_Pos)) /* Assigment of value for SERCOM2 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM3_Pos              _UINT32_(4)                                          /* (PAC_INTFLAGC) SERCOM3 Position */
#define PAC_INTFLAGC_SERCOM3_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM3_Pos)          /* (PAC_INTFLAGC) SERCOM3 Mask */
#define PAC_INTFLAGC_SERCOM3(value)           (PAC_INTFLAGC_SERCOM3_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM3_Pos)) /* Assigment of value for SERCOM3 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM4_Pos              _UINT32_(5)                                          /* (PAC_INTFLAGC) SERCOM4 Position */
#define PAC_INTFLAGC_SERCOM4_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM4_Pos)          /* (PAC_INTFLAGC) SERCOM4 Mask */
#define PAC_INTFLAGC_SERCOM4(value)           (PAC_INTFLAGC_SERCOM4_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM4_Pos)) /* Assigment of value for SERCOM4 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM5_Pos              _UINT32_(6)                                          /* (PAC_INTFLAGC) SERCOM5 Position */
#define PAC_INTFLAGC_SERCOM5_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM5_Pos)          /* (PAC_INTFLAGC) SERCOM5 Mask */
#define PAC_INTFLAGC_SERCOM5(value)           (PAC_INTFLAGC_SERCOM5_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM5_Pos)) /* Assigment of value for SERCOM5 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TC0_Pos                  _UINT32_(7)                                          /* (PAC_INTFLAGC) TC0 Position */
#define PAC_INTFLAGC_TC0_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_TC0_Pos)              /* (PAC_INTFLAGC) TC0 Mask */
#define PAC_INTFLAGC_TC0(value)               (PAC_INTFLAGC_TC0_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC0_Pos)) /* Assigment of value for TC0 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TC1_Pos                  _UINT32_(8)                                          /* (PAC_INTFLAGC) TC1 Position */
#define PAC_INTFLAGC_TC1_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_TC1_Pos)              /* (PAC_INTFLAGC) TC1 Mask */
#define PAC_INTFLAGC_TC1(value)               (PAC_INTFLAGC_TC1_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC1_Pos)) /* Assigment of value for TC1 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TC2_Pos                  _UINT32_(9)                                          /* (PAC_INTFLAGC) TC2 Position */
#define PAC_INTFLAGC_TC2_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_TC2_Pos)              /* (PAC_INTFLAGC) TC2 Mask */
#define PAC_INTFLAGC_TC2(value)               (PAC_INTFLAGC_TC2_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC2_Pos)) /* Assigment of value for TC2 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TCC0_Pos                 _UINT32_(10)                                         /* (PAC_INTFLAGC) TCC0 Position */
#define PAC_INTFLAGC_TCC0_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TCC0_Pos)             /* (PAC_INTFLAGC) TCC0 Mask */
#define PAC_INTFLAGC_TCC0(value)              (PAC_INTFLAGC_TCC0_Msk & (_UINT32_(value) << PAC_INTFLAGC_TCC0_Pos)) /* Assigment of value for TCC0 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TCC1_Pos                 _UINT32_(11)                                         /* (PAC_INTFLAGC) TCC1 Position */
#define PAC_INTFLAGC_TCC1_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TCC1_Pos)             /* (PAC_INTFLAGC) TCC1 Mask */
#define PAC_INTFLAGC_TCC1(value)              (PAC_INTFLAGC_TCC1_Msk & (_UINT32_(value) << PAC_INTFLAGC_TCC1_Pos)) /* Assigment of value for TCC1 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TCC2_Pos                 _UINT32_(12)                                         /* (PAC_INTFLAGC) TCC2 Position */
#define PAC_INTFLAGC_TCC2_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TCC2_Pos)             /* (PAC_INTFLAGC) TCC2 Mask */
#define PAC_INTFLAGC_TCC2(value)              (PAC_INTFLAGC_TCC2_Msk & (_UINT32_(value) << PAC_INTFLAGC_TCC2_Pos)) /* Assigment of value for TCC2 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TCC3_Pos                 _UINT32_(13)                                         /* (PAC_INTFLAGC) TCC3 Position */
#define PAC_INTFLAGC_TCC3_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TCC3_Pos)             /* (PAC_INTFLAGC) TCC3 Mask */
#define PAC_INTFLAGC_TCC3(value)              (PAC_INTFLAGC_TCC3_Msk & (_UINT32_(value) << PAC_INTFLAGC_TCC3_Pos)) /* Assigment of value for TCC3 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_ADC_Pos                  _UINT32_(14)                                         /* (PAC_INTFLAGC) ADC Position */
#define PAC_INTFLAGC_ADC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_ADC_Pos)              /* (PAC_INTFLAGC) ADC Mask */
#define PAC_INTFLAGC_ADC(value)               (PAC_INTFLAGC_ADC_Msk & (_UINT32_(value) << PAC_INTFLAGC_ADC_Pos)) /* Assigment of value for ADC in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_DAC_Pos                  _UINT32_(15)                                         /* (PAC_INTFLAGC) DAC Position */
#define PAC_INTFLAGC_DAC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_DAC_Pos)              /* (PAC_INTFLAGC) DAC Mask */
#define PAC_INTFLAGC_DAC(value)               (PAC_INTFLAGC_DAC_Msk & (_UINT32_(value) << PAC_INTFLAGC_DAC_Pos)) /* Assigment of value for DAC in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_PTC_Pos                  _UINT32_(16)                                         /* (PAC_INTFLAGC) PTC Position */
#define PAC_INTFLAGC_PTC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_PTC_Pos)              /* (PAC_INTFLAGC) PTC Mask */
#define PAC_INTFLAGC_PTC(value)               (PAC_INTFLAGC_PTC_Msk & (_UINT32_(value) << PAC_INTFLAGC_PTC_Pos)) /* Assigment of value for PTC in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TRNG_Pos                 _UINT32_(17)                                         /* (PAC_INTFLAGC) TRNG Position */
#define PAC_INTFLAGC_TRNG_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TRNG_Pos)             /* (PAC_INTFLAGC) TRNG Mask */
#define PAC_INTFLAGC_TRNG(value)              (PAC_INTFLAGC_TRNG_Msk & (_UINT32_(value) << PAC_INTFLAGC_TRNG_Pos)) /* Assigment of value for TRNG in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_CCL_Pos                  _UINT32_(18)                                         /* (PAC_INTFLAGC) CCL Position */
#define PAC_INTFLAGC_CCL_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_CCL_Pos)              /* (PAC_INTFLAGC) CCL Mask */
#define PAC_INTFLAGC_CCL(value)               (PAC_INTFLAGC_CCL_Msk & (_UINT32_(value) << PAC_INTFLAGC_CCL_Pos)) /* Assigment of value for CCL in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_I2S_Pos                  _UINT32_(19)                                         /* (PAC_INTFLAGC) I2S Position */
#define PAC_INTFLAGC_I2S_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_I2S_Pos)              /* (PAC_INTFLAGC) I2S Mask */
#define PAC_INTFLAGC_I2S(value)               (PAC_INTFLAGC_I2S_Msk & (_UINT32_(value) << PAC_INTFLAGC_I2S_Pos)) /* Assigment of value for I2S in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_OPAMP_Pos                _UINT32_(20)                                         /* (PAC_INTFLAGC) OPAMP Position */
#define PAC_INTFLAGC_OPAMP_Msk                (_UINT32_(0x1) << PAC_INTFLAGC_OPAMP_Pos)            /* (PAC_INTFLAGC) OPAMP Mask */
#define PAC_INTFLAGC_OPAMP(value)             (PAC_INTFLAGC_OPAMP_Msk & (_UINT32_(value) << PAC_INTFLAGC_OPAMP_Pos)) /* Assigment of value for OPAMP in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TRAM_Pos                 _UINT32_(21)                                         /* (PAC_INTFLAGC) TRAM Position */
#define PAC_INTFLAGC_TRAM_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TRAM_Pos)             /* (PAC_INTFLAGC) TRAM Mask */
#define PAC_INTFLAGC_TRAM(value)              (PAC_INTFLAGC_TRAM_Msk & (_UINT32_(value) << PAC_INTFLAGC_TRAM_Pos)) /* Assigment of value for TRAM in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_Msk                      _UINT32_(0x003FFFFF)                                 /* (PAC_INTFLAGC) Register Mask  */

#define PAC_INTFLAGC_SERCOM_Pos               _UINT32_(1)                                          /* (PAC_INTFLAGC Position) SERCOMx */
#define PAC_INTFLAGC_SERCOM_Msk               (_UINT32_(0x3F) << PAC_INTFLAGC_SERCOM_Pos)          /* (PAC_INTFLAGC Mask) SERCOM */
#define PAC_INTFLAGC_SERCOM(value)            (PAC_INTFLAGC_SERCOM_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM_Pos)) 
#define PAC_INTFLAGC_TC_Pos                   _UINT32_(7)                                          /* (PAC_INTFLAGC Position) TCx */
#define PAC_INTFLAGC_TC_Msk                   (_UINT32_(0x7) << PAC_INTFLAGC_TC_Pos)               /* (PAC_INTFLAGC Mask) TC */
#define PAC_INTFLAGC_TC(value)                (PAC_INTFLAGC_TC_Msk & (_UINT32_(value) << PAC_INTFLAGC_TC_Pos)) 
#define PAC_INTFLAGC_TCC_Pos                  _UINT32_(10)                                         /* (PAC_INTFLAGC Position) TCCx */
#define PAC_INTFLAGC_TCC_Msk                  (_UINT32_(0xF) << PAC_INTFLAGC_TCC_Pos)              /* (PAC_INTFLAGC Mask) TCC */
#define PAC_INTFLAGC_TCC(value)               (PAC_INTFLAGC_TCC_Msk & (_UINT32_(value) << PAC_INTFLAGC_TCC_Pos)) 

/* -------- PAC_STATUSA : (PAC Offset: 0x34) ( R/ 32) Peripheral write protection status - Bridge A -------- */
#define PAC_STATUSA_RESETVALUE                _UINT32_(0xC000)                                     /*  (PAC_STATUSA) Peripheral write protection status - Bridge A  Reset Value */

#define PAC_STATUSA_PAC_Pos                   _UINT32_(0)                                          /* (PAC_STATUSA) PAC APB Protect Enable Position */
#define PAC_STATUSA_PAC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_PAC_Pos)               /* (PAC_STATUSA) PAC APB Protect Enable Mask */
#define PAC_STATUSA_PAC(value)                (PAC_STATUSA_PAC_Msk & (_UINT32_(value) << PAC_STATUSA_PAC_Pos)) /* Assigment of value for PAC in the PAC_STATUSA register */
#define PAC_STATUSA_PM_Pos                    _UINT32_(1)                                          /* (PAC_STATUSA) PM APB Protect Enable Position */
#define PAC_STATUSA_PM_Msk                    (_UINT32_(0x1) << PAC_STATUSA_PM_Pos)                /* (PAC_STATUSA) PM APB Protect Enable Mask */
#define PAC_STATUSA_PM(value)                 (PAC_STATUSA_PM_Msk & (_UINT32_(value) << PAC_STATUSA_PM_Pos)) /* Assigment of value for PM in the PAC_STATUSA register */
#define PAC_STATUSA_MCLK_Pos                  _UINT32_(2)                                          /* (PAC_STATUSA) MCLK APB Protect Enable Position */
#define PAC_STATUSA_MCLK_Msk                  (_UINT32_(0x1) << PAC_STATUSA_MCLK_Pos)              /* (PAC_STATUSA) MCLK APB Protect Enable Mask */
#define PAC_STATUSA_MCLK(value)               (PAC_STATUSA_MCLK_Msk & (_UINT32_(value) << PAC_STATUSA_MCLK_Pos)) /* Assigment of value for MCLK in the PAC_STATUSA register */
#define PAC_STATUSA_RSTC_Pos                  _UINT32_(3)                                          /* (PAC_STATUSA) RSTC APB Protect Enable Position */
#define PAC_STATUSA_RSTC_Msk                  (_UINT32_(0x1) << PAC_STATUSA_RSTC_Pos)              /* (PAC_STATUSA) RSTC APB Protect Enable Mask */
#define PAC_STATUSA_RSTC(value)               (PAC_STATUSA_RSTC_Msk & (_UINT32_(value) << PAC_STATUSA_RSTC_Pos)) /* Assigment of value for RSTC in the PAC_STATUSA register */
#define PAC_STATUSA_OSCCTRL_Pos               _UINT32_(4)                                          /* (PAC_STATUSA) OSCCTRL APB Protect Enable Position */
#define PAC_STATUSA_OSCCTRL_Msk               (_UINT32_(0x1) << PAC_STATUSA_OSCCTRL_Pos)           /* (PAC_STATUSA) OSCCTRL APB Protect Enable Mask */
#define PAC_STATUSA_OSCCTRL(value)            (PAC_STATUSA_OSCCTRL_Msk & (_UINT32_(value) << PAC_STATUSA_OSCCTRL_Pos)) /* Assigment of value for OSCCTRL in the PAC_STATUSA register */
#define PAC_STATUSA_OSC32KCTRL_Pos            _UINT32_(5)                                          /* (PAC_STATUSA) OSC32KCTRL APB Protect Enable Position */
#define PAC_STATUSA_OSC32KCTRL_Msk            (_UINT32_(0x1) << PAC_STATUSA_OSC32KCTRL_Pos)        /* (PAC_STATUSA) OSC32KCTRL APB Protect Enable Mask */
#define PAC_STATUSA_OSC32KCTRL(value)         (PAC_STATUSA_OSC32KCTRL_Msk & (_UINT32_(value) << PAC_STATUSA_OSC32KCTRL_Pos)) /* Assigment of value for OSC32KCTRL in the PAC_STATUSA register */
#define PAC_STATUSA_SUPC_Pos                  _UINT32_(6)                                          /* (PAC_STATUSA) SUPC APB Protect Enable Position */
#define PAC_STATUSA_SUPC_Msk                  (_UINT32_(0x1) << PAC_STATUSA_SUPC_Pos)              /* (PAC_STATUSA) SUPC APB Protect Enable Mask */
#define PAC_STATUSA_SUPC(value)               (PAC_STATUSA_SUPC_Msk & (_UINT32_(value) << PAC_STATUSA_SUPC_Pos)) /* Assigment of value for SUPC in the PAC_STATUSA register */
#define PAC_STATUSA_GCLK_Pos                  _UINT32_(7)                                          /* (PAC_STATUSA) GCLK APB Protect Enable Position */
#define PAC_STATUSA_GCLK_Msk                  (_UINT32_(0x1) << PAC_STATUSA_GCLK_Pos)              /* (PAC_STATUSA) GCLK APB Protect Enable Mask */
#define PAC_STATUSA_GCLK(value)               (PAC_STATUSA_GCLK_Msk & (_UINT32_(value) << PAC_STATUSA_GCLK_Pos)) /* Assigment of value for GCLK in the PAC_STATUSA register */
#define PAC_STATUSA_WDT_Pos                   _UINT32_(8)                                          /* (PAC_STATUSA) WDT APB Protect Enable Position */
#define PAC_STATUSA_WDT_Msk                   (_UINT32_(0x1) << PAC_STATUSA_WDT_Pos)               /* (PAC_STATUSA) WDT APB Protect Enable Mask */
#define PAC_STATUSA_WDT(value)                (PAC_STATUSA_WDT_Msk & (_UINT32_(value) << PAC_STATUSA_WDT_Pos)) /* Assigment of value for WDT in the PAC_STATUSA register */
#define PAC_STATUSA_RTC_Pos                   _UINT32_(9)                                          /* (PAC_STATUSA) RTC APB Protect Enable Position */
#define PAC_STATUSA_RTC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_RTC_Pos)               /* (PAC_STATUSA) RTC APB Protect Enable Mask */
#define PAC_STATUSA_RTC(value)                (PAC_STATUSA_RTC_Msk & (_UINT32_(value) << PAC_STATUSA_RTC_Pos)) /* Assigment of value for RTC in the PAC_STATUSA register */
#define PAC_STATUSA_EIC_Pos                   _UINT32_(10)                                         /* (PAC_STATUSA) EIC APB Protect Enable Position */
#define PAC_STATUSA_EIC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_EIC_Pos)               /* (PAC_STATUSA) EIC APB Protect Enable Mask */
#define PAC_STATUSA_EIC(value)                (PAC_STATUSA_EIC_Msk & (_UINT32_(value) << PAC_STATUSA_EIC_Pos)) /* Assigment of value for EIC in the PAC_STATUSA register */
#define PAC_STATUSA_FREQM_Pos                 _UINT32_(11)                                         /* (PAC_STATUSA) FREQM APB Protect Enable Position */
#define PAC_STATUSA_FREQM_Msk                 (_UINT32_(0x1) << PAC_STATUSA_FREQM_Pos)             /* (PAC_STATUSA) FREQM APB Protect Enable Mask */
#define PAC_STATUSA_FREQM(value)              (PAC_STATUSA_FREQM_Msk & (_UINT32_(value) << PAC_STATUSA_FREQM_Pos)) /* Assigment of value for FREQM in the PAC_STATUSA register */
#define PAC_STATUSA_PORT_Pos                  _UINT32_(12)                                         /* (PAC_STATUSA) PORT APB Protect Enable Position */
#define PAC_STATUSA_PORT_Msk                  (_UINT32_(0x1) << PAC_STATUSA_PORT_Pos)              /* (PAC_STATUSA) PORT APB Protect Enable Mask */
#define PAC_STATUSA_PORT(value)               (PAC_STATUSA_PORT_Msk & (_UINT32_(value) << PAC_STATUSA_PORT_Pos)) /* Assigment of value for PORT in the PAC_STATUSA register */
#define PAC_STATUSA_AC_Pos                    _UINT32_(13)                                         /* (PAC_STATUSA) AC APB Protect Enable Position */
#define PAC_STATUSA_AC_Msk                    (_UINT32_(0x1) << PAC_STATUSA_AC_Pos)                /* (PAC_STATUSA) AC APB Protect Enable Mask */
#define PAC_STATUSA_AC(value)                 (PAC_STATUSA_AC_Msk & (_UINT32_(value) << PAC_STATUSA_AC_Pos)) /* Assigment of value for AC in the PAC_STATUSA register */
#define PAC_STATUSA_Msk                       _UINT32_(0x00003FFF)                                 /* (PAC_STATUSA) Register Mask  */


/* -------- PAC_STATUSB : (PAC Offset: 0x38) ( R/ 32) Peripheral write protection status - Bridge B -------- */
#define PAC_STATUSB_RESETVALUE                _UINT32_(0x02)                                       /*  (PAC_STATUSB) Peripheral write protection status - Bridge B  Reset Value */

#define PAC_STATUSB_IDAU_Pos                  _UINT32_(0)                                          /* (PAC_STATUSB) IDAU APB Protect Enable Position */
#define PAC_STATUSB_IDAU_Msk                  (_UINT32_(0x1) << PAC_STATUSB_IDAU_Pos)              /* (PAC_STATUSB) IDAU APB Protect Enable Mask */
#define PAC_STATUSB_IDAU(value)               (PAC_STATUSB_IDAU_Msk & (_UINT32_(value) << PAC_STATUSB_IDAU_Pos)) /* Assigment of value for IDAU in the PAC_STATUSB register */
#define PAC_STATUSB_DSU_Pos                   _UINT32_(1)                                          /* (PAC_STATUSB) DSU APB Protect Enable Position */
#define PAC_STATUSB_DSU_Msk                   (_UINT32_(0x1) << PAC_STATUSB_DSU_Pos)               /* (PAC_STATUSB) DSU APB Protect Enable Mask */
#define PAC_STATUSB_DSU(value)                (PAC_STATUSB_DSU_Msk & (_UINT32_(value) << PAC_STATUSB_DSU_Pos)) /* Assigment of value for DSU in the PAC_STATUSB register */
#define PAC_STATUSB_NVMCTRL_Pos               _UINT32_(2)                                          /* (PAC_STATUSB) NVMCTRL APB Protect Enable Position */
#define PAC_STATUSB_NVMCTRL_Msk               (_UINT32_(0x1) << PAC_STATUSB_NVMCTRL_Pos)           /* (PAC_STATUSB) NVMCTRL APB Protect Enable Mask */
#define PAC_STATUSB_NVMCTRL(value)            (PAC_STATUSB_NVMCTRL_Msk & (_UINT32_(value) << PAC_STATUSB_NVMCTRL_Pos)) /* Assigment of value for NVMCTRL in the PAC_STATUSB register */
#define PAC_STATUSB_DMAC_Pos                  _UINT32_(3)                                          /* (PAC_STATUSB) DMAC APB Protect Enable Position */
#define PAC_STATUSB_DMAC_Msk                  (_UINT32_(0x1) << PAC_STATUSB_DMAC_Pos)              /* (PAC_STATUSB) DMAC APB Protect Enable Mask */
#define PAC_STATUSB_DMAC(value)               (PAC_STATUSB_DMAC_Msk & (_UINT32_(value) << PAC_STATUSB_DMAC_Pos)) /* Assigment of value for DMAC in the PAC_STATUSB register */
#define PAC_STATUSB_HMATRIXHS_Pos             _UINT32_(4)                                          /* (PAC_STATUSB) HMATRIXHS APB Protect Enable Position */
#define PAC_STATUSB_HMATRIXHS_Msk             (_UINT32_(0x1) << PAC_STATUSB_HMATRIXHS_Pos)         /* (PAC_STATUSB) HMATRIXHS APB Protect Enable Mask */
#define PAC_STATUSB_HMATRIXHS(value)          (PAC_STATUSB_HMATRIXHS_Msk & (_UINT32_(value) << PAC_STATUSB_HMATRIXHS_Pos)) /* Assigment of value for HMATRIXHS in the PAC_STATUSB register */
#define PAC_STATUSB_USB_Pos                   _UINT32_(5)                                          /* (PAC_STATUSB) USB APB Protect Enable Position */
#define PAC_STATUSB_USB_Msk                   (_UINT32_(0x1) << PAC_STATUSB_USB_Pos)               /* (PAC_STATUSB) USB APB Protect Enable Mask */
#define PAC_STATUSB_USB(value)                (PAC_STATUSB_USB_Msk & (_UINT32_(value) << PAC_STATUSB_USB_Pos)) /* Assigment of value for USB in the PAC_STATUSB register */
#define PAC_STATUSB_Msk                       _UINT32_(0x0000003F)                                 /* (PAC_STATUSB) Register Mask  */


/* -------- PAC_STATUSC : (PAC Offset: 0x3C) ( R/ 32) Peripheral write protection status - Bridge C -------- */
#define PAC_STATUSC_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_STATUSC) Peripheral write protection status - Bridge C  Reset Value */

#define PAC_STATUSC_EVSYS_Pos                 _UINT32_(0)                                          /* (PAC_STATUSC) EVSYS APB Protect Enable Position */
#define PAC_STATUSC_EVSYS_Msk                 (_UINT32_(0x1) << PAC_STATUSC_EVSYS_Pos)             /* (PAC_STATUSC) EVSYS APB Protect Enable Mask */
#define PAC_STATUSC_EVSYS(value)              (PAC_STATUSC_EVSYS_Msk & (_UINT32_(value) << PAC_STATUSC_EVSYS_Pos)) /* Assigment of value for EVSYS in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM0_Pos               _UINT32_(1)                                          /* (PAC_STATUSC) SERCOM0 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM0_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM0_Pos)           /* (PAC_STATUSC) SERCOM0 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM0(value)            (PAC_STATUSC_SERCOM0_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM0_Pos)) /* Assigment of value for SERCOM0 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM1_Pos               _UINT32_(2)                                          /* (PAC_STATUSC) SERCOM1 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM1_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM1_Pos)           /* (PAC_STATUSC) SERCOM1 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM1(value)            (PAC_STATUSC_SERCOM1_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM1_Pos)) /* Assigment of value for SERCOM1 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM2_Pos               _UINT32_(3)                                          /* (PAC_STATUSC) SERCOM2 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM2_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM2_Pos)           /* (PAC_STATUSC) SERCOM2 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM2(value)            (PAC_STATUSC_SERCOM2_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM2_Pos)) /* Assigment of value for SERCOM2 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM3_Pos               _UINT32_(4)                                          /* (PAC_STATUSC) SERCOM3 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM3_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM3_Pos)           /* (PAC_STATUSC) SERCOM3 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM3(value)            (PAC_STATUSC_SERCOM3_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM3_Pos)) /* Assigment of value for SERCOM3 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM4_Pos               _UINT32_(5)                                          /* (PAC_STATUSC) SERCOM4 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM4_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM4_Pos)           /* (PAC_STATUSC) SERCOM4 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM4(value)            (PAC_STATUSC_SERCOM4_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM4_Pos)) /* Assigment of value for SERCOM4 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM5_Pos               _UINT32_(6)                                          /* (PAC_STATUSC) SERCOM5 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM5_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM5_Pos)           /* (PAC_STATUSC) SERCOM5 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM5(value)            (PAC_STATUSC_SERCOM5_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM5_Pos)) /* Assigment of value for SERCOM5 in the PAC_STATUSC register */
#define PAC_STATUSC_TC0_Pos                   _UINT32_(7)                                          /* (PAC_STATUSC) TC0 APB Protect Enable Position */
#define PAC_STATUSC_TC0_Msk                   (_UINT32_(0x1) << PAC_STATUSC_TC0_Pos)               /* (PAC_STATUSC) TC0 APB Protect Enable Mask */
#define PAC_STATUSC_TC0(value)                (PAC_STATUSC_TC0_Msk & (_UINT32_(value) << PAC_STATUSC_TC0_Pos)) /* Assigment of value for TC0 in the PAC_STATUSC register */
#define PAC_STATUSC_TC1_Pos                   _UINT32_(8)                                          /* (PAC_STATUSC) TC1 APB Protect Enable Position */
#define PAC_STATUSC_TC1_Msk                   (_UINT32_(0x1) << PAC_STATUSC_TC1_Pos)               /* (PAC_STATUSC) TC1 APB Protect Enable Mask */
#define PAC_STATUSC_TC1(value)                (PAC_STATUSC_TC1_Msk & (_UINT32_(value) << PAC_STATUSC_TC1_Pos)) /* Assigment of value for TC1 in the PAC_STATUSC register */
#define PAC_STATUSC_TC2_Pos                   _UINT32_(9)                                          /* (PAC_STATUSC) TC2 APB Protect Enable Position */
#define PAC_STATUSC_TC2_Msk                   (_UINT32_(0x1) << PAC_STATUSC_TC2_Pos)               /* (PAC_STATUSC) TC2 APB Protect Enable Mask */
#define PAC_STATUSC_TC2(value)                (PAC_STATUSC_TC2_Msk & (_UINT32_(value) << PAC_STATUSC_TC2_Pos)) /* Assigment of value for TC2 in the PAC_STATUSC register */
#define PAC_STATUSC_TCC0_Pos                  _UINT32_(10)                                         /* (PAC_STATUSC) TCC0 APB Protect Enable Position */
#define PAC_STATUSC_TCC0_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TCC0_Pos)              /* (PAC_STATUSC) TCC0 APB Protect Enable Mask */
#define PAC_STATUSC_TCC0(value)               (PAC_STATUSC_TCC0_Msk & (_UINT32_(value) << PAC_STATUSC_TCC0_Pos)) /* Assigment of value for TCC0 in the PAC_STATUSC register */
#define PAC_STATUSC_TCC1_Pos                  _UINT32_(11)                                         /* (PAC_STATUSC) TCC1 APB Protect Enable Position */
#define PAC_STATUSC_TCC1_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TCC1_Pos)              /* (PAC_STATUSC) TCC1 APB Protect Enable Mask */
#define PAC_STATUSC_TCC1(value)               (PAC_STATUSC_TCC1_Msk & (_UINT32_(value) << PAC_STATUSC_TCC1_Pos)) /* Assigment of value for TCC1 in the PAC_STATUSC register */
#define PAC_STATUSC_TCC2_Pos                  _UINT32_(12)                                         /* (PAC_STATUSC) TCC2 APB Protect Enable Position */
#define PAC_STATUSC_TCC2_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TCC2_Pos)              /* (PAC_STATUSC) TCC2 APB Protect Enable Mask */
#define PAC_STATUSC_TCC2(value)               (PAC_STATUSC_TCC2_Msk & (_UINT32_(value) << PAC_STATUSC_TCC2_Pos)) /* Assigment of value for TCC2 in the PAC_STATUSC register */
#define PAC_STATUSC_TCC3_Pos                  _UINT32_(13)                                         /* (PAC_STATUSC) TCC3 APB Protect Enable Position */
#define PAC_STATUSC_TCC3_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TCC3_Pos)              /* (PAC_STATUSC) TCC3 APB Protect Enable Mask */
#define PAC_STATUSC_TCC3(value)               (PAC_STATUSC_TCC3_Msk & (_UINT32_(value) << PAC_STATUSC_TCC3_Pos)) /* Assigment of value for TCC3 in the PAC_STATUSC register */
#define PAC_STATUSC_ADC_Pos                   _UINT32_(14)                                         /* (PAC_STATUSC) ADC APB Protect Enable Position */
#define PAC_STATUSC_ADC_Msk                   (_UINT32_(0x1) << PAC_STATUSC_ADC_Pos)               /* (PAC_STATUSC) ADC APB Protect Enable Mask */
#define PAC_STATUSC_ADC(value)                (PAC_STATUSC_ADC_Msk & (_UINT32_(value) << PAC_STATUSC_ADC_Pos)) /* Assigment of value for ADC in the PAC_STATUSC register */
#define PAC_STATUSC_DAC_Pos                   _UINT32_(15)                                         /* (PAC_STATUSC) DAC APB Protect Enable Position */
#define PAC_STATUSC_DAC_Msk                   (_UINT32_(0x1) << PAC_STATUSC_DAC_Pos)               /* (PAC_STATUSC) DAC APB Protect Enable Mask */
#define PAC_STATUSC_DAC(value)                (PAC_STATUSC_DAC_Msk & (_UINT32_(value) << PAC_STATUSC_DAC_Pos)) /* Assigment of value for DAC in the PAC_STATUSC register */
#define PAC_STATUSC_PTC_Pos                   _UINT32_(16)                                         /* (PAC_STATUSC) PTC APB Protect Enable Position */
#define PAC_STATUSC_PTC_Msk                   (_UINT32_(0x1) << PAC_STATUSC_PTC_Pos)               /* (PAC_STATUSC) PTC APB Protect Enable Mask */
#define PAC_STATUSC_PTC(value)                (PAC_STATUSC_PTC_Msk & (_UINT32_(value) << PAC_STATUSC_PTC_Pos)) /* Assigment of value for PTC in the PAC_STATUSC register */
#define PAC_STATUSC_TRNG_Pos                  _UINT32_(17)                                         /* (PAC_STATUSC) TRNG APB Protect Enable Position */
#define PAC_STATUSC_TRNG_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TRNG_Pos)              /* (PAC_STATUSC) TRNG APB Protect Enable Mask */
#define PAC_STATUSC_TRNG(value)               (PAC_STATUSC_TRNG_Msk & (_UINT32_(value) << PAC_STATUSC_TRNG_Pos)) /* Assigment of value for TRNG in the PAC_STATUSC register */
#define PAC_STATUSC_CCL_Pos                   _UINT32_(18)                                         /* (PAC_STATUSC) CCL APB Protect Enable Position */
#define PAC_STATUSC_CCL_Msk                   (_UINT32_(0x1) << PAC_STATUSC_CCL_Pos)               /* (PAC_STATUSC) CCL APB Protect Enable Mask */
#define PAC_STATUSC_CCL(value)                (PAC_STATUSC_CCL_Msk & (_UINT32_(value) << PAC_STATUSC_CCL_Pos)) /* Assigment of value for CCL in the PAC_STATUSC register */
#define PAC_STATUSC_I2S_Pos                   _UINT32_(19)                                         /* (PAC_STATUSC) I2S APB Protect Enable Position */
#define PAC_STATUSC_I2S_Msk                   (_UINT32_(0x1) << PAC_STATUSC_I2S_Pos)               /* (PAC_STATUSC) I2S APB Protect Enable Mask */
#define PAC_STATUSC_I2S(value)                (PAC_STATUSC_I2S_Msk & (_UINT32_(value) << PAC_STATUSC_I2S_Pos)) /* Assigment of value for I2S in the PAC_STATUSC register */
#define PAC_STATUSC_OPAMP_Pos                 _UINT32_(20)                                         /* (PAC_STATUSC) OPAMP APB Protect Enable Position */
#define PAC_STATUSC_OPAMP_Msk                 (_UINT32_(0x1) << PAC_STATUSC_OPAMP_Pos)             /* (PAC_STATUSC) OPAMP APB Protect Enable Mask */
#define PAC_STATUSC_OPAMP(value)              (PAC_STATUSC_OPAMP_Msk & (_UINT32_(value) << PAC_STATUSC_OPAMP_Pos)) /* Assigment of value for OPAMP in the PAC_STATUSC register */
#define PAC_STATUSC_TRAM_Pos                  _UINT32_(21)                                         /* (PAC_STATUSC) TRAM APB Protect Enable Position */
#define PAC_STATUSC_TRAM_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TRAM_Pos)              /* (PAC_STATUSC) TRAM APB Protect Enable Mask */
#define PAC_STATUSC_TRAM(value)               (PAC_STATUSC_TRAM_Msk & (_UINT32_(value) << PAC_STATUSC_TRAM_Pos)) /* Assigment of value for TRAM in the PAC_STATUSC register */
#define PAC_STATUSC_Msk                       _UINT32_(0x003FFFFF)                                 /* (PAC_STATUSC) Register Mask  */

#define PAC_STATUSC_SERCOM_Pos                _UINT32_(1)                                          /* (PAC_STATUSC Position) SERCOMx APB Protect Enable */
#define PAC_STATUSC_SERCOM_Msk                (_UINT32_(0x3F) << PAC_STATUSC_SERCOM_Pos)           /* (PAC_STATUSC Mask) SERCOM */
#define PAC_STATUSC_SERCOM(value)             (PAC_STATUSC_SERCOM_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM_Pos)) 
#define PAC_STATUSC_TC_Pos                    _UINT32_(7)                                          /* (PAC_STATUSC Position) TCx APB Protect Enable */
#define PAC_STATUSC_TC_Msk                    (_UINT32_(0x7) << PAC_STATUSC_TC_Pos)                /* (PAC_STATUSC Mask) TC */
#define PAC_STATUSC_TC(value)                 (PAC_STATUSC_TC_Msk & (_UINT32_(value) << PAC_STATUSC_TC_Pos)) 
#define PAC_STATUSC_TCC_Pos                   _UINT32_(10)                                         /* (PAC_STATUSC Position) TCCx APB Protect Enable */
#define PAC_STATUSC_TCC_Msk                   (_UINT32_(0xF) << PAC_STATUSC_TCC_Pos)               /* (PAC_STATUSC Mask) TCC */
#define PAC_STATUSC_TCC(value)                (PAC_STATUSC_TCC_Msk & (_UINT32_(value) << PAC_STATUSC_TCC_Pos)) 

/* -------- PAC_NONSECA : (PAC Offset: 0x54) ( R/ 32) Peripheral non-secure status - Bridge A -------- */
#define PAC_NONSECA_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_NONSECA) Peripheral non-secure status - Bridge A  Reset Value */

#define PAC_NONSECA_PAC_Pos                   _UINT32_(0)                                          /* (PAC_NONSECA) PAC Non-Secure Position */
#define PAC_NONSECA_PAC_Msk                   (_UINT32_(0x1) << PAC_NONSECA_PAC_Pos)               /* (PAC_NONSECA) PAC Non-Secure Mask */
#define PAC_NONSECA_PAC(value)                (PAC_NONSECA_PAC_Msk & (_UINT32_(value) << PAC_NONSECA_PAC_Pos)) /* Assigment of value for PAC in the PAC_NONSECA register */
#define PAC_NONSECA_PM_Pos                    _UINT32_(1)                                          /* (PAC_NONSECA) PM Non-Secure Position */
#define PAC_NONSECA_PM_Msk                    (_UINT32_(0x1) << PAC_NONSECA_PM_Pos)                /* (PAC_NONSECA) PM Non-Secure Mask */
#define PAC_NONSECA_PM(value)                 (PAC_NONSECA_PM_Msk & (_UINT32_(value) << PAC_NONSECA_PM_Pos)) /* Assigment of value for PM in the PAC_NONSECA register */
#define PAC_NONSECA_MCLK_Pos                  _UINT32_(2)                                          /* (PAC_NONSECA) MCLK Non-Secure Position */
#define PAC_NONSECA_MCLK_Msk                  (_UINT32_(0x1) << PAC_NONSECA_MCLK_Pos)              /* (PAC_NONSECA) MCLK Non-Secure Mask */
#define PAC_NONSECA_MCLK(value)               (PAC_NONSECA_MCLK_Msk & (_UINT32_(value) << PAC_NONSECA_MCLK_Pos)) /* Assigment of value for MCLK in the PAC_NONSECA register */
#define PAC_NONSECA_RSTC_Pos                  _UINT32_(3)                                          /* (PAC_NONSECA) RSTC Non-Secure Position */
#define PAC_NONSECA_RSTC_Msk                  (_UINT32_(0x1) << PAC_NONSECA_RSTC_Pos)              /* (PAC_NONSECA) RSTC Non-Secure Mask */
#define PAC_NONSECA_RSTC(value)               (PAC_NONSECA_RSTC_Msk & (_UINT32_(value) << PAC_NONSECA_RSTC_Pos)) /* Assigment of value for RSTC in the PAC_NONSECA register */
#define PAC_NONSECA_OSCCTRL_Pos               _UINT32_(4)                                          /* (PAC_NONSECA) OSCCTRL Non-Secure Position */
#define PAC_NONSECA_OSCCTRL_Msk               (_UINT32_(0x1) << PAC_NONSECA_OSCCTRL_Pos)           /* (PAC_NONSECA) OSCCTRL Non-Secure Mask */
#define PAC_NONSECA_OSCCTRL(value)            (PAC_NONSECA_OSCCTRL_Msk & (_UINT32_(value) << PAC_NONSECA_OSCCTRL_Pos)) /* Assigment of value for OSCCTRL in the PAC_NONSECA register */
#define PAC_NONSECA_OSC32KCTRL_Pos            _UINT32_(5)                                          /* (PAC_NONSECA) OSC32KCTRL Non-Secure Position */
#define PAC_NONSECA_OSC32KCTRL_Msk            (_UINT32_(0x1) << PAC_NONSECA_OSC32KCTRL_Pos)        /* (PAC_NONSECA) OSC32KCTRL Non-Secure Mask */
#define PAC_NONSECA_OSC32KCTRL(value)         (PAC_NONSECA_OSC32KCTRL_Msk & (_UINT32_(value) << PAC_NONSECA_OSC32KCTRL_Pos)) /* Assigment of value for OSC32KCTRL in the PAC_NONSECA register */
#define PAC_NONSECA_SUPC_Pos                  _UINT32_(6)                                          /* (PAC_NONSECA) SUPC Non-Secure Position */
#define PAC_NONSECA_SUPC_Msk                  (_UINT32_(0x1) << PAC_NONSECA_SUPC_Pos)              /* (PAC_NONSECA) SUPC Non-Secure Mask */
#define PAC_NONSECA_SUPC(value)               (PAC_NONSECA_SUPC_Msk & (_UINT32_(value) << PAC_NONSECA_SUPC_Pos)) /* Assigment of value for SUPC in the PAC_NONSECA register */
#define PAC_NONSECA_GCLK_Pos                  _UINT32_(7)                                          /* (PAC_NONSECA) GCLK Non-Secure Position */
#define PAC_NONSECA_GCLK_Msk                  (_UINT32_(0x1) << PAC_NONSECA_GCLK_Pos)              /* (PAC_NONSECA) GCLK Non-Secure Mask */
#define PAC_NONSECA_GCLK(value)               (PAC_NONSECA_GCLK_Msk & (_UINT32_(value) << PAC_NONSECA_GCLK_Pos)) /* Assigment of value for GCLK in the PAC_NONSECA register */
#define PAC_NONSECA_WDT_Pos                   _UINT32_(8)                                          /* (PAC_NONSECA) WDT Non-Secure Position */
#define PAC_NONSECA_WDT_Msk                   (_UINT32_(0x1) << PAC_NONSECA_WDT_Pos)               /* (PAC_NONSECA) WDT Non-Secure Mask */
#define PAC_NONSECA_WDT(value)                (PAC_NONSECA_WDT_Msk & (_UINT32_(value) << PAC_NONSECA_WDT_Pos)) /* Assigment of value for WDT in the PAC_NONSECA register */
#define PAC_NONSECA_RTC_Pos                   _UINT32_(9)                                          /* (PAC_NONSECA) RTC Non-Secure Position */
#define PAC_NONSECA_RTC_Msk                   (_UINT32_(0x1) << PAC_NONSECA_RTC_Pos)               /* (PAC_NONSECA) RTC Non-Secure Mask */
#define PAC_NONSECA_RTC(value)                (PAC_NONSECA_RTC_Msk & (_UINT32_(value) << PAC_NONSECA_RTC_Pos)) /* Assigment of value for RTC in the PAC_NONSECA register */
#define PAC_NONSECA_EIC_Pos                   _UINT32_(10)                                         /* (PAC_NONSECA) EIC Non-Secure Position */
#define PAC_NONSECA_EIC_Msk                   (_UINT32_(0x1) << PAC_NONSECA_EIC_Pos)               /* (PAC_NONSECA) EIC Non-Secure Mask */
#define PAC_NONSECA_EIC(value)                (PAC_NONSECA_EIC_Msk & (_UINT32_(value) << PAC_NONSECA_EIC_Pos)) /* Assigment of value for EIC in the PAC_NONSECA register */
#define PAC_NONSECA_FREQM_Pos                 _UINT32_(11)                                         /* (PAC_NONSECA) FREQM Non-Secure Position */
#define PAC_NONSECA_FREQM_Msk                 (_UINT32_(0x1) << PAC_NONSECA_FREQM_Pos)             /* (PAC_NONSECA) FREQM Non-Secure Mask */
#define PAC_NONSECA_FREQM(value)              (PAC_NONSECA_FREQM_Msk & (_UINT32_(value) << PAC_NONSECA_FREQM_Pos)) /* Assigment of value for FREQM in the PAC_NONSECA register */
#define PAC_NONSECA_PORT_Pos                  _UINT32_(12)                                         /* (PAC_NONSECA) PORT Non-Secure Position */
#define PAC_NONSECA_PORT_Msk                  (_UINT32_(0x1) << PAC_NONSECA_PORT_Pos)              /* (PAC_NONSECA) PORT Non-Secure Mask */
#define PAC_NONSECA_PORT(value)               (PAC_NONSECA_PORT_Msk & (_UINT32_(value) << PAC_NONSECA_PORT_Pos)) /* Assigment of value for PORT in the PAC_NONSECA register */
#define PAC_NONSECA_AC_Pos                    _UINT32_(13)                                         /* (PAC_NONSECA) AC Non-Secure Position */
#define PAC_NONSECA_AC_Msk                    (_UINT32_(0x1) << PAC_NONSECA_AC_Pos)                /* (PAC_NONSECA) AC Non-Secure Mask */
#define PAC_NONSECA_AC(value)                 (PAC_NONSECA_AC_Msk & (_UINT32_(value) << PAC_NONSECA_AC_Pos)) /* Assigment of value for AC in the PAC_NONSECA register */
#define PAC_NONSECA_Msk                       _UINT32_(0x00003FFF)                                 /* (PAC_NONSECA) Register Mask  */


/* -------- PAC_NONSECB : (PAC Offset: 0x58) ( R/ 32) Peripheral non-secure status - Bridge B -------- */
#define PAC_NONSECB_RESETVALUE                _UINT32_(0x02)                                       /*  (PAC_NONSECB) Peripheral non-secure status - Bridge B  Reset Value */

#define PAC_NONSECB_IDAU_Pos                  _UINT32_(0)                                          /* (PAC_NONSECB) IDAU Non-Secure Position */
#define PAC_NONSECB_IDAU_Msk                  (_UINT32_(0x1) << PAC_NONSECB_IDAU_Pos)              /* (PAC_NONSECB) IDAU Non-Secure Mask */
#define PAC_NONSECB_IDAU(value)               (PAC_NONSECB_IDAU_Msk & (_UINT32_(value) << PAC_NONSECB_IDAU_Pos)) /* Assigment of value for IDAU in the PAC_NONSECB register */
#define PAC_NONSECB_DSU_Pos                   _UINT32_(1)                                          /* (PAC_NONSECB) DSU Non-Secure Position */
#define PAC_NONSECB_DSU_Msk                   (_UINT32_(0x1) << PAC_NONSECB_DSU_Pos)               /* (PAC_NONSECB) DSU Non-Secure Mask */
#define PAC_NONSECB_DSU(value)                (PAC_NONSECB_DSU_Msk & (_UINT32_(value) << PAC_NONSECB_DSU_Pos)) /* Assigment of value for DSU in the PAC_NONSECB register */
#define PAC_NONSECB_NVMCTRL_Pos               _UINT32_(2)                                          /* (PAC_NONSECB) NVMCTRL Non-Secure Position */
#define PAC_NONSECB_NVMCTRL_Msk               (_UINT32_(0x1) << PAC_NONSECB_NVMCTRL_Pos)           /* (PAC_NONSECB) NVMCTRL Non-Secure Mask */
#define PAC_NONSECB_NVMCTRL(value)            (PAC_NONSECB_NVMCTRL_Msk & (_UINT32_(value) << PAC_NONSECB_NVMCTRL_Pos)) /* Assigment of value for NVMCTRL in the PAC_NONSECB register */
#define PAC_NONSECB_DMAC_Pos                  _UINT32_(3)                                          /* (PAC_NONSECB) DMAC Non-Secure Position */
#define PAC_NONSECB_DMAC_Msk                  (_UINT32_(0x1) << PAC_NONSECB_DMAC_Pos)              /* (PAC_NONSECB) DMAC Non-Secure Mask */
#define PAC_NONSECB_DMAC(value)               (PAC_NONSECB_DMAC_Msk & (_UINT32_(value) << PAC_NONSECB_DMAC_Pos)) /* Assigment of value for DMAC in the PAC_NONSECB register */
#define PAC_NONSECB_HMATRIXHS_Pos             _UINT32_(4)                                          /* (PAC_NONSECB) HMATRIXHS Non-Secure Position */
#define PAC_NONSECB_HMATRIXHS_Msk             (_UINT32_(0x1) << PAC_NONSECB_HMATRIXHS_Pos)         /* (PAC_NONSECB) HMATRIXHS Non-Secure Mask */
#define PAC_NONSECB_HMATRIXHS(value)          (PAC_NONSECB_HMATRIXHS_Msk & (_UINT32_(value) << PAC_NONSECB_HMATRIXHS_Pos)) /* Assigment of value for HMATRIXHS in the PAC_NONSECB register */
#define PAC_NONSECB_USB_Pos                   _UINT32_(5)                                          /* (PAC_NONSECB) USB Non-Secure Position */
#define PAC_NONSECB_USB_Msk                   (_UINT32_(0x1) << PAC_NONSECB_USB_Pos)               /* (PAC_NONSECB) USB Non-Secure Mask */
#define PAC_NONSECB_USB(value)                (PAC_NONSECB_USB_Msk & (_UINT32_(value) << PAC_NONSECB_USB_Pos)) /* Assigment of value for USB in the PAC_NONSECB register */
#define PAC_NONSECB_Msk                       _UINT32_(0x0000003F)                                 /* (PAC_NONSECB) Register Mask  */


/* -------- PAC_NONSECC : (PAC Offset: 0x5C) ( R/ 32) Peripheral non-secure status - Bridge C -------- */
#define PAC_NONSECC_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_NONSECC) Peripheral non-secure status - Bridge C  Reset Value */

#define PAC_NONSECC_EVSYS_Pos                 _UINT32_(0)                                          /* (PAC_NONSECC) EVSYS Non-Secure Position */
#define PAC_NONSECC_EVSYS_Msk                 (_UINT32_(0x1) << PAC_NONSECC_EVSYS_Pos)             /* (PAC_NONSECC) EVSYS Non-Secure Mask */
#define PAC_NONSECC_EVSYS(value)              (PAC_NONSECC_EVSYS_Msk & (_UINT32_(value) << PAC_NONSECC_EVSYS_Pos)) /* Assigment of value for EVSYS in the PAC_NONSECC register */
#define PAC_NONSECC_SERCOM0_Pos               _UINT32_(1)                                          /* (PAC_NONSECC) SERCOM0 Non-Secure Position */
#define PAC_NONSECC_SERCOM0_Msk               (_UINT32_(0x1) << PAC_NONSECC_SERCOM0_Pos)           /* (PAC_NONSECC) SERCOM0 Non-Secure Mask */
#define PAC_NONSECC_SERCOM0(value)            (PAC_NONSECC_SERCOM0_Msk & (_UINT32_(value) << PAC_NONSECC_SERCOM0_Pos)) /* Assigment of value for SERCOM0 in the PAC_NONSECC register */
#define PAC_NONSECC_SERCOM1_Pos               _UINT32_(2)                                          /* (PAC_NONSECC) SERCOM1 Non-Secure Position */
#define PAC_NONSECC_SERCOM1_Msk               (_UINT32_(0x1) << PAC_NONSECC_SERCOM1_Pos)           /* (PAC_NONSECC) SERCOM1 Non-Secure Mask */
#define PAC_NONSECC_SERCOM1(value)            (PAC_NONSECC_SERCOM1_Msk & (_UINT32_(value) << PAC_NONSECC_SERCOM1_Pos)) /* Assigment of value for SERCOM1 in the PAC_NONSECC register */
#define PAC_NONSECC_SERCOM2_Pos               _UINT32_(3)                                          /* (PAC_NONSECC) SERCOM2 Non-Secure Position */
#define PAC_NONSECC_SERCOM2_Msk               (_UINT32_(0x1) << PAC_NONSECC_SERCOM2_Pos)           /* (PAC_NONSECC) SERCOM2 Non-Secure Mask */
#define PAC_NONSECC_SERCOM2(value)            (PAC_NONSECC_SERCOM2_Msk & (_UINT32_(value) << PAC_NONSECC_SERCOM2_Pos)) /* Assigment of value for SERCOM2 in the PAC_NONSECC register */
#define PAC_NONSECC_SERCOM3_Pos               _UINT32_(4)                                          /* (PAC_NONSECC) SERCOM3 Non-Secure Position */
#define PAC_NONSECC_SERCOM3_Msk               (_UINT32_(0x1) << PAC_NONSECC_SERCOM3_Pos)           /* (PAC_NONSECC) SERCOM3 Non-Secure Mask */
#define PAC_NONSECC_SERCOM3(value)            (PAC_NONSECC_SERCOM3_Msk & (_UINT32_(value) << PAC_NONSECC_SERCOM3_Pos)) /* Assigment of value for SERCOM3 in the PAC_NONSECC register */
#define PAC_NONSECC_SERCOM4_Pos               _UINT32_(5)                                          /* (PAC_NONSECC) SERCOM4 Non-Secure Position */
#define PAC_NONSECC_SERCOM4_Msk               (_UINT32_(0x1) << PAC_NONSECC_SERCOM4_Pos)           /* (PAC_NONSECC) SERCOM4 Non-Secure Mask */
#define PAC_NONSECC_SERCOM4(value)            (PAC_NONSECC_SERCOM4_Msk & (_UINT32_(value) << PAC_NONSECC_SERCOM4_Pos)) /* Assigment of value for SERCOM4 in the PAC_NONSECC register */
#define PAC_NONSECC_SERCOM5_Pos               _UINT32_(6)                                          /* (PAC_NONSECC) SERCOM5 Non-Secure Position */
#define PAC_NONSECC_SERCOM5_Msk               (_UINT32_(0x1) << PAC_NONSECC_SERCOM5_Pos)           /* (PAC_NONSECC) SERCOM5 Non-Secure Mask */
#define PAC_NONSECC_SERCOM5(value)            (PAC_NONSECC_SERCOM5_Msk & (_UINT32_(value) << PAC_NONSECC_SERCOM5_Pos)) /* Assigment of value for SERCOM5 in the PAC_NONSECC register */
#define PAC_NONSECC_TC0_Pos                   _UINT32_(7)                                          /* (PAC_NONSECC) TC0 Non-Secure Position */
#define PAC_NONSECC_TC0_Msk                   (_UINT32_(0x1) << PAC_NONSECC_TC0_Pos)               /* (PAC_NONSECC) TC0 Non-Secure Mask */
#define PAC_NONSECC_TC0(value)                (PAC_NONSECC_TC0_Msk & (_UINT32_(value) << PAC_NONSECC_TC0_Pos)) /* Assigment of value for TC0 in the PAC_NONSECC register */
#define PAC_NONSECC_TC1_Pos                   _UINT32_(8)                                          /* (PAC_NONSECC) TC1 Non-Secure Position */
#define PAC_NONSECC_TC1_Msk                   (_UINT32_(0x1) << PAC_NONSECC_TC1_Pos)               /* (PAC_NONSECC) TC1 Non-Secure Mask */
#define PAC_NONSECC_TC1(value)                (PAC_NONSECC_TC1_Msk & (_UINT32_(value) << PAC_NONSECC_TC1_Pos)) /* Assigment of value for TC1 in the PAC_NONSECC register */
#define PAC_NONSECC_TC2_Pos                   _UINT32_(9)                                          /* (PAC_NONSECC) TC2 Non-Secure Position */
#define PAC_NONSECC_TC2_Msk                   (_UINT32_(0x1) << PAC_NONSECC_TC2_Pos)               /* (PAC_NONSECC) TC2 Non-Secure Mask */
#define PAC_NONSECC_TC2(value)                (PAC_NONSECC_TC2_Msk & (_UINT32_(value) << PAC_NONSECC_TC2_Pos)) /* Assigment of value for TC2 in the PAC_NONSECC register */
#define PAC_NONSECC_TCC0_Pos                  _UINT32_(10)                                         /* (PAC_NONSECC) TCC0 Non-Secure Position */
#define PAC_NONSECC_TCC0_Msk                  (_UINT32_(0x1) << PAC_NONSECC_TCC0_Pos)              /* (PAC_NONSECC) TCC0 Non-Secure Mask */
#define PAC_NONSECC_TCC0(value)               (PAC_NONSECC_TCC0_Msk & (_UINT32_(value) << PAC_NONSECC_TCC0_Pos)) /* Assigment of value for TCC0 in the PAC_NONSECC register */
#define PAC_NONSECC_TCC1_Pos                  _UINT32_(11)                                         /* (PAC_NONSECC) TCC1 Non-Secure Position */
#define PAC_NONSECC_TCC1_Msk                  (_UINT32_(0x1) << PAC_NONSECC_TCC1_Pos)              /* (PAC_NONSECC) TCC1 Non-Secure Mask */
#define PAC_NONSECC_TCC1(value)               (PAC_NONSECC_TCC1_Msk & (_UINT32_(value) << PAC_NONSECC_TCC1_Pos)) /* Assigment of value for TCC1 in the PAC_NONSECC register */
#define PAC_NONSECC_TCC2_Pos                  _UINT32_(12)                                         /* (PAC_NONSECC) TCC2 Non-Secure Position */
#define PAC_NONSECC_TCC2_Msk                  (_UINT32_(0x1) << PAC_NONSECC_TCC2_Pos)              /* (PAC_NONSECC) TCC2 Non-Secure Mask */
#define PAC_NONSECC_TCC2(value)               (PAC_NONSECC_TCC2_Msk & (_UINT32_(value) << PAC_NONSECC_TCC2_Pos)) /* Assigment of value for TCC2 in the PAC_NONSECC register */
#define PAC_NONSECC_TCC3_Pos                  _UINT32_(13)                                         /* (PAC_NONSECC) TCC3 Non-Secure Position */
#define PAC_NONSECC_TCC3_Msk                  (_UINT32_(0x1) << PAC_NONSECC_TCC3_Pos)              /* (PAC_NONSECC) TCC3 Non-Secure Mask */
#define PAC_NONSECC_TCC3(value)               (PAC_NONSECC_TCC3_Msk & (_UINT32_(value) << PAC_NONSECC_TCC3_Pos)) /* Assigment of value for TCC3 in the PAC_NONSECC register */
#define PAC_NONSECC_ADC_Pos                   _UINT32_(14)                                         /* (PAC_NONSECC) ADC Non-Secure Position */
#define PAC_NONSECC_ADC_Msk                   (_UINT32_(0x1) << PAC_NONSECC_ADC_Pos)               /* (PAC_NONSECC) ADC Non-Secure Mask */
#define PAC_NONSECC_ADC(value)                (PAC_NONSECC_ADC_Msk & (_UINT32_(value) << PAC_NONSECC_ADC_Pos)) /* Assigment of value for ADC in the PAC_NONSECC register */
#define PAC_NONSECC_DAC_Pos                   _UINT32_(15)                                         /* (PAC_NONSECC) DAC Non-Secure Position */
#define PAC_NONSECC_DAC_Msk                   (_UINT32_(0x1) << PAC_NONSECC_DAC_Pos)               /* (PAC_NONSECC) DAC Non-Secure Mask */
#define PAC_NONSECC_DAC(value)                (PAC_NONSECC_DAC_Msk & (_UINT32_(value) << PAC_NONSECC_DAC_Pos)) /* Assigment of value for DAC in the PAC_NONSECC register */
#define PAC_NONSECC_PTC_Pos                   _UINT32_(16)                                         /* (PAC_NONSECC) PTC Non-Secure Position */
#define PAC_NONSECC_PTC_Msk                   (_UINT32_(0x1) << PAC_NONSECC_PTC_Pos)               /* (PAC_NONSECC) PTC Non-Secure Mask */
#define PAC_NONSECC_PTC(value)                (PAC_NONSECC_PTC_Msk & (_UINT32_(value) << PAC_NONSECC_PTC_Pos)) /* Assigment of value for PTC in the PAC_NONSECC register */
#define PAC_NONSECC_TRNG_Pos                  _UINT32_(17)                                         /* (PAC_NONSECC) TRNG Non-Secure Position */
#define PAC_NONSECC_TRNG_Msk                  (_UINT32_(0x1) << PAC_NONSECC_TRNG_Pos)              /* (PAC_NONSECC) TRNG Non-Secure Mask */
#define PAC_NONSECC_TRNG(value)               (PAC_NONSECC_TRNG_Msk & (_UINT32_(value) << PAC_NONSECC_TRNG_Pos)) /* Assigment of value for TRNG in the PAC_NONSECC register */
#define PAC_NONSECC_CCL_Pos                   _UINT32_(18)                                         /* (PAC_NONSECC) CCL Non-Secure Position */
#define PAC_NONSECC_CCL_Msk                   (_UINT32_(0x1) << PAC_NONSECC_CCL_Pos)               /* (PAC_NONSECC) CCL Non-Secure Mask */
#define PAC_NONSECC_CCL(value)                (PAC_NONSECC_CCL_Msk & (_UINT32_(value) << PAC_NONSECC_CCL_Pos)) /* Assigment of value for CCL in the PAC_NONSECC register */
#define PAC_NONSECC_I2S_Pos                   _UINT32_(19)                                         /* (PAC_NONSECC) I2S Non-Secure Position */
#define PAC_NONSECC_I2S_Msk                   (_UINT32_(0x1) << PAC_NONSECC_I2S_Pos)               /* (PAC_NONSECC) I2S Non-Secure Mask */
#define PAC_NONSECC_I2S(value)                (PAC_NONSECC_I2S_Msk & (_UINT32_(value) << PAC_NONSECC_I2S_Pos)) /* Assigment of value for I2S in the PAC_NONSECC register */
#define PAC_NONSECC_OPAMP_Pos                 _UINT32_(20)                                         /* (PAC_NONSECC) OPAMP Non-Secure Position */
#define PAC_NONSECC_OPAMP_Msk                 (_UINT32_(0x1) << PAC_NONSECC_OPAMP_Pos)             /* (PAC_NONSECC) OPAMP Non-Secure Mask */
#define PAC_NONSECC_OPAMP(value)              (PAC_NONSECC_OPAMP_Msk & (_UINT32_(value) << PAC_NONSECC_OPAMP_Pos)) /* Assigment of value for OPAMP in the PAC_NONSECC register */
#define PAC_NONSECC_TRAM_Pos                  _UINT32_(21)                                         /* (PAC_NONSECC) TRAM Non-Secure Position */
#define PAC_NONSECC_TRAM_Msk                  (_UINT32_(0x1) << PAC_NONSECC_TRAM_Pos)              /* (PAC_NONSECC) TRAM Non-Secure Mask */
#define PAC_NONSECC_TRAM(value)               (PAC_NONSECC_TRAM_Msk & (_UINT32_(value) << PAC_NONSECC_TRAM_Pos)) /* Assigment of value for TRAM in the PAC_NONSECC register */
#define PAC_NONSECC_Msk                       _UINT32_(0x003FFFFF)                                 /* (PAC_NONSECC) Register Mask  */

#define PAC_NONSECC_SERCOM_Pos                _UINT32_(1)                                          /* (PAC_NONSECC Position) SERCOMx Non-Secure */
#define PAC_NONSECC_SERCOM_Msk                (_UINT32_(0x3F) << PAC_NONSECC_SERCOM_Pos)           /* (PAC_NONSECC Mask) SERCOM */
#define PAC_NONSECC_SERCOM(value)             (PAC_NONSECC_SERCOM_Msk & (_UINT32_(value) << PAC_NONSECC_SERCOM_Pos)) 
#define PAC_NONSECC_TC_Pos                    _UINT32_(7)                                          /* (PAC_NONSECC Position) TCx Non-Secure */
#define PAC_NONSECC_TC_Msk                    (_UINT32_(0x7) << PAC_NONSECC_TC_Pos)                /* (PAC_NONSECC Mask) TC */
#define PAC_NONSECC_TC(value)                 (PAC_NONSECC_TC_Msk & (_UINT32_(value) << PAC_NONSECC_TC_Pos)) 
#define PAC_NONSECC_TCC_Pos                   _UINT32_(10)                                         /* (PAC_NONSECC Position) TCCx Non-Secure */
#define PAC_NONSECC_TCC_Msk                   (_UINT32_(0xF) << PAC_NONSECC_TCC_Pos)               /* (PAC_NONSECC Mask) TCC */
#define PAC_NONSECC_TCC(value)                (PAC_NONSECC_TCC_Msk & (_UINT32_(value) << PAC_NONSECC_TCC_Pos)) 

/* -------- PAC_SECLOCKA : (PAC Offset: 0x74) ( R/ 32) Peripheral secure status locked - Bridge A -------- */
#define PAC_SECLOCKA_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_SECLOCKA) Peripheral secure status locked - Bridge A  Reset Value */

#define PAC_SECLOCKA_PAC_Pos                  _UINT32_(0)                                          /* (PAC_SECLOCKA) PAC Secure Status Locked Position */
#define PAC_SECLOCKA_PAC_Msk                  (_UINT32_(0x1) << PAC_SECLOCKA_PAC_Pos)              /* (PAC_SECLOCKA) PAC Secure Status Locked Mask */
#define PAC_SECLOCKA_PAC(value)               (PAC_SECLOCKA_PAC_Msk & (_UINT32_(value) << PAC_SECLOCKA_PAC_Pos)) /* Assigment of value for PAC in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_PM_Pos                   _UINT32_(1)                                          /* (PAC_SECLOCKA) PM Secure Status Locked Position */
#define PAC_SECLOCKA_PM_Msk                   (_UINT32_(0x1) << PAC_SECLOCKA_PM_Pos)               /* (PAC_SECLOCKA) PM Secure Status Locked Mask */
#define PAC_SECLOCKA_PM(value)                (PAC_SECLOCKA_PM_Msk & (_UINT32_(value) << PAC_SECLOCKA_PM_Pos)) /* Assigment of value for PM in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_MCLK_Pos                 _UINT32_(2)                                          /* (PAC_SECLOCKA) MCLK Secure Status Locked Position */
#define PAC_SECLOCKA_MCLK_Msk                 (_UINT32_(0x1) << PAC_SECLOCKA_MCLK_Pos)             /* (PAC_SECLOCKA) MCLK Secure Status Locked Mask */
#define PAC_SECLOCKA_MCLK(value)              (PAC_SECLOCKA_MCLK_Msk & (_UINT32_(value) << PAC_SECLOCKA_MCLK_Pos)) /* Assigment of value for MCLK in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_RSTC_Pos                 _UINT32_(3)                                          /* (PAC_SECLOCKA) RSTC Secure Status Locked Position */
#define PAC_SECLOCKA_RSTC_Msk                 (_UINT32_(0x1) << PAC_SECLOCKA_RSTC_Pos)             /* (PAC_SECLOCKA) RSTC Secure Status Locked Mask */
#define PAC_SECLOCKA_RSTC(value)              (PAC_SECLOCKA_RSTC_Msk & (_UINT32_(value) << PAC_SECLOCKA_RSTC_Pos)) /* Assigment of value for RSTC in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_OSCCTRL_Pos              _UINT32_(4)                                          /* (PAC_SECLOCKA) OSCCTRL Secure Status Locked Position */
#define PAC_SECLOCKA_OSCCTRL_Msk              (_UINT32_(0x1) << PAC_SECLOCKA_OSCCTRL_Pos)          /* (PAC_SECLOCKA) OSCCTRL Secure Status Locked Mask */
#define PAC_SECLOCKA_OSCCTRL(value)           (PAC_SECLOCKA_OSCCTRL_Msk & (_UINT32_(value) << PAC_SECLOCKA_OSCCTRL_Pos)) /* Assigment of value for OSCCTRL in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_OSC32KCTRL_Pos           _UINT32_(5)                                          /* (PAC_SECLOCKA) OSC32KCTRL Secure Status Locked Position */
#define PAC_SECLOCKA_OSC32KCTRL_Msk           (_UINT32_(0x1) << PAC_SECLOCKA_OSC32KCTRL_Pos)       /* (PAC_SECLOCKA) OSC32KCTRL Secure Status Locked Mask */
#define PAC_SECLOCKA_OSC32KCTRL(value)        (PAC_SECLOCKA_OSC32KCTRL_Msk & (_UINT32_(value) << PAC_SECLOCKA_OSC32KCTRL_Pos)) /* Assigment of value for OSC32KCTRL in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_SUPC_Pos                 _UINT32_(6)                                          /* (PAC_SECLOCKA) SUPC Secure Status Locked Position */
#define PAC_SECLOCKA_SUPC_Msk                 (_UINT32_(0x1) << PAC_SECLOCKA_SUPC_Pos)             /* (PAC_SECLOCKA) SUPC Secure Status Locked Mask */
#define PAC_SECLOCKA_SUPC(value)              (PAC_SECLOCKA_SUPC_Msk & (_UINT32_(value) << PAC_SECLOCKA_SUPC_Pos)) /* Assigment of value for SUPC in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_GCLK_Pos                 _UINT32_(7)                                          /* (PAC_SECLOCKA) GCLK Secure Status Locked Position */
#define PAC_SECLOCKA_GCLK_Msk                 (_UINT32_(0x1) << PAC_SECLOCKA_GCLK_Pos)             /* (PAC_SECLOCKA) GCLK Secure Status Locked Mask */
#define PAC_SECLOCKA_GCLK(value)              (PAC_SECLOCKA_GCLK_Msk & (_UINT32_(value) << PAC_SECLOCKA_GCLK_Pos)) /* Assigment of value for GCLK in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_WDT_Pos                  _UINT32_(8)                                          /* (PAC_SECLOCKA) WDT Secure Status Locked Position */
#define PAC_SECLOCKA_WDT_Msk                  (_UINT32_(0x1) << PAC_SECLOCKA_WDT_Pos)              /* (PAC_SECLOCKA) WDT Secure Status Locked Mask */
#define PAC_SECLOCKA_WDT(value)               (PAC_SECLOCKA_WDT_Msk & (_UINT32_(value) << PAC_SECLOCKA_WDT_Pos)) /* Assigment of value for WDT in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_RTC_Pos                  _UINT32_(9)                                          /* (PAC_SECLOCKA) RTC Secure Status Locked Position */
#define PAC_SECLOCKA_RTC_Msk                  (_UINT32_(0x1) << PAC_SECLOCKA_RTC_Pos)              /* (PAC_SECLOCKA) RTC Secure Status Locked Mask */
#define PAC_SECLOCKA_RTC(value)               (PAC_SECLOCKA_RTC_Msk & (_UINT32_(value) << PAC_SECLOCKA_RTC_Pos)) /* Assigment of value for RTC in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_EIC_Pos                  _UINT32_(10)                                         /* (PAC_SECLOCKA) EIC Secure Status Locked Position */
#define PAC_SECLOCKA_EIC_Msk                  (_UINT32_(0x1) << PAC_SECLOCKA_EIC_Pos)              /* (PAC_SECLOCKA) EIC Secure Status Locked Mask */
#define PAC_SECLOCKA_EIC(value)               (PAC_SECLOCKA_EIC_Msk & (_UINT32_(value) << PAC_SECLOCKA_EIC_Pos)) /* Assigment of value for EIC in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_FREQM_Pos                _UINT32_(11)                                         /* (PAC_SECLOCKA) FREQM Secure Status Locked Position */
#define PAC_SECLOCKA_FREQM_Msk                (_UINT32_(0x1) << PAC_SECLOCKA_FREQM_Pos)            /* (PAC_SECLOCKA) FREQM Secure Status Locked Mask */
#define PAC_SECLOCKA_FREQM(value)             (PAC_SECLOCKA_FREQM_Msk & (_UINT32_(value) << PAC_SECLOCKA_FREQM_Pos)) /* Assigment of value for FREQM in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_PORT_Pos                 _UINT32_(12)                                         /* (PAC_SECLOCKA) PORT Secure Status Locked Position */
#define PAC_SECLOCKA_PORT_Msk                 (_UINT32_(0x1) << PAC_SECLOCKA_PORT_Pos)             /* (PAC_SECLOCKA) PORT Secure Status Locked Mask */
#define PAC_SECLOCKA_PORT(value)              (PAC_SECLOCKA_PORT_Msk & (_UINT32_(value) << PAC_SECLOCKA_PORT_Pos)) /* Assigment of value for PORT in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_AC_Pos                   _UINT32_(13)                                         /* (PAC_SECLOCKA) AC Secure Status Locked Position */
#define PAC_SECLOCKA_AC_Msk                   (_UINT32_(0x1) << PAC_SECLOCKA_AC_Pos)               /* (PAC_SECLOCKA) AC Secure Status Locked Mask */
#define PAC_SECLOCKA_AC(value)                (PAC_SECLOCKA_AC_Msk & (_UINT32_(value) << PAC_SECLOCKA_AC_Pos)) /* Assigment of value for AC in the PAC_SECLOCKA register */
#define PAC_SECLOCKA_Msk                      _UINT32_(0x00003FFF)                                 /* (PAC_SECLOCKA) Register Mask  */


/* -------- PAC_SECLOCKB : (PAC Offset: 0x78) ( R/ 32) Peripheral secure status locked - Bridge B -------- */
#define PAC_SECLOCKB_RESETVALUE               _UINT32_(0x03)                                       /*  (PAC_SECLOCKB) Peripheral secure status locked - Bridge B  Reset Value */

#define PAC_SECLOCKB_IDAU_Pos                 _UINT32_(0)                                          /* (PAC_SECLOCKB) IDAU Secure Status Locked Position */
#define PAC_SECLOCKB_IDAU_Msk                 (_UINT32_(0x1) << PAC_SECLOCKB_IDAU_Pos)             /* (PAC_SECLOCKB) IDAU Secure Status Locked Mask */
#define PAC_SECLOCKB_IDAU(value)              (PAC_SECLOCKB_IDAU_Msk & (_UINT32_(value) << PAC_SECLOCKB_IDAU_Pos)) /* Assigment of value for IDAU in the PAC_SECLOCKB register */
#define PAC_SECLOCKB_DSU_Pos                  _UINT32_(1)                                          /* (PAC_SECLOCKB) DSU Secure Status Locked Position */
#define PAC_SECLOCKB_DSU_Msk                  (_UINT32_(0x1) << PAC_SECLOCKB_DSU_Pos)              /* (PAC_SECLOCKB) DSU Secure Status Locked Mask */
#define PAC_SECLOCKB_DSU(value)               (PAC_SECLOCKB_DSU_Msk & (_UINT32_(value) << PAC_SECLOCKB_DSU_Pos)) /* Assigment of value for DSU in the PAC_SECLOCKB register */
#define PAC_SECLOCKB_NVMCTRL_Pos              _UINT32_(2)                                          /* (PAC_SECLOCKB) NVMCTRL Secure Status Locked Position */
#define PAC_SECLOCKB_NVMCTRL_Msk              (_UINT32_(0x1) << PAC_SECLOCKB_NVMCTRL_Pos)          /* (PAC_SECLOCKB) NVMCTRL Secure Status Locked Mask */
#define PAC_SECLOCKB_NVMCTRL(value)           (PAC_SECLOCKB_NVMCTRL_Msk & (_UINT32_(value) << PAC_SECLOCKB_NVMCTRL_Pos)) /* Assigment of value for NVMCTRL in the PAC_SECLOCKB register */
#define PAC_SECLOCKB_DMAC_Pos                 _UINT32_(3)                                          /* (PAC_SECLOCKB) DMAC Secure Status Locked Position */
#define PAC_SECLOCKB_DMAC_Msk                 (_UINT32_(0x1) << PAC_SECLOCKB_DMAC_Pos)             /* (PAC_SECLOCKB) DMAC Secure Status Locked Mask */
#define PAC_SECLOCKB_DMAC(value)              (PAC_SECLOCKB_DMAC_Msk & (_UINT32_(value) << PAC_SECLOCKB_DMAC_Pos)) /* Assigment of value for DMAC in the PAC_SECLOCKB register */
#define PAC_SECLOCKB_HMATRIXHS_Pos            _UINT32_(4)                                          /* (PAC_SECLOCKB) HMATRIXHS Secure Status Locked Position */
#define PAC_SECLOCKB_HMATRIXHS_Msk            (_UINT32_(0x1) << PAC_SECLOCKB_HMATRIXHS_Pos)        /* (PAC_SECLOCKB) HMATRIXHS Secure Status Locked Mask */
#define PAC_SECLOCKB_HMATRIXHS(value)         (PAC_SECLOCKB_HMATRIXHS_Msk & (_UINT32_(value) << PAC_SECLOCKB_HMATRIXHS_Pos)) /* Assigment of value for HMATRIXHS in the PAC_SECLOCKB register */
#define PAC_SECLOCKB_USB_Pos                  _UINT32_(5)                                          /* (PAC_SECLOCKB) USB Secure Status Locked Position */
#define PAC_SECLOCKB_USB_Msk                  (_UINT32_(0x1) << PAC_SECLOCKB_USB_Pos)              /* (PAC_SECLOCKB) USB Secure Status Locked Mask */
#define PAC_SECLOCKB_USB(value)               (PAC_SECLOCKB_USB_Msk & (_UINT32_(value) << PAC_SECLOCKB_USB_Pos)) /* Assigment of value for USB in the PAC_SECLOCKB register */
#define PAC_SECLOCKB_Msk                      _UINT32_(0x0000003F)                                 /* (PAC_SECLOCKB) Register Mask  */


/* -------- PAC_SECLOCKC : (PAC Offset: 0x7C) ( R/ 32) Peripheral secure status locked - Bridge C -------- */
#define PAC_SECLOCKC_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_SECLOCKC) Peripheral secure status locked - Bridge C  Reset Value */

#define PAC_SECLOCKC_EVSYS_Pos                _UINT32_(0)                                          /* (PAC_SECLOCKC) EVSYS Secure Status Locked Position */
#define PAC_SECLOCKC_EVSYS_Msk                (_UINT32_(0x1) << PAC_SECLOCKC_EVSYS_Pos)            /* (PAC_SECLOCKC) EVSYS Secure Status Locked Mask */
#define PAC_SECLOCKC_EVSYS(value)             (PAC_SECLOCKC_EVSYS_Msk & (_UINT32_(value) << PAC_SECLOCKC_EVSYS_Pos)) /* Assigment of value for EVSYS in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_SERCOM0_Pos              _UINT32_(1)                                          /* (PAC_SECLOCKC) SERCOM0 Secure Status Locked Position */
#define PAC_SECLOCKC_SERCOM0_Msk              (_UINT32_(0x1) << PAC_SECLOCKC_SERCOM0_Pos)          /* (PAC_SECLOCKC) SERCOM0 Secure Status Locked Mask */
#define PAC_SECLOCKC_SERCOM0(value)           (PAC_SECLOCKC_SERCOM0_Msk & (_UINT32_(value) << PAC_SECLOCKC_SERCOM0_Pos)) /* Assigment of value for SERCOM0 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_SERCOM1_Pos              _UINT32_(2)                                          /* (PAC_SECLOCKC) SERCOM1 Secure Status Locked Position */
#define PAC_SECLOCKC_SERCOM1_Msk              (_UINT32_(0x1) << PAC_SECLOCKC_SERCOM1_Pos)          /* (PAC_SECLOCKC) SERCOM1 Secure Status Locked Mask */
#define PAC_SECLOCKC_SERCOM1(value)           (PAC_SECLOCKC_SERCOM1_Msk & (_UINT32_(value) << PAC_SECLOCKC_SERCOM1_Pos)) /* Assigment of value for SERCOM1 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_SERCOM2_Pos              _UINT32_(3)                                          /* (PAC_SECLOCKC) SERCOM2 Secure Status Locked Position */
#define PAC_SECLOCKC_SERCOM2_Msk              (_UINT32_(0x1) << PAC_SECLOCKC_SERCOM2_Pos)          /* (PAC_SECLOCKC) SERCOM2 Secure Status Locked Mask */
#define PAC_SECLOCKC_SERCOM2(value)           (PAC_SECLOCKC_SERCOM2_Msk & (_UINT32_(value) << PAC_SECLOCKC_SERCOM2_Pos)) /* Assigment of value for SERCOM2 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_SERCOM3_Pos              _UINT32_(4)                                          /* (PAC_SECLOCKC) SERCOM3 Secure Status Locked Position */
#define PAC_SECLOCKC_SERCOM3_Msk              (_UINT32_(0x1) << PAC_SECLOCKC_SERCOM3_Pos)          /* (PAC_SECLOCKC) SERCOM3 Secure Status Locked Mask */
#define PAC_SECLOCKC_SERCOM3(value)           (PAC_SECLOCKC_SERCOM3_Msk & (_UINT32_(value) << PAC_SECLOCKC_SERCOM3_Pos)) /* Assigment of value for SERCOM3 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_SERCOM4_Pos              _UINT32_(5)                                          /* (PAC_SECLOCKC) SERCOM4 Secure Status Locked Position */
#define PAC_SECLOCKC_SERCOM4_Msk              (_UINT32_(0x1) << PAC_SECLOCKC_SERCOM4_Pos)          /* (PAC_SECLOCKC) SERCOM4 Secure Status Locked Mask */
#define PAC_SECLOCKC_SERCOM4(value)           (PAC_SECLOCKC_SERCOM4_Msk & (_UINT32_(value) << PAC_SECLOCKC_SERCOM4_Pos)) /* Assigment of value for SERCOM4 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_SERCOM5_Pos              _UINT32_(6)                                          /* (PAC_SECLOCKC) SERCOM5 Secure Status Locked Position */
#define PAC_SECLOCKC_SERCOM5_Msk              (_UINT32_(0x1) << PAC_SECLOCKC_SERCOM5_Pos)          /* (PAC_SECLOCKC) SERCOM5 Secure Status Locked Mask */
#define PAC_SECLOCKC_SERCOM5(value)           (PAC_SECLOCKC_SERCOM5_Msk & (_UINT32_(value) << PAC_SECLOCKC_SERCOM5_Pos)) /* Assigment of value for SERCOM5 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_TC0_Pos                  _UINT32_(7)                                          /* (PAC_SECLOCKC) TC0 Secure Status Locked Position */
#define PAC_SECLOCKC_TC0_Msk                  (_UINT32_(0x1) << PAC_SECLOCKC_TC0_Pos)              /* (PAC_SECLOCKC) TC0 Secure Status Locked Mask */
#define PAC_SECLOCKC_TC0(value)               (PAC_SECLOCKC_TC0_Msk & (_UINT32_(value) << PAC_SECLOCKC_TC0_Pos)) /* Assigment of value for TC0 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_TC1_Pos                  _UINT32_(8)                                          /* (PAC_SECLOCKC) TC1 Secure Status Locked Position */
#define PAC_SECLOCKC_TC1_Msk                  (_UINT32_(0x1) << PAC_SECLOCKC_TC1_Pos)              /* (PAC_SECLOCKC) TC1 Secure Status Locked Mask */
#define PAC_SECLOCKC_TC1(value)               (PAC_SECLOCKC_TC1_Msk & (_UINT32_(value) << PAC_SECLOCKC_TC1_Pos)) /* Assigment of value for TC1 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_TC2_Pos                  _UINT32_(9)                                          /* (PAC_SECLOCKC) TC2 Secure Status Locked Position */
#define PAC_SECLOCKC_TC2_Msk                  (_UINT32_(0x1) << PAC_SECLOCKC_TC2_Pos)              /* (PAC_SECLOCKC) TC2 Secure Status Locked Mask */
#define PAC_SECLOCKC_TC2(value)               (PAC_SECLOCKC_TC2_Msk & (_UINT32_(value) << PAC_SECLOCKC_TC2_Pos)) /* Assigment of value for TC2 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_TCC0_Pos                 _UINT32_(10)                                         /* (PAC_SECLOCKC) TCC0 Secure Status Locked Position */
#define PAC_SECLOCKC_TCC0_Msk                 (_UINT32_(0x1) << PAC_SECLOCKC_TCC0_Pos)             /* (PAC_SECLOCKC) TCC0 Secure Status Locked Mask */
#define PAC_SECLOCKC_TCC0(value)              (PAC_SECLOCKC_TCC0_Msk & (_UINT32_(value) << PAC_SECLOCKC_TCC0_Pos)) /* Assigment of value for TCC0 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_TCC1_Pos                 _UINT32_(11)                                         /* (PAC_SECLOCKC) TCC1 Secure Status Locked Position */
#define PAC_SECLOCKC_TCC1_Msk                 (_UINT32_(0x1) << PAC_SECLOCKC_TCC1_Pos)             /* (PAC_SECLOCKC) TCC1 Secure Status Locked Mask */
#define PAC_SECLOCKC_TCC1(value)              (PAC_SECLOCKC_TCC1_Msk & (_UINT32_(value) << PAC_SECLOCKC_TCC1_Pos)) /* Assigment of value for TCC1 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_TCC2_Pos                 _UINT32_(12)                                         /* (PAC_SECLOCKC) TCC2 Secure Status Locked Position */
#define PAC_SECLOCKC_TCC2_Msk                 (_UINT32_(0x1) << PAC_SECLOCKC_TCC2_Pos)             /* (PAC_SECLOCKC) TCC2 Secure Status Locked Mask */
#define PAC_SECLOCKC_TCC2(value)              (PAC_SECLOCKC_TCC2_Msk & (_UINT32_(value) << PAC_SECLOCKC_TCC2_Pos)) /* Assigment of value for TCC2 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_TCC3_Pos                 _UINT32_(13)                                         /* (PAC_SECLOCKC) TCC3 Secure Status Locked Position */
#define PAC_SECLOCKC_TCC3_Msk                 (_UINT32_(0x1) << PAC_SECLOCKC_TCC3_Pos)             /* (PAC_SECLOCKC) TCC3 Secure Status Locked Mask */
#define PAC_SECLOCKC_TCC3(value)              (PAC_SECLOCKC_TCC3_Msk & (_UINT32_(value) << PAC_SECLOCKC_TCC3_Pos)) /* Assigment of value for TCC3 in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_ADC_Pos                  _UINT32_(14)                                         /* (PAC_SECLOCKC) ADC Secure Status Locked Position */
#define PAC_SECLOCKC_ADC_Msk                  (_UINT32_(0x1) << PAC_SECLOCKC_ADC_Pos)              /* (PAC_SECLOCKC) ADC Secure Status Locked Mask */
#define PAC_SECLOCKC_ADC(value)               (PAC_SECLOCKC_ADC_Msk & (_UINT32_(value) << PAC_SECLOCKC_ADC_Pos)) /* Assigment of value for ADC in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_DAC_Pos                  _UINT32_(15)                                         /* (PAC_SECLOCKC) DAC Secure Status Locked Position */
#define PAC_SECLOCKC_DAC_Msk                  (_UINT32_(0x1) << PAC_SECLOCKC_DAC_Pos)              /* (PAC_SECLOCKC) DAC Secure Status Locked Mask */
#define PAC_SECLOCKC_DAC(value)               (PAC_SECLOCKC_DAC_Msk & (_UINT32_(value) << PAC_SECLOCKC_DAC_Pos)) /* Assigment of value for DAC in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_PTC_Pos                  _UINT32_(16)                                         /* (PAC_SECLOCKC) PTC Secure Status Locked Position */
#define PAC_SECLOCKC_PTC_Msk                  (_UINT32_(0x1) << PAC_SECLOCKC_PTC_Pos)              /* (PAC_SECLOCKC) PTC Secure Status Locked Mask */
#define PAC_SECLOCKC_PTC(value)               (PAC_SECLOCKC_PTC_Msk & (_UINT32_(value) << PAC_SECLOCKC_PTC_Pos)) /* Assigment of value for PTC in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_TRNG_Pos                 _UINT32_(17)                                         /* (PAC_SECLOCKC) TRNG Secure Status Locked Position */
#define PAC_SECLOCKC_TRNG_Msk                 (_UINT32_(0x1) << PAC_SECLOCKC_TRNG_Pos)             /* (PAC_SECLOCKC) TRNG Secure Status Locked Mask */
#define PAC_SECLOCKC_TRNG(value)              (PAC_SECLOCKC_TRNG_Msk & (_UINT32_(value) << PAC_SECLOCKC_TRNG_Pos)) /* Assigment of value for TRNG in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_CCL_Pos                  _UINT32_(18)                                         /* (PAC_SECLOCKC) CCL Secure Status Locked Position */
#define PAC_SECLOCKC_CCL_Msk                  (_UINT32_(0x1) << PAC_SECLOCKC_CCL_Pos)              /* (PAC_SECLOCKC) CCL Secure Status Locked Mask */
#define PAC_SECLOCKC_CCL(value)               (PAC_SECLOCKC_CCL_Msk & (_UINT32_(value) << PAC_SECLOCKC_CCL_Pos)) /* Assigment of value for CCL in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_I2S_Pos                  _UINT32_(19)                                         /* (PAC_SECLOCKC) I2S Secure Status Locked Position */
#define PAC_SECLOCKC_I2S_Msk                  (_UINT32_(0x1) << PAC_SECLOCKC_I2S_Pos)              /* (PAC_SECLOCKC) I2S Secure Status Locked Mask */
#define PAC_SECLOCKC_I2S(value)               (PAC_SECLOCKC_I2S_Msk & (_UINT32_(value) << PAC_SECLOCKC_I2S_Pos)) /* Assigment of value for I2S in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_OPAMP_Pos                _UINT32_(20)                                         /* (PAC_SECLOCKC) OPAMP Secure Status Locked Position */
#define PAC_SECLOCKC_OPAMP_Msk                (_UINT32_(0x1) << PAC_SECLOCKC_OPAMP_Pos)            /* (PAC_SECLOCKC) OPAMP Secure Status Locked Mask */
#define PAC_SECLOCKC_OPAMP(value)             (PAC_SECLOCKC_OPAMP_Msk & (_UINT32_(value) << PAC_SECLOCKC_OPAMP_Pos)) /* Assigment of value for OPAMP in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_TRAM_Pos                 _UINT32_(21)                                         /* (PAC_SECLOCKC) TRAM Secure Status Locked Position */
#define PAC_SECLOCKC_TRAM_Msk                 (_UINT32_(0x1) << PAC_SECLOCKC_TRAM_Pos)             /* (PAC_SECLOCKC) TRAM Secure Status Locked Mask */
#define PAC_SECLOCKC_TRAM(value)              (PAC_SECLOCKC_TRAM_Msk & (_UINT32_(value) << PAC_SECLOCKC_TRAM_Pos)) /* Assigment of value for TRAM in the PAC_SECLOCKC register */
#define PAC_SECLOCKC_Msk                      _UINT32_(0x003FFFFF)                                 /* (PAC_SECLOCKC) Register Mask  */

#define PAC_SECLOCKC_SERCOM_Pos               _UINT32_(1)                                          /* (PAC_SECLOCKC Position) SERCOMx Secure Status Locked */
#define PAC_SECLOCKC_SERCOM_Msk               (_UINT32_(0x3F) << PAC_SECLOCKC_SERCOM_Pos)          /* (PAC_SECLOCKC Mask) SERCOM */
#define PAC_SECLOCKC_SERCOM(value)            (PAC_SECLOCKC_SERCOM_Msk & (_UINT32_(value) << PAC_SECLOCKC_SERCOM_Pos)) 
#define PAC_SECLOCKC_TC_Pos                   _UINT32_(7)                                          /* (PAC_SECLOCKC Position) TCx Secure Status Locked */
#define PAC_SECLOCKC_TC_Msk                   (_UINT32_(0x7) << PAC_SECLOCKC_TC_Pos)               /* (PAC_SECLOCKC Mask) TC */
#define PAC_SECLOCKC_TC(value)                (PAC_SECLOCKC_TC_Msk & (_UINT32_(value) << PAC_SECLOCKC_TC_Pos)) 
#define PAC_SECLOCKC_TCC_Pos                  _UINT32_(10)                                         /* (PAC_SECLOCKC Position) TCCx Secure Status Locked */
#define PAC_SECLOCKC_TCC_Msk                  (_UINT32_(0xF) << PAC_SECLOCKC_TCC_Pos)              /* (PAC_SECLOCKC Mask) TCC */
#define PAC_SECLOCKC_TCC(value)               (PAC_SECLOCKC_TCC_Msk & (_UINT32_(value) << PAC_SECLOCKC_TCC_Pos)) 

/** \brief PAC register offsets definitions */
#define PAC_WRCTRL_REG_OFST            _UINT32_(0x00)      /* (PAC_WRCTRL) Write control Offset */
#define PAC_EVCTRL_REG_OFST            _UINT32_(0x04)      /* (PAC_EVCTRL) Event control Offset */
#define PAC_INTENCLR_REG_OFST          _UINT32_(0x08)      /* (PAC_INTENCLR) Interrupt enable clear Offset */
#define PAC_INTENSET_REG_OFST          _UINT32_(0x09)      /* (PAC_INTENSET) Interrupt enable set Offset */
#define PAC_INTFLAGAHB_REG_OFST        _UINT32_(0x10)      /* (PAC_INTFLAGAHB) Bridge interrupt flag status Offset */
#define PAC_INTFLAGA_REG_OFST          _UINT32_(0x14)      /* (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A Offset */
#define PAC_INTFLAGB_REG_OFST          _UINT32_(0x18)      /* (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B Offset */
#define PAC_INTFLAGC_REG_OFST          _UINT32_(0x1C)      /* (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C Offset */
#define PAC_STATUSA_REG_OFST           _UINT32_(0x34)      /* (PAC_STATUSA) Peripheral write protection status - Bridge A Offset */
#define PAC_STATUSB_REG_OFST           _UINT32_(0x38)      /* (PAC_STATUSB) Peripheral write protection status - Bridge B Offset */
#define PAC_STATUSC_REG_OFST           _UINT32_(0x3C)      /* (PAC_STATUSC) Peripheral write protection status - Bridge C Offset */
#define PAC_NONSECA_REG_OFST           _UINT32_(0x54)      /* (PAC_NONSECA) Peripheral non-secure status - Bridge A Offset */
#define PAC_NONSECB_REG_OFST           _UINT32_(0x58)      /* (PAC_NONSECB) Peripheral non-secure status - Bridge B Offset */
#define PAC_NONSECC_REG_OFST           _UINT32_(0x5C)      /* (PAC_NONSECC) Peripheral non-secure status - Bridge C Offset */
#define PAC_SECLOCKA_REG_OFST          _UINT32_(0x74)      /* (PAC_SECLOCKA) Peripheral secure status locked - Bridge A Offset */
#define PAC_SECLOCKB_REG_OFST          _UINT32_(0x78)      /* (PAC_SECLOCKB) Peripheral secure status locked - Bridge B Offset */
#define PAC_SECLOCKC_REG_OFST          _UINT32_(0x7C)      /* (PAC_SECLOCKC) Peripheral secure status locked - Bridge C Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PAC register API structure */
typedef struct
{  /* Peripheral Access Controller */
  __IO  uint32_t                       PAC_WRCTRL;         /**< Offset: 0x00 (R/W  32) Write control */
  __IO  uint8_t                        PAC_EVCTRL;         /**< Offset: 0x04 (R/W  8) Event control */
  __I   uint8_t                        Reserved1[0x03];
  __IO  uint8_t                        PAC_INTENCLR;       /**< Offset: 0x08 (R/W  8) Interrupt enable clear */
  __IO  uint8_t                        PAC_INTENSET;       /**< Offset: 0x09 (R/W  8) Interrupt enable set */
  __I   uint8_t                        Reserved2[0x06];
  __IO  uint32_t                       PAC_INTFLAGAHB;     /**< Offset: 0x10 (R/W  32) Bridge interrupt flag status */
  __IO  uint32_t                       PAC_INTFLAGA;       /**< Offset: 0x14 (R/W  32) Peripheral interrupt flag status - Bridge A */
  __IO  uint32_t                       PAC_INTFLAGB;       /**< Offset: 0x18 (R/W  32) Peripheral interrupt flag status - Bridge B */
  __IO  uint32_t                       PAC_INTFLAGC;       /**< Offset: 0x1C (R/W  32) Peripheral interrupt flag status - Bridge C */
  __I   uint8_t                        Reserved3[0x14];
  __I   uint32_t                       PAC_STATUSA;        /**< Offset: 0x34 (R/   32) Peripheral write protection status - Bridge A */
  __I   uint32_t                       PAC_STATUSB;        /**< Offset: 0x38 (R/   32) Peripheral write protection status - Bridge B */
  __I   uint32_t                       PAC_STATUSC;        /**< Offset: 0x3C (R/   32) Peripheral write protection status - Bridge C */
  __I   uint8_t                        Reserved4[0x14];
  __I   uint32_t                       PAC_NONSECA;        /**< Offset: 0x54 (R/   32) Peripheral non-secure status - Bridge A */
  __I   uint32_t                       PAC_NONSECB;        /**< Offset: 0x58 (R/   32) Peripheral non-secure status - Bridge B */
  __I   uint32_t                       PAC_NONSECC;        /**< Offset: 0x5C (R/   32) Peripheral non-secure status - Bridge C */
  __I   uint8_t                        Reserved5[0x14];
  __I   uint32_t                       PAC_SECLOCKA;       /**< Offset: 0x74 (R/   32) Peripheral secure status locked - Bridge A */
  __I   uint32_t                       PAC_SECLOCKB;       /**< Offset: 0x78 (R/   32) Peripheral secure status locked - Bridge B */
  __I   uint32_t                       PAC_SECLOCKC;       /**< Offset: 0x7C (R/   32) Peripheral secure status locked - Bridge C */
} pac_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMLS60_PAC_COMPONENT_H_ */
