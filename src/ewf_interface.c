/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework host interface API implementation
 ****************************************************************************/

#include "ewf_interface.h"
#include "ewf_allocator.h"
#include "ewf_tokenizer_basic.h"
#include "ewf_lib.h"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/************************************************************************//**
 *
 * Common
 *
 ****************************************************************************/

ewf_result ewf_interface_init(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result = ewf_platform_mutex_create(&interface_ptr->global_mutex);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to create the host interface access mutex, ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    /* Initialize the current message */
    interface_ptr->current_message.buffer_ptr = NULL;
    interface_ptr->current_message.buffer_length = 0;

    /* Not in Data mode initially */
    interface_ptr->data_mode = false;

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_clean(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result = ewf_platform_mutex_destroy(&interface_ptr->global_mutex);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to destory the host interface access mutex, ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_start(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Initialize the command allocator */
    if (interface_ptr->message_allocator_ptr)
    {
        result = ewf_allocator_start(interface_ptr->message_allocator_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Error creating the interface command allocator.\n");
            return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
        }
    }

    /* Initialize the data allocator */
    if (interface_ptr->data_allocator_ptr)
    {
        result = ewf_allocator_start(interface_ptr->data_allocator_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Error creating the interface data allocator.\n");
            return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
        }
    }

    /* Initialize the response queue */
    if (interface_ptr->response_queue_ptr)
    {
        result = ewf_platform_queue_create(interface_ptr->response_queue_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Error creating the interface response queue.\n");
            return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
        }
    }

    /* Initialize the URC queue */
    if (interface_ptr->urc_queue_ptr)
    {
        result = ewf_platform_queue_create(interface_ptr->urc_queue_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Error creating the interface URC queue.\n");
            return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
        }
    }

    /* Initialize the tokenizer */
    if (interface_ptr->tokenizer_ptr && interface_ptr->tokenizer_ptr->init)
    {
        result = interface_ptr->tokenizer_ptr->init(interface_ptr->tokenizer_ptr, interface_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("The tokenizer init failed, ewf_result %d.\n", result);
            return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
        }
    }

    /* Start the hardware interface */
    if (interface_ptr->hardware_start)
    {
        result = interface_ptr->hardware_start(interface_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Error starting the hardware interface.\n");
            return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
        }
    }

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_stop(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Stop the hardware interface */
    if (interface_ptr->hardware_stop)
    {
        result = interface_ptr->hardware_stop(interface_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("ewf_interface_hardware_start failed, ewf_result %d.\n", result);
        }
    }

    /* Clean the tokenizer */
    if (interface_ptr->tokenizer_ptr && interface_ptr->tokenizer_ptr->clean)
    {
        result = interface_ptr->tokenizer_ptr->clean(interface_ptr->tokenizer_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("The tokenizer clean failed, ewf_result %d.\n", result);
        }
    }

    /* Stop the interface command allocator */
    if (interface_ptr->message_allocator_ptr)
    {
        result = ewf_allocator_stop(interface_ptr->message_allocator_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("ewf_allocator_stop failed, ewf_result %d.\n", result);
        }
    }

    /* Stop the interface data allocator */
    if (interface_ptr->data_allocator_ptr)
    {
        result = ewf_allocator_stop(interface_ptr->data_allocator_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("ewf_allocator_stop failed, ewf_result %d.\n", result);
        }
    }

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_send(ewf_interface* interface_ptr, const uint8_t * const buffer, uint32_t length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    /* Expect a valid buffer */
    if (!buffer) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (length  < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_get(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    /* Log the buffer */
#ifdef EWF_DEBUG
    EWF_LOG(
        "[SEND][%4lu][%s]\n", 
        length, 
        ewfl_escape_str_to_str_buffer((char *) buffer, length));
#endif

    if (interface_ptr->tokenizer_ptr && interface_ptr->tokenizer_ptr->send)
    {
        result = interface_ptr->tokenizer_ptr->send(interface_ptr->tokenizer_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("The tokenizer send failed, ewf_result %d.\n", result);
            result = EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
        }
    }

    /* Send the buffer to the hardware */
    if (interface_ptr->hardware_send != NULL)
    {
        result = interface_ptr->hardware_send(interface_ptr, buffer, length);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("The interface hardware send failed, ewf_result %d.\n", result);
            /* Override the hardware specific error */
            result = EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
        }
    }

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_put(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return result;
}

static ewf_result _ewf_interface_enqueue(ewf_interface* interface_ptr, ewf_platform_queue* queue_ptr, uint32_t wait_time)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!queue_ptr)
    {
        EWF_LOG_ERROR("The queue pointer is NULL");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result = EWF_RESULT_OK;

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result_mutex = EWF_RESULT_OK;
    result_mutex = ewf_platform_mutex_get(&interface_ptr->global_mutex);
    if (ewf_result_failed(result_mutex))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result_mutex);
        return result_mutex;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    /* Set the message buffer */
    ewf_message message;
    message.buffer_ptr = interface_ptr->current_message.buffer_ptr;
    message.buffer_length = interface_ptr->current_message.buffer_length;

#ifdef EWF_DEBUG
    /* Log the data */
    EWF_LOG("[%s][%4lu]",
        (queue_ptr == interface_ptr->response_queue_ptr) ? "RECV" : "URC^",
        interface_ptr->current_message.buffer_length);
    EWF_LOG(ewfl_escape_str_to_str_buffer(
            (char*)interface_ptr->current_message.buffer_ptr,
            interface_ptr->current_message.buffer_length));

    EWF_LOG("\n");
#endif

    /* Clear the current RX buffer */
    interface_ptr->current_message.buffer_ptr = NULL;
    interface_ptr->current_message.buffer_length = 0;

#ifdef EWF_PLATFORM_HAS_THREADING
    result_mutex = ewf_platform_mutex_put(&interface_ptr->global_mutex);
    if (ewf_result_failed(result_mutex))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result_mutex);
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    /* Enqueue the message */
    result = ewf_platform_queue_enqueue(queue_ptr, &message, sizeof(message), wait_time);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to enqueue the message, dropping it, ewf_result %d.\n", result);
        return result;
    }

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_enqueue_response(ewf_interface* interface_ptr, uint32_t wait_time)
{
    return _ewf_interface_enqueue(interface_ptr, interface_ptr->response_queue_ptr, wait_time);
}

ewf_result ewf_interface_enqueue_urc(ewf_interface* interface_ptr, uint32_t wait_time)
{
    return _ewf_interface_enqueue(interface_ptr, interface_ptr->urc_queue_ptr, wait_time);
}

static ewf_result _ewf_interface_dequeue(ewf_interface* interface_ptr, ewf_platform_queue* queue_ptr, uint8_t** buffer_ptr_ptr, uint32_t* buffer_length_ptr, uint32_t wait_time)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!queue_ptr)
    {
        EWF_LOG_ERROR("The queue pointer is NULL");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    /* Expect a valid buffer */
    if (!buffer_ptr_ptr)
    {
        EWF_LOG_ERROR("The buffer pointer is NULL");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_message message;
    uint32_t message_size = sizeof(message);

    ewf_result result = EWF_RESULT_EMPTY_QUEUE;

    if (wait_time == 0) // Don't wait, just check if there is a message
    {
        message_size = sizeof(message);
        result = ewf_platform_queue_dequeue(queue_ptr, &message, &message_size, false);
    }
    else if (wait_time == UINT32_MAX) // Wait forever until we get a message
    {
        while (true)
        {
            message_size = sizeof(message);
            result = ewf_platform_queue_dequeue(queue_ptr, &message, &message_size, false);
            if (result != EWF_RESULT_EMPTY_QUEUE) break;
            ewf_interface_receive_poll(interface_ptr);
            if (interface_ptr->response_queue_ptr == queue_ptr)
            {
                ewf_interface_process_poll(interface_ptr);
            }
            ewf_platform_sleep(1);
        }
    }
    else // Wait for a specific amount of time
    {
        for (uint32_t timeout = wait_time; timeout > 0; timeout--)
        {
            message_size = sizeof(message);
            result = ewf_platform_queue_dequeue(queue_ptr, &message, &message_size, false);
            if (result != EWF_RESULT_EMPTY_QUEUE) break;
            ewf_interface_receive_poll(interface_ptr);
            if (interface_ptr->response_queue_ptr == queue_ptr)
            {
                ewf_interface_process_poll(interface_ptr);
            }
            ewf_platform_sleep(1);
        }
    }

    /* Nothing in the queue while waiting for the timeout */
    if (result == EWF_RESULT_EMPTY_QUEUE)
    {
        return EWF_RESULT_EMPTY_QUEUE;
    }

    /* Something went wrong */
    if (result != EWF_RESULT_OK)
    {
        return result;
    }

    /* We got a message from the queue, set the output parameters */
    *buffer_ptr_ptr = message.buffer_ptr;
    if (buffer_length_ptr) *buffer_length_ptr = message.buffer_length;

    /* OK! */
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_receive_response(ewf_interface* interface_ptr, uint8_t** buffer_ptr_ptr, uint32_t* buffer_length_ptr, uint32_t wait_time)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    return _ewf_interface_dequeue(interface_ptr, interface_ptr->response_queue_ptr, buffer_ptr_ptr, buffer_length_ptr, wait_time);
}

ewf_result ewf_interface_receive_urc(ewf_interface* interface_ptr, uint8_t** buffer_ptr_ptr, uint32_t* buffer_length_ptr, uint32_t wait_time)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    return _ewf_interface_dequeue(interface_ptr, interface_ptr->urc_queue_ptr, buffer_ptr_ptr, buffer_length_ptr, wait_time);
}

ewf_result ewf_interface_message_allocator_set(ewf_interface* interface_ptr, ewf_allocator* allocator_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    interface_ptr->message_allocator_ptr = allocator_ptr;
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_data_allocator_set(ewf_interface* interface_ptr, ewf_allocator* allocator_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    interface_ptr->data_allocator_ptr = allocator_ptr;
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_release(ewf_interface* interface_ptr, void * buffer)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (interface_ptr->message_allocator_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    return ewf_allocator_release(interface_ptr->message_allocator_ptr, buffer);
}

ewf_result ewf_interface_release_data(ewf_interface* interface_ptr, void* buffer)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (interface_ptr->data_allocator_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    return ewf_allocator_release(interface_ptr->data_allocator_ptr, buffer);
}

ewf_result ewf_interface_default_timeout_set(ewf_interface* interface_ptr, uint32_t timeout)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    interface_ptr->default_timeout = timeout;
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_default_timeout_get(ewf_interface* interface_ptr, uint32_t* timeout_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (timeout_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    *timeout_ptr = interface_ptr->default_timeout;
    return EWF_RESULT_OK;
}

/************************************************************************//**
 *
 * Polling
 *
 ****************************************************************************/

ewf_result ewf_interface_poll(ewf_interface* interface_ptr)
{
    ewf_result result = EWF_RESULT_OK;

    result = ewf_interface_receive_poll(interface_ptr);
    if (result != EWF_RESULT_EMPTY_QUEUE && ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to receive, ewf_result %d.\n", result);
        return result;
    }

    result = ewf_interface_process_poll(interface_ptr);
    if (result != EWF_RESULT_EMPTY_QUEUE && ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to process, ewf_result %d.\n", result);
    }

    return result;
}

ewf_result ewf_interface_receive_poll(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result_mutex = EWF_RESULT_OK;
    result_mutex = ewf_platform_mutex_get(&interface_ptr->global_mutex);
    if (ewf_result_failed(result_mutex))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
        return result_mutex;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    if (interface_ptr->data_mode)
    {
        do
        {
            uint8_t buffer[1];
            uint32_t buffer_length = sizeof(buffer);

            result = interface_ptr->hardware_receive(interface_ptr, buffer, &buffer_length, false);
            if (result == EWF_RESULT_EMPTY_QUEUE || result == EWF_RESULT_NO_DATA_AVAILABLE)
            {
                break;
            }
            else if (ewf_result_failed(result))
            {
                EWF_LOG_ERROR("Failed to receive data from the hardware, ewf_result %d.\n", result);
                break;
            }

            if (interface_ptr->data_mode_callback)
            {
                interface_ptr->data_mode_callback(interface_ptr, (uint8_t*)&buffer, 1U);
            }
        }
        while(ewf_result_succeeded(result));
    }
    else
    {
        do
        {
            /* If no current buffer, take a new one*/
            if (interface_ptr->current_message.buffer_ptr == NULL)
            {
                result = ewf_allocator_allocate(
                    interface_ptr->message_allocator_ptr,
                    (void**)&(interface_ptr->current_message.buffer_ptr));

                if (ewf_result_failed(result))
                {
                    EWF_LOG_ERROR("Failed to allocate a new buffer, ewf_result %d.\n", result);

                    /* Make sure the buffer pointer is still NULL */
                    interface_ptr->current_message.buffer_ptr = NULL;

                    break;
                }

                /* Zero the first character */
                interface_ptr->current_message.buffer_ptr[0] = 0;

                /* Point to the beginning of the buffer */
                interface_ptr->current_message.buffer_length = 0;
            }

            /* Process only if the buffer is valid */
            if (interface_ptr->current_message.buffer_ptr)
            {

#ifdef EWF_LOG_VERBOSE
                /* Too verbose normally, but helpful when debugging the interface */
                {
                    uint32_t i;
                    uint8_t b;
                    for (i = 0; i < interface_ptr->current_message.buffer_length; i++)
                    {
                        b = interface_ptr->current_message.buffer_ptr[i];
                        EWF_LOG("[BYTE][%3u][%c]\n", (unsigned)b, (b < 32) ? (' ') : ((char)b));
                    }
                }
#endif

                /*
                 * This code can be used if the tokenizer can handle bulk reception,
                 * otherwise the other branch of this if does character by character
                 */
                if (false) 
                {
                    uint32_t buffer_length = interface_ptr->message_allocator_ptr->block_size - interface_ptr->current_message.buffer_length;

                    result = interface_ptr->hardware_receive(
                        interface_ptr,
                        interface_ptr->current_message.buffer_ptr + interface_ptr->current_message.buffer_length,
                        &buffer_length,
                        false);
                    if (result == EWF_RESULT_EMPTY_QUEUE || result == EWF_RESULT_NO_DATA_AVAILABLE)
                    {
                        break;
                    }
                    else if (ewf_result_failed(result))
                    {
                        EWF_LOG_ERROR("Failed to receive data from the hardware, ewf_result %d.\n", result);
                        break;
                    }
                    else
                    {
                        /* Success, update the size used from the current message */
                        interface_ptr->current_message.buffer_length += buffer_length;
                    }

                    /* Call the tokenizer receive function */
                    if (interface_ptr->tokenizer_ptr && interface_ptr->tokenizer_ptr->receive)
                    {
                        result = interface_ptr->tokenizer_ptr->receive(interface_ptr->tokenizer_ptr);
                        if (ewf_result_failed(result))
                        {
                            EWF_LOG_ERROR("The tokenizer receive failed, ewf_result %d.\n", result);
                            break;
                        }
                    }
                }
                else
                {
                    if (interface_ptr->current_message.buffer_length >= interface_ptr->message_allocator_ptr->block_size)
                    {
                        break;
                    }

                    uint32_t buffer_length = 1;

                    result = interface_ptr->hardware_receive(
                        interface_ptr,
                        interface_ptr->current_message.buffer_ptr + interface_ptr->current_message.buffer_length,
                        &buffer_length,
                        false);
                    if (result == EWF_RESULT_EMPTY_QUEUE || result == EWF_RESULT_NO_DATA_AVAILABLE)
                    {
                        break;
                    }
                    else if (ewf_result_failed(result))
                    {
                        EWF_LOG_ERROR("Failed to receive data from the hardware, ewf_result %d.\n", result);
                        break;
                    }
                    else
                    {
                        /* Success, update the size used from the current message */
                        interface_ptr->current_message.buffer_length += buffer_length;

                        /* Zero terminate the buffer */
                        *(interface_ptr->current_message.buffer_ptr + interface_ptr->current_message.buffer_length) = 0;
                    }

                    /* Call the tokenizer receive function */
                    if (interface_ptr->tokenizer_ptr && interface_ptr->tokenizer_ptr->receive)
                    {
                        result = interface_ptr->tokenizer_ptr->receive(interface_ptr->tokenizer_ptr);
                        if (ewf_result_failed(result))
                        {
                            EWF_LOG_ERROR("The tokenizer receive failed, ewf_result %d.\n", result);
                            break;
                        }
                    }
                }
            }
        }
        while (ewf_result_succeeded(result));
    }

#ifdef EWF_PLATFORM_HAS_THREADING
    result_mutex = ewf_platform_mutex_put(&interface_ptr->global_mutex);
    if (ewf_result_failed(result_mutex))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return result;
}

ewf_result ewf_interface_process_poll(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    while (result == EWF_RESULT_OK)
    {
        uint8_t* buffer_ptr;
        uint32_t buffer_length;

        result = ewf_interface_receive_urc(
            interface_ptr,
            &buffer_ptr,
            &buffer_length,
            0 /* No wait*/);
        
        if (result == EWF_RESULT_EMPTY_QUEUE)
        {
            // Nothing to do on this call
            break;
        }

        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Failed to receive an URC, ewf_result %d.\n", result);
            return result;
        }

#ifdef EWF_DEBUG
        EWF_LOG("[URCv][%4lu][%s]\n", buffer_length, ewfl_escape_str_to_str_buffer((char*)buffer_ptr, buffer_length));
#endif

        if (interface_ptr->urc_callback)
        {
            result = interface_ptr->urc_callback(
                interface_ptr,
                buffer_ptr,
                buffer_length);
            if (ewf_result_failed(result))
            {
                EWF_LOG_ERROR("The URC callback failed: ewf_result %d.\n", result);
            }
        }

        if (interface_ptr->user_urc_callback)
        {
            result = interface_ptr->user_urc_callback(
                interface_ptr,
                buffer_ptr,
                buffer_length);
            if (ewf_result_failed(result))
            {
                EWF_LOG_ERROR("The user URC callback failed: ewf_result %d.\n", result);
            }
        }

        result = ewf_interface_release(interface_ptr, buffer_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Failed to release a buffer, ewf_result %d.\n", result);
            return result;
        }
    }

    return result;
}

/************************************************************************//**
 *
 * Callback
 *
 ****************************************************************************/

ewf_result ewf_interface_set_response_callback(ewf_interface* interface_ptr, ewf_interface_response_callback callback)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    interface_ptr->response_callback = callback;

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_set_urc_callback(ewf_interface* interface_ptr, ewf_interface_urc_callback callback)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    interface_ptr->urc_callback = callback;

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_set_user_urc_callback(ewf_interface* interface_ptr, ewf_interface_urc_callback callback)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    interface_ptr->user_urc_callback = callback;

    return EWF_RESULT_OK;
}

/************************************************************************//**
 *
 * Helpers
 *
 ****************************************************************************/

ewf_result ewf_interface_send_command(ewf_interface* interface_ptr, const char * command_str)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    uint32_t length;
    length = ewfl_str_length((char *) command_str);
    return ewf_interface_send(interface_ptr, (const uint8_t* ) command_str, length);
}

ewf_result ewf_interface_send_commands(ewf_interface* interface_ptr, const char * command_str, ...)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    va_list args;
    va_start(args, command_str);
    do
    {
        uint32_t length;
        length = ewfl_str_length((char *) command_str);
        result = ewf_interface_send(interface_ptr, (const uint8_t* ) command_str, length);
        if (ewf_result_failed(result))
            break;
    }
    while ((command_str = va_arg(args, char *)));
    va_end(args);

    return result;
}

ewf_result ewf_interface_drop_all_responses(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    uint8_t * response = NULL;

    while (ewf_result_succeeded(ewf_interface_receive_response(interface_ptr, &response, NULL, 0)))
    {
        if (response)
        {
            ewf_interface_release(interface_ptr, response);
        }
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_send_buffer_wait_for_prompt(ewf_interface* interface_ptr, const char* prompt_str, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;
    ewf_result result_send = EWF_RESULT_OK;
    ewf_result result_verify = EWF_RESULT_OK;

    ewf_tokenizer* tokenizer_ptr = (ewf_tokenizer*)interface_ptr->tokenizer_ptr;

    ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)tokenizer_ptr->data_ptr;

    ewf_tokenizer_basic_pattern tokenizer_pattern = {
        NULL,
        prompt_str ,
        strlen(prompt_str),
        false,
        NULL,
        NULL,
    };

    if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_basic_data_ptr, &tokenizer_pattern))) return result;

    result_send = ewf_interface_send(interface_ptr, buffer_ptr, buffer_length);

    if (ewf_result_succeeded(result_send))
    {
        result_verify = ewf_interface_verify_response(interface_ptr, prompt_str);
    }

    if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_basic_data_ptr, NULL))) return result;

    if (ewf_result_failed(result_verify)) return result_verify;

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_send_commands_wait_for_prompt(ewf_interface* interface_ptr, const char* prompt_str, const char* command_str, ...)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;
    ewf_result result_command = EWF_RESULT_OK;
    ewf_result result_verify = EWF_RESULT_OK;

    ewf_tokenizer* tokenizer_ptr = (ewf_tokenizer *) interface_ptr->tokenizer_ptr;

    ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)tokenizer_ptr->data_ptr;

    ewf_tokenizer_basic_pattern tokenizer_pattern = {
        NULL,
        prompt_str ,
        strlen(prompt_str),
        false,
        NULL,
        NULL,
    };

    if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_basic_data_ptr, &tokenizer_pattern))) return result;

    va_list args;
    va_start(args, command_str);
    do
    {
        uint32_t length;
        length = ewfl_str_length((char*)command_str);
        result_command = ewf_interface_send(interface_ptr, (const uint8_t*)command_str, length);
        if (ewf_result_failed(result_command))
            break;
    } while ((command_str = va_arg(args, char*)));
    va_end(args);

    if (ewf_result_succeeded(result_command))
    {
        result_verify = ewf_interface_verify_response(interface_ptr, prompt_str);
    }

    if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_basic_data_ptr, NULL))) return result;

    if (ewf_result_failed(result_verify)) return result_verify;

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_drop_response(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;
    uint8_t * response = NULL;

    result = ewf_interface_receive_response(interface_ptr, &response, NULL, interface_ptr->default_timeout);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Modem reception failed.\n");
        return result;
    }
    if (!response)
    {
        EWF_LOG_ERROR("Unexpected NULL response.\n");
        return result;
    }
    else
    {
        ewf_interface_release(interface_ptr, response);
    }

    return result;
}

ewf_result ewf_interface_get_response(ewf_interface* interface_ptr, uint8_t ** response_out)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t * response = NULL;

    result = ewf_interface_receive_response(interface_ptr, &response, NULL, interface_ptr->default_timeout);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Modem reception failed.\n");
        return EWF_RESULT_RECEPTION_FAILED;
    }
    if (!response)
    {
        EWF_LOG_ERROR("Unexpected NULL response.\n");
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }
    else
    {
        if (response_out) *response_out = response;
        else ewf_interface_release(interface_ptr, response);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_verify_response(ewf_interface* interface_ptr, const char * expected_str)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t * response = NULL;
    uint32_t response_legth;

    result = ewf_interface_receive_response(interface_ptr, &response, &response_legth, interface_ptr->default_timeout);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Modem reception failed.\n");
        return EWF_RESULT_RECEPTION_FAILED;
    }
    if (!response)
    {
        EWF_LOG_ERROR("Unexpected NULL response.\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }
    else
    {
        if (!ewfl_str_equals_str((char *) response, (char *) expected_str))
        {
            EWF_LOG_ERROR("Unexpected response: [%s]\n", ewfl_escape_str_to_str_buffer((char*)response, response_legth));
            ewf_interface_release(interface_ptr, response);
            return EWF_RESULT_NOT_SUPPORTED;
        }
        else
        {
            /* got the expected result, release the buffer */
            ewf_interface_release(interface_ptr, response);
        }
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_verify_responses(ewf_interface* interface_ptr, uint32_t response_count, const char **expected_str_arr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t * response = NULL;
    uint32_t response_legth;
    uint8_t i;

    result = ewf_interface_receive_response(interface_ptr, &response, &response_legth, interface_ptr->default_timeout);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Modem reception failed.\n");
        return EWF_RESULT_RECEPTION_FAILED;
    }
    if (!response)
    {
        EWF_LOG_ERROR("Unexpected NULL response.\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }
    else
    {
        for(i=0; i<response_count; i++)
        {
            if(ewfl_str_equals_str((char *) response, (char *) expected_str_arr[i]))
            {
                /* got the expected result, release the buffer */
                ewf_interface_release(interface_ptr, response);
                return EWF_RESULT_OK;
            }
        }
        EWF_LOG_ERROR("Unexpected response: %s\n", response);
        ewf_interface_release(interface_ptr, response);
        return EWF_RESULT_NOT_SUPPORTED;
    }
}

ewf_result ewf_interface_verify_response_starts_with(ewf_interface* interface_ptr, const char * expected_start_str)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t * response = NULL;
    uint32_t response_legth;

    result = ewf_interface_receive_response(interface_ptr, &response, &response_legth, interface_ptr->default_timeout);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Modem reception failed.");
        return EWF_RESULT_RECEPTION_FAILED;
    }
    if (!response)
    {
        EWF_LOG_ERROR("Unexpected NULL response.\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }
    else
    {
        if (!ewfl_str_starts_with((char *) response, (char *)expected_start_str))
        {
            EWF_LOG_ERROR("Unexpected response: %s\n", response);
            ewf_interface_release(interface_ptr, response);
            return EWF_RESULT_NOT_SUPPORTED;
        }
        else
        {
            /* got the expected result, release the buffer */
            ewf_interface_release(interface_ptr, response);
        }
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_verify_response_ends_with(ewf_interface* interface_ptr, const char* expected_end_str)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t* response = NULL;
    uint32_t response_legth;

    result = ewf_interface_receive_response(interface_ptr, &response, &response_legth, interface_ptr->default_timeout);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Modem reception failed.");
        return EWF_RESULT_RECEPTION_FAILED;
    }
    if (!response)
    {
        EWF_LOG_ERROR("Unexpected NULL response.\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }
    else
    {
        if (!ewfl_str_ends_with((char*)response, (char*)expected_end_str))
        {
            EWF_LOG_ERROR("Unexpected response: %s\n", response);
            ewf_interface_release(interface_ptr, response);
            return EWF_RESULT_NOT_SUPPORTED;
        }
        else
        {
            /* got the expected result, release the buffer */
            ewf_interface_release(interface_ptr, response);
        }
    }

    return EWF_RESULT_OK;
}
