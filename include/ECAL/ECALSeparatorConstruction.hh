//
// Title: Header file for ECALSeparator in ND
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

#ifndef ECALSeparatorConstruction_hh_seen
#define ECALSeparatorConstruction_hh_seen

class ECALSeparatorConstruction 
{

public:
  
  ECALSeparatorConstruction();
  ECALSeparatorConstruction(double X,double Y,double Z);
  virtual ~ECALSeparatorConstruction();

  double GetX() {return ECALSeparator_X;};
  double GetY() {return ECALSeparator_Y;};
  double GetZ() {return ECALSeparator_Z;};
  double GetThickness() {return ECALSeparator_Thickness;};
  double GetVolumeSize() {return ECALSeparator_VolumeSize;};
  std::string GetMaterialName() {return ECALSeparator_MaterialName;};
  double GetDensity() {return ECALSeparator_Density;};

  TGeoMaterial * GetMaterial() {return ECALSeparator_Material;};
  TGeoMedium * GetMedium() {return ECALSeparator_Medium;};
  TGeoVolume * GetVolume() {return ECALSeparator_Volume;};

  void SetThickness(double thickness);
  void SetX(double X);
  void SetY(double Y);
  void SetZ(double Z);
  void MakeVolume(double X,double Y,double Z);

protected:

  double ECALSeparator_X;
  double ECALSeparator_Y;
  double ECALSeparator_Z;
  double ECALSeparator_Thickness;
  double ECALSeparator_VolumeSize;
  std::string ECALSeparator_MaterialName;
  double ECALSeparator_Density;
  double ECALSeparator_Mass;
  int ECALSeparator_Charge;
  int  ECALSeparator_Layers;

  TGeoMaterial * ECALSeparator_Material;
  TGeoMedium * ECALSeparator_Medium;
  TGeoVolume * ECALSeparator_Volume;
  TGeoBBox * ECALSeparator_Box;

};

#endif
