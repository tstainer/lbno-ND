//
// Title: Header file for TPCEnclosureX in ND
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

#ifndef TPCEnclosureConstructionX_hh_seen
#define TPCEnclosureConstructionX_hh_seen

class TPCEnclosureConstructionX : public TPCEnclosureConstruction
{

public:
  
  TPCEnclosureConstructionX();
  TPCEnclosureConstructionX(TPCFiducialConstruction * TPCFiducial,double thickness);
  ~TPCEnclosureConstructionX();

};

#endif
