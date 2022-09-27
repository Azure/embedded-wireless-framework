################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/bsp/mcu/all/bsp_clocks.c \
../ra/fsp/src/bsp/mcu/all/bsp_common.c \
../ra/fsp/src/bsp/mcu/all/bsp_delay.c \
../ra/fsp/src/bsp/mcu/all/bsp_group_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_guard.c \
../ra/fsp/src/bsp/mcu/all/bsp_io.c \
../ra/fsp/src/bsp/mcu/all/bsp_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_register_protection.c \
../ra/fsp/src/bsp/mcu/all/bsp_rom_registers.c \
../ra/fsp/src/bsp/mcu/all/bsp_sbrk.c \
../ra/fsp/src/bsp/mcu/all/bsp_security.c 

C_DEPS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.d \
./ra/fsp/src/bsp/mcu/all/bsp_common.d \
./ra/fsp/src/bsp/mcu/all/bsp_delay.d \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_guard.d \
./ra/fsp/src/bsp/mcu/all/bsp_io.d \
./ra/fsp/src/bsp/mcu/all/bsp_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.d \
./ra/fsp/src/bsp/mcu/all/bsp_rom_registers.d \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.d \
./ra/fsp/src/bsp/mcu/all/bsp_security.d 

OBJS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.o \
./ra/fsp/src/bsp/mcu/all/bsp_common.o \
./ra/fsp/src/bsp/mcu/all/bsp_delay.o \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_guard.o \
./ra/fsp/src/bsp/mcu/all/bsp_io.o \
./ra/fsp/src/bsp/mcu/all/bsp_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.o \
./ra/fsp/src/bsp/mcu/all/bsp_rom_registers.o \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.o \
./ra/fsp/src/bsp/mcu/all/bsp_security.o 

SREC += \
ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014.srec 

MAP += \
ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/bsp/mcu/all/%.o: ../ra/fsp/src/bsp/mcu/all/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RA_CORE=CM33 -D_RENESAS_RA_ -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/src" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/inc/api" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/inc/instances" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/rm_threadx_port" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/threadx/common/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_gen" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg/bsp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg/azure/tx" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/private/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/public/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce/common" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/r_sce" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/rm_netxduo_ether" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/rm_netx_secure_crypto/inc/crypto_common" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/fsp/src/rm_netx_secure_crypto/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/pop3" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/snmp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/nat" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/mqtt" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/ftp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/tftp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/sntp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/smtp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/web" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/auto_ip" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/telnet" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/dns" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/dhcp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/http" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/common/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/ports/cortex_m4" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/cloud" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc/configs/RTOS_BASE" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/crypto_libraries/src" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/crypto_libraries/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra/microsoft/azure-rtos/netxduo/nx_secure/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg/middleware" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014/ra_cfg/fsp_cfg/azure/nxd" -I"C:/comms_framework/src" -I"C:/comms_framework/src/examples" -I"C:/comms_framework/src/templates" -I"C:/comms_framework/src/test" -std=c99 -Wno-aggregate-return -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

