/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel common internet(TCP+UDP) implementation
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

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
    ewf_adapter_quectel_common* adapter_quectel_common_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

    if (socket_id_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    *socket_id_ptr = EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_INVALID;

    for (int i = 0; i < EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_POOL_SIZE; ++i)
    {
        if (adapter_quectel_common_ptr->internet_socket_pool[i].used == false)
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
    ewf_adapter_quectel_common* implementation_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

    uint32_t i;
    for (i = 0; i < EWF_ADAPTER_QUECTEL_COMMON_INTERNET_SOCKET_POOL_SIZE; ++i)
    {
        implementation_ptr->internet_socket_pool[i].id = i;
        implementation_ptr->internet_socket_pool[i].type = ewf_adapter_quectel_common_internet_socket_service_type_not_initialized;
        implementation_ptr->internet_socket_pool[i].port = 0;
        implementation_ptr->internet_socket_pool[i].used = false;
        implementation_ptr->internet_socket_pool[i].open = false;
        implementation_ptr->internet_socket_pool[i].open_error = false;
        implementation_ptr->internet_socket_pool[i].conn = false;
        implementation_ptr->internet_socket_pool[i].conn_error = false;
        implementation_ptr->internet_socket_pool[i].recv = false;
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
    ewf_adapter_quectel_common* adapter_quectel_common_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

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
            if (err)
            {
                adapter_quectel_common_ptr->internet_socket_pool[connectionID].used = false;
                adapter_quectel_common_ptr->internet_socket_pool[connectionID].conn = false;
                adapter_quectel_common_ptr->internet_socket_pool[connectionID].conn_error = true;
            }
            else
            {
                adapter_quectel_common_ptr->internet_socket_pool[connectionID].used = true;
                adapter_quectel_common_ptr->internet_socket_pool[connectionID].conn = true;
                adapter_quectel_common_ptr->internet_socket_pool[connectionID].conn_error = false;
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
            adapter_quectel_common_ptr->internet_socket_pool[connectionID].open = false;
            adapter_quectel_common_ptr->internet_socket_pool[connectionID].open_error = false;
            adapter_quectel_common_ptr->internet_socket_pool[connectionID].conn = false;
            adapter_quectel_common_ptr->internet_socket_pool[connectionID].conn_error = false;
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
            adapter_quectel_common_ptr->internet_socket_pool[connectionID].recv = true;
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

ewf_result _ewf_adapter_quectel_common_internet_socket_open(ewf_adapter* adapter_ptr, ewf_adapter_quectel_common_internet_socket* internet_socket_ptr, char const* service_type, char const* server, uint32_t port)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (!service_type)
    {
        EWF_LOG_ERROR("The service type string cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!server)
    {
        EWF_LOG_ERROR("The server string cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    char socket_str[3];
    const char* socket_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));

#ifdef EWF_DEBUG
    /* Close outstanding connections just in case */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QICLOSE=", socket_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    char port_str[7];
    const char* port_cstr = ewfl_unsigned_to_str(port, port_str, sizeof(port_str));

    /* Open a connection */
    if (ewf_result_failed(result = ewf_interface_send_commands(
        interface_ptr,
        "AT+QIOPEN=1,",
        socket_cstr, ",",
        "\"", service_type, "\",",
        "\"", server, "\",",
        port_cstr, ",0,0\r",
        NULL)))
        return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Wait until the connection is established */
    uint32_t timeout = 150 * EWF_PLATFORM_TICKS_PER_SECOND;
    while (--timeout)
    {
        if (internet_socket_ptr->conn)
        {
            break;
        }
        if (internet_socket_ptr->conn_error)
        {
            EWF_LOG("\nFailed to connect to the server: [%s]\n", server);
            return EWF_RESULT_CONNECTION_FAILED;
        }
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }
    if (!timeout)
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QICLOSE=", socket_cstr, "\r", NULL))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
        return EWF_RESULT_CONNECTION_FAILED;
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QISTATE=1,", socket_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result _ewf_adapter_quectel_common_internet_socket_close(ewf_adapter* adapter_ptr, ewf_adapter_quectel_common_internet_socket* internet_socket_ptr)
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

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QICLOSE=", socket_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * TCP
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_quectel_common* adapter_quectel_common_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;

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

    socket_ptr->data_ptr = &(adapter_quectel_common_ptr->internet_socket_pool[socket_id]);

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

ewf_result ewf_adapter_quectel_common_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;
    internet_socket_ptr->port = port;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_tcp_listen(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;
    return _ewf_adapter_quectel_common_internet_socket_open(adapter_ptr, internet_socket_ptr, "TCP LISTENER", "127.0.0.1", internet_socket_ptr->port);
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
    return _ewf_adapter_quectel_common_internet_socket_open(adapter_ptr, internet_socket_ptr, "TCP", server_str, port);
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
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    ewf_result result;

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
        char tokenizer_pattern1_str[] = "\r\n> ";
        ewf_interface_tokenizer_pattern tokenizer_pattern1 = {
            NULL,
            tokenizer_pattern1_str,
            sizeof(tokenizer_pattern1_str) - 1,
            false,
        };

        char tokenizer_pattern2_str[] = "\r\nSEND OK\r\n";
        ewf_interface_tokenizer_pattern tokenizer_pattern2 = {
            NULL,
            tokenizer_pattern2_str,
            sizeof(tokenizer_pattern2_str) - 1,
            false,
        };

        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern1))) return result;

        char socket_str[3];
        char len_str[5];
        if (ewf_result_failed(result = ewf_interface_send_commands(
            interface_ptr,
            "AT+QISEND=",
            ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str)), ",",
            ewfl_unsigned_to_str(buffer_length, len_str, sizeof(len_str)), "\r",
            NULL))) return result;
        if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern1_str))) return result;

        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern2))) return result;
        if (ewf_result_failed(result = ewf_interface_send(interface_ptr, (const uint8_t*)buffer_ptr, buffer_length))) return result;
        if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern2_str))) return result;

        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QISEND=0,0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    ewf_result result;

    uint8_t* response_ptr;
    uint32_t response_length;

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
            if (internet_socket_ptr->recv)
            {
                internet_socket_ptr->recv = false;
                break;
            }
            ewf_interface_poll(interface_ptr);
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

    uint32_t response_overhead = 32; /* Conservative estimate */

    /* Read at most the buffer size, take into account the message overhead */
    uint32_t read_length = interface_ptr->message_allocator_ptr->block_size - response_overhead;
    read_length = (*buffer_length_ptr < read_length) ? *buffer_length_ptr : read_length;

    char socket_str[3];
    char* socket_cstr = ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));

    char read_length_str[5];
    char* read_length_cstr = ewfl_unsigned_to_str(read_length, read_length_str, sizeof(read_length_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(
        interface_ptr,
        "AT+QIRD=",
        socket_cstr, ",",
        read_length_cstr, "\r",
        NULL)))
        return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 30))) return result;

    if (response_length < response_overhead)
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    if (ewfl_str_starts_with((char*)response_ptr, "\r\nERROR"))
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    const char data_read_response_str[] = "\r\n+QIRD: ";
    if (!ewfl_str_starts_with((char*)response_ptr, data_read_response_str))
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }
    else
    {
        uint32_t read_actual_length;
        char* p;
        p = (char*)response_ptr;
        p += sizeof(data_read_response_str) - 1;
        read_actual_length = ewfl_str_to_unsigned(p);
        if (read_actual_length == 0)
        {
            *buffer_length_ptr = 0;
        }
        else
        {
            while (*p && isdigit((int)*p)) p++; // skip the read_actual_length value;
            if (response_length != ((p - (char*)response_ptr) + 2 + read_actual_length + 8)
                || *(p + 0) != '\r'
                || *(p + 1) != '\n'
                || *(p + 2 + read_actual_length + 0) != '\r'
                || *(p + 2 + read_actual_length + 1) != '\n'
                || *(p + 2 + read_actual_length + 2) != '\r'
                || *(p + 2 + read_actual_length + 3) != '\n'
                || *(p + 2 + read_actual_length + 4) != 'O'
                || *(p + 2 + read_actual_length + 5) != 'K'
                || *(p + 2 + read_actual_length + 6) != '\r'
                || *(p + 2 + read_actual_length + 7) != '\n'
                )
            {
                // Unexpected format
            }
            else
            {
                *buffer_length_ptr = (*buffer_length_ptr >= read_actual_length) ? read_actual_length : *buffer_length_ptr;
                memcpy(buffer_ptr, p + 2, *buffer_length_ptr);
            }
        }
        ewf_interface_release(interface_ptr, response_ptr);
    }

    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * UDP
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common* adapter_quectel_common_ptr = (ewf_adapter_quectel_common*)adapter_ptr->implementation_ptr;
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

    socket_ptr->data_ptr = &(adapter_quectel_common_ptr->internet_socket_pool[socket_id]);

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

ewf_result ewf_adapter_quectel_common_udp_bind(ewf_socket_udp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;
    return _ewf_adapter_quectel_common_internet_socket_open(adapter_ptr, internet_socket_ptr, "UDP SERVICE", "127.0.0.1", port);
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
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    ewf_result result;

    if (!remote_address_str)
    {
        EWF_LOG_ERROR("The remote address string pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
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
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    {
        char tokenizer_pattern1_str[] = "\r\n> ";
        ewf_interface_tokenizer_pattern tokenizer_pattern1 = {
            NULL,
            tokenizer_pattern1_str,
            sizeof(tokenizer_pattern1_str) - 1,
            false,
        };

        char tokenizer_pattern2_str[] = "\r\nSEND OK\r\n";
        ewf_interface_tokenizer_pattern tokenizer_pattern2 = {
            NULL,
            tokenizer_pattern2_str,
            sizeof(tokenizer_pattern2_str) - 1,
            false,
        };

        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern1))) return result;

        char socket_id_str[3];
        char buffer_length_str[5];
        char remote_port_str[6];
        if (ewf_result_failed(result = ewf_interface_send_commands(
            interface_ptr,
            "AT+QISEND=",
            ewfl_unsigned_to_str(internet_socket_ptr->id, socket_id_str, sizeof(socket_id_str)), ",",
            ewfl_unsigned_to_str(buffer_length, buffer_length_str, sizeof(buffer_length_str)), ",",
            "\"", remote_address_str,"\",",
            ewfl_unsigned_to_str(remote_port, remote_port_str, sizeof(remote_port_str)), ",",
            "\r",
            NULL))) return result;
        if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern1_str))) return result;

        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern2))) return result;
        if (ewf_result_failed(result = ewf_interface_send(interface_ptr, (const uint8_t*)buffer_ptr, buffer_length))) return result;
        if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern2_str))) return result;

        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QISEND=0,0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address_str, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_quectel_common_internet_socket* internet_socket_ptr = (ewf_adapter_quectel_common_internet_socket*)socket_ptr->data_ptr;

    ewf_result result;

    uint8_t* response_ptr;
    uint32_t response_length;

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
            if (internet_socket_ptr->recv)
            {
                internet_socket_ptr->recv = false;
                break;
            }
            ewf_interface_poll(interface_ptr);
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

    char socket_str[3];
    char length_str[5];
    uint32_t length = (*buffer_length_ptr > 1500) ? (1500) : (*buffer_length_ptr);

    if (ewf_result_failed(result = ewf_interface_send_commands(
        interface_ptr,
        "AT+QIRD=",
        ewfl_unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str)), ",",
        ewfl_unsigned_to_str(length, length_str, sizeof(length_str)), "\r",
        NULL)))
        return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, &response_ptr, &response_length, 30))) return result;

    if (response_length < 7)
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    if (ewfl_str_starts_with((char*)response_ptr, "\r\nERROR"))
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    const char data_read_response_str[] = "\r\n+QIRD: ";
    if (!ewfl_str_starts_with((char*)response_ptr, data_read_response_str))
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }
    else
    {
        uint32_t read_actual_length;
        char* p;
        p = (char*)response_ptr;
        p += sizeof(data_read_response_str) - 1;
        read_actual_length = ewfl_str_to_unsigned(p);
        if (read_actual_length == 0)
        {
            *buffer_length_ptr = 0;
        }
        else
        {
            while (*p && isdigit((int)*p)) p++; // skip the read_actual_length value;
            if (response_length != ((p - (char*)response_ptr) + 2 + read_actual_length + 8)
                || *(p + 0) != '\r'
                || *(p + 1) != '\n'
                || *(p + 2 + read_actual_length + 0) != '\r'
                || *(p + 2 + read_actual_length + 1) != '\n'
                || *(p + 2 + read_actual_length + 2) != '\r'
                || *(p + 2 + read_actual_length + 3) != '\n'
                || *(p + 2 + read_actual_length + 4) != 'O'
                || *(p + 2 + read_actual_length + 5) != 'K'
                || *(p + 2 + read_actual_length + 6) != '\r'
                || *(p + 2 + read_actual_length + 7) != '\n'
                )
            {
                // Unexpected format
            }
            else
            {
                *buffer_length_ptr = (*buffer_length_ptr >= read_actual_length) ? read_actual_length : *buffer_length_ptr;
                memcpy(buffer_ptr, p + 2, *buffer_length_ptr);
            }
        }
        ewf_interface_release(interface_ptr, response_ptr);
    }

    return EWF_RESULT_OK;
}
