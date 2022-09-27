/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework
 ****************************************************************************/

#ifndef __ewf__h__included__
#define __ewf__h__included__

/************************************************************************//**
 * Define the Doxygen groups order
 * @defgroup group_ewf_ids
 * @defgroup group_configuration The EWF configurable settings
 * @brief The EWF configurable settings
 * @defgroup group_ewf
 * @defgroup group_lib
 * @defgroup group_adapter_api
 * @defgroup group_adapter
 * @defgroup group_interface
 * @defgroup group_allocator
 * @defgroup group_platform
 ****************************************************************************/

#include "ewf.config.h"

#include "ewf_ids.h"

#ifdef EWF_DEBUG
#include <stdio.h>
#endif

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_ewf EWF result codes, status test macros and logging
 * @brief Definition of result codes, macros for their evaluation, logging macros and developer ID definitions
 * @{
 ****************************************************************************/

/**
 * @defgroup group_ewf_result_codes EWF result codes
 * @brief EWF result codes and type definitions
 * @{
 */

/** @brief Success and error result codes specific to the EWF API. */
enum _ewf_result;
    
/** @brief Success and error result codes specific to the EWF API. */
typedef enum _ewf_result ewf_result;

/**
 * @brief Success and error result codes specific to the EWF API.
 */
enum _ewf_result
{
    /* Non error results - positive or zero */

    EWF_RESULT_OK                               = 0,    /**< The function completed successfully */

    EWF_RESULT_UNHANDLED_URC                    = 1,    /**< The URC has not been handled. */

    EWF_RESULT_NO_DATA_AVAILABLE                = 2,    /**< There is not data available. */

    /* Error results - negative */

    EWF_RESULT_INVALID_FUNCTION_ARGUMENT        = -1,   /**< An invalid value has been passed to the function. */
    EWF_RESULT_OUT_OF_MEMORY                    = -2,   /**< The system ran out of memory. */
    EWF_RESULT_NOT_SUPPORTED                    = -3,   /**< Unsupported functionality . */
    EWF_RESULT_TIMEOUT                          = -4,   /**< Timeout */
    EWF_RESULT_IRRECOVERABLE_ERROR              = -5,   /**< Irrecoverable error */

    EWF_RESULT_UNEXPECTED_RESPONSE              = -50,  /**< Unexpected adapter response. */

    EWF_RESULT_EMPTY_QUEUE                      = -80,  /**< The queue is empty. */
    EWF_RESULT_FULL_QUEUE                       = -81,  /**< The queue is full. */

    EWF_RESULT_CONNECTION_FAILED                = -101, /**< Failed to connect. */
    EWF_RESULT_RECEPTION_FAILED                 = -102, /**< The reception failed. */
    EWF_RESULT_NO_DATA_RECEIVED                 = -103, /**< No data has been received. */

    EWF_RESULT_TOO_MANY_OPEN_SOCKETS            = -201, /**< Too many open sockets, the adpater limit has been reached. */
    EWF_RESULT_INVALID_SOCKET                   = -202, /**< Invalid socket value. */
    EWF_RESULT_SOCKET_NOT_OPEN                  = -203, /**< The socket is not open. */

    EWF_RESULT_INTERFACE_INITIALIZATION_FAILED  = -301, /**< The interface initialization failed. */
    EWF_RESULT_INTERFACE_SEND_FAILED            = -302, /**< The interface failed to send. */
    EWF_RESULT_INTERFACE_RECEIVE_FAILED         = -303, /**< The interface failed to receive. */

    EWF_RESULT_ADAPTER_INITIALIZATION_FAILED    = -401, /**< The adapter initialization failed. */
    EWF_RESULT_ADAPTER_RESPONDED_ERROR          = -402, /**< The adapter responded with an error message. */
    EWF_RESULT_ADAPTER_RECEIVE_FAILED           = -403, /**< An adapter receive operation failed. */
    EWF_RESULT_ADAPTER_TRANSMIT_FAILED          = -404, /**< An adapter transmit operation failed. */

    EWF_RESULT_ALLOCATOR_INITIALIZATION_FAILED  = -501, /**< The allocator initialization failed. */

    EWF_RESULT_MODEM_NETWORK_NOT_REGISTERED     = -601, /**< The modem not registered to network */
};

/** @} // group_ewf_result_codes */

/**
 * @defgroup group_ewf_result_macros EWF result macros
 * @brief EWF macros for result code testing and evaluation
 * @{
 */

 /**
  * @brief Returns true if the passed code is an error, false if not.
  */
#define ewf_result_failed(code) (EWF_RESULT_OK > (code))

  /**
   * @brief Returns true if the code passed indicates success, false if it is an error.
   */
#define ewf_result_succeeded(code) ((code) >= EWF_RESULT_OK)

/** @} // group_ewf_result_macros */

/**
 * @defgroup group_ewf_logging EWF logging macros
 * @brief EWF logging macros
 * @details
 * There are two macros used for logging information and errors.
 * These are EWF_LOG and EWF_LOG_ERROR.
 * You can define these symbols with your custom implementation before
 * including this file, then these implementations are not defined.
 * @{
 */

#ifndef EWF_LOG
#ifndef EWF_DEBUG
#define EWF_LOG(...)
#else
#define EWF_LOG(...)                                                            \
do {                                                                            \
    (void)fprintf(stdout, __VA_ARGS__);                                         \
    (void)fflush(stdout);                                                       \
} while (0)
#endif
#endif

#ifndef EWF_LOG_ERROR
#ifndef EWF_DEBUG
#define EWF_LOG_ERROR(...)
#else
#define EWF_LOG_ERROR(...)                                                      \
do {                                                                            \
    EWF_LOG(                                                                    \
        "\n\n"                                                                  \
        "ERROR:\n"                                                              \
        "[%s]:[%d]\n"                                                           \
        "function: [%s]\n\n",                                                   \
        __FILE__, __LINE__, __func__);                                          \
    EWF_LOG(__VA_ARGS__);                                                       \
} while (0)
#endif
#endif

/** @} // group_ewf_logging */

/**
 * @defgroup group_ewf_types The EWF types
 * @brief The EWF types
 * @{
 */

/** @brief The adapter struct type declaration */
struct _ewf_adapter;

/** @brief The adapter type definition */
typedef struct _ewf_adapter ewf_adapter;

/** @brief The interface structure declaration */
struct _ewf_interface;

/** @brief The interface type definition */
typedef struct _ewf_interface ewf_interface;

/** @breif The allocator structure declaration */
struct _ewf_allocator;

/** @breif The allocator type definition */
typedef struct _ewf_allocator ewf_allocator;

/** @} // group_ewf_types */

/* Disable warning of parameter not used. */

/**
 * @defgroup group_ewf_utils The EWF utilities
 * @brief The EWF utilities
 * @{
 */

#ifndef EWF_PARAMETER_NOT_USED
#define EWF_PARAMETER_NOT_USED(p) ((void)(p))
#endif /* EWF_PARAMETER_NOT_USED */

/** @} // group_ewf_utils */

/************************************************************************//**
 * @} // group_ewf
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf__h__included__ */
