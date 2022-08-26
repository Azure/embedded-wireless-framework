cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_ewf_certs_win32_winsock2 LANGUAGES C ASM)

# Add sample project
add_executable(
    ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_ids.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_lib.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_lib.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_platform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_platform_win32.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_platform_win32.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator_c_heap.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_allocator_c_heap.c
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
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_winsock2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_winsock2.c
    ewf.config.h
    ewf_example.config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/examples/ewf_example_certs_basic_winsock2.c
    sample_certs.c)

target_link_libraries(${PROJECT_NAME} PRIVATE)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/examples)
