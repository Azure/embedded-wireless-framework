/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter UDP API implementation
 ****************************************************************************/

#include "ewf_adapter.h"

#define EWF_VALIDATE_UDP_API_POINTER(adapter_ptr, function_ptr)                     \
do {                                                                                \
    if ((adapter_ptr->udp_api_ptr == NULL) ||                                       \
        (adapter_ptr->udp_api_ptr->function_ptr == NULL))                           \
    {                                                                               \
        EWF_LOG_ERROR("The function is not implemented.");                          \
        return EWF_RESULT_NOT_SUPPORTED;                                            \
    }                                                                               \
} while(0)

ewf_result ewf_adapter_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_UDP_API_POINTER(adapter_ptr, open);
    return adapter_ptr->udp_api_ptr->open(adapter_ptr, socket_ptr);
}

ewf_result ewf_adapter_udp_close(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_UDP_API_POINTER(adapter_ptr, close);
    return adapter_ptr->udp_api_ptr->close(socket_ptr);
}

ewf_result ewf_adapter_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_UDP_API_POINTER(adapter_ptr, control);
    return adapter_ptr->udp_api_ptr->control(socket_ptr, control_str, buffer_ptr, buffer_length_ptr);
}

ewf_result ewf_adapter_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_UDP_API_POINTER(adapter_ptr, control);
    return adapter_ptr->udp_api_ptr->set_dtls_configuration(socket_ptr, dtls_configuration_id);
}

ewf_result ewf_adapter_udp_bind(ewf_socket_udp* socket_ptr, uint32_t local_port)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_UDP_API_POINTER(adapter_ptr, control);
    return adapter_ptr->udp_api_ptr->bind(socket_ptr, local_port);
}

ewf_result ewf_adapter_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_UDP_API_POINTER(adapter_ptr, control);
    return adapter_ptr->udp_api_ptr->send_to(socket_ptr, remote_address_str, remote_port, buffer_ptr, buffer_length);
}

ewf_result ewf_adapter_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address_str, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_VALIDATE_UDP_API_POINTER(adapter_ptr, control);
    return adapter_ptr->udp_api_ptr->receive_from(socket_ptr, remote_address_str, remote_address_length_ptr, remote_port_ptr, buffer_ptr, buffer_length_ptr, wait);
}

ewf_result ewf_adapter_udp_receive_callback_set(ewf_socket_udp* socket_ptr, ewf_adapter_udp_receive_callback callback)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    socket_ptr->receive_callback = callback;
    return EWF_RESULT_OK;
}
