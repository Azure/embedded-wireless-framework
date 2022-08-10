/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Quectel certificate provisioning example
 * @details EWF certificate provisioning example for all Quectel cellular modems with SSL/TLS support
 ****************************************************************************/

#include "ewf_adapter_quectel_common.h"

#include "baltimore_ca_cert.pem.h"
#include "ca_cert.pem.h"
#include "device_ec_cert.pem.h"
#include "device_ec_key.pem.h"

ewf_result ewf_example_certs_basic_quectel_common(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result;

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_list(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to list the UFS, ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_delete(adapter_ptr, "baltimore_ca_cert.pem")))
    {
        EWF_LOG("Failed to delete file, ewf_result %d.\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_delete(adapter_ptr,"ca_cert.pem")))
    {
        EWF_LOG("Failed to delete file, ewf_result %d.\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_delete(adapter_ptr,"device_ec_cert.pem")))
    {
        EWF_LOG("Failed to delete file, ewf_result %d.\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_delete(adapter_ptr,"device_ec_key.pem")))
    {
        EWF_LOG("Failed to delete file, ewf_result %d.\n", result);
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_upload(adapter_ptr,"baltimore_ca_cert.pem", (const uint8_t*) baltimore_ca_cert_pem, strlen(baltimore_ca_cert_pem))))
    {
        EWF_LOG_ERROR("Failed to upload, ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_upload(adapter_ptr,"ca_cert.pem", (const uint8_t*) ca_cert_pem, strlen(ca_cert_pem))))
    {
        EWF_LOG_ERROR("Failed to upload, ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_upload(adapter_ptr,"device_ec_cert.pem", (const uint8_t*) device_ec_cert_pem, strlen(device_ec_cert_pem))))
    {
        EWF_LOG_ERROR("Failed to upload, ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_upload(adapter_ptr,"device_ec_key.pem", (const uint8_t*) device_ec_key_pem, strlen(device_ec_key_pem))))
    {
        EWF_LOG_ERROR("Failed to upload, ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_quectel_common_ufs_list(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to list the UFS, ewf_result %d.\n", result);
    }

    EWF_LOG("\nCompleted successfully!\n");

    return EWF_RESULT_OK;
}
