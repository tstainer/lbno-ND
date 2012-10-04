//
// Title: Header file for ECAL Z plate in ND
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
#include "ECALConstruction.hh"

#ifndef ECALConstructionZ_hh_seen
#define ECALConstructionZ_hh_seen

class ECALConstructionZ : public ECALConstruction
{

public:

  ECALConstructionZ(TASEnclosureConstruction * TASEnclosure,double Scint_thickness,double Bar_thickness,int layers);
  ~ECALConstructionZ();

};

#endif
