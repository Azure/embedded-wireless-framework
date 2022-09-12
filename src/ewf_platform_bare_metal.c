/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework baremetal platform API
 ****************************************************************************/

#include "ewf_platform_bare_metal.h"

#include <string.h>

ewf_result ewf_platform_sleep(uint32_t t)
{
    EWF_PLATFORM_BUSY_WAIT(t);
    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_create(ewf_platform_queue* queue_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!queue_ptr)
    {
        EWF_LOG_ERROR("The queue pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_destroy(ewf_platform_queue* queue_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!queue_ptr)
    {
        EWF_LOG_ERROR("The queue pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_enqueue(ewf_platform_queue* queue_ptr, const void* data_ptr, uint32_t data_size, bool wait)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!queue_ptr)
    {
        EWF_LOG_ERROR("The queue pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!data_ptr)
    {
        EWF_LOG_ERROR("The data pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (queue_ptr->item_size != data_size)
    {
        EWF_LOG_ERROR("The data pointer size is invalid.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    ewf_result result = EWF_RESULT_OK;

    do
    {
        EWF_PLATFORM_INTERRUPT_STATE_TYPE state;
        state = EWF_PLATFORM_INTERRUPT_STATE_TYPE_GET();
        EWF_PLATFORM_INTERRUPT_DISABLE();

        if (queue_ptr->used_count >= queue_ptr->queue_size)
        {
            EWF_LOG("The queue is already full.");
            result = EWF_RESULT_FULL_QUEUE;
        }
        else
        {
            memcpy(
                ((uint8_t*) queue_ptr->data) + (queue_ptr->tail_index * queue_ptr->item_size),
                data_ptr,
                queue_ptr->item_size);
            queue_ptr->tail_index = (queue_ptr->tail_index + 1) % queue_ptr->queue_size;
            queue_ptr->used_count++;
        }

        EWF_PLATFORM_INTERRUPT_STATE_TYPE_SET(state);
    }
    while (wait && (result == EWF_RESULT_FULL_QUEUE));

    return result;
}

ewf_result ewf_platform_queue_dequeue(ewf_platform_queue* queue_ptr, void* buffer_ptr, uint32_t* buffer_size_ptr, bool wait)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!queue_ptr)
    {
        EWF_LOG_ERROR("The queue pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!buffer_ptr)
    {
        EWF_LOG_ERROR("The buffer pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!buffer_size_ptr)
    {
        EWF_LOG_ERROR("The buffer size pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (queue_ptr->item_size != *buffer_size_ptr)
    {
        EWF_LOG_ERROR("The data pointer size is invalid.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    ewf_result result = EWF_RESULT_OK;

    do
    {
        EWF_PLATFORM_INTERRUPT_STATE_TYPE state;
        state = EWF_PLATFORM_INTERRUPT_STATE_TYPE_GET();
        EWF_PLATFORM_INTERRUPT_DISABLE();

        if (queue_ptr->used_count == 0)
        {
#ifdef EWF_LOG_VERBOSE
            EWF_LOG("The queue is empty.\n");
#endif
            result = EWF_RESULT_EMPTY_QUEUE;
        }
        else
        {
            memcpy(
                buffer_ptr,
                ((uint8_t*) queue_ptr->data) + ((queue_ptr->queue_size + queue_ptr->tail_index - queue_ptr->used_count) % queue_ptr->queue_size) * queue_ptr->item_size,
                queue_ptr->item_size);
            queue_ptr->used_count--;
        }

        EWF_PLATFORM_INTERRUPT_STATE_TYPE_SET(state);
    }
    while (wait && (result == EWF_RESULT_EMPTY_QUEUE));

    return result;
}
