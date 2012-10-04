// Title: Magnitised Iron Detector
//
// Author: Tom Stainer
//
// Description: MIND geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "MINDConstruction.hh"

MINDConstruction::MINDConstruction()
{
  MIND_MaterialName = "Iron";
  MIND_Mass = 55.85;
  MIND_Charge = 26;
  MIND_Density = 7.87;

  MIND_Material = new TGeoMaterial(MIND_MaterialName.c_str(),MIND_Mass,MIND_Charge,MIND_Density);
  MIND_Medium = new TGeoMedium(MIND_MaterialName.c_str(),1,MIND_Material);

  MIND_X = 3;
  MIND_Y = 3;
  MIND_Z = 5;

  MIND_Box = new TGeoBBox("MIND_Box",MIND_X/2.0,MIND_Y/2.0,MIND_Z/2.0);

  MIND_Volume = new TGeoVolume("MIND_Volume",MIND_Box,MIND_Medium);
}


MINDConstruction::MINDConstruction(double X, double Y, double Z)
{
  MIND_MaterialName = "Iron";
  MIND_Mass = 55.85;
  MIND_Charge = 26;
  MIND_Density = 7.87;

  MIND_Material = new TGeoMaterial(MIND_MaterialName.c_str(),MIND_Mass,MIND_Charge,MIND_Density);
  MIND_Medium = new TGeoMedium(MIND_MaterialName.c_str(),1,MIND_Material);

  MIND_X = X;
  MIND_Y = Y;
  MIND_Z = Z;

  MIND_Box = new TGeoBBox("MIND_Box",MIND_X/2.0,MIND_Y/2.0,MIND_Z/2.0);

  MIND_Volume = new TGeoVolume("MIND_Volume",MIND_Box,MIND_Medium);
}

MINDConstruction::~MINDConstruction()
{
  delete MIND_Material;
  delete MIND_Medium;
  delete MIND_Volume;
  delete MIND_Box;

}


void MINDConstruction::SetMaterial(std::string material,double atomic_weight,int charge,double density)
{
  MIND_MaterialName = material.c_str();
  MIND_Mass = atomic_weight;
  MIND_Charge = charge;
  MIND_Density = density;

  MIND_Volume->GetMedium()->GetMaterial()->SetDensity(density);
  MIND_Volume->GetMedium()->GetMaterial()->SetA(atomic_weight);
  MIND_Volume->GetMedium()->GetMaterial()->SetZ(charge);
}

void MINDConstruction::SetVolumeName(std::string volume_name)
{
  MIND_Volume->SetName(volume_name.c_str());
}
