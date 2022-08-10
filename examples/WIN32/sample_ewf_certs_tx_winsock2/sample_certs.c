// Copyright (c) Microsoft Corporation. All rights reserved.

#include "ewf_lib.c"

#include "ewf_platform_threadx.c"
#include "ewf_allocator_threadx.c"
#include "ewf_interface_win32_com.c"
#include "ewf_adapter_quectel_bg96.api.c"

#include "ewf_example_certs_quectel_bg96.c"

/* Telemetry thread */
static TX_THREAD thread;
static void thread_entry(ULONG thread_input);
#define THREAD_STACK_SIZE (1024 * 2)
static ULONG thread_stack[THREAD_STACK_SIZE / sizeof(ULONG)];

/**
 *  @brief The application entry point, initialize the hardware and start ThreadX
 */
int main(int argc, char ** argv)
{
    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();

    return 0;
}

/**
 *  @brief Define what the initial ThreadX system looks like.
 */
void tx_application_define(void *first_unused_memory)
{
    UINT status;

    /* Create the telemetry thread.  */
    status = tx_thread_create(
        &thread,
        "Thread",
        thread_entry, 0,
        thread_stack, THREAD_STACK_SIZE,
        1, 1,
        TX_NO_TIME_SLICE,
        TX_AUTO_START);
    if (status != TX_SUCCESS)
    {
        exit(status);
    }
}

/**
 *  @brief The thread entry point
 */
void thread_entry(ULONG param)
{
    ewf_result result;

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start()))
    {
        EWF_LOG_ERROR("Failed to start the adapter: az_result return code 0x%08lx.", result);
        exit(result);
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN: az_result return code 0x%08lx.", result);
        exit(result);
    }

    // Call the certificate provisioning example
    if (ewf_result_failed(result = ewf_example_certs()))
    {
        EWF_LOG_ERROR("The certificate provisioning example returned and error: az_result return code 0x%08lx.", result);
        exit(result);
    }

    /* Wait forever  */
    while (1)
    {
        tx_thread_sleep(1);
    }
}
