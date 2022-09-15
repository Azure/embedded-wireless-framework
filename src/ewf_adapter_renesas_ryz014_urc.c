/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * brief The Embedded Wireless Framework Renesas RYZ014 adapter driver
 ****************************************************************************/

#include "ewf_adapter_renesas_ryz014.h"
#include "ewf_lib.h"

ewf_result ewf_adapter_renesas_ryz014_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    ewf_result result;

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
        adapter_renesas_ryz014_ptr->module_start = true;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SHUTDOWN"))
    {
        adapter_renesas_ryz014_ptr->module_start = false;
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


#if EWF_ADAPTER_RENESAS_RYZ014_TCP_ENABLED || EWF_ADAPTER_RENESAS_RYZ014_UDP_ENABLED
    /* Call the internet URC callback */
    if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_internet_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

#if EWF_ADAPTER_RENESAS_RYZ014_MQTT_BASIC_ENABLED
    /* Call the MQTT basic URC callback */
    if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_mqtt_basic_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

    if (adapter_renesas_ryz014_ptr->user_urc_callback)
    {
        if (ewf_result_succeeded(adapter_renesas_ryz014_ptr->user_urc_callback(interface_ptr, buffer_ptr, buffer_length)))
        {
            return EWF_RESULT_OK;
        }
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_set_user_urc_callback(ewf_adapter* adapter_ptr, ewf_adapter_urc_user_callback callback)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    adapter_renesas_ryz014_ptr->user_urc_callback = callback;

    return EWF_RESULT_OK;
}
