/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework ESPRESSIF common adapter driver
 ****************************************************************************/

#include "ewf_adapter_espressif_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

ewf_adapter_api_info ewf_adapter_espressif_common_api_info =
{
    ewf_adapter_espressif_common_info,
    ewf_adapter_espressif_common_get_ipv4_address,
    ewf_adapter_espressif_common_get_ipv4_netmask,
    ewf_adapter_espressif_common_get_ipv4_gateway,
    ewf_adapter_espressif_common_get_ipv4_dns,
    NULL,
    NULL,
    NULL,
};

ewf_result ewf_adapter_espressif_common_info(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    EWF_LOG("[ADAPTER INFORMATION START]\n");

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+GMR\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPSTAMAC?\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPAPMAC?\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPMUX?\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPMODE?\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPSTO?\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CWLAP\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CWSAP?\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CWJAP?\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;


    uint32_t ip_address = 0;
    uint32_t network_mask = 0;
    uint32_t gateway_address = 0;
    uint32_t dns_address = 0;

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_address(adapter_ptr, &ip_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 address: ewf_result %d.\n", result);
        return result;
    }

    EWF_LOG("\nIP address: %lu.%lu.%lu.%lu\r\n",
        (ip_address >> 24 & 0xFF),
        (ip_address >> 16 & 0xFF),
        (ip_address >> 8 & 0xFF),
        (ip_address & 0xFF));

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_netmask(adapter_ptr, &network_mask)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 netmask: ewf_result %d.\n", result);
        return result;
    }

    EWF_LOG("\nMask: %lu.%lu.%lu.%lu\r\n",
        (network_mask >> 24 & 0xFF),
        (network_mask >> 16 & 0xFF),
        (network_mask >> 8 & 0xFF),
        (network_mask & 0xFF));

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_gateway(adapter_ptr, &gateway_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 gateway: ewf_result %d.\n", result);
        return result;
    }

    EWF_LOG("\nGateway: %lu.%lu.%lu.%lu\r\n",
        (gateway_address >> 24 & 0xFF),
        (gateway_address >> 16 & 0xFF),
        (gateway_address >> 8 & 0xFF),
        (gateway_address & 0xFF));

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_dns(adapter_ptr, &dns_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 DNS: ewf_result %d.\n", result);
        // continue
    }

    EWF_LOG("\nDNS: %lu.%lu.%lu.%lu\r\n",
        (dns_address >> 24 & 0xFF),
        (dns_address >> 16 & 0xFF),
        (dns_address >> 8 & 0xFF),
        (dns_address & 0xFF));

    EWF_LOG("[ADAPTER INFORMATION END]\n");

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t * address_ptr)
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

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIFSR\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 3 * EWF_PLATFORM_TICKS_PER_SECOND))) return result;

    if (!response_ptr)
    {
        EWF_LOG_ERROR("The response_ptr is NULL.\n");
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    result = EWF_RESULT_OK;

    response_ptr[response_length] = 0;
    char* match_str = strstr(response_ptr, "+CIFSR:STAIP");
    if (!match_str)
    {
        EWF_LOG_ERROR("No IP address information found in the response.\n");
        result = EWF_RESULT_UNEXPECTED_RESPONSE;
    }
    else
    {
        int address_a;
        int address_b;
        int address_c;
        int address_d;
        int fields = sscanf(
            (char*)response_ptr,
            "+CIFSR:STAIP,\"%d.%d.%d.%d\"",
            &address_a, &address_b, &address_c, &address_d);
        if (fields != 4)
        {
            EWF_LOG_ERROR("Unexpected response format.\n");
            result = EWF_RESULT_UNEXPECTED_RESPONSE;
        }
        else
        {
            *address_ptr =
                ((address_a & 0xFF) << 24) |
                ((address_b & 0xFF) << 16) |
                ((address_c & 0xFF) << 8) |
                (address_d & 0xFF);
        }
    }

    ewf_interface_release(interface_ptr, response_ptr);

    return result;
}

ewf_result ewf_adapter_espressif_common_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t * netmask_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!netmask_ptr)
    {
        EWF_LOG_ERROR("The netmask parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    // Match everything
    *netmask_ptr = 0xFFFFFFFF;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t * gateway_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!gateway_ptr)
    {
        EWF_LOG_ERROR("The gateway parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    // No explicit gateway, our own IP is the gateway
    return ewf_adapter_espressif_common_get_ipv4_address(adapter_ptr, gateway_ptr);
}

ewf_result ewf_adapter_espressif_common_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t * dns_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t* response_ptr;
    uint32_t response_length;

    if (!dns_ptr)
    {
        EWF_LOG_ERROR("The dns parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPDNS_CUR?\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 1 * EWF_PLATFORM_TICKS_PER_SECOND))) return result;

    if (!response_ptr)
    {
        EWF_LOG_ERROR("The response_ptr is NULL.\n");
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    result = EWF_RESULT_OK;

    response_ptr[response_length] = 0;
    char* match_str = strstr(response_ptr, "+CIPDNS_CUR");
    if (!match_str)
    {
        EWF_LOG_ERROR("No DNS address information found int he response.\n");
        result = EWF_RESULT_UNEXPECTED_RESPONSE;
    }
    else
    {
        int dns1_a;
        int dns1_b;
        int dns1_c;
        int dns1_d;

        /*
        int dns2_a;
        int dns2_b;
        int dns2_c;
        int dns2_d;
        */

        int fields = sscanf(
            (char*)response_ptr,
            "+CIPDNS_CUR: \"%d.%d.%d.%d\"\r\n",
            &dns1_a, &dns1_b, &dns1_c, &dns1_d);
        if (fields != 4)
        {
            fields = sscanf(
                (char*)response_ptr,
                "+CIPDNS_CUR:%d.%d.%d.%d\r\n",
                &dns1_a, &dns1_b, &dns1_c, &dns1_d);
            if (fields != 4)
            {
                EWF_LOG_ERROR("Unexpected response format.\n");
                result = EWF_RESULT_UNEXPECTED_RESPONSE;
            }
        }

        *dns_ptr =
            ((dns1_a & 0xFF) << 24) |
            ((dns1_b & 0xFF) << 16) |
            ((dns1_c & 0xFF) << 8) |
            (dns1_d & 0xFF);
    }

    ewf_interface_release(interface_ptr, response_ptr);

    return result;
}
