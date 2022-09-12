/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework modem API (3GPP) implementation.
 ****************************************************************************/

#include "ewf_adapter_api_modem.h"

ewf_adapter_modem_api_sim_utility ewf_adapter_modem_api_sim_utility_implementation =
{
	ewf_adapter_modem_sim_pin_enter, /* sim_pin_enter */
	NULL, /* sim_pin_read */
	NULL, /* sim_new_pin_enter */
	NULL, /* sim_pin_retries_read */
	NULL, /* sim_generic_access_set */
	NULL, /* sim_restricted_access */
	NULL, /* facility_lock */
	NULL, /* facility_unlock */
	NULL, /* facility_password_change */
};

ewf_result ewf_adapter_modem_sim_pin_enter(ewf_adapter* adapter_ptr, const char* param)
{
	EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
	if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

	ewf_result result;
	uint8_t* response;
	bool equal;

	/* Set SIM PIN*/
	if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CPIN?\r"))) return result;
	if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response))) return result;

	equal = ewfl_str_equals_str((char*)response, "\r\n+CPIN: READY\r\n\r\nOK\r\n");
	ewf_interface_release(interface_ptr, response);

	if (!equal)
	{
		/* SIM not ready, attempt to enter the PIN */

		if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CPIN=", (param ? param : "0000" /* try a common default value */), "\r", NULL))) return result;
		if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;
	}

	return EWF_RESULT_OK;
}
