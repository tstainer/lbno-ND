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
#include "ECALScintillatorConstruction.hh"
#include "ECALSeparatorConstruction.hh"
#include "ECALSeparatorConstructionZ.hh"

ECALSeparatorConstructionZ::ECALSeparatorConstructionZ() : ECALSeparatorConstruction()
{
}

ECALSeparatorConstructionZ::ECALSeparatorConstructionZ(TASEnclosureConstruction * TASEnclosure,double Sep_thickness) : 
  ECALSeparatorConstruction(TASEnclosure->GetX() + 2*Sep_thickness,TASEnclosure->GetY() + 2*Sep_thickness,Sep_thickness)
{
  ECALSeparator_Thickness = Sep_thickness;
}

ECALSeparatorConstructionZ::ECALSeparatorConstructionZ(ECALScintillatorConstruction * ECALScintillator,double Sep_thickness) : 
  ECALSeparatorConstruction(ECALScintillator->GetX() + 2*Sep_thickness,ECALScintillator->GetY() + 2*Sep_thickness,Sep_thickness )
{
  ECALSeparator_Thickness = Sep_thickness;
}


ECALSeparatorConstructionZ::~ECALSeparatorConstructionZ()
{
}

