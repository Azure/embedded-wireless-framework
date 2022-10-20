#include "azure/az_core.h"
#include "azure/az_iot.h"

#include "ewf_adapter.h"
#include "ewf_lib.h"
#include "ewf_platform.h"
#include "ewf_example.config.h"

#ifndef EWF_CONFIG_TELEMETRY_USERNAME_LENGTH
#define EWF_CONFIG_TELEMETRY_USERNAME_LENGTH        (256)
#endif

#ifndef EWF_CONFIG_TELEMETRY_CLIENT_ID_LENGTH
#define EWF_CONFIG_TELEMETRY_CLIENT_ID_LENGTH       (64)
#endif

#ifndef EWF_CONFIG_TELEMETRY_TOPIC_LENGTH
#define EWF_CONFIG_TELEMETRY_TOPIC_LENGTH           (256)
#endif

#ifndef EWF_CONFIG_TELEMETRY_LOOP_MINUTES
#define EWF_CONFIG_TELEMETRY_LOOP_MINUTES           (60)
#endif

#ifndef EWF_CONFIG_TELEMETRY_MESSAGE_LENGHT
#define EWF_CONFIG_TELEMETRY_MESSAGE_LENGHT         (1024)
#endif

#define EWF_CONFIG_MQTT_PAYLOAD_BUFFER_LENGTH        (256)
#define EWF_CONFIG_QUERY_TOPIC_BUFFER_LENGTH         (256)

// The model this device implements
static az_span const model_id = AZ_SPAN_LITERAL_FROM_STR("dtmi:com:Microchip:PIC32CMLS60_CURIOSITY;1");
static az_span custom_registration_payload_property
= AZ_SPAN_LITERAL_FROM_STR("{\"modelId\":\"dtmi:com:Microchip:PIC32CMLS60_CURIOSITY;1\"}");

// Telemetry Values
static az_span const telemetry_potentiometer_name = AZ_SPAN_LITERAL_FROM_STR("potentiometer");

// Device Values
static uint32_t device_current_potentiometer = 0;

// Command Values
static az_span const command_start_time_name = AZ_SPAN_LITERAL_FROM_STR("startTime");
static az_span const command_end_time_name = AZ_SPAN_LITERAL_FROM_STR("endTime");

/* Prototypes */
static void telemetry_message_send(ewf_adapter* adapter_ptr);
static void telemetry_message_build(uint8_t property_count, az_span const names[],
    uint32_t const values[], az_span const times[], 
    az_span property_payload, az_span* out_property_payload);
ewf_result ewf_mqtt_receive_message_user_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr);
ewf_result ewf_example_iot_pnp_provisioning(ewf_adapter* adapter_ptr);

/* Work buffers */
static char mqtt_client_username_buffer[256];
static char mqtt_client_id_buffer[128];
static char telemetry_topic_buffer[EWF_CONFIG_TELEMETRY_TOPIC_LENGTH];
static char register_topic_buffer[128];

/* The IoT Provisioning client */
static az_iot_provisioning_client provisioning_client;
/* The IoT Hub client */
static az_iot_hub_client hub_client;
static char iot_hub_endpoint_buffer[128];
static char iot_hub_device_id_buffer[128];
static az_span device_iot_hub_endpoint;
static az_span device_id;

typedef struct _ewf_mqtt_receive_message {
    char ewf_mqtt_recv_topic[EWF_CONFIG_TELEMETRY_TOPIC_LENGTH];
    int ewf_mqtt_recv_topic_length;
    char ewf_mqtt_recv_message_buffer[EWF_CONFIG_TELEMETRY_MESSAGE_LENGHT];
    int ewf_mqtt_recv_message_length;
} ewf_mqtt_receive_message;

static ewf_mqtt_receive_message ewf_mqtt_recv_message = { 0 };

volatile uint8_t ewf_mqtt_rx_flag = 0;

ewf_result ewf_mqtt_receive_message_user_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr) {
    EWF_ADAPTER_VALIDATE_POINTER(adapter_ptr);

    ewf_interface* interface_ptr = adapter_ptr->interface_ptr;
    EWF_INTERFACE_VALIDATE_POINTER(interface_ptr);

    ewf_mqtt_rx_flag++;

    ewf_mqtt_recv_message.ewf_mqtt_recv_topic_length = ewfl_str_length(topic_cstr);
    ewfl_str_n_cpy(ewf_mqtt_recv_message.ewf_mqtt_recv_topic, topic_cstr, ewf_mqtt_recv_message.ewf_mqtt_recv_topic_length);

    ewf_mqtt_recv_message.ewf_mqtt_recv_message_length = ewfl_str_length(payload_cstr);
    ewfl_str_n_cpy(ewf_mqtt_recv_message.ewf_mqtt_recv_message_buffer, payload_cstr, ewf_mqtt_recv_message.ewf_mqtt_recv_message_length);

    EWF_LOG("[MQTT-Basic][Message callback:][%s][%s]\r\n", topic_cstr, payload_cstr);

    return EWF_RESULT_OK;
}

/**
 * @brief The IoT PnP provisioning example
 */
ewf_result ewf_example_iot_pnp_provisioning(ewf_adapter* adapter_ptr) {
    az_result result;
    ewf_result ewf_status;

    /* Initialize the hub client with the default connection options. */
    result = az_iot_provisioning_client_init(&provisioning_client,
        AZ_SPAN_FROM_STR(EWF_CONFIG_ENDPOINT),
        AZ_SPAN_FROM_STR(EWF_CONFIG_ID_SCOPE),
        AZ_SPAN_FROM_STR(EWF_CONFIG_REGISTRATION_ID),
        NULL);
    if (az_result_failed(result)) {
        EWF_LOG("Failed to initialize provisioning  client: az_result %ld.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    /* Get the MQTT client ID used for the MQTT connection. */
    result = az_iot_provisioning_client_get_client_id(
        &provisioning_client, mqtt_client_id_buffer, sizeof(mqtt_client_id_buffer), NULL);
    if (az_result_failed(result)) {
        EWF_LOG("Failed to get MQTT client ID: az_result %ld.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    EWF_LOG("IoT provisioning client ID: %s\n", mqtt_client_id_buffer);

    /* Get the MQTT client username. */
    result = az_iot_provisioning_client_get_user_name(
        &provisioning_client, mqtt_client_username_buffer, sizeof(mqtt_client_username_buffer), NULL);
    if (az_result_failed(result)) {
        EWF_LOG("Failed to get MQTT client username: az_result %ld.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    EWF_LOG("MQTT user name: %s\n", mqtt_client_username_buffer);

    /* Configure callback for MQTT message reception */
    ewf_status = ewf_adapter_mqtt_basic_message_callback_set(adapter_ptr, ewf_mqtt_receive_message_user_callback);
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to set MQTT callback: ewf_status %d.", ewf_status);
        return ewf_status;
    }

    /* Connect to the MQTT server */
    ewf_status = ewf_adapter_mqtt_basic_connect(
        adapter_ptr,
        EWF_CONFIG_ENDPOINT,
        8883,
        mqtt_client_id_buffer,
        mqtt_client_username_buffer,
        NULL); // This sample uses x509 authentication.
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to MQTT connect: ewf_status %d.", ewf_status);
        return ewf_status;
    }

    EWF_LOG("[INFO] Connected!\n");

    /* Messages received on register topic will be registration responses from the server. */
    ewf_status = ewf_adapter_mqtt_basic_subscribe(adapter_ptr, AZ_IOT_PROVISIONING_CLIENT_REGISTER_SUBSCRIBE_TOPIC);
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to subscribe to a Register topic: ewf_status %d.\n", ewf_status);
        return ewf_status;
    }

    /* Get the Register topic to publish the register request. */
    result = az_iot_provisioning_client_register_get_publish_topic(
        &provisioning_client, register_topic_buffer, sizeof(register_topic_buffer), NULL);
    if (az_result_failed(result)) {
        EWF_LOG("Failed to get the Register topic: ewf_result %ld.\n", result);
        return result;
    }

    /* Devices registering a ModelId while using Device Provisioning Service must specify
       their ModelId in an MQTT payload sent during registration. */
    uint8_t mqtt_payload_buffer[EWF_CONFIG_MQTT_PAYLOAD_BUFFER_LENGTH] = {0};
    size_t mqtt_payload_buffer_length;
    result = az_iot_provisioning_client_get_request_payload(&provisioning_client,
        custom_registration_payload_property,
        NULL,
        mqtt_payload_buffer,
        sizeof(mqtt_payload_buffer),
        &mqtt_payload_buffer_length);
    if (az_result_failed(result)) {
        EWF_LOG("Failed to initialize provisioning client: ewf_result %ld.\n", result);
        return result;
    }

    ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, (char*)register_topic_buffer, (char*)mqtt_payload_buffer);
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to publish Register request: ewf_status %d.\n", ewf_status);
        return ewf_status;
    }

    az_iot_provisioning_client_register_response register_response;
    register_response.operation_status = AZ_IOT_PROVISIONING_STATUS_UNASSIGNED;
    bool is_operation_complete = false;

    char query_topic_buffer[EWF_CONFIG_QUERY_TOPIC_BUFFER_LENGTH];

    EWF_LOG("Waiting for registration status message.\r\n");

    ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 4 /*register_response.retry_after_seconds */);

    ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, (char*)register_topic_buffer, (char*)" ");
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to publish Register request: ewf_status %d.\n", ewf_status);
        return ewf_status;
    }
    // Continue to parse incoming responses from the provisioning service until the device has been
    // successfully provisioned or an error occurs.   
    do
    {
        if (ewf_mqtt_rx_flag)
        {

            ewf_mqtt_rx_flag--;
            az_span const topic_span = az_span_create((uint8_t*)ewf_mqtt_recv_message.ewf_mqtt_recv_topic, ewf_mqtt_recv_message.ewf_mqtt_recv_topic_length);
            az_span const message_span = az_span_create((uint8_t*)ewf_mqtt_recv_message.ewf_mqtt_recv_message_buffer, ewf_mqtt_recv_message.ewf_mqtt_recv_message_length);

            result = az_iot_provisioning_client_parse_received_topic_and_payload(&provisioning_client, topic_span, message_span, &register_response);
            if (az_result_failed(result)) {
                EWF_LOG("Unknown Topic: %s\r\n", ewf_mqtt_recv_message.ewf_mqtt_recv_topic);
                EWF_LOG("Message from unknown topic: az_result return code 0x%08x.\r\n", result);
            }
            is_operation_complete = az_iot_provisioning_client_operation_complete(register_response.operation_status);
            if ((!is_operation_complete) || (register_response.operation_status != AZ_IOT_PROVISIONING_STATUS_ASSIGNED))
            {
                result = az_iot_provisioning_client_query_status_get_publish_topic(
                    &provisioning_client, register_response.operation_id, query_topic_buffer, sizeof(query_topic_buffer), NULL);

                if (az_result_failed(result))
                {
                    EWF_LOG("Unable to get query status publish topic: az_result return code 0x%08x.\r\n", result);
                }
                else
                {
                    /*  Wait the recommended retry-after number of seconds before query. */
                    ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * register_response.retry_after_seconds);
                    ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, (char*)query_topic_buffer, (char*)" ");
                    if (ewf_result_failed(ewf_status))
                    {
                        EWF_LOG("Failed to publish az_iot_provisioning_client_get_request_payload: ewf_status %d.\r\n", ewf_status);
                        return ewf_status;
                    }
                }
            }
            else
            {
                if (register_response.operation_status == AZ_IOT_PROVISIONING_STATUS_ASSIGNED)
                {
                    break;
                }
                else
                {
                    EWF_LOG("Registration failed with dPS response: operation status %d.\r\n", register_response.operation_status);
                    EWF_LOG("Operation ID: %d\r\n", register_response.operation_id);
                    EWF_LOG("Registration error track id: %d\r\n", register_response.registration_state.error_tracking_id);
                    EWF_LOG("Retrying Registration.\r\n");
                }

            }
        }
    }while (!is_operation_complete);

    /* At this point  operation_status is AZ_IOT_PROVISIONING_STATUS_ASSIGNED */
    EWF_LOG("Device provisioned!!!\r\n");
    device_iot_hub_endpoint
        = az_span_create((uint8_t*)iot_hub_endpoint_buffer, sizeof(iot_hub_endpoint_buffer));
    device_id
        = az_span_create((uint8_t*)iot_hub_device_id_buffer, sizeof(iot_hub_device_id_buffer));

    az_span_copy(device_iot_hub_endpoint, register_response.registration_state.assigned_hub_hostname);
    device_iot_hub_endpoint = az_span_slice(device_iot_hub_endpoint, 0,
        az_span_size(register_response.registration_state.assigned_hub_hostname));

    az_span_copy(device_id, register_response.registration_state.device_id);
    device_id = az_span_slice(device_id, 0,
        az_span_size(register_response.registration_state.device_id));

    EWF_LOG("IoT Hub Hostname: %s\r\nDevice Id: %s\r\n",
        (char*)device_iot_hub_endpoint._internal.ptr,
        (char*)device_id._internal.ptr);

    // Disconnect from the MQTT client from Provisioning service
    ewf_status = ewf_adapter_mqtt_basic_disconnect(adapter_ptr);
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to disconnect MQTT client: ewf_result return code 0x%08lx.\r\n", ewf_status);
    }

    EWF_LOG("Client disconnected from provisioning service.\r\n");

    // The Plug and Play model ID is specified as an option during initial client initialization.
    az_iot_hub_client_options options = az_iot_hub_client_options_default();
    options.model_id = model_id;

    /* Initialize the hub client with the default connection options. */
    result = az_iot_hub_client_init(&hub_client, device_iot_hub_endpoint, device_id, &options);
    if (az_result_failed(result)) {
        EWF_LOG("Failed to initialize hub client: az_result %ld.\r\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    memset(mqtt_client_id_buffer, 0, 128);

    result = az_iot_hub_client_get_client_id(&hub_client,
        mqtt_client_id_buffer, sizeof(mqtt_client_id_buffer), NULL);
    if (az_result_failed(result)) {
        EWF_LOG("Failed to get MQTT client id: az_result %ld.\r\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    memset(mqtt_client_username_buffer, 0, 128);

    /* Get the MQTT client username. */
    result = az_iot_hub_client_get_user_name(&hub_client,
        mqtt_client_username_buffer, sizeof(mqtt_client_username_buffer), NULL);
    if (az_result_failed(result)) {
        EWF_LOG("Failed to get MQTT client username: az_result %ld.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    /* Connect to the MQTT server */
    ewf_status = ewf_adapter_mqtt_basic_connect(
        adapter_ptr,
        (char*)device_iot_hub_endpoint._internal.ptr,
        8883,
        mqtt_client_id_buffer,
        mqtt_client_username_buffer,
        NULL);
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to MQTT connect: ewf_status %d.", ewf_status);
        return ewf_status;
    }

    EWF_LOG("[INFO] Connected!\n");

    /* Subscribe to the incoming commands */
    ewf_status = ewf_adapter_mqtt_basic_subscribe(adapter_ptr, AZ_IOT_HUB_CLIENT_COMMANDS_SUBSCRIBE_TOPIC);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG_ERROR("Failed to subscribe to a topic: ewf_status %d.\n", ewf_status);
    }

    /* Subscribe to the incoming commands */
    ewf_status = ewf_adapter_mqtt_basic_subscribe(adapter_ptr, AZ_IOT_HUB_CLIENT_PROPERTIES_WRITABLE_UPDATES_SUBSCRIBE_TOPIC);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG_ERROR("Failed to subscribe to a topic: ewf_status %d.\n", ewf_status);
    }

    /* Subscribe to the incoming commands */
    ewf_status = ewf_adapter_mqtt_basic_subscribe(adapter_ptr, AZ_IOT_HUB_CLIENT_PROPERTIES_MESSAGE_SUBSCRIBE_TOPIC);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG_ERROR("Failed to subscribe to a topic: ewf_status %d.\n", ewf_status);
    }

    int mqtt_count = 0;
    for (int seconds_counter = 0; seconds_counter < 300; seconds_counter++)
    {
        device_current_potentiometer = seconds_counter;
        telemetry_message_send(adapter_ptr);
        ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 1);
    }

    // Disconnect from the IoT Hub
    ewf_status = ewf_adapter_mqtt_basic_disconnect(adapter_ptr);
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to disconnect MQTT client: ewf_result return code 0x%08lx.\r\n", ewf_status);
    }

    return EWF_RESULT_OK;
}

/* Send telemetry message*/
static void telemetry_message_send(ewf_adapter* adapter_ptr)
{
    ewf_result ewf_status = EWF_RESULT_OK;

    /* Get the Telemetry topic to publish the telemetry messages. */
    az_result result = az_iot_hub_client_telemetry_get_publish_topic(
        &hub_client, NULL, telemetry_topic_buffer, sizeof(telemetry_topic_buffer), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get the Telemetry topic: az_result %ld.\n", result);
        return EWF_RESULT_IRRECOVERABLE_ERROR;
    }

    /* Build Telemetry Message */
    uint8_t property_count = 1;
    az_span const names[1] = { telemetry_potentiometer_name };
    uint32_t const values[1] = { device_current_potentiometer };

    char telemetry_payload_buffer[128] = { 0 };
    az_span telemetry_payload = AZ_SPAN_FROM_BUFFER(telemetry_payload_buffer);
    telemetry_message_build(property_count, names, values, NULL, telemetry_payload, &telemetry_payload);

    ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, telemetry_topic_buffer, (char*)telemetry_payload._internal.ptr);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG("Failed to publish telemetry: ewf_status %d.\n", ewf_status);
    }

}

/* Build telemetry JSON payload.  */
static void telemetry_message_build(uint8_t property_count, az_span const names[],
    uint32_t const values[], az_span const times[],
    az_span property_payload, az_span* out_property_payload)
{
    az_json_writer jw;

    az_result result = (az_json_writer_init(&jw, property_payload, NULL));
    if (az_result_failed(result))
    {
        EWF_LOG("Json writer failed to init writer: az_result %ld.\n", result);
        return result;
    }

    result = az_json_writer_append_begin_object(&jw);
    if (az_result_failed(result))
    {
        EWF_LOG("Json writer append begin object fail: az_result %ld.\n", result);
        return result;
    }

    for (uint8_t i = 0; i < property_count; i++)
    {
        result = az_json_writer_append_property_name(&jw, names[i]);
        if (az_result_failed(result))
        {
            EWF_LOG("Json writer append property name fail: az_result %ld.\n", result);
            return result;
        }

        result = az_json_writer_append_int32(&jw, values[i]);
        if (az_result_failed(result))
        {
            EWF_LOG("Json writer append int32 fail: az_result %ld.\n", result);
            return result;
        }
    }

    if (times != NULL)
    {

        result = az_json_writer_append_property_name(&jw, command_start_time_name);
            if (az_result_failed(result))
            {
                EWF_LOG("Json writer append property name fail: az_result %ld.\n", result);
                return result;
            }

        result = az_json_writer_append_string(&jw, times[0]);
            if (az_result_failed(result))
            {
                EWF_LOG("Json writer append string fail: az_result %ld.\n", result);
                return result;
            }

            result = az_json_writer_append_property_name(&jw, command_end_time_name);
            if (az_result_failed(result))
            {
                EWF_LOG("Json writer append property name fail: az_result %ld.\n", result);
                return result;
            }

            result = az_json_writer_append_string(&jw, times[1]);
            if (az_result_failed(result))
            {
                EWF_LOG("Json writer append string fail: az_result %ld.\n", result);
                return result;
            }
    }

     result = az_json_writer_append_end_object(&jw);
    if (az_result_failed(result))
    {
        EWF_LOG("Json writer append end object fail: az_result %ld.\n", result);
        return result;
    }
}
