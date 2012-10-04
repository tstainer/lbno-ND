//
// Title: Header file for ECALScintillator in ND
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

#ifndef ECALScintillatorConstruction_hh_seen
#define ECALScintillatorConstruction_hh_seen

class ECALScintillatorConstruction 
{

public:
  
  ECALScintillatorConstruction();
  ECALScintillatorConstruction(double X,double Y,double Z);
  virtual ~ECALScintillatorConstruction();

  double GetX() {return ECALScintillator_X;};
  double GetY() {return ECALScintillator_Y;};
  double GetZ() {return ECALScintillator_Z;};
  double GetThickness() {return ECALScintillator_Thickness;};
  double GetVolumeSize() {return ECALScintillator_VolumeSize;};
  std::string GetMaterialName() {return ECALScintillator_MaterialName;};
  double GetDensity() {return ECALScintillator_Density;};

  TGeoMaterial * GetMaterial() {return ECALScintillator_Material;};
  TGeoMedium * GetMedium() {return ECALScintillator_Medium;};
  TGeoVolume * GetVolume() {return ECALScintillator_Volume;};

  void SetThickness(double thickness);
  void SetX(double X);
  void SetY(double Y);
  void SetZ(double Z);
  void MakeVolume(double X,double Y,double Z);

protected:

  double ECALScintillator_X;
  double ECALScintillator_Y;
  double ECALScintillator_Z;
  double ECALScintillator_Thickness;
  double ECALScintillator_VolumeSize;
  std::string ECALScintillator_MaterialName;
  double ECALScintillator_Density;
  int  ECALScintillator_Layers;

  TGeoMixture * ECALScintillator_Material;
  TGeoMedium * ECALScintillator_Medium;
  TGeoVolume * ECALScintillator_Volume;
  TGeoBBox * ECALScintillator_Box;

};

#endif
