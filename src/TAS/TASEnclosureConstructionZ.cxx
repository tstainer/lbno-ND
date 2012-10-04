//
// Title: TAS Enclosure for plates perpendicluar to the Z planes for ND
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

#include "TASEnclosureConstructionZ.hh"
#include "TASEnclosureConstruction.hh"
#include "TASFiducialConstruction.hh"

TASEnclosureConstructionZ::TASEnclosureConstructionZ() : TASEnclosureConstruction()
{
}

TASEnclosureConstructionZ::TASEnclosureConstructionZ(TASFiducialConstruction * TASFiducial,double thickness) : 
   TASEnclosureConstruction(TASFiducial->GetX() + 2*thickness,TASFiducial->GetY() + 2*thickness,thickness)
{
  TASEnclosure_Thickness = thickness;
}

TASEnclosureConstructionZ::~TASEnclosureConstructionZ()
{  
}
