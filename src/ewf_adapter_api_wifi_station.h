/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework WiFi adapter station API
 ****************************************************************************/

#ifndef __ewf_adapter_wifi_station__h__included__
#define __ewf_adapter_wifi_station__h__included__

#include "ewf_adapter.h"
#include "ewf_interface.h"
#include "ewf_lib.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_wifi_station_api EWF WiFi adapter station API
 * @ingroup group_adapter_wifi_api
 * @ingroup group_adapter_api
 * @brief Functions for WiFi adapters, station functionality.
 * @{
 ****************************************************************************/

typedef struct _ewf_adapter_wif_station_api
{
    ewf_result(*connect)(ewf_adapter* adapter_ptr, const char* ssid_str, const char* password_str);
    ewf_result(*disconnect)(ewf_adapter* adapter_ptr);

} ewf_adapter_wifi_station_api;

/**
 * @brief Connect the WiFi adapter to a wireless network
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] ssid_str A pointer to a string with the SSID of the WiFi network to connect to
 * @param[in] password_str A pointer to a string with the network password.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_wifi_station_connect(ewf_adapter* adapter_ptr, const char* ssid_str, const char* password_str);

/**
 * @brief Disconnect the WiFi adapter
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_wifi_station_disconnect(ewf_adapter* adapter_ptr);

/************************************************************************//**
 * @} *** group_adapter_wifi_station
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_wifi_station__h__included__ */
