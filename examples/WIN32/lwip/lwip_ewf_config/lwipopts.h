/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * LWIP stack configuration for Embedded Wireleess Framework integration
 ****************************************************************************/

#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

 /* Use lwIP with OS awareness, NO_SYS = 1 for minimum functionality */
#define NO_SYS                      0

/* Use standard errno */
#define LWIP_PROVIDE_ERRNO          0   // Do not use standard errno
#define LWIP_ERRNO_STDINCLUDE       // Include errno.h

#define LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS

/* Random number generator for lwIP */
#define LWIP_RAND()                 ((u32_t)rand())

#define LWIP_FREERTOS_CHECK_CORE_LOCKING 0
void sys_check_core_locking(void);
#define LWIP_ASSERT_CORE_LOCKED()   //sys_check_core_locking()

void sys_mark_tcpip_thread(void);
#define LWIP_MARK_TCPIP_THREAD()    //sys_mark_tcpip_thread()

/* Intertask protection */
#define SYS_LIGHTWEIGHT_PROT        1

/* Random number generator for lwIP */
#define LWIP_FREERTOS_SYS_ARCH_PROTECT_USES_MUTEX 1

/* Enable/Disable lwIP debugging */
#define LWIP_DEBUG                  0

/* Enable lwIP netconn API */
#define LWIP_NETCONN                1

/*Enable lwIP netif API */
#define LWIP_NETIF_API              1

/* lwIP socket API */
#define LWIP_SOCKET                 1

/* Use lwIP DNS */
#define LWIP_DNS                    1

/* Use IPv4 */
#define LWIP_IPV4                   1

/* Enable raw API */
#define LWIP_RAW                    1

/* Set the default raw API receive mailbox size */
#define DEFAULT_RAW_RECVMBOX_SIZE   8192

/* ---------- TCP options ---------- */
/* Enable TCP */
#define LWIP_TCP                    1

/* Set the maximum TTL value for TCP packets */
#define TCP_TTL                     255

/* Set the default TCP receive mailbox size */
#define DEFAULT_TCP_RECVMBOX_SIZE   8192

/* ---------- UDP options ---------- */
/* Enable UDP */
#define LWIP_UDP                    1

/* Set the maximum TTL value for UDP packets */
#define UDP_TTL                     255

/* Set the maximum TTL value for UDP packets */
#define DEFAULT_UDP_RECVMBOX_SIZE   8192

/* Do not use IPv6 */
#define LWIP_IPV6                   0

/* Use Internet Group Management Protocol (IGMP) for IPv4 */
#define LWIP_IGMP                   LWIP_IPV4

/* Use Internet Control Message Protocol (ICMP) for IPv4 */
#define LWIP_ICMP                   LWIP_IPV4

/* Disable the Address Resolution Protocol (ARP) */
#define LWIP_ARP                    0

/* Use Internet Control Message Protocol (ICMP) for IPv4 */
#define LWIP_TCPIP_CORE_LOCKING     1

/* Set the memory alignment */
#define MEM_ALIGNMENT               1

/* Set the memory alignment */
#define MEMP_NUM_PBUF               10

/* Set the memory alignment */
#define MEM_SIZE                    16000

/* Set the PBUF pool size */
#define PBUF_POOL_SIZE              200

/* Set the PBUF pool buffer size */
#define PBUF_POOL_BUFSIZE           1500

/* Set the PBUF pool buffer size */
#define PBUF_LINK_HLEN              16

/* Maximum number of TCP connections */
#define MEMP_NUM_TCP_PCB            10

/* Set the TCP/IP mailbox size */
#define TCPIP_MBOX_SIZE             2

/* Set the TCP/IP thread stack size */
#define TCPIP_THREAD_STACKSIZE      1024*2

/* Set the TCP/IP thread stack size */
#define TCPIP_THREAD_PRIO           6

/* Maximum segment size */
#define TCP_MSS                     (1500)

/* Enable PPP */
#define PPP_SUPPORT                 1

/* Maximum number of simultaneous PPP connections */
#define NUM_PPP                     1

/* Disable PPP over Ethernet */
#define PPPOE_SUPPORT               0

/* Use PPP over serial */
#define PPPOS_SUPPORT               1

/* Enable Password Authentication Protocol (PAP) support */
#define PAP_SUPPORT                 1

/* Enable Challenge-Handshake Authentication Protocol (CHAP) support */
#define CPAP_SUPPORT                1

/* Disable Microsoft Challenge-Handshake Authentication Protocol (MS-CHAP) support */
#define MSCHAP_SUPPORT              0

/* Enable PPP notify phase callback */
#define PPP_NOTIFY_PHASE            1

/* Enable PPP API support */
#define LWIP_PPP_API                1

/* Set to the value of LWIP_DEBUG to enable support for printing PPP packet data */
#define PRINTPKT_SUPPORT            LWIP_DEBUG

/* Set the level of PPP debugging to LWIP_DBG_ON, LWIP_DBG_OFF, or LWIP_DBG_TRACE */
#define PPP_DEBUG                   LWIP_DBG_OFF

#endif /* __LWIPOPTS_H__ */
