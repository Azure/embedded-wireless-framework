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
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : thread_x_entry.c
 * Version      : 1.0
 * Description  : declare Thread entry function  
 **********************************************************************************************************************/
/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "azurertos_object_init.h"

#include "demo_printf.h"

#define SAMPLE_DHCP_DISABLE

#include "nx_api.h"
#include "nxd_dns.h"
#include "nxd_sntp_client.h"
#include "nx_secure_tls_api.h"

#include "ewf_lib.h"
#include "ewf_platform_threadx.h"
#include "ewf_allocator.h"
#include "ewf_allocator_threadx.h"
#include "ewf_tokenizer.h"
#include "ewf_tokenizer_basic.h"
#include "ewf_interface.h"
#include "ewf_interface_rx_uart.h"
#include "ewf_adapter.h"
#include "ewf_adapter_renesas_common.h"
#include "ewf_adapter_renesas_ryz014.h"
#include "ewf_middleware_netxduo.h"

#include "ewf_example.config.h"

#include "ewf_cellular_private.h"

/* Modem might take some minutes to attach and register to the network. Time out value in seconds */
#define EWF_ADAPTER_RENESAS_NETWORK_REGISTER_TIMEOUT  (120)

//#include "sample_azure_iot_embedded_sdk.c"
/* Include the sample.  */
extern VOID sample_entry(NX_IP* ip_ptr, NX_PACKET_POOL* pool_ptr, NX_DNS* dns_ptr, UINT (*unix_time_callback)(ULONG *unix_time));

/* Define user configurable symbols. */
#ifndef SAMPLE_IP_STACK_SIZE
#define SAMPLE_IP_STACK_SIZE          (2048)
#endif /* SAMPLE_IP_STACK_SIZE  */

#ifndef SAMPLE_PACKET_COUNT
#define SAMPLE_PACKET_COUNT           (40)
#endif /* SAMPLE_PACKET_COUNT  */

#ifndef SAMPLE_PACKET_SIZE
#define SAMPLE_PACKET_SIZE            (1536)
#endif /* SAMPLE_PACKET_SIZE  */

#define SAMPLE_POOL_SIZE              ((SAMPLE_PACKET_SIZE + sizeof(NX_PACKET)) * SAMPLE_PACKET_COUNT)

#ifndef SAMPLE_ARP_CACHE_SIZE
#define SAMPLE_ARP_CACHE_SIZE         (512)
#endif /* SAMPLE_ARP_CACHE_SIZE  */

#ifndef SAMPLE_IP_THREAD_PRIORITY
#define SAMPLE_IP_THREAD_PRIORITY     (1)
#endif /* SAMPLE_IP_THREAD_PRIORITY */

#ifndef SAMPLE_SNTP_SYNC_MAX
#define SAMPLE_SNTP_SYNC_MAX             (30)
#endif /* SAMPLE_SNTP_SYNC_MAX */

#ifndef SAMPLE_SNTP_UPDATE_MAX
#define SAMPLE_SNTP_UPDATE_MAX            (10)
#endif /* SAMPLE_SNTP_UPDATE_MAX */

#ifndef SAMPLE_SNTP_UPDATE_INTERVAL
#define SAMPLE_SNTP_UPDATE_INTERVAL       (NX_IP_PERIODIC_RATE / 2)
#endif /* SAMPLE_SNTP_UPDATE_INTERVAL */

/* Default time. GMT+01: Saturday, December 31, 2022  */
#ifndef SAMPLE_SYSTEM_TIME
#define SAMPLE_SYSTEM_TIME                1672531199
#endif /* SAMPLE_SYSTEM_TIME  */

/* Seconds between Unix Epoch (1/1/1970) and NTP Epoch (1/1/1999) */
#define SAMPLE_UNIX_TO_NTP_EPOCH_SECOND   (0x83AA7E80)

ULONG g_ip_address = 0;
ULONG g_network_mask = 0;
ULONG g_gateway_address = 0;
ULONG g_dns_address = 0;

NX_PACKET_POOL   pool_0;
NX_IP            ip_0;
NX_DNS           dns_0;
NX_SNTP_CLIENT   sntp_client_0;

/* System clock time for UTC.  */
ULONG            unix_time_base;

/* Define the stack/cache for ThreadX.  */
ULONG sample_ip_stack[SAMPLE_IP_STACK_SIZE / sizeof(ULONG)];
ULONG sample_pool_stack[SAMPLE_POOL_SIZE / sizeof(ULONG)];
ULONG sample_pool_stack_size = sizeof(sample_pool_stack);
ULONG sample_arp_cache_area[SAMPLE_ARP_CACHE_SIZE / sizeof(ULONG)];

static const CHAR *sntp_servers[] =
{
    "0.pool.ntp.org",
    "1.pool.ntp.org",
    "2.pool.ntp.org",
    "3.pool.ntp.org",
};
static UINT sntp_server_index;

static UINT dns_create();;
UINT unix_time_get(ULONG *unix_time);
static UINT sntp_time_sync();
static UINT sntp_time_sync_internal(ULONG sntp_server_address);

void renesas_ryz014a_adapter_power_on()
{

    // Release the RYZ014A from reset
    EWF_CELLULAR_SET_PODR(EWF_CELLULAR_CFG_RESET_PORT, EWF_CELLULAR_CFG_RESET_PIN) = EWF_CELLULAR_CFG_RESET_SIGNAL_ON;
    EWF_CELLULAR_SET_PDR(EWF_CELLULAR_CFG_RESET_PORT, EWF_CELLULAR_CFG_RESET_PIN) = EWF_CELLULAR_PIN_DIRECTION_MODE_OUTPUT;
    tx_thread_sleep (100);
    EWF_CELLULAR_SET_PODR(EWF_CELLULAR_CFG_RESET_PORT, EWF_CELLULAR_CFG_RESET_PIN) = EWF_CELLULAR_CFG_RESET_SIGNAL_OFF;
    demo_printf("Waiting for the module to Power Reset!\r\n");
    ewf_platform_sleep(300);
    demo_printf("Ready\r\n");

}

/* New Thread entry function */
void application_thread_entry(ULONG entry_input)
{

    /* Initialize the demo printf implementation. */
    demo_printf_init();

    /* Power on the modem */
    renesas_ryz014a_adapter_power_on();

	ewf_result result;
	UINT status = 0;

	ewf_allocator* message_allocator_ptr = NULL;
	ewf_interface* interface_ptr = NULL;
	ewf_adapter* adapter_ptr = NULL;

	EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_COUNT, EWF_CONFIG_MESSAGE_ALLOCATOR_BLOCK_SIZE);
	EWF_INTERFACE_RX_UART_STATIC_DECLARE(interface_ptr , sci_uart);
	EWF_ADAPTER_RENESAS_RYZ014_STATIC_DECLARE(adapter_ptr, renesas_ryz014, message_allocator_ptr, NULL, interface_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);

        EWF_LOG("Enter while(1) loop to stop program execution.\n");
        while(1);
    }

    /* Disable network Registration URC */
    if (ewf_result_failed(result = ewf_adapter_modem_network_registration_urc_set(adapter_ptr, "0")))
    {
        EWF_LOG_ERROR("Failed to disable network registration status URC, ewf_result %d.\n", result);
        return;
    }

    /* Disable EPS network Registration URC */
    if (ewf_result_failed(result = ewf_adapter_modem_eps_network_registration_urc_set(adapter_ptr, "0")))
    {
        EWF_LOG_ERROR("Failed to disable network registration status URC, ewf_result %d.\n", result);
        return;
    }

    // Set the ME functionality to minimum to clear out any previous connections
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_MINIMUM)))
    {
        EWF_LOG("[Warning][Failed to the ME functionality]\n");
    }

    /* Wait time for modem to be ready*/
    ewf_platform_sleep(300);

    // Set the APN
    if (ewf_result_failed(result = ewf_adapter_modem_pdp_apn_set(adapter_ptr, EWF_CONFIG_CONTEXT_ID, EWF_ADAPTER_MODEM_PDP_TYPE_IP, EWF_CONFIG_SIM_APN)))
    {
        EWF_LOG_ERROR("Failed to the set APN, ewf_result %d.\n", result);
        return;
    }

    // Set the ME functionality
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, EWF_ADAPTER_MODEM_FUNCTIONALITY_FULL)))
    {
        EWF_LOG_ERROR("Failed to the ME functionality, ewf_result %d.\n", result);
        return;
    }

    /* Wait time for modem to be ready after modem is registered to network */
    ewf_platform_sleep(3 * EWF_PLATFORM_TICKS_PER_SECOND);

    // Set the SIM PIN
    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        EWF_LOG_ERROR("Failed to the SIM PIN, ewf_result %d.\n", result);

        EWF_LOG("Enter while(1) loop to stop program execution.\n");
        while(1);
    }

    if (ewf_result_failed(result = ewf_adapter_modem_network_registration_check(adapter_ptr, EWF_ADAPTER_MODEM_CMD_QUERY_EPS_NETWORK_REG, EWF_ADAPTER_RENESAS_NETWORK_REGISTER_TIMEOUT)))
    {
        EWF_LOG("[ERROR][Failed to register to network.]\n");
        return;
    }

    // Activated the PDP context
    if (ewf_result_failed(result = ewf_adapter_modem_packet_service_activate(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG_ERROR("Failed to activate the PDP context: ewf_result %d.\n", result);
        // continue despite the error
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_address(adapter_ptr, (uint32_t*)&g_ip_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 address: ewf_result %d.\n", result);

        EWF_LOG("Enter while(1) loop to stop program execution.\n");
        while(1);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_netmask(adapter_ptr, (uint32_t*)&g_network_mask)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 netmask: ewf_result %d.\n", result);

        EWF_LOG("Enter while(1) loop to stop program execution.\n");
        while(1);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_gateway(adapter_ptr, (uint32_t*)&g_gateway_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 gateway: ewf_result %d.\n", result);

        EWF_LOG("Enter while(1) loop to stop program execution.\n");
        while(1);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_dns(adapter_ptr, (uint32_t*)&g_dns_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 DNS: ewf_result %d.\n", result);

        EWF_LOG("Enter while(1) loop to stop program execution.\n");
        while(1);
    }

    /* Initialize the NetX system.  */
    nx_system_initialize();

    /* Create a packet pool.  */
    status = nx_packet_pool_create(&pool_0, "NetX Main Packet Pool", SAMPLE_PACKET_SIZE,
                                   &sample_pool_stack[0] , sample_pool_stack_size);

    /* Check for pool creation error.  */
    if (status)
    {
    	EWF_LOG_ERROR("nx_packet_pool_create fail: %u\r\n", status);
        return;
    }

    /* Create an IP instance.  */
    status = nx_ip_create(&ip_0, "NetX IP Instance 0",
    		              g_ip_address, g_network_mask,
                          &pool_0, nx_driver_ewf_adapter,
                          (UCHAR*)&sample_ip_stack[0], sizeof(sample_ip_stack),
                          SAMPLE_IP_THREAD_PRIORITY);

    /* Check for IP create errors.  */
    if (status)
    {
    	EWF_LOG_ERROR("nx_ip_create fail: %u\r\n", status);
        return;
    }

    /* Save the adapter pointer in the IP instance */
    ip_0.nx_ip_interface->nx_interface_additional_link_info = adapter_ptr;

    /* Enable ARP and supply ARP cache memory for IP Instance 0.  */
    status = nx_arp_enable(&ip_0, (VOID *)&sample_arp_cache_area[0], sizeof(sample_arp_cache_area));

    /* Check for ARP enable errors.  */
    if (status)
    {
        EWF_LOG_ERROR("nx_arp_enable fail: %u\r\n", status);
        return;
    }

    /* Enable ICMP traffic.  */
    status = nx_icmp_enable(&ip_0);

    /* Check for ICMP enable errors.  */
    if (status)
    {
        EWF_LOG_ERROR("nx_icmp_enable fail: %u\r\n", status);
        return;
    }

    /* Enable TCP traffic.  */
    status = nx_tcp_enable(&ip_0);

    /* Check for TCP enable errors.  */
    if (status)
    {
        EWF_LOG_ERROR("nx_tcp_enable fail: %u\r\n", status);
        return;
    }

    /* Enable UDP traffic.  */
    status = nx_udp_enable(&ip_0);

    /* Check for UDP enable errors.  */
    if (status)
    {
        EWF_LOG_ERROR("nx_udp_enable fail: %u\r\n", status);
        return;
    }


    ULONG   ip_address = 0;
    ULONG   network_mask = 0;
    ULONG   gateway_address = 0;

    nx_ip_gateway_address_set(&ip_0, g_gateway_address);

    /* Get IP address and gateway address. */
    nx_ip_address_get(&ip_0, &ip_address, &network_mask);
    nx_ip_gateway_address_get(&ip_0, &gateway_address);

    /* Output IP address and gateway address. */
    printf("IP address: %lu.%lu.%lu.%lu\r\n",
           (ip_address >> 24),
           (ip_address >> 16 & 0xFF),
           (ip_address >> 8 & 0xFF),
           (ip_address & 0xFF));
    printf("Mask: %lu.%lu.%lu.%lu\r\n",
           (network_mask >> 24),
           (network_mask >> 16 & 0xFF),
           (network_mask >> 8 & 0xFF),
           (network_mask & 0xFF));
    printf("Gateway: %lu.%lu.%lu.%lu\r\n",
           (gateway_address >> 24),
           (gateway_address >> 16 & 0xFF),
           (gateway_address >> 8 & 0xFF),
           (gateway_address & 0xFF));

    status = dns_create();
    if (status)
    {
        EWF_LOG("DNS Create Failed: %u\r\n", status);

        EWF_LOG("Enter while(1) loop to stop program execution.\n");
        while(1);
    }

    /* Sync up time by SNTP at start up.  */
    status = sntp_time_sync();

    /* Check status.  */
    if (status)
    {
        printf("SNTP Time Sync failed.\r\n");
        printf("Set Time to default value: SAMPLE_SYSTEM_TIME.");
        unix_time_base = SAMPLE_SYSTEM_TIME;
    }
    else
    {
        printf("SNTP Time Sync successfully.\r\n");
    }

    ULONG   unix_time = 0;
     /* Use time to init the seed.  */
    unix_time_get(&unix_time);
    srand(unix_time);

    /* Initialize TLS.  */
    nx_secure_tls_initialize();

    sample_entry (&ip_0, &pool_0, &dns_0, unix_time_get);
}



static UINT dns_create()
{

UINT    status;
ULONG   dns_server_address[3];

    /* Create a DNS instance for the Client.  Note this function will create
       the DNS Client packet pool for creating DNS message packets intended
       for querying its DNS server. */
    status = nx_dns_create(&dns_0, &ip_0, (UCHAR *)"DNS Client");
    if (status)
    {
        return(status);
    }

    /* Is the DNS client configured for the host application to create the pecket pool? */
#ifdef NX_DNS_CLIENT_USER_CREATE_PACKET_POOL

    /* Yes, use the packet pool created above which has appropriate payload size
       for DNS messages. */
    status = nx_dns_packet_pool_set(&dns_0, ip_0.nx_ip_default_packet_pool);
    if (status)
    {
        nx_dns_delete(&dns_0);
        return(status);
    }
#endif /* NX_DNS_CLIENT_USER_CREATE_PACKET_POOL */

    dns_server_address[0] = g_dns_address;

    /* Add an IPv4 server address to the Client list. */
    status = nx_dns_server_add(&dns_0, dns_server_address[0]);
    if (status)
    {
        nx_dns_delete(&dns_0);
        return(status);
    }

    /* Output DNS Server address.  */
    printf("DNS Server address: %lu.%lu.%lu.%lu\r\n",
           (dns_server_address[0] >> 24),
           (dns_server_address[0] >> 16 & 0xFF),
           (dns_server_address[0] >> 8 & 0xFF),
           (dns_server_address[0] & 0xFF));

    return(NX_SUCCESS);
}

/* Sync up the local time. */
static UINT sntp_time_sync_internal(ULONG sntp_server_address)
{
  UINT status;
  UINT server_status;
  UINT i;

  /* Create the SNTP Client to run in broadcast mode.. */
  status = nx_sntp_client_create(&sntp_client_0, &ip_0, 0, &pool_0, NX_NULL, NX_NULL,
                                 NX_NULL /* no random_number_generator callback */);

  /* Check status. */
  if (status == NX_SUCCESS)
  {
    /* Use the IPv4 service to initialize the Client and set the IPv4 SNTP server. */
    status = nx_sntp_client_initialize_unicast(&sntp_client_0, sntp_server_address);

    /* Check status. */
    if (status != NX_SUCCESS)
    {
      nx_sntp_client_delete(&sntp_client_0);
      return (status);
    }

    /* Set local time to 0 */
    status = nx_sntp_client_set_local_time(&sntp_client_0, 0, 0);

    /* Check status. */
    if (status != NX_SUCCESS)
    {
      nx_sntp_client_delete(&sntp_client_0);
      return (status);
    }

    /* Run Unicast client */
    status = nx_sntp_client_run_unicast(&sntp_client_0);

    /* Check status. */
    if (status != NX_SUCCESS)
    {
      nx_sntp_client_stop(&sntp_client_0);
      nx_sntp_client_delete(&sntp_client_0);
      return (status);
    }

    /* Wait till updates are received */
    for (i = 0U; i < SAMPLE_SNTP_UPDATE_MAX; i++)
    {
      /* First verify we have a valid SNTP service running. */
      status = nx_sntp_client_receiving_updates(&sntp_client_0, &server_status);

      /* Check status. */
      if ((status == NX_SUCCESS) && (server_status == NX_TRUE))
      {
        /* Server status is good. Now get the Client local time. */
        ULONG sntp_seconds;
        ULONG sntp_fraction;
        ULONG system_time_in_second;

        /* Get the local time. */
        status = nx_sntp_client_get_local_time(&sntp_client_0, &sntp_seconds, &sntp_fraction, NX_NULL);

        /* Check status. */
        if (status != NX_SUCCESS)
        {
          continue;
        }

        /* Get the system time in second. */
        system_time_in_second = tx_time_get() / TX_TIMER_TICKS_PER_SECOND;

        /* Convert to Unix epoch and minus the current system time. */
        unix_time_base = (sntp_seconds - (system_time_in_second + SAMPLE_UNIX_TO_NTP_EPOCH_SECOND));

        /* Time sync successfully. */

        /* Stop and delete SNTP. */
        nx_sntp_client_stop(&sntp_client_0);
        nx_sntp_client_delete(&sntp_client_0);

        return (NX_SUCCESS);
      }

      /* Sleep.  */
      tx_thread_sleep(SAMPLE_SNTP_UPDATE_INTERVAL);
    }

    /* Time sync failed. - Return not success. */
    status = NX_NOT_SUCCESSFUL;
    /* Stop and delete SNTP. */
    nx_sntp_client_stop(&sntp_client_0);
    nx_sntp_client_delete(&sntp_client_0);
  }

  return (status);
}

/* Sync up the local time.  */
static UINT sntp_time_sync(void)
{
  UINT  status;
  ULONG gateway_address;
  ULONG sntp_server_address;

  /* Sync time by SNTP server array. */
  for (UINT i = 0U; i < SAMPLE_SNTP_SYNC_MAX; i++)
  {
    printf("SNTP Time Sync...%s\r\n", sntp_servers[sntp_server_index]);

    /* Make sure the network is still valid. */
    while (nx_ip_gateway_address_get(&ip_0, &gateway_address))
    {
      tx_thread_sleep(NX_IP_PERIODIC_RATE);
    }

    /* Look up SNTP Server address. */
    status = nx_dns_host_by_name_get(&dns_0, (UCHAR *)sntp_servers[sntp_server_index], &sntp_server_address,
                                     (5 * NX_IP_PERIODIC_RATE));

    /* Check status. */
    if (status == NX_SUCCESS)
    {
      /* Start SNTP to sync the local time. */
      status = sntp_time_sync_internal(sntp_server_address);

      /* Check status.  */
      if (status == NX_SUCCESS)
      {
        return (NX_SUCCESS);
      }
    }

    /* Switch SNTP server every time.  */
    sntp_server_index = (sntp_server_index + 1) % (sizeof(sntp_servers) / sizeof(sntp_servers[0]));
  }

  return (NX_NOT_SUCCESSFUL);
}

UINT unix_time_get(ULONG *unix_time)
{

    /* Return number of seconds since Unix Epoch (1/1/1970 00:00:00).  */
    *unix_time =  unix_time_base + (tx_time_get() / TX_TIMER_TICKS_PER_SECOND);

    return(NX_SUCCESS);
}

