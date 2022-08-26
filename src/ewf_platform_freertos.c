/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework freeRTOS platform API
 ****************************************************************************/

#include "ewf_platform_freertos.h"

ewf_result ewf_platform_sleep(uint32_t time)
{
    vTaskDelay((TickType_t) time);

    return EWF_RESULT_OK;
}

static void _ewf_platform_thread_entry(void* p)
{
    if (p && ((struct _ewf_platform_thread*)p)->thread_function_ptr)
        ((struct _ewf_platform_thread*)p)->thread_function_ptr(((struct _ewf_platform_thread*)p)->thread_function_data);
}

ewf_result ewf_platform_thread_create(ewf_platform_thread * thread_ptr)
{
    if (!thread_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    thread_ptr->task_handle = xTaskCreateStatic(
        _ewf_platform_thread_entry,
        thread_ptr->name_ptr,
        thread_ptr->stack_size,
        (void*) thread_ptr,
        thread_ptr->priority,
        thread_ptr->stack_ptr,
        &(thread_ptr->task));
    if (thread_ptr->task_handle == NULL)
    {
        EWF_LOG_ERROR("Failed to create a thread");
    }

    vTaskSuspend(thread_ptr->task_handle);

    return EWF_RESULT_OK;
}


ewf_result ewf_platform_thread_destroy(ewf_platform_thread * thread_ptr)
{
    if (!thread_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    vTaskDelete(thread_ptr->task_handle);

    return EWF_RESULT_OK;
}


ewf_result ewf_platform_thread_start(ewf_platform_thread * thread_ptr)
{
    if (!thread_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    vTaskResume(thread_ptr->task_handle);

    return EWF_RESULT_OK;
}


ewf_result ewf_platform_thread_stop(ewf_platform_thread * thread_ptr)
{
    if (!thread_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    vTaskSuspend(thread_ptr->task_handle);

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_mutex_create(ewf_platform_mutex* mutex_ptr)
{
    if (!mutex_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    mutex_ptr->semaphore_handle = xSemaphoreCreateBinaryStatic(&(mutex_ptr->semaphore));
    if (mutex_ptr->semaphore_handle == NULL)
    {
        EWF_LOG_ERROR("Failed to create a mutex.");
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    xSemaphoreGive(mutex_ptr->semaphore_handle);

    return EWF_RESULT_OK;
}


ewf_result ewf_platform_mutex_destroy(ewf_platform_mutex* mutex_ptr)
{
    if (!mutex_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    vSemaphoreDelete(mutex_ptr->semaphore_handle);

    return EWF_RESULT_OK;
}


ewf_result ewf_platform_mutex_get(ewf_platform_mutex* mutex_ptr)
{
    if (!mutex_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    xSemaphoreTake(mutex_ptr->semaphore_handle, portMAX_DELAY);

    return EWF_RESULT_OK;
}


ewf_result ewf_platform_mutex_put(ewf_platform_mutex* mutex_ptr)
{
    if (!mutex_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    xSemaphoreGive(mutex_ptr->semaphore_handle);

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_create(ewf_platform_queue* queue_ptr)
{
    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    queue_ptr->xQueue = xQueueCreateStatic(
        queue_ptr->uxQueueLength,
        queue_ptr->uxItemSize,
        queue_ptr->pucQueueStorageBuffer,
        &(queue_ptr->xStaticQueue));

    if (queue_ptr->xQueue == NULL)
    {
        EWF_LOG_ERROR("Failed to create a queue.");
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_destroy(ewf_platform_queue* queue_ptr)
{
    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    vQueueDelete(queue_ptr->xQueue);

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_enqueue(ewf_platform_queue* queue_ptr, const void* data_ptr, uint32_t data_size, bool wait)
{
    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!data_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (data_size != queue_ptr->uxItemSize) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (wait)
    {
		BaseType_t status = xQueueSendToBack(queue_ptr->xQueue, data_ptr, portMAX_DELAY);
		switch (status)
		{
		case pdFALSE:
			return EWF_RESULT_FULL_QUEUE;

		case pdTRUE:
			break;

		default:
			EWF_LOG_ERROR("Failed to enqueue, error %d.\n", (int) status);
			return EWF_RESULT_IRRECOVERABLE_ERROR;
		}
    }
    else
    {
		BaseType_t status = xQueueSendToBackFromISR(queue_ptr->xQueue, data_ptr, NULL);
			switch (status)
		{
		case errQUEUE_FULL:
			return EWF_RESULT_FULL_QUEUE;

		case pdPASS:
			break;

		default:
			EWF_LOG_ERROR("Failed to enqueue, error %d.\n", (int) status);
			return EWF_RESULT_IRRECOVERABLE_ERROR;
		}
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_platform_queue_dequeue(ewf_platform_queue* queue_ptr, void* buffer_ptr, uint32_t* buffer_size_ptr, bool wait)
{
    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (!queue_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!buffer_size_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (*buffer_size_ptr < queue_ptr->uxItemSize) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (wait)
    {
		BaseType_t status = xQueueReceive(queue_ptr->xQueue, buffer_ptr, portMAX_DELAY);
		switch (status)
		{
		case pdFALSE:
			return EWF_RESULT_EMPTY_QUEUE;

		case pdTRUE:
			break;

		default:
			EWF_LOG_ERROR("Failed to dequeue, error %d.\n", (int) status);
			return EWF_RESULT_IRRECOVERABLE_ERROR;
		}
    }
    else
    {
		BaseType_t status = xQueueReceiveFromISR(queue_ptr->xQueue, buffer_ptr, NULL);
		switch (status)
		{
		case pdFALSE:
			return EWF_RESULT_EMPTY_QUEUE;

		case pdTRUE:
			break;

		default:
			EWF_LOG_ERROR("Failed to dequeue, error %d.\n", (int) status);
			return EWF_RESULT_IRRECOVERABLE_ERROR;
		}
    }

    *buffer_size_ptr = queue_ptr->uxItemSize;

    return EWF_RESULT_OK;
}
