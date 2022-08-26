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

/**
 * @defgroup group_example_configuration_allocator Allocator configuration
 * @brief Allocator configuration settings used in examples
 * @{
 */

/** @brief the number of allocator blocks */
#define EWF_CONFIG_ALLOCATOR_BLOCK_COUNT                            (16)

/** @brief the size of each blocks allocator block */
#define EWF_CONFIG_ALLOCATOR_BLOCK_SIZE                             (1024)

/** @} *** group_example_configuration_allocator */

/**
 * @defgroup group_example_configuration_interface Interface configuration
 * @brief Interface configuration settings used in examples
 * @{
 */

/** @brief Define the WIN32 COM port interface serial port file name */
#define EWF_CONFIG_INTERFACE_LPC_UART_BASE_ADDRESS                  (USART2)

/** @brief Define the WIN32 COM port interface serial port baud rate */
#define EWF_CONFIG_INTERFACE_LPC_UART_BAUD_RATE                     (115200U)

/** @} *** group_example_configuration_interface */

/**
 * @defgroup group_example_configuration_modem Modem configuration
 * @brief Modem configuration settings used in examples
 * @{
 */

/** @brief The SIM PIN for the modem */
#define EWF_CONFIG_SIM_PIN                                          ("0000")

/** @brief The modem context ID used */
#define EWF_CONFIG_CONTEXT_ID                                       (1)

/** @} *** group_example_configuration_modem */

/************************************************************************//**
 * @} *** group_example_configuration
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_example_conf__h__included__ */
