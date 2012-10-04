//
// Title: Header file for HCALScintillatorY in ND
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

#ifndef HCALScintillatorConstructionY_hh_seen
#define HCALScintillatorConstructionY_hh_seen

class HCALScintillatorConstructionY : public HCALScintillatorConstruction
{

public:
  
  HCALScintillatorConstructionY();
  HCALScintillatorConstructionY(ECALConstruction * ECAL,double Scint_thickness);
  ~HCALScintillatorConstructionY();

};

#endif
