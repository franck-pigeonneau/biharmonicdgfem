include $(shell rheolef-config --libdir)/rheolef/rheolef.mk
LD = $(CXX)
CC = $(CXX)
CXXFLAGS  = $(INCLUDES_RHEOLEF)
LDLIBS    = $(LIBS_RHEOLEF)
default: biharmonic_dg
biharmonic_dg.o : biharmonic_dg.cc boundarycond.cc source.cc
