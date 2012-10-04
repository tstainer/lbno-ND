//
// Title: Source file for ECALScintillator Y plate in ND
//
// Author: Tom STainer
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"

#include "TASFiducialConstruction.hh"
#include "TASEnclosureConstruction.hh"
#include "ECALSeparatorConstruction.hh"
#include "ECALScintillatorConstruction.hh"
#include "ECALScintillatorConstructionY.hh"

ECALScintillatorConstructionY::ECALScintillatorConstructionY() : ECALScintillatorConstruction()
{
}

ECALScintillatorConstructionY::ECALScintillatorConstructionY(TASEnclosureConstruction * TASEnclosure,TASFiducialConstruction * TASFiducialY,TASFiducialConstruction * TASFiducialZ,double Scint_thickness) : 
  ECALScintillatorConstruction(TASEnclosure->GetX() + 2*Scint_thickness,Scint_thickness,TASFiducialY->GetZ() + 1*TASFiducialZ->GetThickness() + 1*TASEnclosure->GetThickness() )
{
  ECALScintillator_Thickness = Scint_thickness;
}

ECALScintillatorConstructionY::ECALScintillatorConstructionY(ECALSeparatorConstruction * ECALSeparator,double Scint_thickness) : 
  ECALScintillatorConstruction(ECALSeparator->GetX() + 2*Scint_thickness,Scint_thickness,ECALSeparator->GetZ() + ECALSeparator->GetThickness() )
{
  ECALScintillator_Thickness = Scint_thickness;
}

ECALScintillatorConstructionY::~ECALScintillatorConstructionY()
{
}

