//
// Title: Source file for ECALScintillator Z plate in ND
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

#include "TASEnclosureConstruction.hh"
#include "ECALSeparatorConstruction.hh"
#include "ECALScintillatorConstruction.hh"
#include "ECALScintillatorConstructionZ.hh"

ECALScintillatorConstructionZ::ECALScintillatorConstructionZ() : ECALScintillatorConstruction()
{
}

ECALScintillatorConstructionZ::ECALScintillatorConstructionZ(TASEnclosureConstruction * TASEnclosure,double Scint_thickness) : 
  ECALScintillatorConstruction(TASEnclosure->GetX() + 2*Scint_thickness,TASEnclosure->GetY() + 2*Scint_thickness,Scint_thickness)
{
  ECALScintillator_Thickness = Scint_thickness;
}

ECALScintillatorConstructionZ::ECALScintillatorConstructionZ(ECALSeparatorConstruction * ECALSeparator,double Scint_thickness) : 
  ECALScintillatorConstruction(ECALSeparator->GetX() + 2*Scint_thickness,ECALSeparator->GetY() + 2*Scint_thickness,Scint_thickness )
{
  ECALScintillator_Thickness = Scint_thickness;
}


ECALScintillatorConstructionZ::~ECALScintillatorConstructionZ()
{
}

