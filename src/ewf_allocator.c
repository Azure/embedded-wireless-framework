/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework allocator API implementation.
 ****************************************************************************/

#include "ewf_allocator.h"

ewf_result ewf_allocator_start(ewf_allocator* allocator_ptr)
{
    if (!allocator_ptr)
    {
        EWF_LOG_ERROR("Allocator pointer is NULL");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    return allocator_ptr->start(allocator_ptr);
}

ewf_result ewf_allocator_stop(ewf_allocator* allocator_ptr)
{
    if (!allocator_ptr)
    {
        EWF_LOG_ERROR("Allocator pointer is NULL");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    return allocator_ptr->stop(allocator_ptr);
}

ewf_result ewf_allocator_allocate(ewf_allocator* allocator_ptr, void ** p)
{
    if (!allocator_ptr)
    {
        EWF_LOG_ERROR("Allocator pointer is NULL");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    return allocator_ptr->allocate(allocator_ptr, p);
}

ewf_result ewf_allocator_release(ewf_allocator* allocator_ptr, void * p)
{
    if (!allocator_ptr)
    {
        EWF_LOG_ERROR("Allocator pointer is NULL");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    return allocator_ptr->release(allocator_ptr, p);
}
