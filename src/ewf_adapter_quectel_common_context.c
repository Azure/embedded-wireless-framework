/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The EWF Common Quectel adapter driver context management implementation
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

ewf_result ewf_adapter_quectel_common_context_activate(ewf_adapter* adapter_ptr, uint32_t context_id)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if ((context_id < 1) || (16 < context_id))
    {
        EWF_LOG_ERROR("Context parameter out of range.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIACT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QIACT=", context_id_cstr,"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIACT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_context_deactivate(ewf_adapter* adapter_ptr, uint32_t context_id)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if ((context_id < 1) || (16 < context_id))
    {
        EWF_LOG_ERROR("Context parameter out of range.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIACT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QIDEACT=", context_id_cstr,"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QIACT?\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

  return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_context_configure(ewf_adapter* adapter_ptr, uint32_t context_id, uint32_t type, const char * const apn, const char * const username, const char * const password, uint32_t authentication)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if ((context_id < 1) || (16 < context_id))
    {
        EWF_LOG_ERROR("Context parameter out of range.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if ((type < 1) || (3 < type))
    {
        EWF_LOG_ERROR("Type parameter out of range.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (/* (authentication < 0) || */ (authentication < 3))
    {
        EWF_LOG_ERROR("Type parameter out of range.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    char context_id_str[3];
    const char * context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QICSGP=", context_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    char type_str[3];
    const char * type_cstr = ewfl_unsigned_to_str(type, type_str, sizeof(type_str));

    char authentication_str[3];
    const char * authentication_cstr = ewfl_unsigned_to_str(authentication, authentication_str, sizeof(authentication_str));

    if (ewf_result_failed(result = ewf_interface_send_commands(
        interface_ptr,
        "AT+QICSGP=",
        context_id_cstr, ",",
        type_cstr, ",",
        "\"", apn ? apn : "", "\",",
        "\"", username ? username : "", "\",",
        "\"", password ? password : "", "\",",
        authentication_cstr, "\r",
        NULL)))
        return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QICSGP=", context_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_context_configure_dns(ewf_adapter* adapter_ptr, uint32_t context_id, const char * const primary_dns, const char * const secondary_dns)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    if ((context_id < 1) || (16 < context_id))
    {
        EWF_LOG_ERROR("Context parameter out of range.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    char context_id_str[3];
    const char * context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QIDNSCFG=", context_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    if (ewf_result_failed(result = ewf_interface_send_commands(
        interface_ptr,
        "AT+QIDNSCFG=",
        context_id_cstr, ",",
        "\"", primary_dns ? primary_dns : "", "\",",
        "\"", secondary_dns ? secondary_dns : "",
        "\r", NULL)))
        return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QIDNSCFG=", context_id_cstr, "\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

    return EWF_RESULT_OK;
}
