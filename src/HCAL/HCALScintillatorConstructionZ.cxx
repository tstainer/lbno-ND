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

#include "ECALSeparatorConstruction.hh"
#include "HCALSeparatorConstruction.hh"
#include "HCALScintillatorConstruction.hh"
#include "HCALScintillatorConstructionZ.hh"

HCALScintillatorConstructionZ::HCALScintillatorConstructionZ() : HCALScintillatorConstruction()
{
}

HCALScintillatorConstructionZ::HCALScintillatorConstructionZ(ECALConstruction * ECAL,double Scint_thickness) : 
  HCALScintillatorConstruction(ECAL->GetZPlate_X() + 2*Scint_thickness,ECAL->GetZPlate_Y() + 2*Scint_thickness,Scint_thickness )
{
  HCALScintillator_Thickness = Scint_thickness;
}

HCALScintillatorConstructionZ::~HCALScintillatorConstructionZ()
{
}

