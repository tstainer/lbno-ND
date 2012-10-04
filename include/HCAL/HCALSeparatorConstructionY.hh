//
// Title: Header file for HCALSeparatorY in ND
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

#include "TASEnclosureConstruction.hh"
#include "HCALSeparatorConstruction.hh"
#include "HCALScintillatorConstruction.hh"

#ifndef HCALSeparatorConstructionY_hh_seen
#define HCALSeparatorConstructionY_hh_seen

class HCALSeparatorConstructionY : public HCALSeparatorConstruction
{

public:

  HCALSeparatorConstructionY();
  HCALSeparatorConstructionY(HCALScintillatorConstruction * HCALScintillator,double Sep_thickness);
  ~HCALSeparatorConstructionY();

};

#endif
