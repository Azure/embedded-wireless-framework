
#ifndef __pic32cmls60_curiosity_commands__h__included__
#define __pic32cmls60_curiosity_commands__h__included__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
    
#include "azure/core/az_span.h"
#include "azure/core/az_json.h"
#include "azure/core/az_http.h"

#define RETURN_ERR_IF_FAILED(ret)  \
    do                             \
    {                              \
        if (az_result_failed(ret)) \
        {                          \
            return ret;            \
        }                          \
    } while (0)

#define RETURN_IF_FAILED(ret)      \
    do                             \
    {                              \
        if (az_result_failed(ret)) \
        {                          \
            return;                \
        }                          \
    } while (0)

#define RETURN_ERR_WITH_MESSAGE_IF_FAILED(ret, msg) \
    do                                              \
    {                                               \
        if (az_result_failed(ret))                  \
        {                                           \
            printf(msg);                            \
            return ret;                             \
        }                                           \
    } while (0)

#define RETURN_WITH_MESSAGE_IF_FAILED(ret, msg) \
    do                                          \
    {                                           \
        if (az_result_failed(ret))              \
        {                                       \
            debug_printError(msg);              \
            return;                             \
        }                                       \
    } while (0)

#define EXIT_WITH_MESSAGE_IF_FAILED(ret, msg) \
    do                                        \
    {                                         \
        if (az_result_failed(ret))            \
        {                                     \
            debug_printError(msg);            \
            exit(1);                          \
        }                                     \
    } while (0)

extern uint32_t SYS_rebootTimer;
    
az_result start_json_object(
    az_json_writer* jw,
    az_span         az_span_buffer);

az_result end_json_object(
    az_json_writer* jw);

az_result append_json_property_int32(
    az_json_writer* jw,
    az_span         property_name_span,
    int32_t         property_val);

az_result append_json_property_string(
    az_json_writer* jw,
    az_span         property_name_span,
    az_span         property_val_span);

az_result COMMAND_Handler_reboot(
    az_span   payload_span,
    az_span   response_span,
    az_span*  out_response_span);

az_result COMMAND_Handler_sendMsg(
    az_span   payload_span,
    az_span   response_span,
    az_span*  out_response_span);

#ifdef __cplusplus
}
#endif

#endif /* __pic32cmls60_curiosity_commands__h__included__ */

