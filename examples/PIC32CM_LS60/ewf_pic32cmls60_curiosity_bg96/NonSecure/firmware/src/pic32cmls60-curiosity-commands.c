
#include "pic32cmls60-curiosity-commands.h"

#define debug_printError printf
#define debug_printInfo printf
#define debug_printTrace printf
#define debug_printWarn printf

uint32_t SYS_rebootTimer = 0;

static char command_topic_buffer[128];
static char command_resp_buffer[128];

static const az_span command_reboot_delay_payload_span     = AZ_SPAN_LITERAL_FROM_STR("delay");
static const az_span command_status_span                   = AZ_SPAN_LITERAL_FROM_STR("status");
static const az_span command_resp_empty_delay_payload_span = AZ_SPAN_LITERAL_FROM_STR("Delay time is empty. Specify 'delay' in period format (PT5S for 5 sec)");
static const az_span command_resp_bad_payload_span         = AZ_SPAN_LITERAL_FROM_STR("Delay time in wrong format. Specify 'delay' in period format (PT5S for 5 sec)");
static const az_span command_resp_error_processing_span    = AZ_SPAN_LITERAL_FROM_STR("Error processing command");
static const az_span command_resp_not_supported_span       = AZ_SPAN_LITERAL_FROM_STR("{\"Status\":\"Unsupported Command\"}");

static const az_span command_sendMsg_payload_span            = AZ_SPAN_LITERAL_FROM_STR("sendMsgString");
static const az_span command_resp_empty_sendMsg_payload_span = AZ_SPAN_LITERAL_FROM_STR("Message string is empty. Specify string.");
static const az_span command_resp_alloc_error_sendMsg_span   = AZ_SPAN_LITERAL_FROM_STR("Failed to allocate memory for the message.");

static const az_span resp_success_span                     = AZ_SPAN_LITERAL_FROM_STR("Success");

/**************************************
 Start JSON_BUILDER for JSON Document
 This creates a new JSON with "{"
*************************************/
az_result start_json_object(
    az_json_writer* jw,
    az_span         az_span_buffer)
{
    RETURN_ERR_IF_FAILED(az_json_writer_init(jw, az_span_buffer, NULL));
    RETURN_ERR_IF_FAILED(az_json_writer_append_begin_object(jw));
    return AZ_OK;
}

/**********************************************
* End JSON_BUILDER for JSON Document
* This adds "}" to the JSON
**********************************************/
az_result end_json_object(
    az_json_writer* jw)
{
    RETURN_ERR_IF_FAILED(az_json_writer_append_end_object(jw));
    return AZ_OK;
}

/**********************************************
*	Add a JSON key-value pair with int32 data
*	e.g. "property_name" : property_val (number)
**********************************************/
az_result append_json_property_int32(
    az_json_writer* jw,
    az_span         property_name_span,
    int32_t         property_val)
{
    RETURN_ERR_IF_FAILED(az_json_writer_append_property_name(jw, property_name_span));
    RETURN_ERR_IF_FAILED(az_json_writer_append_int32(jw, property_val));
    return AZ_OK;
}

/**********************************************
*	Add a JSON key-value pair with float data
*	e.g. "property_name" : property_val (number)
**********************************************/
az_result append_json_property_float(
    az_json_writer* jw,
    az_span         property_name_span,
    float           property_val)
{
    RETURN_ERR_IF_FAILED(az_json_writer_append_property_name(jw, property_name_span));
    RETURN_ERR_IF_FAILED(az_json_writer_append_double(jw, (double)property_val, 5));
    return AZ_OK;
}

/**********************************************
*	Add a JSON key-value pair with double data
*	e.g. "property_name" : property_val (number)
**********************************************/
az_result append_json_property_double(
    az_json_writer* jw,
    az_span         property_name_span,
    double          property_val)
{
    RETURN_ERR_IF_FAILED(az_json_writer_append_property_name(jw, property_name_span));
    RETURN_ERR_IF_FAILED(az_json_writer_append_double(jw, property_val, 5));
    return AZ_OK;
}

/**********************************************
*	Add a JSON key-value pair with long data
*	e.g. "property_name" : property_val (number)
**********************************************/
az_result append_json_property_long(
    az_json_writer* jw,
    az_span         property_name_span,
    int64_t         property_val)
{
    RETURN_ERR_IF_FAILED(az_json_writer_append_property_name(jw, property_name_span));
    RETURN_ERR_IF_FAILED(az_json_writer_append_double(jw, property_val, 5));
    return AZ_OK;
}

/**********************************************
*	Add a JSON key-value pair with bool data
*	e.g. "property_name" : property_val (number)
**********************************************/
az_result append_json_property_bool(
    az_json_writer* jw,
    az_span         property_name_span,
    bool            property_val)
{
    RETURN_ERR_IF_FAILED(az_json_writer_append_property_name(jw, property_name_span));
    RETURN_ERR_IF_FAILED(az_json_writer_append_bool(jw, property_val));
    return AZ_OK;
}

/**********************************************
* Add a JSON key-value pair with string data
* e.g. "property_name" : "property_val (string)"
**********************************************/
az_result append_json_property_string(
    az_json_writer* jw,
    az_span         property_name_span,
    az_span         property_val_span)
{
    RETURN_ERR_IF_FAILED(az_json_writer_append_property_name(jw, property_name_span));
    RETURN_ERR_IF_FAILED(az_json_writer_append_string(jw, property_val_span));
    return AZ_OK;
}

/**********************************************
* Create JSON document for command error response
* e.g.
* {
*   "status":500,
*   "payload":{
*     "Status":"Unsupported Command"
*   }
* }
**********************************************/
static az_result build_command_error_response_payload(
    az_span  response_span,
    az_span  status_string_span,
    az_span* response_payload_span)
{
    az_json_writer jw;

    // Build the command response payload with error status
    RETURN_ERR_IF_FAILED(start_json_object(&jw, response_span));
    RETURN_ERR_IF_FAILED(append_json_property_string(&jw, command_status_span, status_string_span));
    RETURN_ERR_IF_FAILED(end_json_object(&jw));
    *response_payload_span = az_json_writer_get_bytes_used_in_destination(&jw);
    return AZ_OK;
}

/**********************************************
* Create JSON document for reboot command with status message
* e.g.
* {
*   "status":200,
*   "payload":{
*     "status":"Success",
*     "delay":100
*   }
* }
**********************************************/
static az_result build_reboot_command_resp_payload(
    az_span  response_span,
    int      reboot_delay,
    az_span* response_payload_span)
{
    az_json_writer jw;

    // Build the command response payload
    RETURN_ERR_IF_FAILED(start_json_object(&jw, response_span));
    RETURN_ERR_IF_FAILED(append_json_property_string(&jw, command_status_span, resp_success_span));
    RETURN_ERR_IF_FAILED(append_json_property_int32(&jw, command_reboot_delay_payload_span, reboot_delay));
    RETURN_ERR_IF_FAILED(end_json_object(&jw));
    *response_payload_span = az_json_writer_get_bytes_used_in_destination(&jw);
    return AZ_OK;
}

/**********************************************
* Create JSON document for command response with status message
* e.g.
* {
*   "status":200,
*   "payload":{
*     "status":"Success"
*   }
* }
**********************************************/
static az_result build_command_resp_payload(az_span response_span, az_span* response_payload_span)
{
    az_json_writer jw;

    // Build the command response payload
    RETURN_ERR_IF_FAILED(start_json_object(&jw, response_span));
    RETURN_ERR_IF_FAILED(append_json_property_string(&jw, command_status_span, resp_success_span));
    RETURN_ERR_IF_FAILED(end_json_object(&jw));
    *response_payload_span = az_json_writer_get_bytes_used_in_destination(&jw);
    return AZ_OK;
}

/**********************************************
*	Handle reboot command
**********************************************/
az_result COMMAND_Handler_reboot(
    az_span   payload_span,
    az_span   response_span,
    az_span*  out_response_span)
{
    az_result      ret              = AZ_OK;
    char           reboot_delay[32] = {0};
    //az_json_reader jr;

    if (az_span_size(payload_span) > 0)
    {
        printf("AZURE: %s() : Received payload = %s\r\n", __func__, az_span_ptr(payload_span));
#ifdef _ELIMINATE
        RETURN_ERR_IF_FAILED(az_json_reader_init(&jr, payload_span, NULL));

        while (jr.token.kind != AZ_JSON_TOKEN_END_OBJECT)
        {
            if (jr.token.kind == AZ_JSON_TOKEN_PROPERTY_NAME)
            {
                if (az_json_token_is_text_equal(&jr.token, command_reboot_delay_payload_span))
                {
                    if (az_result_failed(ret = az_json_reader_next_token(&jr)))
                    {
                        printf("AZURE: Error getting next token\r\n");
                        break;
                    }
                    else if (az_result_failed(ret = az_json_token_get_string(&jr.token, reboot_delay, sizeof(reboot_delay), NULL)))
                    {
                        printf("AZURE: Error getting string\r\n");
                        break;
                    }

                    break;
                }
            }
            else if (az_result_failed(ret = az_json_reader_next_token(&jr)))
            {
                printf("AZURE: Error getting next token\r\n");
                break;
            }
        }
#endif /* _ELIMINATE */
        strcpy(reboot_delay, az_span_ptr(payload_span));
    }
    else
    {
        debug_printError("AZURE: %s() : Payload is empty\r\n", __func__);
    }

    if (strlen(reboot_delay) == 0)
    {
        debug_printError("AZURE: Reboot delay not found\r\n");

        ret = build_command_error_response_payload(response_span,
                                                   command_resp_empty_delay_payload_span,
                                                   out_response_span);
    }
    else if (reboot_delay[1] != 'P' || reboot_delay[2] != 'T' || reboot_delay[strlen(reboot_delay) - 2] != 'S')
    {
        debug_printError("AZURE: Reboot delay is in the wrong format\r\n");

        ret = build_command_error_response_payload(response_span,
                                                   command_resp_bad_payload_span,
                                                   out_response_span);
    }
    else
    {
        int reboot_delay_seconds = atoi((const char*)&reboot_delay[3]);

        RETURN_ERR_IF_FAILED(build_reboot_command_resp_payload(response_span,
                                                               reboot_delay_seconds,
                                                               out_response_span));
        debug_printInfo("AZURE: Scheduling reboot in %d sec\r\n", reboot_delay_seconds);        
        SYS_rebootTimer = reboot_delay_seconds;
    }

    return ret;
}

/**********************************************
 *	Handle send message command
 **********************************************/
az_result COMMAND_Handler_sendMsg(
    az_span   payload_span,
    az_span   response_span,
    az_span*  out_response_span)
{
    az_result      ret           = AZ_OK;
    size_t         spanSize      = -1;
    char*          messageString = NULL;
    az_json_reader jr;

    printf("AZURE: %s()\r\n", __func__);

    if (az_span_size(payload_span) > 0)
    {
        printf("AZURE: Received message from the Cloud \"%s\"\r\n", az_span_ptr(payload_span));
        
        RETURN_ERR_IF_FAILED(az_json_reader_init(&jr, payload_span, NULL));

        while (jr.token.kind != AZ_JSON_TOKEN_END_OBJECT)
        {
            if (jr.token.kind == AZ_JSON_TOKEN_PROPERTY_NAME)
            {
                if (az_json_token_is_text_equal(&jr.token, command_sendMsg_payload_span))
                {
                    if (az_result_failed(ret = az_json_reader_next_token(&jr)))
                    {
                        printf("AZURE: Error getting next token\r\n");
                        break;
                    }
                    else
                    {
                        spanSize = (size_t)az_span_size(jr.token.slice);
                        break;
                    }

                    break;
                }
            } else if (az_result_failed(ret = az_json_reader_next_token(&jr)))
            {
                printf("AZURE: Error getting next token\r\n");
                break;
            }
        }
    }
    else
    {
        printf("AZURE: %s() : Payload Empty\r\n", __func__);
    }

    if (spanSize == -1)
    {
        printf("AZURE: Message string not found\r\n");

        ret = build_command_error_response_payload(response_span,
                                                   command_resp_empty_sendMsg_payload_span,
                                                   out_response_span);
    }
    else if ((messageString = malloc(spanSize + 1)) == NULL)
    {
        debug_printError("AZURE: Failed to allocate memory for message string : Size %u\r\n", spanSize);

        ret = build_command_error_response_payload(response_span,
                                                   command_resp_alloc_error_sendMsg_span,
                                                   out_response_span);
    }
    else
    {
        RETURN_ERR_IF_FAILED(az_json_token_get_string(&jr.token, messageString, spanSize + 1, NULL));
        strlcat(messageString, "\4", spanSize + 1);
        RETURN_ERR_IF_FAILED(build_command_resp_payload(response_span, out_response_span));
    }

    if (messageString)
    {
        free(messageString);
    }

    return ret;
}


