/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework ThreadX allocator definition
 ****************************************************************************/

#include "ewf_allocator_threadx.h"

ewf_result ewf_allocator_threadx_start(ewf_allocator* allocator_ptr)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_THREADX);
    ewf_allocator_threadx* ewf_allocator_threadx_ptr = (ewf_allocator_threadx*)allocator_ptr->implementation_ptr;

    UINT status = tx_block_pool_create(
        &(ewf_allocator_threadx_ptr->block_pool),
        "EWF_ALLOCATOR",
        allocator_ptr->block_size,
        ewf_allocator_threadx_ptr->block_pool_buffer_ptr,
        ewf_allocator_threadx_ptr->pool_size);
    if (status != TX_SUCCESS)
    {
        return EWF_RESULT_ALLOCATOR_INITIALIZATION_FAILED;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_allocator_threadx_stop(ewf_allocator* allocator_ptr)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_THREADX);
    ewf_allocator_threadx* ewf_allocator_threadx_ptr = (ewf_allocator_threadx*)allocator_ptr->implementation_ptr;

    UINT status = tx_block_pool_delete(&(ewf_allocator_threadx_ptr->block_pool));
    if (status != TX_SUCCESS)
    {
        return EWF_RESULT_ALLOCATOR_INITIALIZATION_FAILED;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_allocator_threadx_allocate(ewf_allocator* allocator_ptr, void ** p)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_THREADX);
    ewf_allocator_threadx* ewf_allocator_threadx_ptr = (ewf_allocator_threadx*)allocator_ptr->implementation_ptr;

    UINT status = tx_block_allocate(&(ewf_allocator_threadx_ptr->block_pool), p, TX_NO_WAIT);
    if (status != TX_SUCCESS)
    {
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_allocator_threadx_release(ewf_allocator* allocator_ptr, void * p)
{
    EWF_ALLOCATOR_VALIDATE_POINTER(allocator_ptr);
    EWF_ALLOCATOR_VALIDATE_POINTER_TYPE(allocator_ptr, EWF_ALLOCATOR_TYPE_THREADX);

    UINT status = tx_block_release(p);
    if (status != TX_SUCCESS)
    {
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    return EWF_RESULT_OK;
}
