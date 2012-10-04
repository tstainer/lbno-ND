// Title: Cavity for excavation
//
// Author: Tom Stainer
//
// Description: Cavity geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#ifndef CavityConstruction_hh_seen
#define CavityConstruction_hh_seen

class CavityConstruction
{

public:
  
  CavityConstruction();
  CavityConstruction(double X,double Y,double Z);
  ~CavityConstruction();

  //getters
  TGeoVolume * GetVolume() {return Cavity_Volume;};
  double GetX() {return Cavity_X;};
  double GetY() {return Cavity_Y;};
  double GetZ() {return Cavity_Z;};

  //setters
  void SetMaterial(std::string material,double density);
  void SetVolumeName(std::string volume_name);

private:

  std::string Cavity_MaterialName;
  double Cavity_Density;
  double Cavity_X;
  double Cavity_Y;
  double Cavity_Z;

  TGeoMixture * Cavity_Material;
  TGeoMedium * Cavity_Medium;
  TGeoBBox * Cavity_Box;
  TGeoVolume * Cavity_Volume;
  

};

#endif
