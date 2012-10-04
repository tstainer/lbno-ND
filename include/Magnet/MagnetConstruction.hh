//
// Title: Header file for Magnet enclosure for ND
//
// Author: Tom Stainer
//
// Description: The magnet enclosure around the outside of HCAL for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"
#include "TGeoMatrix.h"
#include "TGeoCompositeShape.h"

#ifndef MagnetConstruction_hh_seen
#define MagnetConstruction_hh_seen

class MagnetConstruction
{

public:
  
  MagnetConstruction();
  MagnetConstruction(double X,double Y,double Z,double ends,double gap);
  ~MagnetConstruction();

  double GetThickness() {return Magnet_Thickness;};
  double GetX() {return Magnet_X;};
  double GetY() {return Magnet_Y;};
  double GetZ() {return Magnet_Z;};

  TGeoVolume * GetVolume() {return Magnet_Volume;};

private:

  std::string Magnet_MaterialName;
  double Magnet_Mass;
  double Magnet_Charge;
  double Magnet_Density;

  double Magnet_Thickness;
  double Magnet_End;
  double Magnet_Gap;
  double Magnet_X;
  double Magnet_Y;
  double Magnet_Z;

  TGeoMaterial * Magnet_Material;
  TGeoMedium * Magnet_Medium;
  TGeoBBox * Magnet_Main;
  TGeoBBox * Magnet_Ends;
  TGeoCompositeShape * Magnet_Assembly;
  TGeoVolume * Magnet_Volume;

  TGeoTranslation * tr1;
  TGeoTranslation * tr2;
  TGeoTranslation * tr3;
};

#endif 
