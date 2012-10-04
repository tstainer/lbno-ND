//
// Title: Header file for TASEnclosureX in ND
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

#ifndef TASEnclosureConstructionX_hh_seen
#define TASEnclosureConstructionX_hh_seen

class TASEnclosureConstructionX : public TASEnclosureConstruction
{

public:
  
  TASEnclosureConstructionX();
  TASEnclosureConstructionX(TASFiducialConstruction * TASFiducial,double thickness);
  ~TASEnclosureConstructionX();

};

#endif
