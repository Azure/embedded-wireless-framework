/************************************************************************//**
 *
 * @file
 * @version Preview
 * SPDX-License-Identifier: MIT
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * @brief The Embedded Wireless Framework example configuration template.
 * Copy this file into your own project, remove the .template extension
 * and customize its contents.
 *
 ****************************************************************************/


#ifndef __az_sdnet_example_conf__h__included__
#define __az_sdnet_example_conf__h__included__

#ifdef __cplusplus
extern "C" {
#endif


/************************************************************************//**
 * @defgroup group_example_configuration Azure SDNET example configuration
 * @brief The definitions to configure the sample software.
 * @{
 ****************************************************************************/

/**
 * @defgroup group_example_configuration_modem Modem configuration
 * @brief Modem configuration settings used in examples
 * @{
 */
/** @brief The SIM PIN for the modem */
#define EWF_CONFIG_SIM_PIN "0000"
/** @} */

/**
 * @defgroup group_example_configuration_iot_hub IoT Hub configuration
 * @brief IoT Hub configuration settings used in examples
 * @{
 */
/** @brief The IoT Hub hostname */
#define EWF_CONFIG_IOT_HUB_HOSTNAME "azurertos-test.azure-devices.net"
/** @brief The device ID */
#define EWF_CONFIG_IOT_HUB_DEVICEID "bhnaphad-test-cert"
/** @} */

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __az_sdnet_example_conf__h__included__ */
