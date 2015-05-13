#ifndef ZBOSONTRUTH_H
#define ZBOSONTRUTH_H 

//#include "WBosonFinder.h"
#include "BranchBase.h"
#include "TLorentzVector.h"
#include <string>
#include "TH1F.h"

class ZBosonTruth{

    public:
        ZBosonTruth(std::string period="");
        ~ZBosonTruth();
        void setOutputBranches(TTree *outTree);
        bool LoopTruth(int entry, BranchBase* bb, TTree* outputTree);
        bool ActivateBranches(BranchBase* bb, int entry);
        float getEtaConvention(float eta);

    private:
        int   RunNumberNt;
        float vzNt;
        float centralityNt;
        float fcalNt;
        float muon1_gen_ENt;
        float muon1_gen_chargeNt;
        float muon1_gen_etaNt;
        float muon1_gen_eta_conventionNt;
        float muon1_gen_phiNt;
        float muon1_gen_ptNt;
        int   muon1_pdgNt;
        int   muon1_motherNt;
        float phi_gen_muon1_muon2Nt;
        float mt_gen_muon2_muonNt;
        float Z_ptNt;
        float Z_rapidityNt;
        float Z_phiNt;
        float Z_massNt;
        int Z_pdgNt;
        bool m_isPeriodA;
        bool m_isPeriodB;
};

#endif
