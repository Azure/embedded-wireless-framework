/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework MX-CHIP common adapter API
 ****************************************************************************/

#include "ewf_adapter_mxchip_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

ewf_adapter_api_control ewf_adapter_mxchip_common_api_control =
{
    ewf_adapter_mxchip_common_start,
    ewf_adapter_mxchip_common_stop,
};

ewf_result ewf_adapter_mxchip_common_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_mxchip_common* implementation_ptr = (ewf_adapter_mxchip_common*)adapter_ptr->implementation_ptr;

    ewf_result result;

    /* Initialize the interface */
    if (ewf_result_failed(result = ewf_interface_init(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to initialize the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Set the interface default timeout */
    if (ewf_result_failed(result = ewf_interface_default_timeout_set(interface_ptr, EWF_PLATFORM_TICKS_PER_SECOND * 5)))
    {
        EWF_LOG_ERROR("Failed to set the interface default timeout: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Start the interface */
    if (ewf_result_failed(result = ewf_interface_start(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Initialize the tokenizer */
    result = ewf_adapter_mxchip_common_tokenizer_init(interface_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to initialize the tokenizer: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Initialize the socket pool */
    memset(&(implementation_ptr->internet_socket_pool[0]), 0, sizeof(ewf_adapter_mxchip_common_internet_socket));
    memset(&(implementation_ptr->internet_socket_pool[1]), 0, sizeof(ewf_adapter_mxchip_common_internet_socket));
    memset(&(implementation_ptr->internet_socket_pool[2]), 0, sizeof(ewf_adapter_mxchip_common_internet_socket));
    memset(&(implementation_ptr->internet_socket_pool[3]), 0, sizeof(ewf_adapter_mxchip_common_internet_socket));
    memset(&(implementation_ptr->internet_socket_pool[4]), 0, sizeof(ewf_adapter_mxchip_common_internet_socket));

    /* Initialize the reception queues */
    {
#if (EWF_ADAPTER_MXCHIP_COMMON_INTERNET_SOCKET_POOL_SIZE != 5)
#error Please update the code below to match
#endif
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[0].recv_queue_ptr, queue0, uint8_t, EWF_ADAPTER_MXCHIP_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[1].recv_queue_ptr, queue1, uint8_t, EWF_ADAPTER_MXCHIP_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[2].recv_queue_ptr, queue2, uint8_t, EWF_ADAPTER_MXCHIP_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[3].recv_queue_ptr, queue3, uint8_t, EWF_ADAPTER_MXCHIP_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);
        EWF_PLATFORM_QUEUE_STATIC_DECLARE(implementation_ptr->internet_socket_pool[4].recv_queue_ptr, queue4, uint8_t, EWF_ADAPTER_MXCHIP_COMMON_INTERNET_SOCKET_RECV_BUFFER_SIZE);

        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[0].recv_queue_ptr);
        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[1].recv_queue_ptr);
        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[2].recv_queue_ptr);
        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[3].recv_queue_ptr);
        ewf_platform_queue_create(implementation_ptr->internet_socket_pool[4].recv_queue_ptr);
    }

    /* AT - wake the modem */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr)))
    {
#ifdef EWF_ADAPTER_USER_POWER_ON
       /* EWF does not process Power ON URC's at init.
          Application code must add delay of atleast 500ms after modem is power on to skip the URC's
          */
       EWF_ADAPTER_USER_POWER_ON();
#endif
    }
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

#if 0
    /* Reboot the module */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+REBOOT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    /* AT - wake the module */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Log the firmware info */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+FWVER?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Disable local echo */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+UARTE=OFF\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Check that the modem is responding */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

#if 1
    /* Disable automatic connections */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPAUTOCONN=0,0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPAUTOCONN=1,0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPAUTOCONN=2,0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPAUTOCONN=3,0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPAUTOCONN=4,0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
#endif

#if 1
    /* Close all connections */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPSTOP=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPSTOP=1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPSTOP=2\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPSTOP=3\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPSTOP=4\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
#endif

    /* Enable Wi-Fi notifications*/
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+WEVENT=ON\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Enable network notifications */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPEVENT=ON\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Set the reception method */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIPRECVCFG=1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Start the APIs */

#if EWF_ADAPTER_MXCHIP_COMMON_TCP_ENABLED || EWF_ADAPTER_MXCHIP_COMMON_UDP_ENABLED
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_internet_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the internet API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_MXCHIP_COMMON_TLS_ENABLED
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_tls_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the TLS API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_MXCHIP_COMMON_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_tls_basic_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the TLS basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_MXCHIP_COMMON_MQTT_ENABLED
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_mqtt_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the MQTT API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_MXCHIP_COMMON_MQTT_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_mqtt_basic_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the MQTT basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_mxchip_common_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Stop the APIs */

#if defined(EWF_ADAPTER_MXCHIP_COMMON_TCP_ENABLED) || defined(EWF_ADAPTER_MXCHIP_COMMON_UDP_ENABLED)
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_internet_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the internet API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_MXCHIP_COMMON_TLS_ENABLED
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_tls_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the TLS API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
}
#endif

#if EWF_ADAPTER_MXCHIP_COMMON_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_tls_basic_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the TLS basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_MXCHIP_COMMON_MQTT_ENABLED
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_mqtt_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the MQTT API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_MXCHIP_COMMON_MQTT_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_mxchip_common_mqtt_basic_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the MQTT basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

    /* Stop the interface */
    if (ewf_result_failed(result = ewf_interface_stop(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to clean the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Cleanup the interface */
    if (ewf_result_failed(result = ewf_interface_init(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to clean the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    return EWF_RESULT_OK;
}
