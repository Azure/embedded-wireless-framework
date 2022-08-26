/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter info example.
 ****************************************************************************/

#include "ewf_adapter_winsock2.h" // Include first to force correct inclussion order for winsock2.h
#include "ewf_allocator_threadx.h"
#include "ewf_lib.h"
#include "ewf_example.config.h"

#include "ewf_middleware_netxduo.c"

#include "ewf_example_netx_duo_test.c"

/* Define the thread for running Azure SDK on ThreadX (THREADX IoT Platform).  */
#ifndef SAMPLE_STACK_SIZE
#define SAMPLE_STACK_SIZE      (1024)
#endif /* SAMPLE_STACK_SIZE  */

#ifndef SAMPLE_THREAD_PRIORITY
#define SAMPLE_THREAD_PRIORITY (4)
#endif /* SAMPLE_THREAD_PRIORITY  */

/* The thread control block  */
static TX_THREAD  sample_thread;

/* Define the thread stack.  */
static ULONG sample_thread_stack[SAMPLE_STACK_SIZE / sizeof(ULONG)];

/* The thread entry point.  */
void sample_thread_entry(ULONG parameter);

/* Define an error counter.  */
ULONG error_counter;


/**
 *  @brief The application entry point, initialize the hardware and start ThreadX
 */
int main(int argc, char** argv)
{

    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();

    /* We never get here, but we keep the compiler happy.  */
    return 0;
}

/**
 *  @brief Define what the initial system looks like.
 */
void tx_application_define(void* first_unused_memory)
{

    UINT  status;

    /* Create sample thread. */
    status = tx_thread_create(&sample_thread, "Sample Thread",
        sample_thread_entry, 0,
        sample_thread_stack, SAMPLE_STACK_SIZE,
        SAMPLE_THREAD_PRIORITY, SAMPLE_THREAD_PRIORITY,
        TX_NO_TIME_SLICE, TX_AUTO_START);

    /* Check for thread creation error.  */
    if (status)
        error_counter++;

}

/**
 *  @brief The sample thread entry point
 */
void sample_thread_entry(ULONG parameter)
{
    ewf_result result;
    ULONG ip_address = 0;
    ULONG network_mask = 0;
    ULONG gateway_address = 0;
    ULONG dns_address = 0;

    ewf_allocator* data_allocator_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(data_allocator_ptr, data_allocator,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_COUNT,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_SIZE);
    EWF_ADAPTER_WINSOCK2_STATIC_DECLARE(adapter_ptr, winsock2_adapter, data_allocator_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

#ifndef NDEBUG
    // Show the adapter info
    if (ewf_result_failed(result = ewf_adapter_info(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to get the adapter info: az_result return code 0x%08lx.", result);
        exit(result);
    }
#endif

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_address(adapter_ptr, (uint32_t*)&ip_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 address: az_result return code 0x%08lx.", result);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_netmask(adapter_ptr, (uint32_t*)&network_mask)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 netmask: az_result return code 0x%08lx.", result);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_gateway(adapter_ptr, (uint32_t*)&gateway_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 gateway: az_result return code 0x%08lx.", result);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_dns(adapter_ptr, (uint32_t*)&dns_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 DNS: az_result return code 0x%08lx.", result);
        exit(result);
    }

    /* Output IP address and gateway address.  */
    EWF_LOG("\nIP address: %lu.%lu.%lu.%lu\r\n",
        (ip_address >> 24),
        (ip_address >> 16 & 0xFF),
        (ip_address >> 8 & 0xFF),
        (ip_address & 0xFF));
    EWF_LOG("\nMask: %lu.%lu.%lu.%lu\r\n",
        (network_mask >> 24),
        (network_mask >> 16 & 0xFF),
        (network_mask >> 8 & 0xFF),
        (network_mask & 0xFF));
    EWF_LOG("\nGateway: %lu.%lu.%lu.%lu\r\n",
        (gateway_address >> 24),
        (gateway_address >> 16 & 0xFF),
        (gateway_address >> 8 & 0xFF),
        (gateway_address & 0xFF));
    EWF_LOG("\nDNS: %lu.%lu.%lu.%lu\r\n",
        (dns_address >> 24),
        (dns_address >> 16 & 0xFF),
        (dns_address >> 8 & 0xFF),
        (dns_address & 0xFF));

    // Call the NetX Duo test example
    if (ewf_result_failed(result = ewf_example_netx_duo_test(adapter_ptr, ip_address, network_mask, gateway_address)))
    {
        EWF_LOG_ERROR("The NetX Duo test example returned and error: az_result return code 0x%08lx.", result);
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
