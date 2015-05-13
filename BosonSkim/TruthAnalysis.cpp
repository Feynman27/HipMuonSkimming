#include "TruthAnalysis.h"

TruthAnalysis::TruthAnalysis(){

        std::cout << "[TruthAnalysis::TruthAnalysis] ctor"<< std::endl;
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("gen_mother_pdg",0) ); //muon source from MC information
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("gen_pdg",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("gen_charge",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("gen_pt",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("gen_E",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("gen_eta",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("gen_phi",0));
}

TruthAnalysis::~TruthAnalysis() {
  std::cout << "[TruthAnalysis::TruthAnalysis] Dtor: Clean up." << std::endl;
  // Free memory from vector of muons vars
  for(std::map<std::string,std::vector<float>* >::iterator it=m_fBranches.begin(); 
      it!=m_fBranches.end(); ++it)  delete it->second;
  for(std::map<std::string,std::vector<int>* >::iterator it=m_iBranches.begin();
      it!=m_iBranches.end(); ++it)  delete it->second;
}

void TruthAnalysis::ClearVectors(){
  for(std::map<std::string, std::vector<float>* >::iterator itr=m_fBranches.begin();
      itr!=m_fBranches.end(); ++itr) {

    itr->second->clear();
  }
  for(std::map<std::string, std::vector<int>* >::iterator itr=m_iBranches.begin();
      itr!=m_iBranches.end(); ++itr) {

    itr->second->clear();
  }


}

void TruthAnalysis::SetOutputBranches(TTree* outputTree) {

    // Floats
    for(std::map<std::string, std::vector<float>* >::iterator itr=m_fBranches.begin();
            itr!=m_fBranches.end(); ++itr) {

        // Allocate memory to store values
        std::vector<float>* vptr = new std::vector<float>();
        m_fBranches[itr->first] = vptr;

        // Assign a new branch with address to vptr
        outputTree->Branch(std::string(itr->first).c_str(), "std::vector<float>", &(m_fBranches[itr->first]) );
    }

    // Ints
    for(std::map<std::string, std::vector<int>* >::iterator itr=m_iBranches.begin();
            itr!=m_iBranches.end(); ++itr) {

        // Allocate memory to store values
        std::vector<int>* vptr = new std::vector<int>();
        m_iBranches[itr->first] = vptr;

        // Assign a new branch with address to vptr
        outputTree->Branch(std::string(itr->first).c_str(), "std::vector<int>", &(m_iBranches[itr->first]) );
    

    }
}

void TruthAnalysis::ActivateTruthBranches(HeavyIonD3PD* HID3PD, int entry){
    HID3PD->ActivateTruthBranches(entry);
}


// @ToDo: W-->tau nu --> mu nu nu
/*void TruthAnalysis::LoopEvent(HeavyIonD3PD* HID3PD, int entry, int thisAlphaMother, int thisBetaMother, int thisChild1, int thisChild2, int thisChild3) {
  ClearVectors(); //Only clean single muon parameters
  ActivateTruthBranches(HID3PD,entry);
  m_nSignalMuons=0;
  for(int i = 0; i < HID3PD->mc_n; ++i) {
    int pdg = HID3PD->mc_gen_type->at(i);
    if( (fabs(pdg)!=thisChild1) && 
        (fabs(pdg)!=thisChild2) &&
        (fabs(pdg)!=thisChild3) &&
        (fabs(pdg)!=thisChild3) &&
        (fabs(pdg)!=thisAlphaMother)
      ) continue;

    bool isMyChannel = false;
    int mother = HID3PD->mc_gen_mothertype->at(i);
    int barcode = HID3PD->mc_gen_barcode->at(i);
    if(barcode>=200000) continue;
    if( ( (fabs(pdg)==thisChild1) || (fabs(pdg)==thisChild2) ) && (fabs(mother)==thisMother) ) isMyChannel=true;

    if(isMyChannel){
        if( (fabs(pdg)==13) ) ++m_nSignalMuons;
        
        m_iBranches["gen_pdg"]->push_back(pdg);
        m_iBranches["gen_mother_pdg"]->push_back(mother);
        m_fBranches["gen_charge"]->push_back(HID3PD->mc_charge->at(i));
        m_fBranches["gen_pt"]->push_back(HID3PD->mc_gen_pt->at(i)/1000.);
        m_fBranches["gen_E"]->push_back(HID3PD->mc_gen_E->at(i)/1000.);
        m_fBranches["gen_eta"]->push_back(HID3PD->mc_gen_eta->at(i));
        m_fBranches["gen_phi"]->push_back(HID3PD->mc_gen_phi->at(i));
    }
    
  }//i

}
*/

bool TruthAnalysis::isBottomMeson(int mother){
    if(fabs(mother)>=511 && fabs(mother)<=545) return true;
    else if(fabs(mother)>=10511 && fabs(mother)<=10543) return true;
    else if(fabs(mother)>=20513 && fabs(mother)<=10543) return true;
    else return false;
}

bool TruthAnalysis::isCharmedMeson(int mother){
    if(fabs(mother)>=411 && fabs(mother)<=435) return true;
    else if(fabs(mother)>=10411 && fabs(mother)<=10433) return true;
    else if(fabs(mother)>=20413 && fabs(mother)<=20433) return true;
    else return false;
}

bool TruthAnalysis::isBBBAR(int mother){
    if(fabs(mother)>=551 && fabs(mother)<=557) return true;
    else if(fabs(mother)>=10551 && fabs(mother)<=10555) return true;
    else if(fabs(mother)>=20553 && fabs(mother)<=20555) return true;
    else if(fabs(mother)==30553) return true;
    else if(fabs(mother)>=100553 && fabs(mother)<=100557) return true;
    else if(fabs(mother)>=100553 && fabs(mother)<=110555) return true;
    else if(fabs(mother)>=200551 && fabs(mother)<=200555) return true;
    else if(fabs(mother)>=210551 && fabs(mother)<=210553) return true;
    else if(fabs(mother)==220553) return true;
    else if(fabs(mother)==300553) return true;
    else if(fabs(mother)==9000553) return true;
    else if(fabs(mother)==9010553) return true;
    else return false;
}

bool TruthAnalysis::isCCBAR(int mother){
    if(fabs(mother)>=441 && fabs(mother)<=445) return true;
    else if(fabs(mother)>=10441 && fabs(mother)<=10443) return true;
    else if(fabs(mother)==20443) return true;
    else if(fabs(mother)==30443) return true;
    else if(fabs(mother)>=100441 && fabs(mother)<=100445) return true;
    else if(fabs(mother)==9000443) return true;
    else if(fabs(mother)==9010443) return true;
    else if(fabs(mother)==9020443) return true;
    else return false;
}

bool TruthAnalysis::isBottomBaryon(int mother){
    if(fabs(mother)>=5122 && fabs(mother)<=5554) return true;
    else return false;
}
bool TruthAnalysis::isCharmedBaryon(int mother){
    if(fabs(mother)>=4122 && fabs(mother)<=4444) return true;
    else return false;
}

bool TruthAnalysis::isPion(int mother){
    if(fabs(mother)==111) return true;
    else if(fabs(mother)==211) return true;
    else return false;
}

bool TruthAnalysis::isKaon(int mother){
    if(fabs(mother)==311) return true;
    else if(fabs(mother)==321) return true;
    else return false;
}

// Loop truth particles with 1 child species and multiple parent species
// E.g. pi/K-->mu, B/C-->mu
// Bottom Mesons : 511-545, 10511-10543, 20513-10543
// Charmed Mesons: 411-435, 10411-10433, 20413-20433
// bbbar mesons: 551-557, 10551-10555, 20553-20555, 30553, 100553-100557, 100553-110555, 200551-200555, 210551-210553, 220553,300553, 9000553, 9010553
// ccbar mesons: 441-445, 10441-10443, 20443, 30443, 100441-100445, 900443,9010443,9020443
// Bottom baryons: 5122-5554
// Charmed baryons: 4122-4444
// Pions: 111, 211
// Kaons: 311,321
void TruthAnalysis::LoopEventQCD(HeavyIonD3PD* HID3PD, int entry, int thisChild1) {
  ClearVectors(); //Only clean single muon parameters
  ActivateTruthBranches(HID3PD,entry);
  m_nSignalMuons=0;

  // Range of PDGs for pi/K and B/C hadrons
  for(int i = 0; i < HID3PD->mc_n; ++i) {
    // muon/(muon)neutrino/W 
    int pdg = HID3PD->mc_gen_type->at(i);
    if( (fabs(pdg)!=thisChild1) ) continue;

    bool isMyChannel = false;
    int mother = HID3PD->mc_gen_mothertype->at(i);
    int barcode = HID3PD->mc_gen_barcode->at(i);
    //if(barcode>=200000) continue;
    if( (fabs(pdg)==thisChild1) && 
        (isBottomMeson(mother)
         ||isCharmedMeson(mother)
         ||isBBBAR(mother)
         ||isCCBAR(mother)
         ||isBottomBaryon(mother)
         ||isCharmedBaryon(mother)
         ||isPion(mother)
         ||isKaon(mother)) 
      ) isMyChannel=true;

    if(isMyChannel){
        if( (fabs(pdg)==13) ) ++m_nSignalMuons;
        
        m_iBranches["gen_pdg"]->push_back(pdg);
        m_iBranches["gen_mother_pdg"]->push_back(mother);
        m_fBranches["gen_charge"]->push_back(HID3PD->mc_charge->at(i));
        m_fBranches["gen_pt"]->push_back(HID3PD->mc_gen_pt->at(i)/1000.);
        m_fBranches["gen_E"]->push_back(HID3PD->mc_gen_E->at(i)/1000.);
        m_fBranches["gen_eta"]->push_back(HID3PD->mc_gen_eta->at(i));
        m_fBranches["gen_phi"]->push_back(HID3PD->mc_gen_phi->at(i));
    }
    
  }//i

}

// Loop truth particles with 2 child species and single parent species
// E.g. W-->munu, Z-->mumu, tau-->mununu
void TruthAnalysis::LoopEvent(HeavyIonD3PD* HID3PD, int entry, int thisMother, int thisChild1, int thisChild2) {
  ClearVectors(); //Only clean single muon parameters
  ActivateTruthBranches(HID3PD,entry);
  m_nSignalMuons=0;
  for(int i = 0; i < HID3PD->mc_n; ++i) {
    // muon/(muon)neutrino/W 
    int pdg = HID3PD->mc_gen_type->at(i);
    if( (fabs(pdg)!=thisChild1) && 
        (fabs(pdg)!=thisChild2) &&
        (fabs(pdg)!=thisMother)
      ) continue;

    bool isMyChannel = false;
    // W boson
    // No mother info in mc_*
    /*if(pdg==24){
       for(int ich=0; ich<HID3PD->mc_child_n->at(i); ++ich){
            int child = fabs(HID3PD->mc_child_pdg->at(i)[ich]);
            std::cout << "W child PDG: " << child << std::endl;
            int barcode = HID3PD->mc_child_barcode->at(i)[ich];
            // W-->mu
            if(child==13){
                ++nSignalMuons;
                isMyChannel = true; 
                break;
            }
       }//ich
    }
    */
    int mother = HID3PD->mc_gen_mothertype->at(i);
    int barcode = HID3PD->mc_gen_barcode->at(i);
    if(barcode>=200000) continue;
    if( ( (fabs(pdg)==thisChild1) || (fabs(pdg)==thisChild2) ) && (fabs(mother)==thisMother) ) isMyChannel=true;

    // This mc particle
    // comes from the channel of interest 
    // Note: In the case of W-->tau decays, 
    // there will be info for 1 muon and 
    // two neutrinos saved
    if(isMyChannel){
        if( (fabs(pdg)==13) ) ++m_nSignalMuons;
        
        m_iBranches["gen_pdg"]->push_back(pdg);
        m_iBranches["gen_mother_pdg"]->push_back(mother);
        m_fBranches["gen_charge"]->push_back(HID3PD->mc_charge->at(i));
        m_fBranches["gen_pt"]->push_back(HID3PD->mc_gen_pt->at(i)/1000.);
        m_fBranches["gen_E"]->push_back(HID3PD->mc_gen_E->at(i)/1000.);
        m_fBranches["gen_eta"]->push_back(HID3PD->mc_gen_eta->at(i));
        m_fBranches["gen_phi"]->push_back(HID3PD->mc_gen_phi->at(i));
    }
    
  }//i

}
