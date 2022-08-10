/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework ThreadX allocator definition
 ****************************************************************************/

#ifndef __ewf_allocator_threadx__h__included__
#define __ewf_allocator_threadx__h__included__

#include "ewf_allocator.h"

#include "tx_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_allocator_threadx The ThreadX allocator
 * @ingroup group_allocator
 * @brief The ThreadX allocator
 * @{
 ****************************************************************************/

/**
 * @brief ThreadX allocator implementation type
 */
typedef struct _ewf_allocator_threadx
{
    TX_BLOCK_POOL block_pool; /**< The ThreadX block pool control block */
    VOID * block_pool_buffer_ptr; /** Pointer to the block pool buffer */
    ULONG pool_size; /** The size of the pool buffer */

} ewf_allocator_threadx;

ewf_result ewf_allocator_threadx_start(ewf_allocator* allocator_ptr);

ewf_result ewf_allocator_threadx_stop(ewf_allocator* allocator_ptr);

ewf_result ewf_allocator_threadx_allocate(ewf_allocator* allocator_ptr, void** p);

ewf_result ewf_allocator_threadx_release(ewf_allocator* allocator_ptr, void* p);

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ALLOCATOR_THREADX_INITIALIZE_HEADER(allocator_ptr)                                                                                     \
do {                                                                                                                                                    \
(allocator_ptr)->struct_magic = EWF_ALLOCATOR_STRUCT_MAGIC;                                                                                        \
(allocator_ptr)->struct_size = EWF_ALLOCATOR_STRUCT_SIZE;                                                                                          \
(allocator_ptr)->struct_version = EWF_ALLOCATOR_VERSION;                                                                                           \
(allocator_ptr)->struct_type = EWF_ALLOCATOR_TYPE_THREADX;                                                                                         \
} while(0)
#else
#define EWF_ALLOCATOR_THREADX_INITIALIZE_HEADER(allocator_ptr)
#endif /* EWF_PARAMETER_CHECKING */

/**
 * @brief Declare a ThreadX allocator
 * @param[in,out] allocator_ptr a pointer to an allocator that will be initialized to point to the one statically declared by the macro
 * @param[in] allocator_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 * @param[in] block_count the number of blocks
 * @param[in] block_size the size of each block
 */
#define EWF_ALLOCATOR_THREADX_STATIC_DECLARE(allocator_ptr, allocator_name_symb, block_count_param, block_size_param)                           \
do {                                                                                                                                            \
static ULONG block_pool_buffer__##allocator_name_symb[(block_count_param * (block_size_param + sizeof(void*))) / sizeof(ULONG)];                \
static ewf_allocator_threadx ewf_allocator_threadx__##allocator_name_symb = {0};                                                                \
static ewf_allocator ewf_allocator__##allocator_name_symb = {0};                                                                                \
ewf_allocator_threadx__##allocator_name_symb.block_pool_buffer_ptr = block_pool_buffer__##allocator_name_symb;                                  \
ewf_allocator_threadx__##allocator_name_symb.pool_size = sizeof(block_pool_buffer__##allocator_name_symb);                                      \
ewf_allocator__##allocator_name_symb.block_count = (ULONG) block_count_param;                                                                   \
ewf_allocator__##allocator_name_symb.block_size = (ULONG) block_size_param;                                                                     \
ewf_allocator__##allocator_name_symb.start = ewf_allocator_threadx_start;                                                                       \
ewf_allocator__##allocator_name_symb.stop = ewf_allocator_threadx_stop;                                                                         \
ewf_allocator__##allocator_name_symb.allocate = ewf_allocator_threadx_allocate;                                                                 \
ewf_allocator__##allocator_name_symb.release = ewf_allocator_threadx_release;                                                                   \
ewf_allocator__##allocator_name_symb.implementation_ptr = &(ewf_allocator_threadx__##allocator_name_symb);                                      \
allocator_ptr = &(ewf_allocator__##allocator_name_symb);                                                                                        \
EWF_ALLOCATOR_THREADX_INITIALIZE_HEADER(allocator_ptr);                                                                                         \
} while(0)

/************************************************************************//**
 * @} *** group_allocator_threadx
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_allocator_threadx__h__included__ */
