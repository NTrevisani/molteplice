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


using namespace std ;

SteppingAction::SteppingAction()
	{
	}

SteppingAction::~SteppingAction()
	{
	}	

void SteppingAction::UserSteppingAction( const G4Step * theStep ) 
	{
	//get the two points of a step
	G4StepPoint* point1 = theStep->GetPreStepPoint();
	G4StepPoint* point2 = theStep->GetPostStepPoint();
    
    //get the particle involved in the step	
	G4ParticleDefinition* particle = theStep->GetTrack()->GetDefinition(); 

    //get the name of the volume in which the particles is at the beginning of the step
	G4TouchableHandle touch1 = point1->GetTouchableHandle();
	G4VPhysicalVolume* pre_volume = touch1->GetVolume();
    G4String pre_volName = "" ; if ( pre_volume ) pre_volName = pre_volume -> GetName () ;

    //get the name of the volume in which the particles is at the end of the step
   	G4TouchableHandle touch2 = point2->GetTouchableHandle();
   	G4VPhysicalVolume* post_volume = touch2->GetVolume();
    G4String post_volName = "" ; if ( post_volume ) post_volName = post_volume -> GetName () ;


        if ( pre_volName == "World")
		{
       			if ( particle->GetParticleName() == "e-" || particle->GetParticleName() == "e+" )
               	if ( post_volName == "Det" || post_volName == "Out")
               	{
               	CreateTree::Instance() -> number_0_out += 1 ;
               	    if ( theStep->GetTrack()->GetKineticEnergy() > 3*MeV )        //set thresholds
            		{
            		CreateTree::Instance() -> number_3_out += 1 ;
            		    if ( theStep->GetTrack()->GetKineticEnergy() > 10*MeV )        //set thresholds
            		    {
            		    CreateTree::Instance() -> number_10_out += 1 ;
            		        if ( theStep->GetTrack()->GetKineticEnergy() > 30*MeV )        //set thresholds
            		        {
            		        CreateTree::Instance() -> number_30_out += 1 ;
            		            if ( theStep->GetTrack()->GetKineticEnergy() > 30*MeV )        //set thresholds
            		            {
            		            CreateTree::Instance() -> number_100_out += 1 ;
            		            }
            		        }    
            		    }
            		}
            	}
               	if ( post_volName == "Det" )	    //particle passes from world to detector -> it survives
        		{
        		CreateTree::Instance() -> EnergyTotal_0_all += theStep->GetTrack()->GetKineticEnergy();     ////saving the sum of all the particles
        		    if ( particle->GetParticleName() == "e-" || particle->GetParticleName() == "e+" )
                    {
   			        //int aaa = theStep->GetTrack()->GetTrackID();
   			        //CreateTree::Instance() -> ID -> push_back(aaa);
   			        CreateTree::Instance() -> Energies_0 -> push_back( theStep->GetTrack()->GetKineticEnergy() );  //saving particle energy
   			        CreateTree::Instance() -> EnergyTotal_0 += theStep->GetTrack()->GetKineticEnergy();       //saving the sum of all the charged particles
   			        CreateTree::Instance() -> number_0 += 1 ;                                                      //saving the number of survived tracks 
			        }
			        if ( theStep->GetTrack()->GetKineticEnergy() > 3*MeV )        //set thresholds
            		{
            		CreateTree::Instance() -> EnergyTotal_3_all += theStep->GetTrack()->GetKineticEnergy();    
            		    if ( particle->GetParticleName() == "e-" || particle->GetParticleName() == "e+" )
            		    {
       			        CreateTree::Instance() -> Energies_3 -> push_back( theStep->GetTrack()->GetKineticEnergy() );
       			        CreateTree::Instance() -> EnergyTotal_3 += theStep->GetTrack()->GetKineticEnergy();
       			        CreateTree::Instance() -> number_3 += 1 ;
    			        }
    			        if ( theStep->GetTrack()->GetKineticEnergy() > 10*MeV )
            		    {
           			    CreateTree::Instance() -> EnergyTotal_10_all += theStep->GetTrack()->GetKineticEnergy();    
           			        if ( particle->GetParticleName() == "e-" || particle->GetParticleName() == "e+" )
           			        {
           			        CreateTree::Instance() -> Energies_10 -> push_back( theStep->GetTrack()->GetKineticEnergy() );
           			        CreateTree::Instance() -> EnergyTotal_10 += theStep->GetTrack()->GetKineticEnergy();
           			        CreateTree::Instance() -> number_10 += 1 ;
		                    }
		                    if ( theStep->GetTrack()->GetKineticEnergy() > 30*MeV )
            		        {
       			            CreateTree::Instance() -> EnergyTotal_30_all += theStep->GetTrack()->GetKineticEnergy();    
       			                if ( particle->GetParticleName() == "e-" || particle->GetParticleName() == "e+" )
       			                {
       			                CreateTree::Instance() -> Energies_30 -> push_back( theStep->GetTrack()->GetKineticEnergy() );
       			                CreateTree::Instance() -> EnergyTotal_30 += theStep->GetTrack()->GetKineticEnergy();
       			                CreateTree::Instance() -> number_30 += 1 ;
    		                    }
    		                    if ( theStep->GetTrack()->GetKineticEnergy() > 100*MeV )
                		        {
                		        CreateTree::Instance() -> EnergyTotal_100_all += theStep->GetTrack()->GetKineticEnergy();    
                		            if ( particle->GetParticleName() == "e-" || particle->GetParticleName() == "e+" )
                		            {
           			                CreateTree::Instance() -> Energies_100 -> push_back( theStep->GetTrack()->GetKineticEnergy() );
           			                CreateTree::Instance() -> EnergyTotal_100 += theStep->GetTrack()->GetKineticEnergy();
           			                CreateTree::Instance() -> number_100 += 1 ;
           			                }
                                }
                            }
                        }
                    }
                }                                                               
		}
		if ( pre_volName == "mcp" )
		if ( particle->GetParticleName() == "e-" || particle->GetParticleName() == "e+" )
		{
		CreateTree::Instance() -> TrackLenght_0 += theStep->GetTrack()->GetTrackLength();
		CreateTree::Instance() -> StepLenght_0 += theStep->GetStepLength();
        G4String padre = "eIoni";
		
	        //if ( post_volName == "Out" || post_volName == "World" )     CreateTree::Instance() -> NumberEscaped_0 += 1 ;   
	            
   	            if ( theStep->GetTrack()->GetCurrentStepNumber() == 1 )
                    //{
                    //if ( post_volName != "Out" && post_volName != "World" )  
	                    //{
                    if ( theStep->GetTrack()->GetCreatorProcess()->GetProcessName() == "eIoni")//padre)     
                        //if ( theStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName() == padre)
                        //for (int i = 0; i < CreateTree::Instance() -> ID -> size(); ++i )
	                      //  {
	                        //if ( theStep->GetTrack()->GetTrackID() == CreateTree::Instance() -> ID -> at(i) )
	                           // {
	                            CreateTree::Instance() -> n_ioni_0 += 1;
	                            //cout<<CreateTree::Instance() -> n_ioni_0<<endl;
	                            //CreateTree::Instance() -> ID -> erase ( CreateTree::Instance() -> ID -> begin () + i );
	                            //continue;
	                            //}
	                        /*
	                        if ( theStep->GetTrack()->GetParentID() == CreateTree::Instance() -> ID -> at(i) ) 
	                            {
	                            cout<< theStep->GetTrack()->GetPosition().z()<<endl;
	                            CreateTree::Instance() -> position_0 -> push_back( theStep->GetTrack()->GetPosition().z() );
	                            CreateTree::Instance() -> n_ioni_0 += 1;
	                            //CreateTree::Instance() -> ID -> erase ( CreateTree::Instance() -> ID -> begin () + i );
	                            }
	                        //}*/
	                    //}
	                //}
	            
	        if ( theStep->GetTrack()->GetKineticEnergy() > 3*MeV )
            {	    
       		CreateTree::Instance() -> TrackLenght_3 += theStep->GetTrack()->GetTrackLength();
       		CreateTree::Instance() -> StepLenght_3 += theStep->GetStepLength();
		        if ( theStep->GetTrack()->GetKineticEnergy() > 10*MeV )
                {	    
           		CreateTree::Instance() -> TrackLenght_10 += theStep->GetTrack()->GetTrackLength();
        		CreateTree::Instance() -> StepLenght_10 += theStep->GetStepLength();
                    if ( theStep->GetTrack()->GetKineticEnergy() > 30*MeV )
                    {	    
       		        CreateTree::Instance() -> TrackLenght_30 += theStep->GetTrack()->GetTrackLength();
            		CreateTree::Instance() -> StepLenght_30 += theStep->GetStepLength();
               	        if ( theStep->GetTrack()->GetKineticEnergy() > 100*MeV )
                        {	    
                   		CreateTree::Instance() -> TrackLenght_100 += theStep->GetTrack()->GetTrackLength();
                		CreateTree::Instance() -> StepLenght_100 += theStep->GetStepLength();
                        }
                    }
                }
            }
        }  
	}
