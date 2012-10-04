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

#include "CavityConstruction.hh"

CavityConstruction::CavityConstruction()
{
  Cavity_MaterialName = "Air";
  Cavity_Density = 1.2e-3;

  Cavity_Material = new TGeoMixture(Cavity_MaterialName.c_str(),1,Cavity_Density);

  //ratios by mass
  Cavity_Material->DefineElement(0,14,7,0.78);
  Cavity_Material->DefineElement(1,16,8,0.22 );

  Cavity_Medium = new TGeoMedium(Cavity_MaterialName.c_str(),1,Cavity_Material);

  Cavity_X = 10;
  Cavity_Y = 10;
  Cavity_Z = 15;

  Cavity_Box = new TGeoBBox("Cavity_Box",Cavity_X/2.0,Cavity_Y/2.0,Cavity_Z/2.0);

  Cavity_Volume = new TGeoVolume("Cavity_Volume",Cavity_Box,Cavity_Medium);
}


CavityConstruction::CavityConstruction(double X, double Y, double Z)
{
  Cavity_MaterialName = "Air";
  Cavity_Density = 1.2e-3;

  Cavity_Material = new TGeoMixture(Cavity_MaterialName.c_str(),1,Cavity_Density);

  //ratios by mass
  Cavity_Material->DefineElement(0,14,7,0.78);
  Cavity_Material->DefineElement(1,16,8,0.22);

  Cavity_Medium = new TGeoMedium(Cavity_MaterialName.c_str(),1,Cavity_Material);

  Cavity_X = X;
  Cavity_Y = Y;
  Cavity_Z = Z;

  Cavity_Box = new TGeoBBox("Cavity_Box",Cavity_X/2.0,Cavity_Y/2.0,Cavity_Z/2.0);

  Cavity_Volume = new TGeoVolume("Cavity_Volume",Cavity_Box,Cavity_Medium);
}

CavityConstruction::~CavityConstruction()
{
  delete Cavity_Material;
  delete Cavity_Medium;
  delete Cavity_Volume;
  delete Cavity_Box;

}


void CavityConstruction::SetMaterial(std::string material,double density)
{
  Cavity_MaterialName = material.c_str();
  Cavity_Density = density;

  Cavity_Volume->GetMedium()->GetMaterial()->SetDensity(density);
}

void CavityConstruction::SetVolumeName(std::string volume_name)
{
  Cavity_Volume->SetName(volume_name.c_str());
}
