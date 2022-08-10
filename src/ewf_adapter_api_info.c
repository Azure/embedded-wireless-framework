/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter info API implementation
 ****************************************************************************/

#include "ewf_adapter.h"

#define EWF_ADAPTER_VALIDATE_INFO_API_POINTER(adapter_ptr, function_ptr)            \
do {                                                                                \
    if ((adapter_ptr->info_api_ptr == NULL) ||                                      \
        (adapter_ptr->info_api_ptr->function_ptr == NULL))                          \
    {                                                                               \
        EWF_LOG_ERROR("The function is not implemented.");                          \
        return EWF_RESULT_NOT_SUPPORTED;                                            \
    }                                                                               \
} while(0)

ewf_result ewf_adapter_info(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_INFO_API_POINTER(adapter_ptr, info);
    return adapter_ptr->info_api_ptr->info(adapter_ptr);
}

ewf_result ewf_adapter_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t* address_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_INFO_API_POINTER(adapter_ptr, get_ipv4_address);
    return adapter_ptr->info_api_ptr->get_ipv4_address(adapter_ptr, address_ptr);
}

ewf_result ewf_adapter_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t* netmask_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_INFO_API_POINTER(adapter_ptr, get_ipv4_netmask);
    return adapter_ptr->info_api_ptr->get_ipv4_netmask(adapter_ptr, netmask_ptr);
}

ewf_result ewf_adapter_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t* gateway_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_INFO_API_POINTER(adapter_ptr, get_ipv4_gateway);
    return adapter_ptr->info_api_ptr->get_ipv4_gateway(adapter_ptr, gateway_ptr);
}

ewf_result ewf_adapter_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t* dns_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_INFO_API_POINTER(adapter_ptr, get_ipv4_dns);
    return adapter_ptr->info_api_ptr->get_ipv4_dns(adapter_ptr, dns_ptr);
}

ewf_result ewf_adapter_get_ipv6_address(ewf_adapter* adapter_ptr, uint8_t* address_buffer_ptr, uint32_t address_buffer_size, uint32_t* prefix_length_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_INFO_API_POINTER(adapter_ptr, get_ipv6_address);
    return adapter_ptr->info_api_ptr->get_ipv6_address(adapter_ptr, address_buffer_ptr, address_buffer_size, prefix_length_ptr);
}

ewf_result ewf_adapter_get_ipv6_next_hop(ewf_adapter* adapter_ptr, uint8_t* address_buffer_ptr, uint32_t address_buffer_size, uint32_t* prefix_length_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_INFO_API_POINTER(adapter_ptr, get_ipv6_next_hop);
    return adapter_ptr->info_api_ptr->get_ipv6_next_hop(adapter_ptr, address_buffer_ptr, address_buffer_size, prefix_length_ptr);
}

ewf_result ewf_adapter_get_ipv6_dns(ewf_adapter* adapter_ptr, uint8_t* address_buffer_ptr, uint32_t address_buffer_size, uint32_t* prefix_length_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_INFO_API_POINTER(adapter_ptr, get_ipv6_dns);
    return adapter_ptr->info_api_ptr->get_ipv6_dns(adapter_ptr, address_buffer_ptr, address_buffer_size, prefix_length_ptr);
}
