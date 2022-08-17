/*******************************************************************************
 System Tasks File

  File Name:
    tasks.c

  Summary:
    This file contains source code necessary to maintain system's polled tasks.

  Description:
    This file contains source code necessary to maintain system's polled tasks.
    It implements the "SYS_Tasks" function that calls the individual "Tasks"
    functions for all polled MPLAB Harmony modules in the system.

  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    polled in the system.  These handles are passed into the individual module
    "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "definitions.h"

/* ThreadX byte memory pool from which to allocate the thread stacks. */
#define TX_BYTE_POOL_SIZE   (8192 + 512)

TX_BYTE_POOL   byte_pool_0;

// *****************************************************************************
// *****************************************************************************
// Section: RTOS "Tasks" Routine
// *****************************************************************************
// *****************************************************************************
TX_THREAD      _APP_IDLE_Task_TCB;
uint8_t*       _APP_IDLE_Task_Stk_Ptr;

static void _APP_IDLE_Tasks( ULONG thread_input )
{
    while(1)
    {
        /* IDLE Task will be executed if there are not tasks in ready state */

    }
}

TX_THREAD      _EWF_TEST_Task_TCB;
uint8_t*       _EWF_TEST_Task_Stk_Ptr;

void ewf_test_tx_bg96_shield_example(void);
static void _EWF_TEST_Tasks( ULONG thread_input )
{
    ewf_test_tx_bg96_shield_example();
    while(1)
    {
        EWF_TEST_Tasks();
    }
}





void tx_application_define(void* first_unused_memory)
{
    /* Create a byte memory pool from which to allocate the thread stacks. */
    tx_byte_pool_create(&byte_pool_0, "byte pool 0", first_unused_memory, TX_BYTE_POOL_SIZE);

    /* Maintain system services */
    


    /* Maintain Device Drivers */
    

    /* Maintain Middleware & Other Libraries */
    

    /* Maintain the application's state machine. */
        /* Allocate the stack for _APP_IDLE_Tasks threads */
    tx_byte_allocate(&byte_pool_0,
        (VOID **) &_APP_IDLE_Task_Stk_Ptr,
        TX_MINIMUM_STACK,
        TX_NO_WAIT
    );

    /* create the _APP_IDLE_Tasks thread */
    tx_thread_create(&_APP_IDLE_Task_TCB,
        "_APP_IDLE_Tasks",
        _APP_IDLE_Tasks,
        1,
        _APP_IDLE_Task_Stk_Ptr,
        TX_MINIMUM_STACK,
        (TX_MAX_PRIORITIES - 1),
        (TX_MAX_PRIORITIES - 1),
        TX_NO_TIME_SLICE,
        TX_AUTO_START
    );

    /* Allocate the stack for _EWF_TEST threads */
    tx_byte_allocate(&byte_pool_0,
        (VOID **) &_EWF_TEST_Task_Stk_Ptr,
        4096,
        TX_NO_WAIT
    );

    /* create the _EWF_TEST thread */
    tx_thread_create(&_EWF_TEST_Task_TCB,
        "_EWF_TEST_Tasks",
        _EWF_TEST_Tasks,
        0,
        _EWF_TEST_Task_Stk_Ptr,
        4096,
        1,
        1,
        TX_NO_TIME_SLICE,
        TX_AUTO_START
    );



}

// *****************************************************************************
// *****************************************************************************
// Section: System "Tasks" Routine
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SYS_Tasks ( void )

  Remarks:
    See prototype in system/common/sys_module.h.
*/
void SYS_Tasks ( void )
{
        /*Enter the ThreadX kernel.*/
    tx_kernel_enter();

}

/*******************************************************************************
 End of File
 */

