#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/C_Files/Archivos.o \
	${OBJECTDIR}/C_Files/DateGenerator.o \
	${OBJECTDIR}/C_Files/Interfaz.o \
	${OBJECTDIR}/C_Files/Jugador.o \
	${OBJECTDIR}/C_Files/Lista_Registros.o \
	${OBJECTDIR}/C_Files/Nodo.o \
	${OBJECTDIR}/C_Files/Registro.o \
	${OBJECTDIR}/C_Files/Table.o \
	${OBJECTDIR}/C_Files/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quiz_1.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quiz_1.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quiz_1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/C_Files/Archivos.o: C_Files/Archivos.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Archivos.o C_Files/Archivos.c

${OBJECTDIR}/C_Files/DateGenerator.o: C_Files/DateGenerator.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/DateGenerator.o C_Files/DateGenerator.c

${OBJECTDIR}/C_Files/Interfaz.o: C_Files/Interfaz.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Interfaz.o C_Files/Interfaz.c

${OBJECTDIR}/C_Files/Jugador.o: C_Files/Jugador.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Jugador.o C_Files/Jugador.c

${OBJECTDIR}/C_Files/Lista_Registros.o: C_Files/Lista_Registros.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Lista_Registros.o C_Files/Lista_Registros.c

${OBJECTDIR}/C_Files/Nodo.o: C_Files/Nodo.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Nodo.o C_Files/Nodo.c

${OBJECTDIR}/C_Files/Registro.o: C_Files/Registro.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Registro.o C_Files/Registro.c

${OBJECTDIR}/C_Files/Table.o: C_Files/Table.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Table.o C_Files/Table.c

${OBJECTDIR}/C_Files/main.o: C_Files/main.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/main.o C_Files/main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
