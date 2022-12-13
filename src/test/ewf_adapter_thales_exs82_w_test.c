/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Thales EXS82-W adapter driver test
 ****************************************************************************/

#include "ewf_adapter_thales_exs82_w.h"

#include "ewf_adapter_test.c"
#include "ewf_adapter_thales_common_test.c"

ewf_result ewf_adapter_thales_exs82_w_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_THALES_EXS82_W);

    return ewf_adapter_thales_common_test(adapter_ptr);
}
