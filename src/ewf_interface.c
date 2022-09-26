/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework host interface API implementation
 ****************************************************************************/

#include "ewf_interface.h"
#include "ewf_allocator.h"
#include "ewf_lib.h"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/************************************************************************//**
 *
 * Internal function declarations
 *
 ****************************************************************************/

static ewf_result _ewf_interface_queue_current_message();
static ewf_result _ewf_interface_receive_from_queue(ewf_interface* interface_ptr, ewf_platform_queue* queue_ptr, uint8_t** buffer_ptr_ptr, uint32_t* buffer_length_ptr, uint32_t wait_time);
static ewf_result _ewf_interface_match_current_message_to_pattern(ewf_interface* interface_ptr, const ewf_interface_tokenizer_pattern* pattern_ptr, bool* match_ptr);

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

    /* Not in command mode initially */
    interface_ptr->command_mode = false;

    /* No context active initially */
    interface_ptr->current_context = 0;

#ifdef EWF_LOG_VERBOSE
    EWF_LOG("[COMMAND MODE: FALSE]\n");
#endif

    /* Process URCs synchronously by default */
    interface_ptr->sync_urc_processing = true;

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
        result = interface_ptr->message_allocator_ptr->start(interface_ptr->message_allocator_ptr);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Error creating the interface command allocator.\n");
            return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
        }
    }

    /* Initialize the data allocator */
    if (interface_ptr->data_allocator_ptr)
    {
        result = interface_ptr->data_allocator_ptr->start(interface_ptr->data_allocator_ptr);
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
    EWF_LOG("[SEND][%4lu][%s]\n", length, ewfl_escape_str_to_str_buffer((char *) buffer, length));

    /* Enter command mode */
    interface_ptr->command_mode = true;
#ifdef EWF_LOG_VERBOSE
    EWF_LOG("[COMMAND MODE: TRUE]\n");
#endif

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

static ewf_result _ewf_interface_receive_from_queue(ewf_interface* interface_ptr, ewf_platform_queue* queue_ptr, uint8_t** buffer_ptr_ptr, uint32_t* buffer_length_ptr, uint32_t wait_time)
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

    ewf_interface_message message;
    uint32_t message_size = sizeof(message);

    ewf_result result = EWF_RESULT_EMPTY_QUEUE;
    uint32_t timeout = wait_time;
    do
    {
        message_size = sizeof(message);
        if ((result = ewf_platform_queue_dequeue(queue_ptr, &message, &message_size, false)) != EWF_RESULT_EMPTY_QUEUE) break;
        ewf_interface_receive_poll(interface_ptr);
        ewf_platform_sleep(1);
    }
    while (timeout-- > 0);

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
    return _ewf_interface_receive_from_queue(interface_ptr, interface_ptr->response_queue_ptr, buffer_ptr_ptr, buffer_length_ptr, wait_time);
}

ewf_result ewf_interface_receive_urc(ewf_interface* interface_ptr, uint8_t** buffer_ptr_ptr, uint32_t* buffer_length_ptr, uint32_t wait_time)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    return _ewf_interface_receive_from_queue(interface_ptr, interface_ptr->urc_queue_ptr, buffer_ptr_ptr, buffer_length_ptr, wait_time);
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

ewf_result ewf_interface_tokenizer_command_response_end_pattern_set(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern* tokenizer_patter_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result;
    if (ewf_result_failed(result = ewf_platform_mutex_get(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    interface_ptr->command_response_end_tokenizer_pattern_ptr = tokenizer_patter_ptr;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_put(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_tokenizer_command_response_end_pattern_get(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern** tokenizer_patter_ptr_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (tokenizer_patter_ptr_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    *tokenizer_patter_ptr_ptr = interface_ptr->command_response_end_tokenizer_pattern_ptr;
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_tokenizer_command_response_pattern_set(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern* tokenizer_patter_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result;
    if (ewf_result_failed(result = ewf_platform_mutex_get(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    interface_ptr->command_response_tokenizer_pattern_ptr = tokenizer_patter_ptr;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_put(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_tokenizer_command_response_pattern_get(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern** tokenizer_patter_ptr_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (tokenizer_patter_ptr_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    *tokenizer_patter_ptr_ptr = interface_ptr->command_response_tokenizer_pattern_ptr;
    return EWF_RESULT_OK;
}

ewf_result ewf_interface_tokenizer_urc_pattern_set(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern* tokenizer_patter_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result;
    if (ewf_result_failed(result = ewf_platform_mutex_get(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    interface_ptr->urc_tokenizer_pattern_ptr = tokenizer_patter_ptr;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_put(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_tokenizer_urc_pattern_get(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern** tokenizer_patter_ptr_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (tokenizer_patter_ptr_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    *tokenizer_patter_ptr_ptr = interface_ptr->urc_tokenizer_pattern_ptr;
    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * Internal functions
 *
 ******************************************************************************/

/**
 * @brief enqueue an incoming message
 */
static ewf_result _ewf_interface_queue_current_message(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Only if a valid buffer is available */
    if (interface_ptr->current_message.buffer_ptr)
    {
        /* Add a null terminator */
        if (interface_ptr->current_message.buffer_length <= interface_ptr->message_allocator_ptr->block_size)
            interface_ptr->current_message.buffer_ptr[interface_ptr->current_message.buffer_length] = 0;

        /* Log the data */
        EWF_LOG("[%s][%4lu][%s]\n",
            interface_ptr->command_mode ? ("RECV") : ("URC^"),
            interface_ptr->current_message.buffer_length,
            ewfl_escape_str_to_str_buffer(
                (char*)interface_ptr->current_message.buffer_ptr,
                interface_ptr->current_message.buffer_length));

        /* Process URCs */
        if (!interface_ptr->command_mode && interface_ptr->sync_urc_processing)
        {
            result = ewf_interface_urc_process_message(
                interface_ptr,
                interface_ptr->current_message.buffer_ptr,
                interface_ptr->current_message.buffer_length);

            if (ewf_result_failed(result))
            {
                EWF_LOG_ERROR("Failed to process the URC, ewf_result %d.\n", result);
            }

            /* Drop this message */
            result = ewf_interface_release(interface_ptr, (void*)interface_ptr->current_message.buffer_ptr);
            if (ewf_result_failed(result))
            {
                EWF_LOG_ERROR("Failed to release a buffer, ewf_result %d.\n", result);
            }
        }

        /* Queue the message */
        else
        {
            /* Queue the buffer */
            result = ewf_platform_queue_enqueue(
                (interface_ptr->command_mode) ? interface_ptr->response_queue_ptr : interface_ptr->urc_queue_ptr,
                &(interface_ptr->current_message),
                sizeof(interface_ptr->current_message),
                false);

            /* If queuing the message failed, then drop it */
            if (ewf_result_failed(result))
            {
                EWF_LOG_ERROR("Failed to queue a buffer, ewf_result %d.\n", result);

                /* Drop this message */
                result = ewf_interface_release(interface_ptr, (void*)interface_ptr->current_message.buffer_ptr);
                if (ewf_result_failed(result))
                {
                    EWF_LOG_ERROR("Failed to release a buffer, ewf_result %d.\n", result);
                }
            }
        }

        /* Clear the current RX buffer */
        interface_ptr->current_message.buffer_ptr = NULL;
        interface_ptr->current_message.buffer_length = 0;
    }

    return EWF_RESULT_OK;
}

/************************************************************************//**
 *
 * URC processing entry point
 *
 ****************************************************************************/

ewf_result ewf_interface_urc_processing(ewf_interface* interface_ptr)
{
    ewf_result result;

    uint8_t* buffer_ptr;
    uint32_t buffer_length;

    if (ewf_result_failed(result = ewf_interface_receive_urc(interface_ptr, &buffer_ptr, &buffer_length, 0)))
    {
        if (result != EWF_RESULT_EMPTY_QUEUE)
        {
            EWF_LOG_ERROR("Failed to receive an URC, ewf_result %d.\n", result);
        }

        return result;
    }

    if (ewf_result_failed(result = ewf_interface_release(interface_ptr, buffer_ptr)))
    {
        EWF_LOG_ERROR("Failed to release a buffer, ewf_result %d.\n", result);
        return result;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_urc_process_message(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    ewf_result result;

    EWF_LOG("[URCv][%4lu][%s]\n", buffer_length, ewfl_escape_str_to_str_buffer((char*)buffer_ptr, buffer_length));

    if (interface_ptr->urc_callback)
    {
        if (ewf_result_failed(result = interface_ptr->urc_callback(
            interface_ptr,
            interface_ptr->current_message.buffer_ptr,
            interface_ptr->current_message.buffer_length)))
        {
            EWF_LOG_ERROR("The URC callback failed: ewf_result %d.\n", result);
        }
    }

    if (interface_ptr->user_urc_callback)
    {
        if (ewf_result_failed(result = interface_ptr->user_urc_callback(
            interface_ptr,
            interface_ptr->current_message.buffer_ptr,
            interface_ptr->current_message.buffer_length)))
        {
            EWF_LOG_ERROR("The user URC callback failed: ewf_result %d.\n", result);
        }
    }

    return EWF_RESULT_OK;
}

/************************************************************************//**
 *
 * Hardware helpers
 *
 ****************************************************************************/

static ewf_result _ewf_interface_match_current_message_to_pattern(ewf_interface* interface_ptr, const ewf_interface_tokenizer_pattern* pattern_ptr, bool* match_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (pattern_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (match_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    *match_ptr = false;

    for (; pattern_ptr; pattern_ptr = pattern_ptr->netx_ptr)
    {
        if (pattern_ptr->match_function)
        {
            bool stop = false;
            if (pattern_ptr->match_function(
                (const char*)interface_ptr->current_message.buffer_ptr,
                interface_ptr->current_message.buffer_length,
                pattern_ptr,
                &stop))
            {
                *match_ptr = true;
                return EWF_RESULT_OK;
            }
            if (stop) break;
        }
        else
        {
            if (pattern_ptr->has_wildcards)
            {
                if (ewfl_buffer_ends_with_wildcard_string(
                    (const char*)interface_ptr->current_message.buffer_ptr,
                    interface_ptr->current_message.buffer_length,
                    pattern_ptr->pattern_str,
                    pattern_ptr->patter_length))
                {
                    *match_ptr = true;
                    return EWF_RESULT_OK;
                }
            }
            else
            {
                if (ewfl_buffer_ends_with(
                    (const char*)interface_ptr->current_message.buffer_ptr,
                    interface_ptr->current_message.buffer_length,
                    pattern_ptr->pattern_str,
                    pattern_ptr->patter_length))
                {
                    *match_ptr = true;
                    return EWF_RESULT_OK;
                }
            }
        }
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_process_byte(ewf_interface* interface_ptr, uint8_t b)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_get(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    /* Too verbose normally, but helpful when debugging the interface */
#ifdef EWF_LOG_VERBOSE
    EWF_LOG("[BYTE][%3u][%c]\n", (unsigned)b, (b < 32) ? (' ') : ((char)b));
#endif

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
        }

        /* Point to the beginning of the buffer */
        interface_ptr->current_message.buffer_length = 0;
    }

    /* Process only if the buffer is valid */
    if (interface_ptr->current_message.buffer_ptr)
    {
        /* Store the byte in the buffer */
        interface_ptr->current_message.buffer_ptr[(interface_ptr->current_message.buffer_length)++] = b;

        /* Add a (temporary?) NULL terminator */
        interface_ptr->current_message.buffer_ptr[interface_ptr->current_message.buffer_length] = 0;

        /* In command mode - Check for end of command and regular tokenizer patterns */
        if (interface_ptr->command_mode == true)
        {
            bool match = false;

            if (interface_ptr->command_response_end_tokenizer_pattern_ptr)
            {
                if (ewf_result_failed(
                    result = _ewf_interface_match_current_message_to_pattern(
                        interface_ptr,
                        interface_ptr->command_response_end_tokenizer_pattern_ptr,
                        &match)))
                {
                    EWF_LOG_ERROR("Error while matching the current message to the command response end tokenizer pattern, ewf_result %d.\n", result);
                }
                else
                {
                    if (match)
                    {
                        /* queue a buffer */
                        _ewf_interface_queue_current_message(interface_ptr);

                        /* and exit command mode */
                        interface_ptr->command_mode = false;

#ifdef EWF_LOG_VERBOSE
                        EWF_LOG("[COMMAND MODE: FALSE]\n");
#endif
                    }
                }
            }

            if (interface_ptr->command_response_tokenizer_pattern_ptr)
            {
                if (ewf_result_failed(
                    result = _ewf_interface_match_current_message_to_pattern(
                        interface_ptr,
                        interface_ptr->command_response_tokenizer_pattern_ptr,
                        &match)))
                {
                    EWF_LOG_ERROR("Error while matching the current message to the command response tokenizer pattern.");
                }
                else
                {
                    if (match)
                    {
                        /* queue a buffer and stay in command mode */
                        _ewf_interface_queue_current_message(interface_ptr);
                    }
                }
            }
        }

        /* In URC mode - Check for URC tokenizer patterns */
        else
        {
            bool match = false;

            if (interface_ptr->urc_tokenizer_pattern_ptr)
            {
                if (ewf_result_failed(
                    result = _ewf_interface_match_current_message_to_pattern(
                        interface_ptr,
                        interface_ptr->urc_tokenizer_pattern_ptr,
                        &match)))
                {
                    EWF_LOG_ERROR("Error while matching the current message to the URC tokenizer pattern.");
                }
                else
                {
                    if (match)
                    {
                        _ewf_interface_queue_current_message(interface_ptr);
                    }
                }
            }
        }

        /* If the buffer is still full, queue it */
        if (interface_ptr->current_message.buffer_length >= (interface_ptr->message_allocator_ptr->block_size - 1))
        {
            _ewf_interface_queue_current_message(interface_ptr);
        }
    }

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_put(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return EWF_RESULT_OK;
}

/************************************************************************//**
 *
 * Polling
 *
 ****************************************************************************/


ewf_result ewf_interface_poll(ewf_interface* interface_ptr)
{
	return ewf_interface_receive_poll(interface_ptr);
}

ewf_result ewf_interface_receive_poll(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    do
    {
        uint8_t buffer[1];
        uint32_t buffer_length = sizeof(buffer);

        result = interface_ptr->hardware_receive(interface_ptr, buffer, &buffer_length, false);
        if (result == EWF_RESULT_EMPTY_QUEUE || result == EWF_RESULT_NO_DATA_AVAILABLE)
        {
            return result;
        }
        else if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Failed to receive data from the hardware, ewf_result %d.\n", result);
            break;
        }

        /* Process the received byte */
        result = ewf_interface_process_byte(interface_ptr, buffer[0]);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Failed to process a byte, byte [%02d], ewf_result %d.\n", buffer[0], result);
        }
    }
    while(ewf_result_succeeded(result));

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

ewf_result ewf_interface_drop_response(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t * response = NULL;

    result = ewf_interface_receive_response(interface_ptr, &response, NULL, (uint32_t) -1);
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
        ewf_interface_release(interface_ptr, response);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_get_response(ewf_interface* interface_ptr, uint8_t ** response_out)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint8_t * response = NULL;

    result = ewf_interface_receive_response(interface_ptr, &response, NULL, (uint32_t) -1);
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

    result = ewf_interface_receive_response(interface_ptr, &response, &response_legth, (uint32_t) -1);
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

    result = ewf_interface_receive_response(interface_ptr, &response, &response_legth, (uint32_t) -1);
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

    result = ewf_interface_receive_response(interface_ptr, &response, &response_legth, (uint32_t) -1);
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

    result = ewf_interface_receive_response(interface_ptr, &response, &response_legth, (uint32_t)-1);
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
