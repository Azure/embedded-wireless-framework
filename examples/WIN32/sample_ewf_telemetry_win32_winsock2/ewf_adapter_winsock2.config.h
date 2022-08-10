/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework configuration template.
 ****************************************************************************/

#ifndef __ewf_adapter_winsock2__config__h__included__
#define __ewf_adapter_winsock2__config__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup group_configuration_adapter_winsock2 WinSock2 adapter configuration
 * @ingroup group_configuration_adapter
 * @ingroup group_adapter_winsock2
 * @brief WinSock2 adapter configuration
 * @{
 */

/** @brief The total number of supported sockets in the adapter */
#define _ADAPTER_SOCKET_POOL_SIZE (12)

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_winsock2__config__h__included__ */
