cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_ewf_netx_duo_test_bg96 LANGUAGES C ASM)

# Add sample project
add_executable(
    ${PROJECT_NAME}
    sample_netx_duo_test.c)

target_link_libraries(${PROJECT_NAME} PRIVATE threadx netxduo az_core az_iot_hub)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../common
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/examples
    ${CMAKE_CURRENT_SOURCE_DIR}/../netxduo/addons/azure_iot/azure-sdk-for-c/sdk/inc)
