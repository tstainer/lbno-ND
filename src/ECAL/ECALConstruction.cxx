//
// Title: ECAL sections for ND
//
// Author: Tom STainer
//
// Description: ECAL geometry for root in the ND geometry
//
// NOTE: DO NOT ALTER POSITIONS OF NODES - TRANSLATIONS ARE WORKED OUT AND BASED ON PREVIOUS LAYER - ONLY EDIT IF YOU FULLY UNDERSTAND THE GEOMETRY!!
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"
#include "TGeoMatrix.h"

#include "TASFiducialConstruction.hh"
#include "TASEnclosureConstruction.hh"

#include "ECALScintillatorConstruction.hh"
#include "ECALScintillatorConstructionZ.hh"
#include "ECALScintillatorConstructionY.hh"
#include "ECALScintillatorConstructionX.hh"

#include "ECALSeparatorConstruction.hh"
#include "ECALSeparatorConstructionZ.hh"
#include "ECALSeparatorConstructionY.hh"
#include "ECALSeparatorConstructionX.hh"

#include "ECALConstruction.hh"


ECALConstruction::ECALConstruction(TASEnclosureConstruction * TASEnclosureZ,TASEnclosureConstruction * TASEnclosureY,TASEnclosureConstruction * TASEnclosureX,TASFiducialConstruction * TASFiducialX, TASFiducialConstruction * TASFiducialY,TASFiducialConstruction * TASFiducialZ, double Scint_thickness,double Sep_thickness,int layers)
{
  ECALScintillator_Thickness = Scint_thickness;
  ECALSeparator_Thickness = Sep_thickness;
  ECAL_Layers = layers;

  //create an assembly for the Scint blocks and Lead Bars
  ECALAssembly_Volume = new TGeoVolumeAssembly("ECALAssembly_Volume");

  //create Z planes 
  ECALScintZ = new ECALScintillatorConstructionZ(TASEnclosureZ,ECALScintillator_Thickness);
  ECALSepZ = new ECALSeparatorConstructionZ(ECALScintZ,ECALSeparator_Thickness);

  //create Y planes
  ECALScintY = new ECALScintillatorConstructionY(TASEnclosureY,TASFiducialY,TASFiducialZ,ECALScintillator_Thickness);
  ECALSepY = new ECALSeparatorConstructionY(ECALScintY,ECALSeparator_Thickness);

 //create X planes
  ECALScintX = new ECALScintillatorConstructionX(TASEnclosureX,TASFiducialX,TASFiducialZ,ECALScintillator_Thickness);
  ECALSepX = new ECALSeparatorConstructionX(ECALScintX,ECALSeparator_Thickness);

  //translations
  ECALTranslation = (ECALScintillator_Thickness + ECALSeparator_Thickness);

  //set for origin offset
  YScint_origin = (ECALScintZ->GetThickness()+ECALScintY->GetZ())/2.0;
  YSep_origin = ECALScintY->GetZ()/2.0;
  
  //Add nodes to Assembly
  for(int i=0;i<ECAL_Layers;i++)
    {
      ECALScintZ->GetVolume()->SetLineColor(7);
      ECALScintY->GetVolume()->SetLineColor(7);
      ECALScintX->GetVolume()->SetLineColor(7);
      ECALSepZ->GetVolume()->SetLineColor(12);
      ECALSepY->GetVolume()->SetLineColor(12);
      ECALSepX->GetVolume()->SetLineColor(12);

      if(i==0)
	{
	  //Z planes
	  ECALAssembly_Volume->AddNode(ECALScintZ->GetVolume(),i,new TGeoTranslation(0,0,-i*ECALTranslation));
	  ECALAssembly_Volume->AddNode(ECALSepZ->GetVolume(),i,new TGeoTranslation(0,0,-0.5*ECALTranslation));

	  //Y planes
	  ECALAssembly_Volume->AddNode(ECALScintY->GetVolume(),i+ECAL_Layers,new TGeoTranslation(0,(ECALScintZ->GetY() - ECALScintY->GetThickness())/2.0,(ECALScintZ->GetThickness()+ECALScintY->GetZ())/2.0));
	  ECALAssembly_Volume->AddNode(ECALSepY->GetVolume(),i+ECAL_Layers,new TGeoTranslation(0, ( ECALSepZ->GetY() - ECALSepY->GetThickness() )/2.0,ECALScintY->GetZ()/2.0 ));
	  //negative side
	  ECALAssembly_Volume->AddNode(ECALScintY->GetVolume(),i + 2*ECAL_Layers,new TGeoTranslation(0,-(ECALScintZ->GetY() - ECALScintY->GetThickness())/2.0,(ECALScintZ->GetThickness()+ECALScintY->GetZ())/2.0));
	  ECALAssembly_Volume->AddNode(ECALSepY->GetVolume(),i + 2*ECAL_Layers,new TGeoTranslation(0, -( ECALSepZ->GetY() - ECALSepY->GetThickness() )/2.0,ECALScintY->GetZ()/2.0) );
	  
	  //X planes
	  ECALAssembly_Volume->AddNode(ECALScintX->GetVolume(), i + 3*ECAL_Layers,new TGeoTranslation((ECALScintZ->GetX() - ECALScintX->GetThickness())/2.0,0,(ECALScintZ->GetThickness()+ECALScintX->GetZ())/2.0));
	  ECALAssembly_Volume->AddNode(ECALSepX->GetVolume(), i + 3*ECAL_Layers,new TGeoTranslation(( ECALSepZ->GetX() - ECALSepX->GetThickness() )/2.0,0,ECALScintX->GetZ()/2.0 ));
	  //negative side
	  ECALAssembly_Volume->AddNode(ECALScintX->GetVolume(),i + 4*ECAL_Layers,new TGeoTranslation(-(ECALScintZ->GetX() - ECALScintX->GetThickness())/2.0,0,(ECALScintZ->GetThickness()+ECALScintX->GetZ())/2.0));
	  ECALAssembly_Volume->AddNode(ECALSepX->GetVolume(),i + 4*ECAL_Layers,new TGeoTranslation( -( ECALSepZ->GetX() - ECALSepX->GetThickness() )/2.0,0,ECALScintX->GetZ()/2.0) );

	}

      else
	{	  
	  ECALAssembly_Volume->AddNode(ECALScintZ->GetVolume(),i,new TGeoTranslation(0,0,-i*ECALTranslation) );
	  ECALAssembly_Volume->AddNode(ECALSepZ->GetVolume(),i,new TGeoTranslation(0,0,-(i+0.5)*ECALTranslation));

	  //Y planes
	  ECALAssembly_Volume->AddNode(ECALScintY->GetVolume(),i + 1*ECAL_Layers,new TGeoTranslation(0,( ECALScintZ->GetY() - ECALScintY->GetThickness() )/2.0 ,(YScint_origin - i*(ECALTranslation/2.0))));
	  ECALAssembly_Volume->AddNode(ECALSepY->GetVolume(),i + 1*ECAL_Layers,new TGeoTranslation(0, ( ECALSepZ->GetY() - ECALSepY->GetThickness() )/2.0 ,(YSep_origin - i*(ECALTranslation)/2.0) ));
	  //negative side
	  ECALAssembly_Volume->AddNode(ECALScintY->GetVolume(),i + 2*ECAL_Layers,new TGeoTranslation(0,-( ECALScintZ->GetY() - ECALScintY->GetThickness() )/2.0 ,(YScint_origin - i*(ECALTranslation/2.0))));
	  ECALAssembly_Volume->AddNode(ECALSepY->GetVolume(),i + 2*ECAL_Layers,new TGeoTranslation(0, -( ECALSepZ->GetY() - ECALSepY->GetThickness() )/2.0 ,(YSep_origin - i*(ECALTranslation)/2.0) ));
	  
	  //X planes
	  ECALAssembly_Volume->AddNode(ECALScintX->GetVolume(),i + 3*ECAL_Layers,new TGeoTranslation(( ECALScintZ->GetX() - ECALScintX->GetThickness() )/2.0 ,0,(YScint_origin - i*(ECALTranslation/2.0))));
	  ECALAssembly_Volume->AddNode(ECALSepX->GetVolume(),i + 3*ECAL_Layers,new TGeoTranslation(( ECALSepZ->GetX() - ECALSepX->GetThickness() )/2.0 ,0,(YSep_origin - i*(ECALTranslation)/2.0) ));
	  //negative side
	  ECALAssembly_Volume->AddNode(ECALScintX->GetVolume(),i + 4*ECAL_Layers,new TGeoTranslation(-( ECALScintZ->GetX() - ECALScintX->GetThickness() )/2.0 ,0,(YScint_origin - i*(ECALTranslation/2.0))));
	  ECALAssembly_Volume->AddNode(ECALSepX->GetVolume(),i + 4*ECAL_Layers,new TGeoTranslation( -( ECALSepZ->GetX() - ECALSepX->GetThickness() )/2.0 ,0,(YSep_origin - i*(ECALTranslation)/2.0) ));
	  

	}

      ECALTopX_X = ECALSepX->GetX();
      ECALTopX_Y = ECALSepX->GetY();
      ECALTopX_Z = ECALSepX->GetZ();
      
      ECALTopY_X = ECALSepY->GetX();
      ECALTopY_Y = ECALSepY->GetY();
      ECALTopY_Z = ECALSepY->GetZ();
      
      ECALTopZ_X = ECALSepZ->GetX();
      ECALTopZ_Y = ECALSepZ->GetY();
      ECALTopZ_Z = ECALSepZ->GetZ();
      
      //increase plate sizes
      //do not increase the size of the plates on the last turn
      if(i<ECAL_Layers)
	{
	  //Z plates
	  ECALScintZ->SetX(ECALSepZ->GetX() + 2*ECALScintillator_Thickness);
	  ECALScintZ->SetY(ECALSepZ->GetY() + 2*ECALScintillator_Thickness);
	  ECALSepZ->SetX(ECALScintZ->GetX() + 2*ECALSeparator_Thickness);
	  ECALSepZ->SetY(ECALScintZ->GetY() + 2*ECALSeparator_Thickness);
	  
	  //Y plates
	  ECALScintY->SetX(ECALSepY->GetX() + 2*ECALScintillator_Thickness);
	  ECALScintY->SetZ(ECALSepY->GetZ() + 1*ECALSeparator_Thickness);
	  ECALSepY->SetX(ECALScintY->GetX() + 2*ECALSeparator_Thickness);
	  ECALSepY->SetZ(ECALScintY->GetZ() + 1*ECALScintillator_Thickness);
	  
	  //X plates
	  ECALScintX->SetY(ECALSepX->GetY() + 2*ECALSeparator_Thickness);
	  ECALScintX->SetZ(ECALSepX->GetZ() + 1*ECALSeparator_Thickness);
	  ECALSepX->SetY(ECALScintX->GetY() + 2*ECALScintillator_Thickness);
	  ECALSepX->SetZ(ECALScintX->GetZ() + 1*ECALScintillator_Thickness);
	}
    }

}


ECALConstruction::~ECALConstruction()
{

  delete ECALAssembly_Volume; 
  delete ECALScintZ;
  delete ECALSepZ;
  delete ECALScintY;
  delete ECALSepY;
  delete ECALScintX;
  delete ECALSepX;
}



/*
void ECALConstruction::SetScintillatorThickness(double thickness)
{
  ECALScintillator_Thickness = thickness;

  //remake volumes
  ECALScintillator_Box = new TGeoBBox("ECALScintillator_Box",ECALScintillator_X/2.0, ECALScintillator_Y/2.0, ECALScintillator_Z/2.0);
  ECALScintillator_Volume = new TGeoVolume("ECALScintillator_Volume",ECALScintillator_Box,ECALScintillator_Medium);

  ECALSeparator_Box = new TGeoBBox("ECALSeparator_Box",ECALSeparator_X/2.0, ECALSeparator_Y/2.0, ECALSeparator_Z/2.0);
  ECALSeparator_Volume = new TGeoVolume("ECALSeparator_Volume",ECALSeparator_Box,ECALSeparator_Medium);

  ECALScintillator_Volume->SetLineColor(7);
  ECALSeparator_Volume->SetLineColor(12);

}

void ECALConstruction::SetX(double X)
{
  ECALScintillator_X = X;
  ECALSeparator_X = X + 2*this->GetSeparatorThickness();

  //remake volumes
  ECALScintillator_Box = new TGeoBBox("ECALScintillator_Box",ECALScintillator_X/2.0, ECALScintillator_Y/2.0, ECALScintillator_Z/2.0);
  ECALScintillator_Volume = new TGeoVolume("ECALScintillator_Volume",ECALScintillator_Box,ECALScintillator_Medium);

  ECALSeparator_Box = new TGeoBBox("ECALSeparator_Box",ECALSeparator_X/2.0, ECALSeparator_Y/2.0, ECALSeparator_Z/2.0);
  ECALSeparator_Volume = new TGeoVolume("ECALSeparator_Volume",ECALSeparator_Box,ECALSeparator_Medium);

  ECALScintillator_Volume->SetLineColor(7);
  ECALSeparator_Volume->SetLineColor(12);

}

void ECALConstruction::SetY(double Y)
{
  ECALScintillator_Y = Y;
  ECALSeparator_Y = Y + 2*this->GetSeparatorThickness();

  ECALScintillator_Box = new TGeoBBox("ECALScintillator_Box",ECALScintillator_X/2.0, ECALScintillator_Y/2.0, ECALScintillator_Z/2.0);
  ECALScintillator_Volume = new TGeoVolume("ECALScintillator_Volume",ECALScintillator_Box,ECALScintillator_Medium);

  ECALSeparator_Box = new TGeoBBox("ECALSeparator_Box",ECALSeparator_X/2.0, ECALSeparator_Y/2.0, ECALSeparator_Z/2.0);
  ECALSeparator_Volume = new TGeoVolume("ECALSeparator_Volume",ECALSeparator_Box,ECALSeparator_Medium);

  ECALScintillator_Volume->SetLineColor(7);
  ECALSeparator_Volume->SetLineColor(12);

}

void ECALConstruction::SetSeparatorMaterial(std::string material,double atomic_weight,int charge,double density)
{
  ECALSeparator_MaterialName = material;
  ECALSeparator_Mass = atomic_weight;
  ECALSeparator_Charge = charge;
  ECALSeparator_Density = density;
  ECALSeparator_Material = new TGeoMaterial(material.c_str(),atomic_weight,charge,density);
  ECALSeparator_Medium = new TGeoMedium(ECALSeparator_MaterialName.c_str(),1,ECALSeparator_Material);
  ECALSeparator_Volume = new TGeoVolume("ECALSeparator_Volume",ECALSeparator_Box,ECALSeparator_Medium);
}

*/
