//
// Title: Header file for ECALSeparatorX in ND
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
#include "ECALSeparatorConstruction.hh"
#include "ECALScintillatorConstruction.hh"

#ifndef ECALSeparatorConstructionX_hh_seen
#define ECALSeparatorConstructionX_hh_seen

class ECALSeparatorConstructionX : public ECALSeparatorConstruction
{

public:

  ECALSeparatorConstructionX();
  ECALSeparatorConstructionX(TASEnclosureConstruction * TASEnclosure,double Sep_thickness);
  ECALSeparatorConstructionX(ECALScintillatorConstruction * ECALScintillator,double Sep_thickness);
  ~ECALSeparatorConstructionX();

};

#endif
