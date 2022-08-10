#include "ewf_lib.h"


ewf_result ewf_adapter_test_ping();
ewf_result ewf_adapter_test_dns();
ewf_result ewf_adapter_test_ntp();
ewf_result ewf_adapter_test_http();
ewf_result ewf_adapter_test_ufs();
ewf_result ewf_adapter_test_tcp();
ewf_result ewf_adapter_test_udp();


ewf_result ewf_adapter_test()
{
    ewf_result result;

    // Adapter tests - ping
    result = ewf_adapter_test_ping();
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter ping test: az_result return code 0x%08x.", result);
    }

    // Adapter tests - DNS
    result = ewf_adapter_test_dns();
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter DNS test: az_result return code 0x%08x.", result);
    }

    // Adapter tests - NTP
    result = ewf_adapter_test_ntp();
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter NTP test: az_result return code 0x%08x.", result);
    }

    // Adapter tests - HTTP
    result = ewf_adapter_test_http();
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter HTTP test: az_result return code 0x%08x.", result);
    }

    // Adapter tests - TCP
    result = ewf_adapter_test_tcp();
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP test: az_result return code 0x%08x.", result);
    }

    // Adapter tests - UDP
    result = ewf_adapter_test_udp();
    if (ewf_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to run the adapter TCP test: az_result return code 0x%08x.", result);
    }

    return EWF_RESULT_OK;
}


ewf_result ewf_adapter_test_dns()
{
  return EWF_RESULT_OK;
}


ewf_result ewf_adapter_test_ping()
{
  return EWF_RESULT_OK;
}


ewf_result ewf_adapter_test_ntp()
{
  return EWF_RESULT_OK;
}


ewf_result ewf_adapter_test_http()
{
  return EWF_RESULT_OK;
}


ewf_result ewf_adapter_test_ufs()
{
  return EWF_RESULT_OK;
}


ewf_result ewf_adapter_test_tcp()
{
    const char http_server[] = "www.microsoft.com";
    unsigned http_host_port = 80;
    const char http_message[] = "GET / HTTP/1.1\r\nHost:www.microsoft.com\r\n\r\n";
    unsigned http_message_length = sizeof(http_message) - 1;
    static char buffer[2048];
    unsigned buffer_length = sizeof(buffer);

    ewf_result result;
    int socket = -1;

    EWF_LOG("WinSock2 adapter TCP test starting...\n");

    EWF_LOG("Connecting to server %s...\n", http_server);
    if (ewf_result_failed(result = ewf_adapter_tcp_connect(&socket, http_server, http_host_port))) return result;
    EWF_LOG("Connected\n");

    EWF_LOG("Sending message %s\n", http_message);
    if (ewf_result_failed(result = ewf_adapter_tcp_send(socket, http_message, http_message_length))) return result;
    EWF_LOG("Message sent\n");

    EWF_LOG("Receving message...\n");
    if (ewf_result_failed(result = ewf_adapter_tcp_receive(socket, buffer, &buffer_length, true))) return result;
    EWF_LOG("Message received: %.*s\n", buffer_length, buffer);

    EWF_LOG("Closing socket...\n");
    if (ewf_result_failed(result = ewf_adapter_tcp_close(socket))) return result;
    EWF_LOG("Socked closed.\n");

    EWF_LOG("WinSock2 adapter TCP test finished successfully.\n");

    return EWF_RESULT_OK;
}

ewf_result ewf_adapter_test_udp()
{
  return EWF_RESULT_OK;
}
