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
 * Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * File Name    : ewf_cellular_private.h
 * Description  : Macro for controlling the pmod terminal
 *********************************************************************************************************************/

#ifndef EWF_CELLULAR_PRIVATE_H_
#define EWF_CELLULAR_PRIVATE_H_

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "r_sci_rx_if.h"
#include "r_sci_rx_pinset.h"
#include "ewf_cellular_config.h"


/* PDR port macros. */
#define EWF_CELLULAR_SET_PDR(x, y)              (EWF_CELLULAR_SET_PDR_PREPROC(x, y))
/* Set the port direction. */
#define EWF_CELLULAR_SET_PDR_PREPROC(x, y)      ((PORT ## x .PDR.BIT.B ## y))

/* PODR port macros. */
#define EWF_CELLULAR_SET_PODR(x, y)             (EWF_CELLULAR_SET_PODR_PREPROC(x, y))
/* Set the port I/O. */
#define EWF_CELLULAR_SET_PODR_PREPROC(x, y)     ((PORT ## x .PODR.BIT.B ## y))

#define EWF_CELLULAR_PIN_DIRECTION_MODE_OUTPUT     (1)

/* Changes the output format of the reset signal sent to the Cellular module.	*/
#if EWF_CELLULAR_CFG_RESET_SIGNAL_LOGIC == 1
#define EWF_CELLULAR_CFG_RESET_SIGNAL_ON        (1)
#define EWF_CELLULAR_CFG_RESET_SIGNAL_OFF       (0)
#else
#define EWF_CELLULAR_CFG_RESET_SIGNAL_ON        (0)
#define EWF_CELLULAR_CFG_RESET_SIGNAL_OFF       (1)
#endif


#ifndef EWF_CELLULAR_CFG_UART_SCI_CH
#error "Error! Need to define EWF_CELLULAR_CFG_UART_SCI_CH in ewf_cellular_config.h"
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (0)
#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
/* Store R_SCI_PinSet_SCI0() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI0())
#elif defined(__CCRL__) || defined(__ICCRL78__) || defined(__RL)
/*  */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()
#endif
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH0)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH0_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH0_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (1)
#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
/* Store R_SCI_PinSet_SCI1() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI1())
#elif defined(__CCRL__) || defined(__ICCRL78__) || defined(__RL)
/* Emptying R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()
#endif
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH1)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH1_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH1_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (2)
#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
/* Store R_SCI_PinSet_SCI2() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI2())
#elif defined(__CCRL__) || defined(__ICCRL78__) || defined(__RL)
/* Emptying R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()
#endif
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH2)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH2_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH2_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (3)
#if defined(__CCRX__) || defined(__ICCRX__) || defined(__RX__)
/* Store R_SCI_PinSet_SCI3() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI3())
#elif defined(__CCRL__) || defined(__ICCRL78__) || defined(__RL)
/* Emptying R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()
#endif
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH3)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH3_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH3_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (4)
/* Store R_SCI_PinSet_SCI4() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI4())
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH4)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH4_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH4_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (5)
/* Store R_SCI_PinSet_SCI5() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI5())
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH5)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH5_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH5_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (6)
/* Store R_SCI_PinSet_SCI6() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI6())
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH6)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH6_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH6_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (7)
/* Store R_SCI_PinSet_SCI7() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI7())
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH7)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH7_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH7_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (8)
/* Store R_SCI_PinSet_SCI8() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI8())
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH8)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH8_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH8_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (9)
/* Store R_SCI_PinSet_SCI9() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI9())
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH9)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH9_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH9_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (10)
/* Store R_SCI_PinSet_SCI10() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI10())
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH10)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH10_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH10_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (11)
/* Store R_SCI_PinSet_SCI11() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI11())
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH11)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH11_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH11_RX_BUFSIZ)
#elif EWF_CELLULAR_CFG_UART_SCI_CH == (12)
/* Store R_SCI_PinSet_SCI12() in R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL() */
#define R_SCI_CFG_PINSET_EWF_CELLULAR_SERIAL()      (R_SCI_PinSet_SCI12())
#define R_SCI_CFG_EWF_CELLULAR_SERIAL_CH            (SCI_CH12)
#define R_SCI_CFG_TX_BUFSIZE                    (SCI_CFG_CH12_TX_BUFSIZ)
#define R_SCI_CFG_RX_BUFSIZE                    (SCI_CFG_CH12_RX_BUFSIZ)
#else
#error "Error! Invalid setting for EWF_CELLULAR_UART_SCI_CH in ewf_cellular_config.h"
#endif /* EWF_CELLULAR_CFG_UART_SCI_CH */


#if R_SCI_CFG_TX_BUFSIZE < (1500)
#error "The SCI send buffer size is too small."
#endif
#if R_SCI_CFG_RX_BUFSIZE < (1500)
#error "The SCI receive buffer size is too small."
#endif

#endif /* EWF_CELLULAR_PRIVATE_H_ */
