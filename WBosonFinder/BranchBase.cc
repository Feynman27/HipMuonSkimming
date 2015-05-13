#define BranchBase_cxx
#include "BranchBase.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void BranchBase::ActivateWBosonFinder(int entry){

    b_MET_RefFinal_etx->GetEntry(entry);
    b_MET_RefFinal_ety->GetEntry(entry);
    b_MET_RefFinal_et->GetEntry(entry);
    b_MET_RefFinal_phi->GetEntry(entry);
    b_mu_n->GetEntry(entry);
    b_mu_eta->GetEntry(entry);
    b_mu_mt->GetEntry(entry);
    b_mu_phi->GetEntry(entry);
    b_mu_phi_mu_met->GetEntry(entry);
    b_mu_ptcone20->GetEntry(entry);
    b_mu_ptcone30->GetEntry(entry);
    b_mu_ptcone40->GetEntry(entry);
    b_mu_ZCandidateType1->GetEntry(entry);
    b_mu_ZCandidateType2->GetEntry(entry);
    b_mu_charge->GetEntry(entry);
    b_mu_pt->GetEntry(entry);
    b_mu_EF_mu8_isMatched->GetEntry(entry);   
    if(m_doTruth){

        b_mu_rec_truth_E->GetEntry(entry);   //!
        b_mu_rec_truth_dr->GetEntry(entry);   //!
        b_mu_rec_truth_eta->GetEntry(entry);   //!
        b_mu_rec_truth_phi->GetEntry(entry);   //!
        b_mu_rec_truth_pt->GetEntry(entry);   //!
        b_mu_rec_truth_matched->GetEntry(entry);   //!
        b_mu_rec_truth_mother_pdg->GetEntry(entry);   //!
        b_mu_rec_truth_pdg->GetEntry(entry);   //!
    }
}

void BranchBase::ActivateTruth(int entry){

    b_gen_E->GetEntry(entry);
    b_gen_charge->GetEntry(entry);
    b_gen_eta->GetEntry(entry);
    b_gen_phi->GetEntry(entry);
    b_gen_pt->GetEntry(entry);
    b_gen_mother_pdg->GetEntry(entry);
    b_gen_pdg->GetEntry(entry);
}

void BranchBase::ActivateTags(int entry){

    b_mu_rec_tag_n->GetEntry(entry);
    b_mu_tag_E->GetEntry(entry);
    b_mu_tag_eta->GetEntry(entry);
    b_mu_tag_phi->GetEntry(entry);
    b_mu_tag_pt->GetEntry(entry);
    b_mu_tag_m->GetEntry(entry);
    b_mu_tag_charge->GetEntry(entry);
}

void BranchBase::ActivateIDProbes(int entry){

    b_mu_rec_IDprobe_n->GetEntry(entry);
    b_mu_rec_IDprobe_charge->GetEntry(entry);
    b_mu_rec_IDprobe_pt->GetEntry(entry);
    b_mu_rec_IDprobe_eta->GetEntry(entry);
    b_mu_rec_IDprobe_phi->GetEntry(entry);
    b_mu_rec_IDprobe_isMatched->GetEntry(entry);

}

void BranchBase::ActivateMSProbes(int entry){

    b_mu_rec_MSprobe_n->GetEntry(entry);
    b_mu_rec_MSprobe_charge->GetEntry(entry);
    b_mu_rec_MSprobe_pt->GetEntry(entry);
    b_mu_rec_MSprobe_eta->GetEntry(entry);
    b_mu_rec_MSprobe_phi->GetEntry(entry);
    b_mu_rec_MSprobe_isMatched->GetEntry(entry);
}

void BranchBase::ActivateEventVariables(int entry){
    b_RunNumber->GetEntry(entry);
    b_EventNumber->GetEntry(entry);
    b_vx_z->GetEntry(entry);
    b_centrality->GetEntry(entry);
    b_fcal->GetEntry(entry);
}

void BranchBase::ActivateTriggerProbes(int entry){

    b_mu_EF_mu8_isMatched->GetEntry(entry);
    b_mu_trig_EF_mu8_probe_n->GetEntry(entry);
    b_mu_trig_EF_mu8_probe_charge->GetEntry(entry);
    b_mu_trig_EF_mu8_probe_pt->GetEntry(entry);
    b_mu_trig_EF_mu8_probe_eta->GetEntry(entry);
    b_mu_trig_EF_mu8_probe_phi->GetEntry(entry);
    b_mu_trig_EF_mu8_probe_isMatched->GetEntry(entry);
}

void BranchBase::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L BranchBase.C
//      Root > BranchBase t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}
