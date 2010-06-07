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
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/MBR.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Property.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/BlockDevice.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/IOException.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Device.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Exception.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Partition.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Scanner.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/main.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/User.o \
	${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/PartitionRecord.o

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
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libinspectfs.so

dist/Debug/GNU-Linux-x86/libinspectfs.so: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -ludev -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinspectfs.so ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/MBR.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/MBR.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/MBR.o /home/coen/workspace/netbeans/libinspectfs/MBR.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Property.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/Property.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Property.o /home/coen/workspace/netbeans/libinspectfs/Property.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/BlockDevice.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/BlockDevice.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/BlockDevice.o /home/coen/workspace/netbeans/libinspectfs/BlockDevice.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/IOException.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/IOException.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/IOException.o /home/coen/workspace/netbeans/libinspectfs/IOException.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Device.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/Device.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Device.o /home/coen/workspace/netbeans/libinspectfs/Device.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Exception.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Exception.o /home/coen/workspace/netbeans/libinspectfs/Exception.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Partition.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/Partition.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Partition.o /home/coen/workspace/netbeans/libinspectfs/Partition.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Scanner.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/Scanner.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/Scanner.o /home/coen/workspace/netbeans/libinspectfs/Scanner.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/main.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/main.o /home/coen/workspace/netbeans/libinspectfs/main.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/User.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/User.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/User.o /home/coen/workspace/netbeans/libinspectfs/User.cpp

${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/PartitionRecord.o: nbproject/Makefile-${CND_CONF}.mk /home/coen/workspace/netbeans/libinspectfs/PartitionRecord.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/coen/workspace/netbeans/libinspectfs/PartitionRecord.o /home/coen/workspace/netbeans/libinspectfs/PartitionRecord.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libinspectfs.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
