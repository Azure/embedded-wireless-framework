/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework NetX-Duo test common code
 ****************************************************************************/

#ifndef __ewf_example_netx_duo_test__h__included__
#define __ewf_example_netx_duo_test__h__included__

#include "ewf.h"
#include "ewf_example.config.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_example_netx_duo_test EWF adapter API test.
 * @brief The definitions and functions to test EWF adapters API implementations.
 * @{
 ****************************************************************************/

/**
 * @defgroup group_example_netx_duo_test_configuration The EWF adapter API test configuration
 * @brief EWF adapter API test configuration settings
 *
 * Every definition can be overriden by the user.
 * Defining a symbol before including this file will skip the definition here.
 * Symbols not defined prior to these definitions will be defined with default values.
 * The default location for use definitions overriding these defaults is the file ewf_example.config.h
 *
 * @{
 */

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_TEST_ENABLED
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_TEST_ENABLED                 1
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_ECHO_TEST_ENABLED
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_ECHO_TEST_ENABLED                 1
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_CLIENT_SERVER_TEST_ENABLED
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_CLIENT_SERVER_TEST_ENABLED        1
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_SMALL_MESSAGE_COMPARE
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_SMALL_MESSAGE_COMPARE             0
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_LARGE_MESSAGE_COMPARE
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_LARGE_MESSAGE_COMPARE             0
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_RECV_SLEEP_TICKS
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_RECV_SLEEP_TICKS                  0
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_LOOP_SLEEP_TICKS
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_LOOP_SLEEP_TICKS                  0
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_SERVER_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_SERVER_STR                   "www.microsoft.com"
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_SERVER_PORT
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_SERVER_PORT                  80
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_REQUEST_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_HTTP_REQUEST_STR                  "GET / HTTP/1.1\r\nHost:www.microsoft.com\r\n\r\n"
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_LOCAL_SERVER_PORT
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_LOCAL_SERVER_PORT                 4080
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_ECHO_SERVER_HOSTNAME_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_ECHO_SERVER_HOSTNAME_STR          "andrejm-ewf-socat-tcp.westus.azurecontainer.io"
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_ECHO_SERVER_PORT
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_ECHO_SERVER_PORT                  4000
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_ITERATIONS
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_ITERATIONS                        32
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_MESSAGE_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_MESSAGE_STR                       \
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_TCP_LARGE_MESSAGE_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_TCP_LARGE_MESSAGE_STR                 \
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

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_DNS_TEST_ENABLED
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_DNS_TEST_ENABLED                  1
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_TEST_ENABLED
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_TEST_ENABLED                 1
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_CLIENT_SERVER_TEST_ENABLED
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_CLIENT_SERVER_TEST_ENABLED        1
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_RECV_SLEEP_TICKS
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_RECV_SLEEP_TICKS                  0
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_LOOP_SLEEP_TICKS
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_LOOP_SLEEP_TICKS                  0
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_HOSTNAME_STR
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_HOSTNAME_STR          "andrejm-ewf-socat-udp.westus.azurecontainer.io"
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_PORT
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ECHO_SERVER_PORT                  5000
#endif

#ifndef EWF_EXAMPLE_NETX_DUO_TEST_UDP_ITERATIONS
#define EWF_EXAMPLE_NETX_DUO_TEST_UDP_ITERATIONS                        32
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

/** @} *** group_example_netx_duo_test_configuration */

/**
 * @defgroup group_example_netx_duo_test_functions The EWF NetX-Duo test functions
 * @brief EWF NetX-Duo test functions
 * @details
 * You can call all test by calling the function ewf_example_netx_duo_test
 * The ewf_example_netx_duo_test function will call all other functions,
 * but it will skip functions that are disabled by the configuration symbols above.
 * You can call specific tests instead of the main entry points in your test code if that is more convenient.
 * @{
 */

/**
 * @brief The NetX-Duo test entry point, it calls the entry points to test each API
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_example_netx_duo_test(ewf_adapter* adapter_ptr);

/**
 * @brief The NetX-Duo TCP API test, issues an HTTP query using the NetX-Duo TCP API
 * @param ip_ptr a pointer to the NX_IP control structure used for the test
 * @return the EWF_RESULT code
 */
ewf_result ewf_example_test_netx_duo_http(NX_IP* ip_ptr);

/**
 * @brief The NetX-Duo TCP API test, uses a TCP ECHO server to bounce TCP packets off.
 * @param ip_ptr a pointer to the NX_IP control structure used for the test
 * @return the EWF_RESULT code
 */
ewf_result ewf_example_test_netx_duo_tcp_echo(NX_IP* ip_ptr);

/**
 * @brief The NetX-Duo UDP API test, issues a DNS query using the NetX-Duo DNS API
 * @param ip_ptr a pointer to the NX_IP control structure used for the test
 * @return the EWF_RESULT code
 */
ewf_result ewf_example_test_netx_duo_dns(NX_IP* ip_ptr);

/**
 * @brief The NetX-Duo UDP API test, uses an UDP ECHO server to bounce UDP packets off.
 * @param ip_ptr a pointer to the NX_IP control structure used for the test
 * @return the EWF_RESULT code
 */
ewf_result ewf_example_test_netx_duo_udp_echo(NX_IP* ip_ptr);

/** @} *** group_example_netx_duo_test_functions */

/************************************************************************//**
 * @} *** group_example_netx_duo_test
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_netx_duo_test__h__included__ */
