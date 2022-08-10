/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework bare metal platform.
 ****************************************************************************/

#ifndef __ewf_platform_bare_metal__h__included__
#define __ewf_platform_bare_metal__h__included__

#include "ewf_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/** Define the number of ticks per second in the platform; this is used to calculate absolute times.  */
#ifndef EWF_PLATFORM_TICKS_PER_SECOND
#define EWF_PLATFORM_TICKS_PER_SECOND          (1000)
#endif

#if defined(__CORTEX_M) /* Generic Cortex-M CMSIS*/
typedef uint32_t ewf_platform_interrupt_state;
#define ewf_platform_interrupt_disable() __disable_irq()
#define ewf_platform_interrupt_enable() __enable_irq()
#define ewf_platform_interrupt_state_get() __get_PRIMASK()
#define ewf_platform_interrupt_state_set(state) __set_PRIMASK(state)
#elif defined(__IAR_SYSTEMS_ICC__) /* Generic IAR */
typedef __istate_t ewf_platform_interrupt_state;
#define ewf_platform_interrupt_disable() __disable_interrupt()
#define ewf_platform_interrupt_enable() __enable_interrupt()
#define ewf_platform_interrupt_state_get() __get_interrupt_state()
#define ewf_platform_interrupt_state_set(state) __set_interrupt_state(state)
#else
// Insert other bare metal implementations here
#error "Bare metal platform not implemented! (yet)"
#endif

#undef EWF_PLATFORM_SUPPORTS_THREADING

#undef EWF_PLATFORM_SUPPORTS_MUTEXING

struct _ewf_platform_queue
{
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
static uint8_t _ewf_platform_queue__buffer__##queue_name_symb[sizeof(item_type) * item_count];                                  \
static ewf_platform_queue _ewf_platform_queue__##queue_name_symb = {0};                                                         \
_ewf_platform_queue__##queue_name_symb.data = _ewf_platform_queue__buffer__##queue_name_symb;                                   \
_ewf_platform_queue__##queue_name_symb.item_size = sizeof(item_type);                                                           \
_ewf_platform_queue__##queue_name_symb.queue_size = item_count;                                                                 \
_ewf_platform_queue__##queue_name_symb.tail_index = 0;                                                                          \
_ewf_platform_queue__##queue_name_symb.used_count = 0;                                                                          \
queue_ptr = &(_ewf_platform_queue__##queue_name_symb);                                                                          \
} while(0)

#ifdef __cplusplus
}
#endif

#endif /* __ewf_platform_bare_metal__h__included__ */
