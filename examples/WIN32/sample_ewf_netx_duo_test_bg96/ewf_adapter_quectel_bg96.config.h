/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework configuration template.
 ****************************************************************************/

#ifndef __ewf_adapter_quectel_bg96__config__h__included__
#define __ewf_adapter_quectel_bg96__config__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_adapter_quectel_bg96 Quectel BG96 adapter configuration
 * @ingroup group_configuration_adapter
 * @ingroup group_adapter
 * @brief Quectel BG96 adapter configuration
 * @{
 ****************************************************************************/

#define EWF_ADAPTER_QUECTEL_BG96_UFS_ENABLED
#define EWF_ADAPTER_QUECTEL_BG96_SSL_ENABLED
#define EWF_ADAPTER_QUECTEL_BG96_TCP_ENABLED
#define EWF_ADAPTER_QUECTEL_BG96_UDP_ENABLED
#define EWF_ADAPTER_QUECTEL_BG96_MQTT_ENABLED

/** @brief The total number of supported internet sockets in the adapter */
#define EWF_ADAPTER_QUECTEL_BG96_INTERNET_SOCKET_POOL_SIZE (12)

/** @brief The internet socket invalid value */
#define EWF_ADAPTER_QUECTEL_BG96_INTERNET_SOCKET_INVALID (-1)

/** @brief The total number of supported MQTT sockets in the adapter */
#define EWF_ADAPTER_QUECTEL_BG96_MQTT_SOCKET_POOL_SIZE (12)

/** @brief The MQTT socket invalid value */
#define EWF_ADAPTER_QUECTEL_BG96_MQTT_SOCKET_INVALID (-1)

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_quectel_bg96__config__h__included__ */
