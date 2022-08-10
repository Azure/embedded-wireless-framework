/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter tls basic API implementation
 ****************************************************************************/

#include "ewf_adapter.h"

#define EWF_ADAPTER_VALIDATE_TLS_BASIC_API_POINTER(adapter_ptr, function_ptr)  \
do {                                                                                \
    if ((adapter_ptr->tls_basic_api_ptr == NULL) ||                                 \
        (adapter_ptr->tls_basic_api_ptr->function_ptr == NULL))                     \
    {                                                                               \
        EWF_LOG_ERROR("The function is not implemented.");                     \
        return EWF_RESULT_NOT_SUPPORTED;                                       \
    }                                                                               \
} while(0)

ewf_result ewf_adapter_tls_basic_init(ewf_adapter * adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_TLS_BASIC_API_POINTER(adapter_ptr, init);
    return adapter_ptr->tls_basic_api_ptr->init(adapter_ptr);
}

ewf_result ewf_adapter_tls_basic_clean(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_TLS_BASIC_API_POINTER(adapter_ptr, clean);
    return adapter_ptr->tls_basic_api_ptr->clean(adapter_ptr);
}
