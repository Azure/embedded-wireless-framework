/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter API control implementation
 ****************************************************************************/

#include "ewf_adapter.h"

#define EWF_ADAPTER_VALIDATE_CONTROL_API_POINTER(adapter_ptr, function_ptr)         \
do {                                                                                \
    if ((adapter_ptr->control_api_ptr == NULL) ||                                   \
        (adapter_ptr->control_api_ptr->function_ptr == NULL))                       \
    {                                                                               \
        EWF_LOG_ERROR("The function is not implemented.");                          \
        return EWF_RESULT_NOT_SUPPORTED;                                            \
    }                                                                               \
} while(0)

ewf_result ewf_adapter_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_CONTROL_API_POINTER(adapter_ptr, start);
    return adapter_ptr->control_api_ptr->start(adapter_ptr);
}

ewf_result ewf_adapter_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_CONTROL_API_POINTER(adapter_ptr, stop);
    return adapter_ptr->control_api_ptr->stop(adapter_ptr);
}
