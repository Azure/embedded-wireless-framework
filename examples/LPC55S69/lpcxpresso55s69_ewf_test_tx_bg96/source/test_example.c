#include <stdio.h>

#include "fsl_common.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "board_setup.h"

#include "ewf_lib.c"
#include "ewf_platform_threadx.c"
#include "ewf_allocator.c"
#include "ewf_allocator_threadx.c"
#include "ewf_interface.c"
#include "ewf_interface_lpc_uart.c"
#include "ewf_adapter.c"
#include "ewf_adapter_api_control.c"
#include "ewf_adapter_api_info.c"
#include "ewf_adapter_api_tls_basic.c"
#include "ewf_adapter_api_mqtt_basic.c"
#include "ewf_adapter_api_tcp.c"
#include "ewf_adapter_api_udp.c"
#include "ewf_adapter_api_modem.c"
#include "ewf_adapter_api_modem_general.c"
#include "ewf_adapter_api_modem_network_service.c"
#include "ewf_adapter_api_modem_packet_domain.c"
#include "ewf_adapter_api_modem_sim_utility.c"
#include "ewf_adapter_api_modem_sms.c"
#include "ewf_adapter_quectel_bg96.c"

#include "ewf_example.config.h"
#include "test/ewf_adapter_quectel_bg96_test.c"

/* ThreadX thread, entry point, stack*/
static TX_THREAD thread_sample;
static void thread_sample_entry(ULONG thread_input);
#define THREAD_SAMPLE_STACK_SIZE (1024)
static ULONG thread_sample_stack[THREAD_SAMPLE_STACK_SIZE / sizeof(ULONG)];

/**
 *  @brief The application entry point, initialize the hardware and start ThreadX
 */
int main(void)
{
    board_setup();

    /* Enter the ThreadX kernel. */
    tx_kernel_enter();

    return 0;
}

/**
 *  @brief Define what the initial ThreadX system looks like.
 */
void tx_application_define(void *first_unused_memory)
{
    UINT status;

    TX_THREAD_NOT_USED(first_unused_memory);

    /* Create the sample thread.  */
    status = tx_thread_create(
        &thread_sample,
        "thread sample",
        thread_sample_entry, 0,
        thread_sample_stack, THREAD_SAMPLE_STACK_SIZE,
        3, 3,
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
		EWF_CONFIG_ALLOCATOR_BLOCK_COUNT,
		EWF_CONFIG_ALLOCATOR_BLOCK_SIZE);
    EWF_INTERFACE_LPC_UART_STATIC_DECLARE(interface_ptr, lpc_uart_interface,
		EWF_CONFIG_INTERFACE_LPC_UART_BASE_ADDRESS,
		EWF_CONFIG_INTERFACE_LPC_UART_BAUD_RATE);
    EWF_ADAPTER_QUECTEL_BG96_STATIC_DECLARE(adapter_ptr, quectel_bg96, message_allocator_ptr, NULL, interface_ptr);

    EWF_LOG("Starting...\n");

    /* Start the adapter.  */
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        return;
    }

    /* Set the SIM PIN.  */
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        return;
    }

    /* Set the ME functionality.  */
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL)))
    {
        EWF_LOG_ERROR("Failed to the ME functionality, ewf_result %d.\n", result);
        return;
    }

    /* Run the adapter tests.  */
    if (ewf_result_failed(result = ewf_adapter_quectel_bg96_test(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to run the adapter test, ewf_result %d.\n", result);
    }

    EWF_LOG("\nDone!\n");

    /* Stay here forever.  */
    while (1)
    {
        EWF_LOG(".");
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND);
    }
}
