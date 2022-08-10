/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework modem adapter gerneral API
 * (Reference : 3GPP TS 27.007, 3GPP TS 24.008, 3GPP TS 27.005, 3GPP TS 24.011
 *  specifiction)
 ****************************************************************************/

#ifndef __ewf_adapter_modem_network_service__h__included__
#define __ewf_adapter_modem_network_service__h__included__

#include "ewf_adapter.h"
#include "ewf_adapter_api_modem_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_modem_network_service Modem adapter network service API
 * @ingroup group_adapter_modem
 * @brief The modem network servicefunctions
 * @{
 ****************************************************************************/

typedef struct _ewf_adapter_modem_api_network_service_command
{
	ewf_result(*subscriber_number_read)(ewf_adapter* adapter_ptr, char * alphax_str, uint32_t *  alphax_buffer_len_ptr, char * numberx_str, uint32_t *  numberx_len_ptr, uint32_t * typex_ptr, uint8_t * service_ptr);
	ewf_result(*network_registration_set)(ewf_adapter* adapter_ptr, const char * n_str);
	ewf_result(*network_registration_read)(ewf_adapter* adapter_ptr, uint32_t * n_ptr, ewf_network_status * cmnRegistrationStatus_ptr, ewf_act * act_ptr, uint32_t * tac_ptr, uint32_t * ci_ptr, uint8_t * cause_type_ptr, uint8_t * reject_cause_ptr);
	ewf_result(*operator_select)(ewf_adapter* adapter_ptr, ewf_operator_sel_register_mode registration_mode, ewf_operator_name_format operator_name_format, const char * operator_name_str, ewf_act act);
	ewf_result(*operator_select_read)(ewf_adapter* adapter_ptr, ewf_operator_sel_register_mode * registration_mode_ptr, ewf_operator_name_format * operator_name_format_ptr, char * operator_name_str, uint32_t * operator_name_len_ptr,  ewf_act *act_ptr);
	ewf_result(*operator_list_edit)(ewf_adapter* adapter_ptr, uint32_t index, ewf_operator_name_format format, const char *operator_name_str, uint8_t gsm, uint8_t gsm_compact, uint8_t utran, uint8_t etran, uint8_t ngran);
	ewf_result(*operator_list_read)(ewf_adapter* adapter_ptr, uint32_t * index_ptr, ewf_operator_name_format * format_ptr, char *operator_name_str, uint32_t * operator_name_len_ptr, uint8_t *gsm_ptr, uint8_t *gsm_compact_ptr, uint8_t *utran_ptr, uint8_t *etran_ptr, uint8_t *ngran_ptr);
	ewf_result(*operator_list_select)(ewf_adapter* adapter_ptr, uint8_t list);
	ewf_result(*operator_option_list_read)(ewf_adapter* adapter_ptr, uint8_t * list_ptr);
	ewf_result(*dynamic_parameters_read)(ewf_adapter* adapter_ptr, ewf_edrx_act* act_type_ptr, uint8_t * requested_edrx_ptr, uint8_t * nw_provided_edrx_ptr, uint8_t * paging_time_window_ptr);
	ewf_result(*dynamic_parameters_set)(ewf_adapter* adapter_ptr, uint8_t mode, ewf_edrx_act act_type, uint8_t requested_edrx, uint8_t nw_provided_edrx, uint8_t paging_time_window);
	ewf_result(*power_saving_mode_set)(ewf_adapter* adapter_ptr, uint32_t mode, const char * periodic_rau_str, const char * gprs_ready_timer_str, const char * periodic_tau_str, const char * active_time_str);
	ewf_result(*power_saving_mode_read)(ewf_adapter* adapter_ptr, uint32_t * mode, char * periodic_rau_str, uint8_t * periodic_rau_len_ptr, char * gprs_Ready_timer_str, uint8_t * gprs_ready_timer_len_ptr, char * periodic_tau_str, uint8_t * periodic_tau_len_ptr, char * active_time_str, uint8_t * active_time_len_ptr);
	ewf_result(*signal_strength_read)(ewf_adapter* adapter_ptr, int32_t * rssi_ptr, int32_t *ber_ptr);
	ewf_result(*signal_strength_extended_read)(ewf_adapter* adapter_ptr, int32_t * rxlev_ptr, int32_t * ber_ptr, int32_t * rscp_ptr, int32_t * ecno_ptr, int32_t * rsrq_ptr, int32_t * rsrp_ptr);
	ewf_result(*timezone_reporting_set)(ewf_adapter* adapter_ptr, uint32_t reporting);
	ewf_result(*timezone_reporting_read)(ewf_adapter* adapter_ptr, uint32_t * reporting_ptr);
	ewf_result(*timezone_autoupdate_set)(ewf_adapter* adapter_ptr, uint32_t option);
	ewf_result(*timezone_autoupdate_read)(ewf_adapter* adapter_ptr, uint32_t * option_ptr);

} ewf_adapter_modem_api_network_service_command;

/**
 * @brief Read subscriber number (+cnum)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] alphax_str A pointer to a string assosciated with numberx
 * @param[out] alphax_buffer_len_ptr A pointer to lenght of the alphax string
 * @param[out] numberx_ptr A pointer to a string phone number
 * @param[out] numberx_len_ptr A pointer to lenght of the phone number
 * @param[out] typex_ptr A pointer to integer indicating type of address octet
 * @param[out] service_ptr A pointer to to integer indicating type service related to phone numbers
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_subscriber_number_read(ewf_adapter* adapter_ptr, char * alphax_str, uint32_t *  alphax_buffer_len_ptr, char * numberx_str, uint32_t *  numberx_len_ptr, uint32_t * typex_ptr, uint8_t * service_ptr);

/**
 * @brief Set Network Registration URC (+creg)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] n_str String indicating network registration URC options
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_network_registration_urc_set(ewf_adapter* adapter_ptr, const char * n_str);

/**
 * @brief Read Network Registration (+creg?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] n_ptr Pointer to integer value for network registration URC options
 * @param[out] cmnRegistrationStatus_ptr Pointer circuit mode network registration status
 * @param[out] act_ptr Access technology integer
 * @param[out] cause_type_ptr Pointer to integer value for cause type for registration rejection
 * @param[out] tac_ptr Pointer to integer value for tracking area code in hex format
 * @param[out] ci_ptr Pointer to integer value for cell If in hex format
 * @param[out] reject_cause_ptr Pointer to integer value for reject cause for registration
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_network_registration_read(ewf_adapter* adapter_ptr, uint32_t * n_ptr, ewf_network_status * cmnRegistrationStatus_ptr, ewf_act * act_ptr, uint32_t * tac_ptr, uint32_t * ci_ptr, uint8_t * cause_type_ptr, uint8_t * reject_cause_ptr);

/**
 * @brief Operator selection (+cops)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] registration_mode  Integer, registration mode
 * @param[in] operator_name_format Integer indicating operator name format
 * @param[in] operator_name_str  Pointer to string for operator name
 * @param[in] act  Access technology
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_operator_select(ewf_adapter* adapter_ptr, ewf_operator_sel_register_mode registration_mode, ewf_operator_name_format operator_name_format, const char * operator_name_str, ewf_act act);

/**
 * @brief Read Operator selection (+cops?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] registration_mode_ptr  Pointer to integer, operator select and registration mode
 * @param[out] operator_name_format_ptr Pointer to integer indicating operator name format
 * @param[out] operator_name_ptr  Pointer to string for operator name
 * @param[out] operator_name_len_ptr Pointer to length of operator name
 * @param[out] act_ptr  Access technology
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_operator_select_read(ewf_adapter* adapter_ptr, ewf_operator_sel_register_mode * registration_mode_ptr, ewf_operator_name_format * operator_name_format_ptr, char * operator_name_str, uint32_t * operator_name_len_ptr,  ewf_act *act_ptr);

/**
 * @brief This function is used to edit the PLMN selector with Access Technology lists (+cpol)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] index  the index of operator in the SIM preferred operator list
 * @param[in] operator_name_format Integer indicating operator name format
 * @param[in] operator_name_str  Pointer to string for operator name
 * @param[in] gsm  GSM access technology option
 * @param[in] gsm_compact  GSM compact access technology option
 * @param[in] utran  UTRAN access technology option
 * @param[in] etran  E-TRAN access technology option
 * @param[in] ngran  NG-RAN access technology option
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_operator_list_edit(ewf_adapter* adapter_ptr, uint32_t index, ewf_operator_name_format format, const char *operator_name_str, uint8_t gsm, uint8_t gsm_compact, uint8_t utran, uint8_t etran, uint8_t ngran);

/**
 * @brief Prefered PLMN list read (+cpol?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in,out] index_ptr  the index of operator in the SIM preferred operator list
 * @param[out] operator_name_format_ptr Integer indicating operator name format
 * @param[out] operator_name_str  Pointer to string for operator name
 * @param[out] operator_name_len_ptr Length of operator name
 * @param[out] gsm_ptr  GSM access technology option
 * @param[out] gsm_compact_ptr  GSM compact access technology option
 * @param[out] utran_ptr  UTRAN access technology option
 * @param[out] etran_ptr  E-TRAN access technology option
 * @param[out] ngran_ptr  NG-RAN access technology option
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_operator_list_read(ewf_adapter* adapter_ptr, uint32_t * index_ptr, ewf_operator_name_format * format_ptr, char *operator_name_str, uint32_t * operator_name_len_ptr, uint8_t *gsm_ptr, uint8_t *gsm_compact_ptr, uint8_t *utran_ptr, uint8_t *etran_ptr, uint8_t *ngran_ptr);

/**
 * @brief Preferred PLMN selector with Access Technology list set (+cpls)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] list Integer indicating list options (0: default, 1: opertor controlled, 2: HPLMN selector)
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_operator_list_select(ewf_adapter* adapter_ptr, uint8_t list);

/**
 * @brief Preferred PLMN with Access Technology list read (+cpls)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] list_ptr Pointer to integer indicating list options (0: default, 1: opertor controlled, 2: HPLMN selector)
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_operator_option_list_read(ewf_adapter* adapter_ptr, uint8_t * list_ptr);

/**
 * @brief Read eDRX dynamic parameters (+cedrxrdp)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] act_type_type Access technology type
 * @param[out] requested_edrx_ptr Requested eDRX value
 * @param[out] nw_provided_edrx_ptr Network provided eDRX value
 * @param[out] paging_time_window_ptr Paging time window
 * @note Refer Table Table 10.5.5.32/3GPP TS 24.008 for more details on the values for eDRX paramter values
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_dynamic_parameters_read(ewf_adapter* adapter_ptr, ewf_edrx_act* act_type_ptr, uint8_t * requested_edrx_ptr, uint8_t * nw_provided_edrx_ptr, uint8_t * paging_time_window_ptr);

/**
 * @brief Set eDRX dynamic parameters (+cedrxs)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] act_type  Access technology type
 * @param[in] requested_edrx Requested eDRX value
 * @param[in] nw_provided_edrx Network provided eDRX value
 * @param[in] paging_time_window Paging time window
 * @note Refer Table Table 10.5.5.32/3GPP TS 24.008 for more details on the values for eDRX paramter values
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_dynamic_parameters_set(ewf_adapter* adapter_ptr, uint8_t mode, ewf_edrx_act act_type, uint8_t requested_edrx, uint8_t nw_provided_edrx, uint8_t paging_time_window);

/**
 * @brief Set Power saving mode setting (+cpsms)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] mode Integer, Disable or enable the use of PSM in the UE
 * @param[in] periodic_rau_str String holding requested extended periodic RAU value (e.g. "01000111" equals 70 hours)
 *            For the coding and the value range, see the GPRS Timer 3 IE in 3GPP TS 24.008 [8] Table 10.5.163a/3GPP TS 24.008.
 *            See also 3GPP TS 23.682 [149] and 3GPP TS 23.060 [47]. The default value, if available, is manufacturer specific.
 * @param[in] gprs_ready_timer_str String holding requested GPRS READY timer value (e.g. "01000011" equals 3 decihours or 18 minutes)
 *            For the coding and the value range, see the GPRS Timer IE in 3GPP TS 24.008 [8] Table 10.5.172/3GPP TS 24.008.
 *            See also 3GPP TS 23.060 [47]. The default value, if available, is manufacturer specific.
 * @param[in] periodic_tau_str String holding requested extended periodic TAU value (e.g. "00001010" equals to 100 minutes)
 *            For the coding and the value range, see the GPRS Timer 3 IE in 3GPP TS 24.008 [8] Table 10.5.163a/3GPP TS 24.008.
 *            See also 3GPP TS 23.682 [149] and 3GPP TS 23.401 [82]. The default value, if available, is manufacturer specific.
 * @param[in] active_time_str String holding requested active time value (e.g. "00001111" equals to 30 seconds)
 *            For the coding and the value range, see the GPRS Timer 2 IE in 3GPP TS 24.008 [8] Table 10.5.163/3GPP TS 24.008.
 *            See also 3GPP TS 23.682 [149], 3GPP TS 23.060 [47] and 3GPP TS 23.401 [82]. The default value, if available, is manufacturer specific.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_power_saving_mode_set(ewf_adapter* adapter_ptr, uint32_t mode, const char * periodic_rau_str, const char * gprs_ready_timer_str, const char * periodic_tau_str, const char * active_time_str);

/**
 * @brief Read Power saving mode setting (+?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] mode_ptr Integer, Disable or enable the use of PSM in the UE
 * @param[out] periodic_rau_str String holding requested extended periodic RAU value (e.g. "01000111" equals 70 hours)
 *            For the coding and the value range, see the GPRS Timer 3 IE in 3GPP TS 24.008 [8] Table 10.5.163a/3GPP TS 24.008.
 *            See also 3GPP TS 23.682 [149] and 3GPP TS 23.060 [47]. The default value, if available, is manufacturer specific.
 * @param[out] periodic_rau_len_ptr Length of periodic-rau string
 * @param[out] gprs_Ready_timer_str  String holding requested GPRS READY timer value (e.g. "01000011" equals 3 decihours or 18 minutes)
 *            For the coding and the value range, see the GPRS Timer IE in 3GPP TS 24.008 [8] Table 10.5.172/3GPP TS 24.008.
 *            See also 3GPP TS 23.060 [47]. The default value, if available, is manufacturer specific.
 * @param[out] gprs_ready_timer_len_ptr Length of gprs ready timer string
 * @param[out] periodic_tau_str  String holding requested extended periodic TAU value (e.g. "00001010" equals to 100 minutes)
 *            For the coding and the value range, see the GPRS Timer 3 IE in 3GPP TS 24.008 [8] Table 10.5.163a/3GPP TS 24.008.
 *            See also 3GPP TS 23.682 [149] and 3GPP TS 23.401 [82]. The default value, if available, is manufacturer specific.
 * @param[out] periodic_tau_len_ptr Length of periodic-tau string
 * @param[out] active_time_str  String holding requested active time value (e.g. "00001111" equals to 30 seconds)
 *            For the coding and the value range, see the GPRS Timer 2 IE in 3GPP TS 24.008 [8] Table 10.5.163/3GPP TS 24.008.
 *            See also 3GPP TS 23.682 [149], 3GPP TS 23.060 [47] and 3GPP TS 23.401 [82]. The default value, if available, is manufacturer specific.
 * @param[out] active_time_len_ptr Length of active time string
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_power_saving_mode_read(ewf_adapter* adapter_ptr, uint32_t * mode, char * periodic_rau_str, uint8_t * periodic_rau_len_ptr, char * gprs_Ready_timer_str, uint8_t * gprs_ready_timer_len_ptr, char * periodic_tau_str, uint8_t * periodic_tau_len_ptr, char * active_time_str, uint8_t * active_time_len_ptr);

/**
 * @brief Read signal strength information (+csq)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] rssi_ptr Recieved signal strength
 * @param[out] ber_ptr Channel bit error rate
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_signal_strength_read(ewf_adapter* adapter_ptr, int32_t * rssi_ptr, int32_t *ber_ptr);

/**
 * @brief Read extended signal strength information (+cesq)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] rxlev_ptr Recieved signal strength lebel
 * @param[out] ber_ptr Channel bit error rate
 * @param[out] rscp_ptr Recieved signal code power
 * @param[out] ecno_ptr Ratio of the received energy per PN chip to the total received power spectral density
 * @param[out] rsrq_ptr Reference signal recieved quality
 * @param[out] rsrp_ptr Reference signal recieved power
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_signal_strength_extended_read(ewf_adapter* adapter_ptr, int32_t * rxlev_ptr, int32_t * ber_ptr, int32_t * rscp_ptr, int32_t * ecno_ptr, int32_t * rsrq_ptr, int32_t * rsrp_ptr);

/**
 * @brief Time zone reporting set (+ctzr)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in]  Reporting status
 * @return #ewf_result status code
 TODO: +CTZV and +CTZE URC
 */
ewf_result ewf_adapter_modem_timezone_reporting_set(ewf_adapter* adapter_ptr, uint32_t reporting);

/**
 * @brief Read Time zone reporting (+ctzr?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] reporting_ptr Reporting status
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_timezone_reporting_read(ewf_adapter* adapter_ptr, uint32_t * reporting_ptr);

/**
 * @brief Automatic Time zone update set (+ctzu)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in]  option  Enable/disable indicator
 * @return #ewf_result status code
 * @note Some adapter modules will require reboot for this update to take effect. Refer module documents for more information
 */
ewf_result ewf_adapter_modem_timezone_autoupdate_set(ewf_adapter* adapter_ptr, uint32_t option);

/**
 * @brief Read automatic Time zone update (+ctzu?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out]  option_ptr  Enable/disable indicator
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_timezone_autoupdate_read(ewf_adapter* adapter_ptr, uint32_t * option_ptr);

/************************************************************************//**
 * @} *** group_adapter_modem_network_service
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_modem_network_service__h__included__ */
