/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework ESPRESSIF ESP8266 adapter API
 ****************************************************************************/

#include "ewf_adapter_espressif_esp8266.h"
#include "ewf_adapter_espressif_common.c"

ewf_adapter_api_control ewf_adapter_espressif_esp8266_api_control =
{
    ewf_adapter_espressif_esp8266_start,
    ewf_adapter_espressif_esp8266_stop,
};

ewf_result ewf_adapter_espressif_esp8266_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_ESPRESSIF_ESP8266);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    if (ewf_result_failed(result = ewf_adapter_espressif_common_start(adapter_ptr)))
    {
        return result;
    }

    /* Do additional adapter specific initialization here */

    return result;
}

ewf_result ewf_adapter_espressif_esp8266_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_ESPRESSIF_ESP8266);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    if (ewf_result_failed(result = ewf_adapter_espressif_common_stop(adapter_ptr)))
    {
        return result;
    }

    /* Do additional adapter specific deinitialization here */

    return result;
}

ewf_result ewf_adapter_espressif_esp8266_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    /* Process adapter specific URCs here */

    return ewf_adapter_espressif_common_urc_callback(interface_ptr, buffer_ptr, buffer_length);
}
