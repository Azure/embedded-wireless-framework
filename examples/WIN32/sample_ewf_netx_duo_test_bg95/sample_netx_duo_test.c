/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter NetX Duo test example.
 ****************************************************************************/

#include "ewf_allocator_threadx.h"
#include "ewf_interface_win32_com.h"
#include "ewf_adapter_quectel_bg95.h"
#include "ewf_lib.h"
#include "ewf_example.config.h"

/* Define the thread for running Azure SDK on ThreadX (THREADX IoT Platform).  */
#ifndef SAMPLE_STACK_SIZE
#define SAMPLE_STACK_SIZE      (1024)
#endif /* SAMPLE_STACK_SIZE  */

#ifndef SAMPLE_THREAD_PRIORITY
#define SAMPLE_THREAD_PRIORITY (4)
#endif /* SAMPLE_THREAD_PRIORITY  */

/* The thread control block  */
static TX_THREAD  sample_thread;

/* Define the thread stack.  */
static ULONG sample_thread_stack[SAMPLE_STACK_SIZE / sizeof(ULONG)];

/* The thread entry point.  */
void sample_thread_entry(ULONG parameter);

/* The EWF NetX Duo test.  */
ewf_result ewf_example_netx_duo_test(ewf_adapter* adapter_ptr);

/**
 *  @brief The application entry point, initialize the hardware and start ThreadX
 */
int main(int argc, char** argv)
{
    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();

    /* We never get here, but we keep the compiler happy.  */
    return 0;
}

/**
 *  @brief Define what the initial ThreadX system looks like.
 */
void tx_application_define(void* first_unused_memory)
{
    UINT  status;

    /* Create sample thread. */
    status = tx_thread_create(&sample_thread, "Sample Thread",
        sample_thread_entry, 0,
        sample_thread_stack, SAMPLE_STACK_SIZE,
        SAMPLE_THREAD_PRIORITY, SAMPLE_THREAD_PRIORITY,
        TX_NO_TIME_SLICE, TX_AUTO_START);

    /* Check for thread creation error.  */
    if (status)
    {
        exit(status);
    }
}

/**
 *  @brief The sample thread entry point
 */
void sample_thread_entry(ULONG parameter)
{
    ewf_result result;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator,
        EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT,
        EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
    EWF_INTERFACE_WIN32_COM_STATIC_DECLARE(interface_ptr, com_port,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_FILE_NAME,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BAUD_RATE,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BYTE_SIZE,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_PARITY,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_STOP_BITS);
    EWF_ADAPTER_QUECTEL_BG95_STATIC_DECLARE(adapter_ptr, quectel_bg95, message_allocator_ptr, NULL, interface_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        exit(result);
    }

    // Activated the PDP context
    if (ewf_result_failed(result = ewf_adapter_quectel_bg95_context_activate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG_ERROR("Failed to activate the PDP context: ewf_result %d.\n", result);
        // continue
    }

    // Call the NetX Duo test example
    if (ewf_result_failed(result = ewf_example_netx_duo_test(adapter_ptr)))
    {
        EWF_LOG_ERROR("The NetX Duo test example failed, ewf_result %d.\n", result);
        exit(result);
    }

    EWF_LOG("\nDone!\n");

    /* Stay here forever.  */
    while (1)
    {
        EWF_LOG(".");
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND);
    }
}
