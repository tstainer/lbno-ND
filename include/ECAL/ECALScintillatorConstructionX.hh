//
// Title: Header file for ECALScintillatorX in ND
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

#ifndef ECALScintillatorConstructionX_hh_seen
#define ECALScintillatorConstructionX_hh_seen

class ECALScintillatorConstructionX : public ECALScintillatorConstruction
{

public:
  
  ECALScintillatorConstructionX();
  ECALScintillatorConstructionX(TASEnclosureConstruction * TASFiducial,TASFiducialConstruction * TASFiducialX,TASFiducialConstruction * TASFiducialZ,double thickness);
  ECALScintillatorConstructionX(ECALSeparatorConstruction * ECALSeparator,double Scint_thickness);
  ~ECALScintillatorConstructionX();

};

#endif
