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
#include "HCALScintillatorConstructionX.hh"

HCALScintillatorConstructionX::HCALScintillatorConstructionX() : HCALScintillatorConstruction()
{
}

HCALScintillatorConstructionX::HCALScintillatorConstructionX(ECALConstruction * ECAL,double Scint_thickness) : 
  HCALScintillatorConstruction(Scint_thickness,ECAL->GetXPlate_Y() + 2*ECAL->GetXPlate_Thickness(),ECAL->GetXPlate_Z() + ECAL->GetXPlate_Thickness()  )
{
  HCALScintillator_Thickness = Scint_thickness;
}

HCALScintillatorConstructionX::~HCALScintillatorConstructionX()
{
}

