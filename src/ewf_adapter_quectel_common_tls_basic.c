/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework Quectel common TLS basic API implementation
 * The TLS basic API was designed to work with a singel set of certificates for the adapter.
 * This cover simple scenarios, when the adpater is connecting to a single server, with a single configuration.
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"
#include "ewf_platform.h"
#include "ewf_lib.h"

ewf_adapter_api_tls_basic ewf_adapter_quectel_common_api_tls_basic  =
{
    ewf_adapter_quectel_common_tls_basic_init,
    ewf_adapter_quectel_common_tls_basic_clean,
};

/******************************************************************************
 *
 * TLS basic API - Control
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_tls_basic_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Enable SSL */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTCFG=\"ssl\",0,1,2\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Select the SSL version */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QMTCFG=\"version\",0,4\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

#ifdef EWF_DEBUG
    /* Query and log the SSL state */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QSSLSTATE\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;
#endif

	return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_tls_basic_stop(ewf_adapter* adapter_ptr)
{
	return EWF_RESULT_OK;
}

/******************************************************************************
 *
 * TLS basic API - URC handler
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_tls_basic_urc_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    /* No SSL specific URCs handled */
    return EWF_RESULT_UNHANDLED_URC;
}

/******************************************************************************
 *
 * TLS basic API
 *
 ******************************************************************************/

ewf_result ewf_adapter_quectel_common_tls_basic_init(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* SSL CA certificate */
    static const char* const ca_cert = "baltimore_ca_cert.pem";
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QSSLCFG=\"cacert\",2,\"", ca_cert, "\"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* SSL client certificate */
    static const char* const device_cert = "device_ec_cert.pem";
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QSSLCFG=\"clientcert\",2,\"", device_cert, "\"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* SSL client key */
    static const char* const device_key = "device_ec_key.pem";
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "AT+QSSLCFG=\"clientkey\",2,\"", device_key, "\"\r", NULL))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* SSL authentication mode: server authentication */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QSSLCFG=\"seclevel\",2,2\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* SSL authentication version */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QSSLCFG=\"sslversion\",2,4\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Cipher suite */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QSSLCFG=\"ciphersuite\",2,0xFFFF\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_verify_response(interface_ptr, "\r\nOK\r\n"))) return result;

    /* Ignore the time of authentication */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QSSLCFG=\"ignorelocaltime\",1\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

#ifdef EWF_DEBUG
    /* Query and log the SSL state */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT+QSSLSTATE\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_response(interface_ptr))) return result;

#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_quectel_common_tls_basic_clean(ewf_adapter* adapter_ptr)
{
    return EWF_RESULT_OK;
}
