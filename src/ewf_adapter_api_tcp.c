/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter TCP API implementation
 ****************************************************************************/

#include "ewf_adapter.h"

#define EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, function_ptr)                     \
do {                                                                                \
    if ((adapter_ptr->tcp_api_ptr == NULL) ||                                       \
        (adapter_ptr->tcp_api_ptr->function_ptr == NULL))                           \
    {                                                                               \
        EWF_LOG_ERROR("The function is not implemented.\n");                        \
        return EWF_RESULT_NOT_SUPPORTED;                                            \
    }                                                                               \
} while(0)

ewf_result ewf_adapter_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, open);
    return adapter_ptr->tcp_api_ptr->open(adapter_ptr, socket_ptr);
}

ewf_result ewf_adapter_tcp_close(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, close);
    return adapter_ptr->tcp_api_ptr->close(socket_ptr);
}

ewf_result ewf_adapter_tcp_control(ewf_socket_tcp* socket_ptr, const char* command_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, control);
    return adapter_ptr->tcp_api_ptr->control(socket_ptr, command_str, buffer_ptr, buffer_length_ptr);
}

ewf_result ewf_adapter_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, set_tls_configuration);
    return adapter_ptr->tcp_api_ptr->set_tls_configuration(socket_ptr, tls_configuration_id);
}

ewf_result ewf_adapter_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, bind);
    return adapter_ptr->tcp_api_ptr->bind(socket_ptr, port);
}

ewf_result ewf_adapter_tcp_listen(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, listen);
    return adapter_ptr->tcp_api_ptr->listen(socket_ptr);
}

ewf_result ewf_adapter_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, accept);
    return adapter_ptr->tcp_api_ptr->accept(socket_ptr, socket_new_ptr);
}

ewf_result ewf_adapter_tcp_connect(ewf_socket_tcp* socket_ptr, const char* server_str, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, connect);
    return adapter_ptr->tcp_api_ptr->connect(socket_ptr, server_str, port);
}

ewf_result ewf_adapter_tcp_shutdown(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, shutdown);
    return adapter_ptr->tcp_api_ptr->shutdown(socket_ptr);
}

ewf_result ewf_adapter_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, send);
    return adapter_ptr->tcp_api_ptr->send(socket_ptr, buffer_ptr, buffer_length);
}

ewf_result ewf_adapter_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t * buffer_length, bool wait)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_TCP_API_POINTER(adapter_ptr, receive);
    return adapter_ptr->tcp_api_ptr->receive(socket_ptr, buffer_ptr, buffer_length, wait);
}

ewf_result ewf_adapter_tcp_receive_callback_set(ewf_socket_tcp* socket_ptr, ewf_adapter_tcp_receive_callback callback)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    socket_ptr->receive_callback = callback;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_tcp_disconnect_callback_set(ewf_socket_tcp* socket_ptr, ewf_adapter_tcp_disconnect_callback callback)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    socket_ptr->disconnect_callback = callback;
    return EWF_RESULT_OK;
}
