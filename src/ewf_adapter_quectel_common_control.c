/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel common adapter driver
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

ewf_adapter_api_control ewf_adapter_quectel_common_api_control =
{
    ewf_adapter_quectel_common_start,
    ewf_adapter_quectel_common_stop,
};

char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5_str[] = "\r\n+CME ERROR: ???\r\n";
char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4_str[] = "\r\n+CME ERROR: ??\r\n";
char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3_str[] = "\r\n+CME ERROR: ?\r\n";
char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2_str[] = "\r\nERROR\r\n";
char ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1_str[] = "\r\nOK\r\n";

static ewf_interface_tokenizer_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5 =
{
    NULL,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5_str)-1,
    true,
};

static ewf_interface_tokenizer_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4 =
{
    &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern5,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4_str)-1,
    true,
};

static ewf_interface_tokenizer_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3 =
{
    &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern4,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3_str)-1,
    true,
};

static ewf_interface_tokenizer_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2 =
{
    &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern3,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2_str)-1,
    false,
};

static ewf_interface_tokenizer_pattern ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1 =
{
    &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern2,
    ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1_str,
    sizeof(ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1_str)-1,
    false,
};

static ewf_interface_tokenizer_pattern* ewf_adapter_quectel_common_command_response_end_tokenizer_pattern_ptr = &ewf_adapter_quectel_common_command_response_end_tokenizer_pattern1;

char ewf_adapter_quectel_common_urc_tokenizer_pattern1_str[] = "\r\n";

static ewf_interface_tokenizer_pattern ewf_adapter_quectel_common_urc_tokenizer_pattern1 =
{
    NULL,
    ewf_adapter_quectel_common_urc_tokenizer_pattern1_str,
    sizeof(ewf_adapter_quectel_common_urc_tokenizer_pattern1_str)-1,
    false,
};

static ewf_interface_tokenizer_pattern* ewf_adapter_quectel_common_urc_tokenizer_pattern_ptr = &ewf_adapter_quectel_common_urc_tokenizer_pattern1;

ewf_result ewf_adapter_quectel_common_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

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

    /* Initialize the interface tokenizer patterns */

    if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_end_pattern_set(interface_ptr, ewf_adapter_quectel_common_command_response_end_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface command response end tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    if (ewf_result_failed(result = ewf_interface_tokenizer_urc_pattern_set(interface_ptr, ewf_adapter_quectel_common_urc_tokenizer_pattern_ptr)))
    {
        EWF_LOG_ERROR("Failed to set the interface URC tokenizer pattern: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* Start the interface */
    if (ewf_result_failed(result = ewf_interface_start(interface_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the interface: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    /* AT - wake the modem */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Disable local echo */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "ATE0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

    /* Check that the modem is responding */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Set the error Message Format */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CMEE=1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Start the APIs */

#if EWF_ADAPTER_QUECTEL_COMMON_TCP_ENABLED || EWF_ADAPTER_QUECTEL_COMMON_UDP_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_internet_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the internet API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_MQTT_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_mqtt_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the MQTT API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_tls_basic_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the TLS basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_MQTT_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_mqtt_basic_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the MQTT basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

    /* All ok! */
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Stop the APIs */

#if EWF_ADAPTER_QUECTEL_COMMON_UFS_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the UFS API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if defined(EWF_ADAPTER_QUECTEL_COMMON_TCP_ENABLED) || defined(EWF_ADAPTER_QUECTEL_COMMON_UDP_ENABLED)
    if (ewf_result_failed(result = ewf_adapter_quectel_common_internet_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the internet API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_MQTT_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_mqtt_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the MQTT API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_tls_basic_stop(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to stop the TLS basic API: ewf_result %d.\n", result);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }
#endif

#if EWF_ADAPTER_QUECTEL_COMMON_MQTT_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_quectel_common_mqtt_basic_stop(adapter_ptr)))
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
