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
/**********************************************************************************************************************
* File Name    : r_sci_rx_dtc.c
* Description  : 
***********************************************************************************************************************
* History : DD.MM.YYYY Version Description
*           25.08.2020 1.00    Initial Release
*           31.03.2022 4.40    Fixed the issue with DTC mode which incorrectly uses the same transfer information 
*                              for all channels.
***********************************************************************************************************************/

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "platform.h"
#include "r_sci_rx_private.h"
#include "r_sci_rx_if.h"
#if ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01))
#include <stdlib.h>
#include "r_dtc_rx_if.h"
#include "r_sci_rx_dtc.h"
#include "r_sci_rx_platform.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
#define SCI_PRV_RX_FIFO_THRESHOLD   (hdl->rom->regs->FCR.BIT.RTRG)
#define SCI_PRV_TX_FIFO_THRESHOLD   (hdl->rom->regs->FCR.BIT.TTRG)

/**********************************************************************************************************************
 Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/
dtc_cmd_arg_t           tx_args_dtc;
dtc_transfer_data_cfg_t tx_cfg_dtc;
dtc_cmd_arg_t           rx_args_dtc;
dtc_transfer_data_cfg_t rx_cfg_dtc;
sci_dtc_info_transfer_t *gp_dtc_info_head = NULL;

/**********************************************************************************************************************
 Private (static) variables and functions
 *********************************************************************************************************************/
sci_err_t sci_dtc_info_transfer_create(sci_hdl_t const hdl, sci_dtc_info_transfer_t **p_info_transfer);
static uint8_t tx_dummy_buf = SCI_CFG_DUMMY_TX_BYTE;
static uint8_t rx_dummy_buf = 0;

#if (SCI_CFG_FIFO_INCLUDED)
/**********************************************************************************************************************
* Function Name: sci_txfifo_dtc_create
* Description  : This function create DTC to transmit data from p_src to SCI TX FIFO (by DTC without CPU)
* Arguments    : hdl -
*                    handle for channel (ptr to chan control block)
*                p_src -
*                    The address of source data need to be sent
*                lenght -
*                    The number of data need to be sent
* Return Value : SCI_SUCCESS -
*                    Create DTC successfully
*                SCI_ERR_DTC -
*                    Create DTC NOT successfully
 *********************************************************************************************************************/
sci_err_t sci_txfifo_dtc_create(sci_hdl_t const hdl, uint8_t *p_src, uint16_t const length)
{
    sci_fifo_ctrl_t        *p_tctrl;
    sci_err_t err_sci = SCI_SUCCESS;
    dtc_err_t  err_dtc = DTC_SUCCESS;
    sci_dtc_info_transfer_t *p_info_transfer = NULL;

    p_tctrl = &hdl->queue[hdl->qindex_app_tx];

    tx_args_dtc.act_src               = hdl->rom->dtc_tx_act_src;
    tx_args_dtc.chain_transfer_nr     = 0;
    tx_args_dtc.p_data_cfg            = &tx_cfg_dtc;

    err_sci = sci_dtc_info_transfer_create(hdl, &p_info_transfer);
    if(SCI_SUCCESS != err_sci)
    {
        return err_sci;
    }
    tx_args_dtc.p_transfer_data = &p_info_transfer->tx_info_dtc;

    tx_cfg_dtc.transfer_mode          = DTC_TRANSFER_MODE_BLOCK;
    tx_cfg_dtc.data_size              = DTC_DATA_SIZE_BYTE;
    tx_cfg_dtc.chain_transfer_enable  = DTC_CHAIN_TRANSFER_DISABLE;
    tx_cfg_dtc.response_interrupt     = DTC_INTERRUPT_AFTER_ALL_COMPLETE;
    tx_cfg_dtc.dest_addr_mode         = DTC_DES_ADDR_FIXED;
    tx_cfg_dtc.dest_addr              = (uint32_t)&hdl->rom->regs->FTDR.BYTE.L;

    if (NULL == p_src)
    {
        tx_cfg_dtc.repeat_block_side = DTC_REPEAT_BLOCK_SOURCE;
        tx_cfg_dtc.src_addr_mode     = DTC_SRC_ADDR_FIXED;
        tx_cfg_dtc.source_addr       = (uint32_t)&tx_dummy_buf;
    }
    else
    {
        tx_cfg_dtc.repeat_block_side = DTC_REPEAT_BLOCK_DESTINATION;
        tx_cfg_dtc.src_addr_mode     = DTC_SRC_ADDR_INCR;
        tx_cfg_dtc.source_addr       = (uint32_t)p_src;
    }

    tx_cfg_dtc.transfer_count = (uint32_t)(length / hdl->rom->dtc_dmaca_tx_block_size);
    tx_cfg_dtc.block_size     = hdl->rom->dtc_dmaca_tx_block_size;

    if (length >= tx_cfg_dtc.block_size)
    {
        if (NULL == p_src)
        {
            p_tctrl->p_tx_fraction_buf = NULL;
        }
        else
        {
            p_tctrl->p_tx_fraction_buf = (uint8_t*)(tx_cfg_dtc.source_addr + (tx_cfg_dtc.transfer_count * tx_cfg_dtc.block_size));
        }

        p_tctrl->tx_fraction = (length - (tx_cfg_dtc.transfer_count * tx_cfg_dtc.block_size));

        err_dtc = R_DTC_Create(tx_args_dtc.act_src, &p_info_transfer->tx_info_dtc, &tx_cfg_dtc, 0);
        if (DTC_SUCCESS == err_dtc)
        {
            err_dtc = R_DTC_Control(DTC_CMD_ACT_SRC_ENABLE, NULL, &tx_args_dtc);
        }
        if (DTC_SUCCESS == err_dtc)
        {
            R_DTC_Control(DTC_CMD_DTC_START, NULL, NULL);
        }
    }
    else
    {
        p_tctrl->p_tx_fraction_buf = p_src;
        p_tctrl->tx_fraction = length;

        err_dtc = R_DTC_Control(DTC_CMD_ACT_SRC_DISABLE, NULL, &tx_args_dtc);
    }

    if (DTC_SUCCESS != err_dtc)
    {
        err_sci = SCI_ERR_DTC;
    }

    return err_sci;
}
/**********************************************************************************************************************
 End of function sci_txfifo_dtc_create
 *********************************************************************************************************************/
#endif

#if (SCI_CFG_FIFO_INCLUDED)
/**********************************************************************************************************************
* Function Name: sci_rxfifo_dtc_create
* Description  : This function create DTC to receive data from SCI RX FIFO (by DTC without CPU)
* Arguments    : hdl -
*                    handle for channel (ptr to chan control block)
*                p_dst -
*                    The address of destination need to be saved
*                lenght -
*                    The number of data need to be saved
* Return Value : SCI_SUCCESS -
*                    Create DTC successfully
*                SCI_ERR_DTC -
*                    Create DTC NOT successfully
 *********************************************************************************************************************/
sci_err_t sci_rxfifo_dtc_create(sci_hdl_t const hdl, uint8_t *p_dst, uint16_t const length)
{
    sci_fifo_ctrl_t        *p_rctrl;
    sci_err_t err_sci = SCI_SUCCESS;
    dtc_err_t  err_dtc = DTC_SUCCESS;
    sci_dtc_info_transfer_t *p_info_transfer = NULL;

    p_rctrl = &hdl->queue[hdl->qindex_app_rx];

    rx_args_dtc.act_src               = hdl->rom->dtc_rx_act_src;
    rx_args_dtc.chain_transfer_nr     = 0;
    rx_args_dtc.p_data_cfg            = &rx_cfg_dtc;

    err_sci = sci_dtc_info_transfer_create(hdl, &p_info_transfer);
    if(SCI_SUCCESS != err_sci)
    {
        return err_sci;
    }
    rx_args_dtc.p_transfer_data = &p_info_transfer->rx_info_dtc;

    rx_cfg_dtc.transfer_mode          = DTC_TRANSFER_MODE_BLOCK;
    rx_cfg_dtc.data_size              = DTC_DATA_SIZE_BYTE;
    rx_cfg_dtc.src_addr_mode          = DTC_SRC_ADDR_FIXED;
    rx_cfg_dtc.chain_transfer_enable  = DTC_CHAIN_TRANSFER_DISABLE;
    rx_cfg_dtc.response_interrupt     = DTC_INTERRUPT_AFTER_ALL_COMPLETE;
    rx_cfg_dtc.source_addr            = (uint32_t)&hdl->rom->regs->FRDR.BYTE.L;

    if (NULL == p_dst)
    {
        rx_cfg_dtc.repeat_block_side = DTC_REPEAT_BLOCK_DESTINATION;
        rx_cfg_dtc.dest_addr_mode    = DTC_DES_ADDR_FIXED;
        rx_cfg_dtc.dest_addr         = (uint32_t)&rx_dummy_buf;
    }
    else
    {
        rx_cfg_dtc.repeat_block_side = DTC_REPEAT_BLOCK_SOURCE;
        rx_cfg_dtc.dest_addr_mode    = DTC_DES_ADDR_INCR;
        rx_cfg_dtc.dest_addr         = (uint32_t)p_dst;
    }

    rx_cfg_dtc.transfer_count = (uint32_t)(length / hdl->rom->dtc_dmaca_rx_block_size);
    rx_cfg_dtc.block_size     = hdl->rom->dtc_dmaca_rx_block_size;

    if (length >= hdl->rx_dflt_thresh)
    {
        if (NULL == p_dst)
        {
            p_rctrl->p_rx_fraction_buf = NULL;
        }
        else
        {
            p_rctrl->p_rx_fraction_buf = (uint8_t*)(rx_cfg_dtc.dest_addr + (rx_cfg_dtc.transfer_count * rx_cfg_dtc.block_size));
        }

        p_rctrl->rx_fraction = (length - (rx_cfg_dtc.transfer_count * rx_cfg_dtc.block_size));
        SCI_PRV_RX_FIFO_THRESHOLD = hdl->rx_dflt_thresh;

        err_dtc = R_DTC_Create(rx_args_dtc.act_src, &p_info_transfer->rx_info_dtc, &rx_cfg_dtc, 0);
        if (DTC_SUCCESS == err_dtc)
        {
            err_dtc = R_DTC_Control(DTC_CMD_ACT_SRC_ENABLE, NULL, &rx_args_dtc);
        }
        if (DTC_SUCCESS == err_dtc)
        {
            R_DTC_Control(DTC_CMD_DTC_START, NULL, NULL);
        }
    }
    else
    {
        p_rctrl->p_rx_fraction_buf = p_dst;
        p_rctrl->rx_fraction = length;

        SCI_PRV_RX_FIFO_THRESHOLD = p_rctrl->rx_fraction;
        err_dtc = R_DTC_Control(DTC_CMD_ACT_SRC_DISABLE, NULL, &rx_args_dtc);
    }

    if (DTC_SUCCESS != err_dtc)
    {
        err_sci = SCI_ERR_DTC;
    }

    return err_sci;
}
/**********************************************************************************************************************
 End of function sci_rxfifo_dtc_create
 *********************************************************************************************************************/
#endif

/**********************************************************************************************************************
* Function Name: sci_rx_dtc_create
* Description  : This function create DTC to receive data from RDR (by DTC without CPU)
* Arguments    : hdl -
*                    handle for channel (ptr to chan control block)
*                p_dst -
*                    The address of destination need to be saved
*                lenght -
*                    The number of data need to be saved
* Return Value : SCI_SUCCESS -
*                    Create DTC successfully
*                SCI_ERR_DTC -
*                    Create DTC NOT successfully
 *********************************************************************************************************************/
sci_err_t sci_rx_dtc_create(sci_hdl_t const hdl, uint8_t *p_dst, uint16_t const length)
{
    sci_fifo_ctrl_t        *p_rctrl;
    sci_err_t err_sci = SCI_SUCCESS;
    dtc_err_t  err_dtc = DTC_SUCCESS;
    sci_dtc_info_transfer_t *p_info_transfer = NULL;

    p_rctrl = &hdl->queue[hdl->qindex_app_rx];

    rx_args_dtc.act_src               = hdl->rom->dtc_rx_act_src;
    rx_args_dtc.chain_transfer_nr     = 0;
    rx_args_dtc.p_data_cfg            = &rx_cfg_dtc;

    err_sci = sci_dtc_info_transfer_create(hdl, &p_info_transfer);
    if(SCI_SUCCESS != err_sci)
    {
        return err_sci;
    }
    rx_args_dtc.p_transfer_data = &p_info_transfer->rx_info_dtc;


    rx_cfg_dtc.transfer_mode          = DTC_TRANSFER_MODE_NORMAL;
    rx_cfg_dtc.data_size              = DTC_DATA_SIZE_BYTE;
    rx_cfg_dtc.src_addr_mode          = DTC_SRC_ADDR_FIXED;
    rx_cfg_dtc.chain_transfer_enable  = DTC_CHAIN_TRANSFER_DISABLE;
    rx_cfg_dtc.response_interrupt     = DTC_INTERRUPT_AFTER_ALL_COMPLETE;
    rx_cfg_dtc.source_addr            = (uint32_t)&hdl->rom->regs->RDR;

    if (NULL == p_dst)
    {
        rx_cfg_dtc.dest_addr_mode    = DTC_DES_ADDR_FIXED;
        rx_cfg_dtc.dest_addr         = (uint32_t)&rx_dummy_buf;
    }
    else
    {
        rx_cfg_dtc.dest_addr_mode    = DTC_DES_ADDR_INCR;
        rx_cfg_dtc.dest_addr         = (uint32_t)p_dst;
    }

    rx_cfg_dtc.transfer_count = (uint32_t)(length);

    if (0 < length)
    {
        if (NULL == p_dst)
        {
            p_rctrl->p_rx_fraction_buf = NULL;
        }
        else
        {
            p_rctrl->p_rx_fraction_buf = (uint8_t*)rx_cfg_dtc.dest_addr;
        }

        p_rctrl->rx_fraction = 0;

        err_dtc = R_DTC_Create(rx_args_dtc.act_src, &p_info_transfer->rx_info_dtc, &rx_cfg_dtc, 0);
        if (DTC_SUCCESS == err_dtc)
        {
            err_dtc = R_DTC_Control(DTC_CMD_ACT_SRC_ENABLE, NULL, &rx_args_dtc);
        }
        if (DTC_SUCCESS == err_dtc)
        {
            R_DTC_Control(DTC_CMD_DTC_START, NULL, NULL);
        }
    }
    else
    {
        err_dtc = R_DTC_Control(DTC_CMD_ACT_SRC_DISABLE, NULL, &rx_args_dtc);
    }

    if (DTC_SUCCESS != err_dtc)
    {
        err_sci = SCI_ERR_DTC;
    }

    return err_sci;
}
/**********************************************************************************************************************
 End of function sci_rx_dtc_create
 *********************************************************************************************************************/

/**********************************************************************************************************************
* Function Name: sci_tx_dtc_create
* Description  : This function create DTC to transmit data from p_src to TDR (by DTC without CPU)
* Arguments    : hdl -
*                    handle for channel (ptr to chan control block)
*                p_src -
*                    The address of source data need to be sent
*                lenght -
*                    The number of data need to be sent
* Return Value : SCI_SUCCESS -
*                    Create DTC successfully
*                SCI_ERR_DTC -
*                    Create DTC NOT successfully
 *********************************************************************************************************************/
sci_err_t sci_tx_dtc_create(sci_hdl_t const hdl, uint8_t *p_src, uint16_t const length)
{
    sci_fifo_ctrl_t        *p_tctrl;
    sci_err_t err_sci = SCI_SUCCESS;
    dtc_err_t  err_dtc = DTC_SUCCESS;
    sci_dtc_info_transfer_t *p_info_transfer = NULL;

    p_tctrl = &hdl->queue[hdl->qindex_app_tx];

    tx_args_dtc.act_src               = hdl->rom->dtc_tx_act_src;
    tx_args_dtc.chain_transfer_nr     = 0;
    tx_args_dtc.p_data_cfg            = &tx_cfg_dtc;

    err_sci = sci_dtc_info_transfer_create(hdl, &p_info_transfer);
    if(SCI_SUCCESS != err_sci)
    {
        return err_sci;
    }
    tx_args_dtc.p_transfer_data = &p_info_transfer->tx_info_dtc;

    tx_cfg_dtc.transfer_mode          = DTC_TRANSFER_MODE_NORMAL;
    tx_cfg_dtc.data_size              = DTC_DATA_SIZE_BYTE;
    tx_cfg_dtc.chain_transfer_enable  = DTC_CHAIN_TRANSFER_DISABLE;
    tx_cfg_dtc.response_interrupt     = DTC_INTERRUPT_AFTER_ALL_COMPLETE;
    tx_cfg_dtc.dest_addr_mode         = DTC_DES_ADDR_FIXED;
    tx_cfg_dtc.dest_addr              = (uint32_t)&hdl->rom->regs->TDR;

    if (NULL == p_src)
    {
        tx_cfg_dtc.src_addr_mode     = DTC_SRC_ADDR_FIXED;
        tx_cfg_dtc.source_addr       = (uint32_t)&tx_dummy_buf;
    }
    else
    {
        tx_cfg_dtc.src_addr_mode     = DTC_SRC_ADDR_INCR;
        tx_cfg_dtc.source_addr       = (uint32_t)p_src;
    }

    tx_cfg_dtc.transfer_count = (uint32_t)(length);

    if (length > 0)
    {
        if (NULL == p_src)
        {
            p_tctrl->p_tx_fraction_buf = NULL;
        }
        else
        {
            p_tctrl->p_tx_fraction_buf = (uint8_t*)tx_cfg_dtc.source_addr;
        }

        p_tctrl->tx_fraction = 0;

        err_dtc = R_DTC_Create(tx_args_dtc.act_src, &p_info_transfer->tx_info_dtc, &tx_cfg_dtc, 0);
        if (DTC_SUCCESS == err_dtc)
        {
            err_dtc = R_DTC_Control(DTC_CMD_ACT_SRC_ENABLE, NULL, &tx_args_dtc);
        }
        if (DTC_SUCCESS == err_dtc)
        {
            R_DTC_Control(DTC_CMD_DTC_START, NULL, NULL);
        }
    }
    else
    {
        err_dtc = R_DTC_Control(DTC_CMD_ACT_SRC_DISABLE, NULL, &tx_args_dtc);
    }

    if (DTC_SUCCESS != err_dtc)
    {
        err_sci = SCI_ERR_DTC;
    }

    return err_sci;
}
/**********************************************************************************************************************
 End of function sci_tx_dtc_create
 *********************************************************************************************************************/

/**********************************************************************************************************************
* Function Name: sci_dtc_info_transfer_create
* Description  : This function creates a allocated memory for information transfer address for DTC transfer
* Arguments    : hdl -
*                    handle for channel (ptr to chan control block)
*                p_info_transfer -
*                    pointer to information transfer address of DTC
* Return Value : SCI_SUCCESS -
*                    Create allocated memory for information transfer address successfully
*                SCI_ERR_DTC -
*                    Create allocated memory for information transfer address NOT successfully
 *********************************************************************************************************************/
sci_err_t sci_dtc_info_transfer_create(sci_hdl_t const hdl, sci_dtc_info_transfer_t **p_info_transfer)
{
    sci_err_t err_sci = SCI_SUCCESS;
    sci_dtc_info_transfer_t **p_current_info = &gp_dtc_info_head;
    sci_dtc_info_transfer_t *p_new_info = NULL;
    uint8_t chan = hdl->rom->chan;

    /* Check allocated memory for start pointer */
    if(NULL == *p_current_info)
    {
        p_new_info = (sci_dtc_info_transfer_t *) malloc(sizeof(sci_dtc_info_transfer_t));
        if(NULL == p_new_info)
        {
            return SCI_ERR_DTC;
        }
        p_new_info->chan = chan;
        p_new_info->next = NULL;
        *p_current_info = p_new_info;
        *p_info_transfer = *p_current_info;
    }
    else /* Allocated memory */
    {
        /* Check allocated memory for current channel */
        while(NULL != *p_current_info)
        {
            if(chan == (*p_current_info)->chan)
            {
                *p_info_transfer = *p_current_info;
                return err_sci;
            }
            p_current_info = &((*p_current_info)->next);
        }

        /* Create new allocated memory for a channel */
        p_new_info = (sci_dtc_info_transfer_t *) malloc(sizeof(sci_dtc_info_transfer_t));
        if(NULL == p_new_info)
        {
            return SCI_ERR_DTC;
        }
        p_new_info->chan = chan;
        p_new_info->next = NULL;
        *p_current_info = p_new_info;
        *p_info_transfer = *p_current_info;
    }
    return err_sci;
}

/**********************************************************************************************************************
 End of function sci_dtc_info_transfer_create
 *********************************************************************************************************************/

/**********************************************************************************************************************
* Function Name: sci_dtc_info_transfer_delete
* Description  : This function deletes the allocated memory of information transfer address for the current channel
* Arguments    : hdl -
*                    handle for channel (ptr to chan control block)
* Return Value : None-
 *********************************************************************************************************************/
void sci_dtc_info_transfer_delete(sci_hdl_t const hdl)
{
    sci_dtc_info_transfer_t **p_current_info = &gp_dtc_info_head;
    sci_dtc_info_transfer_t *p_next_info = NULL;
    uint8_t chan = hdl->rom->chan;

    /* Check allocated memory for current channel */
    while(NULL != *p_current_info)
    {
        if(chan == (*p_current_info)->chan)
        {
            /* Store the next pointer of current list */
            p_next_info = (*p_current_info)->next;

            /*Destroy allocated memory for the current channel */
            free(*p_current_info);
            *p_current_info = NULL;

            /* Re-assign the position current list for the next list */
            *p_current_info = p_next_info;
            break;
        }
        p_current_info = &((*p_current_info)->next);
    }
}
/**********************************************************************************************************************
 End of function sci_dtc_info_transfer_delete
 *********************************************************************************************************************/

#endif /* ((TX_DTC_DMACA_ENABLE & 0x01) || (RX_DTC_DMACA_ENABLE & 0x01)) */
