/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * brief The Embedded Wireless Framework Renesas RYZ014 Internet(TCP+UDP) implementation
 ****************************************************************************/

#include "ewf_adapter_renesas_ryz014.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

/******************************************************************************
 *
 * API
 *
 ******************************************************************************/

ewf_adapter_api_tcp ewf_adapter_renesas_ryz014_api_tcp =
{
    ewf_adapter_renesas_ryz014_tcp_open,
    ewf_adapter_renesas_ryz014_tcp_close,

    ewf_adapter_renesas_ryz014_tcp_control,

    ewf_adapter_renesas_ryz014_tcp_set_tls_configuration,

    ewf_adapter_renesas_ryz014_tcp_bind,
    ewf_adapter_renesas_ryz014_tcp_listen,
    ewf_adapter_renesas_ryz014_tcp_accept,
    ewf_adapter_renesas_ryz014_tcp_connect,
    ewf_adapter_renesas_ryz014_tcp_shutdown,
    ewf_adapter_renesas_ryz014_tcp_send,
    ewf_adapter_renesas_ryz014_tcp_receive,
};

ewf_adapter_api_udp ewf_adapter_renesas_ryz014_api_udp =
{
    ewf_adapter_renesas_ryz014_udp_open,
    ewf_adapter_renesas_ryz014_udp_close,

    ewf_adapter_renesas_ryz014_udp_control,

    ewf_adapter_renesas_ryz014_udp_set_dtls_configuration,

    ewf_adapter_renesas_ryz014_udp_bind,
    ewf_adapter_renesas_ryz014_udp_shutdown,
    ewf_adapter_renesas_ryz014_udp_send_to,
    ewf_adapter_renesas_ryz014_udp_receive_from,
};

/******************************************************************************
 *
 * Internal functions
 *
 ******************************************************************************/

 /**
  * @brief Get an available socket from the internal internet pool
  * @return an index to an available entry in the socket pool, or EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_INVALID if not available
  */
static ewf_result _ewf_adapter_renesas_ryz014_internet_socket_pool_allocate(ewf_adapter* adapter_ptr, uint32_t * socket_id_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    if (socket_id_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    *socket_id_ptr = EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_INVALID;

    for (int i = 0; i < EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE; ++i)
    {
        if (adapter_renesas_ryz014_ptr->internet_socket_pool[i].used == false)
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

ewf_result ewf_adapter_renesas_ryz014_internet_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    /* Initialize the internal data */
    uint32_t i;
    for (i = 0; i < EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE; ++i)
    {
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].socket_ptr = NULL;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].id = i+1; // connId starts from 1 for RYZ014
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].local_port = 0;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].type = ewf_adapter_renesas_ryz014_socket_service_type_not_initialized;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].used = false;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].conn = false;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].conn_error = false;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].recv = false;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_internet_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);

    return EWF_RESULT_OK;
}


/******************************************************************************
 *
 * Internet URC handler
 *
 ******************************************************************************/
ewf_result ewf_adapter_renesas_ryz014_internet_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;

    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    EWF_PARAMETER_NOT_USED(buffer_length);

    if (ewfl_str_starts_with((char*)buffer_ptr, "CONNECT: "))
    {
        return EWF_RESULT_OK;
    }

    if (ewfl_str_starts_with((char*)buffer_ptr, "+CME ERROR: 171"))
    {
        return EWF_RESULT_OK;
    }

    const char urc_prefix_str[] = "+SQNS";
    if (ewfl_str_starts_with((char*)buffer_ptr, urc_prefix_str))
    {
        char* urc_str = (char*) buffer_ptr + ewfl_str_length(urc_prefix_str);
        {
            const char match_str[] = "RING: ";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                char* parse_str = urc_str + ewfl_str_length(match_str);
                uint32_t socket_connect_id = atoi(parse_str);
                if(!(socket_connect_id)|| (EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE < socket_connect_id))
                {
                    EWF_LOG("\nURC: unexpected format.\n");
                    return EWF_RESULT_OK;
                }
                else
                {
                    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = &(adapter_renesas_ryz014_ptr->internet_socket_pool[socket_connect_id - 1]);
                    if (internet_socket_ptr->socket_ptr)
                    {
                        switch (internet_socket_ptr->type)
                        {
                        case ewf_adapter_renesas_ryz014_socket_service_type_tcp_listener:
                        {
                            internet_socket_ptr->recv = true;
                            internet_socket_ptr->conn = true;
                            internet_socket_ptr->conn_error = false;
                        }
                        // fall through
                        // no break
                        case ewf_adapter_renesas_ryz014_socket_service_type_tcp:
                        {
                            ewf_socket_tcp* socket_ptr = (ewf_socket_tcp*)internet_socket_ptr->socket_ptr;
                            if (socket_ptr->receive_callback)
                            {
                                /* TODO */
                            }
                        }
                        break;
                        case ewf_adapter_renesas_ryz014_socket_service_type_udp_listener:
                        {
                            internet_socket_ptr->recv = true;
                            internet_socket_ptr->conn = true;
                            internet_socket_ptr->conn_error = false;
                        }
                        // fall through
                        // no break
                        case ewf_adapter_renesas_ryz014_socket_service_type_udp:
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
        }
        {
            const char match_str[] = "H:";
            if (ewfl_str_starts_with(urc_str, match_str))
            {
                char* parse_str = urc_str + ewfl_str_length(match_str);
                uint32_t socket_connect_id = atoi(parse_str);
                adapter_renesas_ryz014_ptr->internet_socket_pool[socket_connect_id - 1].conn_error = true;
                return EWF_RESULT_OK;
            }
        }
    }
    return EWF_RESULT_UNHANDLED_URC;

}

/******************************************************************************
 *
 * Common TCP and UDP
 *
 ******************************************************************************/

static ewf_result _ewf_adapter_renesas_ryz014_internet_socket_open(ewf_adapter* adapter_ptr, ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr, int service_type, uint32_t udp_local_port, char const* server_str, uint32_t remote_port, uint32_t accept_any_remote)
{
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    ewf_result result;

    if ((service_type < 0) || (service_type > 1))
    {
        EWF_LOG_ERROR("The service type value incorrect, 0-TCP, 1-UDP\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!server_str)
    {
        EWF_LOG_ERROR("The server string cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    char connection_id_str[3];
    const char* connection_id_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, connection_id_str, sizeof(connection_id_str));

    char service_type_str[3];
    const char* service_type_cstr = ewfl_unsigned_to_str(service_type, service_type_str, sizeof(service_type_str));

    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(interface_ptr->current_context, context_id_str, sizeof(context_id_str));

    char accept_any_remote_str[3];
    const char* accept_any_remote_cstr = ewfl_unsigned_to_str(accept_any_remote, accept_any_remote_str, sizeof(accept_any_remote_str));

    // Close outstanding connections just in case
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSH=", connection_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    char remote_port_str[8];
    const char* remote_port_cstr = ewfl_unsigned_to_str(remote_port, remote_port_str, sizeof(remote_port_str));

    if(!udp_local_port) udp_local_port = 0;
    char udp_local_port_str[8];
    const char* udp_local_port_cstr = ewfl_unsigned_to_str(udp_local_port, udp_local_port_str, sizeof(udp_local_port_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSCFG=", connection_id_cstr, ",", context_id_cstr,", 0, 0, 600, 50\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSCFGEXT=", connection_id_cstr, ",0,0,0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr,
            "AT+SQNSD=",
            connection_id_cstr, ",",
            service_type_cstr, ",",
            remote_port_cstr, ",",
            "\"",server_str,"\",",
            "0,",udp_local_port_cstr,",1,",
            accept_any_remote_cstr,
            "\r",
            NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].conn = true;
    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].conn_error = false;

    return EWF_RESULT_OK;
}

static ewf_result _ewf_adapter_renesas_ryz014_internet_socket_close(ewf_adapter* adapter_ptr, ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr)
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

    char socket_str[3];
    const char* socket_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSH=", socket_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    internet_socket_ptr->used = false;
    internet_socket_ptr->conn = false;
    internet_socket_ptr->conn_error = false;

    return EWF_RESULT_OK;
}

static ewf_result _ewf_adapter_renesas_ryz014_internet_socket_send(ewf_adapter* adapter_ptr, ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    if (!internet_socket_ptr)
    {
        EWF_LOG_ERROR("The Internet socket pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (internet_socket_ptr->type == ewf_adapter_renesas_ryz014_socket_service_type_udp ||
        internet_socket_ptr->type == ewf_adapter_renesas_ryz014_socket_service_type_udp_listener)
    {
        if (remote_address_str == NULL || remote_port == 0)
        {
            EWF_LOG_ERROR("The remote address and port need to be specified for a UDP SERVER send.");
            return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
        }
    }
    else if (internet_socket_ptr->type == ewf_adapter_renesas_ryz014_socket_service_type_tcp ||
             internet_socket_ptr->type == ewf_adapter_renesas_ryz014_socket_service_type_tcp_listener)
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
        if ((internet_socket_ptr->type == ewf_adapter_renesas_ryz014_socket_service_type_udp)||(internet_socket_ptr->type == ewf_adapter_renesas_ryz014_socket_service_type_udp_listener))
        {
            result = _ewf_adapter_renesas_ryz014_internet_socket_open(adapter_ptr, internet_socket_ptr, EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_UDP, internet_socket_ptr->local_port, remote_address_str, remote_port, 0);
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

    /* Limit the send size as SQNSSEND command only supports maximum upto 1500 */
    buffer_length = (buffer_length > EWF_ADAPTER_RENESAS_RYZ014_SOCKET_MAX_SEND_SIZE) ? EWF_ADAPTER_RENESAS_RYZ014_SOCKET_MAX_SEND_SIZE : buffer_length;

    char buffer_length_str[8];
    char const* buffer_length_cstr = ewfl_unsigned_to_str(buffer_length, buffer_length_str, sizeof(buffer_length_str));

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSI=", connection_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    {
        char tokenizer_pattern1_str[] = "\r\n> ";
        ewf_interface_tokenizer_pattern tokenizer_pattern1 = {
            NULL,
            tokenizer_pattern1_str,
            sizeof(tokenizer_pattern1_str) - 1,
            false,
            NULL,
            NULL,
        };

        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern1))) return result;

        ewf_result result_send_command;
        ewf_result result_verify_response;

        result_send_command = ewf_interface_send_commands(
                interface_ptr,
                "AT+SQNSSENDEXT=",
                connection_id_cstr, ",",
                buffer_length_cstr, "\r",
                NULL);

        if (ewf_result_succeeded(result_send_command))
        {
            result_verify_response = ewf_interface_verify_response(interface_ptr, tokenizer_pattern1_str);
        }

        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;

        if (ewf_result_failed(result_send_command))
        {
            EWF_LOG_ERROR("Failed to send the Socket SEND/SENDEXT command, connection ID [%s], length [%s].\n", connection_id_cstr, buffer_length_cstr);
            return result_send_command;
        }
        if (ewf_result_failed(result_verify_response))
        {
            return result_verify_response;
        }
    }

    {
        char tokenizer_pattern2_str[] = "\r\nOK\r\n";
        ewf_interface_tokenizer_pattern tokenizer_pattern2 = {
            NULL,
            tokenizer_pattern2_str,
            sizeof(tokenizer_pattern2_str) - 1,
            false,
            NULL,
            NULL,
        };

        ewf_result result_send = EWF_RESULT_OK;
        ewf_result result_verify_response = EWF_RESULT_OK;

        ewf_interface_tokenizer_pattern* saved_tokenizer_pattern_ptr = NULL;
        result = ewf_interface_tokenizer_command_response_end_pattern_get(interface_ptr, &saved_tokenizer_pattern_ptr);
        if (ewf_result_failed(result)) return result;

        result = ewf_interface_tokenizer_command_response_end_pattern_set(interface_ptr, &tokenizer_pattern2);
        if (ewf_result_failed(result)) return result;

        result_send = ewf_interface_send(interface_ptr, (const uint8_t*)buffer_ptr, buffer_length);

        if (ewf_result_succeeded(result_send))
        {
            result_verify_response = ewf_interface_verify_response(interface_ptr, tokenizer_pattern2_str);
        }

        /* Restore the previously saved tokenizer pattern */
        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_end_pattern_set(interface_ptr, saved_tokenizer_pattern_ptr)))
        {
            return result;
        }

        if (ewf_result_failed(result_send))
        {
            return result_send;
        }

        if (ewf_result_failed(result_verify_response))
        {
            return result_verify_response;
        }
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSI=", connection_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

static ewf_result _ewf_adapter_renesas_ryz014_internet_socket_receive(
    ewf_adapter* adapter_ptr,
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr,
    char* remote_address_str, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr,
    uint8_t* buffer_ptr, uint32_t* buffer_length_ptr,
    bool wait)
{
    EWF_PARAMETER_NOT_USED(remote_address_str);
    EWF_PARAMETER_NOT_USED(remote_address_length_ptr);
    EWF_PARAMETER_NOT_USED(remote_port_ptr);

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
        uint32_t t = (wait) ? (t = (60 * EWF_PLATFORM_TICKS_PER_SECOND)) : 1;

        ewf_interface_poll(interface_ptr);

        /* Wait until data is received */
        for (; t; t--)
        {
            uint32_t socket_id = 0;
            uint32_t total_sent_length = 0;
            uint32_t total_receive_length = 0;
            uint32_t unread_length = 0;
            uint32_t total_sent_not_acknowledged = 0;

            if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSI=", connection_id_cstr, "\r", NULL))) return result;

            result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 100);
            if (ewf_result_succeeded(result))
            {
                const char match_str[] = "\r\n+SQNSI: ";
                if (ewfl_str_starts_with((char*)response_ptr, match_str))
                {
                    char* parse_str = (char*)(response_ptr + ewfl_str_length(match_str));
                    socket_id = ewfl_str_to_unsigned(parse_str);
                    while (*parse_str && isdigit((unsigned char)*parse_str)) parse_str++;
                    parse_str++; /* Skip ',' */
                    total_sent_length = ewfl_str_to_unsigned(parse_str);
                    while (*parse_str && isdigit((unsigned char)*parse_str)) parse_str++;
                    parse_str++; /* Skip ',' */
                    total_receive_length = ewfl_str_to_unsigned(parse_str);
                    while (*parse_str && isdigit((unsigned char)*parse_str)) parse_str++;
                    parse_str++; /* Skip ',' */
                    unread_length = ewfl_str_to_unsigned(parse_str);
                    while (*parse_str && isdigit((unsigned char)*parse_str)) parse_str++;
                    parse_str++; /* Skip ',' */
                    total_sent_not_acknowledged = ewfl_str_to_unsigned(parse_str);

                }
            }

            EWF_PARAMETER_NOT_USED(socket_id);
            EWF_PARAMETER_NOT_USED(total_sent_length);
            EWF_PARAMETER_NOT_USED(total_receive_length);
            EWF_PARAMETER_NOT_USED(total_sent_not_acknowledged);

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

            ewf_interface_poll(interface_ptr);
            ewf_platform_sleep(1);
        }

        /* Did the operation timed-out? */
        if (!t)
        {
            if (wait)
            {
                EWF_LOG_ERROR("Timeout while waiting for receive!\n");
            }
            return EWF_RESULT_NO_DATA_RECEIVED;
        }
    }

    uint32_t response_overhead = 40; /* Conservative estimate */

    /* Read at most the buffer size, take into account the message overhead */
    uint32_t read_length = interface_ptr->message_allocator_ptr->block_size - response_overhead;
    read_length = (*buffer_length_ptr < read_length) ? *buffer_length_ptr : read_length;
    read_length = (read_length < EWF_ADAPTER_RENESAS_RYZ014_SOCKET_MAX_RECEIVE_SIZE) ? (read_length) : (EWF_ADAPTER_RENESAS_RYZ014_SOCKET_MAX_RECEIVE_SIZE);

    char read_length_str[8];
    char* read_length_cstr = ewfl_unsigned_to_str(read_length, read_length_str, sizeof(read_length_str));

    result = ewf_interface_send_commands(
        interface_ptr,
        "AT+SQNSRECV=",
        connection_id_cstr, ",",
        read_length_cstr, "\r",
        NULL);
    if (ewf_result_failed(result)) return result;

    result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 500);
    if (ewf_result_failed(result)) return result;

    /* Terminate the string to make parsing safer and faster */
    response_ptr[response_length] = 0;

    /* Parse the response */
    {
        char data_read_response_str[] = "\r\n+SQNSRECV: ";
        uint32_t read_actual_length = 0;

        char* read_actual_length_str = NULL;

        char* p = NULL;

        if (!ewfl_buffer_equals_buffer((char* )response_ptr, data_read_response_str, sizeof(data_read_response_str) - 1))
        {
            result = EWF_RESULT_UNEXPECTED_RESPONSE;
        }
        else
        {
            p = (char *) (response_ptr + (sizeof(data_read_response_str) - 1) + 2) /* skip characters until actual receive length */;
            read_actual_length_str = p;
            read_actual_length = ewfl_str_to_unsigned(read_actual_length_str);
        }

        if (ewf_result_succeeded(result))
        {
            p = ewfl_find_chars_with_terms(p, "\r", NULL);
            if (!p) result = EWF_RESULT_UNEXPECTED_RESPONSE;
            else
            {
                *p = 0; p++;
                if (*p != '\n') result = EWF_RESULT_UNEXPECTED_RESPONSE;
                else { p++; }
            }
        }

        if (ewf_result_succeeded(result))
        {
            *buffer_length_ptr = (*buffer_length_ptr >= read_actual_length) ? read_actual_length : *buffer_length_ptr;
            memcpy(buffer_ptr, p, *buffer_length_ptr);
        }
    }

    ewf_interface_release(interface_ptr, response_ptr);

    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Unexpected response format, response [%s]!\n", (char*)response_ptr);
        return result;
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSI=", connection_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return result;
}

/******************************************************************************
 *
 * TCP
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_ryz014_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

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

    if (ewf_result_failed(result = _ewf_adapter_renesas_ryz014_internet_socket_pool_allocate(adapter_ptr, &socket_id)))
    {
        EWF_LOG_ERROR("Too many open sockets.");
        return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
    }

    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = &(adapter_renesas_ryz014_ptr->internet_socket_pool[socket_id]);

    socket_ptr->data_ptr = internet_socket_ptr;
    internet_socket_ptr->socket_ptr = socket_ptr;
    internet_socket_ptr->type = ewf_adapter_renesas_ryz014_socket_service_type_tcp;
    internet_socket_ptr->used = true;

    return result;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_close(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;
    return _ewf_adapter_renesas_ryz014_internet_socket_close(adapter_ptr, internet_socket_ptr);
}

ewf_result ewf_adapter_renesas_ryz014_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    EWF_PARAMETER_NOT_USED(control_str);
    EWF_PARAMETER_NOT_USED(buffer_ptr);
    EWF_PARAMETER_NOT_USED(buffer_length_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    EWF_PARAMETER_NOT_USED(tls_configuration_id);
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t local_port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;
    internet_socket_ptr->local_port = local_port;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_listen(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

    internet_socket_ptr->type = ewf_adapter_renesas_ryz014_socket_service_type_tcp_listener;

    ewf_result result = EWF_RESULT_OK;

    char socket_str[3];
    const char* socket_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));
    char port_str[7];
    const char* port_cstr = ewfl_unsigned_to_str(internet_socket_ptr->local_port, port_str, sizeof(port_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSL=", socket_cstr, ",",EWF_ADAPTER_RENESAS_RYZ014_SOCKET_COMMAND_MODE,",", port_cstr, "\r", NULL)))
        return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n")))
        return result;

    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].used = true;
    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].open_error = false;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_accept(ewf_socket_tcp* socket_ptr,  ewf_socket_tcp* socket_new_ptr)
{

    EWF_PARAMETER_NOT_USED(socket_new_ptr);
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if ((internet_socket_ptr->id << 0) || (EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE <= internet_socket_ptr->id))
    {
        EWF_LOG_ERROR("Invalid socket value.");
        return EWF_RESULT_INVALID_SOCKET;
    }

    if (true)
    {
        /* Wait until data is received */
        for (;;)
        {
            if (adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].recv)
            {
                adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].recv = false;
                break;
            }
            ewf_interface_poll(interface_ptr);
            ewf_platform_sleep(1);
        }
    }
    else
    {
        ewf_interface_poll(interface_ptr);
        if (adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].recv == false)
        {
            return EWF_RESULT_CONNECTION_FAILED;
        }
    }

    char socket_str[3];
    const char* socket_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));
    char connect_mode_str[7];
    /* Connection mode set to Command Mode */
    const char* connect_mode_cstr = ewfl_unsigned_to_str(1, connect_mode_str, sizeof(connect_mode_str));
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSA=", socket_cstr, ",", connect_mode_cstr, "\r", NULL)))
        return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n")))
        return result;

    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].conn = true;
    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].conn_error = false;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_connect(ewf_socket_tcp * socket_ptr, const char* const server_str, uint32_t remote_port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;
    return _ewf_adapter_renesas_ryz014_internet_socket_open(adapter_ptr, internet_socket_ptr,
                                                            EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_TCP,
                                                            8000/* local port option, no effect for TCP connections */,
                                                            server_str, remote_port, 0);
}


ewf_result ewf_adapter_renesas_ryz014_tcp_shutdown(ewf_socket_tcp* socket_ptr)
{
    EWF_PARAMETER_NOT_USED(socket_ptr);
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

    /* Check if socket was closed by remote host */
    if (internet_socket_ptr->conn_error == true)
    {
        _ewf_adapter_renesas_ryz014_internet_socket_close(adapter_ptr, internet_socket_ptr);
        EWF_LOG_ERROR("Socket is closed by remote.");
        return EWF_RESULT_CONNECTION_FAILED;

    }
    return _ewf_adapter_renesas_ryz014_internet_socket_send(adapter_ptr, internet_socket_ptr,
                                                            NULL, 0, /* Do not specify the remote address and port, they are given by the connection */
                                                            buffer_ptr, buffer_length);

}

ewf_result ewf_adapter_renesas_ryz014_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_renesas_ryz014_internet_socket_receive(
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

ewf_result ewf_adapter_renesas_ryz014_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

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

    if (ewf_result_failed(result = _ewf_adapter_renesas_ryz014_internet_socket_pool_allocate(adapter_ptr, &socket_id)))
    {
        EWF_LOG_ERROR("Too many open sockets.");
        return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
    }

    socket_ptr->data_ptr = &(adapter_renesas_ryz014_ptr->internet_socket_pool[socket_id]);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = &(adapter_renesas_ryz014_ptr->internet_socket_pool[socket_id]);

    socket_ptr->data_ptr = internet_socket_ptr;
    internet_socket_ptr->socket_ptr = socket_ptr;
    internet_socket_ptr->type = ewf_adapter_renesas_ryz014_socket_service_type_udp;
    internet_socket_ptr->used = true;

    return result;
}


ewf_result ewf_adapter_renesas_ryz014_udp_close(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_renesas_ryz014_internet_socket_close(adapter_ptr, internet_socket_ptr);
}

ewf_result ewf_adapter_renesas_ryz014_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    EWF_PARAMETER_NOT_USED(control_str);
    EWF_PARAMETER_NOT_USED(buffer_ptr);
    EWF_PARAMETER_NOT_USED(buffer_length_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    EWF_PARAMETER_NOT_USED(tls_configuration_id);
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_udp_bind(ewf_socket_udp* socket_ptr, uint32_t local_port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    if (internet_socket_ptr->used == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    internet_socket_ptr->type = ewf_adapter_renesas_ryz014_socket_service_type_udp_listener;
    internet_socket_ptr->local_port = local_port;
    internet_socket_ptr->conn =false;
    internet_socket_ptr->conn_error = false;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_udp_shutdown(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_renesas_ryz014_internet_socket_send(
        adapter_ptr,
        internet_socket_ptr,
        remote_address_str, remote_port,
        buffer_ptr, buffer_length);
}

ewf_result ewf_adapter_renesas_ryz014_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address_str, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_PARAMETER_NOT_USED(remote_address_str);
    EWF_PARAMETER_NOT_USED(remote_address_length_ptr);
    EWF_PARAMETER_NOT_USED(remote_port_ptr);

    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_renesas_ryz014_internet_socket_receive(
        adapter_ptr,
        internet_socket_ptr,
        remote_address_str, remote_address_length_ptr, remote_port_ptr,
        (uint8_t *)buffer_ptr, buffer_length_ptr,
        wait);
}
