#include "hal_data.h"

#include "ewf_example.config.h"

/* Inclusion of .c files is for demo purposes only.
 * In production code, please compile the below .c files as you would do for other source files :
 * In your IDE add the files to your project, in your make files add the files to your source list, etc.. */
#include "ewf_lib.c"
#include "ewf_platform_bare_metal.c"
#include "ewf_allocator.c"
#include "ewf_allocator_memory_pool.c"
#include "ewf_tokenizer.c"
#include "ewf_tokenizer_basic.c"
#include "ewf_interface.c"
#include "ewf_interface_ra_uart.c"
#include "ewf_adapter.c"
#include "ewf_adapter_api_mqtt_basic.c"
#include "ewf_adapter_api_tls_basic.c"
#include "ewf_adapter_api_info.c"
#include "ewf_adapter_api_control.c"
#include "ewf_adapter_api_modem.c"
#include "ewf_adapter_api_modem_general.c"
#include "ewf_adapter_api_modem_sim_utility.c"
#include "ewf_adapter_api_modem_packet_domain.c"
#include "ewf_adapter_api_modem_network_service.c"
#include "ewf_adapter_renesas_ryz014.c"
#include "ewf_adapter_renesas_common_tokenizer.c"
#include "ewf_adapter_renesas_common_control.c"
#include "ewf_adapter_renesas_common_info.c"
#include "ewf_adapter_renesas_common_urc.c"
#include "ewf_adapter_renesas_common_internet.c"
#include "ewf_adapter_renesas_common_nvm.c"
#include "ewf_adapter_renesas_common_mqtt_basic.c"
#include "ewf_adapter_renesas_common_tls_basic.c"

#include "ewf_example_telemetry_basic.c"

/* Modem might take some minutes to attach and register to the network. Time out value in seconds */
#define EWF_ADAPTER_RENESAS_NETWORK_REGISTER_TIMEOUT  (120)

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

char ewf_log_buffer[1024];
void ewf_ra_bsp_delay(uint32_t delay_ms);
void ewf_ra_bsp_delay(uint32_t delay_ms)
{
    R_BSP_SoftwareDelay(delay_ms, BSP_DELAY_UNITS_MILLISECONDS);
}

void ewf_telemetry_example_entry(void);

/* EWF example entry function */
void ewf_telemetry_example_entry(void)
{
    ewf_result result;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_MEMORY_POOL_STATIC_DECLARE(message_allocator_ptr, message_allocator,
            EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT,
            EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
    EWF_INTERFACE_RA_UART_STATIC_DECLARE(interface_ptr , sci_uart);
    EWF_ADAPTER_RENESAS_RYZ014_STATIC_DECLARE(adapter_ptr, renesas_ryz014, message_allocator_ptr, NULL, interface_ptr);

    // Release the RYZ014A from reset
    ewf_platform_sleep(500);
    R_IOPORT_PinWrite(&g_ioport_ctrl, PMOD2_IO1, BSP_IO_LEVEL_LOW);
    EWF_LOG("Waiting for the module to Power Reset!\r\n");
    ewf_platform_sleep(3000);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        return;
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL)))
    {
        EWF_LOG_ERROR("Failed to the ME functionality, ewf_result %d.\n", result);
        return;
    }
    /* Wait time for modem to be ready after modem functionality set to full */
    ewf_platform_sleep(5000);

    /* Wait for the modem to be registered to network
     * Refer system integration guide for more info */
    while (EWF_RESULT_OK != ewf_adapter_modem_network_registration_check(adapter_ptr, EWF_ADAPTER_MODEM_CMD_QUERY_EPS_NETWORK_REG, EWF_ADAPTER_RENESAS_NETWORK_REGISTER_TIMEOUT));
    /* Wait time for modem to be ready after modem is registered to network */
    ewf_platform_sleep(2000);

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
    if (ewf_result_failed(result = ewf_adapter_modem_packet_service_activate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG_ERROR("Failed to activate the PDP context: ewf_result %d.\n", result);
        // continue despite the error
    }

    // Initialize the TLS basic API
    if (ewf_result_failed(result = ewf_adapter_tls_basic_init(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to init the SSL basic API: return code 0x%08x.", result);
        return;
    }

    // Call the telemetry example
    if (ewf_result_failed(result = ewf_example_telemetry_basic(adapter_ptr)))
    {
        EWF_LOG_ERROR("The telemetry example returned and error: ewf_result %d.\n", result);
        return;
    }

    // Cleaup the TLS basic API
    if (ewf_result_failed(result = ewf_adapter_tls_basic_clean(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to clean the SSL basic API: return code 0x%08x.", result);
        return;
    }

    EWF_LOG("Done!\n");

    // Stay here forever.
    while (1)
    {
        EWF_LOG(".");
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND);
    }
}

/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void)
{
    /* TODO: add your own code here */
    ewf_telemetry_example_entry();

#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
#if BSP_FEATURE_FLASH_LP_VERSION != 0

        /* Enable reading from data flash. */
        R_FACI_LP->DFLCTL = 1U;

        /* Would normally have to wait tDSTOP(6us) for data flash recovery. Placing the enable here, before clock and
         * C runtime initialization, should negate the need for a delay since the initialization will typically take more than 6us. */
#endif
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open (&g_ioport_ctrl, g_ioport.p_cfg);
    }
}

#if BSP_TZ_SECURE_BUILD

BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ();

/* Trustzone Secure Projects require at least one nonsecure callable function in order to build (Remove this if it is not required to build). */
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ()
{

}
#endif
