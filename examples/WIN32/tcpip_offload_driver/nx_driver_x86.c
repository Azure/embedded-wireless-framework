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
/** NetX Component                                                        */
/**                                                                       */
/**   Shim layer driver for X86                                           */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

/* Indicate that driver source is being compiled.  */

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#define CLOSE(s)    closesocket(s)
#else
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h>

#define SOCKET      int
#define CLOSE(s)    close(s)
#endif

#include "nx_api.h"

#define NX_DRIVER_STATE_NOT_INITIALIZED         1
#define NX_DRIVER_STATE_INITIALIZE_FAILED       2
#define NX_DRIVER_STATE_INITIALIZED             3
#define NX_DRIVER_STATE_LINK_ENABLED            4

#ifndef NX_ENABLE_TCPIP_OFFLOAD
#error "NX_ENABLE_TCPIP_OFFLOAD must be defined to use this driver"
#endif /* NX_ENABLE_TCPIP_OFFLOAD */

#ifndef NX_DRIVER_IP_MTU
#define NX_DRIVER_IP_MTU                        1500
#endif /* NX_DRIVER_IP_MTU */

#ifndef NX_DRIVER_RECEIVE_QUEUE_SIZE
#define NX_DRIVER_RECEIVE_QUEUE_SIZE            10
#endif /* NX_DRIVER_RECEIVE_QUEUE_SIZE */

#ifndef NX_DRIVER_STACK_SIZE
#define NX_DRIVER_STACK_SIZE                    1024
#endif /* NX_DRIVER_STACK_SIZE  */

/* Interval to receive packets when there is no packet. The default value is 100 ticks which is 1s.  */
#ifndef NX_DRIVER_THREAD_INTERVAL
#define NX_DRIVER_THREAD_INTERVAL               1
#endif /* NX_DRIVER_THREAD_INTERVAL */

/* Define the maximum sockets at the same time.  */
#ifndef NX_DRIVER_SOCKETS_MAXIMUM
#define NX_DRIVER_SOCKETS_MAXIMUM               16
#endif

/* Define maximum server pending connections.  */
#ifndef NX_DRIVER_SERVER_LISTEN_COUNT
#define NX_DRIVER_SERVER_LISTEN_COUNT           5
#endif

#define NX_DRIVER_CAPABILITY                    (NX_INTERFACE_CAPABILITY_TCPIP_OFFLOAD)


/* Define basic netword driver information typedef.  */

typedef struct NX_DRIVER_INFORMATION_STRUCT
{

    /* NetX IP instance that this driver is attached to.  */
    NX_IP               *nx_driver_information_ip_ptr;

    /* Driver's current states.  */
    ULONG               nx_driver_information_states;

    /* Packet pool used for receiving packets. */
    NX_PACKET_POOL      *nx_driver_information_packet_pool_ptr;

    /* Define the driver interface association.  */
    NX_INTERFACE        *nx_driver_information_interface;

} NX_DRIVER_INFORMATION;


/* Define socket structure for hardware TCP/IP.  */

typedef struct NX_DRIVER_SOCKET_STRUCT
{
    VOID                *socket_ptr;
    SOCKET               socket_fd;
    UCHAR                protocol;
    UCHAR                tcp_connected;
    UCHAR                is_client;
    ULONG                local_ip;
    ULONG                remote_ip;
    USHORT               local_port;
    USHORT               remote_port;
} NX_DRIVER_SOCKET;

static NX_DRIVER_INFORMATION nx_driver_information;
static NX_DRIVER_SOCKET nx_driver_sockets[NX_DRIVER_SOCKETS_MAXIMUM];
static TX_THREAD nx_driver_thread;
static UCHAR nx_driver_thread_stack[NX_DRIVER_STACK_SIZE];

/* Define the routines for processing each driver entry request.  The contents of these routines will change with
   each driver. However, the main driver entry function will not change, except for the entry function name.  */

static VOID         _nx_driver_interface_attach(NX_IP_DRIVER *driver_req_ptr);
static VOID         _nx_driver_initialize(NX_IP_DRIVER *driver_req_ptr);
static VOID         _nx_driver_enable(NX_IP_DRIVER *driver_req_ptr);
static VOID         _nx_driver_disable(NX_IP_DRIVER *driver_req_ptr);
static VOID         _nx_driver_multicast_join(NX_IP_DRIVER *driver_req_ptr);
static VOID         _nx_driver_multicast_leave(NX_IP_DRIVER *driver_req_ptr);
static VOID         _nx_driver_get_status(NX_IP_DRIVER *driver_req_ptr);
#ifdef NX_ENABLE_INTERFACE_CAPABILITY
static VOID         _nx_driver_capability_get(NX_IP_DRIVER *driver_req_ptr);
static VOID         _nx_driver_capability_set(NX_IP_DRIVER *driver_req_ptr);
#endif /* NX_ENABLE_INTERFACE_CAPABILITY */
static VOID         _nx_driver_deferred_processing(NX_IP_DRIVER *driver_req_ptr);
static VOID         _nx_driver_thread_entry(ULONG thread_input);
static UINT         _nx_driver_tcpip_handler(struct NX_IP_STRUCT *ip_ptr,
                                             struct NX_INTERFACE_STRUCT *interface_ptr,
                                             VOID *socket_ptr, UINT operation, NX_PACKET *packet_ptr,
                                             NXD_ADDRESS *local_ip, NXD_ADDRESS *remote_ip,
                                             UINT local_port, UINT *remote_port, UINT wait_option);

/* Define the prototypes for the hardware implementation of this driver. The contents of these routines are
   driver-specific.  */

static UINT         _nx_driver_hardware_initialize(NX_IP_DRIVER *driver_req_ptr);
static UINT         _nx_driver_hardware_enable(NX_IP_DRIVER *driver_req_ptr);
static UINT         _nx_driver_hardware_disable(NX_IP_DRIVER *driver_req_ptr);
static UINT         _nx_driver_hardware_get_status(NX_IP_DRIVER *driver_req_ptr);
#ifdef NX_ENABLE_INTERFACE_CAPABILITY
static UINT         _nx_driver_hardware_capability_set(NX_IP_DRIVER *driver_req_ptr);
#endif /* NX_ENABLE_INTERFACE_CAPABILITY */


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    nx_driver_x86                                     x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This is the entry point of the NetX Driver. This driver             */
/*    function is responsible for initializing the network controller,    */
/*    enabling or disabling the controller as need, preparing             */
/*    a packet for transmission, and getting status information.          */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        The driver request from the   */
/*                                            IP layer.                   */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _nx_driver_interface_attach           Process attach request        */
/*    _nx_driver_initialize                 Process initialize request    */
/*    _nx_driver_enable                     Process link enable request   */
/*    _nx_driver_disable                    Process link disable request  */
/*    _nx_driver_multicast_join             Process multicast join request*/
/*    _nx_driver_multicast_leave            Process multicast leave req   */
/*    _nx_driver_get_status                 Process get status request    */
/*    _nx_driver_deferred_processing        Drive deferred processing     */
/*    _nx_driver_capability_get             Get interface capability      */
/*    _nx_driver_capability_set             Set interface capability      */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    IP layer                                                            */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
VOID  nx_driver_x86(NX_IP_DRIVER *driver_req_ptr)
{

    /* Default to successful return.  */
    driver_req_ptr -> nx_ip_driver_status =  NX_SUCCESS;

    /* Process according to the driver request type in the IP control
       block.  */
    switch (driver_req_ptr -> nx_ip_driver_command)
    {

    case NX_LINK_INTERFACE_ATTACH:
    {
        /* Process link interface attach requests.  */
        _nx_driver_interface_attach(driver_req_ptr);
        break;
    }

    case NX_LINK_INITIALIZE:
    {

        /* Process link initialize requests.  */
        _nx_driver_initialize(driver_req_ptr);
        break;
    }

    case NX_LINK_ENABLE:
    {

        /* Process link enable requests.  */
        _nx_driver_enable(driver_req_ptr);
        break;
    }

    case NX_LINK_DISABLE:
    {

        /* Process link disable requests.  */
        _nx_driver_disable(driver_req_ptr);
        break;
    }


    case NX_LINK_ARP_SEND:
    case NX_LINK_ARP_RESPONSE_SEND:
    case NX_LINK_PACKET_BROADCAST:
    case NX_LINK_RARP_SEND:
    case NX_LINK_PACKET_SEND:
    {

        /* Default to successful return.  */
        driver_req_ptr -> nx_ip_driver_status = NX_NOT_SUCCESSFUL;
        nx_packet_transmit_release(driver_req_ptr -> nx_ip_driver_packet);
        break;
    }


    case NX_LINK_MULTICAST_JOIN:
    {

        /* Process multicast join requests.  */
        _nx_driver_multicast_join(driver_req_ptr);
        break;
    }


    case NX_LINK_MULTICAST_LEAVE:
    {

        /* Process multicast leave requests.  */
        _nx_driver_multicast_leave(driver_req_ptr);
        break;
    }

    case NX_LINK_GET_STATUS:
    {

        /* Process get status requests.  */
        _nx_driver_get_status(driver_req_ptr);
        break;
    }

    case NX_LINK_DEFERRED_PROCESSING:
    {

        /* Process driver deferred requests.  */

        /* Process a device driver function on behave of the IP thread. */
        _nx_driver_deferred_processing(driver_req_ptr);

        break;
    }

#ifdef NX_ENABLE_INTERFACE_CAPABILITY
    case NX_INTERFACE_CAPABILITY_GET:
    {

        /* Process get capability requests.  */
        _nx_driver_capability_get(driver_req_ptr);
        break;
    }

    case NX_INTERFACE_CAPABILITY_SET:
    {

        /* Process set capability requests.  */
        _nx_driver_capability_set(driver_req_ptr);
        break;
    }
#endif /* NX_ENABLE_INTERFACE_CAPABILITY */

    default:


        /* Invalid driver request.  */

        /* Return the unhandled command status.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_UNHANDLED_COMMAND;

        /* Default to successful return.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_NOT_SUCCESSFUL;
    }
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_interface_attach                       x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the interface attach request.              */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_interface_attach(NX_IP_DRIVER *driver_req_ptr)
{
#ifdef NX_ENABLE_INTERFACE_CAPABILITY
    driver_req_ptr -> nx_ip_driver_interface -> nx_interface_capability_flag = NX_DRIVER_CAPABILITY;
#endif /* NX_ENABLE_INTERFACE_CAPABILITY */

    /* Return successful status.  */
    driver_req_ptr -> nx_ip_driver_status =  NX_SUCCESS;
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_initialize                             x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the initialize request.  The processing    */
/*    in this function is generic. All ethernet controller logic is to    */
/*    be placed in _nx_driver_hardware_initialize.                        */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _nx_driver_hardware_initialize        Process initialize request    */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_initialize(NX_IP_DRIVER *driver_req_ptr)
{

NX_IP        *ip_ptr;
NX_INTERFACE *interface_ptr;
UINT          status;

    /* Setup the driver state to not initialized.  */
    nx_driver_information.nx_driver_information_states = NX_DRIVER_STATE_NOT_INITIALIZED;

    /* Setup the IP pointer from the driver request.  */
    ip_ptr =  driver_req_ptr -> nx_ip_driver_ptr;

    /* Setup interface pointer.  */
    interface_ptr = driver_req_ptr -> nx_ip_driver_interface;

    /* Initialize the driver's information structure.  */

    /* Default IP pointer to NULL.  */
    nx_driver_information.nx_driver_information_ip_ptr = NX_NULL;

    /* Setup the default packet pool for the driver's received packets.  */
    nx_driver_information.nx_driver_information_packet_pool_ptr = ip_ptr -> nx_ip_default_packet_pool;

    /* Call the hardware-specific ethernet controller initialization.  */
    status =  _nx_driver_hardware_initialize(driver_req_ptr);

    /* Determine if the request was successful.  */
    if (status == NX_SUCCESS)
    {

        /* Successful hardware initialization.  */

        /* Setup driver information to point to IP pointer.  */
        nx_driver_information.nx_driver_information_ip_ptr = ip_ptr;
        nx_driver_information.nx_driver_information_interface = interface_ptr;

        /* Setup the link maximum transfer unit. */
        interface_ptr -> nx_interface_ip_mtu_size = NX_DRIVER_IP_MTU;

        /* Setup the physical address of this IP instance.  */
        /* TODO: Use WIFI_GetMAC_Address() to set the real value.  */
        interface_ptr -> nx_interface_physical_address_msw = 0;
        interface_ptr -> nx_interface_physical_address_lsw = 0;

        /* Indicate to the IP software that IP to physical mapping
           is required.  */
        interface_ptr -> nx_interface_address_mapping_needed =  NX_FALSE;

        /* Move the driver's state to initialized.  */
        nx_driver_information.nx_driver_information_states = NX_DRIVER_STATE_INITIALIZED;

        /* Indicate successful initialize.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_SUCCESS;
    }
    else
    {

        /* Initialization failed.  Indicate that the request failed.  */
        driver_req_ptr -> nx_ip_driver_status =   NX_NOT_SUCCESSFUL;
    }
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_enable                                 x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the initialize request. The processing     */
/*    in this function is generic. All ethernet controller logic is to    */
/*    be placed in _nx_driver_hardware_enable.                            */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _nx_driver_hardware_enable            Process enable request        */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_enable(NX_IP_DRIVER *driver_req_ptr)
{

UINT            status;

    /* See if we can honor the NX_LINK_ENABLE request.  */
    if (nx_driver_information.nx_driver_information_states < NX_DRIVER_STATE_INITIALIZED)
    {

        /* Mark the request as not successful.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_NOT_SUCCESSFUL;
        return;
    }

    /* Check if it is enabled by someone already */
    if (nx_driver_information.nx_driver_information_states >=  NX_DRIVER_STATE_LINK_ENABLED)
    {

        /* Yes, the request has already been made.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_ALREADY_ENABLED;
        return;
    }

    /* Call hardware specific enable.  */
    status =  _nx_driver_hardware_enable(driver_req_ptr);

    /* Was the hardware enable successful?  */
    if (status == NX_SUCCESS)
    {

        /* Update the driver state to link enabled.  */
        nx_driver_information.nx_driver_information_states = NX_DRIVER_STATE_LINK_ENABLED;

        /* Mark request as successful.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_SUCCESS;

        /* Mark the IP interface as link up.  */
        driver_req_ptr -> nx_ip_driver_interface -> nx_interface_link_up =  NX_TRUE;

        /* Set TCP/IP callback function.  */
        driver_req_ptr -> nx_ip_driver_interface -> nx_interface_tcpip_offload_handler = _nx_driver_tcpip_handler;
    }
    else
    {

        /* Enable failed.  Indicate that the request failed.  */
        driver_req_ptr -> nx_ip_driver_status =   NX_NOT_SUCCESSFUL;
    }
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_disable                                x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the disable request. The processing        */
/*    in this function is generic. All ethernet controller logic is to    */
/*    be placed in _nx_driver_hardware_disable.                           */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _nx_driver_hardware_disable           Process disable request       */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_disable(NX_IP_DRIVER *driver_req_ptr)
{

UINT            status;

    /* Check if the link is enabled.  */
    if (nx_driver_information.nx_driver_information_states !=  NX_DRIVER_STATE_LINK_ENABLED)
    {

        /* The link is not enabled, so just return an error.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_NOT_SUCCESSFUL;
        return;
    }

    /* Call hardware specific disable.  */
    status =  _nx_driver_hardware_disable(driver_req_ptr);

    /* Was the hardware disable successful?  */
    if (status == NX_SUCCESS)
    {

        /* Mark the IP interface as link down.  */
        driver_req_ptr -> nx_ip_driver_interface -> nx_interface_link_up =  NX_FALSE;

        /* Update the driver state back to initialized.  */
        nx_driver_information.nx_driver_information_states =  NX_DRIVER_STATE_INITIALIZED;

        /* Mark request as successful.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_SUCCESS;

        /* Clear the TCP/IP callback function.  */
        driver_req_ptr -> nx_ip_driver_interface -> nx_interface_tcpip_offload_handler = NX_NULL;
    }
    else
    {

        /* Disable failed, return an error.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_NOT_SUCCESSFUL;
    }
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_multicast_join                         x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the multicast join request. The processing */
/*    in this function is generic. All ethernet controller multicast join */
/*    logic is to be placed in _nx_driver_hardware_multicast_join.        */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_multicast_join(NX_IP_DRIVER *driver_req_ptr)
{

    /* Not supported.  */
    driver_req_ptr -> nx_ip_driver_status =  NX_NOT_SUCCESSFUL;
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_multicast_leave                        x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the multicast leave request. The           */
/*    processing in this function is generic. All ethernet controller     */
/*    multicast leave logic is to be placed in                            */
/*    _nx_driver_hardware_multicast_leave.                                */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_multicast_leave(NX_IP_DRIVER *driver_req_ptr)
{

    /* Not supported.  */
    driver_req_ptr -> nx_ip_driver_status =  NX_NOT_SUCCESSFUL;
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_get_status                             x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the get status request. The processing     */
/*    in this function is generic. All ethernet controller get status     */
/*    logic is to be placed in _nx_driver_hardware_get_status.            */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _nx_driver_hardware_get_status        Process get status request    */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_get_status(NX_IP_DRIVER *driver_req_ptr)
{

UINT        status;


    /* Call hardware specific get status function. */
    status =  _nx_driver_hardware_get_status(driver_req_ptr);

    /* Determine if there was an error.  */
    if (status != NX_SUCCESS)
    {

        /* Indicate an unsuccessful request.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_NOT_SUCCESSFUL;
    }
    else
    {

        /* Indicate the request was successful.   */
        driver_req_ptr -> nx_ip_driver_status =  NX_SUCCESS;
    }
}


#ifdef NX_ENABLE_INTERFACE_CAPABILITY
/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_capability_get                         x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the get capability request.                */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_capability_get(NX_IP_DRIVER *driver_req_ptr)
{

    /* Return the capability of the Ethernet controller.  */
    *(driver_req_ptr -> nx_ip_driver_return_ptr) = NX_DRIVER_CAPABILITY;

    /* Return the success status.  */
    driver_req_ptr -> nx_ip_driver_status =  NX_SUCCESS;
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_capability_set                         x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the set capability request.                */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_capability_set(NX_IP_DRIVER *driver_req_ptr)
{

UINT        status;


    /* Call hardware specific get status function. */
    status =  _nx_driver_hardware_capability_set(driver_req_ptr);

    /* Determine if there was an error.  */
    if (status != NX_SUCCESS)
    {

        /* Indicate an unsuccessful request.  */
        driver_req_ptr -> nx_ip_driver_status =  NX_NOT_SUCCESSFUL;
    }
    else
    {

        /* Indicate the request was successful.   */
        driver_req_ptr -> nx_ip_driver_status =  NX_SUCCESS;
    }
}
#endif /* NX_ENABLE_INTERFACE_CAPABILITY */


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_deferred_processing                    x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the deferred ISR action within the context */
/*    of the IP thread.                                                   */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver command from the IP    */
/*                                            thread                      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID  _nx_driver_deferred_processing(NX_IP_DRIVER *driver_req_ptr)
{
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_thread_entry                           x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function is the driver thread entry. In this thread, it        */
/*    performs checking for incoming TCP and UDP packets. On new packet,  */
/*    it will be passed to NetX.                                          */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    thread_input                          Thread input                  */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    tx_mutex_get                          Obtain protection mutex       */
/*    tx_mutex_put                          Release protection mutex      */
/*    tx_thread_sleep                       Sleep driver thread           */
/*    nx_packet_allocate                    Allocate a packet for incoming*/
/*                                            TCP and UDP data            */
/*    _nx_tcp_socket_driver_packet_receive  Receive TCP packet            */
/*    _nx_tcp_socket_driver_establish       Establish TCP connection      */
/*    _nx_udp_socket_driver_packet_receive  Receive UDP packet            */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static VOID _nx_driver_thread_entry(ULONG thread_input)
{
UINT i;
NX_PACKET *packet_ptr;
UINT packet_type;
UINT status;
int ret;
SOCKET max_socket_fd;
int addrlen;
fd_set read_fds, write_fds, except_fds;
struct timeval tv;
struct sockaddr_in remote_addr;
NXD_ADDRESS local_ip;
NXD_ADDRESS remote_ip;
ULONG network_mask;
ULONG data_length;
NX_IP *ip_ptr = nx_driver_information.nx_driver_information_ip_ptr;
NX_INTERFACE *interface_ptr = nx_driver_information.nx_driver_information_interface;
NX_PACKET_POOL *pool_ptr = nx_driver_information.nx_driver_information_packet_pool_ptr;

    NX_PARAMETER_NOT_USED(thread_input);

    for (;;)
    {

        /* Set FDs. */
        FD_ZERO(&read_fds);
        FD_ZERO(&write_fds);
        FD_ZERO(&except_fds);
        max_socket_fd = -1;

        /* Obtain the IP internal mutex before processing the IP event.  */
        tx_mutex_get(&(ip_ptr -> nx_ip_protection), TX_WAIT_FOREVER);

        for (i = 0; i < NX_DRIVER_SOCKETS_MAXIMUM; i++)
        {
            if (nx_driver_sockets[i].socket_ptr == NX_NULL)
            {

                /* Skip sockets not used.  */
                continue;
            }
            FD_SET(nx_driver_sockets[i].socket_fd, &read_fds);
            FD_SET(nx_driver_sockets[i].socket_fd, &except_fds);
            if ((nx_driver_sockets[i].protocol == NX_PROTOCOL_TCP) &&
                (nx_driver_sockets[i].tcp_connected == NX_FALSE))
            {
                FD_SET(nx_driver_sockets[i].socket_fd, &write_fds);
            }
            if (nx_driver_sockets[i].socket_fd > max_socket_fd)
            {
                max_socket_fd = nx_driver_sockets[i].socket_fd;
            }
        }

        tx_mutex_put(&(ip_ptr -> nx_ip_protection));

#ifndef WIN32
        if (max_socket_fd == -1)
        {

            /* No socket. Just sleep. */
            tx_thread_sleep(NX_DRIVER_THREAD_INTERVAL);
            continue;
        }
#endif

        /* Wait on select. */
        tv.tv_sec = 0;
        tv.tv_usec = 0;
        ret = select(max_socket_fd + 1, &read_fds, &write_fds, &except_fds, &tv);

        if (ret <= 0)
        {

            /* No data. Just sleep. */
            tx_thread_sleep(NX_DRIVER_THREAD_INTERVAL);
            continue;
        }

        /* Obtain the IP internal mutex before processing the IP event.  */
        tx_mutex_get(&(ip_ptr -> nx_ip_protection), TX_WAIT_FOREVER);

        /* Loop through all sockets.  */
        for (i = 0; i < NX_DRIVER_SOCKETS_MAXIMUM; i++)
        {
            if (nx_driver_sockets[i].socket_ptr == NX_NULL)
            {

                /* Skip sockets not used.  */
                continue;
            }

            if (!FD_ISSET(nx_driver_sockets[i].socket_fd, &read_fds) &&
                !FD_ISSET(nx_driver_sockets[i].socket_fd, &write_fds) &&
                !FD_ISSET(nx_driver_sockets[i].socket_fd, &except_fds))
            {

                /* Skip sockets without data.  */
                continue;
            }

            /* Set packet type.  */
            if (nx_driver_sockets[i].protocol == NX_PROTOCOL_TCP)
            {
                packet_type = NX_TCP_PACKET;

                /* Check TCP connection. */
                if (FD_ISSET(nx_driver_sockets[i].socket_fd, &write_fds) &&
                    !FD_ISSET(nx_driver_sockets[i].socket_fd, &except_fds) &&
                    (nx_driver_sockets[i].is_client == NX_TRUE))
                {

                    /* For TCP client, notify NetX with peer information.  */
                    addrlen = sizeof(remote_addr);
                    getpeername(nx_driver_sockets[i].socket_fd,
                                (struct sockaddr *)&remote_addr, &addrlen);
                    remote_ip.nxd_ip_version = NX_IP_VERSION_V4;
                    remote_ip.nxd_ip_address.v4 = htonl(remote_addr.sin_addr.s_addr);
                    _nx_tcp_socket_driver_establish(nx_driver_sockets[i].socket_ptr, interface_ptr,
                                                    nx_driver_sockets[i].remote_port);
                    nx_driver_sockets[i].tcp_connected = NX_TRUE;
                }
            }
            else
            {
                packet_type = NX_UDP_PACKET;
            }

            if (FD_ISSET(nx_driver_sockets[i].socket_fd, &read_fds))
            {

                if ((nx_driver_sockets[i].protocol == NX_PROTOCOL_TCP) &&
                    (nx_driver_sockets[i].tcp_connected == NX_FALSE))
                {

                    /* For TCP server, let NetX initiate accept call.  */
                    if (_nx_tcp_socket_driver_establish(nx_driver_sockets[i].socket_ptr, interface_ptr,
                                                        0))
                    {

                        /* NetX TCP socket is not ready to accept. Just sleep to avoid starving.  */
                        tx_thread_sleep(NX_DRIVER_THREAD_INTERVAL);
                    }
                    continue;
                }

                /* Loop to receive all incoming data.  */
                for (;;)
                {

                    /* Use packet buffer directly. IP fragments are not supported. */
                    if (nx_packet_allocate(pool_ptr, &packet_ptr, packet_type, NX_NO_WAIT))
                    {

                        /* Packet not available.  */
                        break;
                    }

                    /* Get available size of packet.  */
                    data_length = (ULONG)(packet_ptr -> nx_packet_data_end - packet_ptr -> nx_packet_prepend_ptr);

                    /* Receive data. */
                    addrlen = sizeof(remote_addr);
                    ret = recvfrom(nx_driver_sockets[i].socket_fd,
                                (char *)packet_ptr -> nx_packet_prepend_ptr, data_length, 0,
                                (struct sockaddr*)&remote_addr, &addrlen);

                    if (ret == 0)
                    {

                        /* No data available. */
                        nx_packet_release(packet_ptr);
                        break;
                    }
                    else
                    {

                        /* Set packet length.  */
                        packet_ptr -> nx_packet_length = (ULONG)ret;
                        packet_ptr -> nx_packet_append_ptr = packet_ptr -> nx_packet_prepend_ptr + ret;
                        packet_ptr -> nx_packet_ip_interface = interface_ptr;

                        /* Pass it to NetXDuo.  */
                        if (nx_driver_sockets[i].protocol == NX_PROTOCOL_TCP)
                        {
                            _nx_tcp_socket_driver_packet_receive(nx_driver_sockets[i].socket_ptr, packet_ptr);
                        }
                        else
                        {

                            /* Convert IP version.  */
                            remote_ip.nxd_ip_version = NX_IP_VERSION_V4;
                            remote_ip.nxd_ip_address.v4 = htonl(remote_addr.sin_addr.s_addr);
                            local_ip.nxd_ip_version = NX_IP_VERSION_V4;
                            nx_ip_interface_address_get(ip_ptr, interface_ptr -> nx_interface_index,
                                                        &local_ip.nxd_ip_address.v4, &network_mask); /* Multicast is not supported */

                            _nx_udp_socket_driver_packet_receive(nx_driver_sockets[i].socket_ptr,
                                                                 packet_ptr, &local_ip, &remote_ip,
                                                                 nx_driver_sockets[i].remote_port);
                        }
                    }
                }
            }

            if (FD_ISSET(nx_driver_sockets[i].socket_fd, &except_fds))
            {

                /* Connection error. Notify upper layer with Null packet.  */
                if (nx_driver_sockets[i].protocol == NX_PROTOCOL_TCP)
                {
                    _nx_tcp_socket_driver_packet_receive(nx_driver_sockets[i].socket_ptr, NX_NULL);
                }
                else
                {
                    _nx_udp_socket_driver_packet_receive(nx_driver_sockets[i].socket_ptr, NX_NULL,
                                                         NX_NULL, NX_NULL, 0);
                }
            }
        }

        /* Release the IP internal mutex before processing the IP event.  */
        tx_mutex_put(&(ip_ptr -> nx_ip_protection));
    }
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_tcpip_handler                          x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processing the TCP/IP request.                        */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    ip_ptr                                Pointer to IP                 */
/*    interface_ptr                         Pointer to interface          */
/*    socket_ptr                            Pointer to TCP or UDP socket  */
/*    operation                             Operation of TCP/IP request   */
/*    packet_ptr                            Pointer to packet             */
/*    local_ip                              Pointer to local IP address   */
/*    remote_ip                             Pointer to remote IP address  */
/*    local_port                            Local socket port             */
/*    remote_port                           Remote socket port            */
/*    wait_option                           Wait option in ticks          */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    nx_packet_transmit_release            Release transmittion packet   */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Driver entry function                                               */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static UINT _nx_driver_tcpip_handler(struct NX_IP_STRUCT *ip_ptr,
                                     struct NX_INTERFACE_STRUCT *interface_ptr,
                                     VOID *socket_ptr, UINT operation, NX_PACKET *packet_ptr,
                                     NXD_ADDRESS *local_ip, NXD_ADDRESS *remote_ip,
                                     UINT local_port, UINT *remote_port, UINT wait_option)
{
UINT status;
UCHAR remote_ip_bytes[4];
NX_PACKET *current_packet;
ULONG packet_size;
ULONG time_start;
UINT offset;
int ret;
SOCKET socket_fd;
SOCKET accept_socket_fd;
int addrlen;
#ifdef WIN32
u_long mode;
#else
int flags;
#endif
fd_set write_fds, except_fds;
struct timeval tv;
struct sockaddr_in remote_addr, local_addr;
UINT i = 0;
UINT listen_index;

    if (operation == NX_TCPIP_OFFLOAD_TCP_SERVER_SOCKET_LISTEN)
    {

        /* For TCP server socket, find duplicate listen requrest first.
           Only one socket can listen to each TCP port.  */
        for (i = 0; i < NX_DRIVER_SOCKETS_MAXIMUM; i++)
        {
            if ((nx_driver_sockets[i].local_port == local_port) &&
                (nx_driver_sockets[i].protocol == NX_PROTOCOL_TCP))
            {

                /* Find a duplicate listen. Just overwrite it.  */
                ((NX_TCP_SOCKET*)socket_ptr)->nx_tcp_socket_tcpip_offload_context = (VOID*)i;
                nx_driver_sockets[i].socket_ptr = socket_ptr;
                return(NX_SUCCESS);
            }
        }
    }

    if ((operation == NX_TCPIP_OFFLOAD_TCP_CLIENT_SOCKET_CONNECT) ||
        (operation == NX_TCPIP_OFFLOAD_TCP_SERVER_SOCKET_ACCEPT) ||
        (operation == NX_TCPIP_OFFLOAD_UDP_SOCKET_BIND) ||
        ((operation == NX_TCPIP_OFFLOAD_TCP_SERVER_SOCKET_LISTEN) &&
         (i == NX_DRIVER_SOCKETS_MAXIMUM)))
    {

        /* Find a socket that is not used.  */
        for (i = 0; i < NX_DRIVER_SOCKETS_MAXIMUM; i++)
        {
            if (nx_driver_sockets[i].socket_ptr == NX_NULL)
            {

                /* Find an empty entry.  */
                if (operation != NX_TCPIP_OFFLOAD_TCP_SERVER_SOCKET_ACCEPT)
                {
                    if (operation == NX_TCPIP_OFFLOAD_UDP_SOCKET_BIND)
                    {
                        socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
                    }
                    else
                    {
                        socket_fd = socket(AF_INET, SOCK_STREAM, 0);
                    }

#ifdef WIN32
                    if (socket_fd == INVALID_SOCKET)
#else
                    if (socket_fd < 0)
#endif
                    {

                        /* Failed to create socket.  */
                        return(NX_NOT_SUCCESSFUL);
                    }
                    nx_driver_sockets[i].socket_fd = socket_fd;

                    /* Set non blocking mode. */
#ifdef WIN32
                    mode = 1;
                    ioctlsocket(socket_fd, FIONBIO, &mode);
#else
                    flags = fcntl(socket_fd, F_GETFL, 0);
                    fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK);
#endif
                }
                nx_driver_sockets[i].socket_ptr = socket_ptr;
                break;
            }
        }

        if (i == NX_DRIVER_SOCKETS_MAXIMUM)
        {

            /* No more entries.  */
            return(NX_NO_MORE_ENTRIES);
        }
    }

    switch (operation)
    {
    case NX_TCPIP_OFFLOAD_TCP_CLIENT_SOCKET_CONNECT:

        /* Store the index of driver socket.  */
        ((NX_TCP_SOCKET *)socket_ptr) -> nx_tcp_socket_tcpip_offload_context = (VOID *)i;


        /* Store address and port.  */
        nx_driver_sockets[i].remote_ip = remote_ip -> nxd_ip_address.v4;
        nx_driver_sockets[i].local_port = local_port;
        nx_driver_sockets[i].remote_port = *remote_port;
        nx_driver_sockets[i].protocol = NX_PROTOCOL_TCP;
        nx_driver_sockets[i].tcp_connected = NX_FALSE;
        nx_driver_sockets[i].is_client = NX_TRUE;

        socket_fd = nx_driver_sockets[i].socket_fd;

        /* Bind to local IP address. */
        local_addr.sin_family = AF_INET;
        local_addr.sin_port = htons(local_port);
        local_addr.sin_addr.s_addr = INADDR_ANY;
        ret = bind(socket_fd, (struct sockaddr*)&local_addr, sizeof(local_addr));
        if (ret < 0)
        {
            return(NX_NOT_SUCCESSFUL);
        }

        /* Set remote address.  */
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(*remote_port);
        remote_addr.sin_addr.s_addr = htonl(remote_ip -> nxd_ip_address.v4);

        /* Connect.  */
        ret = connect(socket_fd, (struct sockaddr*)&remote_addr, sizeof(remote_addr));
        if (ret < 0)
        {
#ifdef WIN32
            if (WSAGetLastError() != WSAEWOULDBLOCK)
#else
            if (errno != EINPROGRESS)
#endif
            {
                return(NX_NOT_SUCCESSFUL);
            }
            else
            {
                return(NX_IN_PROGRESS);
            }
        }
        break;

    case NX_TCPIP_OFFLOAD_TCP_SERVER_SOCKET_LISTEN:

        /* Store the index of driver socket.  */
        ((NX_TCP_SOCKET *)socket_ptr) -> nx_tcp_socket_tcpip_offload_context = (VOID *)i;


        /* Store address and port.  */
        nx_driver_sockets[i].local_port = local_port;
        nx_driver_sockets[i].protocol = NX_PROTOCOL_TCP;
        nx_driver_sockets[i].tcp_connected = NX_FALSE;
        nx_driver_sockets[i].is_client = NX_FALSE;

        socket_fd = nx_driver_sockets[i].socket_fd;

        /* Bind to local IP address. */
        local_addr.sin_family = AF_INET;
        local_addr.sin_port = htons(local_port);
        local_addr.sin_addr.s_addr = INADDR_ANY;
        ret = bind(socket_fd, (struct sockaddr*)&local_addr, sizeof(local_addr));
        if (ret < 0)
        {
            return(NX_NOT_SUCCESSFUL);
        }

        /* Connect.  */
        ret = listen(socket_fd, NX_DRIVER_SERVER_LISTEN_COUNT);
        if (ret)
        {
            return(NX_NOT_SUCCESSFUL);
        }
        break;

    case NX_TCPIP_OFFLOAD_TCP_SERVER_SOCKET_ACCEPT:

        /* The context in socket still pointers to listen fd.  */
        listen_index = (UINT)(((NX_TCP_SOCKET*)socket_ptr) -> nx_tcp_socket_tcpip_offload_context);

        /* Accept connection.  */
        addrlen = sizeof(remote_addr);
        accept_socket_fd = accept(nx_driver_sockets[listen_index].socket_fd,
                                  (struct sockaddr *)&remote_addr, &addrlen);

#ifdef WIN32
        if (accept_socket_fd == INVALID_SOCKET)
#else
        if (accept_socket_fd < 0)
#endif
        {

            /* Failed to accept connection.  */
            nx_driver_sockets[i].socket_ptr = NX_NULL;
            return(NX_NOT_SUCCESSFUL);
        }

        /* Set non blocking mode. */
#ifdef WIN32
        mode = 1;
        ioctlsocket(accept_socket_fd, FIONBIO, &mode);
#else
        flags = fcntl(accept_socket_fd, F_GETFL, 0);
        fcntl(accept_socket_fd, F_SETFL, flags | O_NONBLOCK);
#endif

        /* Store the index of driver socket.  */
        ((NX_TCP_SOCKET *)socket_ptr) -> nx_tcp_socket_tcpip_offload_context = (VOID *)i;

        /* Store address and port.  */
        *remote_port = (UINT)ntohs(remote_addr.sin_port);
        remote_ip -> nxd_ip_version = NX_IP_VERSION_V4;
        remote_ip -> nxd_ip_address.v4 = htonl(remote_addr.sin_addr.s_addr);
        nx_driver_sockets[i].protocol = NX_PROTOCOL_TCP;
        nx_driver_sockets[i].tcp_connected = NX_TRUE;
        nx_driver_sockets[i].socket_fd = accept_socket_fd;
        break;

    case NX_TCPIP_OFFLOAD_TCP_SERVER_SOCKET_UNLISTEN:
        for (i = 0; i < NX_DRIVER_SOCKETS_MAXIMUM; i++)
        {
            if ((nx_driver_sockets[i].local_port == local_port) &&
                (nx_driver_sockets[i].protocol == NX_PROTOCOL_TCP))
            {
                nx_driver_sockets[i].socket_ptr = NX_NULL;
                nx_driver_sockets[i].local_port = 0;
                CLOSE(nx_driver_sockets[i].socket_fd);
                return(NX_SUCCESS);
            }
        }
        break;

    case NX_TCPIP_OFFLOAD_TCP_SOCKET_DISCONNECT:
        i = (UINT)(((NX_TCP_SOCKET *)socket_ptr) -> nx_tcp_socket_tcpip_offload_context);

        /* Close socket.  */
        socket_fd = nx_driver_sockets[i].socket_fd;
        CLOSE(socket_fd);

        /* Reset socket to free this entry.  */
        nx_driver_sockets[i].socket_ptr = NX_NULL;
        break;

    case NX_TCPIP_OFFLOAD_UDP_SOCKET_BIND:
        /* Note, send data from one port to multiple remotes are not supported.  */
        /* Store the index of driver socket.  */
        ((NX_UDP_SOCKET *)socket_ptr) -> nx_udp_socket_tcpip_offload_context = (VOID *)i;

        socket_fd = nx_driver_sockets[i].socket_fd;
        nx_driver_sockets[i].protocol = NX_PROTOCOL_UDP;

        /* Bind to local IP address. */
        local_addr.sin_family = AF_INET;
        local_addr.sin_port = htons(local_port);
        local_addr.sin_addr.s_addr = INADDR_ANY;
        ret = bind(socket_fd, (struct sockaddr*)&local_addr, sizeof(local_addr));
        if (ret < 0)
        {
            return(NX_NOT_SUCCESSFUL);
        }
        break;

    case NX_TCPIP_OFFLOAD_UDP_SOCKET_UNBIND:
        i = (UINT)(((NX_UDP_SOCKET *)socket_ptr) -> nx_udp_socket_tcpip_offload_context);

        /* Close socket.  */
        socket_fd = nx_driver_sockets[i].socket_fd;
        CLOSE(socket_fd);

        /* Reset socket to free this entry.  */
        nx_driver_sockets[i].socket_ptr = NX_NULL;
        break;

    case NX_TCPIP_OFFLOAD_UDP_SOCKET_SEND:
        i = (UINT)(((NX_UDP_SOCKET *)socket_ptr) -> nx_udp_socket_tcpip_offload_context);

#ifndef NX_DISABLE_PACKET_CHAIN
        if (packet_ptr -> nx_packet_next)
        {

            /* Limitation in this driver. UDP packet must be in one packet.  */
            return (NX_NOT_SUCCESSFUL);
        }
#endif /* NX_DISABLE_PACKET_CHAIN */

        /* Set remote address.  */
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(*remote_port);
        remote_addr.sin_addr.s_addr = htonl(remote_ip -> nxd_ip_address.v4);

        /* Send data.  */
        socket_fd = nx_driver_sockets[i].socket_fd;
        ret = sendto(socket_fd, packet_ptr -> nx_packet_prepend_ptr,
                     packet_ptr -> nx_packet_length, 0,
                     (struct sockaddr*)&remote_addr, sizeof(remote_addr));
        if (ret != (INT)packet_ptr -> nx_packet_length)
        {
            return (NX_NOT_SUCCESSFUL);
        }

        /* Release the packet.  */
        nx_packet_transmit_release(packet_ptr);
        break;

    case NX_TCPIP_OFFLOAD_TCP_SOCKET_SEND:
        i = (UINT)(((NX_TCP_SOCKET *)socket_ptr) -> nx_tcp_socket_tcpip_offload_context);

        socket_fd = nx_driver_sockets[i].socket_fd;

        /* Initialize the current packet to the input packet pointer.  */
        current_packet =  packet_ptr;

        /* Loop to send the packet.  */
        offset = 0;
        while(current_packet)
        {

            /* Calculate current packet size. */
            packet_size = (ULONG)(current_packet -> nx_packet_append_ptr - current_packet -> nx_packet_prepend_ptr);

            /* Send data.  */
            ret = send(socket_fd, packet_ptr -> nx_packet_prepend_ptr + offset,
                       packet_ptr -> nx_packet_length, 0);
            if (ret != (INT)packet_ptr -> nx_packet_length)
            {
                if (ret < 0)
                {
#ifdef WIN32
                    if (WSAGetLastError() != WSAENOBUFS)
#else
                    if (errno != EAGAIN)
#endif
                    {
                        return (NX_NOT_SUCCESSFUL);
                    }
                    else
                    {
                        /* Sleep 1 tick and try again.  */
                        tx_thread_sleep(1);
                        continue;
                    }
                }
                offset = (UINT)ret;
                continue;
            }

#ifndef NX_DISABLE_PACKET_CHAIN
            /* We have crossed the packet boundary.  Move to the next packet structure.  */
            current_packet =  current_packet -> nx_packet_next;
#else
            /* End of the loop.  */
            current_packet = NX_NULL;
#endif /* NX_DISABLE_PACKET_CHAIN */
            offset = 0;
        }

        /* Release the packet.  */
        nx_packet_transmit_release(packet_ptr);
        break;

    default:
        return(NX_NOT_SUCCESSFUL);
    }

    return(NX_SUCCESS);
}


/****** DRIVER SPECIFIC ****** Start of part/vendor specific internal driver functions.  */


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_hardware_initialize                    x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processes hardware-specific initialization.           */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver request pointer        */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                [NX_SUCCESS|NX_NOT_SUCCESSFUL]*/
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    tx_thread_info_get                    Get thread information        */
/*    tx_thread_create                      Create driver thread          */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _nx_driver_initialize                 Driver initialize processing  */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static UINT  _nx_driver_hardware_initialize(NX_IP_DRIVER *driver_req_ptr)
{
UINT status;
UINT priority = 0;

    /* Get priority of IP thread.  */
    tx_thread_info_get(tx_thread_identify(), NX_NULL, NX_NULL, NX_NULL, &priority,
                       NX_NULL, NX_NULL, NX_NULL, NX_NULL);

    /* Create the driver thread.  */
    /* The priority of network thread is lower than IP thread.  */
    status = tx_thread_create(&nx_driver_thread, "Driver Thread", _nx_driver_thread_entry, 0,
                              nx_driver_thread_stack, NX_DRIVER_STACK_SIZE,
                              priority + 1, priority + 1,
                              TX_NO_TIME_SLICE, TX_DONT_START);

    if (status)
    {
        return(status);
    }

#ifdef WIN32
    WORD wVersionRequested;
    WSADATA wsaData;
    int err = wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0)
    {
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }
#endif

    /* Return success!  */
    return(status);
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_hardware_enable                        x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processes hardware-specific link enable requests.     */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver request pointer        */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                [NX_SUCCESS|NX_NOT_SUCCESSFUL]*/
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    tx_thread_reset                       Reset driver thread           */
/*    tx_thread_resume                      Resume driver thread          */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _nx_driver_enable                     Driver link enable processing */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static UINT  _nx_driver_hardware_enable(NX_IP_DRIVER *driver_req_ptr)
{
    tx_thread_reset(&nx_driver_thread);
    tx_thread_resume(&nx_driver_thread);

    /* Return success!  */
    return(NX_SUCCESS);
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_hardware_disable                       x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processes hardware-specific link disable requests.    */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver request pointer        */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                [NX_SUCCESS|NX_NOT_SUCCESSFUL]*/
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    tx_thread_suspend                     Suspend driver thread         */
/*    tx_thread_terminate                   Terminate driver thread       */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _nx_driver_disable                    Driver link disable processing*/
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static UINT  _nx_driver_hardware_disable(NX_IP_DRIVER *driver_req_ptr)
{
UINT i;

    /* Reset all sockets.  */
    for (i = 0; i < NX_DRIVER_SOCKETS_MAXIMUM; i++)
    {
        if (nx_driver_sockets[i].socket_ptr)
        {

            /* Disconnect.  */
            CLOSE(nx_driver_sockets[i].socket_fd);
            nx_driver_sockets[i].socket_ptr = NX_NULL;
        }
    }

    tx_thread_suspend(&nx_driver_thread);
    tx_thread_terminate(&nx_driver_thread);

    /* Return success!  */
    return(NX_SUCCESS);
}


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_hardware_get_status                    x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processes hardware-specific get status requests.      */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                        Driver request pointer        */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                [NX_SUCCESS|NX_NOT_SUCCESSFUL]*/
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _nx_driver_get_status                 Driver get status processing  */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static UINT  _nx_driver_hardware_get_status(NX_IP_DRIVER *driver_req_ptr)
{

    /* Return success.  */
    return(NX_SUCCESS);
}


#ifdef NX_ENABLE_INTERFACE_CAPABILITY
/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_driver_hardware_capability_set                x86/Generic       */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function processes hardware-specific capability set requests.  */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    driver_req_ptr                         Driver request pointer       */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                [NX_SUCCESS|NX_NOT_SUCCESSFUL]*/
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _nx_driver_capability_set             Capability set processing     */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  xx-xx-xxxx     Yuxin Zhou               Initial Version 6.x           */
/*                                                                        */
/**************************************************************************/
static UINT _nx_driver_hardware_capability_set(NX_IP_DRIVER *driver_req_ptr)
{

    return NX_SUCCESS;
}
#endif /* NX_ENABLE_INTERFACE_CAPABILITY */

/****** DRIVER SPECIFIC ****** Start of part/vendor specific internal driver functions.  */
