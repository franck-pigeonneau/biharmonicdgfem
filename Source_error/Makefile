include $(shell rheolef-config --libdir)/rheolef/rheolef.mk
LD = $(CXX)
CC = $(CXX)
CXXFLAGS  = $(INCLUDES_RHEOLEF)
LDLIBS    = $(LIBS_RHEOLEF)
default: biharmonic_error
biharmonic_error.o : biharmonic_error.cc exactsolution.cc
