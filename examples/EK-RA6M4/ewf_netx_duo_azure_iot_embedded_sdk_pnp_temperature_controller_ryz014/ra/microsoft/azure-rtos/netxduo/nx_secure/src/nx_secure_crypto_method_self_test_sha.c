/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** NetX Secure Component                                                 */
/**                                                                       */
/**    Transport Layer Security (TLS)                                     */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define NX_SECURE_SOURCE_CODE


/* Include necessary system files.  */

#include "nx_secure_crypto_table_self_test.h"

#ifdef NX_SECURE_POWER_ON_SELF_TEST_MODULE_INTEGRITY_CHECK

/* 7c9c67323a1df1adbfe5ceb415eaef0155ece2820f4d50c1ec22cba4928ac656c83fe585db6a78ce40bc42757aba7e5a3f582428d6ca68d0c3978336a6efb729613e8d9979016204bfd921322fdd5222183554447de5e6e9bbe6edf76d7b71e18dc2e8d6dc89b7398364f652fafc734329aafa3dcd45d4f31e388e4fafd7fc6495f37ca5cbab7f54d586463da4bfeaa3bae09f7b8e9239d832b4f0a733aa609cc1f8d4 */
static UCHAR plain_1[] = {
0x7c, 0x9c, 0x67, 0x32, 0x3a, 0x1d, 0xf1, 0xad, 0xbf, 0xe5, 0xce, 0xb4, 0x15, 0xea, 0xef, 0x01, 
0x55, 0xec, 0xe2, 0x82, 0x0f, 0x4d, 0x50, 0xc1, 0xec, 0x22, 0xcb, 0xa4, 0x92, 0x8a, 0xc6, 0x56, 
0xc8, 0x3f, 0xe5, 0x85, 0xdb, 0x6a, 0x78, 0xce, 0x40, 0xbc, 0x42, 0x75, 0x7a, 0xba, 0x7e, 0x5a, 
0x3f, 0x58, 0x24, 0x28, 0xd6, 0xca, 0x68, 0xd0, 0xc3, 0x97, 0x83, 0x36, 0xa6, 0xef, 0xb7, 0x29, 
0x61, 0x3e, 0x8d, 0x99, 0x79, 0x01, 0x62, 0x04, 0xbf, 0xd9, 0x21, 0x32, 0x2f, 0xdd, 0x52, 0x22, 
0x18, 0x35, 0x54, 0x44, 0x7d, 0xe5, 0xe6, 0xe9, 0xbb, 0xe6, 0xed, 0xf7, 0x6d, 0x7b, 0x71, 0xe1, 
0x8d, 0xc2, 0xe8, 0xd6, 0xdc, 0x89, 0xb7, 0x39, 0x83, 0x64, 0xf6, 0x52, 0xfa, 0xfc, 0x73, 0x43, 
0x29, 0xaa, 0xfa, 0x3d, 0xcd, 0x45, 0xd4, 0xf3, 0x1e, 0x38, 0x8e, 0x4f, 0xaf, 0xd7, 0xfc, 0x64, 
0x95, 0xf3, 0x7c, 0xa5, 0xcb, 0xab, 0x7f, 0x54, 0xd5, 0x86, 0x46, 0x3d, 0xa4, 0xbf, 0xea, 0xa3, 
0xba, 0xe0, 0x9f, 0x7b, 0x8e, 0x92, 0x39, 0xd8, 0x32, 0xb4, 0xf0, 0xa7, 0x33, 0xaa, 0x60, 0x9c, 
0xc1, 0xf8, 0xd4,
};

/* d8fd6a91ef3b6ced05b98358a99107c1fac8c807 */
static UCHAR secret_1[] = {
0xd8, 0xfd, 0x6a, 0x91, 0xef, 0x3b, 0x6c, 0xed, 0x05, 0xb9, 0x83, 0x58, 0xa9, 0x91, 0x07, 0xc1,
0xfa, 0xc8, 0xc8, 0x07,
};

/* F90D116B1CE425438CE09A7F03E07203BFEC2A4A8FD13D6E649ADA05403FAF754114227A18255F663B57DF0B6D2F004E737A93124FF0D93878C9ED1CB2DB9417311E0F48DC8A25532E958832F489E8273346407B9F12051AC18EC8323F1D766063F045469D686A7DC8120E0C730FBB79BD90FF4F8295ED1803DA0812B69E103B9F79135C8FBAA311BA7E833E5E663E261E8CE17F1E195E449EA5ED1B5FA0037A373EBD2AD9FCCC27CDCF0348AAB8503D29EDA6604599F1645C94E5545A0BB628212417388A296E074E959E50546A5733293C73210F2467039387CD138C2CB967AC8CD1005C9ADB1FFF3B74616A1DD150DE2FC93803167D7320BCE10B7DA9DC14 */
static UCHAR plain_256[] = {
0xF9, 0x0D, 0x11, 0x6B, 0x1C, 0xE4, 0x25, 0x43, 0x8C, 0xE0, 0x9A, 0x7F, 0x03, 0xE0, 0x72, 0x03, 
0xBF, 0xEC, 0x2A, 0x4A, 0x8F, 0xD1, 0x3D, 0x6E, 0x64, 0x9A, 0xDA, 0x05, 0x40, 0x3F, 0xAF, 0x75, 
0x41, 0x14, 0x22, 0x7A, 0x18, 0x25, 0x5F, 0x66, 0x3B, 0x57, 0xDF, 0x0B, 0x6D, 0x2F, 0x00, 0x4E, 
0x73, 0x7A, 0x93, 0x12, 0x4F, 0xF0, 0xD9, 0x38, 0x78, 0xC9, 0xED, 0x1C, 0xB2, 0xDB, 0x94, 0x17, 
0x31, 0x1E, 0x0F, 0x48, 0xDC, 0x8A, 0x25, 0x53, 0x2E, 0x95, 0x88, 0x32, 0xF4, 0x89, 0xE8, 0x27, 
0x33, 0x46, 0x40, 0x7B, 0x9F, 0x12, 0x05, 0x1A, 0xC1, 0x8E, 0xC8, 0x32, 0x3F, 0x1D, 0x76, 0x60, 
0x63, 0xF0, 0x45, 0x46, 0x9D, 0x68, 0x6A, 0x7D, 0xC8, 0x12, 0x0E, 0x0C, 0x73, 0x0F, 0xBB, 0x79, 
0xBD, 0x90, 0xFF, 0x4F, 0x82, 0x95, 0xED, 0x18, 0x03, 0xDA, 0x08, 0x12, 0xB6, 0x9E, 0x10, 0x3B, 
0x9F, 0x79, 0x13, 0x5C, 0x8F, 0xBA, 0xA3, 0x11, 0xBA, 0x7E, 0x83, 0x3E, 0x5E, 0x66, 0x3E, 0x26, 
0x1E, 0x8C, 0xE1, 0x7F, 0x1E, 0x19, 0x5E, 0x44, 0x9E, 0xA5, 0xED, 0x1B, 0x5F, 0xA0, 0x03, 0x7A, 
0x37, 0x3E, 0xBD, 0x2A, 0xD9, 0xFC, 0xCC, 0x27, 0xCD, 0xCF, 0x03, 0x48, 0xAA, 0xB8, 0x50, 0x3D, 
0x29, 0xED, 0xA6, 0x60, 0x45, 0x99, 0xF1, 0x64, 0x5C, 0x94, 0xE5, 0x54, 0x5A, 0x0B, 0xB6, 0x28, 
0x21, 0x24, 0x17, 0x38, 0x8A, 0x29, 0x6E, 0x07, 0x4E, 0x95, 0x9E, 0x50, 0x54, 0x6A, 0x57, 0x33, 
0x29, 0x3C, 0x73, 0x21, 0x0F, 0x24, 0x67, 0x03, 0x93, 0x87, 0xCD, 0x13, 0x8C, 0x2C, 0xB9, 0x67, 
0xAC, 0x8C, 0xD1, 0x00, 0x5C, 0x9A, 0xDB, 0x1F, 0xFF, 0x3B, 0x74, 0x61, 0x6A, 0x1D, 0xD1, 0x50, 
0xDE, 0x2F, 0xC9, 0x38, 0x03, 0x16, 0x7D, 0x73, 0x20, 0xBC, 0xE1, 0x0B, 0x7D, 0xA9, 0xDC, 0x14, 
};

/* 316A9D20B8596F02FA6DFF4B4BEF48E50EA4096E828424ECE6711D7DE35FEFA1 */
static UCHAR secret_256[] = {
0x31, 0x6A, 0x9D, 0x20, 0xB8, 0x59, 0x6F, 0x02, 0xFA, 0x6D, 0xFF, 0x4B, 0x4B, 0xEF, 0x48, 0xE5, 
0x0E, 0xA4, 0x09, 0x6E, 0x82, 0x84, 0x24, 0xEC, 0xE6, 0x71, 0x1D, 0x7D, 0xE3, 0x5F, 0xEF, 0xA1, 
};

/* EDA8CA35AA932D057F0A762965BA7544EC9EA83B8662ED6D63BD7D29761753782C47A370D501151360391F476E176C7B7D8E487DA309BE662E2DAE4665431A2A94A1294F59E09B3CE879606F8ED9D1158F35BE7B04BAB0276710F322ACC9952D76CD103EF4F97C5BF411856E55419C63910E7375C5EA1302BF48E6407EB73D2B6F7E41073E535C6AE371B36F5B1DEA42C5B54958462F3119D2343D3BF1FCEC481B31462C326E5C025F14594499BF8E29D5771A698D41070BFE02A9536A194438E621A347E67C0943F8F2154E75576143EB36BA6A600309712121F7706104CB2854FD854C15337C5FB645670CE50BF941DA1D9061758E4D4D63C3366D4A9CD168 */
static UCHAR plain_384[] = {
0xED, 0xA8, 0xCA, 0x35, 0xAA, 0x93, 0x2D, 0x05, 0x7F, 0x0A, 0x76, 0x29, 0x65, 0xBA, 0x75, 0x44, 
0xEC, 0x9E, 0xA8, 0x3B, 0x86, 0x62, 0xED, 0x6D, 0x63, 0xBD, 0x7D, 0x29, 0x76, 0x17, 0x53, 0x78, 
0x2C, 0x47, 0xA3, 0x70, 0xD5, 0x01, 0x15, 0x13, 0x60, 0x39, 0x1F, 0x47, 0x6E, 0x17, 0x6C, 0x7B, 
0x7D, 0x8E, 0x48, 0x7D, 0xA3, 0x09, 0xBE, 0x66, 0x2E, 0x2D, 0xAE, 0x46, 0x65, 0x43, 0x1A, 0x2A, 
0x94, 0xA1, 0x29, 0x4F, 0x59, 0xE0, 0x9B, 0x3C, 0xE8, 0x79, 0x60, 0x6F, 0x8E, 0xD9, 0xD1, 0x15, 
0x8F, 0x35, 0xBE, 0x7B, 0x04, 0xBA, 0xB0, 0x27, 0x67, 0x10, 0xF3, 0x22, 0xAC, 0xC9, 0x95, 0x2D, 
0x76, 0xCD, 0x10, 0x3E, 0xF4, 0xF9, 0x7C, 0x5B, 0xF4, 0x11, 0x85, 0x6E, 0x55, 0x41, 0x9C, 0x63, 
0x91, 0x0E, 0x73, 0x75, 0xC5, 0xEA, 0x13, 0x02, 0xBF, 0x48, 0xE6, 0x40, 0x7E, 0xB7, 0x3D, 0x2B, 
0x6F, 0x7E, 0x41, 0x07, 0x3E, 0x53, 0x5C, 0x6A, 0xE3, 0x71, 0xB3, 0x6F, 0x5B, 0x1D, 0xEA, 0x42, 
0xC5, 0xB5, 0x49, 0x58, 0x46, 0x2F, 0x31, 0x19, 0xD2, 0x34, 0x3D, 0x3B, 0xF1, 0xFC, 0xEC, 0x48, 
0x1B, 0x31, 0x46, 0x2C, 0x32, 0x6E, 0x5C, 0x02, 0x5F, 0x14, 0x59, 0x44, 0x99, 0xBF, 0x8E, 0x29, 
0xD5, 0x77, 0x1A, 0x69, 0x8D, 0x41, 0x07, 0x0B, 0xFE, 0x02, 0xA9, 0x53, 0x6A, 0x19, 0x44, 0x38, 
0xE6, 0x21, 0xA3, 0x47, 0xE6, 0x7C, 0x09, 0x43, 0xF8, 0xF2, 0x15, 0x4E, 0x75, 0x57, 0x61, 0x43, 
0xEB, 0x36, 0xBA, 0x6A, 0x60, 0x03, 0x09, 0x71, 0x21, 0x21, 0xF7, 0x70, 0x61, 0x04, 0xCB, 0x28, 
0x54, 0xFD, 0x85, 0x4C, 0x15, 0x33, 0x7C, 0x5F, 0xB6, 0x45, 0x67, 0x0C, 0xE5, 0x0B, 0xF9, 0x41, 
0xDA, 0x1D, 0x90, 0x61, 0x75, 0x8E, 0x4D, 0x4D, 0x63, 0xC3, 0x36, 0x6D, 0x4A, 0x9C, 0xD1, 0x68, 
};

/* 08E3D346F6E3C03D8A15D1EB273EC5EE5AD7201C9CE9325B586486C32BBF3FB9DB7DB416D54C68C2AD3E6694E06CFC45 */
static UCHAR secret_384[] = {
0x08, 0xE3, 0xD3, 0x46, 0xF6, 0xE3, 0xC0, 0x3D, 0x8A, 0x15, 0xD1, 0xEB, 0x27, 0x3E, 0xC5, 0xEE, 
0x5A, 0xD7, 0x20, 0x1C, 0x9C, 0xE9, 0x32, 0x5B, 0x58, 0x64, 0x86, 0xC3, 0x2B, 0xBF, 0x3F, 0xB9, 
0xDB, 0x7D, 0xB4, 0x16, 0xD5, 0x4C, 0x68, 0xC2, 0xAD, 0x3E, 0x66, 0x94, 0xE0, 0x6C, 0xFC, 0x45, 
};

/* A40C7F79AC43604D7A11E57C3859E87976E76E7ADF96E26C99830D20B9F64609606C9415EFDD6F36ECDDB2024CC49312EEF3CF718935562B44C6A30B47DA670492D05F7D466BA517A858A4328FA2C10B875D9C1E9D01416DBB01257DB244A91984BFE51493D5E732220F3D50F47EEE62CC079F4D8EF051331A57C31671141E473B34B2009468A813A96D0641B11B217B74FF8A0042F113616A126804D46B1F1631CF831756F01A072030B3281FC35309E025713264F65634679DBB0D72F6D02FAA61FC4B0FF65F400199923B32BF986AACF7A02DBD9AB738E403420430B7864250709F6B06137F54253675251D783E399503D1073F8D383C8E8C5C00D0378308 */
static UCHAR plain_512[] = {
0xA4, 0x0C, 0x7F, 0x79, 0xAC, 0x43, 0x60, 0x4D, 0x7A, 0x11, 0xE5, 0x7C, 0x38, 0x59, 0xE8, 0x79, 
0x76, 0xE7, 0x6E, 0x7A, 0xDF, 0x96, 0xE2, 0x6C, 0x99, 0x83, 0x0D, 0x20, 0xB9, 0xF6, 0x46, 0x09, 
0x60, 0x6C, 0x94, 0x15, 0xEF, 0xDD, 0x6F, 0x36, 0xEC, 0xDD, 0xB2, 0x02, 0x4C, 0xC4, 0x93, 0x12, 
0xEE, 0xF3, 0xCF, 0x71, 0x89, 0x35, 0x56, 0x2B, 0x44, 0xC6, 0xA3, 0x0B, 0x47, 0xDA, 0x67, 0x04, 
0x92, 0xD0, 0x5F, 0x7D, 0x46, 0x6B, 0xA5, 0x17, 0xA8, 0x58, 0xA4, 0x32, 0x8F, 0xA2, 0xC1, 0x0B, 
0x87, 0x5D, 0x9C, 0x1E, 0x9D, 0x01, 0x41, 0x6D, 0xBB, 0x01, 0x25, 0x7D, 0xB2, 0x44, 0xA9, 0x19, 
0x84, 0xBF, 0xE5, 0x14, 0x93, 0xD5, 0xE7, 0x32, 0x22, 0x0F, 0x3D, 0x50, 0xF4, 0x7E, 0xEE, 0x62, 
0xCC, 0x07, 0x9F, 0x4D, 0x8E, 0xF0, 0x51, 0x33, 0x1A, 0x57, 0xC3, 0x16, 0x71, 0x14, 0x1E, 0x47, 
0x3B, 0x34, 0xB2, 0x00, 0x94, 0x68, 0xA8, 0x13, 0xA9, 0x6D, 0x06, 0x41, 0xB1, 0x1B, 0x21, 0x7B, 
0x74, 0xFF, 0x8A, 0x00, 0x42, 0xF1, 0x13, 0x61, 0x6A, 0x12, 0x68, 0x04, 0xD4, 0x6B, 0x1F, 0x16, 
0x31, 0xCF, 0x83, 0x17, 0x56, 0xF0, 0x1A, 0x07, 0x20, 0x30, 0xB3, 0x28, 0x1F, 0xC3, 0x53, 0x09, 
0xE0, 0x25, 0x71, 0x32, 0x64, 0xF6, 0x56, 0x34, 0x67, 0x9D, 0xBB, 0x0D, 0x72, 0xF6, 0xD0, 0x2F, 
0xAA, 0x61, 0xFC, 0x4B, 0x0F, 0xF6, 0x5F, 0x40, 0x01, 0x99, 0x92, 0x3B, 0x32, 0xBF, 0x98, 0x6A, 
0xAC, 0xF7, 0xA0, 0x2D, 0xBD, 0x9A, 0xB7, 0x38, 0xE4, 0x03, 0x42, 0x04, 0x30, 0xB7, 0x86, 0x42, 
0x50, 0x70, 0x9F, 0x6B, 0x06, 0x13, 0x7F, 0x54, 0x25, 0x36, 0x75, 0x25, 0x1D, 0x78, 0x3E, 0x39, 
0x95, 0x03, 0xD1, 0x07, 0x3F, 0x8D, 0x38, 0x3C, 0x8E, 0x8C, 0x5C, 0x00, 0xD0, 0x37, 0x83, 0x08, 
};

/* 4A5C6FC817649A45AF89D4FA2D66B7A8EC28CCC44C3946C25B2A21CC7B9FB36EA4E3887199BBDAC58238AB823E4C03491703023C04B110438A3E069F33F2C79C */
static UCHAR secret_512[] = {
0x4A, 0x5C, 0x6F, 0xC8, 0x17, 0x64, 0x9A, 0x45, 0xAF, 0x89, 0xD4, 0xFA, 0x2D, 0x66, 0xB7, 0xA8, 
0xEC, 0x28, 0xCC, 0xC4, 0x4C, 0x39, 0x46, 0xC2, 0x5B, 0x2A, 0x21, 0xCC, 0x7B, 0x9F, 0xB3, 0x6E, 
0xA4, 0xE3, 0x88, 0x71, 0x99, 0xBB, 0xDA, 0xC5, 0x82, 0x38, 0xAB, 0x82, 0x3E, 0x4C, 0x03, 0x49, 
0x17, 0x03, 0x02, 0x3C, 0x04, 0xB1, 0x10, 0x43, 0x8A, 0x3E, 0x06, 0x9F, 0x33, 0xF2, 0xC7, 0x9C, 
};

/* Output. */
static ULONG output[16];

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    nx_secure_crypto_method_self_test_sha               PORTABLE C      */
/*                                                           6.1          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Timothy Stapko, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function performs the Known Answer Test for SHA crypto method. */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    method_ptr                            Pointer to the crypto method  */
/*                                            to be tested.               */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                Completion status             */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     Timothy Stapko           Initial Version 6.0           */
/*  09-30-2020     Timothy Stapko           Modified comment(s),          */
/*                                            resulting in version 6.1    */
/*                                                                        */
/**************************************************************************/
UINT _nx_secure_crypto_method_self_test_sha(NX_CRYPTO_METHOD *crypto_method_sha,
                                            VOID *metadata, UINT metadata_size)
{
UCHAR  *input;
UCHAR  *secret;
UINT    input_length;
UINT    output_length;
UINT    status;
VOID   *handler = NX_NULL;


    /* Validate the crypto method */
    if(crypto_method_sha == NX_NULL)
        return(NX_PTR_ERROR);

    /* Set the test data.  */
    switch (crypto_method_sha -> nx_crypto_algorithm)
    {
    case NX_CRYPTO_HASH_SHA1:
        input = plain_1;
        secret = secret_1;
        input_length = sizeof(plain_1);
        output_length = sizeof(secret_1);
        break;
    case NX_CRYPTO_HASH_SHA256:
        input = plain_256;
        secret = secret_256;
        input_length = sizeof(plain_256);
        output_length = sizeof(secret_256);
        break;
    case NX_CRYPTO_HASH_SHA384:
        input = plain_384;
        secret = secret_384;
        input_length = sizeof(plain_384);
        output_length = sizeof(secret_384);
        break;
    case NX_CRYPTO_HASH_SHA512:
        input = plain_512;
        secret = secret_512;
        input_length = sizeof(plain_512);
        output_length = sizeof(secret_512);
        break;
    default:
        return(1);
    }

    if (crypto_method_sha -> nx_crypto_init)
    {
        status = crypto_method_sha -> nx_crypto_init(crypto_method_sha,
                                                     NX_NULL,
                                                     0,
                                                     &handler,
                                                     metadata,
                                                     metadata_size);

        if (status != NX_CRYPTO_SUCCESS)
        {
            return(status);
        }
    }

    if (crypto_method_sha -> nx_crypto_operation == NX_NULL)
    {
        return(NX_PTR_ERROR);
    }

    /* Clear the output buffer.  */
    NX_SECURE_MEMSET(output, 0, sizeof(output));

    /* Call the crypto operation function.  */
    status = crypto_method_sha -> nx_crypto_operation(NX_CRYPTO_AUTHENTICATE,
                                                      handler,
                                                      crypto_method_sha,
                                                      NX_NULL,
                                                      0,
                                                      input,
                                                      input_length,
                                                      NX_NULL,
                                                      (UCHAR *)output,
                                                      output_length,
                                                      metadata,
                                                      metadata_size,
                                                      NX_NULL, NX_NULL);

    /* Check the status.  */
    if(status != NX_CRYPTO_SUCCESS)
    {
        return(status);
    }

    /* Validate the output.  */
    if(NX_SECURE_MEMCMP(output, secret, output_length) != 0)
    {
        return(NX_NOT_SUCCESSFUL);
    }

    if (crypto_method_sha -> nx_crypto_cleanup)
    {
        status = crypto_method_sha -> nx_crypto_cleanup(metadata);
    }

    return(status);
}
#endif
