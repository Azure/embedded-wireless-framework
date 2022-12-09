/* This is a small Iperf demo of the high-performance NetX Duo TCP/IP stack.  */

#include   "tx_api.h"
#include   "nx_api.h"
#include   "nxd_dhcp_client.h"

/* Define demo stack size.   */
#define                 NX_PACKET_POOL_SIZE     ((1536 + sizeof(NX_PACKET)) * 60) 
#define                 DEMO_STACK_SIZE         2048
#define                 HTTP_STACK_SIZE         2048
#define                 IPERF_STACK_SIZE        2048 

#ifdef SAMPLE_DHCP_DISABLE
#ifndef SAMPLE_IPV4_ADDRESS
/*#define SAMPLE_IPV4_ADDRESS           IP_ADDRESS(192, 168, 100, 33)*/
#error "SYMBOL SAMPLE_IPV4_ADDRESS must be defined. This symbol specifies the IP address of device. "
#endif /* SAMPLE_IPV4_ADDRESS */

#ifndef SAMPLE_IPV4_MASK
/*#define SAMPLE_IPV4_MASK              0xFFFFFF00UL*/
#error "SYMBOL SAMPLE_IPV4_MASK must be defined. This symbol specifies the IP address mask of device. "
#endif /* SAMPLE_IPV4_MASK */

#ifndef SAMPLE_GATEWAY_ADDRESS
/*#define SAMPLE_GATEWAY_ADDRESS        IP_ADDRESS(192, 168, 100, 1)*/
#error "SYMBOL SAMPLE_GATEWAY_ADDRESS must be defined. This symbol specifies the gateway address for routing. "
#endif /* SAMPLE_GATEWAY_ADDRESS */

#ifndef SAMPLE_DNS_SERVER_ADDRESS
/*#define SAMPLE_DNS_SERVER_ADDRESS     IP_ADDRESS(192, 168, 100, 1)*/
#error "SYMBOL SAMPLE_DNS_SERVER_ADDRESS must be defined. This symbol specifies the dns server address for routing. "
#endif /* SAMPLE_DNS_SERVER_ADDRESS */
#else
#define SAMPLE_IPV4_ADDRESS             IP_ADDRESS(0, 0, 0, 0)
#define SAMPLE_IPV4_MASK                IP_ADDRESS(0, 0, 0, 0)
#endif /* SAMPLE_DHCP_DISABLE */

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
              
/* Include the platform IP driver. */
#ifdef NX_PCAP_SOURCE_NAME
#define nx_network_driver _nx_pcap_network_driver
#else
#define nx_network_driver nx_driver_x86
#endif
void nx_network_driver(struct NX_IP_DRIVER_STRUCT* driver_req);


int main(int argc, char ** argv)
{

    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();
}


/* Define what the initial system looks like.  */
void    tx_application_define(void *first_unused_memory)
{

UINT    status;
                             
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
                          SAMPLE_IPV4_ADDRESS, SAMPLE_IPV4_MASK,
                          &pool_0, 
                          nx_network_driver,
                          pointer, 
                          2048, 
                          1);
    pointer =  pointer + 2048;
          
    /* Check for IP create errors.  */
    if (status)
        error_counter++;
    
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
#ifndef SAMPLE_DHCP_DISABLE
UINT    status;
ULONG   actual_status;


    /* Create the DHCP instance.  */
    printf("DHCP In Progress...\n");

    nx_dhcp_create(&dhcp_client, &ip_0, "dhcp_client");

    /* Start the DHCP Client.  */
    nx_dhcp_start(&dhcp_client);
    
    /* Wait util address is solved. */
    status = nx_ip_status_check(&ip_0, NX_IP_ADDRESS_RESOLVED, &actual_status, 1000);
    
    if (status)
    {
        
        /* DHCP Failed...  no IP address! */
        printf("Can't resolve address\n");
        return;
    }
#endif

    /* Get IP address and gateway address. */
    nx_ip_address_get(&ip_0, &ip_address, &network_mask);

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