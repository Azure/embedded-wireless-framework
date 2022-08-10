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

#ifndef __ewf_adapter_modem_sms__h__included__
#define __ewf_adapter_modem_sms__h__included__

#include "ewf_adapter.h"

#ifdef EWF_SMS_SUPPORT_ENABLED

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_modem_sms Modem adapter SMS API
 * @ingroup group_adapter_modem
 * @brief The Short Message Service (SMS) functions
 * @{
 *
 ****************************************************************************/

typedef struct _ewf_adapter_modem_api_sms
{
    ewf_result(*message_format_set)(ewf_adapter* adapter_ptr, bool mode);
    ewf_result(*message_format_read)(ewf_adapter* adapter_ptr, bool * mode_ptr);
    ewf_result(*message_send)(ewf_adapter* adapter_ptr, const char * phone_num_str, const char * message_str);
    ewf_result(*message_more_send_config_set)(ewf_adapter* adapter_ptr, uint8_t n);
    ewf_result(*message_more_send_config_read)(ewf_adapter* adapter_ptr, uint8_t * n);
    ewf_result(*message_read)(ewf_adapter* adapter_ptr, uint32_t index, char * message_str, uint32_t * message_str_len);
    ewf_result(*message_delete)(ewf_adapter* adapter_ptr, uint32_t index);
    ewf_result(*message_list)(ewf_adapter* adapter_ptr, uint8_t stat);
    ewf_result(*message_service_select)(ewf_adapter* adapter_ptr, uint8_t service);
    ewf_result(*message_service_read)(ewf_adapter* adapter_ptr, uint8_t * service, bool * mt_ptr, bool * mo_ptr, bool* bm_ptr);
    ewf_result(*message_service_center_address_set)(ewf_adapter* adapter_ptr, const char * sca_str, uint32_t tosca);
    ewf_result(*message_service_center_address_read)(ewf_adapter* adapter_ptr, char * sca_str, uint32_t * tosca_ptr);
    ewf_result(*message_show_header_values_mode_set)(ewf_adapter* adapter_ptr, bool show);
    ewf_result(*message_show_header_values_mode_read)(ewf_adapter* adapter_ptr, bool * show_ptr);
    ewf_result(*message_profile_save)(ewf_adapter* adapter_ptr, uint8_t profile);
    ewf_result(*message_profile_restore)(ewf_adapter* adapter_ptr, uint8_t profile);
    ewf_result(*message_preffered_storage_set)(ewf_adapter* adapter_ptr, const char * mem1_str, const char * mem2_str, const char *mem3_str);
    ewf_result(*message_preffered_storage_read)(ewf_adapter* adapter_ptr, uint32_t * used1_ptr, uint32_t * total1_ptr, uint32_t * used2_ptr, uint32_t * total2_ptr, uint32_t * used3_ptr, uint32_t* total3_ptr);
    ewf_result(*message_to_memory_write)(ewf_adapter* adapter_ptr, const char * address_str, uint32_t address_type, uint32_t stat, uint32_t * index_ptr);
    ewf_result(*message_send)(ewf_adapter* adapter_ptr, uint32_t index, const char * address_str, uint32_t address_len, uint32_t address_type);
    ewf_result(*message_recieve_indications_set)(ewf_adapter* adapter_ptr, uint32_t mode, uint32_t mt, uint32_t bm, uint32_t ds, uint32_t bfr);
    ewf_result(*message_recieve_indications_read)(ewf_adapter* adapter_ptr, uint32_t * mode_ptr, uint32_t * mt_ptr, uint32_t * bm_ptr, uint32_t * ds_ptr, uint32_t * bfr_ptr);
    ewf_result(*message_new_acknowlegdement)(ewf_adapter* adapter_ptr, uint32_t n);

} ewf_adapter_modem_api_sms;

/**
 * @brief Set the input/output message format (PDU mode or text mode) (+cmgf)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] mode Integer indicating mode (false : PDU mode, true : text mode)
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_format_set(ewf_adapter* adapter_ptr, bool mode);

/**
 * @brief Read the input/output message format (+cmgf)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] mode_ptr A pointer bool that will contain the mode
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_format_read(ewf_adapter* adapter_ptr, bool * mode_ptr);

/**
 * @brief Send message to phone number (+cmgs)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] phone_num_str Phone number in international format
 * @param[in] message_str Message string to be sent
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_send(ewf_adapter* adapter_ptr, const char * phone_num_str, const char * message_str);

/**
 * @brief  Configure More messages to send feature (+cmms)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] n  Integer indicating the configuration to be set (0,1,2)
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_more_send_config_set(ewf_adapter* adapter_ptr, uint8_t n);

/**
 * @brief  Read the configurations for More messages to send feature (+cmms?)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] n  The buffer containing the more send configuration
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_more_send_config_read(ewf_adapter* adapter_ptr, uint8_t * n);

/**
 * @brief Read message from message storage<mem1> (+cmgr)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] index Integer indicating the index from message storage
 * @param[out] message_str Pointer to buffer containing output string
 * @param[out] message_str_len Lenght of string in buffer
 * @note This API expects application to parse the outout buffer for required information
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_read(ewf_adapter* adapter_ptr, uint32_t index, char * message_str, uint32_t * message_str_len);

/**
 * @brief Delete message (+cmgd)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] index Integer indicating the index of message to be deleted
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_delete(ewf_adapter* adapter_ptr, uint32_t index);

/**
 * @brief List messages with specific status value (+cmgl)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] stat Integer indicating the specific status of messages (0:"REC UNREAD", "REC READ","STO UNSENT", "STO SENT", 4: "ALL" )
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_list(ewf_adapter* adapter_ptr, uint8_t stat);

/**
 * @brief Select message service (+csms)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] service Integer indicating the type of messaging service
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_service_select(ewf_adapter* adapter_ptr, uint8_t service);

/**
 * @brief Read the message service (+csms)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] service_ptr  A pointer to buffer that will contain the type of messaging service
 * @param[out] mt_ptr Pointer to mobile originated type support
 * @param[out] mo_ptr Pointer to mobile terminated type support
 * @param[out] bm_ptr Pointer to broadcast type message support
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_service_read(ewf_adapter* adapter_ptr, uint8_t * service, bool * mt_ptr, bool * mo_ptr, bool* bm_ptr);

/**
 * @brief Set service centre address (+csca)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] sca_str String indicating service center addresss
 * @param[in] tosca Integer indicating service center addresss type
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_service_center_address_set(ewf_adapter* adapter_ptr, const char * sca_str, uint32_t tosca);

/**
 * @brief Read the service centre address (+csca)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] sca_str  A pointer to buffer that will contain the service center addresss
 * @param[out] tosca_ptr  A pointer to integer that will contain the service center addresss type
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_service_center_address_read(ewf_adapter* adapter_ptr, char * sca_str, uint32_t * tosca_ptr);

/**
 * @brief  Set the the text mode paramter display config (+csdh)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] show  Integer indicating mode for header values displayed
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_show_header_values_mode_set(ewf_adapter* adapter_ptr, bool show);

/**
 * @brief  Read the text mode paramters display configuration (+csdh)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] show_ptr A pointer to buffer that will contain the mode for header values displayed
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_show_header_values_mode_read(ewf_adapter* adapter_ptr, bool * show_ptr);

/**
 * @brief  Save message settings to non volatile memory (+csas)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] profile Integer indicating profile number (0-255)
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_profile_save(ewf_adapter* adapter_ptr, uint8_t profile);

/**
 * @brief  Restore message settings from non volatile memory (+cres)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] profile Integer indicating profile number (0-255)
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_profile_restore(ewf_adapter* adapter_ptr, uint8_t profile);

/**
 * @brief  Set Preffered message storage (+cpms)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] mem1_str String indicating memory storage for messages to be read and deleted
 *                  "BM" broadcast message storage
 *                  "ME" ME message storage
 *                  "MT" any of the storages associated with ME
 *                  "SM" (U)SIM message storage
 *                  "TA" TA message storage
 *                  "SR" status report storage
 * @param[in] mem2_str String indicating memory storage for messages to be written and sent. Refer to mem1 for defined values
 * @param[in] mem3_str String indicating memory storage for received messages. Refer to mem1 for defined values
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_preffered_storage_set(ewf_adapter* adapter_ptr, const char * mem1_str, const char * mem2_str, const char *mem3_str);

/**
 * @brief  Read the Preffered message storage (+cpms)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] used1_ptr Number of messages currently in mem1
 * @param[out] total1_ptr Total number off message in location mem1
 * @param[out] used2_ptr Number of messages currently in mem1
 * @param[out] total2_ptr Total number off message in location mem1
 * @param[out] used2_ptr Number of messages currently in mem1
 * @param[out] total2_ptr Total number off message in location mem1
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_preffered_storage_read(ewf_adapter* adapter_ptr, uint32_t * used1_ptr, uint32_t * total1_ptr, uint32_t * used2_ptr, uint32_t * total2_ptr, uint32_t * used3_ptr, uint32_t* total3_ptr);

/**
 * @brief Transmit SMS message (either SMS-DELIVER or SMS-SUBMIT) from TE to memory storage <mem2> (+cmgw)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] address_str String indicating the originating/destination address
 * @param[in] address_type Originating/Destination-Address Type-of-Address octet in integer format
 * @param[in] stat Integer indicating the specific status of messages (0:"REC UNREAD", "REC READ","STO UNSENT", "STO SENT", 4:"ALL" )
 * @param[out] index_ptr Buffer containing the memory location index of the stored message
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_to_memory_write(ewf_adapter* adapter_ptr, const char * address_str, uint32_t address_type, uint32_t stat, uint32_t * index_ptr);

/**
 * @brief Send message from storage (+cmss)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] index The message index from the storage
 * @param[in] address_str String indicating the originating/destination address
 * @param[in] address_len Lenght of address
 * @param[in] address_type Destination-Address Type-of-Address octet in integer format
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_send(ewf_adapter* adapter_ptr, uint32_t index, const char * address_str, uint32_t address_len, uint32_t address_type);

/**
 * @brief  Set the message receiving indiciations (+cnmi)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] mode  URC option value as an integer
 * @param[in] mt  SMS-DELIVER reporting option
 * @param[in] bm  Broadcast reporting option
 * @param[in] ds  SMS-STATUS-REPORTs reporting option
 * @param[in] bfr Buffer URC option
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_recieve_indications_set(ewf_adapter* adapter_ptr, uint32_t mode, uint32_t mt, uint32_t bm, uint32_t ds, uint32_t bfr);


/**
 * @brief  Read the message receiving indiciations (+cnmi)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[out] mode_ptr Buffer containing URC option value as an integer
 * @param[out] mt_ptr Buffer containing the SMS-DELIVER reporting option
 * @param[out] bm_ptr Buffer containing the Broadcast reporting option
 * @param[out] ds_ptr Buffer containing the SMS-STATUS-REPORTs reporting option
 * @param[out] bfr_ptr Buffer containing the Buffer URC option
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_recieve_indications_read(ewf_adapter* adapter_ptr, uint32_t * mode_ptr, uint32_t * mt_ptr, uint32_t * bm_ptr, uint32_t * ds_ptr, uint32_t * bfr_ptr);


/**
 * @brief  New Message Acknowledgement (+cnma)
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] n Integer indicating ACK paramter (ONLY IN PDU mode)
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_modem_message_new_acknowlegdement(ewf_adapter* adapter_ptr, uint32_t n);

/************************************************************************//**
 * @} *** group_adapter_modem_sms
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* EWF_SMS_SUPPORT_ENABLED */

#endif /* __ewf_adapter_modem_sms__h__included__ */
