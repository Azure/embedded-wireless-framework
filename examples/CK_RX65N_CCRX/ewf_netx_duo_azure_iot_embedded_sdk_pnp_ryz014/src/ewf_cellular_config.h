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
 * File Name    : ewf_cellular_config.h
 * Description  : Cellular-related config files such as pmod terminal and APN.
 *********************************************************************************************************************/

#ifndef EWF_CELLULAR_CONFIG_H
#define EWF_CELLULAR_CONFIG_H

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/


/*　Specify uart ch used for communication with cellular module */
#define EWF_CELLULAR_CFG_UART_SCI_CH            (6)

/* Specify the port and pin of the RTS terminal */
#define EWF_CELLULAR_CFG_RTS_PORT               0
#define EWF_CELLULAR_CFG_RTS_PIN                2

/* Specify the port and pin of the RESET terminal */
#define EWF_CELLULAR_CFG_RESET_PORT             5
#define EWF_CELLULAR_CFG_RESET_PIN              5


/* Changes the output format of the reset signal sent to the Cellular module.	*/
/* 1: active high  0: active low */
#define EWF_CELLULAR_CFG_RESET_SIGNAL_LOGIC     (1)

/* Sets the RTS pin control method of the Cellular module.																	*/
/* 0: The CTS pin is controlled by hardware flow control, and the RTS pin is controlled by this FIT module through GPIO.	*/
/* 1: The RTS pin is controlled by hardware flow control, and the CTS pin is controlled by this FIT module through GPIO.	*/
#define EWF_CELLULAR_CFG_CTS_SW_CTRL            (0)		//unused

/* Specify the port and pin of the CTC */
#define EWF_CELLULAR_CFG_CTS_PORT               2		//unused
#define EWF_CELLULAR_CFG_CTS_PIN                2		//unused


/* Specifies the pin function control register (PFS) setting value 					*/
/* to select the peripheral function of the MCU pin used to control the RTS pin of 	*/
/* the Cellular module. Set this option to match the pin to be used.				*/
/* This option takes effect when EWF_CELLULAR_CFG_CTS_SW_CTRL is set to 1.			*/
#define EWF_CELLULAR_CFG_PFS_SET_VALUE          0x0BU	//unused

/* Specify IRQ terminal for RING terminal */
#define EWF_CELLULAR_CFG_IRQ_NUM                (4)		//unused

/* The SIM PIN for the modem */
#define EWF_CONFIG_SIM_PIN                      ("0000")

/* The SIM operator APN */
#define EWF_CONFIG_SIM_APN                      ("globaldata.iot")

/* The modem context ID used */
#define EWF_CONFIG_CONTEXT_ID                   (1)
/* Board dependent settings; please use the value for each setting listed below depending on the board you use.

Preprocessors that define board dependent settings and the corresponding values to be set are as follows:
Confirmed board number              	1,
EWF_CELLULAR_CFG_UART_SCI_CH            6,
EWF_CELLULAR_CFG_RTS_PORT               0,
EWF_CELLULAR_CFG_RTS_PIN               	2,
EWF_CELLULAR_CFG_RESET_PORT             5,
EWF_CELLULAR_CFG_RESET_PIN             	5,
EWF_CELLULAR_CFG_RESET_SIGNAL_LOGIC     1,
EWF_CELLULAR_CFG_CTS_SW_CTRL			0,
EWF_CELLULAR_CFG_CTS_PORT				2,
EWF_CELLULAR_CFG_CTS_PIN				2,
EWF_CELLULAR_CFG_PFS_SET_VALUE			0x0BU,
EWF_CELLULAR_CFG_IRQ_NUM				4,
EWF_CONFIG_SIM_PIN                      "0000",
EWF_CONFIG_SIM_APN                      "globaldata.iot",
EWF_CONFIG_CONTEXT_ID                   1

where the confirmed board numbers listed in the first row above are as follows:
1: CK-RX65N (PMOD1),
In the above preprocessor list, please use one of the values listed on the right side.
On the right side, each column corresponds to each confirmed board number.

Note:
Please supply power source to USB(CN4) port on RYZ014A/RYZ024A-PMOD.
E2 emulator supplying power to RYZ014A/RYZ024A-PMOD may result in insufficient power source.
The E2 emulator can provide 200mA, but RYZ014A/RYZ024A needs more current while connecting to the network.

*/
#endif /* EWF_CELLULAR_CONFIG_H */
