// Copyright (c) Microsoft Corporation. All rights reserved.

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>

#include "ewf_lib.c"

#include "ewf_platform_win32.c"
#include "ewf_allocator_c_heap.c"
#include "ewf_adapter_winsock2.c"

#include "ewf_example_telemetry.c"

/**
 *  @brief The application entry point, initialize the hardware and start ThreadX
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

#ifndef NDEBUG
    // Show the adapter info
    if (ewf_result_failed(result = ewf_adapter_info()))
    {
        EWF_LOG_ERROR("Failed to get the adapter info: az_result return code 0x%08lx.", result);
        exit(result);
    }
#endif

    // Call the telemetry example
    if (ewf_result_failed(result = ewf_example_telemetry()))
    {
        EWF_LOG_ERROR("The telemetry example returned and error: az_result return code 0x%08lx.", result);
        exit(result);
    }

    return 0;
}
