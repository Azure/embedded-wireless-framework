/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework modem API (3GPP) implementation.
 ****************************************************************************/

#include "ewf_adapter_api_modem.h"

ewf_adapter_modem_api_packet_domain ewf_adapter_modem_api_packet_domain_implementation =
{
    ewf_adapter_modem_eps_network_registration_urc_set, /* eps_network_registration_urc_set */
    NULL, /* eps_network_registration_read */
    ewf_adapter_modem_gprs_network_registration_urc_set, /* gprs_network_registration_urc_set */
    NULL, /* gprs_network_registration_read */
    NULL, /* init_pdp_activate */
    NULL, /* init_pdp_activation_config_read */
    NULL, /* pdp_apn_set */
    NULL, /* pdp_apn_read */
    NULL, /* pdp_context_authentication_set */
    NULL, /* pdp_data_mode_enter */
    NULL, /* packet_service_activate */
    NULL, /* packet_service_deactivate */
    NULL, /* network_attach */
    NULL, /* network_dettach */
    NULL, /* network_attach_status_read */
};

ewf_result ewf_adapter_modem_eps_network_registration_urc_set(ewf_adapter* adapter_ptr, const char* n_str)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    if(n_str == NULL)
    {
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result;

    /* Set Network Registration URC option */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CEREG=", n_str, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    return EWF_RESULT_OK;

}

ewf_result ewf_adapter_modem_gprs_network_registration_urc_set(ewf_adapter* adapter_ptr, const char* n_str)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    if(n_str == NULL)
    {
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    ewf_result result;

    /* Set Network Registration URC option */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CGREG=", n_str, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    return EWF_RESULT_OK;

}

ewf_result ewf_adapter_modem_pdp_apn_set(ewf_adapter* adapter_ptr, uint32_t context_id, const char * pdptype_ptr, const char* apn_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    ewf_result result;

    if (context_id <= 0)
    {
        EWF_LOG_ERROR("The PDP context definition invalid.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
    if (!pdptype_ptr)
    {
        EWF_LOG_ERROR("The PDP context definition invalid.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
    if (!apn_ptr)
    {
        EWF_LOG_ERROR("The PDP context definition invalid.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CGDCONT=", context_id_cstr,
            ",\"",pdptype_ptr,"\"",
            ",\"",apn_ptr,"\"",
            "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_packet_service_activate(ewf_adapter* adapter_ptr, uint32_t context_id)
{

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    ewf_result result;
    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

    interface_ptr->current_context = context_id;

    /* Activate PDP context */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CGACT=1,", context_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGACT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_packet_service_deactivate(ewf_adapter* adapter_ptr, uint32_t context_id)
{

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    ewf_result result;
    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

    /* Set Network Registration URC option */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CGACT=0,", context_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGACT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_packet_service_attach(ewf_adapter* adapter_ptr)
{

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    ewf_result result;

    /* Attach to network */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGATT=1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_packet_service_detach(ewf_adapter* adapter_ptr)
{

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    ewf_result result;

    /* Attach to network */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGATT=0\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    return EWF_RESULT_OK;
}

