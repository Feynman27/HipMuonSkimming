#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include "HeavyIonD3PD.h"
#include "EventAnalysis.h"
#include "MuonAnalysis.h"
#include "TruthAnalysis.h"
//#include "Cintex/Cintex.h"

int main(int argc, char* argv[]) {

  //ROOT::Cintex::Cintex::Enable();
  if(argc<2){
      std::cout << "Input parameters: 1) W,Z,TAU,QCD,DATA" << std::endl;
      exit(EXIT_SUCCESS);
  }
  bool doTruthW = false;
  bool doTruthZ = false;
  bool doTruthTau = false;
  bool doTruthQCD = false;
  bool doTruth = false;
  if(strcmp(argv[1],"W")==0) doTruthW=true;
  else if(strcmp(argv[1],"Z")==0) doTruthZ=true;
  else if(strcmp(argv[1],"TAU")==0) doTruthTau=true;
  else if(strcmp(argv[1],"QCD")==0) doTruthQCD=true;
  if(doTruthW||doTruthZ||doTruthTau||doTruthQCD) doTruth=true;
  int mother=-1;
  int child1=-1;
  int child2=-1;
  bool doMinBias = false;
  bool doMu = true;
  bool doMuid = false;
  bool doStaco = false;
  if(doTruthW) { 
      mother=24; // W
      child1=13; // muon
      child2=14; // neutrino
      std::cout << "======> Running on W-->munu Monte Carlo simulation. <======" << std::endl; 
  }
  else if(doTruthZ) { 
      mother=23; // Z
      child1=13; // muon
      child2=13; // muon 
      std::cout << "======> Running on Z-->mumu Monte Carlo simulation. <======" << std::endl; 
  }
  else if(doTruthTau) { 
      mother=15; // tau
      child1=13; // muon
      child2=14; // neutrino(s) 
      std::cout << "======> Running on W-->taunu-->mununu Monte Carlo simulation. <======" << std::endl; 
  }
  else if(doTruthQCD) { 
      child1=13; // muon
      std::cout << "======> Running on QCD Monte Carlo simulation. <======" << std::endl; 
  }
  else if(doMinBias) { std::cout << "======> Running on Minimum Bias Data. <======" << std::endl; }
  else { std::cout << "======> Running on Data. <======" << std::endl; }
  if(doTruth&&doMinBias){

      std::cout << "PLEASE CHOOSE TO RUN ON EITHER MC OR DATA." << std::endl;
      exit(0);
  }
  std::string argStr;
  std::ifstream ifs;
  ifs.open("input.txt");

  // split by ','
  std::vector<std::string> fileList;
  
  std::getline(ifs,argStr);
  for (size_t i=0,n; i <= argStr.length(); i=n+1)
  {
      n = argStr.find_first_of(',',i);
      if (n == std::string::npos)
          n = argStr.length();
      std::string tmp = argStr.substr(i,n-i);
      fileList.push_back(tmp);
  }

  cout << fileList.size() << " files used for processing." << endl;
  // open input files
  TChain* fChain = new TChain("HeavyIonD3PD");

  for (int iFile=0; iFile<fileList.size(); ++iFile)
    {
      std::cout << "open " << fileList[iFile].c_str() << std::endl;
      // Add each file to the TChain
      fChain->Add(fileList[iFile].c_str());
    }
  int entries = fChain->GetEntries();
  std::cout << "entries=" << fChain->GetEntries() << std::endl;

  TFile* fout=0;
  fout=new TFile("skimmed.root","RECREATE");
  TTree* outputTree = new TTree("MuonD3PD","MuonD3PD");
  TTree* outputTallTree = fChain->CloneTree(0);

  // Handle to D3PD
  EventAnalysis* EvtAna = new EventAnalysis(fChain, doTruth, doMinBias);
  EvtAna->SetOutputBranches(outputTree);

  MuonAnalysis* muMuonAna = NULL, *muidMuonAna = NULL, *stacoMuonAna = NULL; 
  if(doMu){
    std::cout << "USING MUON RECONSTRUCTION CHAIN." << std::endl;
    muMuonAna = new MuonAnalysis("mu", doTruth, doMinBias);
    muMuonAna->SetOutputBranches(outputTree);
  }
  if(doMuid){
    std::cout << "USING MUID RECONSTRUCTION CHAIN." << std::endl;
    muidMuonAna = new MuonAnalysis("muid", doTruth, doMinBias);
    muidMuonAna->SetOutputBranches(outputTree);
  }
  if(doStaco){
    std::cout << "USING STACO RECONSTRUCTION CHAIN." << std::endl;
    stacoMuonAna = new MuonAnalysis("staco", doTruth, doMinBias);
    stacoMuonAna->SetOutputBranches(outputTree);
  }

  TruthAnalysis* truAna = NULL;
  if(doTruth){
    truAna = new TruthAnalysis();
    truAna->SetOutputBranches(outputTree);

  }

  // Total number of muons in the sample
  int nMuMuons = 0, nMuidMuons = 0, nStacoMuons = 0;
  for(int iev=0; iev<entries; iev++) {
     // Comment out to activate only select branches. 
     // If you do, outputTallTree will only write muon information and
     // will not dump the entire event information.

      fChain->GetEntry(iev);
      // entry in tree
      int entry = EvtAna->LoadTree(iev);
      if (entry < 0) continue;
      if(iev%1000==0) {
        std::cout << " Event no: " << iev << std::endl;
      }
      // No. of muons w/ pt>20 GeV in this event
      int nHiPtMuMuons=0;
      //if(iev==10000) break; //hack
      if( !EvtAna->LoopEvent(entry) ) continue;
      if(doTruth){
        if(doTruthQCD) truAna->LoopEventQCD(EvtAna,entry,child1); 
        else truAna->LoopEvent(EvtAna,entry,mother,child1,child2);
        int nTruthMu = truAna->GetNumTruthMuon();
        if(nTruthMu==0) continue;
        
      }
      if(doMu) { 
          muMuonAna->LoopEvent(EvtAna,entry);
          int nmu = muMuonAna->GetNumMuMuon();
          nHiPtMuMuons = muMuonAna->GetNumHiPtMuMuon();
          // At least 1 good muon in event
          if( !(doTruth) && (nmu==0) ) continue;
          nMuMuons+=nmu;
      }
      if(doMuid) { 
          muidMuonAna->LoopEvent(EvtAna,entry);
          int nmu = muidMuonAna->GetNumMuidMuon();
          // At least 1 good muon in event
          if( !(doTruth) && (nmu==0) ) continue;
          nMuidMuons+=nmu;
      }
      if(doStaco) { 
          stacoMuonAna->LoopEvent(EvtAna,entry);
          int nmu = stacoMuonAna->GetNumStacoMuon();
          // At least 1 good muon in event
          if( !(doTruth) && (nmu==0) ) continue;
          nStacoMuons+=nmu;
      }

      // Fill once per HiP event
      outputTree->Fill();
      /// If we have a good high pt (20 GeV) muon in the event, 
      /// save all event information to a 2nd tree
      if(nHiPtMuMuons>0 && !doTruth){
	outputTallTree->Fill();
      }
  }//iev
  fout->cd();
  if(doMu) {
      std::cout << "Total number of good \"mu\" muons: " << nMuMuons << std::endl;
      muMuonAna->WriteHistosToFile(fout);
  }
  if(doMuid) {
      std::cout << "Total number of good \"muid\" muons: " << nMuidMuons << std::endl;
      muidMuonAna->WriteHistosToFile(fout);
  }
  if(doStaco){ 
      std::cout << "Total number of good \"staco\" muons: " << nStacoMuons << std::endl;
      stacoMuonAna->WriteHistosToFile(fout);
  }

  if(!doTruth) outputTallTree->Write();
  EvtAna->WriteHistosToFile(fout);
  delete EvtAna;
  if(muMuonAna!=NULL) delete muMuonAna;
  if(muidMuonAna!=NULL) delete muidMuonAna;
  if(stacoMuonAna!=NULL) delete stacoMuonAna;
  outputTree->Write();

  return 0;
}
