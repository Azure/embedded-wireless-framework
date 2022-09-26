/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * brief The Embedded Wireless Framework Renesas RYZ014 adapter driver
 ****************************************************************************/

#include "ewf_adapter_renesas_ryz014.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

ewf_adapter_api_info ewf_adapter_renesas_ryz014_api_info =
{
    ewf_adapter_renesas_ryz014_info,
    ewf_adapter_renesas_ryz014_get_ipv4_address,
    ewf_adapter_renesas_ryz014_get_ipv4_netmask,
    ewf_adapter_renesas_ryz014_get_ipv4_gateway,
    ewf_adapter_renesas_ryz014_get_ipv4_dns,
    NULL,
    NULL,
    NULL,
};

ewf_result ewf_adapter_renesas_ryz014_info(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Display Product Identification Information */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "ATI\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Show ICCID */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNCCID\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Request International Mobile Subscriber Identity (IMSI) */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIMI\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Check sim card is present and active */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CPIN?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Check module name */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGMM\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Firmware version */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGMR\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Get IMEI number */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+GSN\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Get IMEI number */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGSN=1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Sim slot */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CSUS?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Sim state */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNSIMST?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Get system time */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CCLK?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Check operator info */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+COPS?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Extended Signal Quality */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CSQ\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Get more detailed signal info */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CESQ\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Sim State */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNSIMST=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Show PDP context state */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGACT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Attachment or Detachment of PS */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGATT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGDCONT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Show PDP address */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGPADDR\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Get APN and IP address */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGCONTRDP\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CFUN?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNSPCFG\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNSCFG?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t* address_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t* response;
    uint32_t length;

    if (!address_ptr)
    {
        EWF_LOG_ERROR("The address_ptr parameter cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(interface_ptr->current_context, context_id_str, sizeof(context_id_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CGPADDR=", context_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response, &length, 1 * EWF_PLATFORM_TICKS_PER_SECOND))) return result;

    if (response)
    {
        int context_id;
        int address_a;
        int address_b;
        int address_c;
        int address_d;
        int fields = sscanf((char*)response, "\r\n+CGPADDR: %d,\"%d.%d.%d.%d\"", &context_id, &address_a, &address_b, &address_c, &address_d);
        ewf_interface_release(interface_ptr, response);
        if (fields < 5)
        {
            EWF_LOG_ERROR("Unexpected response format.");
            return EWF_RESULT_UNEXPECTED_RESPONSE;
        }

        *address_ptr =
            ((address_a & 0xFF) << 24) |
            ((address_b & 0xFF) << 16) |
            ((address_c & 0xFF) << 8) |
            (address_d & 0xFF);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t* netmask_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!netmask_ptr)
    {
        EWF_LOG_ERROR("The netmask parameter cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    *netmask_ptr = 0xFFFFFFFF;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t* gateway_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!gateway_ptr)
    {
        EWF_LOG_ERROR("The gateway parameter cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    return ewf_adapter_get_ipv4_address(adapter_ptr, gateway_ptr);
}

ewf_result ewf_adapter_renesas_ryz014_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t* dns)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t* response;
    uint32_t length;

    if (!dns)
    {
        EWF_LOG_ERROR("The dns parameter cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(interface_ptr->current_context, context_id_str, sizeof(context_id_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CGCONTRDP=", context_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response, &length, 1 * EWF_PLATFORM_TICKS_PER_SECOND))) return result;

    if (response)
    {
        int context_id;
        int bearer_id;
        char apn[64];

        int dns1_a;
        int dns1_b;
        int dns1_c;
        int dns1_d;

        int dns2_a;
        int dns2_b;
        int dns2_c;
        int dns2_d;

        int fields = sscanf(
            (char*)response,
            "\r\n+CGCONTRDP: %d,%d,\"%64[^\"]\",\"%*d.%*d.%*d.%*d.%*d.%*d.%*d.%*d\",\"\",\"%d.%d.%d.%d\",\"%d.%d.%d.%d\"",
            &context_id, &bearer_id, apn,
            &dns1_a, &dns1_b, &dns1_c, &dns1_d,
            &dns2_a, &dns2_b, &dns2_c, &dns2_d);
        if (fields < 9)
        {
            EWF_LOG_ERROR("Unexpected response format.");
            return EWF_RESULT_UNEXPECTED_RESPONSE;
        }

        *dns =
            ((dns1_a & 0xFF) << 24) |
            ((dns1_b & 0xFF) << 16) |
            ((dns1_c & 0xFF) << 8) |
            (dns1_d & 0xFF);

        ewf_interface_release(interface_ptr, response);
    }

    return EWF_RESULT_OK;
}
