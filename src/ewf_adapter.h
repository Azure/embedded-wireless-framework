/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework adapter API implementation
 ****************************************************************************/

#ifndef __ewf_adapter__h__included__
#define __ewf_adapter__h__included__

#include "ewf.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 * @defgroup group_adapter_api The EWF Adapter APIs
 * @brief The EWF Adapter APIs
 * @{
 ****************************************************************************/

/* Include the headers for the different adapter APIs */

#include "ewf_adapter_api_urc.h"
#include "ewf_adapter_api_control.h"
#include "ewf_adapter_api_wifi_station.h"
#include "ewf_adapter_api_info.h"
#include "ewf_adapter_api_tls.h"
#include "ewf_adapter_api_tls_basic.h"
#include "ewf_adapter_api_dtls.h"
#include "ewf_adapter_api_tcp.h"
#include "ewf_adapter_api_udp.h"
#include "ewf_adapter_api_mqtt.h"
#include "ewf_adapter_api_mqtt_basic.h"

/************************************************************************//**
 * @}
 ****************************************************************************/

/************************************************************************//**
 * @defgroup group_adapter EWF Adapter API
 * @brief Adapters are the hardware or software devices uses to communicate with the network.
 * @{
 ****************************************************************************/

/** @brief The EWF network adapter control structure definition */
struct _ewf_adapter
{
#ifdef EWF_PARAMETER_CHECKING
    uint32_t struct_magic;
    uint32_t struct_size;
    uint32_t struct_version;
    uint32_t struct_type;
#endif /* EWF_PARAMETER_CHECKING */

    ewf_adapter_api_control* control_api_ptr;

    union { /* Only adapter specific control APIs */
        struct {
            ewf_adapter_wifi_station_api* wifi_station_api_ptr;
        };
    };

    ewf_adapter_api_info* info_api_ptr;

    union { /* Only one TLS API per adapter */
        ewf_adapter_api_tls_basic* tls_basic_api_ptr;
        ewf_adapter_api_tls* tls_api_ptr;
    };

    ewf_adapter_api_dtls* dtls_api_ptr;

    ewf_adapter_api_tcp* tcp_api_ptr;

    ewf_adapter_api_udp* udp_api_ptr;

    union { /* Only one MQTT API per adapter */
        ewf_adapter_api_mqtt_basic* mqtt_basic_api_ptr;
        ewf_adapter_api_mqtt* mqtt_api_ptr;
    };

    /**<
     * a pointer to an interface, NULL if there is no associated interface
     */
    struct _ewf_interface * interface_ptr;

    /**<
     * A pointer to the adapter implementation data.
     * a pointer to an interface, if any
     * a pointer to one or more allocators
     * (typically one for non-interface adapters,
     *  or two for interface adapters: one for commands, one for data)
     */
    void* implementation_ptr;
};

#define EWF_ADAPTER_STRUCT_MAGIC           (0x000ADA7E) /* ~~ ada(p)te(r) */
#define EWF_ADAPTER_STRUCT_SIZE            (sizeof(struct _ewf_adapter))
#define EWF_ADAPTER_VERSION                (EWF_DEVELOPER_MICROSOFT | 0x0001)

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr)                                   \
do {                                                                                \
    if ((adapter_ptr == NULL) ||                                                    \
        (adapter_ptr->struct_magic != EWF_ADAPTER_STRUCT_MAGIC) ||                  \
        (adapter_ptr->struct_size != EWF_ADAPTER_STRUCT_SIZE) ||                    \
        (adapter_ptr->struct_version != EWF_ADAPTER_VERSION) ||                     \
        (adapter_ptr->implementation_ptr == NULL))                                  \
    {                                                                               \
        EWF_LOG_ERROR("The adapter pointer is invalid.\n");                         \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)
#else
#define EWF_ADAPTER_VALIDATE_POINTER(allocator_ptr)                                 \
do {                                                                                \
    if ((adapter_ptr == NULL) ||                                                    \
        (adapter_ptr->implementation_ptr == NULL))                                  \
    {                                                                               \
        EWF_LOG_ERROR("The adapter pointer is invalid.\n");                         \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)
#endif /* EWF_PARAMETER_CHECKING */

#ifdef EWF_PARAMETER_CHECKING
#define EWF_ADAPTER_VALIDATE_POINTER_TYPE(adapter_ptr, adapter_type)                \
do {                                                                                \
    if ((adapter_ptr == NULL) ||                                                    \
        (adapter_ptr->struct_magic != EWF_ADAPTER_STRUCT_MAGIC) ||                  \
        (adapter_ptr->struct_size != EWF_ADAPTER_STRUCT_SIZE) ||                    \
        (adapter_ptr->struct_version != EWF_ADAPTER_VERSION) ||                     \
        (adapter_ptr->struct_type != adapter_type))                                 \
    {                                                                               \
        EWF_LOG_ERROR("The adapter type is invalid.\n");                            \
        return EWF_RESULT_INVALID_FUNCTION_ARGUMENT;                                \
    }                                                                               \
} while(0)
#else
#define EWF_ADAPTER_VALIDATE_POINTER_TYPE(interface_ptr, interface_type)
#endif

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter__h__included__ */
