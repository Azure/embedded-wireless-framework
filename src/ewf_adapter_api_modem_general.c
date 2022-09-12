/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework modem API (3GPP) implementation.
 ****************************************************************************/

#include "ewf_adapter_api_modem.h"

ewf_result ewf_adapter_modem_manufacturer_read(ewf_adapter* adapter_ptr, char * info_str, uint16_t * info_str_len_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    if((info_str == NULL) || (info_str_len_ptr == NULL))
    {
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result;
    uint8_t* response_ptr = NULL;

    /* Read Modem Manufacturer info */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGMI\r")))return result;
    if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response_ptr))) return result;

    /* TODO, review */
    ewfl_str_n_cpy(info_str, (char*)response_ptr, ewfl_str_length((char*)response_ptr));
    ewf_interface_release(interface_ptr, response_ptr);
    info_str = ewfl_adapter_response_str_extract(info_str);
    *info_str_len_ptr = (uint16_t)ewfl_str_length(info_str);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_model_read(ewf_adapter* adapter_ptr, char * info_str, uint16_t * info_str_len_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    if((info_str == NULL) || (info_str_len_ptr == NULL))
    {
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result;
    uint8_t* response_ptr = NULL;

    /* Read modem model info */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGMM\r")))return result;
    if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response_ptr))) return result;

    /* TODO, review */
    ewfl_str_n_cpy(info_str, (char*)response_ptr, ewfl_str_length((char*)response_ptr));
    ewf_interface_release(interface_ptr, response_ptr);
    info_str = ewfl_adapter_response_str_extract(info_str);
    *info_str_len_ptr = (uint16_t)ewfl_str_length(info_str);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_revision_read(ewf_adapter* adapter_ptr, char * info_str, uint16_t * info_str_len_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    if((info_str == NULL) || (info_str_len_ptr == NULL))
    {
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result;
    uint8_t* response_ptr = NULL;

    /* Read modem revision info */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGMR\r")))return result;
    if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response_ptr))) return result;

    /* TODO, review */
    ewfl_str_n_cpy(info_str, (char*)response_ptr, ewfl_str_length((char*)response_ptr));
    ewf_interface_release(interface_ptr, response_ptr);
    info_str = ewfl_adapter_response_str_extract(info_str);
    *info_str_len_ptr = (uint16_t)ewfl_str_length(info_str);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_serial_number_read(ewf_adapter* adapter_ptr,  const char * snt_str, char * info_str, uint16_t * info_str_len_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    if((info_str == NULL) || (info_str_len_ptr == NULL))
    {
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result;
    uint8_t* response_ptr = NULL;

    /* Read modem serial number */
    if(snt_str)
    {
        if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CGSN=", snt_str, "\r", NULL)))return result;
    }
    else
    {
        if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGSN\r")))return result;
    }

    if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response_ptr))) return result;

    /* TODO, review */
    ewfl_str_n_cpy(info_str, (char*)response_ptr, ewfl_str_length((char*)response_ptr));
    ewf_interface_release(interface_ptr, response_ptr);
    info_str = ewfl_adapter_response_str_extract(info_str);
    *info_str_len_ptr = (uint16_t)ewfl_str_length(info_str);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_imsi_read(ewf_adapter* adapter_ptr, char * info_str, uint32_t * info_str_len_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    if((info_str == NULL) || (info_str_len_ptr == NULL))
    {
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result;
    uint8_t* response_ptr = NULL;

    /* Read modem ISMI */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CIMI\r")))return result;
    if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response_ptr))) return result;

    /* TODO, review */
    ewfl_str_n_cpy(info_str, (char*)response_ptr, ewfl_str_length((char*)response_ptr));
    ewf_interface_release(interface_ptr, response_ptr);
    info_str = ewfl_adapter_response_str_extract(info_str);
    *info_str_len_ptr = (uint16_t)ewfl_str_length(info_str);

    return EWF_RESULT_OK;
}
