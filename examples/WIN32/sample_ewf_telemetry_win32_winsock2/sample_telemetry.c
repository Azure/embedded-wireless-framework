/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter telemetry example.
 ****************************************************************************/

#include "ewf_adapter_winsock2.h" // Include first to force correct inclussion order for winsock2.h
#include "ewf_allocator_c_heap.h"
#include "ewf_lib.h"
#include "ewf_example.config.h"

/**
 * @brief The application entry point
 */
int main(int argc, char ** argv)
{
    ewf_result result;

    ewf_allocator* data_allocator_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_C_HEAP_STATIC_DECLARE(data_allocator_ptr, data_allocator,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_COUNT,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_SIZE);
    EWF_ADAPTER_WINSOCK2_STATIC_DECLARE(adapter_ptr, winsock2_adapter, data_allocator_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

    // Call the telemetry example
    if (ewf_result_failed(result = ewf_example_telemetry_basic()))
    {
        EWF_LOG_ERROR("The telemetry example returned and error: ewf_result %d.\n", result);
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
