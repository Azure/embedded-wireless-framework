/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework freeRTOS platform API
 ****************************************************************************/

#ifndef __ewf_platform_freertos__h__included__
#define __ewf_platform_freertos__h__included__

#include "ewf_platform.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_configuration_platform_freertos Platform configuration (FreeRTOS)
 * @ingroup group_configuration
 * @ingroup group_platform
 * @brief The definitions used to configure the Azure SD-NET platform.
 * @{
 ****************************************************************************/

/** Define the number of ticks per second in the platform; this is used to calculate absolute times.  */
#define EWF_PLATFORM_TICKS_PER_SECOND          (configTICK_RATE_HZ)

/** Define the thread priorities */
#define EWF_PLATFORM_THREAD_PRIORITY_HIGH      (configMAX_PRIORITIES - 1)
#define EWF_PLATFORM_THREAD_PRIORITY_MEDIUM    (configMAX_PRIORITIES / 2)
#define EWF_PLATFORM_THREAD_PRIORITY_LOW       (1)

/************************************************************************//**
 * @} *** group_configuration_platform_freertos
 ****************************************************************************/

struct _ewf_platform_thread
{
    StaticTask_t task;
    char * name_ptr;
    ewf_platform_thread_function thread_function_ptr;
    void* thread_function_data;
    StackType_t * stack_ptr;
    uint32_t stack_size;
    UBaseType_t priority;
    TaskHandle_t task_handle;
};

#define EWF_PLATFORM_THREAD_STATIC_DECLARE(thread_ptr, thread_name_symb, thread_function_ptr_param, thread_function_data_param, stack_size_param, thread_priority_param)  \
do {                                                                                                                                        \
static StackType_t _ewf_platform_thread__stack__##thread_name_symb[stack_size_param / sizeof(StackType_t ) + 1];                       \
static struct _ewf_platform_thread _ewf_platform_thread__##thread_name_symb = {0};                                                \
_ewf_platform_thread__##thread_name_symb.name_ptr = #thread_name_symb;                                                                 \
_ewf_platform_thread__##thread_name_symb.thread_function_ptr = thread_function_ptr_param;                                              \
_ewf_platform_thread__##thread_name_symb.thread_function_data = thread_function_data_param;                                            \
_ewf_platform_thread__##thread_name_symb.stack_ptr = _ewf_platform_thread__stack__##thread_name_symb;                             \
_ewf_platform_thread__##thread_name_symb.stack_size = stack_size_param / sizeof(StackType_t);                                          \
_ewf_platform_thread__##thread_name_symb.priority = thread_priority_param;                                                             \
_ewf_platform_thread__##thread_name_symb.task_handle = NULL;                                                                           \
thread_ptr = &(_ewf_platform_thread__##thread_name_symb);                                                                              \
} while(0)

struct _ewf_platform_mutex
{
    SemaphoreHandle_t semaphore_handle;
    StaticSemaphore_t semaphore;
};

#define EWF_PLATFORM_MUTEX_STATIC_DECLARE(mutex_ptr, mutex_name)                                                               \
do {                                                                                                                                \
static struct _ewf_platform_mutex _ewf_platform_mutex__##mutex_name = {0};                                                \
mutex_ptr = &(_ewf_platform_mutex__##mutex_name);                                                                              \
} while(0)

/**
 * @brief The platform queue structure
 */
struct _ewf_platform_queue
{
    QueueHandle_t xQueue;
    StaticQueue_t xStaticQueue;
    char* name_cstr;
    uint32_t message_size;
    UBaseType_t uxQueueLength;
    UBaseType_t uxItemSize;
    uint8_t* pucQueueStorageBuffer;
};

/**
 * @brief Declare statically a queue for the platform and initialize its data
 * @param[in,out] queue_ptr a pointer to a _ewf_platform_thread structure that will be made to point to the statically declared thread
 * @param[in] queue_name_symb a symbol that will be used to uniquely declare and name the thread
 * @param[in] item_type type queue item type
 * @param[in] item_count the maximum number item the queue can contain
 */
#define EWF_PLATFORM_QUEUE_STATIC_DECLARE(queue_ptr, queue_name_symb, item_type_param, item_count_param)                           \
do {                                                                                                                                    \
static uint8_t ewf_platform_queue__buffer__##queue_name_symb[sizeof(item_type_param) * item_count_param];                          \
static ewf_platform_queue ewf_platform_queue__##queue_name_symb = {0};                                                        \
ewf_platform_queue__##queue_name_symb.name_cstr = #queue_name_symb;                                                                \
ewf_platform_queue__##queue_name_symb.uxQueueLength = item_count_param;                                                            \
ewf_platform_queue__##queue_name_symb.uxItemSize = sizeof(item_type_param);                                                        \
ewf_platform_queue__##queue_name_symb.pucQueueStorageBuffer = ewf_platform_queue__buffer__##queue_name_symb;                  \
queue_ptr = &(ewf_platform_queue__##queue_name_symb);                                                                              \
} while(0)

#ifdef __cplusplus
}
#endif

#endif /* __ewf_platform_freertos__h__included__ */
