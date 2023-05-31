/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Tokenizer basic API.
 ****************************************************************************/

#include "ewf_tokenizer_basic.h"
#include "ewf_interface.h"

ewf_result ewf_tokenizer_basic_init(ewf_tokenizer* tokenizer_ptr, ewf_interface* interface_ptr)
{
    if (tokenizer_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (tokenizer_ptr->data_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    tokenizer_ptr->interface_ptr = interface_ptr;

    ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)tokenizer_ptr->data_ptr;

    tokenizer_basic_data_ptr->interface_ptr = interface_ptr;

    /* Not in command mode initially */
    tokenizer_basic_data_ptr->command_mode = false;

#ifdef EWF_LOG_VERBOSE
    EWF_LOG("[COMMAND MODE: FALSE]\n");
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_clean(ewf_tokenizer* tokenizer_ptr)
{
    if (tokenizer_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (tokenizer_ptr->data_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = tokenizer_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_send(ewf_tokenizer* tokenizer_ptr)
{
    if (tokenizer_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (tokenizer_ptr->data_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = tokenizer_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)tokenizer_ptr->data_ptr;

    /* Enter command mode */
    tokenizer_basic_data_ptr->command_mode = true;

#ifdef EWF_LOG_VERBOSE
    EWF_LOG("[COMMAND MODE: TRUE]\n");
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_match_pattern(ewf_tokenizer* tokenizer_ptr, const ewf_tokenizer_basic_pattern* tokenizer_pattern_ptr, bool* match_ptr)
{
    if (tokenizer_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (tokenizer_ptr->data_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = tokenizer_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (tokenizer_pattern_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (match_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    *match_ptr = false;

    for (; tokenizer_pattern_ptr; tokenizer_pattern_ptr = tokenizer_pattern_ptr->next_ptr)
    {
        if (tokenizer_pattern_ptr->match_function)
        {
            bool stop = false;
            if (tokenizer_pattern_ptr->match_function(
                interface_ptr->current_message.buffer_ptr,
                interface_ptr->current_message.buffer_length,
                tokenizer_pattern_ptr,
                &stop))
            {
                *match_ptr = true;
                return EWF_RESULT_OK;
            }
            if (stop) break;
        }
        else
        {
            if (tokenizer_pattern_ptr->has_wildcards)
            {
                if (ewfl_buffer_ends_with_wildcard_string(
                    interface_ptr->current_message.buffer_ptr,
                    interface_ptr->current_message.buffer_length,
                    (const uint8_t*)tokenizer_pattern_ptr->pattern_str,
                    tokenizer_pattern_ptr->patter_length))
                {
                    *match_ptr = true;
                    return EWF_RESULT_OK;
                }
            }
            else
            {
                if (ewfl_buffer_ends_with(
                    interface_ptr->current_message.buffer_ptr,
                    interface_ptr->current_message.buffer_length,
                    (const uint8_t*)tokenizer_pattern_ptr->pattern_str,
                    tokenizer_pattern_ptr->patter_length))
                {
                    *match_ptr = true;
                    return EWF_RESULT_OK;
                }
            }
        }
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_receive(ewf_tokenizer* tokenizer_ptr)
{
    if (tokenizer_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (tokenizer_ptr->data_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = tokenizer_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)tokenizer_ptr->data_ptr;

    ewf_result result;

    /* Process only if the buffer is valid */
    if (interface_ptr->current_message.buffer_ptr)
    {
        /* Do we have a match? */
        bool match = false;

        /* Match the current message, generic */
        if (tokenizer_basic_data_ptr->message_tokenizer_pattern_ptr)
        {
            bool saved_command_mode = tokenizer_basic_data_ptr->command_mode;

            if (ewf_result_failed(
                result = ewf_tokenizer_basic_match_pattern(
                    tokenizer_ptr,
                    tokenizer_basic_data_ptr->message_tokenizer_pattern_ptr,
                    &match)))
            {
                EWF_LOG_ERROR("Error while matching the current message to the message tokenizer pattern, ewf_result %d.\n", result);
            }
            else
            {
                if (match)
                {
                    if (tokenizer_basic_data_ptr->command_mode)
                    {
                        ewf_interface_enqueue_response(interface_ptr, 0);
                    }
                    else
                    {
                        ewf_interface_enqueue_urc(interface_ptr, 0);
                    }
                }
            }

            tokenizer_basic_data_ptr->command_mode = saved_command_mode;
        }

        if (!match)
        {
            /* In command mode - Check for end of command and regular tokenizer patterns */
            if (tokenizer_basic_data_ptr->command_mode == true)
            {
                match = false;

                if (tokenizer_basic_data_ptr->command_response_end_tokenizer_pattern_ptr)
                {
                    if (ewf_result_failed(
                        result = ewf_tokenizer_basic_match_pattern(
                            tokenizer_ptr,
                            tokenizer_basic_data_ptr->command_response_end_tokenizer_pattern_ptr,
                            &match)))
                    {
                        EWF_LOG_ERROR("Error while matching the current message to the command response end tokenizer pattern, ewf_result %d.\n", result);
                    }
                    else
                    {
                        if (match)
                        {
                            /* queue a buffer */
                            ewf_interface_enqueue_response(interface_ptr, 0);

                            /* and exit command mode */
                            tokenizer_basic_data_ptr->command_mode = false;

#ifdef EWF_LOG_VERBOSE
                            EWF_LOG("[COMMAND MODE: FALSE]\n");
#endif
                        }
                    }
                }

                if (tokenizer_basic_data_ptr->command_response_tokenizer_pattern_ptr)
                {
                    if (ewf_result_failed(
                        result = ewf_tokenizer_basic_match_pattern(
                            tokenizer_ptr,
                            tokenizer_basic_data_ptr->command_response_tokenizer_pattern_ptr,
                            &match)))
                    {
                        EWF_LOG_ERROR("Error while matching the current message to the command response tokenizer pattern, ewf_result %d.\n", result);
                    }
                    else
                    {
                        if (match)
                        {
                            /* queue a buffer and stay in command mode */
                            ewf_interface_enqueue_response(interface_ptr, 0);
                        }
                    }
                }
            }

            /* In URC mode - Check for URC tokenizer patterns */
            else
            {
                match = false;

                if (tokenizer_basic_data_ptr->urc_tokenizer_pattern_ptr)
                {
                    if (ewf_result_failed(
                        result = ewf_tokenizer_basic_match_pattern(
                            tokenizer_ptr,
                            tokenizer_basic_data_ptr->urc_tokenizer_pattern_ptr,
                            &match)))
                    {
                        EWF_LOG_ERROR("Error while matching the current message to the URC tokenizer pattern.");
                    }
                    else
                    {
                        if (match)
                        {
                            ewf_interface_enqueue_urc(interface_ptr, 0);
                        }
                    }
                }
            }

            /* If the buffer is still full, queue it */
            if (interface_ptr->current_message.buffer_length >= (interface_ptr->message_allocator_ptr->block_size - 1))
            {
                ewf_interface_enqueue_response(interface_ptr, 0);
            }
        }
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_message_pattern_set(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern* tokenizer_pattern_ptr)
{
    ewf_interface* interface_ptr = tokenizer_data_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result;
    if (ewf_result_failed(result = ewf_platform_mutex_get(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    tokenizer_data_ptr->message_tokenizer_pattern_ptr = tokenizer_pattern_ptr;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_put(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_message_pattern_get(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern** tokenizer_pattern_ptr_ptr)
{
    ewf_interface* interface_ptr = tokenizer_data_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (tokenizer_pattern_ptr_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    *tokenizer_pattern_ptr_ptr = tokenizer_data_ptr->message_tokenizer_pattern_ptr;
    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_command_response_end_pattern_set(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern* tokenizer_pattern_ptr)
{
    ewf_interface* interface_ptr = tokenizer_data_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result;
    if (ewf_result_failed(result = ewf_platform_mutex_get(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    tokenizer_data_ptr->command_response_end_tokenizer_pattern_ptr = tokenizer_pattern_ptr;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_put(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_command_response_end_pattern_get(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern** tokenizer_pattern_ptr_ptr)
{
    ewf_interface* interface_ptr = tokenizer_data_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (tokenizer_pattern_ptr_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    *tokenizer_pattern_ptr_ptr = tokenizer_data_ptr->command_response_end_tokenizer_pattern_ptr;
    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_command_response_pattern_set(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern* tokenizer_pattern_ptr)
{
    ewf_interface* interface_ptr = tokenizer_data_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result;
    if (ewf_result_failed(result = ewf_platform_mutex_get(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    tokenizer_data_ptr->command_response_tokenizer_pattern_ptr = tokenizer_pattern_ptr;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_put(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_command_response_pattern_get(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern** tokenizer_pattern_ptr_ptr)
{
    ewf_interface* interface_ptr = tokenizer_data_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (tokenizer_pattern_ptr_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    *tokenizer_pattern_ptr_ptr = tokenizer_data_ptr->command_response_tokenizer_pattern_ptr;
    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_urc_pattern_set(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern* tokenizer_pattern_ptr)
{
    ewf_interface* interface_ptr = tokenizer_data_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_PLATFORM_HAS_THREADING
    ewf_result result;
    if (ewf_result_failed(result = ewf_platform_mutex_get(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to acquire the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    tokenizer_data_ptr->urc_tokenizer_pattern_ptr = tokenizer_pattern_ptr;

#ifdef EWF_PLATFORM_HAS_THREADING
    if (ewf_result_failed(result = ewf_platform_mutex_put(&interface_ptr->global_mutex)))
    {
        EWF_LOG_ERROR("Failed to release the host interface mutex, ewf_result %d.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }
#endif /* EWF_PLATFORM_HAS_THREADING */

    return EWF_RESULT_OK;
}

ewf_result ewf_tokenizer_basic_urc_pattern_get(ewf_tokenizer_basic_data* tokenizer_data_ptr, ewf_tokenizer_basic_pattern** tokenizer_pattern_ptr_ptr)
{
    ewf_interface* interface_ptr = tokenizer_data_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    if (tokenizer_pattern_ptr_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    *tokenizer_pattern_ptr_ptr = tokenizer_data_ptr->urc_tokenizer_pattern_ptr;

    return EWF_RESULT_OK;
}
