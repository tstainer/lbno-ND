//
// Title: Source file for HCALScintillator X plate in ND
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

#include "HCALScintillatorConstruction.hh"
#include "HCALSeparatorConstruction.hh"
#include "HCALSeparatorConstructionX.hh"

HCALSeparatorConstructionX::HCALSeparatorConstructionX() : HCALSeparatorConstruction()
{
}

HCALSeparatorConstructionX::HCALSeparatorConstructionX(HCALScintillatorConstruction * HCALScintillator,double Sep_thickness) : 
  HCALSeparatorConstruction(Sep_thickness,HCALScintillator->GetY() + 2*HCALScintillator->GetThickness(),HCALScintillator->GetZ() + HCALScintillator->GetThickness() )
{
  HCALSeparator_Thickness = Sep_thickness;
}


HCALSeparatorConstructionX::~HCALSeparatorConstructionX()
{
}

