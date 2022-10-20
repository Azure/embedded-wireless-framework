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
${OBJECTDIR}/_ext/1414040249/az_base64.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c  .generated_files/flags/default/cebc2205256df0dfe7d443aa5ff5086d231554a1 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_base64.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_base64.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_context.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c  .generated_files/flags/default/f81cc0dc77a2000f0c0bee6ab4136d42b4ab1e41 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_context.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_context.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c  .generated_files/flags/default/17a1f71ad17121fd4d214d423352e0c586219742 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c  .generated_files/flags/default/206f827e56ee1996f308f49dbaa4a19f8d360a30 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c  .generated_files/flags/default/ff7ffa83c496320c5852ef3fe094fa1d6d29a4 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c  .generated_files/flags/default/edbd468511cb974cd5a7f19f01de2745a3aeaf05 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_request.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c  .generated_files/flags/default/88b11ffedc5eeade9208b9e6e499895537ffcbf .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_request.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_request.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_response.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c  .generated_files/flags/default/6933a387d3c2a813f4c894839335d2e1eb155ce2 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_response.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_response.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_reader.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c  .generated_files/flags/default/b8025796327923ebaf61000c624ed1101e320639 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_reader.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_token.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c  .generated_files/flags/default/b49e8bfb4e7b571224f33f7986efebc0ef16a1cd .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_token.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_token.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_writer.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c  .generated_files/flags/default/400f6cd4f87ef8db771616403b837dd9eb004467 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_writer.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_log.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c  .generated_files/flags/default/6bb573b85a5e20bba4d331c7e2134d2e6e28ae4f .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_log.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_log.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_precondition.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c  .generated_files/flags/default/9025e3d92b3cc9241fb7e5df05bf0d7580d7862d .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_precondition.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_precondition.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_span.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c  .generated_files/flags/default/c336d376902afcf3d4b100e9af37cff92754afdf .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_span.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_span.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_common.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c  .generated_files/flags/default/9d398d78bf05937bd149e8807b356bc3c8493407 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_common.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c  .generated_files/flags/default/a50ca49a088cf1a388f5b46af558bcc57319ea2 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c  .generated_files/flags/default/fee5881ae8819cf803bad27cbbe8d1c59a658500 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c  .generated_files/flags/default/8ce80b88e4537f99e19d1d1ce71bb9bd8285b90d .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c  .generated_files/flags/default/5eba0e96342a3c8883e24e565feaafb9dbe47c55 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c  .generated_files/flags/default/e9aa5ca317be622bf8732235263203eef750f32d .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c  .generated_files/flags/default/41fa2c27245eff373d41bbe7ab31c34cbc1b93c3 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c  .generated_files/flags/default/604df661ec281fa6a1a5e2bded4eadcd07af865c .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c  .generated_files/flags/default/db0f19dd1f49238b9f2b73326047e16e3292d61f .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c  .generated_files/flags/default/149f8352151ac9aee5302afefae8ab84aa2a72af .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c  .generated_files/flags/default/39ea273317cdc32a1d602203f2c1954ce1e5388a .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1434821282/bsp.o: ../src/config/default/bsp/bsp.c  .generated_files/flags/default/8b1dfa72c7063b445aea5b4936a5aefb904ba6e8 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1434821282" 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1434821282/bsp.o.d" -o ${OBJECTDIR}/_ext/1434821282/bsp.o ../src/config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/cb7b77d4c7bfaf879f12cd32c8025a5016f96d84 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/2b3c5476f2511b697dfbce9276f53df40bc9a071 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c  .generated_files/flags/default/dbd2b526403df45733e3901253ca884792276fd .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c  .generated_files/flags/default/541729bdf2c347dd76cd77f468a2a0de11c8392e .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/c57114db1bffafb8982ffa7bf9688ed4889ead4c .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/94edd354da1310e018739b8ccd0016a6aac68ce2 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/c9ad103d7da136aaa9dcd54edc7bcb090d1b0953 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/aba014fa76e420c4cc9d780af72bdfe98a241092 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/310f59a58b3b9bc7fca3235c9d1a7d90e256acb9 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/78cf9485bcffb70786e64eeeace6317f850468a1 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/9bce974a1a8322010dc5c3015ba3883208e22b6b .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/e25682a64641f59cd301a5db98eb6a9269f42696 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1414040249/az_base64.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c  .generated_files/flags/default/235bb2633ed49b650d2441f89997f1d0a8e2c2ae .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_base64.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_base64.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_context.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c  .generated_files/flags/default/bf4d575dca1404aff9c1eaab2d1e5c903f3bd6b3 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_context.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_context.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c  .generated_files/flags/default/e33dca9e455023296f4d953b6172d34cd2bc6770 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c  .generated_files/flags/default/e8dad5cb1fa1f302425f083e0cc58f1856c5e186 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c  .generated_files/flags/default/6e9752d767e46c1dd5e45203891c3d98794cca91 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c  .generated_files/flags/default/b3550437ceaf0912b93c74219f6d7b9777e3b983 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_request.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c  .generated_files/flags/default/60db7b335d22db3ce9c4362be2e5cc21e899a310 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_request.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_request.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_response.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c  .generated_files/flags/default/5f6da7881ebb8a9157e384f5966c1fe782c10fcf .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_response.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_response.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_reader.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c  .generated_files/flags/default/9a027d68b6150cd9be8968d203b82f4bbbfb29d2 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_reader.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_token.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c  .generated_files/flags/default/e7b2f5cf9c21ba0c4fb26bf68981f2f384993085 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_token.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_token.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_writer.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c  .generated_files/flags/default/a197fea3ba0c79ea0cdbd19b301d9a4921fd7419 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_writer.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_log.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c  .generated_files/flags/default/2b757a9dfa86f814a1264617e349811593b6681 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_log.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_log.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_precondition.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c  .generated_files/flags/default/8e035f2197a45aae403e8fe3b4b7483ab2a9458f .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_precondition.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_precondition.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_span.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c  .generated_files/flags/default/a8f20929a1c5b1f592f80f704bb5966e045ea8ab .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_span.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_span.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_common.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c  .generated_files/flags/default/e8aaf8d19ee3754fb3aac3028466c3d8225ecb76 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_common.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c  .generated_files/flags/default/26223156bdddfaca1a3a040cd48bdda8851db7f1 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c  .generated_files/flags/default/bf32e5ada02c9ab0cadc7fe65864ee91e85548d3 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c  .generated_files/flags/default/1f216f3e3806a1c9fc77590cb8a125194019f2d2 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c  .generated_files/flags/default/c173f988ee101232b3a6315aa88bd00d60978206 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c  .generated_files/flags/default/9c72f3ab392a59b22c70e8ec28b299ab01c7c62d .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c  .generated_files/flags/default/6a7352a411ce9745bee0031347fc6c7b02a5d49d .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c  .generated_files/flags/default/a6a77a47380dee8fb3ac98002960a17ad1c98022 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c  .generated_files/flags/default/1bfc73b31a3aad475dbe74a7fca8511f9185df08 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c  .generated_files/flags/default/d55a3154032c18c20b308f4882bca02b5e6d21e6 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c  .generated_files/flags/default/8663717206261037ea840b48e8a908e28a8c12ce .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1434821282/bsp.o: ../src/config/default/bsp/bsp.c  .generated_files/flags/default/e92b659dc8cd123ae7fe015711a99777060deba9 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1434821282" 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1434821282/bsp.o.d" -o ${OBJECTDIR}/_ext/1434821282/bsp.o ../src/config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/ba89b0a49daba739f4c2fbbe7ae0250acf0bd73f .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/50403262d9ac320b37e36b474080c2cd2d5eb3ee .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c  .generated_files/flags/default/f68263b4e6a7d94c7c0533aa370559b2985f93f7 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c  .generated_files/flags/default/94ff968bf1d27bdc5336352b4960e5283f7cef16 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/fad78cba975c483798f0d45a07d5e2981583093e .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/861ef459d58c523f72c60f13b06a4821b4e7c8f .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/26e0a84987aa8424aadebd5b5e99b89dcee19a41 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/8599ef14b9b35171016ac06497a17f5b0ffe9242 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/89c1c0e6711d006b47b1343dbee1f08d05546ff9 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/c2eb3ad089aa8e07d2ab41ddd42c38cbedf0596b .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/a77809f99a493ab809d523c023244edb2bcecd85 .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/db6ed550280769688a478e3e75f5a0816465733f .generated_files/flags/default/de01abd07ef75e90ebce5fe6b3bafdcaf818cb4
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
