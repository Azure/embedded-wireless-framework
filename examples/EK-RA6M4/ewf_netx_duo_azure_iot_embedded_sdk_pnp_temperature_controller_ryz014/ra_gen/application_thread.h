/* generated thread header file - do not edit */
#ifndef APPLICATION_THREAD_H_
#define APPLICATION_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void application_thread_entry(void);
                #else
extern void application_thread_entry(void);
#endif
#include "nxd_sntp_client.h"
FSP_HEADER
#define G_SNTP_CLIENT0_INDEX_NETWORK_INTERFACE  0

void g_sntp_client0_quick_setup();
FSP_FOOTER
#endif /* APPLICATION_THREAD_H_ */
