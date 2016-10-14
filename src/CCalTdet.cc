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
// File: CCalTdet.cc
// Description: CCalEcal Geometry factory class for timing detector
///////////////////////////////////////////////////////////////////////////////
#include "CCalTdet.hh"

#include <fstream>
#include "CCalutils.hh"

//#define debug

CCalTdet::~CCalTdet() {}

int CCalTdet::readFile() {
  ///////////////////////////////////////////////////////////////
  //Let's open the file
  G4cout << " ==> Opening file " << File() << " to read elements..."
       << G4endl;

  std::ifstream is;
  bool ok = openGeomFile(is, pathName, File());
  
  if (!ok)
    return 0;

  // Find *DO TimingDetector
  findDO(is, G4String("TimingDetector"));

  //Let's read the timing detector parameters
  readName(is,timeMat_Abs);
  is  >> dyTime_Abs >> dzTime_Abs >> XPOS_Abs >> N_radiation_length_Abs;
  readName(is,timeMat_Sens);
  is  >> dyTime_Sens >> dzTime_Sens >> XPOS_Sens >> N_radiation_length_Sens >> jump ;
  
  std::cout << " ==> TT absorber detector dimensions read " << "," << dyTime_Abs << "," << dzTime_Abs
       << std::endl;
  std::cout << " ==> TT sensitive detector dimensions read " << "," << dyTime_Sens << "," << dzTime_Sens
       << std::endl;
   
  ///////////////////////////////////////////////////////////////
  // Close the file
  G4cout << " ==> Closing file " << File() << G4endl;
  is.close();

  return 1;

}

void CCalTdet::constructDaughters() {}
