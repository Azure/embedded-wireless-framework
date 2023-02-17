#include "ewf_example_lwip_ppp_test.h"
#include "ewf_lwip_ppp.h"


#define REMOTE_HOST "www.microsoft.com"
#define REMOTE_PORT 80
#define REQUEST "GET / HTTP/1.1\r\nHost: www.microsoft.com\r\n\r\n"
ewf_result ewf_example_lwip_ppp_http_get_test();


ewf_result ewf_example_lwip_ppp_test(ewf_adapter* adapter_ptr)
{
    ewf_result result;
    
    /* Enter Data Mode.  */
    if (ewf_result_failed(result = ewf_adapter_data_mode_enter(adapter_ptr, EWF_CONFIG_CONTEXT_ID)))
    {
        EWF_LOG_ERROR("Failed Enter data mode: ewf_result %d.\n", result);
        exit(result);
    }

    if (ewf_result_failed(result = ewf_lwip_ppp_config(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed configure PPP: ewf_result %d.\n", result);
        exit(result);
    }

    /* Link is fully up and operational. All LWIP activities are now available.
       Send a HTTP GET request over tcp */
    ewf_example_lwip_ppp_http_get_test();

    /* Exit Data Mode. */
    if (ewf_result_failed(result = ewf_adapter_data_mode_exit(adapter_ptr)))
    {
        EWF_LOG_ERROR("Failed to exit data mode: ewf_result %d.\n", result);
        exit(result);
    }

    return EWF_RESULT_OK;
}

ewf_result ewf_example_lwip_ppp_http_get_test()
{
    struct netconn* conn;
    err_t err;
    struct netbuf* buf;
    void* data;
    u16_t len;

    // Get the IP address of the remote host
    ip_addr_t remote_ip;
    err = netconn_gethostbyname(REMOTE_HOST, &remote_ip);
    if (err != ERR_OK) {
        // Error handling
        return;
    }

    // Create a TCP connection
    conn = netconn_new(NETCONN_TCP);
    if (conn == NULL) {
        // Error handling
        return;
    }

    // Connect to the remote host
    err = netconn_connect(conn, &remote_ip, REMOTE_PORT);
    if (err != ERR_OK) {
        // Error handling
        netconn_delete(conn);
        return;
    }

    // Send an HTTP GET request
    err = netconn_write(conn, REQUEST, strlen(REQUEST), NETCONN_COPY);
    if (err != ERR_OK) {
        // Error handling
        netconn_close(conn);
        netconn_delete(conn);
        return;
    }

    // Receive the HTTP response
    u32_t start_time = sys_now();
    err = netconn_recv(conn, &buf);
    u32_t end_time = sys_now();
    if (err == ERR_OK) {
        // Process the HTTP response
        netbuf_data(buf, &data, &len);
        EWF_LOG("Received data: %.*s\n", len, (char*)data);
        netbuf_delete(buf);
        EWF_LOG("Ping time: %d ms\n", (int)(end_time - start_time));
    }
    else {
        // Error handling
    }

    // Close the connection
    netconn_close(conn);
    netconn_delete(conn);

    return EWF_RESULT_OK;

}

