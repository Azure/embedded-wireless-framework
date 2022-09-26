/* generated thread source file - do not edit */
#include "c2d_thread.h"

TX_THREAD c2d_thread;
void c2d_thread_create(void);
static void c2d_thread_func(ULONG thread_input);
static uint8_t c2d_thread_stack[2048] BSP_PLACE_IN_SECTION(".stack.c2d_thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
extern bool g_fsp_common_initialized;
extern uint32_t g_fsp_common_thread_count;
extern TX_SEMAPHORE g_fsp_common_initialized_semaphore;

void c2d_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_fsp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&c2d_thread, (CHAR*) "Cloud2Device Thread", c2d_thread_func, (ULONG) NULL,
                            &c2d_thread_stack, 2048, 2, 2, 1, TX_DONT_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&c2d_thread, 0);
    }
}

static void c2d_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    FSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    c2d_thread_entry ();
}
