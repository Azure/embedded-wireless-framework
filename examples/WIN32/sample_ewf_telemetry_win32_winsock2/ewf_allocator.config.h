/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework configuration template.
 ****************************************************************************/

#ifndef __ewf_allocator__config__h__included__
#define __ewf_allocator__config__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_allocator Allocator configuration
 * @ingroup group_configuration
 * @brief The definitions used to configure the Azure SD-NET allocator.
 * @{
 ****************************************************************************/

/**
 * \def EWF_ALLOCATOR_BLOCK_COUNT
 * @brief Define the allocator block count
 *
 * \def EWF_ALLOCATOR_BLOCK_SIZE
 * @brief Define the allocator block size
 */
#ifndef EWF_DEBUG /* Tight release configuration */
#define EWF_ALLOCATOR_BLOCK_COUNT (4)
#define EWF_ALLOCATOR_BLOCK_SIZE (256)
#else /* Comfortable debug configuration */
#define EWF_ALLOCATOR_BLOCK_COUNT (4)
#define EWF_ALLOCATOR_BLOCK_SIZE (256)
#endif

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_allocator__config__h__included__ */
