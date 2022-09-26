/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework modem API (3GPP) implementation.
 ****************************************************************************/

#include "ewf_adapter_api_modem.h"

ewf_adapter_modem_api_network_service_command ewf_adapter_modem_api_network_service_command_implementation =
{
    NULL, /* subscriber_number_read */
    ewf_adapter_modem_network_registration_urc_set, /* network_registration_set */
	ewf_adapter_modem_network_registration_read, /* network_registration_read */
    NULL, /* operator_select */
    NULL, /* operator_select_read */
    NULL, /* operator_list_edit */
    NULL, /* operator_list_read */
    NULL, /* operator_list_select */
    NULL, /* operator_option_list_read */
    NULL, /* dynamic_parameters_read */
    NULL, /* dynamic_parameters_set */
    NULL, /* power_saving_mode_set */
    NULL, /* power_saving_mode_read */
    NULL, /* signal_strength_read */
    NULL, /* signal_strength_extended_read */
    NULL, /* timezone_reporting_set */
    NULL, /* timezone_reporting_read */
    NULL, /* timezone_autoupdate_set */
    NULL, /* timezone_autoupdate_read */

};

ewf_result ewf_adapter_modem_network_registration_urc_set(ewf_adapter* adapter_ptr, const char * n_str)
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
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CREG=", n_str, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

	return EWF_RESULT_OK;

}

ewf_result ewf_adapter_modem_network_registration_read(ewf_adapter* adapter_ptr, uint32_t * n_ptr, ewf_network_status * cmnRegistrationStatus_ptr, ewf_act * act_ptr, uint32_t * tac_ptr, uint32_t * ci_ptr, uint8_t * cause_type_ptr, uint8_t * reject_cause_ptr)
{
	EWF_PARAMETER_NOT_USED(act_ptr);
	EWF_PARAMETER_NOT_USED(tac_ptr);
	EWF_PARAMETER_NOT_USED(ci_ptr);
	EWF_PARAMETER_NOT_USED(cause_type_ptr);
	EWF_PARAMETER_NOT_USED(reject_cause_ptr);

	EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
	if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

	ewf_result result;
    uint8_t* response_ptr;
    uint32_t response_length;

	/* Read Network Registration status */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CREG?\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr , &response_ptr, &response_length, 500))) return result;
    if (response_length < 5)
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }
    const char data_read_response_str[] = "\r\n+CREG: ";
    if (!ewfl_str_starts_with((char*)response_ptr, data_read_response_str))
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }
    else
    {
    	char* p;
        p = (char*)response_ptr;
        p += sizeof(data_read_response_str) - 1;
        while (*p && (!isdigit((unsigned char)*p))) p++;
        *n_ptr = ewfl_str_to_unsigned(p);
        p = p +2; //skip ',' after URC option value (n)
        *cmnRegistrationStatus_ptr = ewfl_str_to_unsigned(p);
        ewf_interface_release(interface_ptr, response_ptr);
    }

	return EWF_RESULT_OK;
}
