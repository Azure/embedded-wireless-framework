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
#define EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT                    (20)

/** @brief the size of each message allocator block */
#define EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE                     (1600)

/** @} *** group_example_configuration_allocator */

/**
 * @defgroup group_example_configuration_modem Modem configuration
 * @brief Modem configuration settings used in examples
 * @{
 */

void renesas_ryz014a_adapter_power_on();
/** @brief The modem power on user function */
#define EWF_ADAPTER_USER_POWER_ON                                   renesas_ryz014a_adapter_power_on

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
 * @defgroup group_example_configuration_test_netx_duo NetX-Duo test configuration
 * @brief NetX-Duo test configuration settings used in examples
 * @{
 */

#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_TEST_ENABLED             (1)
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_SERVER_IP                IP_ADDRESS(0,0,0,0)

#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_ECHO_TEST_ENABLED             (1)
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_ECHO_SERVER_IP                IP_ADDRESS(0,0,0,0)

#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_DNS_TEST_ENABLED              (1)

#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_TEST_ENABLED             (1)
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_IP                IP_ADDRESS(0,0,0,0)

/** @} *** group_example_configuration_test_netx_duo */

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */
