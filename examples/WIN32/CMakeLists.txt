cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

if(NOT DEFINED THREADX_ARCH)
  if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE
        "cmake/win32.cmake"
        CACHE STRING "")
  elseif(UNIX)
    set(CMAKE_TOOLCHAIN_FILE
        "cmake/linux.cmake"
        CACHE STRING "")
  else()
    message(FATAL_ERROR "Error: Architecture not supported")
  endif()
endif()

if(DEFINED PCAP_NAME)
  message(STATUS "Use pcap driver on \"${PCAP_NAME}\"")
  add_definitions(-DNX_PCAP_SOURCE_NAME=\"${PCAP_NAME}\")
else()
  message(STATUS "Use TCP/IP offload driver")
  add_definitions(-DNX_ENABLE_TCPIP_OFFLOAD -DNX_ENABLE_INTERFACE_CAPABILITY)
endif()

# Project
project(AzureIoTMiddleware LANGUAGES C ASM)

set(NXD_ENABLE_AZURE_IOT
    ON
    CACHE BOOL "Enable Azure IoT Middleware (default is ON)")
set(NX_AZURE_DISABLE_IOT_SECURITY_MODULE
    OFF
    CACHE BOOL "Disable Azure IoT Security Module (default is OFF)")
set(NXD_ENABLE_FILE_SERVERS
    ON
    CACHE BOOL "Includes a dependency on FileX to support 'server' protocol handlers (default is OFF)")

# CFLAGS
if(WIN32)
  set(ADDITIONAL_C_FLAGS $ENV{CFLAGS} "/MP -DWIN32 -D_CRT_SECURE_NO_WARNINGS")
else()
  if(THREADX_ARCH STREQUAL "linux")
    set(ADDITIONAL_C_FLAGS
        "$ENV{CFLAGS} -O0 -g3 -ggdb -m32 -gdwarf-2 -fdiagnostics-color")
  endif()
endif()

# Add definitions
add_definitions(
  ${ADDITIONAL_C_FLAGS}
  -DTX_TIMER_PERIODIC=10
  -DNX_ENABLE_EXTENDED_NOTIFY_SUPPORT
  -DNX_SECURE_ENABLE
  -DNX_DNS_CLIENT_USER_CREATE_PACKET_POOL
  -DNX_DNS_CLIENT_CLEAR_QUEUE
  -DNXD_MQTT_CLOUD_ENABLE
  -DNX_SNTP_CLIENT_MAX_ROOT_DISPERSION=0
  -DNX_ENABLE_IP_PACKET_FILTER
  -DNX_SECURE_TLS_DISABLE_TLS_1_1
  -DNXD_MQTT_PING_TIMEOUT_DELAY=500
  -DNXD_MQTT_SOCKET_TIMEOUT=0)

# Link libraries
if(THREADX_ARCH STREQUAL "linux")
  add_link_options(-m32)
endif()

###############################################################################
# Add libraries
###############################################################################
add_subdirectory(threadx)
add_subdirectory(netxduo)
add_subdirectory(filex)
if(DEFINED PCAP_NAME)
  add_subdirectory(pcap)
else()
  add_subdirectory(tcpip_offload_driver)
endif()

###############################################################################
# Azure RTOS
###############################################################################

# ThreadX
add_subdirectory(sample_threadx)

# NetX Duo
add_subdirectory(sample_netx_duo_azure_iot_embedded_sdk)
add_subdirectory(sample_netx_duo_azure_iot_embedded_sdk_pnp)
add_subdirectory(sample_netx_duo_pnp_temperature_controller)
add_subdirectory(sample_netx_duo_iperf)

###############################################################################
# FreeRTOS
###############################################################################

# FreeRTOS
add_subdirectory(sample_freertos)

###############################################################################
# EWF
###############################################################################

#######################################
# Adapter WinSock2
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_winsock2)
add_subdirectory(sample_ewf_test_tx_winsock2)
#add_subdirectory(sample_ewf_certs_basic_tx_winsock2)
#add_subdirectory(sample_ewf_telemetry_basic_tx_winsock2)
add_subdirectory(sample_ewf_certs_tx_winsock2)
add_subdirectory(sample_ewf_telemetry_tx_winsock2)

# NetX Duo
add_subdirectory(sample_ewf_netx_duo_test_winsock2)
add_subdirectory(sample_ewf_netx_duo_azure_iot_embedded_sdk_winsock2)
add_subdirectory(sample_ewf_netx_duo_azure_iot_embedded_sdk_pnp_winsock2)
add_subdirectory(sample_ewf_netx_duo_pnp_temperature_controller_winsock2)
add_subdirectory(sample_ewf_netx_duo_iperf_winsock2)

# WIN32
add_subdirectory(sample_ewf_info_win32_winsock2)
add_subdirectory(sample_ewf_test_win32_winsock2)
#add_subdirectory(sample_ewf_certs_basic_win32_winsock2)
#add_subdirectory(sample_ewf_telemetry_basic_win32_winsock2)
add_subdirectory(sample_ewf_certs_win32_winsock2)
add_subdirectory(sample_ewf_telemetry_win32_winsock2)

# FreeRTOS
add_subdirectory(sample_ewf_info_freertos_winsock2)
add_subdirectory(sample_ewf_test_freertos_winsock2)
#add_subdirectory(sample_ewf_certs_basic_freertos_winsock2)
#add_subdirectory(sample_ewf_telemetry_basic_freertos_winsock2)
#add_subdirectory(sample_ewf_certs_freertos_winsock2)
#add_subdirectory(sample_ewf_telemetry_freertos_winsock2)

#######################################
# BG95
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_bg95)
add_subdirectory(sample_ewf_test_tx_bg95)
add_subdirectory(sample_ewf_certs_basic_tx_bg95)
add_subdirectory(sample_ewf_telemetry_basic_tx_bg95)

# NetX Duo
add_subdirectory(sample_ewf_netx_duo_test_bg95)
add_subdirectory(sample_ewf_netx_duo_azure_iot_embedded_sdk_bg95)
add_subdirectory(sample_ewf_netx_duo_azure_iot_embedded_sdk_pnp_bg95)
add_subdirectory(sample_ewf_netx_duo_pnp_temperature_controller_bg95)

# WIN32
add_subdirectory(sample_ewf_info_win32_bg95)
add_subdirectory(sample_ewf_test_win32_bg95)
add_subdirectory(sample_ewf_certs_basic_win32_bg95)
add_subdirectory(sample_ewf_telemetry_basic_win32_bg95)

# FreeRTOS
add_subdirectory(sample_ewf_info_freertos_bg95)
add_subdirectory(sample_ewf_test_freertos_bg95)
add_subdirectory(sample_ewf_certs_basic_freertos_bg95)
add_subdirectory(sample_ewf_telemetry_basic_freertos_bg95)

#######################################
# BG96
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_bg96)
add_subdirectory(sample_ewf_test_tx_bg96)
add_subdirectory(sample_ewf_certs_basic_tx_bg96)
add_subdirectory(sample_ewf_telemetry_basic_tx_bg96)

# NetX Duo
add_subdirectory(sample_ewf_netx_duo_test_bg96)
#add_subdirectory(sample_ewf_netx_duo_azure_iot_embedded_sdk_bg96)
#add_subdirectory(sample_ewf_netx_duo_azure_iot_embedded_sdk_pnp_bg96)
#add_subdirectory(sample_ewf_netx_duo_pnp_temperature_controller_bg96)

# WIN32
add_subdirectory(sample_ewf_info_win32_bg96)
add_subdirectory(sample_ewf_test_win32_bg96)
add_subdirectory(sample_ewf_certs_basic_win32_bg96)
add_subdirectory(sample_ewf_telemetry_basic_win32_bg96)

# FreeRTOS
add_subdirectory(sample_ewf_info_freertos_bg96)
add_subdirectory(sample_ewf_test_freertos_bg96)
add_subdirectory(sample_ewf_certs_basic_freertos_bg96)
add_subdirectory(sample_ewf_telemetry_basic_freertos_bg96)

#######################################
# RYZ014
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_ryz014)
add_subdirectory(sample_ewf_test_tx_ryz014)
add_subdirectory(sample_ewf_certs_basic_tx_ryz014)
add_subdirectory(sample_ewf_telemetry_basic_tx_ryz014)

#######################################
# SIM7000
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_sim7000)

#######################################
# SIM900
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_sim900)

#######################################
# SIM868
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_sim868)

#######################################
# ESP8266
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_esp8266)
add_subdirectory(sample_ewf_test_tx_esp8266)

#######################################
# ESP8285
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_esp8285)
add_subdirectory(sample_ewf_test_tx_esp8285)

#######################################
# ESPWROOM02
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_esp_wroom_02)
add_subdirectory(sample_ewf_test_tx_esp_wroom_02)
add_subdirectory(sample_ewf_netx_duo_azure_iot_embedded_sdk_esp_wroom_02)

#######################################
# Seeed LoRa-E5
#######################################

# ThreadX
add_subdirectory(sample_ewf_info_tx_lora_e5)
