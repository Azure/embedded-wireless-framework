/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework BG96 adapter API
 ****************************************************************************/

#ifndef __ewf_allocator__h__included__
#define __ewf_allocator__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_allocator EWF Allocator API
 * @brief Allocators are used to allocate and free buffers for interfaces and adapters.
 * @{
 ****************************************************************************/

/** @brief The allocator structure definition */
struct _ewf_allocator
{
#ifdef EWF_PARAMETER_CHECKING
    uint32_t struct_magic;
    uint32_t struct_size;
    uint32_t struct_version;
    uint32_t struct_type;
#endif /* EWF_PARAMETER_CHECKING */

    uint32_t block_size;
    uint32_t block_count;

    ewf_result(*start)(ewf_allocator* allocator_ptr);
    ewf_result(*stop)(ewf_allocator* allocator_ptr);
    ewf_result(*allocate)(ewf_allocator* allocator_ptr, void** p);
    ewf_result(*release)(ewf_allocator* allocator_ptr, void* p);

    void* implementation_ptr;
};

#define EWF_ALLOCATOR_STRUCT_MAGIC         (0xA110CA70) /* ~~ allocato(r) */
#define EWF_ALLOCATOR_STRUCT_SIZE          (sizeof(struct _ewf_allocator))
#define EWF_ALLOCATOR_VERSION              (EWF_DEVELOPER_MICROSOFT | 0x0001)

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr)                          \
do {                                                                                \
    if ((allocator_ptr == NULL) ||                                                  \
        (allocator_ptr->struct_magic != EWF_ALLOCATOR_STRUCT_MAGIC) ||         \
        (allocator_ptr->struct_size != EWF_ALLOCATOR_STRUCT_SIZE) ||           \
        (allocator_ptr->struct_version != EWF_ALLOCATOR_VERSION) ||            \
        (allocator_ptr->implementation_ptr == NULL))                                \
    {                                                                               \
        EWF_LOG_ERROR("The allocator pointer is invalid.");                    \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                           \
    }                                                                               \
} while(0)
#else
#define EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr)                          \
do {                                                                                \
    if ((allocator_ptr == NULL) ||                                                  \
        (allocator_ptr->implementation_ptr == NULL))                                \
    {                                                                               \
        EWF_LOG_ERROR("The allocator pointer is invalid.");                    \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                           \
    }                                                                               \
} while(0)
#endif /* EWF_PARAMETER_CHECKING */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, allocator_type)     \
do {                                                                                \
    if ((allocator_ptr == NULL) ||                                                  \
        (allocator_ptr->struct_type != allocator_type))                             \
    {                                                                               \
        EWF_LOG_ERROR("The allocator pointer type is invalid.");               \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                           \
    }                                                                               \
} while(0)
#else
#define EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, allocator_type)
#endif


/**
 * @brief Start the allocator
 * @param[in] allocator_ptr a pointer to an allocator control block
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_allocator_start(ewf_allocator* allocator_ptr);

/**
 * @brief Stop the allocator
 * @param[in] allocator_ptr a pointer to an allocator control block
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_allocator_stop(ewf_allocator* allocator_ptr);

/**
 * @brief Allocate a block from the allocator
 * @param[in] allocator_ptr a pointer to an allocator control block
 * @param[in,out] p address of a pointer to receive a pointer to the allocated block
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_allocator_allocate(ewf_allocator* allocator_ptr, void ** p);

/**
 * @brief Release a block back to the allocator
 * @param[in] allocator_ptr a pointer to an allocator control block
 * @param p[in] a pointer to the block to be released
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_allocator_release(ewf_allocator* allocator_ptr, void * p);

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_allocator__h__included__ */
