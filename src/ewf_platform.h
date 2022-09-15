/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Software Platform API
 ****************************************************************************/

#ifndef __ewf_platform__h__included__
#define __ewf_platform__h__included__

#include "ewf.h"

/****************************************************************************
 * Check for platform definitions, define/undef EWF_PLATFORM_HAS_THREADING
 ****************************************************************************/

#if defined(EWF_PLATFORM_BARE_METAL) && !defined(EWF_PLATFORM_THREADX) && !defined(EWF_PLATFORM_FREERTOS) && !defined(EWF_PLATFORM_WIN32) && !defined(EWF_PLATFORM_PTHREAD)
#undef EWF_PLATFORM_HAS_THREADING
#elif !defined(EWF_PLATFORM_BARE_METAL) && defined(EWF_PLATFORM_THREADX) && !defined(EWF_PLATFORM_FREERTOS) && !defined(EWF_PLATFORM_WIN32) && !defined(EWF_PLATFORM_PTHREAD)
#define EWF_PLATFORM_HAS_THREADING
#elif !defined(EWF_PLATFORM_BARE_METAL) && !defined(EWF_PLATFORM_THREADX) && defined(EWF_PLATFORM_FREERTOS) && !defined(EWF_PLATFORM_WIN32) && !defined(EWF_PLATFORM_PTHREAD)
#define EWF_PLATFORM_HAS_THREADING
#elif !defined(EWF_PLATFORM_BARE_METAL) && !defined(EWF_PLATFORM_THREADX) && !defined(EWF_PLATFORM_FREERTOS) && defined(EWF_PLATFORM_WIN32) && !defined(EWF_PLATFORM_PTHREAD)
#define EWF_PLATFORM_HAS_THREADING
#elif !defined(EWF_PLATFORM_BARE_METAL) && !defined(EWF_PLATFORM_THREADX) && !defined(EWF_PLATFORM_FREERTOS) && !defined(EWF_PLATFORM_WIN32) && defined(EWF_PLATFORM_PTHREAD)
#define EWF_PLATFORM_HAS_THREADING
#else
#error One and only one valid platform should be defined (check the file ewf.config.h and/or your build settings)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_platform EWF Platform API
 * @brief Functions for abstracting the platform where EWF is running.
 * @{
 ****************************************************************************/

/**
 * @brief Sleeps for a number of time ticks
 * @param[in] time the number of ticks to sleep
 * @return #ewf_result status code
 */
ewf_result ewf_platform_sleep(uint32_t time);

#ifdef EWF_PLATFORM_HAS_THREADING

/************************************************************************//**
 * @defgroup group_platform_thread EWF Platform API - Thread
 * @brief Functions for abstracting the platform where EWF is running.
 * @{
 ****************************************************************************/

/**
 * @brief The generic thread priority type
 */
enum ewf_platform_thread_priority;

/**
 * @brief The thread structure, defined per platform
 */
struct _ewf_platform_thread;

/**
 * @brief The generic thread type
 */
typedef struct _ewf_platform_thread ewf_platform_thread;

/**
 * @brief The generic thread function type
 */
typedef ewf_result(*ewf_platform_thread_function)(void *);

/**
 * @brief Create a thread
 * The thread is created in the stopped state, call "start" to execute it
 * @return #ewf_result status code
 */
ewf_result ewf_platform_thread_create(ewf_platform_thread * thread_ptr);

/**
 * @brief Destroy a thread
 * @return #ewf_result status code
 */
ewf_result ewf_platform_thread_destroy(ewf_platform_thread * thread_ptr);

/**
 * @brief Start a thread
 * This function needs to be called to execute newly create threads
 * @return #ewf_result status code
 */
ewf_result ewf_platform_thread_start(ewf_platform_thread * thread_ptr);

/**
 * @brief Stop a thread
 * @return #ewf_result status code
 */
ewf_result ewf_platform_thread_stop(ewf_platform_thread * thread_ptr);

/************************************************************************//**
 * @} * group_platform_thread
 ****************************************************************************/

#endif /* EWF_PLATFORM_HAS_THREADING */

#ifdef EWF_PLATFORM_HAS_THREADING

/************************************************************************//**
 * @defgroup group_platform_mutex EWF Platform API - Mutex
 * @brief Functions for abstracting the platform where EWF is running.
 * @{
 ****************************************************************************/

/**
 * @brief The mutex structure, defined per platform
 */
struct _ewf_platform_mutex;

/**
 * @brief The generic mutex type
 */
typedef struct _ewf_platform_mutex ewf_platform_mutex;

/**
 * @brief Create a mutex
 * A newly created is not owned, to acquire the mutex call "get"
 * @return #ewf_result status code
 */
ewf_result ewf_platform_mutex_create(ewf_platform_mutex * mutex_ptr);

/**
 * @brief Destroy a mutex
 * @return #ewf_result status code
 */
ewf_result ewf_platform_mutex_destroy(ewf_platform_mutex * mutex_ptr);

/**
 * @brief Obtain ownership of a mutex
 * This function needs to be called to acquire newly created mutexes
 * @return #ewf_result status code
 */
ewf_result ewf_platform_mutex_get(ewf_platform_mutex * mutex_ptr);

/**
 * @brief Release ownership of a mutex
 * @return #ewf_result status code
 */
ewf_result ewf_platform_mutex_put(ewf_platform_mutex * mutex_ptr);

/************************************************************************//**
 * @} * group_platform_mutex
 ****************************************************************************/

#endif /* EWF_PLATFORM_HAS_THREADING */

/************************************************************************//**
 * @defgroup group_platform_queue EWF Platform API - Queue
 * @brief Functions for abstracting the platform where EWF is running.
 * @{
 ****************************************************************************/

/**
 * @brief The queue structure, defined per platform
 */
struct _ewf_platform_queue;

/**
 * @brief The generic queue type
 */
typedef struct _ewf_platform_queue ewf_platform_queue;

/**
 * @brief Create a queue
 * @return #ewf_result status code
 */
ewf_result ewf_platform_queue_create(ewf_platform_queue* queue_ptr);

/**
 * @brief Destroy a queue
 * @return #ewf_result status code
 */
ewf_result ewf_platform_queue_destroy(ewf_platform_queue* queue_ptr);

/**
 * @brief Enqueue an item
 * @return #ewf_result status code
 */
ewf_result ewf_platform_queue_enqueue(ewf_platform_queue* queue_ptr, const void* data_ptr, uint32_t data_size, bool wait);

/**
 * @brief Dequeue an item
 * @return #ewf_result status code
 */
ewf_result ewf_platform_queue_dequeue(ewf_platform_queue* queue_ptr, void* buffer_ptr, uint32_t* buffer_size_ptr, bool wait);

/************************************************************************//**
 * @} * group_platform_queue
 ****************************************************************************/

/************************************************************************//**
 * @} * group_platform
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

/****************************************************************************
 * Include the platform specific header
 ****************************************************************************/

#if defined(EWF_PLATFORM_BARE_METAL)
#include "ewf_platform_bare_metal.h"
#elif defined(EWF_PLATFORM_THREADX)
#include "ewf_platform_threadx.h"
#elif defined(EWF_PLATFORM_FREERTOS)
#include "ewf_platform_freertos.h"
#elif defined(EWF_PLATFORM_WIN32)
#include "ewf_platform_win32.h"
#elif defined(EWF_PLATFORM_PTHREAD)
#include "ewf_platform_pthread.h"
#else
#error No valid platform defined!
#endif

#endif /* __ewf_platform__h__included__ */
