//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul  1 20:52:00 2014 by ROOT version 5.34/18
// from TTree MuonD3PD/MuonD3PD
// found on file: user.tbalestr.028021._00049.skimmed.root
//////////////////////////////////////////////////////////

#ifndef BranchBase_h
#define BranchBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <cmath>

// Fixed size dimensions of array or collections stored in the TTree if any.

class BranchBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   bool m_doTruth;
   bool m_EventVarsActive;
   // Declaration of leaf types
   Int_t           RunNumber;
   Int_t           EventNumber;
   Int_t           lbn;
   Int_t           vx_n;
   Float_t         vx_z;
   Float_t         centrality;
   Float_t         fcal;
   Float_t         MET_RefFinal_etx;
   Float_t         MET_RefFinal_ety;
   Float_t         MET_RefFinal_et;
   Float_t         MET_RefFinal_phi;
   Float_t         MET_trk04_etx;
   Float_t         MET_trk04_ety;
   Float_t         MET_trk04_et;
   Float_t         MET_trk04_phi;
   Float_t         MET_trk05_etx;
   Float_t         MET_trk05_ety;
   Float_t         MET_trk05_et;
   Float_t         MET_trk05_phi;
   Float_t         MET_trk08_etx;
   Float_t         MET_trk08_ety;
   Float_t         MET_trk08_et;
   Float_t         MET_trk08_phi;
   Float_t         MET_trk1_etx;
   Float_t         MET_trk1_ety;
   Float_t         MET_trk1_et;
   Float_t         MET_trk1_phi;
   Float_t         MET_trk3_etx;
   Float_t         MET_trk3_ety;
   Float_t         MET_trk3_et;
   Float_t         MET_trk3_phi;
   Int_t           EF_mu8;
   Int_t           mu_n;
   Int_t           mu_rec_tag_n;
   std::vector<float>   *mu_tag_E;
   std::vector<float>   *mu_tag_eta;
   std::vector<float>   *mu_tag_m;
   std::vector<float>   *mu_tag_phi;
   std::vector<float>   *mu_tag_pt;
   std::vector<float>   *mu_tag_ptcone20;
   std::vector<float>   *mu_tag_ptcone30;
   std::vector<float>   *mu_tag_ptcone40;
   std::vector<float>   *mu_E;
   std::vector<float>   *mu_beta;
   std::vector<float>   *mu_comp;
   std::vector<float>   *mu_d0;
   std::vector<float>   *mu_d0Sig;
   std::vector<float>   *mu_eta;
   std::vector<float>   *mu_m;
   std::vector<float>   *mu_momentumBalanceSignificance;
   std::vector<float>   *mu_momentumLossPull;
   std::vector<float>   *mu_mt;
   std::vector<float>   *mu_nucone20;
   std::vector<float>   *mu_nucone30;
   std::vector<float>   *mu_nucone40;
   std::vector<float>   *mu_phi;
   std::vector<float>   *mu_phi_mu_met;
   std::vector<float>   *mu_pt;
   std::vector<float>   *mu_ptcone20;
   std::vector<float>   *mu_ptcone30;
   std::vector<float>   *mu_ptcone40;
   std::vector<float>   *mu_ptid;
   std::vector<float>   *mu_scatteringCurvatureSignificance;
   std::vector<float>   *mu_z0;
   std::vector<float>   *mu_z0Sig;
   std::vector<std::vector<float> > *mu_rec_IDprobe_charge;
   std::vector<std::vector<float> > *mu_rec_IDprobe_eta;
   std::vector<std::vector<float> > *mu_rec_IDprobe_phi;
   std::vector<std::vector<float> > *mu_rec_IDprobe_pt;
   std::vector<std::vector<float> > *mu_rec_MSprobe_charge;
   std::vector<std::vector<float> > *mu_rec_MSprobe_eta;
   std::vector<std::vector<float> > *mu_rec_MSprobe_phi;
   std::vector<std::vector<float> > *mu_rec_MSprobe_pt;
   std::vector<std::vector<float> > *mu_trig_EF_mu8_probe_charge;
   std::vector<std::vector<float> > *mu_trig_EF_mu8_probe_eta;
   std::vector<std::vector<float> > *mu_trig_EF_mu8_probe_phi;
   std::vector<std::vector<float> > *mu_trig_EF_mu8_probe_pt;
   std::vector<int>     *mu_EF_mu8_isMatched;
   std::vector<int>     *mu_ZCandidateType1;
   std::vector<int>     *mu_ZCandidateType2;
   std::vector<int>     *mu_charge;
   std::vector<int>     *mu_isTagMuon;
   std::vector<int>     *mu_tag_charge;
   std::vector<int>     *mu_rec_IDprobe_n;
   std::vector<int>     *mu_rec_MSprobe_n;
   std::vector<int>     *mu_trig_EF_mu8_probe_n;
   std::vector<std::vector<int> > *mu_rec_IDprobe_isMatched;
   std::vector<std::vector<int> > *mu_rec_MSprobe_isMatched;
   std::vector<std::vector<int> > *mu_trig_EF_mu8_probe_isMatched;
   std::vector<float>   *mu_rec_truth_E;
   std::vector<float>   *mu_rec_truth_dr;
   std::vector<float>   *mu_rec_truth_eta;
   std::vector<float>   *mu_rec_truth_phi;
   std::vector<float>   *mu_rec_truth_pt;
   std::vector<int>     *mu_rec_truth_matched;
   std::vector<int>     *mu_rec_truth_mother_pdg;
   std::vector<int>     *mu_rec_truth_pdg;
   std::vector<float>   *gen_E;
   std::vector<float>   *gen_charge;
   std::vector<float>   *gen_eta;
   std::vector<float>   *gen_phi;
   std::vector<float>   *gen_pt;
   std::vector<int>     *gen_mother_pdg;
   std::vector<int>     *gen_pdg;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_lbn;   //!
   TBranch        *b_vx_n;   //!
   TBranch        *b_vx_z;   //!
   TBranch        *b_centrality;   //!
   TBranch        *b_fcal;   //!
   TBranch        *b_MET_RefFinal_etx;   //!
   TBranch        *b_MET_RefFinal_ety;   //!
   TBranch        *b_MET_RefFinal_et;   //!
   TBranch        *b_MET_RefFinal_phi;   //!
   TBranch        *b_MET_trk04_etx;   //!
   TBranch        *b_MET_trk04_ety;   //!
   TBranch        *b_MET_trk04_et;   //!
   TBranch        *b_MET_trk04_phi;   //!
   TBranch        *b_MET_trk05_etx;   //!
   TBranch        *b_MET_trk05_ety;   //!
   TBranch        *b_MET_trk05_et;   //!
   TBranch        *b_MET_trk05_phi;   //!
   TBranch        *b_MET_trk08_etx;   //!
   TBranch        *b_MET_trk08_ety;   //!
   TBranch        *b_MET_trk08_et;   //!
   TBranch        *b_MET_trk08_phi;   //!
   TBranch        *b_MET_trk1_etx;   //!
   TBranch        *b_MET_trk1_ety;   //!
   TBranch        *b_MET_trk1_et;   //!
   TBranch        *b_MET_trk1_phi;   //!
   TBranch        *b_MET_trk3_etx;   //!
   TBranch        *b_MET_trk3_ety;   //!
   TBranch        *b_MET_trk3_et;   //!
   TBranch        *b_MET_trk3_phi;   //!
   TBranch        *b_EF_mu8;   //!
   TBranch        *b_mu_n;   //!
   TBranch        *b_mu_rec_tag_n;   //!
   TBranch        *b_mu_tag_E;   //!
   TBranch        *b_mu_tag_eta;   //!
   TBranch        *b_mu_tag_m;   //!
   TBranch        *b_mu_tag_phi;   //!
   TBranch        *b_mu_tag_pt;   //!
   TBranch        *b_mu_tag_ptcone20;   //!
   TBranch        *b_mu_tag_ptcone30;   //!
   TBranch        *b_mu_tag_ptcone40;   //!
   TBranch        *b_mu_tag_charge;   //!
   TBranch        *b_mu_E;   //!
   TBranch        *b_mu_beta;   //!
   TBranch        *b_mu_comp;   //!
   TBranch        *b_mu_d0;   //!
   TBranch        *b_mu_d0Sig;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_m;   //!
   TBranch        *b_mu_momentumBalanceSignificance;   //!
   TBranch        *b_mu_momentumLossPull;   //!
   TBranch        *b_mu_mt;   //!
   TBranch        *b_mu_nucone20;   //!
   TBranch        *b_mu_nucone30;   //!
   TBranch        *b_mu_nucone40;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_phi_mu_met;   //!
   TBranch        *b_mu_pt;   //!
   TBranch        *b_mu_ptcone20;   //!
   TBranch        *b_mu_ptcone30;   //!
   TBranch        *b_mu_ptcone40;   //!
   TBranch        *b_mu_ptid;   //!
   TBranch        *b_mu_scatteringCurvatureSignificance;   //!
   TBranch        *b_mu_z0;   //!
   TBranch        *b_mu_z0Sig;   //!
   TBranch        *b_mu_rec_IDprobe_charge;   //!
   TBranch        *b_mu_rec_IDprobe_eta;   //!
   TBranch        *b_mu_rec_IDprobe_phi;   //!
   TBranch        *b_mu_rec_IDprobe_pt;   //!
   TBranch        *b_mu_rec_MSprobe_charge;   //!
   TBranch        *b_mu_rec_MSprobe_eta;   //!
   TBranch        *b_mu_rec_MSprobe_phi;   //!
   TBranch        *b_mu_rec_MSprobe_pt;   //!
   TBranch        *b_mu_trig_EF_mu8_probe_charge;   //!
   TBranch        *b_mu_trig_EF_mu8_probe_eta;   //!
   TBranch        *b_mu_trig_EF_mu8_probe_phi;   //!
   TBranch        *b_mu_trig_EF_mu8_probe_pt;   //!
   TBranch        *b_mu_EF_mu8_isMatched;   //!
   TBranch        *b_mu_ZCandidateType1;   //!
   TBranch        *b_mu_ZCandidateType2;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_isTagMuon;   //!
   TBranch        *b_mu_rec_IDprobe_n;   //!
   TBranch        *b_mu_rec_MSprobe_n;   //!
   TBranch        *b_mu_rec_IDprobe_isMatched;   //!
   TBranch        *b_mu_rec_MSprobe_isMatched;   //!
   TBranch        *b_mu_trig_EF_mu8_probe_n;   //!
   TBranch        *b_mu_trig_EF_mu8_probe_isMatched;   //!
   TBranch        *b_mu_rec_truth_E;   //!
   TBranch        *b_mu_rec_truth_dr;   //!
   TBranch        *b_mu_rec_truth_eta;   //!
   TBranch        *b_mu_rec_truth_phi;   //!
   TBranch        *b_mu_rec_truth_pt;   //!
   TBranch        *b_mu_rec_truth_matched;   //!
   TBranch        *b_mu_rec_truth_mother_pdg;   //!
   TBranch        *b_mu_rec_truth_pdg;   //!
   TBranch        *b_gen_E;   //!
   TBranch        *b_gen_charge;   //!
   TBranch        *b_gen_eta;   //!
   TBranch        *b_gen_phi;   //!
   TBranch        *b_gen_pt;   //!
   TBranch        *b_gen_mother_pdg;   //!
   TBranch        *b_gen_pdg;   //!

   BranchBase(TTree *tree=0, bool doTruth=false);
   virtual ~BranchBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void ActivateEventVariables(int entry);
   virtual void ActivateWBosonFinder(int entry);
   virtual void ActivateTruth(int entry);
   virtual void ActivateIDProbes(int entry);
   virtual void ActivateMSProbes(int entry);
   virtual void ActivateTriggerProbes(int entry);
   virtual void ActivateTags(int entry);

};

#endif

#ifdef BranchBase_cxx
BranchBase::BranchBase(TTree* tree, bool doTruth) : fChain(0),m_doTruth(doTruth),m_EventVarsActive(false)
{
    std::cout << "[BranchBase::BranchBase] C'tor." << std::endl;
    //fChain->CopyAddresses(tree);
    //fChain = tree->CloneTree();
    //std::cout << "fChain: " << fChain << std::endl;
    //std::cout << "in tree: " << tree << std::endl;
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("user.tbalestr.028021._00049.skimmed.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("user.tbalestr.028021._00049.skimmed.root");
      }
      f->GetObject("MuonD3PD",tree);

   }
   Init(tree);
   //Init(fChain);
}


BranchBase::~BranchBase()
{
   std::cout << "[BranchBase::~BranchBase] D'tor." << std::endl;
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t BranchBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t BranchBase::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   ActivateEventVariables(centry);
   return centry;
}

void BranchBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mu_E = 0;
   mu_beta = 0;
   mu_comp = 0;
   mu_d0 = 0;
   mu_d0Sig = 0;
   mu_eta = 0;
   mu_m = 0;
   mu_momentumBalanceSignificance = 0;
   mu_momentumLossPull = 0;
   mu_mt = 0;
   mu_nucone20 = 0;
   mu_nucone30 = 0;
   mu_nucone40 = 0;
   mu_phi = 0;
   mu_phi_mu_met = 0;
   mu_pt = 0;
   mu_ptcone20 = 0;
   mu_ptcone30 = 0;
   mu_ptcone40 = 0;
   mu_ptid = 0;
   mu_scatteringCurvatureSignificance = 0;
   mu_z0 = 0;
   mu_z0Sig = 0;
   mu_rec_IDprobe_charge = 0;
   mu_rec_IDprobe_eta = 0;
   mu_rec_IDprobe_phi = 0;
   mu_rec_IDprobe_pt = 0;
   mu_rec_MSprobe_charge = 0;
   mu_rec_MSprobe_eta = 0;
   mu_rec_MSprobe_phi = 0;
   mu_rec_MSprobe_pt = 0;
   mu_trig_EF_mu8_probe_charge = 0;
   mu_trig_EF_mu8_probe_eta = 0;
   mu_trig_EF_mu8_probe_phi = 0;
   mu_trig_EF_mu8_probe_pt = 0;
   mu_EF_mu8_isMatched = 0;
   mu_ZCandidateType1 = 0;
   mu_ZCandidateType2 = 0;
   mu_charge = 0;
   mu_isTagMuon = 0;
   mu_tag_E = 0;
   mu_tag_charge = 0;
   mu_tag_eta = 0;
   mu_tag_m = 0;
   mu_tag_phi = 0;
   mu_tag_pt = 0;
   mu_tag_ptcone20 = 0;
   mu_tag_ptcone30 = 0;
   mu_tag_ptcone40 = 0;
   mu_rec_IDprobe_n = 0;
   mu_rec_MSprobe_n = 0;
   mu_rec_IDprobe_isMatched = 0;
   mu_rec_MSprobe_isMatched = 0;
   mu_trig_EF_mu8_probe_n = 0;
   mu_trig_EF_mu8_probe_isMatched = 0;
   mu_rec_truth_E = 0;
   mu_rec_truth_dr = 0;
   mu_rec_truth_eta = 0;
   mu_rec_truth_phi = 0;
   mu_rec_truth_pt = 0;
   mu_rec_truth_matched = 0;
   mu_rec_truth_mother_pdg = 0;
   mu_rec_truth_pdg = 0;
   gen_E = 0;
   gen_charge = 0;
   gen_eta = 0;
   gen_phi = 0;
   gen_pt = 0;
   gen_mother_pdg = 0;
   gen_pdg = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("lbn", &lbn, &b_lbn);
   fChain->SetBranchAddress("vx_n", &vx_n, &b_vx_n);
   fChain->SetBranchAddress("vx_z", &vx_z, &b_vx_z);
   fChain->SetBranchAddress("centrality", &centrality, &b_centrality);
   fChain->SetBranchAddress("fcal", &fcal, &b_fcal);
   fChain->SetBranchAddress("MET_RefFinal_etx", &MET_RefFinal_etx, &b_MET_RefFinal_etx);
   fChain->SetBranchAddress("MET_RefFinal_ety", &MET_RefFinal_ety, &b_MET_RefFinal_ety);
   fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et, &b_MET_RefFinal_et);
   fChain->SetBranchAddress("MET_RefFinal_phi", &MET_RefFinal_phi, &b_MET_RefFinal_phi);
   fChain->SetBranchAddress("MET_trk04_etx", &MET_trk04_etx, &b_MET_trk04_etx);
   fChain->SetBranchAddress("MET_trk04_ety", &MET_trk04_ety, &b_MET_trk04_ety);
   fChain->SetBranchAddress("MET_trk04_et", &MET_trk04_et, &b_MET_trk04_et);
   fChain->SetBranchAddress("MET_trk04_phi", &MET_trk04_phi, &b_MET_trk04_phi);
   fChain->SetBranchAddress("MET_trk05_etx", &MET_trk05_etx, &b_MET_trk05_etx);
   fChain->SetBranchAddress("MET_trk05_ety", &MET_trk05_ety, &b_MET_trk05_ety);
   fChain->SetBranchAddress("MET_trk05_et", &MET_trk05_et, &b_MET_trk05_et);
   fChain->SetBranchAddress("MET_trk05_phi", &MET_trk05_phi, &b_MET_trk05_phi);
   fChain->SetBranchAddress("MET_trk08_etx", &MET_trk08_etx, &b_MET_trk08_etx);
   fChain->SetBranchAddress("MET_trk08_ety", &MET_trk08_ety, &b_MET_trk08_ety);
   fChain->SetBranchAddress("MET_trk08_et", &MET_trk08_et, &b_MET_trk08_et);
   fChain->SetBranchAddress("MET_trk08_phi", &MET_trk08_phi, &b_MET_trk08_phi);
   fChain->SetBranchAddress("MET_trk1_etx", &MET_trk1_etx, &b_MET_trk1_etx);
   fChain->SetBranchAddress("MET_trk1_ety", &MET_trk1_ety, &b_MET_trk1_ety);
   fChain->SetBranchAddress("MET_trk1_et", &MET_trk1_et, &b_MET_trk1_et);
   fChain->SetBranchAddress("MET_trk1_phi", &MET_trk1_phi, &b_MET_trk1_phi);
   fChain->SetBranchAddress("MET_trk3_etx", &MET_trk3_etx, &b_MET_trk3_etx);
   fChain->SetBranchAddress("MET_trk3_ety", &MET_trk3_ety, &b_MET_trk3_ety);
   fChain->SetBranchAddress("MET_trk3_et", &MET_trk3_et, &b_MET_trk3_et);
   fChain->SetBranchAddress("MET_trk3_phi", &MET_trk3_phi, &b_MET_trk3_phi);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_charge", &mu_trig_EF_mu8_probe_charge, &b_mu_trig_EF_mu8_probe_charge);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_eta", &mu_trig_EF_mu8_probe_eta, &b_mu_trig_EF_mu8_probe_eta);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_phi", &mu_trig_EF_mu8_probe_phi, &b_mu_trig_EF_mu8_probe_phi);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_pt", &mu_trig_EF_mu8_probe_pt, &b_mu_trig_EF_mu8_probe_pt);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_n", &mu_trig_EF_mu8_probe_n, &b_mu_trig_EF_mu8_probe_n);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_isMatched", &mu_trig_EF_mu8_probe_isMatched, &b_mu_trig_EF_mu8_probe_isMatched);
   fChain->SetBranchAddress("EF_mu8", &EF_mu8, &b_EF_mu8);
   fChain->SetBranchAddress("mu_n", &mu_n, &b_mu_n);
   fChain->SetBranchAddress("mu_rec_tag_n", &mu_rec_tag_n, &b_mu_rec_tag_n);
   fChain->SetBranchAddress("mu_tag_E", &mu_tag_E, &b_mu_tag_E);
   fChain->SetBranchAddress("mu_tag_charge", &mu_tag_charge, &b_mu_tag_charge);
   fChain->SetBranchAddress("mu_tag_eta", &mu_tag_eta, &b_mu_tag_eta);
   fChain->SetBranchAddress("mu_tag_m", &mu_tag_m, &b_mu_tag_m);
   fChain->SetBranchAddress("mu_tag_phi", &mu_tag_phi, &b_mu_tag_phi);
   fChain->SetBranchAddress("mu_tag_pt", &mu_tag_pt, &b_mu_tag_pt);
   fChain->SetBranchAddress("mu_tag_ptcone20", &mu_tag_ptcone20, &b_mu_tag_ptcone20);
   fChain->SetBranchAddress("mu_tag_ptcone30", &mu_tag_ptcone30, &b_mu_tag_ptcone30);
   fChain->SetBranchAddress("mu_tag_ptcone40", &mu_tag_ptcone40, &b_mu_tag_ptcone40);
   fChain->SetBranchAddress("mu_E", &mu_E, &b_mu_E);
   fChain->SetBranchAddress("mu_beta", &mu_beta, &b_mu_beta);
   fChain->SetBranchAddress("mu_comp", &mu_comp, &b_mu_comp);
   fChain->SetBranchAddress("mu_d0", &mu_d0, &b_mu_d0);
   fChain->SetBranchAddress("mu_d0Sig", &mu_d0Sig, &b_mu_d0Sig);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_m", &mu_m, &b_mu_m);
   fChain->SetBranchAddress("mu_momentumBalanceSignificance", &mu_momentumBalanceSignificance, &b_mu_momentumBalanceSignificance);
   fChain->SetBranchAddress("mu_momentumLossPull", &mu_momentumLossPull, &b_mu_momentumLossPull);
   fChain->SetBranchAddress("mu_mt", &mu_mt, &b_mu_mt);
   fChain->SetBranchAddress("mu_nucone20", &mu_nucone20, &b_mu_nucone20);
   fChain->SetBranchAddress("mu_nucone30", &mu_nucone30, &b_mu_nucone30);
   fChain->SetBranchAddress("mu_nucone40", &mu_nucone40, &b_mu_nucone40);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_phi_mu_met", &mu_phi_mu_met, &b_mu_phi_mu_met);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_ptcone20", &mu_ptcone20, &b_mu_ptcone20);
   fChain->SetBranchAddress("mu_ptcone30", &mu_ptcone30, &b_mu_ptcone30);
   fChain->SetBranchAddress("mu_ptcone40", &mu_ptcone40, &b_mu_ptcone40);
   fChain->SetBranchAddress("mu_ptid", &mu_ptid, &b_mu_ptid);
   fChain->SetBranchAddress("mu_scatteringCurvatureSignificance", &mu_scatteringCurvatureSignificance, &b_mu_scatteringCurvatureSignificance);
   fChain->SetBranchAddress("mu_z0", &mu_z0, &b_mu_z0);
   fChain->SetBranchAddress("mu_z0Sig", &mu_z0Sig, &b_mu_z0Sig);
   fChain->SetBranchAddress("mu_rec_IDprobe_charge", &mu_rec_IDprobe_charge, &b_mu_rec_IDprobe_charge);
   fChain->SetBranchAddress("mu_rec_IDprobe_eta", &mu_rec_IDprobe_eta, &b_mu_rec_IDprobe_eta);
   fChain->SetBranchAddress("mu_rec_IDprobe_phi", &mu_rec_IDprobe_phi, &b_mu_rec_IDprobe_phi);
   fChain->SetBranchAddress("mu_rec_IDprobe_pt", &mu_rec_IDprobe_pt, &b_mu_rec_IDprobe_pt);
   fChain->SetBranchAddress("mu_rec_MSprobe_charge", &mu_rec_MSprobe_charge, &b_mu_rec_MSprobe_charge);
   fChain->SetBranchAddress("mu_rec_MSprobe_eta", &mu_rec_MSprobe_eta, &b_mu_rec_MSprobe_eta);
   fChain->SetBranchAddress("mu_rec_MSprobe_phi", &mu_rec_MSprobe_phi, &b_mu_rec_MSprobe_phi);
   fChain->SetBranchAddress("mu_rec_MSprobe_pt", &mu_rec_MSprobe_pt, &b_mu_rec_MSprobe_pt);
   fChain->SetBranchAddress("mu_EF_mu8_isMatched", &mu_EF_mu8_isMatched, &b_mu_EF_mu8_isMatched);
   fChain->SetBranchAddress("mu_ZCandidateType1", &mu_ZCandidateType1, &b_mu_ZCandidateType1);
   fChain->SetBranchAddress("mu_ZCandidateType2", &mu_ZCandidateType2, &b_mu_ZCandidateType2);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_isTagMuon", &mu_isTagMuon, &b_mu_isTagMuon);
   fChain->SetBranchAddress("mu_rec_IDprobe_n", &mu_rec_IDprobe_n, &b_mu_rec_IDprobe_n);
   fChain->SetBranchAddress("mu_rec_MSprobe_n", &mu_rec_MSprobe_n, &b_mu_rec_MSprobe_n);
   fChain->SetBranchAddress("mu_rec_IDprobe_isMatched", &mu_rec_IDprobe_isMatched, &b_mu_rec_IDprobe_isMatched);
   fChain->SetBranchAddress("mu_rec_MSprobe_isMatched", &mu_rec_MSprobe_isMatched, &b_mu_rec_MSprobe_isMatched);
   if(m_doTruth){

       fChain->SetBranchAddress("mu_rec_truth_E", &mu_rec_truth_E, &b_mu_rec_truth_E);
       fChain->SetBranchAddress("mu_rec_truth_dr", &mu_rec_truth_dr, &b_mu_rec_truth_dr);
       fChain->SetBranchAddress("mu_rec_truth_eta", &mu_rec_truth_eta, &b_mu_rec_truth_eta);
       fChain->SetBranchAddress("mu_rec_truth_phi", &mu_rec_truth_phi, &b_mu_rec_truth_phi);
       fChain->SetBranchAddress("mu_rec_truth_pt", &mu_rec_truth_pt, &b_mu_rec_truth_pt);
       fChain->SetBranchAddress("mu_rec_truth_matched", &mu_rec_truth_matched, &b_mu_rec_truth_matched);
       fChain->SetBranchAddress("mu_rec_truth_mother_pdg", &mu_rec_truth_mother_pdg, &b_mu_rec_truth_mother_pdg);
       fChain->SetBranchAddress("mu_rec_truth_pdg", &mu_rec_truth_pdg, &b_mu_rec_truth_pdg);
       fChain->SetBranchAddress("gen_E", &gen_E, &b_gen_E);
       fChain->SetBranchAddress("gen_charge", &gen_charge, &b_gen_charge);
       fChain->SetBranchAddress("gen_eta", &gen_eta, &b_gen_eta);
       fChain->SetBranchAddress("gen_phi", &gen_phi, &b_gen_phi);
       fChain->SetBranchAddress("gen_pt", &gen_pt, &b_gen_pt);
       fChain->SetBranchAddress("gen_mother_pdg", &gen_mother_pdg, &b_gen_mother_pdg);
       fChain->SetBranchAddress("gen_pdg", &gen_pdg, &b_gen_pdg);
   }
   Notify();
}

Bool_t BranchBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void BranchBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t BranchBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef BranchBase_cxx
