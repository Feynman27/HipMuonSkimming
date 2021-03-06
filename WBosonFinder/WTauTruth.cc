#include "WTauTruth.h"

WTauTruth::WTauTruth(std::string period): m_isPeriodA(false), m_isPeriodB(false){

    std::cout << "[WTauTruth::WTauTruth] Starting the truth analysis." << std::endl;
    if(strcmp(period.c_str(),"A")==0) {
        m_isPeriodA=true;
        std::cout << "[WTauTruth::WTauTruth] Period A configuration (Pb--> <--p)." << std::endl;
    }
    else if(strcmp(period.c_str(),"B")==0){ 
        m_isPeriodB=true;
        std::cout << "[WTauTruth::WTauTruth] Period B configuration (p--> <--Pb)." << std::endl;
    }
}

WTauTruth::~WTauTruth(){
    std::cout << "[WTauTruth::WTauTruth] D'tor." << std::endl;
}

void WTauTruth::setOutputBranches(TTree *outTree){

    outTree->Branch("run",&RunNumberNt);
    outTree->Branch("vz",&vzNt);
    outTree->Branch("centrality",&centralityNt);
    outTree->Branch("fcal",&fcalNt);
    outTree->Branch("muon_gen_E",&muon_gen_ENt);
    outTree->Branch("muon_gen_charge",&muon_gen_chargeNt);
    outTree->Branch("muon_gen_eta",&muon_gen_etaNt);
    outTree->Branch("muon_gen_eta_convention",&muon_gen_eta_conventionNt);
    outTree->Branch("muon_gen_phi",&muon_gen_phiNt);
    outTree->Branch("muon_gen_pt",&muon_gen_ptNt);
    outTree->Branch("muon_pdg",&muon_pdgNt);
    outTree->Branch("muon_mother",&muon_motherNt);
    outTree->Branch("isPeriodA",&m_isPeriodA);
    outTree->Branch("isPeriodB",&m_isPeriodB);
}

float WTauTruth::getEtaConvention(float eta){
   // proton travelling towards negative rapidity in Period A
   if(m_isPeriodA==true) return -1.0*eta; 
   // 
   else if(m_isPeriodB==true) return eta;
   else {
        std::cout << "[WTauTruth::getEtaConvention] ERROR: Cannot find period. " << std::endl;
        return -9999.;
   }
}

bool WTauTruth::LoopTruth(int entry, BranchBase* bb, TTree* outputTree){
    ActivateBranches(bb,entry);
    RunNumberNt        = bb->RunNumber;
    centralityNt       = bb->centrality;
    fcalNt             = bb->fcal;
    vzNt               = bb->vx_z;
    int ngen = bb->gen_pdg->size();
    int nMuons = 0;
    for(int igen=0; igen<ngen; ++igen){
       int pdg    = bb->gen_pdg->at(igen);
       int mother = bb->gen_mother_pdg->at(igen);
       // tau-->mu
       if( (fabs(pdg)==13) && (fabs(mother)==15) && (pdg*mother>0)){
         muon_gen_ENt               = bb->gen_E->at(igen); 
         muon_gen_chargeNt          = bb->gen_charge->at(igen);
         muon_gen_etaNt             = bb->gen_eta->at(igen);
         muon_gen_eta_conventionNt  = getEtaConvention(muon_gen_etaNt);
         muon_gen_phiNt             = bb->gen_phi->at(igen);
         muon_gen_ptNt              = bb->gen_pt->at(igen);
         muon_pdgNt                 = bb->gen_pdg->at(igen);
         muon_motherNt              = bb->gen_mother_pdg->at(igen);
         ++nMuons;
         outputTree->Fill();
       }
    }//igen

    if(nMuons>1) std::cout << "[WTauTruth::LoopTruth] WARNING: Found >1 tau-->mu event. " << std::endl;
    return true;
}

bool WTauTruth::ActivateBranches(BranchBase* bb, int entry){

    bb->ActivateTruth(entry);
    return true;
}
