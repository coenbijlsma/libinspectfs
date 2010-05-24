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
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Scanner.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Property.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/main.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Device.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-ludev
CXXFLAGS=-ludev

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libinspectfs

dist/Debug/GNU-Linux-x86/libinspectfs: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinspectfs ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Scanner.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/Scanner.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Scanner.o /home/coen/workspace/netbeans/libinspectfs/Scanner.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Property.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/Property.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Property.o /home/coen/workspace/netbeans/libinspectfs/Property.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/main.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/main.o /home/coen/workspace/netbeans/libinspectfs/main.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Device.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/Device.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Device.o /home/coen/workspace/netbeans/libinspectfs/Device.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libinspectfs

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
