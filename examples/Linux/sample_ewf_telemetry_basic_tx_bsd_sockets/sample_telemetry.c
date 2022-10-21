// Copyright (c) Microsoft Corporation. All rights reserved.

#include <stdlib.h>
#include <stdio.h>

#include "tx_api.h"

#include "az_sdnet_adapter.h"
#include "az_sdnet_lib.h"

#include "az_sdnet_example_telemetry.c"


/**
 * \def AZ_SDNET_TELEMETRY_THREAD_STACK_SIZE
 * @brief Define the size of the URC thread
 */
#ifndef AZ_SDNET_DEBUG /* Tight release configuration */
#define AZ_SDNET_TELEMETRY_THREAD_STACK_SIZE (512)
#else /* Comfortable debug configuration */
#define AZ_SDNET_TELEMETRY_THREAD_STACK_SIZE (1024)
#endif

/* Telemetry thread */
static TX_THREAD telemetry_thread;
static void telemetry_thread_entry(ULONG thread_input);
static ULONG telemetry_thread_stack[AZ_SDNET_TELEMETRY_THREAD_STACK_SIZE / sizeof(ULONG)];


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

  /* Create the telemetry thread.  */
  status = tx_thread_create(
    &telemetry_thread,
    "Telemetry",
    telemetry_thread_entry, 0,
    telemetry_thread_stack, AZ_SDNET_TELEMETRY_THREAD_STACK_SIZE,
    3, 3,
    TX_NO_TIME_SLICE,
    TX_AUTO_START);
  if (status != TX_SUCCESS)
  {
    exit(status);
  }
}


/**
 *  @brief The telemetry thread entry point
 */
void telemetry_thread_entry(ULONG param)
{
  az_result result;

  // Start the adapter
  if (az_sdnet_result_failed(result = az_sdnet_adapter_start()))
  {
    AZ_SDNET_LOG_ERROR("Failed to start the adapter: az_result return code 0x%08lx.", result);
    exit(result);
  }

#ifndef NDEBUG
  // Show the adapter info
  if (az_sdnet_result_failed(result = az_sdnet_adapter_info()))
  {
    AZ_SDNET_LOG_ERROR("Failed to get the adapter info: az_result return code 0x%08lx.", result);
    exit(result);
  }
#endif

  // Call the telemetry example
  if (az_sdnet_result_failed(result = az_sdnet_example_telemetry()))
  {
    AZ_SDNET_LOG_ERROR("The telemetry example returned and error: az_result return code 0x%08lx.", result);
    exit(result);
  }

  /* Wait forever  */
  while (1)
  {
    tx_thread_sleep(1);
  }
}
