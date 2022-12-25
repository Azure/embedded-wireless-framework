/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Thales common adapter driver test
 ****************************************************************************/

#include "ewf_adapter_test.h"
#include "ewf_adapter_thales_common.h"

ewf_result ewf_adapter_thales_common_test(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_thales_common_test_command_ping(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_thales_common_test_command_dns(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_thales_common_test_command_ntp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_thales_common_test_command_http(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_thales_common_test_command_ffs(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_thales_common_test_command_tcp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_thales_common_test_command_udp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_thales_common_test_command_mqtt(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_thales_common_test_api_ffs(ewf_adapter* adapter_ptr);

/**
 * @brief Run all adapter tests
 */
ewf_result ewf_adapter_thales_common_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGDCONT=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGDCONT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGATT=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGATT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGACT=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGACT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SWWAN=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SWWAN?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISS=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISS?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SICS=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SICS?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SICA=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SICA?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SIPS=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISX=?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /*
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGATT=1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    */

    if (ewf_result_failed(result = ewf_adapter_thales_common_context_activate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG("[WARNING][Failed to activate the context.]\n");
    }

    // Adapter tests - ping
    result = ewf_adapter_thales_common_test_command_ping(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter ping test: ewf_result %d.\n", result);
    }

    // Adapter tests - DNS
    result = ewf_adapter_thales_common_test_command_dns(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter DNS test: ewf_result %d.\n", result);
    }

    // Adapter tests - NTP
    result = ewf_adapter_thales_common_test_command_ntp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter NTP test: ewf_result %d.\n", result);
    }

#if 0
    // Adapter tests - HTTP
    result = ewf_adapter_thales_common_test_command_http(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter HTTP test: ewf_result %d.\n", result);
    }
#endif

    // Adapter tests - Modem - FFS
    result = ewf_adapter_thales_common_test_api_ffs(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the modem adapter FFS test: ewf_result %d.\n", result);
    }

    // Adapter tests
    result = ewf_adapter_test(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter common tests: ewf_result %d.\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_thales_common_context_deactivate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG("Failed to deactivate the context.\n");
    }

    return EWF_RESULT_OK;
}

/**
 * @brief Thales adapter common ping test
 */
ewf_result ewf_adapter_thales_common_test_command_ping(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;
    char * response_ptr;
    uint32_t length;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISX=Ping,1,\"www.microsoft.com\",5,5000\r"))) return result;
    do {
        response_ptr = NULL;
        result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response_ptr, &length, 3);
        if (response_ptr) ewf_interface_release(interface_ptr, response_ptr);
    } while (result == EWF_RESULT_EMPTY_QUEUE);

    /* All ok! */
    return EWF_RESULT_OK;
}

/**
 * @brief Thales adapter common DNS test
 */
ewf_result ewf_adapter_thales_common_test_command_dns(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;
    char * response_ptr = NULL;
    uint32_t length = 0;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISX=HostByName,1,\"www.microsoft.com\"\r"))) return result;
    while (!ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response_ptr, &length, 30)))
    {
        ewf_interface_release(interface_ptr, (uint8_t*)response_ptr);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 1);
    }

    return EWF_RESULT_OK;
}

/**
 * @brief Thales adapter common NTP test
 */
ewf_result ewf_adapter_thales_common_test_command_ntp(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;
    char* response_ptr = NULL;
    uint32_t response_length = 0;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISX=Ntp,1,\"pool.ntp.org\"\r"))) return result;
    while (!ewf_result_failed(result = ewf_interface_receive_response(interface_ptr, (uint8_t**)&response_ptr, &response_length, 3)))
    {
        ewf_interface_release(interface_ptr, response_ptr);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 3);
    }

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CCLK?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    return EWF_RESULT_OK;
}

/** @brief HTTP test - flag to signal when the HTTP get response URC is received */
volatile bool ewf_adapter_thales_common_test_command_http_http_get = false;

/** @brief HTTP test - URC callback */
ewf_result ewf_adapter_thales_common_test_command_http_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    if (ewfl_str_starts_with((char*)buffer_ptr, "^SIS: 4,1"))
    {
        ewf_adapter_thales_common_test_command_http_http_get = true;

        return EWF_RESULT_OK;
    }

    return EWF_RESULT_OK;
}

/** @brief HTTP test */
ewf_result ewf_adapter_thales_common_test_command_http(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Start by closing the HTTP service, in case it is left open from a previous run */
    {
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISC=4\r"))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    }

    /* Configure the connection */
    {
        /* Select service type HTTP */
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISS=4,srvType,\"Http\"\r"))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

        /* Select connection profile 1 */
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISS=4,conId,\"1\"\r"))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

        char url_str[] = "http://www.microsoft.com/";
        unsigned url_length = sizeof(url_str) - 1;

        /* Specify access to the URL */
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT^SISS=4,address,\"", url_str, "\"\r", NULL))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

        /* Select command type download */
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISS=4,cmd,\"get\"\r"))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    }

    /* Open the service and wait for a connection */
    {
        /* Set a user URC callback to wait for the HTTP ready response */
        ewf_adapter_thales_common_test_command_http_http_get = false;
        if (ewf_result_failed(result = ewf_interface_set_user_urc_callback(interface_ptr, ewf_adapter_thales_common_test_command_http_urc_callback))) return result;

        /* Open the service. */
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISO=4\r"))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

        uint32_t timeout = EWF_PLATFORM_TICKS_PER_SECOND * 10;

        /* Wait until the response is recevied or a timeout is reached */
        while (!ewf_adapter_thales_common_test_command_http_http_get && timeout != 0)
        {
            ewf_interface_poll(interface_ptr);
            timeout--;
            ewf_platform_sleep(1);
        }

        /* If we reached the timeout there was no response, fail */
        if (timeout == 0)
        {
            return EWF_RESULT_UNEXPECTED_RESPONSE;
        }

        ewf_result result_send_command = EWF_RESULT_OK;
        ewf_result result_verify_response = EWF_RESULT_OK;

        for (;;)
        {
            result_send_command = ewf_interface_send_command(interface_ptr, "AT^SISR=4,1500\r");
            if (ewf_result_failed(result_send_command))
            {
                EWF_LOG_ERROR("Failed to send the command.\n");
                break;
            }
            else
            {
                result_verify_response = ewf_interface_verify_response_starts_with(interface_ptr, "\r\n^SISR: 4,");
                if (ewf_result_failed(result_verify_response))
                {
                    EWF_LOG_ERROR("Failed to verify the response.\n");
                    break;
                }
            }
        }

        /* Clear the user URC callback */
        if (ewf_result_failed(result = ewf_interface_set_user_urc_callback(interface_ptr, NULL))) return result;

        if (ewf_result_failed(result_send_command)) return result_send_command;
        if (ewf_result_failed(result_verify_response)) return result_verify_response;
    }

    /* Close the HTTP service */
    {
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SISC=4\r"))) return result;
        if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    }

    return EWF_RESULT_OK;
}

/**
 * @brief FFS API test
 */
ewf_result ewf_adapter_thales_common_test_api_ffs(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SFSA=\"ls\",A:/\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SFSA=\"ls\",B:/\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SFSA=\"ls\",C:/\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT^SFSA=\"ls\",D:/\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

#if 0
    if (ewf_result_failed(result = ewf_adapter_thales_common_ffs_list(adapter_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}
