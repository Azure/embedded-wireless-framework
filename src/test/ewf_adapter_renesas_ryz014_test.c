/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Renesas RYZ014 adapter driver test
 ****************************************************************************/

#include "ewf_adapter_renesas_ryz014.h"
#include "ewf_adapter_test.c"
#include "ewf_adapter_renesas_common_test.c"

ewf_result ewf_adapter_renesas_ryz014_test(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_renesas_ryz014_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);

    return ewf_adapter_renesas_common_test(adapter_ptr);
}
