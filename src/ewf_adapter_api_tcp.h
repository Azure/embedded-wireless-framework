/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter TCP API
 ****************************************************************************/

#ifndef __ewf_adapter_tcp__h__included__
#define __ewf_adapter_tcp__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_tcp Adapter TCP API
 * @ingroup group_adapter_api
 * @brief TCP functions to listen, connect, send, receive and close sockets.
 * @{
 ****************************************************************************/

/** @brief The TCP socket structure declaration */
struct _ewf_socket_tcp;

/** @brief The TCP socket type */
typedef struct _ewf_socket_tcp ewf_socket_tcp;

/**
 * @brief A function pointer type for TCP receive callbacks
 * @param[in] buffer_ptr A pointer to a buffer with the received data
 * @param[in] buffer_length The length of the data pointed by buffer_ptr
 * @return #ewf_result success and error conditions
 */
typedef ewf_result(*ewf_adapter_tcp_receive_callback)(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);

/**
 * @brief A function pointer type for TCP disconnect callbacks
 * @return #ewf_result success and error conditions
 */
typedef ewf_result(*ewf_adapter_tcp_disconnect_callback)(ewf_socket_tcp* socket_ptr);

/** @brief The TCP socket structure definition */
struct _ewf_socket_tcp
{
    void* data_ptr;
    ewf_adapter* adapter_ptr;
    ewf_adapter_tcp_receive_callback receive_callback;
    ewf_adapter_tcp_disconnect_callback disconnect_callback;
};

#define EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr)                                 \
do {                                                                                \
    if ((socket_ptr == NULL) ||                                                     \
        (socket_ptr->adapter_ptr == NULL))                                          \
    {                                                                               \
        EWF_LOG_ERROR("The TCP socket pointer is invalid.\n");                      \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)

#define EWF_ADAPTER_TCP_SOCKET_CONTROL_SET_CONNECTION_TIMEOUT      ("!SetConnectionTimeout")

#define EWF_ADAPTER_TCP_SOCKET_QUERY_IS_CONNECTED                  ("?IsConnected")
#define EWF_ADAPTER_TCP_SOCKET_QUERY_IS_BOUND                      ("?IsBound")
#define EWF_ADAPTER_TCP_SOCKET_QUERY_USES_TLS                      ("?UsesTLS")
#define EWF_ADAPTER_TCP_SOCKET_QUERY_PEER_ADDRESSS                 ("?PeerAddress")
#define EWF_ADAPTER_TCP_SOCKET_QUERY_LOCAL_ADDRESSS                ("?LocalAddress")
#define EWF_ADAPTER_TCP_SOCKET_QUERY_SENT_BYTES                    ("?SentBytes")
#define EWF_ADAPTER_TCP_SOCKET_QUERY_RECEIVED_BYTES                ("?ReceivedBytes")

/** @brief The TCP API structure */
typedef struct _ewf_adapter_api_tcp
{
    ewf_result(*open)(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr);
    ewf_result(*close)(ewf_socket_tcp* socket_ptr);

    ewf_result(*control)(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);

    ewf_result(*set_tls_configuration)(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id);

    ewf_result(*bind)(ewf_socket_tcp* socket_ptr, uint32_t port);
    ewf_result(*listen)(ewf_socket_tcp* socket_ptr);
    ewf_result(*accept)(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr);
    ewf_result(*connect)(ewf_socket_tcp* socket_ptr, const char* server_str, uint32_t port);
    ewf_result(*shutdown)(ewf_socket_tcp* socket_ptr);
    ewf_result(*send)(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);
    ewf_result(*receive)(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length, bool wait);

} ewf_adapter_api_tcp;

/**
 * @brief Open a TCP socket
 * @param[in] adapter_ptr A pointer to the adapter
 * @param[in,out] socket_ptr A pointer to a TCP socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr);

/**
 * @brief Close a TCP socket
 * @param[in] socket_ptr A pointer to a TCP socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_close(ewf_socket_tcp* socket_ptr);

/**
 * @brief Control a TCP socket
 * This is mainly used to funnel implementation specific functionality.
 * @param[in] socket_ptr a pointer to a TCP socket
 * @param[in] control_str a pointer to NULL terminated string with the control command to issue
 * @param[in] buffer_ptr a pointer to a buffer with additional data for the command
 * @param[in] buffer_length_ptr the length of the buffer pointer by buffer_ptr on call, the size used on return
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);

/**
 * @brief Set the TLS context for the socket
 * @param[in] socket_ptr A pointer to a TCP socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id);

/**
 * @brief Binds a TCP socket to a port
 * @param[in] socket_ptr A pointer to a TCP socket
 * @param[in] port the port number to bind to
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port);

/**
 * @brief Listens to incomming connections on a socket
 * @param[in] socket_ptr A pointer to a TCP socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_listen(ewf_socket_tcp* socket_ptr);

/**
 * @brief Accept a new connection on a listening TCP socket
 * @param[in] socket_ptr A pointer to a TCP socket
 * @param[in,out] socket a pointer to a variable that will hold the new TCP socket
 * from the accepted connection
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr);

/**
 * @brief Connect a TCP socket to a server
 * @param[in] socket_ptr A pointer to a TCP socket
 * @param[in] server the address or name of the server to connect to
 * @param[in] port the port number to connect to
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_connect(ewf_socket_tcp* socket_ptr, const char* server_str, uint32_t port);

/**
 * @brief Shutdown a TCP socket
 * @param[in] socket_ptr A pointer to a TCP socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_shutdown(ewf_socket_tcp* socket_ptr);

/**
 * @brief Send data over a TCP socket
 * @param[in] socket_ptr A pointer to a TCP socket
 * @param[in] buffer a pointer to the data to be sent
 * @param[in] buffer_length the number of bytes to be sent
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);

/**
 * @brief Receive data over a TCP socket
 * @param[in] socket_ptr A pointer to a TCP socket
 * @param[in,out] buffer a pointer to the buffer that is going to receive the data
 * @param[in,out] buffer_length a pointer to an unsigned holds the size of the buffer on entry and the buffer_length and on return
 * @param[in] wait a boolean indicating if the function should wait until data is available, true wait, false return immediately
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t * buffer_length, bool wait);

/**
 * @brief Register a user TCP receive callback function
 * @param[in] socket_ptr A pointer to a TCP socket
 * @param[in] callback the function pointer to the user callback
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_receive_callback_set(ewf_socket_tcp* socket_ptr, ewf_adapter_tcp_receive_callback callback);

/**
 * @brief Register a user TCP disconnect callback function
 * @param[in] socket_ptr A pointer to a TCP socket
 * @param[in] callback the function pointer to the user callback
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_tcp_disconnect_callback_set(ewf_socket_tcp* socket_ptr, ewf_adapter_tcp_disconnect_callback callback);

/************************************************************************//**
 * @} *** group_adapter_tcp
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_tcp__h__included__ */
