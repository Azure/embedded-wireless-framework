/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter driver test common code
 ****************************************************************************/

#include "ewf_adapter.h"
#include "ewf_adapter_test.h"

/**
 * @brief TCP API test
 */
ewf_result ewf_adapter_test_api_tcp(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    const char http_server [] =  "www.microsoft.com";
    uint32_t http_host_port = 80;
    const char http_message [] = "GET / HTTP/1.1\r\nHost:www.microsoft.com\r\n\r\n";
    uint32_t http_message_length = sizeof(http_message)-1;
    static uint8_t buffer[2048];
    uint32_t buffer_length = sizeof(buffer);

    ewf_result result = EWF_RESULT_OK;

    ewf_socket_tcp socket_tcp = { 0 };

    if (ewf_result_failed(result = ewf_adapter_tcp_open(adapter_ptr, &socket_tcp))) return result;

    if (ewf_result_failed(result = ewf_adapter_tcp_connect(&socket_tcp, http_server, http_host_port))) return result;

    if (ewf_result_failed(result = ewf_adapter_tcp_send(&socket_tcp, (const uint8_t*) http_message, http_message_length))) return result;

    if (ewf_result_failed(result = ewf_adapter_tcp_receive(&socket_tcp, buffer, &buffer_length, true))) return result;

    if (ewf_result_failed(result = ewf_adapter_tcp_shutdown(&socket_tcp))) return result;

    if (ewf_result_failed(result = ewf_adapter_tcp_close(&socket_tcp))) return result;

    return result;
}

/**
 * @brief UDP API test
 */
ewf_result ewf_adapter_test_api_udp(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    ewf_socket_udp socket_udp = { 0 };

    if (ewf_result_failed(result = ewf_adapter_udp_open(adapter_ptr, &socket_udp))) return result;

    if (ewf_result_failed(result = ewf_adapter_udp_close(&socket_udp))) return result;

    return result;
}

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
