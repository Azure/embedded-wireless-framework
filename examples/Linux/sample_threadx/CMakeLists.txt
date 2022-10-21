cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_threadx LANGUAGES C ASM)

# Add sample project
add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE threadx)