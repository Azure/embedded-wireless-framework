/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ewf_test.c

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

#include "ewf_test.h"
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
#include "test/ewf_adapter_quectel_bg96_test.c"

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
    This structure should be initialized by the EWF_TEST_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

EWF_TEST_DATA ewf_testData;

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
void ewf_test_tx_bg96_shield_example(void);
void ewf_test_tx_bg96_shield_example(void)
{
    ewf_result result;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
    EWF_INTERFACE_MICROCHIP_SAM_UART_STATIC_DECLARE(interface_ptr, sam_uart);
    EWF_ADAPTER_QUECTEL_BG96_STATIC_DECLARE(adapter_ptr, quectel_bg96, message_allocator_ptr, NULL, interface_ptr);

    /* Start the adapter.  */
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter: ewf_result %d.\n", result);
        exit(result);
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN: ewf_result %d.\n", result);
        exit(result);
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL)))
    {
        EWF_LOG_ERROR("Failed to the ME functionality: ewf_result %d.\n", result);
        exit(result);
    }

    /* Run the adapter tests.  */
    if (ewf_result_failed(result = ewf_adapter_quectel_bg96_test(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to run the adapter test: ewf_result %d.", result);
        return;
    }

    EWF_LOG("\r\nDone!\n");

    /* Stay here forever.  */
    while (1)
    {
    	EWF_LOG(".");
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
    void EWF_TEST_Initialize ( void )

  Remarks:
    See prototype in ewf_test.h.
 */

void EWF_TEST_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    ewf_testData.state = EWF_TEST_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void EWF_TEST_Tasks ( void )

  Remarks:
    See prototype in ewf_test.h.
 */

void EWF_TEST_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( ewf_testData.state )
    {
        /* Application's initial state. */
        case EWF_TEST_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                ewf_testData.state = EWF_TEST_STATE_SERVICE_TASKS;
            }
            break;
        }

        case EWF_TEST_STATE_SERVICE_TASKS:
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
