//
// Title: Magnet enclosure for ND
//
// Author: Tom Stainer
//
// Description: The magnet enclosure around the outside of HCAL for root in the ND geometry

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMedium.h"
#include "TGeoMatrix.h"
#include "TGeoCompositeShape.h"

#include "MagnetConstruction.hh"

MagnetConstruction::MagnetConstruction()
{
  Magnet_MaterialName = "Iron";
  Magnet_Mass = 55.85;
  Magnet_Charge = 26;
  Magnet_Density = 7.87;

  Magnet_Material = new TGeoMaterial(Magnet_MaterialName.c_str(),Magnet_Mass,Magnet_Charge,Magnet_Density);
  Magnet_Medium = new TGeoMedium(Magnet_MaterialName.c_str(),1,Magnet_Material);

  //X will be the thickness
  Magnet_X = 1;
  Magnet_Y = 5;
  Magnet_Z = 5;

  Magnet_Thickness = Magnet_X;
  //for horse shoe need extra parameter which governs ends
  Magnet_End = 4;

  //translations
  tr1 = new TGeoTranslation("tr1",0,0,0);
  tr2 = new TGeoTranslation("tr2",0,(Magnet_Y + Magnet_Thickness)/2.0,0);
  tr3 = new TGeoTranslation("tr3",0,-(Magnet_Y + Magnet_Thickness)/2.0,0);
  tr1->RegisterYourself();
  tr2->RegisterYourself();
  tr3->RegisterYourself();

  Magnet_Main = new TGeoBBox("Magnet_Main",Magnet_Thickness/2.0,Magnet_Y/2.0,Magnet_Z/2.0);
  Magnet_Ends = new TGeoBBox("Magnet_Ends",(Magnet_End + Magnet_Thickness)/2.0,Magnet_Thickness/2.0,Magnet_Z/2.0);

  Magnet_Assembly = new TGeoCompositeShape("Magnet_Assembly","((Magnet_Main:tr1)+(Magnet_Ends:tr2)+(Magnet_Ends:tr3))");

  Magnet_Volume = new TGeoVolume("Magnet_Volume",Magnet_Assembly,Magnet_Medium);
}

MagnetConstruction::MagnetConstruction(double X,double Y,double Z,double ends,double gap)
{

  Magnet_MaterialName = "Iron";
  Magnet_Mass = 55.85;
  Magnet_Charge = 26;
  Magnet_Density = 7.87;

  Magnet_Material = new TGeoMaterial(Magnet_MaterialName.c_str(),Magnet_Mass,Magnet_Charge,Magnet_Density);
  Magnet_Medium = new TGeoMedium(Magnet_MaterialName.c_str(),1,Magnet_Material);

  //X will be the thickness
  Magnet_X = X;
  Magnet_Y = Y;
  Magnet_Z = Z;
  
  Magnet_Thickness = Magnet_X;
  //for horse shoe need extra parameter which governs ends
  Magnet_End = ends;
  //another parameter to induce a gap between magnets that would arise from real construction
  Magnet_Gap = gap;

  //translations
  tr1 = new TGeoTranslation("tr1",0,0,0);
  tr2 = new TGeoTranslation("tr2",(Magnet_End - Magnet_Gap)/2.0,(Magnet_Y + Magnet_Thickness)/2.0,0);
  tr3 = new TGeoTranslation("tr3",(Magnet_End - Magnet_Gap)/2.0,-(Magnet_Y + Magnet_Thickness)/2.0,0);
  tr1->RegisterYourself();
  tr2->RegisterYourself();
  tr3->RegisterYourself();

  Magnet_Main = new TGeoBBox("Magnet_Main",Magnet_Thickness/2.0,Magnet_Y/2.0,Magnet_Z/2.0);
  Magnet_Ends = new TGeoBBox("Magnet_Ends",(Magnet_End + Magnet_Thickness - Magnet_Gap)/2.0,Magnet_Thickness/2.0,Magnet_Z/2.0);

  Magnet_Assembly = new TGeoCompositeShape("Magnet_Assembly","((Magnet_Main:tr1+Magnet_Ends:tr2+Magnet_Ends:tr3))");

  Magnet_Volume = new TGeoVolume("Magnet_Volume",Magnet_Assembly,Magnet_Medium);


}

MagnetConstruction::~MagnetConstruction()
{
  delete Magnet_Material;
  delete Magnet_Medium;
  delete Magnet_Main;
  delete Magnet_Ends;
  delete Magnet_Assembly;
  delete Magnet_Volume;

}
