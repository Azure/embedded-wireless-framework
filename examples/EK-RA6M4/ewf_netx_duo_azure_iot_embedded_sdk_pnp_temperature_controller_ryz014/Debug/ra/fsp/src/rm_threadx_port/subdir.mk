################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/rm_threadx_port/tx_iar.c \
../ra/fsp/src/rm_threadx_port/tx_initialize_low_level.c \
../ra/fsp/src/rm_threadx_port/tx_isr_end.c \
../ra/fsp/src/rm_threadx_port/tx_isr_start.c \
../ra/fsp/src/rm_threadx_port/tx_port_wait_thread_ready.c \
../ra/fsp/src/rm_threadx_port/tx_thread_interrupt_control.c \
../ra/fsp/src/rm_threadx_port/tx_thread_interrupt_disable.c \
../ra/fsp/src/rm_threadx_port/tx_thread_interrupt_restore.c \
../ra/fsp/src/rm_threadx_port/tx_thread_schedule.c \
../ra/fsp/src/rm_threadx_port/tx_thread_secure_stack_allocate.c \
../ra/fsp/src/rm_threadx_port/tx_thread_secure_stack_free.c \
../ra/fsp/src/rm_threadx_port/tx_thread_stack_build.c \
../ra/fsp/src/rm_threadx_port/tx_thread_system_return.c \
../ra/fsp/src/rm_threadx_port/tx_timer_interrupt.c \
../ra/fsp/src/rm_threadx_port/txe_thread_secure_stack_allocate.c \
../ra/fsp/src/rm_threadx_port/txe_thread_secure_stack_free.c 

C_DEPS += \
./ra/fsp/src/rm_threadx_port/tx_iar.d \
./ra/fsp/src/rm_threadx_port/tx_initialize_low_level.d \
./ra/fsp/src/rm_threadx_port/tx_isr_end.d \
./ra/fsp/src/rm_threadx_port/tx_isr_start.d \
./ra/fsp/src/rm_threadx_port/tx_port_wait_thread_ready.d \
./ra/fsp/src/rm_threadx_port/tx_thread_interrupt_control.d \
./ra/fsp/src/rm_threadx_port/tx_thread_interrupt_disable.d \
./ra/fsp/src/rm_threadx_port/tx_thread_interrupt_restore.d \
./ra/fsp/src/rm_threadx_port/tx_thread_schedule.d \
./ra/fsp/src/rm_threadx_port/tx_thread_secure_stack_allocate.d \
./ra/fsp/src/rm_threadx_port/tx_thread_secure_stack_free.d \
./ra/fsp/src/rm_threadx_port/tx_thread_stack_build.d \
./ra/fsp/src/rm_threadx_port/tx_thread_system_return.d \
./ra/fsp/src/rm_threadx_port/tx_timer_interrupt.d \
./ra/fsp/src/rm_threadx_port/txe_thread_secure_stack_allocate.d \
./ra/fsp/src/rm_threadx_port/txe_thread_secure_stack_free.d 

OBJS += \
./ra/fsp/src/rm_threadx_port/tx_iar.o \
./ra/fsp/src/rm_threadx_port/tx_initialize_low_level.o \
./ra/fsp/src/rm_threadx_port/tx_isr_end.o \
./ra/fsp/src/rm_threadx_port/tx_isr_start.o \
./ra/fsp/src/rm_threadx_port/tx_port_wait_thread_ready.o \
./ra/fsp/src/rm_threadx_port/tx_thread_interrupt_control.o \
./ra/fsp/src/rm_threadx_port/tx_thread_interrupt_disable.o \
./ra/fsp/src/rm_threadx_port/tx_thread_interrupt_restore.o \
./ra/fsp/src/rm_threadx_port/tx_thread_schedule.o \
./ra/fsp/src/rm_threadx_port/tx_thread_secure_stack_allocate.o \
./ra/fsp/src/rm_threadx_port/tx_thread_secure_stack_free.o \
./ra/fsp/src/rm_threadx_port/tx_thread_stack_build.o \
./ra/fsp/src/rm_threadx_port/tx_thread_system_return.o \
./ra/fsp/src/rm_threadx_port/tx_timer_interrupt.o \
./ra/fsp/src/rm_threadx_port/txe_thread_secure_stack_allocate.o \
./ra/fsp/src/rm_threadx_port/txe_thread_secure_stack_free.o 

SREC += \
ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.srec 

MAP += \
ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/rm_threadx_port/%.o: ../ra/fsp/src/rm_threadx_port/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RA_CORE=CM33 -D_RENESAS_RA_ -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/src" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/inc/api" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/inc/instances" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/src/rm_threadx_port" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/threadx/common/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra_gen" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra_cfg/fsp_cfg/bsp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra_cfg/fsp_cfg" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra_cfg/fsp_cfg/azure/tx" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/private/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/public/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/src/r_sce/common" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/src/r_sce" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/src/rm_netxduo_ether" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/src/rm_netx_secure_crypto/inc/crypto_common" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/fsp/src/rm_netx_secure_crypto/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/pop3" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/snmp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/nat" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/mqtt" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/ftp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/tftp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/sntp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/smtp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/web" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/auto_ip" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/telnet" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/dns" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/dhcp" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/http" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/common/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/ports/cortex_m4" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/cloud" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc/configs/RTOS_BASE" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/crypto_libraries/src" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/crypto_libraries/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra/microsoft/azure-rtos/netxduo/nx_secure/inc" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra_cfg/fsp_cfg/middleware" -I"C:/comms_framework/examples/EK-RA6M4/ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/ra_cfg/fsp_cfg/azure/nxd" -I"C:/comms_framework/src" -I"C:/comms_framework/src/examples" -I"C:/comms_framework/src/templates" -I"C:/comms_framework/src/test" -std=c99 -Wno-aggregate-return -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

