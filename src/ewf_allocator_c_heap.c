/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework C heap allocator definition
 ****************************************************************************/

#include "ewf_allocator_c_heap.h"

#include <stdlib.h>

ewf_result ewf_allocator_c_heap_start(ewf_allocator* allocator_ptr)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_C_HEAP);
    ewf_allocator_c_heap* ewf_allocator_c_heap_ptr = (ewf_allocator_c_heap*)allocator_ptr->implementation_ptr;

    return EWF_RESULT_OK;
}

ewf_result ewf_allocator_c_heap_stop(ewf_allocator* allocator_ptr)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_C_HEAP);
    ewf_allocator_c_heap* ewf_allocator_c_heap_ptr = (ewf_allocator_c_heap*)allocator_ptr->implementation_ptr;

    if (ewf_allocator_c_heap_ptr->allocated_count != ewf_allocator_c_heap_ptr->released_count)
    {
        EWF_LOG_ERROR("Not all memory was released by the C heap allocator!");
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_allocator_c_heap_allocate(ewf_allocator* allocator_ptr, void** p)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_C_HEAP);
    ewf_allocator_c_heap* ewf_allocator_c_heap_ptr = (ewf_allocator_c_heap*)allocator_ptr->implementation_ptr;

    if (!p) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if ((ewf_allocator_c_heap_ptr->allocated_count - ewf_allocator_c_heap_ptr->released_count) > ewf_allocator_c_heap_ptr->block_count)
    {
        EWF_LOG_ERROR("Trying to allocate too many blocks in the C heap allocator!");
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    *p = malloc(ewf_allocator_c_heap_ptr->block_size);
    if (!*p)
    {
        EWF_LOG_ERROR("malloc failed to allocate a block in the C heap allocator!");
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    ewf_allocator_c_heap_ptr->allocated_count++;

    return EWF_RESULT_OK;
}

ewf_result ewf_allocator_c_heap_release(ewf_allocator* allocator_ptr, void* p)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_C_HEAP);
    ewf_allocator_c_heap* ewf_allocator_c_heap_ptr = (ewf_allocator_c_heap*)allocator_ptr->implementation_ptr;

    if (!p) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    free(p);

    ewf_allocator_c_heap_ptr->released_count++;

    return EWF_RESULT_OK;
}
