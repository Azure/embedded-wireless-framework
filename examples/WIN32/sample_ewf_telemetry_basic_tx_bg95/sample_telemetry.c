// Copyright (c) Microsoft Corporation. All rights reserved.

#include "ewf_platform.h"
#include "ewf_allocator_threadx.h"
#include "ewf_interface_win32_com.h"
#include "ewf_adapter_quectel_bg95.h"
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

    /* This statement is never reached but keeps the compiler happy */
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
        exit(status);
    }
}

/**
 *  @brief The sample thread entry point
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
    EWF_ADAPTER_QUECTEL_BG95_STATIC_DECLARE(adapter_ptr, quectel_bg95, message_allocator_ptr, NULL, interface_ptr);

    /* Start the adapter.  */
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        return;
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        return;
    }

    // Enable full functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL)))
    {
        EWF_LOG_ERROR("Failed to set the ME functionality, ewf_result %d.\n", result);
        exit(result);
    }

    // Activate the PDP context
    if (ewf_result_failed(result = ewf_adapter_quectel_bg95_context_activate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG("[WARNING] Failed to activate the PDP context, ewf_result %d.\n", result);
        // continue despite the error, the context may be already active
    }

#ifdef EWF_ADAPTER_QUECTEL_BG95_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_tls_basic_init(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to init the SSL basic API, ewf_result %d.\n", result);
        return;
    }
#endif

    // Call the telemetry example
    if (ewf_result_failed(result = ewf_example_telemetry_basic(adapter_ptr)))
    {
        EWF_LOG_ERROR("The telemetry example returned and error, ewf_result %d.\n", result);
        return;
    }

#ifdef EWF_ADAPTER_QUECTEL_BG95_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_tls_basic_clean(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to clean the SSL basic API, ewf_result %d.\n", result);
        return;
    }
#endif

    // Deactivate the PDP context
    if (ewf_result_failed(result = ewf_adapter_quectel_bg95_context_deactivate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG("Failed to deactivate the PDP context, ewf_result %d.\n", result);
        // continue despite the error
    }

    EWF_LOG("Done!\n");

    /* Stay here forever.  */
    while (1)
    {
        EWF_LOG(".");
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND);
    }
}
