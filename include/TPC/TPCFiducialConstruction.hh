//
// Title: Header file for TPCFiducial in ND
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

#ifndef TPCFiducialConstruction_hh_seen
#define TPCFiducialConstruction_hh_seen


class TPCFiducialConstruction 
{

public:
  
  TPCFiducialConstruction();
  TPCFiducialConstruction(double X,double Y,double Z);
  ~TPCFiducialConstruction();

  double GetX() {return TPCFiducial_X;};
  double GetY() {return TPCFiducial_Y;};
  double GetZ() {return TPCFiducial_Z;};
  double GetVolumeSize() {return TPCFiducial_VolumeSize;};
  std::string GetMaterialName() {return TPCFiducial_MaterialName;};
  double GetMass() {return TPCFiducial_Mass;};
  int GetCharge() {return TPCFiducial_Charge;};
  double GetDensity() {return TPCFiducial_Density;};

  TGeoMaterial * GetMaterial() {return TPCFiducial_Material;};
  TGeoMedium * GetMedium() {return TPCFiducial_Medium;};
  TGeoVolume * GetVolume() {return TPCFiducial_Volume;};

  void SetX(double x);
  void SetY(double y);
  void SetZ(double z);
  void SetMaterial(std::string material,double atomic_weight,int charge,double density);

private:

  double TPCFiducial_X;
  double TPCFiducial_Y;
  double TPCFiducial_Z;
  double TPCFiducial_VolumeSize;
  std::string TPCFiducial_MaterialName;
  double TPCFiducial_Mass;
  int TPCFiducial_Charge;
  double TPCFiducial_Density;

  TGeoMaterial * TPCFiducial_Material;
  TGeoMedium * TPCFiducial_Medium;
  TGeoVolume * TPCFiducial_Volume;
  TGeoBBox * TPCFiducial_Box;

};

#endif
