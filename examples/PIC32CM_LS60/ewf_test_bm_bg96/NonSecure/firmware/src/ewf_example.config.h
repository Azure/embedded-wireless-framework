/************************************************************************//**
 * @file
 * @version Preview
 * SPDX-License-Identifier: MIT
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * @brief The Embedded Wireless Framework example configuration.
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
#define EWF_CONFIG_SIM_PIN                                          ("\"\"")

/** @brief The SIM operator APN */
#define EWF_CONFIG_SIM_APN                                          ("internet.telekom")

/** @brief The modem context ID used */
#define EWF_CONFIG_CONTEXT_ID                                       (1)
/** @} */

/**
 * @defgroup group_example_configuration_iot_hub IoT Hub configuration
 * @brief IoT Hub configuration settings used in examples
 * @{
 */
/** @brief The IoT Hub hostname */
#define EWF_CONFIG_IOT_HUB_HOSTNAME                                 ""
/** @brief The device ID */
#define EWF_CONFIG_IOT_HUB_DEVICEID                                 ""
/** @} */
    
/** @{
 */
#define EWF_ADAPTER_TEST_TCP_HTTP_TEST_ENABLED                      1
#define EWF_ADAPTER_TEST_TCP_ECHO_TEST_ENABLED                      1
#define EWF_ADAPTER_TEST_TCP_ECHO_SERVER_HOSTNAME_STR               ""
#define EWF_ADAPTER_TEST_TCP_LOCAL_SERVER_PORT                      4000
#define EWF_ADAPTER_TEST_TCP_RECV_SLEEP_TICKS                       (EWF_PLATFORM_TICKS_PER_SECOND * 1)
#define EWF_ADAPTER_TEST_TCP_LOOP_SLEEP_TICKS                       (EWF_PLATFORM_TICKS_PER_SECOND * 1)
#define EWF_ADAPTER_TEST_TCP_CLIENT_SERVER_TEST_ENABLED             0
#define EWF_ADAPTER_TEST_UDP_ECHO_TEST_ENABLED                      1
#define EWF_ADAPTER_TEST_UDP_ECHO_SERVER_HOSTNAME_STR               ""
#define EWF_ADAPTER_TEST_UDP_LOCAL_SERVER_PORT                      5000
#define EWF_ADAPTER_TEST_UDP_RECV_SLEEP_TICKS                       (EWF_PLATFORM_TICKS_PER_SECOND * 1)
#define EWF_ADAPTER_TEST_UDP_LOOP_SLEEP_TICKS                       (EWF_PLATFORM_TICKS_PER_SECOND * 1)
#define EWF_ADAPTER_TEST_UDP_CLIENT_SERVER_TEST_ENABLED             0
/** @} *** group_example_configuration_test_echo */
/************************************************************************//**
 * @} *** group_example_configuration
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */
