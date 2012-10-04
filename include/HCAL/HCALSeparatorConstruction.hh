//
// Title: Header file for HCALSeparator in ND
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

#ifndef HCALSeparatorConstruction_hh_seen
#define HCALSeparatorConstruction_hh_seen

class HCALSeparatorConstruction 
{

public:
  
  HCALSeparatorConstruction();
  HCALSeparatorConstruction(double X,double Y,double Z);
  virtual ~HCALSeparatorConstruction();

  double GetX() {return HCALSeparator_X;};
  double GetY() {return HCALSeparator_Y;};
  double GetZ() {return HCALSeparator_Z;};
  double GetThickness() {return HCALSeparator_Thickness;};
  double GetVolumeSize() {return HCALSeparator_VolumeSize;};
  std::string GetMaterialName() {return HCALSeparator_MaterialName;};
  double GetDensity() {return HCALSeparator_Density;};

  TGeoMaterial * GetMaterial() {return HCALSeparator_Material;};
  TGeoMedium * GetMedium() {return HCALSeparator_Medium;};
  TGeoVolume * GetVolume() {return HCALSeparator_Volume;};

  void SetThickness(double thickness);
  void SetX(double X);
  void SetY(double Y);
  void SetZ(double Z);
  void MakeVolume(double X,double Y,double Z);

protected:

  double HCALSeparator_X;
  double HCALSeparator_Y;
  double HCALSeparator_Z;
  double HCALSeparator_Thickness;
  double HCALSeparator_VolumeSize;
  std::string HCALSeparator_MaterialName;
  double HCALSeparator_Density;
  double HCALSeparator_Mass;
  int HCALSeparator_Charge;
  int  HCALSeparator_Layers;

  TGeoMaterial * HCALSeparator_Material;
  TGeoMedium * HCALSeparator_Medium;
  TGeoVolume * HCALSeparator_Volume;
  TGeoBBox * HCALSeparator_Box;

};

#endif
