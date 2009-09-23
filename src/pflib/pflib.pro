#-*- mode: makefile; tab-width: 4; -*-
#
include(../../qmake.inc)
#
TEMPLATE = lib
#
SOURCES	 =  TableFactory.cpp \
			Preprocessor_pf.cpp \
		    NATCompiler_ipf.cpp \
			NATCompiler_ipfw.cpp \
			NATCompiler_ipf_writers.cpp \
			NATCompiler_ipfw_writers.cpp \
			NATCompiler_pf.cpp \
			NATCompiler_pf_negation.cpp \
			NATCompiler_pf_writers.cpp \
			OSConfigurator_bsd.cpp \
			OSConfigurator_freebsd.cpp \
			OSConfigurator_macosx.cpp \
			OSConfigurator_openbsd.cpp \
			OSConfigurator_solaris.cpp \
			OSData.cpp \
			PolicyCompiler_ipf.cpp \
			PolicyCompiler_ipf_optimizer.cpp \
			PolicyCompiler_ipfw.cpp \
			PolicyCompiler_ipf_writers.cpp \
			PolicyCompiler_ipfw_writers.cpp \
			PolicyCompiler_pf.cpp \
			PolicyCompiler_pf_writers.cpp \
			CompilerDriver_pf.cpp \
			CompilerDriver_pf_cluster.cpp \
			CompilerDriver_pf_run.cpp \
			CompilerDriver_ipf.cpp \
			CompilerDriver_ipf_run.cpp \
			CompilerDriver_ipfw.cpp \
			CompilerDriver_ipfw_run.cpp \

HEADERS	 = ../../config.h \
			OSData.h \
		    TableFactory.h \
			Preprocessor_pf.h \
			NATCompiler_ipf.h \
			NATCompiler_ipfw.h \
			NATCompiler_pf.h \
			OSConfigurator_bsd.h \
			OSConfigurator_freebsd.h \
			OSConfigurator_macosx.h \
			OSConfigurator_openbsd.h \
			OSConfigurator_solaris.h \
			PolicyCompiler_ipf.h \
			PolicyCompiler_ipfw.h \
			PolicyCompiler_pf.h \
			CompilerDriver_pf.h \
			CompilerDriver_ipf.h \
			CompilerDriver_ipfw.h \

macx:LIBS  += $$LIBS_FWCOMPILER

INCLUDEPATH += ../compiler_lib

win32:LIBS  += ../compiler_lib/release/compilerdriver.lib
!win32:LIBS += ../compiler_lib/libcompilerdriver.a

win32:PRE_TARGETDEPS  = ../compiler_lib/release/compilerdriver.lib
!win32:PRE_TARGETDEPS = ../compiler_lib/libcompilerdriver.a

CONFIG += staticlib

TARGET      = fwbpf

INSTALLS -= target
