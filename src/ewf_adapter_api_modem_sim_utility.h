/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework modem sim card utility API
 * (Reference : 3GPP TS 27.007, 3GPP TS 24.008, 3GPP TS 27.005, 3GPP TS 24.011
 *  specifiction)
 ****************************************************************************/

#ifndef __ewf_adapter_modem_sim_utility__h__included__
#define __ewf_adapter_modem_sim_utility__h__included__

#include "ewf_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_modem_sim_utility Modem adapter simcard utility API
 * @ingroup group_adapter_modem
 * @brief The sim card utility functions
 * @{
 *
 ****************************************************************************/

typedef struct _ewf_adapter_modem_api_sim_utility
{
    ewf_result(*sim_pin_enter)(ewf_adapter* adapter_ptr, const char * pin_str);
    ewf_result(*sim_pin_status_read)(ewf_adapter* adapter_ptr, char * code_str, uint32_t * code_str_len);
    ewf_result(*sim_new_pin_change)(ewf_adapter* adapter_ptr, const char * pin_str, const char * new_pin_str);
    ewf_result(*sim_pin_retries_read)(ewf_adapter* adapter_ptr, const char * sel_code_str, uint32_t* retries_ptr, uint32_t* default_retries_ptr);
    ewf_result(*sim_generic_access_set)(ewf_adapter* adapter_ptr, uint32_t lenght, const char * command_str);
    ewf_result(*sim_restricted_access)(ewf_adapter* adapter_ptr, uint32_t command, uint32_t field, uint32_t p1, uint32_t p2, uint32_t p3, const char * data_str, const char * pathid_str);
    ewf_result(*facility_lock)(ewf_adapter* adapter_ptr, const char * facility_str, const char * password_str,  uint32_t classx);
    ewf_result(*facility_unlock)(ewf_adapter* adapter_ptr, const char * facility_str, const char * password_str, uint32_t classx);
    ewf_result(*facility_password_change)(ewf_adapter* adapter_ptr, const char * facility_str, const char * old_password_str, const char * new_password_str);

} ewf_adapter_modem_api_sim_utility;

/**
 * @brief Enter the modem SIM PIN (+cpin)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] pin_str Pointer to he current SIM PIN string
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_sim_pin_enter(ewf_adapter* adapter_ptr, const char * pin_str);

/**
 * @brief Read the modem SIM PIN status (+cpin?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] code_str A pointer to the buffer that will contain the SIM PIN
 * @param[out] code_str_len The length of the buffer
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_sim_pin_status_read(ewf_adapter* adapter_ptr, char * code_str, uint32_t * code_str_len);

/**
 * @brief Set the modem SIM new PIN (+cpin)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] pin_str Pointer to the current SIM PIN string
 * @param[in] new_pin_str Pointer to the current SIM PIN string
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_sim_pin_change(ewf_adapter* adapter_ptr, const char * pin_str, const char * new_pin_str);

/**
 * @brief Remaining PIN retries (+cpinr)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] sel_code_str Pointer to string containing the type of PIN ("SIM PIN", "SIM PUK", "SIM PIN2", "SIM PUK2")
 * @param[out] retries_ptr Pointer to remaining number of retries
 * @param[out] default_retries_ptr Pointer to remaining number of default/initial retries
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_sim_pin_retries_read(ewf_adapter* adapter_ptr, const char * sel_code_str, uint32_t* retries_ptr, uint32_t* default_retries_ptr);

/**
 * @brief Generic SIM access (+csim)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] length Length of char that are sent in command (twice the actual leght of command or response)
 * @param[in] command_str a pointer to string in hex format, see the 3GPP TS 51.011 [73]
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_sim_generic_access_set(ewf_adapter* adapter_ptr, uint32_t lenght, const char * command_str);

/**
 * @brief Restricted sim access (+crsm)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] command Integer value for command passbed on by MT to the SIM
 * @param[in] field  Integerm Identifier of a elementary datafile on SIM
 * @param[in] p1  Parameter passed on by the MT to the SIM
 * @param[in] p2  Parameter passed on by the MT to the SIM
 * @param[in] p3  Parameter passed on by the MT to the SIM
 * @param[in] data_str  String as Hexadecimal information to be written to the SIM
 * @param[in] pathid_str  String holding the path of an elementary file on the SIM/UICC in hexadecimal format
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_sim_restricted_access(ewf_adapter* adapter_ptr, uint32_t command, uint32_t field, uint32_t p1, uint32_t p2, uint32_t p3, const char * data_str, const char * pathid_str);

/**
 * @brief Lock a modem facility (+clck)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] facility_str a pointer to a string with the facility to read
 * @param[in] password_str a pointer to a string with the password for accessing the facility
 * @param[in] classx Sum of integers each representing a class of information
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_facility_lock(ewf_adapter* adapter_ptr, const char * facility_str, const char * password_str,  uint32_t classx);

/**
 * @brief Unlock a modem facility (+clck)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] facility_str a pointer to a string with the facility to read
 * @param[in] password_str a pointer to a string with the password for accessing the facility
 * @param[in] classx Sum of integers each representing a class of information
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_facility_unlock(ewf_adapter* adapter_ptr, const char * facility_str, const char * password_str, uint32_t classx);

/**
 * @brief Change pwssword of a modem facility (+cpwd)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] facility_str a pointer to a string with the facility to read
 * @param[in] old_password_str a pointer to a string with the current password for accessing the facility
 * @param[in] new_password_str a pointer to a string with the new password for accessing the facility
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_facility_password_change(ewf_adapter* adapter_ptr, const char * facility_str, const char * old_password_str, const char * new_password_str);

/************************************************************************//**
 * @} *** group_adapter_modem_sim_utility
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_modem_sim_utility__h__included__ */
