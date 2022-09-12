/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework WIN32 COM port host interface.
 ****************************************************************************/

#include "ewf_interface_win32_com.h"

#ifndef EWF_PLATFORM_HAS_THREADING
#error This host interface is only supported in platforms with threading
#endif

/******************************************************************************
 *
 * Hardware interface functions
 *
 ******************************************************************************/

ewf_result ewf_interface_win32_com_hardware_start(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_WIN32_COM);
    ewf_interface_win32_com* win32_com_interface_ptr = (ewf_interface_win32_com*)interface_ptr->implementation_ptr;

    DCB dcb;
    DWORD dwBytesTransferred;
    DWORD dwCommModemStatus = 0;
    LPSTR lpBuffer;
    DWORD dwNoOFBytestoWrite;
    BOOL Status;
    DWORD dwCommEvent = 0;
    COMMTIMEOUTS CommTimeouts = { 0 };

    BYTE Byte;
    DWORD dwWritten;
    DWORD dwRes;

    win32_com_interface_ptr->hComm = CreateFile(
        win32_com_interface_ptr->com_port_cstr, // Port name
        GENERIC_READ | GENERIC_WRITE,           // Read/Write
        0,                                      // No Sharing
        NULL,                                   // No Security
        OPEN_EXISTING,                          // Open existing port only
        FILE_FLAG_OVERLAPPED,                   // Overlapped I/O
        NULL);                                  // Null for Comm Devices
    if (win32_com_interface_ptr->hComm == INVALID_HANDLE_VALUE)
    {
        EWF_LOG_ERROR("Error opening the serial port.\n");
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    // Initialize the DCB structure.
    SecureZeroMemory(&dcb, sizeof(DCB));
    dcb.DCBlength = sizeof(DCB);
    if (!GetCommState(win32_com_interface_ptr->hComm, &dcb))
    {
        EWF_LOG_ERROR("GetCommState failed.\n");
        CloseHandle(win32_com_interface_ptr->hComm);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    // Set the COM port settings
    dcb.BaudRate = win32_com_interface_ptr->BaudRate;
    dcb.ByteSize = win32_com_interface_ptr->ByteSize;
    dcb.Parity = win32_com_interface_ptr->Parity; // NOPARITY // no parity
    dcb.StopBits = win32_com_interface_ptr->StopBits; // ONESTOPBIT // 1 stop bit
    if (!SetCommState(win32_com_interface_ptr->hComm, &dcb))
    {
        EWF_LOG_ERROR("SetCommState failed.\n");
        CloseHandle(win32_com_interface_ptr->hComm);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    if (!SetCommTimeouts(win32_com_interface_ptr->hComm, &CommTimeouts))
    {
        EWF_LOG_ERROR("SetCommTimeouts failed.\n");
        CloseHandle(win32_com_interface_ptr->hComm);
        return EWF_RESULT_INTERFACE_INITIALIZATION_FAILED;
    }

    // Create the overlapped event. Must be closed before exiting to avoid a handle leak.
    win32_com_interface_ptr->osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (win32_com_interface_ptr->osWrite.hEvent == NULL)
    {
        EWF_LOG_ERROR("Failed to create the overlapped write event.\n");
        return EWF_RESULT_INTERFACE_SEND_FAILED;
    }

    // Create the overlapped event. Must be closed before exiting to avoid a handle leak.
    win32_com_interface_ptr->osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (win32_com_interface_ptr->osReader.hEvent == NULL)
    {
        EWF_LOG_ERROR("Failed to create the overlapped read event.");
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_win32_com_hardware_stop(ewf_interface* interface_ptr)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_WIN32_COM);
    ewf_interface_win32_com* win32_com_interface_ptr = (ewf_interface_win32_com*)interface_ptr->implementation_ptr;

    if (!CloseHandle(win32_com_interface_ptr->osWrite.hEvent))
    {
        EWF_LOG_ERROR("Failed to close the write event handle.");
    }

    if (!CloseHandle(win32_com_interface_ptr->osReader.hEvent))
    {
        EWF_LOG_ERROR("Failed to close the read event handle.\n");
    }

    if (!CloseHandle(win32_com_interface_ptr->hComm))
    {
        EWF_LOG_ERROR("Failed to close the serial port.\n");
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_interface_win32_com_hardware_send(ewf_interface* interface_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_WIN32_COM);
    ewf_interface_win32_com* win32_com_interface_ptr = (ewf_interface_win32_com*)interface_ptr->implementation_ptr;

    DWORD dwWritten;
    DWORD dwRes;
    BOOL fRes;

    /* Expect a valid buffer */
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (buffer_length < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (!WriteFile(win32_com_interface_ptr->hComm, buffer_ptr, buffer_length, &dwWritten, &win32_com_interface_ptr->osWrite))
    {
        if (GetLastError() != ERROR_IO_PENDING)
        {
            EWF_LOG_ERROR("Write failed.\n");
            // WriteFile failed, but isn't delayed. Report error and abort.
            fRes = FALSE;
        }
        else
        {
            // Write is pending.
            dwRes = WaitForSingleObject(win32_com_interface_ptr->osWrite.hEvent, INFINITE);
            switch (dwRes)
            {
                // OVERLAPPED structure's event has been signaled.
            case WAIT_OBJECT_0:
                if (!GetOverlappedResult(win32_com_interface_ptr->hComm, &win32_com_interface_ptr->osWrite, &dwWritten, FALSE))
                {
                    fRes = FALSE;
                    EWF_LOG_ERROR("The overlapped write operation returned an error.");
                }
                else
                {
                    // Write operation completed successfully.
                    fRes = TRUE;
                }
                break;

            default:
                // An error has occurred in WaitForSingleObject.
                // This usually indicates a problem with the
                // OVERLAPPED structure's event handle.
                fRes = FALSE;
                EWF_LOG_ERROR("Error in WaitForSingleObject on write.");
                break;
            }
        }
    }
    else
    {
        // WriteFile completed immediately
        fRes = TRUE;
    }

    if (fRes)
    {
        return EWF_RESULT_OK;
    }
    else
    {
        return EWF_RESULT_INTERFACE_SEND_FAILED;
    }
}

ewf_result ewf_interface_win32_com_hardware_receive(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);
    EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, EWF_INTERFACE_TYPE_WIN32_COM);
    ewf_interface_win32_com* win32_com_interface_ptr = (ewf_interface_win32_com*)interface_ptr->implementation_ptr;

    /* Expect a valid buffer */
    if (!buffer_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (!buffer_length_ptr) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    if (*buffer_length_ptr < 1) return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;

    if (!wait)
    {
        COMSTAT Stat;

        if (!ClearCommError(win32_com_interface_ptr->hComm, NULL, &Stat))
        {
            EWF_LOG_ERROR("The function ClearCommError failed with error 0x%08X.", GetLastError());
            return EWF_RESULT_IRRECOVERABLE_ERROR;
        }

        if (Stat.cbInQue == 0)
        {
            return EWF_RESULT_NO_DATA_AVAILABLE;
        }
    }

    DWORD dwRes;
    DWORD dwRead = 0;
    DWORD dwLastError;

    // Issue read operation.
    if (ReadFile(
        win32_com_interface_ptr->hComm,
        buffer_ptr,
        *buffer_length_ptr,
        &dwRead,
        &win32_com_interface_ptr->osReader))
    {
        *buffer_length_ptr = dwRead;
        return EWF_RESULT_OK;
    }

    dwLastError = GetLastError();
    if (dwLastError != ERROR_IO_PENDING)
    {
        EWF_LOG_ERROR("The read operation failed with error 0x%08X.", dwLastError);
        return EWF_RESULT_RECEPTION_FAILED;
    }

    dwRes = WaitForSingleObject(win32_com_interface_ptr->osReader.hEvent, INFINITE);
    switch (dwRes)
    {
    case WAIT_OBJECT_0:
        if (!GetOverlappedResult(win32_com_interface_ptr->hComm, &win32_com_interface_ptr->osReader, &dwRead, FALSE))
        {
            dwLastError = GetLastError();
            EWF_LOG_ERROR("The overlapped read operation failed with error 0x%08X.", dwLastError);
            // Error in communications; report it.
        }
        else
        {
            *buffer_length_ptr = dwRead;
            break;
        }
        break;

    case WAIT_TIMEOUT:
        // Operation isn't complete yet. fWaitingOnRead flag isn't
        // changed since I'll loop back around, and I don't want
        // to issue another read until the first one finishes.
        //
        // This is a good time to do some background work.
        break;

    default:
        // Error in the WaitForSingleObject; abort.
        // This indicates a problem with the OVERLAPPED structure's event handle.
        break;
    }

    /* All ok! */
    return EWF_RESULT_OK;
}
