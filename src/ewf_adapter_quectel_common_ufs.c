/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The EWF Common Quectel adapter driver UFS implementation
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

ewf_result ewf_adapter_quectel_common_ufs_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    return EWF_RESULT_UNHANDLED_URC;
}

ewf_result ewf_adapter_quectel_common_ufs_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_ufs_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_ufs_list(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t* response;
    uint32_t length;
    bool finished = false;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QFLST=\"*\"\r"))) return result;
    do
    {
        if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response, &length, 1 * EWF_PLATFORM_TICKS_PER_SECOND))) return result;
        if (ewfl_str_contains_str((char*)response, "\r\nOK\r\n")) finished = true;
        ewf_interface_release(interface_ptr, response);
    } while (!finished);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_ufs_delete(ewf_adapter* adapter_ptr, const char* const filename_str)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QFDEL=\"", filename_str, "\"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_ufs_upload(ewf_adapter* adapter_ptr, const char* filename_str, const uint8_t* data, uint32_t length)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    EWF_LOG("\newf_adapter_ufs_upload: [%s] (%p) (%lu)\n", filename_str, data, length);
    char tokenizer_pattern_str[] = "\r\nCONNECT\r\n";
        ewf_interface_tokenizer_pattern tokenizer_pattern = {
            NULL,
            tokenizer_pattern_str ,
            sizeof(tokenizer_pattern_str)-1,
            false,
        };

    char file_size_str[5];
    const char* file_size_cstr = ewfl_unsigned_to_str(length, file_size_str, sizeof(file_size_str));

    if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern))) return result;
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QFUPL=\"", filename_str, "\",", file_size_cstr, ",10,0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_str))) return result;
    if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_send(interface_ptr, data, length))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    return EWF_RESULT_OK;
}
