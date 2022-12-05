/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Renesas certificate provisioning example
 * @details EWF certificate provisioning example for Renesas cellular modems with SSL/TLS support
 ****************************************************************************/


/**
* @brief Certificate & Key header file include section
* @details Include the certificate and key header files that will be
* provisioned on the adapter/modem
*/
#include "root_ca_cert.pem.h"
#include "ca_cert.pem.h"
#include "device_cert.pem.h"
#include "device_key.pem.h"

#include "ewf_adapter_renesas_common.h"

ewf_result ewf_example_certs_basic_renesas_common(ewf_adapter* adapter_ptr);

ewf_result ewf_example_certs_basic_renesas_common(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result;

#if defined(EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_ID) && defined(EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_BUFFER_NAME)

    /* By default ROOT CA certificate will be used */
    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_upload(adapter_ptr,
            EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_CERTIFICATE,
            (const uint8_t*)EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_BUFFER_NAME,
			sizeof(EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_BUFFER_NAME)-1,
            EWF_CONFIG_ADAPTER_RENESAS_COMMON_ROOT_CA_CERTIFICATE_ID)))
    {
        EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
    }
#endif

#if defined(EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_ID) && defined(EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_BUFFER_NAME)
    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_upload(adapter_ptr,
            EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_CERTIFICATE,
            (const uint8_t*)EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_BUFFER_NAME,
			sizeof(EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_BUFFER_NAME) - 1,
            EWF_CONFIG_ADAPTER_RENESAS_COMMON_USER_CA_CERTIFICATE_ID)))
    {
        EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
        return result;
    }
#endif

    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_upload(adapter_ptr,
            EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_CERTIFICATE,
            (const uint8_t*)EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_CERTIFICATE_BUFFER_NAME,
			sizeof(EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_CERTIFICATE_BUFFER_NAME) - 1,
            EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_CERTIFICATE_ID)))
    {
        EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_upload(adapter_ptr,
            EWF_ADAPTER_RENESAS_COMMON_FILE_TYPE_PRIVATEKEY,
            (const uint8_t*)EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_PRIVATE_KEY_BUFFER_NAME,
			sizeof(EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_PRIVATE_KEY_BUFFER_NAME)-1,
            EWF_CONFIG_ADAPTER_RENESAS_COMMON_CLIENT_PRIVATE_KEY_ID)))
    {
        EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
    }

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_adapter_renesas_common_nvm_list(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to list the UFS: ewf_result %d.\r\n", result);
    }
#endif

    EWF_LOG("\r\nCompleted successfully!\r\n");

    return EWF_RESULT_OK;
}
