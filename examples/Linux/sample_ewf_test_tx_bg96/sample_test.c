// Copyright (c) Microsoft Corporation. All rights reserved.

#include <stdlib.h>

#include "tx_api.h"

#include "az_sdnet_adapter_test.h"
#include "az_sdnet_lib.h"

#include "az_sdnet_example_config.h"


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
  az_sdnet_result result;

  // Start the adapter
  if (az_sdnet_result_failed(result = az_sdnet_adapter_start()))
  {
    AZ_SDNET_LOG_ERROR("Failed to start the modem: az_result return code 0x%08x.", result);
    exit(result);
  }

  // Run the adapter tests
  if (az_sdnet_result_failed(result = az_sdnet_adapter_test_main()))
  {
    AZ_SDNET_LOG_ERROR("Failed to run the adapter test: az_result return code 0x%08x.", result);
    exit(result);
  }

  while (1)
  {
    tx_thread_sleep(100);
  }
}
