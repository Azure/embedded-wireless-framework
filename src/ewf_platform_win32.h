/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework WIN32 platform.
 ****************************************************************************/

#ifndef __ewf_platform_win32__h__included__
#define __ewf_platform_win32__h__included__

#include "ewf_platform.h"

#ifndef EWF_PLATFORM_WIN32
#error EWF_PLATFORM_WIN32 must be defined before including this file
#endif

#include <WinSock2.h>
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_platform_win32 The WIN32 platform
 * @ingroup group_platform
 * @brief The WIN32 platform
 * @{
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_configuration_platform_win32 Platform configuration (WIN32)
 * @ingroup group_configuration
 * @brief The definitions used to configure the Azure SD-NET WIN32 platform.
 * @{
 ****************************************************************************/

/** Define the number of ticks per second in the platform; this is used to calculate absolute times.  */
#define EWF_PLATFORM_TICKS_PER_SECOND (1000)

/** Define the thread priorities */
#define EWF_THREAD_PRIORITY_HIGH       (THREAD_PRIORITY_ABOVE_NORMAL)
#define EWF_THREAD_PRIORITY_MEDIUM     (THREAD_PRIORITY_NORMAL)
#define EWF_THREAD_PRIORITY_LOW        (THREAD_PRIORITY_IDLE)

/************************************************************************//**
 * @} *** group_configuration_platform_win32
 ****************************************************************************/

struct _ewf_platform_thread
{
    HANDLE hThread;
    unsigned dwThreadId;
    ewf_platform_thread_function thread_function_ptr;
    void* thread_function_data;
};

#define EWF_PLATFORM_THREAD_STATIC_DECLARE(thread_ptr, thread_name_symb, thread_function_ptr_param, thread_function_data_param, stack_size_param, thread_priority_param)  \
do {                                                                                                                            \
static ULONG _ewf_platform_thread__stack__##thread_name_symb[stack_size_param / sizeof(ULONG)];                                 \
static struct _ewf_platform_thread _ewf_platform_thread__##thread_name_symb = {0};                                              \
_ewf_platform_thread__##thread_name_symb.thread_function_ptr = thread_function_ptr_param;                                       \
_ewf_platform_thread__##thread_name_symb.thread_function_data = thread_function_data_param;                                     \
thread_ptr = &(_ewf_platform_thread__##thread_name_symb);                                                                       \
} while(0)

struct _ewf_platform_mutex
{
    HANDLE hMutex;
};

#define EWF_PLATFORM_MUTEX_STATIC_DECLARE(mutex_ptr, mutex_name_symb)                                                           \
do {                                                                                                                            \
static struct _ewf_platform_mutex _ewf_platform_mutex__##mutex_name_symb = {0};                                                 \
mutex_ptr = &(_ewf_platform_mutex__##mutex_name_symb);                                                                          \
} while(0)

struct _ewf_platform_queue
{
    HANDLE hMutex;
    void* data;
    uint32_t item_size;
    volatile uint32_t queue_size;
    volatile uint32_t tail_index;
    volatile uint32_t used_count;
};

/**
 * @brief Declare statically a queue for the platform and initialize its data
 * @param[in,out] queue_ptr a pointer to a _ewf_platform_queue structure that will be made to point to the statically declared queue
 * @param[in] queue_name_symb a symbol that will be used to uniquely declare and name the queue
 * @param[in] item_type type queue item type
 * @param[in] item_count the maximum number item the queue can contain
 */
#define EWF_PLATFORM_QUEUE_STATIC_DECLARE(queue_ptr, queue_name_symb, item_type, item_count)                                    \
do {                                                                                                                            \
static item_type ewf_platform_queue__data__##queue_name_symb[item_count];                                                       \
static ewf_platform_queue ewf_platform_queue__##queue_name_symb = {0};                                                          \
ewf_platform_queue__##queue_name_symb.data = ewf_platform_queue__data__##queue_name_symb;                                       \
ewf_platform_queue__##queue_name_symb.item_size = sizeof(item_type);                                                            \
ewf_platform_queue__##queue_name_symb.queue_size = item_count;                                                                  \
ewf_platform_queue__##queue_name_symb.tail_index = 0;                                                                           \
ewf_platform_queue__##queue_name_symb.used_count = 0;                                                                           \
queue_ptr = &(ewf_platform_queue__##queue_name_symb);                                                                           \
} while(0)

/************************************************************************//**
 * @} *** group_platform_win32
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_platform_win32__h__included__ */
