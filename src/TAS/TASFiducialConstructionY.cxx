//
// Title: TAS Fiducial for plates perpendicluar to the Y planes for ND
//
// Author: Tom STainer
//
// Description: TASEnclosure geometry for root in the ND geometry is split into 6 segments - 3 classes
//              one class for plates perpendicular to each axis.
//
//              This class is for the TAS enclosure perpendicular to the Y planes

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TASFiducialConstructionY.hh"
#include "TASFiducialConstruction.hh"
#include "TPCEnclosureConstruction.hh"

TASFiducialConstructionY::TASFiducialConstructionY() : TASFiducialConstruction()
{
}

TASFiducialConstructionY::TASFiducialConstructionY(TPCEnclosureConstruction * TPCEnclosure,double thickness) : 
  TASFiducialConstruction(TPCEnclosure->GetX() + 2*thickness,thickness,TPCEnclosure->GetZ() + (2*TPCEnclosure->GetThickness()) )
{
  TASFiducial_Thickness = thickness;
}

TASFiducialConstructionY::~TASFiducialConstructionY()
{  
}
