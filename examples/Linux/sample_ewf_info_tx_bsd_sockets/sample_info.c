// Copyright (c) Microsoft Corporation. All rights reserved.

#include <stdlib.h>

#include "ewf_allocator_threadx.h"
#include "ewf_adapter_bsd_sockets.h"
#include "ewf_adapter_test.h"
#include "ewf_lib.h"
#include "ewf_example.config.h"

/**
 *  @brief The application entry point
 */
int main(int argc, char ** argv)
{
    ewf_result result;

    ewf_allocator* data_allocator_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(data_allocator_ptr, data_allocator,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_COUNT,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_SIZE);
    EWF_ADAPTER_BSD_SOCKETS_STATIC_DECLARE(adapter_ptr, bsd_sockets_adapter, data_allocator_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

    // Get the adapter info
    if (ewf_result_failed(result = ewf_adapter_info(adapter_ptr)))
    {
        EWF_LOG_ERROR("The info function returned an error, ewf_result %d.\n", result);
        exit(result);
    }

    EWF_LOG("\nDone!\n");

    /* Stay here forever.  */
    while (1)
    {
        EWF_LOG(".");
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND);
    }

    return 0;
}
