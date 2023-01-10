/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
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
 * @defgroup group_example_configuration_allocator Allocator configuration
 * @brief Allocator configuration settings used in examples
 * @{
 */

/** @brief the number of message allocator blocks */
#define EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT                    (6)

/** @brief the size of each message allocator block */
#define EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE                     (1600)

/** @} *** group_example_configuration_allocator */

/**
 * @defgroup group_example_configuration_wifi WiFi configuration
 * @brief WiFi configuration settings used in examples
 * @{
 */

 /** @brief the number of message allocator blocks */
#define EWF_CONFIG_WIFI_STATION_SSID                                "DESKTOP-V5NOFS8"

/** @brief the size of each message allocator block */
#define EWF_CONFIG_WIFI_STATION_PASSWORD                            "12F80u90"

/** @} *** group_example_configuration_wifi */

/**
 * @defgroup group_example_configuration_test_echo Echo test configuration
 * @brief Echo test configuration settings used in examples
 * @{
 */

#define EWF_ADAPTER_TEST_TCP_HTTP_TEST_ENABLED                      1
#define EWF_ADAPTER_TEST_TCP_HTTP_SERVER_STR                        "www.bing.com"

#define EWF_ADAPTER_TEST_TCP_ECHO_TEST_ENABLED                      1
#define EWF_ADAPTER_TEST_TCP_ECHO_SERVER_HOSTNAME_STR               ""
#define EWF_ADAPTER_TEST_TCP_LOCAL_SERVER_PORT                      4000
#define EWF_ADAPTER_TEST_TCP_CLIENT_SERVER_TEST_ENABLED             0
#define EWF_ADAPTER_TEST_TCP_RECV_SLEEP_TICKS                       1 // (EWF_PLATFORM_TICKS_PER_SECOND * 1)

#define EWF_ADAPTER_TEST_UDP_ECHO_TEST_ENABLED                      1
#define EWF_ADAPTER_TEST_UDP_ECHO_SERVER_HOSTNAME_STR               ""
#define EWF_ADAPTER_TEST_UDP_LOCAL_SERVER_PORT                      5000
#define EWF_ADAPTER_TEST_UDP_CLIENT_SERVER_TEST_ENABLED             0
#define EWF_ADAPTER_TEST_UDP_LOOP_SLEEP_TICKS						(EWF_PLATFORM_TICKS_PER_SECOND * 1)
#define EWF_ADAPTER_TEST_UDP_RECV_SLEEP_TICKS                       (EWF_PLATFORM_TICKS_PER_SECOND * 1)

/** @} *** group_example_configuration_test_echo */

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */