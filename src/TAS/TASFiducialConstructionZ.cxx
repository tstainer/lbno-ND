//
// Title: TAS Fiducial for plates perpendicluar to the Z planes for ND
//
// Author: Tom STainer
//
// Description: TASEnclosure geometry for root in the ND geometry is split into 6 segments - 3 classes
//              one class for plates perpendicular to each axis.
//
//              This class is for the TAS enclosure perpendicular to the Z planes

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TASFiducialConstructionZ.hh"
#include "TASFiducialConstruction.hh"
#include "TPCEnclosureConstruction.hh"

TASFiducialConstructionZ::TASFiducialConstructionZ() : TASFiducialConstruction()
{
}

TASFiducialConstructionZ::TASFiducialConstructionZ(TPCEnclosureConstruction * TPCEnclosure,double thickness) : 
   TASFiducialConstruction(TPCEnclosure->GetX() + 2*thickness,TPCEnclosure->GetY() + 2*thickness,thickness)
{
  TASFiducial_Thickness = thickness;
}

TASFiducialConstructionZ::~TASFiducialConstructionZ()
{  
}
