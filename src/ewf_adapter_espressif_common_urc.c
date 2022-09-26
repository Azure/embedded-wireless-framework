/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework ESP common adapter driver
 ****************************************************************************/

#include "ewf_adapter_espressif_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

ewf_result ewf_adapter_espressif_common_urc_callback(ewf_interface* interface_ptr, uint8_t * buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    /* Ignore empty URCs */
    if (ewfl_str_equals_str((char*)buffer_ptr, "\r\n"))
    {
        return EWF_RESULT_OK;
    }

    ewf_result result;

#if EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED || EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED
    /* Call the internet URC callback */
    if (ewf_result_failed(result = ewf_adapter_espressif_common_internet_urc_callback(interface_ptr, buffer_ptr, buffer_length))) return result;
    if (result != EWF_RESULT_UNHANDLED_URC) return EWF_RESULT_OK;
#endif

    return EWF_RESULT_OK;
}
