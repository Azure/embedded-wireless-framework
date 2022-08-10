/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter DTLS API
 ****************************************************************************/

#ifndef __ewf_adapter_dtls__h__included__
#define __ewf_adapter_dtls__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_dtls Adapter DTLS API
 * @ingroup group_adapter_api
 * @brief DTLS functions
 * @{
 *
 ****************************************************************************/

/** @brief the DTLS context handle type */
typedef int ewf_adapter_dtls_context_handle;

/** @brief the DTLS context information type */
typedef struct _ewf_adapter_dtls_context_info
{
    /** The total number of handles available */
    uint32_t handle_count;

    /** The minimum valid handle value */
    uint32_t minimum_handle;

    /** The maximum valid handle value */
    uint32_t maximum_handle;

} ewf_adapter_dtls_context_info;

/** @brief the DTLS context version type */
typedef enum _ewf_adapter_dtls_context_version
{
    DTLS_1_0 = 0x0100,
    DTLS_1_2 = 0x0102,

} ewf_adapter_dtls_context_version;

/** @brief the DTLS context cipher suite type */
typedef enum _ewf_adapter_dtls_context_cipher_suite
{
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_ALL,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_RSA_WITH_AES_256_CBC_SHA,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_RSA_WITH_AES_128_CBC_SHA,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_RSA_WITH_RC4_128_SHA,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_RSA_WITH_RC4_128_MD5,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_RSA_WITH_3DES_EDE_CBC_SHA,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_RSA_WITH_AES_256_CBC_SHA256,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_ECDHE_RSA_WITH_RC4_128_SHA,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_ECDHE_RSA_WITH_AES_128_CBC_SHA,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_ECDHE_RSA_WITH_AES_256_CBC_SHA,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_ECDHE_RSA_WITH_AES_128_CBC_SHA256,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_ECDHE_RSA_WITH_AES_256_CBC_SHA384,
    EWF_ADAPTER_DTLS_CONTEXT_CIPHER_SUITE_ECDHE_RSA_WITH_AES_128_GCM_SHA256,

} ewf_adapter_dtls_context_cipher_suite;

#define EWF_DTLS_CONTEXT_SETTING_TLS_VERSION "tls version"
#define EWF_DTLS_CONTEXT_SETTING_DTLS_VERSION "dtls version"
#define EWF_DTLS_CONTEXT_SETTING_CIPHER_SUITE "cipher"

/** @brief the DTLS context API structure */
typedef struct _ewf_adapter_api_dtls
{
    ewf_result(*get_info)(ewf_adapter* adapter_ptr, ewf_adapter_dtls_context_info* info_ptr);
    ewf_result(*configure)(ewf_adapter* adapter_ptr, ewf_adapter_dtls_context_handle context_handle, const char* setting_str, const char* value_str);

    ewf_result(*set_version)(ewf_adapter* adapter_ptr, ewf_adapter_dtls_context_handle context_handle, ewf_adapter_dtls_context_version tls_version);
    ewf_result(*set_cipher_suite)(ewf_adapter* adapter_ptr, ewf_adapter_dtls_context_handle context_handle, ewf_adapter_dtls_context_cipher_suite cipher_suite);
    ewf_result(*configure_custom_parameter)(ewf_adapter* adapter_ptr, ewf_adapter_dtls_context_handle context_handle, const char* parameter, const char* value);

} ewf_adapter_api_dtls;

/**
 * @brief Set the DTLS version to be used
 */
ewf_result ewf_adapter_dtls_set_version(ewf_adapter* adapter_ptr, ewf_adapter_dtls_context_handle context_handle, ewf_adapter_dtls_context_version* version_ptr);

/**
 * @brief Set the DTLS cipher suite
 */
ewf_result ewf_adapter_dtls_context_set_cipher_suite(ewf_adapter* adapter_ptr, ewf_adapter_dtls_context_handle context_handle, ewf_adapter_dtls_context_cipher_suite cipher_suite);

/**
 * @brief Set a custom DTLS parameter value
 */
ewf_result ewf_adapter_dtls_context_configure_custom_parameter(ewf_adapter* adapter_ptr, ewf_adapter_dtls_context_handle context_handle, const char* parameter, const char* value);

/************************************************************************//**
 * @} *** group_adapter_dtls
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_dtls__h__included__ */
