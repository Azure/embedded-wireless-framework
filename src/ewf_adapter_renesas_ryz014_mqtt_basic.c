#include "ewf_adapter_renesas_ryz014.h"
#include "ewf_lib.h"

/******************************************************************************
 * API
 ******************************************************************************/

ewf_adapter_api_mqtt_basic ewf_adapter_renesas_ryz014_api_mqtt_basic =
{
    ewf_adapter_renesas_ryz014_mqtt_basic_default_state_callback,
    ewf_adapter_renesas_ryz014_mqtt_basic_default_message_callback,
    NULL,
    NULL,
    ewf_adapter_renesas_ryz014_mqtt_basic_connect,
    ewf_adapter_renesas_ryz014_mqtt_basic_disconnect,
    ewf_adapter_renesas_ryz014_mqtt_basic_subscribe,
    ewf_adapter_renesas_ryz014_mqtt_basic_unsubscribe,
    ewf_adapter_renesas_ryz014_mqtt_basic_publish,
};

/******************************************************************************
 *
 * MQTT basic API - URC handler
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter* adapter_ptr = interface_ptr->adapter_ptr;

    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    EWF_PARAMETER_NOT_USED(buffer_length);

    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTONCONNECT:0,0"))
    {
    	adapter_renesas_ryz014_ptr->mqtt_basic_conn = true;
    	adapter_renesas_ryz014_ptr->mqtt_basic_conn_error = false;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTONCONNECT:0,-1"))
    {
    	adapter_renesas_ryz014_ptr->mqtt_basic_conn = false;
    	adapter_renesas_ryz014_ptr->mqtt_basic_conn_error = true;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTONCONNECT:0,-4"))
    {
        adapter_renesas_ryz014_ptr->mqtt_basic_conn = false;
        adapter_renesas_ryz014_ptr->mqtt_basic_conn_error = true;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTONCONNECT:0,-7"))
    {
        adapter_renesas_ryz014_ptr->mqtt_basic_conn = false;
        adapter_renesas_ryz014_ptr->mqtt_basic_conn_error = true;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTONCONNECT:0,-1"))
    {
        adapter_renesas_ryz014_ptr->mqtt_basic_conn = false;
        adapter_renesas_ryz014_ptr->mqtt_basic_conn_error = true;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTONCONNECT:0,-11"))
    {
        adapter_renesas_ryz014_ptr->mqtt_basic_conn = false;
        adapter_renesas_ryz014_ptr->mqtt_basic_conn_error = true;
        return EWF_RESULT_OK;
    }

    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSPCFG: "))
    {
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTPUBLISH:0,"))
    {
        adapter_renesas_ryz014_ptr->mqtt_basic_publish = true;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTONSUBSCRIBE:0"))
    {
        adapter_renesas_ryz014_ptr->mqtt_basic_subscribe = true;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTDISCONNECT:"))
    {
        adapter_renesas_ryz014_ptr->mqtt_basic_conn = false;
        adapter_renesas_ryz014_ptr->mqtt_basic_conn_error = false;
        return EWF_RESULT_OK;
    }
    if (ewfl_str_starts_with((char*)buffer_ptr, "+SQNSMQTTONMESSAGE:0"))
    {
        /* TODO: RYZ014 does not return full URC for SQNSMQTTONMESSAGE. Awaiting Firmware update from Renesas
        ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTRCVMESSAGE=0,\"", AZ_IOT_HUB_CLIENT_C2D_SUBSCRIBE_TOPIC,"\"\r");
        ewf_interface_drop_response(interface_ptr);
        */
        return EWF_RESULT_OK;
    }

    return EWF_RESULT_UNHANDLED_URC;
}

/******************************************************************************
 *
 * MQTT basic API - default callbacks
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_default_state_callback(ewf_adapter* adapter_ptr, const char* state_cstr, const char* param_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    EWF_LOG("[MQTT-Basic][State callback:][%s][%s]\n", state_cstr, param_cstr);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_default_message_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    EWF_LOG("[MQTT-Basic][Message callback:][%s][%s]\n", topic_cstr, payload_cstr);

    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * MQTT basic API control
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_adapter_renesas_ryz014* implementation_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    implementation_ptr->mqtt_basic_conn = false;
    implementation_ptr->mqtt_basic_conn_error = false;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * MQTT basic API
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_connect(ewf_adapter* adapter_ptr, char const* const server, uint32_t port, char const* const clientid, char const* const username, char const* const password)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

#ifdef EWF_DEBUG
    /* Close the connection in case it is still outstanding, ignore errors */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNSMQTTDISCONNECT=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    /* MQTT client configuration */
    if (!username)
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTCFG=0,\"", clientid, "\"\r", NULL))) return result;
    }
    else if (!password)
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTCFG=0,\"", clientid, "\",\"", username, "\",,", EWF_SECURITY_PROFILE_ID, "\r", NULL))) return result;
    }
    else /* username and password provided */
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTCFG=0,\"", clientid, "\",\"", username, "\",\"", password, "\",", EWF_SECURITY_PROFILE_ID, "\"\r", NULL))) return result;
    }
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    char port_str[7];
    const char* port_cstr = ewfl_unsigned_to_str(port, port_str, sizeof(port_str));

    /* Initiate MQTT connection */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTCONNECT=0,\"", server, "\",", port_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    for (unsigned i = 0; i < (30 * EWF_PLATFORM_TICKS_PER_SECOND); i++)
    {
        if (adapter_renesas_ryz014_ptr->mqtt_basic_conn) break;
        if (adapter_renesas_ryz014_ptr->mqtt_basic_conn_error) return EWF_RESULT_UNEXPECTED_RESPONSE;
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_disconnect(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNSMQTTDISCONNECT=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    for (unsigned i = 0; i < (30 * EWF_PLATFORM_TICKS_PER_SECOND); i++)
    {
        if (adapter_renesas_ryz014_ptr->mqtt_basic_conn == false) break;
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_subscribe(ewf_adapter* adapter_ptr, char const* topic)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    ewf_result result;

    if (!topic) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTSUBSCRIBE=0,\"", topic, "\",0\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    for (unsigned i = 0; i < (2 * EWF_PLATFORM_TICKS_PER_SECOND); i++)
    {
        if (adapter_renesas_ryz014_ptr->mqtt_basic_subscribe) break;
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }
    adapter_renesas_ryz014_ptr->mqtt_basic_subscribe = false;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_unsubscribe(ewf_adapter* adapter_ptr, char const* topic)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    if (!topic) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    /* This modem does not have AT command to unsubscribe from a topic */

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_mqtt_basic_publish(ewf_adapter* adapter_ptr, const char* const topic, const char* message_cstr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;

    if (!topic) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!message_cstr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    ewf_result result;
    uint8_t* response;

    /* allow empty messages, zero length, NULL pointer */
    uint32_t message_length = (message_cstr == NULL) ? 0 : strlen(message_cstr);

    char tokenizer_pattern_str[] = "\r\n> ";
    ewf_interface_tokenizer_pattern tokenizer_pattern = {
        NULL,
        tokenizer_pattern_str ,
        sizeof(tokenizer_pattern_str) - 1,
        false,
    };
    char message_length_str[6];
    if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, &tokenizer_pattern))) return result;
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSMQTTPUBLISH=0,\"", topic, "\",,", ewfl_unsigned_to_str(message_length, message_length_str, sizeof(message_length_str)), "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, tokenizer_pattern_str))) return result;
    if (ewf_result_failed(result = ewf_interface_tokenizer_command_response_pattern_set(interface_ptr, NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_send(interface_ptr, (uint8_t*)message_cstr, message_length))) return result;
    if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response))) return result;
    if (!ewfl_str_starts_with((char*)response, "\r\n+SQNSMQTTPUBLISH: "))
    {
        EWF_LOG_ERROR("Unexpected NULL response.");
    }
    ewf_interface_release(interface_ptr, response);
    for (unsigned i = 0; i < (2 * EWF_PLATFORM_TICKS_PER_SECOND); i++)
    {
        if (adapter_renesas_ryz014_ptr->mqtt_basic_publish) break;
        ewf_interface_poll(interface_ptr);
        ewf_platform_sleep(1);
    }
    adapter_renesas_ryz014_ptr->mqtt_basic_publish = false;
    return EWF_RESULT_OK;
}
