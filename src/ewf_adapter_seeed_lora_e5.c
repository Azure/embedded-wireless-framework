/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Seeed LoRa-E5 adapter driver
 ****************************************************************************/

#include "ewf_adapter_seeed_lora_e5.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#include "ewf_lib.h"

ewf_adapter_api_control ewf_adapter_seeed_lora_e5_api_control =
{
    ewf_adapter_seeed_lora_e5_start,
    ewf_adapter_seeed_lora_e5_stop,
};

char ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern5_str[] = "\r\n+CME ERROR: ???\r\n";
char ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern4_str[] = "\r\n+CME ERROR: ??\r\n";
char ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern3_str[] = "\r\n+CME ERROR: ?\r\n";
char ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern2_str[] = "\r\nERROR\r\n";
char ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern1_str[] = "\r\n";

static ewf_interface_tokenizer_pattern ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern5 =
{
    NULL,
    ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern5_str,
    sizeof(ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern5_str)-1,
    true,
};

static ewf_interface_tokenizer_pattern ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern4 =
{
    &ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern5,
    ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern4_str,
    sizeof(ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern4_str)-1,
    true,
};

static ewf_interface_tokenizer_pattern ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern3 =
{
    &ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern4,
    ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern3_str,
    sizeof(ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern3_str)-1,
    true,
};

static ewf_interface_tokenizer_pattern ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern2 =
{
    &ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern3,
    ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern2_str,
    sizeof(ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern2_str)-1,
    false,
};

static ewf_interface_tokenizer_pattern ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern1 =
{
    &ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern2,
    ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern1_str,
    sizeof(ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern1_str)-1,
    false,
};

static ewf_interface_tokenizer_pattern* ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern_ptr = &ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern1;

char ewf_adapter_seeed_lora_e5_urc_tokenizer_pattern1_str[] = "\r\n";

static ewf_interface_tokenizer_pattern ewf_adapter_seeed_lora_e5_urc_tokenizer_pattern1 =
{
    NULL,
    ewf_adapter_seeed_lora_e5_urc_tokenizer_pattern1_str,
    sizeof(ewf_adapter_seeed_lora_e5_urc_tokenizer_pattern1_str)-1,
    false,
};

static ewf_interface_tokenizer_pattern* ewf_adapter_seeed_lora_e5_urc_tokenizer_pattern_ptr = &ewf_adapter_seeed_lora_e5_urc_tokenizer_pattern1;

ewf_result ewf_adapter_seeed_lora_e5_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_SEEED_LORA_E5);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Initialize the interface */
    if (ewf_result_failed(result = ewf_interface_init(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to initialize the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Set the interface default timeout */
    if (ewf_result_failed(result = ewf_interface_default_timeout_set(interface_ptr, EWF_PLATFORM_TICKS_PER_SECOND * 5)))
    {
        EWF_LOG_ERROR("Failed to set the interface default timeout: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Initialize the interface tokenizer patterns */

    if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_end_pattern_set(interface_ptr, ewf_adapter_seeed_lora_e5_command_response_end_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface command response end tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    if (ewf_result_failed(result = ewf_interface_tokenizer_urc_pattern_set(interface_ptr, ewf_adapter_seeed_lora_e5_urc_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface URC tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Start the interface */
    if (ewf_result_failed(result = ewf_interface_start(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* AT - wake the modem */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

#if 0
    /* Disable local echo */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "ATE0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    /* Check that the modem is responding */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "+AT: OK\r\n"))) return result;

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_seeed_lora_e5_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_SEEED_LORA_E5);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Stop the interface */
    if (ewf_result_failed(result = ewf_interface_stop(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to clean the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Cleanup the interface */
    if (ewf_result_failed(result = ewf_interface_init(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to clean the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_seeed_lora_e5_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    /* Ignore empty URCs */
    if (ewfl_str_equals_str((char*)buffer_ptr, "\r\n"))
    {
        return EWF_RESULT_OK;
    }

    return EWF_RESULT_OK;
}

ewf_adapter_api_info ewf_adapter_seeed_lora_e5_api_info =
{
    ewf_adapter_seeed_lora_e5_info,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

ewf_result ewf_adapter_seeed_lora_e5_info(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_SEEED_LORA_E5);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    EWF_LOG("[ADAPTER INFORMATION START]\n");

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+VER\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+ID\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CH\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+POWER=TABLE\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+BEACON\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+LW=NET\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+LW=THLD\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+LW=LEN\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+TEMP\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+RTC\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+UART=TIMEOUT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    EWF_LOG("[ADAPTER INFORMATION END]\n");

    return EWF_RESULT_OK;
}
