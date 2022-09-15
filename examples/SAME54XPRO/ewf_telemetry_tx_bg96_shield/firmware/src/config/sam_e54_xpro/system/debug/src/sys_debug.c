/*******************************************************************************
  Debug System Service Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    sys_debug.c

  Summary:
    Debug System Service interface implementation.

  Description:
    The DEBUG system service provides a simple interface to manage the DEBUG
    module on Microchip microcontrollers. This file Implements the core
    interface routines for the DEBUG system service. While building the system
    service from source, ALWAYS include this file in the build.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "configuration.h"
#include "system/system.h"
#include "system/console/sys_console.h"
#include "sys_debug_local.h"
#include "system/debug/sys_debug.h"

static SYS_DEBUG_INSTANCE sysDebugInstance;

SYS_ERROR_LEVEL gblErrLvl;

SYS_MODULE_OBJ SYS_DEBUG_Initialize(
    const SYS_MODULE_INDEX index,
    const SYS_MODULE_INIT* const init
)
{
    SYS_DEBUG_INIT* initConfig = (SYS_DEBUG_INIT*)init;

    gblErrLvl = initConfig->errorLevel;

    sysDebugInstance.debugConsole = initConfig->consoleIndex;
    sysDebugInstance.status = SYS_STATUS_READY;

    return SYS_MODULE_OBJ_STATIC;
}


SYS_MODULE_INDEX SYS_DEBUG_ConsoleInstanceGet(void)
{
    return sysDebugInstance.debugConsole;
}

SYS_STATUS SYS_DEBUG_Status ( SYS_MODULE_OBJ object )
{
    return ( sysDebugInstance.status );
}

void SYS_DEBUG_ErrorLevelSet(SYS_ERROR_LEVEL level)
{
    gblErrLvl = level;
}

SYS_ERROR_LEVEL SYS_DEBUG_ErrorLevelGet(void)
{
    return gblErrLvl;
}

bool SYS_DEBUG_Redirect(const SYS_MODULE_INDEX index)
{
    if (index < SYS_CONSOLE_DEVICE_MAX_INSTANCES)
    {
        sysDebugInstance.debugConsole = index;
        return true;
    }
    else
    {
        return false;
    }
}