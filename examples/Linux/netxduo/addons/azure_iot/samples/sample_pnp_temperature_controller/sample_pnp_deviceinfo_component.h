/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

#ifndef SAMPLE_PNP_DEVICEINFO_COMPONENT_H
#define SAMPLE_PNP_DEVICEINFO_COMPONENT_H

#ifdef __cplusplus
extern   "C" {
#endif

#include "nx_azure_iot_hub_client_properties.h"

UINT sample_pnp_deviceinfo_report_all_properties(UCHAR *component_name_ptr, USHORT component_name_length,
                                                 NX_AZURE_IOT_HUB_CLIENT *iotpnp_client_ptr);

#ifdef __cplusplus
}
#endif
#endif /* SAMPLE_PNP_DEVICEINFO_COMPONENT_H */
