/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Tokenizer API
 ****************************************************************************/

#ifndef __ewf_tokenizer_basic__h__included__
#define __ewf_tokenizer_basic__h__included__

#include "ewf.h"
#include "ewf_tokenizer.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_tokenizer_basic The tokenizer basic API
 * @brief Functions for setting up and controlling the tokenizer basic API
 * @{
 ****************************************************************************/

struct _ewf_tokenizer_basic_pattern;

typedef struct _ewf_tokenizer_basic_pattern ewf_tokenizer_basic_pattern;

/** @brief The tokenizer pattern structure definition */
struct _ewf_tokenizer_basic_pattern
{
    /**< a pointer to the next patter in the list, NULL if no further patters */
    ewf_tokenizer_basic_pattern* next_ptr;

    /**< a pointer to a NULL terminated string for the pattern */
    const char* pattern_str;

    /**< the length of the patter */
    uint32_t patter_length;

    /**< true if the pattern contains wildcards, false otherwise */
    bool has_wildcards;

    /**< custom function for matching */
    bool(*match_function)(const uint8_t* buffer, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* tokenizer_pattern_ptr, bool* stop_ptr);

    /**< pointer to custom data, that can be used by the match function */
    void* data_ptr;
};

typedef struct _ewf_tokenizer_basic_data
{
    /**< A pointer to the tokenizer associated with this tokenizer data */
    ewf_tokenizer* tokenizer_ptr;

    /**< The interface pointer */
    ewf_interface* interface_ptr;

    /**< A The current mode of the */
    bool command_mode;

    /**< A pointer to the first on a list of tokenizer patterns for tokenizing messages */
    ewf_tokenizer_basic_pattern* message_tokenizer_pattern_ptr;

    /**< A pointer to the first on a list of tokenizer patterns for tokenizing command responses, they complete commands and end the command mode */
    ewf_tokenizer_basic_pattern* command_response_end_tokenizer_pattern_ptr;

    /**< A pointer to the first on a list of tokenizer patterns for tokenizing command responses, they do not complete commands and end the command mode */
    ewf_tokenizer_basic_pattern* command_response_tokenizer_pattern_ptr;

    /**< A pointer to the first on a list of tokenizer patterns set by the user for tokenizing URCs */
    ewf_tokenizer_basic_pattern* urc_tokenizer_pattern_ptr;

} ewf_tokenizer_basic_data;

/**
 * @brief Set the interface message tokenizer pattern
 * @param[in] tokenizer_ptr a pointer to the tokenizer structure
 * @param[in] interface_ptr a pointer to the interface data structure
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_init(ewf_tokenizer* tokenizer_ptr, ewf_interface* interface_ptr);

/**
 * @brief Set the interface message tokenizer pattern
 * @param[in] tokenizer_ptr a pointer to the tokenizer structure
 * @param[in] tokenizer_patter_ptr a pointer to a tokenizer pattern that will be set in the interface as the message tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_clean(ewf_tokenizer* tokenizer_ptr);

/**
 * @brief Set the interface message tokenizer pattern
 * @param[in] tokenizer_ptr a pointer to the tokenizer structure
 * @param[in] buffer_ptr a pointer to the buffer that will be sent
 * @param[in] buffer_length the length of the buffer that will be sent
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_send(ewf_tokenizer* tokenizer_ptr);

/**
 * @brief Set the interface message tokenizer pattern
 * @param[in] tokenizer_ptr a pointer to the tokenizer structure
 * @param[in] tokenizer_pattern_ptr a pointer to the tokenizer data structure
 * @param[out] match_ptr a pointer to match flag
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_match_pattern(ewf_tokenizer* tokenizer_ptr, const ewf_tokenizer_basic_pattern* tokenizer_pattern_ptr, bool* match_ptr);

/**
 * @brief To be called when the interface receives data
 * @param[in] tokenizer_ptr a pointer to the tokenizer structure
 * @param[in] buffer_ptr a pointer to the received buffer
 * @param[in] buffer_length the length of the received data buffer
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_receive(ewf_tokenizer* tokenizer_ptr);

/**
 * @brief Set the interface message tokenizer pattern
 * @param[in] tokenizer_data_ptr a pointer to the tokenizer data structure
 * @param[in] tokenizer_patter_ptr a pointer to a tokenizer pattern that will be set in the interface as the message tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_message_pattern_set(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern* tokenizer_patter_ptr);

/**
 * @brief Get the interface message tokenizer pattern
 * @param[in] tokenizer_data_ptr a pointer to the tokenizer data structure
 * @param[in,out] tokenizer_patter_ptr_ptr a pointer to a pointer to a tokenizer pattern that will get the current message tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_message_pattern_get(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern** tokenizer_patter_ptr_ptr);

/**
 * @brief Set the interface command response end tokenizer pattern
 * @param[in] tokenizer_data_ptr a pointer to the tokenizer data structure
 * @param[in] tokenizer_patter_ptr a pointer to a tokenizer pattern that will be set in the interface as the command response end tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_command_response_end_pattern_set(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern* tokenizer_patter_ptr);

/**
 * @brief Get the interface command response end tokenizer pattern
 * @param[in] tokenizer_data_ptr a pointer to the tokenizer data structure
 * @param[in,out] tokenizer_patter_ptr_ptr a pointer to a pointer to a tokenizer pattern that will get the current command response end tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_command_response_end_pattern_get(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern** tokenizer_patter_ptr_ptr);

/**
 * @brief Set the interface command response tokenizer pattern
 * @param[in] tokenizer_data_ptr a pointer to the tokenizer data structure
 * @param[in] tokenizer_patter_ptr a pointer to a tokenizer pattern that will be set in the interface as the current command response tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_command_response_pattern_set(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern* tokenizer_patter_ptr);

/**
 * @brief Get the interface command response tokenizer pattern
 * @param[in] tokenizer_data_ptr a pointer to the tokenizer data structure
 * @param[in,out] tokenizer_patter_ptr_ptr a pointer to a pointer to a tokenizer pattern that will get the current command response tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_command_response_pattern_get(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern** tokenizer_patter_ptr_ptr);

/**
 * @brief Set the interface URC tokenizer pattern
 * @param[in] tokenizer_data_ptr a pointer to the tokenizer data structure
 * @param[in] tokenizer_patter_ptr a pointer to a tokenizer pattern that will be set in the interface as the URC tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_urc_pattern_set(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern* tokenizer_patter_ptr);

/**
 * @brief Get the interface URC tokenizer pattern
 * @param[in] tokenizer_data_ptr a pointer to the tokenizer data structure
 * @param[in,out] tokenizer_patter_ptr_ptr a pointer to a pointer to a tokenizer pattern that will get the URC tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_tokenizer_basic_urc_pattern_get(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern** tokenizer_patter_ptr_ptr);

#ifdef EWF_PARAMETER_CHECKING
#define EWF_TOKENIZER_BASIC_INITIALIZE_HEADER(tokenizer_ptr)                                                                                    \
do {                                                                                                                                            \
(tokenizer_ptr)->struct_magic = EWF_TOKENIZER_STRUCT_MAGIC;                                                                                     \
(tokenizer_ptr)->struct_size = EWF_TOKENIZER_STRUCT_SIZE;                                                                                       \
(tokenizer_ptr)->struct_version = EWF_TOKENIZER_VERSION;                                                                                        \
(tokenizer_ptr)->struct_type = EWF_TOKENIZER_TYPE_BASIC;                                                                                        \
} while(0)
#else
#define EWF_TOKENIZER_THREADX_INITIALIZE_HEADER(tokenizer_ptr)
#endif /* EWF_PARAMETER_CHECKING */

/**
 * @brief Declare a tokenizer basic
 * @param[in,out] tokenizer_ptr a pointer to an tokenizer that will be initialized to point to the one statically declared by the macro
 * @param[in] tokenizer_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 * @param[in] block_count the number of blocks
 * @param[in] block_size the size of each block
 */
#define EWF_TOKENIZER_BASIC_STATIC_DECLARE(tokenizer_ptr, tokenizer_name_symb)                                                                  \
do {                                                                                                                                            \
static ewf_tokenizer_basic_data ewf_adapter_quectel_bg95_tokenizer_basic_data__##adapter_name_symb = {0};                                       \
static ewf_tokenizer ewf_adapter_quectel_bg95_tokenizer__##adapter_name_symb  = {0};                                                            \
tokenizer_ptr = &(ewf_adapter_quectel_bg95_tokenizer__##adapter_name_symb);                                                                     \
tokenizer_ptr->data_ptr = &(ewf_adapter_quectel_bg95_tokenizer_basic_data__##adapter_name_symb);                                                \
tokenizer_ptr->init = ewf_tokenizer_basic_init;                                                                                                 \
tokenizer_ptr->clean = ewf_tokenizer_basic_clean;                                                                                               \
tokenizer_ptr->send = ewf_tokenizer_basic_send;                                                                                                 \
tokenizer_ptr->receive = ewf_tokenizer_basic_receive;                                                                                           \
EWF_TOKENIZER_BASIC_INITIALIZE_HEADER(tokenizer_ptr);                                                                                           \
} while(0)

/************************************************************************//**
 * @} // group_tokenizer_basic
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_tokenizer_basic__h__included__ */
