/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter driver test common code
 ****************************************************************************/

#ifndef __ewf_adapter_test__h__included__
#define __ewf_adapter_test__h__included__

#include "ewf.h"
#include "ewf_example.config.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_example_adapter_test EWF adapter API test.
 * @brief The definitions and functions to test EWF adapters API implementations.
 * @{
 ****************************************************************************/

/**
 * @defgroup group_example_adapter_test_configuration The EWF adapter API test configuration
 * @brief EWF adapter API test configuration settings
 * @description Every definition can be overriden by the user.
 * Defining a symbol before including this file will skip the definition here.
 * Symbols not defined prior to these definitions will be defined with default values.
 * The default location for use definitions overriding these defaults is the file ewf_example.config.h
 * @{
 */

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
#define EWF_ADAPTER_TEST_TCP_LOCAL_SERVER_PORT                  4080
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
#define EWF_ADAPTER_TEST_UDP_LOCAL_SERVER_PORT                  5080
#endif

#ifndef EWF_ADAPTER_TEST_UDP_ECHO_SERVER_HOSTNAME_STR
#define EWF_ADAPTER_TEST_UDP_ECHO_SERVER_HOSTNAME_STR           "example-test-ewf-socat-udp-echo.westus.azurecontainer.io"
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

/** @} *** group_example_adapter_test_configuration */

/**
 * @defgroup group_example_adapter_test_functions The EWF adapter API test functions
 * @brief EWF adapter API test functions
 * @description You can call all test by calling the function ewf_adapter_test
 * The ewf_adapter_test function will call all other functions, 
 * but it will skip functions that are disabled by the configuration symbols above.
 * You can call specific tests instead of the main entry points in your test code if that is more convenient.
 * @{
 */

/**
 * @brief The adapter test entry point, it calls the entry points to test each API
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_adapter_test(ewf_adapter* adapter_ptr);

/**
 * @brief The TCP API test entry point, it calls other TCP tests
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_adapter_test_api_tcp(ewf_adapter* adapter_ptr);

/**
 * @brief The TCP API test, issues an HTTP query usint the TCP API
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_adapter_test_api_tcp_http(ewf_adapter* adapter_ptr);

/**
 * @brief The TCP API test, uses an TCP ECHO server to bounce TCP packets off.
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_adapter_test_api_tcp_echo(ewf_adapter* adapter_ptr);

/**
 * @brief The TCP API test, creates client and server sockets in the adapter and sends TCP packets between them.
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_adapter_test_api_tcp_client_server(ewf_adapter* adapter_ptr);

/**
 * @brief The UDP API test entry point, it calls other UDP tests
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_adapter_test_api_udp(ewf_adapter* adapter_ptr);

/**
 * @brief The UDP API test, uses an UDP ECHO server to bounce UDP packets off.
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_adapter_test_api_udp_echo(ewf_adapter* adapter_ptr);

/**
 * @brief The UDP API test, creates client and server sockets in the adapter and sends UDP packets between them.
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_adapter_test_api_udp_client_server(ewf_adapter* adapter_ptr);

/**
 * @brief The MQTT API test entry point, it calls other MQTT tests
 * @param adapter_ptr a pointer to the adapter control structure for the adapter to the tested
 * @return the EWF_RESULT code
 */
ewf_result ewf_adapter_test_api_mqtt(ewf_adapter* adapter_ptr);

/** @} *** group_example_adapter_test_functions */

/************************************************************************//**
 * @} *** group_example_configuration
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_test__h__included__ */
