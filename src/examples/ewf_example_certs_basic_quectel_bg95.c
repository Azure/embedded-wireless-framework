/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel BG95
 * @details EWF certificate provisioning example for Quectel BG95
 ****************************************************************************/

#include "ewf_adapter_quectel_bg95.h"

#include "ewf_example_certs_basic_quectel_common.c"

ewf_result ewf_example_certs_basic_quectel_bg95(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_QUECTEL_BG95);

    return ewf_example_certs_basic_quectel_common(adapter_ptr);
}
