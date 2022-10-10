
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include <tx_api.h>

#include "r_cg_macrodriver.h"
#include <platform.h>
#include "r_sci_rx_if.h"
#include <Config_SCI5.h>

#include "demo_printf.h"

#define DEMO_PRINTF_BUF_LEN (256U)


static char demo_printf_buf[DEMO_PRINTF_BUF_LEN + 1u];

TX_MUTEX demo_printf_mutex;
TX_SEMAPHORE demo_printf_semaphore;
sci_hdl_t Console;

void demo_printf_init(void)
{
    tx_mutex_create(&demo_printf_mutex, "Demo printf mutex", TX_INHERIT);

    tx_semaphore_create(&demo_printf_semaphore, "Demo printf semaphore", 0u);
}

void demo_printf(char *format, ...)
{
    va_list v_args;
    size_t len;

    tx_mutex_get(&demo_printf_mutex, TX_WAIT_FOREVER);

    va_start(v_args, format);

    len = (size_t)vsnprintf(&demo_printf_buf[0], sizeof(demo_printf_buf), format, v_args);

    R_Config_SCI5_Serial_Send((uint8_t *)demo_printf_buf, len);

    va_end(v_args);

    tx_semaphore_get(&demo_printf_semaphore, TX_WAIT_FOREVER);

    tx_mutex_put(&demo_printf_mutex);
}

void demo_printf_transmit_end(void)
{
    tx_semaphore_put(&demo_printf_semaphore);
}

void my_sw_charput_function(char c)
{
    tx_mutex_get(&demo_printf_mutex, TX_WAIT_FOREVER);
    
    R_Config_SCI5_Serial_Send(&c, 1u);
    
    tx_semaphore_get(&demo_printf_semaphore, TX_WAIT_FOREVER);

    tx_mutex_put(&demo_printf_mutex);

	return;
}
