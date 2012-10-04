//
// Title: TAS Fiducial for plates perpendicluar to the X planes for ND
//
// Author: Tom STainer
//
// Description: TASEnclosure geometry for root in the ND geometry is split into 6 segments - 3 classes
//              one class for plates perpendicular to each axis.
//
//              This class is for the TAS enclosure perpendicular to the X planes

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TASFiducialConstructionX.hh"
#include "TASFiducialConstruction.hh"
#include "TPCEnclosureConstruction.hh"

TASFiducialConstructionX::TASFiducialConstructionX() : TASFiducialConstruction()
{
}

TASFiducialConstructionX::TASFiducialConstructionX(TPCEnclosureConstruction * TPCEnclosure,double thickness) : 
  TASFiducialConstruction(thickness,TPCEnclosure->GetY() + (2*TPCEnclosure->GetThickness()),TPCEnclosure->GetZ() + (2*TPCEnclosure->GetThickness()))
{
  TASFiducial_Thickness = thickness;
}

TASFiducialConstructionX::~TASFiducialConstructionX()
{  
}
