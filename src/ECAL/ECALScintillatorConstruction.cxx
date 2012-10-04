//
// Title: ECALScintillator sections for ND
//
// Author: Tom STainer
//
// Description: ECALScintillator geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "ECALScintillatorConstruction.hh"

ECALScintillatorConstruction::ECALScintillatorConstruction()
{
 //set Scintillator material properties
  ECALScintillator_MaterialName = "Scintillator";
  ECALScintillator_Density = 1.18;

  //default material is Plastic Scintillator CH2
  ECALScintillator_Material = new TGeoMixture(ECALScintillator_MaterialName.c_str(),1,ECALScintillator_Density);

  //ratios by mass
  //85% Carbon and 15% Hydrogen
  ECALScintillator_Material->DefineElement(0,12,6,0.85);
  ECALScintillator_Material->DefineElement(1,1.01,1,0.15);

  ECALScintillator_Medium = new TGeoMedium(ECALScintillator_MaterialName.c_str(),1,ECALScintillator_Material);

  ECALScintillator_Thickness = 0.5;

  ECALScintillator_X = 5;
  ECALScintillator_Y = 5;
  ECALScintillator_Z = ECALScintillator_Thickness;

  //make a block of scintillator
  this->MakeVolume(ECALScintillator_X,ECALScintillator_Y,ECALScintillator_Z);
}

ECALScintillatorConstruction::ECALScintillatorConstruction(double X,double Y,double Z)
{
  //set Scintillator material properties
  ECALScintillator_MaterialName = "Scintillator";
  ECALScintillator_Density = 1.18;

  //default material is Plastic Scintillator CH2
  ECALScintillator_Material = new TGeoMixture(ECALScintillator_MaterialName.c_str(),1,ECALScintillator_Density);

  //ratios by mass
  //85% Carbon and 15% Hydrogen
  ECALScintillator_Material->DefineElement(0,12,6,0.85);
  ECALScintillator_Material->DefineElement(1,1.01,1,0.15);

  ECALScintillator_Medium = new TGeoMedium(ECALScintillator_MaterialName.c_str(),1,ECALScintillator_Material);

  ECALScintillator_X = X;
  ECALScintillator_Y = Y;
  ECALScintillator_Z = Z;

  //make a block of scintillator
  this->MakeVolume(ECALScintillator_X,ECALScintillator_Y,ECALScintillator_Z);
}

ECALScintillatorConstruction::~ECALScintillatorConstruction()
{
  delete ECALScintillator_Material;
  delete ECALScintillator_Medium; 
  delete ECALScintillator_Box;
  delete ECALScintillator_Volume; 
}

void ECALScintillatorConstruction::SetThickness(double thickness)
{
  ECALScintillator_Thickness = thickness;
  this->MakeVolume(ECALScintillator_X,ECALScintillator_Y,thickness);
}

void ECALScintillatorConstruction::SetX(double X)
{
  ECALScintillator_X = X;
  this->MakeVolume(X,ECALScintillator_Y,ECALScintillator_Z);
}

void ECALScintillatorConstruction::SetY(double Y)
{
  ECALScintillator_Y = Y;
  this->MakeVolume(ECALScintillator_X,Y,ECALScintillator_Z);
}

void ECALScintillatorConstruction::SetZ(double Z)
{
  ECALScintillator_Z = Z;
  this->MakeVolume(ECALScintillator_X,ECALScintillator_Y,Z);
}

void ECALScintillatorConstruction::MakeVolume(double X,double Y,double Z)
{
  ECALScintillator_Box = new TGeoBBox("ECALScintillator_Box",X/2.0, Y/2.0,Z/2.0);
  ECALScintillator_Volume = new TGeoVolume("ECALScintillator_Volume",ECALScintillator_Box,ECALScintillator_Medium);
}

