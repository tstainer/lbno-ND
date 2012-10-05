//
// Title: HCAL sections for ND
//
// Author: Tom STainer
//
// Description: HCAL geometry for root in the ND geometry
//                
//             Inheret from ECAL setup
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"
#include "TGeoMatrix.h"

#include "ECALConstruction.hh"
#include "HCALConstruction.hh"


HCALConstruction::HCALConstruction(double XY, double XZ, double YX, double YZ, double ZX,double ZY,double HCALScint_thickness,double HCALSep_thickness,int HCALlayers) : 
  ECALConstruction(XY,XZ,YX,YZ,ZX,ZY,HCALScint_thickness,HCALSep_thickness,HCALlayers)
{
      ECALScintZ->GetVolume()->SetLineColor(2);
      ECALScintY->GetVolume()->SetLineColor(2);
      ECALScintX->GetVolume()->SetLineColor(2);
      ECALSepZ->GetVolume()->SetLineColor(12);
      ECALSepY->GetVolume()->SetLineColor(12);
      ECALSepX->GetVolume()->SetLineColor(12);
}

HCALConstruction::~HCALConstruction()
{
}


