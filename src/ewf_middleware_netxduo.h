/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework NetX Duo driver
 ****************************************************************************/

#ifndef __ewf_middleware_netxduo__h__included__
#define __ewf_middleware_netxduo__h__included__

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


/* Define the driver entry function. */

VOID  nx_driver_ewf_adapter(NX_IP_DRIVER *driver_req_ptr);


/************************************************************************//**
 * @}
 ****************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* __ewf_middleware_netxduo__h__included__ */
