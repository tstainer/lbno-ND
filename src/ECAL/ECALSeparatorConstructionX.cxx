//
// Title: Source file for ECALScintillator X plate in ND
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
#include "ECALSeparatorConstructionX.hh"

ECALSeparatorConstructionX::ECALSeparatorConstructionX() : ECALSeparatorConstruction()
{
}

ECALSeparatorConstructionX::ECALSeparatorConstructionX(TASEnclosureConstruction * TASEnclosure,double Sep_thickness) : 
  ECALSeparatorConstruction(Sep_thickness,TASEnclosure->GetY() + 2*TASEnclosure->GetThickness(),TASEnclosure->GetZ() + TASEnclosure->GetThickness())
{
  ECALSeparator_Thickness = Sep_thickness;
}

ECALSeparatorConstructionX::ECALSeparatorConstructionX(ECALScintillatorConstruction * ECALScintillator,double Sep_thickness) : 
  ECALSeparatorConstruction(Sep_thickness,ECALScintillator->GetY() + 2*ECALScintillator->GetThickness(),ECALScintillator->GetZ() + ECALScintillator->GetThickness() )
{
  ECALSeparator_Thickness = Sep_thickness;
}


ECALSeparatorConstructionX::~ECALSeparatorConstructionX()
{
}

