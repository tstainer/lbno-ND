//
// Title: Source file for HCALScintillator Z plate in ND
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
#include "HCALSeparatorConstructionZ.hh"

HCALSeparatorConstructionZ::HCALSeparatorConstructionZ() : HCALSeparatorConstruction()
{
}

HCALSeparatorConstructionZ::HCALSeparatorConstructionZ(HCALScintillatorConstruction * HCALScintillator,double Sep_thickness) : 
  HCALSeparatorConstruction(HCALScintillator->GetX() + 2*Sep_thickness,HCALScintillator->GetY() + 2*Sep_thickness,Sep_thickness )
{
  HCALSeparator_Thickness = Sep_thickness;
}

HCALSeparatorConstructionZ::~HCALSeparatorConstructionZ()
{
}

