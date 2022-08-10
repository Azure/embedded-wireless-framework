/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter TLS API
 ****************************************************************************/

#ifndef __ewf_adapter_tls__h__included__
#define __ewf_adapter_tls__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_tls The adapter TLS API
 * @ingroup group_adapter_api
 * @brief The adapter TLS API
 * @{
 *
 ****************************************************************************/

/** @brief the TLS version type */
typedef enum _ewf_adapter_tls_version
{
    SSL_1_0 = 0x0001,
    SSL_2_0 = 0x0002,
    SSL_3_0 = 0x0003,
    TLS_1_0 = 0x0100,
    TLS_1_1 = 0x0101,
    TLS_1_2 = 0x0102,
    TLS_1_3 = 0x0103,

} ewf_adapter_tls_version;

/** @brief the TLS key agreement */
typedef enum _ewf_adapter_tls_key_agreement
{
    EWF_ADAPTER_TLS_KEY_AGREEMENT_ANY,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_DH_RSA,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_DHE_RSA_FS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_ECDH_RSA,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_ECDHE_RSA_FS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_DH_DSS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_DHE_DSS_FS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_ECDH_ECDSA,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_ECDHE_ECDSA_FS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_ECDH_EDDSA,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_ECDHE_EDDSA_FS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_PSK,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_PSK_RSA,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_DHE_PSK_FS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_ECDHE_PSK_FS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_SRP,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_SRP_DSS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_SRP_RSA,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_KERBEROS,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_DH_ANON,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_ECDH_ANON,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_GOST_R_34_10_94,
    EWF_ADAPTER_TLS_KEY_AGREEMENT_GOST_R_34_10_2001,

} ewf_adapter_tls_key_agreement;

/** @brief the TLS cipher */
typedef enum _ewf_adapter_tls_cipher
{
    EWF_ADAPTER_TLS_CIPHER_ANY,
    EWF_ADAPTER_TLS_CIPHER_NONE,
    EWF_ADAPTER_TLS_CIPHER_AES_GCM,
    EWF_ADAPTER_TLS_CIPHER_AES_CCM,
    EWF_ADAPTER_TLS_CIPHER_AES_CBC,
    EWF_ADAPTER_TLS_CIPHER_CAMELIA_GCM,
    EWF_ADAPTER_TLS_CIPHER_CAMELIA_CBC,
    EWF_ADAPTER_TLS_CIPHER_ARIA_GCM,
    EWF_ADAPTER_TLS_CIPHER_ARIA_CBC,
    EWF_ADAPTER_TLS_CIPHER_SEED_CBC,
    EWF_ADAPTER_TLS_CIPHER_3DES_EDE_CBC,
    EWF_ADAPTER_TLS_CIPHER_GOST_28147_89_CNT,
    EWF_ADAPTER_TLS_CIPHER_IDEA_CBC,
    EWF_ADAPTER_TLS_CIPHER_DES_CBC,
    EWF_ADAPTER_TLS_CIPHER_RC2_CBC,
    EWF_ADAPTER_TLS_CIPHER_CHACHA20_POLY1305,
    EWF_ADAPTER_TLS_CIPHER_RC4,

} ewf_adapter_tls_cipher;

/** @brief the TLS data integrity */
typedef enum _ewf_adapter_tls_data_integrity
{
    EWF_ADAPTER_TLS_DATA_INTEGRITY_HMAC_MD5,
    EWF_ADAPTER_TLS_DATA_INTEGRITY_HMAC_SHA1,
    EWF_ADAPTER_TLS_DATA_INTEGRITY_HMAC_SHA256,
    EWF_ADAPTER_TLS_DATA_INTEGRITY_HMAC_SHA384,
    EWF_ADAPTER_TLS_DATA_INTEGRITY_AEAD,
    EWF_ADAPTER_TLS_DATA_INTEGRITY_GOST_28147_89_IMIT,
    EWF_ADAPTER_TLS_DATA_INTEGRITY_GOST_R_34_11_94,

} ewf_adapter_tls_data_integrity;

/**
 * @brief set the TLS version of the configuration
 * buffer_ptr points to a ewf_adapter_tls_version
 * buffer_length should be sizeof(ewf_adapter_tls_version)
 */
#define EWF_TLS_CONFIGURATION_SETTING_VERSION                      "common_tls_version"
#define EWF_TLS_CONFIGURATION_SETTING_KEY_AGREEMENT                "common_key_agreement"
#define EWF_TLS_CONFIGURATION_SETTING_CIPHER                       "common_cipher"
#define EWF_TLS_CONFIGURATION_SETTING_DATA_INTEGRITY               "common_data_integrity"

#define EWF_TLS_CONFIGURATION_SETTING_STORE_CA_CERTIFICATE         "common_store_ca_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_STORE_ROOT_CERTIFICATE       "common_store_root_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_STORE_SERVER_CERTIFICATE     "common_store_server_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_STORE_CLIENT_CERTIFICATE     "common_store_client_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_STORE_DEVICE_KEY             "common_store_device_key"
#define EWF_TLS_CONFIGURATION_SETTING_STORE_PSK                    "common_store_psk"

#define EWF_TLS_CONFIGURATION_SETTING_DELETE_CA_CERTIFICATE        "common_delete_ca_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_DELETE_ROOT_CERTIFICATE      "common_delete_root_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_DELETE_SERVER_CERTIFICATE    "common_delete_server_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_DELETE_CLIENT_CERTIFICATE    "common_delete_client_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_DELETE_DEVICE_KEY            "common_delete_device_key"
#define EWF_TLS_CONFIGURATION_SETTING_DELETE_PSK                   "common_delete_psk"

#define EWF_TLS_CONFIGURATION_SETTING_OTA_CA_CERTIFICATE           "common_ota_ca_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_OTA_ROOT_CERTIFICATE         "common_ota_root_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_OTA_SERVER_CERTIFICATE       "common_ota_server_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_OTA_CLIENT_CERTIFICATE       "common_ota_client_certificate"
#define EWF_TLS_CONFIGURATION_SETTING_OTA_DEVICE_KEY               "common_ota_device_key"
#define EWF_TLS_CONFIGURATION_SETTING_OTA_PSK                      "common_ota_psk"

/** @brief the TLS configuration API */
typedef struct _ewf_adapter_api_tls
{
    ewf_result(*configuration_setting_set)(ewf_adapter* adapter_ptr, uint32_t configuration_id, const char* setting_str, const void* buffer_ptr, uint32_t buffer_length);
    ewf_result(*configuration_setting_query)(ewf_adapter* adapter_ptr, uint32_t configuration_id, const char* setting_str, const void* buffer_ptr, uint32_t* buffer_length_ptr);

} ewf_adapter_api_tls;

/**
 * @brief Set a TLS configuration setting
 */
ewf_result ewf_adapter_tls_configuration_setting_set(ewf_adapter* adapter_ptr, uint32_t configuration_id, const char* setting_str, const void* buffer_ptr, uint32_t buffer_length);

/**
 * @brief Query a TLS configuration
 */
ewf_result ewf_adapter_tls_configuration_setting_query(ewf_adapter* adapter_ptr, uint32_t configuration_id, const char* setting_str, const void* buffer_ptr, uint32_t* buffer_length_ptr);

/************************************************************************//**
 * @} *** group_adapter_tls
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_tls__h__included__ */
