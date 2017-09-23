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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/HDI3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/HDI3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=UART/UART.c SPI/SPI.c CC1101/CC1101.c TIMER/TIMER.c Firmware/lcd.c Firmware/usb_descriptors.c Firmware/USBRFCoordinator.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/UART/UART.o ${OBJECTDIR}/SPI/SPI.o ${OBJECTDIR}/CC1101/CC1101.o ${OBJECTDIR}/TIMER/TIMER.o ${OBJECTDIR}/Firmware/lcd.o ${OBJECTDIR}/Firmware/usb_descriptors.o ${OBJECTDIR}/Firmware/USBRFCoordinator.o
POSSIBLE_DEPFILES=${OBJECTDIR}/UART/UART.o.d ${OBJECTDIR}/SPI/SPI.o.d ${OBJECTDIR}/CC1101/CC1101.o.d ${OBJECTDIR}/TIMER/TIMER.o.d ${OBJECTDIR}/Firmware/lcd.o.d ${OBJECTDIR}/Firmware/usb_descriptors.o.d ${OBJECTDIR}/Firmware/USBRFCoordinator.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/UART/UART.o ${OBJECTDIR}/SPI/SPI.o ${OBJECTDIR}/CC1101/CC1101.o ${OBJECTDIR}/TIMER/TIMER.o ${OBJECTDIR}/Firmware/lcd.o ${OBJECTDIR}/Firmware/usb_descriptors.o ${OBJECTDIR}/Firmware/USBRFCoordinator.o

# Source Files
SOURCEFILES=UART/UART.c SPI/SPI.c CC1101/CC1101.c TIMER/TIMER.c Firmware/lcd.c Firmware/usb_descriptors.c Firmware/USBRFCoordinator.c


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/HDI3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F14K50
MP_PROCESSOR_OPTION_LD=18f14k50
MP_LINKER_DEBUG_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/UART/UART.o: UART/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/UART 
	@${RM} ${OBJECTDIR}/UART/UART.o.d 
	@${RM} ${OBJECTDIR}/UART/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/UART/UART.o   UART/UART.c 
	@${DEP_GEN} -d ${OBJECTDIR}/UART/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/UART/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/SPI/SPI.o: SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SPI 
	@${RM} ${OBJECTDIR}/SPI/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/SPI/SPI.o   SPI/SPI.c 
	@${DEP_GEN} -d ${OBJECTDIR}/SPI/SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI/SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/CC1101/CC1101.o: CC1101/CC1101.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/CC1101 
	@${RM} ${OBJECTDIR}/CC1101/CC1101.o.d 
	@${RM} ${OBJECTDIR}/CC1101/CC1101.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/CC1101/CC1101.o   CC1101/CC1101.c 
	@${DEP_GEN} -d ${OBJECTDIR}/CC1101/CC1101.o 
	@${FIXDEPS} "${OBJECTDIR}/CC1101/CC1101.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/TIMER/TIMER.o: TIMER/TIMER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TIMER 
	@${RM} ${OBJECTDIR}/TIMER/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/TIMER/TIMER.o   TIMER/TIMER.c 
	@${DEP_GEN} -d ${OBJECTDIR}/TIMER/TIMER.o 
	@${FIXDEPS} "${OBJECTDIR}/TIMER/TIMER.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Firmware/lcd.o: Firmware/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/lcd.o.d 
	@${RM} ${OBJECTDIR}/Firmware/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Firmware/lcd.o   Firmware/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Firmware/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Firmware/usb_descriptors.o: Firmware/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/Firmware/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Firmware/usb_descriptors.o   Firmware/usb_descriptors.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Firmware/usb_descriptors.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/usb_descriptors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Firmware/USBRFCoordinator.o: Firmware/USBRFCoordinator.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/USBRFCoordinator.o.d 
	@${RM} ${OBJECTDIR}/Firmware/USBRFCoordinator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Firmware/USBRFCoordinator.o   Firmware/USBRFCoordinator.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Firmware/USBRFCoordinator.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/USBRFCoordinator.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/UART/UART.o: UART/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/UART 
	@${RM} ${OBJECTDIR}/UART/UART.o.d 
	@${RM} ${OBJECTDIR}/UART/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/UART/UART.o   UART/UART.c 
	@${DEP_GEN} -d ${OBJECTDIR}/UART/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/UART/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/SPI/SPI.o: SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SPI 
	@${RM} ${OBJECTDIR}/SPI/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/SPI/SPI.o   SPI/SPI.c 
	@${DEP_GEN} -d ${OBJECTDIR}/SPI/SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI/SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/CC1101/CC1101.o: CC1101/CC1101.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/CC1101 
	@${RM} ${OBJECTDIR}/CC1101/CC1101.o.d 
	@${RM} ${OBJECTDIR}/CC1101/CC1101.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/CC1101/CC1101.o   CC1101/CC1101.c 
	@${DEP_GEN} -d ${OBJECTDIR}/CC1101/CC1101.o 
	@${FIXDEPS} "${OBJECTDIR}/CC1101/CC1101.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/TIMER/TIMER.o: TIMER/TIMER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TIMER 
	@${RM} ${OBJECTDIR}/TIMER/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/TIMER/TIMER.o   TIMER/TIMER.c 
	@${DEP_GEN} -d ${OBJECTDIR}/TIMER/TIMER.o 
	@${FIXDEPS} "${OBJECTDIR}/TIMER/TIMER.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Firmware/lcd.o: Firmware/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/lcd.o.d 
	@${RM} ${OBJECTDIR}/Firmware/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Firmware/lcd.o   Firmware/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Firmware/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Firmware/usb_descriptors.o: Firmware/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/Firmware/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Firmware/usb_descriptors.o   Firmware/usb_descriptors.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Firmware/usb_descriptors.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/usb_descriptors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Firmware/USBRFCoordinator.o: Firmware/USBRFCoordinator.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/USBRFCoordinator.o.d 
	@${RM} ${OBJECTDIR}/Firmware/USBRFCoordinator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/microchip_solutions_v2013-06-15/Microchip/Include" -I"C:/microchip_solutions_v2013-06-15/Microchip/USB" -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Firmware/USBRFCoordinator.o   Firmware/USBRFCoordinator.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Firmware/USBRFCoordinator.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/USBRFCoordinator.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/HDI3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)     -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"     $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/HDI3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/HDI3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)      -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"    -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/HDI3.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
