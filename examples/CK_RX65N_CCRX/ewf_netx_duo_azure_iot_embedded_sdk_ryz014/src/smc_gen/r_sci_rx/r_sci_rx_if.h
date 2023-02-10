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
* Copyright (C) 2013-2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_sci_rx_if.h
* Description  : Functions for using SCI on RX devices. 
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*           25.09.2013 1.00    Initial Release
*           17.04.2014 1.20    Bumped revision for RX110 support.
*           02.07.2014 1.30    Fixed bug that caused Group12 rx errors to only be enabled for channel 2.
*           25.11.2014 1.40    Added RX113 support
*           11.03.2015 1.40    Consolidated with r_sci_rx64m and added support for RX71M
*           11.05.2015 1.60    Added RX231 support
*           30.09.2015 1.70    Added RX23T support
*           01.10.2016 1.80    Added support for RX65N (comments and TX/RX FIFO THRESHOLD options)
*           19.12.2016 1.90    Added RX24U support
*                              SCI_CMD_EN_TEI was Changed to ineffective, because it is meaningless command.
*           07.03.2017 2.00    Fixed a bug that send/receive is incorrect when changed setting when FIFO enabled.
*                              Fixed a bug that callback function work many times at receive interrupt
*                               when FIFO(async) enabled.
*                              Fixed a bug that the interrupt priority level can be changed only in async mode.
*           31.10.2017 2.01    Added the demo for RX65N, RX65N-2M.
*           28.09.2018 2.10    Added support RX66T
*                              Added SCI_CMD_COMPARE_RECEIVED_DATA command
*                              Added SCI_EVT_RX_CHAR_MATCH for receiving data match event
*                              Fixed section layout follow GSCE 5.0
*           16.11.2018 2.11    Added XML document number
*           01.02.2019 2.20    Added support RX72T, RX65N-64pin
*           20.05.2019 3.00    Added support for GNUC and ICCRX.
*           28.06.2019 3.10    Added support RX23W
*           15.08.2019 3.20    Added support RX72M
*           16.09.2019 3.21    Fixed issue in RX631/RX63N sci_initialize_ints()
*           25.11.2019 3.30    Added support RX13T.
*           30.12.2019 3.40    Added support RX66N, RX72N.
*           31.03.2020 3.50    Added support RX23E-A.
*           25.08.2020 3.60    Added feature using DTC/DMAC in SCI transfer.
*                              Merged IrDA functionality to SCI FIT.
*           30.09.2020 3.70    Fixed issue of duplicate device group for SCI11 in MDF file.
*                              Fixed issue of missing SSCL, SSDA in MDF file.
*           31.03.2021 3.80    Added support for RX671.
*                              Added support circular buffer in mode asynchronous.
*           15.04.2021 3.90    Added support for RX140
*           16.08.2021 3.91    Updated Application Notes
*                              R_SCI_Send() function: Added notes to describe using TEI callback function.
*           13.09.2021 4.00    Added the demo for RX671.
*           15.11.2021 4.10    Added command SCI_CMD_SET_TXI_RXI_PRIORITY in R_SCI_Control()
*                              for changing TXI and RXI priority level simultaneously.
*                              Added support command SCI_CMD_SET_TXI_PRIORITY and SCI_CMD_SET_RXI_PRIORITY 
*                              in R_SCI_Control() for Series RX100 and RX200.
*           29.12.2021 4.20    Added support for RX140-256KB.
*           14.03.2022 4.30    Added support for RX66T-48Pin.
*           31.03.2022 4.40    Fixed the issue with DTC mode which incorrectly uses the same transfer information 
*                              for all channels.
*                              Fixed issue of consecutively calling R_SCI_Receive() function in using DTC/DMAC.
*                              Added support for RX660.
*           28.06.2022 4.50    Updated demo projects.
*           27.12.2022 4.60    Fixed the issue that rx_idle is not changed to true when reception is complete 
*                              in DMAC mode.
*                              Updated macro definition enable and disable nested interrupt for TXI, RXI, ERI, TEI.
***********************************************************************************************************************/

#ifndef SCI_IF_H
#define SCI_IF_H

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "platform.h"
#include "r_sci_rx_config.h"  /* SCI config definitions */
#include "r_byteq_config.h"
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

#if R_BSP_VERSION_MAJOR < 5
    #error "This module must use BSP module of Rev.5.00 or higher. Please use the BSP module of Rev.5.00 or higher."
#endif

#if (SCI_CFG_USE_CIRCULAR_BUFFER == 1)
#if (BYTEQ_CFG_PROTECT_QUEUE == 0)
    #error "Circular buffer must be protected."
#endif
#endif

/* Version Number of API. */
#define SCI_VERSION_MAJOR  (4)
#define SCI_VERSION_MINOR  (60)

#define SCI_DTC_DMACA_DISABLE  (0x0)
#define SCI_DTC_ENABLE         (0x1)
#define SCI_DMACA_ENABLE       (0x2)

#define TX_DTC_DMACA_ENABLE (SCI_CFG_CH8_TX_DTC_DMACA_ENABLE | SCI_CFG_CH9_TX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH10_TX_DTC_DMACA_ENABLE | SCI_CFG_CH11_TX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH1_TX_DTC_DMACA_ENABLE  | SCI_CFG_CH2_TX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH3_TX_DTC_DMACA_ENABLE  | SCI_CFG_CH4_TX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH5_TX_DTC_DMACA_ENABLE  | SCI_CFG_CH6_TX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH7_TX_DTC_DMACA_ENABLE  | SCI_CFG_CH12_TX_DTC_DMACA_ENABLE | SCI_CFG_CH0_TX_DTC_DMACA_ENABLE)
#define RX_DTC_DMACA_ENABLE (SCI_CFG_CH8_RX_DTC_DMACA_ENABLE | SCI_CFG_CH9_RX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH10_RX_DTC_DMACA_ENABLE | SCI_CFG_CH11_RX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH1_RX_DTC_DMACA_ENABLE  | SCI_CFG_CH2_RX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH3_RX_DTC_DMACA_ENABLE  | SCI_CFG_CH4_RX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH5_RX_DTC_DMACA_ENABLE  | SCI_CFG_CH6_RX_DTC_DMACA_ENABLE | \
                            SCI_CFG_CH7_RX_DTC_DMACA_ENABLE  | SCI_CFG_CH12_RX_DTC_DMACA_ENABLE | SCI_CFG_CH0_RX_DTC_DMACA_ENABLE)

#define SCI_CLK_INT         (0x00U) /* use internal clock for baud generation */
#define SCI_CLK_EXT8X       (0x03U) /* use external clock 8x baud rate (ASYNC) */
#define SCI_CLK_EXT16X      (0x02U) /* use external clock 16x baud rate (ASYNC) */
#define SCI_DATA_7BIT       (0x40U)
#define SCI_DATA_8BIT       (0x00U)
#define SCI_PARITY_ON       (0x20U)
#define SCI_PARITY_OFF      (0x00U)
#define SCI_ODD_PARITY      (0x10U)
#define SCI_EVEN_PARITY     (0x00U)
#define SCI_STOPBITS_2      (0x08U)
#define SCI_STOPBITS_1      (0x00U)

#if SCI_CFG_IRDA_INCLUDED
/* IrDA Output Pulse Width Select Data (do NOT change values) */
#define SCI_IRDA_OUT_WIDTH_3_16  (0x00U)
#define SCI_IRDA_OUT_WIDTH_2     (0x01U)
#define SCI_IRDA_OUT_WIDTH_4     (0x02U)
#define SCI_IRDA_OUT_WIDTH_8     (0x03U)
#define SCI_IRDA_OUT_WIDTH_16    (0x04U)
#define SCI_IRDA_OUT_WIDTH_32    (0x05U)
#define SCI_IRDA_OUT_WIDTH_64    (0x06U)
#define SCI_IRDA_OUT_WIDTH_128   (0x07U)
#endif

/*****************************************************************************
Typedef definitions
******************************************************************************/
typedef enum e_sci_ch       // SCI channel numbers
{
    SCI_CH0=0,
    SCI_CH1,
    SCI_CH2,
    SCI_CH3,
    SCI_CH4,
    SCI_CH5,
    SCI_CH6,
    SCI_CH7,
    SCI_CH8,
    SCI_CH9,
    SCI_CH10,
    SCI_CH11,
    SCI_CH12,
    SCI_NUM_CH
} sci_ch_t;


typedef enum e_sci_mode     // SCI operational modes
{
    SCI_MODE_OFF=0,         // channel not in use
    SCI_MODE_ASYNC,         // Asynchronous
    SCI_MODE_SSPI,          // Simple SPI
    SCI_MODE_SYNC,          // Synchronous
    SCI_MODE_IRDA,          // Infrared Data Association
    SCI_MODE_MAX            // End of modes currently supported
} sci_mode_t;


typedef enum e_sci_err      /* SCI API error codes */
{
    SCI_SUCCESS=0,
    SCI_ERR_BAD_CHAN,       // non-existent channel number
    SCI_ERR_OMITTED_CHAN,   // SCI_CHx_INCLUDED is 0 in config.h
    SCI_ERR_CH_NOT_CLOSED,  // chan still running in another mode
    SCI_ERR_BAD_MODE,       // unsupported or incorrect mode for channel
    SCI_ERR_INVALID_ARG,    // argument is not one of the predefined values
    SCI_ERR_NULL_PTR,       // received null ptr; missing required argument
    SCI_ERR_XCVR_BUSY,      // cannot start data transfer; transceiver busy

    /* Asynchronous/IrDA mode only */
    SCI_ERR_QUEUE_UNAVAILABLE,  // can't open tx or rx queue or both
    SCI_ERR_INSUFFICIENT_SPACE, // not enough space in transmit queue
    SCI_ERR_INSUFFICIENT_DATA,  // not enough data in receive queue

    /* Synchronous/SSPI modes only */
    SCI_ERR_XFER_NOT_DONE,   // data transfer still in progress
    
    /* DTC/DMAC error */
    SCI_ERR_DTC,
    SCI_ERR_DMACA,

    /* Not support when use DTC/DMAC */
    SCI_ERR_DTC_DMACA_NOT_SUPPORT 

} sci_err_t;


/* CHANNEL CONTROL BLOCK HANDLE */

typedef struct st_sci_ch_ctrl * sci_hdl_t;


/* SCI_OPEN() ARGUMENT DEFINITIONS (do NOT change values) */

typedef enum e_sci_spi_mode
{
    SCI_SPI_MODE_OFF = 1,   /* channel is in synchronous mode */

    SCI_SPI_MODE_0 = 0x80,  /* SPMR Register CKPH=1, CKPOL=0
                               Mode 0: 00 CPOL=0 resting lo, CPHA=0 leading edge/rising */
    SCI_SPI_MODE_1 = 0x40,  /* SPMR Register CKPH=0, CKPOL=1
                               Mode 1: 01 CPOL=0 resting lo, CPHA=1 trailing edge/falling */
    SCI_SPI_MODE_2 = 0xC0,  /* SPMR Register CKPH=1, CKPOL=1
                               Mode 2: 10 CPOL=1 resting hi, CPHA=0 leading edge/falling */
    SCI_SPI_MODE_3 = 0x00   /* SPMR Register CKPH=0, CKPOL=0
                               Mode 3: 11 CPOL=1 resting hi, CPHA=1 trailing edge/rising */
} sci_spi_mode_t;


/* Open() p_cfg structure when mode=SCI_MODE_ASYNC */
typedef struct st_sci_uart
{
    uint32_t    baud_rate;      // ie 9600, 19200, 115200
    uint8_t     clk_src;        // use SCI_CLK_INT/EXT8X/EXT16X
    uint8_t     data_size;      // use SCI_DATA_nBIT
    uint8_t     parity_en;      // use SCI_PARITY_ON/OFF
    uint8_t     parity_type;    // use SCI_ODD/EVEN_PARITY
    uint8_t     stop_bits;      // use SCI_STOPBITS_1/2
    uint8_t     int_priority;   // interrupt priority; 1=low, 15=high
} sci_uart_t;

/* Open() p_cfg structure when mode=SCI_MODE_IRDA */
typedef struct st_sci_irda
{
    uint32_t    baud_rate;      /* ie 9600, 19200, 115200                     */
    uint8_t     clk_out_width;  /* IrDA Output Pulse Width                    */
    uint8_t     int_priority;   /* txi, tei, rxi INT priority; 1=low, 15=high */
} sci_irda_t;


/* Open() p_cfg structure when mode = SCI_MODE_SYNC or SCI_MODE_SSPI */
typedef struct st_sci_sync_sspi
{
    sci_spi_mode_t  spi_mode;       // clock polarity and phase; unused for sync
    uint32_t        bit_rate;       // ie 1000000 for 1Mbps
    bool            msb_first;
    bool            invert_data;
    uint8_t         int_priority;   // interrupt priority; 1=low, 15=high
} sci_sync_sspi_t;

typedef union
{
    sci_uart_t      async;
    sci_sync_sspi_t sync;
    sci_sync_sspi_t sspi;
    sci_irda_t      irda;
} sci_cfg_t;


/* CALLBACK FUNCTION ARGUMENT DEFINITIONS */

typedef enum e_sci_cb_evt   // callback function events
{
    /* Async/Irda Events */
    SCI_EVT_TEI,            // TEI interrupt occurred; transmitter is idle
    SCI_EVT_RX_CHAR,        // received a character; already placed in queue
    SCI_EVT_RXBUF_OVFL,     // rx queue is full; can't save anymore data
    SCI_EVT_FRAMING_ERR,    // receiver hardware framing error

    /* Async Events */
    SCI_EVT_PARITY_ERR,     // receiver hardware parity error
    SCI_EVT_RX_CHAR_MATCH,  // received a matched character; already placed in queue

    /* SSPI/Sync Events */
    SCI_EVT_XFER_DONE,      // transfer completed
    SCI_EVT_XFER_ABORTED,   // transfer aborted

    /* Common Events */
    SCI_EVT_OVFL_ERR,        // receiver hardware overrun error

    /* Receive Sync Done */
    SCI_EVT_RX_SYNC_DONE,

    /* Receive Async Done */
    SCI_EVT_RX_DONE
} sci_cb_evt_t;

typedef struct st_sci_cb_args // callback arguments
{
    sci_hdl_t       hdl;
    sci_cb_evt_t    event;
    uint8_t         byte;   // byte read when error occurred (unused for TEI, XFER_DONE)
    uint8_t         num;    // Number of bytes were stored to queue (used only async(FIFO))
} sci_cb_args_t;


/* SCI_CONTROL() ARGUMENT DEFINITIONS */

/* commands */
typedef enum e_sci_cmd
{
    /* All modes */
    SCI_CMD_CHANGE_BAUD,              /* change baud/bit rate */
#if ((SCI_CFG_CH7_FIFO_INCLUDED) || (SCI_CFG_CH8_FIFO_INCLUDED) || (SCI_CFG_CH9_FIFO_INCLUDED)  || (SCI_CFG_CH10_FIFO_INCLUDED) || (SCI_CFG_CH11_FIFO_INCLUDED))
    SCI_CMD_CHANGE_TX_FIFO_THRESH,    /* change TX FIFO threshold */
    SCI_CMD_CHANGE_RX_FIFO_THRESH,    /* change RX FIFO threshold */
#endif
    SCI_CMD_SET_RXI_PRIORITY,         /* change RXI priority level */
    SCI_CMD_SET_TXI_PRIORITY,         /* change TXI priority level */
    SCI_CMD_SET_TXI_RXI_PRIORITY,     /* change TXI and RXI priority level simultaneously */
    /* Async commands */
    SCI_CMD_EN_NOISE_CANCEL,          /* enable noise cancellation */
    SCI_CMD_EN_TEI,                   /* SCI_CMD_EN_TEI is obsolete command,
                                         but it exists only for compatibility with older version. */
    SCI_CMD_OUTPUT_BAUD_CLK,          /* output baud clock on the SCK pin */
    SCI_CMD_START_BIT_EDGE,           /* detect start bit as falling edge of RXDn pin
                                         (default detect as low level on RXDn pin) */
    SCI_CMD_GENERATE_BREAK,           /* generate break condition */
    SCI_CMD_COMPARE_RECEIVED_DATA,    /* Compare received data with comparison data */

    /* Async/IrDA commands */
    SCI_CMD_TX_Q_FLUSH,               /* flush transmit queue */
    SCI_CMD_RX_Q_FLUSH,               /* flush receive queue */
    SCI_CMD_TX_Q_BYTES_FREE,          /* get count of unused transmit queue bytes */
    SCI_CMD_RX_Q_BYTES_AVAIL_TO_READ, /* get num bytes ready for reading */

    /* Async/Sync commands */
    SCI_CMD_EN_CTS_IN,                /* enable CTS input (default RTS output) */

    /* SSPI/Sync commands */
    SCI_CMD_CHECK_XFER_DONE,          /* see if send, rcv, or both are done; SCI_SUCCESS if yes */
    SCI_CMD_ABORT_XFER,
    SCI_CMD_XFER_LSB_FIRST,           /* start from LSB bit when sending */
    SCI_CMD_XFER_MSB_FIRST,           /* start from MSB bit when sending */
    SCI_CMD_INVERT_DATA,              /* logic level of send/receive data is invert */

    /* SSPI commands */
    SCI_CMD_CHANGE_SPI_MODE,           /* change clock polarity and phase in SSPI mode */
    SCI_CMD_CHECK_TX_DONE,           /* see if tx requests complete; SCI_SUCCESS if yes */
    SCI_CMD_CHECK_RX_DONE,            /* see if rx request complete in sync mode; SCI_SUCCESS if yes */
    SCI_CMD_CHECK_RX_SYNC_DONE,

    /*Sampling/transition timing adjust commands*/
    SCI_CMD_RX_SAMPLING_ENABLE,
    SCI_CMD_RX_SAMPLING_DISABLE,
    SCI_CMD_TX_TRANSITION_TIMING_ENABLE,
    SCI_CMD_TX_TRANSITION_TIMING_DISABLE,
    SCI_CMD_SAMPLING_TIMING_ADJUST,
    SCI_CMD_TRANSITION_TIMING_ADJUST
} sci_cmd_t;

/* SCI_CMD_CHANGE_BAUD/CHANGE_BITRATE take a ptr to this structure for *p_args */
typedef struct st_sci_baud
{
    uint32_t    pclk;       // peripheral clock speed; e.g. 24000000 is 24MHz
    uint32_t    rate;       // e.g. 9600, 19200, 115200
} sci_baud_t;

/* SCI_CMD_TX_Q_BYTES_FREE and SCI_CMD_RX_Q_BYTES_AVAIL_TO_READ take a pointer
   to a uint16_t for p_args */

/* SCI_CMD_SET_RXI_PRIORITY and SCI_CMD_SET_TXI_PRIORITY take a pointer to a
   uint8_t for p_args */

/* SCI_CMD_CHANGE_SPI_MODE takes a pointer to an sci_spi_mode_t for p_args */

/*****************************************************************************
Public Functions
******************************************************************************/
sci_err_t R_SCI_Open(uint8_t const      chan,
                     sci_mode_t const   mode,
                     sci_cfg_t * const  p_cfg,
                     void               (* const p_callback)(void *p_args),
                     sci_hdl_t * const  p_hdl);

sci_err_t R_SCI_Send(sci_hdl_t const    hdl,
                     uint8_t            *p_src,
                     uint16_t const     length);
                    
sci_err_t R_SCI_SendReceive(sci_hdl_t const hdl,        /* SSPI/SYNC only */
                            uint8_t         *p_src,
                            uint8_t         *p_dst,
                            uint16_t const  length);

sci_err_t R_SCI_Receive(sci_hdl_t const hdl,
                        uint8_t         *p_dst,
                        uint16_t const  length);

sci_err_t R_SCI_Control(sci_hdl_t const     hdl,
                        sci_cmd_t const     cmd,
                        void                *p_args);

sci_err_t R_SCI_Close(sci_hdl_t const hdl);

uint32_t  R_SCI_GetVersion(void);

                                    
#endif /* SCI_IF_H */

