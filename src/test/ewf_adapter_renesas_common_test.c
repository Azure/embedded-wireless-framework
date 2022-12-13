/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Renesas common adapter driver test
 * @details EWF adapter common test for Renesas
 ****************************************************************************/

#include "ewf_adapter_test.h"
#include "ewf_adapter_renesas_common.h"

ewf_result ewf_adapter_renesas_common_test(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_renesas_common_test_command_ping(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_test_command_dns(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_test_command_ntp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_test_command_http(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_test_command_nvm(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_test_command_tcp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_test_command_udp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_renesas_common_test_command_mqtt(ewf_adapter* adapter_ptr);

/**
 * @brief Run all adapter tests
 */
ewf_result ewf_adapter_renesas_common_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_result result;


    // Activate the PDP context
    if (ewf_result_failed(result = ewf_adapter_modem_packet_service_activate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG_ERROR("Failed to activate the PDP context: ewf_result %d.\n", result);
        // continue despite the error
    }

    // Adapter tests - ping
    result = ewf_adapter_renesas_common_test_command_ping(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter ping test: ewf_result %d.\n", result);
    }

    // Adapter tests - DNS
    result = ewf_adapter_renesas_common_test_command_dns(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter DNS test: ewf_result %d.\n", result);
    }

    // Adapter tests - NTP
    result = ewf_adapter_renesas_common_test_command_ntp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter NTP test: ewf_result %d.\n", result);
    }

    // Adapter tests - HTTP
    result = ewf_adapter_renesas_common_test_command_http(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter HTTP test: ewf_result %d.\n", result);
    }

    // Adapter tests - TCP
    result = ewf_adapter_test_api_tcp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP test: ewf_result %d.\n", result);
    }
    // Adapter tests - UDP
    result = ewf_adapter_test_api_udp(adapter_ptr);
   // result = ewf_adapter_renesas_common_test_api_udp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter UDP test: ewf_result %d.\n", result);
    }

    // Adapter tests - NVM
    result = ewf_adapter_renesas_common_test_command_nvm(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the modem adapter NVM test: ewf_result %d.\n", result);
    }

    return EWF_RESULT_OK;
}

/**
 * @brief Ping test
 */
ewf_result ewf_adapter_renesas_common_test_command_ping(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    char *response;
    uint32_t length;

    if (ewf_result_failed (result = ewf_interface_send_command(interface_ptr, "AT+CGPADDR\r"))) return result;
    if (ewf_result_failed (result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed (result = ewf_interface_send_command(interface_ptr, "AT+PING=\"www.microsoft.com\"\r"))) return result;
    while (!ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response, &length, 500)))
    {
        ewf_interface_release(interface_ptr, response);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 1);
    }


    /* All ok! */
    return EWF_RESULT_OK;
}

/**
 * @brief DNS test
 */
ewf_result ewf_adapter_renesas_common_test_command_dns(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    char * response;
    uint32_t length;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNDNSLKUP=\"www.microsoft.com\"\r"))) return result;
    while (!ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response, &length, 500)))
    {
        ewf_interface_release(interface_ptr, (uint8_t*)response);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 1);
    }

    return EWF_RESULT_OK;
}

/**
 * @brief NTP test
 * This test will only return the time zone related configuration from the modem, 
 *  as this modem does nothave support for AT command to Synchronize time with NTP server
 */
ewf_result ewf_adapter_renesas_common_test_command_ntp(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    char* response_str;
    uint32_t response_length;

    /* Automatic timezone update */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CTZU?\r"))) return result;
    while (!ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response_str, &response_length, 100)))
    {
        ewf_interface_release(interface_ptr, response_str);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 3);
    }

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CCLK?\r"))) return result;
    while (!ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response_str, &response_length, 100)))
    {
        ewf_interface_release(interface_ptr, response_str);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 3);
    }

    return EWF_RESULT_OK;
}

volatile bool ewf_adapter_renesas_common_test_command_http_http_get = false;

/** @brief HTTP test - URC callback */
ewf_result ewf_adapter_renesas_common_test_command_http_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);
ewf_result ewf_adapter_renesas_common_test_command_http_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
	EWF_PARAMETER_NOT_USED(interface_ptr);
	EWF_PARAMETER_NOT_USED(buffer_length);
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNHTTPRING: "))
    {
        ewf_adapter_renesas_common_test_command_http_http_get = true;

        return EWF_RESULT_OK;
    }

    return EWF_RESULT_OK;
}
/**
 * @brief HTTP test
 */
ewf_result ewf_adapter_renesas_common_test_command_http(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNHTTPCFG?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    uint8_t url_str [] = "\"www.w3.org\"";
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNHTTPCFG=1,", url_str, ",80\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    ewf_adapter_renesas_common_test_command_http_http_get = false;
    if (ewf_result_failed(result = ewf_interface_set_user_urc_callback(interface_ptr, ewf_adapter_renesas_common_test_command_http_urc_callback))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNHTTPQRY=1,0,\"/Summary.html\"\r"))) return result;

    uint32_t timeout = EWF_PLATFORM_TICKS_PER_SECOND * 60;
    while (!ewf_adapter_renesas_common_test_command_http_http_get && timeout != 0)
    {
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
        timeout--;
    }

    /* Clear the user URC callback */
    if (ewf_result_failed(result = ewf_interface_set_user_urc_callback(interface_ptr, NULL))) return result;

    if (timeout == 0)
    {
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    /* Read the responses */
    {
         ewf_interface_send_commands(interface_ptr, "AT+SQNHTTPRCV=1,100\r",NULL);

         /* Wait for the read response time out */
         timeout = EWF_PLATFORM_TICKS_PER_SECOND * 10;
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
 * @brief NVM test
 */
ewf_result ewf_adapter_renesas_common_test_command_nvm(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_adapter_renesas_common_nvm_list(adapter_ptr);

    return EWF_RESULT_OK;
}
