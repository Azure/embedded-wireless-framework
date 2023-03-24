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
/** NetX Duo PPP Component                                                */
/**                                                                       */
/**   Generic PPP Driver for Embedded Wireless Framework Adapters         */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

/* EWF enabled to use with Azure RTOS NetX */
#if (EWF_CONFIG_AZURE_RTOS_NETX == 1)

#include <stdlib.h>
#include <stdint.h>

#include "ewf.h"
#include "ewf_adapter.h"
#include "ewf_lib.h"

#include "ewf_netxduo_ppp.h"

#include "nx_api.h"
#include "nx_ip.h"
#include "nx_ppp.h"

static TX_THREAD ewf_ppp_rx_thread;
static uint8_t ewf_ppp_rx_thread_stack[1024];

static NX_PPP* g_ppp0_ptr;
static NX_IP* g_ip0_ptr;

ewf_netxduo_ppp_cfg* g_ppp_cfg;

static ewf_interface* g_interface0_ptr = NULL;
bool ppp_linkup = false;

void ewf_ppp_byte_send(UCHAR byte);
void ewf_ppp_link_up_callback(NX_PPP *ppp_ptr);
void ewf_ppp_link_down_callback(NX_PPP *ppp_ptr);
void ewf_ppp_invalid_packet_handler(NX_PACKET *packet_ptr);
void ewf_ppp_rx_thread_entry(ULONG thread_input);

void ewf_ppp_rx_thread_entry(ULONG thread_input)
{
    EWF_PARAMETER_NOT_USED(thread_input);
    while(1)
    {
        ewf_result result = ewf_interface_receive_poll(g_interface0_ptr);
        if (result == EWF_RESULT_EMPTY_QUEUE || result == EWF_RESULT_NO_DATA_AVAILABLE)
        {
            tx_thread_sleep(1);
        }
    }
}

ewf_result ewf_adapter_data_mode_enter(ewf_adapter* adapter_ptr, uint32_t context_id)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    g_interface0_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    UINT status = NX_SUCCESS;

    /* Set the data mode callback */
    g_interface0_ptr->data_mode_callback = ewf_interface_data_mode_ppp_byte_receive_callback;

#ifdef EWF_PLATFORM_THREADX
    // Create a thread to poll receive processing when adapter is in data mode (PPP)
    status = tx_thread_create(&ewf_ppp_rx_thread, "PPP RX Thread", ewf_ppp_rx_thread_entry, 0,
        ewf_ppp_rx_thread_stack, sizeof(ewf_ppp_rx_thread_stack),
        5, 5,
        TX_NO_TIME_SLICE, TX_AUTO_START);
    /* Check for thread creation error.  */
    if (status)
    {
        EWF_LOG_ERROR("Failed to create PPP Receive thread, status: %d.\n", status);
        return EWF_RESULT_CONNECTION_FAILED;
    }
#endif

    ewf_result result = EWF_RESULT_OK;
    char context_id_str[3];
    const char* context_id_cstr = ewfl_unsigned_to_str(context_id, context_id_str, sizeof(context_id_str));

    g_interface0_ptr->data_mode = false;

    /* Enter Data Mode */
    if (ewf_result_failed(result = ewf_interface_send_commands(interface_ptr, "ATD*99***", context_id_cstr,"#\r",NULL))) return result;
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

    nx_ppp_stop(g_ppp0_ptr);

    nx_ip_delete(g_ip0_ptr);

    nx_ppp_delete(g_ppp0_ptr);

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

    // Delete the PPP receive thread
    tx_thread_delete(&ewf_ppp_rx_thread);

    g_interface0_ptr->data_mode = false;
    EWF_LOG("[ADAPTER DATA MODE OFF]\n");

    // Delete terminate and delete RX thread
    return EWF_RESULT_OK;
}

void ewf_ppp_byte_send(UCHAR byte)
{
    ewf_interface_send(g_interface0_ptr, (const uint8_t* )&byte, 1U);
}

void ewf_ppp_link_up_callback(NX_PPP *ppp_ptr)
{
	EWF_PARAMETER_NOT_USED(ppp_ptr);
    EWF_LOG("[PPP link up]");
    ppp_linkup = true;
}

void ewf_ppp_link_down_callback(NX_PPP *ppp_ptr)
{
    EWF_LOG("[PPP link down]");
    ppp_linkup = false;
    /* Restart the PPP instance.  */
    nx_ppp_restart(ppp_ptr);
}

void ewf_ppp_invalid_packet_handler(NX_PACKET *packet_ptr)
{
    if (g_ppp_cfg->ppp_invalid_packet_callback)
    {
        g_ppp_cfg->ppp_invalid_packet_callback(packet_ptr);
    }
}

 ewf_result ewf_netxduo_ppp_config(ewf_adapter* adapter_ptr, ewf_netxduo_ppp_cfg* ppp_cfg_ptr)
{
    g_ppp_cfg = ppp_cfg_ptr;
    g_ppp0_ptr = ppp_cfg_ptr->ppp_ptr;
    g_ip0_ptr = ppp_cfg_ptr->ip_ptr;

    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);
    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    /* Update the global interface pointer to be used for PPP send */
    g_interface0_ptr = interface_ptr;
    UINT status = 0;

    /* Initialize the NetX system.  */
    nx_system_initialize();

    /* Create the PPP instance.  */
    status =  nx_ppp_create(ppp_cfg_ptr->ppp_ptr,
            "NetX PPP Instance 0", ppp_cfg_ptr->ip_ptr,
        ppp_cfg_ptr->ppp_thread_stack_ptr, 
        ppp_cfg_ptr->ppp_thread_stack_size,
        ppp_cfg_ptr->ppp_thread_priority,
        ppp_cfg_ptr->pool_ptr, 
        ewf_ppp_invalid_packet_handler, 
        ewf_ppp_byte_send);

    /* Check for PPP creation error.  */
    if (status)
    {
        EWF_LOG_ERROR("Failed to create PPP instance, status: %d.\n", status);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    /* Define IP address. This PPP instance is effectively the client since it doesn't have any IP addresses. */
    status = nx_ppp_ip_address_assign(ppp_cfg_ptr->ppp_ptr, IP_ADDRESS(0, 0, 0, 0), IP_ADDRESS(0, 0, 0, 0));

    /* Check for PPP IP address assign error.   */
    if (status)
    {
        EWF_LOG_ERROR("Failed to assign PPP IP address, status: %d.\n", status);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    /* Register the link up/down callbacks.  */
    status =  nx_ppp_link_up_notify(ppp_cfg_ptr->ppp_ptr, ewf_ppp_link_up_callback);
    if (status)
    {
        EWF_LOG_ERROR("Failed to register PPP uplink callback, status: %d.\n", status);
        (void)nx_ppp_delete(ppp_cfg_ptr->ppp_ptr);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    status = nx_ppp_link_down_notify(ppp_cfg_ptr->ppp_ptr, ewf_ppp_link_down_callback);
    if (status)
    {
        EWF_LOG_ERROR("Failed to register PPP downlink callback, status: %d.\n", status);
        (void)nx_ppp_delete(ppp_cfg_ptr->ppp_ptr);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    /* Create an IP instance.  */
    status = nx_ip_create(ppp_cfg_ptr->ip_ptr,
            "NetX IP Instance",
            IP_ADDRESS(0, 0, 0, 0), 
            IP_ADDRESS(255, 255, 255, 0),
            ppp_cfg_ptr->pool_ptr,
            nx_ppp_driver,
            ppp_cfg_ptr->ip_thread_stack_ptr,
            ppp_cfg_ptr->ip_thread_stack_size,
            /* Configure NetX IP thread at a higher priority than the PPP thread */
            ppp_cfg_ptr->ppp_thread_priority - 1);

    /* Check for IP create errors.  */
    if (status)
    {
        EWF_LOG_ERROR("Failed to create IP instance, status: %d.\n", status);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    while (ppp_linkup != true)
    {
        tx_thread_sleep(1);
    }

    ULONG ip_status = 0;
    do
    {

        /* Wait for the link to come up.  */
        status = nx_ip_status_check(ppp_cfg_ptr->ip_ptr, NX_IP_LINK_ENABLED, &ip_status, 10 * NX_IP_PERIODIC_RATE);
    } while (status);

    /* Wait for address resolved.  */
    status = nx_ip_status_check(ppp_cfg_ptr->ip_ptr, NX_IP_ADDRESS_RESOLVED, &ip_status, 5 * NX_IP_PERIODIC_RATE);

    /* Check status.  */
    if (status)
    {
        EWF_LOG("ERROR!\n");
    }

    UCHAR ipv4address[4];
    UCHAR networkmask[4];
    UCHAR gateway_address[4];
    ULONG temp;
    /* Get IP address. */
    nx_ip_address_get(ppp_cfg_ptr->ip_ptr, (ULONG*)&ipv4address[0], (ULONG*)&networkmask[0]);

    nx_ip_gateway_address_get(ppp_cfg_ptr->ip_ptr, (ULONG*)&gateway_address[0]);

    /* Convert IP address & network mask from little endian.  */
    temp = *((ULONG*)&ipv4address[0]);
    NX_CHANGE_ULONG_ENDIAN(temp);
    *((ULONG*)&ipv4address[0]) = temp;

    temp = *((ULONG*)&networkmask[0]);
    NX_CHANGE_ULONG_ENDIAN(temp);
    *((ULONG*)&networkmask[0]) = temp;

    temp = *((ULONG*)&gateway_address[0]);
    NX_CHANGE_ULONG_ENDIAN(temp);
    *((ULONG*)&gateway_address[0]) = temp;

    status = nx_ip_address_set(ppp_cfg_ptr->ip_ptr, IP_ADDRESS(ipv4address[0], ipv4address[1], ipv4address[2], ipv4address[3]), 0xFFFFFF00);
    if (status)
    {
        EWF_LOG("Failed to set network mask\r\n");
    }

    /* Get IP address. */
    nx_ip_address_get(ppp_cfg_ptr->ip_ptr, (ULONG*)&ipv4address[0], (ULONG*)&networkmask[0]);

    /* Convert IP address & network mask from little endian.  */
    temp = *((ULONG*)&ipv4address[0]);
    NX_CHANGE_ULONG_ENDIAN(temp);
    *((ULONG*)&ipv4address[0]) = temp;

    temp = *((ULONG*)&networkmask[0]);
    NX_CHANGE_ULONG_ENDIAN(temp);
    *((ULONG*)&networkmask[0]) = temp;

    /* Output IP address. */
    EWF_LOG("\r\nIP address: %d.%d.%d.%d\nMask: %d.%d.%d.%d\nGateway: %d.%d.%d.%d\r\n",
        (UINT)(ipv4address[0]),
        (UINT)(ipv4address[1]),
        (UINT)(ipv4address[2]),
        (UINT)(ipv4address[3]),
        (UINT)(networkmask[0]),
        (UINT)(networkmask[1]),
        (UINT)(networkmask[2]),
        (UINT)(networkmask[3]),
        (UINT)(gateway_address[0]),
        (UINT)(gateway_address[1]),
        (UINT)(gateway_address[2]),
        (UINT)(gateway_address[3]));

    return EWF_RESULT_OK;
}


ewf_result ewf_interface_data_mode_ppp_byte_receive_callback(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length)
{
    EWF_PARAMETER_NOT_USED(interface_ptr);
    EWF_PARAMETER_NOT_USED(buffer_length);

#ifdef EWF_DEBUG
    EWF_LOG("[%s][%c]\n", "PPP_RECV", *buffer_ptr);
#endif

    (void)nx_ppp_byte_receive(g_ppp0_ptr, *buffer_ptr);

    return EWF_RESULT_OK;
}

#endif
