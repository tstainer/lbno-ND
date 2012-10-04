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

#include "ECALConstruction.hh"
#include "HCALScintillatorConstruction.hh"
#include "HCALScintillatorConstructionY.hh"

HCALScintillatorConstructionY::HCALScintillatorConstructionY() : HCALScintillatorConstruction()
{
}

HCALScintillatorConstructionY::HCALScintillatorConstructionY(ECALConstruction * ECAL,double Scint_thickness) : 
  HCALScintillatorConstruction(ECAL->GetYPlate_X() + 2*Scint_thickness,Scint_thickness,ECAL->GetYPlate_Z() + ECAL->GetYPlate_Thickness() )
{
  HCALScintillator_Thickness = Scint_thickness;
}

HCALScintillatorConstructionY::~HCALScintillatorConstructionY()
{
}

