//
// Title: Header file for TPCEnclosureY in ND
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

#include "TPCFiducialConstruction.hh"
#include "TPCEnclosureConstruction.hh"

#ifndef TPCEnclosureConstructionY_hh_seen
#define TPCEnclosureConstructionY_hh_seen

class TPCEnclosureConstructionY : public TPCEnclosureConstruction
{

public:
  
  TPCEnclosureConstructionY();
  TPCEnclosureConstructionY(TPCFiducialConstruction * TPCFiducial,double thickness);
  ~TPCEnclosureConstructionY();

};

#endif
