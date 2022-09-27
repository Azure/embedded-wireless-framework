/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework ThreadX platform.
 ****************************************************************************/

#ifndef __ewf_platform_threadx__h__included__
#define __ewf_platform_threadx__h__included__

#include "ewf_platform.h"

#ifndef EWF_PLATFORM_THREADX
#error EWF_PLATFORM_THREADX must be defined before including this file
#endif

#include "tx_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_platform_threadx The ThreadX platform
 * @ingroup group_platform
 * @brief The ThreadX platform
 * @{
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_configuration_platform_threadx Platform configuration (ThreadX)
 * @ingroup group_configuration
 * @ingroup group_platform
 * @brief The definitions used to configure the Azure SD-NET platform.
 * @{
 ****************************************************************************/

#ifndef EWF_PLATFORM_TICKS_PER_SECOND
/** Define the number of ticks per second in the platform; this is used to calculate absolute times.  */
#define EWF_PLATFORM_TICKS_PER_SECOND          (TX_TIMER_TICKS_PER_SECOND)
#endif

#ifndef EWF_PLATFORM_THREAD_PRIORITY_HIGH
/** Define the high priority thread value */
#define EWF_PLATFORM_THREAD_PRIORITY_HIGH      (1)
#endif

#ifndef EWF_PLATFORM_THREAD_PRIORITY_MEDIUM
/** Define the medium priority thread value */
#define EWF_PLATFORM_THREAD_PRIORITY_MEDIUM    (7)
#endif

#ifndef EWF_PLATFORM_THREAD_PRIORITY_LOW
/** Define the low priority thread value */
#define EWF_PLATFORM_THREAD_PRIORITY_LOW       (15)
#endif

/************************************************************************//**
 * @} *** group_configuration_platform_threadx
 ****************************************************************************/

/**
 * @brief The platform thread structure
 */
struct _ewf_platform_thread
{
    TX_THREAD thread;
    CHAR* name_cstr;
    ewf_platform_thread_function thread_function_ptr;
    void* thread_function_data;
    VOID* stack_ptr;
    unsigned stack_size;
    UINT priority;
    UINT preempt_threshold;
    ULONG time_slice;
};

/**
 * @brief Declare statically a thread for the platform and initialize its data
 * @param[in,out] thread_ptr a pointer to a _ewf_platform_thread structure that will point to the statically declared thread
 * @param[in] thread_name_symb a symbol that will be used to uniquely declare and name the thread
 * @param[in] thread_function the thread function of the type ewf_platform_thread_function
 * @param[in] stack_size_param the thread stack size
 * @param[in] thread_priority_param the thread priority
 */
#define EWF_PLATFORM_THREAD_STATIC_DECLARE(thread_ptr, thread_name_symb, thread_function_ptr_param, thread_function_data_param, stack_size_param, thread_priority_param) \
do {                                                                                                                            \
static ULONG _ewf_platform_thread__stack__##thread_name_symb[stack_size_param / sizeof(ULONG)];                                 \
static struct _ewf_platform_thread _ewf_platform_thread__##thread_name_symb = {0};                                              \
_ewf_platform_thread__##thread_name_symb.name_cstr = #thread_name_symb;                                                         \
_ewf_platform_thread__##thread_name_symb.thread_function_ptr = thread_function_ptr_param;                                       \
_ewf_platform_thread__##thread_name_symb.thread_function_data = thread_function_data_param;                                     \
_ewf_platform_thread__##thread_name_symb.stack_ptr = _ewf_platform_thread__stack__##thread_name_symb;                           \
_ewf_platform_thread__##thread_name_symb.stack_size = stack_size_param;                                                         \
_ewf_platform_thread__##thread_name_symb.priority = thread_priority_param;                                                      \
_ewf_platform_thread__##thread_name_symb.preempt_threshold = thread_priority_param;                                             \
_ewf_platform_thread__##thread_name_symb.time_slice = 1;                                                                        \
thread_ptr = &(_ewf_platform_thread__##thread_name_symb);                                                                       \
} while(0)

/**
 * @brief The platform mutex structure
 */
struct _ewf_platform_mutex
{
	/* Use a ThreadX binary semaphore for implementation! */
    TX_SEMAPHORE sem;
    CHAR * name_cstr;
};

/**
 * @brief Declare statically a mutex for the platform and initialize its data
 * @param[in,out] mutex_ptr a pointer to a _ewf_platform_mutex structure that will point to the statically declared mutex
 * @param[in] mutex_name_symb a symbol that will be used to uniquely declare and name the mutex
 */
#define EWF_PLATFORM_MUTEX_STATIC_DECLARE(mutex_ptr, mutex_name_symb)                                                           \
do {                                                                                                                            \
static struct _ewf_platform_mutex _ewf_platform_mutex__##mutex_name_symb = {0};                                                 \
_ewf_platform_mutex__##mutex_name_symb.name_cstr = #mutex_name_symb;                                                            \
mutex_ptr = &(_ewf_platform_mutex__##mutex_name_symb);                                                                          \
} while(0)

/**
 * @brief The platform queue structure
 */
struct _ewf_platform_queue
{
    TX_QUEUE queue;
    CHAR* name_cstr;
    UINT message_size;
    VOID* queue_start;
    ULONG queue_size;
};

/**
 * @brief Declare statically a queue for the platform and initialize its data
 * @param[in,out] queue_ptr a pointer to a _ewf_platform_thread structure that will be made to point to the statically declared thread
 * @param[in] queue_name_symb a symbol that will be used to uniquely declare and name the thread
 * @param[in] item_type type queue item type
 * @param[in] item_count the maximum number item the queue can contain
 */
#define EWF_PLATFORM_QUEUE_STATIC_DECLARE(queue_ptr, queue_name_symb, item_type, item_count)                                    \
do {                                                                                                                            \
static ULONG _ewf_platform_queue__buffer__##queue_name_symb[sizeof(item_type) * item_count];                                    \
static ewf_platform_queue _ewf_platform_queue__##queue_name_symb = {0};                                                         \
_ewf_platform_queue__##queue_name_symb.name_cstr = #queue_name_symb;                                                            \
_ewf_platform_queue__##queue_name_symb.message_size = sizeof(item_type);                                                        \
_ewf_platform_queue__##queue_name_symb.queue_start = _ewf_platform_queue__buffer__##queue_name_symb;                            \
_ewf_platform_queue__##queue_name_symb.queue_size = sizeof(_ewf_platform_queue__buffer__##queue_name_symb);                     \
queue_ptr = &(_ewf_platform_queue__##queue_name_symb);                                                                          \
} while(0)

#ifdef __cplusplus
}
#endif

#endif /* __ewf_platform_threadx__h__included__ */
