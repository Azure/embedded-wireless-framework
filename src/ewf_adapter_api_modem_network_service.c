/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework modem API (3GPP) implementation.
 ****************************************************************************/

#include "ewf_adapter_api_modem.h"
#include "ewf_adapter.h"

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

ewf_result ewf_adapter_modem_network_registration_read(ewf_adapter* adapter_ptr, ewf_adapter_modem_cmd_query_network_reg reg_cmd, uint32_t * n_ptr, ewf_adapter_modem_network_status * RegistrationStatus_ptr, ewf_adapter_modem_act * act_ptr, uint32_t * tac_ptr, uint32_t * ci_ptr, uint8_t * cause_type_ptr, uint8_t * reject_cause_ptr)
{
    EWF_PARAMETER_NOT_USED(act_ptr);
    EWF_PARAMETER_NOT_USED(tac_ptr);
    EWF_PARAMETER_NOT_USED(ci_ptr);
    EWF_PARAMETER_NOT_USED(cause_type_ptr);
    EWF_PARAMETER_NOT_USED(reject_cause_ptr);

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    if (adapter_ptr->interface_ptr == NULL) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;

    ewf_result result = EWF_RESULT_OK;
    uint8_t* response_ptr;
    uint32_t response_length;

    const char * response_prefix_str[3] = {"\r\n+CREG:", "\r\n+CEREG:", "\r\n+CGREG:"};
    switch(reg_cmd)
    {
		case 0:
			/* Read Network Registration status */
			if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CREG?\r", NULL))) return result;
			break;
		case 1:
			/* Read GPRS Network Registration status */
			if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CEREG?\r", NULL))) return result;
			break;
		case 2:
			/* Read EPS Network Registration status */
			if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+CGREG?\r", NULL))) return result;
			break;
		default :
			return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }
    if (ewf_result_failed(result = ewf_interface_receive_response(interface_ptr , &response_ptr, &response_length, 500))) return result;
    if (response_length < 5)
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }
    if (!ewfl_str_contains_str((char*)response_ptr, response_prefix_str[reg_cmd]))
    {
        ewf_interface_release(interface_ptr, response_ptr);
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }
    else
    {
        char* p;
        p = (char*)response_ptr;
        p += sizeof(response_prefix_str[reg_cmd]) - 1;
        while (*p && (!isdigit((unsigned char)*p))) p++;
        *n_ptr = ewfl_str_to_unsigned(p);
        p = p +2; //skip ',' after URC option value (n)
        *RegistrationStatus_ptr = ewfl_str_to_unsigned(p);
        ewf_interface_release(interface_ptr, response_ptr);
    }

    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_modem_network_registration_check(ewf_adapter* adapter_ptr, ewf_adapter_modem_cmd_query_network_reg reg_cmd, uint32_t timeout)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    if(!timeout)
    {
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    uint32_t n;
    ewf_adapter_modem_network_status stat = EWF_ADAPTER_MODEM_NOT_REGISTERED_NOT_SEARCHING;

    while(--timeout)
    {
        while(ewf_adapter_modem_network_registration_read(adapter_ptr, reg_cmd, &n, &stat,NULL,NULL,NULL,NULL,NULL) != EWF_RESULT_OK);
        /* Check if module is registered to network */
        if((stat == EWF_ADAPTER_MODEM_REGISTERED_HOME)||(stat == EWF_ADAPTER_MODEM_REGISTERED_ROAMING))
        {
            break;
        }
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 1U);
    }
    if (!timeout)
    {

        EWF_LOG("Failed to register to Network, timeout occurred\r\n");
        return EWF_RESULT_ADAPTER_NETWORK_NOT_REGISTERED;
    }

    return EWF_RESULT_OK;

}
