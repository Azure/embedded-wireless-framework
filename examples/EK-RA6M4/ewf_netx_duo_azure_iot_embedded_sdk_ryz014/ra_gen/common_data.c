/* generated common source file - do not edit */
#include "common_data.h"
NX_AZURE_IOT nx_azure_iot;
icu_instance_ctrl_t pushButtonS2_ctrl;
const external_irq_cfg_t pushButtonS2_cfg =
{ .channel = 11,
  .trigger = EXTERNAL_IRQ_TRIG_RISING,
  .filter_enable = true,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .p_callback = pb_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = NULL,
  .ipl = (10),
#if defined(VECTOR_NUMBER_ICU_IRQ11)
    .irq                 = VECTOR_NUMBER_ICU_IRQ11,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const external_irq_instance_t pushButtonS2 =
{ .p_ctrl = &pushButtonS2_ctrl, .p_cfg = &pushButtonS2_cfg, .p_api = &g_external_irq_on_icu };
icu_instance_ctrl_t pushButtonS1_ctrl;
const external_irq_cfg_t pushButtonS1_cfg =
{ .channel = 10,
  .trigger = EXTERNAL_IRQ_TRIG_RISING,
  .filter_enable = true,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .p_callback = pb_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = NULL,
  .ipl = (10),
#if defined(VECTOR_NUMBER_ICU_IRQ10)
    .irq                 = VECTOR_NUMBER_ICU_IRQ10,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const external_irq_instance_t pushButtonS1 =
{ .p_ctrl = &pushButtonS1_ctrl, .p_cfg = &pushButtonS1_cfg, .p_api = &g_external_irq_on_icu };
ioport_instance_ctrl_t g_ioport_ctrl;
const ioport_instance_t g_ioport =
{ .p_api = &g_ioport_on_ioport, .p_ctrl = &g_ioport_ctrl, .p_cfg = &g_bsp_pin_cfg, };
TX_QUEUE g_topic_queue;
static uint8_t queue_memory_g_topic_queue[64];
void tx_startup_err_callback(void *p_instance, void *p_data);
void g_common_init(void)
{
    UINT err_g_topic_queue;
    err_g_topic_queue = tx_queue_create (&g_topic_queue, (CHAR*) "Topic Queue", 16, &queue_memory_g_topic_queue,
                                         sizeof(queue_memory_g_topic_queue));
    if (TX_SUCCESS != err_g_topic_queue)
    {
        tx_startup_err_callback (&g_topic_queue, 0);
    }
}
