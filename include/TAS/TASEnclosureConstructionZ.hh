//
// Title: Header file for TASEnclosureZ in ND
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

#include "TASFiducialConstruction.hh"
#include "TASEnclosureConstruction.hh"

#ifndef TASEnclosureConstructionZ_hh_seen
#define TASEnclosureConstructionZ_hh_seen

class TASEnclosureConstructionZ : public TASEnclosureConstruction
{

public:
  
  TASEnclosureConstructionZ();
  TASEnclosureConstructionZ(TASFiducialConstruction * TASFiducial,double thickness);
  ~TASEnclosureConstructionZ();

};

#endif
