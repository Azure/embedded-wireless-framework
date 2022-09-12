/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework memory pool allocator implementation
 ****************************************************************************/

#include "ewf_allocator_memory_pool.h"

ewf_result ewf_allocator_memory_pool_start(ewf_allocator* allocator_ptr)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_MEMORY_POOL);
    ewf_allocator_memory_pool* implementation_ptr = (ewf_allocator_memory_pool*)allocator_ptr->implementation_ptr;

    uint32_t i;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(ewf_platform_mutex_create(implementation_ptr->mutex_ptr)))
    {
        EWF_LOG_ERROR("Error creating the memory pool allocator mutex.\n");
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

    for (i = 0; i < allocator_ptr->block_count; ++i)
        ((ewf_allocator_memory_pool_block*) (implementation_ptr->pool_ptr + (allocator_ptr->block_size * i)))->next_free_ptr =
            (ewf_allocator_memory_pool_block*) (implementation_ptr->pool_ptr + (allocator_ptr->block_size * (i + 1)));
    ((ewf_allocator_memory_pool_block*)(implementation_ptr->pool_ptr + (allocator_ptr->block_size * (i - 1))))->next_free_ptr = NULL;

    implementation_ptr->next_free_ptr = (ewf_allocator_memory_pool_block*) implementation_ptr->pool_ptr;

    return EWF_RESULT_OK;
}

ewf_result ewf_allocator_memory_pool_stop(ewf_allocator* allocator_ptr)
{
    return EWF_RESULT_OK;
}

ewf_result ewf_allocator_memory_pool_allocate(ewf_allocator* allocator_ptr, void** p)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_MEMORY_POOL);
    ewf_allocator_memory_pool* implementation_ptr = (ewf_allocator_memory_pool*)allocator_ptr->implementation_ptr;

    if (!p) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (implementation_ptr->next_free_ptr == NULL)
    {
        *p = NULL;
        return EWF_RESULT_OUT_OF_MEMORY;
    }

#if defined(EWF_PLATFORM_HAS_THREADING)
    ewf_platform_mutex_get(implementation_ptr->mutex_ptr);
#elif defined(EWF_PLATFORM_BARE_METAL)
    EWF_PLATFORM_INTERRUPT_STATE_TYPE state;
    state = EWF_PLATFORM_INTERRUPT_STATE_TYPE_GET();
    EWF_PLATFORM_INTERRUPT_DISABLE();
#endif

    *p = implementation_ptr->next_free_ptr->data_ptr;
    implementation_ptr->next_free_ptr = implementation_ptr->next_free_ptr->next_free_ptr;

#if defined(EWF_PLATFORM_HAS_THREADING)
    ewf_platform_mutex_put(implementation_ptr->mutex_ptr);
#elif defined(EWF_PLATFORM_BARE_METAL)
    EWF_PLATFORM_INTERRUPT_STATE_TYPE_SET(state);
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_allocator_memory_pool_release(ewf_allocator* allocator_ptr, void* p)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_MEMORY_POOL);
    ewf_allocator_memory_pool* implementation_ptr = (ewf_allocator_memory_pool*)allocator_ptr->implementation_ptr;

    if (!p) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (p < ((void*) implementation_ptr->pool_ptr) || ((void *) (implementation_ptr->pool_ptr + implementation_ptr->pool_size)) <= p)
    {
        EWF_LOG_ERROR("Trying to release a pointer outside of the memory pool,  pointer: %p", p);
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if ((((size_t) p) - ((size_t) implementation_ptr->pool_ptr)) % implementation_ptr->block_size)
    {
        EWF_LOG_ERROR("Trying to release an invalid pointer, not properly aligned,  pointer: %p", p);
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

#if defined(EWF_PLATFORM_HAS_THREADING)
    ewf_platform_mutex_get(implementation_ptr->mutex_ptr);
#elif defined(EWF_PLATFORM_BARE_METAL)
    EWF_PLATFORM_INTERRUPT_STATE_TYPE state;
    state = EWF_PLATFORM_INTERRUPT_STATE_TYPE_GET();
    EWF_PLATFORM_INTERRUPT_DISABLE();
#endif

    ((ewf_allocator_memory_pool_block*)p)->next_free_ptr = implementation_ptr->next_free_ptr;
    implementation_ptr->next_free_ptr = ((ewf_allocator_memory_pool_block*)p);

#if defined(EWF_PLATFORM_HAS_THREADING)
    ewf_platform_mutex_put(implementation_ptr->mutex_ptr);
#elif defined(EWF_PLATFORM_BARE_METAL)
    EWF_PLATFORM_INTERRUPT_STATE_TYPE_SET(state);
#endif

    return EWF_RESULT_OK;
}
