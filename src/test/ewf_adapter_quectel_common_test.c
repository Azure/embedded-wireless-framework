/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel common adapter driver test
 ****************************************************************************/

#include "ewf_adapter_test.h"
#include "ewf_adapter_quectel_common.h"

ewf_result ewf_adapter_quectel_common_test(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_quectel_common_test_command_ping(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_quectel_common_test_command_dns(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_quectel_common_test_command_ntp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_quectel_common_test_command_http(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_quectel_common_test_command_ufs(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_quectel_common_test_command_tcp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_quectel_common_test_command_udp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_quectel_common_test_command_mqtt(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_quectel_common_test_api_ufs(ewf_adapter* adapter_ptr);

/**
 * @brief Run all adapter tests
 */
ewf_result ewf_adapter_quectel_common_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QICSGP=1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIDNSCFG=1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    uint32_t pdp_context = 1;

    if (ewf_result_failed(result = ewf_adapter_quectel_common_context_activate(adapter_ptr, pdp_context)))
    {
        EWF_LOG("[WARNING][Failed to activate the context.]\n");
    }

    // Adapter tests - ping
    result = ewf_adapter_quectel_common_test_command_ping(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter ping test: ewf_result %d.\n", result);
    }

    // Adapter tests - DNS
    result = ewf_adapter_quectel_common_test_command_dns(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter DNS test: ewf_result %d.\n", result);
    }

    // Adapter tests - NTP
    result = ewf_adapter_quectel_common_test_command_ntp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter NTP test: ewf_result %d.\n", result);
    }

#if 0
    // Adapter tests - HTTP
    result = ewf_adapter_quectel_common_test_command_http(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter HTTP test: ewf_result %d.\n", result);
    }
#endif

    // Adapter tests - Modem - UFS
    result = ewf_adapter_quectel_common_test_api_ufs(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the modem adapter UFS test: ewf_result %d.\n", result);
    }

    // Adapter tests - TCP/HTTP
    result = ewf_adapter_test_api_tcp_http(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP/HTTP test: ewf_result %d.\n", result);
    }

#if 0 /* TODO, under development */
    // Adapter tests - TCP
    result = ewf_adapter_test_api_tcp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP test: ewf_result %d.\n", result);
    }
#endif

#if 0 /* TODO, under development */
    // Adapter tests - UDP
    result = ewf_adapter_test_api_udp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter UDP test: ewf_result %d.\n", result);
    }
#endif

#if 0 /* TODO, under development */
    // Adapter tests - MQTT
    result = ewf_adapter_test_api_mqtt(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter UDP test: ewf_result %d.\n", result);
    }
#endif

    if (ewf_result_failed(result = ewf_adapter_quectel_common_context_deactivate(adapter_ptr, pdp_context)))
    {
        EWF_LOG("Failed to deactivate the context.\n");
    }

    return EWF_RESULT_OK;
}

/**
 * @brief Quectel adapter common ping test
 */
ewf_result ewf_adapter_quectel_common_test_command_ping(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    char * response;
    uint32_t length;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QPING=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QPING=1,\"www.microsoft.com\",3,4\r"))) return result;
    while (!ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response, &length, 3)))
    {
        ewf_interface_release(interface_ptr, response);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 3);
    }

    /* All ok! */
    return EWF_RESULT_OK;
}

/**
 * @brief Quectel adapter common DNS test
 */
ewf_result ewf_adapter_quectel_common_test_command_dns(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    char * response;
    uint32_t length;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIDNSGIP=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIDNSGIP=1,\"www.microsoft.com\"\r"))) return result;
    while (!ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response, &length, 30)))
    {
        ewf_interface_release(interface_ptr, (uint8_t*)response);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 3);
    }

    return EWF_RESULT_OK;
}

/**
 * @brief Quectel adapter common NTP test
 */
ewf_result ewf_adapter_quectel_common_test_command_ntp(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    char* response_str;
    uint32_t response_length;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QNTP=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QNTP=1,\"pool.ntp.org\"\r"))) return result;
    while (!ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response_str, &response_length, 3)))
    {
        ewf_interface_release(interface_ptr, response_str);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 3);
    }

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CCLK?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    return EWF_RESULT_OK;
}

/** @brief HTTP test - flag to signal when the HTTP get response URC is received */
volatile bool ewf_adapter_quectel_common_test_command_http_http_get = false;

/** @brief HTTP test - URC callback */
ewf_result ewf_adapter_quectel_common_test_command_http_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    if (ewfl_str_starts_with((char*)buffer_ptr, "+QHTTPGET: "))
    {
        ewf_adapter_quectel_common_test_command_http_http_get = true;

        return EWF_RESULT_OK;
    }

    return EWF_RESULT_OK;
}

/** @brief HTTP test */
ewf_result ewf_adapter_quectel_common_test_command_http(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QHTTPCFG=\"contextid\",1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QHTTPCFG=\"responseheader\",1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    {
#if 1
        char url_str[] = "http://www.microsoft.com/";
#else
        char url_str[] = "http://www.sina.com.cn/";
#endif
        unsigned url_length = sizeof(url_str) - 1;
        char tokenizer_pattern_str[] = "\r\nCONNECT\r\n";
        ewf_interface_tokenizer_pattern tokenizer_pattern = {
            NULL,
            tokenizer_pattern_str ,
            sizeof(tokenizer_pattern_str)-1,
            false,
        };

        char url_length_str[4];
        const char* url_length_cstr = ewfl_unsigned_to_str(url_length, url_length_str, sizeof(url_length_str));

        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern))) return result;
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QHTTPURL=", url_length_cstr, ",80\r", NULL))) return result;
        if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_str)))
        {
            EWF_LOG_ERROR("Unexpected response.\n");
            if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;
            return EWF_RESULT_UNEXPECTED_RESPONSE;
        }
        else
        {
            if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;
            if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, url_str, "\r", NULL))) return result;
            if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
        }
    }

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QHTTPGET=80\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Set a user URC callback to wait for the HTTP GET response */
    ewf_adapter_quectel_common_test_command_http_http_get = false;
    if (ewf_result_failed(result = ewf_interface_set_user_urc_callback(interface_ptr, ewf_adapter_quectel_common_test_command_http_urc_callback))) return result;

    /* Wait until the response is recevied or a timeout is reached */
    uint32_t timeout = EWF_PLATFORM_TICKS_PER_SECOND * 60;
    while (!ewf_adapter_quectel_common_test_command_http_http_get && timeout != 0)
    {
        ewf_platform_sleep(1);
        ewf_interface_poll(interface_ptr);
        timeout--;
    }

    /* Clear the user URC callback */
    if (ewf_result_failed(result = ewf_interface_set_user_urc_callback(interface_ptr, NULL))) return result;

    /* If we reached the timeout there was no response, fail */
    if (timeout == 0)
    {
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    /* Read the responses */
    {
        char tokenizer_pattern_str[] = "\r\nCONNECT\r\n";
        ewf_interface_tokenizer_pattern tokenizer_pattern = {
            NULL,
            tokenizer_pattern_str ,
            sizeof(tokenizer_pattern_str)-1,
            false,
        };
        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern))) return result;
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QHTTPREAD=10\r"))) return result;
        if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_str)))
        {
            EWF_LOG_ERROR("Unexpected response.\n");
        }
        if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;

        /* Wait for the read response time out */
        uint32_t timeout = EWF_PLATFORM_TICKS_PER_SECOND * 10;
        while (timeout != 0)
        {
            ewf_interface_drop_all_responses(interface_ptr);
            timeout--;
            ewf_platform_sleep(1);
        }

    }

    return EWF_RESULT_OK;
}

/**
 * @brief UFS API test
 */
ewf_result ewf_adapter_quectel_common_test_api_ufs(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_list(adapter_ptr))) return result;

    return EWF_RESULT_OK;
}
