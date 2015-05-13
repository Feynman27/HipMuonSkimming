#include "TagAndProbe.h"
#include "TLorentzVector.h"
#include <sstream>
#include <string>

TagAndProbe::TagAndProbe(std::string period, bool doTruth): m_isPeriodA(false), m_isPeriodB(false), m_doTruth(doTruth){
    std::cout << "[TagAndProbe::TagAndProbe] Starting the T&P analysis." << std::endl;

    if(m_doTruth) std::cout << "[TagAndProbe::TagAndProbe] Running on MC simulated data." << std::endl;

    if(strcmp(period.c_str(),"A")==0) {
        m_isPeriodA=true;
        std::cout << "[TagAndProbe::TagAndProbe] Period A configuration (Pb--> <--p)." << std::endl;
    }
    else if(strcmp(period.c_str(),"B")==0){ 
        m_isPeriodB=true;
        std::cout << "[TagAndProbe::TagAndProbe] Period B configuration (p--> <--Pb)." << std::endl;
    }
}

TagAndProbe::~TagAndProbe(){
    std::cout << "[TagAndProbe::TagAndProbe] D'tor." << std::endl;
}


void TagAndProbe::setOutputTriggerBranches(TTree *outTree){

    outTree->Branch("run",&RunNumberNt);
    outTree->Branch("vz",&vzNt);
    outTree->Branch("centrality",&centralityNt);
    outTree->Branch("fcal",&fcalNt);
    outTree->Branch("probeTrig_n",&probeTrig_nNt);
    outTree->Branch("trig_EF_mu8_probe_charge",&trig_EF_mu8_probe_chargeNt);
    outTree->Branch("trig_EF_mu8_probe_eta",&trig_EF_mu8_probe_etaNt);
    outTree->Branch("trig_EF_mu8_probe_phi",&trig_EF_mu8_probe_phiNt);
    outTree->Branch("trig_EF_mu8_probe_pt",&trig_EF_mu8_probe_ptNt);
    outTree->Branch("trig_EF_mu8_probe_isMatched",&trig_EF_mu8_probe_isMatchedNt);
    outTree->Branch("trig_EF_mu8_probe_muuOS",&trig_EF_mu8_probe_muuOSNt);
    outTree->Branch("trig_EF_mu8_probe_muuSS",&trig_EF_mu8_probe_muuSSNt);
    outTree->Branch("trig_EF_mu8_probe_isOS",&trig_EF_mu8_probe_isOSNt);
    outTree->Branch("trig_EF_mu8_probe_isSS",&trig_EF_mu8_probe_isSSNt);
    outTree->Branch("isPeriodA",&m_isPeriodA);
    outTree->Branch("isPeriodB",&m_isPeriodB);
    std::cout << "[TagAndProbe::setOutputTriggerBranches] Trigger tree branches set."<<std::endl;
}

void TagAndProbe::setOutputMSProbeBranches(TTree *outTree){

    outTree->Branch("run",&RunNumberNt);
    outTree->Branch("vz",&vzNt);
    outTree->Branch("centrality",&centralityNt);
    outTree->Branch("fcal",&fcalNt);
    outTree->Branch("probeMS_n",&probeMS_nNt);
    outTree->Branch("rec_MSprobe_charge",&rec_MSprobe_chargeNt);
    outTree->Branch("rec_MSprobe_eta",&rec_MSprobe_etaNt);
    outTree->Branch("rec_MSprobe_phi",&rec_MSprobe_phiNt);
    outTree->Branch("rec_MSprobe_pt",&rec_MSprobe_ptNt);
    outTree->Branch("rec_MSprobe_isMatched",&rec_MSprobe_isMatchedNt);
    outTree->Branch("rec_MSprobe_muuOS",&rec_MSprobe_muuOSNt);
    outTree->Branch("rec_MSprobe_muuSS",&rec_MSprobe_muuSSNt);
    outTree->Branch("rec_MSprobe_isOS",&rec_MSprobe_isOSNt);
    outTree->Branch("rec_MSprobe_isSS",&rec_MSprobe_isSSNt);
    outTree->Branch("isPeriodA",&m_isPeriodA);
    outTree->Branch("isPeriodB",&m_isPeriodB);
    std::cout << "[TagAndProbe::setOutputMSProbeBranches] MS tree branches set."<<std::endl;
}

void TagAndProbe::setOutputIDProbeBranches(TTree *outTree){

    outTree->Branch("run",&RunNumberNt);
    outTree->Branch("vz",&vzNt);
    outTree->Branch("centrality",&centralityNt);
    outTree->Branch("fcal",&fcalNt);
    outTree->Branch("probeID_n",&probeID_nNt);
    outTree->Branch("rec_IDprobe_charge",&rec_IDprobe_chargeNt);
    outTree->Branch("rec_IDprobe_eta",&rec_IDprobe_etaNt);
    outTree->Branch("rec_IDprobe_phi",&rec_IDprobe_phiNt);
    outTree->Branch("rec_IDprobe_pt",&rec_IDprobe_ptNt);
    outTree->Branch("rec_IDprobe_isMatched",&rec_IDprobe_isMatchedNt);
    outTree->Branch("rec_IDprobe_muuOS",&rec_IDprobe_muuOSNt);
    outTree->Branch("rec_IDprobe_muuSS",&rec_IDprobe_muuSSNt);
    outTree->Branch("rec_IDprobe_isOS",&rec_IDprobe_isOSNt);
    outTree->Branch("rec_IDprobe_isSS",&rec_IDprobe_isSSNt);
    outTree->Branch("isPeriodA",&m_isPeriodA);
    outTree->Branch("isPeriodB",&m_isPeriodB);

    std::cout << "[TagAndProbe::setOutputIDProbeBranches] ID tree branches set."<<std::endl;
}

bool TagAndProbe::LoopProbes(int entry, BranchBase* bb, bool doRec, bool doTrig, TTree* IDTree, TTree* MSTree, TTree* TriggerTree){

    if(doRec==true&&(IDTree==NULL||MSTree==NULL)){
        std::cout << "[TagAndProbe::LoopProbes] ERROR: T&P reco has NULL tree. Please set it in the argument. " << std::endl;
        return false;
    }
    if(doTrig==true&&TriggerTree==NULL){
        std::cout << "[TagAndProbe::LoopProbes] ERROR: T&P trigger has NULL tree. Please set it in the argument. " << std::endl;
        return false;
    }

    ActivateTagBranches(bb,entry);

    for(int itag=0; itag<bb->mu_rec_tag_n; ++itag){

        if(doRec){
            LoopIDProbes(entry,itag,bb,IDTree);
            LoopMSProbes(entry,itag,bb,MSTree);
        }
        if(doTrig){
            LoopTriggerProbes(entry,itag,bb,TriggerTree);
        }
    }//itag
    return true;
}

bool TagAndProbe::LoopIDProbes(int entry, int itag, BranchBase* bb, TTree* outputTree){
    ActivateIDProbeBranches(bb,entry);

    RunNumberNt        = bb->RunNumber;
    centralityNt       = bb->centrality;
    fcalNt             = bb->fcal;
    vzNt               = bb->vx_z;
    probeID_nNt        = bb->mu_rec_IDprobe_n->at(itag);
    TLorentzVector vtag;
    vtag.SetPtEtaPhiM(bb->mu_tag_pt->at(itag),bb->mu_tag_eta->at(itag),bb->mu_tag_phi->at(itag),bb->mu_tag_m->at(itag));
    for(int iprobe=0; iprobe<probeID_nNt; ++iprobe){

        rec_IDprobe_muuOSNt=-9999.;
        rec_IDprobe_muuSSNt=-9999.;
        rec_IDprobe_isSSNt = false;
        rec_IDprobe_isOSNt = false;

        rec_IDprobe_chargeNt    = bb->mu_rec_IDprobe_charge->at(itag)[iprobe];
        rec_IDprobe_etaNt       = bb->mu_rec_IDprobe_eta->at(itag)[iprobe];
        rec_IDprobe_phiNt       = bb->mu_rec_IDprobe_phi->at(itag)[iprobe];
        rec_IDprobe_ptNt        = bb->mu_rec_IDprobe_pt->at(itag)[iprobe];
        rec_IDprobe_isMatchedNt = bb->mu_rec_IDprobe_isMatched->at(itag)[iprobe];
        TLorentzVector vprobe; 
        vprobe.SetPtEtaPhiM(rec_IDprobe_ptNt,rec_IDprobe_etaNt,rec_IDprobe_phiNt,0.105658);
        if( (bb->mu_rec_IDprobe_charge->at(itag)[iprobe]*bb->mu_tag_charge->at(itag)>0.0) ) {
            rec_IDprobe_muuSSNt= (vtag+vprobe).M(); 
            rec_IDprobe_isSSNt = true;
        }
        else {
            rec_IDprobe_muuOSNt = (vtag+vprobe).M();
            rec_IDprobe_isOSNt = true;
        }

        outputTree->Fill();
    }//iprobe
    return true;
}

bool TagAndProbe::LoopMSProbes(int entry, int itag, BranchBase* bb, TTree* outputTree){
    ActivateMSProbeBranches(bb,entry);

    RunNumberNt        = bb->RunNumber;
    centralityNt       = bb->centrality;
    fcalNt             = bb->fcal;
    vzNt               = bb->vx_z;
    probeMS_nNt        = bb->mu_rec_MSprobe_n->at(itag);
    TLorentzVector vtag;
    vtag.SetPtEtaPhiM(bb->mu_tag_pt->at(itag),bb->mu_tag_eta->at(itag),bb->mu_tag_phi->at(itag),bb->mu_tag_m->at(itag));
    for(int iprobe=0; iprobe<probeMS_nNt; ++iprobe){

        rec_MSprobe_muuOSNt=-9999.;
        rec_MSprobe_muuSSNt=-9999.;
        rec_MSprobe_isSSNt = false;
        rec_MSprobe_isOSNt = false;

        rec_MSprobe_chargeNt    = bb->mu_rec_MSprobe_charge->at(itag)[iprobe];
        rec_MSprobe_etaNt       = bb->mu_rec_MSprobe_eta->at(itag)[iprobe];
        rec_MSprobe_phiNt       = bb->mu_rec_MSprobe_phi->at(itag)[iprobe];
        rec_MSprobe_ptNt        = bb->mu_rec_MSprobe_pt->at(itag)[iprobe];
        rec_MSprobe_isMatchedNt = bb->mu_rec_MSprobe_isMatched->at(itag)[iprobe];
        TLorentzVector vprobe; 
        vprobe.SetPtEtaPhiM(rec_MSprobe_ptNt,rec_MSprobe_etaNt,rec_MSprobe_phiNt,0.105658);
        if( (bb->mu_rec_MSprobe_charge->at(itag)[iprobe]*bb->mu_tag_charge->at(itag)>0.0) ) {
            rec_MSprobe_muuSSNt= (vtag+vprobe).M(); 
            rec_MSprobe_isSSNt=true;
        }
        else {
            rec_MSprobe_muuOSNt = (vtag+vprobe).M();
            rec_MSprobe_isOSNt=true;
        }

        outputTree->Fill();
    }//iprobe
    return true;
}

bool TagAndProbe::LoopTriggerProbes(int entry, int itag, BranchBase* bb, TTree* outputTree){
    ActivateTriggerProbeBranches(bb,entry);

    RunNumberNt        = bb->RunNumber;
    centralityNt       = bb->centrality;
    fcalNt             = bb->fcal;
    vzNt               = bb->vx_z;
    probeTrig_nNt      = bb->mu_trig_EF_mu8_probe_n->at(itag);
    TLorentzVector vtag;
    vtag.SetPtEtaPhiM(bb->mu_tag_pt->at(itag),bb->mu_tag_eta->at(itag),bb->mu_tag_phi->at(itag),bb->mu_tag_m->at(itag));
    for(int iprobe=0; iprobe<probeTrig_nNt; ++iprobe){

        trig_EF_mu8_probe_muuOSNt = -9999.0;
        trig_EF_mu8_probe_muuSSNt = -9999.0;
        trig_EF_mu8_probe_isSSNt = false;
        trig_EF_mu8_probe_isOSNt = false;

        trig_EF_mu8_probe_chargeNt    = bb->mu_trig_EF_mu8_probe_charge->at(itag)[iprobe];
        trig_EF_mu8_probe_etaNt       = bb->mu_trig_EF_mu8_probe_eta->at(itag)[iprobe];
        trig_EF_mu8_probe_phiNt       = bb->mu_trig_EF_mu8_probe_phi->at(itag)[iprobe];
        trig_EF_mu8_probe_ptNt        = bb->mu_trig_EF_mu8_probe_pt->at(itag)[iprobe];
        trig_EF_mu8_probe_isMatchedNt = bb->mu_trig_EF_mu8_probe_isMatched->at(itag)[iprobe];
        TLorentzVector vprobe; 
        vprobe.SetPtEtaPhiM(trig_EF_mu8_probe_ptNt,trig_EF_mu8_probe_etaNt,trig_EF_mu8_probe_phiNt,0.105658);
        if( (bb->mu_trig_EF_mu8_probe_charge->at(itag)[iprobe]*bb->mu_tag_charge->at(itag)>0.0) ) {
            trig_EF_mu8_probe_muuSSNt= (vtag+vprobe).M(); 
            trig_EF_mu8_probe_isSSNt=true;
        }
        else {
            trig_EF_mu8_probe_muuOSNt = (vtag+vprobe).M();
            trig_EF_mu8_probe_isOSNt=true;
        }

        outputTree->Fill();
    }//iprobe
    return true;
}

bool TagAndProbe::ActivateIDProbeBranches(BranchBase* bb, int entry){
    bb->ActivateIDProbes(entry);
    return true;
}

bool TagAndProbe::ActivateMSProbeBranches(BranchBase* bb, int entry){
    bb->ActivateMSProbes(entry);
    return true;
}

bool TagAndProbe::ActivateTriggerProbeBranches(BranchBase* bb, int entry){
    bb->ActivateTriggerProbes(entry);
    return true;
}

bool TagAndProbe::ActivateTagBranches(BranchBase* bb, int entry){

    bb->ActivateTags(entry);
    return true;
}
