#include "BranchBase.h"

#ifndef TagAndProbe_h
#define TagAndProbe_h
class TagAndProbe{
    public:
        TagAndProbe(std::string period,bool doTruth=false);
        ~TagAndProbe();
        void setOutputTriggerBranches(TTree *outTree);
        void setOutputMSProbeBranches(TTree *outTree);
        void setOutputIDProbeBranches(TTree *outTree);
        bool LoopProbes(int entry, BranchBase* bb, bool doRec, bool doTrig, TTree* IDTree=NULL, TTree* MSTree=NULL, TTree* TriggerTree=NULL);
        bool LoopIDProbes(int entry, int itag, BranchBase* bb, TTree* outputTree);
        bool LoopMSProbes(int entry, int itag, BranchBase* bb, TTree* outputTree);
        bool LoopTriggerProbes(int entry, int itag, BranchBase* bb, TTree* outputTree);
        bool ActivateIDProbeBranches(BranchBase* bb, int entry);
        bool ActivateMSProbeBranches(BranchBase* bb, int entry);
        bool ActivateTriggerProbeBranches(BranchBase* bb, int entry);
        bool ActivateTagBranches(BranchBase* bb, int entry);
    private:
        bool m_isPeriodA;
        bool m_isPeriodB;
        bool m_doTruth;
        float centralityNt,fcalNt,vzNt;
        int RunNumberNt;
        float rec_IDprobe_chargeNt,rec_IDprobe_etaNt,rec_IDprobe_phiNt,rec_IDprobe_ptNt,rec_IDprobe_muuOSNt,rec_IDprobe_muuSSNt;
        bool rec_IDprobe_isOSNt, rec_IDprobe_isSSNt;
        int probeID_nNt,rec_IDprobe_isMatchedNt;
        float rec_MSprobe_chargeNt,rec_MSprobe_etaNt,rec_MSprobe_phiNt,rec_MSprobe_ptNt,rec_MSprobe_muuOSNt,rec_MSprobe_muuSSNt;
        bool rec_MSprobe_isOSNt,rec_MSprobe_isSSNt;
        int probeMS_nNt,rec_MSprobe_isMatchedNt;
        float trig_EF_mu8_probe_chargeNt,trig_EF_mu8_probe_etaNt,trig_EF_mu8_probe_phiNt,trig_EF_mu8_probe_ptNt, trig_EF_mu8_probe_muuOSNt,trig_EF_mu8_probe_muuSSNt;
        bool trig_EF_mu8_probe_isOSNt,trig_EF_mu8_probe_isSSNt;
        int probeTrig_nNt,trig_EF_mu8_probe_isMatchedNt;
};
#endif
