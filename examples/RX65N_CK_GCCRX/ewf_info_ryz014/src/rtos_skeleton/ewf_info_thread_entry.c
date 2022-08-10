/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : thread_x_entry.c
 * Version      : 1.0
 * Description  : declare Thread entry function  
 **********************************************************************************************************************/
/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "azurertos_object_init.h"

#include "ewf_lib.c"
#include "ewf_platform_threadx.c"
#include "ewf_allocator.c"
#include "ewf_allocator_threadx.c"
#include "ewf_interface.c"
#include "ewf_interface_rx_uart.c"
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

#include "ewf_example.config.h"

#include "r_gpio_rx_if.h"

/* New Thread entry function */
void ewf_info_thread_entry(ULONG entry_input)
{

	ewf_result result;

	ewf_allocator* message_allocator_ptr = NULL;
	ewf_interface* interface_ptr = NULL;
	ewf_adapter* adapter_ptr = NULL;

	EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator, 12, 256);
	EWF_INTERFACE_RX_UART_STATIC_DECLARE(interface_ptr , sci_uart);
	EWF_ADAPTER_RENESAS_RYZ014_STATIC_DECLARE(adapter_ptr, renesas_ryz014, message_allocator_ptr, NULL, interface_ptr);


	// Release the RYZ014A from reset
    PORTD.PODR.BIT.B0= 1;
    PORTD.PDR.BIT.B0= 1;
    tx_thread_sleep (100);
    PORTD.PODR.BIT.B0= 0;
	EWF_LOG("Waiting for the module to Power Reset!\r\n");
	ewf_platform_sleep(200);
	EWF_LOG("Ready\r\n");

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

	/* Wait for the modem functionality to be up, increase/decrease the sleep time as required by modem and network,
	 * Refer system integration guide for more info */
	uint32_t wait_time_seconds = 15;

	if (ewf_result_failed(result = ewf_adapter_modem_network_registration_check(adapter_ptr, wait_time_seconds)))
	{
		EWF_LOG_ERROR("Failed to register modem to network within timeout specified, ewf_result %d.\n", result);
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

	// Set the SIM PIN
	if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
	{
		EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
		return;
	}

    // Activated the PDP context
    if (ewf_result_failed(result = ewf_adapter_modem_packet_service_activate(adapter_ptr, "1")))
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

