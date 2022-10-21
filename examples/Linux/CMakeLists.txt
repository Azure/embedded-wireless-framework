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

# Add libraries
add_subdirectory(threadx)
add_subdirectory(netxduo)
add_subdirectory(filex)
if(DEFINED PCAP_NAME)
  add_subdirectory(pcap)
else()
  add_subdirectory(tcpip_offload_driver)
endif()

# Add samples
add_subdirectory(sample_threadx)
add_subdirectory(sample_azure_iot_embedded_sdk)
add_subdirectory(sample_azure_iot_embedded_sdk_pnp)
add_subdirectory(sample_pnp_temperature_controller)
add_subdirectory(sample_netx_duo_iperf)

# Add EWF examples - ThreadX - BSD socket
add_subdirectory(sample_ewf_info_tx_bsd_sockets)
add_subdirectory(sample_ewf_test_tx_bsd_sockets)
#add_subdirectory(sample_ewf_telemetry_basic_bsd_sockets)
add_subdirectory(sample_ewf_netx_duo_test_bsd_sockets)

# Add EWF examples - POSIX threads - BSD socket
add_subdirectory(sample_ewf_info_pthread_bsd_sockets)
add_subdirectory(sample_ewf_test_pthread_bsd_sockets)
#add_subdirectory(sample_ewf_telemetry_basic_pthread_bsd_sockets)

# Add EWF examples - ThreadX - Quectel BG96
# add_subdirectory(sample_ewf_test_bg96)
# add_subdirectory(sample_ewf_test_bg96)
# add_subdirectory(sample_ewf_telemetry_basic_bg96)
# add_subdirectory(sample_ewf_netx_duo_test_bg96)
