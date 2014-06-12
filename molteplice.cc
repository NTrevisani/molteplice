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
//
// $Id: exampleN01.cc,v 1.6 2006-06-29 17:47:10 gunter Exp $
// GEANT4 tag $Name: geant4-09-04-patch-02 $
//
// 
// --------------------------------------------------------------
//      GEANT 4 - exampleN01
// --------------------------------------------------------------

#include "ExN01EventAction.hh"
#include "ExN01CreateTree.hh"

#include <vector>
#include <map>
#include "B4Analysis.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"

//#include "TCint.h"

#include "ExN01DetectorConstruction.hh"
#include "ExN01PhysicsList.hh"
#include "ExN01PrimaryGeneratorAction.hh"

#include "ExN01SteppingAction.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#include "ExN01VisAction.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

using namespace CLHEP;

int main(int argc,char** argv)
{
  // Construct the default run manager
  //
  G4RunManager* runManager = new G4RunManager;

  // set mandatory initialization classes
  //
  G4VUserDetectorConstruction* detector = new ExN01DetectorConstruction;
  runManager->SetUserInitialization(detector);
  //
  G4VUserPhysicsList* physics = new ExN01PhysicsList;
  runManager->SetUserInitialization(physics);

  
/*
//GRAFICA - PRIMA INSERZIONE
  #ifdef G4VIS_USE
  // Visualization, if you choose to have it!
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  // Set User Vis Action...
  visManager->SetUserAction
    (new UVA_VisAction, G4VisExtent(-1*m,1*m,-2*m,0,3.5*m,5.5*m));
  // 2nd argument optional - overridden by /vis/scene/add/userAction
  // arguments, if any.
  #endif
//**************************
*/
     
  // set mandatory user action class
  //
  G4VUserPrimaryGeneratorAction* gen_action = new ExG4PrimaryGeneratorAction01;
  runManager->SetUserAction(gen_action);

//  int cont = 0;

  // Create analysis manager
  //G4AnalysisManager* man = G4AnalysisManager::Instance();
	
  // Creating histogram 
  //man->CreateH1("1","Energy Left", 500, 0., 500*MeV);

  //Creating Tree
    CreateTree* mytree = new CreateTree ("tree") ;  
    //CreateTree::Instance() -> attenuationLengths -> Fill();
 
 

//G4cout << ">>> Define EventAction::begin <<<" << G4endl;
  G4UserEventAction* event_action = new EventAction();//printModulo);
  runManager->SetUserAction(event_action);
//  G4cout << ">>> Define EventAction::end <<<" << G4endl; 

    
  G4UserSteppingAction* stpAct = new SteppingAction();
  runManager->SetUserAction(stpAct);
  
      std::cout<<"sono qui!!!!!! :) :) :) :) :) :)"<<std::endl;
  
  
  // Initialize G4 kernel
  //
  runManager->Initialize();

/*
//GRAFICA - SECONDA INSERZIONE
  //get the pointer to the User Interface manager 
  G4UImanager * UImanager = G4UImanager::GetUIpointer();  

  if(argc==1)
#ifdef G4UI_USE
  // Define (G)UI terminal for interactive mode  
  { 
    G4UIExecutive * ui = new G4UIExecutive(argc, argv);
    UImanager->ApplyCommand("/control/execute vis.mac");    
    ui->SessionStart();
    delete ui;
#endif
  }
  else
  // Batch mode
  { 
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }

  #ifdef G4VIS_USE
  delete visManager;
  #endif

//***********************************
*/

  // Get the pointer to the UI manager and set verbosities
  //
  G4UImanager* UI = G4UImanager::GetUIpointer();
  UI->ApplyCommand("/run/verbose 0");
  UI->ApplyCommand("/event/verbose 0");
  UI->ApplyCommand("/tracking/verbose 0");


  // Start a run
  //
  G4int numberOfEvent = 15000;
  runManager->BeamOn(numberOfEvent);


  TFile *output = new TFile("molteplice.root","RECREATE");
  mytree->Write(output);
  output->Close();
  // Job termination
  //
  // Free the store: user actions, physics_list and detector_description are
  //                 owned and deleted by the run manager, so they should not
  //                 be deleted in the main() program !
  //
  delete runManager;

  return 0;
}


