/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The EWF Quectel modem common adapter driver tokenizer patterns and functions
 *
 * These custom function matching patterns are not reentrant, they can be used by only one interface at a time.
 * If you have more than one adapter at the same time, you will need to provide separate state for each one.
 * The code is prepared for that. Use an instance specific state structure instead of the global static here.
 *
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"
#include "ewf_tokenizer_basic.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

/************************************************************************//**
 * command response end tokenizer pattern list
 ****************************************************************************/

char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5_str[] = "\r\n+CME ERROR: ???\r\n";
char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4_str[] = "\r\n+CME ERROR: ??\r\n";
char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3_str[] = "\r\n+CME ERROR: ?\r\n";
char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2_str[] = "\r\nERROR\r\n";
char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1_str[] = "\r\nOK\r\n";

static ewf_tokenizer_basic_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5 =
{
    NULL,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5_str)-1,
    true,
};

static ewf_tokenizer_basic_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4 =
{
    &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4_str)-1,
    true,
};

static ewf_tokenizer_basic_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3 =
{
    &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3_str)-1,
    true,
};

static ewf_tokenizer_basic_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2 =
{
    &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2_str)-1,
    false,
};

static ewf_tokenizer_basic_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1 =
{
    &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1_str)-1,
    false,
};

ewf_tokenizer_basic_pattern* ewf_adapter_quectel_common_command_response_end_tokenizer_pattern_ptr = &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1;

/************************************************************************//**
 * URC tokenizer pattern list
 ****************************************************************************/

char ewf_adapter_quectel_common_urc_tokenizer_pattern1_str[] = "\r\n";

static ewf_tokenizer_basic_pattern ewf_adapter_quectel_common_urc_tokenizer_pattern1 =
{
    NULL,
    ewf_adapter_quectel_common_urc_tokenizer_pattern1_str,
    sizeof(ewf_adapter_quectel_common_urc_tokenizer_pattern1_str)-1,
    false,
};

ewf_tokenizer_basic_pattern* ewf_adapter_quectel_common_urc_tokenizer_pattern_ptr = &ewf_adapter_quectel_common_urc_tokenizer_pattern1;

/************************************************************************//**
 * Message tokenizer pattern list
 ****************************************************************************/

/*
 * Note:
 * This custom function matching pattern is not reentrant, it can be used by only one interface at a time.
 * If you have more than one adapter at the same time, you will need to provide separate state for each one.
 * The code is prepared for that. Use an instance specific state structure instead of the global static here.
 */

static struct _ewf_adapter_quectel_common_message_tokenizer_pattern_match_function_state
{
    ewf_interface* interface_ptr;

} ewf_adapter_quectel_common_message_tokenizer_pattern_match_function_state = { 0 };

static bool _ewf_adapter_quectel_common_message_tokenizer_pattern_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_quectel_common_message_tokenizer_pattern_match_function_state* state_ptr =
        (struct _ewf_adapter_quectel_common_message_tokenizer_pattern_match_function_state*)pattern_ptr->data_ptr;

#define TEST_CSTR(cstr) ((buffer_length >= (sizeof(cstr)-1)) && ewfl_buffer_equals_buffer(buffer_ptr, (const uint8_t*)cstr, (sizeof(cstr)-1)))

    if 
        (
            /* Test for different strings */
            (
                (
                    TEST_CSTR("+QIURC: ") ||
                    TEST_CSTR("\r\n+QIURC: ") ||
                    TEST_CSTR("\r\n\r\n+QIURC: ") ||

                    TEST_CSTR("+QMTSTAT: ") ||
                    TEST_CSTR("\r\n+QMTSTAT: ") ||
                    TEST_CSTR("\r\n\r\n+QMTSTAT: ") ||

                    TEST_CSTR("+QMTRECV: ") ||
                    TEST_CSTR("\r\n+QMTRECV: ") ||
                    TEST_CSTR("\r\n\r\n+QMTRECV: ") ||
                    TEST_CSTR("\r\n\r\n\r\n+QMTRECV: ")
                )

                && ((buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n'))
            )

        )
    {
        /* Set the interface to URC mode */
        if (state_ptr->interface_ptr && state_ptr->interface_ptr->tokenizer_ptr && state_ptr->interface_ptr->tokenizer_ptr->data_ptr)
        {
            ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)state_ptr->interface_ptr->tokenizer_ptr->data_ptr;
            tokenizer_basic_data_ptr->command_mode = false;
        }

        /* Signal the match */
        return true;
    }
    else
    {
        /* No match */
        return false;
    }

#undef TEST_CSTR

}

static ewf_tokenizer_basic_pattern ewf_adapter_quectel_common_message_tokenizer_pattern =
{
    NULL,
    NULL,
    0,
    false,
    _ewf_adapter_quectel_common_message_tokenizer_pattern_match_function,
    &ewf_adapter_quectel_common_message_tokenizer_pattern_match_function_state
};

ewf_tokenizer_basic_pattern* ewf_adapter_quectel_common_message_tokenizer_pattern_ptr = &ewf_adapter_quectel_common_message_tokenizer_pattern;

ewf_result ewf_adapter_quectel_common_tokenizer_init(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)interface_ptr->tokenizer_ptr->data_ptr;

    ewf_adapter_quectel_common_message_tokenizer_pattern_match_function_state.interface_ptr = interface_ptr;

    result = ewf_tokenizer_basic_message_pattern_set(tokenizer_basic_data_ptr, ewf_adapter_quectel_common_message_tokenizer_pattern_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to set the interface message tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    result = ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_basic_data_ptr, ewf_adapter_quectel_common_command_response_end_tokenizer_pattern_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to set the interface command response end tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    result = ewf_tokenizer_basic_urc_pattern_set(tokenizer_basic_data_ptr, ewf_adapter_quectel_common_urc_tokenizer_pattern_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to set the interface URC tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    return EWF_RESULT_OK;
}
