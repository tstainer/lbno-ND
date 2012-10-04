//
// Title: Header file for HCAL in ND
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
#include "TGeoMatrix.h"

#include "ECALConstruction.hh"

#ifndef HCALConstruction_hh_seen
#define HCALConstruction_hh_seen

class HCALConstruction : public ECALConstruction
{

public:
 
  HCALConstruction(double XY, double XZ, double YX, double YZ, double ZX,double ZY,double Scint_thickness,double Sep_thickness,int layers);
  ~HCALConstruction();
  
};

#endif
