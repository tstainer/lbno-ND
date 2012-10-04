//
// Title: Header file for TASEnclosureY in ND
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

#ifndef TASEnclosureConstructionY_hh_seen
#define TASEnclosureConstructionY_hh_seen

class TASEnclosureConstructionY : public TASEnclosureConstruction
{

public:
  
  TASEnclosureConstructionY();
  TASEnclosureConstructionY(TASFiducialConstruction * TASFiducial,double thickness);
  ~TASEnclosureConstructionY();

};

#endif
