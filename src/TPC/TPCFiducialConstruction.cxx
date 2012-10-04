//
// Title: Time Projection Chamber for ND
//
// Author: Tom STainer
//
// Description: TPCFiducial geometry for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"

#include "TPCFiducialConstruction.hh"

TPCFiducialConstruction::TPCFiducialConstruction()
{

  TPCFiducial_MaterialName = "ArgonGas";
  TPCFiducial_Mass = 39.95;
  TPCFiducial_Charge = 18;
  TPCFiducial_Density = 1.8e-2;

  //default material is Gas Argon at density of 10 atm
  TPCFiducial_Material = new TGeoMaterial(TPCFiducial_MaterialName.c_str(),TPCFiducial_Mass,TPCFiducial_Charge,TPCFiducial_Density);
  TPCFiducial_Medium = new TGeoMedium(TPCFiducial_MaterialName.c_str(),1,TPCFiducial_Material);

  //default size is 1m X 1m X 2m
  TPCFiducial_X = 1;
  TPCFiducial_Y = 1;
  TPCFiducial_Z = 2;

  TPCFiducial_Box = new TGeoBBox("TPCFiducial_Box",TPCFiducial_X/2.0, TPCFiducial_Y/2.0, TPCFiducial_Z/2.0);

  TPCFiducial_Volume = new TGeoVolume("TPCFiducial_Volume",TPCFiducial_Box,TPCFiducial_Medium);
}

TPCFiducialConstruction::TPCFiducialConstruction(double X,double Y,double Z)
{

  TPCFiducial_MaterialName = "ArgonGas";
  TPCFiducial_Mass = 39.95;
  TPCFiducial_Charge = 18;
  TPCFiducial_Density = 1.8e-2;

  //default material is Gas Argon at density of 10 atm
  TPCFiducial_Material = new TGeoMaterial(TPCFiducial_MaterialName.c_str(),TPCFiducial_Mass,TPCFiducial_Charge,TPCFiducial_Density);
  TPCFiducial_Medium = new TGeoMedium(TPCFiducial_MaterialName.c_str(),1,TPCFiducial_Material);

  TPCFiducial_X = X;
  TPCFiducial_Y = Y;
  TPCFiducial_Z = Z;

  TPCFiducial_Box = new TGeoBBox("TPCFiducial_Box",TPCFiducial_X/2.0, TPCFiducial_Y/2.0, TPCFiducial_Z/2.0);

  TPCFiducial_Volume = new TGeoVolume("TPCFiducial_Volume",TPCFiducial_Box,TPCFiducial_Medium);
}

TPCFiducialConstruction::~TPCFiducialConstruction()
{
  delete TPCFiducial_Material;
  delete TPCFiducial_Medium;
  delete TPCFiducial_Box;
  delete TPCFiducial_Volume;
}

void TPCFiducialConstruction::SetX(double x)
{
  TPCFiducial_X = x;
}

void TPCFiducialConstruction::SetY(double y)
{
  TPCFiducial_Y = y;
}

void TPCFiducialConstruction::SetZ(double z)
{
  TPCFiducial_Z = z;
}

void TPCFiducialConstruction::SetMaterial(std::string material,double atomic_weight,int charge,double density)
{
  TPCFiducial_MaterialName = material.c_str();
  TPCFiducial_Mass = atomic_weight;
  TPCFiducial_Charge = charge;
  TPCFiducial_Density = density;

  TPCFiducial_Volume->GetMedium()->GetMaterial()->SetDensity(density);
  TPCFiducial_Volume->GetMedium()->GetMaterial()->SetA(atomic_weight);
  TPCFiducial_Volume->GetMedium()->GetMaterial()->SetZ(charge);
}
