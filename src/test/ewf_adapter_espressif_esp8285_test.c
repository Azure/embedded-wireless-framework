/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Espressif ESP8285 adapter driver test
 ****************************************************************************/

#include "ewf_adapter_espressif_esp8285.h"
#include "ewf_adapter_test.c"
#include "ewf_adapter_espressif_common_test.c"

ewf_result ewf_adapter_espressif_esp8285_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_ESPRESSIF_ESP8285);

    return ewf_adapter_espressif_common_test(adapter_ptr);
}
