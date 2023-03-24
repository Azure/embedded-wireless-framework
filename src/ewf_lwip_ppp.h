/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework LwIP PPP driver
 ****************************************************************************/

#ifndef __ewf_lwip_ppp__h__included__
#define __ewf_lwip_ppp__h__included__

/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** LWIP Component                                                        */
/**                                                                       */
/**   Generic Driver for Embedded Wireless Framework Adapters             */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LWIP_INCLUDED

#include "netif/ppp/pppapi.h"
#include "lwip/api.h"
#include "lwip/ip.h"
#include "lwip/udp.h"
#include "lwip/sys.h"

/* Define the PPP config function. */
ewf_result ewf_lwip_ppp_config(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_data_mode_enter(ewf_adapter* adapter_ptr, uint32_t context_id);
ewf_result ewf_adapter_data_mode_exit(ewf_adapter* adapter_ptr);
void pppos_rx_thread_task(void* arg);
ewf_result ewf_interface_data_mode_ppp_byte_receive_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

#endif

/************************************************************************//**
 * @}
 ****************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* __ewf_lwip_ppp__h__included__ */
