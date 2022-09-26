cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Project
project(sample_netx_duo_azure_iot_embedded_sdk_pnp LANGUAGES C ASM)

# Add sample project
add_executable(${PROJECT_NAME} main.c
                               nx_azure_iot_cert.c
                               nx_azure_iot_ciphersuites.c
                               sample_device_identity.c
                               sample_azure_iot_embedded_sdk_pnp.c)

target_link_libraries(${PROJECT_NAME} PRIVATE netxduo)

if(NOT DEFINED PCAP_NAME)
  include(${CMAKE_CURRENT_LIST_DIR}/../tcpip_offload_driver/network_config.cmake)
  target_compile_definitions(${PROJECT_NAME} PRIVATE -DSAMPLE_DHCP_DISABLE)
  network_config(${PROJECT_NAME})
endif()