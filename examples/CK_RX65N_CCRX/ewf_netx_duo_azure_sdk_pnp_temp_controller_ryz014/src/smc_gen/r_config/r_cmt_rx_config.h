/* Generated configuration header file - do not edit */
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
* File Name    : r_cmt_rx_config.h
* Description  : Configures the r_cmt_rx code.
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*         : 06.11.2013 2.00    First GSCE Release.
*         : 25.11.2019 4.30    Changed for FIT+RTOS
*         : 31.08.2020 4.70    Added condition for _RI_TRACE_TIMER macro
*                              Fixed warning when using RI600V4 with device has 2 CMT channels
*         : 27.12.2022 5.40    Updated macro definition enable and disable nested interrupt for CMT.
***********************************************************************************************************************/
#ifndef CMT_CONFIG_HEADER_FILE
#define CMT_CONFIG_HEADER_FILE

/***********************************************************************************************************************
Configuration Options
***********************************************************************************************************************/
/* The interrupt priority level to be used for CMT interrupts. */
#define CMT_RX_CFG_IPR         (5)

/* SPECIFY WHETHER TO INCLUDE CODE FOR NESTED INTERRUPT CMT CHANNEL 0 */
/* 1=included, 0=not */
#define CMT_CFG_CH0_EN_NESTED_INT    (0)

/* SPECIFY WHETHER TO INCLUDE CODE FOR NESTED INTERRUPT CMT CHANNEL 1 */
/* 1=included, 0=not */
#define CMT_CFG_CH1_EN_NESTED_INT    (0)

/* SPECIFY WHETHER TO INCLUDE CODE FOR NESTED INTERRUPT CMT CHANNEL 2 */
/* 1=included, 0=not */
#define CMT_CFG_CH2_EN_NESTED_INT    (0)

/* SPECIFY WHETHER TO INCLUDE CODE FOR NESTED INTERRUPT CMT CHANNEL 3 */
/* 1=included, 0=not */
#define CMT_CFG_CH3_EN_NESTED_INT    (0)

#if (BSP_CFG_RTOS_USED == 4) && (BSP_CFG_RENESAS_RTOS_USED == 0) /* RI600V4 */
#define _RI_TRACE_TIMER 1 /* RI600V4 uses CMT1 channel for the trace feature.*/
#elif (BSP_CFG_RTOS_USED == 4) && (BSP_CFG_RENESAS_RTOS_USED == 1) /* RI600PX */
#include "r_bsp_config.h"
#define _RI_TRACE_TIMER BSP_CFG_RTOS_SYSTEM_TIMER /* RI600PX does not actually have the trace feature.*/
#else
#define _RI_TRACE_TIMER 1 /* It’s guaranteed that definition _RI_TRACE_TIMER is never used unless BSP_CFG_RTOS_USED == 4.*/
#endif

#endif /* CMT_CONFIG_HEADER_FILE */


