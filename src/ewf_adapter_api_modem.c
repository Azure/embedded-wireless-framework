/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework modem API (3GPP) implementation.
 ****************************************************************************/

#include "ewf_adapter_api_modem.h"
#include "ewf_lib.h"

#include <stddef.h>

ewf_result ewf_adapter_modem_functionality_set(ewf_adapter* adapter_ptr, const char * fun)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CFUN=", (fun ? fun : "0" /* disable by default*/), "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+CFUN?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_modem_network_registration_check(ewf_adapter* adapter_ptr, uint32_t timeout)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    if(!timeout)
    {
    	return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

	ewf_result result = EWF_RESULT_OK;
	uint32_t n;
	ewf_network_status stat = EWF_NOT_REGISTERED_NOT_SEARCHING;

	while(--timeout)
	{
		while(ewf_adapter_modem_network_registration_read(adapter_ptr, &n, &stat,NULL,NULL,NULL,NULL,NULL) != EWF_RESULT_OK);
		/* Check if module is registered to network */
		if((stat == EWF_REGISTERED_HOME)||(stat == EWF_REGISTERED_ROAMING))
		{
			break;
		}
		ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 1U);
	}
    if (!timeout)
    {

		EWF_LOG_ERROR("Failed to register to Network, ewf_result %d.\n", result);
		return EWF_RESULT_MODEM_NETWORK_NOT_REGISTERED;
    }

    return EWF_RESULT_OK;

}
