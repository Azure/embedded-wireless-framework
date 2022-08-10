/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework ThreadX platform implementation
 ****************************************************************************/

#include "ewf_platform_threadx.h"

ewf_result ewf_platform_sleep(uint32_t time)
{
    tx_thread_sleep((ULONG) time);

    return EWF_RESULT_OK;
}

static VOID _ewf_platform_thread_entry(ULONG p)
{
    if (p && ((struct _ewf_platform_thread*)p)->thread_function_ptr)
        ((struct _ewf_platform_thread*)p)->thread_function_ptr(((struct _ewf_platform_thread*)p)->thread_function_data);
}

ewf_result ewf_platform_thread_create(ewf_platform_thread * thread_ptr)
{
    UINT status;

    if (!thread_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    status = tx_thread_create(
        &(thread_ptr->thread),
        thread_ptr->name_cstr,
        _ewf_platform_thread_entry,
        (ULONG) thread_ptr,
        thread_ptr->stack_ptr,
        thread_ptr->stack_size,
        thread_ptr->priority,
        thread_ptr->preempt_threshold,
        thread_ptr->time_slice,
        TX_DONT_START);
    if (status != TX_SUCCESS)
    {
       EWF_LOG_ERROR("Failed to create a thread, error %u", status);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_thread_destroy(ewf_platform_thread * thread_ptr)
{
    UINT status;

    if (!thread_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    status = tx_thread_delete(&(thread_ptr->thread));
    if (status != TX_SUCCESS)
    {
       return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_thread_start(ewf_platform_thread * thread_ptr)
{
    UINT status;

    if (!thread_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    status = tx_thread_resume(&(thread_ptr->thread));
    if (status != TX_SUCCESS)
    {
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_thread_stop(ewf_platform_thread * thread_ptr)
{
    UINT status;

    if (!thread_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    status = tx_thread_suspend(&(thread_ptr->thread));
    if (status != TX_SUCCESS)
    {
       return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_mutex_create(ewf_platform_mutex* mutex_ptr)
{
    if (!mutex_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    UINT status = tx_semaphore_create(&(mutex_ptr->sem), mutex_ptr->name_cstr, 1);
    if (status != TX_SUCCESS)
    {
        EWF_LOG_ERROR("Failed to create a mutex.");
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_mutex_destroy(ewf_platform_mutex* mutex_ptr)
{
    if (!mutex_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    UINT status = tx_semaphore_delete(&(mutex_ptr->sem));
    if (status != TX_SUCCESS)
    {
        EWF_LOG_ERROR("Failed to destroy a mutex.");
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_mutex_get(ewf_platform_mutex* mutex_ptr)
{
    if (!mutex_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    UINT status = tx_semaphore_get(&(mutex_ptr->sem), TX_WAIT_FOREVER);
    if (status != TX_SUCCESS)
    {
        EWF_LOG_ERROR("Failed to obtain ownership of a mutex.");
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_mutex_put(ewf_platform_mutex* mutex_ptr)
{
    if (!mutex_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    UINT status = tx_semaphore_ceiling_put(&(mutex_ptr->sem), 1);
    if (status != TX_SUCCESS)
    {
        EWF_LOG_ERROR("Failed to release ownership of a mutex.");
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_create(ewf_platform_queue* queue_ptr)
{
    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    UINT message_size_in_words = (queue_ptr->message_size % 4) ? (queue_ptr->message_size / 4 + 1) : (queue_ptr->message_size / 4);

    UINT status = tx_queue_create(
        &(queue_ptr->queue),
        queue_ptr->name_cstr,
        message_size_in_words,
        queue_ptr->queue_start,
        queue_ptr->queue_size);
    if (status != TX_SUCCESS)
    {
        EWF_LOG_ERROR("Failed to create a queue.");
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_destroy(ewf_platform_queue* queue_ptr)
{
    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    UINT status = tx_queue_delete(
        &(queue_ptr->queue));
    if (status != TX_SUCCESS)
    {
        EWF_LOG_ERROR("Failed to destroy a queue.");
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_enqueue(ewf_platform_queue* queue_ptr, const void* data_ptr, uint32_t data_size, bool wait)
{
    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!data_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (data_size != queue_ptr->message_size) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    UINT status = tx_queue_send(
        &(queue_ptr->queue),
        (void*) data_ptr,
        wait ? TX_WAIT_FOREVER : TX_NO_WAIT);
    switch(status)
    {
    case TX_QUEUE_FULL:
        return EWF_RESULT_FULL_QUEUE;

    case TX_SUCCESS:
        break;

    default:
        EWF_LOG_ERROR("Failed to enqueue, error 0x%08X", status);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_dequeue(ewf_platform_queue* queue_ptr, void* buffer_ptr, uint32_t* buffer_size_ptr, bool wait)
{
    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!buffer_size_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (*buffer_size_ptr < queue_ptr->message_size) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    UINT status = tx_queue_receive(
        &(queue_ptr->queue),
        buffer_ptr,
		wait ? TX_WAIT_FOREVER : TX_NO_WAIT);
    switch (status)
    {
    case TX_QUEUE_EMPTY:
        return EWF_RESULT_EMPTY_QUEUE;

    case TX_SUCCESS:
        break;

    default:
        EWF_LOG_ERROR("Failed to dequeue, error 0x%08X", status);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    *buffer_size_ptr = queue_ptr->message_size;

    return EWF_RESULT_OK;
}
