/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework Renesas RYZ014 TLS basic API implementation
 * The TLS basic API was designed to work with a signel set of certificates for the adapter.
 * This cover simple scenarios, when the adpater is connecting to a single server, with a single configuration.
 ****************************************************************************/

#include "ewf_adapter_renesas_ryz014.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

ewf_adapter_api_tls_basic ewf_adapter_renesas_ryz014_api_tls_basic  =
{
    ewf_adapter_renesas_ryz014_tls_basic_init,
    ewf_adapter_renesas_ryz014_tls_basic_clean,
};

/******************************************************************************
 *
 * TLS basic API - URC handler
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_ryz014_tls_basic_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_PARAMETER_NOT_USED(interface_ptr);
    EWF_PARAMETER_NOT_USED(buffer_ptr);
    EWF_PARAMETER_NOT_USED(buffer_length);

	/* No SSL specific URCs handled */
	return EWF_RESULT_UNHANDLED_URC;
}

/******************************************************************************
 *
 * TLS basic API
 *
 ******************************************************************************/

ewf_result ewf_adapter_renesas_ryz014_tls_basic_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_RENESAS_RYZ014);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

	return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tls_basic_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
	return EWF_RESULT_OK;
}

ewf_result ewf_adapter_renesas_ryz014_tls_basic_init(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

	ewf_result result;
    uint8_t* response_str;
    char* expected_suffix_str = "\r\nOK\r\n";

    /* Secure profile configuration */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+SQNSPCFG=", EWF_SECURITY_PROFILE_ID, ",3,\"\",1,", EWF_CA_CERTIFICATE_ID, ",", EWF_CLIENT_CERTIFICATE_ID, ",", EWF_PRIVATE_KEY_ID, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_get_response(interface_ptr, &response_str))) return result;
    if (ewfl_buffer_ends_with((const char *)response_str,
    		ewfl_str_length((const char *)response_str),
			expected_suffix_str,
			ewfl_str_length((const char *)expected_suffix_str)))
    {
        return EWF_RESULT_OK;
    }
    else
    {
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }
}

ewf_result ewf_adapter_renesas_ryz014_tls_basic_clean(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
	return EWF_RESULT_OK;
}
