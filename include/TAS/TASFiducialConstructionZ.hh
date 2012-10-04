//
// Title: Header file for TASFiducialZ in ND
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

#include "TPCEnclosureConstruction.hh"
#include "TASFiducialConstruction.hh"

#ifndef TASFiducialConstructionZ_hh_seen
#define TASFiducialConstructionZ_hh_seen

class TASFiducialConstructionZ : public TASFiducialConstruction
{

public:
  
  TASFiducialConstructionZ();
  TASFiducialConstructionZ(TPCEnclosureConstruction * TPCEnclosure,double thickness);
  ~TASFiducialConstructionZ();

};

#endif
