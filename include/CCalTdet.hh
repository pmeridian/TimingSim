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
// File: CCalTdet.hh
// Description: CCalEcal Geometry factory class for timing detector
///////////////////////////////////////////////////////////////////////////////
#ifndef CCalTdet_h
#define CCalTdet_h 1

#include "CCalDetector.hh"

class CCalTdet: public CCalDetector {
public:
  //Constructor and Destructor
  CCalTdet(const G4String &name):
    CCalDetector(name) {}
  virtual ~CCalTdet();

  //Get Methods
  G4String getTimeMatAbs()		     const {return timeMat_Abs;}
  double getDyTimeAbs()		     const {return dyTime_Abs;}
  double getDzTimeAbs()		     const {return dzTime_Abs;}
  double getXPOSAbs()                   const {return XPOS_Abs;}
  double getNRadiationLengthAbs()       const {return N_radiation_length_Abs;}

  G4String getTimeMatSens()		     const {return timeMat_Sens;}
  double getDyTimeSens()		     const {return dyTime_Sens;}
  double getDzTimeSens()		     const {return dzTime_Sens;}
  double getXPOSSens()                   const {return XPOS_Sens;}
  double getNRadiationLengthSens()       const {return N_radiation_length_Sens;}


protected:
  virtual int readFile();
  virtual void constructDaughters();

private:
  G4String timeMat_Abs ;			      //Material of timing detector
  G4String timeMat_Sens ;			      //Material of timing detector
  double dyTime_Abs, dzTime_Abs;                      //Dimensions of timing detector
  double dyTime_Sens, dzTime_Sens;                      //Dimensions of timing detector
  double XPOS_Abs,XPOS_Sens;                                //Distance between timing detector and ecal
  double N_radiation_length_Abs;                  //Thickness defined using number of radiation lengths of material
  double N_radiation_length_Sens;                  //Thickness defined using number of radiation lengths of material

};

#endif
















