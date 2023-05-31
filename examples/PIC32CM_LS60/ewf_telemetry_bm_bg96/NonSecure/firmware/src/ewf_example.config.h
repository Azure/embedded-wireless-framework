/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework example configuration.
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
 * @defgroup group_example_configuration_allocator Allocator configuration
 * @brief Allocator configuration settings used in examples
 * @{
 */

/** @brief the number of message allocator blocks */
#define EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT                         (8)

/** @brief the size of each message allocator block */
#define EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE                          (512)

/** @} *** group_example_configuration_allocator */

/**
 * @defgroup group_example_configuration_modem Modem configuration
 * @brief Modem configuration settings used in examples
 * @{
 */

/** @brief The SIM PIN for the modem */
#define EWF_CONFIG_SIM_PIN                                               ("0000")

/** @brief The SIM operator APN */
#define EWF_CONFIG_SIM_APN                                               ("internet.telekom")

/** @brief The modem context ID used */
#define EWF_CONFIG_CONTEXT_ID                                            (1)

/** @} *** group_example_configuration_modem */

/**
 * @defgroup group_example_configuration_iot_hub IoT Hub configuration
 * @brief IoT Hub configuration settings used in examples
 * @{
 */

/** @brief The IoT Hub hostname */
#define EWF_CONFIG_IOT_HUB_HOSTNAME                                 ""

/** @brief The device ID */
#define EWF_CONFIG_IOT_HUB_DEVICEID                                 ""

/** @} *** group_example_configuration_iot_hub */

/**
 * @defgroup group_example_configuration_telemetry
 * @brief Telemetry example configuration
 * @{
 */

/** @brief The size of the buffer used to hold the IoT Hub username */
#define EWF_CONFIG_TELEMETRY_USERNAME_LENGTH                             (256)

/** @brief The size of the buffer used to hold the IoT Hub client ID */
#define EWF_CONFIG_TELEMETRY_CLIENT_ID_LENGTH                            (64)

/** @brief The size of the buffer used to hold the IoT Hub topic length */
#define EWF_CONFIG_TELEMETRY_TOPIC_LENGTH                                (256)

/** @brief The number of minutes to run the telemetry loop, 0 means to run forever */
#define EWF_CONFIG_TELEMETRY_LOOP_MINUTES                                (60)

/** @} */

/**
 * @brief CA certificate file name that will be used in the security/TLS profile configuration
 * @details This name will either be EWF_CONFIG_ADAPTER_QUECTEL_BG96_ROOT_CA_CERTIFICATE_FILE_NAME or
 * EWF_CONFIG_ADAPTER_QUECTEL_BG96_USER_CA_CERTIFICATE_FILE_NAME used when certificate provisioning.
 * By default this example is set to use the ROOT CA certificate file name.
 */
#define EWF_CONFIG_ADAPTER_QUECTEL_BG96_CA_CERTIFICATE_FILE_NAME         ("root_ca_cert.pem")

 /** @brief Client certificate ID, range 0-19 */
#define EWF_CONFIG_ADAPTER_QUECTEL_BG96_CLIENT_CERTIFICATE_FILE_NAME     ("device_cert.pem")

/** @brief Client private key ID, range 0-19  */
#define EWF_CONFIG_ADAPTER_QUECTEL_BG96_CLIENT_PRIVATE_KEY_FILE_NAME     ("device_key.pem")

/** @} *** group_example_configuration_tls */

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */
