/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework Renesas RYZ014 Internet(TCP+UDP) implementation
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

    uint32_t i;
    for (i = 0; i < EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE; ++i)
    {
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].id = i+1; // connId starts from 1
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].type = ewf_adapter_renesas_ryz014_socket_service_type_not_initialized;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].port = 0;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].used = false;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].open = false;
        adapter_renesas_ryz014_ptr->internet_socket_pool[i].open_error = false;
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

    if (_str_starts_with((char*)buffer_ptr, "CONNECT: "))
    {
        return EWF_RESULT_OK;
    }
    if (_str_starts_with((char*)buffer_ptr, "+SQNSRING:"))
    {
        EWF_LOG("\nURC: SQNSRING");
        int connectionID = EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_INVALID;
        int items = sscanf((char*)buffer_ptr, "+SQNSRING: %u", &connectionID);
        if (items != 1 ||
            ((connectionID < 0) || (EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE <= connectionID)))
        {
            EWF_LOG("\nURC: unexpected format.");
            return EWF_RESULT_OK;
        }
        else
        {
            adapter_renesas_ryz014_ptr->internet_socket_pool[connectionID - 1].recv = true;
            return EWF_RESULT_OK;
        }
        return EWF_RESULT_OK;
    }
    if (_str_starts_with((char*)buffer_ptr, "SQNSH:"))
    {
        int connectionID = -1;
        int items = sscanf((char*)buffer_ptr, "SQNSH:%u", &connectionID);
        if (items != 1 ||
            ((connectionID < 0) || (EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE <= connectionID)))
        {
            EWF_LOG("\nURC: unexpected format.");
            return EWF_RESULT_OK;
        }
        else
        {
            adapter_renesas_ryz014_ptr->internet_socket_pool[connectionID + 1].open = false;
            adapter_renesas_ryz014_ptr->internet_socket_pool[connectionID + 1].open_error = false;
            adapter_renesas_ryz014_ptr->internet_socket_pool[connectionID + 1].conn = false;
            adapter_renesas_ryz014_ptr->internet_socket_pool[connectionID + 1].conn_error = false;
            return EWF_RESULT_OK;
        }
    }
    if (_str_starts_with((char*)buffer_ptr, "+QIURC: \"recv\","))// TODO for RYZ014, awaiting new firmware update
    {
        int connectionID = -1;
        int items = sscanf((char*)buffer_ptr, "+QIURC: \"recv\",%u", &connectionID);
        if (items != 1 ||
            ((connectionID < 0) || (EWF_ADAPTER_RENESAS_RYZ014_INTERNET_SOCKET_POOL_SIZE <= connectionID)))
        {
            EWF_LOG("\nURC: unexpected format.");
            return EWF_RESULT_OK;
        }
        else
        {
            adapter_renesas_ryz014_ptr->internet_socket_pool[connectionID].recv = true;
            return EWF_RESULT_OK;
        }
    }
    if (_str_starts_with((char*)buffer_ptr, "+CME ERROR: 171"))
    {
        return EWF_RESULT_OK;
    }
    return EWF_RESULT_UNHANDLED_URC;

}

/******************************************************************************
 *
 * Common TCP and UDP
 *
 ******************************************************************************/

static ewf_result _ewf_adapter_renesas_ryz014_internet_socket_open(ewf_adapter* adapter_ptr, ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr, int service_type, char const* server_str, uint32_t port)
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

    char socket_str[3];
    const char* socket_cstr = _unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));

    char service_type_str[3];
    const char* service_type_cstr = _unsigned_to_str(service_type, service_type_str, sizeof(service_type_str));

#ifdef EWF_DEBUG
    // Socket Information
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNSI\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    // Close outstanding connections just in case
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSH=", socket_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    char port_str[7];
    const char* port_cstr = _unsigned_to_str(port, port_str, sizeof(port_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSCFG=", socket_cstr, ",1,0,0,600,50\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSCFGEXT=", socket_cstr, ",0,0,0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr,
            "AT+SQNSD=",
            socket_cstr, ",",
            service_type_cstr, ",",
            port_cstr, ",",
            "\"",server_str,"\",",
            "0,4004,1\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].used = true;
    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].open_error = false;
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

    internet_socket_ptr->used = false;
    internet_socket_ptr->conn = false;
    internet_socket_ptr->conn_error = false;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSH=", _unsigned_to_str_buffer(internet_socket_ptr->id), "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    return EWF_RESULT_OK;
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

    socket_ptr->data_ptr = &(adapter_renesas_ryz014_ptr->internet_socket_pool[socket_id]);

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
    EWF_PARAMETER_NOT_USED(socket_ptr);
    EWF_PARAMETER_NOT_USED(control_str);
    EWF_PARAMETER_NOT_USED(buffer_ptr);
    EWF_PARAMETER_NOT_USED(buffer_length_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_PARAMETER_NOT_USED(socket_ptr);
    EWF_PARAMETER_NOT_USED(tls_configuration_id);
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;
    internet_socket_ptr->port = port;
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

    ewf_result result;

    char socket_str[3];
    const char* socket_cstr = _unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));
    char port_str[7];
    const char* port_cstr = _unsigned_to_str(internet_socket_ptr->port, port_str, sizeof(port_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSL=", socket_cstr, ",1,", port_cstr, "\r", NULL)))
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
            ewf_platform_sleep(1);
        }
    }
    else
    {
        if (adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].recv == false)
        {
            return EWF_RESULT_NO_DATA_RECEIVED;
        }
    }

    char socket_str[3];
    const char* socket_cstr = _unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));
    char connect_mode_str[7];
    /* Connection mode set to Command Mode */
    const char* connect_mode_cstr = _unsigned_to_str(1, connect_mode_str, sizeof(connect_mode_str));
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSA=", socket_cstr, ",", connect_mode_cstr, "\r", NULL)))
        return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n")))
        return result;

    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].conn = true;
    adapter_renesas_ryz014_ptr->internet_socket_pool[internet_socket_ptr->id - 1].conn_error = false;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tcp_connect(ewf_socket_tcp * socket_ptr, const char* const server_str, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;
    return _ewf_adapter_renesas_ryz014_internet_socket_open(adapter_ptr, internet_socket_ptr, 0, server_str, port);
}


ewf_result ewf_adapter_renesas_ryz014_tcp_shutdown(ewf_socket_tcp* socket_ptr)
{
    EWF_PARAMETER_NOT_USED(socket_ptr);
    return EWF_RESULT_OK;
}
static ewf_result _ewf_adapter_renesas_ryz014_socket_send(ewf_interface* interface_ptr, ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
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

    char tokenizer_pattern1_str[] = "\r\n> ";
    ewf_interface_tokenizer_pattern tokenizer_pattern1 = {
        NULL,
        tokenizer_pattern1_str,
        sizeof(tokenizer_pattern1_str) - 1,
        false,
    };
    char tokenizer_pattern2_str[] = "\r\nOK\r\n";
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
            "AT+SQNSSENDEXT=",
            _unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str)), ",",
            _unsigned_to_str(buffer_length, len_str, sizeof(len_str)), "\r",
            NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern1_str))) return result;

    if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern2))) return result;
    if (ewf_result_failed(result = ewf_interface_send(interface_ptr, (const uint8_t*)buffer_ptr, buffer_length))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern2_str))) return result;

    if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;
    return EWF_RESULT_OK;


}
ewf_result ewf_adapter_renesas_ryz014_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

    return _ewf_adapter_renesas_ryz014_socket_send(interface_ptr, internet_socket_ptr, buffer_ptr, buffer_length);

}

ewf_result ewf_adapter_renesas_ryz014_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

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
            ewf_platform_sleep(1);
        }
    }
    else
    {
        if (internet_socket_ptr->recv == false)
        {
            return EWF_RESULT_NO_DATA_RECEIVED;
        }
    }

    char read_length_str[5];
    uint32_t read_length = (*buffer_length_ptr > 1500) ? (1500) : (*buffer_length_ptr);

    char socket_str[3];
    const char* socket_cstr = _unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));
    char* read_length_cstr = _unsigned_to_str(read_length, read_length_str, sizeof(read_length_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSRECV=",socket_cstr,",",read_length_cstr,"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr , &response_ptr, &response_length, 100))) return result;

    if (response_length < 7)
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    if (_str_starts_with((char*)response_ptr, "\r\nERROR"))
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    const char data_read_response_str[] = "\r\n+SQNSRECV: ";
    if (!_str_starts_with((char*)response_ptr, data_read_response_str))
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
        read_actual_length = _str_to_unsigned(p);
        if (read_actual_length == 0)
        {
            *buffer_length_ptr = 0;
        }
        else
        {
            while (*p && isdigit((unsigned char)*p)) p++;
            while (*p && (*p==',')) p++; // skip the socket number and ','
            uint32_t recieve_actual_lenght;
            recieve_actual_lenght = atoi(p);
            while (*p && isdigit((unsigned char)*p)) p++; // skip the received length
            p = p+2; // skip <CR><LF> before start of data
            if(*(p + recieve_actual_lenght + 0) != '\r'
                        || *(p + recieve_actual_lenght + 1) != '\n'
                        || *(p + recieve_actual_lenght + 2) != '\r'
                        || *(p + recieve_actual_lenght + 3) != '\n'
                        || *(p + recieve_actual_lenght + 4) != 'O'
                        || *(p + recieve_actual_lenght + 5) != 'K'
                        || *(p + recieve_actual_lenght + 6) != '\r'
                        || *(p + recieve_actual_lenght + 7) != '\n')
            {
                //Unexpected format
            }
            else
            {
                *buffer_length_ptr = (uint32_t)((*buffer_length_ptr >= recieve_actual_lenght) ? recieve_actual_lenght : *buffer_length_ptr);
                memcpy(buffer_ptr, p, *buffer_length_ptr);
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
    EWF_PARAMETER_NOT_USED(socket_ptr);
    EWF_PARAMETER_NOT_USED(control_str);
    EWF_PARAMETER_NOT_USED(buffer_ptr);
    EWF_PARAMETER_NOT_USED(buffer_length_ptr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_PARAMETER_NOT_USED(socket_ptr);
    EWF_PARAMETER_NOT_USED(tls_configuration_id);
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_udp_bind(ewf_socket_udp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;
    internet_socket_ptr->port = port;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

    ewf_result result;

    /* Configure socket connection and open socket connect to remote address */
    if (ewf_result_failed(result = _ewf_adapter_renesas_ryz014_internet_socket_open(adapter_ptr, internet_socket_ptr, 1, remote_address_str, remote_port)))
    {
        EWF_LOG_ERROR("Failed to open UDP socket.");
        return EWF_RESULT_CONNECTION_FAILED;
    }
    return _ewf_adapter_renesas_ryz014_socket_send(interface_ptr, internet_socket_ptr, buffer_ptr, buffer_length);
}

ewf_result ewf_adapter_renesas_ryz014_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_PARAMETER_NOT_USED(remote_address);
    EWF_PARAMETER_NOT_USED(remote_address_length_ptr);
    EWF_PARAMETER_NOT_USED(remote_port_ptr);

    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_ryz014_internet_socket* internet_socket_ptr = (ewf_adapter_renesas_ryz014_internet_socket*)socket_ptr->data_ptr;

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
            ewf_platform_sleep(1);
        }
    }
    else
    {
        if (internet_socket_ptr->recv == false)
        {
            return EWF_RESULT_NO_DATA_RECEIVED;
        }
    }

    char read_length_str[5];
    uint32_t read_length = (*buffer_length_ptr > 1500) ? (1500) : (*buffer_length_ptr);

    char socket_str[3];
    const char* socket_cstr = _unsigned_to_str(internet_socket_ptr->id, socket_str, sizeof(socket_str));
    char* read_length_cstr = _unsigned_to_str(read_length, read_length_str, sizeof(read_length_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSRECV=",socket_cstr,",",read_length_cstr,"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr , &response_ptr, &response_length, 100))) return result;

    if (response_length < 7)
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    if (_str_starts_with((char*)response_ptr, "\r\nERROR"))
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    const char data_read_response_str[] = "\r\n+SQNSRECV: ";
    if (!_str_starts_with((char*)response_ptr, data_read_response_str))
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
        read_actual_length = _str_to_unsigned(p);
        if (read_actual_length == 0)
        {
            *buffer_length_ptr = 0;
        }
        else
        {
            while (*p && isdigit((unsigned char)*p)) p++;
            while (*p && (*p==',')) p++; // skip the socket number and ','
            uint32_t recieve_actual_lenght;
            recieve_actual_lenght = atoi(p);
            while (*p && isdigit((unsigned char)*p)) p++; // skip the received length
            p = p+2; // skip <CR><LF> before start of data
            if(*(p + recieve_actual_lenght + 0) != '\r'
                        || *(p + recieve_actual_lenght + 1) != '\n'
                        || *(p + recieve_actual_lenght + 2) != '\r'
                        || *(p + recieve_actual_lenght + 3) != '\n'
                        || *(p + recieve_actual_lenght + 4) != 'O'
                        || *(p + recieve_actual_lenght + 5) != 'K'
                        || *(p + recieve_actual_lenght + 6) != '\r'
                        || *(p + recieve_actual_lenght + 7) != '\n')
            {
                //Unexpected format
            }
            else
            {
                *buffer_length_ptr = (uint32_t)((*buffer_length_ptr >= recieve_actual_lenght) ? recieve_actual_lenght : *buffer_length_ptr);
                memcpy(buffer_ptr, p, *buffer_length_ptr);
            }
        }
        ewf_interface_release(interface_ptr, response_ptr);
    }

    return EWF_RESULT_OK;
}
