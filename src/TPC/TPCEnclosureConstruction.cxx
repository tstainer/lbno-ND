//
// Title: Time Projection Chamber for ND
//
// Author: Tom STainer
//
// Description: TPCEnclosure geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TPCEnclosureConstruction.hh"
#include "TPCFiducialConstruction.hh"

TPCEnclosureConstruction::TPCEnclosureConstruction()
{
  //set material properties
  TPCEnclosure_MaterialName = "Al";
  TPCEnclosure_Mass = 26.98;
  TPCEnclosure_Charge = 13;
  TPCEnclosure_Density = 2.7;

  //default material is Aluminium for casing
  TPCEnclosure_Material = new TGeoMaterial(TPCEnclosure_MaterialName.c_str(),TPCEnclosure_Mass,TPCEnclosure_Charge,TPCEnclosure_Density);
  TPCEnclosure_Medium = new TGeoMedium(TPCEnclosure_MaterialName.c_str(),1,TPCEnclosure_Material);

  //default thickness is 5mm
  TPCEnclosure_Thickness = 0.005;

  //default size is TPCFiducial + 0.1 m X TPCFiducial + 0.1 m X 0.005m
  TPCEnclosure_X = 1 + (2*TPCEnclosure_Thickness);
  TPCEnclosure_Y = 1 + (2*TPCEnclosure_Thickness);
  TPCEnclosure_Z = TPCEnclosure_Thickness;

  //make a plate and replicate it for enclosure
  TPCEnclosure_Box = new TGeoBBox("TPCEnclosure_Box",TPCEnclosure_X/2.0, TPCEnclosure_Y/2.0, TPCEnclosure_Z/2.0);

  TPCEnclosure_Volume = new TGeoVolume("TPCEnclosure_Volume",TPCEnclosure_Box,TPCEnclosure_Medium);
}

TPCEnclosureConstruction::TPCEnclosureConstruction(double X,double Y,double Z)
{
  //set material properties
  TPCEnclosure_MaterialName = "Al";
  TPCEnclosure_Mass = 26.98;
  TPCEnclosure_Charge = 13;
  TPCEnclosure_Density = 2.7;

  //default material is Aluminium for casing
  TPCEnclosure_Material = new TGeoMaterial(TPCEnclosure_MaterialName.c_str(),TPCEnclosure_Mass,TPCEnclosure_Charge,TPCEnclosure_Density);
  TPCEnclosure_Medium = new TGeoMedium(TPCEnclosure_MaterialName.c_str(),1,TPCEnclosure_Material);

  TPCEnclosure_X = X;
  TPCEnclosure_Y = Y;
  TPCEnclosure_Z = Z;

  //make a plate and replicate it for enclosure
  TPCEnclosure_Box = new TGeoBBox("TPCEnclosure_Box",TPCEnclosure_X/2.0, TPCEnclosure_Y/2.0, TPCEnclosure_Z/2.0);

  TPCEnclosure_Volume = new TGeoVolume("TPCEnclosure_Volume",TPCEnclosure_Box,TPCEnclosure_Medium);
}


TPCEnclosureConstruction::~TPCEnclosureConstruction()
{
  delete TPCEnclosure_Material;
  delete TPCEnclosure_Medium;
  delete TPCEnclosure_Box;
  delete TPCEnclosure_Volume; 
}

void TPCEnclosureConstruction::SetThickness(double thickness)
{
  TPCEnclosure_Thickness = thickness;
}

void TPCEnclosureConstruction::SetX(double X)
{
  TPCEnclosure_X = X;
}

void TPCEnclosureConstruction::SetY(double Y)
{
  TPCEnclosure_Y = Y;
}

void TPCEnclosureConstruction::SetZ(double Z)
{
  TPCEnclosure_Z = Z;
}

void TPCEnclosureConstruction::SetMaterial(std::string material,double atomic_weight,int charge,double density)
{
  TPCEnclosure_MaterialName = material.c_str();
  TPCEnclosure_Mass = atomic_weight;
  TPCEnclosure_Charge = charge;
  TPCEnclosure_Density = density;
  TPCEnclosure_Material = new TGeoMaterial(material.c_str(),atomic_weight,charge,density);
  TPCEnclosure_Medium = new TGeoMedium(TPCEnclosure_MaterialName.c_str(),1,TPCEnclosure_Material);
}
