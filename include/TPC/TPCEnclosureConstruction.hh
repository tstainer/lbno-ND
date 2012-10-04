//
// Title: Header file for TPCEnclosure in ND
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

#include "TPCFiducialConstruction.hh"

#ifndef TPCEnclosureConstruction_hh_seen
#define TPCEnclosureConstruction_hh_seen

class TPCEnclosureConstruction 
{

public:
  
  TPCEnclosureConstruction();
  TPCEnclosureConstruction(double X,double Y,double Z);
  virtual ~TPCEnclosureConstruction();

  double GetX() {return TPCEnclosure_X;};
  double GetY() {return TPCEnclosure_Y;};
  double GetZ() {return TPCEnclosure_Z;};
  double GetThickness() {return TPCEnclosure_Thickness;};
  double GetVolumeSize() {return TPCEnclosure_VolumeSize;};
  std::string GetMaterialName() {return TPCEnclosure_MaterialName;};
  double GetMass() {return TPCEnclosure_Mass;};
  int GetCharge() {return TPCEnclosure_Charge;};
  double GetDensity() {return TPCEnclosure_Density;};

  TGeoMaterial * GetMaterial() {return TPCEnclosure_Material;};
  TGeoMedium * GetMedium() {return TPCEnclosure_Medium;};
  TGeoVolume * GetVolume() {return TPCEnclosure_Volume;};

  void SetThickness(double thickness);
  void SetX(double X);
  void SetY(double Y);
  void SetZ(double Z);
  void SetMaterial(std::string material,double atomic_weight,int charge,double density);

protected:

  double TPCEnclosure_X;
  double TPCEnclosure_Y;
  double TPCEnclosure_Z;
  double TPCEnclosure_Thickness;
  double TPCEnclosure_VolumeSize;
  std::string TPCEnclosure_MaterialName;
  double TPCEnclosure_Mass;
  int TPCEnclosure_Charge;
  double TPCEnclosure_Density;

  TGeoMaterial * TPCEnclosure_Material;
  TGeoMedium * TPCEnclosure_Medium;
  TGeoVolume * TPCEnclosure_Volume;
  TGeoBBox * TPCEnclosure_Box;

};

#endif
