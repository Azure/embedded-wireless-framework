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

#ifndef __ewf_adapter_modem_general__h__included__
#define __ewf_adapter_modem_general__h__included__

#include "ewf_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_modem_general Modem adapter general API
 * @ingroup group_adapter_modem
 * @brief The general modem functions
 * @{
 ****************************************************************************/

typedef struct _ewf_adapter_modem_api_general
{
    ewf_result(*manufacturer_read)(ewf_adapter* adapter_ptr, char * info_str, uint16_t * info_str_len_ptr);
    ewf_result(*model_read)(ewf_adapter* adapter_ptr, char * info_str, uint16_t * info_str_len_ptr);
    ewf_result(*revision_read)(ewf_adapter* adapter_ptr, char * info_str, uint16_t * info_str_len_ptr);
    ewf_result(*serial_number_read)(ewf_adapter* adapter_ptr,  const char * snt_str, char * info_str, uint16_t * info_str_len_ptr);
    ewf_result(*imsi_read)(ewf_adapter* adapter_ptr, char * info_str, uint32_t * info_str_len_ptr);
    ewf_result(*message_character_set)(ewf_adapter* adapter_ptr, const char * chset_str);
    ewf_result(*message_character_read)(ewf_adapter* adapter_ptr, char * chset_str, uint32_t * chset_len_ptr);
    ewf_result(*multiplexing_mode_set)(ewf_adapter* adapter_ptr, bool transparency, uint8_t subset, uint8_t port_speed, uint32_t n1, uint8_t t1, uint8_t n2, uint8_t t2, uint8_t t3, uint8_t k);
    ewf_result(*multiplexing_mode_read)(ewf_adapter* adapter_ptr, bool * transparency_ptr, uint8_t *subset_ptr, uint8_t *port_speed_ptr, uint32_t* n1_ptr, uint8_t *t1_ptr, uint8_t *n2_ptr, uint8_t *t2_ptr, uint8_t *t3_ptr, uint8_t *k_ptr);

} ewf_adapter_modem_api_general;

/**
 * @brief Read manufacturer info (+cgmi)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] info_ptr A pointer holding manufacturer info string
 * @param[out] info_str_len_ptr A pointer to lenght of info buffer
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_manufacturer_read(ewf_adapter* adapter_ptr, char * info_str, uint16_t * info_str_len_ptr);

/**
 * @brief Read manufacturer model info (+cgmm)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] info_str A pointer to a string with the model info
 * @param[out] info_str_len_ptr A pointer to lenght of info buffer
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_model_read(ewf_adapter* adapter_ptr, char * info_str, uint16_t * info_str_len_ptr);

/**
 * @brief Read manufacturer model revision info (+cgmr)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] info_ptr A pointer to a string with the model revision info
 * @param[out] info_str_len_ptr A pointer to lenght of info buffer
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_revision_read(ewf_adapter* adapter_ptr, char * info_str, uint16_t * info_str_len_ptr);

/**
 * @brief Read manufacturer product serial number info (+cgsn)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] snt_str String indicating serial number type that has been requested
 * @note if snt_str is NULL, the function will provide IMEI. Not all modems will support this option.
 * @param[out] info_ptr A pointer to a string with the serial number info
 * @param[out] info_str_len_ptr Lenght of the serial number
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_serial_number_read(ewf_adapter* adapter_ptr,  const char * snt_str, char * info_str, uint16_t * info_str_len_ptr);

/**
 * @brief Read the modem IMSI (+cimi)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] info_str A pointer to the buffer that will contain the IMSI
 * @param[out] info_str_len_ptr Pointer to the length of the buffer
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_imsi_read(ewf_adapter* adapter_ptr, char * info_str, uint32_t * info_str_len_ptr);

/**
 * @brief Set TE character set (+cscs)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] chset_str String indicating character set
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_character_set(ewf_adapter* adapter_ptr, const char * chset_str);

/**
 * @brief Read the TE character set (+cscs?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] chset_str  A pointer to buffer that will contain the character set
 * @param[out] chset_len_ptr  Pointer to length of chset buffer data
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_character_read(ewf_adapter* adapter_ptr, char * chset_str, uint32_t * chset_len_ptr);

/**
 * @brief Set Multiplexing mode (+cmux)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] transparency Integer indicating multiplexer transperency mechanism
 * @param[in] subset Integer indicating multiplexer control channel option
 * @param[in] port_speed Integer representing transmission rate
 * @param[in] n1 Maximum framesize (Default 31 for Basic transperency option and 64 for advanced option)
 * @param[in] t1 Timer in units of temn millisecods
 * @param[in] n2 Maximum number of re-transmissions
 * @param[in] t2 response timer for the multiplexer control channel in units of ten milliseconds (t2>t1)
 * @param[in] t3 Wake up response timer in seconds
 * @param[in] k Wiindow size, for Advanced option with Error-Recovery Mode
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_multiplexing_mode_set(ewf_adapter* adapter_ptr, bool transparency, uint8_t subset, uint8_t port_speed, uint32_t n1, uint8_t t1, uint8_t n2, uint8_t t2, uint8_t t3, uint8_t k);

/**
 * @brief Read Multiplexing mode (+cmux?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] transparency_ptr Pointer to integer indicating multiplexer transperency mechanism
 * @param[out] subset_ptr Pointer to integer indicating multiplexer control channel option
 * @param[out] port_speed_ptr Pointer to integer indicating Transmission rate
 * @param[out] n1_ptr Pointer to integer indicating Maximum framesize (Default 31 for Basic transperency option and 64 for advanced option)
 * @param[out] t1_ptr Pointer to integer indicating Timer in units of temn millisecods
 * @param[out] n2_ptr Pointer to integer indicating Maximum number of re-transmissions
 * @param[out] t2_ptr Pointer to integer indicating response timer for the multiplexer control channel in units of ten milliseconds (t2>t1)
 * @param[out] t3_ptr Pointer to integer indicating Wake up response timer in seconds
 * @param[out] k_ptr Pointer to integer indicating Window size, for Advanced option with Error-Recovery Mode
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_multiplexing_mode_read(ewf_adapter* adapter_ptr, bool * transparency_ptr, uint8_t *subset_ptr, uint8_t *port_speed_ptr, uint32_t* n1_ptr, uint8_t *t1_ptr, uint8_t *n2_ptr, uint8_t *t2_ptr, uint8_t *t3_ptr, uint8_t *k_ptr);

/************************************************************************//**
 * @} *** group_adapter_modem_general
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_modem_general__h__included__ */
