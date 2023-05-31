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
FINAL_IMAGE=${DISTDIR}/ewf_telemetry_bm_bg96_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ewf_telemetry_bm_bg96_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/ewf_telemetry_bm_bg96_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/1414040249/az_base64.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c  .generated_files/flags/default/5a59fa8cac18c7233f2932e2ef64fb660c043ece .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_base64.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_base64.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_context.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c  .generated_files/flags/default/db7424b3d2dcffb21bdba023a263a409010c03a5 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_context.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_context.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c  .generated_files/flags/default/453c724e2d32d0fa2f03a406f8832bfd5cab3b3 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c  .generated_files/flags/default/3afdb6543adaf0c705863e0e90c1f3190f7d5f05 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c  .generated_files/flags/default/55ecc99804f3d30367a55b2dea48819154422976 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c  .generated_files/flags/default/fa9e0cdb1cce6145b8b354da87cb008f7d0a275e .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_request.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c  .generated_files/flags/default/f2d37a6707aeef1492f5a65150144c05946afe21 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_request.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_request.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_response.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c  .generated_files/flags/default/8ba20d1755f2fee7942f8f832d894ccd3bbc8a9b .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_response.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_response.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_reader.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c  .generated_files/flags/default/e0dc41e96eb2d4eb98b9fea664df17edee14bf68 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_reader.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_token.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c  .generated_files/flags/default/cca1fd7db8f8710272c2f53bbcda5351124abec1 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_token.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_token.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_writer.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c  .generated_files/flags/default/d68873512fa60920837c2c3ae22178de1b040263 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_writer.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_log.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c  .generated_files/flags/default/dfefe40c5cec695ab83450474fa7cb4d25c9f632 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_log.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_log.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_precondition.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c  .generated_files/flags/default/4d911fdbfe97c2b991fd9800f4c3c94bd88bcc9d .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_precondition.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_precondition.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_span.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c  .generated_files/flags/default/a8f5a853df4282b41d8a0287811e4ca828015e73 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_span.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_span.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_common.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c  .generated_files/flags/default/81e3a1bd6348c06efaefd243fa4c9361f8a1094b .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_common.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c  .generated_files/flags/default/2c1def88dd1a07fc614ff7ac9efe4b7856885556 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c  .generated_files/flags/default/943f6f8a75833443b491b2902190e5f92560eaad .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c  .generated_files/flags/default/c7820751fc8ad76c8171ecdb32593ffe80f76b00 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c  .generated_files/flags/default/35372bc8c30e715cde47b9bc5749229cd07f0688 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c  .generated_files/flags/default/6772b7d80e90286cdaf57fe2b56256b4b59deb00 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c  .generated_files/flags/default/7f55d0f974652b8a6fefc8be8a71b4f2043d7d7c .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c  .generated_files/flags/default/b9bbb31e0a72429650f12aef0e03705f9b1c725f .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c  .generated_files/flags/default/d162b3317ba25072007facd0de6551a0d7937c15 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c  .generated_files/flags/default/fbf842d94e25c914f2d875046bf654c216b8c574 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c  .generated_files/flags/default/8032fac6838a70fb756d2dcd79d198de956d1a19 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1434821282/bsp.o: ../src/config/default/bsp/bsp.c  .generated_files/flags/default/5250d7b8bbcd95344ae517bbe5158d672fad9baf .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1434821282" 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1434821282/bsp.o.d" -o ${OBJECTDIR}/_ext/1434821282/bsp.o ../src/config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/f25e44617c6babe40cb17e656900d0af0806ed00 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/6b6ba554038aa30d04f5bbf4301e1351b98cbe75 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c  .generated_files/flags/default/d41a386efd611f6ddb7d018af9a6f003a4327c08 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c  .generated_files/flags/default/7ab18d31c8196f278687d4ead3f615bf40fc10d7 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/8d67a2051dd8cf9e40dcbf0ab5569ddcbce4393f .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/d75aac0e34614e99e43f9e929fe6d63739422e6a .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/4de4349ca918b90ada84ff49056d96ebdab224ab .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/4c5aede6aee9cff27ddcc63597aed7b4fc477ffd .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/9e6d2e9a894e3d4b72c46520f0141b3cef29ba20 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/9cb14821ff94524254cfa04b6641c35e0311a88b .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/5e96569a55a4ed20bd2ec2f8cf8d09b56cb35dac .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/125c3469ee8c3068eedb82b4b647c66a025aa694 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1414040249/az_base64.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c  .generated_files/flags/default/9eda8ef9e76cabe51855af4653badd2663b89781 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_base64.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_base64.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_base64.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_base64.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_context.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c  .generated_files/flags/default/4e1bf861c2555c1e1e7d978f4b007bc9a57c4723 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_context.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_context.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_context.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_context.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c  .generated_files/flags/default/d29b47f483a8acccec350526248ebc14fdb5e6c9 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_pipeline.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_pipeline.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c  .generated_files/flags/default/70aaf2fcd3725577f92554625ad11592a07f2c33 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c  .generated_files/flags/default/c9bb909c41b57882e74700bbf90566874d7338d6 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_logging.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_logging.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c  .generated_files/flags/default/483fdbac159056615372a5d5b1e147f66bc0c3d2 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_policy_retry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_policy_retry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_request.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c  .generated_files/flags/default/9485fa100be079e1614cc77d899b95ceda38182c .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_request.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_request.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_request.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_request.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_http_response.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c  .generated_files/flags/default/f75203a23e734a28dc9f4d23ec9745387a27da18 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_http_response.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_http_response.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_http_response.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_http_response.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_reader.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c  .generated_files/flags/default/d1a4bc55f62c081a9a857c3a2b1ce3840af369e0 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_reader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_reader.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_reader.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_reader.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_token.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c  .generated_files/flags/default/1ce7d26ba59587883e508a8ad44b9caa89c1929 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_token.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_token.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_token.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_token.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_json_writer.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c  .generated_files/flags/default/eb2bfac9235e0a5b25cd33581ec8c9598e111650 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_json_writer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_json_writer.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_json_writer.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_json_writer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_log.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c  .generated_files/flags/default/9f7e9d2fab026b72440a48700c5443defa1ddbb5 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_log.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_log.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_log.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_log.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_precondition.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c  .generated_files/flags/default/a62f4993ec2b67b7d8bafffcdd298df6f74d1175 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_precondition.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_precondition.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_precondition.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_precondition.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1414040249/az_span.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c  .generated_files/flags/default/20f12a9e06ed78c497549190a2bb7d08238dbc90 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1414040249" 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o.d 
	@${RM} ${OBJECTDIR}/_ext/1414040249/az_span.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1414040249/az_span.o.d" -o ${OBJECTDIR}/_ext/1414040249/az_span.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/core/az_span.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_common.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c  .generated_files/flags/default/71cf364d4151eb20f4331da547e62935caa9de70 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_common.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_common.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_common.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_common.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c  .generated_files/flags/default/c4caece951f126ea54dcd68c1d7d5d9f6594aa51 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c  .generated_files/flags/default/36d02a3ef9a9e67c8380d28624d000520910362d .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_c2d.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_c2d.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c  .generated_files/flags/default/96c006ec0235ca9b842c41412fde3590e8c4ed57 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_commands.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c  .generated_files/flags/default/7f3d35c286fc02ebde7c0c0fd2676294277b4c5c .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_methods.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_methods.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c  .generated_files/flags/default/7cee7faf3d200e524407ccaede70e0db4e9e599f .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_properties.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_properties.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c  .generated_files/flags/default/8573c7a7daa91bcb0815f039e22cfa1d299c1d57 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c  .generated_files/flags/default/28bdb8812df1db206a33216eb0ae924aff1269dd .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_telemetry.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_telemetry.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c  .generated_files/flags/default/16681b1d778746128bf64af9a6b60c163ec0d14e .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_hub_client_twin.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_hub_client_twin.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c  .generated_files/flags/default/4bf47b5d65b1af9cd483ee1eeefcf4de54da330c .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o: ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c  .generated_files/flags/default/9ef1ccbc13536bcf7e7660577f71d2665c8c8c4 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1292534426" 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o.d" -o ${OBJECTDIR}/_ext/1292534426/az_iot_provisioning_client_sas.o ../../../../../../externals/azure-sdk-for-c/sdk/src/azure/iot/az_iot_provisioning_client_sas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1434821282/bsp.o: ../src/config/default/bsp/bsp.c  .generated_files/flags/default/b71676ac5be2664aa81d545c9b0940345f93fa1a .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1434821282" 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1434821282/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1434821282/bsp.o.d" -o ${OBJECTDIR}/_ext/1434821282/bsp.o ../src/config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/5c669bc9b083ecb53a34b769b57be689cbb558 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/11554a53ee6df8fff3f7bbb3fb75c53e0b7d88a4 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c  .generated_files/flags/default/2445da9ebc7af44fab8aa5cad83f8a63006aba79 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom3_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom3_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c  .generated_files/flags/default/e9932c9ec65965c6433e663d16cf64c0f696a3e6 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom2_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom2_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/768fbf81fa05a2e2540a428ddf9886ae420e8e0a .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/6d4ecd94b092749cd37da543e83290601a8d972d .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/a53fb121eb9aafef3d349dd66e5acae69707578c .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/dffb30d29ac85482db3f16b950e813343a26c875 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/d7a0905df3b56b0525661e3bc230e97c8a602f6b .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/171d65da0eac41d951de48c1e01173457298258c .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/3fb14b535ea02a865d8f85bc094992596f45453 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/5efd5076507f6890e373043ab6b898b95bbb931 .generated_files/flags/default/4931640289d249c8a001a35224768791fb483b17
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164LS60100_DFP" -I"../../../../../../externals/azure-sdk-for-c/sdk/inc" -I"../../../../../../externals/azure-sdk-for-c/sdk/src" -I"../../../../../../src" -I"../../../../../../src/examples" -I"../../../../../../src/test" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-LS60" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/ewf_telemetry_bm_bg96_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/default/PIC32CM5164LS60100.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/ewf_telemetry_bm_bg96_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=512,--gc-sections,-L"./",-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DAS_SIZE=0x40000,-DBOOTPROT_SIZE=0x0,-DNONSECURE,-DRS_SIZE=0x8000,--memorysummary,${DISTDIR}/memoryfile.xml,-l:ewf_telemetry_bm_bg96_Secure_sg_veneer.lib -mdfp="${DFP_DIR}/PIC32CM-LS60"
	
else
${DISTDIR}/ewf_telemetry_bm_bg96_NonSecure.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/default/PIC32CM5164LS60100.ld ../../../Secure/firmware/ewf_telemetry_bm_bg96_Secure.X/dist/default/production/ewf_telemetry_bm_bg96_Secure.X.production.hex
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/ewf_telemetry_bm_bg96_NonSecure.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,-L"./",-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DAS_SIZE=0x40000,-DBOOTPROT_SIZE=0x0,-DNONSECURE,-DRS_SIZE=0x8000,--memorysummary,${DISTDIR}/memoryfile.xml,-l:ewf_telemetry_bm_bg96_Secure_sg_veneer.lib -mdfp="${DFP_DIR}/PIC32CM-LS60"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/ewf_telemetry_bm_bg96_NonSecure.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
	@echo "Creating unified hex file"
	@"C:/Program Files/Microchip/MPLABX/v6.00/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v6.00/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" ${DISTDIR}/ewf_telemetry_bm_bg96_NonSecure.X.${IMAGE_TYPE}.hex ../../../Secure/firmware/ewf_telemetry_bm_bg96_Secure.X/dist/default/production/ewf_telemetry_bm_bg96_Secure.X.production.hex -odist/${CND_CONF}/production/ewf_telemetry_bm_bg96_NonSecure.X.production.unified.hex

endif


# Subprojects
.build-subprojects:
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
	cd ../../../Secure/firmware/ewf_telemetry_bm_bg96_Secure.X && ${MAKE}  -f Makefile CONF=default TYPE_IMAGE=DEBUG_RUN
else
	cd ../../../Secure/firmware/ewf_telemetry_bm_bg96_Secure.X && ${MAKE}  -f Makefile CONF=default
endif


# Subprojects
.clean-subprojects:
	cd ../../../Secure/firmware/ewf_telemetry_bm_bg96_Secure.X && rm -rf "build/default" "dist/default"

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
