//
// Title: T A Scintillator for ND
//
// Author: Tom STainer
//
// Description: TAS Fiducial base class for the geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TASFiducialConstruction.hh"
#include "TPCEnclosureConstruction.hh"

TASFiducialConstruction::TASFiducialConstruction()
{
  //set material properties
  TASFiducial_Density = 1.18;
  TASFiducial_MaterialName = "Scintillator";

  //default material is Plastic Scintillator CH2
  TASFiducial_Material = new TGeoMixture(TASFiducial_MaterialName.c_str(),1,TASFiducial_Density);

  //ratios by mass
  //85% Carbon and 15% Hydrogen
  TASFiducial_Material->DefineElement(0,12,6,0.85);
  TASFiducial_Material->DefineElement(1,1.01,1,0.15);

  TASFiducial_Medium = new TGeoMedium(TASFiducial_MaterialName.c_str(),1,TASFiducial_Material);

  TASFiducial_Thickness = 0.5;

  //default size is 3m X 3m X 0.5m
  TASFiducial_Z = TASFiducial_Thickness;
  TASFiducial_X = 2 + 2*TASFiducial_Z;
  TASFiducial_Y = 2 + 2*TASFiducial_Z;

  TASFiducial_Box = new TGeoBBox("TASFiducial_Box",TASFiducial_X/2.0, TASFiducial_Y/2.0, TASFiducial_Z/2.0);

  TASFiducial_Volume = new TGeoVolume("TASFiducial_Volume",TASFiducial_Box,TASFiducial_Medium);
}

TASFiducialConstruction::TASFiducialConstruction(double X,double Y,double Z)
{
  //set material properties
  TASFiducial_Density = 1.18;
  TASFiducial_MaterialName = "Scintillator";

  //default material is Plastic Scintillator CH2
  TASFiducial_Material = new TGeoMixture(TASFiducial_MaterialName.c_str(),1,TASFiducial_Density);

  //ratios by mass
  //85% Carbon and 15% Hydrogen
  TASFiducial_Material->DefineElement(0,12,6,0.85);
  TASFiducial_Material->DefineElement(1,1.01,1,0.15);

  TASFiducial_Medium = new TGeoMedium(TASFiducial_MaterialName.c_str(),1,TASFiducial_Material);

  TASFiducial_X = X;
  TASFiducial_Y = Y;
  TASFiducial_Z = Z;

  TASFiducial_Box = new TGeoBBox("TASFiducial_Box",TASFiducial_X/2.0, TASFiducial_Y/2.0, TASFiducial_Z/2.0);

  TASFiducial_Volume = new TGeoVolume("TASFiducial_Volume",TASFiducial_Box,TASFiducial_Medium);
}

TASFiducialConstruction::~TASFiducialConstruction()
{
  delete TASFiducial_Material;
  delete TASFiducial_Medium;
  delete TASFiducial_Box;
  delete TASFiducial_Volume;
}
void TASFiducialConstruction::SetThickness(double thickness)
{
  TASFiducial_Thickness = thickness;
}

void TASFiducialConstruction::SetX(double x)
{
  TASFiducial_X = x;
}

void TASFiducialConstruction::SetY(double y)
{
  TASFiducial_Y = y;
}

void TASFiducialConstruction::SetZ(double z)
{
  TASFiducial_Z = z;
}

void TASFiducialConstruction::SetMaterial(std::string material,double density)
{
  TASFiducial_MaterialName = material;
  TASFiducial_Density = density;
  TASFiducial_Material = new TGeoMixture(material.c_str(),1,density);
  TASFiducial_Medium = new TGeoMedium(TASFiducial_MaterialName.c_str(),1,TASFiducial_Material);
}
