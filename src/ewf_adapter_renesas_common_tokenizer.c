/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework common Renesas adapter driver
 ****************************************************************************/

#include "ewf_adapter_renesas_common.h"
#include "ewf_tokenizer_basic.h"

char ewf_adapter_renesas_common_command_response_end_tokenizer_pattern5_str[] = "\r\n+CME ERROR: ???\r\n";
char ewf_adapter_renesas_common_command_response_end_tokenizer_pattern4_str[] = "\r\n+CME ERROR: ??\r\n";
char ewf_adapter_renesas_common_command_response_end_tokenizer_pattern3_str[] = "\r\n+CME ERROR: ?\r\n";
char ewf_adapter_renesas_common_command_response_end_tokenizer_pattern2_str[] = "\r\nERROR\r\n";
char ewf_adapter_renesas_common_command_response_end_tokenizer_pattern1_str[] = "\r\nOK\r\n";

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_command_response_end_tokenizer_pattern5 =
{
    NULL,
    ewf_adapter_renesas_common_command_response_end_tokenizer_pattern5_str,
    sizeof(ewf_adapter_renesas_common_command_response_end_tokenizer_pattern5_str) - 1,
    true,
    NULL,
    NULL,
};

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_command_response_end_tokenizer_pattern4 =
{
    &ewf_adapter_renesas_common_command_response_end_tokenizer_pattern5,
    ewf_adapter_renesas_common_command_response_end_tokenizer_pattern4_str,
    sizeof(ewf_adapter_renesas_common_command_response_end_tokenizer_pattern4_str) - 1,
    true,
    NULL,
    NULL,
};

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_command_response_end_tokenizer_pattern3 =
{
    &ewf_adapter_renesas_common_command_response_end_tokenizer_pattern4,
    ewf_adapter_renesas_common_command_response_end_tokenizer_pattern3_str,
    sizeof(ewf_adapter_renesas_common_command_response_end_tokenizer_pattern3_str) - 1,
    true,
    NULL,
    NULL,
};

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_command_response_end_tokenizer_pattern2 =
{
    &ewf_adapter_renesas_common_command_response_end_tokenizer_pattern3,
    ewf_adapter_renesas_common_command_response_end_tokenizer_pattern2_str,
    sizeof(ewf_adapter_renesas_common_command_response_end_tokenizer_pattern2_str) - 1,
    false,
    NULL,
    NULL,
};

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_command_response_end_tokenizer_pattern1 =
{
    &ewf_adapter_renesas_common_command_response_end_tokenizer_pattern2,
    ewf_adapter_renesas_common_command_response_end_tokenizer_pattern1_str,
    sizeof(ewf_adapter_renesas_common_command_response_end_tokenizer_pattern1_str) - 1,
    false,
    NULL,
    NULL,
};

static ewf_tokenizer_basic_pattern* ewf_adapter_renesas_common_command_response_end_tokenizer_pattern_ptr = &ewf_adapter_renesas_common_command_response_end_tokenizer_pattern1;

char ewf_adapter_renesas_common_urc_tokenizer_pattern1_str[] = "\r\n";

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_urc_tokenizer_pattern1 =
{
    NULL,
    ewf_adapter_renesas_common_urc_tokenizer_pattern1_str,
    sizeof(ewf_adapter_renesas_common_urc_tokenizer_pattern1_str) - 1,
    false,
    NULL,
    NULL,
};

static ewf_tokenizer_basic_pattern* ewf_adapter_renesas_common_urc_tokenizer_pattern_ptr = &ewf_adapter_renesas_common_urc_tokenizer_pattern1;

/*
 * Note:
 * This custom function matching pattern is not reentrant, it can be used by only one interface at a time.
 * If you have more than one adapter at the same time, you will need to provide separate state for each one.
 * The code is prepared for that. Use an instance specific state structure instead of the global static here.
 */

struct _ewf_adapter_renesas_common_message_tokenizer_pattern7_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
};

static struct _ewf_adapter_renesas_common_message_tokenizer_pattern7_match_function_state ewf_adapter_renesas_common_message_tokenizer_pattern7_match_function_state = { 0 };

static bool _ewf_adapter_renesas_common_message_tokenizer_pattern7_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_renesas_common_message_tokenizer_pattern7_match_function_state* state_ptr =
        (struct _ewf_adapter_renesas_common_message_tokenizer_pattern7_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length == 1)
    {
        state_ptr->prefix_matches = false;
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    const char prefix_str[] = "\r\n+SQNSMQTTDISCONNECT:";
    const uint32_t prefix_length = sizeof(prefix_str) - 1;

    if (buffer_length < prefix_length)
    {
        return false;
    }

    if (buffer_length == prefix_length)
    {
        if (ewfl_buffer_equals_buffer(buffer_ptr, (uint8_t*)prefix_str, prefix_length))
        {
            state_ptr->prefix_matches = true;
            return false;
        }
    }

    /* At this point the buffer it is longer than the prefix */

    /* We did not match the prefix in previous runs, just ignore the rest of the incoming characters */
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

    /* Is the message complete? */
    if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
    {
        /* Set the interface to URC mode */
        ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)state_ptr->interface_ptr->tokenizer_ptr->data_ptr;
        tokenizer_basic_data_ptr->command_mode = false;

        /* Signal the match */
        return true;
    }
    else
    {
        /* Not yet matched */
        return false;
    }
}

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_message_tokenizer_pattern7 =
{
    NULL,
    NULL,
    0,
    false,
    _ewf_adapter_renesas_common_message_tokenizer_pattern7_match_function,
    &ewf_adapter_renesas_common_message_tokenizer_pattern7_match_function_state
};

struct _ewf_adapter_renesas_common_message_tokenizer_pattern6_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
};

static struct _ewf_adapter_renesas_common_message_tokenizer_pattern6_match_function_state ewf_adapter_renesas_common_message_tokenizer_pattern6_match_function_state = { 0 };

static bool _ewf_adapter_renesas_common_message_tokenizer_pattern6_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_renesas_common_message_tokenizer_pattern6_match_function_state* state_ptr =
        (struct _ewf_adapter_renesas_common_message_tokenizer_pattern6_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length == 1)
    {
        state_ptr->prefix_matches = false;
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    const char prefix_str[] = "\r\n+SQNSMQTTONCONNECT:";
    const uint32_t prefix_length = sizeof(prefix_str) - 1;

    if (buffer_length < prefix_length)
    {
        return false;
    }

    if (buffer_length == prefix_length)
    {
        if (ewfl_buffer_equals_buffer(buffer_ptr, (uint8_t*)prefix_str, prefix_length))
        {
            state_ptr->prefix_matches = true;
            return false;
        }
    }

    /* At this point the buffer it is longer than the prefix */

    /* We did not match the prefix in previous runs, just ignore the rest of the incoming characters */
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

    /* Is the message complete? */
    if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
    {
        /* Set the interface to URC mode */
        ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)state_ptr->interface_ptr->tokenizer_ptr->data_ptr;
        tokenizer_basic_data_ptr->command_mode = false;

        /* Signal the match */
        return true;
    }
    else
    {
        /* Not yet matched */
        return false;
    }
}

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_message_tokenizer_pattern6 =
{
    &ewf_adapter_renesas_common_message_tokenizer_pattern7,
    NULL,
    0,
    false,
    _ewf_adapter_renesas_common_message_tokenizer_pattern6_match_function,
    &ewf_adapter_renesas_common_message_tokenizer_pattern6_match_function_state
};

struct _ewf_adapter_renesas_common_message_tokenizer_pattern5_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
};

static struct _ewf_adapter_renesas_common_message_tokenizer_pattern5_match_function_state ewf_adapter_renesas_common_message_tokenizer_pattern5_match_function_state = { 0 };

static bool _ewf_adapter_renesas_common_message_tokenizer_pattern5_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_renesas_common_message_tokenizer_pattern5_match_function_state* state_ptr =
        (struct _ewf_adapter_renesas_common_message_tokenizer_pattern5_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length == 1)
    {
        state_ptr->prefix_matches = false;
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    const char prefix_str[] = "\r\n+SQNSMQTTONSUBSCRIBE:";
    const uint32_t prefix_length = sizeof(prefix_str) - 1;

    if (buffer_length < prefix_length)
    {
        return false;
    }

    if (buffer_length == prefix_length)
    {
        if (ewfl_buffer_equals_buffer(buffer_ptr, (uint8_t*)prefix_str, prefix_length))
        {
            state_ptr->prefix_matches = true;
            return false;
        }
    }

    /* At this point the buffer it is longer than the prefix */

    /* We did not match the prefix in previous runs, just ignore the rest of the incoming characters */
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

    /* Is the message complete? */
    if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
    {
        /* Set the interface to URC mode */
        ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)state_ptr->interface_ptr->tokenizer_ptr->data_ptr;
        tokenizer_basic_data_ptr->command_mode = false;

        /* Signal the match */
        return true;
    }
    else
    {
        /* Not yet matched */
        return false;
    }
}

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_message_tokenizer_pattern5 =
{
    &ewf_adapter_renesas_common_message_tokenizer_pattern6,
    NULL,
    0,
    false,
    _ewf_adapter_renesas_common_message_tokenizer_pattern5_match_function,
    &ewf_adapter_renesas_common_message_tokenizer_pattern5_match_function_state
};

struct _ewf_adapter_renesas_common_message_tokenizer_pattern4_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
};

static struct _ewf_adapter_renesas_common_message_tokenizer_pattern4_match_function_state ewf_adapter_renesas_common_message_tokenizer_pattern4_match_function_state = { 0 };

static bool _ewf_adapter_renesas_common_message_tokenizer_pattern4_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_renesas_common_message_tokenizer_pattern4_match_function_state* state_ptr =
        (struct _ewf_adapter_renesas_common_message_tokenizer_pattern4_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length == 1)
    {
        state_ptr->prefix_matches = false;
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    const char prefix_str[] = "\r\n+SQNSMQTTONPUBLISH:";
    const uint32_t prefix_length = sizeof(prefix_str) - 1;

    if (buffer_length < prefix_length)
    {
        return false;
    }

    if (buffer_length == prefix_length)
    {
        if (ewfl_buffer_equals_buffer(buffer_ptr, (uint8_t*)prefix_str, prefix_length))
        {
            state_ptr->prefix_matches = true;
            return false;
        }
    }

    /* At this point the buffer it is longer than the prefix */

    /* We did not match the prefix in previous runs, just ignore the rest of the incoming characters */
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

    /* Is the message complete? */
    if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
    {
        /* Set the interface to URC mode */
        ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)state_ptr->interface_ptr->tokenizer_ptr->data_ptr;
        tokenizer_basic_data_ptr->command_mode = false;

        /* Signal the match */
        return true;
    }
    else
    {
        /* Not yet matched */
        return false;
    }
}

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_message_tokenizer_pattern4 =
{
    &ewf_adapter_renesas_common_message_tokenizer_pattern5,
    NULL,
    0,
    false,
    _ewf_adapter_renesas_common_message_tokenizer_pattern4_match_function,
    &ewf_adapter_renesas_common_message_tokenizer_pattern4_match_function_state
};

struct _ewf_adapter_renesas_common_message_tokenizer_pattern3_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
};

static struct _ewf_adapter_renesas_common_message_tokenizer_pattern3_match_function_state ewf_adapter_renesas_common_message_tokenizer_pattern3_match_function_state = { 0 };

static bool _ewf_adapter_renesas_common_message_tokenizer_pattern3_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_renesas_common_message_tokenizer_pattern3_match_function_state* state_ptr =
        (struct _ewf_adapter_renesas_common_message_tokenizer_pattern3_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length == 1)
    {
        state_ptr->prefix_matches = false;
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    const char prefix_str[] = "\r\n+SQNSH:";
    const uint32_t prefix_length = sizeof(prefix_str) - 1;

    if (buffer_length < prefix_length)
    {
        return false;
    }

    if (buffer_length == prefix_length)
    {
        if (ewfl_buffer_equals_buffer(buffer_ptr, (uint8_t*)prefix_str, prefix_length))
        {
            state_ptr->prefix_matches = true;
            return false;
        }
    }

    /* At this point the buffer it is longer than the prefix */

    /* We did not match the prefix in previous runs, just ignore the rest of the incoming characters */
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

    /* Is the message complete? */
    if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
    {
        /* Set the interface to URC mode */
        ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)state_ptr->interface_ptr->tokenizer_ptr->data_ptr;
        tokenizer_basic_data_ptr->command_mode = false;

        /* Signal the match */
        return true;
    }
    else
    {
        /* Not yet matched */
        return false;
    }
}

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_message_tokenizer_pattern3 =
{
    &ewf_adapter_renesas_common_message_tokenizer_pattern4,
    NULL,
    0,
    false,
    _ewf_adapter_renesas_common_message_tokenizer_pattern3_match_function,
    &ewf_adapter_renesas_common_message_tokenizer_pattern3_match_function_state
};

struct _ewf_adapter_renesas_common_message_tokenizer_pattern2_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
};

static struct _ewf_adapter_renesas_common_message_tokenizer_pattern2_match_function_state ewf_adapter_renesas_common_message_tokenizer_pattern2_match_function_state = { 0 };

static bool _ewf_adapter_renesas_common_message_tokenizer_pattern2_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_renesas_common_message_tokenizer_pattern2_match_function_state* state_ptr =
        (struct _ewf_adapter_renesas_common_message_tokenizer_pattern2_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length == 1)
    {
        state_ptr->prefix_matches = false;
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    /* Define the message prefixes and calculate their lengths */
     const char prefix1_str[] = "+SQNSRING: ";
     const uint32_t prefix1_length = sizeof(prefix1_str) - 1;
     const char prefix2_str[] = "\r\n+SQNSRING: ";
     const uint32_t prefix2_length = sizeof(prefix2_str) - 1;

     const uint32_t prefix_min_length = prefix1_length;
     const uint32_t prefix_max_length = prefix2_length;

     /* If the buffer is smaller than the prefix, then it is not yet for us */
     if (buffer_length < prefix_min_length)
     {
         return false;
     }


     /* We did not match the prefix in previous runs, try to match */
     if (!state_ptr->prefix_matches)
     {
         /* prefix1 */
         {
             /* If the buffer contains as many characters as the prefix, then look if it is for us */
             if (buffer_length == prefix1_length)
             {
                 if (ewfl_buffer_equals_buffer(buffer_ptr, (uint8_t*)prefix1_str, prefix1_length))
                 {
                     state_ptr->prefix_matches = true;
                     return false;
                 }
             }
         }

         /* prefix2 */
         {
             /* If the buffer contains as many characters as the prefix, then look if it is for us */
             if (buffer_length == prefix2_length)
             {
                 if (ewfl_buffer_equals_buffer(buffer_ptr, (uint8_t*)prefix2_str, prefix2_length))
                 {
                     state_ptr->prefix_matches = true;
                     return false;
                 }
             }
         }

         /* just ignore the rest of the incoming characters */
         return false;
     }

     /* If the buffer is bigger than the biggest prefix, and we do not have a match yet, then it is not yet for us */
     if (buffer_length > prefix_max_length && !state_ptr->prefix_matches)
     {
         return false;
     }

     /* At this point the buffer it is longer than the prefix */

     if (state_ptr->prefix_matches)
     {
         /* This is for us, stop parsing other tokens further down the list */
         *stop_ptr = true;
     }

     /* At this point we have a matching prefix */

     /* Is the message complete? */
     if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
     {
         /* Set the interface to URC mode */
         ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)state_ptr->interface_ptr->tokenizer_ptr->data_ptr;
         tokenizer_basic_data_ptr->command_mode = false;

         /* Signal the match */
         return true;
     }
     else
     {
         /* Not yet matched */
         return false;
     }
 }

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_message_tokenizer_pattern2 =
{
    &ewf_adapter_renesas_common_message_tokenizer_pattern3,
    NULL,
    0,
    false,
    _ewf_adapter_renesas_common_message_tokenizer_pattern2_match_function,
    &ewf_adapter_renesas_common_message_tokenizer_pattern2_match_function_state
};

struct _ewf_adapter_renesas_common_message_tokenizer_pattern1_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
};

static struct _ewf_adapter_renesas_common_message_tokenizer_pattern1_match_function_state ewf_adapter_renesas_common_message_tokenizer_pattern1_match_function_state = { 0 };

static bool _ewf_adapter_renesas_common_message_tokenizer_pattern1_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_renesas_common_message_tokenizer_pattern1_match_function_state* state_ptr =
        (struct _ewf_adapter_renesas_common_message_tokenizer_pattern1_match_function_state*)pattern_ptr->data_ptr;

    /* Initialize the state on a new buffer */
    if (buffer_length == 1)
    {
        state_ptr->prefix_matches = false;
        return false;
    }

    /* Add a NULL terminator - explicit const override */
    ((char*)buffer_ptr)[buffer_length] = 0;

    const char prefix_str[] = "\r\n+SQNSMQTTONMESSAGE:";
    const uint32_t prefix_length = sizeof(prefix_str) - 1;

    if (buffer_length < prefix_length)
    {
        return false;
    }

    if (buffer_length == prefix_length)
    {
        if (ewfl_buffer_equals_buffer(buffer_ptr, (uint8_t*)prefix_str, prefix_length))
        {
            state_ptr->prefix_matches = true;
            return false;
        }
    }

    /* At this point the buffer it is longer than the prefix */

    /* We did not match the prefix in previous runs, just ignore the rest of the incoming characters */
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

    /* Is the message complete? */
    if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
    {
        /* Set the interface to URC mode */
        ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)state_ptr->interface_ptr->tokenizer_ptr->data_ptr;
        tokenizer_basic_data_ptr->command_mode = false;

        /* Signal the match */
        return true;
    }
    else
    {
        /* Not yet matched */
        return false;
    }
}

static ewf_tokenizer_basic_pattern ewf_adapter_renesas_common_message_tokenizer_pattern1 =
{
    &ewf_adapter_renesas_common_message_tokenizer_pattern2,
    NULL,
    0,
    false,
    _ewf_adapter_renesas_common_message_tokenizer_pattern1_match_function,
    &ewf_adapter_renesas_common_message_tokenizer_pattern1_match_function_state
};

static ewf_tokenizer_basic_pattern* ewf_adapter_renesas_common_message_tokenizer_pattern_ptr = &ewf_adapter_renesas_common_message_tokenizer_pattern1;

ewf_result ewf_adapter_renesas_common_tokenizer_init(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    ewf_tokenizer_basic_data* tokenizer_basic_data_ptr = (ewf_tokenizer_basic_data*)interface_ptr->tokenizer_ptr->data_ptr;

    ewf_adapter_renesas_common_message_tokenizer_pattern1_match_function_state.interface_ptr = interface_ptr;
    ewf_adapter_renesas_common_message_tokenizer_pattern2_match_function_state.interface_ptr = interface_ptr;
    ewf_adapter_renesas_common_message_tokenizer_pattern3_match_function_state.interface_ptr = interface_ptr;
    ewf_adapter_renesas_common_message_tokenizer_pattern4_match_function_state.interface_ptr = interface_ptr;
    ewf_adapter_renesas_common_message_tokenizer_pattern5_match_function_state.interface_ptr = interface_ptr;
    ewf_adapter_renesas_common_message_tokenizer_pattern6_match_function_state.interface_ptr = interface_ptr;
    ewf_adapter_renesas_common_message_tokenizer_pattern7_match_function_state.interface_ptr = interface_ptr;

    if (ewf_result_failed(result = ewf_tokenizer_basic_message_pattern_set(tokenizer_basic_data_ptr, ewf_adapter_renesas_common_message_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface message tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_basic_data_ptr, ewf_adapter_renesas_common_command_response_end_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface command response end tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    if (ewf_result_failed(result = ewf_tokenizer_basic_urc_pattern_set(tokenizer_basic_data_ptr, ewf_adapter_renesas_common_urc_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface URC tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
    return EWF_RESULT_OK;
}
