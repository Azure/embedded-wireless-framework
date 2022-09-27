#include "ewf_test_thread.h"

#include "ewf_lib.c"
#include "ewf_platform_threadx.c"
#include "ewf_allocator.c"
#include "ewf_allocator_threadx.c"
#include "ewf_interface.c"
#include "ewf_interface_ra_uart.c"
#include "ewf_adapter.c"
#include "ewf_adapter_api_tcp.c"
#include "ewf_adapter_api_udp.c"
#include "ewf_adapter_api_mqtt_basic.c"
#include "ewf_adapter_api_tls_basic.c"
#include "ewf_adapter_api_info.c"
#include "ewf_adapter_api_control.c"
#include "ewf_adapter_api_modem.c"
#include "ewf_adapter_api_modem_general.c"
#include "ewf_adapter_api_modem_sim_utility.c"
#include "ewf_adapter_api_modem_packet_domain.c"
#include "ewf_adapter_api_modem_network_service.c"
#include "ewf_adapter_sequans.c"
#include "ewf_adapter_renesas_ryz014.c"

#include "ewf_adapter_renesas_ryz014_test.c"
#include "ewf_example.config.h"


/* Azure SD-NET test thread entry function */
void ewf_test_thread_entry(void)
{
    ewf_result result;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator,
            EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT,
            EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
    EWF_INTERFACE_RA_UART_STATIC_DECLARE(interface_ptr , sci_uart);
    EWF_ADAPTER_RENESAS_RYZ014_STATIC_DECLARE(adapter_ptr, renesas_ryz014, message_allocator_ptr, NULL, interface_ptr);

    // Release the RYZ014A from reset
    ewf_platform_sleep(100);
    R_IOPORT_PinWrite(&g_ioport_ctrl, PMOD2_IO1, BSP_IO_LEVEL_LOW);
    EWF_LOG("Waiting for the module to Power Reset!\r\n");
    ewf_platform_sleep(400);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        return;
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, "1")))
    {
        EWF_LOG_ERROR("Failed to the ME functionality, ewf_result %d.\n", result);
        return;
    }
    ewf_platform_sleep(200);

    /* Wait for the modem to be registered to network
     * Refer system integration guide for more info */
    while(EWF_RESULT_OK!=ewf_adapter_modem_network_registration_check(adapter_ptr, (uint32_t)-1));
    ewf_platform_sleep(200);

    /* Disable network Registration URC */
    if (ewf_result_failed(result = ewf_adapter_modem_network_registration_urc_set(adapter_ptr, "0")))
    {
        EWF_LOG_ERROR("Failed to disable network registration status URC, ewf_result %d.\n", result);
        return;
    }

    /* Disable EPS network Registration URC */
    if (ewf_result_failed(result = ewf_adapter_modem_eps_network_registration_urc_set(adapter_ptr, "0")))
    {
        EWF_LOG_ERROR("Failed to disable network registration status URC, ewf_result %d.\n", result);
        return;
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        return;
    }

    /* Run the adapter tests.  */
    if (ewf_result_failed(result = ewf_adapter_renesas_ryz014_test(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to run the adapter test: az_result return code 0x%08x.", result);
        exit(result);
    }

    EWF_LOG("\r\nTest Complete\r\n");
    while (1)
    {
        EWF_LOG(".");
        tx_thread_sleep(100);
    }
}
