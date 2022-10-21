macro(network_symbol_add target symbol address)
  string(REPLACE "." ";" addresses "${address}")
  string(JOIN "," addresses ${addresses})
  string(STRIP ${addresses} addresses)
  target_compile_definitions(${target}
                             PRIVATE "-D${symbol}=IP_ADDRESS\(${addresses}\)")
endmacro()

set(CURRENT_LIST_DIR ${CMAKE_CURRENT_LIST_DIR})

# Configure IP address
macro(network_config target)
  if (UNIX)
    execute_process(COMMAND bash "-c" "ip route|awk '/^default/ {print $3}'"
                    OUTPUT_VARIABLE GATEWAY_ADDRESS)
    execute_process(
      COMMAND
        bash "-c"
        "ifconfig $(ip route|awk '/^default/ {print $5}')|awk '/netmask/{ print $2;}'"
      OUTPUT_VARIABLE IP_ADDRESS)
    execute_process(
      COMMAND
        bash "-c"
        "ifconfig $(ip route|awk '/^default/ {print $5}')|awk '/netmask/{ print $4;}'"
      OUTPUT_VARIABLE NETMASK)
    execute_process(
      COMMAND bash "-c"
              "grep nameserver /etc/resolv.conf|awk '{ print $2;}'|head -n1"
      OUTPUT_VARIABLE DNS_SERVER)
  else()
    execute_process(COMMAND PowerShell -ExecutionPolicy Bypass -File ${CURRENT_LIST_DIR}/network_config.ps1
                    OUTPUT_VARIABLE IP_ADDRESSES)
    string(REGEX REPLACE "\n" ";" ADDRESS_LIST "${IP_ADDRESSES}")
    list(GET ADDRESS_LIST 0 GATEWAY_ADDRESS)
    list(GET ADDRESS_LIST 1 IP_ADDRESS)
    list(GET ADDRESS_LIST 2 DNS_SERVER)
    list(GET ADDRESS_LIST 3 NETMASK)
  endif()
  network_symbol_add(${target} SAMPLE_IPV4_ADDRESS ${IP_ADDRESS})
  network_symbol_add(${target} SAMPLE_IPV4_MASK ${NETMASK})
  network_symbol_add(${target} SAMPLE_GATEWAY_ADDRESS ${GATEWAY_ADDRESS})
  network_symbol_add(${target} SAMPLE_DNS_SERVER_ADDRESS ${DNS_SERVER})
endmacro()
