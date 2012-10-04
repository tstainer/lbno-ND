#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"

#ifndef TASFiducialConstruction_hh_seen
#define TASFiducialConstruction_hh_seen


class TASFiducialConstruction 
{

public:
  
  TASFiducialConstruction();
  TASFiducialConstruction(double X,double Y,double Z);
  virtual ~TASFiducialConstruction();

  double GetX() {return TASFiducial_X;};
  double GetY() {return TASFiducial_Y;};
  double GetZ() {return TASFiducial_Z;};
  double GetThickness() {return TASFiducial_Thickness;};
  double GetVolumeSize() {return TASFiducial_VolumeSize;};
  std::string GetMaterialName() {return TASFiducial_MaterialName;};
  double GetDensity() {return TASFiducial_Density;};

  TGeoMaterial * GetMaterial() {return TASFiducial_Material;};
  TGeoMedium * GetMedium() {return TASFiducial_Medium;};
  TGeoVolume * GetVolume() {return TASFiducial_Volume;};

  void SetThickness(double thickness);
  void SetX(double x);
  void SetY(double y);
  void SetZ(double z);
  void SetMaterial(std::string material,double density);

protected:

  double TASFiducial_X;
  double TASFiducial_Y;
  double TASFiducial_Z;
  double TASFiducial_Thickness;
  double TASFiducial_VolumeSize;
  std::string TASFiducial_MaterialName;
  double TASFiducial_Density;

  TGeoMixture * TASFiducial_Material;
  TGeoMedium * TASFiducial_Medium;
  TGeoVolume * TASFiducial_Volume;
  TGeoBBox * TASFiducial_Box;

};

#endif
