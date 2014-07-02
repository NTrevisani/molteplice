#include "ExN01CreateTree.hh"
#include <algorithm>
#include <vector>

using namespace std ;

CreateTree* CreateTree::fInstance = NULL ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


CreateTree::CreateTree (TString name)
                        //,const std::vector<float>& attL)
{
  if ( fInstance )
  {
    return ;
  }


  this->fInstance = this ;
  this->fname     = name ;
  this->ftree     = new TTree (name,name) ;
  
  this->ftree->SetDirectory(0);

  ID = new std::vector<int> () ;  

  this->GetTree ()->Branch ("Event", &this->Event, "Event/I") ;
  
  this->GetTree ()->Branch ("n_ioni_0", &this->n_ioni_0, "n_ioni_0/I") ;
  position_0 = new vector<float> () ;
  this->GetTree ()->Branch ("position_0","vector<float>",&position_0) ;
  this->GetTree ()->Branch ("number_0", &this->number_0, "number_0/I") ;
  this->GetTree ()->Branch ("number_0_out", &this->number_0_out, "number_0_out/I") ;
  this->GetTree ()->Branch ("NumberEscaped_0", &this->NumberEscaped_0, "NumberEscaped_0/I") ;  
  this->GetTree ()->Branch ("EnergyTotal_0", &this->EnergyTotal_0, "EnergyTotal_0/F") ;
  this->GetTree ()->Branch ("EnergyTotal_0_all", &this->EnergyTotal_0_all, "EnergyTotal_0_all/F") ;
  Energies_0 = new vector<float> () ;
  this->GetTree ()->Branch ("Energies_0","vector<float>",&Energies_0) ;
  this->GetTree ()->Branch ("TrackLenght_0", &this->TrackLenght_0, "TrackLenght_0/F") ;
  this->GetTree ()->Branch ("StepLenght_0", &this->StepLenght_0, "StepLenght_0/F") ;    

  this->GetTree ()->Branch ("number_3", &this->number_3, "number_3/I") ;
  this->GetTree ()->Branch ("number_3_out", &this->number_3_out, "number_3_out/I") ;
  this->GetTree ()->Branch ("EnergyTotal_3", &this->EnergyTotal_3, "EnergyTotal_3/F") ;
  this->GetTree ()->Branch ("EnergyTotal_3_all", &this->EnergyTotal_3_all, "EnergyTotal_3_all/F") ;
  Energies_3 = new vector<float> () ;
  this->GetTree ()->Branch ("Energies_3","vector<float>",&Energies_3) ;
  this->GetTree ()->Branch ("TrackLenght_3", &this->TrackLenght_3, "TrackLenght_3/F") ;  
  this->GetTree ()->Branch ("StepLenght_3", &this->StepLenght_3, "StepLenght_3/F") ;    
    
  this->GetTree ()->Branch ("number_10", &this->number_10, "number_10/I") ;  
  this->GetTree ()->Branch ("number_10_out", &this->number_10_out, "number_10_out/I") ;
  this->GetTree ()->Branch ("EnergyTotal_10", &this->EnergyTotal_10, "EnergyTotal_10/F") ;
  this->GetTree ()->Branch ("EnergyTotal_10_all", &this->EnergyTotal_10_all, "EnergyTotal_10_all/F") ;
  Energies_10 = new vector<float> () ;
  this->GetTree ()->Branch ("Energies_10","vector<float>",&Energies_10) ;
  this->GetTree ()->Branch ("TrackLenght_10", &this->TrackLenght_10, "TrackLenght_10/F") ;  
  this->GetTree ()->Branch ("StepLenght_10", &this->StepLenght_10, "StepLenght_10/F") ;    
      
  this->GetTree ()->Branch ("number_30", &this->number_30, "number_30/I") ;  
  this->GetTree ()->Branch ("number_30_out", &this->number_30_out, "number_30_out/I") ;
  this->GetTree ()->Branch ("EnergyTotal_30", &this->EnergyTotal_30, "EnergyTotal_30/F") ;
  this->GetTree ()->Branch ("EnergyTotal_30_all", &this->EnergyTotal_30_all, "EnergyTotal_30_all/F") ;
  Energies_30 = new vector<float> () ;
  this->GetTree ()->Branch ("Energies_30","vector<float>",&Energies_30) ;
  this->GetTree ()->Branch ("TrackLenght_30", &this->TrackLenght_30, "TrackLenght_30/F") ;  
  this->GetTree ()->Branch ("StepLenght_30", &this->StepLenght_30, "StepLenght_30/F") ;    
      
  this->GetTree ()->Branch ("number_100", &this->number_100, "number_100/I") ;  
  this->GetTree ()->Branch ("number_100_out", &this->number_100_out, "number_100_out/I") ;
  this->GetTree ()->Branch ("EnergyTotal_100", &this->EnergyTotal_100, "EnergyTotal_100/F") ;
  this->GetTree ()->Branch ("EnergyTotal_100_all", &this->EnergyTotal_100_all, "EnergyTotal_100_all/F") ;
  Energies_100 = new vector<float> () ;
  this->GetTree ()->Branch ("Energies_100","vector<float>",&Energies_100) ;
  this->GetTree ()->Branch ("TrackLenght_100", &this->TrackLenght_100, "TrackLenght_100/F") ;  
  this->GetTree ()->Branch ("StepLenght_100", &this->StepLenght_100, "StepLenght_100/F") ;    
  
  this->Clear () ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


CreateTree::~CreateTree ()
{}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int CreateTree::Fill () 
{ 
  return this->GetTree ()->Fill () ; 
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


void CreateTree::Write (TFile * outfile)
{
  outfile->cd () ;
  ftree->Write () ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


void CreateTree::Clear ()
{
  Event	= 0 ;

  ID->clear();
  position_0->clear();
  n_ioni_0 = 0;
    
  number_0 = 0 ;
  number_0_out = 0 ;
  NumberEscaped_0 = 0;
  EnergyTotal_0 = 0. ;
  EnergyTotal_0_all = 0. ;
  Energies_0->clear () ;
  TrackLenght_0 = 0.;
  StepLenght_0 = 0. ;  
  
  number_3 = 0 ;
  number_3_out = 0 ;
  EnergyTotal_3 = 0. ;
  EnergyTotal_3_all = 0. ;
  Energies_3->clear () ;
  TrackLenght_3 = 0.;
  StepLenght_3 = 0. ;    
  
  number_10 = 0 ;
  number_10_out = 0 ;
  EnergyTotal_10 = 0. ;
  EnergyTotal_10_all = 0. ;
  Energies_10->clear () ;
  TrackLenght_10 = 0.;
  StepLenght_10 = 0. ;  
    
  number_30 = 0 ;
  number_30_out = 0 ;
  EnergyTotal_30 = 0. ;
  EnergyTotal_30_all = 0. ;
  Energies_30->clear () ;
  TrackLenght_30 = 0.;
  StepLenght_30 = 0. ;  
    
  number_100 = 0 ;
  number_100_out = 0 ;
  EnergyTotal_100 = 0. ;
  EnergyTotal_100_all = 0. ;
  Energies_100->clear () ;
  TrackLenght_100 = 0.;
  StepLenght_100 = 0. ;  
}
