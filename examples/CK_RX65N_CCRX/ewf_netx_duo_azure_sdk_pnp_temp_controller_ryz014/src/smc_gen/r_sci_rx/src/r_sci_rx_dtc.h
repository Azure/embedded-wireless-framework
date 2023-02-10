/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_sci_rx_dtc.h
* Description  : 
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*           25.08.2020 1.00    Initial Release
*           31.03.2022 4.40    Fixed the issue with DTC mode which incorrectly uses the same transfer information 
*                              for all channels.
***********************************************************************************************************************/
#ifndef SCI_RX_DTC_H
#define SCI_RX_DTC_H

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "platform.h"
#include "r_sci_rx_if.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Global Typedef definitions
 *********************************************************************************************************************/
typedef struct st_sci_dtc_info_transfer
{
    uint8_t chan;                            /* Channel SCI is used */
    dtc_transfer_data_t tx_info_dtc;         /* Transfer data address for TX */
    dtc_transfer_data_t rx_info_dtc;         /* Transfer data address for RX */
    struct st_sci_dtc_info_transfer * next;  /* Pointer used to link one node to the next node */
} sci_dtc_info_transfer_t;

/**********************************************************************************************************************
 External global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Exported global functions
 *********************************************************************************************************************/
sci_err_t sci_txfifo_dtc_create(sci_hdl_t const hdl, uint8_t *p_src, uint16_t const length);
sci_err_t sci_rxfifo_dtc_create(sci_hdl_t const hdl, uint8_t *p_dst, uint16_t const length);
sci_err_t sci_tx_dtc_create(sci_hdl_t const hdl, uint8_t *p_src, uint16_t const length);
sci_err_t sci_rx_dtc_create(sci_hdl_t const hdl, uint8_t *p_dst, uint16_t const length);
void sci_dtc_info_transfer_delete(sci_hdl_t const hdl);

#endif /* SCI_RX_DTC_H */