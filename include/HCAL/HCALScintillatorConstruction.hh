//
// Title: Header file for HCALScintillator in ND
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

#ifndef HCALScintillatorConstruction_hh_seen
#define HCALScintillatorConstruction_hh_seen

class HCALScintillatorConstruction 
{

public:
  
  HCALScintillatorConstruction();
  HCALScintillatorConstruction(double X,double Y,double Z);
  virtual ~HCALScintillatorConstruction();

  double GetX() {return HCALScintillator_X;};
  double GetY() {return HCALScintillator_Y;};
  double GetZ() {return HCALScintillator_Z;};
  double GetThickness() {return HCALScintillator_Thickness;};
  double GetVolumeSize() {return HCALScintillator_VolumeSize;};
  std::string GetMaterialName() {return HCALScintillator_MaterialName;};
  double GetDensity() {return HCALScintillator_Density;};

  TGeoMaterial * GetMaterial() {return HCALScintillator_Material;};
  TGeoMedium * GetMedium() {return HCALScintillator_Medium;};
  TGeoVolume * GetVolume() {return HCALScintillator_Volume;};

  void SetThickness(double thickness);
  void SetX(double X);
  void SetY(double Y);
  void SetZ(double Z);
  void MakeVolume(double X,double Y,double Z);

protected:

  double HCALScintillator_X;
  double HCALScintillator_Y;
  double HCALScintillator_Z;
  double HCALScintillator_Thickness;
  double HCALScintillator_VolumeSize;
  std::string HCALScintillator_MaterialName;
  double HCALScintillator_Density;
  int  HCALScintillator_Layers;

  TGeoMixture * HCALScintillator_Material;
  TGeoMedium * HCALScintillator_Medium;
  TGeoVolume * HCALScintillator_Volume;
  TGeoBBox * HCALScintillator_Box;

};

#endif
