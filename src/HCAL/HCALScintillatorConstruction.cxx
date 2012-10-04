//
// Title: HCALScintillator sections for ND
//
// Author: Tom STainer
//
// Description: HCALScintillator geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "HCALScintillatorConstruction.hh"

HCALScintillatorConstruction::HCALScintillatorConstruction()
{
 //set Scintillator material properties
  HCALScintillator_MaterialName = "Scintillator";
  HCALScintillator_Density = 1.18;

  //default material is Plastic Scintillator CH2
  HCALScintillator_Material = new TGeoMixture(HCALScintillator_MaterialName.c_str(),1,HCALScintillator_Density);

  //ratios by mass
  //85% Carbon and 15% Hydrogen
  HCALScintillator_Material->DefineElement(0,12,6,0.85);
  HCALScintillator_Material->DefineElement(1,1.01,1,0.15);

  HCALScintillator_Medium = new TGeoMedium(HCALScintillator_MaterialName.c_str(),1,HCALScintillator_Material);

  HCALScintillator_Thickness = 0.5;

  HCALScintillator_X = 5;
  HCALScintillator_Y = 5;
  HCALScintillator_Z = HCALScintillator_Thickness;
      
  //make a block of scintillator
  this->MakeVolume(HCALScintillator_X,HCALScintillator_Y,HCALScintillator_Z);
}

HCALScintillatorConstruction::HCALScintillatorConstruction(double X,double Y,double Z)
{
  //set Scintillator material properties
  HCALScintillator_MaterialName = "Scintillator";
  HCALScintillator_Density = 1.18;

  //default material is Plastic Scintillator CH2
  HCALScintillator_Material = new TGeoMixture(HCALScintillator_MaterialName.c_str(),1,HCALScintillator_Density);

  //ratios by mass
  //85% Carbon and 15% Hydrogen
  HCALScintillator_Material->DefineElement(0,12,6,0.85);
  HCALScintillator_Material->DefineElement(1,1.01,1,0.15);

  HCALScintillator_Medium = new TGeoMedium(HCALScintillator_MaterialName.c_str(),1,HCALScintillator_Material);

  HCALScintillator_X = X;
  HCALScintillator_Y = Y;
  HCALScintillator_Z = Z;
    
  //make a block of scintillator
  this->MakeVolume(HCALScintillator_X,HCALScintillator_Y,HCALScintillator_Z);
}

HCALScintillatorConstruction::~HCALScintillatorConstruction()
{
  delete HCALScintillator_Material;
  delete HCALScintillator_Medium;
  delete HCALScintillator_Box;
  delete HCALScintillator_Volume; 
}

void HCALScintillatorConstruction::SetThickness(double thickness)
{
  HCALScintillator_Thickness = thickness;
  this->MakeVolume(HCALScintillator_X,HCALScintillator_Y,thickness);
}

void HCALScintillatorConstruction::SetX(double X)
{
  HCALScintillator_X = X;
  this->MakeVolume(X,HCALScintillator_Y,HCALScintillator_Z);
}

void HCALScintillatorConstruction::SetY(double Y)
{
  HCALScintillator_Y = Y;
  this->MakeVolume(HCALScintillator_X,Y,HCALScintillator_Z);
}

void HCALScintillatorConstruction::SetZ(double Z)
{
  HCALScintillator_Z = Z;
  this->MakeVolume(HCALScintillator_X,HCALScintillator_Y,Z);
}

void HCALScintillatorConstruction::MakeVolume(double X,double Y,double Z)
{
  HCALScintillator_Box = new TGeoBBox("HCALScintillator_Box",X/2.0, Y/2.0,Z/2.0);
  HCALScintillator_Volume = new TGeoVolume("HCALScintillator_Volume",HCALScintillator_Box,HCALScintillator_Medium);
}

