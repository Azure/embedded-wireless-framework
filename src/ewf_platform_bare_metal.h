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

#ifndef EWF_PLATFORM_BARE_METAL
#error EWF_PLATFORM_BARE_METAL must be defined before including this file
#endif

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EWF_PLATFORM_TICKS_PER_SECOND
/** Define the number of ticks per second in the platform; this is used to calculate absolute times. This default value is only a recommendation, override with the right value for your system.  */
#define EWF_PLATFORM_TICKS_PER_SECOND          (1000)
#endif

#ifndef EWF_PLATFORM_BUSY_WAIT
/**
 * @brief The default platform busy wait macro.
 * @description
 * This default implementation is not time accurate and very wasteful (power hungry, bus hungry).
 * Override it with an implementation valid for your system, ideally sleeping the CPU for the requested number of ticks.
 *
 */
#define EWF_PLATFORM_BUSY_WAIT(count)       \
do {                                        \
    static volatile uint32_t i, j, x;       \
    for (i = 0, x = 0; i < count; i++)      \
        for (j = 0; j < 1024; j++)          \
            x += i + j;                     \
} while(0)
#endif

#if defined(__CORTEX_M) /* Generic Cortex-M CMSIS*/

#define EWF_PLATFORM_INTERRUPT_DISABLE() __disable_irq()
#define EWF_PLATFORM_INTERRUPT_ENABLE() __enable_irq()

#define EWF_PLATFORM_INTERRUPT_STATE_TYPE uint32_t

#define EWF_PLATFORM_INTERRUPT_STATE_TYPE_GET() __get_PRIMASK()
#define EWF_PLATFORM_INTERRUPT_STATE_TYPE_SET(state) __set_PRIMASK(state)

#elif defined(__IAR_SYSTEMS_ICC__) /* Generic IAR */

#define EWF_PLATFORM_INTERRUPT_DISABLE() __disable_interrupt()
#define EWF_PLATFORM_INTERRUPT_ENABLE() __enable_interrupt()

#define EWF_PLATFORM_INTERRUPT_STATE_TYPE __istate_t

#define EWF_PLATFORM_INTERRUPT_STATE_TYPE_GET() __get_interrupt_state()
#define EWF_PLATFORM_INTERRUPT_STATE_TYPE_SET(state) __set_interrupt_state(state)

#else

// Insert other bare metal implementations here
#error "Bare metal platform not implemented! (yet)"

#endif

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
static uint8_t ewf_platform_queue__buffer__##queue_name_symb[sizeof(item_type) * item_count];                                   \
static ewf_platform_queue ewf_platform_queue__##queue_name_symb = {0};                                                          \
ewf_platform_queue__##queue_name_symb.data = ewf_platform_queue__buffer__##queue_name_symb;                                     \
ewf_platform_queue__##queue_name_symb.item_size = sizeof(item_type);                                                            \
ewf_platform_queue__##queue_name_symb.queue_size = item_count;                                                                  \
ewf_platform_queue__##queue_name_symb.tail_index = 0;                                                                           \
ewf_platform_queue__##queue_name_symb.used_count = 0;                                                                          	\
queue_ptr = &(ewf_platform_queue__##queue_name_symb);                                                                          	\
} while(0)

#ifdef __cplusplus
}
#endif

#endif /* __ewf_platform_bare_metal__h__included__ */
