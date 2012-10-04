//
// Title: Header file for HCALScintillatorX in ND
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

#ifndef HCALScintillatorConstructionX_hh_seen
#define HCALScintillatorConstructionX_hh_seen

class HCALScintillatorConstructionX : public HCALScintillatorConstruction
{

public:
  
  HCALScintillatorConstructionX();
  HCALScintillatorConstructionX(ECALConstruction * ECAL,double Scint_thickness);
  ~HCALScintillatorConstructionX();

};

#endif
