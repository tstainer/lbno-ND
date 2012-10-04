//
// Title: Rock Environment for the enclosure around the ND
//
// Author: Tom STainer
//
// Description: Rock geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoTube.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"
//#include "TGeoMixture.h"

#include "RockConstruction.hh"

RockConstruction::RockConstruction()
{
  //default length of the "world" - the Rock, is 80m in length and 30m radius
  Rock_Z = 80;
  Rock_R = 30;
  Rock_VolumeSize = 3.14*Rock_Z*Rock_R*Rock_R;
  Rock_MaterialName = "Sandstone";
  Rock_Density = 2.323;

  //Rock is Sandstone Si02
  Rock_Material = new TGeoMixture(Rock_MaterialName.c_str(),1, Rock_Density);

  //ratios by mass - approximate Sandstone to SiO2
  //53.33% Oxygen & 46.67% Silicon
  Rock_Material->DefineElement(0,16,8,0.5333);
  Rock_Material->DefineElement(1,28,14,0.4667);
  
  Rock_Medium = new TGeoMedium(Rock_MaterialName.c_str(),1,Rock_Material);

  Rock_Tube = new TGeoTube("Rock_Tube",0,Rock_R,Rock_Z/2.0);
  
  Rock_Volume = new TGeoVolume("Rock_Volume",Rock_Tube,Rock_Medium);
}

RockConstruction::RockConstruction(double Z,double R)
{
  Rock_VolumeSize = 3.14*Rock_Z*Rock_R*Rock_R;
  Rock_MaterialName = "Sandstone";
  Rock_Density = 2.323;

  //Rock is Sandstone Si02
  Rock_Material = new TGeoMixture(Rock_MaterialName.c_str(),1, Rock_Density);

  //ratios by mass - approximate Sandstone to SiO2
  //53.33% Oxygen & 46.67% Silicon
  Rock_Material->DefineElement(0,16,8,0.5333);
  Rock_Material->DefineElement(1,28,14,0.4667);
  
  Rock_Medium = new TGeoMedium(Rock_MaterialName.c_str(),1,Rock_Material);

  //set minimum dimensions of world so that it includes the detector - assume this is 10m and a radius of 8m
  if((Z < 10) || (R < 8))
    {
      //if smaller than allowed set to defaults
      Rock_Z = 80;
      Rock_R = 30;
      std::cout << "\nTo small dimensions set for the rock, set to defaults of Z = 80 m and R = 30 m." << std::endl;
    }

  else
    {
      Rock_Z = Z;
      Rock_R = R;
    }

  Rock_Tube = new TGeoTube("Rock_Tube",0,Rock_R,Rock_Z/2.0);
  
  Rock_Volume = new TGeoVolume("Rock_Volume",Rock_Tube,Rock_Medium);
}


RockConstruction::~RockConstruction()
{
  delete Rock_Material;
  delete Rock_Medium;
  delete Rock_Tube;
  delete Rock_Volume;
}

void RockConstruction::SetZ(double Z)
{
  Rock_Z = Z;
}

void RockConstruction::SetR(double R)
{
  Rock_R = R;
}

void RockConstruction::SetDensity(double density)
{
  Rock_Density = density;
  Rock_Volume->GetMedium()->GetMaterial()->SetDensity(density);
}
