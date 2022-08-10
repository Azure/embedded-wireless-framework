/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @details
 * The Embedded Wireless Framework HTTP/HTTPS API
 * (Reference : RFC2616, RFC2626)
 ****************************************************************************/

#ifndef __ewf_adapter_http__h__included__
#define __ewf_adapter_http__h__included__

#include "ewf_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************//**
 *
 * @defgroup group_adapter_modem_http Modem adapter http API
 * @ingroup group_adapter_api
 * @brief HTTP functions
 * @{
 *
 ****************************************************************************/
typedef struct _ewf_adapter_api_http
{
    ewf_result(*open)(ewf_adapter* adapter_ptr, ewf_http_socket * http_socket_ptr);
    ewf_result(*close)(ewf_adapter* adapter_ptr, ewf_http_socket http_socket);
    ewf_result(*context_configure)(ewf_adapter* adapter_ptr,ewf_http_socket http_socket,
                                                            uint8_t context_id, uint8_t sprofile_id, const char * server_addr,
                                                            uint16_t server_port, bool auth_type, const char * username_str,
                                                            const char * password_str, bool ssl_enabled, uint32_t timeout);
    ewf_result(*get)(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                              const char * uri,
                                              char ** response_ptr_ptr, uint32 * response_length_ptr);
    ewf_result(*head)(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                               const char * uri_str,
                                               char ** response_ptr_ptr, uint32 * response_length_ptr);
    ewf_result(*delete)(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                                 const char * uri_str,
                                                 char ** response_ptr_ptr, uint32 * response_length_ptr);
    ewf_result(*post)(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                               const char * uri_str,
                                               const char * data,  uint8_t content_type,
                                               char ** response_ptr_ptr, uint32 * response_length_ptr);
    ewf_result(*put)(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                              const char * uri_str
                                              const char * data_str, uint8_t content_type,
                                              char ** response_ptr_ptr, uint32 * response_length_ptr);

} ewf_adapter_api_http;
typedef int ewf_http_socket;

/**
 * @brief Open an HTTP socket
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in,out] http_socket_ptr A pointer to an HTTP socket that will receive will initialized on open
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_http_open(ewf_adapter* adapter_ptr, ewf_http_socket * http_socket_ptr);

/**
 * @brief Close an HTTP socket
 * @param[in] http_socket Socket number used as HTTP Profile ID
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_http_close(ewf_adapter* adapter_ptr, ewf_http_socket http_socket);

/**
 * @brief HTTP client configuration
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] http_socket The HTTP socket
 * @param[in] context_id PDP context ID
 * @param[in] sprofile_id Secure profile ID
 * @param[in] server_addr String containing server IP address or server name
 * @param[in] server_port HTTP server port
 * @param[in] auth_type Authentication method/type (No Authentication/ Basic Authentication)
 * @param[in] username_str String indicating username for HTTP login
 * @param[in] password_str String indicating passowrd for HTTP login
 * @param[in] ssl_enabled HTTP secure option enable/disable
 * @param[in] timeout Timeout in seconds
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_http_context_configure(ewf_adapter* adapter_ptr,ewf_http_socket http_socket,
                                                        uint8_t context_id, uint8_t sprofile_id, const char * server_addr,
                                                        uint16_t server_port, bool auth_type, const char * username_str,
                                                        const char * password_str, bool ssl_enabled, uint32_t timeout);

/**
 * @brief HTTP GET request
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] http_socket The HTTP socket
 * @param[in] uri HTTP resource (uri)
 * @param[out] response_ptr Response for the HTTP request, if available
 * @param[out] response_length_ptr Pointer to lenght of response
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_http_get(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                          const char * uri,
                                          char ** response_ptr_ptr, uint32 * response_length_ptr);

/**
 * @brief HTTP HEAD request
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] http_socket The HTTP socket
 * @param[in] uri_str HTTP resource (uri)
 * @param[out] response_ptr_ptr Response for the HTTP request, if available
 * @param[out] response_length_ptr Pointer to lenght of response
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_http_head(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                           const char * uri_str,
                                           char ** response_ptr_ptr, uint32 * response_length_ptr);

/**
 * @brief HTTP DELETE request
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] http_socket The HTTP socket
 * @param[in] uri_str HTTP resource (uri)
 * @param[out] response_ptr_ptr Response for the HTTP request, if available
 * @param[out] response_length_ptr Pointer to lenght of response
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_http_delete(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                             const char * uri_str,
                                             char ** response_ptr_ptr, uint32 * response_length_ptr);

/**
 * @brief HTTP POST request
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] http_socket The HTTP socket
 * @param[in] uri_str HTTP resource (uri)
 * @param[in] data Data to be sent
 * @param[in] content_type HTTP Content-Type identifier. Refer the modem user manual for supported types
 * @param[out] response_ptr_ptr Response for the HTTP request, if available
 * @param[out] response_length_ptr Pointer to lenght of response
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_http_post(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                           const char * uri_str,
                                           const char * data,  uint8_t content_type,
                                           char ** response_ptr_ptr, uint32 * response_length_ptr);

/**
 * @brief HTTP PUT request
 * @param[in] adapter_ptr A pointer to the adapter structure
 * @param[in] http_socket The HTTP socket
 * @param[in] uri_str HTTP resource (uri)
 * @param[in] data_str Data to be sent
 * @param[in] content_type HTTP Content-Type identifier. Refer the modem user manual for supported types
 * @param[out] response_ptr_ptr Response for the HTTP request, if available
 * @param[out] response_length_ptr Pointer to lenght of response
 * @return #ewf_result status code
 */
ewf_result ewf_adapter_http_put(ewf_adapter* adapter_ptr, ewf_http_socket http_socket,
                                          const char * uri_str
                                          const char * data_str, uint8_t content_type,
                                          char ** response_ptr_ptr, uint32 * response_length_ptr);

/************************************************************************//**
 * @}
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __ewf_adapter_http__h__included__ */
