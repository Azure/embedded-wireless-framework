/*******************************************************************************
  Azure RTOS ThreadX OSAL Header

  Company:
    Microchip Technology Inc.

  File Name:
    osal_threadx.h

  Summary:
    OSAL Azure RTOS ThreadX implementation interface file

  Description:
    Interface file to allow Azure RTOS ThreadX to be used with the OSAL

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

#ifndef _OSAL_THREADX_H
#define _OSAL_THREADX_H

#ifdef __cplusplus
extern "C" {
#endif

/*
------------------------------------------------------------------------------------------------------------------------
*                                                    INCLUDE FILES
------------------------------------------------------------------------------------------------------------------------
*/

#include "device.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tx_api.h"
/*
------------------------------------------------------------------------------------------------------------------------
*                                                     DATA TYPES
------------------------------------------------------------------------------------------------------------------------
*/

typedef uint32_t                        OSAL_CRITSECT_DATA_TYPE;
typedef TX_SEMAPHORE                    OSAL_SEM_HANDLE_TYPE;
typedef TX_MUTEX                        OSAL_MUTEX_HANDLE_TYPE;

extern TX_BYTE_POOL byte_pool_0;

#define OSAL_WAIT_FOREVER               0xFFFF
#define OSAL_SEM_DECLARE(semID)         TX_SEMAPHORE semID
#define OSAL_MUTEX_DECLARE(mutexID)     TX_MUTEX mutexID

#define OSAL_ASSERT(test, message)      test
// *****************************************************************************
/* OSAL Result type

  Summary:
    Enumerated type representing the general return value from OSAL functions.

  Description:
    This enum represents possible return types from OSAL functions.

  Remarks:
    These enum values are the possible return values from OSAL functions
    where a standard success/fail type response is required. The majority
    of OSAL functions will return this type with a few exceptions.
*/

typedef enum OSAL_SEM_TYPE
{
  OSAL_SEM_TYPE_BINARY,
  OSAL_SEM_TYPE_COUNTING
} OSAL_SEM_TYPE;

typedef enum OSAL_CRIT_TYPE
{
  OSAL_CRIT_TYPE_LOW,
  OSAL_CRIT_TYPE_HIGH
} OSAL_CRIT_TYPE;

typedef enum OSAL_RESULT
{
  OSAL_RESULT_NOT_IMPLEMENTED = -1,
  OSAL_RESULT_FALSE = 0,
  OSAL_RESULT_TRUE = 1
} OSAL_RESULT;

// *****************************************************************************
// *****************************************************************************
// Section: Section: Interface Routines Group Declarations
// *****************************************************************************
// *****************************************************************************
OSAL_RESULT OSAL_SEM_Create(OSAL_SEM_HANDLE_TYPE* semID, OSAL_SEM_TYPE type, uint8_t maxCount, uint8_t initialCount);
OSAL_RESULT OSAL_SEM_Delete(OSAL_SEM_HANDLE_TYPE* semID);
OSAL_RESULT OSAL_SEM_Pend(OSAL_SEM_HANDLE_TYPE* semID, uint16_t waitMS);
OSAL_RESULT OSAL_SEM_Post(OSAL_SEM_HANDLE_TYPE* semID);
OSAL_RESULT OSAL_SEM_PostISR(OSAL_SEM_HANDLE_TYPE* semID);
uint8_t OSAL_SEM_GetCount(OSAL_SEM_HANDLE_TYPE* semID);

OSAL_CRITSECT_DATA_TYPE OSAL_CRIT_Enter(OSAL_CRIT_TYPE severity);
void OSAL_CRIT_Leave(OSAL_CRIT_TYPE severity, OSAL_CRITSECT_DATA_TYPE status);

OSAL_RESULT OSAL_MUTEX_Create(OSAL_MUTEX_HANDLE_TYPE* mutexID);
OSAL_RESULT OSAL_MUTEX_Delete(OSAL_MUTEX_HANDLE_TYPE* mutexID);
OSAL_RESULT OSAL_MUTEX_Lock(OSAL_MUTEX_HANDLE_TYPE* mutexID, uint16_t waitMS);
OSAL_RESULT OSAL_MUTEX_Unlock(OSAL_MUTEX_HANDLE_TYPE* mutexID);

void* OSAL_Malloc(size_t size);
void OSAL_Free(void* pData);

OSAL_RESULT OSAL_Initialize();

// *****************************************************************************
/* Function: const char* OSAL_Name()

  Summary:
    Obtain the name of the underlying RTOS.

  Description:
    This function returns a const char* to the textual name of the RTOS.
    The name is a NULL terminated string.

  Precondition:
    None

  Parameters:
    None

  Returns:
    const char* -   Name of the underlying RTOS or NULL

  Example:
    <code>
    // get the RTOS name
    const char* sName;

    sName = OSAL_Name();
    sprintf(buff, "RTOS: %s", sName);
    </code>

  Remarks:

 */
__STATIC_INLINE __attribute__((always_inline)) const char* OSAL_Name (void)
{
    return "ThreadX";
}

#ifdef __cplusplus
}
#endif

#endif // _OSAL_THREADX_H
