//
// Title: Header file for TASEnclosure in ND
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

//#include "TASFiducialConstruction.hh"

#ifndef TASEnclosureConstruction_hh_seen
#define TASEnclosureConstruction_hh_seen

class TASEnclosureConstruction 
{

public:
  
  TASEnclosureConstruction();
  TASEnclosureConstruction(double X,double Y,double Z);
  virtual ~TASEnclosureConstruction();

  double GetX() {return TASEnclosure_X;};
  double GetY() {return TASEnclosure_Y;};
  double GetZ() {return TASEnclosure_Z;};
  double GetThickness() {return TASEnclosure_Thickness;};
  double GetVolumeSize() {return TASEnclosure_VolumeSize;};
  std::string GetMaterialName() {return TASEnclosure_MaterialName;};
  double GetMass() {return TASEnclosure_Mass;};
  int GetCharge() {return TASEnclosure_Charge;};
  double GetDensity() {return TASEnclosure_Density;};

  TGeoMaterial * GetMaterial() {return TASEnclosure_Material;};
  TGeoMedium * GetMedium() {return TASEnclosure_Medium;};
  TGeoVolume * GetVolume() {return TASEnclosure_Volume;};

  void SetThickness(double thickness);
  void SetX(double X);
  void SetY(double Y);
  void SetZ(double Z);
  void SetMaterial(std::string material,double atomic_weight,double charge,double density);

protected:

  double TASEnclosure_X;
  double TASEnclosure_Y;
  double TASEnclosure_Z;
  double TASEnclosure_Thickness;
  double TASEnclosure_VolumeSize;
  std::string TASEnclosure_MaterialName;
  double TASEnclosure_Mass;
  int TASEnclosure_Charge;
  double TASEnclosure_Density;

  TGeoMaterial * TASEnclosure_Material;
  TGeoMedium * TASEnclosure_Medium;
  TGeoVolume * TASEnclosure_Volume;
  TGeoBBox * TASEnclosure_Box;

};

#endif
