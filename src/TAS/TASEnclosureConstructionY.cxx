//
// Title: TAS Enclosure for plates perpendicluar to the Y planes for ND
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

#include "TASEnclosureConstructionY.hh"
#include "TASEnclosureConstruction.hh"
#include "TASFiducialConstruction.hh"

TASEnclosureConstructionY::TASEnclosureConstructionY() : TASEnclosureConstruction()
{
}

TASEnclosureConstructionY::TASEnclosureConstructionY(TASFiducialConstruction * TASFiducial,double thickness) : 
  TASEnclosureConstruction(TASFiducial->GetX() + 2*thickness,thickness,TASFiducial->GetZ() + 2*(TASFiducial->GetThickness()) )
{
  TASEnclosure_Thickness = thickness;
}

TASEnclosureConstructionY::~TASEnclosureConstructionY()
{  
}
