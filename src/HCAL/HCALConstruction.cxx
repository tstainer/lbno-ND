//
// Title: HCAL sections for ND
//
// Author: Tom STainer
//
// Description: HCAL geometry for root in the ND geometry
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

#include "ECALSeparatorConstruction.hh"

#include "HCALScintillatorConstruction.hh"
#include "HCALScintillatorConstructionZ.hh"
#include "HCALScintillatorConstructionY.hh"
#include "HCALScintillatorConstructionX.hh"

#include "HCALSeparatorConstruction.hh"
#include "HCALSeparatorConstructionZ.hh"
#include "HCALSeparatorConstructionY.hh"
#include "HCALSeparatorConstructionX.hh"

#include "HCALConstruction.hh"

HCALConstruction::HCALConstruction(ECALConstruction * ECAL,double Scint_thickness,double Sep_thickness,int layers)
{
  HCALScintillator_Thickness = Scint_thickness;
  HCALSeparator_Thickness = Sep_thickness;
  HCAL_Layers = layers;

  //create an assembly for the Scint blocks and Lead Bars
  HCALAssembly_Volume = new TGeoVolumeAssembly("HCALAssembly_Volume");

  //create Z planes 
  HCALScintZ = new HCALScintillatorConstructionZ(ECAL,HCALScintillator_Thickness);
  HCALSepZ = new HCALSeparatorConstructionZ(HCALScintZ,HCALSeparator_Thickness);

  //create Y planes
  HCALScintY = new HCALScintillatorConstructionY(ECAL,HCALScintillator_Thickness);
  HCALSepY = new HCALSeparatorConstructionY(HCALScintY,HCALSeparator_Thickness);

 //create X planes
  HCALScintX = new HCALScintillatorConstructionX(ECAL,HCALScintillator_Thickness);
  HCALSepX = new HCALSeparatorConstructionX(HCALScintX,HCALSeparator_Thickness);

  //translations
  HCALTranslation = (HCALScintillator_Thickness + HCALSeparator_Thickness);

  //set for origin offset
  YScint_origin = (HCALScintZ->GetThickness()+HCALScintY->GetZ())/2.0;
  YSep_origin = HCALScintY->GetZ()/2.0;
  
  //Add nodes to Assembly
  for(int i=0;i<HCAL_Layers;i++)
    {
      HCALScintZ->GetVolume()->SetLineColor(kRed);
      HCALScintY->GetVolume()->SetLineColor(kRed);
      HCALScintX->GetVolume()->SetLineColor(kRed);
      HCALSepZ->GetVolume()->SetLineColor(12);
      HCALSepY->GetVolume()->SetLineColor(12);
      HCALSepX->GetVolume()->SetLineColor(12);

      if(i==0)
	{
	  //Z planes
	  HCALAssembly_Volume->AddNode(HCALScintZ->GetVolume(),i,new TGeoTranslation(0,0,-i*HCALTranslation));
	  HCALAssembly_Volume->AddNode(HCALSepZ->GetVolume(),i,new TGeoTranslation(0,0,-0.5*HCALTranslation));

	  //Y planes
	  HCALAssembly_Volume->AddNode(HCALScintY->GetVolume(),i+HCAL_Layers,new TGeoTranslation(0,(HCALScintZ->GetY() - HCALScintY->GetThickness())/2.0,(HCALScintZ->GetThickness()+HCALScintY->GetZ())/2.0));
	  HCALAssembly_Volume->AddNode(HCALSepY->GetVolume(),i+HCAL_Layers,new TGeoTranslation(0, ( HCALSepZ->GetY() - HCALSepY->GetThickness() )/2.0,HCALScintY->GetZ()/2.0 ));
	  //negative side
	  HCALAssembly_Volume->AddNode(HCALScintY->GetVolume(),i + 2*HCAL_Layers,new TGeoTranslation(0,-(HCALScintZ->GetY() - HCALScintY->GetThickness())/2.0,(HCALScintZ->GetThickness()+HCALScintY->GetZ())/2.0));
	  HCALAssembly_Volume->AddNode(HCALSepY->GetVolume(),i + 2*HCAL_Layers,new TGeoTranslation(0, -( HCALSepZ->GetY() - HCALSepY->GetThickness() )/2.0,HCALScintY->GetZ()/2.0) );
	  
	  //X planes
	  HCALAssembly_Volume->AddNode(HCALScintX->GetVolume(), i + 3*HCAL_Layers,new TGeoTranslation((HCALScintZ->GetX() - HCALScintX->GetThickness())/2.0,0,(HCALScintZ->GetThickness()+HCALScintX->GetZ())/2.0));
	  HCALAssembly_Volume->AddNode(HCALSepX->GetVolume(), i + 3*HCAL_Layers,new TGeoTranslation(( HCALSepZ->GetX() - HCALSepX->GetThickness() )/2.0,0,HCALScintX->GetZ()/2.0 ));
	  //negative side
	  HCALAssembly_Volume->AddNode(HCALScintX->GetVolume(),i + 4*HCAL_Layers,new TGeoTranslation(-(HCALScintZ->GetX() - HCALScintX->GetThickness())/2.0,0,(HCALScintZ->GetThickness()+HCALScintX->GetZ())/2.0));
	  HCALAssembly_Volume->AddNode(HCALSepX->GetVolume(),i + 4*HCAL_Layers,new TGeoTranslation( -( HCALSepZ->GetX() - HCALSepX->GetThickness() )/2.0,0,HCALScintX->GetZ()/2.0) );

	}

      else
	{	  
	  HCALAssembly_Volume->AddNode(HCALScintZ->GetVolume(),i,new TGeoTranslation(0,0,-i*HCALTranslation) );
	  HCALAssembly_Volume->AddNode(HCALSepZ->GetVolume(),i,new TGeoTranslation(0,0,-(i+0.5)*HCALTranslation));

	  //Y planes
	  HCALAssembly_Volume->AddNode(HCALScintY->GetVolume(),i + 1*HCAL_Layers,new TGeoTranslation(0,( HCALScintZ->GetY() - HCALScintY->GetThickness() )/2.0 ,(YScint_origin - i*(HCALTranslation/2.0))));
	  HCALAssembly_Volume->AddNode(HCALSepY->GetVolume(),i + 1*HCAL_Layers,new TGeoTranslation(0, ( HCALSepZ->GetY() - HCALSepY->GetThickness() )/2.0 ,(YSep_origin - i*(HCALTranslation)/2.0) ));
	  //negative side
	  HCALAssembly_Volume->AddNode(HCALScintY->GetVolume(),i + 2*HCAL_Layers,new TGeoTranslation(0,-( HCALScintZ->GetY() - HCALScintY->GetThickness() )/2.0 ,(YScint_origin - i*(HCALTranslation/2.0))));
	  HCALAssembly_Volume->AddNode(HCALSepY->GetVolume(),i + 2*HCAL_Layers,new TGeoTranslation(0, -( HCALSepZ->GetY() - HCALSepY->GetThickness() )/2.0 ,(YSep_origin - i*(HCALTranslation)/2.0) ));
	  
	  //X planes
	  HCALAssembly_Volume->AddNode(HCALScintX->GetVolume(),i + 3*HCAL_Layers,new TGeoTranslation(( HCALScintZ->GetX() - HCALScintX->GetThickness() )/2.0 ,0,(YScint_origin - i*(HCALTranslation/2.0))));
	  HCALAssembly_Volume->AddNode(HCALSepX->GetVolume(),i + 3*HCAL_Layers,new TGeoTranslation(( HCALSepZ->GetX() - HCALSepX->GetThickness() )/2.0 ,0,(YSep_origin - i*(HCALTranslation)/2.0) ));
	  //negative side
	  HCALAssembly_Volume->AddNode(HCALScintX->GetVolume(),i + 4*HCAL_Layers,new TGeoTranslation(-( HCALScintZ->GetX() - HCALScintX->GetThickness() )/2.0 ,0,(YScint_origin - i*(HCALTranslation/2.0))));
	  HCALAssembly_Volume->AddNode(HCALSepX->GetVolume(),i + 4*HCAL_Layers,new TGeoTranslation( -( HCALSepZ->GetX() - HCALSepX->GetThickness() )/2.0 ,0,(YSep_origin - i*(HCALTranslation)/2.0) ));
	  

	}
      
      HCALTopX_X = HCALSepX->GetX();
      HCALTopX_Y = HCALSepX->GetY();
      HCALTopX_Z = HCALSepX->GetZ();
      
      HCALTopY_X = HCALSepY->GetX();
      HCALTopY_Y = HCALSepY->GetY();
      HCALTopY_Z = HCALSepY->GetZ();
      
      HCALTopZ_X = HCALSepZ->GetX();
      HCALTopZ_Y = HCALSepZ->GetY();
      HCALTopZ_Z = HCALSepZ->GetZ();

      //increase plate sizes
      //do not increase the size of the plates on the last turn
      if(i<HCAL_Layers)
	{
	  //Z plates
	  HCALScintZ->SetX(HCALSepZ->GetX() + 2*HCALScintillator_Thickness);
	  HCALScintZ->SetY(HCALSepZ->GetY() + 2*HCALScintillator_Thickness);
	  HCALSepZ->SetX(HCALScintZ->GetX() + 2*HCALSeparator_Thickness);
	  HCALSepZ->SetY(HCALScintZ->GetY() + 2*HCALSeparator_Thickness);
	  
	  //Y plates
	  HCALScintY->SetX(HCALSepY->GetX() + 2*HCALScintillator_Thickness);
	  HCALScintY->SetZ(HCALSepY->GetZ() + 1*HCALSeparator_Thickness);
	  HCALSepY->SetX(HCALScintY->GetX() + 2*HCALSeparator_Thickness);
	  HCALSepY->SetZ(HCALScintY->GetZ() + 1*HCALScintillator_Thickness);
	  
	  //X plates
	  HCALScintX->SetY(HCALSepX->GetY() + 2*HCALSeparator_Thickness);
	  HCALScintX->SetZ(HCALSepX->GetZ() + 1*HCALSeparator_Thickness);
	  HCALSepX->SetY(HCALScintX->GetY() + 2*HCALScintillator_Thickness);
	  HCALSepX->SetZ(HCALScintX->GetZ() + 1*HCALScintillator_Thickness);
	}
    }
}

HCALConstruction::~HCALConstruction()
{
  delete HCALScintZ;
  delete HCALSepZ;
  delete HCALScintY;
  delete HCALSepY;
  delete HCALScintX;
  delete HCALSepX;
  delete HCALAssembly_Volume; 
}


