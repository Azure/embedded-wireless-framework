/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * brief The Embedded Wireless Framework Renesas common adapter driver
 ****************************************************************************/

#include "ewf_adapter_renesas_common.h"
#include "ewf_lib.h"

ewf_result ewf_adapter_renesas_common_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_common* adapter_renesas_common_ptr = (ewf_adapter_renesas_common*)adapter_ptr->implementation_ptr;

    ewf_result result;

    /* Ignore empty URCs */
    if (ewfl_str_equals_str((char*)buffer_ptr, "\r\n"))
    {
        return EWF_RESULT_OK;
    }

    /* Skip leading \r\n */
    if (buffer_length >= 2 && buffer_ptr[0] == '\r' && buffer_ptr[1] == '\n')
    {
        buffer_length -= 2;
        buffer_ptr += 2;
    }

    if (ewfl_str_starts_with((char*)buffer_ptr, "+CREG:"))
    {
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+CEREG:"))
    {
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SYSSTART"))
    {
        adapter_renesas_common_ptr->module_start = true;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SHUTDOWN"))
    {
        adapter_renesas_common_ptr->module_start = false;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSIMST: "))
    {
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+CME ERROR: 171"))
    {
        /* Last PDN disconnection not allowed, Cause No. 49 �quality of service unavailable�
        * refer  3GPP TS 24.008 [8] cause codes for more info */
        return EWF_RESULT_OK;
    }


#if EWF_ADAPTER_RENESAS_COMMON_TCP_ENABLED || EWF_ADAPTER_RENESAS_COMMON_UDP_ENABLED
    /* Call the internet URC callback */
    if (ewf_result_failed(result = ewf_adapter_renesas_common_internet_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

#if EWF_ADAPTER_RENESAS_COMMON_MQTT_BASIC_ENABLED
    /* Call the MQTT basic URC callback */
    if (ewf_result_failed(result = ewf_adapter_renesas_common_mqtt_basic_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

    return EWF_RESULT_OK;
}

