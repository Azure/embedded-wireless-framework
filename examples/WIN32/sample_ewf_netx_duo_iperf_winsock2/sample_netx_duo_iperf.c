/* This is a small Iperf demo of the high-performance NetX Duo TCP/IP stack.  */

#include "ewf_adapter_winsock2.h" // Include first to force correct inclussion order for winsock2.h
#include "ewf_allocator_threadx.h"
#include "ewf_lib.h"
#include "ewf_middleware_netxduo.h"
#include "ewf_example.config.h"

#define SAMPLE_DHCP_DISABLE

#include   "tx_api.h"
#include   "nx_api.h"
#include   "nxd_dhcp_client.h"

/* Define demo stack size.   */
#define                 NX_PACKET_POOL_SIZE     ((1536 + sizeof(NX_PACKET)) * 60) 
#define                 DEMO_STACK_SIZE         2048
#define                 HTTP_STACK_SIZE         2048
#define                 IPERF_STACK_SIZE        2048 

ULONG g_ip_address = 0;
ULONG g_network_mask = 0;
ULONG g_gateway_address = 0;
ULONG g_dns_address = 0;


/* Define the ThreadX and NetX object control blocks...  */
TX_THREAD               thread_0;
NX_PACKET_POOL          pool_0;
NX_IP                   ip_0;
#ifndef SAMPLE_DHCP_DISABLE
NX_DHCP                 dhcp_client;
#endif
UCHAR                   *pointer;
UCHAR                   *http_stack;
UCHAR                   *iperf_stack;
#ifdef FEATURE_NX_IPV6
NXD_ADDRESS             ipv6_address;
#endif

static ULONG            pool_area[NX_PACKET_POOL_SIZE >> 2];
                      
/* Define the counters used in the demo application...  */
ULONG                   error_counter;

/* Define thread prototypes.  */
VOID    thread_0_entry(ULONG thread_input);
extern  VOID nx_iperf_entry(NX_PACKET_POOL *pool_ptr, NX_IP *ip_ptr, UCHAR* http_stack, ULONG http_stack_size, UCHAR *iperf_stack, ULONG iperf_stack_size);


int main(int argc, char ** argv)
{

    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();
}


/* Define what the initial system looks like.  */
void    tx_application_define(void *first_unused_memory)
{

UINT    status;

ewf_result result;

ewf_allocator* data_allocator_ptr = NULL;
ewf_adapter* adapter_ptr = NULL;

    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(data_allocator_ptr, data_allocator,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_COUNT,
        EWF_CONFIG_DATA_ALLOCATOR_BLOCK_SIZE);
    EWF_ADAPTER_WINSOCK2_STATIC_DECLARE(adapter_ptr, winsock2_adapter, data_allocator_ptr);

    // Start the adapter
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to start the adapter, ewf_result %d.\n", result);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_address(adapter_ptr, (uint32_t*)&g_ip_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 address: ewf_result %d.\n", result);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_netmask(adapter_ptr, (uint32_t*)&g_network_mask)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 netmask: ewf_result %d.\n", result);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_gateway(adapter_ptr, (uint32_t*)&g_gateway_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 gateway: ewf_result %d.\n", result);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_dns(adapter_ptr, (uint32_t*)&g_dns_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 DNS: ewf_result %d.\n", result);
        exit(result);
    }
    
    /* Setup the working pointer.  */
    pointer = (UCHAR *) first_unused_memory;

    /* Initialize the NetX system.  */
    nx_system_initialize();

    /* Create a packet pool.  */ 
    status = nx_packet_pool_create(&pool_0, "NetX Main Packet Pool", 
                                   1536, 
                                   pool_area, NX_PACKET_POOL_SIZE);
                
    /* Check for packet pool create errors.  */
    if (status)
        error_counter++;     
    
    /* Create an IP instance.  */
    status = nx_ip_create(&ip_0, "NetX IP Instance 0", 
                          g_ip_address, g_network_mask,
                          &pool_0, 
                          nx_driver_ewf_adapter,
                          pointer, 
                          2048, 
                          1);
    pointer =  pointer + 2048;
          
    /* Check for IP create errors.  */
    if (status)
        error_counter++;
    
    /* Save the adapter pointer in the IP instance */
    ip_0.nx_ip_reserved_ptr = adapter_ptr;

    /* Enable ARP and supply ARP cache memory for IP Instance 0.  */
    status =  nx_arp_enable(&ip_0, (void *) pointer, 1024);
    pointer = pointer + 1024;

    /* Check for ARP enable errors.  */
    if (status)
        error_counter++;

    /* Enable ICMP */
    status = nx_icmp_enable(&ip_0); 

    /* Check for ICMP enable errors.  */
    if(status)
        error_counter++;
    
    /* Enable UDP traffic.  */
    status =  nx_udp_enable(&ip_0);

    /* Check for UDP enable errors.  */
    if (status)
        error_counter++;

    /* Enable TCP traffic.  */
    status =  nx_tcp_enable(&ip_0); 

    /* Check for TCP enable errors.  */
    if (status)
        error_counter++;
    
    /* Create the main thread.  */
    tx_thread_create(&thread_0, "thread 0", thread_0_entry, 0,  
                     pointer, DEMO_STACK_SIZE, 
                     4, 4, TX_NO_TIME_SLICE, TX_AUTO_START); 
    pointer =  pointer + DEMO_STACK_SIZE;
    
#ifdef FEATURE_NX_IPV6
    /* Set up the IPv6 address here. */
    ipv6_address.nxd_ip_address.v6[3] = 0x3;
    ipv6_address.nxd_ip_address.v6[2] = 0x0;
    ipv6_address.nxd_ip_address.v6[1] = 0x0;
    ipv6_address.nxd_ip_address.v6[0] = 0xfe800000;
    ipv6_address.nxd_ip_version = NX_IP_VERSION_V6;

    /* Enable ICMPv6 services. */
    status = nxd_icmp_enable(&ip_0);
    if (status)
        error_counter++;

    /* Enable IPv6 services. */
    status = nxd_ipv6_enable(&ip_0);
    if (status)
        error_counter++;

    status = nxd_ipv6_address_set(&ip_0, 0, &ipv6_address, 10, NX_NULL);
    if (status)
        error_counter++;
#endif
}

/* Define the test threads.  */
void    thread_0_entry(ULONG thread_input)
{
ULONG   ip_address = 0;
ULONG   network_mask = 0;
ULONG   gateway_address = 0;

#ifndef SAMPLE_DHCP_DISABLE
    dhcp_wait();
#else
    nx_ip_gateway_address_set(&ip_0, g_gateway_address);
#endif

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

#ifdef FEATURE_NX_IPV6
    tx_thread_sleep(NX_IP_PERIODIC_RATE);
#endif

    /* Set the HTTP stack and IPerf stack.  */
    http_stack = pointer;
    pointer += HTTP_STACK_SIZE;   
    iperf_stack = pointer;
    pointer += IPERF_STACK_SIZE;

    /* Call entry function to start iperf test.  */
    nx_iperf_entry(&pool_0, &ip_0, http_stack, HTTP_STACK_SIZE, iperf_stack, IPERF_STACK_SIZE);
}

#ifndef SAMPLE_DHCP_DISABLE
static void dhcp_wait()
{
ULONG   actual_status;

    printf("DHCP In Progress...\r\n");

    /* Create the DHCP instance.  */
    nx_dhcp_create(&dhcp_client, &ip_0, "dhcp_client");

    /* Start the DHCP Client.  */
    nx_dhcp_start(&dhcp_client);
    
    /* Wait util address is solved. */
    nx_ip_status_check(&ip_0, NX_IP_ADDRESS_RESOLVED, &actual_status, NX_WAIT_FOREVER);
}
#endif /* SAMPLE_DHCP_DISABLE  */
