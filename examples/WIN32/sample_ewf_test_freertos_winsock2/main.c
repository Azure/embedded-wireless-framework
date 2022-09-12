
#include "ewf_adapter_winsock2.h" // Include first to force correct inclussion order for winsock2.h

/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Standard demo includes. */
#include "StaticAllocation.h"

/* Embedded Wireless Framework */
#include "ewf_platform_freertos.h"
#include "ewf_allocator_memory_pool.h"

#include "ewf_lib.h"

#include "ewf_example.config.h"

/*-----------------------------------------------------------*/

/*
 * Prototypes for the standard FreeRTOS stack overflow hook (callback)
 * function.  http://www.freertos.org/Stacks-and-stack-overflow-checking.html
 */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );

/*
 * This demo has configSUPPORT_STATIC_ALLOCATION set to 1 so the following
 * application callback function must be provided to supply the RAM that will
 * get used for the Idle task data structures and stack.
 */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/*
* This demo has configSUPPORT_STATIC_ALLOCATION set to 1 and configUSE_TIMERS
* set to 1 so the following application callback function must be provided to
* supply the RAM that will get used for the Timer task data structures and
* stack.
*/
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize );

/* This is the main task. */
static void prvMainTask( void *pvParameters );

/*-----------------------------------------------------------*/

int main( void )
{
	#define MAIN_STACK_SIZE (1024)

	/* Allocate the data structure that will hold the task's TCB.  NOTE:  This is
	declared static so it still exists after this function has returned. */
	static StaticTask_t xMainTask;

	/* Allocate the stack that will be used by the task.  NOTE:  This is declared
	static so it still exists after this function has returned. */
	static StackType_t ucTaskStack[MAIN_STACK_SIZE * sizeof(StackType_t)];

	/* Create the task, which will use the RAM allocated by the linker to the
	variables declared in this function. */
	xTaskCreateStatic(prvMainTask, "Main", MAIN_STACK_SIZE, NULL, EWF_PLATFORM_THREAD_PRIORITY_HIGH, ucTaskStack, &xMainTask);

	/* Start the scheduler so the demo tasks start to execute. */
	vTaskStartScheduler();

	/* vTaskStartScheduler() would only return if RAM required by the Idle and
	Timer tasks could not be allocated.  As this demo uses statically allocated
	RAM only, there are no allocations that could fail, and
	vTaskStartScheduler() cannot return - so there is no need to put the normal
	infinite loop after the call to vTaskStartScheduler(). */

	return 0;
}
/*-----------------------------------------------------------*/

static void prvMainTask( void *pvParameters )
{
    /* Just to remove compiler warning. */
    ( void ) pvParameters;

    ewf_result result;

    ewf_allocator* data_allocator_ptr = NULL;
    ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_MEMORY_POOL_STATIC_DECLARE(data_allocator_ptr, data_allocator,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_COUNT,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_SIZE);
    EWF_ADAPTER_WINSOCK2_STATIC_DECLARE(adapter_ptr, winsock2_adapter, data_allocator_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

    /* Run the adapter tests.  */
    if (ewf_result_failed(result = ewf_adapter_winsock2_test(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to run the adapter test, ewf_result %d.\n", result);
        exit(result);
    }

    EWF_LOG("\nDone!\n");

    for( ;; )
    {
        /* Place this task in the blocked state until it is time to run again. */
        vTaskDelay(pdMS_TO_TICKS(1000UL));

        /* This is the only task that uses stdout so its ok to call printf() directly. */
        printf( "tick count %d\r\n", xTaskGetTickCount());
    }
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected.  This function is
	provided as an example only as stack overflow checking does not function
	when running the FreeRTOS Windows port. */
	vAssertCalled( __LINE__, __FILE__ );
}
/*-----------------------------------------------------------*/

void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
volatile uint32_t ulSetToNonZeroInDebuggerToContinue = 0;

	/* Called if an assertion passed to configASSERT() fails.  See
	http://www.freertos.org/a00110.html#configASSERT for more information. */

	/* Parameters are not used. */
	( void ) ulLine;
	( void ) pcFileName;

	printf( "ASSERT! Line %d, file %s\r\n", ulLine, pcFileName );

 	taskENTER_CRITICAL();
	{
		/* You can step out of this function to debug the assertion by using
		the debugger to set ulSetToNonZeroInDebuggerToContinue to a non-zero
		value. */
		while( ulSetToNonZeroInDebuggerToContinue == 0 )
		{
			__asm{ NOP };
			__asm{ NOP };
		}
	}
	taskEXIT_CRITICAL();
}
/*-----------------------------------------------------------*/

/* configUSE_STATIC_ALLOCATION is set to 1, so the application must provide an
implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
used by the Idle task. */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
/* If the buffers to be provided to the Idle task are declared inside this
function then they must be declared static - otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

	/* Pass out a pointer to the StaticTask_t structure in which the Idle task's
	state will be stored. */
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

	/* Pass out the array that will be used as the Idle task's stack. */
	*ppxIdleTaskStackBuffer = uxIdleTaskStack;

	/* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
	Note that, as the array is necessarily of type StackType_t,
	configMINIMAL_STACK_SIZE is specified in words, not bytes. */
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}
/*-----------------------------------------------------------*/

/* configUSE_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize )
{
/* If the buffers to be provided to the Timer task are declared inside this
function then they must be declared static - otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xTimerTaskTCB;
static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

	/* Pass out a pointer to the StaticTask_t structure in which the Timer
	task's state will be stored. */
	*ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

	/* Pass out the array that will be used as the Timer task's stack. */
	*ppxTimerTaskStackBuffer = uxTimerTaskStack;

	/* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
	Note that, as the array is necessarily of type StackType_t,
	configMINIMAL_STACK_SIZE is specified in words, not bytes. */
	*pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}
