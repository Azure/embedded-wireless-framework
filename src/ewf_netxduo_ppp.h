/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework NetX Duo PPP driver
 ****************************************************************************/

#ifndef __ewf_netxduo_ppp__h__included__
#define __ewf_netxduo_ppp__h__included__

/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** NetX Component                                                        */
/**                                                                       */
/**   Generic Driver for Embedded Wireless Framework Adapters           */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "nx_api.h"
#include "nx_ppp.h"

typedef struct _ewf_netxduo_ppp_cfg
{
    NX_PPP* ppp_ptr;
    uint8_t* ppp_thread_stack_ptr;
    uint32_t ppp_thread_stack_size;
    uint8_t ppp_thread_priority;
    NX_IP* ip_ptr;
    uint8_t* ip_thread_stack_ptr;
    uint32_t ip_thread_stack_size;
    NX_PACKET_POOL* pool_ptr;
}ewf_netxduo_ppp_cfg;

/* Define the PPP config function. */
ewf_result ewf_netxduo_ppp_config(ewf_adapter* adapter_ptr, ewf_netxduo_ppp_cfg* ppp_cfg_ptr);
ewf_result ewf_adapter_data_mode_enter(ewf_adapter* adapter_ptr, uint32_t context_id);
ewf_result ewf_adapter_data_mode_exit(ewf_adapter* adapter_ptr);
ewf_result ewf_interface_data_mode_ppp_byte_receive_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);



/************************************************************************//**
 * @}
 ****************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* __ewf_netxduo_ppp__h__included__ */
