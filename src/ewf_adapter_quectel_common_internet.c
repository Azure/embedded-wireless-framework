/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel common internet(TCP+UDP) implementation
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"
#include "ewf_tokenizer_basic.h"

/******************************************************************************
 *
 * API
 *
 ******************************************************************************/

ewf_adapter_api_tcp ewf_adapter_quectel_common_api_tcp =
{
    ewf_adapter_quectel_common_tcp_open,
    ewf_adapter_quectel_common_tcp_close,

    ewf_adapter_quectel_common_tcp_control,

    ewf_adapter_quectel_common_tcp_set_tls_configuration,

    ewf_adapter_quectel_common_tcp_bind,
    ewf_adapter_quectel_common_tcp_listen,
    ewf_adapter_quectel_common_tcp_accept,
    ewf_adapter_quectel_common_tcp_connect,
    ewf_adapter_quectel_common_tcp_shutdown,
    ewf_adapter_quectel_common_tcp_send,
    ewf_adapter_quectel_common_tcp_receive,
};

ewf_adapter_api_udp ewf_adapter_quectel_common_api_udp =
{
    ewf_adapter_quectel_common_udp_open,
    ewf_adapter_quectel_common_udp_close,

    ewf_adapter_quectel_common_udp_control,

    ewf_adapter_quectel_common_udp_set_dtls_configuration,

    ewf_adapter_quectel_common_udp_bind,
    ewf_adapter_quectel_common_udp_shutdown,
    ewf_adapter_quectel_common_udp_send_to,
    ewf_adapter_quectel_common_udp_receive_from,
};

/******************************************************************************
 *
 * Internal functions
 *
 ******************************************************************************/

 /**
  * @brief Get an available socket from the internal internet socket pool
  * @return an index to an available entry in the socket pool, or EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_INVALID if not available
  */
static ewf_result _ewf_adapter_quectel_common_internet_socket_pool_allocate(ewf_adapter* adapter_ptr, uint32_t * socket_id_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

    if (socket_id_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    *socket_id_ptr = EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_INVALID;

    for (int i = 0; i < EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_POOL_SIZE; ++i)
    {
        if (implementation_ptr->internet_socket_pool[i].used == false)
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

ewf_result ewf_adapter_quectel_common_internet_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

    ewf_result result = EWF_RESULT_OK;

    /* Disable QISEND echo */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QISDE=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Initialize the internal data */
    {
        uint32_t i;
        for (i = 0; i < EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_POOL_SIZE; ++i)
        {
            implementation_ptr->internet_socket_pool[i].socket_ptr = NULL;
            implementation_ptr->internet_socket_pool[i].id = i;
            implementation_ptr->internet_socket_pool[i].local_port = 0;
            implementation_ptr->internet_socket_pool[i].type = ewf_adapter_quectel_common_internet_socket_service_type_not_initialized;
            implementation_ptr->internet_socket_pool[i].used = false;
            implementation_ptr->internet_socket_pool[i].open = false;
            implementation_ptr->internet_socket_pool[i].open_error = false;
            implementation_ptr->internet_socket_pool[i].conn = false;
            implementation_ptr->internet_socket_pool[i].conn_error = false;
        }
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_internet_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * Internet URC handler
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_internet_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

    if (ewfl_str_starts_with((char*)buffer_ptr, "+QIOPEN: "))
    {
        int connectionID = EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_INVALID;
        int err = -1;
        int items = sscanf((char*)buffer_ptr, "+QIOPEN: %u,%u", &connectionID, &err);
        if (items != 2 ||
            ((connectionID < 0) || (EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_POOL_SIZE <= connectionID)))
        {
            EWF_LOG("\nURC: unexpected format.");
            return EWF_RESULT_OK;
        }
        else
        {
            ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = &(implementation_ptr->internet_socket_pool[connectionID]);

            if (err)
            {
                internet_socket_ptr->used = false;
                internet_socket_ptr->conn = false;
                internet_socket_ptr->conn_error = true;
            }
            else
            {
                internet_socket_ptr->used = true;
                internet_socket_ptr->conn = true;
                internet_socket_ptr->conn_error = false;
            }
            return EWF_RESULT_OK;
        }
    }

    if (ewfl_str_starts_with((char*)buffer_ptr, "+QIURC: \"closed\","))
    {
        int connectionID = EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_INVALID;
        int items = sscanf((char*)buffer_ptr, "+QIURC: \"closed\",%u", &connectionID);
        if (items != 1 ||
            ((connectionID < 0) || (EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_POOL_SIZE <= connectionID)))
        {
            EWF_LOG("\nURC: unexpected format.\n");
            return EWF_RESULT_OK;
        }
        else
        {
            ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = &(implementation_ptr->internet_socket_pool[connectionID]);

            internet_socket_ptr->open = false;
            internet_socket_ptr->open_error = false;
            internet_socket_ptr->conn = false;
            internet_socket_ptr->conn_error = false;

            if (internet_socket_ptr->socket_ptr)
            {
                switch (internet_socket_ptr->type)
                {
                case ewf_adapter_quectel_common_internet_socket_service_type_tcp:
                case ewf_adapter_quectel_common_internet_socket_service_type_tcp_listener:
                {
                    ewf_socket_tcp* socket_ptr = (ewf_socket_tcp*)internet_socket_ptr->socket_ptr;
                    if (socket_ptr->disconnect_callback) socket_ptr->disconnect_callback(socket_ptr);
                }
                break;
                default:
                    EWF_LOG_ERROR("Unexpected URC for this socket type.\n");
                    break;
                }
            }

            return EWF_RESULT_OK;
        }
    }

    if (ewfl_str_starts_with((char*)buffer_ptr, "+QIURC: \"recv\","))
    {
        int connectionID = EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_INVALID;
        int items = sscanf((char*)buffer_ptr, "+QIURC: \"recv\",%u", &connectionID);
        if (items != 1 ||
            ((connectionID < 0) || (EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_POOL_SIZE <= connectionID)))
        {
            EWF_LOG("\nURC: unexpected format.\n");
            return EWF_RESULT_OK;
        }
        else
        {
            ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = &(implementation_ptr->internet_socket_pool[connectionID]);

            if (internet_socket_ptr->socket_ptr)
            {
                switch (internet_socket_ptr->type)
                {
                case ewf_adapter_quectel_common_internet_socket_service_type_tcp:
                case ewf_adapter_quectel_common_internet_socket_service_type_tcp_listener:
                {
                    ewf_socket_tcp* socket_ptr = (ewf_socket_tcp*)internet_socket_ptr->socket_ptr;
                    if (socket_ptr->receive_callback)
                    {
                        /* TODO */
                    }
                }
                break;
                case ewf_adapter_quectel_common_internet_socket_service_type_udp:
                case ewf_adapter_quectel_common_internet_socket_service_type_udp_listener:
                {
                    ewf_socket_udp* socket_ptr = (ewf_socket_udp*)internet_socket_ptr->socket_ptr;
                    if (socket_ptr->receive_callback)
                    {
                        /* TODO */
                    }
                }
                break;
                default:
                    EWF_LOG_ERROR("Unexpected URC for this socket type.\n");
                    break;
                }
            }
            return EWF_RESULT_OK;
        }
    }

    if (ewfl_str_starts_with((char*)buffer_ptr, "+QIURC: \"incoming\","))
    {
        // TODO : incoming connection
        return EWF_RESULT_OK;
    }

    return EWF_RESULT_UNHANDLED_URC;
}

/******************************************************************************
 *
 * Common TCP and UDP
 *
 ******************************************************************************/

ewf_result _ewf_adapter_quectel_common_internet_log_last_error(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIGETERROR\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    return result;
}

ewf_result _ewf_adapter_quectel_common_internet_socket_open(ewf_adapter* adapter_ptr, ewf_adapter_quectel_common_internet_socket* internet_socket_ptr, char const* service_type_str, uint16_t local_port, char const* server_str, uint16_t remote_port)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    if (!service_type_str)
    {
        EWF_LOG_ERROR("The service type string cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!server_str)
    {
        EWF_LOG_ERROR("The server string cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    char connection_id_str[8];
    const char* connection_id_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, connection_id_str, sizeof(connection_id_str));

    /* Close an outstanding connection, just in case */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QICLOSE=", connection_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    char local_port_str[8];
    const char* local_port_cstr = ewfl_unsigned_to_str(local_port, local_port_str, sizeof(local_port_str));

    char remote_port_str[8];
    const char* remote_port_cstr = ewfl_unsigned_to_str(remote_port, remote_port_str, sizeof(remote_port_str));

    /* Open a connection */
    result = ewf_interface_send_commands(
        interface_ptr,
        "AT+QIOPEN=1,",
        connection_id_cstr, ",",
        "\"", service_type_str, "\",",
        "\"", server_str, "\",",
        remote_port_cstr, ",",
        local_port_cstr, ",",
        "0\r",
        NULL);
    if (ewf_result_failed(result))
    return result;

    /* Verify the command result */
    result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n");
    if (ewf_result_failed(result))
    {
        _ewf_adapter_quectel_common_internet_log_last_error(adapter_ptr);
        return result;
    }

    /* Wait until the connection is established */
    uint32_t timeout = 150 * EWF_PLATFORM_TICKS_PER_SECOND;
    for (; timeout; timeout--)
    {
        if (internet_socket_ptr->conn)
        {
            break;
        }
        if (internet_socket_ptr->conn_error)
        {
            EWF_LOG("\nFailed to open a socket service, type [%s], server [%s], local port [%s], remote port[%s]\n", service_type_str, server_str, local_port_cstr, remote_port_cstr);
            return EWF_RESULT_CONNECTION_FAILED;
        }
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }

    /* If we reached the timeout*/
    if (!timeout)
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QICLOSE=", connection_id_cstr, "\r", NULL))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
        return EWF_RESULT_CONNECTION_FAILED;
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QISTATE=1,", connection_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result _ewf_adapter_quectel_common_internet_socket_close(ewf_adapter* adapter_ptr, ewf_adapter_quectel_common_internet_socket* internet_socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

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

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QICLOSE=", socket_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    return EWF_RESULT_OK;
}

ewf_result _ewf_adapter_quectel_common_internet_socket_send(ewf_adapter* adapter_ptr, ewf_adapter_quectel_common_internet_socket* internet_socket_ptr, const char* remote_address_str, uint16_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    if (!internet_socket_ptr)
    {
        EWF_LOG_ERROR("The internet socket pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (internet_socket_ptr->type == ewf_adapter_quectel_common_internet_socket_service_type_udp ||
        internet_socket_ptr->type == ewf_adapter_quectel_common_internet_socket_service_type_udp_listener)
    {
        if (remote_address_str == NULL || remote_port == 0)
        {
            EWF_LOG_ERROR("The remote address and port need to be specified for a UDP SERVER send.");
            return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
        }
    }
    else if (internet_socket_ptr->type == ewf_adapter_quectel_common_internet_socket_service_type_tcp ||
             internet_socket_ptr->type == ewf_adapter_quectel_common_internet_socket_service_type_tcp_listener)
    {
        if (remote_address_str != NULL || remote_port != 0)
        {
            EWF_LOG_ERROR("The remote address and port are not used for send command with this socket type.");
            return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
        }
    }

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
        if (internet_socket_ptr->type == ewf_adapter_quectel_common_internet_socket_service_type_udp)
        {
            result = _ewf_adapter_quectel_common_internet_socket_open(adapter_ptr, internet_socket_ptr, "UDP", internet_socket_ptr->local_port, remote_address_str, remote_port);
            if (ewf_result_failed(result))
            {
                EWF_LOG_ERROR("Filed to open the UDP socket.\n");
                return result;
            }
        }
        else
        {
            EWF_LOG_ERROR("The socket is not open.\n");
            return EWF_RESULT_SOCKET_NOT_OPEN;
        }
    }

    char connection_id_str[8];
    char const* connection_id_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, connection_id_str, sizeof(connection_id_str));

    char buffer_length_str[8];
    char const* buffer_length_cstr = ewfl_unsigned_to_str(buffer_length, buffer_length_str, sizeof(buffer_length_str));

#ifdef EWF_DEBUG
    EWF_LOG("_ewf_adapter_quectel_common_internet_socket_send - ENTRY - BEGIN\n");
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QISEND=", connection_id_cstr, ",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QIRD=", connection_id_cstr, ",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    EWF_LOG("_ewf_adapter_quectel_common_internet_socket_send - ENTRY - END\n");
#endif

    {
        ewf_tokenizer_basic_pattern* tokenizer_basic_command_response_pattern_saved_ptr = NULL;

        char tokenizer_pattern_str[] = "\r\n> ";
        ewf_tokenizer_basic_pattern tokenizer_pattern = {
            NULL,
            tokenizer_pattern_str,
            sizeof(tokenizer_pattern_str) - 1,
            false,
        };

        ewf_tokenizer_basic_data* tokenizer_data_ptr = (ewf_tokenizer_basic_data*)interface_ptr->tokenizer_ptr->data_ptr;

        if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_get(tokenizer_data_ptr, &tokenizer_basic_command_response_pattern_saved_ptr))) return result;

        if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, &tokenizer_pattern))) return result;

        ewf_result result_send_command;
        ewf_result result_verify_response;

        if (internet_socket_ptr->type == ewf_adapter_quectel_common_internet_socket_service_type_udp_listener)
        {
            char remote_port_str[8];
            char const* remote_port_cstr = ewfl_unsigned_to_str(remote_port, remote_port_str, sizeof(remote_port_str));

            result_send_command = ewf_interface_send_commands(
                interface_ptr,
                "AT+QISEND=",
                connection_id_cstr, ",",
                buffer_length_cstr, ",",
                "\"", remote_address_str, "\",",
                remote_port_cstr, "\r",
                NULL);
        }
        else
        {
            result_send_command = ewf_interface_send_commands(
                interface_ptr,
                "AT+QISEND=",
                connection_id_cstr, ",",
                buffer_length_cstr, "\r",
                NULL);
        }

        if (ewf_result_succeeded(result_send_command))
        {
            result_verify_response = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_str);
        }

        if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, tokenizer_basic_command_response_pattern_saved_ptr))) return result;

        if (ewf_result_failed(result_send_command))
        {
            EWF_LOG_ERROR("Failed to send the QISEND command, connection ID [%s], length [%s].\n", connection_id_cstr, buffer_length_cstr);
            return result_send_command;
        }

        if (ewf_result_failed(result_verify_response))
        {
            _ewf_adapter_quectel_common_internet_log_last_error(adapter_ptr);
            return result_verify_response;
        }
    }

    {
        char tokenizer_pattern_str[] = "\r\nSEND OK\r\n";
        ewf_tokenizer_basic_pattern tokenizer_pattern = {
            NULL,
            tokenizer_pattern_str,
            sizeof(tokenizer_pattern_str) - 1,
            false,
        };

        ewf_result result_send;
        ewf_result result_verify_response;

        ewf_tokenizer_basic_data* tokenizer_data_ptr = (ewf_tokenizer_basic_data*)interface_ptr->tokenizer_ptr->data_ptr;

        ewf_tokenizer_basic_pattern* saved_tokenizer_pattern_ptr = NULL;
        result = ewf_tokenizer_basic_command_response_end_pattern_get(tokenizer_data_ptr, &saved_tokenizer_pattern_ptr);
        if (ewf_result_failed(result)) return result;

        result = ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_data_ptr, &tokenizer_pattern);
        if (ewf_result_failed(result)) return result;

        result_send = ewf_interface_send(interface_ptr, (const uint8_t*)buffer_ptr, buffer_length);
        if (ewf_result_succeeded(result_send))
        {
            result_verify_response = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_str);
        }

        /* Resotre the previously saved tokenizer pattern */
        if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_data_ptr, saved_tokenizer_pattern_ptr)))
        {
            return result;
        }

        if (ewf_result_failed(result_send))
        {
            _ewf_adapter_quectel_common_internet_log_last_error(adapter_ptr);
            return result_send;
        }

        if (ewf_result_failed(result_verify_response))
        {
            _ewf_adapter_quectel_common_internet_log_last_error(adapter_ptr);
            return result_verify_response;
        }
    }

#ifdef EWF_DEBUG
    EWF_LOG("_ewf_adapter_quectel_common_internet_socket_send - EXIT - BEGIN\n");
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QISEND=", connection_id_cstr, ",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QIRD=", connection_id_cstr, ",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    EWF_LOG("_ewf_adapter_quectel_common_internet_socket_send - EXIT - END\n");
#endif

    return EWF_RESULT_OK;
}

struct _ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function_state
{
    ewf_interface* interface_ptr;
    bool prefix_matches;
    bool parsed;
    uint32_t read_actual_length;
    uint32_t total_expected_length;
    uint8_t* data_ptr;
};

static bool _ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function(const uint8_t* buffer_ptr, uint32_t buffer_length, const ewf_tokenizer_basic_pattern* pattern_ptr, bool* stop_ptr)
{
    if (!buffer_ptr) return false;
    if (!buffer_length) return false;
    if (!pattern_ptr) return false;
    if (!stop_ptr) return false;

    struct _ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function_state* state_ptr =
        (struct _ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function_state*)pattern_ptr->data_ptr;

    /* Define the message prefix and calculate its length */
    const uint8_t prefix_str[] = "\r\n+QIRD: ";
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

    /* If the message parameters were not yet parsed */ 
    if (!state_ptr->parsed)
    {
        /* and we have a whole line, then parse it now */
        if (buffer_ptr[buffer_length - 2] == '\r' && buffer_ptr[buffer_length - 1] == '\n')
        {
            /* The message is complete, try to parse it */
            int count = sscanf((char*)buffer_ptr, "\r\n+QIRD: %lu", &state_ptr->read_actual_length);
            if (count != 1)
            {
                EWF_LOG_ERROR("Unexpected response format!\n");
                return false;
            }

            state_ptr->total_expected_length = buffer_length + state_ptr->read_actual_length + 2 + 6;
            state_ptr->data_ptr = (uint8_t*)buffer_ptr + buffer_length;

            state_ptr->parsed = true;
        }

        return false;
    }

    /* From this point we parsed data */

    /* Is the message complete? */
    if ((buffer_length) >= state_ptr->total_expected_length)
    {
        /* Signal the match */
        return true;
    }
    else
    {
        /* Not yet matched */
        return false;
    }
}

ewf_result _ewf_adapter_quectel_common_internet_socket_receive(
    ewf_adapter* adapter_ptr, 
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr, 
    char* remote_address_str, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr,
    uint8_t* buffer_ptr, uint32_t* buffer_length_ptr,
    bool wait)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    if (!internet_socket_ptr)
    {
        EWF_LOG_ERROR("The internet socket pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

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

    char connection_id_str[8];
    char* connection_id_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, connection_id_str, sizeof(connection_id_str));

    uint8_t* response_ptr = NULL;
    uint32_t response_length = 0;

    {
        uint32_t t = (wait) ? (t = interface_ptr->default_timeout) : 1;

        ewf_interface_poll(interface_ptr);

        /* Wait until data is received */
        for (; t; t--)
        {
            uint32_t total_receive_length = 0;
            uint32_t have_read_length = 0;
            uint32_t unread_length = 0;

            result = ewf_interface_send_commands(interface_ptr, "AT+QIRD=", connection_id_cstr, ",0\r", NULL);
            if (ewf_result_failed(result))
            {
                return result;
            }

            response_ptr = NULL;
            result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, -1);
            if (ewf_result_succeeded(result))
            {
                unread_length = 0;
                int count = sscanf((char*)response_ptr, "\r\n+QIRD: %lu,%lu,%lu\r\n\r\nOK\r\n", &total_receive_length, &have_read_length, &unread_length);
                if (count != 3)
                {
                    result = EWF_RESULT_UNEXPECTED_RESPONSE;
                }

                ewf_interface_release(interface_ptr, response_ptr);

                if (ewf_result_failed(result))
                {
                    EWF_LOG_ERROR("Unexpected response format, response [%s]!\n", (char*)response_ptr);
                    return result;
                }

                if (unread_length)
                {
                    break;
                }
            }

            ewf_interface_poll(interface_ptr);
            ewf_platform_sleep(1);
        }

        /* Did the operation timed-out? */
        if (!t)
        {
            if (wait) EWF_LOG_ERROR("Timeout while waiting for receive!\n");
            return EWF_RESULT_NO_DATA_RECEIVED;
        }
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QISEND=", connection_id_cstr, ",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QIRD=", connection_id_cstr, ",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    uint32_t response_overhead = 40; /* Conservative estimate */

    /* Read at most the buffer size, take into account the message overhead */
    uint32_t read_length = interface_ptr->message_allocator_ptr->block_size - response_overhead;
    read_length = (*buffer_length_ptr < read_length) ? *buffer_length_ptr : read_length;

    char read_length_str[8];
    char* read_length_cstr = ewfl_unsigned_to_str(read_length, read_length_str, sizeof(read_length_str));

    struct _ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function_state ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function_state = { 0 };
    ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function_state.interface_ptr = interface_ptr;

    {
        ewf_tokenizer_basic_pattern ewf_adapter_quectel_common_qird_message_tokenizer_pattern =
        {
            NULL,
            NULL,
            0,
            false,
            _ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function,
            &ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function_state
        };

        ewf_tokenizer_basic_data* tokenizer_data_ptr = (ewf_tokenizer_basic_data*)interface_ptr->tokenizer_ptr->data_ptr;

        ewf_tokenizer_basic_pattern* tokenizer_basic_message_pattern_saved_ptr = NULL;
        ewf_tokenizer_basic_pattern* tokenizer_basic_command_response_pattern_saved_ptr = NULL;
        ewf_tokenizer_basic_pattern* tokenizer_basic_command_response_end_pattern_saved_ptr = NULL;
        ewf_tokenizer_basic_pattern* tokenizer_basic_urc_pattern_saved_ptr = NULL;

        ewf_result ewf_result_send_command = EWF_RESULT_OK;
        ewf_result ewf_result_receive_response = EWF_RESULT_OK;

        if (ewf_result_failed(result = ewf_tokenizer_basic_message_pattern_get(tokenizer_data_ptr, &tokenizer_basic_message_pattern_saved_ptr))) return result;
        if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_pattern_get(tokenizer_data_ptr, &tokenizer_basic_command_response_pattern_saved_ptr))) return result;
        if (ewf_result_failed(result = ewf_tokenizer_basic_command_response_end_pattern_get(tokenizer_data_ptr, &tokenizer_basic_command_response_end_pattern_saved_ptr))) return result;
        if (ewf_result_failed(result = ewf_tokenizer_basic_urc_pattern_get(tokenizer_data_ptr, &tokenizer_basic_urc_pattern_saved_ptr))) return result;

        if (ewf_result_succeeded(result = ewf_tokenizer_basic_message_pattern_set(tokenizer_data_ptr, &ewf_adapter_quectel_common_qird_message_tokenizer_pattern)) &&
            ewf_result_succeeded(result = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, NULL)) &&
            ewf_result_succeeded(result = ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_data_ptr, NULL)) &&
            ewf_result_succeeded(result = ewf_tokenizer_basic_urc_pattern_set(tokenizer_data_ptr, NULL)))
        {
            ewf_result_send_command = ewf_interface_send_commands(
                interface_ptr,
                "AT+QIRD=",
                connection_id_cstr, ",",
                read_length_cstr, "\r",
                NULL);
            if (ewf_result_succeeded(ewf_result_send_command))
            {
                ewf_result_receive_response = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, interface_ptr->default_timeout);
            }
        }

        ewf_result result_restore_message_pattern = ewf_tokenizer_basic_message_pattern_set(tokenizer_data_ptr, tokenizer_basic_message_pattern_saved_ptr);
        ewf_result result_restore_command_response_pattern = ewf_tokenizer_basic_command_response_pattern_set(tokenizer_data_ptr, tokenizer_basic_command_response_pattern_saved_ptr);
        ewf_result result_restore_command_response_end_pattern  = ewf_tokenizer_basic_command_response_end_pattern_set(tokenizer_data_ptr, tokenizer_basic_command_response_end_pattern_saved_ptr);
        ewf_result result_restore_urc_pattern = ewf_tokenizer_basic_urc_pattern_set(tokenizer_data_ptr, tokenizer_basic_urc_pattern_saved_ptr);

        if (ewf_result_failed(result_restore_message_pattern)) return result_restore_message_pattern;
        if (ewf_result_failed(result_restore_command_response_pattern)) return result_restore_command_response_pattern;
        if (ewf_result_failed(result_restore_command_response_end_pattern)) return result_restore_command_response_end_pattern;
        if (ewf_result_failed(result_restore_urc_pattern)) return result_restore_urc_pattern;

        if (ewf_result_failed(ewf_result_send_command))
        {
            return ewf_result_send_command;
        }

        if (ewf_result_failed(ewf_result_receive_response))
        {
            return ewf_result_receive_response;
        }
    }

    /* Copy the buffer */
    memcpy(buffer_ptr, ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function_state.data_ptr, ewf_adapter_quectel_common_qird_message_tokenizer_pattern_match_function_state.read_actual_length);

    /* Release the buffer */
    ewf_interface_release(interface_ptr, response_ptr);

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QISEND=", connection_id_cstr, ",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QIRD=", connection_id_cstr, ",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return result;
}

/******************************************************************************
 *
 * TCP
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

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

    if (ewf_result_failed(result = _ewf_adapter_quectel_common_internet_socket_pool_allocate(adapter_ptr, &socket_id)))
    {
        EWF_LOG_ERROR("Too many open sockets.");
        return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
    }

    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = &(implementation_ptr->internet_socket_pool[socket_id]);

    socket_ptr->data_ptr = internet_socket_ptr;
    internet_socket_ptr->socket_ptr = socket_ptr;
    internet_socket_ptr->type = ewf_adapter_quectel_common_internet_socket_service_type_tcp;

    return result;
}

ewf_result ewf_adapter_quectel_common_tcp_close(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_quectel_common_internet_socket_close(adapter_ptr, internet_socket_ptr);
}

ewf_result ewf_adapter_quectel_common_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t local_port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    internet_socket_ptr->local_port = local_port;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_tcp_listen(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;
    
    internet_socket_ptr->type = ewf_adapter_quectel_common_internet_socket_service_type_tcp_listener;
    
    return _ewf_adapter_quectel_common_internet_socket_open(adapter_ptr, internet_socket_ptr, "TCP LISTENER", internet_socket_ptr->local_port, "127.0.0.1", 0 /* no remote port during service creation */);
}

ewf_result ewf_adapter_quectel_common_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_tcp_connect(ewf_socket_tcp* socket_ptr, const char* server_str, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_quectel_common_internet_socket_open(adapter_ptr, internet_socket_ptr, "TCP", 0 /* local port assigned automatically */, server_str, port);
}

ewf_result ewf_adapter_quectel_common_tcp_shutdown(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_quectel_common_internet_socket_send(
        adapter_ptr, 
        internet_socket_ptr,
        NULL, 0, /* Do not specify the remote address and port, they are given by the connection */
        buffer_ptr, buffer_length);
}

ewf_result ewf_adapter_quectel_common_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_quectel_common_internet_socket_receive(
        adapter_ptr,
        internet_socket_ptr,
        NULL, NULL, NULL, /* Do not specify the remote address and port buffers, they are given by the connection */
        buffer_ptr, buffer_length_ptr,
        wait);
}

/******************************************************************************
 *
 * UDP
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;
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

    if (ewf_result_failed(result = _ewf_adapter_quectel_common_internet_socket_pool_allocate(adapter_ptr, &socket_id)))
    {
        EWF_LOG_ERROR("Too many open sockets.");
        return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
    }

    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = &(implementation_ptr->internet_socket_pool[socket_id]);

    socket_ptr->data_ptr = internet_socket_ptr;
    internet_socket_ptr->socket_ptr = socket_ptr;
    internet_socket_ptr->type = ewf_adapter_quectel_common_internet_socket_service_type_udp;

    return result;
}

ewf_result ewf_adapter_quectel_common_udp_close(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;
    return _ewf_adapter_quectel_common_internet_socket_close(adapter_ptr, internet_socket_ptr);
}

ewf_result ewf_adapter_quectel_common_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_udp_bind(ewf_socket_udp* socket_ptr, uint32_t local_port)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    internet_socket_ptr->type = ewf_adapter_quectel_common_internet_socket_service_type_udp_listener;

    internet_socket_ptr->local_port = local_port;

    return _ewf_adapter_quectel_common_internet_socket_open(adapter_ptr, internet_socket_ptr, "UDP SERVICE", internet_socket_ptr->local_port, "127.0.0.1", 0 /* No remote port during service creation */);
}

ewf_result ewf_adapter_quectel_common_udp_shutdown(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_quectel_common_internet_socket_send(
        adapter_ptr,
        internet_socket_ptr,
        remote_address_str, remote_port,
        buffer_ptr, buffer_length);
}

ewf_result ewf_adapter_quectel_common_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address_str, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_quectel_common_internet_socket_receive(
        adapter_ptr,
        internet_socket_ptr,
        remote_address_str, remote_address_length_ptr, remote_port_ptr,
        buffer_ptr, buffer_length_ptr,
        wait);
}
