/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Renesas RYZ014A
 * @details EWF certificate provisioning example for Renesas RYZ014A
 ****************************************************************************/

#include "ewf_adapter_renesas_ryz014.h"

#include "ewf_example_certs_basic_renesas_common.c"

ewf_result ewf_example_certs_basic_renesas_ryz014(ewf_adapter* adapter_ptr);

ewf_result ewf_example_certs_basic_renesas_ryz014(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);

    return ewf_example_certs_basic_renesas_common(adapter_ptr);
}
