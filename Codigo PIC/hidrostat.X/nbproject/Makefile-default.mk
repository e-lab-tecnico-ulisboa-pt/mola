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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/hidrostat.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/hidrostat.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../Library/delays.c ../Library/step_motor2.c ../Library/rec_generic_driver.c ../Library/timer.c ../Library/uart.c ../Library/maq_de_estados.c ../Library/protocolos.c ../Library/tm1640.c ../Library/adc.c ../hidrostat.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/150355788/delays.o ${OBJECTDIR}/_ext/150355788/step_motor2.o ${OBJECTDIR}/_ext/150355788/rec_generic_driver.o ${OBJECTDIR}/_ext/150355788/timer.o ${OBJECTDIR}/_ext/150355788/uart.o ${OBJECTDIR}/_ext/150355788/maq_de_estados.o ${OBJECTDIR}/_ext/150355788/protocolos.o ${OBJECTDIR}/_ext/150355788/tm1640.o ${OBJECTDIR}/_ext/150355788/adc.o ${OBJECTDIR}/_ext/1472/hidrostat.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/150355788/delays.o.d ${OBJECTDIR}/_ext/150355788/step_motor2.o.d ${OBJECTDIR}/_ext/150355788/rec_generic_driver.o.d ${OBJECTDIR}/_ext/150355788/timer.o.d ${OBJECTDIR}/_ext/150355788/uart.o.d ${OBJECTDIR}/_ext/150355788/maq_de_estados.o.d ${OBJECTDIR}/_ext/150355788/protocolos.o.d ${OBJECTDIR}/_ext/150355788/tm1640.o.d ${OBJECTDIR}/_ext/150355788/adc.o.d ${OBJECTDIR}/_ext/1472/hidrostat.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/150355788/delays.o ${OBJECTDIR}/_ext/150355788/step_motor2.o ${OBJECTDIR}/_ext/150355788/rec_generic_driver.o ${OBJECTDIR}/_ext/150355788/timer.o ${OBJECTDIR}/_ext/150355788/uart.o ${OBJECTDIR}/_ext/150355788/maq_de_estados.o ${OBJECTDIR}/_ext/150355788/protocolos.o ${OBJECTDIR}/_ext/150355788/tm1640.o ${OBJECTDIR}/_ext/150355788/adc.o ${OBJECTDIR}/_ext/1472/hidrostat.o

# Source Files
SOURCEFILES=../Library/delays.c ../Library/step_motor2.c ../Library/rec_generic_driver.c ../Library/timer.c ../Library/uart.c ../Library/maq_de_estados.c ../Library/protocolos.c ../Library/tm1640.c ../Library/adc.c ../hidrostat.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/hidrostat.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F4011
MP_LINKER_FILE_OPTION=,--script=p30F4011.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/150355788/delays.o: ../Library/delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/delays.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/delays.c  -o ${OBJECTDIR}/_ext/150355788/delays.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/delays.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/delays.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/step_motor2.o: ../Library/step_motor2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/step_motor2.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/step_motor2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/step_motor2.c  -o ${OBJECTDIR}/_ext/150355788/step_motor2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/step_motor2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/step_motor2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/rec_generic_driver.o: ../Library/rec_generic_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/rec_generic_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/rec_generic_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/rec_generic_driver.c  -o ${OBJECTDIR}/_ext/150355788/rec_generic_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/rec_generic_driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/rec_generic_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/timer.o: ../Library/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/timer.c  -o ${OBJECTDIR}/_ext/150355788/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/uart.o: ../Library/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/uart.c  -o ${OBJECTDIR}/_ext/150355788/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/maq_de_estados.o: ../Library/maq_de_estados.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/maq_de_estados.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/maq_de_estados.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/maq_de_estados.c  -o ${OBJECTDIR}/_ext/150355788/maq_de_estados.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/maq_de_estados.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/maq_de_estados.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/protocolos.o: ../Library/protocolos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/protocolos.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/protocolos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/protocolos.c  -o ${OBJECTDIR}/_ext/150355788/protocolos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/protocolos.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/protocolos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/tm1640.o: ../Library/tm1640.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/tm1640.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/tm1640.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/tm1640.c  -o ${OBJECTDIR}/_ext/150355788/tm1640.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/tm1640.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/tm1640.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/adc.o: ../Library/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/adc.c  -o ${OBJECTDIR}/_ext/150355788/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/hidrostat.o: ../hidrostat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/hidrostat.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/hidrostat.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../hidrostat.c  -o ${OBJECTDIR}/_ext/1472/hidrostat.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/hidrostat.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/hidrostat.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/150355788/delays.o: ../Library/delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/delays.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/delays.c  -o ${OBJECTDIR}/_ext/150355788/delays.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/delays.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/delays.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/step_motor2.o: ../Library/step_motor2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/step_motor2.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/step_motor2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/step_motor2.c  -o ${OBJECTDIR}/_ext/150355788/step_motor2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/step_motor2.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/step_motor2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/rec_generic_driver.o: ../Library/rec_generic_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/rec_generic_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/rec_generic_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/rec_generic_driver.c  -o ${OBJECTDIR}/_ext/150355788/rec_generic_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/rec_generic_driver.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/rec_generic_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/timer.o: ../Library/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/timer.c  -o ${OBJECTDIR}/_ext/150355788/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/timer.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/uart.o: ../Library/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/uart.c  -o ${OBJECTDIR}/_ext/150355788/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/uart.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/maq_de_estados.o: ../Library/maq_de_estados.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/maq_de_estados.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/maq_de_estados.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/maq_de_estados.c  -o ${OBJECTDIR}/_ext/150355788/maq_de_estados.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/maq_de_estados.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/maq_de_estados.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/protocolos.o: ../Library/protocolos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/protocolos.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/protocolos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/protocolos.c  -o ${OBJECTDIR}/_ext/150355788/protocolos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/protocolos.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/protocolos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/tm1640.o: ../Library/tm1640.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/tm1640.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/tm1640.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/tm1640.c  -o ${OBJECTDIR}/_ext/150355788/tm1640.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/tm1640.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/tm1640.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/150355788/adc.o: ../Library/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/150355788 
	@${RM} ${OBJECTDIR}/_ext/150355788/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Library/adc.c  -o ${OBJECTDIR}/_ext/150355788/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/150355788/adc.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/150355788/adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/hidrostat.o: ../hidrostat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/hidrostat.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/hidrostat.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../hidrostat.c  -o ${OBJECTDIR}/_ext/1472/hidrostat.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/hidrostat.o.d"        -g -omf=elf -O0 -I"../Library" -I"." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/hidrostat.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/hidrostat.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/hidrostat.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="../C:/Program Files/Microchip/MPLAB C30/lib",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/hidrostat.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/hidrostat.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/hidrostat.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="../C:/Program Files/Microchip/MPLAB C30/lib",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/hidrostat.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/hidrostat.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
