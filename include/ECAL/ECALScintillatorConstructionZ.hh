//
// Title: Header file for ECALScintillatorZ in ND
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

#ifndef ECALScintillatorConstructionZ_hh_seen
#define ECALScintillatorConstructionZ_hh_seen

class ECALScintillatorConstructionZ : public ECALScintillatorConstruction
{

public:
  
  ECALScintillatorConstructionZ();
  ECALScintillatorConstructionZ(TASEnclosureConstruction * TASFiducial,double thickness);
  ECALScintillatorConstructionZ(ECALSeparatorConstruction * ECALSeparator,double Scint_thickness);
  ~ECALScintillatorConstructionZ();

};

#endif
