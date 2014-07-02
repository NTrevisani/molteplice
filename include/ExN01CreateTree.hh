#ifndef CreateTree_H
#define CreateTree_H 1

#include <iostream>
#include <vector>
#include <map>

#include "TH2F.h"
#include "TH3F.h"
#include "TFile.h"
#include "TTree.h"
#include "TNtuple.h"



class CreateTree
{
private:
  
  TTree*  ftree ;
  TString fname ;
  
public:
  
  CreateTree (TString name);

  ~CreateTree () ;
  
  TTree*             GetTree  () const { return ftree ; } ;
  TString            GetName  () const { return fname ; } ;

  int                Fill     () ;
  void               Write    (TFile *) ;
  void               Clear    () ;
  static CreateTree* Instance () { return fInstance ; } ;
  static CreateTree* fInstance ;
  
  int   Event ;

  std::vector<int> *ID;
  std::vector<float> *position_0;
  int n_ioni_0;
    
  int number_0;
  int NumberEscaped_0;
  int number_0_out;  
  float EnergyTotal_0 ;
  float EnergyTotal_0_all ; //count also neutral particles (photons)
  std::vector<float> * Energies_0 ;
  float TrackLenght_0 ;
  float StepLenght_0 ;  
  
  int number_3;
  int number_3_out;
  float EnergyTotal_3 ;
  float EnergyTotal_3_all ;
  std::vector<float> * Energies_3 ;
  float TrackLenght_3 ;
  float StepLenght_3 ;  
    
  int number_10;
  int number_10_out;    
  float EnergyTotal_10 ;
  float EnergyTotal_10_all ;
  std::vector<float> * Energies_10 ;
  float TrackLenght_10 ;
  float StepLenght_10 ;  
      
  int number_30;
  int number_30_out;    
  float EnergyTotal_30 ;
  float EnergyTotal_30_all ;
  std::vector<float> * Energies_30 ;
  float TrackLenght_30 ;
  float StepLenght_30 ;  
      
  int number_100;
  int number_100_out;    
  float EnergyTotal_100 ;
  float EnergyTotal_100_all ;
  std::vector<float> * Energies_100 ;
  float TrackLenght_100 ;
  float StepLenght_100 ;    
} ;

#endif
