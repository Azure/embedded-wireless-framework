/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework modem adapter packt domain API
 * (Reference : 3GPP TS 27.007, 3GPP TS 24.008, 3GPP TS 27.005, 3GPP TS 24.011
 *  specifiction)
 ****************************************************************************/

#ifndef __ewf_adapter_modem_packet_domain__h__included__
#define __ewf_adapter_modem_packet_domain__h__included__

#include "ewf_adapter.h"
#include "ewf_adapter_api_modem_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_modem_packet_domain Modem adapter common API
 * @ingroup group_adapter_modem
 * @brief The common modem functions
 * @{
 *
 ****************************************************************************/

typedef struct _ewf_adapter_modem_api_packet_domain
{
    ewf_result(*eps_network_registration_urc_set)(ewf_adapter* adapter_ptr, const char* n_str);
    ewf_result(*eps_network_registration_read)(ewf_adapter* adapter_ptr, ewf_network_status * epsregistrationstatus_ptr, ewf_act * act_ptr, uint32_t * tac_ptr, uint32_t * ci_ptr, uint32_t rac_ptr, uint8_t * cause_type_ptr, uint8_t * reject_cause_ptr);
    ewf_result(*gprs_network_registration_urc_set)(ewf_adapter* adapter_ptr, const char* n_str);
    ewf_result(*gprs_network_registration_read)(ewf_adapter* adapter_ptr, ewf_network_status * status_ptr, ewf_act* act_ptr, uint32_t * tac_ptr, uint32_t * ci_ptr,  uint32_t * rac_ptr, uint8_t * cause_type_ptr, uint8_t * reject_cause_ptr);
    ewf_result(*init_pdp_activate)(ewf_adapter* adapter_ptr, uint32_t n, bool attachPDN);
    ewf_result(*init_pdp_activation_config_read)(ewf_adapter* adapter_ptr, uint32_t * n_ptr, bool * attachpdn_ptr);
    ewf_result(*pdp_apn_set)(ewf_adapter* adapter_ptr, uint32_t context_id, const char * pdptype_ptr, const char* apn_ptr);
    ewf_result(*pdp_apn_read)(ewf_adapter* adapter_ptr, uint32_t context_id, char* pdptype_ptr, char* apn_ptr, uint8_t apn_len);
    ewf_result(*pdp_context_authentication_set)(ewf_adapter* adapter_ptr, uint32_t context_id, const char * userid_str, const char * password_str);
    ewf_result(*pdp_data_mode_enter)(ewf_adapter* adapter_ptr, const char * l2p_str, uint32_t context_id);
    ewf_result(*packet_service_activate)(ewf_adapter* adapter_ptr, const char * contextid);
    ewf_result(*packet_service_deactivate)(ewf_adapter* adapter_ptr, const char * contextid);
    ewf_result(*network_attach)(ewf_adapter* adapter_ptr);
    ewf_result(*network_dettach)(ewf_adapter* adapter_ptr);
    ewf_result(*network_attach_status_read)(ewf_adapter* adapter_ptr, bool *state_ptr);

} ewf_adapter_modem_api_packet_domain;

/**
 * @brief EPS Network Registration (+cereg)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] n_str String indicating EPS network registration URC options
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_eps_network_registration_urc_set(ewf_adapter* adapter_ptr, const char * n_str);

/**
 * @brief Read EPS Network Registration (+cereg?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] n_ptr Pointer to integer value for network registration URC options
 * @param[out] epsregistrationstatus_ptr Pointer to eps network registration status
 * @param[out] act_ptr Access technology integer
 * @param[out] tac_ptr Pointer to integer value for tracking area code in hex format
 * @param[out] ci_ptr Pointer to integer value for cell id in hex format
 * @param[out] rac_ptr Pointer to integer value for routing area code in hex format
 * @param[out] cause_type_ptr Pointer to integer value for cause type for registration rejection
 * @param[out] reject_cause_ptr Pointer to integer value for reject cause for registration
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_eps_network_registration_read(ewf_adapter* adapter_ptr, ewf_network_status * epsregistrationstatus_ptr, ewf_act * act_ptr, uint32_t * tac_ptr, uint32_t * ci_ptr, uint32_t rac_ptr, uint8_t * cause_type_ptr, uint8_t * reject_cause_ptr);

/**
 * @brief GPRS Network Registration (+cgreg)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] n_str String indicating gprs network registration URC options
 * @note This is an optional command as per 3GPP, not all modems will support this
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_gprs_network_registration_urc_set(ewf_adapter* adapter_ptr, const char * n_str);

/**
 * @brief Read GPRS Network Registration (+cgreg)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] n_ptr Pointer to integer value for network registration URC options
 * @param[out] status_ptr Pointer to eps network registration status
 * @param[out] act_ptr Access technology integer
 * @param[out] tac_ptr Pointer to integer value for tracking area code in hex format
 * @param[out] ci_ptr Pointer to integer value for cell If in hex format
 * @param[out] rac_ptr Pointer to integer value for routing area code in hex format
 * @param[out] cause_type_ptr Pointer to integer value for cause type for registration rejection
 * @param[out] reject_cause_ptr Pointer to integer value for reject cause for registration
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_gprs_network_registration_read(ewf_adapter* adapter_ptr, ewf_network_status * status_ptr, ewf_act* act_ptr, uint32_t * tac_ptr, uint32_t * ci_ptr,  uint32_t * rac_ptr, uint8_t * cause_type_ptr, uint8_t * reject_cause_ptr);

/**
 * @brief Initial PDP context activation (+cipca)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in]  n Activation option
 * @param[in]  attachPDN EPS attach with or without PDN connection
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_init_pdp_activate(ewf_adapter* adapter_ptr, uint32_t n, bool attachPDN);

/**
 * @brief Read Initial PDP context activation config(+cipca)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out]  n_ptr Activation option
 * @param[out]  attachpdn_ptr EPS attach with or without PDN connection
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_init_pdp_activation_config_read(ewf_adapter* adapter_ptr, uint32_t * n_ptr, bool * attachpdn_ptr);

/**
 * @brief Set PDP context APN (+cgdcont)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] contextid Integer value for PDP context definition id.
 * @param[in] pdptype Integer for PDP type
 * @param[in] apn_str Pointer to string holding apn
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_pdp_apn_set(ewf_adapter* adapter_ptr, uint32_t context_id, const char * pdptype_ptr, const char* apn_ptr);

/**
 * @brief Read PDP context APN (+cgdcont?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] contextid Integer value for PDP context definition id.
 * @param[out] pdptype_ptr Integer for PDP type
 * @param[out] apn_str Pointer to string holding apn
 * @param[out] apn_str_len Pointer to lenght of apn string
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_pdp_apn_read(ewf_adapter* adapter_ptr, uint32_t context_id, char* pdptype_ptr, char* apn_ptr, uint8_t apn_str_len);

/**
 * @brief Set PDP context authentication parameter (+cgauth)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] contextid Integer value for PDP context definition id.
 * @param[in] userid_str Pointer to username/user id string
 * @param[in] pdptype Integer for PDP type
 * @param[in] password_str Pointer to a string with the password for accessing the facility
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_pdp_context_authentication_set(ewf_adapter* adapter_ptr, uint32_t context_id, const char * userid_str, const char * password_str);

/**
 * @brief Enter data state (+cgdata)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] l2p_str String inidicating the layer 2 protocol to be used between TE and the MT
 * @note Refer to modem user manual for supported Layer 2 protocol options. This command immplementation is 3GPP optional
 * @param[in] contextid Integer value for PDP context definition id.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_pdp_data_mode_enter(ewf_adapter* adapter_ptr, const char * l2p_str, uint32_t context_id);

/**
 * @brief Activate context (+cgact)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] context_id  Integer indicating context definition id
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_packet_service_activate(ewf_adapter* adapter_ptr, uint32_t context_id);

/**
 * @brief De-activate context (+cgact)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] context_id  Integer indicating context definition id
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_packet_service_deactivate(ewf_adapter* adapter_ptr, uint32_t context_id);

/**
 * @brief Attach to the Packet domain service (+cgatt)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_packet_service_attach(ewf_adapter* adapter_ptr);

/**
 * @brief Detach form the Packet domain service (+cgatt)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_packet_service_detach(ewf_adapter* adapter_ptr);

/**
 * @brief Read the network attach status (+cgatt?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] state_ptr Pointer to integer value indicating status of network attachment
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_network_attach_status_read(ewf_adapter* adapter_ptr, bool *state_ptr);

/************************************************************************//**
 * @} *** group_adapter_modem_packet_domain
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_modem_packet_domain__h__included__ */
