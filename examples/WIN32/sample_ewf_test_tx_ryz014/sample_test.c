// Copyright (c) Microsoft Corporation. All rights reserved.

#include "ewf_platform.h"
#include "ewf_allocator_threadx.h"
#include "ewf_interface_win32_com.h"
#include "ewf_adapter_renesas_ryz014.h"
#include "ewf_lib.h"
#include "ewf_example.config.h"

/* ThreadX thread, entry point declaration and stack definition.  */
static TX_THREAD thread_sample;
static void thread_sample_entry(ULONG thread_input);
#define THREAD_SAMPLE_STACK_SIZE (1024)
static ULONG thread_sample_stack[THREAD_SAMPLE_STACK_SIZE / sizeof(ULONG)];

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

    /* Create the sample thread.  */
    status = tx_thread_create(
        &thread_sample,
        "thread sample",
        thread_sample_entry, 0,
        thread_sample_stack, THREAD_SAMPLE_STACK_SIZE,
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
void thread_sample_entry(ULONG param)
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
    EWF_ADAPTER_RENESAS_RYZ014_STATIC_DECLARE(adapter_ptr, renesas_ryz014, message_allocator_ptr, NULL, interface_ptr);

    /* Start the adapter.  */
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the modem, ewf_result %d.\n", result);
        exit(result);
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL)))
    {
        EWF_LOG_ERROR("Failed to the ME functionality, ewf_result %d.\n", result);
        return;
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        return;
    }

    /* Wait for the modem functionality to be up, increase/decrease the sleep time as required by modem and network,
     * Refer system integration guide for more info */
    uint32_t wait_time_seconds = 15;

    if (ewf_result_failed(result = ewf_adapter_modem_network_registration_check(adapter_ptr, wait_time_seconds)))
    {
        EWF_LOG_ERROR("Failed to register modem to network within timeout specified, ewf_result %d.\n", result);
        return;
    }

    // Activated the PDP context
    if (ewf_result_failed(result = ewf_adapter_modem_packet_service_activate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG_ERROR("Failed to activate the PDP context, ewf_result %d.\n", result);
        // continue despite the error
    }

    /* Update the context_id that should be used for the tests */
    ewf_adapter_renesas_ryz014* adapter_renesas_ryz014_ptr = (ewf_adapter_renesas_ryz014*)adapter_ptr->implementation_ptr;
    adapter_renesas_ryz014_ptr->current_context_id = EWF_CONFIG_CONTEXT_ID;

    /* Run the adapter tests.  */
    if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_test(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to run the adapter test, ewf_result %d.\n", result);
        exit(result);
    }

    /* Stay here forever.  */
    while (1)
    {
        tx_thread_sleep(100);
    }
}
