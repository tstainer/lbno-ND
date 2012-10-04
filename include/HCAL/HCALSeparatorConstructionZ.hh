//
// Title: Header file for HCALSeparatorZ in ND
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

#ifndef HCALSeparatorConstructionZ_hh_seen
#define HCALSeparatorConstructionZ_hh_seen

class HCALSeparatorConstructionZ : public HCALSeparatorConstruction
{

public:

  HCALSeparatorConstructionZ();
  HCALSeparatorConstructionZ(HCALScintillatorConstruction * HCALScintillator,double Sep_thickness);
  ~HCALSeparatorConstructionZ();

};

#endif
