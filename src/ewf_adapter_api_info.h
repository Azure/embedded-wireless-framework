/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter info API
 ****************************************************************************/

#ifndef __ewf_adapter_info__h__included__
#define __ewf_adapter_info__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_info Adapter information API
 * @ingroup group_adapter_api
 * @brief Functions to get information from the adapter.
 * @{
 ****************************************************************************/

typedef struct _ewf_adapter_api_info
{
    ewf_result(*info)(ewf_adapter* adapter_ptr);
    ewf_result(*get_ipv4_address)(ewf_adapter* adapter_ptr, uint32_t* address_ptr);
    ewf_result(*get_ipv4_netmask)(ewf_adapter* adapter_ptr, uint32_t* netmask_ptr);
    ewf_result(*get_ipv4_gateway)(ewf_adapter* adapter_ptr, uint32_t* gateway_ptr);
    ewf_result(*get_ipv4_dns)(ewf_adapter* adapter_ptr, uint32_t* dns_ptr);
    ewf_result(*get_ipv6_address)(ewf_adapter* adapter_ptr, uint8_t* address_buffer_ptr, uint32_t address_buffer_size, uint32_t* prefix_length_ptr);
    ewf_result(*get_ipv6_next_hop)(ewf_adapter* adapter_ptr, uint8_t* address_buffer_ptr, uint32_t address_buffer_size, uint32_t* prefix_length_ptr);
    ewf_result(*get_ipv6_dns)(ewf_adapter* adapter_ptr, uint8_t* address_buffer_ptr, uint32_t address_buffer_size, uint32_t* prefix_length_ptr);

} ewf_adapter_api_info;

/**
 * @brief Query and log the modem information
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_info(ewf_adapter* adapter_ptr);

/**
 * @brief Get the adapter's IPv4 address
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param address_ptr[in,out] a pointer to a variable that will receive the adapter IPv4 address
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t* address_ptr);

/**
 * @brief Get the adapter's IPv4 network mask
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param netmask_ptr[in,out] a pointer to a variable that will receive the adapter IPv4 netmask
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t * netmask_ptr);

/**
 * @brief Get the adapter's IPv4 gateway address
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param gateway_ptr[in,out] a pointer to a variable that will receive the adapter IPv4 gateway address
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t * gateway_ptr);

/**
 * @brief Get the adapter's IPv4 primary DNS address
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param dns_ptr[in,out] a pointer to a variable that will receive the adapter primary IPv4 DNS address
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t * dns_ptr);

/**
 * @brief Get the adapter's IPv6 address
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param address_buffer_ptr[in,out] a pointer to a variable that will receive the adapter IPv6 address
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_get_ipv6_address(ewf_adapter* adapter_ptr, uint8_t* address_buffer_ptr, uint32_t address_buffer_size, uint32_t * prefix_length_ptr);

/**
 * @brief Get the adapter's IPv6 next hop
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param address_buffer_ptr[in,out] a pointer to a variable that will receive the next hop IPv6 address
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_get_ipv6_next_hop(ewf_adapter* adapter_ptr, uint8_t* address_buffer_ptr, uint32_t address_buffer_size, uint32_t* prefix_length_ptr);

/**
 * @brief Get the adapter's IPv6 primary DNS address
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param address_buffer_ptr[in,out] a pointer to a variable that will receive the adapter primary IPv6 DNS address
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_get_ipv6_dns(ewf_adapter* adapter_ptr, uint8_t* address_buffer_ptr, uint32_t address_buffer_size, uint32_t* prefix_length_ptr);

/************************************************************************//**
 * @} *** group_adapter_info
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_info__h__included__ */
