#include "tx_api.h"
#include "nx_api.h"

#include "ewf_adapter.h"
#include "ewf_lib.h"

#include "ewf_netxduo_ppp.h"

#include "ewf_example_netx_duo_ppp_test.h"
#include "ewf_example.config.h"

/* Define user configurable symbols. */
#ifndef SAMPLE_PACKET_COUNT
#define SAMPLE_PACKET_COUNT             (30)
#endif /* SAMPLE_PACKET_COUNT  */

#ifndef SAMPLE_PACKET_SIZE
#define SAMPLE_PACKET_SIZE              (1536)
#endif /* SAMPLE_PACKET_SIZE  */

#ifndef SAMPLE_POOL_SIZE
#define SAMPLE_POOL_SIZE                ((SAMPLE_PACKET_SIZE + sizeof(NX_PACKET)) * SAMPLE_PACKET_COUNT)
#endif /* SAMPLE_POOL_SIZE */

#ifndef SAMPLE_IP_STACK_SIZE
#define SAMPLE_IP_STACK_SIZE            (2048)
#endif /* SAMPLE_IP_STACK_SIZE  */

#ifndef SAMPLE_PPP_THREAD_PRIORITY
#define SAMPLE_PPP_THREAD_PRIORITY       (3)
#endif /* SAMPLE_IP_THREAD_PRIORITY */

/* Define the IP thread's stack area.  */
static ULONG ip_thread_stack[SAMPLE_IP_STACK_SIZE / sizeof(ULONG)];

/* Define the PPP thread stack */
uint8_t ppp_0_stack[4096];

/* Define the ARP cache area.  */
ULONG arp_space_area[512 / sizeof(ULONG)];

/* Define packet pool for the demonstration.  */
static ULONG sample_pool[SAMPLE_POOL_SIZE / sizeof(ULONG)];
static ULONG sample_pool_size = sizeof(sample_pool);

/* Function declaration */
ewf_result ewf_example_netx_duo_ppp_test(ewf_adapter* adapter_ptr);
ewf_result ewf_example_ppp_mode_netx_duo_test(NX_IP* ip_ptr);
ewf_result ewf_example_test_netx_duo_icmp_ping(NX_IP* ip_ptr);
ewf_result ewf_example_test_netx_duo_udp_echo(NX_IP* ip_ptr);
ewf_result ewf_example_test_netx_duo_http(NX_IP* ip_ptr);

/* Define the NetX object control blocks...  */
NX_PACKET_POOL          pool_0;
NX_IP                   ip_0;
NX_PPP                  ppp_0;

void invalid_packet_handler(NX_PACKET* packet_ptr)
{

    nx_packet_release(packet_ptr);

}

/* Intalize the PPP config */
ewf_netxduo_ppp_cfg ppp_cfg =
{
    .ppp_ptr = &ppp_0,
    .ppp_thread_stack_ptr = &ppp_0_stack[0],
    .ppp_thread_stack_size = sizeof(ppp_0_stack),
    .ppp_thread_priority = SAMPLE_PPP_THREAD_PRIORITY,
    .ppp_invalid_packet_callback = invalid_packet_handler,
    .ip_ptr = &ip_0,
    .ip_thread_stack_ptr = (uint8_t*)&ip_thread_stack[0],
    .ip_thread_stack_size = sizeof(ip_thread_stack),
    .pool_ptr = &pool_0
};

ewf_result ewf_example_netx_duo_ppp_test(ewf_adapter* adapter_ptr)
{

    ewf_result result = EWF_RESULT_OK;
    UINT status;

    /* Enter Data Mode.  */
    if (ewf_result_failed(result = ewf_adapter_data_mode_enter(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG_ERROR("Failed Enter data mode: ewf_result %d.\n", result);
        exit(result);
    }

    /* Create a packet pool.  */
    status = nx_packet_pool_create(&pool_0,
        "NetX Main Packet Pool",
        SAMPLE_PACKET_SIZE,
        (UCHAR*)sample_pool, sample_pool_size);

    /* Check for pool creation error.  */
    if (status)
    {
        EWF_LOG_ERROR("Failed to create NetX packet pool fail: %u\r\n", status);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_netxduo_ppp_config(adapter_ptr, &ppp_cfg)))
    {
        EWF_LOG_ERROR("Failed configure PPP: ewf_result %d.\n", result);
        exit(result);
    }

    /* Link is fully up and operational. All NetX activities are now available.
       Enable NetX services that your application would need. 
       Below services (ARP, TCP, UDP, ICMP) are enabled for demo purposes only.*/

    /* Enable ARP and supply ARP cache memory for IP Instance 0.  */
    status = nx_arp_enable(&ip_0, (void*)arp_space_area, sizeof(arp_space_area));
    /* Check for ARP enable errors.  */
    if (status)
    {
        EWF_LOG_ERROR("Failed to enable ARP, status: %d.\n", status);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    /* Enable TCP traffic.  */
    status = nx_tcp_enable(&ip_0);
    if (status)
    {
        EWF_LOG_ERROR("Failed to enable TCP, status: %d.\n", status);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    /* Enable ICMP.  */
    status = nx_icmp_enable(&ip_0);
    if (status)
    {
        EWF_LOG_ERROR("Failed to enable ICMP, status: %d.\n", status);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    /* Enable UDP traffic.  */
    status = nx_udp_enable(&ip_0);
    if (status)
    {
        EWF_LOG_ERROR("Failed to enable UDP, status: %d.\n", status);
        return EWF_RESULT_CONNECTION_FAILED;
    }

    ewf_example_ppp_mode_netx_duo_test(&ip_0);

    /* Exit Data Mode. */
    if (ewf_result_failed(result = ewf_adapter_data_mode_exit(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to exit data mode: ewf_result %d.\n", result);
        exit(result);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_example_ppp_mode_netx_duo_test(NX_IP* ip_ptr)
{
    ewf_result result = EWF_RESULT_OK;

    result = ewf_example_test_netx_duo_icmp_ping(ip_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("NetX-Duo ping test failed, result %d\n", result);
    }

#if 0
    result = ewf_example_test_netx_duo_udp_echo(ip_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("NetX-Duo UDP echo test failed, result %d\n", result);
    }
#endif

    result = ewf_example_test_netx_duo_http(ip_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("NetX-Duo HTTP test failed, result %d\n", result);
    }

    return EWF_RESULT_OK;
}
ewf_result ewf_example_test_netx_duo_icmp_ping(NX_IP* ip_ptr)
{
    ULONG ipv4_address = IP_ADDRESS(8, 8, 8, 8);
    uint8_t counter = 0;
    uint8_t error_count = 0;
    NX_PACKET* response = NULL;
    UINT status = 0;
    while (counter < 5)
    {
        UINT ping_status = nx_icmp_ping(ip_ptr, ipv4_address, "!!!!!", 5, &response, 5 * NX_IP_PERIODIC_RATE);
        if (NX_SUCCESS == ping_status)
        {
            EWF_LOG("ICMP ping success, counter: %d\n", counter);
        }
        else
        {
            EWF_LOG("ICMP ping failed, counter: %d\n", counter);
        }

        ++counter;
        /* Release the packet once the response is received and get ready for the next packet */
        status = nx_packet_release(response);

        if (NX_SUCCESS == status)
        {
            continue;
        }
        else
        {
            error_count++;
        }
    }
    return EWF_RESULT_OK;
}

ewf_result ewf_example_test_netx_duo_udp_echo(NX_IP* ip_ptr)
{
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][                      UDP ECHO Test                      ][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");

    UINT i;
    UINT status;

    for (i = 0; i < 5; ++i)
    {
        EWF_LOG("[****][Creating a socket...]\n");
        NX_UDP_SOCKET socket;
        status = nx_udp_socket_create(
            ip_ptr,
            &socket,
            "Socket",
            NX_IP_NORMAL, NX_DONT_FRAGMENT,
            0x80, 200);

        if (status)
        {
            EWF_LOG_ERROR("Socket creation failed\n");
        }
        else
        {
            EWF_LOG("[****][Socket created]\n");

            EWF_LOG("[****][Binding a socket...]\n");
            status = nx_udp_socket_bind(&socket, NX_ANY_PORT, NX_WAIT_FOREVER);
            if (status)
            {
                EWF_LOG_ERROR("Failed to bind the socket\n");
            }
            else
            {
                EWF_LOG("[****][Socket bound]\n");

                NX_PACKET* packet_ptr;

                EWF_LOG("[****][Allocating a packet...]\n");
                status = nx_packet_allocate(&pool_0, &packet_ptr, NX_UDP_PACKET, NX_WAIT_FOREVER);
                if (status)
                {
                    EWF_LOG_ERROR("Failed to allocate the packet\n");
                }
                else
                {
                    EWF_LOG("[****][Appending %d bytes to the packet...]\n", ewf_example_test_netx_duo_udp_echo_message_length);
                    status = nx_packet_data_append(
                        packet_ptr,
                        ewf_example_test_netx_duo_udp_echo_message,
                        ewf_example_test_netx_duo_udp_echo_message_length,
                        &pool_0,
                        NX_WAIT_FOREVER);
                    if (status)
                    {
                        EWF_LOG_ERROR("Failed to append data to the packet\n");
                    }
                    else
                    {
                        EWF_LOG("[****][Data appended to the packet]\n");

                        EWF_LOG("[****][Sending...]\n");
                        status = nx_udp_socket_send(
                            &socket,
                            packet_ptr,
                            ewf_example_test_netx_duo_udp_echo_server_ip,
                            ewf_example_test_netx_duo_udp_echo_server_port);
                        if (status)
                        {
                            EWF_LOG_ERROR("Failed to send the packet\n");

                            EWF_LOG("[****][Releasing the packet after a send error...]\n");
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

                            EWF_LOG("[****][Receiving...]\n");
                            status = nx_udp_socket_receive(&socket, &packet_ptr, 5 * NX_IP_PERIODIC_RATE);
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

                                EWF_LOG("[****][Releasing the received packet...]\n");
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

                EWF_LOG("[****][Unbinding the socket...]\n");
                status = nx_udp_socket_unbind(&socket);
                if (status)
                {
                    EWF_LOG_ERROR("Failed to unbind the socket\n");
                }
                else
                {
                    EWF_LOG("[****][Socket unbound]\n");
                }
            }

            EWF_LOG("[****][Deleting the socket...]\n");
            status = nx_udp_socket_delete(&socket);
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

    return EWF_RESULT_OK;
}

ewf_result ewf_example_test_netx_duo_http(NX_IP* ip_ptr)
{
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][                      NetX Duo HTTP Test                 ][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");
    EWF_LOG("[****][---------------------------------------------------------][****]\n");

    UINT i;
    UINT status;

    for (i = 0; i < 5; ++i)
    {
        NX_TCP_SOCKET socket;
        status = nx_tcp_socket_create(
            ip_ptr,
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

                status = nx_tcp_client_socket_connect(&socket, http_server_ip, http_server_port, NX_WAIT_FOREVER);
                if (status)
                {
                    EWF_LOG_ERROR("Failed to connect\n");
                }
                else
                {
                    EWF_LOG("[****][Connected]\n");

                    NX_PACKET* packet_ptr;

                    status = nx_packet_allocate(&pool_0, &packet_ptr, NX_TCP_PACKET, NX_WAIT_FOREVER);
                    if (status)
                    {
                        EWF_LOG_ERROR("Failed to allocate the packet\n");
                    }
                    else
                    {
                        EWF_LOG("[****][Appending %lu bytes to the packet...]\n", http_message_length);
                        status = nx_packet_data_append(packet_ptr, http_request, http_message_length, &pool_0, NX_WAIT_FOREVER);
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

                                EWF_LOG("[****][Receiving...]\n");
                                while (!(status = nx_tcp_socket_receive(&socket, &packet_ptr, 5 * NX_IP_PERIODIC_RATE)))
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
                    EWF_LOG("[****][No further packets recieved]\n");
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

    return EWF_RESULT_OK;
}

