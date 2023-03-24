/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework SIMCom common adapter API
 ****************************************************************************/

#include "ewf_adapter_simcom_common.h"
#include "ewf_tokenizer_basic.h"

char ewf_adapter_simcom_common_command_response_end_tokenizer_pattern5_str[] = "\r\n+CME ERROR: ???\r\n";
char ewf_adapter_simcom_common_command_response_end_tokenizer_pattern4_str[] = "\r\n+CME ERROR: ??\r\n";
char ewf_adapter_simcom_common_command_response_end_tokenizer_pattern3_str[] = "\r\n+CME ERROR: ?\r\n";
char ewf_adapter_simcom_common_command_response_end_tokenizer_pattern2_str[] = "\r\nERROR\r\n";
char ewf_adapter_simcom_common_command_response_end_tokenizer_pattern1_str[] = "\r\nOK\r\n";

static ewf_tokenizer_basic_pattern ewf_adapter_simcom_common_command_response_end_tokenizer_pattern5 =
{
    NULL,
    ewf_adapter_simcom_common_command_response_end_tokenizer_pattern5_str,
    sizeof(ewf_adapter_simcom_common_command_response_end_tokenizer_pattern5_str) - 1,
    true,
};

static ewf_tokenizer_basic_pattern ewf_adapter_simcom_common_command_response_end_tokenizer_pattern4 =
{
    &ewf_adapter_simcom_common_command_response_end_tokenizer_pattern5,
    ewf_adapter_simcom_common_command_response_end_tokenizer_pattern4_str,
    sizeof(ewf_adapter_simcom_common_command_response_end_tokenizer_pattern4_str) - 1,
    true,
};

static ewf_tokenizer_basic_pattern ewf_adapter_simcom_common_command_response_end_tokenizer_pattern3 =
{
    &ewf_adapter_simcom_common_command_response_end_tokenizer_pattern4,
    ewf_adapter_simcom_common_command_response_end_tokenizer_pattern3_str,
    sizeof(ewf_adapter_simcom_common_command_response_end_tokenizer_pattern3_str) - 1,
    true,
};

static ewf_tokenizer_basic_pattern ewf_adapter_simcom_common_command_response_end_tokenizer_pattern2 =
{
    &ewf_adapter_simcom_common_command_response_end_tokenizer_pattern3,
    ewf_adapter_simcom_common_command_response_end_tokenizer_pattern2_str,
    sizeof(ewf_adapter_simcom_common_command_response_end_tokenizer_pattern2_str) - 1,
    false,
};

static ewf_tokenizer_basic_pattern ewf_adapter_simcom_common_command_response_end_tokenizer_pattern1 =
{
    &ewf_adapter_simcom_common_command_response_end_tokenizer_pattern2,
    ewf_adapter_simcom_common_command_response_end_tokenizer_pattern1_str,
    sizeof(ewf_adapter_simcom_common_command_response_end_tokenizer_pattern1_str) - 1,
    false,
};

static ewf_tokenizer_basic_pattern* ewf_adapter_simcom_common_command_response_end_tokenizer_pattern_ptr = &ewf_adapter_simcom_common_command_response_end_tokenizer_pattern1;

char ewf_adapter_simcom_common_urc_tokenizer_pattern1_str[] = "\r\n";

static ewf_tokenizer_basic_pattern ewf_adapter_simcom_common_urc_tokenizer_pattern1 =
{
    NULL,
    ewf_adapter_simcom_common_urc_tokenizer_pattern1_str,
    sizeof(ewf_adapter_simcom_common_urc_tokenizer_pattern1_str) - 1,
    false,
};

static ewf_tokenizer_basic_pattern* ewf_adapter_simcom_common_urc_tokenizer_pattern_ptr = &ewf_adapter_simcom_common_urc_tokenizer_pattern1;

ewf_result ewf_adapter_simcom_common_tokenizer_init(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)interface_ptr->tokenizer_ptr->data_ptr;

    /* Initialize the interface tokenizer patterns */

    if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_basic_data_ptr, ewf_adapter_simcom_common_command_response_end_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface command response end tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    if (ewf_result_failed(result = ewf_tokenizer_basic_urc_pattern_set(tokenizer_basic_data_ptr, ewf_adapter_simcom_common_urc_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface URC tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    return EWF_RESULT_OK;
}
