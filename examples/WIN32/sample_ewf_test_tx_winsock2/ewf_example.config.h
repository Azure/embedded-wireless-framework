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

/** @brief the number of data allocator blocks */
#define EWF_CONFIG_DATA_ALLOCATOR_BLOCK_COUNT                       (4)

/** @brief the size of each data allocator block */
#define EWF_CONFIG_DATA_ALLOCATOR_BLOCK_SIZE                        (512)

/** @} *** group_example_configuration_allocator */

/**
 * @defgroup group_example_configuration_test_echo Echo test configuration
 * @brief Echo test configuration settings used in examples
 * @{
 */

#define EWF_ADAPTER_TEST_TCP_ECHO_SERVER_HOSTNAME_STR               "andrejm-ewf-socat-tcp.westus.azurecontainer.io"

#define EWF_ADAPTER_TEST_TCP_LOCAL_SERVER_PORT                      4000

#define EWF_ADAPTER_TEST_UDP_ECHO_SERVER_HOSTNAME_STR               "andrejm-ewf-socat-udp.westus.azurecontainer.io"

#define EWF_ADAPTER_TEST_UDP_LOCAL_SERVER_PORT                      5000

/** @} *** group_example_configuration_test_echo */

/************************************************************************//**
 * @} *** group_example_configuration
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */
