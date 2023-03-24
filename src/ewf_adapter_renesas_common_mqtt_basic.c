/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Common Renesas MQTT basic API implementation
 ****************************************************************************/

#include "ewf_adapter_renesas_common.h"
#include "ewf_tokenizer_basic.h"

/******************************************************************************
 * API
 ******************************************************************************/

ewf_adapter_api_mqtt_basic ewf_adapter_renesas_common_api_mqtt_basic =
{
    ewf_adapter_renesas_common_mqtt_basic_default_state_callback,
    ewf_adapter_renesas_common_mqtt_basic_default_message_callback,

    ewf_adapter_renesas_common_mqtt_basic_urc_callback,

    NULL, /* control, not implemented */

    ewf_adapter_renesas_common_mqtt_basic_connect,
    ewf_adapter_renesas_common_mqtt_basic_disconnect,
    ewf_adapter_renesas_common_mqtt_basic_subscribe,
    ewf_adapter_renesas_common_mqtt_basic_unsubscribe,
    ewf_adapter_renesas_common_mqtt_basic_publish,
    ewf_adapter_renesas_common_mqtt_basic_message_get,
};

/******************************************************************************
 *
 * MQTT basic API - URC handler
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_common_mqtt_basic_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_common* adapter_renesas_common_ptr = (ewf_adapter_renesas_common*)adapter_ptr->implementation_ptr;

    EWF_PARAMETER_NOT_USED(buffer_length);

    const char urc_prefix_str[] = "+SQNSMQTT";
    if (ewfl_str_starts_with((char*)buffer_ptr, urc_prefix_str))
    {
        char* urc_str = (char*)(buffer_ptr + sizeof(urc_prefix_str) - 1);

        {
            const char match_str[] = "ONCONNECT:0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                /* Skip until "+SQNSMQTTONCONNECT:0,-" */
                char* parse_str = (char *)(urc_str +  ewfl_str_length(match_str) + 1);
                uint32_t err = ewfl_str_to_unsigned(parse_str);
                if(err == 0)
                {
                    adapter_renesas_common_ptr->mqtt_basic_conn = true;
                    adapter_renesas_common_ptr->mqtt_basic_conn_error =  (uint8_t)err;
                    return EWF_RESULT_OK;
                }
                else
                {
                    adapter_renesas_common_ptr->mqtt_basic_conn = false;
                    adapter_renesas_common_ptr->mqtt_basic_conn_error = (uint8_t)err;
                    EWF_LOG("[RYZ ADAPTER][MQTT CONN ERR] [CODE : -%ld]", err);
                    return EWF_RESULT_OK;
                }
            }
        }

        {
            const char match_str[] = "PUBLISH:0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                char* parse_str = urc_str + sizeof(match_str) - 1;
                char* q1 = NULL;

                /* skip to the error code */
                q1 = (ewfl_find_chars_with_terms(parse_str, ",", NULL)) + 1;
                uint32_t err = ewfl_str_to_unsigned(q1);
                if(err != 0)
                {
                    EWF_LOG("[RYZ ADAPTER][MQTT PUBLISH ERR] [CODE : %ld]\r\n", err);
                    adapter_renesas_common_ptr->mqtt_basic_publish_error = (uint8_t)err;
                }
                adapter_renesas_common_ptr->mqtt_basic_publish = true;
                return EWF_RESULT_OK;
            }
        }

        {
            const char match_str[] = "SUBSCRIBE:0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                char* parse_str = urc_str + sizeof(match_str) - 1;
                char* q1 = NULL;

                /* skip to the error code */
                q1 = (ewfl_find_chars_with_terms(parse_str, ",", NULL)) + 1;
                uint32_t err = ewfl_str_to_unsigned(q1);
                if(err != 0)
                {
                    EWF_LOG("[RYZ ADAPTER][MQTT SUBSCRIBE ERR] [CODE : %ld]\r\n", err);
                    adapter_renesas_common_ptr->mqtt_basic_subscribe_error = (uint8_t)err;
                }
                adapter_renesas_common_ptr->mqtt_basic_subscribe = true;
                return EWF_RESULT_OK;
            }
        }

        {
            const char match_str[] = "DISCONNECT:0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                /* Skip until "+SQNSMQTTDISCONNECT:0," */
                char* parse_str = (char *)(urc_str +  sizeof(match_str) - 1);
                uint32_t err = ewfl_str_to_unsigned(parse_str);
                if(err == 0)
                {
                    adapter_renesas_common_ptr->mqtt_basic_conn = false;
                    adapter_renesas_common_ptr->mqtt_basic_conn_error = false;
                    return EWF_RESULT_OK;
                }
                else
                {
                    adapter_renesas_common_ptr->mqtt_basic_conn = false;
                    adapter_renesas_common_ptr->mqtt_basic_conn_error = true;
                    EWF_LOG("[RYZ ADAPTER][MQTT DISCONNECT ERR] [CODE : -%ld]", err);
                    return EWF_RESULT_OK;
                }
            }
        }

        {
            const char match_str[] = "ONMESSAGE:0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                /* MQTT Received Message URC format : +SQNSMQTTONMESSAGE:<id>,<topic>,<msg_length>,<qos>[,<mid>] */
                char* parse_str = urc_str + sizeof(match_str) - 1;

                /* Parse the topic */
                {
                    char* topic = NULL;
                    {
                        char* q1 = NULL;
                        char* q2 = NULL;

                        q1 = ewfl_find_chars_with_terms(parse_str, "\"", NULL);
                        q2 = ewfl_find_chars_with_terms(q1+1, "\"", NULL);
                        if (q1 && q2)
                        {
                            topic = q1+1;
                            *q2 = 0;
                        }

                    }

                    if (adapter_ptr->mqtt_basic_api_ptr && adapter_ptr->mqtt_basic_api_ptr->message_callback)
                    {
                        adapter_ptr->mqtt_basic_api_ptr->message_callback(adapter_ptr, topic, NULL);
                    }

                    return EWF_RESULT_OK;
                }
            }
        }
    }

    return EWF_RESULT_UNHANDLED_URC;
}

/******************************************************************************
 *
 * MQTT basic API - default callbacks
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_common_mqtt_basic_default_state_callback(ewf_adapter* adapter_ptr, const char* state_cstr, const char* param_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
#ifdef EWF_DEBUG
    EWF_LOG("[MQTT-Basic][State callback:][%s][%s]\n", state_cstr, param_cstr);
#else
    EWF_PARAMETER_NOT_USED(state_cstr);
    EWF_PARAMETER_NOT_USED(param_cstr);
#endif
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_common_mqtt_basic_default_message_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_PARAMETER_NOT_USED(payload_cstr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

#ifdef EWF_DEBUG
    EWF_LOG("[MQTT-Basic][Message callback][TOPIC:][%s]\r\n", topic_cstr);
#else
    EWF_PARAMETER_NOT_USED(topic_cstr);
    EWF_PARAMETER_NOT_USED(payload_cstr);
#endif
    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * MQTT basic API control
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_common_mqtt_basic_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_renesas_common* implementation_ptr = (ewf_adapter_renesas_common*)adapter_ptr->implementation_ptr;

    implementation_ptr->mqtt_basic_conn = false;
    implementation_ptr->mqtt_basic_conn_error = false;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_common_mqtt_basic_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * MQTT basic API
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_common_mqtt_basic_connect(ewf_adapter* adapter_ptr, char const* const server, uint32_t port, char const* const clientid, char const* const username, char const* const password)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_common* adapter_renesas_common_ptr = (ewf_adapter_renesas_common*)adapter_ptr->implementation_ptr;

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

#ifdef EWF_DEBUG
    /* Close the connection in case it is still outstanding, ignore errors */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNSMQTTDISCONNECT=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    /* MQTT client configuration */
    if (!username)
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTCFG=0,\"", clientid, "\"\r", NULL))) return result;
    }
    else if (!password)
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTCFG=0,\"", clientid, "\",\"", username, "\",,", EWF_CONFIG_ADAPTER_RENESAS_COMMON_SECURITY_PROFILE_ID, "\r", NULL))) return result;
    }
    else /* username and password provided */
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTCFG=0,\"", clientid, "\",\"", username, "\",\"", password, "\",", EWF_CONFIG_ADAPTER_RENESAS_COMMON_SECURITY_PROFILE_ID, "\"\r", NULL))) return result;
    }
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    char port_str[7] = {0};
    const char* port_cstr = ewfl_unsigned_to_str(port, port_str, sizeof(port_str));

    /* Initiate MQTT connection */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTCONNECT=0,\"", server, "\",", port_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    for (unsigned i = 0; i < (60 * EWF_PLATFORM_TICKS_PER_SECOND); i++)
    {
        if (adapter_renesas_common_ptr->mqtt_basic_conn) break;
        if (adapter_renesas_common_ptr->mqtt_basic_conn_error) return EWF_RESULT_UNEXPECTED_RESPONSE;
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_common_mqtt_basic_disconnect(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_common* adapter_renesas_common_ptr = (ewf_adapter_renesas_common*)adapter_ptr->implementation_ptr;

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNSMQTTDISCONNECT=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    for (unsigned i = 0; i < (30 * EWF_PLATFORM_TICKS_PER_SECOND); i++)
    {
        if (adapter_renesas_common_ptr->mqtt_basic_conn == false) break;
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_common_mqtt_basic_subscribe(ewf_adapter* adapter_ptr, char const* topic)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_common* adapter_renesas_common_ptr = (ewf_adapter_renesas_common*)adapter_ptr->implementation_ptr;

    ewf_result result;

    if(!topic) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if(adapter_renesas_common_ptr->mqtt_basic_conn_error) return EWF_RESULT_ADAPTER_MQTT_DISCONNECTED;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTSUBSCRIBE=0,\"", topic, "\",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    for (unsigned i = 0; i < (2 * EWF_PLATFORM_TICKS_PER_SECOND); i++)
    {
        if (adapter_renesas_common_ptr->mqtt_basic_subscribe) break;
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }
    adapter_renesas_common_ptr->mqtt_basic_subscribe = false;
    if(adapter_renesas_common_ptr->mqtt_basic_subscribe_error)
    {
        return EWF_RESULT_ADAPTER_MQTT_SUBSCRIBE_FAILED;
    }
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_common_mqtt_basic_unsubscribe(ewf_adapter* adapter_ptr, char const* topic)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    if (!topic) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    /* This modem does not have AT command to unsubscribe from a topic */

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_common_mqtt_basic_publish(ewf_adapter* adapter_ptr, const char* const topic, const char* message_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_common* adapter_renesas_common_ptr = (ewf_adapter_renesas_common*)adapter_ptr->implementation_ptr;

    if (!topic) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!message_cstr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if(adapter_renesas_common_ptr->mqtt_basic_conn_error) return EWF_RESULT_ADAPTER_MQTT_DISCONNECTED;

    ewf_result result;
    uint8_t* response;

    /* allow empty messages, zero length, NULL pointer */
    uint32_t message_length = (message_cstr == NULL) ? 0 : strlen(message_cstr);

    char tokenizer_pattern_str[] = "\r\n> ";
    ewf_tokenizer_basic_pattern tokenizer_pattern = {
        NULL,
        tokenizer_pattern_str ,
        sizeof(tokenizer_pattern_str) - 1,
        false,
        NULL,
        NULL,
    };
    char message_length_str[6] = {0};
    ewf_tokenizer_basic_data* tokenizer_data_ptr = (ewf_tokenizer_basic_data*)interface_ptr->tokenizer_ptr->data_ptr;
    if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, &tokenizer_pattern))) return result;
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTPUBLISH=0,\"", topic, "\",,", ewfl_unsigned_to_str(message_length, message_length_str, sizeof(message_length_str)), "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_str))) return result;
    if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_send(interface_ptr, (uint8_t*)message_cstr, message_length))) return result;
    if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response))) return result;
    if (!ewfl_str_starts_with((char*)response, "\r\n+SQNSMQTTPUBLISH: "))
    {
        EWF_LOG_ERROR("Unexpected NULL response.");
    }
    ewf_interface_release(interface_ptr, response);
    for (unsigned i = 0; i < (2 * EWF_PLATFORM_TICKS_PER_SECOND); i++)
    {
        if (adapter_renesas_common_ptr->mqtt_basic_publish) break;
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }
    adapter_renesas_common_ptr->mqtt_basic_publish = false;
    if(adapter_renesas_common_ptr->mqtt_basic_publish_error)
    {
        return EWF_RESULT_ADAPTER_MQTT_PUBLISH_FAILED;
    }
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_common_mqtt_basic_message_get(ewf_adapter* adapter_ptr, const char* topic_cstr, char* message_buffer_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_common* adapter_renesas_common_ptr = (ewf_adapter_renesas_common*)adapter_ptr->implementation_ptr;

    if(adapter_renesas_common_ptr->mqtt_basic_conn_error) return EWF_RESULT_ADAPTER_MQTT_DISCONNECTED;

    ewf_result result = EWF_RESULT_OK;
    uint8_t* response = NULL;

    if ((!message_buffer_ptr) || (!topic_cstr))
    {
        return(EWF_RESULT_INVALID_FUNCTION_ARGUMENT);
    }
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTRCVMESSAGE=0,\"", topic_cstr, "\"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response))) return result;

    if (ewfl_str_ends_with((char*)response, "\r\nOK\r\n"))
    {
        ewfl_str_n_cpy((char*)message_buffer_ptr, (char*)response, ewfl_str_length((char*)response) - 6);
    }
    else
    {
        /* No message with the queried topic received */
        ewf_interface_release(interface_ptr, response);
        return EWF_RESULT_ADAPTER_MQTT_MESSAGE_GET_FAILED;
    }
    ewf_interface_release(interface_ptr, response);

    return EWF_RESULT_OK;
}
