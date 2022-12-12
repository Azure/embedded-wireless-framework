/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework MX-CHIP EMW3080B adapter driver test
 ****************************************************************************/

#include "ewf_adapter_mxchip_emw3080b.h"
#include "ewf_adapter_test.c"
#include "ewf_adapter_mxchip_common_test.c"

ewf_result ewf_adapter_mxchip_emw3080b_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_MXCHIP_EMW3080B);

    return ewf_adapter_mxchip_common_test(adapter_ptr);
}
