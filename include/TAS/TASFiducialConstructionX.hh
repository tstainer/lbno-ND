//
// Title: Header file for TASFiducialX in ND
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

#ifndef TASFiducialConstructionX_hh_seen
#define TASFiducialConstructionX_hh_seen

class TASFiducialConstructionX : public TASFiducialConstruction
{

public:
  
  TASFiducialConstructionX();
  TASFiducialConstructionX(TPCEnclosureConstruction * TPCEnclosure,double thickness);
  ~TASFiducialConstructionX();

};

#endif
