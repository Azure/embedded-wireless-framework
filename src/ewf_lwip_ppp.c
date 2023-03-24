/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT

 * @details
 * The Embedded Wireless Framework LwIP PPP driver
 ****************************************************************************/

/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** LWIP Component                                                        */
/**                                                                       */
/**   Generic Driver for Embedded Wireless Framework Adapters             */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#ifdef LWIP_INCLUDED

#include <stdlib.h>
#include <stdint.h>

#include "ewf.h"
#include "ewf_adapter.h"
#include "ewf_lwip_ppp.h"

ewf_interface* g_interface0_ptr = NULL;
struct netif g_ppp_netif;
static ppp_pcb* ppp;
volatile static ppp_connected = false;

void pppos_rx_thread_task(void* arg)
{
    /* Wait until the interface pointer is initialized before running the receive poll loop */
    while(!g_interface0_ptr)
    {
        ewf_platform_sleep(1);
    }

    while (1)
    {
        ewf_result result = ewf_interface_receive_poll(g_interface0_ptr);
        if (result == EWF_RESULT_EMPTY_QUEUE || result == EWF_RESULT_NO_DATA_AVAILABLE)
        {
            ewf_platform_sleep(2);
        }
    }
}

static u32_t  ewf_ppp_byte_send(ppp_pcb* pcb, u8_t* byte, u32_t len, void* ctx)
{
    ewf_result result = EWF_RESULT_OK;

    if (ewf_result_failed(result = ewf_interface_send(g_interface0_ptr, (const uint8_t*)byte, len)))
    {
        return 0;
    }
    return len;
}

ewf_result ewf_adapter_data_mode_enter(ewf_adapter* adapter_ptr, uint32_t context_id)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    g_interface0_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result = EWF_RESULT_OK;

    /* Set the data mode callback */
    g_interface0_ptr->data_mode_callback = ewf_interface_data_mode_ppp_byte_receive_callback;

    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

    g_interface0_ptr->data_mode = false;

    /* Enter Data Mode */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "ATD*99***", context_id_cstr, "#\r", NULL))) return result;
    ewf_platform_sleep(100);

    if (ewf_result_failed(result = ewf_interface_drop_all_responses(interface_ptr))) return result;

    g_interface0_ptr->data_mode = true;
    EWF_LOG("[ADAPTER DATA MODE ON]\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_data_mode_exit(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_result result;

    /* Wait for 1 second before inputing the exit string ("+++") */
    ewf_platform_sleep(1 * EWF_PLATFORM_TICKS_PER_SECOND);

    /* Exit Data Mode */
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "\x2B\x2B\x2B"))) return result;
    ewf_platform_sleep(5 * EWF_PLATFORM_TICKS_PER_SECOND);
    if (ewf_result_failed(result = ewf_interface_drop_all_responses(interface_ptr))) return result;

    /* Wait for 1 second after inputing the exit string ("+++") */
    ewf_platform_sleep(1 * EWF_PLATFORM_TICKS_PER_SECOND);

#ifdef EWF_DEBUG
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_all_responses(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_all_responses(interface_ptr))) return result;
    if (ewf_result_failed(result = ewf_interface_send_command(interface_ptr, "AT\r"))) return result;
    if (ewf_result_failed(result = ewf_interface_drop_all_responses(interface_ptr))) return result;
#endif

    g_interface0_ptr->data_mode = false;
    EWF_LOG("[ADAPTER DATA MODE OFF]\n");

    // Delete terminate and delete RX thread
    return EWF_RESULT_OK;
}

static void ppp_link_status_cb(ppp_pcb* pcb, int err_code, void* ctx)
{
    struct netif* pppif = ppp_netif(pcb);
    LWIP_UNUSED_ARG(ctx);

    switch (err_code) {
    case PPPERR_NONE: {
        ppp_connected = true;
        EWF_LOG("status_cb: Connected\n");
        break;
    }
    case PPPERR_PARAM: {
        EWF_LOG("status_cb: Invalid parameter\n");
        break;
    }
    case PPPERR_OPEN: {
        EWF_LOG("status_cb: Unable to open PPP session\n");
        break;
    }
    case PPPERR_DEVICE: {
        EWF_LOG("status_cb: Invalid I/O device for PPP\n");
        break;
    }
    case PPPERR_ALLOC: {
        EWF_LOG("status_cb: Unable to allocate resources\n");
        break;
    }
    case PPPERR_USER: {
        EWF_LOG("status_cb: User interrupt\n");
        ppp_connected = false;
        break;
    }
    case PPPERR_CONNECT: {
        EWF_LOG("status_cb: Connection lost\n");
        ppp_connected = false;
        break;
    }
    case PPPERR_AUTHFAIL: {
        EWF_LOG("status_cb: Failed authentication challenge\n");
        break;
    }
    case PPPERR_PROTOCOL: {
        EWF_LOG("status_cb: Failed to meet protocol\n");
        break;
    }
    case PPPERR_PEERDEAD: {
        EWF_LOG("status_cb: Connection timeout\n");
        break;
    }
    case PPPERR_IDLETIMEOUT: {
        EWF_LOG("status_cb: Idle Timeout\n");
        break;
    }
    case PPPERR_CONNECTTIME: {
        EWF_LOG("status_cb: Max connect time reached\n");
        break;
    }
    case PPPERR_LOOPBACK: {
        EWF_LOG("status_cb: Loopback detected\n");
        break;
    }
    default: {
        EWF_LOG("status_cb: Unknown error code %d\n", err_code);
        break;
    }
    }
}

ewf_result ewf_lwip_ppp_config(ewf_adapter* adapter_ptr)
{
    /* Create a PPP control block */
    ppp = pppapi_pppos_create(&g_ppp_netif, ewf_ppp_byte_send, ppp_link_status_cb, NULL);

    /* Set this interface as default route */
    ppp_set_default(ppp);

    /* Ask the peer for up to 2 DNS server addresses. */
    ppp_set_usepeerdns(ppp, 1);

   // ppp_set_auth(ppp, PPPAUTHTYPE_ANY, "", "");
    ppp_set_auth(ppp, PPPAUTHTYPE_ANY, NULL, NULL);

    /* Start PPP negotiation */
    pppapi_connect(ppp, 0);

    /* Check the status of the PPP connection */
    while (!ppp_connected)
    {
        ewf_platform_sleep(1);
    }

    /* PPP connection etablished get the IP address, netmask and gateway */
 #if PPP_IPV4_SUPPORT
    EWF_LOG("   ipaddr   = %s\n", ipaddr_ntoa(netif_ip4_netmask(&g_ppp_netif)));
    EWF_LOG("   gateway  = %s\n", ipaddr_ntoa(netif_ip4_netmask(&g_ppp_netif)));
    EWF_LOG("   netmask  = %s\n", ipaddr_ntoa(netif_ip4_netmask(&g_ppp_netif)));
#if LWIP_DNS
    const ip_addr_t* ns;
    ns = dns_getserver(0);
    EWF_LOG("   dns1     = %s\n", ipaddr_ntoa(ns));
    ns = dns_getserver(1);
    EWF_LOG("   dns2     = %s\n", ipaddr_ntoa(ns));
#endif /* LWIP_DNS */
#endif /* PPP_IPV4_SUPPORT */
#if PPP_IPV6_SUPPORT
    EWF_LOG("   our6_ipaddr = %s\n", ip6addr_ntoa(netif_ip6_addr(&g_ppp_netif, 0)));
#endif /* PPP_IPV6_SUPPORT */

    return EWF_RESULT_OK;
}


ewf_result ewf_interface_data_mode_ppp_byte_receive_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_PARAMETER_NOT_USED(interface_ptr);

#ifdef EWF_DEBUG
    EWF_LOG("[%s][%c]\n", "PPP_RECV", *buffer_ptr);
#endif

    /* Pass received raw characters from PPPoS to be decoded through lwIP
         * TCPIP thread using the TCPIP API. This is thread safe in all cases
         * but you should avoid passing data byte after byte. */
    pppos_input_tcpip(ppp, buffer_ptr, buffer_length);

    return EWF_RESULT_OK;
}

#endif


