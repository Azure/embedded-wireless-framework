// Copyright (c) Microsoft Corporation. All rights reserved.

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>

#include "ewf_lib.c"

#include "ewf_platform_threadx.c"
#include "ewf_allocator_threadx.c"
#include "ewf_adapter_winsock2.c"

#include "ewf_example_telemetry.c"


/**
 * \def EWF_TELEMETRY_THREAD_STACK_SIZE
 * @brief Define the size of the URC thread
 */
#ifndef EWF_DEBUG /* Tight release configuration */
#define EWF_TELEMETRY_THREAD_STACK_SIZE (512)
#else /* Comfortable debug configuration */
#define EWF_TELEMETRY_THREAD_STACK_SIZE (1024)
#endif

/* Telemetry thread */
static TX_THREAD telemetry_thread;
static void telemetry_thread_entry(ULONG thread_input);
static ULONG telemetry_thread_stack[EWF_TELEMETRY_THREAD_STACK_SIZE / sizeof(ULONG)];


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
    telemetry_thread_stack, EWF_TELEMETRY_THREAD_STACK_SIZE,
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

  /* Wait forever  */
  while (1)
  {
    tx_thread_sleep(1);
  }
}
