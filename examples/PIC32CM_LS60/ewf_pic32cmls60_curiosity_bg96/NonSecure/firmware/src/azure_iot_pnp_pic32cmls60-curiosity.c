#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "azure/az_core.h"
#include "azure/az_iot.h"

#include "ewf_adapter.h"
#include "ewf_lib.h"
#include "ewf_platform.h"
#include "ewf_example.config.h"

#include "pic32cmls60-curiosity-buttons.h"
#include "pic32cmls60-curiosity-commands.h"
#include "pic32cmls60-curiosity-led.h"

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

#ifndef EWF_CONFIG_TELEMETRY_MESSAGE_LENGTH
#define EWF_CONFIG_TELEMETRY_MESSAGE_LENGTH         (1024)
#endif

#define EWF_CONFIG_MQTT_PAYLOAD_BUFFER_LENGTH        (256)
#define EWF_CONFIG_QUERY_TOPIC_BUFFER_LENGTH         (256)

extern char BUTTON_eventBuffer[EWF_CONFIG_TELEMETRY_TOPIC_LENGTH];

static char const iso_spec_time_format[] = "%Y-%m-%dT%H:%M:%SZ"; // ISO8601 Time Format

// The model this device implements
static az_span const model_id = AZ_SPAN_LITERAL_FROM_STR("dtmi:com:Microchip:PIC32CMLS60_CURIOSITY;1");
static az_span custom_registration_payload_property
= AZ_SPAN_LITERAL_FROM_STR("{\"modelId\":\"dtmi:com:Microchip:PIC32CMLS60_CURIOSITY;1\"}");

// MQTT Connection Values
static uint16_t connection_request_id = 0;
static char connection_request_id_buffer[16];

// Property Values
static az_span const property_success_name = AZ_SPAN_LITERAL_FROM_STR("success");
static az_span const property_desired_temperature_name
= AZ_SPAN_LITERAL_FROM_STR("targetTemperature");
static az_span const property_reported_maximum_temperature_name
= AZ_SPAN_LITERAL_FROM_STR("maxTempSinceLastReboot");

static az_span const property_led0_name = AZ_SPAN_LITERAL_FROM_STR("LED0");
static az_span const property_led1_name = AZ_SPAN_LITERAL_FROM_STR("LED1");
static az_span const property_disable_telemetry_name = AZ_SPAN_LITERAL_FROM_STR("disableTelemetry");
static az_span const property_telemetry_interval_name = AZ_SPAN_LITERAL_FROM_STR("telemetryInterval");

// Telemetry Values
static az_span const telemetry_temperature_name = AZ_SPAN_LITERAL_FROM_STR("temperature");
static az_span const telemetry_potentiometer_name = AZ_SPAN_LITERAL_FROM_STR("potentiometer");

// Command Values
static az_span const command_getMaxMinReport_name = AZ_SPAN_LITERAL_FROM_STR("getMaxMinReport");
static az_span const command_max_temp_name = AZ_SPAN_LITERAL_FROM_STR("maxTemp");
static az_span const command_min_temp_name = AZ_SPAN_LITERAL_FROM_STR("minTemp");
static az_span const command_avg_temp_name = AZ_SPAN_LITERAL_FROM_STR("avgTemp");
static az_span const command_start_time_name = AZ_SPAN_LITERAL_FROM_STR("startTime");
static az_span const command_end_time_name = AZ_SPAN_LITERAL_FROM_STR("endTime");
static az_span const command_empty_response_payload = AZ_SPAN_LITERAL_FROM_STR("{}");
static char command_start_time_value_buffer[32];
static char command_end_time_value_buffer[32];
static char command_response_payload_buffer[256];

static const az_span command_name_reboot_span = AZ_SPAN_LITERAL_FROM_STR("reboot");
static const az_span command_name_send_message_span = AZ_SPAN_LITERAL_FROM_STR("sendMsg");

#define DEFAULT_START_TEMP_COUNT 1
#define DEFAULT_START_TEMP_CELSIUS 22.0
#define DOUBLE_DECIMAL_PLACE_DIGITS 2

// Device Values
static double device_current_temperature = DEFAULT_START_TEMP_CELSIUS;
static double device_maximum_temperature = DEFAULT_START_TEMP_CELSIUS;
static double device_minimum_temperature = DEFAULT_START_TEMP_CELSIUS;
static double device_temperature_summation = DEFAULT_START_TEMP_CELSIUS;
static uint32_t device_temperature_count = DEFAULT_START_TEMP_COUNT;
static double device_average_temperature = DEFAULT_START_TEMP_CELSIUS;

static uint16_t device_current_potentiometer = 0;

/* Work buffers */
static char mqtt_client_username_buffer[256];
static char mqtt_client_id_buffer[128] = { 0 };
static char telemetry_topic_buffer[EWF_CONFIG_TELEMETRY_TOPIC_LENGTH];
static char register_topic_buffer[128] = { 0 };

/* The IoT Provisioning client */
static az_iot_provisioning_client provisioning_client;
/* The IoT Hub client */
static az_iot_hub_client hub_client;
static char azure_iot_hub_endpoint_buffer[128] = { 0 };
static char azure_iot_hub_device_id_buffer[128] = { 0 };
static az_span device_azure_iot_hub_endpoint;
static az_span device_id;

typedef struct _ewf_mqtt_receive_message {
    char ewf_mqtt_recv_topic[EWF_CONFIG_TELEMETRY_TOPIC_LENGTH];
    int ewf_mqtt_recv_topic_length;
    char ewf_mqtt_recv_message_buffer[EWF_CONFIG_TELEMETRY_MESSAGE_LENGTH];
    int ewf_mqtt_recv_message_length;
} ewf_mqtt_receive_message;

static ewf_mqtt_receive_message ewf_mqtt_recv_message = { 0 };

volatile uint8_t ewf_mqtt_rx_flag = 0;

static bool disableTelemetry = AZ_JSON_TOKEN_FALSE;
static uint32_t telemetryInterval = EWF_CONFIG_TELEMETRY_INTERVAL_SECONDS;

/* Prototypes */
static void azure_iot_hub_topics_subscribe(ewf_adapter* adapter_ptr);
static void button_message_send(ewf_adapter* adapter_ptr);
static void azure_iot_telemetry_message_send(ewf_adapter* adapter_ptr);
static void azure_iot_hub_properties_request(ewf_adapter* adapter_ptr);
static void azure_iot_hub_reported_property_send(ewf_adapter* adapter_ptr,
    az_span name,
    double value,
    int32_t version,
    bool write_payload_with_status);
static az_span properties_get_request_id(void);
static void azure_iot_handle_command_request(ewf_adapter* adapter_ptr,
    ewf_mqtt_receive_message* recv_message_ptr,
    az_iot_hub_client_command_request const* command_request);
static void azure_iot_receive_message_process(ewf_adapter* adapter_ptr, ewf_mqtt_receive_message* recv_message_ptr);
static void azure_iot_handle_device_property_message(ewf_adapter* adapter_ptr,
    ewf_mqtt_receive_message* recv_message_ptr,
    az_iot_hub_client_properties_message const* property_message);
static bool invoke_getMaxMinReport(ewf_adapter* adapter_ptr, az_span payload, az_span response, az_span* out_response);
static void azure_iot_process_device_property_message(ewf_adapter* adapter_ptr,
    az_span message_span,
    az_iot_hub_client_properties_message_type message_type);
static void azure_iot_send_command_response(ewf_adapter* adapter_ptr,
    az_iot_hub_client_command_request const* command_request,
    az_iot_status status,
    az_span response);
static void payload_build(uint8_t property_count, az_span const names[],
    double const values[], az_span const times[],
    az_span property_payload, az_span* out_property_payload);
static void payload_with_status_build(
    az_span name,
    double value,
    int32_t status_code_value,
    int32_t version_value,
    az_span description_value,
    az_span property_payload,
    az_span* out_property_payload);
static void update_device_temperature_property(double temperature, bool* out_is_max_temp_changed);
ewf_result ewf_mqtt_receive_message_user_callback(ewf_adapter* adapter_ptr, const char* topic_cstr, const char* payload_cstr);
ewf_result ewf_example_azure_iot_pnp_provisioning(ewf_adapter* adapter_ptr);
static void ewf_azure_iot_pnp_sample_demo(ewf_adapter* adapter_ptr);

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
ewf_result ewf_example_azure_iot_pnp_provisioning(ewf_adapter* adapter_ptr) {
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
    uint8_t mqtt_payload_buffer[EWF_CONFIG_MQTT_PAYLOAD_BUFFER_LENGTH] = { 0 };
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
                        EWF_LOG("Failed to publish registration query message: ewf_status %d.\r\n", ewf_status);
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
                    EWF_LOG("Operation ID: %s\r\n", register_response.operation_id._internal.ptr);
                    EWF_LOG("Registration error track id: %s\r\n", register_response.registration_state.error_tracking_id._internal.ptr);
                    EWF_LOG("Retrying Registration.\r\n");
                }

            }
        }
        else
        {
            /* Send a blank payload after register request if there is not message from host endpoint */
            ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, (char*)register_topic_buffer, (char*)" ");
            if (ewf_result_failed(ewf_status)) {
                EWF_LOG("Failed to publish Register request: ewf_status %d.\n", ewf_status);
                return ewf_status;
            }
        }
    } while (!is_operation_complete);

    /* At this point  operation_status is AZ_IOT_PROVISIONING_STATUS_ASSIGNED */
    EWF_LOG("Device provisioned!!!\r\n");
    device_azure_iot_hub_endpoint
        = az_span_create((uint8_t*)azure_iot_hub_endpoint_buffer, sizeof(azure_iot_hub_endpoint_buffer));
    device_id
        = az_span_create((uint8_t*)azure_iot_hub_device_id_buffer, sizeof(azure_iot_hub_device_id_buffer));

    az_span_copy(device_azure_iot_hub_endpoint, register_response.registration_state.assigned_hub_hostname);
    device_azure_iot_hub_endpoint = az_span_slice(device_azure_iot_hub_endpoint, 0,
        az_span_size(register_response.registration_state.assigned_hub_hostname));

    az_span_copy(device_id, register_response.registration_state.device_id);
    device_id = az_span_slice(device_id, 0,
        az_span_size(register_response.registration_state.device_id));

    EWF_LOG("IoT Hub Hostname: %s\r\nDevice Id: %s\r\n",
        (char*)device_azure_iot_hub_endpoint._internal.ptr,
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
    result = az_iot_hub_client_init(&hub_client, device_azure_iot_hub_endpoint, device_id, &options);
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
        (char*)device_azure_iot_hub_endpoint._internal.ptr,
        8883,
        mqtt_client_id_buffer,
        mqtt_client_username_buffer,
        NULL);
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to MQTT connect: ewf_status %d.", ewf_status);
        return ewf_status;
    }

    EWF_LOG("[INFO] Connected!\n");

    /* Subscribe the incoming commands to the device and notify about device properties. */
    azure_iot_hub_topics_subscribe(adapter_ptr);

    /* Send reported properties */
    azure_iot_hub_reported_property_send(adapter_ptr, property_reported_maximum_temperature_name, device_current_temperature, 0, false);

    /* Request all property information */
    azure_iot_hub_properties_request(adapter_ptr);

    /* Send telemetry and process received commands or device property messages */
    ewf_azure_iot_pnp_sample_demo(adapter_ptr);

    // Disconnect from the IoT Hub
    ewf_status = ewf_adapter_mqtt_basic_disconnect(adapter_ptr);
    if (ewf_result_failed(ewf_status)) {
        EWF_LOG("Failed to disconnect MQTT client: ewf_result return code 0x%08lx.\r\n", ewf_status);
    }

    return EWF_RESULT_OK;
}

static void ewf_azure_iot_pnp_sample_demo(ewf_adapter* adapter_ptr)
{

    int minutes_counter;
    int seconds_counter;
    int telemetry_counter = 1;
    
    EIC_CallbackRegister(EIC_PIN_12, (EIC_CALLBACK)BUTTON_SW0_callback, 0);
    EIC_InterruptEnable(EIC_PIN_12);
    EIC_CallbackRegister(EIC_PIN_4, (EIC_CALLBACK)BUTTON_SW1_callback, 0);
    EIC_InterruptEnable(EIC_PIN_4);       
    ADC_Enable();
    LED_init();

    for (minutes_counter = 0;
        (EWF_CONFIG_TELEMETRY_LOOP_MINUTES == 0) || (EWF_CONFIG_TELEMETRY_LOOP_MINUTES != 0 && minutes_counter < EWF_CONFIG_TELEMETRY_LOOP_MINUTES);
        minutes_counter++)
    {
        for (seconds_counter = 0; seconds_counter < 60; seconds_counter++)
        {
            if (ewf_mqtt_rx_flag)
            {
                ewf_mqtt_rx_flag--;
                EWF_LOG("Waiting for command request or device property message.\r\n");

                azure_iot_receive_message_process(adapter_ptr, &ewf_mqtt_recv_message);

            }
            if (telemetry_counter++ >= telemetryInterval)
            {
                //if (disableTelemetry == AZ_JSON_TOKEN_FALSE)
                {
                    azure_iot_telemetry_message_send(adapter_ptr);
                }
                telemetry_counter = 1;
            }
            if (BUTTON_SW0_check() == BUTTON_PRESS_TRUE)
            {
                button_message_send(adapter_ptr);                
            }
            if (BUTTON_SW1_check() == BUTTON_PRESS_TRUE)
            {
                button_message_send(adapter_ptr);                
            }
            LED_refresh();
            if (SYS_rebootTimer > 0)
            {
                SYS_rebootTimer--;
                if (SYS_rebootTimer == 0)
                {
                    __NVIC_SystemReset();
                }
            }
            /* Sleep for the desired telemetry interval */
            ewf_platform_sleep(EWF_PLATFORM_TICKS_PER_SECOND * 1);
        }
    }

}

/* Process the message received */
static void azure_iot_receive_message_process(ewf_adapter* adapter_ptr, ewf_mqtt_receive_message* recv_message_ptr)
{

    az_result result = AZ_OK;

    az_span const topic_span = az_span_create((uint8_t*)recv_message_ptr->ewf_mqtt_recv_topic, recv_message_ptr->ewf_mqtt_recv_topic_length);
    az_span const message_span = az_span_create((uint8_t*)recv_message_ptr->ewf_mqtt_recv_message_buffer, recv_message_ptr->ewf_mqtt_recv_message_length);

    az_iot_hub_client_properties_message property_message;
    az_iot_hub_client_command_request command_request;

    result = az_iot_hub_client_properties_parse_received_topic(
        &hub_client, topic_span, &property_message);
    if (az_result_succeeded(result))
    {
        EWF_LOG("Client received a valid topic.\r\n");
        EWF_LOG("Topic: %s\r\n", recv_message_ptr->ewf_mqtt_recv_topic);
        EWF_LOG("Payload: %s\r\n", recv_message_ptr->ewf_mqtt_recv_message_buffer);
        EWF_LOG("Status: %d\r\n", property_message.status);

        azure_iot_handle_device_property_message(adapter_ptr, recv_message_ptr, &property_message);
    }
    else
    {
        result = az_iot_hub_client_commands_parse_received_topic(&hub_client, topic_span, &command_request);
        if (az_result_succeeded(result))
        {
            EWF_LOG("Client received a valid topic.\r\n");
            EWF_LOG("Topic: %s\r\n", recv_message_ptr->ewf_mqtt_recv_topic);
            EWF_LOG("Payload: %s\r\n", recv_message_ptr->ewf_mqtt_recv_message_buffer);

            azure_iot_handle_command_request(adapter_ptr, recv_message_ptr, &command_request);
        }

    }

}

// Handles an incoming command from Azure IoT Hub
static void azure_iot_handle_command_request(ewf_adapter* adapter_ptr,
    ewf_mqtt_receive_message* recv_message_ptr,
    az_iot_hub_client_command_request const* command_request)
{
    az_span const message_span = az_span_create((uint8_t*)recv_message_ptr->ewf_mqtt_recv_message_buffer, recv_message_ptr->ewf_mqtt_recv_message_length);

    // Check for 'getMaxMinReport' command
    if ((az_span_is_content_equal(command_request->component_name, AZ_SPAN_EMPTY))
        && (az_span_is_content_equal(command_getMaxMinReport_name, command_request->command_name)))
    {
        az_iot_status status;
        az_span command_response_payload = AZ_SPAN_FROM_BUFFER(command_response_payload_buffer);

        // Process the command
        if (!invoke_getMaxMinReport(adapter_ptr, message_span, command_response_payload, &command_response_payload))
        {
            status = AZ_IOT_STATUS_BAD_REQUEST;
        }
        else
        {
            status = AZ_IOT_STATUS_OK;
        }
        EWF_LOG("Client processed command 'getMaxMinReport'\r\n");

        azure_iot_send_command_response(adapter_ptr, command_request, status, command_response_payload);
    }
    // Check for 'reboot' command
    else if ((az_span_is_content_equal(command_request->component_name, AZ_SPAN_EMPTY))
        && (az_span_is_content_equal(command_name_reboot_span, command_request->command_name)))
    {
        az_iot_status status;
        az_span command_response_payload = AZ_SPAN_FROM_BUFFER(command_response_payload_buffer);

        // Process the command
        if (!COMMAND_Handler_reboot(message_span, command_response_payload, &command_response_payload))
        {
            status = AZ_IOT_STATUS_BAD_REQUEST;
        }
        else
        {
            status = AZ_IOT_STATUS_OK;
        }
        EWF_LOG("Client processed command 'reboot'\r\n");

        azure_iot_send_command_response(adapter_ptr, command_request, status, command_response_payload);
    }
    // Check for 'sendMsg' command
    else if ((az_span_is_content_equal(command_request->component_name, AZ_SPAN_EMPTY))
        && (az_span_is_content_equal(command_name_send_message_span, command_request->command_name)))
    {
        az_iot_status status;
        az_span command_response_payload = AZ_SPAN_FROM_BUFFER(command_response_payload_buffer);

        // Process the command
        if (!COMMAND_Handler_sendMsg(message_span, command_response_payload, &command_response_payload))
        {
            status = AZ_IOT_STATUS_BAD_REQUEST;
        }
        else
        {
            status = AZ_IOT_STATUS_OK;
        }
        EWF_LOG("Client processed command 'sendMsg'\r\n");

        azure_iot_send_command_response(adapter_ptr, command_request, status, command_response_payload);
    }
    else
    {
        EWF_LOG("Command not supported: %s\r\n", command_request->command_name._internal.ptr);
        azure_iot_send_command_response(adapter_ptr, command_request, AZ_IOT_STATUS_NOT_FOUND, command_empty_response_payload);
    }
}

// Sends a response to a command invoked by Azure IoT Hub
static void azure_iot_send_command_response(ewf_adapter* adapter_ptr,
    az_iot_hub_client_command_request const* command_request,
    az_iot_status status,
    az_span response)
{
    az_result result;
    ewf_result ewf_status;

    // Get the command response topic to publish the command response.
    char command_response_topic_buffer[128] = { 0 };
    result = az_iot_hub_client_commands_response_get_publish_topic(
        &hub_client,
        command_request->request_id,
        (uint16_t)status,
        command_response_topic_buffer,
        sizeof(command_response_topic_buffer),
        NULL);
    if (az_result_failed(result)) {
        EWF_LOG("Failed to get the command response topic: az_result %d.", result);
        exit(1);
    }

    // Publish the command response.
    ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, command_response_topic_buffer, (char*)response._internal.ptr);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG("Failed to publish telemetry: ewf_result %d.\n", ewf_status);
    }
    EWF_LOG("Client published the Command response.\r\n");
    EWF_LOG("Status: %d\r\n", status);
    EWF_LOG("Payload: %s\r\n", response._internal.ptr);
}

// Called when the command "getMaxMinReport" arrives from the service.
// It writes the response payload based on simulated temperature data.
static bool invoke_getMaxMinReport(ewf_adapter* adapter_ptr, az_span payload, az_span response, az_span* out_response)
{
    int32_t incoming_since_value_len = 0;
    az_json_reader jr;

    az_result result = AZ_OK;
    ewf_result ewf_status;

    result = az_json_reader_init(&jr, payload, NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to parse for `since` field in payload, Could not initialize JSON reader: az_result %d\r\n", result);
        exit(1);
    }

    result = az_json_reader_next_token(&jr);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to parse for `since` field in payload, Could not move to next property value: az_result %d\r\n", result);
        exit(1);
    }

    if (az_result_failed(az_json_token_get_string(
        &jr.token,
        command_start_time_value_buffer,
        sizeof(command_start_time_value_buffer),
        &incoming_since_value_len)))
    {
        *out_response = command_empty_response_payload;
        return false;
    }

    // Set the response payload to error if the `since` value was empty.
    if (incoming_since_value_len == 0)
    {
        *out_response = command_empty_response_payload;
        return false;
    }

    az_span start_time_span
        = az_span_create((uint8_t*)command_start_time_value_buffer, incoming_since_value_len);
    EWF_LOG("Start time: %s\r\n", start_time_span._internal.ptr);

    // Get the current time as a string
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = (struct tm *)localtime(&rawtime);
    size_t length = strftime(
        command_end_time_value_buffer,
        sizeof(command_end_time_value_buffer),
        iso_spec_time_format,
        timeinfo);
    az_span end_time_span = az_span_create((uint8_t*)command_end_time_value_buffer, (int32_t)length);
    EWF_LOG("End time: %s\r\n", end_time_span._internal.ptr);

    // Write command response message
    uint8_t count = 3;
    az_span const names[3] = { command_max_temp_name, command_min_temp_name, command_avg_temp_name };
    double const values[3]
        = { device_maximum_temperature, device_minimum_temperature, device_average_temperature };
    az_span const times[2] = { start_time_span, end_time_span };

    payload_build(count, names, values, times, response, out_response);

    return true;
}

// Handles incoming properties from Azure IoT Hub
static void azure_iot_handle_device_property_message(ewf_adapter* adapter_ptr,
    ewf_mqtt_receive_message* recv_message_ptr,
    az_iot_hub_client_properties_message const* property_message)
{
    az_span const message_span = az_span_create((uint8_t*)recv_message_ptr->ewf_mqtt_recv_message_buffer, recv_message_ptr->ewf_mqtt_recv_message_length);

    // Invoke appropriate action per message type (3 types only).
    switch (property_message->message_type)
    {
        // A message from a property GET publish message with the property document as a payload.
    case AZ_IOT_HUB_CLIENT_PROPERTIES_MESSAGE_TYPE_GET_RESPONSE:
        EWF_LOG("Message Type: GET\r\n");
        azure_iot_process_device_property_message(adapter_ptr, message_span, property_message->message_type);
        break;

        // An update to the desired properties with the properties as a payload.
    case AZ_IOT_HUB_CLIENT_PROPERTIES_MESSAGE_TYPE_WRITABLE_UPDATED:
        EWF_LOG("Message Type: Desired Properties\r\n");
        azure_iot_process_device_property_message(adapter_ptr, message_span, property_message->message_type);
        break;

        // When the device publishes a property update, this message type arrives when
        // server acknowledges this.
    case AZ_IOT_HUB_CLIENT_PROPERTIES_MESSAGE_TYPE_ACKNOWLEDGEMENT:
        EWF_LOG("Message Type: IoT Hub has acknowledged properties that the device sent\r\n");
        break;

        // An error has occurred
    case AZ_IOT_HUB_CLIENT_PROPERTIES_MESSAGE_TYPE_ERROR:
        EWF_LOG("Message Type: Request Error\r\n");
        break;
    }
}


// Handles incoming properties from Azure IoT Hub
static void azure_iot_process_device_property_message(ewf_adapter* adapter_ptr,
    az_span message_span,
    az_iot_hub_client_properties_message_type message_type)
{
    az_json_reader jr;
    az_result result = az_json_reader_init(&jr, message_span, NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Could not initialize JSON reader: az_result %d\r\n", result);
        exit(1);
    }

    int32_t version_number;
    result = az_iot_hub_client_properties_get_properties_version(
        &hub_client, &jr, message_type, &version_number);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Could not get property version: az_result %d\r\n", result);
        exit(1);
    }

    result = az_json_reader_init(&jr, message_span, NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Could not initialize JSON reader: az_result %d\r\n", result);
        exit(1);
    }

    double desired_temperature;
    uint32_t desired_led0_status;
    uint32_t desired_led1_status;
    bool desired_disable_telemetry;
    uint32_t desired_telemetry_interval;
    az_span component_name;

    // Applications call az_iot_hub_client_properties_get_next_component_property to enumerate
    // properties received.
    while (az_result_succeeded(az_iot_hub_client_properties_get_next_component_property(
        &hub_client, &jr, message_type, AZ_IOT_HUB_CLIENT_PROPERTY_WRITABLE, &component_name)))
    {
        if (az_json_token_is_text_equal(&jr.token, property_desired_temperature_name))
        {
            // Process an update for desired temperature.
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not move to property value: az_result % d\r\n", result);
            }

            result = az_json_token_get_double(&jr.token, &desired_temperature);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not get property value: az_result % d\r\n", result);
            }

            bool is_max_temp_changed;

            // Update device temperature locally and report update to server.
            update_device_temperature_property(desired_temperature, &is_max_temp_changed);
            azure_iot_hub_reported_property_send(adapter_ptr,
                property_desired_temperature_name, desired_temperature, version_number, true);

            if (is_max_temp_changed)
            {
                azure_iot_hub_reported_property_send(adapter_ptr,
                    property_reported_maximum_temperature_name, device_maximum_temperature, 0, false);
            }

            // Skip to next property value
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Invalid JSON. Could not move to next property name: az_result % d\r\n", result);
            }
        }
        else if (az_json_token_is_text_equal(&jr.token, property_led0_name))
        {
            // Process an update for desired LED0 state.
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not move to property value: az_result % d\r\n", result);
            }

            result = az_json_token_get_uint32(&jr.token, &desired_led0_status);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not get property value: az_result % d\r\n", result);
            }

            // Update LED0 locally and report update to server.
            LED_controller[LED0_GREEN].mode = desired_led0_status;
            azure_iot_hub_reported_property_send(adapter_ptr,
                property_led0_name, desired_led0_status, version_number, true);

            // Skip to next property value
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Invalid JSON. Could not move to next property name: az_result % d\r\n", result);
            }
        }
        else if (az_json_token_is_text_equal(&jr.token, property_led1_name))
        {
            // Process an update for desired LED1 state.
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not move to property value: az_result % d\r\n", result);
            }

            result = az_json_token_get_uint32(&jr.token, &desired_led1_status);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not get property value: az_result % d\r\n", result);
            }

            // Update LED1 locally and report update to server.
            LED_controller[LED1_RED].mode = desired_led1_status;
            azure_iot_hub_reported_property_send(adapter_ptr,
                property_led1_name, desired_led1_status, version_number, true);

            // Skip to next property value
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Invalid JSON. Could not move to next property name: az_result % d\r\n", result);
            }
        }
        else if (az_json_token_is_text_equal(&jr.token, property_disable_telemetry_name))
        {
            // Process an update for desired disableTelemetry.
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not move to property value: az_result % d\r\n", result);
            }

            result = az_json_token_get_boolean(&jr.token, &desired_disable_telemetry);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not get property value: az_result % d\r\n", result);
            }

            // Set the property internally and report update to server.
            disableTelemetry = desired_disable_telemetry;
            azure_iot_hub_reported_property_send(adapter_ptr,
                property_disable_telemetry_name, desired_disable_telemetry, version_number, true);

            // Skip to next property value
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Invalid JSON. Could not move to next property name: az_result % d\r\n", result);
            }
        }
        else if (az_json_token_is_text_equal(&jr.token, property_telemetry_interval_name))
        {
            // Process an update for desired telemetry interval.
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not move to property value: az_result % d\r\n", result);
            }

            result = az_json_token_get_uint32(&jr.token, &desired_telemetry_interval);
            if (az_result_failed(result))
            {
                EWF_LOG("Could not get property value: az_result % d\r\n", result);
            }

            // Set the property internally and report update to server.
            telemetryInterval = desired_telemetry_interval;
            azure_iot_hub_reported_property_send(adapter_ptr,
                property_telemetry_interval_name, desired_telemetry_interval, version_number, true);

            // Skip to next property value
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Invalid JSON. Could not move to next property name: az_result % d\r\n", result);
            }
        }        
        else
        {
            EWF_LOG("Unknown Property Received: %s\r\n", jr.token.slice._internal.ptr);
            // The JSON reader must be advanced regardless of whether the property
            // is of interest or not.
            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Invalid JSON. Could not move to next property value: az_result % d\r\n", result);
            }

            // Skip children in case the property value is an object
            result = az_json_reader_skip_children(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Invalid JSON. Could not skip children: az_result % d\r\n", result);
            }

            result = az_json_reader_next_token(&jr);
            if (az_result_failed(result))
            {
                EWF_LOG("Invalid JSON. Could not move to next property name: az_result % d\r\n", result);
            }
        }
    }
}
/* Send a request to Azure IoT Hub to request all properties from the device */
static void azure_iot_hub_properties_request(ewf_adapter* adapter_ptr)
{
    az_result result = AZ_OK;
    ewf_result ewf_status = EWF_RESULT_OK;

    // Get the topic to publish the property document request.
    char property_document_topic_buffer[128] = { 0 };
    result = az_iot_hub_client_properties_document_get_publish_topic(
        &hub_client,
        properties_get_request_id(),
        property_document_topic_buffer,
        sizeof(property_document_topic_buffer),
        NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("IoTHub client device twin get topic fail: az_result %ld.\n", result);
    }

    ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, property_document_topic_buffer,
        (char*)" ");
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG("Failed to publish telemetry: ewf_status %d.\n", ewf_status);
    }

}

/* Creates a message with payload reporting device status and then sends to Azure IoT Hub */
static void azure_iot_hub_reported_property_send(ewf_adapter* adapter_ptr,
    az_span name,
    double value,
    int32_t version,
    bool write_payload_with_status)
{
    az_result result = AZ_OK;
    ewf_result ewf_status = EWF_RESULT_OK;

    // Get the property topic to send a reported property update.
    char property_update_topic_buffer[128] = { 0 };
    result = az_iot_hub_client_properties_get_reported_publish_topic(
        &hub_client,
        properties_get_request_id(),
        property_update_topic_buffer,
        sizeof(property_update_topic_buffer),
        NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get the property update topic: az_result %ld.\n", result);
        exit(1);
    }

    // Write the updated reported property message.
    char reported_property_payload_buffer[128] = { 0 };
    az_span reported_property_payload = AZ_SPAN_FROM_BUFFER(reported_property_payload_buffer);

    if (write_payload_with_status)
    {
        payload_with_status_build(
            name,
            value,
            AZ_IOT_STATUS_OK,
            version,
            property_success_name,
            reported_property_payload,
            &reported_property_payload);
    }
    else
    {
        uint8_t count = 1;
        az_span const names[1] = { name };
        double const values[1] = { value };

        payload_build(
            count, names, values, NULL, reported_property_payload, &reported_property_payload);
    }

    ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, property_update_topic_buffer, (char*)reported_property_payload._internal.ptr);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG("Failed to publish telemetry: ewf_status %d.\n", ewf_status);
    }
}

static az_span properties_get_request_id(void)
{
    az_span remainder;
    az_span out_span = az_span_create(
        (uint8_t*)connection_request_id_buffer, sizeof(connection_request_id_buffer));

    connection_request_id++;
    if (connection_request_id == UINT16_MAX)
    {
        // Connection id has looped.  Reset.
        connection_request_id = 1;
    }

    az_result result = az_span_u32toa(out_span, connection_request_id, &remainder);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get request id: az_result %ld.\n", result);
    }

    return az_span_slice(out_span, 0, az_span_size(out_span) - az_span_size(remainder));

}
/* Subscribe to MQTT topics for Azure IoT Hub */
static void azure_iot_hub_topics_subscribe(ewf_adapter* adapter_ptr)
{
    ewf_result ewf_status = EWF_RESULT_OK;

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

}

/* Send button event */
static void button_message_send(ewf_adapter* adapter_ptr)
{
    ewf_result ewf_status = EWF_RESULT_OK;

    /* Get the Telemetry topic to publish the telemetry messages. */
    az_result result = az_iot_hub_client_telemetry_get_publish_topic(
        &hub_client, NULL, telemetry_topic_buffer, sizeof(telemetry_topic_buffer), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get the Telemetry topic: az_result %ld.\n", result);
        exit(1);
    }

    az_span telemetry_payload = AZ_SPAN_FROM_BUFFER(BUTTON_eventBuffer);

    ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, telemetry_topic_buffer, (char*)telemetry_payload._internal.ptr);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG("Failed to publish telemetry: ewf_status %d.\n", ewf_status);
    }

}

/* Send telemetry message*/
static void azure_iot_telemetry_message_send(ewf_adapter* adapter_ptr)
{
    ewf_result ewf_status = EWF_RESULT_OK;

    /* Get the Telemetry topic to publish the telemetry messages. */
    az_result result = az_iot_hub_client_telemetry_get_publish_topic(
        &hub_client, NULL, telemetry_topic_buffer, sizeof(telemetry_topic_buffer), NULL);
    if (az_result_failed(result))
    {
        EWF_LOG_ERROR("Failed to get the Telemetry topic: az_result %ld.\n", result);
        exit(1);
    }

    /* Build Telemetry Message */
    uint8_t telemetry_count = 1;
    device_current_potentiometer = ADC_ConversionResultGet();
    az_span const names[1] = { telemetry_potentiometer_name };
    double const values[1] = { device_current_potentiometer };

    char telemetry_payload_buffer[128] = { 0 };
    az_span telemetry_payload = AZ_SPAN_FROM_BUFFER(telemetry_payload_buffer);
    payload_build(telemetry_count, names, values, NULL, telemetry_payload, &telemetry_payload);

    ewf_status = ewf_adapter_mqtt_basic_publish(adapter_ptr, telemetry_topic_buffer, (char*)telemetry_payload._internal.ptr);
    if (ewf_result_failed(ewf_status))
    {
        EWF_LOG("Failed to publish telemetry: ewf_status %d.\n", ewf_status);
    }

}

/* Build the JSON payload with response to a desired property  */
static void payload_with_status_build(
    az_span name,
    double value,
    int32_t status_code_value,
    int32_t version_value,
    az_span description_value,
    az_span property_payload,
    az_span* out_property_payload)
{
    az_json_writer jw;

    az_result result = (az_json_writer_init(&jw, property_payload, NULL));
    if (az_result_failed(result))
    {
        EWF_LOG("JSON writer failed to init writer: az_result %ld.\n", result);
        exit(1);
    }

    result = az_json_writer_append_begin_object(&jw);
    if (az_result_failed(result))
    {
        EWF_LOG("JSON writer append begin object fail: az_result %ld.\n", result);
        exit(1);
    }

    result = az_iot_hub_client_properties_writer_begin_response_status(
        &hub_client, &jw, name, status_code_value, version_value, description_value);
    if (az_result_failed(result))
    {
        EWF_LOG("Failed to prefix data: az_result %ld.\n", result);
        exit(1);
    }

    // result = az_json_writer_append_int32(&jw, value);
    result = az_json_writer_append_double(&jw, value, DOUBLE_DECIMAL_PLACE_DIGITS);
    if (az_result_failed(result))
    {
        EWF_LOG("JSON writer append double fail: az_result %ld.\n", result);
        exit(1);
    }

    result = az_iot_hub_client_properties_writer_end_response_status(&hub_client, &jw);
    if (az_result_failed(result))
    {
        EWF_LOG("Failed to suffix data: az_result %ld.\n", result);
        exit(1);
    }

    result = az_json_writer_append_end_object(&jw);
    if (az_result_failed(result))
    {
        EWF_LOG("JSON writer append end object failed: az_result % ld.\n", result);
        exit(1);
    }
    *out_property_payload = az_json_writer_get_bytes_used_in_destination(&jw);

}

/* Build the telemetry JSON payload.  */
static void payload_build(uint8_t property_count, az_span const names[],
    double const values[], az_span const times[],
    az_span property_payload, az_span* out_property_payload)
{
    az_json_writer jw;

    az_result result = (az_json_writer_init(&jw, property_payload, NULL));
    if (az_result_failed(result))
    {
        EWF_LOG("Json writer failed to init writer: az_result %ld.\n", result);
        exit(1);
    }

    result = az_json_writer_append_begin_object(&jw);
    if (az_result_failed(result))
    {
        EWF_LOG("Json writer append begin object fail: az_result %ld.\n", result);
        exit(1);
    }

    for (uint8_t i = 0; i < property_count; i++)
    {
        result = az_json_writer_append_property_name(&jw, names[i]);
        if (az_result_failed(result))
        {
            EWF_LOG("Json writer append property name fail: az_result %ld.\n", result);
            exit(1);
        }

        //result = az_json_writer_append_int32(&jw, values[i]);
        result = az_json_writer_append_double(&jw, values[i], DOUBLE_DECIMAL_PLACE_DIGITS);
        if (az_result_failed(result))
        {
            EWF_LOG("Json writer append double fail: az_result %ld.\n", result);
            exit(1);
        }
    }

    if (times != NULL)
    {

        result = az_json_writer_append_property_name(&jw, command_start_time_name);
        if (az_result_failed(result))
        {
            EWF_LOG("Json writer append property name fail: az_result %ld.\n", result);
            exit(1);
        }

        result = az_json_writer_append_string(&jw, times[0]);
        if (az_result_failed(result))
        {
            EWF_LOG("Json writer append string fail: az_result %ld.\n", result);
            exit(1);
        }

        result = az_json_writer_append_property_name(&jw, command_end_time_name);
        if (az_result_failed(result))
        {
            EWF_LOG("Json writer append property name fail: az_result %ld.\n", result);
            exit(1);
        }

        result = az_json_writer_append_string(&jw, times[1]);
        if (az_result_failed(result))
        {
            EWF_LOG("Json writer append string fail: az_result %ld.\n", result);
            exit(1);
        }
    }

    result = az_json_writer_append_end_object(&jw);
    if (az_result_failed(result))
    {
        EWF_LOG("Json writer append end object fail: az_result %ld.\n", result);
        exit(1);
    }
    *out_property_payload = az_json_writer_get_bytes_used_in_destination(&jw);
}

// update_device_temperature_property updates the simulated device temperature as well
// as the temperature's statistics over time
static void update_device_temperature_property(double temperature, bool* out_is_max_temp_changed)
{
    *out_is_max_temp_changed = false;
    device_current_temperature = temperature;

    // Update maximum or minimum temperatures.
    if (device_current_temperature > device_maximum_temperature)
    {
        device_maximum_temperature = device_current_temperature;
        *out_is_max_temp_changed = true;
    }
    else if (device_current_temperature < device_minimum_temperature)
    {
        device_minimum_temperature = device_current_temperature;
    }

    // Calculate the new average temperature.
    device_temperature_count++;
    device_temperature_summation += device_current_temperature;
    device_average_temperature = device_temperature_summation / device_temperature_count;

    EWF_LOG("Client updated desired temperature variables locally.\r\n");
    EWF_LOG("Current Temperature: %2f\r\n", device_current_temperature);
    EWF_LOG("Maximum Temperature: %2f\r\n", device_maximum_temperature);
    EWF_LOG("Minimum Temperature: %2f\r\n", device_minimum_temperature);
    EWF_LOG("Average Temperature: %2f\r\n", device_average_temperature);
}
