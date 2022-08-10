/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel BG95 adapter driver test
 ****************************************************************************/

#include "ewf_adapter_quectel_bg95.h"

#include "ewf_adapter_test.c"
#include "ewf_adapter_quectel_common_test.c"

ewf_result ewf_adapter_quectel_bg95_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_QUECTEL_BG95);

    return ewf_adapter_quectel_common_test(adapter_ptr);
}
