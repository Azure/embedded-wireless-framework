/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework WIN32 platform API
 ****************************************************************************/

#include "ewf_platform_win32.h"

ewf_result ewf_platform_sleep(uint32_t time)
{
    Sleep((DWORD) time);

    return EWF_RESULT_OK;
}

static unsigned __stdcall _ewf_platform_thread_entry(void* p)
{
    if (p && ((struct _ewf_platform_thread*)p)->thread_function_ptr)
        ((struct _ewf_platform_thread*)p)->thread_function_ptr(((struct _ewf_platform_thread*)p)->thread_function_data);
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

    thread_ptr->hThread = (HANDLE) _beginthreadex(
        NULL,                       // default security attributes
        0,                          // use default stack size
        _ewf_platform_thread_entry,    // the thread function
        thread_ptr,                 // argument to the thread function
        CREATE_SUSPENDED,           // create the thread in a suspended state
        &(thread_ptr->dwThreadId)); // returns the thread identifier
    if (thread_ptr->hThread == NULL)
    {
        EWF_LOG_ERROR("Failed to create a thread, error: 0x%08X", GetLastError());
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

    if (!CloseHandle(thread_ptr->hThread))
    {
        EWF_LOG_ERROR("Failed to close a thread handle, error: 0x%08X", GetLastError());
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_thread_start(ewf_platform_thread * thread_ptr)
{
#ifdef EWF_PARAMETER_CHECKING
    if (!thread_ptr)
    {
        EWF_LOG_ERROR("The thread pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
#endif

    DWORD dwStatus = ResumeThread(thread_ptr->hThread);
    if (dwStatus == -1)
    {
        EWF_LOG_ERROR("Failed to resume a thread, error: 0x%08X", GetLastError());
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

    DWORD dwStatus = SuspendThread(thread_ptr->hThread);
    if (dwStatus == -1)
    {
        EWF_LOG_ERROR("Failed to suspend a thread, error: 0x%08X", GetLastError());
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

    mutex_ptr->hMutex = CreateMutex(NULL, FALSE, NULL);
    if (mutex_ptr->hMutex == NULL)
    {
        EWF_LOG_ERROR("Failed to create a mutex.");
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

    if (!CloseHandle(mutex_ptr->hMutex))
    {
        EWF_LOG_ERROR("Failed to close a mutex handle, error: 0x%08X", GetLastError());
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

    DWORD dwStatus = WaitForSingleObject(mutex_ptr->hMutex, INFINITE);
    if (dwStatus != WAIT_OBJECT_0)
    {
        EWF_LOG_ERROR("Failed to get a mutex, error: 0x%08X", GetLastError());
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

    if (!ReleaseMutex(mutex_ptr->hMutex))
    {
        EWF_LOG_ERROR("Failed to release a mutex, error: 0x%08X", GetLastError());
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

    queue_ptr->hMutex = CreateMutex(NULL, FALSE, NULL);
    if (queue_ptr->hMutex == NULL)
    {
        EWF_LOG_ERROR("Failed to create a mutex.");
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

    if (!CloseHandle(queue_ptr->hMutex))
    {
        EWF_LOG_ERROR("Failed to close a mutex handle, error: 0x%08X", GetLastError());
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
        DWORD dwStatus = WaitForSingleObject(queue_ptr->hMutex, INFINITE);
        if (dwStatus != WAIT_OBJECT_0)
        {
            EWF_LOG_ERROR("Failed to get a mutex, error: 0x%08X", GetLastError());
            result = EWF_RESULT_IRRECOVERABLE_ERROR;
            break;
        }

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

        if (!ReleaseMutex(queue_ptr->hMutex))
        {
            EWF_LOG_ERROR("Failed to release a mutex, error: 0x%08X", GetLastError());
            result = EWF_RESULT_IRRECOVERABLE_ERROR;
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
        DWORD dwStatus = WaitForSingleObject(queue_ptr->hMutex, INFINITE);
        if (dwStatus != WAIT_OBJECT_0)
        {
            EWF_LOG_ERROR("Failed to get a mutex, error: 0x%08X", GetLastError());
            result = EWF_RESULT_IRRECOVERABLE_ERROR;
            break;
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

        if (!ReleaseMutex(queue_ptr->hMutex))
        {
            EWF_LOG_ERROR("Failed to release a mutex, error: 0x%08X", GetLastError());
            result = EWF_RESULT_IRRECOVERABLE_ERROR;
        }
    }
    while (wait && (result == EWF_RESULT_EMPTY_QUEUE));

    return result;
}
