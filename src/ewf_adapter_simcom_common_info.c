/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework SIMCom common adapter driver
 ****************************************************************************/

#include "ewf_adapter_simcom_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

ewf_adapter_api_info ewf_adapter_simcom_common_api_info =
{
    ewf_adapter_simcom_common_info,
    ewf_adapter_simcom_common_get_ipv4_address,
    ewf_adapter_simcom_common_get_ipv4_netmask,
    ewf_adapter_simcom_common_get_ipv4_gateway,
    ewf_adapter_simcom_common_get_ipv4_dns,
    NULL,
    NULL,
    NULL,
};

ewf_result ewf_adapter_simcom_common_info(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t * response_ptr;
    uint32_t response_length;

    EWF_LOG("[ADAPTER INFORMATION START]\n");

    /* Display Product Identification Information */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "ATI\r"))) return result;
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

    /* Get system time */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CCLK?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Check operator info */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+COPS?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Get signal strength */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CSQ\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Get network registration status */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGREG?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Attachment or Detachment of PS */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGATT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Show PDP address */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGPADDR\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Get APN and IP address */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGCONTRDP\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    EWF_LOG("[ADAPTER INFORMATION END]\n");

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_simcom_common_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t * address_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t * response_ptr;
    uint32_t response_length;

    if (!address_ptr)
    {
        EWF_LOG_ERROR("The address_ptr parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIACT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 1 * EWF_PLATFORM_TICKS_PER_SECOND))) return result;

    if (response_ptr)
    {
        int context_id;
        int context_state;
        int context_type;
        int address_a;
        int address_b;
        int address_c;
        int address_d;
        int fields = sscanf((char *) response_ptr, "\r\n+QIACT: %d,%d,%d,\"%d.%d.%d.%d\"", &context_id, &context_state, &context_type, &address_a, &address_b, &address_c, &address_d);
        ewf_interface_release(interface_ptr, response_ptr);
        if (fields !=7)
        {
            EWF_LOG_ERROR("Unexpected response format.\n");
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

ewf_result ewf_adapter_simcom_common_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t * netmask_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!netmask_ptr)
    {
        EWF_LOG_ERROR("The netmask parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    *netmask_ptr = 0xFFFFFFFF;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_simcom_common_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t * gateway_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!gateway_ptr)
    {
        EWF_LOG_ERROR("The gateway parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    return ewf_adapter_simcom_common_get_ipv4_address(adapter_ptr, gateway_ptr);
}

ewf_result ewf_adapter_simcom_common_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t * dns)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t* response_ptr;
    uint32_t response_length;

    if (!dns)
    {
        EWF_LOG_ERROR("The dns parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIDNSCFG=1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 1 * EWF_PLATFORM_TICKS_PER_SECOND))) return result;

    if (response_ptr)
    {
        int context_id;

        int dns1_a;
        int dns1_b;
        int dns1_c;
        int dns1_d;

        int dns2_a;
        int dns2_b;
        int dns2_c;
        int dns2_d;

        int fields = sscanf(
            (char *) response_ptr,
            "\r\n+QIDNSCFG: %d,\"%d.%d.%d.%d\",\"%d.%d.%d.%d\"",
            &context_id,
            &dns1_a, &dns1_b, &dns1_c, &dns1_d,
            &dns2_a, &dns2_b, &dns2_c, &dns2_d);
        if (fields !=9)
        {
            EWF_LOG_ERROR("Unexpected response format.\n");
            return EWF_RESULT_UNEXPECTED_RESPONSE;
        }

        *dns =
            ((dns1_a & 0xFF) << 24) |
            ((dns1_b & 0xFF) << 16) |
            ((dns1_c & 0xFF) << 8) |
            (dns1_d & 0xFF);

        ewf_interface_release(interface_ptr, response_ptr);
    }

    return EWF_RESULT_OK;
}
