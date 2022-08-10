/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework C heap allocator definition
 ****************************************************************************/

#ifndef __ewf_allocator_c_heap__h__included__
#define __ewf_allocator_c_heap__h__included__

#include "ewf_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_allocator_c_heap The C heap allocator
 * @ingroup group_allocator
 * @brief The C heap allocator
 * @{
 ****************************************************************************/

/**
 * @brief C heap allocator implementation type
 */
typedef struct _ewf_allocator_c_heap
{
    uint32_t allocated_count;
    uint32_t released_count;

    uint32_t block_count; /** The maximum number of blocks to allocate */
    uint32_t block_size; /** The size of a block */

} ewf_allocator_c_heap;

ewf_result ewf_allocator_c_heap_start(ewf_allocator* allocator_ptr);

ewf_result ewf_allocator_c_heap_stop(ewf_allocator* allocator_ptr);

ewf_result ewf_allocator_c_heap_allocate(ewf_allocator* allocator_ptr, void** p);

ewf_result ewf_allocator_c_heap_release(ewf_allocator* allocator_ptr, void* p);

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ALLOCATOR_C_HEAP_INITIALIZE_HEADER(allocator_ptr)                                                                                      \
do {                                                                                                                                                    \
(allocator_ptr)->struct_magic = EWF_ALLOCATOR_STRUCT_MAGIC;                                                                                        \
(allocator_ptr)->struct_size = EWF_ALLOCATOR_STRUCT_SIZE;                                                                                          \
(allocator_ptr)->struct_version = EWF_ALLOCATOR_VERSION;                                                                                           \
(allocator_ptr)->struct_type = EWF_ALLOCATOR_TYPE_C_HEAP;                                                                                          \
} while(0)
#else
#define EWF_ALLOCATOR_C_HEAP_INITIALIZE_HEADER(allocator_ptr)
#endif /* EWF_PARAMETER_CHECKING */

/**
 * @brief Declare a C heap allocator
 * @param[in,out] allocator_ptr a pointer to an allocator that will be initialized to point to the one statically declared by the macro
 * @param[in] allocator_name_symb a unique symbol name that will be used as a name suffix for the statically declared data
 * @param[in] block_count the number of blocks
 * @param[in] block_size the size of each block
 */
#define EWF_ALLOCATOR_C_HEAP_STATIC_DECLARE(allocator_ptr, allocator_name_symb, block_count_param, block_size_param)                               \
do {                                                                                                                                                    \
static ewf_allocator_c_heap ewf_allocator_c_heap__##allocator_name_symb = {0};                                                                \
static ewf_allocator ewf_allocator__##allocator_name_symb = {0};                                                                              \
ewf_allocator_c_heap__##allocator_name_symb.block_count = block_count_param;                                                                       \
ewf_allocator_c_heap__##allocator_name_symb.block_size = block_size_param;                                                                         \
ewf_allocator__##allocator_name_symb.start = ewf_allocator_c_heap_start;                                                                      \
ewf_allocator__##allocator_name_symb.stop = ewf_allocator_c_heap_stop;                                                                        \
ewf_allocator__##allocator_name_symb.allocate = ewf_allocator_c_heap_allocate;                                                                \
ewf_allocator__##allocator_name_symb.release = ewf_allocator_c_heap_release;                                                                  \
ewf_allocator__##allocator_name_symb.implementation_ptr = &(ewf_allocator_c_heap__##allocator_name_symb);                                     \
allocator_ptr = &(ewf_allocator__##allocator_name_symb);                                                                                           \
EWF_ALLOCATOR_C_HEAP_INITIALIZE_HEADER(allocator_ptr);                                                                                             \
} while(0)

/************************************************************************//**
 * @} *** group_allocator_c_heap
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_allocator_c_heap__h__included__ */
