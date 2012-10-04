//
// Title: ECALSeparator sections for ND
//
// Author: Tom STainer
//
// Description: ECALSeparator geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "ECALSeparatorConstruction.hh"

ECALSeparatorConstruction::ECALSeparatorConstruction()
{
 //set Separator material properties
  ECALSeparator_MaterialName = "Pb";
  ECALSeparator_Mass = 207.2;
  ECALSeparator_Charge = 82;
  ECALSeparator_Density = 11.35;

  ECALSeparator_Material = new TGeoMaterial(ECALSeparator_MaterialName.c_str(),ECALSeparator_Mass,ECALSeparator_Charge,ECALSeparator_Density);
  ECALSeparator_Medium = new TGeoMedium(ECALSeparator_MaterialName.c_str(),1,ECALSeparator_Material);

  ECALSeparator_Thickness = 0.5;

  ECALSeparator_X = 5;
  ECALSeparator_Y = 5;
  ECALSeparator_Z = ECALSeparator_Thickness;
      
  //make a block of scintillator
  this->MakeVolume(ECALSeparator_X,ECALSeparator_Y,ECALSeparator_Z);
}

ECALSeparatorConstruction::ECALSeparatorConstruction(double X,double Y,double Z)
{
  //set Separator material properties
  ECALSeparator_MaterialName = "Pb";
  ECALSeparator_Mass = 207.2;
  ECALSeparator_Charge = 82;
  ECALSeparator_Density = 11.35;

  ECALSeparator_Material = new TGeoMaterial(ECALSeparator_MaterialName.c_str(),ECALSeparator_Mass,ECALSeparator_Charge,ECALSeparator_Density);
  ECALSeparator_Medium = new TGeoMedium(ECALSeparator_MaterialName.c_str(),1,ECALSeparator_Material);

  ECALSeparator_X = X;
  ECALSeparator_Y = Y;
  ECALSeparator_Z = Z;
    
  //make a block of scintillator
  this->MakeVolume(ECALSeparator_X,ECALSeparator_Y,ECALSeparator_Z);
}

ECALSeparatorConstruction::~ECALSeparatorConstruction()
{
  delete ECALSeparator_Material;
  delete ECALSeparator_Medium;
  delete ECALSeparator_Box;
  delete ECALSeparator_Volume; 
}

void ECALSeparatorConstruction::SetThickness(double thickness)
{
  ECALSeparator_Thickness = thickness;
  this->MakeVolume(ECALSeparator_X,ECALSeparator_Y,thickness);
}

void ECALSeparatorConstruction::SetX(double X)
{
  ECALSeparator_X = X;
  this->MakeVolume(X,ECALSeparator_Y,ECALSeparator_Z);
}

void ECALSeparatorConstruction::SetY(double Y)
{
  ECALSeparator_Y = Y;
  this->MakeVolume(ECALSeparator_X,Y,ECALSeparator_Z);
}

void ECALSeparatorConstruction::SetZ(double Z)
{
  ECALSeparator_Z = Z;
  this->MakeVolume(ECALSeparator_X,ECALSeparator_Y,Z);
}

void ECALSeparatorConstruction::MakeVolume(double X,double Y,double Z)
{
  ECALSeparator_Box = new TGeoBBox("ECALSeparator_Box",X/2.0, Y/2.0,Z/2.0);
  ECALSeparator_Volume = new TGeoVolume("ECALSeparator_Volume",ECALSeparator_Box,ECALSeparator_Medium);
}

