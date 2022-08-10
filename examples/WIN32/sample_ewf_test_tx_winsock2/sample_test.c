/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter test example.
 ****************************************************************************/

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#include <stdlib.h>

#include "ewf_platform_threadx.h"
#include "ewf_allocator_threadx.h"
#include "ewf_adapter_winsock2.h"
#include "ewf_lib.h"
#include "ewf_example.config.h"

/* ThreadX thread, entry point, stack*/
static TX_THREAD thread_sample;
static void thread_sample_entry(ULONG thread_input);
#define THREAD_SAMPLE_STACK_SIZE (1024)
static ULONG thread_sample_stack[THREAD_SAMPLE_STACK_SIZE / sizeof(ULONG)];


/**
 *  @brief The application entry point, initialize the hardware and start ThreadX
 */
int main(int argc, char ** argv)
{

  /* Enter the ThreadX kernel.  */
  tx_kernel_enter();
}


/**
 *  @brief Define what the initial ThreadX system looks like.
 */
void tx_application_define(void *first_unused_memory)
{
  UINT status;

  /* Create the sample thread.  */
  status = tx_thread_create(
    &thread_sample,
    "thread sample",
    thread_sample_entry, 0,
    thread_sample_stack, THREAD_SAMPLE_STACK_SIZE,
    3, 3,
    TX_NO_TIME_SLICE,
    TX_AUTO_START);
  if (status != TX_SUCCESS)
  {
      exit(-1);
  }
}


/**
 *  @brief The sample thread entry point, it calls other examples
 */
void thread_sample_entry(ULONG param)
{
    ewf_result result;

    ewf_allocator* data_allocator_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_C_HEAP_STATIC_DECLARE(data_allocator_ptr, data_allocator,
        EWF_CONFIG_ALLOCATOR_BLOCK_COUNT,
        EWF_CONFIG_ALLOCATOR_BLOCK_SIZE);
    EWF_ADAPTER_WINSOCK2_STATIC_DECLARE(adapter_ptr, winsock2_adapter, data_allocator_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

    // Get the adapter info
    if (ewf_result_failed(result = ewf_adapter_test(adapter_ptr)))
    {
        EWF_LOG_ERROR("The test function returned an error, ewf_result %d.\n", result);
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
