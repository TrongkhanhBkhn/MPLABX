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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FindPositon.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FindPositon.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Firmware/Console.c Firmware/Lcd.c Firmware/FindPosition.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Firmware/Console.o ${OBJECTDIR}/Firmware/Lcd.o ${OBJECTDIR}/Firmware/FindPosition.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Firmware/Console.o.d ${OBJECTDIR}/Firmware/Lcd.o.d ${OBJECTDIR}/Firmware/FindPosition.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Firmware/Console.o ${OBJECTDIR}/Firmware/Lcd.o ${OBJECTDIR}/Firmware/FindPosition.o

# Source Files
SOURCEFILES=Firmware/Console.c Firmware/Lcd.c Firmware/FindPosition.c


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/FindPositon.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA306
MP_LINKER_FILE_OPTION=,-Tp24FJ128GA306.gld
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
${OBJECTDIR}/Firmware/Console.o: Firmware/Console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/Console.o.d 
	@${RM} ${OBJECTDIR}/Firmware/Console.o.ok ${OBJECTDIR}/Firmware/Console.o.err 
	@${RM} ${OBJECTDIR}/Firmware/Console.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/Console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Firmware/Console.o.d" -o ${OBJECTDIR}/Firmware/Console.o Firmware/Console.c    
	
${OBJECTDIR}/Firmware/Lcd.o: Firmware/Lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/Lcd.o.d 
	@${RM} ${OBJECTDIR}/Firmware/Lcd.o.ok ${OBJECTDIR}/Firmware/Lcd.o.err 
	@${RM} ${OBJECTDIR}/Firmware/Lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/Lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Firmware/Lcd.o.d" -o ${OBJECTDIR}/Firmware/Lcd.o Firmware/Lcd.c    
	
${OBJECTDIR}/Firmware/FindPosition.o: Firmware/FindPosition.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/FindPosition.o.d 
	@${RM} ${OBJECTDIR}/Firmware/FindPosition.o.ok ${OBJECTDIR}/Firmware/FindPosition.o.err 
	@${RM} ${OBJECTDIR}/Firmware/FindPosition.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/FindPosition.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Firmware/FindPosition.o.d" -o ${OBJECTDIR}/Firmware/FindPosition.o Firmware/FindPosition.c    
	
else
${OBJECTDIR}/Firmware/Console.o: Firmware/Console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/Console.o.d 
	@${RM} ${OBJECTDIR}/Firmware/Console.o.ok ${OBJECTDIR}/Firmware/Console.o.err 
	@${RM} ${OBJECTDIR}/Firmware/Console.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/Console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Firmware/Console.o.d" -o ${OBJECTDIR}/Firmware/Console.o Firmware/Console.c    
	
${OBJECTDIR}/Firmware/Lcd.o: Firmware/Lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/Lcd.o.d 
	@${RM} ${OBJECTDIR}/Firmware/Lcd.o.ok ${OBJECTDIR}/Firmware/Lcd.o.err 
	@${RM} ${OBJECTDIR}/Firmware/Lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/Lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Firmware/Lcd.o.d" -o ${OBJECTDIR}/Firmware/Lcd.o Firmware/Lcd.c    
	
${OBJECTDIR}/Firmware/FindPosition.o: Firmware/FindPosition.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/Firmware 
	@${RM} ${OBJECTDIR}/Firmware/FindPosition.o.d 
	@${RM} ${OBJECTDIR}/Firmware/FindPosition.o.ok ${OBJECTDIR}/Firmware/FindPosition.o.err 
	@${RM} ${OBJECTDIR}/Firmware/FindPosition.o 
	@${FIXDEPS} "${OBJECTDIR}/Firmware/FindPosition.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Firmware/FindPosition.o.d" -o ${OBJECTDIR}/Firmware/FindPosition.o Firmware/FindPosition.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/FindPositon.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/FindPositon.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/FindPositon.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/FindPositon.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/FindPositon.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
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
