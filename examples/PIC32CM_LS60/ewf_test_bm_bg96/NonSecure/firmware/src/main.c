/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "ewf_lib.c"
#include "ewf_platform_bare_metal.c"
#include "ewf_allocator.c"
#include "ewf_allocator_memory_pool.c"
#include "ewf_tokenizer.c"
#include "ewf_tokenizer_basic.c"
#include "ewf_interface.c"
#include "ewf_interface_microchip_pic_uart.c"
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
#include "ewf_adapter_quectel_common_tokenizer.c"
#include "ewf_adapter_quectel_common_urc.c"
#include "ewf_adapter_quectel_common_control.c"
#include "ewf_adapter_quectel_common_context.c"
#include "ewf_adapter_quectel_common_info.c"
#include "ewf_adapter_quectel_common_internet.c"
#include "ewf_adapter_quectel_common_ufs.c"
#include "ewf_adapter_quectel_common_mqtt_basic.c"
#include "ewf_adapter_quectel_common_tls_basic.c"

#include "ewf_example.config.h"
#include "test/ewf_adapter_quectel_bg96_test.c"

/* Modem might take some minutes to attach and register to the network. Time out value in seconds */
#define EWF_ADAPTER_QUECTEL_NETWORK_REGISTER_TIMEOUT  (120)

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

void mikroe_bg96_power_toggle()
{
    GPIO_PB04_OutputEnable();
    GPIO_PB04_Clear();
    SYSTICK_DelayMs(200); 
    GPIO_PB04_Set();
    SYSTICK_DelayMs(2000); 
    GPIO_PB04_Clear();
    SYSTICK_DelayMs(5000);  
}   
int main(void) {
    /* Initialize all modules */
    SYS_Initialize(NULL);
    
    SYSTICK_TimerStart();

//    mikroe_bg96_power_toggle();
    
    ewf_result result;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_MEMORY_POOL_STATIC_DECLARE(message_allocator_ptr, message_allocator, 5, 512);
    EWF_INTERFACE_MICROCHIP_PIC_UART_STATIC_DECLARE(interface_ptr, pic_uart);
    EWF_ADAPTER_QUECTEL_BG96_STATIC_DECLARE(adapter_ptr, quectel_bg96, message_allocator_ptr, NULL, interface_ptr);

    /* Start the adapter.  */
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr))) {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }
    // Set the ME functionality to minimum to clear out any previous connections
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_MINIMUM)))
    {
        EWF_LOG("[Warning][Failed to the ME functionality]\n");
    }
    ewf_platform_sleep(1 * EWF_PLATFORM_TICKS_PER_SECOND);

    // Set the APN
    if (ewf_result_failed(result = ewf_adapter_modem_pdp_apn_set(adapter_ptr, EWF_CONFIG_CONTEXT_ID, EWF_ADAPTER_MODEM_PDP_TYPE_IPV4V6, EWF_CONFIG_SIM_APN)))
    {
        EWF_LOG_ERROR("Failed to the set APN, ewf_result %d.\n", result);
        while(1);
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL)))
    {
        EWF_LOG_ERROR("Failed to the ME functionality, ewf_result %d.\n", result);
        while(1);
    }

    /* Wait time for modem to be ready after modem is registered to network */
    ewf_platform_sleep(3 * EWF_PLATFORM_TICKS_PER_SECOND);

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        while(1);
    }

    /* Check modem registration */
    if (ewf_result_failed(result = ewf_adapter_modem_network_registration_check(adapter_ptr, 
            EWF_ADAPTER_MODEM_CMD_QUERY_EPS_NETWORK_REG, 
            EWF_ADAPTER_QUECTEL_NETWORK_REGISTER_TIMEOUT)))
    {
        EWF_LOG("[ERROR][Failed to register to network.]\n");
        while(1);
    }
    
    /* Run the adapter tests.  */
    if (ewf_result_failed(result = ewf_adapter_quectel_bg96_test(adapter_ptr))) {
        EWF_LOG_ERROR("Failed to run the adapter test: ewf_result %d.", result);
    }

    EWF_LOG("\nDone!\n");

    while(1)
    {
        EWF_LOG(".");
        SYSTICK_DelayMs(1000);
        
    }
}


/*******************************************************************************
 End of File
 */

