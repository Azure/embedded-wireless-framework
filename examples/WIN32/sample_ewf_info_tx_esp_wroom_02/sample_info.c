/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter info example.
 ****************************************************************************/

#include "ewf_platform.h"
#include "ewf_allocator_threadx.h"
#include "ewf_interface_win32_com.h"
#include "ewf_adapter_espressif_wroom_02.h"
#include "ewf_lib.h"
#include "ewf_example.config.h"

/* The thread */
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

    /* We never get here, but we keep the compiler happy.  */
    return 0;
}

/**
 *  @brief Define what the initial ThreadX system looks like.
 */
void tx_application_define(void *first_unused_memory)
{
    UINT status;

    /* Create the example thread.  */
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
        exit(-1);
    }
}

/**
 *  @brief The sample thread entry point, it calls other examples
 */
void thread_entry(ULONG param)
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
    EWF_ADAPTER_ESPRESSIF_WROOM_02_STATIC_DECLARE(adapter_ptr, wroom_02, message_allocator_ptr, NULL, interface_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        return;
    }

    // Get the adapter info
    if (ewf_result_failed(result = ewf_adapter_info(adapter_ptr)))
    {
        EWF_LOG_ERROR("The info function returned an error, ewf_result %d.\n", result);
        return;
    }

    EWF_LOG("\nDone!\n");

    /* Wait forever  */
    while (1)
    {
        EWF_LOG(".");
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND);
    }
}
