/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Renesas RYZ014
 * @details EWF certificate provisioning example for Renesas RYZ014
 ****************************************************************************/

#include "ewf_adapter_renesas_ryz014.h"
#include "ewf_lib.h"

#include "baltimore_ca_cert.pem.h"
#include "ca_cert.pem.h"
#include "device_ec_cert.pem.h"
#include "device_ec_key.pem.h"

ewf_result ewf_example_certs_basic_renesas_ryz014(ewf_adapter* adapter_ptr);

ewf_result ewf_example_certs_basic_renesas_ryz014(ewf_adapter* adapter_ptr)
{
	ewf_result result;

	if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_nvm_list(adapter_ptr)))
	{
		EWF_LOG_ERROR("Failed to list the UFS: ewf_result %d.\r\n", result);
	}

	if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_nvm_upload(adapter_ptr, EWF_FILE_TYPE_CERTIFICATE, (const uint8_t*)baltimore_ca_cert_pem, strlen(baltimore_ca_cert_pem), EWF_CA_CERTIFICATE_ID)))
	{
		EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
	}

	//	if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_nvm_upload(adapter_ptr, EWF_FILE_TYPE_CERTIFICATE, (const uint8_t*)ca_cert, strlen(ca_cert), EWF_CA_CERTIFICATE_ID)))
	//	{
	//		EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
	//		return result;
	//	}

	if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_nvm_upload(adapter_ptr, EWF_FILE_TYPE_CERTIFICATE, (const uint8_t*)device_ec_cert_pem, strlen(device_ec_cert_pem), EWF_CLIENT_CERTIFICATE_ID)))
	{
		EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
	}

	if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_nvm_upload(adapter_ptr, EWF_FILE_TYPE_PRIVATEKEY, (const uint8_t*)device_ec_key_pem, strlen(device_ec_key_pem), EWF_PRIVATE_KEY_ID)))
	{
		EWF_LOG_ERROR("Failed to upload: ewf_result %d.\r\n", result);
	}

	if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_nvm_list(adapter_ptr)))
	{
		EWF_LOG_ERROR("Failed to list the UFS: ewf_result %d.\r\n", result);
	}

	EWF_LOG("\nDone!\n");

	while (1)
	{
	    tx_thread_sleep(100);
	}
}
