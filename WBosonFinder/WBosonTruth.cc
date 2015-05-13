#include "WBosonTruth.h"

WBosonTruth::WBosonTruth(std::string period): m_isPeriodA(false), m_isPeriodB(false){

    std::cout << "[WBosonTruth::WBosonTruth] Starting the truth analysis." << std::endl;
    if(strcmp(period.c_str(),"A")==0) {
        m_isPeriodA=true;
        std::cout << "[WBosonFinder::WBosonFinder] Period A configuration (Pb--> <--p)." << std::endl;
    }
    else if(strcmp(period.c_str(),"B")==0){ 
        m_isPeriodB=true;
        std::cout << "[WBosonFinder::WBosonFinder] Period B configuration (p--> <--Pb)." << std::endl;
    }
}

WBosonTruth::~WBosonTruth(){
    std::cout << "[WBosonTruth::WBosonTruth] D'tor." << std::endl;
}

void WBosonTruth::setOutputBranches(TTree *outTree){

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
    outTree->Branch("neutrino_gen_E",&neutrino_gen_ENt);
    outTree->Branch("neutrino_gen_charge",&neutrino_gen_chargeNt);
    outTree->Branch("neutrino_gen_eta",&neutrino_gen_etaNt);
    outTree->Branch("neutrino_gen_phi",&neutrino_gen_phiNt);
    outTree->Branch("neutrino_gen_pt",&neutrino_gen_ptNt);
    outTree->Branch("neutrino_pdg",&neutrino_pdgNt);
    outTree->Branch("neutrino_mother",&neutrino_motherNt);
    outTree->Branch("phi_gen_muon_neutrino",&phi_gen_muon_neutrinoNt);
    outTree->Branch("mt_gen_neutrino_muon",&mt_gen_neutrino_muonNt);
    outTree->Branch("W_pt",&W_ptNt);
    outTree->Branch("W_rapidity",&W_rapidityNt);
    outTree->Branch("W_phi",&W_phiNt);
    outTree->Branch("W_mass",&W_massNt);
    outTree->Branch("W_pdg",&W_pdgNt);
    outTree->Branch("isPeriodA",&m_isPeriodA);
    outTree->Branch("isPeriodB",&m_isPeriodB);
}

float WBosonTruth::getEtaConvention(float eta){
   // proton travelling towards negative rapidity in Period A
   if(m_isPeriodA==true) return -1.0*eta; 
   // 
   else if(m_isPeriodB==true) return eta;
   else {
        std::cout << "[WBosonTruth::getEtaConvention] ERROR: Cannot find period. " << std::endl;
        return -9999.;
   }
}

bool WBosonTruth::LoopTruth(int entry, BranchBase* bb, TTree* outputTree){
    ActivateBranches(bb,entry);

    RunNumberNt        = bb->RunNumber;
    centralityNt       = bb->centrality;
    fcalNt             = bb->fcal;
    vzNt               = bb->vx_z;
    int ngen = bb->gen_pdg->size();
    int nMuons = 0;
    int nNeutrinos = 0;
    for(int igen=0; igen<ngen; ++igen){
       int pdg    = bb->gen_pdg->at(igen);
       int mother = bb->gen_mother_pdg->at(igen);
       // Find the muons
       if( (fabs(pdg)==13) && (fabs(mother)==24) ){
         muon_gen_ENt               = bb->gen_E->at(igen); 
         muon_gen_chargeNt          = bb->gen_charge->at(igen);
         muon_gen_etaNt             = bb->gen_eta->at(igen);
         muon_gen_eta_conventionNt  = getEtaConvention(muon_gen_etaNt);
         muon_gen_phiNt             = bb->gen_phi->at(igen);
         muon_gen_ptNt              = bb->gen_pt->at(igen);
         muon_pdgNt                 = bb->gen_pdg->at(igen);
         muon_motherNt              = bb->gen_mother_pdg->at(igen);
         ++nMuons;
         // Find the neutrino matched
         // with this muon
         for(int inu=0; inu<ngen; ++inu){
             int pdg2 = bb->gen_pdg->at(inu);
             int mother2 = bb->gen_mother_pdg->at(inu);
             // @ToDo: at the moment the input pdg's are the absolute 
             // values. Therefore, pdg1*pdg2 will always be > 0. However,
             // the muon pdg and neutrino pdg will have opposite sign when 
             // this is fixed.
             if( (fabs(pdg2)==14) && (fabs(mother2)==24) && (pdg2*pdg<0) ){
                 neutrino_gen_ENt    = bb->gen_E->at(inu); 
                 neutrino_gen_chargeNt = bb->gen_charge->at(inu);
                 neutrino_gen_etaNt    = bb->gen_eta->at(inu);
                 neutrino_gen_phiNt    = bb->gen_phi->at(inu);
                 neutrino_gen_ptNt     = bb->gen_pt->at(inu);
                 neutrino_pdgNt        = bb->gen_pdg->at(inu);
                 neutrino_motherNt     = bb->gen_mother_pdg->at(inu);
                 // variables involving both decay products
                 phi_gen_muon_neutrinoNt = muon_gen_phiNt-neutrino_gen_phiNt;
                 if(phi_gen_muon_neutrinoNt>TMath::Pi()) phi_gen_muon_neutrinoNt-=TMath::TwoPi(); 
                 if(phi_gen_muon_neutrinoNt<-1.*TMath::Pi()) phi_gen_muon_neutrinoNt+=TMath::TwoPi();
                 mt_gen_neutrino_muonNt  = TMath::Sqrt(2.0*muon_gen_ptNt*neutrino_gen_ptNt*(1.0-TMath::Cos(phi_gen_muon_neutrinoNt))); 
                 // W kinematics (not including QED corrections)
                 TLorentzVector vnu, vmu, vW;
                 vnu.SetPtEtaPhiE(neutrino_gen_ptNt,neutrino_gen_etaNt,neutrino_gen_phiNt,neutrino_gen_ENt);
                 vmu.SetPtEtaPhiE(muon_gen_ptNt,muon_gen_etaNt,muon_gen_phiNt,muon_gen_ENt);
                 vW = vnu+vmu;
                 W_ptNt       = (float)vW.Pt();
                 W_rapidityNt = (float)vW.Rapidity();
                 W_phiNt      = (float)vW.Phi();
                 W_massNt     = (float)vW.M();
                 W_pdgNt      = neutrino_motherNt;

                 ++nNeutrinos;
                 break;
             }//neutrino
         }//inu
         outputTree->Fill();
       }//muon
       if(nMuons>1||nNeutrinos>1) std::cout << "[WBosonTruth::LoopTruth] WARNING: Found WW event. " << std::endl;
    }//igen

    return true;
}

bool WBosonTruth::ActivateBranches(BranchBase* bb, int entry){

    bb->ActivateTruth(entry);
    return true;
}
