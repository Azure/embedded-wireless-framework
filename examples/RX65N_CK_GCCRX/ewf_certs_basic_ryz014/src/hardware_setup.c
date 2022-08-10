
#include "r_smc_entry.h"

#include <platform.h>

#include <r_cmt_rx_if.h>

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

    /* Create periodic timer for the system tick. */
    R_CMT_CreatePeriodic(100u, timer_callback, &chan);
    
}
