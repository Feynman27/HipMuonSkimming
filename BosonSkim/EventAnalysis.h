#ifndef EVENTANALYSIS_H_
#define EVENTANALYSIS_H_

#include <iostream>
#include "HeavyIonD3PD.h"
#include "TVector3.h"
#include "TH1.h"
#include "TH1F.h"
#include "TFile.h"

class EventAnalysis:public HeavyIonD3PD {

    public:
        std::vector<TH1*> m_histV;
        EventAnalysis(TTree* tree, bool doTruth=false, bool doMinBias=false);
        ~EventAnalysis() {
            std::cout << "[EventAnalysis::EventAnalysis] dtor"<<std::endl;
            if(!m_doTruth) std::cout << "Events before selection: " << evtCountBefTrig
                << " Events after selection: " << evtCountAftTrig << ", Ratio = " << (float(evtCountAftTrig))/evtCountBefTrig << std::endl;
        };

        bool LoopEvent(int entry);
        //int SelectTrigger();
        void SetOutputBranches(TTree* outputTree);
        float AssignCentrality(float fcal);
        TVector3 TrackMET(float ptThr);
        virtual void WriteHistosToFile(TFile* file);

    private:
        int runNumberEvt;
        int evtNumberEvt;
        int triggerEvt;
        int vx_nEvt;
        int lbnEvt;
	bool isDiffractiveEventEvt;
	bool isPileUpEventEvt;
        float centrality;
        float fcal;
        float vxEvt;
        float vyEvt;
        float vzEvt;
        float MET_RefFinal_etxEvt;
        float MET_RefFinal_etyEvt;
        float MET_RefFinal_etEvt;
        float MET_RefFinal_phiEvt;
        float MET_trk04_etx;
        float MET_trk04_ety;
        float MET_trk04_et;
        float MET_trk04_phi;
        float MET_trk05_etx ;
        float MET_trk05_ety ;
        float MET_trk05_et  ;
        float MET_trk05_phi ;
        float MET_trk08_etx ;
        float MET_trk08_ety ;
        float MET_trk08_et  ;
        float MET_trk08_phi ;
        float MET_trk1_etx  ;
        float MET_trk1_ety  ;
        float MET_trk1_et   ;
        float MET_trk1_phi  ;
        float MET_trk3_etx  ;
        float MET_trk3_ety  ;
        float MET_trk3_et   ;
        float MET_trk3_phi  ;
        bool  EF_mu8Evt;
        float rectionPhiEvt;
        float mc_vxEvt;
        float mc_vyEvt;
        float mc_vzEvt;
        float npixEvt;


};

#endif
