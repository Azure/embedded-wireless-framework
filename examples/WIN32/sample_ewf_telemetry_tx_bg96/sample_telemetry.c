// Copyright (c) Microsoft Corporation. All rights reserved.

#include "ewf_platform.h"
#include "ewf_allocator_threadx.h"
#include "ewf_interface_win32_com.h"
#include "ewf_adapter_quectel_bg96.h"
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

    uint32_t context_id = 1;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_allocator* data_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator,
        EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT,
        EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(data_allocator_ptr, data_allocator, 4, 1500);
    EWF_INTERFACE_WIN32_COM_STATIC_DECLARE(interface_ptr, com_port,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_FILE_NAME,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BAUD_RATE,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BYTE_SIZE,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_PARITY,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_STOP_BITS);
    EWF_ADAPTER_QUECTEL_BG96_STATIC_DECLARE(adapter_ptr, quectel_bg96, message_allocator_ptr, data_allocator_ptr, interface_ptr);

    /* Start the adapter.  */
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter: return code 0x%08lx.", result);
        return;
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN: return code 0x%08lx.", result);
        return;
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, "1")))
    {
        EWF_LOG_ERROR("Failed to the ME functionality: return code 0x%08lx.", result);
        return;
    }

    // Activated the PDP context
    if (ewf_result_failed(result = ewf_adapter_quectel_bg96_context_activate(adapter_ptr, context_id)))
    {
        EWF_LOG_ERROR("Failed to activate the PDP context: return code 0x%08lx.", result);
        // continue despite the error
    }

#ifdef EWF_ADAPTER_QUECTEL_BG96_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_tls_basic_init(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to init the SSL basic API: return code 0x%08x.", result);
        return;
    }
#endif

    // Call the telemetry example
    if (ewf_result_failed(result = ewf_example_telemetry_basic(adapter_ptr)))
    {
        EWF_LOG_ERROR("The telemetry example returned and error: return code 0x%08lx.", result);
        return;
    }

#ifdef EWF_ADAPTER_QUECTEL_BG96_TLS_BASIC_ENABLED
    if (ewf_result_failed(result = ewf_adapter_tls_basic_clean(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to clean the SSL basic API: return code 0x%08x.", result);
        return;
    }
#endif

    /* Stay here forever.  */
    while (1)
    {
        tx_thread_sleep(100);
    }
}
