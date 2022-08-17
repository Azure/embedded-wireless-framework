/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ewf_certs.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "ewf_certs.h"
#include "system/console/sys_console.h"

#include "ewf_lib.c"
#include "ewf_platform_threadx.c"
#include "ewf_allocator.c"
#include "ewf_allocator_threadx.c"
#include "ewf_interface.c"
#include "ewf_interface_microchip_sam_uart.c"
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

#include "ewf_example.config.h"

SYS_CONSOLE_HANDLE ewfConsoleHandle;
char ewf_log_buffer[256];

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the EWF_CERTS_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

EWF_CERTS_DATA ewf_certsData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/

void ewf_certs_tx_bg96_shield_example(void);
void ewf_certs_tx_bg96_shield_example(void)
{
    ewf_result result;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
    EWF_INTERFACE_MICROCHIP_SAM_UART_STATIC_DECLARE(interface_ptr, sam_uart);
    EWF_ADAPTER_QUECTEL_BG96_STATIC_DECLARE(adapter_ptr, quectel_bg96, message_allocator_ptr, NULL, interface_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);
        exit(result);
    }

    // Call the certificate provisioning example
    if (ewf_result_failed(result = ewf_example_certs_basic_quectel_bg96(adapter_ptr)))
    {
        EWF_LOG_ERROR("The certificate provisioning example returned and error, ewf_result %d.\n", result);
        exit(result);
    }

    EWF_LOG("Done!\n");

    /* Stay here forever.  */
    while (1)
    {
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND);
    }
    
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void EWF_CERTS_Initialize ( void )

  Remarks:
    See prototype in ewf_certs.h.
 */

void EWF_CERTS_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    ewf_certsData.state = EWF_CERTS_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void EWF_CERTS_Tasks ( void )

  Remarks:
    See prototype in ewf_certs.h.
 */

void EWF_CERTS_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( ewf_certsData.state )
    {
        /* Application's initial state. */
        case EWF_CERTS_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                ewf_certsData.state = EWF_CERTS_STATE_SERVICE_TASKS;
            }
            break;
        }

        case EWF_CERTS_STATE_SERVICE_TASKS:
        {

            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
