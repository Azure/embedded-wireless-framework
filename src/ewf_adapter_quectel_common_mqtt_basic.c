/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Common Quectel MQTT basic API implementation
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

/******************************************************************************
 *
 * API
 *
 ******************************************************************************/

ewf_adapter_api_mqtt_basic ewf_adapter_quectel_common_api_mqtt_basic =
{
    ewf_adapter_quectel_common_mqtt_basic_default_state_callback,
    ewf_adapter_quectel_common_mqtt_basic_default_message_callback,

    ewf_adapter_quectel_common_mqtt_basic_urc_callback,

    NULL, /* control, not implemented */

    ewf_adapter_quectel_common_mqtt_basic_connect,
    ewf_adapter_quectel_common_mqtt_basic_disconnect,
    ewf_adapter_quectel_common_mqtt_basic_subscribe,
    ewf_adapter_quectel_common_mqtt_basic_unsubscribe,
    ewf_adapter_quectel_common_mqtt_basic_publish,
};

/******************************************************************************
 *
 * MQTT basic API - URC handler
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_mqtt_basic_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

    const char urc_prefix_str[] = "+QMT";
    if (ewfl_str_starts_with((char*)buffer_ptr, urc_prefix_str))
    {
        char* urc_str = (char*) buffer_ptr + sizeof(urc_prefix_str) - 1;

        {
            const char match_str[] = "OPEN: 0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                char* parse_str = urc_str + sizeof(match_str) - 1;
                int err = atoi(parse_str);

                implementation_ptr->mqtt_basic_open = true;
                implementation_ptr->mqtt_basic_open_error = (err == 0) ? false : true;
                implementation_ptr->mqtt_basic_conn = false;
                implementation_ptr->mqtt_basic_conn_error = false;

                return EWF_RESULT_OK;
            }
        }

        {
            const char match_str[] = "CONN: 0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                char* parse_str = urc_str + sizeof(match_str) - 1;
                int err = atoi(parse_str);

                implementation_ptr->mqtt_basic_conn = true;
                implementation_ptr->mqtt_basic_conn_error = (err == 0) ? false : true;

                return EWF_RESULT_OK;
            }
        }

        {
            const char match_str[] = "DISC: 0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                char* parse_str = urc_str + sizeof(match_str) - 1;
                int err = atoi(parse_str);

                implementation_ptr->mqtt_basic_open = false;
                implementation_ptr->mqtt_basic_open_error = false;
                implementation_ptr->mqtt_basic_conn = false;
                implementation_ptr->mqtt_basic_conn_error = (err == 0) ? false : true;

                return EWF_RESULT_OK;
            }
        }

        {
            const char match_str[] = "STAT: 0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                char* parse_str = urc_str + sizeof(match_str) - 1;
                int err = atoi(parse_str);

                switch (err)
                {
                case 1: /* Connection is closed or reset by peer. */
                    implementation_ptr->mqtt_basic_open = false;
                    implementation_ptr->mqtt_basic_open_error = false;
                    implementation_ptr->mqtt_basic_conn = false;
                    implementation_ptr->mqtt_basic_conn_error = true;
                    break;

                case 2: /* Sending PINGREQ packet timed out or failed. */
                    /* TODO */
                    /* Deactivate PDP first, and then active PDP and
                        * reopen MQTT connection.
                        */
                    break;

                case 3: /* Sending CONNECT packet timed out or failed. */
                case 4: /* Receiving CONNECK packet timed out or failed. */
                    /* TODO */
                    /* 1. Check whether the inputted user name and
                        *    password are correct.
                        * 2. Make sure the client ID is not used.
                        * 3. Reopen MQTT connection and try to send
                        *    CONNECT packet to server again.
                        */
                    implementation_ptr->mqtt_basic_open = false;
                    implementation_ptr->mqtt_basic_open_error = false;
                    implementation_ptr->mqtt_basic_conn = false;
                    implementation_ptr->mqtt_basic_conn_error = true;
                    break;

                case 5: /* The client sends DISCONNECT packet to sever and the server is initiative to close MQTT connection. */
                    /* This is a normal process. */
                    break;

                case 6: /* The client is initiative to close MQTT connection due to packet sending failure all the time. */
                    /* TODO */
                    /* 1. Make sure the data is correct.
                        * 2. Try to reopen MQTT connection since there
                        * may be network congestion or an error.
                        */
                    implementation_ptr->mqtt_basic_open = false;
                    implementation_ptr->mqtt_basic_open_error = false;
                    implementation_ptr->mqtt_basic_conn = false;
                    implementation_ptr->mqtt_basic_conn_error = true;
                    break;

                case 7:
                    break;

                default:
                    EWF_LOG("\nURC: unexpected error code: %d", err);
                    break;
                }
                return EWF_RESULT_OK;
            }
        }

        {
            const char match_str[] = "PUB: 0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                /* Message published */
                EWF_LOG("[INFO][QUECTEL MQTT PUB]\n");
                return EWF_RESULT_OK;
            }
        }

        {
            const char match_str[] = "SUB: 0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                /* Subscribed to topic */
                EWF_LOG("[INFO][QUECTEL MQTT SUB]\n");
                return EWF_RESULT_OK;
            }
        }

        {
            const char match_str[] = "UNS: 0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                /* Unsubscribed from topic */
                EWF_LOG("[INFO][QUECTEL MQTT UNS]\n");
                return EWF_RESULT_OK;
            }
        }

        {
            const char match_str[] = "RECV: 0,";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                char* parse_str = urc_str + sizeof(match_str) - 1;

                //int msgID = atoi(parse_str); // Unused, for now

                /* Parse the topic and payload */
                {
                    char* topic = NULL;
                    char* payload = NULL;
                    {
                        char* q1 = NULL;
                        char* q2 = NULL;
                        char* q3 = NULL;
                        char* q4 = NULL;

                        for (char* p = parse_str; *p; p++)
                        {
                            if (*p == '\"')
                            {
                                if (!q1) q1 = p;
                                else if (!q2) q2 = p;
                                else if (!q3) q3 = p;
                                else if (!q4) q4 = p;
                            }
                        }

                        if (q1 && q2)
                        {
                            topic = q1+1;
                            *q2 = 0;
                        }

                        if (q3 && q4)
                        {
                            payload = q3+1;
                            *q4 = 0;
                        }
                    }

                    if (adapter_ptr->mqtt_basic_api_ptr && adapter_ptr->mqtt_basic_api_ptr->message_callback)
                    {
                        adapter_ptr->mqtt_basic_api_ptr->message_callback(adapter_ptr, topic, payload);
                    }
                }

                return EWF_RESULT_OK;
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

ewf_result ewf_adapter_quectel_common_mqtt_basic_default_state_callback(ewf_adapter* adapter_ptr, const char* state_cstr, const char* param_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    EWF_LOG("[MQTT-Basic][State callback:][%s][%s]\n", state_cstr, param_cstr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_mqtt_basic_default_message_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    EWF_LOG("[MQTT-Basic][Message callback:][%s][%s]\n", topic_cstr, payload_cstr);

    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * MQTT basic API control
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_mqtt_basic_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

    implementation_ptr->mqtt_basic_open = false;
    implementation_ptr->mqtt_basic_open_error = false;
    implementation_ptr->mqtt_basic_conn = false;
    implementation_ptr->mqtt_basic_conn_error = false;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_mqtt_basic_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * MQTT basic API
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_mqtt_basic_connect(ewf_adapter* adapter_ptr, char const* server_str, uint32_t port, char const* clientid, char const* username, char const* password)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint32_t timeout;

#ifdef EWF_DEBUG
    /* List the MQTT connections */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTOPEN?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

#ifdef EWF_DEBUG
    /* Close the connection in case it is still outstanding, ignore errors */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTCLOSE=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    char port_str[7];
    const char* port_cstr = ewfl_unsigned_to_str(port, port_str, sizeof(port_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(
            interface_ptr,
            "AT+QMTOPEN=0,",
            "\"", server_str, "\",",
            port_cstr, "\r",
            NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Wait until the socket is open */
    timeout = 30 * EWF_PLATFORM_TICKS_PER_SECOND;
    while (--timeout)
    {
        ewf_interface_receive_poll(interface_ptr);
        if (implementation_ptr->mqtt_basic_open)
        {
    EWF_LOG("connected\n");
            break;
        }
        if (implementation_ptr->mqtt_basic_open_error)
        {
    EWF_LOG("error\n");
            return EWF_RESULT_CONNECTION_FAILED;
        }
        ewf_platform_sleep(1);
    }
    if (!timeout)
    {
    EWF_LOG("timeout\n");
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QICLOSE=0\r"))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
        return EWF_RESULT_CONNECTION_FAILED;
    }

#ifdef EWF_DEBUG
    /* List the MQTT connections */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTOPEN?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

#ifdef EWF_ADAPTER_QUECTEL_BG96_TLS_BASIC_ENABLED
    /* Use SSL */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTCFG=\"ssl\",0,1,2\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
#endif

    /* Configure the MQTT version */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTCFG=\"version\",0,4\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    if (!username)
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(
                interface_ptr,
                "AT+QMTCONN=",
                "0,",
                "\"", clientid, "\"",
                "\r",
                NULL))) return result;
    }
    else if (!password)
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(
                interface_ptr,
                "AT+QMTCONN=",
                "0,",
                "\"", clientid, "\"", ",",
                "\"", username, "\"",
                "\r",
                NULL))) return result;
    }
    else /* username and password provided */
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(
                interface_ptr,
                "AT+QMTCONN=",
                "0,",
                "\"", clientid, "\"", ",",
                "\"", username, "\"", ",",
                "\"", password, "\"",
                "\r",
                NULL))) return result;
    }
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Wait until the connection is established */
    timeout = 30 * EWF_PLATFORM_TICKS_PER_SECOND;
    while (--timeout)
    {
        ewf_interface_receive_poll(interface_ptr);
        if (implementation_ptr->mqtt_basic_conn)
        {
            break;
        }
        if (implementation_ptr->mqtt_basic_conn_error)
        {
            return EWF_RESULT_UNEXPECTED_RESPONSE;
        }
        ewf_platform_sleep(1);
    }
    if (!timeout)
    {
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QICLOSE=0\r"))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
        return EWF_RESULT_CONNECTION_FAILED;
    }

#ifdef EWF_DEBUG
    /* List the MQTT connections */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTOPEN?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_mqtt_basic_disconnect(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    uint32_t timeout;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTDISC=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Wait until the connection is closed, or the timeout runs out */
    timeout = 30 * EWF_PLATFORM_TICKS_PER_SECOND;
    while (--timeout)
    {
        ewf_interface_receive_poll(interface_ptr);
        if (implementation_ptr->mqtt_basic_conn == false) break;
        ewf_platform_sleep(1);
    }

#ifdef EWF_DEBUG
    /* List the MQTT connections */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTOPEN?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_mqtt_basic_subscribe(ewf_adapter* adapter_ptr, char const* topic_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (!topic_cstr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QMTSUB=0,1,\"", topic_cstr, "\",2\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_mqtt_basic_unsubscribe(ewf_adapter* adapter_ptr, char const* topic_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (!topic_cstr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QMTUNS=0,1,\"", topic_cstr, "\"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_mqtt_basic_publish(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* message_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (!topic_cstr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!message_cstr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    /* allow empty messages, zero length, NULL pointer */
    uint32_t message_length = (message_cstr == NULL) ? 0 : strlen(message_cstr);
    if (message_length > 512) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    {
        char tokenizer_pattern_str[] = "\r\n> ";
        ewf_interface_tokenizer_pattern tokenizer_pattern = {
            NULL,
            tokenizer_pattern_str ,
            sizeof(tokenizer_pattern_str) - 1,
            false,
        };
        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern))) return result;
        char message_length_str[6];
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QMTPUB=0,0,0,0,\"", topic_cstr, "\",", ewfl_unsigned_to_str(message_length, message_length_str, sizeof(message_length_str)), "\r", NULL))) return result;
        if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_str))) return result;
        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;
    }
    if (ewf_result_failed(result = ewf_interface_send(interface_ptr, (const uint8_t*)message_cstr, message_length))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    return EWF_RESULT_OK;
}
