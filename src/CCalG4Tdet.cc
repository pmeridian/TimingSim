//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
///////////////////////////////////////////////////////////////////////////////
// File: CCalG4Tdet.cc
// Description: CCalG4Tdet Factory class to construct the G4 geometry of the
//              timing detector
///////////////////////////////////////////////////////////////////////////////

#include <cmath>

#include "CCalG4Tdet.hh"
#include "CCalEcal.hh"


#include "CCalMaterialFactory.hh"
#include "CCalRotationMatrixFactory.hh"
#include "CCalSensitiveDetectors.hh"

#include "CCalutils.hh"

#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4Box.hh"
#include "G4Trd.hh"

#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

//#define debug
//#define ddebug
//#define pdebug
//#define sdebug


//Initialize static prefix name
G4String CCalG4Tdet::idName = "TimingDetector";

////////////////////////////////////////////////////////////////////
// CCalG4Tdet constructor & destructor...
////////////////////////////////////////////////////////////////////

CCalG4Tdet::CCalG4Tdet(const G4String &name):
  CCalTdet(name), CCalG4Able(name) {}

CCalG4Tdet::~CCalG4Tdet() {}

////////////////////////////////////////////////////////////////////
// CCalG4Tdet methods...
////////////////////////////////////////////////////////////////////

G4VPhysicalVolume* CCalG4Tdet::constructIn(G4VPhysicalVolume* mother) {
  G4cout << "==>> Constructing CCalG4Tdet..." << G4endl;
  
  //Getting the rotation and materials
  //CCalRotationMatrixFactory* rotfact = CCalRotationMatrixFactory::getInstance();
  CCalMaterialFactory* matfact = CCalMaterialFactory::getInstance();
  
  //Actual construction of the timing detector
  G4String name("Null");
  double radiation_length = 0.3504*cm;
  nameAbs = "TimeAbs";
  G4Material* matterAbs = matfact->findMaterial(getTimeMatAbs());
  G4VSolid* solidAbs = new G4Box (name, 0.5*getNRadiationLengthAbs()*radiation_length, 0.5*getDyTimeAbs()*mm, 0.5*getDzTimeAbs()*mm);
  G4LogicalVolume* tlogAbs = new G4LogicalVolume (solidAbs, matterAbs, nameAbs);
  setVisType(CCalVisualisable::Sensitive,tlogAbs);
  G4double xpAbs = (-232-1033-getXPOSAbs()-0.5*getNRadiationLengthAbs()*radiation_length-9.)*mm;
  G4PVPlacement* timingdetAbs = new G4PVPlacement(0, G4ThreeVector(xpAbs,0,0),tlogAbs,nameAbs,mother->GetLogicalVolume(),false, 0);

  nameSens = "TimeSens";
  G4Material* matterSens = matfact->findMaterial(getTimeMatSens());
  G4VSolid* solidSens = new G4Box (name, 0.5*getNRadiationLengthSens()*radiation_length, 0.5*getDyTimeSens()*mm, 0.5*getDzTimeSens()*mm);
  G4LogicalVolume* tlogSens = new G4LogicalVolume (solidSens, matterSens, nameSens);
  setVisType(CCalVisualisable::Sensitive,tlogSens);
  G4double xpSens = (-232-1033-getXPOSSens()-0.5*getNRadiationLengthSens()*radiation_length-9.)*mm;
  G4PVPlacement* timingdetSens = new G4PVPlacement(0, G4ThreeVector(xpSens,0,0),tlogSens,nameSens,mother->GetLogicalVolume(),false, 0);


  return timingdet;

}
  

			  
