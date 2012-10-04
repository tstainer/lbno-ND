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

#include "TASEnclosureConstruction.hh"
#include "ECALScintillatorConstruction.hh"
#include "ECALSeparatorConstruction.hh"
#include "ECALSeparatorConstructionY.hh"

ECALSeparatorConstructionY::ECALSeparatorConstructionY() : ECALSeparatorConstruction()
{
}

ECALSeparatorConstructionY::ECALSeparatorConstructionY(TASEnclosureConstruction * TASEnclosure,double Sep_thickness) : 
  ECALSeparatorConstruction(TASEnclosure->GetX() + 2*Sep_thickness,Sep_thickness,TASEnclosure->GetZ() + TASEnclosure->GetThickness())
{
  ECALSeparator_Thickness = Sep_thickness;
}

ECALSeparatorConstructionY::ECALSeparatorConstructionY(ECALScintillatorConstruction * ECALScintillator,double Sep_thickness) : 
  ECALSeparatorConstruction(ECALScintillator->GetX() + 2*Sep_thickness,Sep_thickness, ECALScintillator->GetZ() + ECALScintillator->GetThickness() )
{
  ECALSeparator_Thickness = Sep_thickness;
}


ECALSeparatorConstructionY::~ECALSeparatorConstructionY()
{
}

