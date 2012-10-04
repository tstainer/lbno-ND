//
// Title: Header file for TPCEnclosureZ in ND
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

#ifndef TPCEnclosureConstructionZ_hh_seen
#define TPCEnclosureConstructionZ_hh_seen

class TPCEnclosureConstructionZ : public TPCEnclosureConstruction
{

public:
  
  TPCEnclosureConstructionZ();
  TPCEnclosureConstructionZ(TPCFiducialConstruction * TPCFiducial,double thickness);
  ~TPCEnclosureConstructionZ();

};

#endif
