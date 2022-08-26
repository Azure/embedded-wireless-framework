cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_ewf_telemetry_basic_freertos_bg96 LANGUAGES C ASM)

# Add sample project
add_executable(
    ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/portable/MSVC-MingW/port.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/event_groups.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/queue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/stream_buffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/tasks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/timers.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_ids.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_lib.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_lib.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_platform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_platform_freertos.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_platform_freertos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator_memory_pool.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator_memory_pool.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_interface.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_interface.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_interface_win32_com.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_interface_win32_com.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_control.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_control.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_info.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_info.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_tls.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_tls.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_tls_basic.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_tls_basic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_dtls.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_dtls.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_tcp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_tcp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_udp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_udp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_mqtt.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_mqtt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_mqtt_basic.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_mqtt_basic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_general.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_general.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_network_service.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_network_service.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_packet_domain.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_packet_domain.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_sim_utility.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_sim_utility.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_sms.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_modem_sms.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_quectel_bg96.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_quectel_bg96.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/examples/ewf_example_telemetry_basic.c
    ewf.config.h
    ewf_example.config.h
    main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE az_core az_iot_hub)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/common/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/portable/MSVC-MingW
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/examples
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../externals/azure-sdk-for-c/sdk/inc)
