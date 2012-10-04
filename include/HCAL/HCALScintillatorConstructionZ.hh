//
// Title: Header file for HCALScintillatorZ in ND
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

#include "ECALConstruction.hh"
#include "HCALScintillatorConstruction.hh"

#ifndef HCALScintillatorConstructionZ_hh_seen
#define HCALScintillatorConstructionZ_hh_seen

class HCALScintillatorConstructionZ : public HCALScintillatorConstruction
{

public:
  
  HCALScintillatorConstructionZ();
  HCALScintillatorConstructionZ(ECALConstruction * ECAL,double Scint_thickness);
  ~HCALScintillatorConstructionZ();

};

#endif
