//
// Title: TAS Enclosure for plates perpendicluar to the X planes for ND
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

#include "TASEnclosureConstructionX.hh"
#include "TASEnclosureConstruction.hh"
#include "TASFiducialConstruction.hh"

TASEnclosureConstructionX::TASEnclosureConstructionX() : TASEnclosureConstruction()
{
}

TASEnclosureConstructionX::TASEnclosureConstructionX(TASFiducialConstruction * TASFiducial,double thickness) : 
  TASEnclosureConstruction(thickness,TASFiducial->GetY() + (2*TASFiducial->GetThickness()),TASFiducial->GetZ() + (2*TASFiducial->GetThickness()) )
{
  TASEnclosure_Thickness = thickness;
}

TASEnclosureConstructionX::~TASEnclosureConstructionX()
{  
}
