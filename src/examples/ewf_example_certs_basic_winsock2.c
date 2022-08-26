/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework WinSock2
 * @details EWF certificate provisioning example for WinSock2
 ****************************************************************************/

#include "ewf_adapter_winsock2.h"

ewf_result ewf_example_certs_basic_winsock2(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    return EWF_RESULT_OK;
}
