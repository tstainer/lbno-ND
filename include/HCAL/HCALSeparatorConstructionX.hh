//
// Title: Header file for HCALSeparatorX in ND
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

#ifndef HCALSeparatorConstructionX_hh_seen
#define HCALSeparatorConstructionX_hh_seen

class HCALSeparatorConstructionX : public HCALSeparatorConstruction
{

public:

  HCALSeparatorConstructionX();
  HCALSeparatorConstructionX(HCALScintillatorConstruction * HCALScintillator,double Sep_thickness);
  ~HCALSeparatorConstructionX();

};

#endif
