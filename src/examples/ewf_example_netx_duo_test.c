#include "tx_api.h"
#include "nx_api.h"
#include "nxd_dns.h"

#include "ewf_adapter.h"
#include "ewf_lib.h"

#include "ewf_example.config.h"

#include "ewf_middleware_netxduo.h"

/* Define user configurable symbols. */
#ifndef SAMPLE_IP_STACK_SIZE
#define SAMPLE_IP_STACK_SIZE            (2048)
#endif /* SAMPLE_IP_STACK_SIZE  */

#ifndef SAMPLE_IP_THREAD_PRIORITY
#define SAMPLE_IP_THREAD_PRIORITY       (2)
#endif /* SAMPLE_IP_THREAD_PRIORITY */

#ifndef SAMPLE_PACKET_COUNT
#define SAMPLE_PACKET_COUNT             (4)
#endif /* SAMPLE_PACKET_COUNT  */

#ifndef SAMPLE_PACKET_SIZE
#define SAMPLE_PACKET_SIZE              (1536)
#endif /* SAMPLE_PACKET_SIZE  */

#ifndef SAMPLE_POOL_SIZE
#define SAMPLE_POOL_SIZE                ((SAMPLE_PACKET_SIZE + sizeof(NX_PACKET)) * SAMPLE_PACKET_COUNT)
#endif /* SAMPLE_POOL_SIZE */

#ifndef SAMPLE_TEST_REPETITIONS
#define SAMPLE_TEST_REPETITIONS         (10)
#endif /* SAMPLE_TEST_REPETITIONS */

#ifdef NX_DNS_CACHE_ENABLE
#define DNS_LOCAL_CACHE_SIZE            (2048)
UCHAR dns_local_cache[DNS_LOCAL_CACHE_SIZE];
#endif

#define NX_PACKET_PAYLOAD               (1536)
#define NX_PACKET_POOL_SIZE             (4 * NX_PACKET_PAYLOAD)

/* Define the ThreadX and NetX object control blocks...  */
static NX_PACKET_POOL pool_0;
static NX_IP ip_0;
static NX_DNS dns_0;

/* Define the IP thread's stack area.  */
static ULONG ip_thread_stack[SAMPLE_IP_STACK_SIZE / sizeof(ULONG)];

/* Define packet pool for the demonstration.  */
static ULONG sample_pool[SAMPLE_POOL_SIZE / sizeof(ULONG)];
static ULONG sample_pool_size = sizeof(sample_pool);

/* TCP test - HTTP query variables */
//ULONG http_host_ip = IP_ADDRESS(20, 228, 124, 154); 
ULONG http_host_ip = IP_ADDRESS(23, 35, 229, 160);
//ULONG http_host_ip = IP_ADDRESS(92, 123, 229, 216);
UINT http_host_port = 80;
char http_message [] = "GET /index.html HTTP/1.1\r\nHost:www.microsoft.com\r\n\r\n";
ULONG http_message_length = sizeof(http_message)-1;

/* UDP test - DNS query variables */
#define MAX_RECORD_COUNT  20
ULONG record_buffer[50];
UINT record_count;
ULONG* ipv4_address_ptr[MAX_RECORD_COUNT];
UCHAR dns_packet_pool_buffer[NX_PACKET_POOL_SIZE];

ewf_result ewf_example_netx_duo_test(ewf_adapter* adapter_ptr)
{
    ewf_result result;

    ULONG ip_address = 0;
    ULONG network_mask = 0;
    ULONG gateway_address = 0;
    ULONG dns_address = 0;

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_address(adapter_ptr, (uint32_t*)&ip_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 address: ewf_result %d.\n", result);
        return EWF_RESULT_NOT_SUPPORTED;
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_netmask(adapter_ptr, (uint32_t*)&network_mask)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 netmask: ewf_result %d.\n", result);
        return EWF_RESULT_NOT_SUPPORTED;
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_gateway(adapter_ptr, (uint32_t*)&gateway_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 gateway: ewf_result %d.\n", result);
        return EWF_RESULT_NOT_SUPPORTED;
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_dns(adapter_ptr, (uint32_t*)&dns_address)))
    {
        EWF_LOG_ERROR("Failed to get the adapter IPv4 DNS: ewf_result %d.\n", result);
        return EWF_RESULT_NOT_SUPPORTED;
    }

    /* Output IP address and gateway address.  */
    EWF_LOG("\nIP address: %lu.%lu.%lu.%lu\r\n",
        (ip_address >> 24 & 0xFF),
        (ip_address >> 16 & 0xFF),
        (ip_address >> 8 & 0xFF),
        (ip_address & 0xFF));
    EWF_LOG("\nMask: %lu.%lu.%lu.%lu\r\n",
        (network_mask >> 24 & 0xFF),
        (network_mask >> 16 & 0xFF),
        (network_mask >> 8 & 0xFF),
        (network_mask & 0xFF));
    EWF_LOG("\nGateway: %lu.%lu.%lu.%lu\r\n",
        (gateway_address >> 24 & 0xFF),
        (gateway_address >> 16 & 0xFF),
        (gateway_address >> 8 & 0xFF),
        (gateway_address & 0xFF));
    EWF_LOG("\nDNS: %lu.%lu.%lu.%lu\r\n",
        (dns_address >> 24 & 0xFF),
        (dns_address >> 16 & 0xFF),
        (dns_address >> 8 & 0xFF),
        (dns_address & 0xFF));

    UINT i;
    UINT status;

    /* Initialize the NetX system.  */
    nx_system_initialize();

    /* Create a packet pool.  */
    status = nx_packet_pool_create(&pool_0,
                                   "NetX Main Packet Pool",
                                   SAMPLE_PACKET_SIZE,
                                   (UCHAR *)sample_pool , sample_pool_size);

    /* Check for pool creation error.  */
    if (status)
    {
        EWF_LOG_ERROR("nx_packet_pool_create fail: %u\r\n", status);
        return EWF_RESULT_NOT_SUPPORTED;
    }

    /* Create an IP instance.  */
    status = nx_ip_create(&ip_0,
                          "NetX IP Instance 0",
                          ip_address, network_mask,
                          &pool_0,
                          nx_driver_ewf_adapter,
                          ip_thread_stack, SAMPLE_IP_STACK_SIZE,
                          SAMPLE_IP_THREAD_PRIORITY);

    /* Check for IP create errors.  */
    if (status)
    {
        EWF_LOG_ERROR("nx_ip_create fail: %u\r\n", status);
        return EWF_RESULT_NOT_SUPPORTED;
    }

    /* Save the adapter pointer in the IP instance */
    ip_0.nx_ip_reserved_ptr = adapter_ptr;

    status = nx_ip_gateway_address_set(&ip_0, gateway_address);

    /* Check for gateway address set errors.  */
    if (status)
    {
        EWF_LOG_ERROR("Gateway address set failed.\r\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }

    /*************************************************************************
     *
     * TCP test
     *
     *************************************************************************/

    status = nx_tcp_enable(&ip_0);

    if (status)
    {
        EWF_LOG_ERROR("TCP enable failed.\r\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }

    for (i = 0; i < SAMPLE_TEST_REPETITIONS; ++i)
    {
      NX_TCP_SOCKET socket;

      status = nx_tcp_socket_create(
        &ip_0,
        &socket,
        "Socket",
        NX_IP_NORMAL, NX_DONT_FRAGMENT,
        0x80, 200, NX_NULL, NX_NULL);

        if (status)
        {
          EWF_LOG_ERROR("Socket creation failed\n");
        }
        else
        {
          EWF_LOG("[****][Socket created]\n");

          status = nx_tcp_client_socket_bind(&socket, NX_ANY_PORT, NX_WAIT_FOREVER);
          if (status)
          {
            EWF_LOG_ERROR("Failed to bind the socket\n");
          }
          else
          {
            EWF_LOG("[****][Socket bound]\n");

            status = nx_tcp_client_socket_connect(&socket, http_host_ip, http_host_port, NX_WAIT_FOREVER);

            if (status)
            {
              EWF_LOG_ERROR("Failed to connect\n");
            }
            else
            {
              EWF_LOG("[****][Connected]\n");

              NX_PACKET * packet_ptr;

              status = nx_packet_allocate(&pool_0, &packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);
              if (status)
              {
                EWF_LOG_ERROR("Failed to allocate the packet\n");
              }
              else
              {
                status = nx_packet_data_append(packet_ptr, http_message, http_message_length, &pool_0, NX_WAIT_FOREVER);
                if (status)
                {
                  EWF_LOG_ERROR("Failed to append data to the packet\n");
                }
                else
                {
                  EWF_LOG("[****][Data appended to the packet]\n");

                  status = nx_tcp_socket_send(&socket, packet_ptr, NX_WAIT_FOREVER);
                  if (status)
                  {
                    EWF_LOG_ERROR("Failed to send the packet\n");

                    status = nx_packet_release(packet_ptr);
                    if (status)
                    {
                      EWF_LOG_ERROR("Failed to release the packet\n");
                    }
                    else
                    {
                      EWF_LOG("[****][Packet released]\n");
                    }
                  }
                  else
                  {
                    EWF_LOG("[****][Data sent]\n");

                    status = nx_tcp_socket_receive(&socket, &packet_ptr, NX_WAIT_FOREVER);
                    if (status)
                    {
                      EWF_LOG_ERROR("Failed to receive a packet\n");
                    }
                    else
                    {
                      EWF_LOG("[****][Packet received]\n");

                      ULONG packet_length;
                      status = nx_packet_length_get(packet_ptr, &packet_length);

                      EWF_LOG("[****][%lu bytes received]\n", packet_length);

                      status = nx_packet_release(packet_ptr);
                      if (status)
                      {
                        EWF_LOG_ERROR("Failed to release the packet\n");
                      }
                      else
                      {
                        EWF_LOG("[****][Packet released]\n");
                      }
                    }
                  }
                }
              }

              status = nx_tcp_socket_disconnect(&socket, NX_WAIT_FOREVER);
              if (status)
              {
                EWF_LOG_ERROR("Failed to disconnect\n");
              }
              else
              {
                EWF_LOG("[****][Disconnected]\n");
              }
            }

            status = nx_tcp_client_socket_unbind(&socket);
            if (status)
            {
              EWF_LOG_ERROR("Failed to unbind the socket\n");
            }
            else
            {
              EWF_LOG("[****][Socket unbound]\n");
            }
          }

          status = nx_tcp_socket_delete(&socket);
          if (status)
          {
            EWF_LOG_ERROR("Failed to delete the socket\n");
          }
          else
          {
            EWF_LOG("[****][Socket deleted]\n");
          }
        }

      tx_thread_sleep(1);
    }

    /*************************************************************************
     *
     * UDP test, by using DNS
     *
     *************************************************************************/

    status = nx_udp_enable(&ip_0);
    if (status)
    {
        EWF_LOG_ERROR("UDP enable failed.\r\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }

    NX_PACKET_POOL client_pool;
    status = nx_packet_pool_create(&client_pool, "DNS Client Packet Pool", NX_DNS_PACKET_PAYLOAD, dns_packet_pool_buffer, NX_DNS_PACKET_POOL_SIZE);
    if (status)
    {
        EWF_LOG_ERROR("Failed to create the DNS packet pool.\r\n");
        return EWF_RESULT_NOT_SUPPORTED;
    }

    status = nx_dns_create(&dns_0, &ip_0, (UCHAR*) "My DNS");
    if (status)
    {
        EWF_LOG_ERROR("DNS create failed.\r\n");
    }
    else
    {
        status = nx_dns_packet_pool_set(&dns_0, &client_pool);
        if (status)
        {
            EWF_LOG_ERROR("Failed to set the DNS packet pool.\r\n");
        }

        status = nx_dns_server_add(&dns_0, IP_ADDRESS(8, 8, 8, 8));
        if (status)
        {
            EWF_LOG_ERROR("Failed to add a DNS server.\r\n");
        }
        else
        {

#ifdef NX_DNS_CACHE_ENABLE
            /* Initialize the cache. */
            status = nx_dns_cache_initialize(&dns_0, dns_local_cache, DNS_LOCAL_CACHE_SIZE);
            if (status)
            {
                EWF_LOG_ERROR("Failed to initialize the local DNS cache.\r\n");
            }
            else
#endif
            {
                /* Request the IPv4 address for the specified host. */
                status = nx_dns_ipv4_address_by_name_get(
                    &dns_0,
                    (UCHAR*)"www.azure.com",
                    record_buffer,
                    sizeof(record_buffer), &record_count,
                    500);

                /* Check for DNS query error. */
                if (status != NX_SUCCESS)
                {
                    EWF_LOG_ERROR("nx_dns_ipv4_address_by_name_get failed.\r\n");
                }
                else
                {
                    EWF_LOG("record_count = %d \n", record_count);

                    /* Get the IPv4 addresses of host. */
                    for (i = 0; i < record_count; i++)
                    {
                        ipv4_address_ptr[i] = (ULONG*)(record_buffer + i * sizeof(ULONG));
                        EWF_LOG("record %u: IP address: %u.%u.%u.%u\n",
                            i,
                            (unsigned) (*ipv4_address_ptr[i] >> 24 & 0xFF),
                            (unsigned) (*ipv4_address_ptr[i] >> 16 & 0xFF),
                            (unsigned) (*ipv4_address_ptr[i] >> 8 & 0xFF),
                            (unsigned) (*ipv4_address_ptr[i] & 0xFF));
                    }
                }
            }
        }

        status = nx_dns_delete(&dns_0);
        if (status)
        {
            EWF_LOG_ERROR("DNS delete failed.\r\n");
        }
    }

    return EWF_RESULT_OK;
}
