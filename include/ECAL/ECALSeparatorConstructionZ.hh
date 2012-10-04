//
// Title: Header file for ECALSeparatorZ in ND
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

#ifndef ECALSeparatorConstructionZ_hh_seen
#define ECALSeparatorConstructionZ_hh_seen

class ECALSeparatorConstructionZ : public ECALSeparatorConstruction
{

public:

  ECALSeparatorConstructionZ();
  ECALSeparatorConstructionZ(TASEnclosureConstruction * TASEnclosure,double Sep_thickness);
  ECALSeparatorConstructionZ(ECALScintillatorConstruction * ECALScintillator,double Sep_thickness);
  ~ECALSeparatorConstructionZ();

};

#endif
