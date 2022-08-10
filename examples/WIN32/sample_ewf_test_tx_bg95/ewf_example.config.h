/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework example configuration.
 ****************************************************************************/

#ifndef __ewf_example_conf__h__included__
#define __ewf_example_conf__h__included__

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_example_configuration EWF example configuration
 * @brief The definitions to configure the sample software.
 * @{
 ****************************************************************************/

/** @brief The SIM PIN for the modem */
#define EWF_CONFIG_SIM_PIN "0000"

/** @brief The IoT Hub hostname */
#define EWF_CONFIG_IOT_HUB_HOSTNAME "andrejm-test-iot-hub.azure-devices.net"

/** @brief The device ID */
#define EWF_CONFIG_IOT_HUB_DEVICEID "andrejm-test-win32-bg96-cert"

/** @brief Define the WIN32 COM port interface serial port file name */
#define EWF_CONFIG_INTERFACE_WIN32_COM_PORT_FILE_NAME      ("\\\\.\\COM62")

/** @brief Define the WIN32 COM port interface serial port baud rate */
#define EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BAUD_RATE      (CBR_115200)

/** @brief Define the WIN32 COM port interface serial port byte size */
#define EWF_CONFIG_INTERFACE_WIN32_COM_PORT_BYTE_SIZE      (8)

/** @brief Define the WIN32 COM port interface serial port parity */
#define EWF_CONFIG_INTERFACE_WIN32_COM_PORT_PARITY         (NOPARITY)

/** @brief Define the WIN32 COM port interface serial stop bits */
#define EWF_CONFIG_INTERFACE_WIN32_COM_PORT_STOP_BITS      (ONESTOPBIT)

/** @brief The test server hostname */
#define EWF_CONFIG_TEST_SERVER_HOSTNAME (andrejm-ewf-test-server.azurewebsites.net)

/** @brief The test server TCP port */
#define EWF_CONFIG_TEST_SERVER_TCP_PORT (7770)

/** @brief The test server UDP port */
#define EWF_CONFIG_TEST_SERVER_UDP_PORT (7780)

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */
