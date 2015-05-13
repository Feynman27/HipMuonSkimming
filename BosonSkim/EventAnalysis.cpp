#include "EventAnalysis.h"

// ctor
EventAnalysis::EventAnalysis(TTree* tree, bool doTruth, bool doMinBias):HeavyIonD3PD(tree, doTruth, doMinBias){
  std::cout << "[EventAnalysis::EventAnalysis] ctor"<<std::endl;
  hNEvtAll = new TH1F("hNEvtAll","",1,2e5,3e5);
  m_histV.push_back(hNEvtAll);
  hNEvtSel = new TH1F("hNEvtSel","",1,2e5,3e5);
  m_histV.push_back(hNEvtSel);
};

TVector3 EventAnalysis::TrackMET(float ptThr){

    TVector3 vMET(0.,0.,0.);
    int tracks = 0;
    // If no tracks in the event
    if(!(trk_n>0)) {
        vMET.SetXYZ(-999.,-999.,-999.);
        return vMET;
    }
    for (int itr = 0; itr<trk_n; ++itr){
        float pt = trk_pt->at(itr)*1.e-3;
        if (isGoodTrack(itr)&&pt>ptThr)
        {

            float eta = trk_eta->at(itr);
            float phi = trk_phi->at(itr);
            TVector3 vTrk; vTrk.SetPtEtaPhi(pt,eta,phi);

            vMET+=vTrk;
            ++tracks;
            
        }
    }
    // Don't calculate MET if no good tracks
    // or if no tracks meet pT threshold
    if(tracks==0){
        vMET.SetXYZ(-999.,-999.,-999.);
        return vMET;
    }

    return vMET;
}

bool EventAnalysis::LoopEvent(int entry) {
    // Uncomment to activate only select branches
    ActivateBranches(entry);
    if( !SelectEvent() ) return false;
    isDiffractiveEventEvt = isDiffractiveEvent(); 
    isPileUpEventEvt = isPileUpEvent(); 
    runNumberEvt = RunNumber;
    evtNumberEvt = EventNumber;
    lbnEvt = lbn;
    vx_nEvt = vx_n;
    vxEvt = vx_x->at(0);
    vyEvt = vx_y->at(0);
    vzEvt = vx_z->at(0);
    // MET from CALO
    MET_RefFinal_etxEvt = MET_RefFinal_etx*1.e-3;
    MET_RefFinal_etyEvt = MET_RefFinal_ety*1.e-3;
    MET_RefFinal_etEvt = MET_RefFinal_et*1.e-3;
    MET_RefFinal_phiEvt = MET_RefFinal_phi;
    // MET from ID TRACKS
    TVector3 MET = TrackMET(0.4); 
    MET_trk04_etx = fabs(MET.Px() ) < 998. ? -1.0*MET.Px() : -999.;
    MET_trk04_ety = fabs(MET.Py() ) < 998. ? -1.0*MET.Py() : -999.;
    MET_trk04_et = fabs(MET.Pt() ) < 998. ? MET.Pt() : -999.;
    MET_trk04_phi = fabs(MET.Px() ) < 998. ? MET.Phi()+ TMath::Pi() : -999.;
    if(MET_trk04_phi > TMath::Pi()) MET_trk04_phi-=TMath::TwoPi();
    MET.SetPtEtaPhi(-999.,-999.,-999.);
    MET = TrackMET(0.5); 
    MET_trk05_etx = fabs(MET.Px() ) < 998. ? -1.0*MET.Px() : -999.;
    MET_trk05_ety = fabs(MET.Py() ) < 998. ? -1.0*MET.Py() : -999.;
    MET_trk05_et = fabs(MET.Pt() ) < 998. ? MET.Pt() : -999.;
    MET_trk05_phi = fabs(MET.Px() ) < 998. ? MET.Phi()+ TMath::Pi() : -999.;
    if(MET_trk05_phi > TMath::Pi()) MET_trk05_phi-=TMath::TwoPi();
    MET.SetPtEtaPhi(-999.,-999.,-999.);
    MET = TrackMET(0.8); 
    MET_trk08_etx = fabs(MET.Px() ) < 998. ? -1.0*MET.Px() : -999.;
    MET_trk08_ety = fabs(MET.Py() ) < 998. ? -1.0*MET.Py() : -999.;
    MET_trk08_et = fabs(MET.Pt() ) < 998. ? MET.Pt() : -999.;
    MET_trk08_phi = fabs(MET.Px() ) < 998. ? MET.Phi()+ TMath::Pi() : -999.;
    if(MET_trk08_phi > TMath::Pi()) MET_trk08_phi-=TMath::TwoPi();
    MET.SetPtEtaPhi(-999.,-999.,-999.);
    MET = TrackMET(1.0); 
    MET_trk1_etx = fabs(MET.Px() ) < 998. ? -1.0*MET.Px() : -999.;
    MET_trk1_ety = fabs(MET.Py() ) < 998. ? -1.0*MET.Py() : -999.;
    MET_trk1_et = fabs(MET.Pt() ) < 998. ? MET.Pt() : -999.;
    MET_trk1_phi = fabs(MET.Px() ) < 998. ? MET.Phi()+ TMath::Pi() : -999.;
    if(MET_trk1_phi > TMath::Pi()) MET_trk1_phi-=TMath::TwoPi();
    MET.SetPtEtaPhi(-999.,-999.,-999.);
    MET = TrackMET(3.0); 
    MET_trk3_etx = fabs(MET.Px() ) < 998. ? -1.0*MET.Px() : -999.;
    MET_trk3_ety = fabs(MET.Py() ) < 998. ? -1.0*MET.Py() : -999.;
    MET_trk3_et = fabs(MET.Pt() ) < 998. ? MET.Pt() : -999.;
    MET_trk3_phi = fabs(MET.Px() ) < 998. ? MET.Phi()+ TMath::Pi() : -999.;
    if(MET_trk3_phi > TMath::Pi()) MET_trk3_phi-=TMath::TwoPi();

    EF_mu8Evt = EF_mu8;


    //calculate the corrected FCal Et for this event
    //(use for MC??)
    if(RunNumber>218589)//period B
    {
        fcal = 1e-3*(cccEt_n_Eh_FCal->at(0)+cccEt_n_Eh_FCal->at(1)+cccEt_n_Eh_FCal->at(2));
        fcal = centralityTool.GetCorrectedFCalET(RunNumber,fcal,vzEvt);
    }
    else //period A
    {
        fcal = 1e-3*(cccEt_p_Eh_FCal->at(0)+cccEt_p_Eh_FCal->at(1)+cccEt_p_Eh_FCal->at(2));
        fcal = centralityTool.GetCorrectedFCalET(RunNumber,fcal,vzEvt);
    }
 
    centrality = AssignCentrality(fcal);

    return true;
}

// Centrality definitions from Dennis
// see https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/HeavyIonAnalysis2013
float EventAnalysis::AssignCentrality(float fcal_Et){

	float centralityTemp = -1.;
	// FCal in GeV
	if(fcal_Et > 91.08){
		centralityTemp = (0.0+(1.0-0.0)/2.0)*1.0e-2; //0-1%
	}
	else if(fcal_Et > 66.03){
		centralityTemp = (1.0+(5.0-1.0)/2.0)*1.0e-2; //1-5%
	}
	else if(fcal_Et > 53.74){

		centralityTemp = (5.0+(10.0-5.0)/2.0)*1.0e-2; //5-10%
	}
	else if(fcal_Et > 40.04){

		centralityTemp = (10.0+(20.0-10.0)/2.0)*1.0e-2; //10-20%
	}
	else if(fcal_Et > 31.07){

		centralityTemp = (20.0+(30.0-20.0)/2.0)*1.0e-2; //20-30%
	}
	else if(fcal_Et > 24.10){

		centralityTemp = (30.0+(40.0-30.0)/2.0)*1.0e-2; //30-40%
	}
	else if(fcal_Et > 13.41){

		centralityTemp = (40.0+(60.0-40.0)/2.0)*1.0e-2; //40-60%
	}
	else if(fcal_Et > 2.555){

		centralityTemp = (60.0+(90.0-60.0)/2.0)*1.0e-2; //60-90%
	}

	return centralityTemp;
}

void EventAnalysis::SetOutputBranches(TTree* outputTree) {
    std::cout << "[EventAnalysis::EventAnalysis] Setting output branches."<<std::endl;
    outputTree->Branch("RunNumber",&runNumberEvt);
    outputTree->Branch("EventNumber",&evtNumberEvt);
    outputTree->Branch("lbn",&lbnEvt);
    outputTree->Branch("vx_n",&vx_nEvt);
    outputTree->Branch("vx_z",&vzEvt);
    outputTree->Branch("isDiffractiveEvent",&isDiffractiveEventEvt);
    outputTree->Branch("isPileUpEvent",&isPileUpEventEvt);
	outputTree->Branch("centrality",&centrality,"centrality/F");
	outputTree->Branch("fcal",&fcal,"fcal/F");
	outputTree->Branch("MET_RefFinal_etx",&MET_RefFinal_etxEvt,"MET_RefFinal_etx/F");
	outputTree->Branch("MET_RefFinal_ety",&MET_RefFinal_etyEvt,"MET_RefFinal_ety/F");
	outputTree->Branch("MET_RefFinal_et",&MET_RefFinal_etEvt,"MET_RefFinal_et/F");
	outputTree->Branch("MET_RefFinal_phi",&MET_RefFinal_phiEvt,"MET_RefFinal_phi/F");
	outputTree->Branch("MET_trk04_etx",&MET_trk04_etx,"MET_trk04_etx/F");
	outputTree->Branch("MET_trk04_ety",&MET_trk04_ety,"MET_trk04_ety/F");
	outputTree->Branch("MET_trk04_et",&MET_trk04_et,"MET_trk04_et/F");
	outputTree->Branch("MET_trk04_phi",&MET_trk04_phi,"MET_trk04_phi/F");
	outputTree->Branch("MET_trk05_etx",&MET_trk05_etx,"MET_trk05_etx/F");
	outputTree->Branch("MET_trk05_ety",&MET_trk05_ety,"MET_trk05_ety/F");
	outputTree->Branch("MET_trk05_et",&MET_trk05_et,"MET_trk05_et/F");
	outputTree->Branch("MET_trk05_phi",&MET_trk05_phi,"MET_trk05_phi/F");
	outputTree->Branch("MET_trk08_etx",&MET_trk08_etx,"MET_trk08_etx/F");
	outputTree->Branch("MET_trk08_ety",&MET_trk08_ety,"MET_trk08_ety/F");
	outputTree->Branch("MET_trk08_et",&MET_trk08_et,"MET_trk08_et/F");
	outputTree->Branch("MET_trk08_phi",&MET_trk08_phi,"MET_trk08_phi/F");
	outputTree->Branch("MET_trk1_etx",&MET_trk1_etx,"MET_trk1_etx/F");
	outputTree->Branch("MET_trk1_ety",&MET_trk1_ety,"MET_trk1_ety/F");
	outputTree->Branch("MET_trk1_et",&MET_trk1_et,"MET_trk1_et/F");
	outputTree->Branch("MET_trk1_phi",&MET_trk1_phi,"MET_trk1_phi/F");
	outputTree->Branch("MET_trk3_etx",&MET_trk3_etx,"MET_trk3_etx/F");
	outputTree->Branch("MET_trk3_ety",&MET_trk3_ety,"MET_trk3_ety/F");
	outputTree->Branch("MET_trk3_et",&MET_trk3_et,"MET_trk3_et/F");
	outputTree->Branch("MET_trk3_phi",&MET_trk3_phi,"MET_trk3_phi/F");
	outputTree->Branch("EF_mu8",&EF_mu8Evt,"EF_mu8/I");

}

void EventAnalysis::WriteHistosToFile(TFile* file){
    file->cd();
    for(unsigned int i=0; i<m_histV.size(); ++i) m_histV[i]->Write();
}
