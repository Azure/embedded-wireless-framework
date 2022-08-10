/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework modem adapter types definitions
 * (Reference : 3GPP TS 27.007, 3GPP TS 24.008, 3GPP TS 27.005, 3GPP TS 24.011
 *  specifiction)
 ****************************************************************************/

#ifndef __ewf_adapter_modem_types__h__included__
#define __ewf_adapter_modem_types__h__included__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ewf_time
{
    uint8_t year;        /* Year indicating last two digits. (2022 will be 22) */
    uint8_t month;       /* Month, 1 (Jan)...12 (Dec) */
    uint8_t day;         /* Day, 1 to 31 */
    uint8_t hour;        /* Hour, 0 to 23 */
    uint8_t min;         /* Minute, 0 to 59 */
    uint8_t sec;         /* Second, 0 to 59 */
    int timezone;        /* Timezone expressed in quarters if an hour, between local time and GMT.
                           e.g. 6th of May 1994, 22:10:00 GMT+2 hours equals to "94/05/06,22:10:00+08" */
    uint8_t isdst;       /* Daylight savings flag */

}ewf_time;

typedef enum _ewf_network_status
{
    EWF_NOT_REGISTERED_NOT_SEARCHING = 0,
    EWF_REGISTERED_HOME = 1,
    EWF_SEARCHING = 2,
    EWF_REGISTRATION_DENIED = 3,
    EWF_UNKNOWN = 4,
    EWF_REGISTERED_ROAMING = 5,
    EWF_REGISTERED_SMS_ONLY_HOME = 6,
    EWF_REGISTERED_SMS_ONLY_ROAMING = 7,
    EWF_EMERGENCY_ONLY = 8,
    EWF_REGISTERED_NO_CSFB_HOME = 9,
    EWF_REGISTERED_NO_CSFB_ROAMING= 10,
    /* Specific status for Renesas RYZ014 indicating registered, temporary connection lost */
    EWF_TEMPORARY_CONNECTION_LOSS_RYZ014_PROPRIETARY =80

} ewf_network_status;

/* Access technologies as per 3GPP TS 27.007 */
typedef enum _ewf_act
{
    EWF_ACT_INVALID = -1,
    EWF_ACT_GSM = 0,
    EWF_ACT_GSM_COMPACT = 1,
    EWF_ACT_UTRAN = 2,
    EWF_ACT_EGPRS = 3,
    EWF_ACT_HSDPA = 4,
    EWF_ACT_HSUPA = 5,
    EWF_ACT_HSDPA_HSUPA = 6,
    EWF_ACT_EUTRAN = 7,
    EWF_ACT_LTE_CATM1 = 8,
    EWF_ACT_NBIOT = 9,

} ewf_act;

typedef enum _ewf_edrx_act
{
    EWF_ACT_EDRX_INVALID = -1,
    EWF_ACT_NO_EDRX = 0,
    EWF_ACT_EDRX_EC_GSM_IOT = 1,
    EWF_ACT_EDRX_GSM = 2,
    EWF_ACT_EDRX_UTRAN = 3,
    EWF_ACT_EDRX_EUTRAN_LTE_CATM1 = 4,
    EWF_ACT_EDRX_EUTRAN_NBIOT = 5,

} ewf_edrx_act;

/* Registration modes */
typedef enum _ewf_operator_sel_register_mode
{
    EWF_SELECT_REGISTER_MODE_AUTO = 0,
    EWF_SELECT_REGISTER_MODE_MANUAL = 1,
    EWF_SELECT_REGISTER_MODE_DEREGISTER = 2,
    EWF_SELECT_REGISTER_MODE_NO_REGISTER_NO_DEREGISTER = 3,
    EWF_SELECT_REGISTER_MODE_MANUAL_AUTO = 4

} ewf_operator_sel_register_mode;

typedef enum _ewf_operator_name_format
{
    EWF_OPERATOR_NAME_FORMAT_LONG = 0,    /**< Long format alphanumeric */
    EWF_OPERATOR_NAME_FORMAT_SHORT,       /**< Short format alphanumeric */
    EWF_OPERATOR_NAME_FORMAT_NUMERIC,     /**< Numeric operator name */

} ewf_operator_name_format;

/** @brief Packet data protocol(PDP) type */
#define EWF_PDP_CONTEXT_TYPE_IP             "IP"
#define EWF_PDP_CONTEXT_TYPE_IPV6  			"IPV6"
#define EWF_PDP_CONTEXT_TYPE_IPV4V6			"IPV4V6"
#define EWF_PDP_CONTEXT_TYPE_PPP			"PPP"

typedef enum _ewf_pdpauthtype
{
    EWF_PDP_AUTH_NONE = 0,   /**< No authentication */
    EWF_PDP_AUTH_PAP,        /**< Password Authentication Protocol (PAP) */
    EWF_PDP_AUTH_CHAP        /**< Challenge Handshake Authentication Protocol (CHAP) */

} ewf_pdpauthtype;

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_modem_types__h__included__ */
