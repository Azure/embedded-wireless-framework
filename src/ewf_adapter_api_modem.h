/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework modem adapter API
 * @details Specifiction: 3GPP TS 27.007, 3GPP TS 24.008, 3GPP TS 27.005, 3GPP TS 24.011
 ****************************************************************************/

#ifndef __ewf_adapter_modem__h__included__
#define __ewf_adapter_modem__h__included__

#include "ewf.h"

#include "ewf_adapter_api_modem_types.h"
#include "ewf_adapter_api_modem_general.h"
#include "ewf_adapter_api_modem_network_service.h"
#include "ewf_adapter_api_modem_packet_domain.h"
#include "ewf_adapter_api_modem_sim_utility.h"
#include "ewf_adapter_api_modem_sms.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_modem Adapter Modem API
 * @ingroup group_adapter_api
 * @brief API for modem adapters.
 * @{
 ****************************************************************************/

typedef struct _ewf_adapter_api_modem_data
{
    /**< Current Context ID */
    volatile uint32_t current_context;

} ewf_adapter_api_modem_data;

/************************************************************************//**
 * @defgroup group_adapter_modem_common Modem adapter common API
 * @brief The common modem functions
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @{
 ****************************************************************************/

/**
 * @brief Function to send command that is not implmented in the framework
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] buffer_ptr A pointer to a string holding the command to be sent
 * @param[in] buffer_lenght_ptr Lenght of the command to be sent to the modem
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_custom_command_send(ewf_adapter* adapter_ptr, const char* command_str);

/**
 * @brief Function to read command that is not implmented in the framework
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] buffer_ptr_ptr A pointer to a string destination holding the output of read command
 * @param[in] buffer_length_ptr Lenght of the data in output buffer
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_custom_command_receive(ewf_adapter* adapter_ptr, char** buffer_ptr_ptr, uint32_t * buffer_length_ptr);

#define EWF_ADAPTER_MODEM_FUNCTIONALITY_MINIMUM             ("0") /**< Minimum modem functionality */
#define EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL                ("1") /**< Full modem functionality */
#define EWF_ADAPTER_MODEM_FUNCTIONALITY_DISABLE_TX          ("2") /**< Disable transmission */
#define EWF_ADAPTER_MODEM_FUNCTIONALITY_DISABLE_RX          ("3") /**< Disable reception */
#define EWF_ADAPTER_MODEM_FUNCTIONALITY_DISABLE_ME          ("4") /**< Disable ME */

/**
 * @brief Set the modem functionality (+cfun)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] fun String indicating the functionality value
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_functionality_set(ewf_adapter* adapter_ptr, const char * fun_str);

/**
 * @brief Read the modem functionality (+cfun?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] option A pointer to a integer with the functionality level
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_functionality_read(ewf_adapter* adapter_ptr, uint8_t * fun);

/**
 * @brief Set the clock (+cclk)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out]  time_info_ptr pointer to structure holding clock time values.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_clock_set(ewf_adapter* adapter_ptr, ewf_adapter_modem_time * time_info_ptr);

/**
 * @brief Read the clock (+cclk)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out]  time_info_ptr pointer to structure holding clock time values.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_clock_read(ewf_adapter* adapter_ptr, ewf_adapter_modem_time * time_info_ptr);

/**
 * @brief Set the alarm (+cala)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] alarm_info Pointer to structure holding alarm time values.
 * @param[in] n  Integer indicaitng the index of alarm
 * @param[in] type Integer indicating type of alarm. Defaults are manufacturer specific
 * @param[in] text_str Pointer to string indicating the text to be displayed
 * @param[in] text_len Maximum Lenght of text
 * @param[in] recurr_str Pointer to string indicating days of week for recurring alarm. Eg If alarm is to recurr on
 *                   Monday, Wednesday and Sunday then the string will be "1,3,7". The string "1,2,3,4,5" is
 *                   used to set an alarm for all weekdays.
 * @param[in] recurr_len Maximum length of recurr string
 * @param[in] silent Integer to indicate if alarm is silent or not.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_alarm_set(ewf_adapter* adapter_ptr,  ewf_adapter_modem_time * alarm_info_ptr, uint8_t n, uint32_t type, const char * text_str,  uint32_t text_len, const char * recurr_str, uint32_t recurr_len, bool silent);

/**
 * @brief Delete the alarm (+cald)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in]  index Index of the alarm to be deleted.
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_alarm_delete(ewf_adapter* adapter_ptr, uint32_t index);

/**
 * @brief Read the list of commands (+clac)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] buffer_ptr_ptr Pointer to buffer holding the output list of all the commands
 * @param[out] buffer_length_ptr_ptr Pointer to lenght of buffer
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_commands_list_read(ewf_adapter* adapter_ptr, const char ** buffer_ptr_ptr, uint32_t * response_length_ptr);

/**
 * @brief Read extended error report (+ceer)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] report Pointer to integer indicating report
 * @note This is an optional command and not all modems will have this implemented
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_extended_err_report_read(ewf_adapter* adapter_ptr, uint16_t * report);

/**
 * @brief Read status of MT indicators (+cind)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] indicator_ptr Pointer to buffer contianing inidcator status options
 * @param[out] indicator_len Lenght of data in indicator buffer
 * @note This api will output complete output string from +cind. User application is expected to parse the output to get
 *       required values as per the modem used as the descriptions will differ accross modem manufacturers
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_indicator_status_read(ewf_adapter* adapter_ptr, char * indicator_ptr, uint32_t * indicator_len);

/************************************************************************//**
 * @} *** group_adapter_modem_common
 ****************************************************************************/

/************************************************************************//**
 * @} *** group_adapter_modem
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_modem__h__included__ */
