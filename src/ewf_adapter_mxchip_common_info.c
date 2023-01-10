/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework MX-CHIP common adapter driver
 ****************************************************************************/

#include "ewf_adapter_mxchip_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

ewf_adapter_api_info ewf_adapter_mxchip_common_api_info =
{
    ewf_adapter_mxchip_common_info,
    ewf_adapter_mxchip_common_get_ipv4_address,
    ewf_adapter_mxchip_common_get_ipv4_netmask,
    ewf_adapter_mxchip_common_get_ipv4_gateway,
    ewf_adapter_mxchip_common_get_ipv4_dns,
    NULL,
    NULL,
    NULL,
};

ewf_result ewf_adapter_mxchip_common_info(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    EWF_LOG("[ADAPTER INFORMATION START]\n");

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+FWVER?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SYSTIME?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+MEMFREE?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+FLASHLOCK?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WEVENT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPEVENT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+UART?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+UARTFOMAT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+UARTE?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WFVER?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WMAC?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WSCANOPT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+AT+WDHCP?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WSAPIP?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WSAP=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WJAPIP?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    // This code will query the adapter IPv4 address, netmask, gateway and DNS
    // It will fail if the adapter is not connected to a network
    // It is disabled by default
#if 0
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
#endif

    EWF_LOG("[ADAPTER INFORMATION END]\n");

    /* All ok! */
    return EWF_RESULT_OK;
}

static ewf_result _ewf_adapter_mxchip_common_query_ips(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_mxchip_common* implementation_ptr = (ewf_adapter_mxchip_common*)adapter_ptr->implementation_ptr;

    ewf_result result;
    uint8_t* response_ptr;
    uint32_t response_length;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WJAPIP?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 3 * EWF_PLATFORM_TICKS_PER_SECOND))) return result;

    if (!response_ptr)
    {
        EWF_LOG_ERROR("The response_ptr is NULL.\n");
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    result = EWF_RESULT_OK;

    response_ptr[response_length] = 0;
    char* match_str = strstr((char*)response_ptr, "+WJAPIP:");
    if (!match_str)
    {
        EWF_LOG_ERROR("No IP address information found in the response.\n");
        result = EWF_RESULT_UNEXPECTED_RESPONSE;
    }
    else
    {
        int ipv4_address_a = 0, ipv4_address_b = 0, ipv4_address_c = 0, ipv4_address_d = 0;
        int ipv4_netmask_a = 0, ipv4_netmask_b = 0, ipv4_netmask_c = 0, ipv4_netmask_d = 0;
        int ipv4_gateway_a = 0, ipv4_gateway_b = 0, ipv4_gateway_c = 0, ipv4_gateway_d = 0;
        int ipv4_dns_a = 0, ipv4_dns_b = 0, ipv4_dns_c = 0, ipv4_dns_d = 0;
        int fields = sscanf(
            (char*)match_str,
            "+WJAPIP:%d.%d.%d.%d,%d.%d.%d.%d,%d.%d.%d.%d,%d.%d.%d.%d",
            &ipv4_address_a, &ipv4_address_b, &ipv4_address_c, &ipv4_address_d,
            &ipv4_netmask_a, &ipv4_netmask_b, &ipv4_netmask_c, &ipv4_netmask_d,
            &ipv4_gateway_a, &ipv4_gateway_b, &ipv4_gateway_c, &ipv4_gateway_d,
            &ipv4_dns_a, &ipv4_dns_b, &ipv4_dns_c, &ipv4_dns_d);
        if (fields != 12 && fields != 16)
        {
            EWF_LOG_ERROR("Unexpected response format.\n");
            result = EWF_RESULT_UNEXPECTED_RESPONSE;
        }
        else
        {
            implementation_ptr->ipv4_address =
                ((ipv4_address_a & 0xFF) << 24) |
                ((ipv4_address_b & 0xFF) << 16) |
                ((ipv4_address_c & 0xFF) << 8) |
                (ipv4_address_d & 0xFF);

            implementation_ptr->ipv4_netmask =
                ((ipv4_netmask_a & 0xFF) << 24) |
                ((ipv4_netmask_b & 0xFF) << 16) |
                ((ipv4_netmask_c & 0xFF) << 8) |
                (ipv4_netmask_d & 0xFF);

            implementation_ptr->ipv4_gateway =
                ((ipv4_gateway_a & 0xFF) << 24) |
                ((ipv4_gateway_b & 0xFF) << 16) |
                ((ipv4_gateway_c & 0xFF) << 8) |
                (ipv4_gateway_d & 0xFF);

            implementation_ptr->ipv4_dns =
                ((ipv4_dns_a & 0xFF) << 24) |
                ((ipv4_dns_b & 0xFF) << 16) |
                ((ipv4_dns_c & 0xFF) << 8) |
                (ipv4_dns_d & 0xFF);
        }
    }

    ewf_interface_release(interface_ptr, response_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_mxchip_common_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t * address_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_mxchip_common* implementation_ptr = (ewf_adapter_mxchip_common*)adapter_ptr->implementation_ptr;

    if (!address_ptr)
    {
        EWF_LOG_ERROR("The address_ptr parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result = EWF_RESULT_OK;

    result = _ewf_adapter_mxchip_common_query_ips(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to query the adapter IPv4 data.\n");
        return result;
    }

    *address_ptr = implementation_ptr->ipv4_address;

    return result;
}

ewf_result ewf_adapter_mxchip_common_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t * netmask_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_mxchip_common* implementation_ptr = (ewf_adapter_mxchip_common*)adapter_ptr->implementation_ptr;

    if (!netmask_ptr)
    {
        EWF_LOG_ERROR("The netmask parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result = EWF_RESULT_OK;

    result = _ewf_adapter_mxchip_common_query_ips(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to query the adapter IPv4 data.\n");
        return result;
    }

    *netmask_ptr = implementation_ptr->ipv4_netmask;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_mxchip_common_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t * gateway_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_mxchip_common* implementation_ptr = (ewf_adapter_mxchip_common*)adapter_ptr->implementation_ptr;

    if (!gateway_ptr)
    {
        EWF_LOG_ERROR("The gateway parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result = EWF_RESULT_OK;

    result = _ewf_adapter_mxchip_common_query_ips(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to query the adapter IPv4 data.\n");
        return result;
    }

    *gateway_ptr = implementation_ptr->ipv4_gateway;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_mxchip_common_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t * dns_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_mxchip_common* implementation_ptr = (ewf_adapter_mxchip_common*)adapter_ptr->implementation_ptr;

    if (!dns_ptr)
    {
        EWF_LOG_ERROR("The dns parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result = EWF_RESULT_OK;

    result = _ewf_adapter_mxchip_common_query_ips(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to query the adapter IPv4 data.\n");
        return result;
    }

    *dns_ptr = implementation_ptr->ipv4_dns;

    return result;
}
