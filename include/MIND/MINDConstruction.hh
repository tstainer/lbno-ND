//
// Title: Header file for MIND detector in ND
//
// Author: Tom Stainer
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"

#ifndef MINDConstruction_hh_seen
#define MINDConstruction_hh_seen

class MINDConstruction
{

public:
  
  MINDConstruction();
  MINDConstruction(double X,double Y,double Z);
  ~MINDConstruction();

  //getters
  double GetX() { return MIND_X;};
  double GetY() { return MIND_Y;};
  double GetZ() { return MIND_Z;};

  TGeoVolume * GetVolume() { return MIND_Volume;};

  void SetMaterial(std::string material,double atomic_weight,int charge,double density);
  void SetVolumeName(std::string volume_name);

private:

  std::string MIND_MaterialName;
  double MIND_Mass;
  double MIND_Charge;
  double MIND_Density;

  double MIND_X;
  double MIND_Y;
  double MIND_Z;

  TGeoMaterial * MIND_Material;
  TGeoMedium * MIND_Medium;
  TGeoBBox * MIND_Box;
  TGeoVolume * MIND_Volume;
  
};

#endif
