###############################################
# Makefile for detector geometry construction #                
#					      #
#                                             #
# 		Author: Tom Stainer           #
###############################################

SHELL = /bin/sh
NAME = all
MAKEFILE = Makefile

EXTENSION = cxx
H_EXTENSION = hh

# ROOT headers and libraries
ROOT_INCLUDES  = -I$(shell root-config --incdir)
ROOT_LIBRARIES = $(shell root-config --glibs) \
                       -lMinuit -lGeom -lEG -lEGPythia6

INCLUDES := $(ROOT_INCLUDES) $(LINUX_SYS_INCLUDES)

LIBS := $(SYSLIBS) $(ROOT_LIBRARIES)

#local src and include directories for my own created cxx and header files
IDIR    = include
SDIR	= src
ODIR	= obj

VPATH	= $(SDIR) $(IDIR) 

#compiler
CC      = g++
DEBUG   = -g

#compile flags
CFLAGS  = -Wall -c $(DEBUG) -I$(IDIR) -I$(IDIR)/TPC -I$(IDIR)/TAS -I$(IDIR)/ECAL -I$(IDIR)/HCAL \
	 -I$(IDIR)/Magnet -I$(IDIR)/MIND -I$(IDIR)/Cavity/ -I$(ROOTSYS)/include

#linking flags
LFLAGS	= -Wall $(DEBUG)

#define root system location
ROOTSYS = /hepstore/store6/stainer/root

#name of the executable
TARGET  = Geometry

all: $(ODIR) $(TARGET)

#objects needed for linking together for the target exe
OBJ    = NearDetector.o RockConstruction.o TPCFiducialConstruction.o \
	TPCEnclosureConstruction.o TPCEnclosureConstructionX.o TPCEnclosureConstructionY.o TPCEnclosureConstructionZ.o \
	TASFiducialConstruction.o TASFiducialConstructionX.o TASFiducialConstructionY.o TASFiducialConstructionZ.o \
	TASEnclosureConstruction.o TASEnclosureConstructionX.o TASEnclosureConstructionY.o TASEnclosureConstructionZ.o \
	ECALScintillatorConstruction.o ECALScintillatorConstructionZ.o ECALScintillatorConstructionY.o ECALScintillatorConstructionX.o \
	ECALSeparatorConstruction.o ECALSeparatorConstructionZ.o ECALSeparatorConstructionY.o ECALSeparatorConstructionX.o \
	ECALConstruction.o \
	HCALScintillatorConstruction.o HCALScintillatorConstructionZ.o HCALScintillatorConstructionY.o HCALScintillatorConstructionX.o \
	HCALSeparatorConstruction.o HCALSeparatorConstructionZ.o HCALSeparatorConstructionY.o HCALSeparatorConstructionX.o \
	HCALConstruction.o \
	MagnetConstruction.o \
	MINDConstruction.o \
	CavityConstruction.o

OBJS = $(addprefix $(ODIR)/,$(OBJ))

#includes
INC = $(IDIR)/*.hh $(IDIR)/TPC/*.hh $(IDIR)/TAS/*.hh $(IDIR)/ECAL/*.hh $(IDIR)/HCAL/*.hh \
	$(IDIR)/Magnet/*.hh $(IDIR)/MIND/*.hh $(IDIR)/Cavity/*.hh $(ROOTSYS)/include/*.h

$(ODIR):
	mkdir $(ODIR)

#executable file linking always comes first!
$(TARGET): $(OBJS)
	@echo ........Compiling 
	$(CC) $(LFLAGS) $(OBJS) $(LIBS) -o app/$(TARGET).exe
	@echo Done!

#compile the libraries
$(ODIR)/NearDetector.o: $(SDIR)/NearDetector.cxx $(INC)
	@echo ........Building Objects
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/NearDetector.cxx -o $@

$(ODIR)/RockConstruction.o: $(SDIR)/RockConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/RockConstruction.cxx -o $@

$(ODIR)/TPCFiducialConstruction.o: $(SDIR)/TPC/TPCFiducialConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCFiducialConstruction.cxx -o $@

#1 base class and 3 derived classes for TPCEnclosure
$(ODIR)/TPCEnclosureConstruction.o: $(SDIR)/TPC/TPCEnclosureConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCEnclosureConstruction.cxx -o $@

$(ODIR)/TPCEnclosureConstructionX.o: $(SDIR)/TPC/TPCEnclosureConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCEnclosureConstructionX.cxx -o $@

$(ODIR)/TPCEnclosureConstructionY.o: $(SDIR)/TPC/TPCEnclosureConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCEnclosureConstructionY.cxx -o $@

$(ODIR)/TPCEnclosureConstructionZ.o: $(SDIR)/TPC/TPCEnclosureConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCEnclosureConstructionZ.cxx -o $@
#1 base class and 3 derived classes for TASFiducial
$(ODIR)/TASFiducialConstruction.o: $(SDIR)/TAS/TASFiducialConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASFiducialConstruction.cxx -o $@

$(ODIR)/TASFiducialConstructionX.o: $(SDIR)/TAS/TASFiducialConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASFiducialConstructionX.cxx -o $@

$(ODIR)/TASFiducialConstructionY.o: $(SDIR)/TAS/TASFiducialConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASFiducialConstructionY.cxx -o $@

$(ODIR)/TASFiducialConstructionZ.o: $(SDIR)/TAS/TASFiducialConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASFiducialConstructionZ.cxx -o $@

#1 base class and 3 derived classes for TASEnclosure
$(ODIR)/TASEnclosureConstruction.o: $(SDIR)/TAS/TASEnclosureConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASEnclosureConstruction.cxx -o $@

$(ODIR)/TASEnclosureConstructionX.o: $(SDIR)/TAS/TASEnclosureConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASEnclosureConstructionX.cxx -o $@

$(ODIR)/TASEnclosureConstructionY.o: $(SDIR)/TAS/TASEnclosureConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASEnclosureConstructionY.cxx -o $@

$(ODIR)/TASEnclosureConstructionZ.o: $(SDIR)/TAS/TASEnclosureConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASEnclosureConstructionZ.cxx -o $@

#1 base class and 3 derived classes for ECALScintillatorConstruction
$(ODIR)/ECALScintillatorConstruction.o: $(SDIR)/ECAL/ECALScintillatorConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALScintillatorConstruction.cxx -o $@

$(ODIR)/ECALScintillatorConstructionZ.o: $(SDIR)/ECAL/ECALScintillatorConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALScintillatorConstructionZ.cxx -o $@

$(ODIR)/ECALScintillatorConstructionY.o: $(SDIR)/ECAL/ECALScintillatorConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALScintillatorConstructionY.cxx -o $@

$(ODIR)/ECALScintillatorConstructionX.o: $(SDIR)/ECAL/ECALScintillatorConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALScintillatorConstructionX.cxx -o $@

#1 base class and 3 derived classes for ECALSeparatorConstruction
$(ODIR)/ECALSeparatorConstruction.o: $(SDIR)/ECAL/ECALSeparatorConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALSeparatorConstruction.cxx -o $@

$(ODIR)/ECALSeparatorConstructionZ.o: $(SDIR)/ECAL/ECALSeparatorConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALSeparatorConstructionZ.cxx -o $@

$(ODIR)/ECALSeparatorConstructionY.o: $(SDIR)/ECAL/ECALSeparatorConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALSeparatorConstructionY.cxx -o $@

$(ODIR)/ECALSeparatorConstructionX.o: $(SDIR)/ECAL/ECALSeparatorConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALSeparatorConstructionX.cxx -o $@
#ECAL
$(ODIR)/ECALConstruction.o: $(SDIR)/ECAL/ECALConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALConstruction.cxx -o $@

#1 base class and 3 derived classes for ECALScintillatorConstruction
$(ODIR)/HCALScintillatorConstruction.o: $(SDIR)/HCAL/HCALScintillatorConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALScintillatorConstruction.cxx -o $@

$(ODIR)/HCALScintillatorConstructionZ.o: $(SDIR)/HCAL/HCALScintillatorConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALScintillatorConstructionZ.cxx -o $@

$(ODIR)/HCALScintillatorConstructionY.o: $(SDIR)/HCAL/HCALScintillatorConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALScintillatorConstructionY.cxx -o $@

$(ODIR)/HCALScintillatorConstructionX.o: $(SDIR)/HCAL/HCALScintillatorConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALScintillatorConstructionX.cxx -o $@

#1 base class and 3 derived classes for HCALSeparatorConstruction
$(ODIR)/HCALSeparatorConstruction.o: $(SDIR)/HCAL/HCALSeparatorConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALSeparatorConstruction.cxx -o $@

$(ODIR)/HCALSeparatorConstructionZ.o: $(SDIR)/HCAL/HCALSeparatorConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALSeparatorConstructionZ.cxx -o $@

$(ODIR)/HCALSeparatorConstructionY.o: $(SDIR)/HCAL/HCALSeparatorConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALSeparatorConstructionY.cxx -o $@

$(ODIR)/HCALSeparatorConstructionX.o: $(SDIR)/HCAL/HCALSeparatorConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALSeparatorConstructionX.cxx -o $@

#HCAL
$(ODIR)/HCALConstruction.o: $(SDIR)/HCAL/HCALConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALConstruction.cxx -o $@

#Magnet
$(ODIR)/MagnetConstruction.o: $(SDIR)/Magnet/MagnetConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/Magnet/MagnetConstruction.cxx -o $@

#MIND
$(ODIR)/MINDConstruction.o: $(SDIR)/MIND/MINDConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/MIND/MINDConstruction.cxx -o $@

#Cavity	
$(ODIR)/CavityConstruction.o: $(SDIR)/Cavity/CavityConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/Cavity/CavityConstruction.cxx -o $@


.PHONY : clean

#clean up
clean:
	@rm -f app/$(TARGET).exe
	@rm -rf $(ODIR) 
