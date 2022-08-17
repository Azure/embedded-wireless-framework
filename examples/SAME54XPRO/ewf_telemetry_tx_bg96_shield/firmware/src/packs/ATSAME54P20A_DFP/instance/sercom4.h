/*
 * Instance header file for ATSAME54P20A
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

/* file generated from device description version 2022-02-14T14:27:35Z */
#ifndef _SAME54_SERCOM4_INSTANCE_
#define _SAME54_SERCOM4_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM4 peripheral ========== */
#define SERCOM4_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM4_DLY_COMPENSATION                 (1)        /* Compensates for a fast DLY50 element. Assuming 20ns */
#define SERCOM4_DMA                              (1)        /* DMA support implemented? */
#define SERCOM4_DMAC_ID_RX                       (12)       /* Index of DMA RX trigger */
#define SERCOM4_DMAC_ID_TX                       (13)       /* Index of DMA TX trigger */
#define SERCOM4_FIFO_DEPTH_POWER                 (1)        /* 2^FIFO_DEPTH_POWER gives rx FIFO depth. */
#define SERCOM4_GCLK_ID_CORE                     (34)       
#define SERCOM4_GCLK_ID_SLOW                     (3)        
#define SERCOM4_INT_MSB                          (6)        
#define SERCOM4_PMSB                             (3)        
#define SERCOM4_RETENTION_SUPPORT                (0)        /* Retention supported? */
#define SERCOM4_SE_CNT                           (1)        /* SE counter included? */
#define SERCOM4_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM4_SPI_HW_SS_CTRL                   (1)        /* Master _SS hardware control implemented? */
#define SERCOM4_SPI_ICSPACE_EXT                  (1)        /* SPI inter character space implemented? */
#define SERCOM4_SPI_OZMO                         (0)        /* OZMO features implemented? */
#define SERCOM4_SPI_WAKE_ON_SSL                  (1)        /* _SS low detect implemented? */
#define SERCOM4_SPI_TX_READY_INT_SRC             (62)       /* SPI TX READY Interrupt */
#define SERCOM4_SPI_TX_COMPLETE_INT_SRC          (63)       /* SPI TX COMPLETE Interrupt */
#define SERCOM4_SPI_RX_INT_SRC                   (64)       /* SPI RX Interrupt */
#define SERCOM4_SPI_ERROR_INT_SRC                (65)       /* SPI ERROR Interrupt */
#define SERCOM4_TTBIT_EXTENSION                  (1)        /* 32-bit extension implemented? */
#define SERCOM4_I2CM                             (1)        /* I2C Master mode implemented? */
#define SERCOM4_I2CS                             (1)        /* I2C Slave mode implemented? */
#define SERCOM4_I2CS_AUTO_ACK                    (1)        /* I2C slave automatic acknowledge implemented? */
#define SERCOM4_I2CS_GROUP_CMD                   (1)        /* I2C slave group command implemented? */
#define SERCOM4_I2CS_SDASETUP_CNT_SIZE           (8)        /* I2CS sda setup count size */
#define SERCOM4_I2CS_SDASETUP_SIZE               (4)        /* I2CS sda setup size */
#define SERCOM4_I2CS_SUDAT                       (1)        /* I2C slave SDA setup implemented? */
#define SERCOM4_I2C_FASTMP                       (1)        /* I2C fast mode plus implemented? */
#define SERCOM4_I2C_HSMODE                       (1)        /* USART mode implemented? */
#define SERCOM4_I2C_SCLSM_MODE                   (1)        /* I2C SCL clock stretch mode implemented? */
#define SERCOM4_I2C_SMB_TIMEOUTS                 (1)        /* I2C SMBus timeouts implemented? */
#define SERCOM4_I2C_TENBIT_ADR                   (1)        /* I2C ten bit enabled? */
#define SERCOM4_I2C_0_INT_SRC                    (62)       /* I2C 0 Interrupt */
#define SERCOM4_I2C_1_INT_SRC                    (63)       /* I2C 1 Interrupt */
#define SERCOM4_I2C_2_INT_SRC                    (64)       /* I2C 2 Interrupt */
#define SERCOM4_I2C_3_INT_SRC                    (65)       /* I2C 3 Interrupt */
#define SERCOM4_USART                            (1)        /* USART mode implemented? */
#define SERCOM4_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM4_USART_COLDET                     (1)        /* USART collision detection implemented? */
#define SERCOM4_USART_FLOW_CTRL                  (1)        /* USART flow control implemented? */
#define SERCOM4_USART_FRAC_BAUD                  (1)        /* USART fractional BAUD implemented? */
#define SERCOM4_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM4_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM4_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM4_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM4_USART_SAMPA_EXT                  (1)        /* USART sample adjust implemented? */
#define SERCOM4_USART_SAMPR_EXT                  (1)        /* USART oversampling adjustment implemented? */
#define SERCOM4_USART_TX_READY_INT_SRC           (62)       /* USART TX READY Interrupt */
#define SERCOM4_USART_TX_COMPLETE_INT_SRC        (63)       /* USART TX COMPLETE Interrupt */
#define SERCOM4_USART_RX_INT_SRC                 (64)       /* USART RX Interrupt */
#define SERCOM4_USART_ERROR_INT_SRC              (65)       /* USART ERROR Interrupt */
#define SERCOM4_INSTANCE_ID                      (96)       /* Instance index for SERCOM4 */

#endif /* _SAME54_SERCOM4_INSTANCE_ */
