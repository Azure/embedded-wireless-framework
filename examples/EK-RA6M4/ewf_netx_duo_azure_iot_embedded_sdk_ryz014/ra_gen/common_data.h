/* generated common header file - do not edit */
#ifndef COMMON_DATA_H_
#define COMMON_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "tx_api.h"
#include "nx_api.h"
#include "rm_netx_secure_crypto.h"
#include "nx_azure_iot.h"
#include "r_icu.h"
#include "r_external_irq_api.h"
#include "r_ioport.h"
#include "bsp_pin_cfg.h"
FSP_HEADER
void azure_iot_quick_setup();
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t pushButtonS2;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t pushButtonS2_ctrl;
extern const external_irq_cfg_t pushButtonS2_cfg;

#ifndef pb_callback
void pb_callback(external_irq_callback_args_t *p_args);
#endif
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t pushButtonS1;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t pushButtonS1_ctrl;
extern const external_irq_cfg_t pushButtonS1_cfg;

#ifndef pb_callback
void pb_callback(external_irq_callback_args_t *p_args);
#endif
/* IOPORT Instance */
extern const ioport_instance_t g_ioport;

/* IOPORT control structure. */
extern ioport_instance_ctrl_t g_ioport_ctrl;
extern TX_QUEUE g_topic_queue;
void g_common_init(void);
FSP_FOOTER
#endif /* COMMON_DATA_H_ */
