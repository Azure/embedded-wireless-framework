/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework Message API
 ****************************************************************************/

#ifndef __ewf_message__h__included__
#define __ewf_message__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_tokenizer EWF Message API
 * @brief Messages are tokenized incoming host interface data.
 * @{
 ****************************************************************************/

/** @brief The interface message structure declaration */
struct _ewf_message;

/** @brief The interface message structure type definition */
typedef struct _ewf_message ewf_message;

/** @brief The interface message structure definition */
struct _ewf_message
{
    uint8_t* buffer_ptr;
    uint32_t buffer_length;
};

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_message__h__included__ */
