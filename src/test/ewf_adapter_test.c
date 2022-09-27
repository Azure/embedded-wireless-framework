/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter driver API test code.
 ****************************************************************************/

#include "ewf_adapter.h"
#include "ewf_adapter_test.h"
#include "ewf_lib.h"

/**
 * @brief TCP API test
 */
ewf_result ewf_adapter_test_api_tcp(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result = EWF_RESULT_OK;

#if EWF_ADAPTER_TEST_TCP_HTTP_TEST_ENABLED
    // Adapter tests - TCP/HTTP
    result = ewf_adapter_test_api_tcp_http(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP/HTTP test: ewf_result %d.\n", result);
    }
#endif /* EWF_ADAPTER_TEST_TCP_HTTP_TEST_ENABLED */

#if EWF_ADAPTER_TEST_TCP_ECHO_TEST_ENABLED
    // Adapter tests - TCP/echo
    result = ewf_adapter_test_api_tcp_echo(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP/echo test: ewf_result %d.\n", result);
    }
#endif /* EWF_ADAPTER_TEST_TCP_ECHO_TEST_ENABLED */

#if EWF_ADAPTER_TEST_TCP_CLIENT_SERVER_TEST_ENABLED
    // Adapter tests - TCP/client-server
    result = ewf_adapter_test_api_tcp_client_server(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP/client-server test: ewf_result %d.\n", result);
    }
#endif /* EWF_ADAPTER_TEST_TCP_CLIENT_SERVER_TEST_ENABLED */

    return result;
}

/**
 * @brief UDP API test
 */
ewf_result ewf_adapter_test_api_udp(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result = EWF_RESULT_OK;

#if EWF_ADAPTER_TEST_UDP_ECHO_TEST_ENABLED
    // Adapter tests - UDP/echo
    result = ewf_adapter_test_api_udp_echo(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter UDP/echo test: ewf_result %d.\n", result);
    }
#endif /* EWF_ADAPTER_TEST_UDP_ECHO_TEST_ENABLED */

#if EWF_ADAPTER_TEST_UDP_CLIENT_SERVER_TEST_ENABLED
    // Adapter tests - UDP/client-server
    result = ewf_adapter_test_api_udp_client_server(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter UDP/client-server test: ewf_result %d.\n", result);
    }
#endif /* EWF_ADAPTER_TEST_UDP_CLIENT_SERVER_TEST_ENABLED */

    return result;
}

#if EWF_ADAPTER_TEST_TCP_HTTP_TEST_ENABLED
ewf_result ewf_adapter_test_api_tcp_http(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result = EWF_RESULT_OK;

    ewf_socket_tcp socket_tcp = { 0 };

    uint32_t http_request_length = ewfl_str_length(EWF_ADAPTER_TEST_TCP_HTTP_REQUEST_STR);

    static uint8_t buffer[1500];
    uint32_t buffer_length = sizeof(buffer);

    if (ewf_result_failed(result = ewf_adapter_tcp_open(adapter_ptr, &socket_tcp))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_connect(&socket_tcp, EWF_ADAPTER_TEST_TCP_HTTP_SERVER_STR, EWF_ADAPTER_TEST_TCP_HTTP_SERVER_PORT))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_send(&socket_tcp, (const uint8_t*) EWF_ADAPTER_TEST_TCP_HTTP_REQUEST_STR, http_request_length))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_receive(&socket_tcp, buffer, &buffer_length, true))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_shutdown(&socket_tcp))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_close(&socket_tcp))) return result;

    return result;
}
#endif /* EWF_ADAPTER_TEST_TCP_HTTP_TEST_ENABLED */

#if EWF_ADAPTER_TEST_TCP_ECHO_TEST_ENABLED
ewf_result ewf_adapter_test_api_tcp_echo(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result = EWF_RESULT_OK;

    ewf_socket_tcp socket_tcp = { 0 };

    static uint8_t receive_buffer[1500];
    uint32_t receive_buffer_length;

    if (ewf_result_failed(result = ewf_adapter_tcp_open(adapter_ptr, &socket_tcp))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_connect(&socket_tcp, EWF_ADAPTER_TEST_TCP_ECHO_SERVER_HOSTNAME_STR, EWF_ADAPTER_TEST_TCP_ECHO_SERVER_PORT))) return result;
    for (int i = 0; i < EWF_ADAPTER_TEST_TCP_ITERATIONS; i++)
    {
        if (ewf_result_failed(result = ewf_adapter_tcp_send(&socket_tcp, (uint8_t*)EWF_ADAPTER_TEST_TCP_MESSAGE_STR, sizeof(EWF_ADAPTER_TEST_TCP_MESSAGE_STR)))) return result;
        receive_buffer_length = sizeof(receive_buffer);
        if (ewf_result_failed(result = ewf_adapter_tcp_receive(&socket_tcp, receive_buffer, &receive_buffer_length, true))) return result;
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * EWF_ADAPTER_TEST_TCP_LOOP_SLEEP_SECS);
        if (ewf_result_failed(result = ewf_adapter_tcp_send(&socket_tcp, (uint8_t*)EWF_ADAPTER_TEST_TCP_LARGE_MESSAGE_STR, sizeof(EWF_ADAPTER_TEST_TCP_LARGE_MESSAGE_STR)))) return result;
        receive_buffer_length = sizeof(receive_buffer);
        if (ewf_result_failed(result = ewf_adapter_tcp_receive(&socket_tcp, receive_buffer, &receive_buffer_length, true))) return result;
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * EWF_ADAPTER_TEST_TCP_LOOP_SLEEP_SECS);
    }
    if (ewf_result_failed(result = ewf_adapter_tcp_shutdown(&socket_tcp))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_close(&socket_tcp))) return result;

    return result;
}
#endif /* EWF_ADAPTER_TEST_TCP_ECHO_TEST_ENABLED */

#if EWF_ADAPTER_TEST_TCP_CLIENT_SERVER_TEST_ENABLED
ewf_result ewf_adapter_test_api_tcp_client_server(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result = EWF_RESULT_OK;

    ewf_socket_tcp socket_tcp_client = { 0 };
    ewf_socket_tcp socket_tcp_server = { 0 };
    ewf_socket_tcp socket_tcp_incomming = { 0 };

    static uint8_t receive_buffer[1500];
    uint32_t receive_buffer_length;

    uint32_t local_address;

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_address(adapter_ptr, &local_address))) return result;

    char local_address_str[16];
    sprintf(local_address_str, "%d.%d.%d.%d",
        (int)(((uint8_t*)&local_address)[3]),
        (int)(((uint8_t*)&local_address)[2]),
        (int)(((uint8_t*)&local_address)[1]),
        (int)(((uint8_t*)&local_address)[0]));

    if (ewf_result_failed(result = ewf_adapter_tcp_open(adapter_ptr, &socket_tcp_client))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_open(adapter_ptr, &socket_tcp_server))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_bind(&socket_tcp_server, EWF_ADAPTER_TEST_TCP_LOCAL_SERVER_PORT))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_listen(&socket_tcp_server))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_connect(&socket_tcp_client, local_address_str, EWF_ADAPTER_TEST_TCP_LOCAL_SERVER_PORT))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_accept(&socket_tcp_server, &socket_tcp_incomming))) return result;

    for (int i = 0; i < EWF_ADAPTER_TEST_TCP_ITERATIONS; i++)
    {
        if (ewf_result_failed(result = ewf_adapter_tcp_send(
            &socket_tcp_client,
            (uint8_t*)EWF_ADAPTER_TEST_TCP_LARGE_MESSAGE_STR, sizeof(EWF_ADAPTER_TEST_TCP_LARGE_MESSAGE_STR)))) return result;
        receive_buffer_length = sizeof(receive_buffer);
        if (ewf_result_failed(result = ewf_adapter_tcp_receive(
            &socket_tcp_incomming,
            receive_buffer, &receive_buffer_length,
            true))) return result;
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * EWF_ADAPTER_TEST_TCP_LOOP_SLEEP_SECS);
    }
    if (ewf_result_failed(result = ewf_adapter_tcp_close(&socket_tcp_server))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_close(&socket_tcp_client))) return result;
    if (ewf_result_failed(result = ewf_adapter_tcp_close(&socket_tcp_incomming))) return result;

    return result;
}
#endif /* EWF_ADAPTER_TEST_TCP_CLIENT_SERVER_TEST_ENABLED */

#if EWF_ADAPTER_TEST_UDP_ECHO_TEST_ENABLED
ewf_result ewf_adapter_test_api_udp_echo(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result = EWF_RESULT_OK;

    ewf_socket_udp socket_udp = { 0 };

    static char remote_buffer_str[1024];
    uint32_t remote_bufferewfl_str_length;
    uint32_t remote_port = 0;

    static char receive_buffer[1500];
    uint32_t receive_buffer_length;

    if (ewf_result_failed(result = ewf_adapter_udp_open(adapter_ptr, &socket_udp))) return result;
    for (int i = 0; i < EWF_ADAPTER_TEST_UDP_ITERATIONS; i++)
    {
        if (ewf_result_failed(result = ewf_adapter_udp_send_to(
            &socket_udp,
            EWF_ADAPTER_TEST_UDP_ECHO_SERVER_HOSTNAME_STR, EWF_ADAPTER_TEST_UDP_ECHO_SERVER_PORT,
            (uint8_t*)EWF_ADAPTER_TEST_UDP_MESSAGE_STR, sizeof(EWF_ADAPTER_TEST_UDP_MESSAGE_STR)))) return result;
        receive_buffer_length = sizeof(receive_buffer);
        if (ewf_result_failed(result = ewf_adapter_udp_receive_from(
            &socket_udp,
            remote_buffer_str, &remote_bufferewfl_str_length, &remote_port,
            receive_buffer, &receive_buffer_length,
            true))) return result;
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * EWF_ADAPTER_TEST_UDP_LOOP_SLEEP_SECS);
        if (ewf_result_failed(result = ewf_adapter_udp_send_to(
            &socket_udp,
            EWF_ADAPTER_TEST_UDP_ECHO_SERVER_HOSTNAME_STR, EWF_ADAPTER_TEST_UDP_ECHO_SERVER_PORT,
            (uint8_t*)EWF_ADAPTER_TEST_UDP_LARGE_MESSAGE_STR, sizeof(EWF_ADAPTER_TEST_UDP_LARGE_MESSAGE_STR)))) return result;
        receive_buffer_length = sizeof(receive_buffer);
        if (ewf_result_failed(result = ewf_adapter_udp_receive_from(
            &socket_udp,
            remote_buffer_str, &remote_bufferewfl_str_length, &remote_port,
            receive_buffer, &receive_buffer_length,
            true))) return result;
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * EWF_ADAPTER_TEST_UDP_LOOP_SLEEP_SECS);
    }
    if (ewf_result_failed(result = ewf_adapter_udp_close(&socket_udp))) return result;

    return result;
}
#endif /* EWF_ADAPTER_TEST_UDP_ECHO_TEST_ENABLED */

#if EWF_ADAPTER_TEST_UDP_CLIENT_SERVER_TEST_ENABLED
ewf_result ewf_adapter_test_api_udp_client_server(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result = EWF_RESULT_OK;

    ewf_socket_udp socket_udp_client = { 0 };
    ewf_socket_udp socket_udp_server = { 0 };

    static char remote_buffer_str[1024];
    uint32_t remote_buffer_str_length;
    uint32_t remote_port = 0;

    static char receive_buffer[1500];
    uint32_t receive_buffer_length;

    uint32_t local_address;

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_address(adapter_ptr, &local_address))) return result;

    char local_address_str[16];
    sprintf(local_address_str, "%d.%d.%d.%d",
        (int)(((uint8_t*)&local_address)[3]),
        (int)(((uint8_t*)&local_address)[2]),
        (int)(((uint8_t*)&local_address)[1]),
        (int)(((uint8_t*)&local_address)[0]));

    if (ewf_result_failed(result = ewf_adapter_udp_open(adapter_ptr, &socket_udp_client))) return result;
    if (ewf_result_failed(result = ewf_adapter_udp_open(adapter_ptr, &socket_udp_server))) return result;
    if (ewf_result_failed(result = ewf_adapter_udp_bind(&socket_udp_server, EWF_ADAPTER_TEST_UDP_LOCAL_SERVER_PORT))) return result;
    for (int i = 0; i < EWF_ADAPTER_TEST_UDP_ITERATIONS; i++)
    {
        if (ewf_result_failed(result = ewf_adapter_udp_send_to(
            &socket_udp_client,
            local_address_str, EWF_ADAPTER_TEST_UDP_LOCAL_SERVER_PORT,
            (uint8_t*)EWF_ADAPTER_TEST_UDP_LARGE_MESSAGE_STR, sizeof(EWF_ADAPTER_TEST_UDP_LARGE_MESSAGE_STR)))) return result;
        receive_buffer_length = sizeof(receive_buffer);
        if (ewf_result_failed(result = ewf_adapter_udp_receive_from(
            &socket_udp_server,
            remote_buffer_str, &remote_buffer_str_length, &remote_port,
            receive_buffer, &receive_buffer_length,
            true))) return result;
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * EWF_ADAPTER_TEST_UDP_LOOP_SLEEP_SECS);
    }
    if (ewf_result_failed(result = ewf_adapter_udp_close(&socket_udp_server))) return result;
    if (ewf_result_failed(result = ewf_adapter_udp_close(&socket_udp_client))) return result;

    return result;
}
#endif /* EWF_ADAPTER_TEST_UDP_CLIENT_SERVER_TEST_ENABLED */

/**
 * @brief MQTT API test
 */
ewf_result ewf_adapter_test_api_mqtt(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    return result;
}
