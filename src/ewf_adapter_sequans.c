/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Sequans adapter driver
 ****************************************************************************/
#include "ewf_adapter_sequans.h"
#include "ewf_adapter.h"
#include "ewf_lib.h"

ewf_result ewf_adapter_sequans_autoconnect(ewf_adapter* adapter_ptr, uint32_t mode)
{
	EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
	ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
	EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

	ewf_result result;

#ifdef EWF_DEBUG
	if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNAUTOCONNECT?\r"))) return result;
	if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

	char mode_str[3];
	const char* mode_cstr = ewfl_unsigned_to_str(mode, mode_str, sizeof(mode_str));

	if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNAUTOCONNECT=", mode_cstr,"\r", NULL))) return result;
	if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

	return EWF_RESULT_OK;
}

ewf_result ewf_adapter_sequans_autointernet(ewf_adapter* adapter_ptr, uint32_t mode)
{
	EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
	ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
	EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

	ewf_result result;

#ifdef EWF_DEBUG
	if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+SQNAUTOINTERNET?\r"))) return result;
	if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

	char mode_str[3];
	const char* mode_cstr = ewfl_unsigned_to_str(mode, mode_str, sizeof(mode_str));

	if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNAUTOINTERNET=", mode_cstr,"\r", NULL))) return result;
	if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

	return EWF_RESULT_OK;
}

ewf_result ewf_adapter_sequans_configure_pdp_context(ewf_adapter* adapter_ptr, uint32_t context_id,const char * const apn, const char * const pdp_type)
{
	EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
	ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
	EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

	ewf_result result;

	if ((context_id < 1) || (8 < context_id))
	{
		EWF_LOG_ERROR("Context parameter out of range.");
		return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
	}

	char context_id_str[3];
	const char * context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

	if (ewf_result_failed(result = ewf_interface_send_commands(
			interface_ptr,
			"AT+CGDCONT=",
			context_id_cstr, ",\"",
			pdp_type? pdp_type : "IPV4V6", "\",",
					"\"", apn ? apn : "", "\"",
							",,,,0,0,0,0,0,0,1,,0\r", NULL)))
		return result;
	if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

#ifdef EWF_DEBUG
	if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CGDCONT?\r"))) return result;
	if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif
	return EWF_RESULT_OK;
}
