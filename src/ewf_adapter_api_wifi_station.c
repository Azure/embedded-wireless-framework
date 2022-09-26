/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter UDP API implementation
 ****************************************************************************/

#include "ewf_adapter.h"

#define EWF_VALIDATE_WIFI_STATION_API_POINTER(adapter_ptr, function_ptr)                    \
do {                                                                                        \
    if ((adapter_ptr->wifi_station_api_ptr == NULL) ||                                      \
        (adapter_ptr->wifi_station_api_ptr->function_ptr == NULL))                          \
    {                                                                                       \
        EWF_LOG_ERROR("The function is not implemented.");                                  \
        return EWF_RESULT_NOT_SUPPORTED;                                                    \
    }                                                                                       \
} while(0)

ewf_result ewf_adapter_wifi_station_connect(ewf_adapter* adapter_ptr, const char* ssid_str, const char* password_str)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_WIFI_STATION_API_POINTER(adapter_ptr, connect);
    return adapter_ptr->wifi_station_api_ptr->connect(adapter_ptr, ssid_str, password_str);
}

ewf_result ewf_adapter_wifi_station_disconnect(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_WIFI_STATION_API_POINTER(adapter_ptr, connect);
    return adapter_ptr->wifi_station_api_ptr->disconnect(adapter_ptr);
}
