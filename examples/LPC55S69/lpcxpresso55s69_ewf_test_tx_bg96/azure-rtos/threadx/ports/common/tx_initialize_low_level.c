/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"

#include "tx_api.h"

/* the memory space after the heap is unused */
#if defined(__CC_ARM) || defined(__ARMCC_VERSION)

/* Keil MDK */
extern void *Image$$ARM_LIB_HEAP$$ZI$$Limit;
#define UNUSED_MEM_PTR  (&Image$$ARM_LIB_HEAP$$ZI$$Limit)

#elif defined(__MCUXPRESSO)

/* MCUXpresso IDE */
extern void *_pvHeapLimit;
#define UNUSED_MEM_PTR  (&_pvHeapLimit)

#elif defined(__GNUC__)

/* GCC */
extern void *__HeapLimit;
#define UNUSED_MEM_PTR  (&__HeapLimit)

#elif defined(__ICCARM__)

/* IAR */
extern void *HEAD$$Limit;
#define UNUSED_MEM_PTR  (&HEAD$$Limit)

#endif

extern VOID *_tx_initialize_unused_memory;

extern VOID _tx_timer_interrupt(VOID);

VOID _tx_initialize_low_level(VOID)
{
    DisableGlobalIRQ();

    _tx_initialize_unused_memory = (VOID *)UNUSED_MEM_PTR;

    /* enable CPU cycle counter */
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

    SysTick_Config(SystemCoreClock / TX_TIMER_TICKS_PER_SECOND);

    NVIC_SetPriority(MemoryManagement_IRQn, 0);
    NVIC_SetPriority(BusFault_IRQn, 0);
    NVIC_SetPriority(UsageFault_IRQn, 0);

    NVIC_SetPriority(SVCall_IRQn, 0x0ff);

    NVIC_SetPriority(DebugMonitor_IRQn, 0);
    NVIC_SetPriority(PendSV_IRQn, 0x0ff);
    NVIC_SetPriority(SysTick_IRQn, 0x40);
}

VOID SysTick_Handler(VOID)
{
    _tx_timer_interrupt();
}
