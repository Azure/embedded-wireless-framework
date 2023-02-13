
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include <tx_api.h>

#include "r_cg_macrodriver.h"
#include <platform.h>
#include "r_sci_rx_if.h"
#include "r_sci_rx_pinset.h"

#include "demo_printf.h"

#define DEMO_PRINTF_BUF_LEN (256U)

void demo_printf_transmit_end(void * pArgs);

static char demo_printf_buf[DEMO_PRINTF_BUF_LEN + 1u];

TX_MUTEX demo_printf_mutex;
TX_SEMAPHORE demo_printf_semaphore;
sci_hdl_t Console;

void demo_printf_init(void)
{
    UINT res;
    sci_cfg_t config;
    sci_err_t err;

    config.async.baud_rate = 115200;
    config.async.clk_src = SCI_CLK_INT;
    config.async.data_size = SCI_DATA_8BIT;
    config.async.parity_en = SCI_PARITY_OFF;
    config.async.parity_type = SCI_EVEN_PARITY; //
    config.async.stop_bits = SCI_STOPBITS_1;
    config.async.int_priority = 5; //
    err = R_SCI_Open(SCI_CH5, SCI_MODE_ASYNC, &config, demo_printf_transmit_end, &Console);

    R_SCI_PinSet_SCI5();

    res = tx_mutex_create(&demo_printf_mutex, "Demo printf mutex", TX_INHERIT);
    if(res != TX_SUCCESS) {
        for(;;) {}
    }

    res = tx_semaphore_create(&demo_printf_semaphore, "Demo printf semaphore", 0u);
    if(res != TX_SUCCESS) {
        for(;;) {}
    }

}

void demo_printf(char *format, ...)
{
    va_list v_args;
    size_t len;

    tx_mutex_get(&demo_printf_mutex, TX_WAIT_FOREVER);

    va_start(v_args, format);

    len = (size_t)vsnprintf(&demo_printf_buf[0], sizeof(demo_printf_buf), format, v_args);

    R_SCI_Send(Console,(uint8_t *)demo_printf_buf,len);
    
    va_end(v_args);

    tx_semaphore_get(&demo_printf_semaphore, TX_WAIT_FOREVER);

    tx_mutex_put(&demo_printf_mutex);
}

void demo_printf_transmit_end(void * pArgs)
{
	sci_cb_args_t *p_args = (sci_cb_args_t*) pArgs;

	if (SCI_EVT_TEI == p_args->event) {
		tx_semaphore_put(&demo_printf_semaphore);
	}
}

void my_sw_charput_function(uint8_t c)
{
    tx_mutex_get(&demo_printf_mutex, TX_WAIT_FOREVER);
    
    R_SCI_Send(Console,&c,1);
    
    tx_semaphore_get(&demo_printf_semaphore, TX_WAIT_FOREVER);

    tx_mutex_put(&demo_printf_mutex);

	return;
}
