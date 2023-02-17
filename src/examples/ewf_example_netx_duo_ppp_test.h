/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework NetX-Duo PPP test common code
 ****************************************************************************/

#ifndef __ewf_example_netx_duo_ppp_test__h__included__
#define __ewf_example_netx_duo_ppp_test__h__included__

#include "ewf.h"
#include "ewf_example.config.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_example_netx_duo_ppp_test EWF adapter API test.
 * @brief The definitions and functions to test EWF adapters API implementations.
 * @{
 ****************************************************************************/

/**
 * @defgroup group_example_netx_duo_ppp_test_configuration The EWF adapter API test configuration
 * @brief EWF adapter API test configuration settings
 *
 * Every definition can be overriden by the user.
 * Defining a symbol before including this file will skip the definition here.
 * Symbols not defined prior to these definitions will be defined with default values.
 * The default location for use definitions overriding these defaults is the file ewf_example.config.h
 *
 * @{
 */

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_SERVER_PORT
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_SERVER_PORT                  80
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_REQUEST_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_REQUEST_STR                  "GET / HTTP/1.1\r\nHost:www.microsoft.com\r\n\r\n"
#endif
/* EWF NetX Duo test - HTTP query variables */
//ULONG http_server_ip = IP_ADDRESS(23, 35, 229, 160);
//ULONG http_server_ip = IP_ADDRESS(20, 228, 124, 154);
//ULONG http_server_ip = IP_ADDRESS(92, 123, 229, 216);
ULONG http_server_ip = IP_ADDRESS(104,95,181,163);
UINT http_server_port = EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_SERVER_PORT;
char http_request[] = EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_REQUEST_STR;
ULONG http_message_length = sizeof(http_request) - 1;


#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_TEST_ENABLED
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_TEST_ENABLED                 1
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_CLIENT_SERVER_TEST_ENABLED
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_CLIENT_SERVER_TEST_ENABLED        1
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_RECV_SLEEP_TICKS
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_RECV_SLEEP_TICKS                  1
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_LOOP_SLEEP_TICKS
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_LOOP_SLEEP_TICKS                  0
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_HOSTNAME_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_HOSTNAME_STR          ""
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_PORT
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_PORT                  5000
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_ITERATIONS
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ITERATIONS                        5
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_MESSAGE_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_MESSAGE_STR                       \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_LARGE_MESSAGE_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_LARGE_MESSAGE_STR                 \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif

CHAR ewf_example_test_netx_duo_udp_echo_server_hostname[] = EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_HOSTNAME_STR;
ULONG ewf_example_test_netx_duo_udp_echo_server_ip = IP_ADDRESS(168, 61, 1, 33);
UINT ewf_example_test_netx_duo_udp_echo_server_port = EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_PORT;
CHAR ewf_example_test_netx_duo_udp_echo_message[] = EWF_EXAMPLE_NETX_DUO_TEST_UDP_LARGE_MESSAGE_STR;
UINT ewf_example_test_netx_duo_udp_echo_message_length = sizeof(ewf_example_test_netx_duo_udp_echo_message);



/************************************************************************//**
 * @} *** group_example_netx_duo_ppp_test
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_netx_duo_ppp_test__h__included__ */
