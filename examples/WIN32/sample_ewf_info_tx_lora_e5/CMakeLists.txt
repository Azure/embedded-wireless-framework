cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_ewf_info_tx_lora_e5 LANGUAGES C ASM)

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
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_lora.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_api_lora.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_seeed_lora_e5.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ewf_adapter_seeed_lora_e5.c
    ewf.config.h
    ewf_example.config.h
    sample_info.c)

target_link_libraries(${PROJECT_NAME} PRIVATE threadx)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../common
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/examples)
