//
// Title: Header file for HCAL in ND
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
#include "TGeoMatrix.h"

#include "ECALSeparatorConstruction.hh"
#include "HCALScintillatorConstruction.hh"
#include "HCALSeparatorConstruction.hh"

#ifndef HCALConstruction_hh_seen
#define HCALConstruction_hh_seen

class HCALConstruction 
{

public:
 
  HCALConstruction(ECALConstruction * ECAL,double Scint_thickness,double Sep_thickness,int layers);
  ~HCALConstruction();

  TGeoVolumeAssembly * GetVolume() {return HCALAssembly_Volume;};
  
  
  double GetScintillatorX() {return HCALScintillator_X;};
  double GetScintillatorY() {return HCALScintillator_Y;};
  double GetScintillatorZ() {return HCALScintillator_Z;};
  double GetScintillatorThickness() {return HCALScintillator_Thickness;};
  double GetScintillatorVolumeSize() {return HCALScintillator_VolumeSize;};
  std::string GetScintillatorMaterialName() {return HCALScintillator_MaterialName;};
  double GetScintillatorDensity() {return HCALScintillator_Density;};

  double GetXPlate_Thickness() {return HCALTopX_X;};
  double GetXPlate_Y() {return HCALTopX_Y;};
  double GetXPlate_Z() {return HCALTopX_Z;};

  double GetYPlate_X() {return HCALTopY_X;};
  double GetYPlate_Thickness() {return HCALTopY_Y;};
  double GetYPlate_Z() {return HCALTopY_Z;};

  double GetZPlate_X() {return HCALTopZ_X;};
  double GetZPlate_Y() {return HCALTopZ_Y;};
  double GetZPlate_Thickness() {return HCALTopZ_Z;};

  double GetTotalX() {return (HCALScintillator_Thickness + HCALSeparator_Thickness)*HCAL_Layers;};
  double GetTotalY() {return (HCALScintillator_Thickness + HCALSeparator_Thickness)*HCAL_Layers;};
  double GetTotalZ() {return (HCALScintillator_Thickness + HCALSeparator_Thickness)*HCAL_Layers;};
 
private:

  TGeoVolumeAssembly * HCALAssembly_Volume;

  HCALScintillatorConstruction * HCALScintZ;
  HCALScintillatorConstruction * HCALScintY;
  HCALScintillatorConstruction * HCALScintX;
  HCALSeparatorConstruction * HCALSepZ;
  HCALSeparatorConstruction * HCALSepY;
  HCALSeparatorConstruction * HCALSepX;
  
  double HCALScintillator_X;
  double HCALScintillator_Y;
  double HCALScintillator_Z;
  double HCALScintillator_Thickness;
  double HCALScintillator_VolumeSize;
  std::string HCALScintillator_MaterialName;
  double HCALScintillator_Density;
  
  TGeoMixture * HCALScintillator_Material;
  TGeoMedium * HCALScintillator_Medium;
  TGeoVolume * HCALScintillator_Volume;
  TGeoBBox * HCALScintillator_Box;

  double HCALSeparator_X;
  double HCALSeparator_Y;
  double HCALSeparator_Z;
  double HCALSeparator_Thickness;
  double HCALSeparator_VolumeSize;
  std::string HCALSeparator_MaterialName;
  double HCALSeparator_Mass;
  int HCALSeparator_Charge;
  double HCALSeparator_Density;
   
  TGeoMaterial * HCALSeparator_Material;
  TGeoMedium * HCALSeparator_Medium;
  TGeoVolume * HCALSeparator_Volume;
  TGeoBBox * HCALSeparator_Box;

  double HCAL_Thickness;
  int HCAL_Layers;

  //translation variable for adding nodes in HCAL assembly
   double HCALTranslation;

  //origin offset
  double YScint_origin;
  double YSep_origin;

  TGeoTranslation *  HCALScintillator_Translation;
  TGeoTranslation *  HCALSeparator_Translation;
  
  //total size of HCAL plates
  double HCALTopX_X;
  double HCALTopX_Y;
  double HCALTopX_Z;

  double HCALTopY_X;
  double HCALTopY_Y;
  double HCALTopY_Z;

  double HCALTopZ_X;
  double HCALTopZ_Y;
  double HCALTopZ_Z;
};

#endif
