// Copyright (c) Microsoft Corporation. All rights reserved.

#include "ewf_platform.h"
#include "ewf_allocator_c_heap.h"
#include "ewf_interface_win32_com.h"
#include "ewf_adapter_quectel_bg96.h"
#include "ewf_lib.h"
#include "ewf_example.config.h"

/**
 *  @brief The application entry point
 */
int main(int argc, char ** argv)
{
    ewf_result result;

    uint32_t context_id = 1;

    ewf_allocator* message_allocator_ptr = NULL;
    ewf_allocator* data_allocator_ptr = NULL;
    ewf_interface* interface_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_C_HEAP_STATIC_DECLARE(message_allocator_ptr, message_allocator,
        EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT,
        EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
    EWF_ALLOCATOR_C_HEAP_STATIC_DECLARE(data_allocator_ptr, data_allocator, 4, 1500);
    EWF_INTERFACE_WIN32_COM_STATIC_DECLARE(interface_ptr, com_port,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_FILE_NAME,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BAUD_RATE,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BYTE_SIZE,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_PARITY,
        EWF_CONFIG_INTERFACE_WIN32_COM_PORT_STOP_BITS);
    EWF_ADAPTER_QUECTEL_BG96_STATIC_DECLARE(adapter_ptr, quectel_bg96, message_allocator_ptr, data_allocator_ptr, interface_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the modem: az_result return code 0x%08x.", result);
        exit(result);
    }

    // Set the modem PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the modem PIN: az_result return code 0x%08lx.", result);
        exit(result);
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, "1")))
    {
        EWF_LOG_ERROR("Failed to the ME functionality, return code 0x%08lx.", result);
        return;
    }

    // Collect and show the adapter information
    result = ewf_adapter_info(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to query the adapter information: az_result return code 0x%08x.", result);
        exit(result);
    }

    // Run the adapter tests
    if (ewf_result_failed(result = ewf_adapter_quectel_bg96_test(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to run the adapter test: az_result return code 0x%08x.", result);
        exit(result);
    }

    return 0;
}
