/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Tokenizer API
 ****************************************************************************/

#ifndef __ewf_tokenizer__h__included__
#define __ewf_tokenizer__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_tokenizer The tokenizer API
 * @brief Functions for setting up and controlling the tokenizer
 * @{
 ****************************************************************************/

struct _ewf_tokenizer
{
#ifdef EWF_PARAMETER_CHECKING
    uint32_t struct_magic;
    uint32_t struct_size;
    uint32_t struct_version;
    uint32_t struct_type;
#endif /* EWF_PARAMETER_CHECKING */

    /**< The tokenizer data */
    void* data_ptr;

    /**< The interface pointer */
    ewf_interface* interface_ptr;

    /**< initialization function */
    ewf_result(*init)(ewf_tokenizer* tokenizer_ptr, ewf_interface* interface_ptr);

    /**< cleanup function */
    ewf_result(*clean)(ewf_tokenizer* tokenizer_ptr);

    /**< called when sending data */
    ewf_result(*send)(ewf_tokenizer* tokenizer_ptr);

    /**< called when receiving data */
    ewf_result(*receive)(ewf_tokenizer* tokenizer_ptr);
};

#define EWF_TOKENIZER_STRUCT_MAGIC         (0x707e9e00) /* ~~ tokenizer */
#define EWF_TOKENIZER_STRUCT_SIZE          (sizeof(struct _ewf_tokenizer))
#define EWF_TOKENIZER_VERSION              (EWF_DEVELOPER_MICROSOFT | 0x0001)

#ifdef EWF_PARAMETER_CHECKING
#define EWF_TOKENIZER_VALIDATE_POINTER(tokenizer_ptr)                               \
do {                                                                                \
    if ((tokenizer_ptr == NULL) ||                                                  \
        (tokenizer_ptr->struct_magic != EWF_TOKENIZER_STRUCT_MAGIC) ||              \
        (tokenizer_ptr->struct_size != EWF_TOKENIZER_STRUCT_SIZE) ||                \
        (tokenizer_ptr->struct_version != EWF_TOKENIZER_VERSION) ||                 \
        (tokenizer_ptr->implementation_ptr == NULL))                                \
    {                                                                               \
        EWF_LOG_ERROR("The tokenizer pointer is invalid.");                         \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)
#else
#define EWF_TOKENIZER_VALIDATE_POINTER(tokenizer_ptr)                               \
do {                                                                                \
    if ((tokenizer_ptr == NULL) ||                                                  \
        (tokenizer_ptr->implementation_ptr == NULL))                                \
    {                                                                               \
        EWF_LOG_ERROR("The tokenizer pointer is invalid.");                         \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)
#endif /* EWF_PARAMETER_CHECKING */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_TOKENIZER_VALIDATE_POINTER_TYPE(tokenizer_ptr, tokenizer_type)          \
do {                                                                                \
    if ((tokenizer_ptr == NULL) ||                                                  \
        (tokenizer_ptr->struct_type != tokenizer_type))                             \
    {                                                                               \
        EWF_LOG_ERROR("The tokenizer pointer type is invalid.");                    \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)
#else
#define EWF_TOKENIZER_VALIDATE_POINTER_TYPE(tokenizer_ptr, tokenizer_type)
#endif

/************************************************************************//**
 * @} // group_tokenizer
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_tokenizer__h__included__ */
