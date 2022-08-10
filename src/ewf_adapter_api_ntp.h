/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Azure Small Device Adapter NTP API
 * (Reference : RFC4330)
 ****************************************************************************/

#ifndef __ewf_adapter_ntp__h__included__
#define __ewf_adapter_ntp__h__included__

#include "ewf_adapter.h"
#include "ewf_modem_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_ntp Adapter NTP API
 * @ingroup group_adapter_api
 * @brief NTP functions
 * @{
 *
 ***************************************************************/
typedef struct _ewf_adapter_api_modem_ntp
{
    ewf_result(*adapter_ntp_network_time_synchronize)(ewf_adapter* adapter_ptr, const char* server_str, uint16_t port, uint8_t autoset, ewf_time * time_info_ptr);
} ewf_adapter_api_modem_ntp;

/**
 * @brief Synchronize time with NTP
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] server_str String indicating NTP server URL
 * @param[in] port NTP server port
 * @param[in] autoset Integer, wheter to automatically set the synchronized time to local time
 * @param[out] time_info_ptr The time synchronized from NTP server if available in output URC
 * @note Not all modems support NTP synchronization, refer modem user manual for feature suport informations
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_ntp_network_time_synchronize(ewf_adapter* adapter_ptr, const char* server_str, uint16_t port, uint8_t autoset, ewf_time * time_info_ptr);

/************************************************************************//**
 * @} *** group_adapter_ntp
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_ntp__h__included__ */
