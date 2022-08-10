/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter driver test common code
 ****************************************************************************/

#ifndef __ewf_adapter_test__h__included__
#define __ewf_adapter_test__h__included__

#ifdef __cplusplus
extern "C" {
#endif

#include "ewf.h"

ewf_result ewf_adapter_test(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_test_api_tcp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_test_api_udp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_test_api_mqtt(ewf_adapter* adapter_ptr);

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_test__h__included__ */
