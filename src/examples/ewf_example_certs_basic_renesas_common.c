/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Renesas certificate provisioning example
 * @details EWF certificate provisioning example for Renesas cellular modems with SSL/TLS support
 ****************************************************************************/

#include "ewf_adapter_renesas_common.h"

#include "baltimore_ca_cert.pem.h"
#include "ca_cert.pem.h"
#include "device_ec_cert.pem.h"
#include "device_ec_key.pem.h"

ewf_result ewf_example_certs_basic_renesas_common(ewf_adapter* adapter_ptr);

ewf_result ewf_example_certs_basic_renesas_common(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_list(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to list the UFS: ewf_result %d.\r\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_upload(adapter_ptr, EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_CERTIFICATE, (const uint8_t*)baltimore_ca_cert_pem, strlen(baltimore_ca_cert_pem), EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_ID)))
    {
        EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
    }

//    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_upload(adapter_ptr, EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_CERTIFICATE, (const uint8_t*)ca_cert_pem, strlen(ca_cert_pem), EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_ID)))
//    {
//    	EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
//    	return result;
//    }

    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_upload(adapter_ptr, EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_CERTIFICATE, (const uint8_t*)device_ec_cert_pem, strlen(device_ec_cert_pem), EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_CERTIFICATE_ID)))
    {
        EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_upload(adapter_ptr, EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_PRIVATEKEY, (const uint8_t*)device_ec_key_pem, strlen(device_ec_key_pem), EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_PRIVATE_KEY_ID)))
    {
        EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_list(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to list the UFS: ewf_result %d.\r\n", result);
    }

    EWF_LOG("\nCompleted successfully!\n");

    return EWF_RESULT_OK;
}
