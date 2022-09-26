/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework host interface API
 ****************************************************************************/

#ifndef __ewf_interface__h__included__
#define __ewf_interface__h__included__

#include "ewf.h"
#include "ewf_platform.h"
#include "ewf_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_interface EWF Interface API
 * Interface is short for Host Interface.
 * This is a software driver that implements the software connection between
 * a ** Network Adapter Driver ** (known simply as an ** adapter driver **
 * in the framework) and the ** Physical Network Adapter **.
 * The Interface can serve as a raw interface for transferring data or provide
 * advanced capabilities to parse a serial AT interface and buffer.
 * Queuing is achieved by using Platform Queues. An interface has one or two
 * associated queues: one for incoming Command Response Messages (or simply
 * messages) and another for data.
 * An interface has a status variable indicating if it is in command mode or not.
 * When in command mode, incoming bytes are interpreted as responses to commands,
 * until OK or an error response is received, then the interface switched to non
 * command mode.
 * In non command mode, the interface will interpret every received message as
 * an Unrequested Return Code or URC.
 * @brief Interfaces are an abstraction and implementations of asynchronous
 * serial communication between adapters and hardware.
 * @{
 ****************************************************************************/

/** @brief The interface message structure declaration */
struct _ewf_interface_message;

/** @brief The interface message structure type definition */
typedef struct _ewf_interface_message ewf_interface_message;

/** @brief The interface tokenizer pattern structure declaration */
struct _ewf_interface_tokenizer_pattern;

/** @brief The interface tokenizer pattern structure type definition */
typedef struct _ewf_interface_tokenizer_pattern ewf_interface_tokenizer_pattern;

/**
 * @brief a function pointer type for response callbacks
 */
typedef ewf_result(*ewf_interface_response_callback)(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t length);

/**
 * @brief a function pointer type for URC callbacks
 */
typedef ewf_result(*ewf_interface_urc_callback)(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t length);

/** @brief The interface message structure definition */
struct _ewf_interface_message
{
    uint8_t* buffer_ptr;
    uint32_t buffer_length;
};

/** @brief The interface tokenizer pattern structure definition */
struct _ewf_interface_tokenizer_pattern
{
    /**< a pointer to the next patter in the list, NULL if no further patters */
    ewf_interface_tokenizer_pattern* netx_ptr;

    /**< a pointer to a NULL terminated string for the pattern */
    const char* pattern_str;

    /**< the length of the patter */
    uint32_t patter_length;

    /**< true if the pattern contains wildcards, false otherwise */
    bool has_wildcards;

    /**< custom function for matching */
    bool(*match_function)(const char* buffer, uint32_t buffer_length, const ewf_interface_tokenizer_pattern* pattern_ptr, bool* stop_ptr);

    /**< pointer to custom data, that can be used by the match function */
    void* data_ptr;
};

/** @brief The interface structure definition */
struct _ewf_interface
{
#ifdef EWF_PARAMETER_CHECKING
    uint32_t struct_magic;
    uint32_t struct_size;
    uint32_t struct_version;
    uint32_t struct_type;
#endif /* EWF_PARAMETER_CHECKING */

#ifdef EWF_PLATFORM_HAS_THREADING
    /**< The access mutex used to synchronize access to internal state */
    ewf_platform_mutex global_mutex;
#endif /* EWF_PLATFORM_HAS_THREADING */

    /**< Current Context ID */
    volatile uint32_t current_context;

    /**<
     * The current message being received
     * This is a serial interface, only one message at a time is being received.
     * There is no interleaving of message types (command or data).
     */
    ewf_interface_message current_message;

    /**< Internal reception mode: command or URC */
    volatile bool command_mode;

    /**< URC processing policy: synchronous or asynchronous */
    volatile bool sync_urc_processing;

    /**< Pointers to the stored interface response callbacks */
    ewf_interface_response_callback response_callback;

    /**< Pointers to the stored interface URC callbacks */
    ewf_interface_urc_callback urc_callback;
    ewf_interface_urc_callback user_urc_callback;

    /**< The message allocator, it might be NULL */
    ewf_allocator* message_allocator_ptr;

    /**< The data allocator, it might be NULL */
    ewf_allocator* data_allocator_ptr;

    /**< The command response queue */
    ewf_platform_queue* response_queue_ptr;

    /**< The urc queue */
    ewf_platform_queue* urc_queue_ptr;

    /* *** Timeout parameters *** */

    /**< The default timeout for all operations */
    volatile uint32_t default_timeout;

    /* *** Tokenizer data *** */

    /**< A pointer to the first on a list of tokenizer patterns for tokenizing command responses, they complete commands and end the command mode */
    ewf_interface_tokenizer_pattern* command_response_end_tokenizer_pattern_ptr;

    /**< A pointer to the first on a list of tokenizer patterns for tokenizing command responses, they do not complete commands and end the command mode */
    ewf_interface_tokenizer_pattern* command_response_tokenizer_pattern_ptr;

    /**< A pointer to the first on a list of tokenizer patterns set by the user for tokenizing URCs */
    ewf_interface_tokenizer_pattern* urc_tokenizer_pattern_ptr;

    /* *** Hardware interface *** */

    /**< A pointer to the hardware start function */
    ewf_result(*hardware_start)(ewf_interface* interface_ptr);

    /**< A pointer to the hardware stop function */
    ewf_result(*hardware_stop)(ewf_interface* interface_ptr);

    /**< A pointer to the hardware send function */
    ewf_result(*hardware_send)(ewf_interface* interface_ptr, const uint8_t* buffer_ptr, uint32_t buffer_length);

    /**< A pointer to the hardware receive function */
    ewf_result(*hardware_receive)(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t* buffer_length_ptr, bool wait);

    /* *** Pointers to other related structures *** */

    /**< The pointer to the adapter */
    struct _ewf_adapter* adapter_ptr;

    /**< The pointer to the implementation data */
    void* implementation_ptr;
};

#define EWF_INTERFACE_STRUCT_MAGIC         (0x017eface) /* ~~ i(n)te(r)face */
#define EWF_INTERFACE_STRUCT_SIZE          (sizeof(struct _ewf_interface))
#define EWF_INTERFACE_VERSION              (EWF_DEVELOPER_MICROSOFT | 0x0001)

#ifdef EWF_PARAMETER_CHECKING
#define EWF_INTERFACE_VALIDATE_POINTER(interface_ptr)                               \
do {                                                                                \
    if ((interface_ptr == NULL) ||                                                  \
        (interface_ptr->struct_magic != EWF_INTERFACE_STRUCT_MAGIC) ||              \
        (interface_ptr->struct_size != EWF_INTERFACE_STRUCT_SIZE) ||                \
        (interface_ptr->struct_version != EWF_INTERFACE_VERSION) ||                 \
        (interface_ptr->implementation_ptr == NULL))                                \
    {                                                                               \
        EWF_LOG_ERROR("The interface pointer is invalid.");                         \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)
#else
#define EWF_INTERFACE_VALIDATE_POINTER(interface_ptr)                               \
do {                                                                                \
    if ((interface_ptr == NULL) ||                                                  \
        (interface_ptr->implementation_ptr == NULL))                                \
    {                                                                               \
        EWF_LOG_ERROR("The interface pointer is invalid.");                         \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)
#endif /* EWF_PARAMETER_CHECKING */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, interface_type)          \
do {                                                                                \
    if ((interface_ptr == NULL) ||                                                  \
        (interface_ptr->struct_type != interface_type) ||                           \
        (interface_ptr->implementation_ptr == NULL))                                \
    {                                                                               \
        EWF_LOG_ERROR("The interface type is invalid.");                            \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)
#else
#define EWF_INTERFACE_VALIDATE_POINTER_TYPE(interface_ptr, interface_type)
#endif

/************************************************************************//**
 * @defgroup group_interface_common Common Interface API
 * @brief Common interface functions
 * @{
 ****************************************************************************/

 /**
  * @brief Initialize the interface
  * This initializes the internal status of the control structure
  * This doesn't start the hardware interface
  * Call ewf_interface_start to start the interface before using it
  * @param[in] interface_ptr A pointer to the interface structure
  * @return #ewf_result status code
  */
ewf_result ewf_interface_init(ewf_interface* interface_ptr);

/**
 * @brief Cleanup the interface
 * This is called after the interface has been stopped
 * It releases resources used by the internal status of interface control structure
 * @param[in] interface_ptr A pointer to the interface structure
 * @return #ewf_result status code
 */
ewf_result ewf_interface_clean(ewf_interface* interface_ptr);

/**
 * @brief Starts the interface
 * @param[in] interface_ptr A pointer to the interface structure
 * @return #ewf_result status code
 */
ewf_result ewf_interface_start(ewf_interface* interface_ptr);

/**
 * @brief Stops the interface
 * @param[in] interface_ptr A pointer to the interface structure
 * @return #ewf_result status code
 */
ewf_result ewf_interface_stop(ewf_interface* interface_ptr);

/**
 * @brief Sends data to the interface
 * @param[in] interface_ptr A pointer to the interface structure
 * @param[in] buffer_ptr a pointer to the buffer to be sent
 * @param[in] buffer_length the length of the data to be sent
 * @return #ewf_result status code
 */
ewf_result ewf_interface_send(ewf_interface* interface_ptr, const uint8_t * buffer_ptr, uint32_t buffer_length);

/**
 * @brief Read a response message from the interface
 * @param[in] interface_ptr A pointer to the interface structure
 * @param[in,out] buffer_ptr_ptr address of a pointer that will receive the response pointer allocated by the interface
 * @param[in,out] buffer_length_ptr address of a variable that will receive the length of the response
 * @param[in] wait_time the number of time units to wait for a response
 * @return #ewf_result status code
 */
ewf_result ewf_interface_receive_response(ewf_interface* interface_ptr, uint8_t** buffer_ptr_ptr, uint32_t* buffer_length_ptr, uint32_t wait_time);

/**
 * @brief Receive a message from the URC queue
 * @param[in] interface_ptr A pointer to the interface structure
 * @param[in,out] buffer address of a pointer that will receive the response pointer allocated by the interface
 * @param[in,out] buffer_length_ptr address of a variable that will receive the length of the response
 * @param[in] wait_time the number of time units to wait for a response
 * @return #ewf_result status code
 */
ewf_result ewf_interface_receive_urc(ewf_interface* interface_ptr, uint8_t** buffer, uint32_t * buffer_length_ptr, uint32_t wait_time);

/**
 * @brief Set the interface message allocator
 * @param[in] interface_ptr A pointer to the interface structure
 * @return #ewf_result status code
 */
ewf_result ewf_interface_message_allocator_set(ewf_interface* interface_ptr, ewf_allocator* allocator_ptr);

/**
 * @brief Set the interface data allocator
 * @param[in] interface_ptr A pointer to the interface structure
 * @return #ewf_result status code
 */
ewf_result ewf_interface_data_allocator_set(ewf_interface* interface_ptr, ewf_allocator * allocator_ptr);

/**
 * @brief Release a message buffer returned by the interface
 * @param[in] interface_ptr A pointer to the interface structure
 * @param[in] buffer_ptr a pointer to the message buffer to be released
 * @return #ewf_result status code
  */
ewf_result ewf_interface_release(ewf_interface* interface_ptr, void * buffer_ptr);
/* TODO: global rename ewf_interface_release -> ewf_interface_release_message */

/**
 * @brief Release a data buffer returned by the interface
 * @param[in] interface_ptr A pointer to the interface structure
 * @param[in] buffer_ptr a pointer to the data buffer to be released
 * @return #ewf_result status code
  */
ewf_result ewf_interface_release_data(ewf_interface * interface_ptr, void* buffer_ptr);

/**
 * @brief Set the interface default timeout value
 * @param[in] interface_ptr A pointer to the interface structure
 * @param[in] timeout the default timeout value, number of ticks to wait for a response
 * @return #ewf_result status code
 */
ewf_result ewf_interface_default_timeout_set(ewf_interface * interface_ptr, uint32_t timeout);

/**
 * @brief Get the current interface default timeout value
 * @param[in] interface_ptr A pointer to the interface structure
 * @param[in,out] timeout_ptr a pointer to a variable that will get the current interface default timeout value
 * @return #ewf_result status code
 */
ewf_result ewf_interface_default_timeout_get(ewf_interface * interface_ptr, uint32_t* timeout_ptr);

/************************************************************************//**
 * @} *** group_interface_common
 ****************************************************************************/

/************************************************************************//**
  * @defgroup group_interface_tokenizer The Interface tokenizer API
  * @brief Functions for setting up and controlling the interface tokenizer
  * @{
  ****************************************************************************/

/**
 * @brief Set the interface command response end tokenizer pattern
 * @param[in] interface_ptr a pointer to the interface data structure
 * @param[in] tokenizer_patter_ptr a pointer to a tokenizer pattern that will be set in the interface as the command response end tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_interface_tokenizer_command_response_end_pattern_set(ewf_interface * interface_ptr, ewf_interface_tokenizer_pattern * tokenizer_patter_ptr);

/**
 * @brief Get the interface command response end tokenizer pattern
 * @param[in] interface_ptr a pointer to the interface data structure
 * @param[in,out] tokenizer_patter_ptr_ptr a pointer to a pointer to a tokenizer pattern that will get the current command response end tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_interface_tokenizer_command_response_end_pattern_get(ewf_interface * interface_ptr, ewf_interface_tokenizer_pattern * *tokenizer_patter_ptr_ptr);

/**
 * @brief Set the interface command response tokenizer pattern
 * @param[in] interface_ptr a pointer to the interface data structure
 * @param[in] tokenizer_patter_ptr a pointer to a tokenizer pattern that will be set in the interface as the current command response tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_interface_tokenizer_command_response_pattern_set(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern* tokenizer_patter_ptr);

/**
 * @brief Get the interface command response tokenizer pattern
 * @param[in] interface_ptr a pointer to the interface data structure
 * @param[in,out] tokenizer_patter_ptr_ptr a pointer to a pointer to a tokenizer pattern that will get the current command response tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_interface_tokenizer_command_response_pattern_get(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern** tokenizer_patter_ptr_ptr);

/**
 * @brief Set the interface URC tokenizer pattern
 * @param[in] interface_ptr a pointer to the interface data structure
 * @param[in] tokenizer_patter_ptr a pointer to a tokenizer pattern that will be set in the interface as the URC tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_interface_tokenizer_urc_pattern_set(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern* tokenizer_patter_ptr);

/**
 * @brief Get the interface URC tokenizer pattern
 * @param[in] interface_ptr a pointer to the interface data structure
 * @param[in,out] tokenizer_patter_ptr_ptr a pointer to a pointer to a tokenizer pattern that will get the URC tokenizer pattern
 * @return #ewf_result status code
 */
ewf_result ewf_interface_tokenizer_urc_pattern_get(ewf_interface* interface_ptr, ewf_interface_tokenizer_pattern** tokenizer_patter_ptr_ptr);

/************************************************************************//**
 * @} *** group_interface_tokenizer
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_interface_hardware Hardware Interface API
 * @brief Hardware interface functions implemented per platform
 * @{
 ****************************************************************************/

/**
 * @brief Called by the hardware code to process an incoming byte
 * When the hardware interface receives a byte it used this function
 * to pase this byte to the common code for further processing.
 * Typically used to process commands, when in command mode.
 * @param[in] interface_ptr a pointer to the interface data structure
 * @param[in] b the incomming byte to be processed
 * @return #ewf_result status code
 */
ewf_result ewf_interface_process_byte(ewf_interface* interface_ptr, uint8_t b);

/**
 * @brief Called by the hardware code to process a buffer
 * When the hardware interface receives a byte it used this function
 * to pase this byte to the common code for further processing.
 * Typically used to process data.
 * @param[in] interface_ptr a pointer to the interface data structure
 * @param[in] buffer_ptr a pointer to the incomming buffer to be processed
 * @param[in] buffer_length the size of the data pointe by the buffer_ptr parameter
 * @return #ewf_result status code
 */
ewf_result ewf_interface_process_buffer(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/************************************************************************//**
 * @} *** group_interface_hardware
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_interface_urc Interface URC processing
 * @brief The host interface URC processing
 * @{
 ****************************************************************************/

/**
 * @brief Call periodically to process URCs
 * This is called internally by the URC thread.
 * Call manually if there is not threading.
 * @return #ewf_result status code
 */
ewf_result ewf_interface_urc_processing(ewf_interface* interface_ptr);

/**
 * @brief Process a URC message
 * @return #ewf_result status code
 */
ewf_result ewf_interface_urc_process_message(ewf_interface* interface_ptr, uint8_t* buffer_ptr, uint32_t buffer_length);

/************************************************************************//**
 * @} *** group_interface_urc
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_interface_polling Host interface polling calls
 * @brief The host interface polling calls
 * @{
 ****************************************************************************/

ewf_result ewf_interface_poll(ewf_interface* interface_ptr);

ewf_result ewf_interface_receive_poll(ewf_interface* interface_ptr);

/************************************************************************//**
 * @} *** group_interface_polling
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_interface_callback Interface callback API
 * @brief Asynchronous callback interface
 * @{
 ****************************************************************************/

/**
 * @brief register a user callback for responses
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_set_response_callback(ewf_interface* interface_ptr, ewf_interface_response_callback callback);

/**
 * @brief register a callback for URC
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_set_urc_callback(ewf_interface* interface_ptr, ewf_interface_urc_callback callback);

/**
 * @brief register a user callback for URC
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_set_user_urc_callback(ewf_interface* interface_ptr, ewf_interface_urc_callback callback);

/************************************************************************//**
 * @} *** group_interface_callback
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_interface_helpers Interface helper functions
 * @brief Helper interface functions
 * @{
 ****************************************************************************/

/**
 * @brief Send a command
 * @param command_str a pointer to a null terminated string with the command to be sent
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_send_command(ewf_interface* interface_ptr, const char * command_str);

/**
 * @brief Send a command
 * @param command_str a pointer to a null terminated string with the command to be sent
 * This function will take one or more string pointers and it should be terminated with
 * a last parameter equal to NULL
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_send_commands(ewf_interface* interface_ptr, const char * command_str, ...);

/**
 * @brief Drop all responses from the interface
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_drop_all_responses(ewf_interface* interface_ptr);

/**
 * @brief Drop a single response from the interface
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_drop_response(ewf_interface* interface_ptr);

/**
 * @brief Get a response from the interface
 * @param a pointer to a pointer that will hold the response on return
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_get_response(ewf_interface* interface_ptr, uint8_t ** response_out);

/**
 * @brief Verify an interface response
 * @param[in] expected_str a pointer to a NULL terminated string that will be compared
 * agains the interface response. If different, the function will return an error
 * code, if equal, the function will return a success code.
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_verify_response(ewf_interface* interface_ptr, const char  * expected_str);

/**
 * @brief Verify an interface responses
 * @param[in] expected_str_arr is array of NULL terminated strings that will be compared
 * against the interface response. If different, the function will return an error
 * code, if match is found, the function will return a success code.
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_verify_responses(ewf_interface* interface_ptr, uint32_t response_count, const char ** expected_str_arr);

/**
 * @brief Verify if interface response starts with expected string
 * @param[in] expected_start_str a pointer to a NULL terminated string that will be compared
 * against the interface response. If different, the function will return an error
 * code, if equal or starts with expected string, the function will return a success code.
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_verify_response_starts_with(ewf_interface* interface_ptr, const char * expected_start_str);

/**
 * @brief Verify if interface response starts with expected string
 * @param[in] expected_end_str a pointer to a NULL terminated string that will be compared
 * against the interface response. If different, the function will return an error
 * code, if equal or ends with expected string, the function will return a success code.
 * @return #ewf_result success and error conditions
 */
ewf_result ewf_interface_verify_response_ends_with(ewf_interface* interface_ptr, const char* expected_end_str);

/************************************************************************//**
 * @} *** group_interface_helpers
 ****************************************************************************/

/************************************************************************//**
 * @} *** group_interface
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_interface__h__included__ */
