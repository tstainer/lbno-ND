#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoTube.h"
#include "TGeoVolume.h"
//#include "TGeoMixture.h"

#ifndef RockConstruction_hh_seen
#define RockConstruction_hh_seen


class RockConstruction 
{

public:
  
  RockConstruction();
  RockConstruction(double Z,double R);
  ~RockConstruction();

  double GetR() {return Rock_R;};
  double GetZ() {return Rock_Z;};
  double GetVolumeSize() {return Rock_VolumeSize;};
  std::string GetMaterialName() {return Rock_MaterialName;};
  double GetDensity() {return Rock_Density;};

  TGeoMaterial * GetMaterial() {return Rock_Material;};
  TGeoMedium * GetMedium() {return Rock_Medium;};
  TGeoVolume * GetVolume() {return Rock_Volume;};

  void SetZ(double Z);
  void SetR(double R);
  void SetDensity(double density);

private:

  double Rock_R;
  double Rock_Z;
  double Rock_VolumeSize;
  std::string Rock_MaterialName;
  double Rock_Density;

  TGeoMixture * Rock_Material;
  TGeoMedium * Rock_Medium;
  TGeoVolume * Rock_Volume;
  TGeoTube * Rock_Tube;

};

#endif
