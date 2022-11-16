/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework modem API (3GPP) implementation.
 ****************************************************************************/

#include "ewf_adapter_api_modem.h"
#include "ewf_lib.h"

#include <stddef.h>

ewf_result ewf_adapter_modem_custom_command_send(ewf_adapter* adapter_ptr, const char* command_str)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    result = ewf_interface_send_command(interface_ptr, command_str);
    if (ewf_result_failed(result)) return result;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_custom_command_receive(ewf_adapter* adapter_ptr, char** buffer_ptr_ptr, uint32_t* buffer_length_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    result = ewf_interface_receive_response(interface_ptr, (uint8_t**)buffer_ptr_ptr, buffer_length_ptr, (uint32_t)-1);
    if (ewf_result_failed(result)) return result;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_functionality_set(ewf_adapter* adapter_ptr, const char * fun)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CFUN=", (fun ? fun : "0" /* disable by default*/), "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CFUN?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}
