/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework memory pool allocator definition
 ****************************************************************************/

#ifndef __ewf_allocator_memory_pool__h__included__
#define __ewf_allocator_memory_pool__h__included__

#include "ewf_allocator.h"
#include "ewf_platform.h"

struct _ewf_allocator_memory_pool_block;
typedef struct _ewf_allocator_memory_pool_block ewf_allocator_memory_pool_block;
struct _ewf_allocator_memory_pool_block
{
    union
    {
        ewf_allocator_memory_pool_block* next_free_ptr;
        uint32_t data_ptr[1];
    };
};

struct _ewf_allocator_memory_pool;
typedef struct _ewf_allocator_memory_pool ewf_allocator_memory_pool;
struct _ewf_allocator_memory_pool
{
    uint8_t* pool_ptr;
    ewf_allocator_memory_pool_block* next_free_ptr;
    uint32_t pool_size; /**< The size of the pool buffer */
    uint32_t block_size; /**< The size of a block */
#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_platform_mutex* mutex_ptr;
#endif
};

ewf_result ewf_allocator_memory_pool_start(ewf_allocator* allocator_ptr);

ewf_result ewf_allocator_memory_pool_stop(ewf_allocator* allocator_ptr);

ewf_result ewf_allocator_memory_pool_allocate(ewf_allocator* allocator_ptr, void** p);

ewf_result ewf_allocator_memory_pool_release(ewf_allocator* allocator_ptr, void* p);

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ALLOCATOR_MEMORY_POOL_INITIALIZE_HEADER(allocator_ptr)                                                                                 \
do {                                                                                                                                                    \
(allocator_ptr)->struct_magic = EWF_ALLOCATOR_STRUCT_MAGIC;                                                                                        \
(allocator_ptr)->struct_size = EWF_ALLOCATOR_STRUCT_SIZE;                                                                                          \
(allocator_ptr)->struct_version = EWF_ALLOCATOR_VERSION;                                                                                           \
(allocator_ptr)->struct_type = EWF_ALLOCATOR_TYPE_MEMORY_POOL;                                                                                     \
} while(0)
#else
#define EWF_ALLOCATOR_MEMORY_POOL_INITIALIZE_HEADER(allocator_ptr)
#endif /* EWF_PARAMETER_CHECKING */

#ifdef EWF_PLATFORM_HAS_THREADING
#define EWF_ALLOCATOR_MEMORY_POOL_STATIC_DECLARE__MUTEX(mutex_ptr, name_symb) \
EWF_PLATFORM_MUTEX_STATIC_DECLARE(mutex_ptr, name_symb);
#else
#define EWF_ALLOCATOR_MEMORY_POOL_STATIC_DECLARE__MUTEX(mutex_ptr, name_symb)
#endif

/**
 * @brief Declare a memory pool allocator
 * @param[in,out] allocator_ptr a pointer to an allocator that will be initialized to point to the one statically declared by the macro
 * @param[in] allocator_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 * @param[in] block_count the number of blocks
 * @param[in] block_size the size of each block
 */
#define EWF_ALLOCATOR_MEMORY_POOL_STATIC_DECLARE(allocator_ptr, allocator_name_symb, block_count_param, block_size_param)                       \
do {                                                                                                                                            \
static ewf_allocator_memory_pool_block ewf_allocator_memory_pool__buffer__##allocator_name_symb[                                                \
    ((block_size_param > sizeof(ewf_allocator_memory_pool_block))                                                                               \
        ? (block_size_param) : sizeof(ewf_allocator_memory_pool_block))                                                                         \
            * (block_count_param + 1)];                                                                                                         \
static struct _ewf_allocator_memory_pool ewf_allocator_memory_pool__##allocator_name_symb = {0};                                                \
static ewf_allocator ewf_allocator__##allocator_name_symb = {0};                                                                                \
ewf_allocator_memory_pool__##allocator_name_symb.pool_ptr = (uint8_t*) ewf_allocator_memory_pool__buffer__##allocator_name_symb;                \
ewf_allocator_memory_pool__##allocator_name_symb.pool_size = sizeof(ewf_allocator_memory_pool__buffer__##allocator_name_symb);                  \
ewf_allocator_memory_pool__##allocator_name_symb.block_size = (uint32_t) block_size_param;                                                      \
EWF_ALLOCATOR_MEMORY_POOL_STATIC_DECLARE__MUTEX(ewf_allocator_memory_pool__##allocator_name_symb.mutex_ptr, allocator_name_symb);               \
ewf_allocator__##allocator_name_symb.block_size = block_size_param;                                                                             \
ewf_allocator__##allocator_name_symb.block_count = block_count_param;                                                                           \
ewf_allocator__##allocator_name_symb.start = ewf_allocator_memory_pool_start;                                                                   \
ewf_allocator__##allocator_name_symb.stop = ewf_allocator_memory_pool_stop;                                                                     \
ewf_allocator__##allocator_name_symb.allocate = ewf_allocator_memory_pool_allocate;                                                             \
ewf_allocator__##allocator_name_symb.release = ewf_allocator_memory_pool_release;                                                               \
ewf_allocator__##allocator_name_symb.implementation_ptr = &(ewf_allocator_memory_pool__##allocator_name_symb);                                  \
allocator_ptr = &(ewf_allocator__##allocator_name_symb);                                                                                        \
EWF_ALLOCATOR_MEMORY_POOL_INITIALIZE_HEADER(allocator_ptr);                                                                                     \
} while(0)

#endif /* __ewf_allocator_memory_pool__h__included__ */
