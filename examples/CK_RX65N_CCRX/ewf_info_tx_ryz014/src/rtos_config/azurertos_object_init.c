/***********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
 * SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2021 Renesas Electronics Corporation. All rights reserved.
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : azure_object_init.c
 * Version      : 1.0
 * Description  : define Objects initialization  
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "azurertos_object_init.h"
/* Start user code for user includes. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * ThreadX object control blocks definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Stacks definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Function Name: tx_application_define_user
 * Description  : This function initializes Azure RTOS objects.
 * Arguments    : None.
 * Return Value : None.
 * Note         : If this function is not called anywhere yet, please call it manually in application code
                  (for e.g. call it in tx_application_define())
 **********************************************************************************************************************/
void tx_application_define_user (void)
{
    /************** thread creation *************************/

    /************** queue creation **************************/

    /************** Semaphore creation **********************/

    /************** Mutex creation **************************/

    /************** Event flags creation ********************/

    /************** Application timer creation **************/
    /* Start user code for user initialization code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
} /* End of function tx_application_define_user()*/

/* Start user code for others user code. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
