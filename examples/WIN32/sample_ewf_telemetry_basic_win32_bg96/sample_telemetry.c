// Copyright (c) Microsoft Corporation. All rights reserved.

#include "ewf_lib.c"

#include "ewf_platform_win32.c"
#include "ewf_allocator_c_heap.c"
#include "ewf_interface_win32_com.c"
#include "ewf_adapter_quectel_bg96.api.c"

#include "ewf_example_telemetry.c"

/**
 * @brief The application entry point
 */
int main(int argc, char ** argv)
{
    az_result result;

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start()))
    {
        EWF_LOG_ERROR("Failed to start the adapter: az_result return code 0x%08lx.", result);
        exit(result);
    }

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN: az_result return code 0x%08lx.", result);
        exit(result);
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_set_functionality("1")))
    {
        EWF_LOG_ERROR("Failed to the ME functionality: az_result return code 0x%08lx.", result);
        exit(result);
    }

    // Activated the PDP context
    if (ewf_result_failed(result = ewf_adapter_quectel_bg96_context_activate(1)))
    {
        EWF_LOG_ERROR("Failed to activate the PDP context: az_result return code 0x%08lx.", result);
        // continue despite the error
    }

    // Call the telemetry example
    if (ewf_result_failed(result = ewf_example_telemetry()))
    {
        EWF_LOG_ERROR("The telemetry example returned and error: az_result return code 0x%08lx.", result);
        exit(result);
    }

    return 0;
}
