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
    main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE az_core az_iot_hub)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../common
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/common/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/portable/MSVC-MingW
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/examples
    ${CMAKE_CURRENT_SOURCE_DIR}/../netxduo/addons/azure_iot/azure-sdk-for-c/sdk/inc)
