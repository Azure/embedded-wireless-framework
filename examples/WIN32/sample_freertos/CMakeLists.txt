cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_freertos LANGUAGES C ASM)

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

target_link_libraries(${PROJECT_NAME} PRIVATE)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/common/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../freertos/portable/MSVC-MingW)
