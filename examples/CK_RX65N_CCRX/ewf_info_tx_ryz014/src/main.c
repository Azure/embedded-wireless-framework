/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

#include "tx_api.h"

#include "ewf_lib.h"
#include "ewf_platform_threadx.h"
#include "ewf_allocator.h"
#include "ewf_allocator_threadx.h"
#include "ewf_tokenizer.h"
#include "ewf_tokenizer_basic.h"
#include "ewf_interface.h"
#include "ewf_interface_rx_uart.h"
#include "ewf_adapter.h"
#include "ewf_adapter_api_tcp.h"
#include "ewf_adapter_api_udp.h"
#include "ewf_adapter_api_mqtt_basic.h"
#include "ewf_adapter_api_tls_basic.h"
#include "ewf_adapter_api_info.h"
#include "ewf_adapter_api_control.h"
#include "ewf_adapter_api_modem.h"
#include "ewf_adapter_api_modem_general.h"
#include "ewf_adapter_api_modem_sim_utility.h"
#include "ewf_adapter_api_modem_packet_domain.h"
#include "ewf_adapter_api_modem_network_service.h"
#include "ewf_adapter_renesas_ryz014.h"

#include "ewf_example.config.h"

#include "ewf_cellular_private.h"


/* Modem might take some minutes to attach and register to the network. Time out value in seconds */
#define EWF_ADAPTER_RENESAS_NETWORK_REGISTER_TIMEOUT  (120)

TX_THREAD               ewf_info_thread;
UCHAR                   ewf_info_thread_memory_stack[4096];

/* Define the prototypes for sample thread.  */
static void ewf_info_thread_entry(ULONG parameter);


void platform_setup(void);

void renesas_ryz014a_adapter_power_on()
{

    // Release the RYZ014A from reset
    EWF_CELLULAR_SET_PODR(EWF_CELLULAR_CFG_RESET_PORT, EWF_CELLULAR_CFG_RESET_PIN) = EWF_CELLULAR_CFG_RESET_SIGNAL_ON;
    EWF_CELLULAR_SET_PDR(EWF_CELLULAR_CFG_RESET_PORT, EWF_CELLULAR_CFG_RESET_PIN) = EWF_CELLULAR_PIN_DIRECTION_MODE_OUTPUT;
    ewf_platform_sleep (1 * EWF_PLATFORM_TICKS_PER_SECOND);
    EWF_CELLULAR_SET_PODR(EWF_CELLULAR_CFG_RESET_PORT, EWF_CELLULAR_CFG_RESET_PIN) = EWF_CELLULAR_CFG_RESET_SIGNAL_OFF;
    demo_printf("Waiting for the module to Power Reset!\r\n");
    ewf_platform_sleep(3 * EWF_PLATFORM_TICKS_PER_SECOND);
    demo_printf("Ready\r\n");

}

/* Define main entry point.  */
int main(void)
{   
	/* Setup the hardware. */
	platform_setup();

	/* Enter the ThreadX kernel.  */
	tx_kernel_enter();
}

/* Define what the initial system looks like.  */
void    tx_application_define(void *first_unused_memory)
{
	UINT status;

	status = tx_thread_create(&ewf_info_thread, "EWF info thread",
			ewf_info_thread_entry, 0, ewf_info_thread_memory_stack,
			4096, 5, 5, 0, TX_AUTO_START);

	if (TX_SUCCESS != status)
	{
		while (1)
		{
			/* Failed! Thread can not be created. */
		}
	}
	/* Check status.  */
	if (status)
	{
		printf("Demo helper thread creation fail: %u\r\n", status);
		return;
	}
}

/* Define sample helper thread entry.  */
void ewf_info_thread_entry(ULONG parameter)
{
    /* Initialize the demo printf implementation. */
    demo_printf_init();

    /* Power On the adapter*/
    renesas_ryz014a_adapter_power_on();

    ewf_result result;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
    EWF_INTERFACE_RX_UART_STATIC_DECLARE(interface_ptr , sci_uart);
    EWF_ADAPTER_RENESAS_RYZ014_STATIC_DECLARE(adapter_ptr, renesas_ryz014, message_allocator_ptr, NULL, interface_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        return;
    }

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

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL)))
    {
        EWF_LOG_ERROR("Failed to the ME functionality, ewf_result %d.\n", result);
        return;
    }
    /* Wait time for modem to be ready after modem functionality set to full */
    ewf_platform_sleep(3 * EWF_PLATFORM_TICKS_PER_SECOND);

    // Set the APN
    if (ewf_result_failed(result = ewf_adapter_modem_pdp_apn_set(adapter_ptr, EWF_CONFIG_CONTEXT_ID, EWF_ADAPTER_MODEM_PDP_TYPE_IP, EWF_CONFIG_SIM_APN)))
    {
        EWF_LOG_ERROR("Failed to the set APN, ewf_result %d.\n", result);
        while(1);
    }

    /* Wait for the modem to be registered to network
     * Refer system integration guide for more info */
    if (ewf_result_failed(result = ewf_adapter_modem_network_registration_check(adapter_ptr, EWF_ADAPTER_MODEM_CMD_QUERY_EPS_NETWORK_REG, EWF_ADAPTER_RENESAS_NETWORK_REGISTER_TIMEOUT)))
    {
        EWF_LOG("[ERROR][Failed to register to network.]\n");
        return;
    }
    /* Wait time for modem to be ready after modem to be ready */
    ewf_platform_sleep(3 * EWF_PLATFORM_TICKS_PER_SECOND);

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        return;
    }

    // Activated the PDP context
    if (ewf_result_failed(result = ewf_adapter_modem_packet_service_activate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG_ERROR("Failed to activate the PDP context: ewf_result %d.\n", result);
        // continue despite the error
    }

    // Get the adapter info
    if (ewf_result_failed(result = ewf_adapter_info(adapter_ptr)))
    {
        EWF_LOG_ERROR("The info function returned an error, ewf_result %d.\n", result);
        return;
    }

    EWF_LOG("\nDone!\n");

    while (1)
    {
        EWF_LOG(".");
        tx_thread_sleep(100);
    }
}
