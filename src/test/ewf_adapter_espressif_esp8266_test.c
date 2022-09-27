/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Espressif ESP8266 adapter driver test
 ****************************************************************************/

#include "ewf_adapter_espressif_esp8266.h"
#include "ewf_adapter_test.c"
#include "ewf_adapter_espressif_common_test.c"

ewf_result ewf_adapter_espressif_esp8266_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_ESPRESSIF_ESP8266);

    return ewf_adapter_espressif_common_test(adapter_ptr);
}
