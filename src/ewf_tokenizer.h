/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework Tokenizer API
 ****************************************************************************/

#ifndef __ewf_tokenizer__h__included__
#define __ewf_tokenizer__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_tokenizer EWF Tokenizer API
 * @brief Tokenizer patters are user to separate the incoming host interface byte stream into messages.
 * @{
 ****************************************************************************/

/** @brief The interface tokenizer pattern structure definition */
struct _ewf_tokenizer_pattern
{
    /**< a pointer to the next patter in the list, NULL if no further patters */
    ewf_tokenizer_pattern* next_ptr;

    /**< a pointer to a NULL terminated string for the pattern */
    const char* pattern_str;

    /**< the length of the patter */
    uint32_t patter_length;

    /**< true if the pattern contains wildcards, false otherwise */
    bool has_wildcards;

    /**< custom function for matching */
    bool(*match_function)(const char* buffer, uint32_t buffer_length, const ewf_tokenizer_pattern* pattern_ptr, bool* stop_ptr);

    /**< pointer to custom data, that can be used by the match function */
    void* data_ptr;
};

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_tokenizer__h__included__ */
