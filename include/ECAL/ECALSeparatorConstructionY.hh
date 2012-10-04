//
// Title: Header file for ECALSeparatorY in ND
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

#ifndef ECALSeparatorConstructionY_hh_seen
#define ECALSeparatorConstructionY_hh_seen

class ECALSeparatorConstructionY : public ECALSeparatorConstruction
{

public:

  ECALSeparatorConstructionY();
  ECALSeparatorConstructionY(TASEnclosureConstruction * TASEnclosure,double Sep_thickness);
  ECALSeparatorConstructionY(ECALScintillatorConstruction * ECALScintillator,double Sep_thickness);
  ~ECALSeparatorConstructionY();

};

#endif
