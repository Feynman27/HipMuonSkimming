#ifndef MUONANALYSIS_H_
#define MUONANALYSIS_H_

#include "HeavyIonD3PD.h"
#include "TLorentzVector.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

class MuonAnalysis {
 public:
     MuonAnalysis(){}; //default constructor
     MuonAnalysis(std::string prefix, bool doMC=false, bool doMinBias=false);
     virtual ~MuonAnalysis();

     virtual void LoopEvent(HeavyIonD3PD* HID3PD,int entry);
     virtual void SetOutputBranches(TTree* outputTree);
     virtual void ActivateMuonBranches(HeavyIonD3PD* HID3PD, int entry);
     void fillCtrlMuHistos(HeavyIonD3PD* HID3PD, int imu);
     void fillCtrlMuidHistos(HeavyIonD3PD* HID3PD, int imu);
     void fillCtrlStacoHistos(HeavyIonD3PD* HID3PD, int imu);
     bool isZCandidateType1(HeavyIonD3PD* HID3PD, int imu);
     bool isZCandidateType2(HeavyIonD3PD* HID3PD, int imu, std::vector<std::pair<int,int> >& Zpair);
     void SetdRCut(float dr) { m_dRCut=dr; }
     bool isMediumMuMuon(HeavyIonD3PD* HID3PD, int imu);
     bool isMediumMuidMuon(HeavyIonD3PD* HID3PD, int imu);
     bool isMediumStacoMuon(HeavyIonD3PD* HID3PD, int imu);
     int GetNumHiPtMuMuon() const { return numHiPtMuMuon; }
     int GetNumMuMuon() const { return numMuMuon; }
     int GetNumMuidMuon() const { return numMuidMuon; }
     int GetNumStacoMuon() const { return numStacoMuon; }
     int GetDoMC() const { return m_doTruth; }
     void recIDProbes(HeavyIonD3PD* HID3PD, int imu);
     void recMSProbes(HeavyIonD3PD* HID3PD, int imu);
     void trigProbes(HeavyIonD3PD* HID3PD, int imu);
     bool isRecTagMuon(HeavyIonD3PD* HID3PD, int imu);
     //int AssignMuonPrompt(HeavyIonD3PD* HID3PD, int index);
     virtual void WriteHistosToFile(TFile* file);
 private:
     std::string name;
     float m_dRCut;
     int m_doTruth;
     int m_doMinBias;
     int numMuMuon;
     int numMuidMuon;
     int numStacoMuon;
     int numHiPtMuMuon;
     int numRecTags;
     float m_motherpt;
     int m_eventIndex;
     bool m_isMuChain;
     bool m_isMuidChain;
     bool m_isStacoChain;

     std::vector <TH1*> m_hMuonVec;
     TH1I* hmu_medium;
     TH1I* hmu_author;
     TH1I* hmu_nPixHits;
     TH1I* hmu_nBLHits;
     TH1I* hmu_nSCTHits;
     TH1I* hmu_nPixSCTHoles;
     TH1I* hmu_isCombinedMuon;
     TH1F* hmu_EF_mu8_dR;
     TH1F* hmu_momentumBalanceSignificance;
     TH1F* hmu_momentumLossPull;
     TH1F* hmu_id_d0_exPV;
     TH1F* hmu_id_z0_exPVsinTheta;
     TH1F* hmu_matchchi2Overndof;
     TH1F* hmu_scatteringCurvatureSignificance;
     TH1F* hmu_z0_vx_z_diff; 

     TH1I* hmu_muid_medium;
     TH1I* hmu_muid_author;
     TH1I* hmu_muid_nPixHits;
     TH1I* hmu_muid_nBLHits;
     TH1I* hmu_muid_nSCTHits;
     TH1I* hmu_muid_nPixSCTHoles;
     TH1I* hmu_muid_isCombinedMuon;
     TH1I* hmu_muid_EF_mu8_dR;
     TH1F* hmu_muid_momentumBalanceSignificance;
     TH1F* hmu_muid_momentumLossPull;
     TH1F* hmu_muid_id_d0_exPV;
     TH1F* hmu_muid_id_z0_exPVsinTheta;
     TH1F* hmu_muid_matchchi2Overndof;
     TH1F* hmu_muid_scatteringCurvatureSignificance;
     TH1F* hmu_muid_z0_vx_z_diff; 

     TH1I* hmu_staco_medium;
     TH1I* hmu_staco_author;
     TH1I* hmu_staco_nPixHits;
     TH1I* hmu_staco_nBLHits;
     TH1I* hmu_staco_nSCTHits;
     TH1I* hmu_staco_nPixSCTHoles;
     TH1I* hmu_staco_isCombinedMuon;
     TH1I* hmu_staco_EF_mu8_dR;
     TH1F* hmu_staco_momentumBalanceSignificance;
     TH1F* hmu_staco_momentumLossPull;
     TH1F* hmu_staco_id_d0_exPV;
     TH1F* hmu_staco_id_z0_exPVsinTheta;
     TH1F* hmu_staco_matchchi2Overndof;
     TH1F* hmu_staco_scatteringCurvatureSignificance;
     TH1F* hmu_staco_z0_vx_z_diff; 

     std::map<std::string, std::vector<float>* > m_fBranches;
     std::map<std::string, std::vector<int>* > m_iBranches;
     std::map<std::string, std::vector<std::vector<int> >* > m_iLeaves;
     std::map<std::string, std::vector<std::vector<float> >* > m_fLeaves;
     virtual bool isGoodMuMuon(HeavyIonD3PD* HID3PD, int index);
     virtual bool isGoodMuidMuon(HeavyIonD3PD* HID3PD, int index);
     virtual bool isGoodStacoMuon(HeavyIonD3PD* HID3PD, int index);
     bool matchEF_mu8(HeavyIonD3PD* HID3PD, int imu);
     void ClearVectors(); 
};
#endif
