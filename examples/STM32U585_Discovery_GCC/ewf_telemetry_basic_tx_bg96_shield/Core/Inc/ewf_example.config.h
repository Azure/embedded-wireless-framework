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
#define EWF_CONFIG_SIM_PIN "0000"

/** @} */

/**
 * @defgroup group_example_configuration_iot_hub IoT Hub configuration
 * @brief IoT Hub configuration settings used in examples
 * @{
 */

/** @brief The IoT Hub hostname */
#define EWF_CONFIG_IOT_HUB_HOSTNAME "andrejm-test-iot-hub.azure-devices.net"

/** @brief The device ID */
#define EWF_CONFIG_IOT_HUB_DEVICEID "andrejm-test-win32-bg96-cert"

/** @} */

/**
 * @defgroup group_example_configuration_telemetry
 * @brief Telemetry example configuration
 * @{
 */

/** @brief The size of the buffer used to hold the IoT Hub username */
#define EWF_CONFIG_TELEMETRY_USERNAME_LENGTH        (256)

/** @brief The size of the buffer used to hold the IoT Hub client ID */
#define EWF_CONFIG_TELEMETRY_CLIENT_ID_LENGTH       (64)

/** @brief The size of the buffer used to hold the IoT Hub topic length */
#define EWF_CONFIG_TELEMETRY_TOPIC_LENGTH           (256)

/** @brief The number of minutes to run the telemetry loop, 0 means to run forever */
#define EWF_CONFIG_TELEMETRY_LOOP_MINUTES           (60)

/** @} */

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */
