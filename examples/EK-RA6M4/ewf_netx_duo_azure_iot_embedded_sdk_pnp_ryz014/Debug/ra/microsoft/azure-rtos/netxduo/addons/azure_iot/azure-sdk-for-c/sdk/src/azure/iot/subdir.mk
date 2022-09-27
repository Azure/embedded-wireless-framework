################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c \
../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c 

C_DEPS += \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.d \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.d 

OBJS += \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.o \
./ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.o 

SREC += \
ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014.srec 

MAP += \
ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014.map 


# Each subdirectory must supply rules for building sources it contributes
ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/%.o: ../ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RA_CORE=CM33 -D_RENESAS_RA_ -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/src" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/inc/api" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/inc/instances" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/rm_threadx_port" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/threadx/common/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_gen" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg/bsp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg/azure/tx" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/private/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/public/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce/common" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/rm_netxduo_ether" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/rm_netx_secure_crypto/inc/crypto_common" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/rm_netx_secure_crypto/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/pop3" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/snmp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/nat" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/mqtt" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/ftp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/tftp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/sntp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/smtp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/web" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/auto_ip" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/telnet" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/dns" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/dhcp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/http" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/common/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/ports/cortex_m4" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/cloud" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc/configs/RTOS_BASE" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/crypto_libraries/src" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/crypto_libraries/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/nx_secure/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg/middleware" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg/azure/nxd" -I"C:/comms_framework/src" -I"C:/comms_framework/src/examples" -I"C:/comms_framework/src/templates" -I"C:/comms_framework/src/test" -std=c99 -Wno-aggregate-return -w -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

