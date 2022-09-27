/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework Sequans adapter API
 ****************************************************************************/

#ifndef __ewf_adapter_sequans__h__included__
#define __ewf_adapter_sequans__h__included__

#include "ewf_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_sequans Sequans generic adapter functions
 * @ingroup group_adapter
 * @{
 ****************************************************************************/

/**
 * @brief Auto-connect the UE,  automatically set the UE to its maximal functionality
 * @param mode 0- disabled, 1- enabled
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_sequans_autoconnect(ewf_adapter* adapter_ptr, uint32_t mode);

/**
 * @brief Auto-connect to Internet, when enabled device will try to connect to Internet PDN provisioned
 * @param mode 0- disabled, 1- enabled
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_sequans_autointernet(ewf_adapter* adapter_ptr, uint32_t mode);

/**
 * @brief Define PDP context
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_sequans_configure_pdp_context(ewf_adapter* adapter_ptr, uint32_t context_id, const char* const apn, const char* const pdp_type);

/************************************************************************//**
 * @} *** group_adapter_sequans
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_sequans__h__included__ */
