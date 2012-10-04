//
// Title: Source file for HCALScintillator Y plate in ND
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
#include "HCALSeparatorConstructionY.hh"

HCALSeparatorConstructionY::HCALSeparatorConstructionY() : HCALSeparatorConstruction()
{
}

HCALSeparatorConstructionY::HCALSeparatorConstructionY(HCALScintillatorConstruction * HCALScintillator,double Sep_thickness) : 
  HCALSeparatorConstruction(HCALScintillator->GetX() + 2*Sep_thickness,Sep_thickness, HCALScintillator->GetZ() + HCALScintillator->GetThickness() )
{
  HCALSeparator_Thickness = Sep_thickness;
}

HCALSeparatorConstructionY::~HCALSeparatorConstructionY()
{
}

