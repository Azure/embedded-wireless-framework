/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework POSIX threads platform API.
 ****************************************************************************/

#ifndef __ewf_platform_pthread__h__included__
#define __ewf_platform_pthread__h__included__

#include "ewf_platform.h"

#ifndef EWF_PLATFORM_PTHREAD
#error EWF_PLATFORM_PTHREAD must be defined before including this file
#endif

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_platform_pthread The POSIX threads platform
 * @ingroup group_platform
 * @brief The POSIX threads platform
 * @{
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_configuration_platform_pthread Platform configuration (pthreads)
 * @ingroup group_configuration
 * @brief The definitions used to configure the EWF POSIX threads platform.
 * @{
 ****************************************************************************/

/** Define the number of ticks per second in the platform; this is used to calculate absolute times.  */
#define EWF_PLATFORM_TICKS_PER_SECOND (1000)

/** Define the thread priorities */
#define EWF_THREAD_PRIORITY_HIGH       (THREAD_PRIORITY_ABOVE_NORMAL)
#define EWF_THREAD_PRIORITY_MEDIUM     (THREAD_PRIORITY_NORMAL)
#define EWF_THREAD_PRIORITY_LOW        (THREAD_PRIORITY_IDLE)

/************************************************************************//**
 * @} *** group_configuration_platform_pthread
 ****************************************************************************/

struct _ewf_platform_thread
{
    pthread_t thread;
    pthread_attr_t attr;
    ewf_platform_thread_function thread_function_ptr;
    void* thread_function_data;
    size_t stacksize;
    int prio;
};

#define EWF_PLATFORM_THREAD_STATIC_DECLARE(thread_ptr, thread_name_symb, thread_function_ptr_param, thread_function_data_param, stack_size_param, thread_priority_param)  \
do {                                                                                                                            \
static ewf_platform_thread__##thread_name_symb = {0};                                                                           \
ewf_platform_pthread__##thread_name_symb.thread_function_ptr = thread_function_ptr_param;                                       \
ewf_platform_pthread__##thread_name_symb.thread_function_data = thread_function_data_param;                                     \
ewf_platform_pthread__##thread_name_symb.stacksize = stack_size_param;                                                          \
ewf_platform_pthread__##thread_name_symb.prio = thread_priority_param;                                                          \
thread_ptr = &(ewf_platform_pthread__##thread_name_symb);                                                                       \
} while(0)

struct _ewf_platform_mutex
{
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexattr;
};

#define EWF_PLATFORM_MUTEX_STATIC_DECLARE(mutex_ptr, mutex_name_symb)                                                           \
do {                                                                                                                            \
static ewf_platform_mutex ewf_platform_mutex__##mutex_name_symb = {0};                                                          \
mutex_ptr = &(ewf_platform_mutex__##mutex_name_symb);                                                                           \
} while(0)

struct _ewf_platform_queue
{
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexattr;
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
 * @} *** group_platform_pthread
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_platform_pthread__h__included__ */
