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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RF315Coordinator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RF315Coordinator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=TIMER/TIMER.c SPI/SPI.c LCD/LCD.c CC1101/CC1101.c RFCoordinator.c UART/UART.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/TIMER/TIMER.o ${OBJECTDIR}/SPI/SPI.o ${OBJECTDIR}/LCD/LCD.o ${OBJECTDIR}/CC1101/CC1101.o ${OBJECTDIR}/RFCoordinator.o ${OBJECTDIR}/UART/UART.o
POSSIBLE_DEPFILES=${OBJECTDIR}/TIMER/TIMER.o.d ${OBJECTDIR}/SPI/SPI.o.d ${OBJECTDIR}/LCD/LCD.o.d ${OBJECTDIR}/CC1101/CC1101.o.d ${OBJECTDIR}/RFCoordinator.o.d ${OBJECTDIR}/UART/UART.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/TIMER/TIMER.o ${OBJECTDIR}/SPI/SPI.o ${OBJECTDIR}/LCD/LCD.o ${OBJECTDIR}/CC1101/CC1101.o ${OBJECTDIR}/RFCoordinator.o ${OBJECTDIR}/UART/UART.o

# Source Files
SOURCEFILES=TIMER/TIMER.c SPI/SPI.c LCD/LCD.c CC1101/CC1101.c RFCoordinator.c UART/UART.c


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/RF315Coordinator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
MP_PROCESSOR_OPTION_LD=18f46k20
MP_LINKER_DEBUG_OPTION= -u_DEBUGCODESTART=0xfd30 -u_DEBUGCODELEN=0x2d0 -u_DEBUGDATASTART=0xef4 -u_DEBUGDATALEN=0xb
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/TIMER/TIMER.o: TIMER/TIMER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TIMER 
	@${RM} ${OBJECTDIR}/TIMER/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/TIMER/TIMER.o   TIMER/TIMER.c 
	@${DEP_GEN} -d ${OBJECTDIR}/TIMER/TIMER.o 
	@${FIXDEPS} "${OBJECTDIR}/TIMER/TIMER.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/SPI/SPI.o: SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SPI 
	@${RM} ${OBJECTDIR}/SPI/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/SPI/SPI.o   SPI/SPI.c 
	@${DEP_GEN} -d ${OBJECTDIR}/SPI/SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI/SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD/LCD.o: LCD/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/LCD 
	@${RM} ${OBJECTDIR}/LCD/LCD.o.d 
	@${RM} ${OBJECTDIR}/LCD/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD/LCD.o   LCD/LCD.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD/LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD/LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/CC1101/CC1101.o: CC1101/CC1101.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/CC1101 
	@${RM} ${OBJECTDIR}/CC1101/CC1101.o.d 
	@${RM} ${OBJECTDIR}/CC1101/CC1101.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/CC1101/CC1101.o   CC1101/CC1101.c 
	@${DEP_GEN} -d ${OBJECTDIR}/CC1101/CC1101.o 
	@${FIXDEPS} "${OBJECTDIR}/CC1101/CC1101.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/RFCoordinator.o: RFCoordinator.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/RFCoordinator.o.d 
	@${RM} ${OBJECTDIR}/RFCoordinator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/RFCoordinator.o   RFCoordinator.c 
	@${DEP_GEN} -d ${OBJECTDIR}/RFCoordinator.o 
	@${FIXDEPS} "${OBJECTDIR}/RFCoordinator.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/UART/UART.o: UART/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/UART 
	@${RM} ${OBJECTDIR}/UART/UART.o.d 
	@${RM} ${OBJECTDIR}/UART/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/UART/UART.o   UART/UART.c 
	@${DEP_GEN} -d ${OBJECTDIR}/UART/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/UART/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/TIMER/TIMER.o: TIMER/TIMER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TIMER 
	@${RM} ${OBJECTDIR}/TIMER/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/TIMER/TIMER.o   TIMER/TIMER.c 
	@${DEP_GEN} -d ${OBJECTDIR}/TIMER/TIMER.o 
	@${FIXDEPS} "${OBJECTDIR}/TIMER/TIMER.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/SPI/SPI.o: SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SPI 
	@${RM} ${OBJECTDIR}/SPI/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/SPI/SPI.o   SPI/SPI.c 
	@${DEP_GEN} -d ${OBJECTDIR}/SPI/SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI/SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/LCD/LCD.o: LCD/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/LCD 
	@${RM} ${OBJECTDIR}/LCD/LCD.o.d 
	@${RM} ${OBJECTDIR}/LCD/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD/LCD.o   LCD/LCD.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD/LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/LCD/LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/CC1101/CC1101.o: CC1101/CC1101.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/CC1101 
	@${RM} ${OBJECTDIR}/CC1101/CC1101.o.d 
	@${RM} ${OBJECTDIR}/CC1101/CC1101.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/CC1101/CC1101.o   CC1101/CC1101.c 
	@${DEP_GEN} -d ${OBJECTDIR}/CC1101/CC1101.o 
	@${FIXDEPS} "${OBJECTDIR}/CC1101/CC1101.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/RFCoordinator.o: RFCoordinator.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/RFCoordinator.o.d 
	@${RM} ${OBJECTDIR}/RFCoordinator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/RFCoordinator.o   RFCoordinator.c 
	@${DEP_GEN} -d ${OBJECTDIR}/RFCoordinator.o 
	@${FIXDEPS} "${OBJECTDIR}/RFCoordinator.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/UART/UART.o: UART/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/UART 
	@${RM} ${OBJECTDIR}/UART/UART.o.d 
	@${RM} ${OBJECTDIR}/UART/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/UART/UART.o   UART/UART.c 
	@${DEP_GEN} -d ${OBJECTDIR}/UART/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/UART/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/RF315Coordinator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/RF315Coordinator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/RF315Coordinator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/RF315Coordinator.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
