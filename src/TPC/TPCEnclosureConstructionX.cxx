//
// Title: Time Projection Chamber Enclosure for plates perpendicluar to the X planes for ND
//
// Author: Tom STainer
//
// Description: TPCEnclosure geometry for root in the ND geometry is split into 6 segments - 3 classes
//              one class for plates perpendicular to each axis.
//
//              This class is for the TPC enclosure perpendicular to the X planes

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TPCEnclosureConstructionX.hh"
#include "TPCEnclosureConstruction.hh"
#include "TPCFiducialConstruction.hh"

TPCEnclosureConstructionX::TPCEnclosureConstructionX() : TPCEnclosureConstruction()

{
  //default size is 0.005 X 1 X 2 m
  TPCEnclosure_X = TPCEnclosure_Thickness;
  TPCEnclosure_Y = 1;
  TPCEnclosure_Z = 2;
}

TPCEnclosureConstructionX::TPCEnclosureConstructionX(TPCFiducialConstruction * TPCFiducial,double thickness): 
  TPCEnclosureConstruction(thickness,TPCFiducial->GetY(),TPCFiducial->GetZ())
{
  TPCEnclosure_Thickness = thickness;
}

TPCEnclosureConstructionX::~TPCEnclosureConstructionX()
{  
}
