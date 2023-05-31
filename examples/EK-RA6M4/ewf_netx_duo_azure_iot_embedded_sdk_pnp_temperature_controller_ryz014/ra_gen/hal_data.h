/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_sci_uart.h"
#include "r_uart_api.h"
#include "r_adc.h"
#include "r_adc_api.h"
#include "r_gpt.h"
#include "r_timer_api.h"
FSP_HEADER
/** UART on SCI Instance. */
extern const uart_instance_t g_uart0;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern sci_uart_instance_ctrl_t g_uart0_ctrl;
extern const uart_cfg_t g_uart0_cfg;
extern const sci_uart_extended_cfg_t g_uart0_cfg_extend;

#ifndef user_uart_callback
void user_uart_callback(uart_callback_args_t *p_args);
#endif
/** ADC on ADC Instance. */
extern const adc_instance_t adc;

/** Access the ADC instance using these structures when calling API functions directly (::p_api is not used). */
extern adc_instance_ctrl_t adc_ctrl;
extern const adc_cfg_t adc_cfg;
extern const adc_channel_cfg_t adc_channel_cfg;

#ifndef NULL
void NULL(adc_callback_args_t *p_args);
#endif

#ifndef NULL
#define ADC_DMAC_CHANNELS_PER_BLOCK_NULL  1
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t gpt;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t gpt_ctrl;
extern const timer_cfg_t gpt_cfg;

#ifndef g_gpt_timer_cb
void g_gpt_timer_cb(timer_callback_args_t *p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
