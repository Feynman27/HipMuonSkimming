#include "WBosonFinder.h"

WBosonFinder::WBosonFinder(TTree *tree, bool doTruth, std::string period):BranchBase(tree,doTruth), m_isPeriodA(false), m_isPeriodB(false){

    std::cout << "[WBosonFinder::WBosonFinder] Starting the W boson finder." << std::endl;
    if(m_doTruth) std::cout << "[WBosonFinder::WBosonFinder] Truth variables are turned ON." << std::endl;
    if(strcmp(period.c_str(),"A")==0) {
        m_isPeriodA=true;
        std::cout << "[WBosonFinder::WBosonFinder] Period A configuration (Pb--> <--p)." << std::endl;
    }
    else if(strcmp(period.c_str(),"B")==0){ 
        m_isPeriodB=true;
        std::cout << "[WBosonFinder::WBosonFinder] Period B configuration (p--> <--Pb)." << std::endl;
    }

    h_total=new TH1F("h_total","h_total",400,0.0,400.0);
    h_passed=new TH1F("h_passed","h_passed",400,0.0,400.0);
}

TH1F* WBosonFinder::getTotalHisto(){
    return (TH1F*)h_total->Clone("h_total");
}

TH1F* WBosonFinder::getPassedHisto(){
    return (TH1F*)h_passed->Clone("h_passed");
}

WBosonFinder::~WBosonFinder(){

    std::cout << "[WBosonFinder::~WBosonFinder] D'tor. " << std::endl;
}

bool WBosonFinder::isWCandidate(int imu){

    // trigger matching
    // Do for MC?
    if( (mu_EF_mu8_isMatched->at(imu)==1) ){;} else return false;
    if(( mu_pt->at(imu)>25.0) ) {;} else return false;
    if( (mu_mt->at(imu)>40.0) ) {;} else return false;
    if( (MET_RefFinal_et>25.0) ) {;} else return false; 
    if( (mu_ZCandidateType1->at(imu)==0) ) {;} else return false;
    return true;
}

bool WBosonFinder::motherIsW(int imu){
    if(fabs(mu_rec_truth_mother_pdg->at(imu))==24) return true;
    else return false;
}
bool WBosonFinder::motherIsZ(int imu){
    if(fabs(mu_rec_truth_mother_pdg->at(imu))==23) return true;
    else return false;
}
bool WBosonFinder::motherIsTau(int imu){
    if(fabs(mu_rec_truth_mother_pdg->at(imu))==15) return true;
    else return false;
}
bool WBosonFinder::motherIsQCD(int imu){
    int mother = mu_rec_truth_mother_pdg->at(imu);
    if(fabs(mother)>=511 && fabs(mother)<=545) return true;
    else if(fabs(mother)>=10511 && fabs(mother)<=10543) return true;
    else if(fabs(mother)>=20513 && fabs(mother)<=10543) return true;
    else if(fabs(mother)>=411 && fabs(mother)<=435) return true;
    else if(fabs(mother)>=10411 && fabs(mother)<=10433) return true;
    else if(fabs(mother)>=20413 && fabs(mother)<=20433) return true;
    else if(fabs(mother)>=551 && fabs(mother)<=557) return true;
    else if(fabs(mother)>=10551 && fabs(mother)<=10555) return true;
    else if(fabs(mother)>=20553 && fabs(mother)<=20555) return true;
    else if(fabs(mother)==30553) return true;
    else if(fabs(mother)>=100553 && fabs(mother)<=100557) return true;
    else if(fabs(mother)>=110553 && fabs(mother)<=110555) return true;
    else if(fabs(mother)>=200551 && fabs(mother)<=200555) return true;
    else if(fabs(mother)>=210551 && fabs(mother)<=210553) return true;
    else if(fabs(mother)==220553) return true;
    else if(fabs(mother)==300553) return true;
    else if(fabs(mother)==9000553) return true;
    else if(fabs(mother)==9010553) return true;
    else if(fabs(mother)>=441 && fabs(mother)<=445) return true;
    else if(fabs(mother)>=10441 && fabs(mother)<=10443) return true;
    else if(fabs(mother)==20443) return true;
    else if(fabs(mother)==30443) return true;
    else if(fabs(mother)>=100441 && fabs(mother)<=100445) return true;
    else if(fabs(mother)==9000443) return true;
    else if(fabs(mother)==9010443) return true;
    else if(fabs(mother)==9020443) return true;
    else if(fabs(mother)>=5122 && fabs(mother)<=5554) return true;
    else if(fabs(mother)>=4122 && fabs(mother)<=4444) return true;
    else if(fabs(mother)==111) return true;
    else if(fabs(mother)==211) return true;
    else if(fabs(mother)==311) return true;
    else if(fabs(mother)==321) return true;
    else return false;
}

bool WBosonFinder::LoopMuons(int entry, TTree* outTree, std::string Mother){
    ActivateWBosonFinder(entry);
    RunNumberNt        = RunNumber;
    EventNumberNt      = EventNumber;
    centralityNt       = centrality;
    fcalNt             = fcal;
    MET_RefFinal_etxNt = MET_RefFinal_etx;
    MET_RefFinal_etyNt = MET_RefFinal_ety;
    MET_RefFinal_etNt  = MET_RefFinal_et;
    if(!m_doTruth&&(RunNumber<=218589) )     m_isPeriodA = true;
    else if(!m_doTruth&&(RunNumber>218589)) m_isPeriodB = true;
    //if( !(MET_RefFinal_etNt>25.0) ) return false; 
    vzNt = vx_z;

    for(int imu=0; imu<mu_n; ++imu){

        bool isMyChannel=false;
        if(strcmp(Mother.c_str(),"W")==0) isMyChannel = motherIsW(imu);
        else if(strcmp(Mother.c_str(),"Z")==0) isMyChannel = motherIsZ(imu);
        else if(strcmp(Mother.c_str(),"tau")==0) isMyChannel = motherIsTau(imu);
        else if(strcmp(Mother.c_str(),"QCD")==0) isMyChannel = motherIsQCD(imu);
        else if(m_doTruth) {
            std::cout << "[WBosonFinder::LoopMuons] ERROR: Cannot find MC type. Please designate as W,Z,tau,or QCD in argument." << std::endl; 
            break;
        }
         
        if(m_doTruth) {
            // Must be a generated muon (i.e. not embedded)
            if(!(fabs(mu_rec_truth_pdg->at(imu))==13)) continue;
            if(isMyChannel)  h_total->Fill(mu_pt->at(imu));
        }
        if( !(isWCandidate(imu)) ) continue;
        if(m_doTruth && isMyChannel)  h_passed->Fill(mu_pt->at(imu));

        etaNt           = mu_eta->at(imu);
        etaConvention   = getEtaConvention(mu_eta->at(imu));
        mtNt            = mu_mt->at(imu);
        phiNt           = mu_phi->at(imu);
        phi_mu_metNt    = mu_phi_mu_met->at(imu);
        ptcone20Nt      = mu_ptcone20->at(imu);
        ptcone30Nt      = mu_ptcone30->at(imu);
        ptcone40Nt      = mu_ptcone40->at(imu);
        chargeNt        = mu_charge->at(imu);
        ptNt            = mu_pt->at(imu);
        isZCandidateType1Nt  = mu_ZCandidateType1->at(imu);
        isZCandidateType2Nt  = mu_ZCandidateType2->at(imu);
        
        EF_mu8_matchedNt= mu_EF_mu8_isMatched->at(imu);
        if(m_doTruth){
            rec_truth_ENt          = mu_rec_truth_E->at(imu);            
            rec_truth_drNt         = mu_rec_truth_dr->at(imu);
            rec_truth_etaNt        = getEtaConvention(mu_rec_truth_eta->at(imu));
            rec_truth_phiNt        = mu_rec_truth_phi->at(imu);
            rec_truth_ptNt         = mu_rec_truth_pt->at(imu);
            rec_truth_matchedNt    = mu_rec_truth_matched->at(imu);
            rec_truth_mother_pdgNt = fabs(mu_rec_truth_mother_pdg->at(imu));
            rec_truth_pdgNt        = fabs(mu_rec_truth_pdg->at(imu));
        }

        outTree->Fill();
    }//imu

   return true;
}

float WBosonFinder::getEtaConvention(float eta){
   // proton travelling towards negative rapidity in Period A
   if(m_isPeriodA==true) return -1.0*eta; 
   // 
   else if(m_isPeriodB==true) return eta;
   else {
        std::cout << "[WBosonFinder::getEtaConvention] ERROR: Cannot find period. " << std::endl;
        return -9999.;
   }
}

void WBosonFinder::setOutputBranches(TTree *outTree){

    outTree->Branch("run",&RunNumberNt);
    outTree->Branch("isPeriodA",&m_isPeriodA);
    outTree->Branch("isPeriodB",&m_isPeriodB);
    outTree->Branch("vz",&vzNt);
    outTree->Branch("centrality",&centralityNt);
    outTree->Branch("fcal",&fcalNt);
    outTree->Branch("met_x",&MET_RefFinal_etxNt);
    outTree->Branch("met_y",&MET_RefFinal_etyNt);
    outTree->Branch("met",&MET_RefFinal_etNt);
    outTree->Branch("met_phi",&MET_RefFinal_phiNt);
    outTree->Branch("eta",&etaNt);
    // proton is positive eta
    outTree->Branch("eta_p_pos",&etaConvention);
    outTree->Branch("mt",&mtNt);
    outTree->Branch("pt",&ptNt);
    outTree->Branch("phi",&phiNt);
    outTree->Branch("charge",&chargeNt);
    outTree->Branch("dphi_mu_met",&phi_mu_metNt);
    outTree->Branch("ptcone20",&ptcone20Nt);
    outTree->Branch("ptcone30",&ptcone30Nt);
    outTree->Branch("ptcone40",&ptcone40Nt);
    outTree->Branch("isZCandidateType1",&isZCandidateType1Nt);
    outTree->Branch("isZCandidateType2",&isZCandidateType2Nt);
    outTree->Branch("EF_mu8_matched",&EF_mu8_matchedNt);
    if(m_doTruth){
        outTree->Branch("rec_truth_E",&rec_truth_ENt);
        outTree->Branch("mu_rec_truth_dr",&mu_rec_truth_drNt);
        outTree->Branch("rec_truth_eta",&rec_truth_etaNt);
        outTree->Branch("rec_truth_phi",&rec_truth_phiNt);
        outTree->Branch("rec_truth_pt",&rec_truth_ptNt);
        outTree->Branch("rec_truth_matched",&rec_truth_matchedNt);
        outTree->Branch("rec_truth_mother_pdg",&rec_truth_mother_pdgNt);
        outTree->Branch("rec_truth_pdg",&rec_truth_pdgNt);
    }
}
