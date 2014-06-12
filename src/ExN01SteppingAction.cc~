/**
* @file   SteppingAction.cc
*
* @date   17 Dec 2009
* @author adotti
*
* @brief  Implements user class SteppingAction.
*/
#include <vector>

#include "ExN01CreateTree.hh"
#include "B4Analysis.hh"
#include "LinkDef.h"
#include "ExN01SteppingAction.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4SteppingManager.hh"
#include "G4UnitsTable.hh"


SteppingAction::SteppingAction()
	{
  	// Create analysis manager
//  	G4AnalysisManager* man = G4AnalysisManager::Instance();
//  	man->CreateH1("1","Energy Left", 500, 0., 500*MeV);	
	}

SteppingAction::~SteppingAction()
	{
	//delete G4AnalysisManager::Instance();
	}	

void SteppingAction::UserSteppingAction( const G4Step * theStep ) 
	{
	//recall (or define (??)) histogram
	//G4AnalysisManager* man = G4AnalysisManager::Instance();
	
	//track informations
	G4StepPoint* point1 = theStep->GetPreStepPoint();
	G4StepPoint* point2 = theStep->GetPostStepPoint();
	G4ParticleDefinition* particle = theStep->GetTrack()->GetDefinition(); 
    const G4DynamicParticle* din = theStep->GetTrack()->GetDynamicParticle(); 	

	G4TouchableHandle touch1 = point1->GetTouchableHandle();
	G4VPhysicalVolume* pre_volume = touch1->GetVolume();
    G4String pre_volName = "" ; if ( pre_volume ) pre_volName = pre_volume -> GetName () ;
//	G4String pre_volName = pre_volume->GetName();

		if ( particle->GetParticleName() == "e-" || particle->GetParticleName() == "e+" )
        if ( pre_volName == "World")
		{
		G4TouchableHandle touch2 = point2->GetTouchableHandle();
		G4VPhysicalVolume* post_volume = touch2->GetVolume();
//		G4String post_volName = post_volume->GetName();
        G4String post_volName = "" ; if ( post_volume ) post_volName = post_volume -> GetName () ;
//		std::cout<<post_volName<<std::endl;
       	 		//std::cout<<"FORSE ATTRAVERSO!!!!!!!"<<std::endl;	
               	if ( post_volName == "Det" )	    //particle passes from world to detector -> it survives
        		{
   			    CreateTree::Instance() -> depositedEnergies_0 -> push_back( theStep->GetTrack()->GetKineticEnergy() );
   			    CreateTree::Instance() -> depositedEnergyTotal_0 += theStep->GetTrack()->GetKineticEnergy();
   			    CreateTree::Instance() -> number_0 += 1 ;
			        if ( theStep->GetTrack()->GetKineticEnergy() > 3*MeV )        //set threshold
            		{
       			    CreateTree::Instance() -> depositedEnergies_3 -> push_back( theStep->GetTrack()->GetKineticEnergy() );
       			    CreateTree::Instance() -> depositedEnergyTotal_3 += theStep->GetTrack()->GetKineticEnergy();
       			    CreateTree::Instance() -> number_3 += 1 ;
    			        if ( theStep->GetTrack()->GetKineticEnergy() > 10*MeV )        //set a threshold
            		    {
           			    CreateTree::Instance() -> depositedEnergies_10 -> push_back( theStep->GetTrack()->GetKineticEnergy() );
           			    CreateTree::Instance() -> depositedEnergyTotal_10 += theStep->GetTrack()->GetKineticEnergy();
           			    CreateTree::Instance() -> number_10 += 1 ;
		                    if ( theStep->GetTrack()->GetKineticEnergy() > 30*MeV )        //set a threshold
            		        {
       			            CreateTree::Instance() -> depositedEnergies_30 -> push_back( theStep->GetTrack()->GetKineticEnergy() );
       			            CreateTree::Instance() -> depositedEnergyTotal_30 += theStep->GetTrack()->GetKineticEnergy();
       			            CreateTree::Instance() -> number_30 += 1 ;
    		                    if ( theStep->GetTrack()->GetKineticEnergy() > 100*MeV )        //set a threshold
                		        {
           			            CreateTree::Instance() -> depositedEnergies_100 -> push_back( theStep->GetTrack()->GetKineticEnergy() );
           			            CreateTree::Instance() -> depositedEnergyTotal_100 += theStep->GetTrack()->GetKineticEnergy();
           			            CreateTree::Instance() -> number_100 += 1 ;
                                }
                            }
                        }
                    }
                }                                                               
		}
	}
