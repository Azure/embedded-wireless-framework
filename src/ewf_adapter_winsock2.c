/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework WinSock2 adapter driver
 ****************************************************************************/

#pragma comment (lib, "Ws2_32.lib")
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "fwpuclnt.lib") // Winsock secure socket extensions
#pragma comment(lib, "ntdsapi.lib") // DsMakeSpn function

#include "ewf_adapter_winsock2.h"

#include <stdio.h>
#include <stdlib.h>

#include "ewf_lib.h"

/**
 * @brief Get an available socket from the internal pool
 * @return an index to an available entry in the socket pool, or -1 if not available
 */
static int _ewf_adapter_winsock2_socket_pool_allocate(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);
    ewf_adapter_winsock2* implementation_ptr = (ewf_adapter_winsock2*) adapter_ptr->implementation_ptr;

    int i = -1;
    for (i = 0; i < EWF_ADAPTER_WINSOCK2_SOCKET_POOL_SIZE; ++i)
        if (implementation_ptr->socket_pool[i].used == false)
            break;
    return i;
}

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

    /* Initialize the internal socket array */
    for (unsigned i = 0; i < EWF_ADAPTER_WINSOCK2_SOCKET_POOL_SIZE; ++i)
    {
        implementation_ptr->socket_pool[i].used = false;
        implementation_ptr->socket_pool[i].s = -1;
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
        EWF_LOG_ERROR("The address_ptr parameter cannot be NULL.");
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
        EWF_LOG_ERROR("The netmask parameter cannot be NULL.");
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
        EWF_LOG_ERROR("The gateway parameter cannot be NULL.");
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
        EWF_LOG_ERROR("The dns parameter cannot be NULL.");
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

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_close(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_control(ewf_socket_tcp* socket_ptr, const char* control_str, const uint8_t* buffer_ptr, uint32_t* buffer_length_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_set_tls_configuration(ewf_socket_tcp* socket_ptr, uint32_t tls_configuration_id)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_bind(ewf_socket_tcp* socket_ptr, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_listen(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_accept(ewf_socket_tcp* socket_ptr, ewf_socket_tcp* socket_new_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_connect(ewf_socket_tcp* socket_ptr, const char* const server, uint32_t port)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

#if 0
    ewf_result result;
    int iResult;

    if (!server)
    {
        EWF_LOG_ERROR("The server string cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    *socket_id_ptr = _adapter_socket_pool_allocate();
    if (*socket_id_ptr == -1)
    {
        EWF_LOG_ERROR("Too many open sockets.");
        return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
    }

	char port_str[7];
	const char* port_cstr = _unsigned_to_str(port, port_str, sizeof(port_str));

	struct addrinfo server_addrinfo;
	ZeroMemory(&server_addrinfo, sizeof(server_addrinfo));
	server_addrinfo.ai_family = AF_INET;
	server_addrinfo.ai_socktype = SOCK_STREAM;
	server_addrinfo.ai_protocol = IPPROTO_TCP;

	struct addrinfo* addrinfo_result = NULL;
	struct addrinfo* addrinfo_ptr = NULL;

	/* Resolve the server address and port */
	iResult = getaddrinfo(server, port_cstr, &server_addrinfo, &addrinfo_result);
	if (iResult != 0)
	{
		EWF_LOG_ERROR("getaddrinfo failed with error: %d\n", iResult);
		return EWF_RESULT_CONNECTION_FAILED;
	}

	/* Attempt to connect to an address until one succeeds */
	for (addrinfo_ptr = addrinfo_result; addrinfo_ptr != NULL; addrinfo_ptr = addrinfo_ptr->ai_next) {

		/* Create a SOCKET for connecting to the server. */
		_adapter_socket_pool[*socket_id_ptr].s = socket(addrinfo_ptr->ai_family, addrinfo_ptr->ai_socktype, addrinfo_ptr->ai_protocol);
		if (_adapter_socket_pool[*socket_id_ptr].s == INVALID_SOCKET) {
			EWF_LOG_ERROR("socket failed with error: %ld\n", WSAGetLastError());
			break;
		}

		/* Attmept to connect to the server. */
		iResult = connect(_adapter_socket_pool[*socket_id_ptr].s, addrinfo_ptr->ai_addr, (int)addrinfo_ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(_adapter_socket_pool[*socket_id_ptr].s);
			_adapter_socket_pool[*socket_id_ptr].s = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(addrinfo_result);

	if (_adapter_socket_pool[*socket_id_ptr].s == INVALID_SOCKET) {
		EWF_LOG_ERROR("Unable to connect to server!\n");
		return EWF_RESULT_CONNECTION_FAILED;
	}

	_adapter_socket_pool[*socket_id_ptr].used = true;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_shutdown(ewf_socket_tcp* socket_ptr)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

#if 0
    ewf_result result;
	int iResult;

	if ((socket_id < 0) || (_ADAPTER_SOCKET_POOL_SIZE <= socket_id))
	{
		EWF_LOG_ERROR("Invalid socket value.");
		return EWF_RESULT_INVALID_SOCKET;
	}

	if (_adapter_socket_pool[socket_id].used == false)
	{
		EWF_LOG_ERROR("Socket is not open.");
		return EWF_RESULT_SOCKET_NOT_OPEN;
	}

	_adapter_socket_pool[socket_id].used = false;

	iResult = shutdown(_adapter_socket_pool[socket_id].s, SD_BOTH);
	if (iResult == SOCKET_ERROR) {
		EWF_LOG_ERROR("shutdown failed with error: %d\n", WSAGetLastError());
	}

	closesocket(_adapter_socket_pool[socket_id].s);
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_send(ewf_socket_tcp* socket_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

#if 0
	int iResult;

	if ((socket_id < 0) || (_ADAPTER_SOCKET_POOL_SIZE <= socket_id))
	{
		EWF_LOG_ERROR("Invalid socket value.");
		return EWF_RESULT_INVALID_SOCKET;
	}

	if (_adapter_socket_pool[socket_id].used == false)
	{
		EWF_LOG_ERROR("Socket is not open.");
		return EWF_RESULT_SOCKET_NOT_OPEN;
	}

	iResult = send(_adapter_socket_pool[socket_id].s, buffer, (int)buffer_length, 0);
	if (iResult == SOCKET_ERROR) 
    {
		EWF_LOG_ERROR("send failed with error: %d\n", WSAGetLastError());
	}
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_tcp_receive(ewf_socket_tcp* socket_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length, bool wait)
{
    EWF_VALIDATE_TCP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

#if 0
	int iResult;

	if ((socket_id < 0) || (_ADAPTER_SOCKET_POOL_SIZE <= socket_id))
	{
		EWF_LOG_ERROR("Invalid socket value.");
		return EWF_RESULT_INVALID_SOCKET;
	}

	if (_adapter_socket_pool[socket_id].used == false)
	{
		EWF_LOG_ERROR("Socket is not open.");
		return EWF_RESULT_SOCKET_NOT_OPEN;
	}

	iResult = recv(_adapter_socket_pool[socket_id].s, buffer, *buffer_length, 0);
	if (iResult > 0)
	{
		*buffer_length = iResult;
	}
	else if (iResult == 0)
	{
		EWF_LOG_ERROR("Connection closed");
		return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
	}
	else
	{
		EWF_LOG_ERROR("recv failed with error: %d\n", WSAGetLastError());
		return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
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
    ewf_adapter_winsock2_udp_send_to,
    ewf_adapter_winsock2_udp_receive_from,
};

ewf_result ewf_adapter_winsock2_udp_open(ewf_adapter* adapter_ptr, ewf_socket_udp* socket_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

#if 0
    ewf_result result;
    int iResult;

    if (!socket_id_ptr)
    {
        EWF_LOG_ERROR("The socket pointer cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    if (!server)
    {
        EWF_LOG_ERROR("The server string cannot be NULL.");
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;
    }

    *socket_id_ptr = _adapter_socket_pool_allocate();
    if (*socket_id_ptr == -1)
    {
        EWF_LOG_ERROR("Too many open sockets.");
        return EWF_RESULT_TOO_MANY_OPEN_SOCKETS;
    }

    char port_str[7];
    const char* port_cstr = _unsigned_to_str(port, port_str, sizeof(port_str));

    struct addrinfo server_addrinfo;
    ZeroMemory(&server_addrinfo, sizeof(server_addrinfo));
    server_addrinfo.ai_family = AF_INET;
    server_addrinfo.ai_socktype = SOCK_DGRAM;
    server_addrinfo.ai_protocol = IPPROTO_UDP;

    struct addrinfo* addrinfo_result = NULL;
    struct addrinfo* addrinfo_ptr = NULL;

    /* Resolve the server address and port */
    iResult = getaddrinfo(server, port_cstr, &server_addrinfo, &addrinfo_result);
    if (iResult != 0)
    {
        EWF_LOG_ERROR("getaddrinfo failed with error: %d\n", iResult);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    /* Attempt to connect to an address until one succeeds */
    for (addrinfo_ptr = addrinfo_result; addrinfo_ptr != NULL; addrinfo_ptr = addrinfo_ptr->ai_next) {

        /* Create a SOCKET for connecting to the server. */
        _adapter_socket_pool[*socket_id_ptr].s = socket(addrinfo_ptr->ai_family, addrinfo_ptr->ai_socktype, addrinfo_ptr->ai_protocol);
        if (_adapter_socket_pool[*socket_id_ptr].s == INVALID_SOCKET) {
            EWF_LOG_ERROR("socket failed with error: %ld\n", WSAGetLastError());
            break;
        }

        /* Attmept to connect to the server. */
        iResult = connect(_adapter_socket_pool[*socket_id_ptr].s, addrinfo_ptr->ai_addr, (int)addrinfo_ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(_adapter_socket_pool[*socket_id_ptr].s);
            _adapter_socket_pool[*socket_id_ptr].s = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(addrinfo_result);

    if (_adapter_socket_pool[*socket_id_ptr].s == INVALID_SOCKET) {
        EWF_LOG_ERROR("Unable to connect to server!\n");
        return EWF_RESULT_CONNECTION_FAILED;
    }

    _adapter_socket_pool[*socket_id_ptr].used = true;
#endif

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_close(ewf_socket_udp* socket_ptr)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    /*
    ewf_result result;
    int iResult;

    if ((socket_id < 0) || (_ADAPTER_SOCKET_POOL_SIZE <= socket_id))
    {
        EWF_LOG_ERROR("Invalid socket value.");
        return EWF_RESULT_INVALID_SOCKET;
    }

    if (_adapter_socket_pool[socket_id].used == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    _adapter_socket_pool[socket_id].used = false;

    iResult = shutdown(_adapter_socket_pool[socket_id].s, SD_BOTH);
    if (iResult == SOCKET_ERROR) {
        EWF_LOG_ERROR("shutdown failed with error: %d\n", WSAGetLastError());
    }

    closesocket(_adapter_socket_pool[socket_id].s);
    */

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

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_send_to(ewf_socket_udp* socket_ptr, const char* remote_address_str, uint32_t remote_port, const uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    /*
    int iResult;

    if ((socket_id < 0) || (_ADAPTER_SOCKET_POOL_SIZE <= socket_id))
    {
        EWF_LOG_ERROR("Invalid socket value.");
        return EWF_RESULT_INVALID_SOCKET;
    }

    if (_adapter_socket_pool[socket_id].used == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    iResult = send(_adapter_socket_pool[socket_id].s, buffer, (int)buffer_length, 0);
    if (iResult == SOCKET_ERROR) 
    {
        EWF_LOG_ERROR("send failed with error: %d\n", WSAGetLastError());
    }
    */

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_winsock2_udp_receive_from(ewf_socket_udp* socket_ptr, char* remote_address, uint32_t* remote_address_length_ptr, uint32_t* remote_port_ptr, char* buffer_ptr, uint32_t* buffer_length_ptr, bool wait)
{
    EWF_VALIDATE_UDP_SOCKET_POINTER(socket_ptr);
    ewf_adapter* adapter_ptr = socket_ptr->adapter_ptr;
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, EWF_ADAPTER_TYPE_WINSOCK2);

    /*
    int iResult;

    if ((socket_id < 0) || (_ADAPTER_SOCKET_POOL_SIZE <= socket_id))
    {
        EWF_LOG_ERROR("Invalid socket value.");
        return EWF_RESULT_INVALID_SOCKET;
    }

    if (_adapter_socket_pool[socket_id].used == false)
    {
        EWF_LOG_ERROR("Socket is not open.");
        return EWF_RESULT_SOCKET_NOT_OPEN;
    }

    iResult = recv(_adapter_socket_pool[socket_id].s, buffer, *buffer_length, 0);
    if (iResult > 0)
    {
        *buffer_length = iResult;
    }
    else if (iResult == 0)
    {
        EWF_LOG_ERROR("Connection closed");
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }
    else
    {
        EWF_LOG_ERROR("recv failed with error: %d\n", WSAGetLastError());
        return EWF_RESULT_ADAPTER_RECEIVE_FAILED;
    }
    */

    return EWF_RESULT_OK;
}

#endif /* EWF_ADAPTER_WINSOCK2_UDP_ENABLED */
