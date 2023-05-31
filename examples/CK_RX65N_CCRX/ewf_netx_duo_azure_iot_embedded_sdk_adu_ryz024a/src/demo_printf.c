
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include <tx_api.h>

#include "r_cg_macrodriver.h"
#include <platform.h>
#include "r_sci_rx_if.h"

#include "demo_printf.h"

#define DEMO_PRINTF_BUF_LEN (4096U)


static char demo_printf_buf[DEMO_PRINTF_BUF_LEN + 1u];

TX_MUTEX demo_printf_mutex;
TX_SEMAPHORE demo_printf_semaphore;
sci_hdl_t     sci_uart_print_handle;
static void sci_uart_print_callback(void *pArgs)
{
    sci_cb_args_t   *p_args;

    p_args = (sci_cb_args_t *)pArgs;

    if (SCI_EVT_TEI == p_args->event)
    {
    	demo_printf_transmit_end();
    }

}

void demo_printf_init(void)
{
    tx_mutex_create(&demo_printf_mutex, "Demo printf mutex", TX_INHERIT);

    tx_semaphore_create(&demo_printf_semaphore, "Demo printf semaphore", 0u);
    sci_cfg_t   my_sci_config;
     sci_err_t   my_sci_err;

     /* Initialize the I/O port pins for communication on this SCI channel.
     * This is specific to the MCU and ports chosen. For the RSKRX65-2M we will use the
     * SCI channel connected to the USB serial port emulation. */
     R_SCI_PinSet_SCI5();

     /* Set up the configuration data structure for asynchronous (UART) operation. */
     my_sci_config.async.baud_rate    = 115200;
     my_sci_config.async.clk_src      = SCI_CLK_INT;
     my_sci_config.async.data_size    = SCI_DATA_8BIT;
     my_sci_config.async.parity_en    = SCI_PARITY_OFF;
     my_sci_config.async.parity_type  = SCI_EVEN_PARITY;
     my_sci_config.async.stop_bits    = SCI_STOPBITS_1;
     my_sci_config.async.int_priority = 3;    // 1=lowest, 15=highest

     /* OPEN ASYNC CHANNEL
     *  Provide address of the configure structure,
     *  the callback function to be assigned,
     *  and the location for the handle to be stored.*/
     my_sci_err = R_SCI_Open(SCI_CH5, SCI_MODE_ASYNC, &my_sci_config, sci_uart_print_callback, &sci_uart_print_handle);

     /* If there were an error this would demonstrate error detection of API calls. */
     if (SCI_SUCCESS != my_sci_err)
     {
         R_BSP_NOP(); // Your error handling code would go here.
     }
}

void demo_printf(char *format, ...)
{
    va_list v_args;
    size_t len;

    tx_mutex_get(&demo_printf_mutex, TX_WAIT_FOREVER);

    va_start(v_args, format);

    len = (size_t)vsnprintf(&demo_printf_buf[0], sizeof(demo_printf_buf), format, v_args);
    if (len >= DEMO_PRINTF_BUF_LEN) {
        len = DEMO_PRINTF_BUF_LEN;
    }
    R_SCI_Send(sci_uart_print_handle,(uint8_t *)demo_printf_buf, len);

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
    
    R_SCI_Send(sci_uart_print_handle, &c, 1u);
    
    tx_semaphore_get(&demo_printf_semaphore, TX_WAIT_FOREVER);

    tx_mutex_put(&demo_printf_mutex);

    return;
}
