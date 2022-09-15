/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework POSIX threads platform API
 ****************************************************************************/

#include "ewf_platform_pthread.h"

#include <time.h>
#include <unistd.h>
#include <memory.h>

ewf_result ewf_platform_sleep(uint32_t time)
{
    usleep(time * 1000);

    return EWF_RESULT_OK;
}

static void* _ewf_platform_thread_entry(void* p)
{
    ewf_platform_thread* thread_ptr = (ewf_platform_thread*)p;
    if (thread_ptr && thread_ptr->thread_function_ptr)
        thread_ptr->thread_function_ptr(thread_ptr->thread_function_data);
    return 0;
}

ewf_result ewf_platform_thread_create(ewf_platform_thread * thread_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!thread_ptr)
    {
        EWF_LOG_ERROR("The thread pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    int ret;

    ret = pthread_attr_init(&thread_ptr->attr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to initialize the thread attributes, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    ret = pthread_attr_setstacksize(&thread_ptr->attr, thread_ptr->stacksize);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to set the thread attributes stack size, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_thread_destroy(ewf_platform_thread * thread_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!thread_ptr)
    {
        EWF_LOG_ERROR("The thread pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    int ret = pthread_attr_destroy(&thread_ptr->attr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to destroy the thread attributes, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_thread_start(ewf_platform_thread* thread_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!thread_ptr)
    {
        EWF_LOG_ERROR("The thread pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    int ret = pthread_create(
        &thread_ptr->thread,
        &thread_ptr->attr,
        _ewf_platform_thread_entry,
        thread_ptr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to create a thread, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_thread_stop(ewf_platform_thread* thread_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!thread_ptr)
    {
        EWF_LOG_ERROR("The thread pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    int ret = pthread_cancel(thread_ptr->thread);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to cancel a thread, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_mutex_create(ewf_platform_mutex* mutex_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!mutex_ptr)
    {
        EWF_LOG_ERROR("The mutex pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    int ret;

    ret = pthread_mutexattr_init(&mutex_ptr->mutexattr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to initialize mutex attributes, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    ret = pthread_mutex_init(&mutex_ptr->mutex, &mutex_ptr->mutexattr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to initialize a mutex, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_mutex_destroy(ewf_platform_mutex* mutex_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!mutex_ptr)
    {
        EWF_LOG_ERROR("The mutex pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    int ret;

    ret = pthread_mutex_unlock(&mutex_ptr->mutex);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to unlock a mutex, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    ret = pthread_mutex_destroy(&mutex_ptr->mutex);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to destroy a mutex, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    ret = pthread_mutexattr_destroy(&mutex_ptr->mutexattr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to destory mutex attributes, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_mutex_get(ewf_platform_mutex* mutex_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!mutex_ptr)
    {
        EWF_LOG_ERROR("The mutex pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    int ret = pthread_mutex_lock(&mutex_ptr->mutex);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to lock a mutex, error: %d", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_mutex_put(ewf_platform_mutex* mutex_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!mutex_ptr)
    {
        EWF_LOG_ERROR("The mutex pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    int ret = pthread_mutex_unlock(&mutex_ptr->mutex);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to unlock a mutex, error: %d", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

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

    int ret;

    ret = pthread_mutexattr_init(&queue_ptr->mutexattr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to initialize mutex attributes, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    ret = pthread_mutex_init(&queue_ptr->mutex, &queue_ptr->mutexattr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to initialize a mutex, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

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

    int ret;

    ret = pthread_mutex_unlock(&queue_ptr->mutex);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to unlock a mutex, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    ret = pthread_mutex_destroy(&queue_ptr->mutex);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to destroy a mutex, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    ret = pthread_mutexattr_destroy(&queue_ptr->mutexattr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("Failed to destory mutex attributes, error: %d\n", ret);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

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
        int ret;

        ret = pthread_mutex_lock(&queue_ptr->mutex);
        if (ret != 0)
        {
            EWF_LOG_ERROR("Failed to lock a mutex, error: %d", ret);
            return EWF_RESULT_IRRECOVERABLE_ERROR;
        }

        if (queue_ptr->used_count >= queue_ptr->queue_size)
        {
#ifdef EWF_LOG_VERBOSE
            EWF_LOG("The queue is already full.");
#endif
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

        ret = pthread_mutex_unlock(&queue_ptr->mutex);
        if (ret != 0)
        {
            EWF_LOG_ERROR("Failed to unlock a mutex, error: %d", ret);
            return EWF_RESULT_IRRECOVERABLE_ERROR;
        }
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
        int ret;

        ret = pthread_mutex_lock(&queue_ptr->mutex);
        if (ret != 0)
        {
            EWF_LOG_ERROR("Failed to lock a mutex, error: %d", ret);
            return EWF_RESULT_IRRECOVERABLE_ERROR;
        }

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

        ret = pthread_mutex_unlock(&queue_ptr->mutex);
        if (ret != 0)
        {
            EWF_LOG_ERROR("Failed to unlock a mutex, error: %d", ret);
            return EWF_RESULT_IRRECOVERABLE_ERROR;
        }
    }
    while (wait && (result == EWF_RESULT_EMPTY_QUEUE));

    return result;
}
