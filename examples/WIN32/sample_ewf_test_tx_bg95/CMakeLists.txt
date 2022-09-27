cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_ewf_test_tx_bg95 LANGUAGES C ASM)

# Add sample project
add_executable(
    ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_ids.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_lib.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_lib.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_platform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_platform_threadx.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_platform_threadx.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator_threadx.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator_threadx.c
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
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_quectel_bg95.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_quectel_bg95.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/test/ewf_adapter_quectel_bg95_test.c
    ewf.config.h
    ewf_example.config.h
    sample_test.c)

target_link_libraries(${PROJECT_NAME} PRIVATE threadx az_core az_iot_hub)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../test)
