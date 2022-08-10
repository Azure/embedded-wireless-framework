/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter linux socket API implementation
 ****************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#include "ewf_adapter.h"
#include "ewf_lib.h"


/**
 * @defgroup group_adapter_bsd_socket The BSD socket adapter driver
 * @ingroup group_adapter
 * @brief The BSD socket adapter
 * @{
 */

/**
 * @defgroup group_adapter_bsd_socket_configuration BSD socket adapter configuration
 * @ingroup group_adapter_configuration
 * @brief BSD socket adapter configuration
 * @{
 */

/** @brief The total number of supported sockets in the adapter */
#define _ADAPTER_SOCKET_POOL_SIZE (12)

/** @} */


/**
 * @defgroup group_adapter_bsd_socket_state BSD socket adapter internal state
 * @brief WinSock2 adapter driver internal state
 * @{
 */

/** @brief Internal structure for socket status  */
typedef struct _adapter_socket
{
    volatile int s;
    volatile bool used;

} _adapter_socket;

/** @brief The internal memory pool of sockets */
static _adapter_socket _adapter_socket_pool[_ADAPTER_SOCKET_POOL_SIZE];

/**
 * @brief Get an available socket from the internal pool
 * @return an index to an available entry in the socket pool, or -1 if not available
 */
static int _adapter_socket_pool_allocate()
{
    int i = -1;
    for (i = 0; i < _ADAPTER_SOCKET_POOL_SIZE; ++i)
        if (_adapter_socket_pool[i].used == false)
            break;
    return i;
}

/** @} */


ewf_result ewf_adapter_start()
{
    for (unsigned i = 0; i < _ADAPTER_SOCKET_POOL_SIZE; ++i)
    {
        _adapter_socket_pool[i].used = false;
        _adapter_socket_pool[i].s = -1;
    }
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_stop()
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_info()
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_get_ipv4_address(uint32_t* address)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_get_ipv4_netmask(uint32_t* netmask)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_get_ipv4_gateway(uint32_t* gateway)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_get_ipv4_dns(uint32_t* dns)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_tcp_listen(int* socket_id_ptr, unsigned port)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_tcp_connect(int* socket_id_ptr, char const* server, unsigned port)
{
	ewf_result result;
	int iResult;

	if (!socket_id_ptr)
	{
		EWF_LOG_ERROR("The socket pointer cannot be NULL.");
		return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	}

	if (!server)
	{
		EWF_LOG_ERROR("The server string cannot be NULL.");
		return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	}

	*socket_id_ptr = _adapter_socket_pool_allocate();
	if (*socket_id_ptr == -1)
	{
		EWF_LOG_ERROR("Too many open sockets.");
		return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
	}

	char port_str[7];
	const char* port_cstr = _unsigned_to_str(port, port_str, sizeof(port_str));

    int s;
	struct addrinfo hints;
	struct addrinfo* res = NULL;
	struct addrinfo* res0 = NULL;
 struct in_addr addr;
    struct sockaddr_in sa;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;

	/* Resolve the server address and port */
	iResult = getaddrinfo(server, port_cstr, &hints, &res0);
	if (iResult)
	{
		EWF_LOG_ERROR("getaddrinfo failed with error: %d\n", iResult);
		return EWF_RESULT_CONNECTION_FAILED;
	}

    addr.s_addr = ((struct sockaddr_in *)(res0->ai_addr))->sin_addr.s_addr;
    printf("ip address : %s\n", inet_ntoa(addr));

if (signal(SIGUSR1, SIG_IGN) == SIG_ERR)
                    perror("SIGUSR1");
    for (res = res0; res; res = res->ai_next)
    {
        s = socket(res->ai_family, res->ai_socktype,
                       res->ai_protocol);
        printf("Socket: %d\n", s);
        if (s < 0)
        {
		    EWF_LOG_ERROR("socket failed");
            continue;
        }
        memset(&sa, 0, sizeof sa);

        sa.sin_family = AF_INET;
        sa.sin_port = htons(port);
        iResult = inet_pton(AF_INET, inet_ntoa(addr), &sa.sin_addr);

        printf("sizeof sa : %d %x \n", iResult, sa.sin_addr.s_addr);
		iResult = connect(s,  (struct sockaddr *)&sa, sizeof (sa));
        unsigned int timeout =1000;
        if((iResult< 0) && (errno ==EINTR ))
        {
		    while((timeout--) || (connect(s,  (struct sockaddr *)&sa, sizeof (sa)) < 0));
            if ((iResult< 0) || timeout < 00)
            {
                close(s);
                EWF_LOG_ERROR("connect failed %d %s  timeout %d",iResult, strerror(errno),timeout);
                s = -1;
                continue;
            }
            else
            {
                printf("Connect successfull %d\n",timeout);
            }
        }
        else if(iResult< 0)
            {
                close(s);
                EWF_LOG_ERROR("connect failed %d %s",iResult, strerror(errno));
                s = -1;
                continue;
            }
            else
            {
                printf("Connect successfull\n");
            }

        break;
    }

	freeaddrinfo(res0);
    _adapter_socket_pool[*socket_id_ptr].s = s;

	if (_adapter_socket_pool[*socket_id_ptr].s == -1) {
		EWF_LOG_ERROR("Unable to connect to server!\n");
		return EWF_RESULT_CONNECTION_FAILED;
	}
	_adapter_socket_pool[*socket_id_ptr].used = true;

    // const char http_message[] = "GET /index.html HTTP/1.1\r\nHost:www.microsoft.com\r\n\r\n";
    // unsigned http_message_length = sizeof(http_message) - 1;
    // static char buffer[2048];
    // unsigned buffer_length = sizeof(buffer);

    //  write(s, http_message, http_message_length);
    //     bzero(buffer, sizeof(buffer));
    //     read(s, buffer, sizeof(buffer));
    //     printf("From Server : %s\n", buffer);
	return EWF_RESULT_OK;

}


ewf_result ewf_adapter_tcp_close(int socket_id)
{
    ewf_result result;
    int iResult;

    if ((socket_id < 0) || (_ADAPTER_SOCKET_POOL_SIZE <= socket_id))
    {
        EWF_LOG_ERROR("Invalid socket value.");
        return EWF_RESULT_INVALID_SOCKET;
    }

    if (_adapter_socket_pool[socket_id].used == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    _adapter_socket_pool[socket_id].used = false;

    iResult = shutdown(_adapter_socket_pool[socket_id].s, SHUT_RDWR);
    if (iResult < 0) {
        EWF_LOG_ERROR("shutdown failed with error \n");
    }

    close(_adapter_socket_pool[socket_id].s);

    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_tcp_send(int socket_id, char const* buffer, unsigned buffer_length)
{
    int iResult;

    if ((socket_id < 0) || (_ADAPTER_SOCKET_POOL_SIZE <= socket_id))
    {
        EWF_LOG_ERROR("Invalid socket value.");
        return EWF_RESULT_INVALID_SOCKET;
    }

    if (_adapter_socket_pool[socket_id].used == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    iResult = write(_adapter_socket_pool[socket_id].s, buffer, buffer_length);
    if (iResult < 0) {
        EWF_LOG_ERROR("send failed with error: %s\n",strerror(errno));

    }
    printf("Write complete,data sent:  %s\n",buffer);

    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_tcp_receive(int socket_id, char* buffer, unsigned* buffer_length, bool wait)
{
    int iResult;

    if ((socket_id < 0) || (_ADAPTER_SOCKET_POOL_SIZE <= socket_id))
    {
        EWF_LOG_ERROR("Invalid socket value.");
        return EWF_RESULT_INVALID_SOCKET;
    }

    if (_adapter_socket_pool[socket_id].used == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    iResult = recv(_adapter_socket_pool[socket_id].s, (void *) buffer, (size_t )*buffer_length, 0);
    if (iResult > 0)
    {
        *buffer_length = iResult;
    }
    else if (iResult == 0)
    {
        EWF_LOG_ERROR("Connection closed");
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }
    else
    {
        EWF_LOG_ERROR("recv failed with error\n");
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    printf("Received Data:  %s\n", buffer);
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_set_user_tcp_callback(ewf_adapter_tcp_receive_callback callback)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_udp_listen(int* socket_id, unsigned port)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_udp_connect(int* socket_id, char const* server, unsigned port)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_udp_close(int socket_id)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_udp_send(int socket_id, char const* buffer, unsigned len)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_udp_receive(int socket, char * buffer, unsigned * buffer_length, bool wait)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_set_user_udp_callback(ewf_adapter_udp_receive_callback callback)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_mqtt_connect(char const* server, unsigned port, char const* clientid, char const* username, char const* password)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_mqtt_disconnect()
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_mqtt_publish(const char* topic, unsigned len, const char* msg)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_mqtt_subscribe(const char* topic)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_mqtt_unsubscribe(const char* topic)
{
    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_set_user_mqtt_publish_callback(ewf_adapter_mqtt_publish_callback callback)
{
    return EWF_RESULT_OK;
}

/** @} *** group_adapter_bsd_socket */
