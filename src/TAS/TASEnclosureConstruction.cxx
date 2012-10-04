//
// Title: T A Scintillator Enclosure for ND
//
// Author: Tom STainer
//
// Description: TASEnclosure geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TASEnclosureConstruction.hh"

TASEnclosureConstruction::TASEnclosureConstruction()
{
  //set material properties
  TASEnclosure_MaterialName = "Al";
  TASEnclosure_Mass = 26.98;
  TASEnclosure_Charge = 13;
  TASEnclosure_Density = 2.7;

  //default material is Aluminium for casing
  TASEnclosure_Material = new TGeoMaterial(TASEnclosure_MaterialName.c_str(),TASEnclosure_Mass,TASEnclosure_Charge,TASEnclosure_Density);
  TASEnclosure_Medium = new TGeoMedium(TASEnclosure_MaterialName.c_str(),1,TASEnclosure_Material);

  //default thickness is 5mm
  TASEnclosure_Thickness = 0.005;

  //default dimensions
  TASEnclosure_X = 3 + (2*TASEnclosure_Thickness);
  TASEnclosure_Y = 3 + (2*TASEnclosure_Thickness);
  TASEnclosure_Z = TASEnclosure_Thickness;

  //make a plate and replicate it for enclosure
  TASEnclosure_Box = new TGeoBBox("TASEnclosure_Box",TASEnclosure_X/2.0, TASEnclosure_Y/2.0, TASEnclosure_Z/2.0);

  TASEnclosure_Volume = new TGeoVolume("TASEnclosure_Volume",TASEnclosure_Box,TASEnclosure_Medium);
}

TASEnclosureConstruction::TASEnclosureConstruction(double X,double Y,double Z)
{
  //set material properties
  TASEnclosure_MaterialName = "Al";
  TASEnclosure_Mass = 26.98;
  TASEnclosure_Charge = 13;
  TASEnclosure_Density = 2.7;

  //default material is Aluminium for casing
  TASEnclosure_Material = new TGeoMaterial(TASEnclosure_MaterialName.c_str(),TASEnclosure_Mass,TASEnclosure_Charge,TASEnclosure_Density);
  TASEnclosure_Medium = new TGeoMedium(TASEnclosure_MaterialName.c_str(),1,TASEnclosure_Material);

  TASEnclosure_X = X;
  TASEnclosure_Y = Y;
  TASEnclosure_Z = Z;

  //make a plate and replicate it for enclosure
  TASEnclosure_Box = new TGeoBBox("TASEnclosure_Box",TASEnclosure_X/2.0, TASEnclosure_Y/2.0, TASEnclosure_Z/2.0);

  TASEnclosure_Volume = new TGeoVolume("TASEnclosure_Volume",TASEnclosure_Box,TASEnclosure_Medium);
}

TASEnclosureConstruction::~TASEnclosureConstruction()
{ 
  delete TASEnclosure_Material;
  delete TASEnclosure_Medium;
  delete TASEnclosure_Box;
  delete TASEnclosure_Volume;
}

void TASEnclosureConstruction::SetThickness(double thickness)
{
  TASEnclosure_Thickness = thickness;
}

void TASEnclosureConstruction::SetX(double X)
{
  TASEnclosure_X = X;
}

void TASEnclosureConstruction::SetY(double Y)
{
  TASEnclosure_Y = Y;
}

void TASEnclosureConstruction::SetZ(double Z)
{
  TASEnclosure_Z = Z;
}

void TASEnclosureConstruction::SetMaterial(std::string material,double atomic_weight,double charge,double density)
{
  TASEnclosure_MaterialName = material.c_str();
  TASEnclosure_Mass = atomic_weight;
  TASEnclosure_Charge = charge;
  TASEnclosure_Density = density;

  TASEnclosure_Material = new TGeoMaterial(material.c_str(),atomic_weight,charge,density);
  TASEnclosure_Medium = new TGeoMedium(material.c_str(),1,TASEnclosure_Material);
}
