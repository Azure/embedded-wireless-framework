cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_ewf_certs_win32_winsock2 LANGUAGES C ASM)

# Add sample project
add_executable(
    ${PROJECT_NAME}
    sample_certs.c)

target_link_libraries(${PROJECT_NAME} PRIVATE)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../common
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/examples)
