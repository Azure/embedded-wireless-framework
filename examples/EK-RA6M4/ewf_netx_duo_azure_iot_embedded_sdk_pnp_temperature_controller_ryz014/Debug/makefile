################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

-include makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/SEGGER_RTT/subdir.mk
-include src/subdir.mk
-include ra_gen/subdir.mk
-include ra/microsoft/azure-rtos/threadx/common/src/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/nx_secure/src/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/crypto_libraries/src/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/common/src/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/web/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/tftp/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/telnet/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/sntp/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/snmp/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/smtp/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/pop3/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/nat/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/mqtt/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/http/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/ftp/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/dns/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/dhcp/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/cloud/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/platform/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/iot/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src/azure/core/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/azure_iot/subdir.mk
-include ra/microsoft/azure-rtos/netxduo/addons/auto_ip/subdir.mk
-include ra/fsp/src/rm_threadx_port/subdir.mk
-include ra/fsp/src/rm_netxduo_ether/subdir.mk
-include ra/fsp/src/rm_netx_secure_crypto/subdir.mk
-include ra/fsp/src/r_sci_uart/subdir.mk
-include ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/subdir.mk
-include ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/adaptors/subdir.mk
-include ra/fsp/src/r_ioport/subdir.mk
-include ra/fsp/src/r_icu/subdir.mk
-include ra/fsp/src/r_gpt/subdir.mk
-include ra/fsp/src/r_ether_phy/targets/KSZ8091RNB/subdir.mk
-include ra/fsp/src/r_ether_phy/targets/KSZ8041/subdir.mk
-include ra/fsp/src/r_ether_phy/targets/ICS1894/subdir.mk
-include ra/fsp/src/r_ether_phy/targets/DP83620/subdir.mk
-include ra/fsp/src/r_ether_phy/subdir.mk
-include ra/fsp/src/r_ether/subdir.mk
-include ra/fsp/src/r_adc/subdir.mk
-include ra/fsp/src/bsp/mcu/all/subdir.mk
-include ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/subdir.mk
-include ra/board/ra6m4_ek/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(P_UPPER_DEPS)),)
-include $(P_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(PP_UPPER_DEPS)),)
-include $(PP_UPPER_DEPS)
endif
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif
ifneq ($(strip $(FSY_UPPER_DEPS)),)
-include $(FSY_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(JMP_UPPER_DEPS)),)
-include $(JMP_UPPER_DEPS)
endif
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(SX_UPPER_DEPS)),)
-include $(SX_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.srec \

SECONDARY_SIZE += \
ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.siz \


# All Target
all: ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf secondary-outputs

# Tool invocations
ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf: $(OBJS) $(USER_OBJS) $(LINKER_SCRIPT)
	$(file > ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -T "fsp.ld" -Xlinker --gc-sections -L "C:\\comms_framework\\examples\\EK-RA6M4\\ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014/script" -Wl,-Map,"ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.map" --specs=nano.specs -u _printf_float -u _scanf_float --specs=rdimon.specs -o "ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf" -Wl,--start-group $(OBJS) $(USER_OBJS) $(LIBS) -Wl,--end-group)
	@echo Building target: $@ && arm-none-eabi-gcc @"ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf.in"

ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.srec: ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf
	arm-none-eabi-objcopy -O srec "ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf"  "ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.srec"

ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.siz: ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf
	arm-none-eabi-size --format=berkeley "ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf"

# Other Targets
clean:
	-$(file > clean_file.tmp,  $(JMP_DEPS)  $(FSY_DEPS)  $(C_UPPER_DEPS)  $(SECONDARY_SIZE)  $(SRC_UPPER_DEPS)  $(P_UPPER_DEPS)  $(S_DEPS)  $(PP_UPPER_DEPS)  $(P_DEPS)  $(FSY_UPPER_DEPS)  $(C_DEPS)  $(SRC_DEPS)  $(JMP_UPPER_DEPS)  $(PP_DEPS)  $(ASM_UPPER_DEPS)  $(SX_DEPS)  $(SX_UPPER_DEPS)  $(OBJS)  $(SECONDARY_FLASH)  $(ASM_DEPS)  $(SREC)  $(S_UPPER_DEPS)  $(MAP) )
	-@ xargs -P 2 -s 32000 -t -a clean_file.tmp $(RM)
	-@$(RM) clean_file.tmp
	-$(RM)  ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
