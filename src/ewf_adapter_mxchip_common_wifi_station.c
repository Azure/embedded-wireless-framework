/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework MX-CHIP adapter Wifi station API
 ****************************************************************************/

#include "ewf_adapter_mxchip_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

ewf_adapter_api_wifi_station ewf_adapter_mxchip_common_api_wifi_station =
{
    ewf_adapter_mxchip_common_wifi_station_connect,
    ewf_adapter_mxchip_common_wifi_station_disconnect,
};

ewf_result ewf_adapter_mxchip_common_wifi_station_connect(ewf_adapter* adapter_ptr, const char* ssid_str, const char* password_str)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_mxchip_common* implementation_ptr = (ewf_adapter_mxchip_common*)adapter_ptr->implementation_ptr;

    ewf_result result = EWF_RESULT_OK;

    {
        uint8_t* response_ptr;
        uint32_t response_length;

        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+WJAP=", ssid_str, ",", password_str, "\r", NULL))) return result;
        if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 10 * EWF_PLATFORM_TICKS_PER_SECOND)))
        {
            EWF_LOG_ERROR("Failed to receive a response.\n");
            return result;
        }

        if (!response_ptr)
        {
            EWF_LOG_ERROR("The response_ptr is NULL.\n");
            return EWF_RESULT_UNEXPECTED_RESPONSE;
        }

        result = EWF_RESULT_OK;

        char expected_ok_str[] = "\r\nOK\r\n";

        bool ok_found = ewfl_buffer_ends_with(response_ptr, response_length, (uint8_t*)expected_ok_str, sizeof(expected_ok_str)-1);

        result = ewf_interface_release(interface_ptr, response_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Failed to release a buffer.\n");
        }

        if (!ok_found)
        {
            EWF_LOG_ERROR("The connection did not response OK.\n");
            return EWF_RESULT_UNEXPECTED_RESPONSE;
        }
    }

    {
        while (implementation_ptr->status_station != true)
        {
            ewf_platform_sleep(1);
            ewf_interface_poll(interface_ptr);
        }
    }

    return result;
}

ewf_result ewf_adapter_mxchip_common_wifi_station_disconnect(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WJAPQ\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    return result;
}
