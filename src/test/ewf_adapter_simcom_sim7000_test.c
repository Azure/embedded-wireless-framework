/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework SIMcom SIM7000 adapter driver test
 ****************************************************************************/

#include "ewf_adapter_simcom_sim7000.h"

ewf_result ewf_adapter_simcom_sim7000_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_SIMCOM_SIM7000);

    return ewf_adapter_simcom_common_test(adapter_ptr);
}
