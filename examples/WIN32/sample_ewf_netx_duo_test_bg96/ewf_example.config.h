/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework example configuration template.
 ****************************************************************************/


#ifndef __ewf_example_conf__h__included__
#define __ewf_example_conf__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_example_configuration EWF example configuration
 * @brief The definitions to configure the sample software.
 * @{
 ****************************************************************************/

/**
 * @defgroup group_example_configuration_modem Modem configuration
 * @brief Modem configuration settings used in examples
 * @{
 */
/** @brief The SIM PIN for the modem */
#define EWF_CONFIG_SIM_PIN "0633"
/** @} */

/**
 * @defgroup group_example_configuration_wifi WiFi configuration
 * @brief WiFi configuration settings used in examples
 * @{
 */
/** @brief The SSID of the WiFi network to connect to */
#define EWF_CONFIG_SSID ""
/** @brief The password for the WiFi network to connect to */
#define EWF_CONFIG_PASSWORD ""
/** @} */

/**
 * @defgroup group_example_configuration_iot_hub IoT Hub configuration
 * @brief IoT Hub configuration settings used in examples
 * @{
 */
/** @brief The IoT Hub hostname */
#define EWF_CONFIG_IOT_HUB_HOSTNAME ""
/** @brief The device ID */
#define EWF_CONFIG_IOT_HUB_DEVICEID ""
/** @} */

/**
 * @def EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BAUD_RATE
 * @brief Define the serial port baud rate for the WIN32 COM port interface
 */
#define EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BAUD_RATE (CBR_115200)

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */
