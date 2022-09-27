/************************************************************************//**
 * @file
 * @version Preview
 * @copyright Copyright (c) Microsoft Corporation. All rights reserved.
 * SPDX-License-Identifier: MIT
 * @brief The Embedded Wireless Framework Espressif common adapter driver test
 ****************************************************************************/

#include "ewf_adapter_test.h"
#include "ewf_adapter_espressif_common.h"

ewf_result ewf_adapter_espressif_common_test(ewf_adapter* adapter_ptr);

ewf_result ewf_adapter_espressif_common_test_ping(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_espressif_common_test_dns(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_espressif_common_test_ntp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_espressif_common_test_http(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_espressif_common_test_tcp(ewf_adapter* adapter_ptr);
ewf_result ewf_adapter_espressif_common_test_udp(ewf_adapter* adapter_ptr);

/**
 * @brief Run all adapter tests
 */
ewf_result ewf_adapter_espressif_common_test(ewf_adapter* adapter_ptr)
{
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_result result;

    // Adapter tests - ping
    result = ewf_adapter_espressif_common_test_ping(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter ping test: ewf_result %d.\n", result);
    }

    // Adapter tests - DNS
    result = ewf_adapter_espressif_common_test_dns(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter DNS test: ewf_result %d.\n", result);
    }

    // Adapter tests - NTP
    result = ewf_adapter_espressif_common_test_ntp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter NTP test: ewf_result %d.\n", result);
    }

    // Adapter tests - HTTP
    result = ewf_adapter_espressif_common_test_http(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter HTTP test: ewf_result %d.\n", result);
    }

    // Adapter tests - TCP
    result = ewf_adapter_espressif_common_test_tcp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP test: ewf_result %d.\n", result);
    }

    // Adapter tests - UDP
    result = ewf_adapter_espressif_common_test_udp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter UDP test: ewf_result %d.\n", result);
    }

    // Adapter tests - TCP
    result = ewf_adapter_test_api_tcp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP test: ewf_result %d.\n", result);
    }

    // Adapter tests - UDP
    result = ewf_adapter_test_api_udp(adapter_ptr);
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter UDP test: ewf_result %d.\n", result);
    }

    return EWF_RESULT_OK;
}

/**
 * @brief The ESPRESSIF adapter ping test
 */
ewf_result ewf_adapter_espressif_common_test_ping(ewf_adapter* adapter_ptr)
{
    return EWF_RESULT_OK;
}

/**
 * @brief The ESPRESSIF adapter ping test
 */
ewf_result ewf_adapter_espressif_common_test_dns(ewf_adapter* adapter_ptr)
{
    return EWF_RESULT_OK;
}

/**
 * @brief The ESPRESSIF adapter NTP test
 */
ewf_result ewf_adapter_espressif_common_test_ntp(ewf_adapter* adapter_ptr)
{
    return EWF_RESULT_OK;
}

/**
 * @brief The ESPRESSIF adapter HTTP test
 */
ewf_result ewf_adapter_espressif_common_test_http(ewf_adapter* adapter_ptr)
{
    return EWF_RESULT_OK;
}

/**
 * @brief The ESPRESSIF adapter TCP test
 */
ewf_result ewf_adapter_espressif_common_test_tcp(ewf_adapter* adapter_ptr)
{
    return EWF_RESULT_OK;
}

/**
 * @brief The ESPRESSIF adapter UDP test
 */
ewf_result ewf_adapter_espressif_common_test_udp(ewf_adapter* adapter_ptr)
{
    return EWF_RESULT_OK;
}
