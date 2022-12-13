cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_az_sdnet_telemetry_linux_socket LANGUAGES C ASM)

# Add sample project
add_executable(
    ${PROJECT_NAME}
    sample_telemetry.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/az_sdnet_lib.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/az_sdnet_adapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/az_sdnet_adapter_linux_socket.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/az_sdnet_allocator_threadx.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/az_sdnet_platform_threadx.c)

target_link_libraries(${PROJECT_NAME} PRIVATE threadx az_core az_iot_hub)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../common
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/examples
    ${CMAKE_CURRENT_SOURCE_DIR}/../netxduo/addons/azure_iot/azure-sdk-for-c/sdk/inc)
