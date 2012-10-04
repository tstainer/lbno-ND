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

#include "TASFiducialConstruction.hh"
#include "TASEnclosureConstruction.hh"
#include "ECALSeparatorConstruction.hh"
#include "ECALScintillatorConstruction.hh"
#include "ECALScintillatorConstructionX.hh"

ECALScintillatorConstructionX::ECALScintillatorConstructionX() : ECALScintillatorConstruction()
{
}

ECALScintillatorConstructionX::ECALScintillatorConstructionX(TASEnclosureConstruction * TASEnclosure,TASFiducialConstruction * TASFiducialX,TASFiducialConstruction * TASFiducialZ,double Scint_thickness) : 
  ECALScintillatorConstruction(Scint_thickness,TASEnclosure->GetY() + 2*TASEnclosure->GetThickness(),TASFiducialX->GetZ() + TASFiducialZ->GetThickness() + 1*TASEnclosure->GetThickness() )
{
  ECALScintillator_Thickness = Scint_thickness;
}

ECALScintillatorConstructionX::ECALScintillatorConstructionX(ECALSeparatorConstruction * ECALSeparator,double Scint_thickness) : 
  ECALScintillatorConstruction(Scint_thickness,ECALSeparator->GetY() + 2*ECALSeparator->GetThickness(),ECALSeparator->GetZ() + ECALSeparator->GetThickness()  )
{
  ECALScintillator_Thickness = Scint_thickness;
}

ECALScintillatorConstructionX::~ECALScintillatorConstructionX()
{
}

