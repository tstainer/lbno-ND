//
// Title: Header file for Near detector main file
//
// Author: Tom STainer
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoBBox.h"
#include "TGeoVolume.h"
#include "TGeoMatrix.h"

#include "RockConstruction.hh"
#include "TPCFiducialConstruction.hh"
#include "TPCEnclosureConstruction.hh"
#include "TASFiducialConstruction.hh"
#include "TASEnclosureConstruction.hh"
#include "ECALConstruction.hh"
#include "HCALConstruction.hh"
#include "MagnetConstruction.hh"
#include "MINDConstruction.hh"
#include "CavityConstruction.hh"

#ifndef NearDetector_hh_seen
#define NearDetector_hh_seen

//------------------------Volumes------------------------
RockConstruction * Rock;
TPCFiducialConstruction * TPCFiducial;
TPCEnclosureConstruction * TPCEnclosureZ;
TPCEnclosureConstruction * TPCEnclosureY;
TPCEnclosureConstruction * TPCEnclosureX;
TASFiducialConstruction * TASFiducialZ;
TASFiducialConstruction * TASFiducialY;
TASFiducialConstruction * TASFiducialX;
TASEnclosureConstruction * TASEnclosureZ;
TASEnclosureConstruction * TASEnclosureY;
TASEnclosureConstruction * TASEnclosureX;
ECALConstruction * ECAL;
HCALConstruction * HCAL;
MagnetConstruction * Magnet;
MINDConstruction * MIND;
CavityConstruction * Cavity_ND;
CavityConstruction * Cavity_MIND;

//------------------Translations--------------------------

//positions of TPCEnclosure plates

//plates perp to Z
TGeoTranslation * TPCEnclosureTr_pZ;
TGeoTranslation * TPCEnclosureTr_nZ;

//plates perp to X
TGeoTranslation * TPCEnclosureTr_pX;
TGeoTranslation * TPCEnclosureTr_nX;

//plates perp to Y
TGeoTranslation * TPCEnclosureTr_pY;
TGeoTranslation * TPCEnclosureTr_nY;


//positions of TAS pannels

//plates perp to Z
TGeoTranslation * TASFiducialTr_pZ;
TGeoTranslation * TASFiducialTr_nZ;

//plates perp to Y
TGeoTranslation * TASFiducialTr_pY;
TGeoTranslation * TASFiducialTr_nY;

//plates perp to X
TGeoTranslation * TASFiducialTr_pX;
TGeoTranslation * TASFiducialTr_nX;


//positions of TASEnclosure pannels

//plates perp to Z
TGeoTranslation * TASEnclosureTr_pZ;
TGeoTranslation * TASEnclosureTr_nZ;

//plates perp to Y
TGeoTranslation * TASEnclosureTr_pY;
TGeoTranslation * TASEnclosureTr_nY;

//plates perp to X
TGeoTranslation * TASEnclosureTr_pX;
TGeoTranslation * TASEnclosureTr_nX;

//positions for ECAL
//z plate
TGeoTranslation * ECALTr_nZ;

//y plates
TGeoTranslation * ECALTr_pY;
TGeoTranslation * ECALTr_nY;

//x plates
TGeoTranslation * ECALTr_pX;

//position for HCAL
//z plate
TGeoTranslation * HCALTr_nZ;

//Magnet
TGeoTranslation * MagnetTr_pX;
TGeoTranslation * MagnetTr_nX;
TGeoRotation * MagnetRot_pX;
TGeoCombiTrans * MagnetCom_pX;

//MIND
TGeoTranslation * MINDTr_nZ;

//Origin Shift
TGeoTranslation * OriginShiftZ;

#endif
