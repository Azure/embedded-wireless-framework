/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** ThreadX Component                                                     */
/**                                                                       */
/**   User Specific                                                       */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/**************************************************************************/
/*                                                                        */
/*  PORT SPECIFIC C INFORMATION                            RELEASE        */
/*                                                                        */
/*    tx_user.h                                           PORTABLE C      */
/*                                                           6.1.9        */
/*                                                                        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    William E. Lamie, Microsoft Corporation                             */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This file contains user defines for configuring ThreadX in specific */
/*    ways. This file will have an effect only if the application and     */
/*    ThreadX library are built with TX_INCLUDE_USER_DEFINE_FILE defined. */
/*    Note that all the defines in this file may also be made on the      */
/*    command line when building ThreadX library and application objects. */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020      William E. Lamie        Initial Version 6.0           */
/*  09-30-2020      Yuxin Zhou              Modified comment(s),          */
/*                                            resulting in version 6.1    */
/*  03-02-2021      Scott Larson            Modified comment(s),          */
/*                                            added option to remove      */
/*                                            FileX pointer,              */
/*                                            resulting in version 6.1.5  */
/*  06-02-2021      Scott Larson            Added options for multiple    */
/*                                            block pool search & delay,  */
/*                                            resulting in version 6.1.7  */
/*  10-15-2021      Yuxin Zhou              Modified comment(s), added    */
/*                                            user-configurable symbol    */
/*                                            TX_TIMER_TICKS_PER_SECOND   */
/*                                            resulting in version 6.1.9  */
/*                                                                        */
/**************************************************************************/

#ifndef TX_USER_H
#define TX_USER_H


/* Define various build options for the ThreadX port.  The application should either make changes
   here by commenting or un-commenting the conditional compilation defined OR supply the defines 
   though the compiler's equivalent of the -D option.  
   
   For maximum speed, the following should be defined:

        TX_MAX_PRIORITIES                       32
        TX_DISABLE_PREEMPTION_THRESHOLD
        TX_DISABLE_REDUNDANT_CLEARING
        TX_DISABLE_NOTIFY_CALLBACKS
        TX_NOT_INTERRUPTABLE
        TX_TIMER_PROCESS_IN_ISR
        TX_REACTIVATE_INLINE
        TX_DISABLE_STACK_FILLING
        TX_INLINE_THREAD_RESUME_SUSPEND
   
   For minimum size, the following should be defined:
   
        TX_MAX_PRIORITIES                       32
        TX_DISABLE_PREEMPTION_THRESHOLD
        TX_DISABLE_REDUNDANT_CLEARING
        TX_DISABLE_NOTIFY_CALLBACKS
        TX_NOT_INTERRUPTABLE
        TX_TIMER_PROCESS_IN_ISR
   
   Of course, many of these defines reduce functionality and/or change the behavior of the
   system in ways that may not be worth the trade-off. For example, the TX_TIMER_PROCESS_IN_ISR
   results in faster and smaller code, however, it increases the amount of processing in the ISR.
   In addition, some services that are available in timers are not available from ISRs and will
   therefore return an error if this option is used. This may or may not be desirable for a 
   given application.  */


/* Override various options with default values already assigned in tx_port.h. Please also refer
   to tx_port.h for descriptions on each of these options.  */

#define USE_TX_MAX_PRIORITIES						0
#if USE_TX_MAX_PRIORITIES
#define TX_MAX_PRIORITIES							32
#endif

#define USE_TX_MINIMUM_STACK						0
#if USE_TX_MINIMUM_STACK
#define TX_MINIMUM_STACK							64
#endif

#define USE_TX_TIMER_THREAD_STACK_SIZE				0
#if USE_TX_TIMER_THREAD_STACK_SIZE
#define TX_TIMER_THREAD_STACK_SIZE					128
#endif

#define USE_TX_TIMER_THREAD_PRIORITY				0
#if USE_TX_TIMER_THREAD_PRIORITY
#define TX_TIMER_THREAD_PRIORITY					1
#endif

#define USE_TX_THREAD_USER_EXTENSION				0
#if USE_TX_THREAD_USER_EXTENSION
#define TX_THREAD_USER_EXTENSION
#endif

/* Define the common timer tick reference for use by other middleware components. The default
   value is 10ms (i.e. 100 ticks, defined in tx_api.h), but may be replaced by a port-specific
   version in tx_port.h or here.
   Note: the actual hardware timer value may need to be changed (usually in tx_initialize_low_level).  */
#define USE_TX_TIMER_TICKS_PER_SECOND				0
#if USE_TX_TIMER_TICKS_PER_SECOND
#define TX_TIMER_TICKS_PER_SECOND		((ULONG) 100)
#endif

/* Determine if there is a FileX pointer in the thread control block.
   By default, the pointer is there for legacy/backwards compatibility.
   The pointer must also be there for applications using FileX.
   Define this to save space in the thread control block.  */
#define USE_TX_NO_FILEX_POINTER						0
#if USE_TX_NO_FILEX_POINTER
#define TX_NO_FILEX_POINTER
#endif

/* Determine if timer expirations (application timers, timeouts, and tx_thread_sleep calls 
   should be processed within the a system timer thread or directly in the timer ISR. 
   By default, the timer thread is used. When the following is defined, the timer expiration 
   processing is done directly from the timer ISR, thereby eliminating the timer thread control
   block, stack, and context switching to activate it.  */
#define USE_TX_TIMER_PROCESS_IN_ISR					0
#if USE_TX_TIMER_PROCESS_IN_ISR
#define TX_TIMER_PROCESS_IN_ISR
#endif
/* Determine if in-line timer reactivation should be used within the timer expiration processing.
   By default, this is disabled and a function call is used. When the following is defined,
   reactivating is performed in-line resulting in faster timer processing but slightly larger
   code size.  */

#define USE_TX_REACTIVATE_INLINE					0
#if USE_TX_REACTIVATE_INLINE
#define TX_REACTIVATE_INLINE
#endif

/* Determine is stack filling is enabled. By default, ThreadX stack filling is enabled,
   which places an 0xEF pattern in each byte of each thread's stack.  This is used by
   debuggers with ThreadX-awareness and by the ThreadX run-time stack checking feature.  */

#define USE_TX_DISABLE_STACK_FILLING				0
#if USE_TX_DISABLE_STACK_FILLING
#define TX_DISABLE_STACK_FILLING
#endif

/* Determine whether or not stack checking is enabled. By default, ThreadX stack checking is 
   disabled. When the following is defined, ThreadX thread stack checking is enabled.  If stack
   checking is enabled (TX_ENABLE_STACK_CHECKING is defined), the TX_DISABLE_STACK_FILLING
   define is negated, thereby forcing the stack fill which is necessary for the stack checking
   logic.  */
#define USE_TX_ENABLE_STACK_CHECKING				0
#if USE_TX_ENABLE_STACK_CHECKING
#define TX_ENABLE_STACK_CHECKING
#endif

/* Determine if preemption-threshold should be disabled. By default, preemption-threshold is 
   enabled. If the application does not use preemption-threshold, it may be disabled to reduce
   code size and improve performance.  */
#define USE_TX_DISABLE_PREEMPTION_THRESHOLD			0
#if USE_TX_DISABLE_PREEMPTION_THRESHOLD
#define TX_DISABLE_PREEMPTION_THRESHOLD
#endif

/* Determine if global ThreadX variables should be cleared. If the compiler startup code clears 
   the .bss section prior to ThreadX running, the define can be used to eliminate unnecessary
   clearing of ThreadX global variables.  */
#define USE_TX_DISABLE_REDUNDANT_CLEARING			0
#if USE_TX_DISABLE_REDUNDANT_CLEARING
#define TX_DISABLE_REDUNDANT_CLEARING
#endif

/* Determine if no timer processing is required. This option will help eliminate the timer 
   processing when not needed. The user will also have to comment out the call to 
   tx_timer_interrupt, which is typically made from assembly language in 
   tx_initialize_low_level. Note: if TX_NO_TIMER is used, the define TX_TIMER_PROCESS_IN_ISR
   must also be used and tx_timer_initialize must be removed from ThreadX library.  */

#define USE_TX_NO_TIMER								0
#if USE_TX_NO_TIMER
	#define TX_NO_TIMER
	#ifndef TX_TIMER_PROCESS_IN_ISR
		#define TX_TIMER_PROCESS_IN_ISR
	#endif
#endif

/* Determine if the notify callback option should be disabled. By default, notify callbacks are
   enabled. If the application does not use notify callbacks, they may be disabled to reduce
   code size and improve performance.  */
#define USE_TX_DISABLE_NOTIFY_CALLBACKS				1
#if USE_TX_DISABLE_NOTIFY_CALLBACKS
#define TX_DISABLE_NOTIFY_CALLBACKS
#endif


/* Determine if the tx_thread_resume and tx_thread_suspend services should have their internal 
   code in-line. This results in a larger image, but improves the performance of the thread 
   resume and suspend services.  */
#define USE_TX_INLINE_THREAD_RESUME_SUSPEND			0
#if USE_TX_INLINE_THREAD_RESUME_SUSPEND
#define TX_INLINE_THREAD_RESUME_SUSPEND
#endif

/* Determine if the internal ThreadX code is non-interruptable. This results in smaller code 
   size and less processing overhead, but increases the interrupt lockout time.  */
#define USE_TX_NOT_INTERRUPTABLE					0
#if USE_TX_NOT_INTERRUPTABLE
#define TX_NOT_INTERRUPTABLE
#endif

/* Determine if the trace event logging code should be enabled. This causes slight increases in 
   code size and overhead, but provides the ability to generate system trace information which 
   is available for viewing in TraceX.  */
#define USE_TX_ENABLE_EVENT_TRACE					0
#if USE_TX_ENABLE_EVENT_TRACE
#define TX_ENABLE_EVENT_TRACE
#endif

/* Determine if block pool performance gathering is required by the application. When the following is
   defined, ThreadX gathers various block pool performance information. */
#define USE_TX_BLOCK_POOL_ENABLE_PERFORMANCE_INFO	0
#if USE_TX_BLOCK_POOL_ENABLE_PERFORMANCE_INFO
#define TX_BLOCK_POOL_ENABLE_PERFORMANCE_INFO
#endif

/* Determine if byte pool performance gathering is required by the application. When the following is
   defined, ThreadX gathers various byte pool performance information. */
#define USE_TX_BYTE_POOL_ENABLE_PERFORMANCE_INFO	0
#if USE_TX_BYTE_POOL_ENABLE_PERFORMANCE_INFO
#define TX_BYTE_POOL_ENABLE_PERFORMANCE_INFO
#endif

/* Determine if event flags performance gathering is required by the application. When the following is
   defined, ThreadX gathers various event flags performance information. */
#define USE_TX_EVENT_FLAGS_ENABLE_PERFORMANCE_INFO	0
#if USE_TX_EVENT_FLAGS_ENABLE_PERFORMANCE_INFO
#define TX_EVENT_FLAGS_ENABLE_PERFORMANCE_INFO
#endif

/* Determine if mutex performance gathering is required by the application. When the following is
   defined, ThreadX gathers various mutex performance information. */
#define USE_TX_MUTEX_ENABLE_PERFORMANCE_INFO		0
#if USE_TX_MUTEX_ENABLE_PERFORMANCE_INFO
#define TX_MUTEX_ENABLE_PERFORMANCE_INFO
#endif

/* Determine if queue performance gathering is required by the application. When the following is
   defined, ThreadX gathers various queue performance information. */

#define USE_TX_QUEUE_ENABLE_PERFORMANCE_INFO		0
#if USE_TX_QUEUE_ENABLE_PERFORMANCE_INFO
#define TX_QUEUE_ENABLE_PERFORMANCE_INFO
#endif

/* Determine if semaphore performance gathering is required by the application. When the following is
   defined, ThreadX gathers various semaphore performance information. */

#define USE_TX_SEMAPHORE_ENABLE_PERFORMANCE_INFO	0
#if USE_TX_SEMAPHORE_ENABLE_PERFORMANCE_INFO
#define TX_SEMAPHORE_ENABLE_PERFORMANCE_INFO
#endif

/* Determine if thread performance gathering is required by the application. When the following is
   defined, ThreadX gathers various thread performance information. */

#define USE_TX_THREAD_ENABLE_PERFORMANCE_INFO		0
#if USE_TX_THREAD_ENABLE_PERFORMANCE_INFO
#define TX_THREAD_ENABLE_PERFORMANCE_INFO
#endif

/* Determine if timer performance gathering is required by the application. When the following is
   defined, ThreadX gathers various timer performance information. */

#define USE_TX_TIMER_ENABLE_PERFORMANCE_INFO		0
#if USE_TX_TIMER_ENABLE_PERFORMANCE_INFO
#define TX_TIMER_ENABLE_PERFORMANCE_INFO
#endif

/* Override options for byte pool searches of multiple blocks. */
#define USE_TX_BYTE_POOL_MULTIPLE_BLOCK_SEARCH		0
#if USE_TX_BYTE_POOL_MULTIPLE_BLOCK_SEARCH
#define TX_BYTE_POOL_MULTIPLE_BLOCK_SEARCH			20
#endif

/* Override options for byte pool search delay to avoid thrashing. */
#define USE_TX_BYTE_POOL_DELAY_VALUE				0
#if USE_TX_BYTE_POOL_DELAY_VALUE
#define TX_BYTE_POOL_DELAY_VALUE 					3
#endif

/* Define Low Power macros and flags */

/* Define Low Power usage */
#define TX_LOW_POWER								0

/* Define the Enter low power mode macro*/
#if TX_LOW_POWER
void Demo_LowPower_Enter(void);
#define TX_LOW_POWER_USER_ENTER						Demo_LowPower_Enter()
#endif

/* Define the Exist low power mode macro*/
#if TX_LOW_POWER
void Demo_LowPower_Exit(void);
#define TX_LOW_POWER_USER_EXIT						Demo_LowPower_Exit()
#endif

/* Define Low Power tickess usage */
#define USE_TX_LOW_POWER_TICKLESS					0
#if USE_TX_LOW_POWER_TICKLESS
#define TX_LOW_POWER_TICKLESS
#endif

/* Define the TX_LOW_POWER_TIMER_SETUP macro*/
#if TX_LOW_POWER && !USE_TX_LOW_POWER_TICKLESS
#define USE_TX_LOW_POWER_TIMER_SETUP				0
#endif
#if USE_TX_LOW_POWER_TIMER_SETUP
void Demo_LowPower_Timer_Setup(unsigned long tx_low_power_next_expiration);  /* can not use ULONG */
#define TX_LOW_POWER_TIMER_SETUP					Demo_LowPower_Timer_Setup
#endif

/* Define the TX_LOW_POWER_USER_TIMER_ADJUST macro*/
#if TX_LOW_POWER && !USE_TX_LOW_POWER_TICKLESS
#define USE_TX_LOW_POWER_USER_TIMER_ADJUST			0
#endif
#if USE_TX_LOW_POWER_USER_TIMER_ADJUST
unsigned long Demo_LowPower_User_Timer_Adjust(void);						/* can not use ULONG */
#define TX_LOW_POWER_USER_TIMER_ADJUST				Demo_LowPower_User_Timer_Adjust()
#endif

/* Define the TX_ENABLE_WAIT usage*/
#define TX_ENABLE_WAIT								0

#endif

