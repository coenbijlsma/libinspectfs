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
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/595930898/Partition.o \
	${OBJECTDIR}/_ext/595930898/PartitionRecord.o \
	${OBJECTDIR}/_ext/595930898/User.o \
	${OBJECTDIR}/_ext/595930898/IOException.o \
	${OBJECTDIR}/_ext/595930898/MBR.o \
	${OBJECTDIR}/_ext/595930898/Device.o \
	${OBJECTDIR}/_ext/595930898/Exception.o \
	${OBJECTDIR}/_ext/595930898/Property.o \
	${OBJECTDIR}/_ext/595930898/main.o \
	${OBJECTDIR}/_ext/595930898/Scanner.o \
	${OBJECTDIR}/_ext/595930898/BlockDevice.o


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
LDLIBSOPTIONS=`pkg-config --libs libudev`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinspectfs.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinspectfs.so: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinspectfs.so ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/595930898/Partition.o: /home/coen/git/libinspectfs/Partition.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/Partition.o /home/coen/git/libinspectfs/Partition.cpp

${OBJECTDIR}/_ext/595930898/PartitionRecord.o: /home/coen/git/libinspectfs/PartitionRecord.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/PartitionRecord.o /home/coen/git/libinspectfs/PartitionRecord.cpp

${OBJECTDIR}/_ext/595930898/User.o: /home/coen/git/libinspectfs/User.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/User.o /home/coen/git/libinspectfs/User.cpp

${OBJECTDIR}/_ext/595930898/IOException.o: /home/coen/git/libinspectfs/IOException.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/IOException.o /home/coen/git/libinspectfs/IOException.cpp

${OBJECTDIR}/_ext/595930898/MBR.o: /home/coen/git/libinspectfs/MBR.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/MBR.o /home/coen/git/libinspectfs/MBR.cpp

${OBJECTDIR}/_ext/595930898/Device.o: /home/coen/git/libinspectfs/Device.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/Device.o /home/coen/git/libinspectfs/Device.cpp

${OBJECTDIR}/_ext/595930898/Exception.o: /home/coen/git/libinspectfs/Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/Exception.o /home/coen/git/libinspectfs/Exception.cpp

${OBJECTDIR}/_ext/595930898/Property.o: /home/coen/git/libinspectfs/Property.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/Property.o /home/coen/git/libinspectfs/Property.cpp

${OBJECTDIR}/_ext/595930898/main.o: /home/coen/git/libinspectfs/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/main.o /home/coen/git/libinspectfs/main.cpp

${OBJECTDIR}/_ext/595930898/Scanner.o: /home/coen/git/libinspectfs/Scanner.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/Scanner.o /home/coen/git/libinspectfs/Scanner.cpp

${OBJECTDIR}/_ext/595930898/BlockDevice.o: /home/coen/git/libinspectfs/BlockDevice.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/595930898
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/include `pkg-config --cflags libudev`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/595930898/BlockDevice.o /home/coen/git/libinspectfs/BlockDevice.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libinspectfs.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
