/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework WinSock2 adapter driver
 ****************************************************************************/

#include "ewf_adapter_winsock2.h" // Include first to force correct inclussion order for winsock2.h

#pragma comment (lib, "Ws2_32.lib")
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "fwpuclnt.lib") // Winsock secure socket extensions
#pragma comment(lib, "ntdsapi.lib") // DsMakeSpn function

#include <stdio.h>
#include <stdlib.h>

#include "ewf_lib.h"

ewf_adapter_api_control ewf_adapter_winsock2_api_control =
{
    ewf_adapter_winsock2_start,
    ewf_adapter_winsock2_stop,
};

ewf_result ewf_adapter_winsock2_start(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*)adapter_ptr->implementation_ptr;

    int iResult;

    /* Initialize Winsock */
    iResult = WSAStartup(MAKEWORD(2, 2), &(implementation_ptr->wsaData));
    if (iResult != 0)
    {
        EWF_LOG_ERROR("WSAStartup failed with error: %d\n", iResult);
        return EWF_RESULT_ADAPTER_INITIALIZATION_FAILED;
    }

    PIP_ADAPTER_INFO pAdapterInfo;
    PIP_ADAPTER_INFO pAdapter = NULL;
    DWORD dwRetVal = 0;
    bool valid_adapter = false;

    ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
    pAdapterInfo = (IP_ADAPTER_INFO*)HeapAlloc(GetProcessHeap(), 0, sizeof(IP_ADAPTER_INFO));
    if (pAdapterInfo == NULL)
    {
        EWF_LOG("Error allocating memory needed to call GetAdaptersinfo\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }

    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
    {
        HeapFree(GetProcessHeap(), 0, pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO*)HeapAlloc(GetProcessHeap(), 0, ulOutBufLen);
        if (pAdapterInfo == NULL)
        {
            EWF_LOG("Error allocating memory needed to call GetAdaptersinfo\n");
            return EWF_RESULT_NOT_SUPPORTED;
        }
    }

    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) != NO_ERROR)
    {
        EWF_LOG("GetAdaptersInfo failed with error: %d\n", dwRetVal);
    }
    else
    {
        for (pAdapter = pAdapterInfo; pAdapter; pAdapter = pAdapter->Next)
        {
            int a = 0, b = 0, c = 0, d = 0;
            int items = sscanf(pAdapter->GatewayList.IpAddress.String, "%d.%d.%d.%d", &a, &b, &c, &d);
            if (items != 4 || (a == 0 && b == 0 && c == 0 && d == 0))
            {
                /* Invalid gateway, ignore this adapter */
            }
            else
            {
                /* Valid gateway address */
                implementation_ptr->ipv4_gateway.S_un.S_un_b.s_b1 = d;
                implementation_ptr->ipv4_gateway.S_un.S_un_b.s_b2 = c;
                implementation_ptr->ipv4_gateway.S_un.S_un_b.s_b3 = b;
                implementation_ptr->ipv4_gateway.S_un.S_un_b.s_b4 = a;

                /* Parse and store the adapter IP address */
                items = sscanf(pAdapter->IpAddressList.IpAddress.String, "%d.%d.%d.%d", &a, &b, &c, &d);
                if (items != 4) continue;
                implementation_ptr->ipv4_address.S_un.S_un_b.s_b1 = d;
                implementation_ptr->ipv4_address.S_un.S_un_b.s_b2 = c;
                implementation_ptr->ipv4_address.S_un.S_un_b.s_b3 = b;
                implementation_ptr->ipv4_address.S_un.S_un_b.s_b4 = a;

                /* Parse and store the adapter IP mask */
                items = sscanf(pAdapter->IpAddressList.IpMask.String, "%d.%d.%d.%d", &a, &b, &c, &d);
                if (items != 4) continue;
                implementation_ptr->ipv4_netmask.S_un.S_un_b.s_b1 = d;
                implementation_ptr->ipv4_netmask.S_un.S_un_b.s_b2 = c;
                implementation_ptr->ipv4_netmask.S_un.S_un_b.s_b3 = b;
                implementation_ptr->ipv4_netmask.S_un.S_un_b.s_b4 = a;

                /* Add a default DNS */ /* TODO */
                implementation_ptr->ipv4_dns.S_un.S_un_b.s_b1 = 50; // 8;
                implementation_ptr->ipv4_dns.S_un.S_un_b.s_b2 = 10; // 8;
                implementation_ptr->ipv4_dns.S_un.S_un_b.s_b3 = 50; // 8;
                implementation_ptr->ipv4_dns.S_un.S_un_b.s_b4 = 10; // 8;

                /* We found our adapter */
                valid_adapter = true;
                break;
            }
        }
    }

    if (pAdapterInfo)
    {
        HeapFree(GetProcessHeap(), 0, pAdapterInfo);
    }

    if (!valid_adapter)
    {
        EWF_LOG("No valid adapter found\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_stop(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    WSACleanup();

    return EWF_RESULT_OK;
}

ewf_adapter_api_info ewf_adapter_winsock2_api_info =
{
    ewf_adapter_winsock2_info,
    ewf_adapter_winsock2_get_ipv4_address,
    ewf_adapter_winsock2_get_ipv4_netmask,
    ewf_adapter_winsock2_get_ipv4_gateway,
    ewf_adapter_winsock2_get_ipv4_dns,
    NULL,
    NULL,
    NULL,
};

ewf_result ewf_adapter_winsock2_info(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*)adapter_ptr->implementation_ptr;

    // It is possible for an adapter to have multiple
    // IPv4 addresses, gateways, and secondary WINS servers
    // assigned to the adapter.
    //
    // Note that this sample code only prints out the
    // first entry for the IP address/mask, and gateway, and
    // the primary and secondary WINS server for each adapter.

    PIP_ADAPTER_INFO pAdapterInfo;
    PIP_ADAPTER_INFO pAdapter = NULL;
    DWORD dwRetVal = 0;
    UINT i;

    /* variables used to print DHCP time info */
    struct tm newtime;
    char buffer[32];
    errno_t error;

    ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
    pAdapterInfo = (IP_ADAPTER_INFO*)HeapAlloc(GetProcessHeap(), 0, sizeof(IP_ADAPTER_INFO));
    if (pAdapterInfo == NULL)
    {
        EWF_LOG("Error allocating memory needed to call GetAdaptersinfo\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }

    // Make an initial call to GetAdaptersInfo to get
    // the necessary size into the ulOutBufLen variable
    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
    {
        HeapFree(GetProcessHeap(), 0, pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO*)HeapAlloc(GetProcessHeap(), 0, ulOutBufLen);
        if (pAdapterInfo == NULL)
        {
            EWF_LOG("Error allocating memory needed to call GetAdaptersinfo\n");
            return EWF_RESULT_NOT_SUPPORTED;
        }
    }

    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR)
    {
        pAdapter = pAdapterInfo;
        while (pAdapter)
        {
            EWF_LOG("\tComboIndex: \t%d\n", pAdapter->ComboIndex);
            EWF_LOG("\tAdapter Name: \t%s\n", pAdapter->AdapterName);
            EWF_LOG("\tAdapter Desc: \t%s\n", pAdapter->Description);
            EWF_LOG("\tAdapter Addr: \t");
            for (i = 0; i < pAdapter->AddressLength; i++)
            {
                if (i == (pAdapter->AddressLength - 1))
                    EWF_LOG("%.2X\n", (int)pAdapter->Address[i]);
                else
                    EWF_LOG("%.2X-", (int)pAdapter->Address[i]);
            }
            EWF_LOG("\tIndex: \t%d\n", pAdapter->Index);
            EWF_LOG("\tType: \t");
            switch (pAdapter->Type) {
            case MIB_IF_TYPE_OTHER:
                EWF_LOG("Other\n");
                break;
            case MIB_IF_TYPE_ETHERNET:
                EWF_LOG("Ethernet\n");
                break;
            case MIB_IF_TYPE_TOKENRING:
                EWF_LOG("Token Ring\n");
                break;
            case MIB_IF_TYPE_FDDI:
                EWF_LOG("FDDI\n");
                break;
            case MIB_IF_TYPE_PPP:
                EWF_LOG("PPP\n");
                break;
            case MIB_IF_TYPE_LOOPBACK:
                EWF_LOG("Lookback\n");
                break;
            case MIB_IF_TYPE_SLIP:
                EWF_LOG("Slip\n");
                break;
            default:
                EWF_LOG("Unknown type %ld\n", pAdapter->Type);
                break;
            }

            EWF_LOG("\tIP Address: \t%s\n", pAdapter->IpAddressList.IpAddress.String);
            EWF_LOG("\tIP Mask: \t%s\n", pAdapter->IpAddressList.IpMask.String);
            EWF_LOG("\tGateway: \t%s\n", pAdapter->GatewayList.IpAddress.String);
            EWF_LOG("\t***\n");

            if (pAdapter->DhcpEnabled)
            {
                EWF_LOG("\tDHCP Enabled: Yes\n");
                EWF_LOG("\t  DHCP Server: \t%s\n",
                pAdapter->DhcpServer.IpAddress.String);

                EWF_LOG("\t  Lease Obtained: ");
                /* Display local time */
                error = _localtime32_s(&newtime, (__time32_t*)&pAdapter->LeaseObtained);
                if (error)
                {
                    EWF_LOG("Invalid Argument to _localtime32_s\n");
                }
                else
                {
                    // Convert to an ASCII representation
                    error = asctime_s(buffer, 32, &newtime);
                    if (error)
                        EWF_LOG("Invalid Argument to asctime_s\n");
                    else
                        /* asctime_s returns the string terminated by \n\0 */
                        EWF_LOG("%s", buffer);
                }

                EWF_LOG("\t  Lease Expires:  ");
                error = _localtime32_s(&newtime, (__time32_t*)&pAdapter->LeaseExpires);
                if (error)
                {
                    EWF_LOG("Invalid Argument to _localtime32_s\n");
                }
                else
                {
                    // Convert to an ASCII representation
                    error = asctime_s(buffer, 32, &newtime);
                    if (error)
                        EWF_LOG("Invalid Argument to asctime_s\n");
                    else
                        /* asctime_s returns the string terminated by \n\0 */
                        EWF_LOG("%s", buffer);
                }
            }
            else
                EWF_LOG("\tDHCP Enabled: No\n");

            if (pAdapter->HaveWins) {
                EWF_LOG("\tHave Wins: Yes\n");
                EWF_LOG("\t  Primary Wins Server:    %s\n",
                    pAdapter->PrimaryWinsServer.IpAddress.String);
                EWF_LOG("\t  Secondary Wins Server:  %s\n",
                    pAdapter->SecondaryWinsServer.IpAddress.String);
            }
            else
            {
                EWF_LOG("\tHave Wins: No\n");
            }
            pAdapter = pAdapter->Next;
            EWF_LOG("\n");
        }
    }
    else
    {
        EWF_LOG("GetAdaptersInfo failed with error: %d\n", dwRetVal);
    }
    if (pAdapterInfo)
        HeapFree(GetProcessHeap(), 0, pAdapterInfo);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_get_ipv4_address(ewf_adapter* adapter_ptr, uint32_t * address_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*)adapter_ptr->implementation_ptr;

    if (!address_ptr)
    {
        EWF_LOG_ERROR("The address_ptr parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    *address_ptr = implementation_ptr->ipv4_address.S_un.S_addr;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_get_ipv4_netmask(ewf_adapter* adapter_ptr, uint32_t * netmask_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*)adapter_ptr->implementation_ptr;

    if (!netmask_ptr)
    {
        EWF_LOG_ERROR("The netmask parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    *netmask_ptr = implementation_ptr->ipv4_netmask.S_un.S_addr;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_get_ipv4_gateway(ewf_adapter* adapter_ptr, uint32_t * gateway_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*)adapter_ptr->implementation_ptr;

    if (!gateway_ptr)
    {
        EWF_LOG_ERROR("The gateway parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    *gateway_ptr = implementation_ptr->ipv4_gateway.S_un.S_addr;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_get_ipv4_dns(ewf_adapter* adapter_ptr, uint32_t * dns_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*)adapter_ptr->implementation_ptr;

    if (!dns_ptr)
    {
        EWF_LOG_ERROR("The dns parameter cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    *dns_ptr = implementation_ptr->ipv4_dns.S_un.S_addr;

    return EWF_RESULT_OK;
}

#if EWF_ADAPTER_WINSOCK2_TCP_ENABLED

ewf_adapter_api_tcp ewf_adapter_winsock2_api_tcp =
{
    ewf_adapter_winsock2_tcp_open,
    ewf_adapter_winsock2_tcp_close,

    ewf_adapter_winsock2_tcp_control,

    ewf_adapter_winsock2_tcp_set_tls_configuration,

    ewf_adapter_winsock2_tcp_bind,
    ewf_adapter_winsock2_tcp_listen,
    ewf_adapter_winsock2_tcp_accept,
    ewf_adapter_winsock2_tcp_connect,
    ewf_adapter_winsock2_tcp_shutdown,
    ewf_adapter_winsock2_tcp_send,
    ewf_adapter_winsock2_tcp_receive,
};

ewf_result ewf_adapter_winsock2_tcp_open(ewf_adapter* adapter_ptr, ewf_socket_tcp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*) adapter_ptr->implementation_ptr;

    if (socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][TCP][OPEN/CALL][ADAPTER 0x%08p]\n", adapter_ptr);

    socket_ptr->adapter_ptr = adapter_ptr;

    socket_ptr->data_ptr = HeapAlloc(GetProcessHeap(), 0, sizeof(ewf_adapter_winsock2_socket));

    if (socket_ptr->data_ptr == NULL)
    {
        EWF_LOG_ERROR("Failed to allocate a new socket in the heap.\n");
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    ws2_socket_ptr->s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("socket failed with error: %ld\n", WSAGetLastError());
        if (socket_ptr->data_ptr == NULL)
        {
            HeapFree(GetProcessHeap(), 0, socket_ptr->data_ptr);
        }
        return EWF_RESULT_INVALID_SOCKET;
    }

    /* Make socket non-blocking */
    u_long mode = 1;
    ioctlsocket(ws2_socket_ptr->s, FIONBIO, &mode);

    EWF_LOG("[WINSOCK2][TCP][OPEN/RETURN][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_close(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    EWF_LOG("[WINSOCK2][TCP][CLOSE/CALL][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    if (socket_ptr->data_ptr)
    {
        ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

        if (ws2_socket_ptr->s != INVALID_SOCKET)
        {
            int iResult;

            iResult = closesocket(ws2_socket_ptr->s);
            if (iResult == SOCKET_ERROR)
            {
                EWF_LOG_ERROR("closesocket failed with error: %d\n", WSAGetLastError());
            }
        }

        HeapFree(GetProcessHeap(), 0, socket_ptr->data_ptr);
    }

    EWF_LOG("[WINSOCK2][TCP][CLOSE/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*)adapter_ptr->implementation_ptr;
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][TCP][BIND/CALL][SOCKET 0x%08X][PORT %u]\n", ws2_socket_ptr->s, port);

    struct sockaddr_in bind_addr;
    bind_addr.sin_family = AF_INET;
    bind_addr.sin_port = htons(port);
    bind_addr.sin_addr.s_addr = htonl(implementation_ptr->ipv4_address.S_un.S_addr); //htonl(INADDR_ANY); //inet_addr("127.0.0.1");

    int iResult = bind(ws2_socket_ptr->s, (SOCKADDR*)&bind_addr, sizeof(bind_addr));
    if (iResult == SOCKET_ERROR)
    {
        EWF_LOG_ERROR("bind failed with error: %d\n", WSAGetLastError());
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    EWF_LOG("[WINSOCK2][TCP][BIND/RETURN][SOCKET 0x%08X][PORT %u]\n", ws2_socket_ptr->s, port);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_listen(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][TCP][LISTEN/CALL][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    int iResult = listen(ws2_socket_ptr->s, SOMAXCONN);
    if (iResult == SOCKET_ERROR)
    {
        EWF_LOG_ERROR("listen failed with error: %d\n", WSAGetLastError());
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    EWF_LOG("[WINSOCK2][TCP][LISTEN/RETURN][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (socket_new_ptr == NULL)
    {
        EWF_LOG_ERROR("The new socket pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][TCP][ACCEPT/CALL][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    socket_new_ptr->adapter_ptr = adapter_ptr;

    socket_new_ptr->data_ptr = HeapAlloc(GetProcessHeap(), 0, sizeof(ewf_adapter_winsock2_socket));
    if (socket_new_ptr->data_ptr == NULL)
    {
        EWF_LOG_ERROR("Failed to allocate a new socket in the heap.\n");
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    ewf_adapter_winsock2_socket* ws2_new_socket_ptr = (ewf_adapter_winsock2_socket*)socket_new_ptr->data_ptr;

    struct sockaddr_in addr;
    int addrlen = sizeof(addr);

    ws2_new_socket_ptr->s = accept(ws2_socket_ptr->s, (SOCKADDR*)&addr, &addrlen);
    if (ws2_new_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("accept failed with error: %d\n", WSAGetLastError());
        return EWF_RESULT_INVALID_SOCKET;
    }

    char addr_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr.sin_addr), addr_str, INET_ADDRSTRLEN);
    EWF_LOG("[WINSOCK2][TCP][ACCEPT/RETURN][SOCKET 0x%08X][NEW SOCKET 0x%08X][ORIGIN %s]\n", ws2_socket_ptr->s, ws2_new_socket_ptr->s, addr_str);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_connect(ewf_socket_tcp* socket_ptr, const char* server_str, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!server_str)
    {
        EWF_LOG_ERROR("The server string cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][TCP][CONNECT/CALL][SOCKET 0x%08X][SERVER %s][PORT %u]\n", ws2_socket_ptr->s, server_str, port);

    char port_str[7];
    const char* port_cstr = ewfl_unsigned_to_str(port, port_str, sizeof(port_str));

    ewf_result result = EWF_RESULT_OK;
    int iResult;

    struct addrinfo server_addrinfo;
    ZeroMemory(&server_addrinfo, sizeof(server_addrinfo));
    server_addrinfo.ai_family = AF_INET;
    server_addrinfo.ai_socktype = SOCK_STREAM;
    server_addrinfo.ai_protocol = IPPROTO_TCP;

    struct addrinfo* addrinfo_result = NULL;
    struct addrinfo* addrinfo_ptr = NULL;

    /* Resolve the server address and port */
    iResult = getaddrinfo(server_str, port_cstr, &server_addrinfo, &addrinfo_result);
    if (iResult != 0)
    {
        EWF_LOG_ERROR("getaddrinfo failed with error: %d\n", iResult);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    if (addrinfo_result->ai_next)
    {
        EWF_LOG_ERROR("[WARNING] Ambiguous address resolved, using the first one.\n");
    }

    /* Set the result to success before the next block */
    result = EWF_RESULT_OK;

    /* Attmept to connect to the server. */
    iResult = connect(ws2_socket_ptr->s, addrinfo_result->ai_addr, (int)addrinfo_result->ai_addrlen);
    if (iResult == SOCKET_ERROR)
    {
        DWORD WSALastError = WSAGetLastError();
        if (WSALastError != WSAEWOULDBLOCK)
        {
            EWF_LOG("connect failed with error: %d\n", WSALastError);
            result = EWF_RESULT_CONNECTION_FAILED;
        }
        else
        {
            for(;;)
            {
                fd_set write_fds, except_fds;

                FD_ZERO(&write_fds);
                FD_SET(ws2_socket_ptr->s, &write_fds);

                FD_ZERO(&except_fds);
                FD_SET(ws2_socket_ptr->s, &except_fds);

                /* Wait on select. */
                struct timeval tv;
                tv.tv_sec = 0;
                tv.tv_usec = 0;

                iResult = select(ws2_socket_ptr->s + 1, NULL, &write_fds, &except_fds, &tv);
                if (iResult == SOCKET_ERROR)
                {
                    EWF_LOG_ERROR("select failed, return %d, error %d\n", iResult, WSAGetLastError());
                    result = EWF_RESULT_CONNECTION_FAILED;
                    break;
                }

                if (FD_ISSET(ws2_socket_ptr->s, &write_fds))
                {
                    EWF_LOG("[WINSOCK2][TCP][CONNECTED!]\n");
                    result = EWF_RESULT_OK;
                    break;
                }

                if (FD_ISSET(ws2_socket_ptr->s, &except_fds))
                {
                    EWF_LOG_ERROR("The socket connection failed.\n");
                    result = EWF_RESULT_CONNECTION_FAILED;
                    break;
                }

                /* Not ready yet, just sleep and try again. */
                ewf_platform_sleep(1);
            }
        }
    }

    freeaddrinfo(addrinfo_result);

    if (result != EWF_RESULT_OK)
    {
        EWF_LOG_ERROR("Unable to connect to server!\n");
        return result;
    }

    EWF_LOG("[WINSOCK2][TCP][CONNECT/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_shutdown(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][TCP][SHUTDOWN/CALL][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    int iResult = shutdown(ws2_socket_ptr->s, SD_BOTH);
    if (iResult == SOCKET_ERROR)
    {
        EWF_LOG_ERROR("shutdown failed with error: %d\n", WSAGetLastError());
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    EWF_LOG("[WINSOCK2][TCP][SHUTDOWN/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    int iResult;

#ifdef EWF_DEBUG
    uint32_t step = 64;
    for (uint32_t i = 0; i < buffer_length; i += step)
    {
        const char* str = ewfl_escape_str_to_str_buffer(buffer_ptr + i, step);
        EWF_LOG("[WINSOCK2][TCP][SEND/CALL][BUFFER 0x%08p][%04d][%s]\n", buffer_ptr, i, str);
    }
#endif

    EWF_LOG("[WINSOCK2][TCP][SEND/CALL][SOCKET 0x%08X][BUFFER 0x%08p][LENGTH %u]\n", ws2_socket_ptr->s, buffer_ptr, buffer_length);

    iResult = send(ws2_socket_ptr->s, buffer_ptr, (int)buffer_length, 0);
    if (iResult == SOCKET_ERROR)
    {
        EWF_LOG_ERROR("send failed with error: %d\n", WSAGetLastError());
        return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
    }

    EWF_LOG("[WINSOCK2][TCP][SEND/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][TCP][RECEIVE/CALL][SOCKET 0x%08X][BUFFER 0x%08p][LENGTH %u]\n", ws2_socket_ptr->s, buffer_ptr, *buffer_length_ptr);

    for(;;)
    {
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        struct fd_set fds;
        FD_ZERO(&fds);
        FD_SET(ws2_socket_ptr->s, &fds);

        int iResult = select(ws2_socket_ptr->s + 1, &fds, NULL, NULL, &timeout);
        
        if (iResult == SOCKET_ERROR)
        {
            EWF_LOG_ERROR("select failed with error: %d\n", WSAGetLastError());
            return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
        }

        if (iResult == 0) /* Timeout */
        {
            if (wait)
            {
                /* Sleep and continue */
                ewf_platform_sleep(1);
                continue;
            }
            else
            {
                *buffer_length_ptr = 0;
                EWF_LOG("[WINSOCK2][TCP][RECEIVE/CALL][NO DATA]\n");
                return EWF_RESULT_NO_DATA_AVAILABLE;
            }
        }

        if (FD_ISSET(ws2_socket_ptr->s, &fds))
        {
            /* Data is available! */
            break;
        }
        else
        {
            EWF_LOG_ERROR("select returned unexpectedly.\n");
            return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
        }
    }

    int iResult = recv(ws2_socket_ptr->s, buffer_ptr, *buffer_length_ptr, 0);
    if (iResult == 0)
    {
        EWF_LOG_ERROR("Connection closed");
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }
    else if (iResult == SOCKET_ERROR)
    {
        EWF_LOG_ERROR("recv failed with error %u\n", WSAGetLastError());
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    *buffer_length_ptr = iResult;

    EWF_LOG("[WINSOCK2][TCP][RECEIVE/RETURN][SOCKET 0x%08X][LENGTH %u]\n", ws2_socket_ptr->s, *buffer_length_ptr);

#ifdef EWF_DEBUG
    uint32_t step = 64;
    for (uint32_t i = 0; i < *buffer_length_ptr; i += step)
    {
        const char* str = ewfl_escape_str_to_str_buffer(buffer_ptr + i, step);
        EWF_LOG("[WINSOCK2][TCP][RECEIVE/RETURN][SOCKET 0x%08X][%04d][%s]\n", ws2_socket_ptr->s, i, str);
    }
#endif

    return EWF_RESULT_OK;
}

#endif /* EWF_ADAPTER_WINSOCK2_TCP_ENABLED */

#if EWF_ADAPTER_WINSOCK2_UDP_ENABLED

ewf_adapter_api_udp ewf_adapter_winsock2_api_udp =
{
    ewf_adapter_winsock2_udp_open,
    ewf_adapter_winsock2_udp_close,

    ewf_adapter_winsock2_udp_control,

    ewf_adapter_winsock2_udp_set_dtls_configuration,

    ewf_adapter_winsock2_udp_bind,
    ewf_adapter_winsock2_udp_shutdown,
    ewf_adapter_winsock2_udp_send_to,
    ewf_adapter_winsock2_udp_receive_from,
};

ewf_result ewf_adapter_winsock2_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*)adapter_ptr->implementation_ptr;

    if (socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket pointer cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][UDP][OPEN/CALL][ADAPTER 0x%08p]\n", adapter_ptr);

    socket_ptr->adapter_ptr = adapter_ptr;

    socket_ptr->data_ptr = HeapAlloc(GetProcessHeap(), 0, sizeof(ewf_adapter_winsock2_socket));
    if (socket_ptr->data_ptr == NULL)
    {
        EWF_LOG_ERROR("Failed to allocate a new socket in the heap.\n");
        return EWF_RESULT_OUT_OF_MEMORY;
    }

    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    ws2_socket_ptr->s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("socket failed with error: %ld\n", WSAGetLastError());
        return EWF_RESULT_INVALID_SOCKET;
    }

    /* Make socket non-blocking */
    u_long mode = 1;
    ioctlsocket(ws2_socket_ptr->s, FIONBIO, &mode);

    EWF_LOG("[WINSOCK2][UDP][OPEN/RETURN][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_close(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    EWF_LOG("[WINSOCK2][UDP][CLOSE/CALL][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    if (socket_ptr->data_ptr)
    {
        ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

        if (ws2_socket_ptr->s != INVALID_SOCKET)
        {
            int iResult;

            iResult = closesocket(ws2_socket_ptr->s);
            if (iResult == SOCKET_ERROR)
            {
                EWF_LOG_ERROR("closesocket failed with error: %d\n", WSAGetLastError());
            }
        }

        HeapFree(GetProcessHeap(), 0, socket_ptr->data_ptr);
    }

    EWF_LOG("[WINSOCK2][UDP][CLOSE/RETURN][OK]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_control(ewf_socket_udp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_set_dtls_configuration(ewf_socket_udp* socket_ptr, uint32_t dtls_configuration_id)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_bind(ewf_socket_udp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*)adapter_ptr->implementation_ptr;
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][UDP][BIND/CALL][SOCKET 0x%08X][PORT %u]\n", ws2_socket_ptr->s, port);

    struct sockaddr_in bind_addr;
    bind_addr.sin_family = AF_INET;
    bind_addr.sin_port = htons(port);
    bind_addr.sin_addr.s_addr = htonl(implementation_ptr->ipv4_address.S_un.S_addr); //htonl(INADDR_ANY); //inet_addr("127.0.0.1");

    int iResult = bind(ws2_socket_ptr->s, (SOCKADDR*)&bind_addr, sizeof(bind_addr));
    if (iResult == SOCKET_ERROR)
    {
        EWF_LOG_ERROR("bind failed with error: %d\n", WSAGetLastError());
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    EWF_LOG("[WINSOCK2][UDP][BIND/RETURN][SOCKET 0x%08X][PORT %u]\n", ws2_socket_ptr->s, port);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_shutdown(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    EWF_LOG("[WINSOCK2][UDP][SHUTDOWN/CALL][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    int iResult = shutdown(ws2_socket_ptr->s, SD_BOTH);
    if (iResult == SOCKET_ERROR)
    {
        EWF_LOG_ERROR("shutdown failed with error: %d\n", WSAGetLastError());
        return EWF_RESULT_UNEXPECTED_RESPONSE;
    }

    EWF_LOG("[WINSOCK2][UDP][SHUTDOWN/RETURN][SOCKET 0x%08X]\n", ws2_socket_ptr->s);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    int iResult;

    char remote_port_str[7];
    const char* remote_port_cstr = ewfl_unsigned_to_str(remote_port, remote_port_str, sizeof(remote_port_str));

    struct addrinfo remote_addrinfo;
    ZeroMemory(&remote_addrinfo, sizeof(remote_addrinfo));
    remote_addrinfo.ai_family = AF_INET;
    remote_addrinfo.ai_socktype = SOCK_DGRAM;
    remote_addrinfo.ai_protocol = IPPROTO_UDP;

    struct addrinfo* addrinfo_result = NULL;
    struct addrinfo* addrinfo_ptr = NULL;

    /* Resolve the server address and port */
    iResult = getaddrinfo(remote_address_str, remote_port_cstr, &remote_addrinfo, &addrinfo_result);
    if (iResult != 0)
    {
        EWF_LOG_ERROR("getaddrinfo failed with error: %d\n", iResult);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    if (addrinfo_result->ai_next)
    {
        EWF_LOG_ERROR("[WARNING] Ambiguous address resolved, using the first one.\n");
    }

#ifdef EWF_DEBUG
    uint32_t step = 16;
    for (uint32_t i = 0; i < buffer_length; i += step)
    {
        uint32_t step_buffer_length = (step > (buffer_length - i)) ? (buffer_length - i) : step;
        EWF_LOG("[WINSOCK2][UDP][SEND-TO/CALL][SOCKET 0x%08X][%04d][", ws2_socket_ptr->s, i);
        uint32_t j;
        for (j = 0; j < step; j++)
        {
            if (j < step_buffer_length)
            {
                char c = (char)*(buffer_ptr + i + j);
                EWF_LOG("%c", (32 <= c && c <= 127) ? c : '.');
            }
            else
            {
                EWF_LOG(" ");
            }
        }
        EWF_LOG("]");
        for (j = 0; j < step_buffer_length; j++)
        {
            EWF_LOG(" %02X", (uint32_t) *(buffer_ptr + i + j));
        }
        EWF_LOG("\n");
    }
#endif

    EWF_LOG("[WINSOCK2][UDP][SEND-TO/CALL][SOCKET 0x%08X][SERVER %s][PORT %u][BUFFER 0x%08p][LENGTH %u]\n", ws2_socket_ptr->s, remote_address_str, remote_port, buffer_ptr, buffer_length);

    iResult = sendto(ws2_socket_ptr->s, buffer_ptr, buffer_length, 0, addrinfo_result->ai_addr, addrinfo_result->ai_addrlen);
    if (iResult == SOCKET_ERROR)
    {
        EWF_LOG_ERROR("sendto failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(addrinfo_result);
        return EWF_RESULT_ADAPTER_TRANSMIT_FAILED;
    }

    freeaddrinfo(addrinfo_result);

    EWF_LOG("[WINSOCK2][UDP][SEND-TO/RETURN][SOCKET 0x%08X][SERVER %s][PORT %u][BUFFER 0x%08p][LENGTH %u]\n", ws2_socket_ptr->s, remote_address_str, remote_port, buffer_ptr, buffer_length);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2_socket* ws2_socket_ptr = (ewf_adapter_winsock2_socket*)socket_ptr->data_ptr;

    if (ws2_socket_ptr == NULL)
    {
        EWF_LOG_ERROR("The socket is not valid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (ws2_socket_ptr->s == INVALID_SOCKET)
    {
        EWF_LOG_ERROR("The socket is invalid.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (buffer_ptr == NULL)
    {
        EWF_LOG_ERROR("buffer_ptr cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (buffer_length_ptr == NULL)
    {
        EWF_LOG_ERROR("buffer_length_ptr cannot be NULL.\n");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    struct sockaddr_in remote_addr;
    int remote_addr_size = sizeof(remote_addr);

    EWF_LOG("[WINSOCK2][UDP][RECEIVE-FROM/CALL][SOCKET 0x%08X][BUFFER 0x%08p][LENGTH %u]\n", ws2_socket_ptr->s, buffer_ptr, *buffer_length_ptr);

    for (;;)
    {
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        struct fd_set fds;
        FD_ZERO(&fds);
        FD_SET(ws2_socket_ptr->s, &fds);

        int iResult = select(ws2_socket_ptr->s + 1, &fds, NULL, NULL, &timeout);

        if (iResult == SOCKET_ERROR)
        {
            EWF_LOG_ERROR("select failed with error: %d\n", WSAGetLastError());
            return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
        }

        if (iResult == 0) /* Timeout */
        {
            if (wait)
            {
                /* Sleep and continue */
                ewf_platform_sleep(1);
                continue;
            }
            else
            {
                *buffer_length_ptr = 0;
                EWF_LOG("[WINSOCK2][UDP][RECEIVE/CALL][NO DATA]\n");
                return EWF_RESULT_NO_DATA_AVAILABLE;
            }
        }

        if (FD_ISSET(ws2_socket_ptr->s, &fds))
        {
            /* Data is available! */
            break;
        }
        else
        {
            EWF_LOG_ERROR("select returned unexpectedly.\n");
            return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
        }
    }

    int iResult = recvfrom(ws2_socket_ptr->s, buffer_ptr, *buffer_length_ptr, 0, (SOCKADDR*)&remote_addr, &remote_addr_size);
    if (iResult == SOCKET_ERROR)
    {
        EWF_LOG_ERROR("recv failed with error: %d\n", WSAGetLastError());
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }

    *buffer_length_ptr = iResult;

    if (remote_address && remote_address_length_ptr && (*remote_address_length_ptr > 0))
    {
        inet_ntop(AF_INET, &(remote_addr.sin_addr), remote_address, *remote_address_length_ptr);
    }

    if (remote_port_ptr)
    {
        *remote_port_ptr = ntohs(remote_addr.sin_port);
    }

    EWF_LOG("[WINSOCK2][UDP][RECEIVE-FROM/RETURN][SOCKET 0x%08X][SERVER %s][PORT %u][LENGTH %u]\n", ws2_socket_ptr->s, remote_address ? remote_address : "unresolved", ntohs(remote_addr.sin_port), *buffer_length_ptr);

#ifdef EWF_DEBUG
    uint32_t step = 16;
    for (uint32_t i = 0; i < *buffer_length_ptr; i += step)
    {
        uint32_t step_buffer_length = (step > (*buffer_length_ptr - i)) ? (*buffer_length_ptr - i) : step;
        EWF_LOG("[WINSOCK2][UDP][RECEIVE-FROM/RETURN][SOCKET 0x%08X][%04d][", ws2_socket_ptr->s, i);
        uint32_t j;
        for (j = 0; j < step; j++)
        {
            if (j < step_buffer_length)
            {
                char c = (char)*(buffer_ptr + i + j);
                EWF_LOG("%c", (32 <= c && c <= 127) ? c : '.');
            }
            else
            {
                EWF_LOG(" ");
            }
        }
        EWF_LOG("]");
        for (j = 0; j < step_buffer_length; j++)
        {
            EWF_LOG(" %02X", (uint8_t) * (buffer_ptr + i + j));
        }
        EWF_LOG("\n");
    }
#endif

    return EWF_RESULT_OK;
}

#endif /* EWF_ADAPTER_WINSOCK2_UDP_ENABLED */
