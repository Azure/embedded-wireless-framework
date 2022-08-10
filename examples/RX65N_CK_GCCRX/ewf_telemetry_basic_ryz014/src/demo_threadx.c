/* This is a small demo of the high-performance ThreadX kernel.  It includes examples of eight
   threads of different priorities, using a message queue, semaphore, mutex, event flags group, 
   byte pool, and block pool.  */

#include "tx_api.h"

#include "hardware_setup.h"
#include "azurertos_object_init.h"

extern void tx_application_define_user (void);

/* Define main entry point.  */

int main()
{
    /* Setup the hardware. */
    platform_setup();

    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();
}


/* Define what the initial system looks like.  */

void    tx_application_define(void *first_unused_memory)
{
	tx_application_define_user();
}

