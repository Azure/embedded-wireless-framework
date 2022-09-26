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

/** @brief the number of allocator blocks */
#define EWF_CONFIG_ALLOCATOR_BLOCK_COUNT                    (6)

/** @brief the size of each blocks allocator block */
#define EWF_CONFIG_ALLOCATOR_BLOCK_SIZE                     (1024)

/** @} *** group_example_configuration_allocator */

/************************************************************************//**
 * @} *** group_example_configuration
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */
