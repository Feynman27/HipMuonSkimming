#include "ZBosonTruth.h"

ZBosonTruth::ZBosonTruth(std::string period): m_isPeriodA(false), m_isPeriodB(false){

    std::cout << "[ZBosonTruth::ZBosonTruth] Starting the truth analysis." << std::endl;
    if(strcmp(period.c_str(),"A")==0) {
        m_isPeriodA=true;
        std::cout << "[ZBosonTruth::ZBosonTruth] Period A configuration (Pb--> <--p)." << std::endl;
    }
    else if(strcmp(period.c_str(),"B")==0){ 
        m_isPeriodB=true;
        std::cout << "[ZBosonTruth::ZBosonTruth] Period B configuration (p--> <--Pb)." << std::endl;
    }
}

ZBosonTruth::~ZBosonTruth(){
    std::cout << "[ZBosonTruth::ZBosonTruth] D'tor." << std::endl;
}

void ZBosonTruth::setOutputBranches(TTree *outTree){

    outTree->Branch("run",&RunNumberNt);
    outTree->Branch("vz",&vzNt);
    outTree->Branch("centrality",&centralityNt);
    outTree->Branch("fcal",&fcalNt);
    outTree->Branch("muon_gen_E",&muon1_gen_ENt);
    outTree->Branch("muon_gen_charge",&muon1_gen_chargeNt);
    outTree->Branch("muon_gen_eta",&muon1_gen_etaNt);
    outTree->Branch("muon_gen_eta_convention",&muon1_gen_eta_conventionNt);
    outTree->Branch("muon_gen_phi",&muon1_gen_phiNt);
    outTree->Branch("muon_gen_pt",&muon1_gen_ptNt);
    outTree->Branch("muon_pdg",&muon1_pdgNt);
    outTree->Branch("muon_mother",&muon1_motherNt);
    outTree->Branch("phi_gen_muon1_muon2",&phi_gen_muon1_muon2Nt);
    outTree->Branch("mt_gen_muon2_muon",&mt_gen_muon2_muonNt);
    outTree->Branch("Z_pt",&Z_ptNt);
    outTree->Branch("Z_rapidity",&Z_rapidityNt);
    outTree->Branch("Z_phi",&Z_phiNt);
    outTree->Branch("Z_mass",&Z_massNt);
    outTree->Branch("Z_pdg",&Z_pdgNt);
    outTree->Branch("isPeriodA",&m_isPeriodA);
    outTree->Branch("isPeriodB",&m_isPeriodB);
}

float ZBosonTruth::getEtaConvention(float eta){
   // proton travelling towards negative rapidity in Period A
   if(m_isPeriodA==true) return -1.0*eta; 
   // 
   else if(m_isPeriodB==true) return eta;
   else {
        std::cout << "[ZBosonTruth::getEtaConvention] ERROR: Cannot find period. " << std::endl;
        return -9999.;
   }
}

bool ZBosonTruth::LoopTruth(int entry, BranchBase* bb, TTree* outputTree){
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
       // Find the muons
       if( (fabs(pdg)==13) && (fabs(mother)==23) ){
         muon1_gen_ENt               = bb->gen_E->at(igen); 
         muon1_gen_chargeNt          = bb->gen_charge->at(igen);
         muon1_gen_etaNt             = bb->gen_eta->at(igen);
         muon1_gen_eta_conventionNt  = getEtaConvention(muon1_gen_etaNt);
         muon1_gen_phiNt             = bb->gen_phi->at(igen);
         muon1_gen_ptNt              = bb->gen_pt->at(igen);
         muon1_pdgNt                 = bb->gen_pdg->at(igen);
         muon1_motherNt              = bb->gen_mother_pdg->at(igen);
         ++nMuons;
         // Find the muon2 matched
         // with this muon
         for(int inu=igen+1; inu<ngen; ++inu){
             int pdg2 = bb->gen_pdg->at(inu);
             int mother2 = bb->gen_mother_pdg->at(inu);
             if( (fabs(pdg2)==13) && (fabs(mother2)==23) && (pdg2*pdg<0) ){
                 float muon2_gen_ENt    = bb->gen_E->at(inu); 
                 float muon2_gen_chargeNt = bb->gen_charge->at(inu);
                 float muon2_gen_etaNt    = bb->gen_eta->at(inu);
                 float muon2_gen_phiNt    = bb->gen_phi->at(inu);
                 float muon2_gen_ptNt     = bb->gen_pt->at(inu);
                 float muon2_motherNt     = bb->gen_mother_pdg->at(inu);
                 // variables involving both decay products
                 phi_gen_muon1_muon2Nt = muon1_gen_phiNt-muon2_gen_phiNt;
                 if(phi_gen_muon1_muon2Nt>TMath::Pi()) phi_gen_muon1_muon2Nt-=TMath::TwoPi(); 
                 if(phi_gen_muon1_muon2Nt<-1.*TMath::Pi()) phi_gen_muon1_muon2Nt+=TMath::TwoPi();
                 mt_gen_muon2_muonNt  = TMath::Sqrt(2.0*muon1_gen_ptNt*muon2_gen_ptNt*(1.0-TMath::Cos(phi_gen_muon1_muon2Nt))); 
                 // Z kinematics (not including QED corrections)
                 TLorentzVector vmu2, vmu1, vZ;
                 vmu2.SetPtEtaPhiE(muon2_gen_ptNt,muon2_gen_etaNt,muon2_gen_phiNt,muon2_gen_ENt);
                 vmu1.SetPtEtaPhiE(muon1_gen_ptNt,muon1_gen_etaNt,muon1_gen_phiNt,muon1_gen_ENt);
                 vZ = vmu2+vmu1;
                 Z_ptNt       = (float)vZ.Pt();
                 Z_rapidityNt = (float)vZ.Rapidity();
                 Z_phiNt      = (float)vZ.Phi();
                 Z_massNt     = (float)vZ.M();
                 Z_pdgNt      = muon2_motherNt;

             }//muon2
         }//inu
        outputTree->Fill();
       }//muon

    }//igen

    if(nMuons>2) std::cout << "[ZBosonTruth::LoopTruth] WARNING: Found ZZ event. " << std::endl;
    return true;
}

bool ZBosonTruth::ActivateBranches(BranchBase* bb, int entry){

    bb->ActivateTruth(entry);
    return true;
}
