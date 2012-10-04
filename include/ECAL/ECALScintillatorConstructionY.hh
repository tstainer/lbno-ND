//
// Title: Header file for ECALScintillatorY in ND
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

#include "TASFiducialConstruction.hh"
#include "TASEnclosureConstruction.hh"
#include "ECALSeparatorConstruction.hh"
#include "ECALScintillatorConstruction.hh"

#ifndef ECALScintillatorConstructionY_hh_seen
#define ECALScintillatorConstructionY_hh_seen

class ECALScintillatorConstructionY : public ECALScintillatorConstruction
{

public:
  
  ECALScintillatorConstructionY();
  ECALScintillatorConstructionY(TASEnclosureConstruction * TASEnclosure,TASFiducialConstruction * TASFiducialY,TASFiducialConstruction * TASFiducialZ,double thickness);
  ECALScintillatorConstructionY(ECALSeparatorConstruction * ECALSeparator,double Scint_thickness);
  ~ECALScintillatorConstructionY();

};

#endif
