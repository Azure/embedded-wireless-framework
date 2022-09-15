/*
 * Instance header file for PIC32CM5164LS60100
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
#ifndef _PIC32CMLS60_IDAU_INSTANCE_
#define _PIC32CMLS60_IDAU_INSTANCE_


/* ========== Instance Parameter definitions for IDAU peripheral ========== */
#define IDAU_CRYA_AES_DEC_ADDR                   (0x02006808) /* crya_aes_dec function address */
#define IDAU_CRYA_AES_ENC_ADDR                   (0x02006804) /* crya_aes_enc function address */
#define IDAU_CRYA_GF_MULT128_ADDR                (0x0200680C) /* crya_gf_mult128 function address */
#define IDAU_CRYA_SHA_PROCESS_ADDR               (0x02006800) /* crya_sha_process function address */
#define IDAU_CRYA_SHA256_FINAL_ADDR              (0x02006818) /* crya_sha256_final function address */
#define IDAU_CRYA_SHA256_INIT_ADDR               (0x02006810) /* crya_sha256_init function address */
#define IDAU_CRYA_SHA256_UPDATE_ADDR             (0x02006814) /* crya_sha256_update function address */
#define IDAU_GRANULARITY_ANSC                    (0x20)     /* Application Non-Secure Callable region granularity */
#define IDAU_GRANULARITY_AS                      (0x100)    /* Application Secure region granularity */
#define IDAU_GRANULARITY_BNSC                    (0x20)     /* Boot Flash Non-Secure Callable region granularity */
#define IDAU_GRANULARITY_BOOTPROT                (0x100)    /* BOOTPROT region granularity */
#define IDAU_GRANULARITY_BS                      (0x100)    /* Boot Flash Secure region granularity */
#define IDAU_GRANULARITY_DS                      (0x100)    /* DS region granularity */
#define IDAU_GRANULARITY_RS                      (0x80)     /* RAM Secure region granularity */
#define IDAU_REGION_ANS                          (0x05)     /* Application Non-Secure region ID */
#define IDAU_REGION_ANSC                         (0x04)     /* Application Non-Secure Callable region ID */
#define IDAU_REGION_AS                           (0x03)     /* Application Secure region ID */
#define IDAU_REGION_BNSC                         (0x02)     /* Boot Flash Non-Secure Callable region ID */
#define IDAU_REGION_BOOTROM                      (0x08)     /* Boot ROM region ID */
#define IDAU_REGION_BS                           (0x01)     /* Boot Flash Secure region ID */
#define IDAU_REGION_DNS                          (0x07)     /* DATAFLASH Non-Secure region ID */
#define IDAU_REGION_DS                           (0x06)     /* DATAFLASH Secure region ID */
#define IDAU_REGION_IOBUS                        (0x00)     /* IOBUS region ID */
#define IDAU_REGION_OTHER                        (0x00)     /* Other region ID */
#define IDAU_REGION_PERIPHERALS                  (0x00)     /* Peripherals region ID */
#define IDAU_REGION_RNS                          (0x0A)     /* RAM Non-Secure region ID */
#define IDAU_REGION_RS                           (0x09)     /* RAM Secure region ID */
#define IDAU_INSTANCE_ID                         (32)       /* Instance index for IDAU */

#endif /* _PIC32CMLS60_IDAU_INSTANCE_ */
