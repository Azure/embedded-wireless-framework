/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter BSD sockets API implementation
 ****************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#include "ewf_adapter_bsd_sockets.h"
#include "ewf_lib.h"

ewf_adapter_api_control ewf_adapter_bsd_sockets_api_control =
{
    ewf_adapter_bsd_sockets_start,
    ewf_adapter_bsd_sockets_stop,
};

ewf_result ewf_adapter_bsd_sockets_start(ewf_adapter* adapter_ptr)
{
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_stop(ewf_adapter* adapter_ptr)
{
    return EWF_RESULT_OK;
}

ewf_adapter_api_info ewf_adapter_bsd_sockets_api_info =
{
    ewf_adapter_bsd_sockets_info,
    ewf_adapter_bsd_sockets_get_ipv4_address,
    ewf_adapter_bsd_sockets_get_ipv4_netmask,
    ewf_adapter_bsd_sockets_get_ipv4_gateway,
    ewf_adapter_bsd_sockets_get_ipv4_dns,
    NULL,
    NULL,
    NULL,
};

ewf_result ewf_adapter_bsd_sockets_info(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result = EWF_RESULT_OK;

    uint32_t ipv4_address;
    if (ewf_result_failed(result = ewf_adapter_bsd_sockets_get_ipv4_address(adapter_ptr, &ipv4_address))) return result;

    EWF_LOG("\nIPv4 address: %u.%u.%u.%u\r\n",
        (unsigned) (ipv4_address >> 24 & 0xFF),
        (unsigned) (ipv4_address >> 16 & 0xFF),
        (unsigned) (ipv4_address >> 8 & 0xFF),
        (unsigned) (ipv4_address & 0xFF));

    return result;
}

ewf_result ewf_adapter_bsd_sockets_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t* address_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);

    if (address_ptr == NULL)
    {
        EWF_LOG_ERROR("The address pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s < 0)
    {
        EWF_LOG_ERROR("Failed to create a socket, with error %d.\n", errno);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    struct sockaddr_in addr_dns_server;
    addr_dns_server.sin_family = PF_INET;
    addr_dns_server.sin_port = htons(53);
    inet_aton("8.8.8.8", &addr_dns_server.sin_addr);

    int ret = connect(s, (struct sockaddr*)&addr_dns_server, sizeof(addr_dns_server));
    if (ret < 0)
    {
        EWF_LOG_ERROR("Failed to connect a socket, with error %d.\n", errno);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    struct sockaddr_in addr = {0};
    addr.sin_family = PF_INET;
    socklen_t len = sizeof(addr);
    ret = getsockname(s, (struct sockaddr*)&addr, &len);
    if (ret < 0)
    {
        EWF_LOG_ERROR("Failed to get a socket address, with error %d.\n", errno);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    *address_ptr = ntohl(addr.sin_addr.s_addr);

    EWF_LOG("The local IPv4 address is 0x%08X", *address_ptr);

    ret = close(s);
    if (ret < 0)
    {
        EWF_LOG_ERROR("Failed to close a socket, with error %d.\n", errno);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t* netmask_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);

    if (netmask_ptr == NULL)
    {
        EWF_LOG_ERROR("The netmask pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    *netmask_ptr = 0xFFFFFFFF;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t* gateway_ptr)
{
    return ewf_adapter_bsd_sockets_get_ipv4_address(adapter_ptr, gateway_ptr);
}

ewf_result ewf_adapter_bsd_sockets_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t* dns_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);

    if (dns_ptr == NULL)
    {
        EWF_LOG_ERROR("The DNS pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    // Rather look into the resolver?
    *dns_ptr = 0x08080808;

    return EWF_RESULT_OK;
}

#if EWF_ADAPTER_BSD_SOCKETS_TCP_ENABLED

ewf_adapter_api_tcp ewf_adapter_bsd_sockets_api_tcp =
{
    ewf_adapter_bsd_sockets_tcp_open,
    ewf_adapter_bsd_sockets_tcp_close,

    ewf_adapter_bsd_sockets_tcp_control,

    ewf_adapter_bsd_sockets_tcp_set_tls_configuration,

    ewf_adapter_bsd_sockets_tcp_bind,
    ewf_adapter_bsd_sockets_tcp_listen,
    ewf_adapter_bsd_sockets_tcp_accept,
    ewf_adapter_bsd_sockets_tcp_connect,
    ewf_adapter_bsd_sockets_tcp_shutdown,
    ewf_adapter_bsd_sockets_tcp_send,
    ewf_adapter_bsd_sockets_tcp_receive,
};

ewf_result ewf_adapter_bsd_sockets_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets* implementation_ptr = (ewf_adapter_bsd_sockets*) adapter_ptr->implementation_ptr;

    if (socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[BSD SOCKETS][TCP][OPEN/CALL][ADAPTER %p]\n", adapter_ptr);

    socket_ptr->adapter_ptr = adapter_ptr;

    socket_ptr->data_ptr = malloc(sizeof(ewf_adapter_bsd_sockets_socket));

    if (socket_ptr->data_ptr == NULL)
    {
        EWF_LOG_ERROR("Failed to allocate a new socket in the heap.\n");
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    bsd_socket_ptr->s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("socket failed with error: %d\n", errno);
        if (socket_ptr->data_ptr == NULL)
        {
            free(socket_ptr->data_ptr);
        }
        return EWF_RESULT_INVALID_SOCKET;
    }

    EWF_LOG("[BSD SOCKETS][TCP][OPEN/RETURN][SOCKET %d]\n", bsd_socket_ptr->s);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_close(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    EWF_LOG("[BSD SOCKETS][TCP][CLOSE/CALL][SOCKET %d]\n", bsd_socket_ptr->s);

    if (socket_ptr->data_ptr)
    {
        ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

        if (bsd_socket_ptr->s < 0)
        {
            int ret = close(bsd_socket_ptr->s);
            if (ret < 0)
            {
                EWF_LOG_ERROR("closesocket failed with error: %d\n", errno);
            }
        }

        free(socket_ptr->data_ptr);
    }

    EWF_LOG("[BSD SOCKETS][TCP][CLOSE/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    struct sockaddr_in bind_addr;
    bind_addr.sin_family = AF_INET;
    bind_addr.sin_port = htons(port);
    bind_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(bsd_socket_ptr->s, (struct sockaddr*)&bind_addr, sizeof(bind_addr));
    if (ret < 0)
    {
        EWF_LOG_ERROR("bind failed with error: %d\n", errno);
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_listen(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    int ret = listen(bsd_socket_ptr->s, SOMAXCONN);
    if (ret < 0)
    {
        EWF_LOG_ERROR("listen failed with error: %d\n", errno);
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (socket_new_ptr == NULL)
    {
        EWF_LOG_ERROR("The new socket pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[BSD SOCKETS][TCP][ACCEPT/CALL][SOCKET 0x%08X]\n", bsd_socket_ptr->s);

    socket_new_ptr->adapter_ptr = adapter_ptr;

    socket_new_ptr->data_ptr = malloc(sizeof(ewf_adapter_bsd_sockets_socket));
    if (socket_new_ptr->data_ptr == NULL)
    {
        EWF_LOG_ERROR("Failed to allocate a new socket in the heap.\n");
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    ewf_adapter_bsd_sockets_socket* bsd_new_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_new_ptr->data_ptr;

    struct sockaddr_in addr;
    int addrlen = sizeof(addr);

    bsd_new_socket_ptr->s = accept(bsd_socket_ptr->s, (struct sockaddr*)&addr, &addrlen);
    if (bsd_new_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("accept failed with error: %d\n", errno);
        return EWF_RESULT_INVALID_SOCKET;
    }

    char addr_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr.sin_addr), addr_str, INET_ADDRSTRLEN);
    EWF_LOG("[BSD SOCKETS][TCP][ACCEPT/RETURN][SOCKET 0x%08X][NEW SOCKET 0x%08X][ORIGIN %s]\n", bsd_socket_ptr->s, bsd_new_socket_ptr->s, addr_str);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_connect(ewf_socket_tcp* socket_ptr, const char* server_str, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!server_str)
    {
        EWF_LOG_ERROR("The server string cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[BSD SOCKETS][TCP][CONNECT/CALL][SOCKET 0x%08X][SERVER %s][PORT %u]\n", bsd_socket_ptr->s, server_str, port);

    char port_str[7];
    const char* port_cstr = ewfl_unsigned_to_str(port, port_str, sizeof(port_str));

    ewf_result result;
    int ret;

    struct addrinfo server_addrinfo;
    memset(&server_addrinfo, 0, sizeof(server_addrinfo));
    server_addrinfo.ai_family = AF_INET;
    server_addrinfo.ai_socktype = SOCK_STREAM;
    server_addrinfo.ai_protocol = IPPROTO_TCP;

    struct addrinfo* addrinfo_result_ptr = NULL;
    struct addrinfo* addrinfo_ptr = NULL;

    /* Resolve the server address and port */
    ret = getaddrinfo(server_str, port_cstr, &server_addrinfo, &addrinfo_result_ptr);
    if (ret != 0)
    {
        EWF_LOG_ERROR("getaddrinfo failed, server [%s], port [%s], return [%d], error: [%d]\n", server_str, port_cstr, ret, errno);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    if (addrinfo_result_ptr->ai_next)
    {
        EWF_LOG_ERROR("[WARNING] Ambiguous address resolved, using the first one.\n");
    }

    /* Attmept to connect to the server. */
    ret = connect(bsd_socket_ptr->s, addrinfo_result_ptr->ai_addr, (int)addrinfo_result_ptr->ai_addrlen);

    freeaddrinfo(addrinfo_result_ptr);

    if (ret)
    {
        EWF_LOG("connect failed, ret [%d], errno [%d]\n", ret, errno);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("Unable to connect to server!\n");
        return EWF_RESULT_CONNECTION_FAILED;
    }

    EWF_LOG("[BSD SOCKETS][TCP][CONNECT/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_shutdown(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[BSD SOCKETS][TCP][SHUTDOWN/CALL][SOCKET 0x%08X]\n", bsd_socket_ptr->s);

    int ret = shutdown(bsd_socket_ptr->s, SHUT_RDWR);
    if (ret < 0)
    {
        EWF_LOG_ERROR("shutdown failed with error: %d\n", errno);
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    EWF_LOG("[BSD SOCKETS][TCP][SHUTDOWN/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

#ifdef EWF_DEBUG
    uint32_t step = 64;
    for (uint32_t i = 0; i < buffer_length; i += step)
    {
        const char* str = ewfl_escape_str_to_str_buffer(buffer_ptr + i, step);
        EWF_LOG("[BSD SOCKETS][TCP][SEND/CALL][BUFFER %p][%04d][%s]\n", buffer_ptr, i, str);
    }
#endif

    EWF_LOG("[BSD SOCKETS][TCP][SEND/CALL][SOCKET 0x%08X][BUFFER %p][LENGTH %u]\n", bsd_socket_ptr->s, buffer_ptr, buffer_length);

    int ret = send(bsd_socket_ptr->s, buffer_ptr, (int)buffer_length, 0);
    if (ret < 0)
    {
        EWF_LOG_ERROR("send failed with error: %d\n", errno);
        return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
    }

    EWF_LOG("[BSD SOCKETS][TCP][SEND/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[BSD SOCKETS][TCP][RECEIVE/CALL][SOCKET 0x%08X][BUFFER %p][LENGTH %u]\n", bsd_socket_ptr->s, buffer_ptr, *buffer_length_ptr);

    if (!wait)
    {
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(bsd_socket_ptr->s, &fds);

        int ret = select(bsd_socket_ptr->s + 1, &fds, 0, 0, &timeout);
        if (ret == 0)
        {
            *buffer_length_ptr = 0;
            return EWF_RESULT_NO_DATA_AVAILABLE;
        }
        else if (ret < 0)
        {
            EWF_LOG_ERROR("select failed with error: %d\n", errno);
            return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
        }
    }

    int ret = recv(bsd_socket_ptr->s, buffer_ptr, *buffer_length_ptr, 0);
    if (ret == 0)
    {
        EWF_LOG_ERROR("recv returned zero.");
        return EWF_RESULT_NO_DATA_AVAILABLE;
    }
    else if (ret < 0)
    {
        EWF_LOG_ERROR("recv failed, ret [%d], errno [%d]\n", ret, errno);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    *buffer_length_ptr = ret;

    EWF_LOG("[BSD SOCKETS][TCP][RECEIVE/RETURN][SOCKET 0x%08X][LENGTH %u]\n", bsd_socket_ptr->s, *buffer_length_ptr);

#ifdef EWF_DEBUG
    uint32_t step = 64;
    for (uint32_t i = 0; i < *buffer_length_ptr; i += step)
    {
        const char* str = ewfl_escape_str_to_str_buffer(buffer_ptr + i, step);
        EWF_LOG("[BSD SOCKETS][TCP][RECEIVE/RETURN][SOCKET 0x%08X][%04d][%s]\n", bsd_socket_ptr->s, i, str);
    }
#endif

    return EWF_RESULT_OK;
}

#endif /* EWF_ADAPTER_BSD_SOCKETS_TCP_ENABLED */

#if EWF_ADAPTER_BSD_SOCKETS_UDP_ENABLED

ewf_adapter_api_udp ewf_adapter_bsd_sockets_api_udp =
{
    ewf_adapter_bsd_sockets_udp_open,
    ewf_adapter_bsd_sockets_udp_close,

    ewf_adapter_bsd_sockets_udp_control,

    ewf_adapter_bsd_sockets_udp_set_dtls_configuration,

    ewf_adapter_bsd_sockets_udp_bind,
    ewf_adapter_bsd_sockets_udp_shutdown,
    ewf_adapter_bsd_sockets_udp_send_to,
    ewf_adapter_bsd_sockets_udp_receive_from,
};

ewf_result ewf_adapter_bsd_sockets_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets* implementation_ptr = (ewf_adapter_bsd_sockets*)adapter_ptr->implementation_ptr;

    if (socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[BSD SOCKETS][UDP][OPEN/CALL][ADAPTER %p]\n", adapter_ptr);

    socket_ptr->adapter_ptr = adapter_ptr;

    socket_ptr->data_ptr = malloc(sizeof(ewf_adapter_bsd_sockets_socket));
    if (socket_ptr->data_ptr == NULL)
    {
        EWF_LOG_ERROR("Failed to allocate a new socket in the heap.\n");
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    bsd_socket_ptr->s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("socket failed with error: %d\n", errno);
        return EWF_RESULT_INVALID_SOCKET;
    }

    EWF_LOG("[BSD SOCKETS][UDP][OPEN/RETURN][SOCKET 0x%08X]\n", bsd_socket_ptr->s);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_udp_close(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    EWF_LOG("[BSD SOCKETS][UDP][CLOSE/CALL][SOCKET 0x%08X]\n", bsd_socket_ptr->s);

    if (socket_ptr->data_ptr)
    {
        ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

        if (bsd_socket_ptr->s < 0)
        {
            int ret = close(bsd_socket_ptr->s);
            if (ret < 0)
            {
                EWF_LOG_ERROR("close failed with error: %d\n", errno);
            }
        }

        free(socket_ptr->data_ptr);
    }

    EWF_LOG("[BSD SOCKETS][UDP][CLOSE/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_udp_bind(ewf_socket_udp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    struct sockaddr_in bind_addr;
    bind_addr.sin_family = AF_INET;
    bind_addr.sin_port = htons(port);
    bind_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(bsd_socket_ptr->s, (struct sockaddr*)&bind_addr, sizeof(bind_addr));
    if (ret < 0)
    {
        EWF_LOG_ERROR("bind failed with error: %d\n", errno);
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_udp_shutdown(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[BSD SOCKETS][UDP][SHUTDOWN/CALL][SOCKET 0x%08X]\n", bsd_socket_ptr->s);

    int ret = shutdown(bsd_socket_ptr->s, SHUT_RDWR);
    if (ret < 0)
    {
        EWF_LOG_ERROR("shutdown failed with error: %d\n", errno);
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    EWF_LOG("[BSD SOCKETS][UDP][SHUTDOWN/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    int ret;

    char remote_port_str[7];
    const char* remote_port_cstr = ewfl_unsigned_to_str(remote_port, remote_port_str, sizeof(remote_port_str));

    struct addrinfo remote_addrinfo;
    memset(&remote_addrinfo, 0, sizeof(remote_addrinfo));
    remote_addrinfo.ai_family = AF_INET;
    remote_addrinfo.ai_socktype = SOCK_DGRAM;
    remote_addrinfo.ai_protocol = IPPROTO_UDP;

    struct addrinfo* addrinfo_result = NULL;
    struct addrinfo* addrinfo_ptr = NULL;

    /* Resolve the server address and port */
    ret = getaddrinfo(remote_address_str, remote_port_cstr, &remote_addrinfo, &addrinfo_result);
    if (ret)
    {
        EWF_LOG_ERROR("getaddrinfo failed, return %d, error: %d\n", ret, errno);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    if (addrinfo_result->ai_next)
    {
        EWF_LOG_ERROR("[WARNING] Ambiguous address resolved, using the first one.\n");
    }

#ifdef EWF_DEBUG
    uint32_t step = 64;
    for (uint32_t i = 0; i < buffer_length; i += step)
    {
        const char* str = ewfl_escape_str_to_str_buffer(buffer_ptr + i, step);
        EWF_LOG("[BSD SOCKETS][UDP][SEND-TO/CALL][SOCKET 0x%08X][%04d][%s]\n", bsd_socket_ptr->s, i, str);
    }
#endif

    EWF_LOG("[BSD SOCKETS][UDP][SEND-TO/CALL][SOCKET 0x%08X][SERVER %s][PORT %u][BUFFER %p][LENGTH %u]\n", bsd_socket_ptr->s, remote_address_str, remote_port, buffer_ptr, buffer_length);

    ret = sendto(bsd_socket_ptr->s, buffer_ptr, buffer_length, 0, addrinfo_result->ai_addr, addrinfo_result->ai_addrlen);
    if (ret < 0)
    {
        EWF_LOG_ERROR("sendto failed with error: %d\n", ret);
        freeaddrinfo(addrinfo_result);
        return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
    }

    freeaddrinfo(addrinfo_result);

    EWF_LOG("[BSD SOCKETS][UDP][SEND-TO/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_bsd_sockets_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_BSD_SOCKETS);
    ewf_adapter_bsd_sockets_socket* bsd_socket_ptr = (ewf_adapter_bsd_sockets_socket*)socket_ptr->data_ptr;

    if (bsd_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (bsd_socket_ptr->s < 0)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (buffer_ptr == NULL)
    {
        EWF_LOG_ERROR("buffer_ptr cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (buffer_length_ptr == NULL)
    {
        EWF_LOG_ERROR("buffer_length_ptr cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    struct sockaddr_in remote_addr;
    int remote_addr_size = sizeof(remote_addr);

    EWF_LOG("[BSD SOCKETS][UDP][RECEIVE-FROM/CALL][SOCKET 0x%08X][BUFFER %p][LENGTH %u]\n", bsd_socket_ptr->s, buffer_ptr, *buffer_length_ptr);

    if (!wait)
    {
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(bsd_socket_ptr->s, &fds);

        int ret = select(bsd_socket_ptr->s + 1, &fds, 0, 0, &timeout);
        if (ret == 0)
        {
            *buffer_length_ptr = 0;
            return EWF_RESULT_NO_DATA_AVAILABLE;
        }
        else if (ret < 0)
        {
            EWF_LOG_ERROR("select failed with error: %d\n", errno);
            return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
        }
    }

    int ret = recvfrom(bsd_socket_ptr->s, buffer_ptr, *buffer_length_ptr, 0, (struct sockaddr*)&remote_addr, &remote_addr_size);
    if (ret == 0)
    {
        EWF_LOG_ERROR("recvfrom returned zero.");
        return EWF_RESULT_NO_DATA_AVAILABLE;
    }
    else if (ret < 0)
    {
        EWF_LOG_ERROR("recvfrom failed, ret [%d], errno [%d]\n", ret, errno);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    *buffer_length_ptr = ret;

    if (remote_address && remote_address_length_ptr && (*remote_address_length_ptr > 0))
    {
        inet_ntop(AF_INET, &(remote_addr.sin_addr), remote_address, *remote_address_length_ptr);
    }

    if (remote_port_ptr)
    {
        *remote_port_ptr = remote_addr.sin_port;
    }

    EWF_LOG("[BSD SOCKETS][UDP][RECEIVE-FROM/RETURN][SOCKET 0x%08X][SERVER %s][PORT %u][LENGTH %u]\n", bsd_socket_ptr->s, remote_address ? remote_address : "unresolved", remote_addr.sin_port, *buffer_length_ptr);

#ifdef EWF_DEBUG
    uint32_t step = 64;
    for (uint32_t i = 0; i < *buffer_length_ptr; i += step)
    {
        const char* str = ewfl_escape_str_to_str_buffer(buffer_ptr + i, step);
        EWF_LOG("[BSD SOCKETS][UDP][RECEIVE-FROM/RETURN][SOCKET 0x%08X][%04d][%s]\n", bsd_socket_ptr->s, i, str);
    }
#endif

    return EWF_RESULT_OK;
}

#endif /* EWF_ADAPTER_BSD_SOCKETS_UDP_ENABLED */

/** @} *** group_adapter_bsd_sockets */
