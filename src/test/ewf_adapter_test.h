/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter driver test common code
 ****************************************************************************/

#ifndef __ewf_adapter_test__h__included__
#define __ewf_adapter_test__h__included__

#ifdef __cplusplus
extern "C" {
#endif

#include "ewf.h"

#ifndef EWF_ADAPTER_TEST_TCP_HTTP_TEST_ENABLED
#define EWF_ADAPTER_TEST_TCP_HTTP_TEST_ENABLED                  1
#endif

#ifndef EWF_ADAPTER_TEST_TCP_ECHO_TEST_ENABLED
#define EWF_ADAPTER_TEST_TCP_ECHO_TEST_ENABLED                  1
#endif

#ifndef EWF_ADAPTER_TEST_TCP_CLIENT_SERVER_TEST_ENABLED
#define EWF_ADAPTER_TEST_TCP_CLIENT_SERVER_TEST_ENABLED         1
#endif

#ifndef EWF_ADAPTER_TEST_UDP_ECHO_TEST_ENABLED
#define EWF_ADAPTER_TEST_UDP_ECHO_TEST_ENABLED                  1
#endif

#ifndef EWF_ADAPTER_TEST_UDP_CLIENT_SERVER_TEST_ENABLED
#define EWF_ADAPTER_TEST_UDP_CLIENT_SERVER_TEST_ENABLED         1
#endif

#ifndef EWF_ADAPTER_TEST_TCP_LOOP_SLEEP_SECS
#define EWF_ADAPTER_TEST_TCP_LOOP_SLEEP_SECS                    0
#endif

#ifndef EWF_ADAPTER_TEST_TCP_HTTP_SERVER_STR
#define EWF_ADAPTER_TEST_TCP_HTTP_SERVER_STR                    "www.microsoft.com"
#endif

#ifndef EWF_ADAPTER_TEST_TCP_HTTP_SERVER_PORT
#define EWF_ADAPTER_TEST_TCP_HTTP_SERVER_PORT                   80
#endif

#ifndef EWF_ADAPTER_TEST_TCP_HTTP_REQUEST_STR
#define EWF_ADAPTER_TEST_TCP_HTTP_REQUEST_STR                   "GET / HTTP/1.1\r\nHost:www.microsoft.com\r\n\r\n"
#endif

#ifndef EWF_ADAPTER_TEST_TCP_LOCAL_SERVER_PORT
#define EWF_ADAPTER_TEST_TCP_LOCAL_SERVER_PORT                  3080
#endif

#ifndef EWF_ADAPTER_TEST_TCP_ECHO_SERVER_HOSTNAME_STR
#define EWF_ADAPTER_TEST_TCP_ECHO_SERVER_HOSTNAME_STR           ""
#endif

#ifndef EWF_ADAPTER_TEST_TCP_ECHO_SERVER_PORT
#define EWF_ADAPTER_TEST_TCP_ECHO_SERVER_PORT                   4000
#endif

#ifndef EWF_ADAPTER_TEST_TCP_ITERATIONS
#define EWF_ADAPTER_TEST_TCP_ITERATIONS                         32
#endif

#ifndef EWF_ADAPTER_TEST_TCP_MESSAGE_STR
#define EWF_ADAPTER_TEST_TCP_MESSAGE_STR                                \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif

#ifndef EWF_ADAPTER_TEST_TCP_LARGE_MESSAGE_STR
#define EWF_ADAPTER_TEST_TCP_LARGE_MESSAGE_STR                          \
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
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"    \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif

#ifndef EWF_ADAPTER_TEST_UDP_LOOP_SLEEP_SECS
#define EWF_ADAPTER_TEST_UDP_LOOP_SLEEP_SECS                    0
#endif

#ifndef EWF_ADAPTER_TEST_UDP_LOCAL_SERVER_PORT
#define EWF_ADAPTER_TEST_UDP_LOCAL_SERVER_PORT                  3080
#endif

#ifndef EWF_ADAPTER_TEST_UDP_ECHO_SERVER_HOSTNAME_STR
#define EWF_ADAPTER_TEST_UDP_ECHO_SERVER_HOSTNAME_STR           "andrejm-ewf-socat-udp.westus.azurecontainer.io"
#endif

#ifndef EWF_ADAPTER_TEST_UDP_ECHO_SERVER_PORT
#define EWF_ADAPTER_TEST_UDP_ECHO_SERVER_PORT                   5000
#endif

#ifndef EWF_ADAPTER_TEST_UDP_ITERATIONS
#define EWF_ADAPTER_TEST_UDP_ITERATIONS                         32
#endif

#ifndef EWF_ADAPTER_TEST_UDP_MESSAGE_STR
#define EWF_ADAPTER_TEST_UDP_MESSAGE_STR                                \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif

#ifndef EWF_ADAPTER_TEST_UDP_LARGE_MESSAGE_STR
#define EWF_ADAPTER_TEST_UDP_LARGE_MESSAGE_STR                          \
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

ewf_result ewf_adapter_test(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_test_api_tcp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_test_api_tcp_http(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_test_api_tcp_echo(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_test_api_tcp_client_server(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_test_api_udp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_test_api_udp_echo(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_test_api_udp_client_server(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_test_api_mqtt(ewf_adapter* adapter_ptr);

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_test__h__included__ */
