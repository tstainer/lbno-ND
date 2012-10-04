//
// Title: Header file for TASFiducialY in ND
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

#ifndef TASFiducialConstructionY_hh_seen
#define TASFiducialConstructionY_hh_seen

class TASFiducialConstructionY : public TASFiducialConstruction
{

public:
  
  TASFiducialConstructionY();
  TASFiducialConstructionY(TPCEnclosureConstruction * TPCEnclosure,double thickness);
  ~TASFiducialConstructionY();

};

#endif
