//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Aug 22 18:04:11 2014 by ROOT version 5.34/19
// from TTree MuonD3PD/MuonD3PD
// found on file: /usatlas/u/tbales/scratch/user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2014.08.22.v01.218677_skimmed.root.646867/user.tbalestr.028670._000043.skimmed.root
//////////////////////////////////////////////////////////

#ifndef dummy_h
#define dummy_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class dummy {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

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
   vector<float>   *mu_E;
   vector<float>   *mu_beta;
   vector<float>   *mu_comp;
   vector<float>   *mu_d0;
   vector<float>   *mu_d0Sig;
   vector<float>   *mu_eta;
   vector<float>   *mu_m;
   vector<float>   *mu_momentumBalanceSignificance;
   vector<float>   *mu_momentumLossPull;
   vector<float>   *mu_mt;
   vector<float>   *mu_nucone20;
   vector<float>   *mu_nucone30;
   vector<float>   *mu_nucone40;
   vector<float>   *mu_phi;
   vector<float>   *mu_phi_mu_met;
   vector<float>   *mu_pt;
   vector<float>   *mu_ptcone20;
   vector<float>   *mu_ptcone30;
   vector<float>   *mu_ptcone40;
   vector<float>   *mu_ptid;
   vector<float>   *mu_scatteringCurvatureSignificance;
   vector<float>   *mu_tag_E;
   vector<float>   *mu_tag_eta;
   vector<float>   *mu_tag_m;
   vector<float>   *mu_tag_phi;
   vector<float>   *mu_tag_pt;
   vector<float>   *mu_tag_ptcone20;
   vector<float>   *mu_tag_ptcone30;
   vector<float>   *mu_tag_ptcone40;
   vector<float>   *mu_z0;
   vector<float>   *mu_z0Sig;
   vector<vector<float> > *mu_rec_IDprobe_charge;
   vector<vector<float> > *mu_rec_IDprobe_eta;
   vector<vector<float> > *mu_rec_IDprobe_phi;
   vector<vector<float> > *mu_rec_IDprobe_pt;
   vector<vector<float> > *mu_rec_MSprobe_charge;
   vector<vector<float> > *mu_rec_MSprobe_eta;
   vector<vector<float> > *mu_rec_MSprobe_phi;
   vector<vector<float> > *mu_rec_MSprobe_pt;
   vector<vector<float> > *mu_trig_EF_mu8_probe_charge;
   vector<vector<float> > *mu_trig_EF_mu8_probe_eta;
   vector<vector<float> > *mu_trig_EF_mu8_probe_phi;
   vector<vector<float> > *mu_trig_EF_mu8_probe_pt;
   vector<int>     *mu_EF_mu8_isMatched;
   vector<int>     *mu_ZCandidate;
   vector<int>     *mu_charge;
   vector<int>     *mu_isTagMuon;
   vector<int>     *mu_rec_IDprobe_n;
   vector<int>     *mu_rec_MSprobe_n;
   vector<int>     *mu_tag_charge;
   vector<int>     *mu_trig_EF_mu8_probe_n;
   vector<vector<int> > *mu_rec_IDprobe_isMatched;
   vector<vector<int> > *mu_rec_MSprobe_isMatched;
   vector<vector<int> > *mu_trig_EF_mu8_probe_isMatched;

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
   TBranch        *b_mu_tag_E;   //!
   TBranch        *b_mu_tag_eta;   //!
   TBranch        *b_mu_tag_m;   //!
   TBranch        *b_mu_tag_phi;   //!
   TBranch        *b_mu_tag_pt;   //!
   TBranch        *b_mu_tag_ptcone20;   //!
   TBranch        *b_mu_tag_ptcone30;   //!
   TBranch        *b_mu_tag_ptcone40;   //!
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
   TBranch        *b_mu_ZCandidate;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_isTagMuon;   //!
   TBranch        *b_mu_rec_IDprobe_n;   //!
   TBranch        *b_mu_rec_MSprobe_n;   //!
   TBranch        *b_mu_tag_charge;   //!
   TBranch        *b_mu_trig_EF_mu8_probe_n;   //!
   TBranch        *b_mu_rec_IDprobe_isMatched;   //!
   TBranch        *b_mu_rec_MSprobe_isMatched;   //!
   TBranch        *b_mu_trig_EF_mu8_probe_isMatched;   //!

   dummy(TTree *tree=0);
   virtual ~dummy();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef dummy_cxx
dummy::dummy(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/usatlas/u/tbales/scratch/user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2014.08.22.v01.218677_skimmed.root.646867/user.tbalestr.028670._000043.skimmed.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/usatlas/u/tbales/scratch/user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2014.08.22.v01.218677_skimmed.root.646867/user.tbalestr.028670._000043.skimmed.root");
      }
      f->GetObject("MuonD3PD",tree);

   }
   Init(tree);
}

dummy::~dummy()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t dummy::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t dummy::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void dummy::Init(TTree *tree)
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
   mu_tag_E = 0;
   mu_tag_eta = 0;
   mu_tag_m = 0;
   mu_tag_phi = 0;
   mu_tag_pt = 0;
   mu_tag_ptcone20 = 0;
   mu_tag_ptcone30 = 0;
   mu_tag_ptcone40 = 0;
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
   mu_ZCandidate = 0;
   mu_charge = 0;
   mu_isTagMuon = 0;
   mu_rec_IDprobe_n = 0;
   mu_rec_MSprobe_n = 0;
   mu_tag_charge = 0;
   mu_trig_EF_mu8_probe_n = 0;
   mu_rec_IDprobe_isMatched = 0;
   mu_rec_MSprobe_isMatched = 0;
   mu_trig_EF_mu8_probe_isMatched = 0;
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
   fChain->SetBranchAddress("EF_mu8", &EF_mu8, &b_EF_mu8);
   fChain->SetBranchAddress("mu_n", &mu_n, &b_mu_n);
   fChain->SetBranchAddress("mu_rec_tag_n", &mu_rec_tag_n, &b_mu_rec_tag_n);
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
   fChain->SetBranchAddress("mu_tag_E", &mu_tag_E, &b_mu_tag_E);
   fChain->SetBranchAddress("mu_tag_eta", &mu_tag_eta, &b_mu_tag_eta);
   fChain->SetBranchAddress("mu_tag_m", &mu_tag_m, &b_mu_tag_m);
   fChain->SetBranchAddress("mu_tag_phi", &mu_tag_phi, &b_mu_tag_phi);
   fChain->SetBranchAddress("mu_tag_pt", &mu_tag_pt, &b_mu_tag_pt);
   fChain->SetBranchAddress("mu_tag_ptcone20", &mu_tag_ptcone20, &b_mu_tag_ptcone20);
   fChain->SetBranchAddress("mu_tag_ptcone30", &mu_tag_ptcone30, &b_mu_tag_ptcone30);
   fChain->SetBranchAddress("mu_tag_ptcone40", &mu_tag_ptcone40, &b_mu_tag_ptcone40);
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
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_charge", &mu_trig_EF_mu8_probe_charge, &b_mu_trig_EF_mu8_probe_charge);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_eta", &mu_trig_EF_mu8_probe_eta, &b_mu_trig_EF_mu8_probe_eta);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_phi", &mu_trig_EF_mu8_probe_phi, &b_mu_trig_EF_mu8_probe_phi);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_pt", &mu_trig_EF_mu8_probe_pt, &b_mu_trig_EF_mu8_probe_pt);
   fChain->SetBranchAddress("mu_EF_mu8_isMatched", &mu_EF_mu8_isMatched, &b_mu_EF_mu8_isMatched);
   fChain->SetBranchAddress("mu_ZCandidate", &mu_ZCandidate, &b_mu_ZCandidate);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_isTagMuon", &mu_isTagMuon, &b_mu_isTagMuon);
   fChain->SetBranchAddress("mu_rec_IDprobe_n", &mu_rec_IDprobe_n, &b_mu_rec_IDprobe_n);
   fChain->SetBranchAddress("mu_rec_MSprobe_n", &mu_rec_MSprobe_n, &b_mu_rec_MSprobe_n);
   fChain->SetBranchAddress("mu_tag_charge", &mu_tag_charge, &b_mu_tag_charge);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_n", &mu_trig_EF_mu8_probe_n, &b_mu_trig_EF_mu8_probe_n);
   fChain->SetBranchAddress("mu_rec_IDprobe_isMatched", &mu_rec_IDprobe_isMatched, &b_mu_rec_IDprobe_isMatched);
   fChain->SetBranchAddress("mu_rec_MSprobe_isMatched", &mu_rec_MSprobe_isMatched, &b_mu_rec_MSprobe_isMatched);
   fChain->SetBranchAddress("mu_trig_EF_mu8_probe_isMatched", &mu_trig_EF_mu8_probe_isMatched, &b_mu_trig_EF_mu8_probe_isMatched);
   Notify();
}

Bool_t dummy::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void dummy::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t dummy::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef dummy_cxx
