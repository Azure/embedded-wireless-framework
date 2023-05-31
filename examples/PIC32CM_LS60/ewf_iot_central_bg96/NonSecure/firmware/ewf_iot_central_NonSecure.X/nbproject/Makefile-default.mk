#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ewf_iot_central_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ewf_iot_central_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c ../src/config/default/bsp/bsp.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c ../src/config/default/peripheral/systick/plib_systick.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1414040249/az_base64.o ${OBJECTDIR}/_ext/1414040249/az_context.o ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o ${OBJECTDIR}/_ext/1414040249/az_http_policy.o ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o ${OBJECTDIR}/_ext/1414040249/az_http_request.o ${OBJECTDIR}/_ext/1414040249/az_http_response.o ${OBJECTDIR}/_ext/1414040249/az_json_reader.o ${OBJECTDIR}/_ext/1414040249/az_json_token.o ${OBJECTDIR}/_ext/1414040249/az_json_writer.o ${OBJECTDIR}/_ext/1414040249/az_log.o ${OBJECTDIR}/_ext/1414040249/az_precondition.o ${OBJECTDIR}/_ext/1414040249/az_span.o ${OBJECTDIR}/_ext/1292534426/az_iot_common.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o ${OBJECTDIR}/_ext/1434821282/bsp.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1414040249/az_base64.o.d ${OBJECTDIR}/_ext/1414040249/az_context.o.d ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d ${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d ${OBJECTDIR}/_ext/1414040249/az_http_request.o.d ${OBJECTDIR}/_ext/1414040249/az_http_response.o.d ${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d ${OBJECTDIR}/_ext/1414040249/az_json_token.o.d ${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d ${OBJECTDIR}/_ext/1414040249/az_log.o.d ${OBJECTDIR}/_ext/1414040249/az_precondition.o.d ${OBJECTDIR}/_ext/1414040249/az_span.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d ${OBJECTDIR}/_ext/1434821282/bsp.o.d ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d ${OBJECTDIR}/_ext/1865521619/plib_port.o.d ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d ${OBJECTDIR}/_ext/1171490990/initialization.o.d ${OBJECTDIR}/_ext/1171490990/interrupts.o.d ${OBJECTDIR}/_ext/1171490990/exceptions.o.d ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1414040249/az_base64.o ${OBJECTDIR}/_ext/1414040249/az_context.o ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o ${OBJECTDIR}/_ext/1414040249/az_http_policy.o ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o ${OBJECTDIR}/_ext/1414040249/az_http_request.o ${OBJECTDIR}/_ext/1414040249/az_http_response.o ${OBJECTDIR}/_ext/1414040249/az_json_reader.o ${OBJECTDIR}/_ext/1414040249/az_json_token.o ${OBJECTDIR}/_ext/1414040249/az_json_writer.o ${OBJECTDIR}/_ext/1414040249/az_log.o ${OBJECTDIR}/_ext/1414040249/az_precondition.o ${OBJECTDIR}/_ext/1414040249/az_span.o ${OBJECTDIR}/_ext/1292534426/az_iot_common.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o ${OBJECTDIR}/_ext/1434821282/bsp.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c ../src/config/default/bsp/bsp.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c ../src/config/default/peripheral/systick/plib_systick.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/main.c

# Pack Options 
PACK_COMMON_OPTIONS=-I "${CMSIS_DIR}/CMSIS/Core/Include"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/ewf_iot_central_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32CM5164LS60100
MP_LINKER_FILE_OPTION=,--script="..\src\config\default\PIC32CM5164LS60100.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1414040249/az_base64.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c  .generated_files/flags/default/dd67f205bd3110ef924560c7bb931fbec6083ca0 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_base64.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_base64.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_context.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c  .generated_files/flags/default/bd3ee94a007e754b510f3c31de4334e5ddf3c97f .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_context.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_context.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c  .generated_files/flags/default/9157cece1c4014c7e5cc7d1976766f92afb3cee .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c  .generated_files/flags/default/285dbd6a56fe8a18d438b27c5178be8149e18ef2 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c  .generated_files/flags/default/c059df5ecc1da60123c1125f682f0f60b93c14c7 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c  .generated_files/flags/default/c1a697fc51c58b6195f7b186b48b4b8d4187ef80 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_request.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c  .generated_files/flags/default/abd9178a174b39cfc419f87b6267a6164ed5bb26 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_request.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_request.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_response.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c  .generated_files/flags/default/69cc99f38b80c62b21cf7579a8513db4103ba0b3 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_response.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_response.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_reader.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c  .generated_files/flags/default/192a5fa0bead1a89c39e279e059b1e2ea9a82ccd .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_reader.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_token.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c  .generated_files/flags/default/2ac6a5fafa38f59e50f6b77e8400b32901f88070 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_token.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_token.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_writer.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c  .generated_files/flags/default/5feba0358685c211b177a0e6bd1bb00e1c500b6b .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_writer.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_log.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c  .generated_files/flags/default/b14a684db72369f221f41fdf07a5e460f48a29d5 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_log.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_log.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_precondition.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c  .generated_files/flags/default/d734032c471f06a2d87d49f45d6a643119b6c9b7 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_precondition.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_precondition.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_span.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c  .generated_files/flags/default/2a6c28849fb8eb5354cd2bcfb55e99e61195916d .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_span.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_span.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_common.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c  .generated_files/flags/default/242de00788040f07ff53a102bd7d13ca125c0327 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_common.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c  .generated_files/flags/default/8ab0b3d04b58afd7948ad07519779c2a2d86450a .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c  .generated_files/flags/default/dc27dfdfbfc4c0d969d0c8ef43f97bdfb481d56f .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c  .generated_files/flags/default/60815714f14137b17a09fbd0fd24036b7809ba25 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c  .generated_files/flags/default/225398e310ce2e0057d22ab1c3e6b2e31aefeb94 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c  .generated_files/flags/default/14a01a96774a0fa3635808670b7aadca3305368e .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c  .generated_files/flags/default/1caf59ca973f3e0b7ae6a22c13cf38f7984321e0 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c  .generated_files/flags/default/50c596e945dee10d93a4f2e05006291e929124e6 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c  .generated_files/flags/default/83282556e029d9054158879616a1bd308cf3b84c .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c  .generated_files/flags/default/2bbfb84cfe90d60c1616b7af663b6639e7cecc14 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c  .generated_files/flags/default/ccfcff85ab69c10ed361723826ba717e8ac2e8cc .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1434821282/bsp.o: ../src/config/default/bsp/bsp.c  .generated_files/flags/default/728dad263d90e5fb41803f24da89a517ef478f79 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1434821282" 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1434821282/bsp.o.d" -o ${OBJECTDIR}/_ext/1434821282/bsp.o ../src/config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/cb7af264ec21e555c5c1b5b4195d54723a8879d2 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/6ee0b1f36751fba12004b3c08d44e7571cc687da .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c  .generated_files/flags/default/c7f43c3ef25c0e1e9e8f50a1d8eb496625874056 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c  .generated_files/flags/default/a1e781fc78be07611c92eb874059ffa80a5de71c .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/1d3c793645a7b9663d572e667620a84506cd9c24 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/749180edf3095fd53ebdf60129bda187f7b9738e .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/be38c436cf756a3ab7bf996885371ca459f421fb .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/c7948b25e0a874ebc53317b19ab8e8832870a957 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/2874f090474f170dfc142e0a463b5686a6c6c631 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/29bac28cdb6d133f1a3c67f8a241c113e590b58 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/6201ca4d08dbb15e16d80859434203ef24ae12 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/5103e837bd4edb6ef1deb29e840695182bd551f3 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1414040249/az_base64.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c  .generated_files/flags/default/bcb213585c4aab7b562ef0e054cebd043b265361 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_base64.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_base64.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_context.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c  .generated_files/flags/default/d2afd176982664592b5d97f5105bfc17bb7aca15 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_context.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_context.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c  .generated_files/flags/default/de52d3a09ae5834a7a5b5a5ba982c032d8a90795 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c  .generated_files/flags/default/2ab8fe37f54768c370045a42a20bc9444dff256c .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c  .generated_files/flags/default/5a4528605264cda29b381648835026c0f5ffdc1 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c  .generated_files/flags/default/e73cc35c464fff3f4bb615c72c73af1979875d77 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_request.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c  .generated_files/flags/default/a4d1060a435ea6a1d08ffa064f8d7eba4bce110f .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_request.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_request.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_response.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c  .generated_files/flags/default/c56252d6ae1d605d8d4ae0b5b53e6acc41d24fcd .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_response.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_response.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_reader.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c  .generated_files/flags/default/a8459fe546299b39e700c747d24ac2c09a4b4886 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_reader.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_token.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c  .generated_files/flags/default/2ace74685df6ec886b1b04939d76a14e7bcaebb2 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_token.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_token.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_writer.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c  .generated_files/flags/default/3f77c0ec3c232a8b82dbd03568290ec15785413b .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_writer.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_log.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c  .generated_files/flags/default/7dbd038d281735a9290c78ab78746186877c52ed .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_log.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_log.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_precondition.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c  .generated_files/flags/default/a7e14e09872b7287ad90de05d4c3e43e088c8917 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_precondition.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_precondition.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_span.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c  .generated_files/flags/default/9352d5bc88b62736cb4ab1d010a52beafdf192fe .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_span.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_span.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_common.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c  .generated_files/flags/default/2a345890aae0282ae56a23b152ae6cd420343462 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_common.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c  .generated_files/flags/default/b1848eeeecec9ec4310c8e4301363a8a9d2a9a68 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c  .generated_files/flags/default/d470bc3dbd15dc479026a12d2aedef336d8a2316 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c  .generated_files/flags/default/766e41f8745f573f3797424efc2e2eec16cdbbe5 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c  .generated_files/flags/default/142c36fc8e90b548d56ae1a8decb920f71df9fb4 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c  .generated_files/flags/default/1de308a38854011a4b39ebbd039b4f39a8e865ea .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c  .generated_files/flags/default/dce9ca1ae583129ff0c025fb1e51a2be8af1f1d8 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c  .generated_files/flags/default/e2d66f0f4a4ea6b93eb32664a562551b67813d6a .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c  .generated_files/flags/default/de7715882ad86d828f1e14e3b713ff5c479d233d .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c  .generated_files/flags/default/602fdbcabe7fe9fa86d7a0cf1d8ff1bbaf64eaa3 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c  .generated_files/flags/default/8865db38ac41e0629a0fdeb98f60a30c75a19fd3 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1434821282/bsp.o: ../src/config/default/bsp/bsp.c  .generated_files/flags/default/dcdcaead896bfaf62f1145465c3320b7cf31b84d .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1434821282" 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1434821282/bsp.o.d" -o ${OBJECTDIR}/_ext/1434821282/bsp.o ../src/config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/37157ecae35fad2357ab80237ca6856b3f0fb263 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/4bb540907c52ede6a8da345de5e73c1f072a0fd3 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c  .generated_files/flags/default/d508f6a64e64e20c51fae7ac0cb8e956e371ceac .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c  .generated_files/flags/default/3f71f663cb98be628b1639ff72e7f27ba8f5afad .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/f4f151a626409de4b0ad084ed91e6dd84cdafc90 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/fedc1a24f2e9c87222bea21fa5edb83a9a0ae960 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/6bf5d2fc6da55f7887db6e98974b5b8cb233d686 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/98304f60d969e74daca61b46cfb18a45e9dd9d91 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/3fc66f0d2505d27cb9b9f8a0d22ce96aa64d3f7e .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/72b6eec823843554e73729d67ade3da6c55ccaec .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/a60a28007a50126c1cb2e281c8483d9b2e5b04f2 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/6795e42c2439cbf17025ace022350a6f2cb176f1 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/ewf_iot_central_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/default/PIC32CM5164LS60100.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/ewf_iot_central_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=512,--gc-sections,-L"./",-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DAS_SIZE=0x40000,-DBOOTPROT_SIZE=0x0,-DNONSECURE,-DRS_SIZE=0x8000,--memorysummary,${DISTDIR}/memoryfile.xml,-l:ewf_iot_central_Secure_sg_veneer.lib -mdfp="${DFP_DIR}/PIC32CM-LS60"
	
else
${DISTDIR}/ewf_iot_central_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/default/PIC32CM5164LS60100.ld ../../../Secure/firmware/ewf_iot_central_Secure.X/dist/default/production/ewf_iot_central_Secure.X.production.hex
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/ewf_iot_central_NonSecure.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,-L"./",-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DAS_SIZE=0x40000,-DBOOTPROT_SIZE=0x0,-DNONSECURE,-DRS_SIZE=0x8000,--memorysummary,${DISTDIR}/memoryfile.xml,-l:ewf_iot_central_Secure_sg_veneer.lib -mdfp="${DFP_DIR}/PIC32CM-LS60"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/ewf_iot_central_NonSecure.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
	@echo "Creating unified hex file"
	@"C:/Program Files/Microchip/MPLABX/v6.00/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v6.00/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" ${DISTDIR}/ewf_iot_central_NonSecure.X.${IMAGE_TYPE}.hex ../../../Secure/firmware/ewf_iot_central_Secure.X/dist/default/production/ewf_iot_central_Secure.X.production.hex -odist/${CND_CONF}/production/ewf_iot_central_NonSecure.X.production.unified.hex

endif


# Subprojects
.build-subprojects:
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
	cd ../../../Secure/firmware/ewf_iot_central_Secure.X && ${MAKE}  -f Makefile CONF=default TYPE_IMAGE=DEBUG_RUN
else
	cd ../../../Secure/firmware/ewf_iot_central_Secure.X && ${MAKE}  -f Makefile CONF=default
endif


# Subprojects
.clean-subprojects:
	cd ../../../Secure/firmware/ewf_iot_central_Secure.X && rm -rf "build/default" "dist/default"

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
