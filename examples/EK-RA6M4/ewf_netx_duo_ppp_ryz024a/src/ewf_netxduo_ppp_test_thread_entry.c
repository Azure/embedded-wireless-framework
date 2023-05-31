#include <ewf_netxduo_ppp_test_thread.h>
#include "tx_api.h"

#include "ewf_example.config.h"

/* Inclusion of .c files is for demo purposes only.
 * In production code, please compile the below .c files as you would do for other source files :
 * In your IDE add the files to your project, in your make files add the files to your source list, etc.. */
#include "ewf_lib.c"
#include "ewf_platform_threadx.c"
#include "ewf_allocator.c"
#include "ewf_allocator_threadx.c"
#include "ewf_tokenizer.c"
#include "ewf_tokenizer_basic.c"
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
#include "ewf_adapter_renesas_ryz024a.c"
#include "ewf_adapter_renesas_common_tokenizer.c"
#include "ewf_adapter_renesas_common_control.c"
#include "ewf_adapter_renesas_common_info.c"
#include "ewf_adapter_renesas_common_urc.c"
#include "ewf_adapter_renesas_common_internet.c"
#include "ewf_adapter_renesas_common_nvm.c"
#include "ewf_adapter_renesas_common_mqtt_basic.c"
#include "ewf_adapter_renesas_common_tls_basic.c"

#include "ewf_netxduo_ppp.c"
#include "ewf_example_netx_duo_ppp_test.c"

/* Modem might take some minutes to attach and register to the network. Time out value in seconds */
#define EWF_ADAPTER_RENESAS_NETWORK_REGISTER_TIMEOUT  (120)

void renesas_ryz024a_adapter_power_on()
{
    // Release the RYZ024A from reset
    R_IOPORT_PinWrite(&g_ioport_ctrl, PMOD2_IO1, BSP_IO_LEVEL_LOW);
    ewf_platform_sleep(50);
    R_IOPORT_PinWrite(&g_ioport_ctrl, PMOD2_IO1, BSP_IO_LEVEL_HIGH);
    EWF_LOG("Waiting for the module to Power Reset!\r\n");
    ewf_platform_sleep(300);
}

/* Embedded Wireless Framework (EWF) test thread entry function */
void ewf_netxduo_ppp_test_thread_entry(void)
{
    ewf_result result;

    /* Power on the modem */
    renesas_ryz024a_adapter_power_on();

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
    EWF_INTERFACE_RA_UART_STATIC_DECLARE(interface_ptr , sci_uart);
    EWF_ADAPTER_RENESAS_RYZ024A_STATIC_DECLARE(adapter_ptr, renesas_ryz024a, message_allocator_ptr, NULL, interface_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

    // Set the APN
    if (ewf_result_failed(result = ewf_adapter_modem_pdp_apn_set(adapter_ptr, EWF_CONFIG_CONTEXT_ID, EWF_ADAPTER_MODEM_PDP_TYPE_IP, EWF_CONFIG_SIM_APN)))
    {
        EWF_LOG_ERROR("Failed to the set APN, ewf_result %d.\n", result);
        exit(result);
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL)))
    {
        EWF_LOG_ERROR("Failed to the ME functionality, ewf_result %d.\n", result);
        return;
    }

    /* Wait time for modem to be ready after modem is registered to network */
    ewf_platform_sleep(3 * EWF_PLATFORM_TICKS_PER_SECOND);

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_adapter_modem_network_registration_check(adapter_ptr, EWF_ADAPTER_MODEM_CMD_QUERY_EPS_NETWORK_REG, EWF_ADAPTER_RENESAS_NETWORK_REGISTER_TIMEOUT)))
    {
        EWF_LOG("[ERROR][Failed to register to network.]\n");
        return;
    }

    // Call the NetX Duo test example
    if (ewf_result_failed(result = ewf_example_netx_duo_ppp_test(adapter_ptr)))
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
