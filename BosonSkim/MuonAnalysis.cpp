#include "MuonAnalysis.h"

MuonAnalysis::MuonAnalysis(std::string prefix, bool doTruth, bool doMinBias):
    name(prefix),m_dRCut(0.2),m_doTruth(doTruth),m_doMinBias(doMinBias),numMuMuon(0),numMuidMuon(0),numStacoMuon(0),numHiPtMuMuon(0),
    m_isMuChain(false), m_isMuidChain(false), m_isStacoChain(false) {

        std::cout << "[MuonAnalysis::MuonAnalysis] ctor"<< std::endl;
        if(m_doTruth) std::cout << "[MuonAnalysis::MuonAnalysis] Monte Carlo Sample. " << std::endl;
        if(m_doMinBias) std::cout << "[MuonAnalysis::MuonAnalysis] Minimum Bias Sample. " << std::endl;

        /// Map muon vars --> vectors<>*
	/// Add new branches here
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("E",0) ); //total energy
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("pt",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("ptid",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("eta",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("phi",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("m",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("beta",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("nucone20",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("nucone30",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("nucone40",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("ptcone20",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("ptcone30",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("ptcone40",0) );
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("charge",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("d0",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("z0",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("d0Sig",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("z0Sig",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("scatteringCurvatureSignificance",0) ); //scatter significance
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("momentumBalanceSignificance",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("momentumLossPull",0) );
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("comp",0) ); //composite
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("phi_mu_met",0) ); 
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("mt",0) ); 
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("EF_mu8_isMatched",0) ); 
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("isTagMuon",0) );
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("rec_IDprobe_n",0) );
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("rec_MSprobe_n",0) );
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("trig_EF_mu8_probe_n",0) );
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("ZCandidateType1",0) ); 
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("ZCandidateType2",0) ); 
        if(m_doTruth) { 
            // truth quantities of rec muons
            m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("rec_truth_dr",0));
            m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("rec_truth_E",0));
            m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("rec_truth_pt",0));
            m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("rec_truth_eta",0));
            m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("rec_truth_phi",0));
            m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("rec_truth_pdg",0));
            m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("rec_truth_mother_pdg",0));
            m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("rec_truth_matched",0));

        }
        // Variables associated to rec tags
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("tag_pt",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("tag_eta",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("tag_phi",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("tag_m",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("tag_E",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("tag_ptcone20",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("tag_ptcone30",0));
        m_fBranches.insert(std::make_pair<std::string, std::vector<float>* >("tag_ptcone40",0));
        m_iBranches.insert(std::make_pair<std::string, std::vector<int>* >("tag_charge",0));

        m_iLeaves.insert(std::make_pair<std::string, std::vector<std::vector<int> >* >("rec_IDprobe_isMatched",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("rec_IDprobe_pt",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("rec_IDprobe_eta",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("rec_IDprobe_phi",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("rec_IDprobe_charge",0));

        m_iLeaves.insert(std::make_pair<std::string, std::vector<std::vector<int> >* >("rec_MSprobe_isMatched",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("rec_MSprobe_pt",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("rec_MSprobe_eta",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("rec_MSprobe_phi",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("rec_MSprobe_charge",0));

        // Variables associated with trig tags
        m_iLeaves.insert(std::make_pair<std::string, std::vector<std::vector<int> >* >("trig_EF_mu8_probe_isMatched",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("trig_EF_mu8_probe_pt",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("trig_EF_mu8_probe_eta",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("trig_EF_mu8_probe_phi",0));
        m_fLeaves.insert(std::make_pair<std::string, std::vector<std::vector<float> >* >("trig_EF_mu8_probe_charge",0));

        // Control histos
        if(strcmp(name.c_str(),"mu")==0){
            m_isMuChain = true;
            std::cout << "[MuonAnalysis::MuonAnalysis] Running on " << name << " muons." << std::endl;

            hmu_medium = new TH1I("hmu_medium","hmu_medium",5,0,2);
            m_hMuonVec.push_back(hmu_medium); 
            hmu_author = new TH1I("hmu_author","hmu_author",60,0,30);
            m_hMuonVec.push_back(hmu_author); 
            hmu_nPixHits = new TH1I("hmu_nPixHits","hmu_nPixHits",40,0,20);
            m_hMuonVec.push_back(hmu_nPixHits); 
            hmu_nBLHits = new TH1I("hmu_nBLHits","hmu_nBLHits",40,0,20);
            m_hMuonVec.push_back(hmu_nBLHits); 
            hmu_nSCTHits = new TH1I("hmu_nSCTHits","hmu_nSCTHits",40,0,20);
            m_hMuonVec.push_back(hmu_nSCTHits); 
            hmu_nPixSCTHoles = new TH1I("hmu_nPixSCTHoles","hmu_nPixSCTHoles",40,0,20);
            m_hMuonVec.push_back(hmu_nPixSCTHoles); 
            hmu_isCombinedMuon = new TH1I("hmu_isCombinedMuon","hmu_isCombinedMuon",5,0,2);
            m_hMuonVec.push_back(hmu_isCombinedMuon); 

            hmu_EF_mu8_dR = new TH1F("hmu_EF_mu8_dR","hmu_EF_mu8_dR",1e3,0.0,10.0);
            m_hMuonVec.push_back(hmu_EF_mu8_dR);
            hmu_momentumBalanceSignificance = new TH1F("hmu_momentumBalanceSignificance","hmu_momentumBalanceSignificance",100,0.0,40.0);
            m_hMuonVec.push_back(hmu_momentumBalanceSignificance); 
            hmu_momentumLossPull = new TH1F("hmu_momentumLossPull","hmu_momentumLossPull",100,0.0,40.0);
            m_hMuonVec.push_back(hmu_momentumLossPull); 
            hmu_id_d0_exPV = new TH1F("hmu_id_d0_exPV","hmu_id_d0_exPV",500,0.0,30.0);
            m_hMuonVec.push_back(hmu_id_d0_exPV); 
            hmu_id_z0_exPVsinTheta = new TH1F("hmu_id_z0_exPVsinTheta","hmu_id_z0_exPVsinTheta",500,0.0,30.0);
            m_hMuonVec.push_back(hmu_id_z0_exPVsinTheta); 
            hmu_matchchi2Overndof = new TH1F("hmu_matchchi2Overndof","hmu_matchchi2Overndof",400,0.0,100.0);
            m_hMuonVec.push_back(hmu_matchchi2Overndof); 
            hmu_scatteringCurvatureSignificance = new TH1F("hmu_scatteringCurvatureSignificance","hmu_scatteringCurvatureSignificance",100,0.0,40.0);
            m_hMuonVec.push_back(hmu_scatteringCurvatureSignificance); 
            hmu_z0_vx_z_diff = new TH1F("hmu_z0_vx_z_diff","hmu_z0_vx_z_diff",100,0.0,30.0); 
            m_hMuonVec.push_back(hmu_z0_vx_z_diff); 

        }

        else if(strcmp(name.c_str(),"muid")==0){

            m_isMuidChain = true;
            std::cout << "[MuonAnalysis::MuonAnalysis] Running on " << name << " muons." << std::endl;

            hmu_muid_medium = new TH1I("hmu_muid_medium","hmu_muid_medium",5,0,2);
            m_hMuonVec.push_back(hmu_muid_medium); 
            hmu_muid_author = new TH1I("hmu_muid_author","hmu_muid_author",60,0,30);
            m_hMuonVec.push_back(hmu_muid_author); 
            hmu_muid_nPixHits = new TH1I("hmu_muid_nPixHits","hmu_muid_nPixHits",40,0,20);
            m_hMuonVec.push_back(hmu_muid_nPixHits); 
            hmu_muid_nBLHits = new TH1I("hmu_muid_nBLHits","hmu_muid_nBLHits",40,0,20);
            m_hMuonVec.push_back(hmu_muid_nBLHits); 
            hmu_muid_nSCTHits = new TH1I("hmu_muid_nSCTHits","hmu_muid_nSCTHits",40,0,20);
            m_hMuonVec.push_back(hmu_muid_nSCTHits); 
            hmu_muid_nPixSCTHoles = new TH1I("hmu_muid_nPixSCTHoles","hmu_muid_nPixSCTHoles",40,0,20);
            m_hMuonVec.push_back(hmu_muid_nPixSCTHoles); 
            hmu_muid_isCombinedMuon = new TH1I("hmu_muid_isCombinedMuon","hmu_muid_isCombinedMuon",5,0,2);
            m_hMuonVec.push_back(hmu_muid_isCombinedMuon); 

            hmu_muid_momentumBalanceSignificance = new TH1F("hmu_muid_momentumBalanceSignificance","hmu_muid_momentumBalanceSignificance",100,0.0,40.0);
            m_hMuonVec.push_back(hmu_muid_momentumBalanceSignificance); 
            hmu_muid_momentumLossPull = new TH1F("hmu_muid_momentumLossPull","hmu_muid_momentumLossPull",100,0.0,40.0);
            m_hMuonVec.push_back(hmu_muid_momentumLossPull); 
            hmu_muid_id_d0_exPV = new TH1F("hmu_muid_id_d0_exPV","hmu_muid_id_d0_exPV",500,0.0,30.0);
            m_hMuonVec.push_back(hmu_muid_id_d0_exPV); 
            hmu_muid_id_z0_exPVsinTheta = new TH1F("hmu_muid_id_z0_exPVsinTheta","hmu_muid_id_z0_exPVsinTheta",500,0.0,30.0);
            m_hMuonVec.push_back(hmu_muid_id_z0_exPVsinTheta); 
            hmu_muid_matchchi2Overndof = new TH1F("hmu_muid_matchchi2Overndof","hmu_muid_matchchi2Overndof",400,0.0,100.0);
            m_hMuonVec.push_back(hmu_muid_matchchi2Overndof); 
            hmu_muid_scatteringCurvatureSignificance = new TH1F("hmu_muid_scatteringCurvatureSignificance","hmu_muid_scatteringCurvatureSignificance",100,0.0,40.0);
            m_hMuonVec.push_back(hmu_muid_scatteringCurvatureSignificance); 
            hmu_muid_z0_vx_z_diff = new TH1F("hmu_muid_z0_vx_z_diff","hmu_muid_z0_vx_z_diff",100,0.0,30.0); 
            m_hMuonVec.push_back(hmu_muid_z0_vx_z_diff); 
            hmu_muid_EF_mu8_dR = new TH1I("hmu_muid_EF_mu8_dR","hmu_muid_EF_mu8_dR",1e3,0.0,10.0);
            m_hMuonVec.push_back(hmu_muid_EF_mu8_dR);

        }
        else if(strcmp(name.c_str(),"staco")==0){

            m_isStacoChain = true;
            std::cout << "[MuonAnalysis::MuonAnalysis] Running on " << name << " muons." << std::endl;

            hmu_staco_medium = new TH1I("hmu_staco_medium","hmu_staco_medium",5,0,2);
            m_hMuonVec.push_back(hmu_staco_medium); 
            hmu_staco_author = new TH1I("hmu_staco_author","hmu_staco_author",60,0,30);
            m_hMuonVec.push_back(hmu_staco_author); 
            hmu_staco_nPixHits = new TH1I("hmu_staco_nPixHits","hmu_staco_nPixHits",40,0,20);
            m_hMuonVec.push_back(hmu_staco_nPixHits); 
            hmu_staco_nBLHits = new TH1I("hmu_staco_nBLHits","hmu_staco_nBLHits",40,0,20);
            m_hMuonVec.push_back(hmu_staco_nBLHits); 
            hmu_staco_nSCTHits = new TH1I("hmu_staco_nSCTHits","hmu_staco_nSCTHits",40,0,20);
            m_hMuonVec.push_back(hmu_staco_nSCTHits); 
            hmu_staco_nPixSCTHoles = new TH1I("hmu_staco_nPixSCTHoles","hmu_staco_nPixSCTHoles",40,0,20);
            m_hMuonVec.push_back(hmu_staco_nPixSCTHoles); 
            hmu_staco_isCombinedMuon = new TH1I("hmu_staco_isCombinedMuon","hmu_staco_isCombinedMuon",5,0,2);
            m_hMuonVec.push_back(hmu_staco_isCombinedMuon); 

            hmu_staco_momentumBalanceSignificance = new TH1F("hmu_staco_momentumBalanceSignificance","hmu_staco_momentumBalanceSignificance",100,0.0,40.0);
            m_hMuonVec.push_back(hmu_staco_momentumBalanceSignificance); 
            hmu_staco_momentumLossPull = new TH1F("hmu_staco_momentumLossPull","hmu_staco_momentumLossPull",100,0.0,40.0);
            m_hMuonVec.push_back(hmu_staco_momentumLossPull); 
            hmu_staco_id_d0_exPV = new TH1F("hmu_staco_id_d0_exPV","hmu_staco_id_d0_exPV",500,0.0,30.0);
            m_hMuonVec.push_back(hmu_staco_id_d0_exPV); 
            hmu_staco_id_z0_exPVsinTheta = new TH1F("hmu_staco_id_z0_exPVsinTheta","hmu_staco_id_z0_exPVsinTheta",500,0.0,30.0);
            m_hMuonVec.push_back(hmu_staco_id_z0_exPVsinTheta); 
            hmu_staco_matchchi2Overndof = new TH1F("hmu_staco_matchchi2Overndof","hmu_staco_matchchi2Overndof",400,0.0,100.0);
            m_hMuonVec.push_back(hmu_staco_matchchi2Overndof); 
            hmu_staco_scatteringCurvatureSignificance = new TH1F("hmu_staco_scatteringCurvatureSignificance","hmu_staco_scatteringCurvatureSignificance",100,0.0,40.0);
            m_hMuonVec.push_back(hmu_staco_scatteringCurvatureSignificance); 
            hmu_staco_z0_vx_z_diff = new TH1F("hmu_staco_z0_vx_z_diff","hmu_staco_z0_vx_z_diff",100,0.0,30.0); 
            m_hMuonVec.push_back(hmu_staco_z0_vx_z_diff); 
            hmu_staco_EF_mu8_dR = new TH1I("hmu_staco_EF_mu8_dR","hmu_staco_EF_mu8_dR",1e3,0.0,10.0);
            m_hMuonVec.push_back(hmu_staco_EF_mu8_dR);

        }
        else {
            std::cout << "[MuonAnalysis::MuonAnalysis] Error. Please choose either mu, muid, or staco." << std::endl; exit(0);
        }

}

MuonAnalysis::~MuonAnalysis() {
  std::cout << "[MuonAnalysis::MuonAnalysis] Dtor: Clean up." << std::endl;
  // Free memory from vector of muons vars
  for(std::map<std::string,std::vector<float>* >::iterator it=m_fBranches.begin(); 
      it!=m_fBranches.end(); ++it)  delete it->second;
  for(std::map<std::string,std::vector<int>* >::iterator it=m_iBranches.begin();
      it!=m_iBranches.end(); ++it)  delete it->second;
  for(std::map<std::string, std::vector<std::vector<float> >* >::iterator it=m_fLeaves.begin();
          it!=m_fLeaves.end(); ++it) delete it->second;
  for(std::map<std::string, std::vector<std::vector<int> >* >::iterator it=m_iLeaves.begin();
          it!=m_iLeaves.end(); ++it) delete it->second;
}

void MuonAnalysis::SetOutputBranches(TTree* outputTree) {
    
    if(m_isMuChain) { 
        outputTree->Branch(std::string("mu_n").c_str(),&numMuMuon);
        outputTree->Branch(std::string("mu_rec_tag_n").c_str(),&numRecTags);
    }
    else if (m_isStacoChain) outputTree->Branch(std::string("staco_n").c_str(),&numStacoMuon);
    else if (m_isMuidChain)outputTree->Branch(std::string("muid_n").c_str(),&numMuidMuon);
    else {
        std::cout << "[MuonAnalysis::SetOutputBranches] Error: Please specify whether running on mu, muid, or staco muons." << std::endl; 
        exit(0);
    }

    // Floats
    for(std::map<std::string, std::vector<float>* >::iterator itr=m_fBranches.begin();
            itr!=m_fBranches.end(); ++itr) {

        // Allocate memory to store values
        std::vector<float>* vptr = new std::vector<float>();
        m_fBranches[itr->first] = vptr;

        // Assign a new branch with address to vptr
        outputTree->Branch(std::string(name+"_"+itr->first).c_str(), "std::vector<float>", &(m_fBranches[itr->first]) );
    }

    for(std::map<std::string, std::vector<std::vector<float> >* >::iterator itr=m_fLeaves.begin();
            itr!=m_fLeaves.end(); ++itr){

        std::vector<std::vector<float> >* p_vv = new std::vector<std::vector<float> >();
        m_fLeaves[itr->first] = p_vv;
        outputTree->Branch(std::string(name+"_"+itr->first).c_str(), "std::vector<std::vector<float> >", &(m_fLeaves[itr->first]) );
    }

    // Ints
    for(std::map<std::string, std::vector<int>* >::iterator itr=m_iBranches.begin();
            itr!=m_iBranches.end(); ++itr) {

        // Allocate memory to store values
        std::vector<int>* vptr = new std::vector<int>();
        m_iBranches[itr->first] = vptr;

        // Assign a new branch with address to vptr
        outputTree->Branch(std::string(name+"_"+itr->first).c_str(), "std::vector<int>", &(m_iBranches[itr->first]) );
    }

    for(std::map<std::string, std::vector<std::vector<int> >* >::iterator itr=m_iLeaves.begin();
            itr!=m_iLeaves.end(); ++itr){

        std::vector<std::vector<int> >* p_vv = new std::vector<std::vector<int> >();
        m_iLeaves[itr->first] = p_vv;
        outputTree->Branch(std::string(name+"_"+itr->first).c_str(), "std::vector<std::vector<int> >", &(m_iLeaves[itr->first]) );
    }
}

void MuonAnalysis::ActivateMuonBranches(HeavyIonD3PD* HID3PD, int entry){
    
  if(m_isMuChain){
      HID3PD->ActivateMuBranches(entry);
  }
  else if(m_isMuidChain){
      HID3PD->ActivateMuidBranches(entry);
  }
  else if(m_isStacoChain){
      HID3PD->ActivateStacoBranches(entry);
  }

}

bool MuonAnalysis::isMediumMuidMuon(HeavyIonD3PD* HID3PD, int imu){
    int quality = 0;
	if(HID3PD->mu_muid_medium->at(imu)) ++quality; else return false;
    return true;
}

bool MuonAnalysis::isMediumStacoMuon(HeavyIonD3PD* HID3PD, int imu){
    int quality = 0;
	if(HID3PD->mu_staco_medium->at(imu)) ++quality; else return false;
    return true;
}

/// medium+ recommendation from  
/// https://twiki.cern.ch/twiki/bin/view/AtlasProtected/MuonsQualityDefinition
bool MuonAnalysis::isMediumMuMuon(HeavyIonD3PD* HID3PD, int imu){

	int quality = 0;
	//1
	if(HID3PD->mu_medium->at(imu)) ++quality; else return false;
	//2
	if (
		(HID3PD->mu_author->at(imu)==11&&HID3PD->mu_nprecisionLayers->at(imu)>2&&fabs(HID3PD->mu_eta->at(imu))>2.5)||   // SA
		(HID3PD->mu_author->at(imu)==6)||   //STACO CB
		(HID3PD->mu_author->at(imu)==12&&HID3PD->mu_momentumBalanceSignificance->at(imu)<4.)||   //MUID CB
		(HID3PD->mu_author->at(imu)==13&&HID3PD->mu_momentumBalanceSignificance->at(imu)<4.&&HID3PD->mu_isCombinedMuon->at(imu))   //Mugirl CB
	) ++quality; else return false;
    return true;
}

bool MuonAnalysis::isGoodMuMuon(HeavyIonD3PD* HID3PD, int imu){

	int quality = 0;
	//1
	if(HID3PD->mu_medium->at(imu)) ++quality; else return false;
	//2
    // medium+ recommendation from  
    // https://twiki.cern.ch/twiki/bin/view/AtlasProtected/MuonsQualityDefinition
	if (
		(HID3PD->mu_author->at(imu)==11&&HID3PD->mu_nprecisionLayers->at(imu)>2&&fabs(HID3PD->mu_eta->at(imu))>2.5)||   // SA
		(HID3PD->mu_author->at(imu)==6)||   //STACO CB
		(HID3PD->mu_author->at(imu)==12&&HID3PD->mu_momentumBalanceSignificance->at(imu)<4.)||   //MUID CB
		(HID3PD->mu_author->at(imu)==13&&HID3PD->mu_momentumBalanceSignificance->at(imu)<4.&&HID3PD->mu_isCombinedMuon->at(imu))   //Mugirl CB
	) ++quality; else return false;
	//3
	if(HID3PD->mu_nPixHits->at(imu)>0) ++quality; else return false;
	//4
	if((!HID3PD->mu_expectBLayerHit->at(imu))||(HID3PD->mu_nBLHits->at(imu)>0)) ++quality; else return false;
	//5
	if(HID3PD->mu_nSCTHits->at(imu)>5) ++quality; else return false;
	//6
	if((HID3PD->mu_nPixHoles->at(imu)+HID3PD->mu_nSCTHoles->at(imu))<3) ++quality; else return false;
	//7
	if(fabs(HID3PD->mu_id_d0_exPV->at(imu))<5.0) ++quality; else return false;
	//8
	if(fabs(HID3PD->mu_id_z0_exPV->at(imu))*TMath::Sin(HID3PD->mu_id_theta_exPV->at(imu))<5.0) ++quality; else return false; 
	//9
	if(fabs(HID3PD->mu_eta->at(imu))<2.7) ++quality; else return false;
	//10
	if(HID3PD->mu_matchchi2->at(imu)/HID3PD->mu_matchndof->at(imu)<10.0) ++quality; else return false;
	// combined muon cuts
	//if(fabs(1.0/HID3PD->mu_id_qoverp_exPV->at(imu))>0.0) ++quality; else return false;
	//if(fabs(1.0/HID3PD->mu_me_qoverp_exPV->at(imu))>0.0) ++quality; else return false;
	//11
	if(HID3PD->mu_isCombinedMuon->at(imu)) ++quality; else return false;
	// Additional cuts from pp Asymmetry Internal Note
	if(fabs((HID3PD->mu_me_qoverp->at(imu) - HID3PD->mu_id_qoverp->at(imu))/HID3PD->mu_me_qoverp->at(imu))<0.5) ++quality; else return false;
	//12
	if(fabs(HID3PD->mu_scatteringCurvatureSignificance->at(imu))<4.0) ++quality; else return false;
	//13
	//if(fabs(HID3PD->mu_z0_exPV->at(imu)-vx_z->at(0)) < 10.0) ++quality; else return false;
	return true;
}

bool MuonAnalysis::isGoodMuidMuon(HeavyIonD3PD* HID3PD, int imu){

	int quality = 0;
	//1
	if(HID3PD->mu_muid_medium->at(imu)) ++quality; else return false;
	//2
	/*if (
		(HID3PD->mu_muid_author->at(imu)==11&&HID3PD->mu_muid_nprecisionLayers->at(imu)>2&&fabs(HID3PD->mu_muid_eta->at(imu))>2.5)||   // SA
		(HID3PD->mu_muid_author->at(imu)==6)||   //STACO CB
		(HID3PD->mu_muid_author->at(imu)==12&&HID3PD->mu_muid_momentumBalanceSignificance->at(imu)<4.)||   //MUID CB
		(HID3PD->mu_muid_author->at(imu)==13&&HID3PD->mu_muid_momentumBalanceSignificance->at(imu)<4.&&HID3PD->mu_muid_isCombinedMuon->at(imu))   //Mugirl CB
	) ++quality; else return false;
    */
	//3
	if(HID3PD->mu_muid_nPixHits->at(imu)>0) ++quality; else return false;
	//4
	if((!HID3PD->mu_muid_expectBLayerHit->at(imu))||(HID3PD->mu_muid_nBLHits->at(imu)>0)) ++quality; else return false;
	//5
	if(HID3PD->mu_muid_nSCTHits->at(imu)>5) ++quality; else return false;
	//6
	if((HID3PD->mu_muid_nPixHoles->at(imu)+HID3PD->mu_muid_nSCTHoles->at(imu))<3) ++quality; else return false;
	//7
	if(fabs(HID3PD->mu_muid_id_d0_exPV->at(imu))<5.0) ++quality; else return false;
	//8
	if(fabs(HID3PD->mu_muid_id_z0_exPV->at(imu))*TMath::Sin(HID3PD->mu_muid_id_theta_exPV->at(imu))<5.0) ++quality; else return false; 
	//9
	if(fabs(HID3PD->mu_muid_eta->at(imu))<2.7) ++quality; else return false;
	//10
	if(HID3PD->mu_muid_matchchi2->at(imu)/HID3PD->mu_muid_matchndof->at(imu)<10.0) ++quality; else return false;
	// combined muon cuts
	//if(fabs(1.0/HID3PD->mu_muid_id_qoverp_exPV->at(imu))>0.0) ++quality; else return false;
	//if(fabs(1.0/HID3PD->mu_muid_me_qoverp_exPV->at(imu))>0.0) ++quality; else return false;
	//11
	if(HID3PD->mu_muid_isCombinedMuon->at(imu)) ++quality; else return false;
	// Additional cuts from pp Asymmetry Internal Note
	if(fabs((HID3PD->mu_muid_me_qoverp->at(imu)-HID3PD->mu_muid_id_qoverp->at(imu))/HID3PD->mu_muid_me_qoverp->at(imu))<0.5) ++quality; else return false;
	//12
	if(fabs(HID3PD->mu_muid_scatteringCurvatureSignificance->at(imu))<4.0) ++quality; else return false;
	//13
	//if(fabs(HID3PD->mu_muid_z0_exPV->at(imu)-vx_z->at(0)) < 10.0) ++quality; else return false;
    return true;
}

bool MuonAnalysis::isGoodStacoMuon(HeavyIonD3PD* HID3PD, int imu){

	int quality = 0;
	//1
	if(HID3PD->mu_staco_medium->at(imu)) ++quality; else return false;
	//2
	/*if (
		(HID3PD->mu_staco_author->at(imu)==11&&HID3PD->mu_staco_nprecisionLayers->at(imu)>2&&fabs(HID3PD->mu_staco_eta->at(imu))>2.5)||   // SA
		(HID3PD->mu_staco_author->at(imu)==6)||   //STACO CB
		(HID3PD->mu_staco_author->at(imu)==12&&HID3PD->mu_staco_momentumBalanceSignificance->at(imu)<4.)||   //MUID CB
		(HID3PD->mu_staco_author->at(imu)==13&&HID3PD->mu_staco_momentumBalanceSignificance->at(imu)<4.&&HID3PD->mu_staco_isCombinedMuon->at(imu))   //Mugirl CB
	) ++quality; else return false;
    */
	//3
	if(HID3PD->mu_staco_nPixHits->at(imu)>0) ++quality; else return false;
	//4
	if((!HID3PD->mu_staco_expectBLayerHit->at(imu))||(HID3PD->mu_staco_nBLHits->at(imu)>0)) ++quality; else return false;
	//5
	if(HID3PD->mu_staco_nSCTHits->at(imu)>5) ++quality; else return false;
	//6
	if((HID3PD->mu_staco_nPixHoles->at(imu)+HID3PD->mu_staco_nSCTHoles->at(imu))<3) ++quality; else return false;
	//7
	if(fabs(HID3PD->mu_staco_id_d0_exPV->at(imu))<5.0) ++quality; else return false;
	//8
	if(fabs(HID3PD->mu_staco_id_z0_exPV->at(imu))*TMath::Sin(HID3PD->mu_staco_id_theta_exPV->at(imu))<5.0) ++quality; else return false; 
	//9
	if(fabs(HID3PD->mu_staco_eta->at(imu))<2.7) ++quality; else return false;
	//10
	if(HID3PD->mu_staco_matchchi2->at(imu)/HID3PD->mu_staco_matchndof->at(imu)<10.0) ++quality; else return false;
	// combined muon cuts
	//if(fabs(1.0/HID3PD->mu_staco_id_qoverp_exPV->at(imu))>0.0) ++quality; else return false;
	//if(fabs(1.0/HID3PD->mu_staco_me_qoverp_exPV->at(imu))>0.0) ++quality; else return false;
	//11
	if(HID3PD->mu_staco_isCombinedMuon->at(imu)) ++quality; else return false;
	// Additional cuts from pp Asymmetry Internal Note
	if(fabs((HID3PD->mu_staco_me_qoverp->at(imu)-HID3PD->mu_staco_id_qoverp->at(imu))/HID3PD->mu_staco_me_qoverp->at(imu))<0.5) ++quality; else return false;
	//12
	if(fabs(HID3PD->mu_staco_scatteringCurvatureSignificance->at(imu))<4.0) ++quality; else return false;
	//13
	//if(fabs(HID3PD->mu_staco_z0_exPV->at(imu)-vx_z->at(0)) < 10.0) ++quality; else return false;
    return true;
}

// MS probes for measuring muon trigger efficiency
void MuonAnalysis::trigProbes(HeavyIonD3PD* HID3PD, int itag){

	int nProbes = 0;
    // Each probe may or may not be matched to an online trigger object 
    std::vector<int> vProbeMatched;
    // Each probe has pT, eta, phi, and charge
    std::vector<float> vProbeEta;
    std::vector<float> vProbePhi;
    std::vector<float> vProbePt;
    std::vector<float> vProbeCh;
	// Use muon "tracks" for probe
	for(int iprobe=0; iprobe<HID3PD->mu_n; ++iprobe){

      // if probe is same muon as tag, skip it
      if(itag==iprobe) continue;
	  // Cuts on the probe
	  float mu_me_eta = -1.0*TMath::Log(TMath::Tan(HID3PD->mu_me_theta->at(iprobe)/2.0));
	  float mu_me_pt  = fabs(1.0/HID3PD->mu_me_qoverp->at(iprobe))/TMath::CosH(mu_me_eta)*1.0e-3;
	  if(
	     !(fabs(mu_me_eta)<2.5) || 
	     !(mu_me_pt > 10.0)
        ) continue;

	  //construct 4-vector of tag and MS probe
	  TLorentzVector vtag,vprobe, vsum;
	  vtag.SetPtEtaPhiM(HID3PD->mu_pt->at(itag)*1.0e-3,HID3PD->mu_eta->at(itag),HID3PD->mu_phi->at(itag),0.105658);
	  vprobe.SetPtEtaPhiM(mu_me_pt,mu_me_eta,HID3PD->mu_me_phi->at(iprobe),0.105658);
	  vsum = vtag+vprobe;
	  // Must be within 10 GeV of Z pole
	  if(!(fabs(vsum.M()-91.1876)<15.0)) continue;
      if(!(fabs(HID3PD->mu_me_phi->at(iprobe)-HID3PD->mu_phi->at(itag))>2.0)) continue;
	  // We've found a probe
	  //std::cout << "[MuonAnalysis::trigProbes] Probe found! " << std::endl;
	  ++nProbes;

	  float chargeTemp = mu_me_pt*TMath::CosH(mu_me_eta)*HID3PD->mu_me_qoverp->at(iprobe)/1.0e-3;
      vProbeCh.push_back(chargeTemp);
      vProbeEta.push_back(mu_me_eta);
      vProbePt.push_back(mu_me_pt);
      vProbePhi.push_back(HID3PD->mu_me_phi->at(iprobe));

	  // Now match probe to an online muon trigger object in dR<m_dRCut
	  bool matched = false;
      matched = matchEF_mu8(HID3PD,iprobe);
      vProbeMatched.push_back(matched);

    }//iprobe

	// Number of probes found for this tag (>=0)
    m_iBranches["trig_EF_mu8_probe_n"]->push_back(nProbes);
    // Safety: Prevent empty vectors
    if(nProbes==0) {
        if(vProbeMatched.size()     > 0 
                || vProbePt.size()  > 0
                || vProbeEta.size() > 0
                || vProbePhi.size() > 0
                || vProbeCh.size()  > 0
          ) std::cout << "[MuonAnalysis::trigProbes] WARNING: Undefined behavior in T&P. Please check your macro." << std::endl;
        
        vProbeMatched.push_back(-999);
        vProbePt.push_back(-999.);
        vProbeEta.push_back(-999.);
        vProbePhi.push_back(-999.);
        vProbeCh.push_back(-999.);
    }

    m_iLeaves["trig_EF_mu8_probe_isMatched"]->push_back(vProbeMatched);
    m_fLeaves["trig_EF_mu8_probe_pt"]->push_back(vProbePt);
    m_fLeaves["trig_EF_mu8_probe_eta"]->push_back(vProbeEta);
    m_fLeaves["trig_EF_mu8_probe_phi"]->push_back(vProbePhi);
    m_fLeaves["trig_EF_mu8_probe_charge"]->push_back(vProbeCh);

}//

// MS probes for measuring muon-track ID efficiency
// epsilon(ID)
void MuonAnalysis::recMSProbes(HeavyIonD3PD* HID3PD, int itag){
	int nProbes = 0;
    // Each probe may or may not be matched to an MS track
    std::vector<int> vProbeMatched;
    // Each probe has pT, eta, phi, and charge
    std::vector<float> vProbeEta;
    std::vector<float> vProbePhi;
    std::vector<float> vProbePt;
    std::vector<float> vProbeCh;

	// Use muon "tracks" for probe
	for(int iprobe=0; iprobe<HID3PD->mu_n; ++iprobe){

      // if probe is same muon as tag, skip it
      if(itag==iprobe) continue;
	  // Cuts on the probe
	  float mu_me_eta = -1.0*TMath::Log(TMath::Tan(HID3PD->mu_me_theta->at(iprobe)/2.0));
	  float mu_me_pt  = fabs(1.0/HID3PD->mu_me_qoverp->at(iprobe))/TMath::CosH(mu_me_eta)*1.0e-3;
	  if(
	     !(fabs(mu_me_eta)<2.5) || 
	     !(mu_me_pt > 10.0)
        ) continue;

	  //construct 4-vector of tag and MS probe
	  TLorentzVector vtag,vprobe, vsum;
	  vtag.SetPtEtaPhiM(HID3PD->mu_pt->at(itag)*1.0e-3,HID3PD->mu_eta->at(itag),HID3PD->mu_phi->at(itag),0.105658);
	  vprobe.SetPtEtaPhiM(mu_me_pt,mu_me_eta,HID3PD->mu_me_phi->at(iprobe),0.105658);
	  vsum = vtag+vprobe;
	  // Must be within 10 GeV of Z pole
	  if(!(fabs(vsum.M()-91.1876)<15.0)) continue;
      if(!(fabs(HID3PD->mu_me_phi->at(iprobe)-HID3PD->mu_phi->at(itag))>2.0)) continue;
	  // We've found a probe
	  //std::cout << "[MuonAnalysis::recMSProbes] Probe found! " << std::endl;
	  ++nProbes;

	  float chargeTemp = mu_me_pt*TMath::CosH(mu_me_eta)*HID3PD->mu_me_qoverp->at(iprobe)/1.0e-3;
      vProbeCh.push_back(chargeTemp);
      vProbeEta.push_back(mu_me_eta);
      vProbePt.push_back(mu_me_pt);
      vProbePhi.push_back(HID3PD->mu_me_phi->at(iprobe));

	  // Now match probe to an ID track within dR<0.05
	  bool matched = false;
	  for(int imatch=0; imatch<HID3PD->trk_n; ++imatch){

	     // Match to a good track
	     if(!(HID3PD->isGoodTrack(imatch))) continue;
	     // Probe must be same sign as track 
         float chargeMatch = HID3PD->trk_pt->at(imatch)*TMath::CosH(HID3PD->trk_eta->at(imatch))*HID3PD->trk_qoverp->at(imatch);
	     if(!(chargeTemp*chargeMatch>0.0)) continue;
	     // dR of probe and track
	     float dphi = HID3PD->mu_me_phi->at(iprobe)-HID3PD->trk_phi->at(imatch);
	     float deta = mu_me_eta - HID3PD->trk_eta->at(imatch);
         float dR = TMath::Sqrt(TMath::Power(dphi,2)+TMath::Power(deta,2));

	     // If it's a match, break the loop.
	     // Otherwise, keep looking
	     if(dR<0.05){ 
	       matched = true; break;
	     }
      }//imatch
      vProbeMatched.push_back(matched);
    } // iprobe

	// Number of probes found for this tag (>=0)
    m_iBranches["rec_MSprobe_n"]->push_back(nProbes);
    // Prevent empty vectors
    if(nProbes==0) {
        if(vProbeMatched.size() > 0 
                || vProbePt.size() > 0
                || vProbeEta.size() > 0
                || vProbePhi.size() > 0
                || vProbeCh.size() > 0
          ) std::cout << "[MuonAnalysis::recMSProbes] WARNING: Undefined behavior in T&P. Please check your macro." << std::endl;
        
        vProbeMatched.push_back(-999);
        vProbePt.push_back(-999.);
        vProbeEta.push_back(-999.);
        vProbePhi.push_back(-999.);
        vProbeCh.push_back(-999.);
    }

    m_iLeaves["rec_MSprobe_isMatched"]->push_back(vProbeMatched);
    m_fLeaves["rec_MSprobe_pt"]->push_back(vProbePt);
    m_fLeaves["rec_MSprobe_eta"]->push_back(vProbeEta);
    m_fLeaves["rec_MSprobe_phi"]->push_back(vProbePhi);
    m_fLeaves["rec_MSprobe_charge"]->push_back(vProbeCh);
}

// ID probes for measuring MS and matching efficiency
// epsilon(type|ID) where type = CB or ST
void MuonAnalysis::recIDProbes(HeavyIonD3PD* HID3PD,int itag){
	// Set initial number of probes for this tag to zero
	int nProbes = 0;
    // Each probe may or may not be matched to an MS track
    std::vector<int> vProbeMatched;
    // Each probe has pT, eta, phi, and charge
    std::vector<float> vProbeEta;
    std::vector<float> vProbePhi;
    std::vector<float> vProbePt;
    std::vector<float> vProbeCh;

	for(int iprobe=0; iprobe<HID3PD->trk_n; ++iprobe){
	  // cuts on the probe
	  if(
		!(HID3PD->isGoodTrack(iprobe)) ||
		!(fabs(HID3PD->trk_eta->at(iprobe))<2.5) || 
		!(HID3PD->trk_pt->at(iprobe)*1.0e-3 > 10.0) 
        ) continue;

	  //construct 4-vector of (CB) tag and ID probe
	  TLorentzVector vtag,vprobe, vsum;
	  vtag.SetPtEtaPhiM(HID3PD->mu_pt->at(itag)*1.0e-3,HID3PD->mu_eta->at(itag),HID3PD->mu_phi->at(itag),0.105658);
	  vprobe.SetPtEtaPhiM(HID3PD->trk_pt->at(iprobe)*1.0e-3,HID3PD->trk_eta->at(iprobe),HID3PD->trk_phi->at(iprobe),0.105658);
	  vsum = vtag+vprobe;
	  // Must be within 10 GeV of Z pole
	  if(!(fabs(vsum.M()-91.1876)<15.0)) continue;
      if(!(fabs(HID3PD->trk_phi->at(iprobe)-HID3PD->mu_phi->at(itag))>2.0)) continue;
	  // We've found a probe
      //std::cout << "[MuonAnalysis::recIDProbes] Probe found." << std::endl;
	  ++nProbes;
      vProbeEta.push_back(HID3PD->trk_eta->at(iprobe));
      vProbePt.push_back(HID3PD->trk_pt->at(iprobe)*1.0e-3);
      vProbePhi.push_back(HID3PD->trk_phi->at(iprobe));
	  float chargeTemp = HID3PD->trk_pt->at(iprobe)*TMath::CosH(HID3PD->trk_eta->at(iprobe))*HID3PD->trk_qoverp->at(iprobe);
      vProbeCh.push_back(chargeTemp);

	  // Now match the probe to a muon track type (CB,ST) 
	  // in dR<0.01  
	  bool matched = false;
	  for(int imatch=0; imatch<HID3PD->mu_n; ++imatch){
         // don't use same muon being used as tag
         if(imatch == itag) continue;
	     // Match to combined muon
	     if(!(HID3PD->mu_isCombinedMuon->at(imatch))) continue;
	     // Probe must be same sign as muon track
	     if(!(chargeTemp*HID3PD->mu_charge->at(imatch)>0.0)) continue;
	     // dR of probe and muon track
	     float dphi = HID3PD->trk_phi->at(iprobe) - HID3PD->mu_phi->at(imatch);
	     float deta = HID3PD->trk_eta->at(iprobe) - HID3PD->mu_eta->at(imatch);
	     float dR = TMath::Sqrt(TMath::Power(dphi,2)+TMath::Power(deta,2));
	     // If it's a match, break the loop.
	     // Otherwise, keep looking
	     if(dR<0.05){ 
	       matched = true; break;
	     }

      }//imatch
      vProbeMatched.push_back(matched);
    } //iprobe

	// Number of probes found for this tag (>=0)
    m_iBranches["rec_IDprobe_n"]->push_back(nProbes);
    // Prevent empty vectors
    if(nProbes==0) {
        if(vProbeMatched.size() > 0 
                || vProbePt.size() > 0
                || vProbeEta.size() > 0
                || vProbePhi.size() > 0
                || vProbeCh.size() > 0
          ) std::cout << "[MuonAnalysis::recIDProbes] WARNING: Undefined behavior in T&P. Please check your macro." << std::endl;
        
        vProbeMatched.push_back(-999);
        vProbePt.push_back(-999.);
        vProbeEta.push_back(-999.);
        vProbePhi.push_back(-999.);
        vProbeCh.push_back(-999.);
    }

    m_iLeaves["rec_IDprobe_isMatched"]->push_back(vProbeMatched);
    m_fLeaves["rec_IDprobe_pt"]->push_back(vProbePt);
    m_fLeaves["rec_IDprobe_eta"]->push_back(vProbeEta);
    m_fLeaves["rec_IDprobe_phi"]->push_back(vProbePhi);
    m_fLeaves["rec_IDprobe_charge"]->push_back(vProbeCh);
}

bool MuonAnalysis::matchEF_mu8(HeavyIonD3PD* HID3PD, int imu){

	// offline muon phi,eta at MS
	float muonMSPhi = -999.; 
    float muonMSEta = -999.;
    float muonCharge = -999.;
    if(m_isMuChain) {
        muonMSPhi = HID3PD->mu_me_phi->at(imu);
        muonMSEta = -1.*TMath::Log(TMath::Tan(HID3PD->mu_me_theta->at(imu)/2.));
        muonCharge = HID3PD->mu_charge->at(imu);
    }
    else if(m_isMuidChain) {
        muonMSPhi = HID3PD->mu_muid_me_phi->at(imu);
        muonMSEta = -1.*TMath::Log(TMath::Tan(HID3PD->mu_muid_me_theta->at(imu)/2.));
        muonCharge = HID3PD->mu_muid_charge->at(imu);
    }
    else if(m_isStacoChain) {
        muonMSPhi = HID3PD->mu_staco_me_phi->at(imu);
        muonMSEta = -1.*TMath::Log(TMath::Tan(HID3PD->mu_staco_me_theta->at(imu)/2.));
        muonCharge = HID3PD->mu_staco_charge->at(imu);
    }

	float dR = 9999.;
	bool flag = false;

	// Loop over ALL online muon trigger objects
	for(int itrig = 0; itrig < HID3PD->trig_EF_trigmuonef_n; ++itrig){

		// Is this an online trigger object for EF_mu8?
		int mu8Object = HID3PD->trig_EF_trigmuonef_EF_mu8->at(itrig);	
		if(mu8Object==1) {

			// Number of tracks in trigger's ROI
			int nMuInRoi = HID3PD->trig_EF_trigmuonef_track_n->at(itrig);
			for(int iRoi = 0; iRoi<nMuInRoi; ++iRoi){

                // Does this track in the ROI have an MS hit?
				if(!(HID3PD->trig_EF_trigmuonef_track_MS_hasMS->at(itrig)[iRoi])) continue;

				float etaMu8 = HID3PD->trig_EF_trigmuonef_track_MS_eta->at(itrig)[iRoi]; 
				float phiMu8 = HID3PD->trig_EF_trigmuonef_track_MS_phi->at(itrig)[iRoi];
				float chargeMu8 = HID3PD->trig_EF_trigmuonef_track_MS_charge->at(itrig)[iRoi];
                // Make sure the offline-online charges are the same
				if(!(muonCharge==chargeMu8)) continue;

				float dEta = muonMSEta-etaMu8;
				float dPhi = muonMSPhi-phiMu8;
				if(dPhi>TMath::Pi()) {dPhi-=TMath::TwoPi();} if(dPhi<-1.*TMath::Pi()) {dPhi+=TMath::TwoPi();} //Fold between -PI,PI
				float dRTemp = TMath::Sqrt(TMath::Power(dEta,2)+TMath::Power(dPhi,2));

				if(m_isMuChain) hmu_EF_mu8_dR->Fill(dRTemp);
                else if(m_isMuidChain) hmu_muid_EF_mu8_dR->Fill(dRTemp);
				if(m_isStacoChain) hmu_staco_EF_mu8_dR->Fill(dRTemp);

				// Find smallest dR
				if(dRTemp<dR) dR = dRTemp;
            }//iRoi

			if(dR<m_dRCut) flag = true;
        }
        else continue;
    }//itrig
    return flag;
}


// Z Candidate if 2 high pT muons in event 
bool MuonAnalysis::isZCandidateType2(HeavyIonD3PD* HID3PD, int imu, std::vector<std::pair<int,int> >& Zpair){
    int nmu = -999.;
    float pt = 1.0e-3*HID3PD->mu_pt->at(imu);
    if(pt<20.0) return false;
    float pt2 = 15.0;
    if(m_isMuChain){
        nmu = HID3PD->mu_n;
        for(int imu2=0; imu2<nmu; ++imu2){
            if( !(isMediumMuMuon(HID3PD,imu2)) || (imu==imu2) ) continue;
            // Use only OS pairs 
            if(HID3PD->mu_charge->at(imu)==HID3PD->mu_charge->at(imu2)) continue;
            // Muon above 20GeV matched to muon > 15 GeV
            if(HID3PD->mu_pt->at(imu2)*1.0e-3 > pt2) {
                Zpair.push_back(std::make_pair(imu,imu2));
                return true;
            }
        }//imu2

        return false;
    }
    if(m_isMuidChain){
        nmu = HID3PD->mu_muid_n;
        for(int imu2=0; imu2<nmu; ++imu2){
            if( !(isMediumMuMuon(HID3PD,imu2)) || (imu==imu2) ) continue;
            // Use only OS pairs 
            if(HID3PD->mu_muid_charge->at(imu)==HID3PD->mu_muid_charge->at(imu2)) continue;
            if(HID3PD->mu_muid_pt->at(imu2)*1.0e-3 > pt2) {
                Zpair.push_back(std::make_pair(imu,imu2));
                return true;
            }
        }//imu2

        return false;
    }
    if(m_isStacoChain){
        nmu = HID3PD->mu_staco_n;
        for(int imu2=0; imu2<nmu; ++imu2){
            if( !(isMediumMuMuon(HID3PD,imu2)) || (imu==imu2) ) continue;
            // Use only OS pairs 
            if(HID3PD->mu_staco_charge->at(imu)==HID3PD->mu_staco_charge->at(imu2)) continue;
            if(HID3PD->mu_staco_pt->at(imu2)*1.0e-3 > pt2) {
                return true;
                Zpair.push_back(std::make_pair(imu,imu2));
            }
        }//imu2

        return false;
    }

    return false;
}

// Z Candidate if m_uu > 66 
bool MuonAnalysis::isZCandidateType1(HeavyIonD3PD* HID3PD, int imu){
    int nmu = -999.;

    if(m_isMuChain){
        nmu = HID3PD->mu_n;
        for(int imu2=0; imu2<nmu; ++imu2){
            if( !(isMediumMuMuon(HID3PD,imu2)) || (imu==imu2) ) continue;
            // Use only OS pairs 
            if(HID3PD->mu_charge->at(imu)==HID3PD->mu_charge->at(imu2)) continue;
            TLorentzVector vmu1,vmu2,vSum;
            vmu1.SetPxPyPzE(HID3PD->mu_px->at(imu),HID3PD->mu_py->at(imu),HID3PD->mu_pz->at(imu),HID3PD->mu_E->at(imu));
            vmu2.SetPxPyPzE(HID3PD->mu_px->at(imu2),HID3PD->mu_py->at(imu2),HID3PD->mu_pz->at(imu2),HID3PD->mu_E->at(imu2));
            vSum = vmu1+vmu2;
		    if(vSum.M()*1.0e-3 > 66.0) {return true;}
            
        }//imu2

        return false;
    }

    if(m_isMuidChain){
        nmu = HID3PD->mu_muid_n;

        for(int imu2=0; imu2<nmu; ++imu2){
            if( !(isMediumMuidMuon(HID3PD,imu2)) || (imu==imu2) ) continue;
            // Use only OS pairs 
            if(HID3PD->mu_muid_charge->at(imu)==HID3PD->mu_muid_charge->at(imu2)) continue;
            TLorentzVector vmu1,vmu2,vSum;
            vmu1.SetPxPyPzE(HID3PD->mu_muid_px->at(imu),HID3PD->mu_muid_py->at(imu),HID3PD->mu_muid_pz->at(imu),HID3PD->mu_muid_E->at(imu));
            vmu2.SetPxPyPzE(HID3PD->mu_muid_px->at(imu2),HID3PD->mu_muid_py->at(imu2),HID3PD->mu_muid_pz->at(imu2),HID3PD->mu_muid_E->at(imu2));
            vSum = vmu1+vmu2;
		    if(vSum.M()*1.0e-3 > 66.0) {return true;}
        }//imu2

        return false;
    }

    if(m_isStacoChain){
        nmu = HID3PD->mu_staco_n;

        for(int imu2=0; imu2<nmu; ++imu2){
            if( !(isMediumStacoMuon(HID3PD,imu2)) || (imu==imu2) ) continue;
            // Use only OS pairs 
            if(HID3PD->mu_staco_charge->at(imu)==HID3PD->mu_staco_charge->at(imu2)) continue;
            TLorentzVector vmu1,vmu2,vSum;
            vmu1.SetPxPyPzE(HID3PD->mu_staco_px->at(imu),HID3PD->mu_staco_py->at(imu),HID3PD->mu_staco_pz->at(imu),HID3PD->mu_staco_E->at(imu));
            vmu2.SetPxPyPzE(HID3PD->mu_staco_px->at(imu2),HID3PD->mu_staco_py->at(imu2),HID3PD->mu_staco_pz->at(imu2),HID3PD->mu_staco_E->at(imu2));
            vSum = vmu1+vmu2;
		    if(vSum.M()*1.0e-3 > 66.0) {return true;}
        }//imu2

        return false;
    }

    return false;

}

bool MuonAnalysis::isRecTagMuon(HeavyIonD3PD* HID3PD, int imu){
    if(
        fabs(HID3PD->mu_eta->at(imu))<2.5 
        && HID3PD->mu_pt->at(imu)*1.0e-3 > 0.0
        && HID3PD->mu_ptcone30->at(imu)/HID3PD->mu_pt->at(imu) < 0.2
        && matchEF_mu8(HID3PD,imu)
      ) return true;
    else return false;
}

void MuonAnalysis::LoopEvent(HeavyIonD3PD* HID3PD, int entry) {
  ClearVectors(); //Only clean single muon parameters
  numMuMuon = 0; numStacoMuon = 0; numMuidMuon = 0;
  numHiPtMuMuon = 0;
  numRecTags = 0;

  // Uncomment to read only select branches
  ActivateMuonBranches(HID3PD,entry);
  if(m_isMuChain){
    std::vector<int> vec_muon_index;
    std::vector<std::pair<int,int> > local_Z_pair;
    local_Z_pair.clear();
    vec_muon_index.clear();
    for(int i = 0; i < HID3PD->mu_n; ++i) {
        fillCtrlMuHistos(HID3PD,i);
        if(!isGoodMuMuon(HID3PD,i)) continue;
        numMuMuon++;
        // keep track of original indices
        vec_muon_index.push_back(i);

        // Trigger matching
        m_iBranches["EF_mu8_isMatched"]->push_back(matchEF_mu8(HID3PD,i));
        m_iBranches["ZCandidateType1"]->push_back(isZCandidateType1(HID3PD,i));
        m_iBranches["ZCandidateType2"]->push_back(isZCandidateType2(HID3PD,i,local_Z_pair));
        m_fBranches["E"]->push_back(HID3PD->mu_E->at(i)/1000.);
        m_fBranches["pt"]->push_back(HID3PD->mu_pt->at(i)/1000.);

	// High pt muon (20 GeV)
	if( (HID3PD->mu_pt->at(i)/1000.)>20.0 ) numHiPtMuMuon++;
        float phi_mu_met = HID3PD->mu_phi->at(i) - HID3PD->MET_RefFinal_phi;
		if(phi_mu_met>TMath::Pi()) phi_mu_met-=TMath::TwoPi(); if(phi_mu_met<-1.*TMath::Pi()) phi_mu_met+=TMath::TwoPi();
        m_fBranches["phi_mu_met"]->push_back(phi_mu_met);
        float mt = TMath::Sqrt(2.0*HID3PD->mu_pt->at(i)*HID3PD->MET_RefFinal_et*(1.0-TMath::Cos(phi_mu_met)));
        m_fBranches["mt"]->push_back(mt/1000.);
        m_fBranches["ptid"]->push_back(1/fabs(HID3PD->mu_id_qoverp_exPV->at(i))/1000.*sin(HID3PD->mu_id_theta_exPV->at(i)));
        m_fBranches["eta"]->push_back(HID3PD->mu_eta->at(i));
        m_fBranches["phi"]->push_back(HID3PD->mu_phi->at(i) );
        m_fBranches["m"]->push_back(HID3PD->mu_m->at(i)*1.e-3 );
        m_fBranches["beta"]->push_back(HID3PD->mu_beta->at(i) );
        m_fBranches["nucone20"]->push_back(HID3PD->mu_nucone20->at(i) );
        m_fBranches["nucone30"]->push_back(HID3PD->mu_nucone30->at(i) );
        m_fBranches["nucone40"]->push_back(HID3PD->mu_nucone40->at(i) );
        m_fBranches["ptcone20"]->push_back(HID3PD->mu_ptcone20->at(i)*1.e-3 );
        m_fBranches["ptcone30"]->push_back(HID3PD->mu_ptcone30->at(i)*1.e-3 );
        m_fBranches["ptcone40"]->push_back(HID3PD->mu_ptcone40->at(i)*1.e-3 );
        m_iBranches["charge"]->push_back(HID3PD->mu_charge->at(i) );
        m_fBranches["d0"]->push_back(HID3PD->mu_d0_exPV->at(i) );
        m_fBranches["z0"]->push_back(HID3PD->mu_z0_exPV->at(i) );
        m_fBranches["d0Sig"]->push_back(HID3PD->mu_d0_exPV->at(i)/sqrt(HID3PD->mu_cov_d0_exPV->at(i)) );
        m_fBranches["z0Sig"]->push_back(HID3PD->mu_z0_exPV->at(i)/sqrt(HID3PD->mu_cov_z0_exPV->at(i)) );
        m_fBranches["scatteringCurvatureSignificance"]->push_back(HID3PD->mu_scatteringCurvatureSignificance->at(i) );
        m_fBranches["momentumBalanceSignificance"]->push_back(HID3PD->mu_momentumBalanceSignificance->at(i) );
        float momLoss = fabs((HID3PD->mu_me_qoverp->at(i) - HID3PD->mu_id_qoverp->at(i))/HID3PD->mu_me_qoverp->at(i));
        m_fBranches["momentumLossPull"]->push_back(momLoss);

        float comp = fabs(momLoss)+0.07*fabs(HID3PD->mu_scatteringCurvatureSignificance->at(i));
        m_fBranches["comp"]->push_back(comp);

        if(m_doTruth){
            m_fBranches["rec_truth_dr"]->push_back(HID3PD->mu_truth_dr->at(i));
            m_fBranches["rec_truth_E"]->push_back(HID3PD->mu_truth_E->at(i)*1.e-3 );
            m_fBranches["rec_truth_pt"]->push_back(HID3PD->mu_truth_pt->at(i)*1.e-3 );
            m_fBranches["rec_truth_eta"]->push_back(HID3PD->mu_truth_eta->at(i));
            m_fBranches["rec_truth_phi"]->push_back(HID3PD->mu_truth_phi->at(i));
            m_iBranches["rec_truth_pdg"]->push_back(HID3PD->mu_truth_type->at(i));
            m_iBranches["rec_truth_mother_pdg"]->push_back(HID3PD->mu_truth_mothertype->at(i));
            m_iBranches["rec_truth_matched"]->push_back(HID3PD->mu_truth_matched->at(i));
        }//doTruth

        // T&P reco/trig efficiency
        // tags
        bool isRecTag = isRecTagMuon(HID3PD,i);
        m_iBranches["isTagMuon"]->push_back(isRecTag);
        if(isRecTag==true){ 
            // tag kinematics
            m_fBranches["tag_pt"]->push_back(HID3PD->mu_pt->at(i)/1000.);
            m_fBranches["tag_eta"]->push_back(HID3PD->mu_eta->at(i));
            m_fBranches["tag_phi"]->push_back(HID3PD->mu_phi->at(i));
            m_fBranches["tag_m"]->push_back(HID3PD->mu_m->at(i)*1.e-3);
            m_fBranches["tag_E"]->push_back(HID3PD->mu_E->at(i)/1000.);
            m_fBranches["tag_ptcone20"]->push_back(HID3PD->mu_ptcone20->at(i)*1.e-3 );
            m_fBranches["tag_ptcone30"]->push_back(HID3PD->mu_ptcone30->at(i)*1.e-3 );
            m_fBranches["tag_ptcone40"]->push_back(HID3PD->mu_ptcone40->at(i)*1.e-3 );
            m_iBranches["tag_charge"]->push_back(HID3PD->mu_charge->at(i) );
            // counter for #tags
            ++numRecTags;
            // probes
            recIDProbes(HID3PD,i);
            recMSProbes(HID3PD,i);
            trigProbes(HID3PD,i);
        }

        if( m_doTruth ) { 
            //m_iBranches["prompt"]->push_back( AssignMuonPrompt(HID3PD,i) );
            //m_fBranches["motherpt"]->push_back( m_motherpt );
            //m_iBranches["eventIndex"]->push_back( m_eventIndex );
        }
    }//i
    // recover tight Z candidates with pT>15GeV paired 
    // with tight muons with pT > 20 GeV
    for(int ipair=0; ipair<local_Z_pair.size(); ++ipair){
        // index in mu container
        int index = (local_Z_pair.at(ipair)).second;
        for(int it=0; it<vec_muon_index.size(); ++it){
            // match to index in output container
            if(vec_muon_index[it]==index){
                if(isGoodMuMuon(HID3PD,index) ) {
                    m_iBranches["ZCandidateType2"]->at(it) = true;
                    break;
                }
            }
        }//it
    }//ipair

  }//combined chain
  else if(m_isMuidChain){

    for(int i = 0; i < HID3PD->mu_muid_n; ++i) {

        fillCtrlMuidHistos(HID3PD,i);
        if(!isGoodMuidMuon(HID3PD,i)) continue;

        m_iBranches["EF_mu8_isMatched"]->push_back(matchEF_mu8(HID3PD,i));
        m_iBranches["ZCandidateType1"]->push_back(isZCandidateType1(HID3PD,i));
        //m_iBranches["ZCandidateType2"]->push_back(isZCandidateType2(HID3PD,i));
        m_fBranches["E"]->push_back(HID3PD->mu_muid_E->at(i)/1000.);
        m_fBranches["pt"]->push_back(HID3PD->mu_muid_pt->at(i)/1000.);
        m_fBranches["ptid"]->push_back(1/fabs(HID3PD->mu_muid_id_qoverp_exPV->at(i))/1000.*sin(HID3PD->mu_muid_id_theta_exPV->at(i)));
        m_fBranches["eta"]->push_back(HID3PD->mu_muid_eta->at(i));
        m_fBranches["phi"]->push_back(HID3PD->mu_muid_phi->at(i) );
        m_fBranches["m"]->push_back(HID3PD->mu_muid_m->at(i)*1.e-3 );
        m_fBranches["beta"]->push_back(HID3PD->mu_muid_beta->at(i) );
        m_fBranches["nucone20"]->push_back(HID3PD->mu_muid_nucone20->at(i) );
        m_fBranches["nucone30"]->push_back(HID3PD->mu_muid_nucone30->at(i) );
        m_fBranches["nucone40"]->push_back(HID3PD->mu_muid_nucone40->at(i) );
        m_fBranches["ptcone20"]->push_back(HID3PD->mu_muid_ptcone20->at(i)*1.e-3 );
        m_fBranches["ptcone30"]->push_back(HID3PD->mu_muid_ptcone30->at(i)*1.e-3 );
        m_fBranches["ptcone40"]->push_back(HID3PD->mu_muid_ptcone40->at(i)*1.e-3 );
        m_iBranches["charge"]->push_back(HID3PD->mu_muid_charge->at(i) );
        m_fBranches["d0"]->push_back(HID3PD->mu_muid_d0_exPV->at(i) );
        m_fBranches["z0"]->push_back(HID3PD->mu_muid_z0_exPV->at(i) );
        m_fBranches["d0Sig"]->push_back(HID3PD->mu_muid_d0_exPV->at(i)/sqrt(HID3PD->mu_muid_cov_d0_exPV->at(i)) );
        m_fBranches["z0Sig"]->push_back(HID3PD->mu_muid_z0_exPV->at(i)/sqrt(HID3PD->mu_muid_cov_z0_exPV->at(i)) );
        m_fBranches["scatteringCurvatureSignificance"]->push_back(HID3PD->mu_muid_scatteringCurvatureSignificance->at(i) );
        m_fBranches["momentumBalanceSignificance"]->push_back(HID3PD->mu_muid_momentumBalanceSignificance->at(i) );
        float momLoss = fabs((HID3PD->mu_muid_me_qoverp->at(i) - HID3PD->mu_muid_id_qoverp->at(i))/HID3PD->mu_muid_me_qoverp->at(i));
        m_fBranches["momentumLossPull"]->push_back(momLoss);

        float comp = fabs(momLoss)+0.07*fabs(HID3PD->mu_muid_scatteringCurvatureSignificance->at(i));
        m_fBranches["comp"]->push_back(comp);
        if( m_doTruth ) { 
            //m_iBranches["prompt"]->push_back( AssignMuonPrompt(HID3PD,i) );
            //m_fBranches["motherpt"]->push_back( m_motherpt );
            //m_iBranches["eventIndex"]->push_back( m_eventIndex );
        }
        numMuidMuon++;

    }//i
  }//muid
  else if(m_isStacoChain){
    for(int i = 0; i < HID3PD->mu_muid_n; ++i) {
        fillCtrlStacoHistos(HID3PD,i);
        if(!isGoodStacoMuon(HID3PD,i)) continue;

        m_iBranches["EF_mu8_isMatched"]->push_back(matchEF_mu8(HID3PD,i));
        m_iBranches["ZCandidateType1"]->push_back(isZCandidateType1(HID3PD,i));
        //m_iBranches["ZCandidateType2"]->push_back(isZCandidateType2(HID3PD,i));
        m_fBranches["E"]->push_back(HID3PD->mu_staco_E->at(i)/1000.);
        m_fBranches["pt"]->push_back(HID3PD->mu_staco_pt->at(i)/1000.);
        m_fBranches["ptid"]->push_back(1/fabs(HID3PD->mu_staco_id_qoverp_exPV->at(i))/1000.*sin(HID3PD->mu_staco_id_theta_exPV->at(i)));
        m_fBranches["eta"]->push_back(HID3PD->mu_staco_eta->at(i));
        m_fBranches["phi"]->push_back(HID3PD->mu_staco_phi->at(i) );
        m_fBranches["m"]->push_back(HID3PD->mu_staco_m->at(i)*1.e-3 );
        m_fBranches["beta"]->push_back(HID3PD->mu_staco_beta->at(i) );
        m_fBranches["nucone20"]->push_back(HID3PD->mu_staco_nucone20->at(i) );
        m_fBranches["nucone30"]->push_back(HID3PD->mu_staco_nucone30->at(i) );
        m_fBranches["nucone40"]->push_back(HID3PD->mu_staco_nucone40->at(i) );
        m_fBranches["ptcone20"]->push_back(HID3PD->mu_staco_ptcone20->at(i)*1.e-3 );
        m_fBranches["ptcone30"]->push_back(HID3PD->mu_staco_ptcone30->at(i)*1.e-3 );
        m_fBranches["ptcone40"]->push_back(HID3PD->mu_staco_ptcone40->at(i)*1.e-3 );
        m_iBranches["charge"]->push_back(HID3PD->mu_staco_charge->at(i) );
        m_fBranches["d0"]->push_back(HID3PD->mu_staco_d0_exPV->at(i) );
        m_fBranches["z0"]->push_back(HID3PD->mu_staco_z0_exPV->at(i) );
        m_fBranches["d0Sig"]->push_back(HID3PD->mu_staco_d0_exPV->at(i)/sqrt(HID3PD->mu_staco_cov_d0_exPV->at(i)) );
        m_fBranches["z0Sig"]->push_back(HID3PD->mu_staco_z0_exPV->at(i)/sqrt(HID3PD->mu_staco_cov_z0_exPV->at(i)) );
        m_fBranches["scatteringCurvatureSignificance"]->push_back(HID3PD->mu_staco_scatteringCurvatureSignificance->at(i) );
        m_fBranches["momentumBalanceSignificance"]->push_back(HID3PD->mu_staco_momentumBalanceSignificance->at(i) );
        float momLoss = fabs((HID3PD->mu_staco_me_qoverp->at(i) - HID3PD->mu_staco_id_qoverp->at(i))/HID3PD->mu_staco_me_qoverp->at(i));
        m_fBranches["momentumLossPull"]->push_back(momLoss);

        float comp = fabs(momLoss)+0.07*fabs(HID3PD->mu_staco_scatteringCurvatureSignificance->at(i));
        m_fBranches["comp"]->push_back(comp);

        if( m_doTruth ) { 
            //m_iBranches["prompt"]->push_back( AssignMuonPrompt(HID3PD,i) );
            //m_fBranches["motherpt"]->push_back( m_motherpt );
            //m_iBranches["eventIndex"]->push_back( m_eventIndex );
        }
        numStacoMuon++;
    }//i
  }//staco
}

void MuonAnalysis::fillCtrlMuHistos(HeavyIonD3PD* HID3PD, int imu){
	hmu_medium->Fill(HID3PD->mu_medium->at(imu));
	hmu_author->Fill(HID3PD->mu_author->at(imu));
	hmu_momentumBalanceSignificance->Fill(HID3PD->mu_momentumBalanceSignificance->at(imu));
    float momLoss = fabs((HID3PD->mu_me_qoverp->at(imu) - HID3PD->mu_id_qoverp->at(imu))/HID3PD->mu_me_qoverp->at(imu));
	hmu_momentumLossPull->Fill(momLoss);
	hmu_nPixHits->Fill(HID3PD->mu_nPixHits->at(imu));
	hmu_nBLHits->Fill(HID3PD->mu_nBLHits->at(imu));
	hmu_nSCTHits->Fill(HID3PD->mu_nSCTHits->at(imu));
	hmu_nPixSCTHoles->Fill(HID3PD->mu_nPixHoles->at(imu)+HID3PD->mu_nSCTHoles->at(imu));
	hmu_id_d0_exPV->Fill(HID3PD->mu_id_d0_exPV->at(imu));
	hmu_id_z0_exPVsinTheta->Fill(fabs(HID3PD->mu_id_z0_exPV->at(imu))*TMath::Sin(HID3PD->mu_id_theta_exPV->at(imu)));
	hmu_matchchi2Overndof->Fill(HID3PD->mu_matchchi2->at(imu)/HID3PD->mu_matchndof->at(imu));
	hmu_isCombinedMuon->Fill(HID3PD->mu_isCombinedMuon->at(imu));
	hmu_scatteringCurvatureSignificance->Fill(fabs(HID3PD->mu_scatteringCurvatureSignificance->at(imu)));
    hmu_z0_vx_z_diff->Fill(fabs(HID3PD->mu_z0_exPV->at(imu)-HID3PD->vx_z->at(0)));
}

void MuonAnalysis::fillCtrlMuidHistos(HeavyIonD3PD* HID3PD, int imu){
	hmu_muid_medium->Fill(HID3PD->mu_muid_medium->at(imu));
	hmu_muid_author->Fill(HID3PD->mu_muid_author->at(imu));
	hmu_muid_momentumBalanceSignificance->Fill(HID3PD->mu_muid_momentumBalanceSignificance->at(imu));
    float momLoss = fabs((HID3PD->mu_muid_me_qoverp->at(imu) - HID3PD->mu_muid_id_qoverp->at(imu))/HID3PD->mu_muid_me_qoverp->at(imu));
	hmu_muid_momentumLossPull->Fill(momLoss);
	hmu_muid_nPixHits->Fill(HID3PD->mu_muid_nPixHits->at(imu));
	hmu_muid_nBLHits->Fill(HID3PD->mu_muid_nBLHits->at(imu));
	hmu_muid_nSCTHits->Fill(HID3PD->mu_muid_nSCTHits->at(imu));
	hmu_muid_nPixSCTHoles->Fill(HID3PD->mu_muid_nPixHoles->at(imu)+HID3PD->mu_muid_nSCTHoles->at(imu));
	hmu_muid_id_d0_exPV->Fill(HID3PD->mu_muid_id_d0_exPV->at(imu));
	hmu_muid_id_z0_exPVsinTheta->Fill(fabs(HID3PD->mu_muid_id_z0_exPV->at(imu))*TMath::Sin(HID3PD->mu_muid_id_theta_exPV->at(imu)));
	hmu_muid_matchchi2Overndof->Fill(HID3PD->mu_muid_matchchi2->at(imu)/HID3PD->mu_muid_matchndof->at(imu));
	hmu_muid_isCombinedMuon->Fill(HID3PD->mu_muid_isCombinedMuon->at(imu));
	hmu_muid_scatteringCurvatureSignificance->Fill(fabs(HID3PD->mu_muid_scatteringCurvatureSignificance->at(imu)));
    hmu_muid_z0_vx_z_diff->Fill(fabs(HID3PD->mu_muid_z0_exPV->at(imu)-HID3PD->vx_z->at(0)));

}

void MuonAnalysis::fillCtrlStacoHistos(HeavyIonD3PD* HID3PD, int imu){

	hmu_staco_medium->Fill(HID3PD->mu_staco_medium->at(imu));
	hmu_staco_author->Fill(HID3PD->mu_staco_author->at(imu));
	hmu_staco_momentumBalanceSignificance->Fill(HID3PD->mu_staco_momentumBalanceSignificance->at(imu));
    float momLoss = fabs((HID3PD->mu_staco_me_qoverp->at(imu) - HID3PD->mu_staco_id_qoverp->at(imu))/HID3PD->mu_staco_me_qoverp->at(imu));
	hmu_staco_momentumLossPull->Fill(momLoss);
	hmu_staco_nPixHits->Fill(HID3PD->mu_staco_nPixHits->at(imu));
	hmu_staco_nBLHits->Fill(HID3PD->mu_staco_nBLHits->at(imu));
	hmu_staco_nSCTHits->Fill(HID3PD->mu_staco_nSCTHits->at(imu));
	hmu_staco_nPixSCTHoles->Fill(HID3PD->mu_staco_nPixHoles->at(imu)+HID3PD->mu_staco_nSCTHoles->at(imu));
	hmu_staco_id_d0_exPV->Fill(HID3PD->mu_staco_id_d0_exPV->at(imu));
	hmu_staco_id_z0_exPVsinTheta->Fill(fabs(HID3PD->mu_staco_id_z0_exPV->at(imu))*TMath::Sin(HID3PD->mu_staco_id_theta_exPV->at(imu)));
	hmu_staco_matchchi2Overndof->Fill(HID3PD->mu_staco_matchchi2->at(imu)/HID3PD->mu_staco_matchndof->at(imu));
	hmu_staco_isCombinedMuon->Fill(HID3PD->mu_staco_isCombinedMuon->at(imu));
	hmu_staco_scatteringCurvatureSignificance->Fill(fabs(HID3PD->mu_staco_scatteringCurvatureSignificance->at(imu)));
    hmu_staco_z0_vx_z_diff->Fill(fabs(HID3PD->mu_staco_z0_exPV->at(imu)-HID3PD->vx_z->at(0)));

}

void MuonAnalysis::ClearVectors(){
  for(std::map<std::string, std::vector<float>* >::iterator itr=m_fBranches.begin();
      itr!=m_fBranches.end(); ++itr) {

    itr->second->clear();
  }

  for(std::map<std::string, std::vector<std::vector<float> >* >::iterator itr=m_fLeaves.begin();
          itr!=m_fLeaves.end(); ++itr){

    itr->second->clear();
  }

  for(std::map<std::string, std::vector<int>* >::iterator itr=m_iBranches.begin();
      itr!=m_iBranches.end(); ++itr) {

    itr->second->clear();
  }

  for(std::map<std::string, std::vector<std::vector<int> >* >::iterator itr=m_iLeaves.begin();
          itr!=m_iLeaves.end(); ++itr){

    itr->second->clear();
  }
  
}

void MuonAnalysis::WriteHistosToFile(TFile* file){
    file->cd();
    for(unsigned int i=0; i<m_hMuonVec.size(); ++i) m_hMuonVec[i]->Write();
}
