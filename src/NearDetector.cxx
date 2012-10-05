//
// Title: Root Geometry for the Near Detector
//
// Description: to be written
//
// Author: Tom Stainer
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoManager.h"
#include "TSystem.h"
#include "TGeoVolume.h"
#include "TGeoMatrix.h"
#include "TGeoVolumeEditor.h"
//#include "Utils/CmdLnArgParser.h"

#include "TPCFiducialConstruction.hh"

#include "TPCEnclosureConstructionX.hh"
#include "TPCEnclosureConstructionY.hh"
#include "TPCEnclosureConstructionZ.hh"

#include "TASFiducialConstructionX.hh"
#include "TASFiducialConstructionY.hh"
#include "TASFiducialConstructionZ.hh"

#include "TASEnclosureConstructionX.hh"
#include "TASEnclosureConstructionY.hh"
#include "TASEnclosureConstructionZ.hh"

#include "ECALConstruction.hh"
#include "HCALConstruction.hh"

#include "MagnetConstruction.hh"

#include "MINDConstruction.hh"

#include "CavityConstruction.hh"

#include "NearDetector.hh"
#include "RockConstruction.hh"

//filename
std::string fOutFilename = "outputFiles/ND_geometry.root";

//free parameters for geometry (in meters)
double fRock_r = 30;
double fRock_z = 80;
double fRock_density = 2.323e-12;

double fTPCFiducial_x = 2;
double fTPCFiducial_y = 2;
double fTPCFiducial_z = 6;
double fTPCFiducial_density = 18.0e-3;

double fTPCEnclosure_thickness = 0.005;
double fTASFiducial_thickness = 0.5;

//ignore TASEnclosure for current model - set to 0 thickness
double fTASEnclosure_thickness = 0.00;

double fECALScint_thickness = 0.01;
double fECALSep_thickness = 0.005;
int fECALScint_layers = 35;

double fHCALScint_thickness = 0.01;
double fHCALSep_thickness = 0.02;
int fHCALScint_layers = 50;

double fMagnet_thickness = 0.0;
double fMagnet_gap = 0.1;

double fMIND_x = 6;
double fMIND_y = 6;
double fMIND_z = 8;
double fMIND_gap = 0.0;

double fCavity_gap = 1.0;
//___________________________________________________________________
int main()
{

  //load the geometry library
  TSystem * system = new TSystem("system");
  system->Load("libGeom"); 
  
  TGeoManager * geom = new TGeoManager("geom","Near Detector");
  
  //---------------------detector constructors-----------------------
  //ROCK
  Rock = new RockConstruction(fRock_z,fRock_r);
  Rock->SetDensity(fRock_density);

  //TPC FiDUCIAL
  TPCFiducial = new TPCFiducialConstruction(fTPCFiducial_x,fTPCFiducial_y,fTPCFiducial_z);
  TPCFiducial->SetMaterial("ArgonGas",39.95,18,fTPCFiducial_density);
  
  //TPC ENCLOSURE
  TPCEnclosureZ = new TPCEnclosureConstructionZ(TPCFiducial,fTPCEnclosure_thickness);
  TPCEnclosureY = new TPCEnclosureConstructionY(TPCFiducial,fTPCEnclosure_thickness);
  TPCEnclosureX = new TPCEnclosureConstructionX(TPCFiducial,fTPCEnclosure_thickness);
 
  //TAS VOLUMES (p denotes positive and n denotes negative)
  TASFiducialZ = new TASFiducialConstructionZ(TPCEnclosureZ,fTASFiducial_thickness);
  TASFiducialY = new TASFiducialConstructionY(TPCEnclosureY,fTASFiducial_thickness);
  TASFiducialX = new TASFiducialConstructionX(TPCEnclosureX,fTASFiducial_thickness);

  //TAS ENCLOSURE
  TASEnclosureZ = new TASEnclosureConstructionZ(TASFiducialZ,fTASEnclosure_thickness);
  TASEnclosureY = new TASEnclosureConstructionY(TASFiducialY,fTASEnclosure_thickness);
  TASEnclosureX = new TASEnclosureConstructionX(TASFiducialX,fTASEnclosure_thickness);

  //ECAL
  ECAL = new ECALConstruction(TASEnclosureZ,TASEnclosureY,TASEnclosureX,TASFiducialX,TASFiducialY,TASFiducialZ,fECALScint_thickness,fECALSep_thickness,fECALScint_layers);
   
  //HCAL 
  HCAL = new HCALConstruction(ECAL,fHCALScint_thickness,fHCALSep_thickness,fHCALScint_layers);

  //Magnet
  Magnet = new MagnetConstruction(fMagnet_thickness,HCAL->GetXPlate_Y() + 2*fHCALSep_thickness,HCAL->GetXPlate_Z(),(HCAL->GetYPlate_X())/2.0, fMagnet_gap);

  //MIND
  MIND = new MINDConstruction(fMIND_x,fMIND_y,fMIND_z);

  //total thickness of ND
  double ND_X = fTPCFiducial_x + 2*fTPCEnclosure_thickness + 2*fTASFiducial_thickness + 2*fTASEnclosure_thickness + 2*ECAL->GetTotalX() + 2*HCAL->GetTotalX() + 2*fMagnet_thickness;
  double ND_Y = fTPCFiducial_y + 2*fTPCEnclosure_thickness + 2*fTASFiducial_thickness + 2*fTASEnclosure_thickness + 2*ECAL->GetTotalY() + 2*HCAL->GetTotalY() + 2*fMagnet_thickness;
  double ND_Z = fTPCFiducial_z + 2*fTPCEnclosure_thickness + 2*fTASFiducial_thickness + 2*fTASEnclosure_thickness + 1*ECAL->GetTotalZ() + 1*HCAL->GetTotalZ();

  //Cavities
  Cavity_ND = new CavityConstruction(ND_X + 2*fCavity_gap,ND_Y + 2*fCavity_gap,ND_Z + 2*fCavity_gap);
  Cavity_MIND = new CavityConstruction(fMIND_x + 2*fCavity_gap,fMIND_y + 2*fCavity_gap,fMIND_z + 2*fCavity_gap);
  
  Cavity_ND->SetVolumeName("Cavity_ND_Volume");
  Cavity_MIND->SetVolumeName("Cavity_MIND_Volume");

  //set rock as the top volume
  geom->SetTopVolume(Rock->GetVolume());

  //set colours of volumes for drawing
  Rock->GetVolume()->SetLineColor(kRed);
  TPCFiducial->GetVolume()->SetLineColor(kBlue);
  TPCEnclosureZ->GetVolume()->SetLineColor(kBlack);
  TPCEnclosureX->GetVolume()->SetLineColor(kBlack);
  TPCEnclosureY->GetVolume()->SetLineColor(kBlack);

 
  TASFiducialZ->GetVolume()->SetLineColor(8);
  TASFiducialY->GetVolume()->SetLineColor(8);
  TASFiducialX->GetVolume()->SetLineColor(8);

  if(fTASEnclosure_thickness==0.0)
    {
      //set to the same colour as the Fiducial to make drawing easier
      TASEnclosureZ->GetVolume()->SetLineColor(8);
      TASEnclosureY->GetVolume()->SetLineColor(8);
      TASEnclosureX->GetVolume()->SetLineColor(8);
    }

  else
    {
      //set it to pink to show up
      TASEnclosureZ->GetVolume()->SetLineColor(6);
      TASEnclosureY->GetVolume()->SetLineColor(6);
      TASEnclosureX->GetVolume()->SetLineColor(6);
    }
 
  //9 is purple
  Magnet->GetVolume()->SetLineColor(9);
  
  MIND->GetVolume()->SetLineColor(11);

  //POSITIONS

  //-------------------------------------Origin Shift in Z------------------------------------------------
  //due to asymmetry of ND in z axis need to displace the origin in Cavity to have an equal surrounding layer of the cavity
  OriginShiftZ = new TGeoTranslation(0,0,(ECAL->GetTotalZ() + HCAL->GetTotalZ())/2.0);

  //-----------------------------TPCEnclosure Plates--------------------------------------
  //plates perp to Z
  TPCEnclosureTr_pZ = new TGeoTranslation(0,0,(TPCFiducial->GetZ() + TPCEnclosureZ->GetThickness())/2.0);
  TPCEnclosureTr_pZ->Add(OriginShiftZ);

  TPCEnclosureTr_nZ = new TGeoTranslation(0,0,-(TPCFiducial->GetZ() + TPCEnclosureZ->GetThickness())/2.0);
  TPCEnclosureTr_nZ->Add(OriginShiftZ);

  //plates perp to Y
  TPCEnclosureTr_pY = new TGeoTranslation(0,(TPCFiducial->GetY() + TPCEnclosureZ->GetThickness())/2.0,0);
  TPCEnclosureTr_pY->Add(OriginShiftZ);

  TPCEnclosureTr_nY = new TGeoTranslation(0,-(TPCFiducial->GetY() + TPCEnclosureZ->GetThickness())/2.0,0);
  TPCEnclosureTr_nY->Add(OriginShiftZ);

  //plates perp to X
  TPCEnclosureTr_pX = new TGeoTranslation((TPCFiducial->GetX()+ TPCEnclosureZ->GetThickness())/2.0,0,0);
  TPCEnclosureTr_pX->Add(OriginShiftZ);

  TPCEnclosureTr_nX = new TGeoTranslation(-(TPCFiducial->GetX()+ TPCEnclosureZ->GetThickness())/2.0,0,0);
  TPCEnclosureTr_nX->Add(OriginShiftZ);

  //-------------------------------TASFiducial Plates-------------------------------------------------------
  //plates perp to Z
  TASFiducialTr_pZ = new TGeoTranslation(0,0,(TPCEnclosureZ->GetThickness() + TASFiducialZ->GetZ())/2.0);
  TASFiducialTr_pZ->Add(TPCEnclosureTr_pZ);

  TASFiducialTr_nZ = new TGeoTranslation(0,0,-(TPCEnclosureZ->GetThickness() + TASFiducialZ->GetZ())/2.0);
  TASFiducialTr_nZ->Add(TPCEnclosureTr_nZ);

  //plates perp to Y
  TASFiducialTr_pY = new TGeoTranslation(0,(TPCEnclosureY->GetY()+ TASFiducialY->GetY())/2.0,0);
  TASFiducialTr_pY->Add(TPCEnclosureTr_pY);

  TASFiducialTr_nY = new TGeoTranslation(0,-(TPCEnclosureY->GetY()+ TASFiducialY->GetY())/2.0,0);
  TASFiducialTr_nY->Add(TPCEnclosureTr_nY);

  //plates perp to X
  TASFiducialTr_pX = new TGeoTranslation((TPCEnclosureX->GetX()+ TASFiducialX->GetX())/2.0,0,0);
  TASFiducialTr_pX->Add(TPCEnclosureTr_pX);

  TASFiducialTr_nX = new TGeoTranslation(-(TPCEnclosureX->GetX()+ TASFiducialX->GetX())/2.0,0,0);
  TASFiducialTr_nX->Add(TPCEnclosureTr_nX);

  //-------------------------------TASEnclosure Plates-------------------------------------------------------
  //plates perp to Z
  TASEnclosureTr_pZ = new TGeoTranslation(0,0,(TASFiducialZ->GetZ() + TASEnclosureZ->GetZ())/2.0);
  TASEnclosureTr_pZ->Add(TASFiducialTr_pZ);

  TASEnclosureTr_nZ = new TGeoTranslation(0,0,-(TASFiducialZ->GetZ() + TASEnclosureZ->GetZ())/2.0);
  TASEnclosureTr_nZ->Add(TASFiducialTr_nZ);

 //plates perp to Y
  TASEnclosureTr_pY = new TGeoTranslation(0,(TASFiducialY->GetY() + TASEnclosureY->GetY())/2.0,0);
  TASEnclosureTr_pY->Add(TASFiducialTr_pY);

  TASEnclosureTr_nY = new TGeoTranslation(0,-(TASFiducialY->GetY() + TASEnclosureY->GetY())/2.0,0);
  TASEnclosureTr_nY->Add(TASFiducialTr_nY);

 //plates perp to X
  TASEnclosureTr_pX = new TGeoTranslation((TASFiducialX->GetX() + TASEnclosureX->GetX())/2.0,0,0);
  TASEnclosureTr_pX->Add(TASFiducialTr_pX);

  TASEnclosureTr_nX = new TGeoTranslation(-(TASFiducialX->GetX() + TASEnclosureX->GetX())/2.0,0,0);
  TASEnclosureTr_nX->Add(TASFiducialTr_nX);

  //----------------------------------------ECAL------------------------------------------------------------
  //plates perp to Z
  ECALTr_nZ = new TGeoTranslation(0,0,-(ECAL->GetScintillatorThickness()+ TASEnclosureZ->GetZ())/2.0);
  ECALTr_nZ->Add(TASEnclosureTr_nZ);

 
  //----------------------------------------HCAL------------------------------------------------------------
  //plates perp to Z
  HCALTr_nZ = new TGeoTranslation(0,0,-(HCAL->GetScintillatorThickness() + 2*ECAL->GetTotalZ() - ECAL->GetScintillatorThickness())/2.0);
  HCALTr_nZ->Add(ECALTr_nZ);

  //---------------------------------------Magnet---------------------------------------------------------
  //plates perp to X
  MagnetTr_pX = new TGeoTranslation((HCAL->GetYPlate_X() + Magnet->GetThickness())/2.0,0, - (Magnet->GetZ() - TPCFiducial->GetZ() - TPCEnclosureX->GetThickness())/2.0 );
  MagnetTr_pX->Add(OriginShiftZ);

  MagnetTr_nX = new TGeoTranslation(-(HCAL->GetYPlate_X() + Magnet->GetThickness())/2.0,0,- (Magnet->GetZ() - TPCFiducial->GetZ() - TPCEnclosureX->GetThickness())/2.0 );
  MagnetTr_nX->Add(OriginShiftZ);

  MagnetRot_pX = new TGeoRotation("MagnetRot_pX",180,0,0);
  MagnetCom_pX = new TGeoCombiTrans(*MagnetTr_pX,*MagnetRot_pX);

  //-------------------------------------MIND----------------------------------------------------------
  //placement
  MINDTr_nZ = new TGeoTranslation(0,0,-( ND_Z + fMIND_z + 4*fCavity_gap + fMIND_gap)/2.0 );
  //MINDTr_nZ->Add(HCALTr_nZ);

  //-------------------------------------------------------------------------------------------------------
  //---------------------------------Add Volumes at nodes---------------------------------------------------
  
  //Add Cavities first
  Rock->GetVolume()->AddNode(Cavity_ND->GetVolume(),1,0);
  Rock->GetVolume()->AddNode(Cavity_MIND->GetVolume(),2,MINDTr_nZ);

  //Add fiducial TPC
  Cavity_ND->GetVolume()->AddNode(TPCFiducial->GetVolume(),1,OriginShiftZ);
  
  //Add TPC plates enclosure
  //Perp to Z plane
  Cavity_ND->GetVolume()->AddNode(TPCEnclosureZ->GetVolume(),1,TPCEnclosureTr_pZ);
  Cavity_ND->GetVolume()->AddNode(TPCEnclosureZ->GetVolume(),2,TPCEnclosureTr_nZ);

  //Perp to Y plane
  Cavity_ND->GetVolume()->AddNode(TPCEnclosureY->GetVolume(),3,TPCEnclosureTr_pY);
  Cavity_ND->GetVolume()->AddNode(TPCEnclosureY->GetVolume(),4,TPCEnclosureTr_nY);

  //Perp to X plane
  Cavity_ND->GetVolume()->AddNode(TPCEnclosureX->GetVolume(),5,TPCEnclosureTr_pX);
  Cavity_ND->GetVolume()->AddNode(TPCEnclosureX->GetVolume(),6,TPCEnclosureTr_nX);
  
  //TAS Fiducial
  Cavity_ND->GetVolume()->AddNode(TASFiducialZ->GetVolume(),1,TASFiducialTr_pZ);
  Cavity_ND->GetVolume()->AddNode(TASFiducialZ->GetVolume(),2,TASFiducialTr_nZ);
  Cavity_ND->GetVolume()->AddNode(TASFiducialY->GetVolume(),3,TASFiducialTr_pY);
  Cavity_ND->GetVolume()->AddNode(TASFiducialY->GetVolume(),4,TASFiducialTr_nY);
  Cavity_ND->GetVolume()->AddNode(TASFiducialX->GetVolume(),5,TASFiducialTr_pX);
  Cavity_ND->GetVolume()->AddNode(TASFiducialX->GetVolume(),6,TASFiducialTr_nX);
  
 
  //TAS Enclosure
  Cavity_ND->GetVolume()->AddNode(TASEnclosureZ->GetVolume(),1,TASEnclosureTr_pZ);
  Cavity_ND->GetVolume()->AddNode(TASEnclosureZ->GetVolume(),2,TASEnclosureTr_nZ);
  Cavity_ND->GetVolume()->AddNode(TASEnclosureY->GetVolume(),3,TASEnclosureTr_pY);
  Cavity_ND->GetVolume()->AddNode(TASEnclosureY->GetVolume(),4,TASEnclosureTr_nY);
  Cavity_ND->GetVolume()->AddNode(TASEnclosureX->GetVolume(),5,TASEnclosureTr_pX);
  Cavity_ND->GetVolume()->AddNode(TASEnclosureX->GetVolume(),6,TASEnclosureTr_nX);
  

  //ECAL Assembly
  Cavity_ND->GetVolume()->AddNode(ECAL->GetVolume(),1,ECALTr_nZ);
    
  //HCAL Assembly
  Cavity_ND->GetVolume()->AddNode(HCAL->GetVolume(),1,HCALTr_nZ);
 
  //Magnet
  Cavity_ND->GetVolume()->AddNode(Magnet->GetVolume(),1,MagnetCom_pX);
  Cavity_ND->GetVolume()->AddNode(Magnet->GetVolume(),2,MagnetTr_nX);
  
  //MIND
  Cavity_MIND->GetVolume()->AddNode(MIND->GetVolume(),1,0);

  //close geometry
  geom->CloseGeometry();

  geom->Export(fOutFilename.c_str());

  std::cout << "\nRoot file created for geometry.\nOutput file is: "<< fOutFilename.c_str() << "\n\n";

  return 0;
}
