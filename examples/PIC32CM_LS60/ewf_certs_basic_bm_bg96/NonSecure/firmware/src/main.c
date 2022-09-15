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

#include "ewf_example.config.h"
#include "ewf_example_certs_basic_quectel_bg96.c"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

void mikroe_bg96_power_on()
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

    //mikroe_bg96_power_on();
     
    ewf_result result;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_MEMORY_POOL_STATIC_DECLARE(message_allocator_ptr, message_allocator, 4, 1024);
    EWF_INTERFACE_MICROCHIP_PIC_UART_STATIC_DECLARE(interface_ptr, pic_uart);
    EWF_ADAPTER_QUECTEL_BG96_STATIC_DECLARE(adapter_ptr, quectel_bg96, message_allocator_ptr, NULL, interface_ptr);

    /* Start the adapter.  */
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr))) {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN))) {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        exit(result);
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, "1"))) {
        EWF_LOG_ERROR("Failed to the ME functionality, ewf_result %d.\n", result);
        exit(result);
    }

    // Call the certificate provisioning example
    if (ewf_result_failed(result = ewf_example_certs_basic_quectel_bg96(adapter_ptr)))
    {
        EWF_LOG_ERROR("The certificate provisioning example returned and error: result  0x%08x.", result);
        exit(result);
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

