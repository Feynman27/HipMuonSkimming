#ifndef WBOSONTRUTH_H
#define WBOSONTRUTH_H 

//#include "WBosonFinder.h"
#include "BranchBase.h"
#include "TLorentzVector.h"
#include <string>
#include "TH1F.h"

class WBosonTruth{

    public:
        WBosonTruth(std::string period="");
        ~WBosonTruth();
        void setOutputBranches(TTree *outTree);
        bool LoopTruth(int entry, BranchBase* bb, TTree* outputTree);
        bool ActivateBranches(BranchBase* bb, int entry);
        float getEtaConvention(float eta);

    private:
        int   RunNumberNt;
        float vzNt;
        float centralityNt;
        float fcalNt;
        float muon_gen_ENt;
        float muon_gen_chargeNt;
        float muon_gen_etaNt;
        float muon_gen_eta_conventionNt;
        float muon_gen_phiNt;
        float muon_gen_ptNt;
        int   muon_pdgNt;
        int   muon_motherNt;
        float neutrino_gen_ENt;
        float neutrino_gen_chargeNt;
        float neutrino_gen_etaNt;
        float neutrino_gen_phiNt;
        float neutrino_gen_ptNt;
        int   neutrino_pdgNt;
        int   neutrino_motherNt;
        float phi_gen_muon_neutrinoNt;
        float mt_gen_neutrino_muonNt;
        float W_ptNt;
        float W_rapidityNt;
        float W_phiNt;
        float W_massNt;
        int W_pdgNt;
        bool m_isPeriodA;
        bool m_isPeriodB;
};

#endif
