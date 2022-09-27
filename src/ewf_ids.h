/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework identifiers
 ****************************************************************************/

#ifndef __ewf__ids__h__included__
#define __ewf__ids__h__included__

/**
 * @defgroup group_ewf_ids EWF IDs
 * @brief EWF IDs
 * @{
 */

/**
 * @defgroup group_ewf_ids_developer EWF developer IDs
 * @brief EWF developer IDs
 * @{
 */

#define EWF_DEVELOPER_PRIVATE                      (0x00000000)
#define EWF_DEVELOPER_MICROSOFT                    (0x00010000)
#define EWF_DEVELOPER_ARM                          (0x00020000)
#define EWF_DEVELOPER_STM                          (0x00030000)
#define EWF_DEVELOPER_RENESAS                      (0x00040000)
#define EWF_DEVELOPER_NXP                          (0x00050000)
#define EWF_DEVELOPER_MICROCHIP                    (0x00060000)
#define EWF_DEVELOPER_QUECTEL                      (0x00060000)
#define EWF_DEVELOPER_SIMCOM                       (0x00070000)
#define EWF_DEVELOPER_SEQUANS                      (0x00080000)
#define EWF_DEVELOPER_UBLOX                        (0x00090000)
#define EWF_DEVELOPER_ESPRESSIF                    (0x000A0000)
#define EWF_DEVELOPER_WIZNET                       (0x000B0000)

#define EWF_DEVELOPER_ANONYMOUS                    (0xFFFF0000)

/** @} *** group_ewf_ids_developer */

/**
 * @defgroup group_ewf_ids_adapter EWF adapter IDs
 * @brief EWF adapter IDs
 * @{
 */

#define EWF_ADAPTER_TYPE_WINSOCK2                  (EWF_DEVELOPER_MICROSOFT | 0x0001)
#define EWF_ADAPTER_TYPE_BSD_SOCKETS               (EWF_DEVELOPER_MICROSOFT | 0x0002)
#define EWF_ADAPTER_TYPE_QUECTEL_BG96              (EWF_DEVELOPER_MICROSOFT | 0x0003)
#define EWF_ADAPTER_TYPE_QUECTEL_BG95              (EWF_DEVELOPER_MICROSOFT | 0x0004)
#define EWF_ADAPTER_TYPE_SIMCOM_SIM7000            (EWF_DEVELOPER_MICROSOFT | 0x0005)
#define EWF_ADAPTER_TYPE_SIMCOM_SIM868             (EWF_DEVELOPER_MICROSOFT | 0x0006)
#define EWF_ADAPTER_TYPE_UBLOX_SARA_R4             (EWF_DEVELOPER_MICROSOFT | 0x0007)
#define EWF_ADAPTER_TYPE_UBLOX_SARA_R5             (EWF_DEVELOPER_MICROSOFT | 0x0008)
#define EWF_ADAPTER_TYPE_SEQUANS_MONARCH           (EWF_DEVELOPER_MICROSOFT | 0x0009)
#define EWF_ADAPTER_TYPE_SEQUANS_MONARCHGO         (EWF_DEVELOPER_MICROSOFT | 0x000A)
#define EWF_ADAPTER_TYPE_SEQUANS_MONARCH2          (EWF_DEVELOPER_MICROSOFT | 0x000B)
#define EWF_ADAPTER_TYPE_ESPRESSIF_ESP8266         (EWF_DEVELOPER_MICROSOFT | 0x000C)
#define EWF_ADAPTER_TYPE_ESPRESSIF_ESP8285         (EWF_DEVELOPER_MICROSOFT | 0x000D)
#define EWF_ADAPTER_TYPE_ESPRESSIF_ESP32           (EWF_DEVELOPER_MICROSOFT | 0x000E)
#define EWF_ADAPTER_TYPE_ESPRESSIF_WROOM_02        (EWF_DEVELOPER_MICROSOFT | 0x000F)
#define EWF_ADAPTER_TYPE_WIZNET_W5500              (EWF_DEVELOPER_MICROSOFT | 0x0010)
#define EWF_ADAPTER_TYPE_WIZNET_WIZFI360           (EWF_DEVELOPER_MICROSOFT | 0x0011)
#define EWF_ADAPTER_TYPE_RENESAS_RYZ014            (EWF_DEVELOPER_MICROSOFT | 0x0012)
#define EWF_ADAPTER_TYPE_SEEED_LORA_E5             (EWF_DEVELOPER_MICROSOFT | 0x0013)
#define EWF_ADAPTER_TYPE_SIMCOM_SIM900             (EWF_DEVELOPER_MICROSOFT | 0x0014)

/** @} *** group_ewf_ids_adapter */

/**
 * @defgroup group_ewf_ids_interfaces EWF interface IDs
 * @brief EWF interface IDs
 * @{
 */

#define EWF_INTERFACE_TYPE_WIN32_COM               (EWF_DEVELOPER_MICROSOFT | 0x0001)
#define EWF_INTERFACE_TYPE_LINUX_SERIAL            (EWF_DEVELOPER_MICROSOFT | 0x0002)
#define EWF_INTERFACE_TYPE_STM32_UART              (EWF_DEVELOPER_MICROSOFT | 0x0003)
#define EWF_INTERFACE_TYPE_RA_UART                 (EWF_DEVELOPER_MICROSOFT | 0x0004)
#define EWF_INTERFACE_TYPE_RX_UART                 (EWF_DEVELOPER_MICROSOFT | 0x0005)
#define EWF_INTERFACE_TYPE_LPC_UART                (EWF_DEVELOPER_MICROSOFT | 0x0006)
#define EWF_INTERFACE_TYPE_MICROCHIP_SAM_UART      (EWF_DEVELOPER_MICROSOFT | 0x0007)
#define EWF_INTERFACE_TYPE_MICROCHIP_PIC_UART      (EWF_DEVELOPER_MICROSOFT | 0x0008)
#define EWF_INTERFACE_TYPE_PIC_UART                (EWF_DEVELOPER_MICROSOFT | 0x0009)
#define EWF_INTERFACE_TYPE_ESP32_UART              (EWF_DEVELOPER_MICROSOFT | 0x000A)
#define EWF_INTERFACE_TYPE_RPI_PICO_UART           (EWF_DEVELOPER_MICROSOFT | 0x000B)
#define EWF_INTERFACE_TYPE_GPIO_BIT_BANG           (EWF_DEVELOPER_MICROSOFT | 0x000C)
#define EWF_INTERFACE_TYPE_USBX                    (EWF_DEVELOPER_MICROSOFT | 0x000D)
#define EWF_INTERFACE_TYPE_WINDOWS_USB             (EWF_DEVELOPER_MICROSOFT | 0x000E)
#define EWF_INTERFACE_TYPE_LINUX_USB               (EWF_DEVELOPER_MICROSOFT | 0x000F)

/** @} *** group_ewf_ids_interface */

/**
 * @defgroup group_ewf_ids_allocator EWF allocator IDs
 * @brief EWF allocator IDs
 * @{
 */

#define EWF_ALLOCATOR_TYPE_C_HEAP                  (EWF_DEVELOPER_MICROSOFT | 0x0001)
#define EWF_ALLOCATOR_TYPE_MEMORY_POOL             (EWF_DEVELOPER_MICROSOFT | 0x0002)
#define EWF_ALLOCATOR_TYPE_THREADX                 (EWF_DEVELOPER_MICROSOFT | 0x0003)
#define EWF_ALLOCATOR_TYPE_NETX                    (EWF_DEVELOPER_MICROSOFT | 0x0004)

/** @} *** group_ewf_ids_allocator */

/** @} *** group_ewf_ids */

#endif /* __ewf__ids__h__included__ */
