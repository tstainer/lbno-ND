//
// Title: Time Projection Chamber Enclosure for plates perpendicluar to the Y planes for ND
//
// Author: Tom STainer
//
// Description: TPCEnclosure geometry for root in the ND geometry is split into 6 segments - 3 classes
//              one class for plates perpendicular to each axis.
//
//              This class is for the TPC enclosure perpendicular to the Y planes

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TPCEnclosureConstructionY.hh"
#include "TPCEnclosureConstruction.hh"
#include "TPCFiducialConstruction.hh"

TPCEnclosureConstructionY::TPCEnclosureConstructionY() : TPCEnclosureConstruction()
{
 
  //default size is 1 X 0.005 X 2 m
  TPCEnclosure_X = 1 + 2*TPCEnclosure_Thickness;
  TPCEnclosure_Y = TPCEnclosure_Thickness;
  TPCEnclosure_Z = 2;
}

TPCEnclosureConstructionY::TPCEnclosureConstructionY(TPCFiducialConstruction * TPCFiducial,double thickness): 
  TPCEnclosureConstruction(TPCFiducial->GetX() + 2*thickness,thickness,TPCFiducial->GetZ())
{
  TPCEnclosure_Thickness = thickness;
}

TPCEnclosureConstructionY::~TPCEnclosureConstructionY()
{  
}
