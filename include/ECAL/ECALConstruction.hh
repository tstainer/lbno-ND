//
// Title: Header file for ECAL in ND
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

#include "TASFiducialConstruction.hh"
#include "TASEnclosureConstruction.hh"
#include "ECALScintillatorConstruction.hh"
#include "ECALSeparatorConstruction.hh"

#ifndef ECALConstruction_hh_seen
#define ECALConstruction_hh_seen

class ECALConstruction 
{

public:
 
  ECALConstruction(TASEnclosureConstruction * TASEnclosureZ,TASEnclosureConstruction * TASEnclosureY,TASEnclosureConstruction * TASEnclosureX,TASFiducialConstruction * TASFiducialX, TASFiducialConstruction * TASFiducialY,TASFiducialConstruction * TASFiducialZ,double Scint_thickness,double Sep_thickness,int layers);
  ECALConstruction(double XY,double XZ,double YX, double YZ, double ZX, double ZY, double Scint_thickness,double Sep_thickness,int layers);
  ~ECALConstruction();

  TGeoVolumeAssembly * GetVolume() {return ECALAssembly_Volume;};
    
  double GetScintillatorX() {return ECALScintillator_X;};
  double GetScintillatorY() {return ECALScintillator_Y;};
  double GetScintillatorZ() {return ECALScintillator_Z;};
  double GetScintillatorThickness() {return ECALScintillator_Thickness;};
  double GetScintillatorVolumeSize() {return ECALScintillator_VolumeSize;};
  std::string GetScintillatorMaterialName() {return ECALScintillator_MaterialName;};
  double GetScintillatorDensity() {return ECALScintillator_Density;};

  double GetXPlate_Thickness() {return ECALTopX_X;};
  double GetXPlate_Y() {return ECALTopX_Y;};
  double GetXPlate_Z() {return ECALTopX_Z;};

  double GetYPlate_X() {return ECALTopY_X;};
  double GetYPlate_Thickness() {return ECALTopY_Y;};
  double GetYPlate_Z() {return ECALTopY_Z;};

  double GetZPlate_X() {return ECALTopZ_X;};
  double GetZPlate_Y() {return ECALTopZ_Y;};
  double GetZPlate_Thickness() {return ECALTopZ_Z;};

  double GetAmountOfLayers() {return ECAL_Layers;};

  double GetTotalX() {return (ECALScintillator_Thickness + ECALSeparator_Thickness)*ECAL_Layers;};
  double GetTotalY() {return (ECALScintillator_Thickness + ECALSeparator_Thickness)*ECAL_Layers;};
  double GetTotalZ() {return (ECALScintillator_Thickness + ECALSeparator_Thickness)*ECAL_Layers;};

  /*
  TGeoMaterial * GetScintillatorMaterial() {return ECALScintillator_Material;};
  TGeoMedium * GetScintillatorMedium() {return ECALScintillator_Medium;};
  TGeoVolume * GetScintillatorVolume() {return ECALScintillator_Volume;};

  void SetScintillatorThickness(double thickness);
 
  double GetBarsX() {return ECALBars_X;};
  double GetBarsY() {return ECALBars_Y;};
  double GetBarsZ() {return ECALBars_Z;};
  double GetBarsThickness() {return ECALBars_Thickness;};
  double GetBarsVolumeSize() {return ECALBars_VolumeSize;};
  std::string GetBarsMaterialName() {return ECALBars_MaterialName;};
  double GetMass() {return ECALBars_Mass;};
  int GetCharge() {return ECALBars_Charge;};
  double GetBarsDensity() {return ECALBars_Density;};

  TGeoMaterial * GetBarsMaterial() {return ECALBars_Material;};
  TGeoMedium * GetBarsMedium() {return ECALBars_Medium;};
  TGeoVolume * GetBarsVolume() {return ECALBars_Volume;};

  void SetBarsThickness(double thickness);
  void SetBarsMaterial(std::string material,double atomic_weight,int charge,double density);

  void SetX(double X);
  void SetY(double Y);

  
  double GetAssemblyThickness() {return ECAL_Thickness;};
  */
protected:

  TGeoVolumeAssembly * ECALAssembly_Volume;

  ECALScintillatorConstruction * ECALScintZ;
  ECALScintillatorConstruction * ECALScintY;
  ECALScintillatorConstruction * ECALScintX;
  ECALSeparatorConstruction * ECALSepZ;
  ECALSeparatorConstruction * ECALSepY;
  ECALSeparatorConstruction * ECALSepX;
  
  double ECALScintillator_X;
  double ECALScintillator_Y;
  double ECALScintillator_Z;
  double ECALScintillator_Thickness;
  double ECALScintillator_VolumeSize;
  std::string ECALScintillator_MaterialName;
  double ECALScintillator_Density;
  
  TGeoMixture * ECALScintillator_Material;
  TGeoMedium * ECALScintillator_Medium;
  TGeoVolume * ECALScintillator_Volume;
  TGeoBBox * ECALScintillator_Box;

  double ECALSeparator_X;
  double ECALSeparator_Y;
  double ECALSeparator_Z;
  double ECALSeparator_Thickness;
  double ECALSeparator_VolumeSize;
  std::string ECALSeparator_MaterialName;
  double ECALSeparator_Mass;
  int ECALSeparator_Charge;
  double ECALSeparator_Density;
   
  TGeoMaterial * ECALSeparator_Material;
  TGeoMedium * ECALSeparator_Medium;
  TGeoVolume * ECALSeparator_Volume;
  TGeoBBox * ECALSeparator_Box;

  double ECAL_Thickness;
  int ECAL_Layers;

  //translation variable for adding nodes in ECAL assembly
   double ECALTranslation;

  //origin offset
  double YScint_origin;
  double YSep_origin;

  TGeoTranslation *  ECALScintillator_Translation;
  TGeoTranslation *  ECALSeparator_Translation;
  
  //total size of ECAL plates
  double ECALTopX_X;
  double ECALTopX_Y;
  double ECALTopX_Z;

  double ECALTopY_X;
  double ECALTopY_Y;
  double ECALTopY_Z;

  double ECALTopZ_X;
  double ECALTopZ_Y;
  double ECALTopZ_Z;

};

#endif
