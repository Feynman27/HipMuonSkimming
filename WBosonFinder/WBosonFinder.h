#ifndef WBosonFinder_h
#define WBosonFinder_h
#include "BranchBase.h"
#include "TH1F.h"

class WBosonFinder:public BranchBase{
    public:
        WBosonFinder(TTree *tree=0, bool doMc=false,std::string="");
        ~WBosonFinder();
        bool LoopMuons(int entry,TTree* tree=0,std::string mother="data");
        void setOutputBranches(TTree *tree=0);
        bool isWCandidate(int imu);
        bool motherIsW(int imu);
        bool motherIsZ(int imu);
        bool motherIsTau(int imu);
        bool motherIsQCD(int imu);
        float getEtaConvention(float eta);
        TH1F* getTotalHisto();
        TH1F* getPassedHisto();
    private:
        int   RunNumberNt;
        int   EventNumberNt;
        bool   m_isPeriodA;
        bool   m_isPeriodB;
        bool  isZCandidateType1Nt;
        bool  isZCandidateType2Nt;
        bool  EF_mu8_matchedNt;
        float vzNt;
        float centralityNt;
        float fcalNt;
        float MET_RefFinal_etxNt;
        float MET_RefFinal_etyNt;
        float MET_RefFinal_etNt;
        float MET_RefFinal_phiNt;
        float etaNt;
        float etaConvention;
        float mtNt;
        float phiNt;
        float phi_mu_metNt;
        float ptcone20Nt;
        float ptcone30Nt;
        float ptcone40Nt;
        float chargeNt;
        float ptNt;
        float rec_truth_ENt;
        float mu_rec_truth_drNt;
        float rec_truth_etaNt;
        float rec_truth_phiNt;
        float rec_truth_ptNt;
        float rec_truth_drNt;
        int   rec_truth_matchedNt;
        int   rec_truth_mother_pdgNt;
        int   rec_truth_pdgNt;

        TH1F* h_total;
        TH1F* h_passed;
};

#endif
