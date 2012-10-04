//
// Title: HCALSeparator sections for ND
//
// Author: Tom STainer
//
// Description: HCALSeparator geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "HCALSeparatorConstruction.hh"

HCALSeparatorConstruction::HCALSeparatorConstruction()
{
 //set Separator material properties
  HCALSeparator_MaterialName = "Pb";
  HCALSeparator_Mass = 207.19;
  HCALSeparator_Charge = 82;
  HCALSeparator_Density = 11.35;

  HCALSeparator_Material = new TGeoMaterial(HCALSeparator_MaterialName.c_str(),HCALSeparator_Mass,HCALSeparator_Charge,HCALSeparator_Density);
  HCALSeparator_Medium = new TGeoMedium(HCALSeparator_MaterialName.c_str(),1,HCALSeparator_Material);

  HCALSeparator_Thickness = 0.5;

  HCALSeparator_X = 5;
  HCALSeparator_Y = 5;
  HCALSeparator_Z = HCALSeparator_Thickness;
      
  //make a block of scintillator
  this->MakeVolume(HCALSeparator_X,HCALSeparator_Y,HCALSeparator_Z);
}

HCALSeparatorConstruction::HCALSeparatorConstruction(double X,double Y,double Z)
{
  //set Separator material properties
  HCALSeparator_MaterialName = "Pb";
  HCALSeparator_Mass = 207.19;
  HCALSeparator_Charge = 82;
  HCALSeparator_Density = 11.35;

  HCALSeparator_Material = new TGeoMaterial(HCALSeparator_MaterialName.c_str(),HCALSeparator_Mass,HCALSeparator_Charge,HCALSeparator_Density);
  HCALSeparator_Medium = new TGeoMedium(HCALSeparator_MaterialName.c_str(),1,HCALSeparator_Material);

  HCALSeparator_X = X;
  HCALSeparator_Y = Y;
  HCALSeparator_Z = Z;
    
  //make a block of scintillator
  this->MakeVolume(HCALSeparator_X,HCALSeparator_Y,HCALSeparator_Z);
}

HCALSeparatorConstruction::~HCALSeparatorConstruction()
{
  delete HCALSeparator_Material;
  delete HCALSeparator_Medium;
  delete HCALSeparator_Box;
  delete HCALSeparator_Volume; 
}

void HCALSeparatorConstruction::SetThickness(double thickness)
{
  HCALSeparator_Thickness = thickness;
  this->MakeVolume(HCALSeparator_X,HCALSeparator_Y,thickness);
}

void HCALSeparatorConstruction::SetX(double X)
{
  HCALSeparator_X = X;
  this->MakeVolume(X,HCALSeparator_Y,HCALSeparator_Z);
}

void HCALSeparatorConstruction::SetY(double Y)
{
  HCALSeparator_Y = Y;
  this->MakeVolume(HCALSeparator_X,Y,HCALSeparator_Z);
}

void HCALSeparatorConstruction::SetZ(double Z)
{
  HCALSeparator_Z = Z;
  this->MakeVolume(HCALSeparator_X,HCALSeparator_Y,Z);
}

void HCALSeparatorConstruction::MakeVolume(double X,double Y,double Z)
{
  HCALSeparator_Box = new TGeoBBox("HCALSeparator_Box",X/2.0, Y/2.0,Z/2.0);
  HCALSeparator_Volume = new TGeoVolume("HCALSeparator_Volume",HCALSeparator_Box,HCALSeparator_Medium);
}

