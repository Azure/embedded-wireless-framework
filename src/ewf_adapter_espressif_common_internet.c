/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Espressif common internet(TCP+UDP) implementation
 ****************************************************************************/

#include "ewf_adapter_espressif_common.h"
#include "ewf_tokenizer_basic.h"

/******************************************************************************
 *
 * API
 *
 ******************************************************************************/

ewf_adapter_api_tcp ewf_adapter_espressif_common_api_tcp =
{
    ewf_adapter_espressif_common_tcp_open,
    ewf_adapter_espressif_common_tcp_close,

    ewf_adapter_espressif_common_tcp_control,

    ewf_adapter_espressif_common_tcp_set_tls_configuration,

    ewf_adapter_espressif_common_tcp_bind,
    ewf_adapter_espressif_common_tcp_listen,
    ewf_adapter_espressif_common_tcp_accept,
    ewf_adapter_espressif_common_tcp_connect,
    ewf_adapter_espressif_common_tcp_shutdown,
    ewf_adapter_espressif_common_tcp_send,
    ewf_adapter_espressif_common_tcp_receive,
};

ewf_adapter_api_udp ewf_adapter_espressif_common_api_udp =
{
    ewf_adapter_espressif_common_udp_open,
    ewf_adapter_espressif_common_udp_close,

    ewf_adapter_espressif_common_udp_control,

    ewf_adapter_espressif_common_udp_set_dtls_configuration,

    ewf_adapter_espressif_common_udp_bind,
    ewf_adapter_espressif_common_udp_shutdown,
    ewf_adapter_espressif_common_udp_send_to,
    ewf_adapter_espressif_common_udp_receive_from,
};

/******************************************************************************
 *
 * Internal functions
 *
 ******************************************************************************/

 /**
  * @brief Get an available socket from the internal internet socket pool
  * @return an index to an available entry in the socket pool, or EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_INVALID if not available
  */
static ewf_result _ewf_adapter_espressif_common_internet_socket_pool_allocate(ewf_adapter* adapter_ptr, uint32_t * socket_id_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_espressif_common* adapter_espressif_common_ptr = (ewf_adapter_espressif_common*)adapter_ptr->implementation_ptr;

    if (socket_id_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    *socket_id_ptr = EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_INVALID;

    for (int i = 0; i < EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_POOL_SIZE; ++i)
    {
        if (adapter_espressif_common_ptr->internet_socket_pool[i].used == false)
        {
            *socket_id_ptr = i;
            return EWF_RESULT_OK;
        }
    }

    return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
}

/******************************************************************************
 *
 * Internet API
 *
 ******************************************************************************/

ewf_result ewf_adapter_espressif_common_internet_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_espressif_common* implementation_ptr = (ewf_adapter_espressif_common*)adapter_ptr->implementation_ptr;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    uint32_t i;
    for (i = 0; i < EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_POOL_SIZE; ++i)
    {
        implementation_ptr->internet_socket_pool[i].id = i;
        implementation_ptr->internet_socket_pool[i].type = ewf_adapter_espressif_common_internet_socket_service_type_not_initialized;
        implementation_ptr->internet_socket_pool[i].local_port = 0;
        implementation_ptr->internet_socket_pool[i].used = false;
        implementation_ptr->internet_socket_pool[i].open = false;
        implementation_ptr->internet_socket_pool[i].open_error = false;
        implementation_ptr->internet_socket_pool[i].conn = false;
        implementation_ptr->internet_socket_pool[i].conn_error = false;
        implementation_ptr->internet_socket_pool[i].recv = false;
    }

    /* Try to set the TCP receive mode: passive mode */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPRECVMODE=0\r\n"))) return result;
    result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n");
    if (ewf_result_failed(result))
    {
        // Passive mode not supported
        implementation_ptr->passive_mode = false;
    }
    else
    {
        // Passive mode supported, use it
        implementation_ptr->passive_mode = true;
    }

    /* Disable transparent mode */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPMODE=0\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Enable multiple connections */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPMUX=1\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_internet_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * Internet URC handler
 *
 ******************************************************************************/

ewf_result ewf_adapter_espressif_common_internet_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_espressif_common* implementation_ptr = (ewf_adapter_espressif_common*)adapter_ptr->implementation_ptr;

    if (ewfl_str_starts_with((char*)buffer_ptr, "\r\n+IPD,"))
    {
        int link_id = EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_INVALID;
        int length = 0;
        int items = sscanf((char*)buffer_ptr, "\r\n+IPD,%d,%d:", &link_id, &length);
        if (items != 2 ||
            ((link_id < 0) || (EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_POOL_SIZE <= link_id)))
        {
            EWF_LOG("\nURC: unexpected format.\n");
            return EWF_RESULT_OK;
        }
        else
        {
            ewf_adapter_espressif_common_internet_socket* internet_socket_ptr =
                &implementation_ptr->internet_socket_pool[link_id];

            if (implementation_ptr->passive_mode)
            {
                internet_socket_ptr->recv = true;
            }
            else
            {
                internet_socket_ptr->recv = true;

                if (length > EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE)
                {
                    EWF_LOG("\nThe received data is too big for the configured buffer, length %d, buffer %d.\n",
                        length,
                        EWF_ADAPTER_ESPRESSIF_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
                }

                uint8_t* data_ptr = buffer_ptr;
                while (*data_ptr)
                {
                    /* check for the data marker */
                    if (*data_ptr == ':')
                    {
                        data_ptr++;
                        break;
                    }

                    /* not found in the expected range */
                    if ((buffer_ptr + 15) < data_ptr)
                    {
                        data_ptr = NULL;
                        break;
                    }

                    data_ptr++;
                }

                if (data_ptr)
                {
                    for (size_t i = 0; i < length; i++)
                    {
                        ewf_platform_queue_enqueue(internet_socket_ptr->recv_queue_ptr, data_ptr + i, sizeof(uint8_t), false);
                    }
                }
            }

            return EWF_RESULT_OK;

        }
    }

    return EWF_RESULT_UNHANDLED_URC;
}

/******************************************************************************
 *
 * Common TCP and UDP
 *
 ******************************************************************************/

ewf_result _ewf_adapter_espressif_common_internet_socket_open(ewf_adapter* adapter_ptr, ewf_adapter_espressif_common_internet_socket* internet_socket_ptr, char const* service_type_str, char const* server_str, uint32_t port, uint32_t local_port, uint32_t keep_alive)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (!service_type_str || !service_type_str[0])
    {
        EWF_LOG_ERROR("The service type string cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!server_str || !server_str[0])
    {
        EWF_LOG_ERROR("The server string cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    char socket_str[3];
    const char* socket_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));

#ifdef EWF_DEBUG
    /* Close outstanding connections just in case */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CIPCLOSE=", socket_cstr, "\r\n", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    char port_str[7];
    const char* port_cstr = ewfl_unsigned_to_str(port, port_str, sizeof(port_str));

    if (ewfl_str_equals_str("TCP", service_type_str) && keep_alive != 0)
    {
        char keep_alive_str[12];
        const char * keep_alive_cstr = ewfl_unsigned_to_str(keep_alive, keep_alive_str, sizeof(keep_alive_str));
        /* Open a connection */
        if (ewf_result_failed(result = ewf_interface_send_commands(
            interface_ptr,
            "AT+CIPSTART=",
            socket_cstr, ",",
            "\"", service_type_str, "\",",
            "\"", server_str, "\",",
            port_cstr, ",",
            keep_alive_cstr, "\r\n",
            NULL)))
            return result;
    }
    else if (ewfl_str_equals_str("UDP", service_type_str) && local_port != 0)
    {
        char local_port_str[12];
        const char* local_port_cstr = ewfl_unsigned_to_str(local_port, local_port_str, sizeof(local_port_str));
        /* Open a connection */
        if (ewf_result_failed(result = ewf_interface_send_commands(
            interface_ptr,
            "AT+CIPSTART=",
            socket_cstr, ",",
            "\"", service_type_str, "\",",
            "\"", server_str, "\",",
            port_cstr, ",",
            local_port_cstr, ",2\r\n",
            NULL)))
            return result;
    }
    else
    {
        /* Open a connection */
        if (ewf_result_failed(result = ewf_interface_send_commands(
            interface_ptr,
            "AT+CIPSTART=",
            socket_cstr, ",",
            "\"", service_type_str, "\",",
            "\"", server_str, "\",",
            port_cstr,
            "\r\n",
            NULL)))
            return result;
    }

    uint8_t* response_ptr;
    uint32_t response_length;

    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 10 * EWF_PLATFORM_TICKS_PER_SECOND))) return result;

    if (!response_ptr)
    {
        EWF_LOG_ERROR("The response_ptr is NULL.\n");
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    result = EWF_RESULT_OK;

    char expected_ok_str[] = "\r\nOK\r\n";

    bool ok_found = ewfl_buffer_ends_with(response_ptr, response_length, (uint8_t*)expected_ok_str, sizeof(expected_ok_str) - 1);

    ewf_interface_release(interface_ptr, response_ptr);

    if (!ok_found)
    {
        EWF_LOG_ERROR("The connection did not respond with OK.\n");
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    internet_socket_ptr->used = true;
    internet_socket_ptr->conn = true;
    internet_socket_ptr->conn_error = false;

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPSTATUS\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result _ewf_adapter_espressif_common_internet_socket_close(ewf_adapter* adapter_ptr, ewf_adapter_espressif_common_internet_socket* internet_socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (internet_socket_ptr->used == false)
    {
        EWF_LOG_ERROR("Socket is not open.\n");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    internet_socket_ptr->used = false;
    internet_socket_ptr->conn = false;
    internet_socket_ptr->conn_error = false;

    char socket_str[3];
    const char* socket_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CIPCLOSE=", socket_cstr, "\r\n", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    return EWF_RESULT_OK;
}

ewf_result _ewf_adapter_espressif_common_internet_socket_send(ewf_adapter* adapter_ptr, ewf_adapter_espressif_common_internet_socket* internet_socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!buffer_ptr)
    {
        EWF_LOG_ERROR("The buffer pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (buffer_length == 0)
    {
        EWF_LOG_ERROR("The length cannot be 0.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (internet_socket_ptr->conn == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    {
        char tokenizer_pattern_error_str[] = "\r\nERROR\r\n";
        ewf_tokenizer_basic_pattern tokenizer_pattern_error = {
            NULL,
            tokenizer_pattern_error_str,
            sizeof(tokenizer_pattern_error_str) - 1,
            false,
        };

        char tokenizer_pattern_ok_str[] = "\r\nOK\r\n";
        ewf_tokenizer_basic_pattern tokenizer_pattern_ok = {
            &tokenizer_pattern_error,
            tokenizer_pattern_ok_str,
            sizeof(tokenizer_pattern_ok_str) - 1,
            false,
        };

        char tokenizer_pattern_prompt_str[] = "> ";
        ewf_tokenizer_basic_pattern tokenizer_pattern_prompt = {
            &tokenizer_pattern_ok,
            tokenizer_pattern_prompt_str,
            sizeof(tokenizer_pattern_prompt_str) - 1,
            false,
        };

        ewf_result result_command;
        ewf_result result_verify_ok;
        ewf_result result_verify_prompt;

        ewf_tokenizer_basic_data* tokenizer_data_ptr = (ewf_tokenizer_basic_data*)interface_ptr->tokenizer_ptr->data_ptr;

        // Send the AT+CIPSEND command and wait for the > prompt
        ewf_tokenizer_basic_pattern* saved_end_pattern_ptr = NULL;
        ewf_tokenizer_basic_command_response_end_pattern_get(tokenizer_data_ptr, &saved_end_pattern_ptr);
        ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_data_ptr, NULL);
        ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, &tokenizer_pattern_prompt);
        char socket_str[3];
        char len_str[5];
        result_command = ewf_interface_send_commands(
            interface_ptr,
            "AT+CIPSEND=",
            ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str)), ",",
            ewfl_unsigned_to_str(buffer_length, len_str, sizeof(len_str)),
            "\r\n",
            NULL);
        if (ewf_result_succeeded(result_command))
            result_verify_ok = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_ok_str);
        if (ewf_result_succeeded(result_command) && ewf_result_succeeded(result_verify_ok))
            result_verify_prompt = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_prompt_str);
        ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_data_ptr, saved_end_pattern_ptr);
        ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, NULL);
        if (ewf_result_failed(result_command)) return result_command;
        if (ewf_result_failed(result_verify_ok)) return result_verify_ok;
        if (ewf_result_failed(result_verify_prompt)) return result_verify_prompt;
    }

    {
        char tokenizer_pattern4_str[] = "\r\nRecv ???? bytes\r\n";
        ewf_tokenizer_basic_pattern tokenizer_pattern4 = {
            NULL,
            tokenizer_pattern4_str, sizeof(tokenizer_pattern4_str) - 1, true,
            NULL, NULL,
        };

        char tokenizer_pattern3_str[] = "\r\nRecv ??? bytes\r\n";
        ewf_tokenizer_basic_pattern tokenizer_pattern3 = {
            &tokenizer_pattern4,
            tokenizer_pattern3_str, sizeof(tokenizer_pattern3_str) - 1, true,
            NULL, NULL,
        };

        char tokenizer_pattern2_str[] = "\r\nRecv ?? bytes\r\n";
        ewf_tokenizer_basic_pattern tokenizer_pattern2 = {
            &tokenizer_pattern3,
            tokenizer_pattern2_str, sizeof(tokenizer_pattern2_str) - 1, true,
            NULL, NULL,
        };

        char tokenizer_pattern1_str[] = "\r\nRecv ? bytes\r\n";
        ewf_tokenizer_basic_pattern tokenizer_pattern1 = {
            &tokenizer_pattern2,
            tokenizer_pattern1_str, sizeof(tokenizer_pattern1_str) - 1, true,
            NULL, NULL,
        };

        char tokenizer_pattern_send_fail_str[] = "\r\nSEND FAIL\r\n";
        ewf_tokenizer_basic_pattern tokenizer_pattern_send_fail = {
            NULL,
            tokenizer_pattern_send_fail_str, sizeof(tokenizer_pattern_send_fail_str) - 1, false,
            NULL, NULL,
        };

        char tokenizer_pattern_send_ok_str[] = "\r\nSEND OK\r\n";
        ewf_tokenizer_basic_pattern tokenizer_pattern_send_ok = {
            &tokenizer_pattern_send_fail,
            tokenizer_pattern_send_ok_str, sizeof(tokenizer_pattern_send_ok_str) - 1, false,
            NULL, NULL,
        };

        ewf_result result_command;
        ewf_result result_verify;
        ewf_tokenizer_basic_pattern* saved_command_end_pattern_ptr = NULL;
        ewf_tokenizer_basic_pattern* saved_command_pattern_ptr = NULL;
        ewf_tokenizer_basic_data *tokenizer_data_ptr = (ewf_tokenizer_basic_data*)interface_ptr->tokenizer_ptr->data_ptr;
        ewf_tokenizer_basic_command_response_end_pattern_get(tokenizer_data_ptr, &saved_command_end_pattern_ptr);
        ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_data_ptr, &tokenizer_pattern_send_ok);
        ewf_tokenizer_basic_command_response_pattern_get(tokenizer_data_ptr, &saved_command_pattern_ptr);
        ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, &tokenizer_pattern1);
        result_command = ewf_interface_send(interface_ptr, (const uint8_t*)buffer_ptr, buffer_length);
        if (ewf_result_succeeded(result_command)) {
            ewf_interface_drop_response(interface_ptr);
            result_verify = ewf_interface_verify_response_ends_with(interface_ptr, tokenizer_pattern_send_ok_str);
        }
        ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_data_ptr, saved_command_end_pattern_ptr);
        ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, saved_command_pattern_ptr);
        if (ewf_result_failed(result_command)) return result_command;
        if (ewf_result_failed(result_verify)) return result_verify;
    }

    return EWF_RESULT_OK;
}

ewf_result _ewf_adapter_espressif_common_internet_socket_receive(ewf_adapter* adapter_ptr, ewf_adapter_espressif_common_internet_socket* internet_socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (!buffer_ptr)
    {
        EWF_LOG_ERROR("The buffer pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!buffer_length_ptr)
    {
        EWF_LOG_ERROR("The length pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (*buffer_length_ptr == 0)
    {
        EWF_LOG_ERROR("The buffer length cannot be 0.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (internet_socket_ptr->conn == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    size_t i;
    for (i = 0; i < *buffer_length_ptr; i++)
    {
        uint32_t buffer_size = sizeof(uint8_t);
        ewf_result result = ewf_platform_queue_dequeue(internet_socket_ptr->recv_queue_ptr, &(buffer_ptr[i]), &buffer_size, false);
        if (result != EWF_RESULT_OK)
        {
            break;
        }
    }
    *buffer_length_ptr = i;

    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * TCP
 *
 ******************************************************************************/

ewf_result ewf_adapter_espressif_common_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_espressif_common* adapter_espressif_common_ptr = (ewf_adapter_espressif_common*)adapter_ptr->implementation_ptr;

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    socket_ptr->adapter_ptr = adapter_ptr;

    ewf_result result = EWF_RESULT_OK;

    uint32_t socket_id;

    if (ewf_result_failed(result = _ewf_adapter_espressif_common_internet_socket_pool_allocate(adapter_ptr, &socket_id)))
    {
        EWF_LOG_ERROR("Too many open sockets.");
        return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
    }

    socket_ptr->data_ptr = &(adapter_espressif_common_ptr->internet_socket_pool[socket_id]);

    return result;
}

ewf_result ewf_adapter_espressif_common_tcp_close(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_espressif_common_internet_socket* internet_socket_ptr = (ewf_adapter_espressif_common_internet_socket*)socket_ptr->data_ptr;
    return _ewf_adapter_espressif_common_internet_socket_close(adapter_ptr, internet_socket_ptr);
}

ewf_result ewf_adapter_espressif_common_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_espressif_common_internet_socket* internet_socket_ptr = (ewf_adapter_espressif_common_internet_socket*)socket_ptr->data_ptr;

    /* Do not bind, just save the requested port */
    internet_socket_ptr->local_port = port;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_tcp_listen(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_tcp_connect(ewf_socket_tcp* socket_ptr, const char* server_str, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_espressif_common_internet_socket* internet_socket_ptr = (ewf_adapter_espressif_common_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_espressif_common_internet_socket_open(adapter_ptr, internet_socket_ptr, "TCP", server_str, port, 0, 0);
}

ewf_result ewf_adapter_espressif_common_tcp_shutdown(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_espressif_common_internet_socket* internet_socket_ptr = (ewf_adapter_espressif_common_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_espressif_common_internet_socket_send(adapter_ptr, internet_socket_ptr, buffer_ptr, buffer_length);
}

ewf_result ewf_adapter_espressif_common_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_espressif_common_internet_socket* internet_socket_ptr = (ewf_adapter_espressif_common_internet_socket*)socket_ptr->data_ptr;

    if (!buffer_ptr)
    {
        EWF_LOG_ERROR("The buffer pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!buffer_length_ptr)
    {
        EWF_LOG_ERROR("The length pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (*buffer_length_ptr == 0)
    {
        EWF_LOG_ERROR("The buffer length cannot be 0.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (internet_socket_ptr->used == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    if (wait)
    {
        /* Wait until data is received */
        for (;;)
        {
            ewf_interface_poll(interface_ptr);
            if (internet_socket_ptr->recv)
            {
                internet_socket_ptr->recv = false;
                break;
            }
            ewf_platform_sleep(1);
        }
    }
    else
    {
        ewf_interface_poll(interface_ptr);
        if (internet_socket_ptr->recv == false)
        {
            return EWF_RESULT_NO_DATA_RECEIVED;
        }
    }

    return _ewf_adapter_espressif_common_internet_socket_receive(adapter_ptr, internet_socket_ptr, buffer_ptr, buffer_length_ptr);
}

/******************************************************************************
 *
 * UDP
 *
 ******************************************************************************/

ewf_result ewf_adapter_espressif_common_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_espressif_common* adapter_espressif_common_ptr = (ewf_adapter_espressif_common*)adapter_ptr->implementation_ptr;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    if (socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    socket_ptr->adapter_ptr = adapter_ptr;

    ewf_result result = EWF_RESULT_OK;

    uint32_t socket_id;

    if (ewf_result_failed(result = _ewf_adapter_espressif_common_internet_socket_pool_allocate(adapter_ptr, &socket_id)))
    {
        EWF_LOG_ERROR("Too many open sockets.");
        return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
    }

    socket_ptr->data_ptr = &(adapter_espressif_common_ptr->internet_socket_pool[socket_id]);

    return result;
}

ewf_result ewf_adapter_espressif_common_udp_close(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_espressif_common_internet_socket* internet_socket_ptr = (ewf_adapter_espressif_common_internet_socket*)socket_ptr->data_ptr;
    return _ewf_adapter_espressif_common_internet_socket_close(adapter_ptr, internet_socket_ptr);
}

ewf_result ewf_adapter_espressif_common_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_udp_bind(ewf_socket_udp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_espressif_common_internet_socket* internet_socket_ptr = (ewf_adapter_espressif_common_internet_socket*)socket_ptr->data_ptr;

    /* Do not bind, just save the requested port */
    internet_socket_ptr->local_port = port;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_udp_shutdown(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    /* Do nothing */

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_espressif_common_internet_socket* internet_socket_ptr = (ewf_adapter_espressif_common_internet_socket*)socket_ptr->data_ptr;

    ewf_result result;

    if (!internet_socket_ptr->used)
    {
        result = _ewf_adapter_espressif_common_internet_socket_open(adapter_ptr, internet_socket_ptr, "UDP", remote_address_str, remote_port, internet_socket_ptr->local_port, 0);
        if (ewf_result_failed(result))
        {
            EWF_LOG_ERROR("Failed to open the UDP socket.");
            return EWF_RESULT_SOCKET_NOT_OPEN;
        }
    }

    result = _ewf_adapter_espressif_common_internet_socket_send(adapter_ptr, internet_socket_ptr, buffer_ptr, buffer_length);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to close the UDP socket.");
        return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_espressif_common_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address_str, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_espressif_common_internet_socket* internet_socket_ptr = (ewf_adapter_espressif_common_internet_socket*)socket_ptr->data_ptr;

    if (!buffer_ptr)
    {
        EWF_LOG_ERROR("The buffer pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!buffer_length_ptr)
    {
        EWF_LOG_ERROR("The length pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (*buffer_length_ptr == 0)
    {
        EWF_LOG_ERROR("The buffer length cannot be 0.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (internet_socket_ptr->used == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    if (wait)
    {
        /* Wait until data is received */
        for (;;)
        {
            ewf_interface_poll(interface_ptr);
            if (internet_socket_ptr->recv)
            {
                break;
            }
            ewf_platform_sleep(1);
        }
    }
    else
    {
        ewf_interface_poll(interface_ptr);
        if (internet_socket_ptr->recv == false)
        {
            return EWF_RESULT_NO_DATA_RECEIVED;
        }
    }

    return _ewf_adapter_espressif_common_internet_socket_receive(adapter_ptr, internet_socket_ptr, buffer_ptr, buffer_length_ptr);
}
