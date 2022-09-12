/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel common adapter driver
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

ewf_result ewf_adapter_quectel_common_urc_callback(ewf_interface* interface_ptr, uint8_t * buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result;

    /* Ignore empty URCs */
    if (ewfl_str_equals_str((char*)buffer_ptr, "\r\n"))
    {
        return EWF_RESULT_OK;
    }

    /* Modem ready */
    if (ewfl_str_starts_with((char*)buffer_ptr, "APP RDY"))
    {
        return EWF_RESULT_OK;
    }

    /* PDP context */
    if (ewfl_str_starts_with((char *)buffer_ptr, "+QIURC: \"pdpdeact\","))
    {
        return EWF_RESULT_OK;
    }

#if EWF_ADAPTER_QUECTEL_COMMON_UFS_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_TLS_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_tls_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_tls_basic_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_TCP_ENABLED || EWF_ADAPTER_QUECTEL_COMMON_UDP_ENABLED
    /* Call the internet URC callback */
    if (ewf_result_failed(result = ewf_adapter_quectel_common_internet_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_MQTT_ENABLED
    /* Call the MQTT URC callback */
    if (ewf_result_failed(result = ewf_adapter_quectel_common_mqtt_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_MQTT_BASIC_ENABLED
    /* Call the MQTT URC callback */
    if (ewf_result_failed(result = ewf_adapter_quectel_common_mqtt_basic_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

    return EWF_RESULT_OK;
}
