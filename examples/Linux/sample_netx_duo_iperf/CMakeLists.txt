cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_netx_duo_iperf LANGUAGES C ASM)

# Add sample project
add_executable(
  ${PROJECT_NAME} sample_netx_duo_iperf.c)

target_link_libraries(${PROJECT_NAME} PRIVATE netxduo filex)

if(NOT DEFINED PCAP_NAME)
  include(${CMAKE_CURRENT_LIST_DIR}/../tcpip_offload_driver/network_config.cmake)
  target_compile_definitions(${PROJECT_NAME} PRIVATE -DSAMPLE_DHCP_DISABLE)
  network_config(${PROJECT_NAME})
endif()
