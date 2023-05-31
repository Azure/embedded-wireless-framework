
#include "r_smc_entry.h"

#include <platform.h>

#include <r_cmt_rx_if.h>

#include <tx_api.h>
#include "demo_printf.h"
#include "hardware_setup.h"

void _tx_timer_interrupt(void);

/* CMT Timer callback used as the system tick. */
void timer_callback(void * pdata)
{
    _tx_timer_interrupt();
}


void platform_setup(void)
{
    uint32_t chan;

    /* Setup SCI5 for printf output. */
    R_Config_SCI5_Start();

    /* Initialize the demo printf implementation. */
    LOG_TERMINAL_INIT();

    /* Create periodic timer for the system tick. */
    R_CMT_CreatePeriodic(TX_TIMER_TICKS_PER_SECOND, timer_callback, &chan);

}
