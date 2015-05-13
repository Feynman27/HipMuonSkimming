#ifndef QCDTRUTH_H
#define QCDTRUTH_H 

#include "BranchBase.h"
#include "TLorentzVector.h"
#include <string>
#include "TH1F.h"

class QCDTruth{

    public:
        QCDTruth(std::string period="");
        ~QCDTruth();
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
        bool m_isPeriodA;
        bool m_isPeriodB;
};

#endif
