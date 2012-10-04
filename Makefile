##############################################
# Makefile for detector geometry construction#                
##############################################
#
# Author: Tom Stainer
#
#A Makefile is essentially made of:
# The Target is the name of the file
# The Dependancies are the files that the target depends on
# THe commands to run based on the target and the dependancies

#----------REMEMBER TO USE A TAB FOR COMMANDS!!-----------------------
#---------------------------------------------------------------------

SHELL = /bin/sh
NAME = all
MAKEFILE = Makefile

# ROOT headers and libraries
ROOT_INCLUDES  = -I$(shell root-config --incdir)
ROOT_LIBRARIES = $(shell root-config --glibs) \
                       -lMinuit -lGeom -lEG -lEGPythia6

INCLUDES := $(ROOT_INCLUDES) $(LINUX_SYS_INCLUDES)

LIBRARIES := $(SYSLIBS) $(ROOT_LIBRARIES)

LIBS  :=  $(LIBRARIES) 

#local src and include directories for my own created cxx and header files
IDIR    = include
SDIR	= src

#object directory
ODIR	= $(SDIR)/obj

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

all: $(TARGET)

#objects needed for linking together for the target exe
OBJS    = NearDetector.o RockConstruction.o TPCFiducialConstruction.o \
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

#includes
INC = $(IDIR)/*.hh $(IDIR)/TPC/*.hh $(IDIR)/TAS/*.hh $(IDIR)/ECAL/*.hh $(IDIR)/HCAL/*.hh \
	$(IDIR)/Magnet/*.hh $(IDIR)/MIND/*.hh $(IDIR)/Cavity/*.hh $(ROOTSYS)/include/*.h


#executable file linking always comes first!
$(TARGET): $(OBJS)
	@echo ........Compiling 
	$(CC) $(LFLAGS) $(OBJS) $(LIBS) -o app/$(TARGET).exe
	@echo Done!

#compile the libraries
NearDetector.o: $(SDIR)/NearDetector.cxx $(INC)
	@echo ........Building Objects
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/NearDetector.cxx

RockConstruction.o: $(SDIR)/RockConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/RockConstruction.cxx

TPCFiducialConstruction.o: $(SDIR)/TPC/TPCFiducialConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCFiducialConstruction.cxx

#1 base class and 3 derived classes for TPCEnclosure
TPCEnclosureConstruction.o: $(SDIR)/TPC/TPCEnclosureConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCEnclosureConstruction.cxx

TPCEnclosureConstructionX.o: $(SDIR)/TPC/TPCEnclosureConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCEnclosureConstructionX.cxx

TPCEnclosureConstructionY.o: $(SDIR)/TPC/TPCEnclosureConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCEnclosureConstructionY.cxx

TPCEnclosureConstructionZ.o: $(SDIR)/TPC/TPCEnclosureConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TPC/TPCEnclosureConstructionZ.cxx

#1 base class and 3 derived classes for TASFiducial
TASFiducialConstruction.o: $(SDIR)/TAS/TASFiducialConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASFiducialConstruction.cxx

TASFiducialConstructionX.o: $(SDIR)/TAS/TASFiducialConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASFiducialConstructionX.cxx

TASFiducialConstructionY.o: $(SDIR)/TAS/TASFiducialConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASFiducialConstructionY.cxx

TASFiducialConstructionZ.o: $(SDIR)/TAS/TASFiducialConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASFiducialConstructionZ.cxx

#1 base class and 3 derived classes for TASEnclosure
TASEnclosureConstruction.o: $(SDIR)/TAS/TASEnclosureConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASEnclosureConstruction.cxx

TASEnclosureConstructionX.o: $(SDIR)/TAS/TASEnclosureConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASEnclosureConstructionX.cxx

TASEnclosureConstructionY.o: $(SDIR)/TAS/TASEnclosureConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASEnclosureConstructionY.cxx

TASEnclosureConstructionZ.o: $(SDIR)/TAS/TASEnclosureConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/TAS/TASEnclosureConstructionZ.cxx

#1 base class and 3 derived classes for ECALScintillatorConstruction
ECALScintillatorConstruction.o: $(SDIR)/ECAL/ECALScintillatorConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALScintillatorConstruction.cxx

ECALScintillatorConstructionZ.o: $(SDIR)/ECAL/ECALScintillatorConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALScintillatorConstructionZ.cxx

ECALScintillatorConstructionY.o: $(SDIR)/ECAL/ECALScintillatorConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALScintillatorConstructionY.cxx

ECALScintillatorConstructionX.o: $(SDIR)/ECAL/ECALScintillatorConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALScintillatorConstructionX.cxx

#1 base class and 3 derived classes for ECALSeparatorConstruction
ECALSeparatorConstruction.o: $(SDIR)/ECAL/ECALSeparatorConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALSeparatorConstruction.cxx

ECALSeparatorConstructionZ.o: $(SDIR)/ECAL/ECALSeparatorConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALSeparatorConstructionZ.cxx

ECALSeparatorConstructionY.o: $(SDIR)/ECAL/ECALSeparatorConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALSeparatorConstructionY.cxx

ECALSeparatorConstructionX.o: $(SDIR)/ECAL/ECALSeparatorConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALSeparatorConstructionX.cxx
#ECAL
ECALConstruction.o: $(SDIR)/ECAL/ECALConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/ECAL/ECALConstruction.cxx

#1 base class and 3 derived classes for ECALScintillatorConstruction
HCALScintillatorConstruction.o: $(SDIR)/HCAL/HCALScintillatorConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALScintillatorConstruction.cxx

HCALScintillatorConstructionZ.o: $(SDIR)/HCAL/HCALScintillatorConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALScintillatorConstructionZ.cxx

HCALScintillatorConstructionY.o: $(SDIR)/HCAL/HCALScintillatorConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALScintillatorConstructionY.cxx

HCALScintillatorConstructionX.o: $(SDIR)/HCAL/HCALScintillatorConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALScintillatorConstructionX.cxx

#1 base class and 3 derived classes for HCALSeparatorConstruction
HCALSeparatorConstruction.o: $(SDIR)/HCAL/HCALSeparatorConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALSeparatorConstruction.cxx

HCALSeparatorConstructionZ.o: $(SDIR)/HCAL/HCALSeparatorConstructionZ.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALSeparatorConstructionZ.cxx

HCALSeparatorConstructionY.o: $(SDIR)/HCAL/HCALSeparatorConstructionY.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALSeparatorConstructionY.cxx

HCALSeparatorConstructionX.o: $(SDIR)/HCAL/HCALSeparatorConstructionX.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALSeparatorConstructionX.cxx

#HCAL
HCALConstruction.o: $(SDIR)/HCAL/HCALConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/HCAL/HCALConstruction.cxx

#Magnet
MagnetConstruction.o: $(SDIR)/Magnet/MagnetConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/Magnet/MagnetConstruction.cxx

#MIND
MINDConstruction.o: $(SDIR)/MIND/MINDConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/MIND/MINDConstruction.cxx

#Cavity	
CavityConstruction.o: $(SDIR)/Cavity/CavityConstruction.cxx $(INC)
	$(CC) $(CFLAGS) $(LIBS) $(SDIR)/Cavity/CavityConstruction.cxx

.PHONY : clean

#clean up
clean:
	\rm *.o *~ $(TARGET)
