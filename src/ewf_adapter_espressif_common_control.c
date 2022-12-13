/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework ESP common adapter API
 ****************************************************************************/

#include "ewf_adapter_espressif_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

ewf_adapter_api_control ewf_adapter_espressif_common_api_control =
{
    ewf_adapter_espressif_common_start,
    ewf_adapter_espressif_common_stop,
};

char ewf_adapter_espressif_common_command_response_end_tokenizer_pattern5_str[] = "\r\n+CME ERROR: ???\r\n";
char ewf_adapter_espressif_common_command_response_end_tokenizer_pattern4_str[] = "\r\n+CME ERROR: ??\r\n";
char ewf_adapter_espressif_common_command_response_end_tokenizer_pattern3_str[] = "\r\n+CME ERROR: ?\r\n";
char ewf_adapter_espressif_common_command_response_end_tokenizer_pattern2_str[] = "\r\nERROR\r\n";
char ewf_adapter_espressif_common_command_response_end_tokenizer_pattern1_str[] = "\r\nOK\r\n";

static ewf_interface_tokenizer_pattern ewf_adapter_espressif_common_command_response_end_tokenizer_pattern5 =
{
    NULL,
    ewf_adapter_espressif_common_command_response_end_tokenizer_pattern5_str,
    sizeof(ewf_adapter_espressif_common_command_response_end_tokenizer_pattern5_str)-1,
    true,
    NULL,
    NULL,
};

static ewf_interface_tokenizer_pattern ewf_adapter_espressif_common_command_response_end_tokenizer_pattern4 =
{
    &ewf_adapter_espressif_common_command_response_end_tokenizer_pattern5,
    ewf_adapter_espressif_common_command_response_end_tokenizer_pattern4_str,
    sizeof(ewf_adapter_espressif_common_command_response_end_tokenizer_pattern4_str)-1,
    true,
    NULL,
    NULL,
};

static ewf_interface_tokenizer_pattern ewf_adapter_espressif_common_command_response_end_tokenizer_pattern3 =
{
    &ewf_adapter_espressif_common_command_response_end_tokenizer_pattern4,
    ewf_adapter_espressif_common_command_response_end_tokenizer_pattern3_str,
    sizeof(ewf_adapter_espressif_common_command_response_end_tokenizer_pattern3_str)-1,
    true,
    NULL,
    NULL,
};

static ewf_interface_tokenizer_pattern ewf_adapter_espressif_common_command_response_end_tokenizer_pattern2 =
{
    &ewf_adapter_espressif_common_command_response_end_tokenizer_pattern3,
    ewf_adapter_espressif_common_command_response_end_tokenizer_pattern2_str,
    sizeof(ewf_adapter_espressif_common_command_response_end_tokenizer_pattern2_str)-1,
    false,
    NULL,
    NULL,
};

static ewf_interface_tokenizer_pattern ewf_adapter_espressif_common_command_response_end_tokenizer_pattern1 =
{
    &ewf_adapter_espressif_common_command_response_end_tokenizer_pattern2,
    ewf_adapter_espressif_common_command_response_end_tokenizer_pattern1_str,
    sizeof(ewf_adapter_espressif_common_command_response_end_tokenizer_pattern1_str)-1,
    false,
    NULL,
    NULL,
};

static ewf_interface_tokenizer_pattern* ewf_adapter_espressif_common_command_response_end_tokenizer_pattern_ptr = &ewf_adapter_espressif_common_command_response_end_tokenizer_pattern1;

char ewf_adapter_espressif_common_urc_tokenizer_pattern1_str[] = "\r\nOK\r\n";

static ewf_interface_tokenizer_pattern ewf_adapter_espressif_common_urc_tokenizer_pattern1 =
{
    NULL,
    ewf_adapter_espressif_common_urc_tokenizer_pattern1_str,
    sizeof(ewf_adapter_espressif_common_urc_tokenizer_pattern1_str) - 1,
    false,
    NULL,
    NULL,
};

static ewf_interface_tokenizer_pattern* ewf_adapter_espressif_common_urc_tokenizer_pattern_ptr = &ewf_adapter_espressif_common_urc_tokenizer_pattern1;

/*
 * Note: 
 * This custom function matching pattern is not reentrant, it can be used by only one interface at a time.
 * If you have more than one adapter at the same time, you will need to provide separate state for each one.
 * The code is prepared for that. Use an instance specific state structure instead of the global static here.
 */

struct _ewf_adapter_espressif_common_message_tokenizer_pattern1_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
    bool parsed;
    uint32_t link_id;
    uint32_t length;
    uint32_t total_expected_urc_length;
};

static struct _ewf_adapter_espressif_common_message_tokenizer_pattern1_match_function_state ewf_adapter_espressif_common_message_tokenizer_pattern1_match_function_state = { 0 };

static bool _ewf_adapter_espressif_common_message_tokenizer_pattern1_match_function(const char* buffer_ptr, uint32_t buffer_length, const ewf_interface_tokenizer_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_espressif_common_message_tokenizer_pattern1_match_function_state* state_ptr =
        (struct _ewf_adapter_espressif_common_message_tokenizer_pattern1_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length == 1)
    {
        state_ptr->prefix_matches = false;
        state_ptr->parsed = false;
        state_ptr->total_expected_urc_length = 0;
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    /* Define the message prefix and calculate its length */
    const char prefix_str[] = "\r\n+IPD,";
    const uint32_t prefix_length = sizeof(prefix_str) - 1;

    /* If the buffer is smaller than the prefix, then it is not yet for us */
    if (buffer_length < prefix_length)
    {
        return false;
    }

    /* If the buffer contains as many characters as the prefix, then look if it is for us */
    if (buffer_length == prefix_length)
    {
        if (ewfl_buffer_equals_buffer(buffer_ptr, prefix_str, prefix_length))
        {
            state_ptr->prefix_matches = true;
            return false;
        }
    }

    /* At this point the buffer it is longer than the prefix */

    /* We did not match the prefix in previous runs, just ignore the rest of the incomming characters */
    if (!state_ptr->prefix_matches)
    {
        return false;
    }
    else
    {
        /* This is for us, stop parsing other tokens further down the list */
        *stop_ptr = true;
    }

    /* At this point we have a matching prefix */

    /* If the message parameters were not yet parsed, then do it now */
    if (!state_ptr->parsed)
    {
        /* Look for the message parameter terminator: ':' */
        if (buffer_ptr[buffer_length - 1] != ':')
        {
            return false;
        }
        else
        {
            /* The message is complete, try to parse it */
            int count = sscanf(buffer_ptr, "\r\n+IPD,%lu,%lu:", &state_ptr->link_id, &state_ptr->length);
            if (count != 2)
            {
                EWF_LOG_ERROR("Unexpected response format!\n");
                return false;
            }
            state_ptr->total_expected_urc_length = buffer_length + state_ptr->length;
            state_ptr->parsed = true;
            return false;
        }
    }

    /* From this point we parsed data */

    /* Is the message complete? */
    if (buffer_length >= state_ptr->total_expected_urc_length)
    {
        /* Set the interface to URC mode */
        if (state_ptr->interface_ptr) state_ptr->interface_ptr->command_mode = false;

        /* Signal the match */
        return true;
    }
    else
    {
        /* Not yet matched */
        return false;
    }
}

static ewf_interface_tokenizer_pattern ewf_adapter_espressif_common_message_tokenizer_pattern1 =
{
    NULL,
    NULL,
    0,
    false,
    _ewf_adapter_espressif_common_message_tokenizer_pattern1_match_function,
    &ewf_adapter_espressif_common_message_tokenizer_pattern1_match_function_state
};

static ewf_interface_tokenizer_pattern* ewf_adapter_espressif_common_message_tokenizer_pattern_ptr = &ewf_adapter_espressif_common_message_tokenizer_pattern1;

ewf_result ewf_adapter_espressif_common_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_espressif_common* implementation_ptr = (ewf_adapter_espressif_common*)adapter_ptr->implementation_ptr;

    ewf_result result;

    /* Initialize the interface */
    if (ewf_result_failed(result = ewf_interface_init(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to initialize the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Set the interface default timeout */
    if (ewf_result_failed(result = ewf_interface_default_timeout_set(interface_ptr, EWF_PLATFORM_TICKS_PER_SECOND * 5)))
    {
        EWF_LOG_ERROR("Failed to set the interface default timeout: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Initialize the interface tokenizer patterns */

    ewf_adapter_espressif_common_message_tokenizer_pattern1_match_function_state.interface_ptr = interface_ptr;
    if (ewf_result_failed(result = ewf_interface_tokenizer_message_pattern_set(interface_ptr, ewf_adapter_espressif_common_message_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface message tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_end_pattern_set(interface_ptr, ewf_adapter_espressif_common_command_response_end_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface command response end tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    if (ewf_result_failed(result = ewf_interface_tokenizer_urc_pattern_set(interface_ptr, ewf_adapter_espressif_common_urc_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface URC tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Start the interface */
    if (ewf_result_failed(result = ewf_interface_start(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Initialize the reception queues */
    {
#if (EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_POOL_SIZE != 5)
#error Please update the code below to match
#endif
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[0].recv_queue_ptr, queue0, uint8_t, EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[1].recv_queue_ptr, queue1, uint8_t, EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[2].recv_queue_ptr, queue2, uint8_t, EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[3].recv_queue_ptr, queue3, uint8_t, EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[4].recv_queue_ptr, queue4, uint8_t, EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
    
        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[0].recv_queue_ptr);
        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[1].recv_queue_ptr);
        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[2].recv_queue_ptr);
        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[3].recv_queue_ptr);
        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[4].recv_queue_ptr);
    }

    /* AT - wake the module */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Restart the module to clear state and connections */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+RST\r\n"))) return result;
    {
        /* Wait two seconds, polling at each tick and dropping responses */
        for (int i = 0; i < (EWF_PLATFORM_TICKS_PER_SECOND * 2); i++)
        {
            ewf_interface_poll(interface_ptr);
            ewf_platform_sleep(1);
            if (ewf_result_failed(result = ewf_interface_drop_all_responses(interface_ptr))) return result;
        }
    }

    /* AT - wake the module */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Log the firmware info */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+GMR\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Disable local echo */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "ATE0\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Check that the modem is responding */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Start the APIs */

#if EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED || EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED
    if (ewf_result_failed(result = ewf_adapter_espressif_common_internet_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the internet API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_ESPRESSIF_COMMON_TLS_ENABLED
    if (ewf_result_failed(result = ewf_adapter_espressif_common_tls_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the TLS API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_ESPRESSIF_COMMON_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_espressif_common_tls_basic_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the TLS basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_ESPRESSIF_COMMON_MQTT_ENABLED
    if (ewf_result_failed(result = ewf_adapter_espressif_common_mqtt_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the MQTT API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_ESPRESSIF_COMMON_MQTT_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_espressif_common_mqtt_basic_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the MQTT basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Stop the APIs */

#if defined(EWF_ADAPTER_ESPRESSIF_COMMON_TCP_ENABLED) || defined(EWF_ADAPTER_ESPRESSIF_COMMON_UDP_ENABLED)
    if (ewf_result_failed(result = ewf_adapter_espressif_common_internet_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the internet API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_ESPRESSIF_COMMON_TLS_ENABLED
    if (ewf_result_failed(result = ewf_adapter_espressif_common_tls_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the TLS API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
}
#endif

#if EWF_ADAPTER_ESPRESSIF_COMMON_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_espressif_common_tls_basic_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the TLS basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_ESPRESSIF_COMMON_MQTT_ENABLED
    if (ewf_result_failed(result = ewf_adapter_espressif_common_mqtt_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the MQTT API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_ESPRESSIF_COMMON_MQTT_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_espressif_common_mqtt_basic_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the MQTT basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

    /* Stop the interface */
    if (ewf_result_failed(result = ewf_interface_stop(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to clean the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Cleanup the interface */
    if (ewf_result_failed(result = ewf_interface_init(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to clean the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    return EWF_RESULT_OK;
}
