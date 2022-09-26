/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter UDP API
 ****************************************************************************/

#ifndef __ewf_adapter_udp__h__included__
#define __ewf_adapter_udp__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_udp Adapter UDP API
 * @ingroup group_adapter_api
 * @brief UDP functions to bind, connect, send, receive and close sockets.
 * @{
 ****************************************************************************/

/** @brief The UDP socket structure declaration */
struct _ewf_socket_udp;

/** @brief The UDP socket type */
typedef struct _ewf_socket_udp ewf_socket_udp;

/**
 * @brief A function pointer type for TCP receive callbacks
 * @param[in] adapter_ptr a pointer to an adapter structure
 * @return #ewf_result success and error conditions
 */
typedef ewf_result(*ewf_adapter_udp_receive_callback)(ewf_socket_udp* socket_ptr, const char* server, uint32_t port, const char* buffer, uint32_t length);

/** @brief The UDP socket structure definition */
struct _ewf_socket_udp
{
    void* data_ptr;
    ewf_adapter* adapter_ptr;
    ewf_adapter_udp_receive_callback receive_callback;
};

#define EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr)                                 \
do {                                                                                \
    if ((socket_ptr == NULL) ||                                                     \
        (socket_ptr->adapter_ptr == NULL))                                          \
    {                                                                               \
        EWF_LOG_ERROR("The UDP socket pointer is invalid.\n");                      \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)

#define EWF_ADAPTER_UDP_SOCKET_QUERY_IS_BOUND                      ("?IsBound")
#define EWF_ADAPTER_UDP_SOCKET_QUERY_USES_TLS                      ("?UsesTLS")
#define EWF_ADAPTER_UDP_SOCKET_QUERY_SENT_BYTES                    ("?SentBytes")
#define EWF_ADAPTER_UDP_SOCKET_QUERY_RECEIVED_BYTES                ("?ReceivedBytes")

/** @brief The UDP API type */
typedef struct _ewf_adapter_api_udp
{
    ewf_result(*open)(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr);
    ewf_result(*close)(ewf_socket_udp* socket_ptr);

    ewf_result(*control)(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);

    ewf_result(*set_dtls_configuration)(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id);

    ewf_result(*bind)(ewf_socket_udp* socket_ptr, uint32_t local_port);
    ewf_result(*shutdown)(ewf_socket_udp* socket_ptr);
    ewf_result(*send_to)(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length);
    ewf_result(*receive_from)(ewf_socket_udp* socket_ptr, char* remote_address, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

} ewf_adapter_api_udp;

/**
 * @brief Open a UDP socket
 * @param[in] adapter_ptr a pointer to an adapter structure
 * @param[in] socket_ptr a pointer to an UDP socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr);

/**
 * @brief Close a UDP socket
 * @param[in] socket_ptr a pointer to an UDP socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_udp_close(ewf_socket_udp* socket_ptr);

/**
 * @brief Control an UDP socket
 * This is mainly used to funnel implementation specific functionality.
 * @param[in] socket_ptr a pointer to a UDP socket
 * @param[in] control_str a pointer to NULL terminated string with the control string to execute
 * @param[in] buffer_ptr a pointer to a buffer with additional data for the command
 * @param[in] buffer_length_ptr the length of the buffer pointer by buffer_ptr on call, the size used on return
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr);

/**
 * @brief Set the DTLS configuration for the socket
 * @param[in] socket_ptr a pointer to an UDP socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id);

/**
 * @brief Binds an UDP socket to a local port
 * @param[in] socket_ptr a pointer to an UDP socket
 * @param[in] local_port the port number to bind to
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_udp_bind(ewf_socket_udp* socket_ptr, uint32_t local_port);

/**
 * @brief Shutdown a UDP socket
 * @param[in] socket_ptr A pointer to a UDP socket
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_udp_shutdown(ewf_socket_udp* socket_ptr);

/**
 * @brief Send data over a UDP socket
 * @param[in] socket_ptr a pointer to an UDP socket
 * @param[in] remote_address_str a pointer to a NULL terminated string with the address to send to
 * @param[in] remote_port the remote port number to send to
 * @param[in] buffer_ptr a pointer to the data to be sent
 * @param[in] buffer_length the number of bytes to be sent
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length);

/**
 * @brief Receive data over a UDP socket
 * @param[in] socket_ptr a pointer to an UDP socket
 * @param[in,out] remote_address the address or name of the remote host from which the data was received, or NULL if not needed
 * @param[in,out] remote_address_length_ptr the buffer length on input, the size of the remote string on output, or NULL if not needed
 * @param[in,out] remote_port_ptr a pointer to a variable to hold the port number from which the data was received, or NULL if not needed
 * @param[in,out] buffer_ptr a pointer to the buffer that is going to receive the data
 * @param[in,out] buffer_length_ptr a pointer to an unsigned holds the size of the buffer on entry and the buffer_length and on return
 * @param[in] wait a boolean indicating if the function should wait until data is available, true wait, false return immediately
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

/**
 * @brief Register a user UDP receive callback function
 * @param[in] socket_ptr a pointer to an UDP socket
 * @param[in] callback the function pointer to the user callback
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_adapter_udp_receive_callback_set(ewf_socket_udp* socket_ptr, ewf_adapter_udp_receive_callback callback);

/************************************************************************//**
 * @} *** group_adapter_udp
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_udp__h__included__ */
