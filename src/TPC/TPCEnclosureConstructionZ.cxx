//
// Title: Time Projection Chamber Enclosure for plates perpendicluar to the Z planes for ND
//
// Author: Tom STainer
//
// Description: TPCEnclosure geometry for root in the ND geometry is split into 6 segments - 3 classes
//              one class for plates perpendicular to each axis.
//
//              This class is for the TPC enclosure perpendicular to the Z planes

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TPCEnclosureConstructionZ.hh"
#include "TPCEnclosureConstruction.hh"
#include "TPCFiducialConstruction.hh"

TPCEnclosureConstructionZ::TPCEnclosureConstructionZ() : TPCEnclosureConstruction()
{
}

TPCEnclosureConstructionZ::TPCEnclosureConstructionZ(TPCFiducialConstruction * TPCFiducial,double thickness) : 
   TPCEnclosureConstruction(TPCFiducial->GetX() + 2*thickness,TPCFiducial->GetY() + 2*thickness,thickness)
{
  TPCEnclosure_Thickness = thickness;
}

TPCEnclosureConstructionZ::~TPCEnclosureConstructionZ()
{  
}
