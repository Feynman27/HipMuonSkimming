#define HeavyIonD3PD_cxx
#include "HeavyIonD3PD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void HeavyIonD3PD::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L HeavyIonD3PD.C
//      Root > HeavyIonD3PD t
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

void HeavyIonD3PD::ActivateBranches(Long64_t entry) {
    ActivateEventBranches(entry);
    ActivateVtxBranches(entry);
    ActivateFCalBranches(entry);
    ActivateTriggerBranches(entry);
    ActivateCaloBranches(entry);
    ActivateTrkBranches(entry);
}

void HeavyIonD3PD::ActivateMuBranches(Long64_t entry) {
    b_mu_n->GetEntry(entry);
    b_mu_medium->GetEntry(entry);
    b_mu_author->GetEntry(entry);
    b_mu_nprecisionLayers->GetEntry(entry);
    b_mu_eta->GetEntry(entry);
    b_mu_momentumBalanceSignificance->GetEntry(entry);
    b_mu_isCombinedMuon->GetEntry(entry);
    b_mu_nPixHits->GetEntry(entry);
    b_mu_expectBLayerHit->GetEntry(entry);
    b_mu_nBLHits->GetEntry(entry);
    b_mu_nSCTHits->GetEntry(entry);
    b_mu_nPixHoles->GetEntry(entry);
    b_mu_nSCTHoles->GetEntry(entry);
    b_mu_id_d0_exPV->GetEntry(entry);
    b_mu_id_z0_exPV->GetEntry(entry);
    b_mu_id_theta_exPV->GetEntry(entry);
    b_mu_matchchi2->GetEntry(entry);
    b_mu_matchndof->GetEntry(entry);
    b_mu_scatteringCurvatureSignificance->GetEntry(entry);
    b_mu_E->GetEntry(entry);
    b_mu_pt->GetEntry(entry);
    b_mu_px->GetEntry(entry);
    b_mu_py->GetEntry(entry);
    b_mu_pz->GetEntry(entry);
    b_mu_id_qoverp_exPV->GetEntry(entry);
    b_mu_id_qoverp->GetEntry(entry);
    b_mu_phi->GetEntry(entry);
    b_mu_m->GetEntry(entry);
    b_mu_beta->GetEntry(entry);
    b_mu_nucone20->GetEntry(entry);
    b_mu_nucone30->GetEntry(entry);
    b_mu_nucone40->GetEntry(entry);
    b_mu_ptcone20->GetEntry(entry);
    b_mu_ptcone30->GetEntry(entry);
    b_mu_ptcone40->GetEntry(entry);
    b_mu_charge->GetEntry(entry);
    b_mu_d0_exPV->GetEntry(entry);
    b_mu_z0_exPV->GetEntry(entry);
    b_mu_cov_d0_exPV->GetEntry(entry);
    b_mu_cov_z0_exPV->GetEntry(entry);
    b_mu_me_phi->GetEntry(entry);
    b_mu_me_theta->GetEntry(entry);
    b_mu_me_qoverp->GetEntry(entry);
    b_mu_ms_phi->GetEntry(entry);
    b_mu_ms_theta->GetEntry(entry);
    b_mu_ms_qoverp->GetEntry(entry);
    if(m_doTruth){
       b_mu_truth_dr->GetEntry(entry); 
       b_mu_truth_E->GetEntry(entry);
       b_mu_truth_pt->GetEntry(entry);
       b_mu_truth_eta->GetEntry(entry);
       b_mu_truth_phi->GetEntry(entry);
       b_mu_truth_type->GetEntry(entry);
       b_mu_truth_barcode->GetEntry(entry);
       b_mu_truth_mothertype->GetEntry(entry);
       b_mu_truth_motherbarcode->GetEntry(entry);
       b_mu_truth_matched->GetEntry(entry);
    }

}

void HeavyIonD3PD::ActivateTruthBranches(Long64_t entry) {

   b_mc_n->GetEntry(entry);
   b_mc_gen_E->GetEntry(entry);
   b_mc_gen_pt->GetEntry(entry);
   b_mc_gen_eta->GetEntry(entry);
   b_mc_gen_phi->GetEntry(entry);
   b_mc_gen_type->GetEntry(entry);
   b_mc_gen_status->GetEntry(entry);
   b_mc_gen_barcode->GetEntry(entry);
   b_mc_gen_mothertype->GetEntry(entry);
   b_mc_gen_motherbarcode->GetEntry(entry);
   b_mc_charge->GetEntry(entry);
   b_mc_child_n->GetEntry(entry);   //!
   b_mc_child_barcode->GetEntry(entry);   //!
   b_mc_child_pdg->GetEntry(entry);   //!
}

void HeavyIonD3PD::ActivateMuidBranches(Long64_t entry) {
    b_mu_muid_n->GetEntry(entry);
    b_mu_muid_medium->GetEntry(entry);
    b_mu_muid_author->GetEntry(entry);
    b_mu_muid_nprecisionLayers->GetEntry(entry);
    b_mu_muid_eta->GetEntry(entry);
    b_mu_muid_momentumBalanceSignificance->GetEntry(entry);
    b_mu_muid_isCombinedMuon->GetEntry(entry);
    b_mu_muid_nPixHits->GetEntry(entry);
    b_mu_muid_expectBLayerHit->GetEntry(entry);
    b_mu_muid_nBLHits->GetEntry(entry);
    b_mu_muid_nSCTHits->GetEntry(entry);
    b_mu_muid_nPixHoles->GetEntry(entry);
    b_mu_muid_nSCTHoles->GetEntry(entry);
    b_mu_muid_id_d0_exPV->GetEntry(entry);
    b_mu_muid_id_z0_exPV->GetEntry(entry);
    b_mu_muid_id_theta_exPV->GetEntry(entry);
    b_mu_muid_matchchi2->GetEntry(entry);
    b_mu_muid_matchndof->GetEntry(entry);
    b_mu_muid_scatteringCurvatureSignificance->GetEntry(entry);
    b_mu_muid_E->GetEntry(entry);
    b_mu_muid_pt->GetEntry(entry);
    b_mu_muid_px->GetEntry(entry);
    b_mu_muid_py->GetEntry(entry);
    b_mu_muid_pz->GetEntry(entry);
    b_mu_muid_id_qoverp_exPV->GetEntry(entry);
    b_mu_muid_id_qoverp->GetEntry(entry);
    b_mu_muid_phi->GetEntry(entry);
    b_mu_muid_m->GetEntry(entry);
    b_mu_muid_beta->GetEntry(entry);
    b_mu_muid_nucone20->GetEntry(entry);
    b_mu_muid_nucone30->GetEntry(entry);
    b_mu_muid_nucone40->GetEntry(entry);
    b_mu_muid_ptcone20->GetEntry(entry);
    b_mu_muid_ptcone30->GetEntry(entry);
    b_mu_muid_ptcone40->GetEntry(entry);
    b_mu_muid_charge->GetEntry(entry);
    b_mu_muid_d0_exPV->GetEntry(entry);
    b_mu_muid_z0_exPV->GetEntry(entry);
    b_mu_muid_cov_d0_exPV->GetEntry(entry);
    b_mu_muid_cov_z0_exPV->GetEntry(entry);
    b_mu_muid_me_phi->GetEntry(entry);
    b_mu_muid_me_theta->GetEntry(entry);
    b_mu_muid_me_qoverp->GetEntry(entry);

}
void HeavyIonD3PD::ActivateStacoBranches(Long64_t entry) {

    b_mu_staco_n->GetEntry(entry);
    b_mu_staco_medium->GetEntry(entry);
    b_mu_staco_author->GetEntry(entry);
    b_mu_staco_nprecisionLayers->GetEntry(entry);
    b_mu_staco_eta->GetEntry(entry);
    b_mu_staco_momentumBalanceSignificance->GetEntry(entry);
    b_mu_staco_isCombinedMuon->GetEntry(entry);
    b_mu_staco_nPixHits->GetEntry(entry);
    b_mu_staco_expectBLayerHit->GetEntry(entry);
    b_mu_staco_nBLHits->GetEntry(entry);
    b_mu_staco_nSCTHits->GetEntry(entry);
    b_mu_staco_nPixHoles->GetEntry(entry);
    b_mu_staco_nSCTHoles->GetEntry(entry);
    b_mu_staco_id_d0_exPV->GetEntry(entry);
    b_mu_staco_id_z0_exPV->GetEntry(entry);
    b_mu_staco_id_theta_exPV->GetEntry(entry);
    b_mu_staco_matchchi2->GetEntry(entry);
    b_mu_staco_matchndof->GetEntry(entry);
    b_mu_staco_scatteringCurvatureSignificance->GetEntry(entry);
    b_mu_staco_E->GetEntry(entry);
    b_mu_staco_pt->GetEntry(entry);
    b_mu_staco_px->GetEntry(entry);
    b_mu_staco_py->GetEntry(entry);
    b_mu_staco_pz->GetEntry(entry);
    b_mu_staco_id_qoverp_exPV->GetEntry(entry);
    b_mu_staco_id_qoverp->GetEntry(entry);
    b_mu_staco_phi->GetEntry(entry);
    b_mu_staco_m->GetEntry(entry);
    b_mu_staco_beta->GetEntry(entry);
    b_mu_staco_nucone20->GetEntry(entry);
    b_mu_staco_nucone30->GetEntry(entry);
    b_mu_staco_nucone40->GetEntry(entry);
    b_mu_staco_ptcone20->GetEntry(entry);
    b_mu_staco_ptcone30->GetEntry(entry);
    b_mu_staco_ptcone40->GetEntry(entry);
    b_mu_staco_charge->GetEntry(entry);
    b_mu_staco_d0_exPV->GetEntry(entry);
    b_mu_staco_z0_exPV->GetEntry(entry);
    b_mu_staco_cov_d0_exPV->GetEntry(entry);
    b_mu_staco_cov_z0_exPV->GetEntry(entry);
    b_mu_staco_me_phi->GetEntry(entry);
    b_mu_staco_me_theta->GetEntry(entry);
    b_mu_staco_me_qoverp->GetEntry(entry);

}

void HeavyIonD3PD::ActivateTriggerBranches(Long64_t entry) {
    b_EF_mu8->GetEntry(entry);
    b_EF_mbMbts_1_1->GetEntry(entry);
    b_trig_EF_trigmuonef_n->GetEntry(entry);
    b_trig_EF_trigmuonef_EF_mu8->GetEntry(entry);
    b_trig_EF_trigmuonef_track_n->GetEntry(entry);
    b_trig_EF_trigmuonef_track_MS_hasMS->GetEntry(entry);
    b_trig_EF_trigmuonef_track_MS_eta->GetEntry(entry);
    b_trig_EF_trigmuonef_track_MS_phi->GetEntry(entry);
    b_trig_EF_trigmuonef_track_MS_charge->GetEntry(entry);
}

void HeavyIonD3PD::ActivateCaloBranches(Long64_t entry) {
    
    b_cl_hadTopo_eta->GetEntry(entry);
    b_cl_hadTopo_phi->GetEntry(entry);
    b_cl_hadTopo_pt->GetEntry(entry);
    b_cl_hadTopo_cellSignificance->GetEntry(entry);
    b_cl_hadTopo_cellSigSampling->GetEntry(entry);
    b_MET_RefFinal_etx->GetEntry(entry);
    b_MET_RefFinal_ety->GetEntry(entry);
    b_MET_RefFinal_et->GetEntry(entry);
    b_MET_RefFinal_phi->GetEntry(entry);
}

void HeavyIonD3PD::ActivateTrkBranches(Long64_t entry) {

    b_trk_n->GetEntry(entry);
    b_trk_pt->GetEntry(entry);
    b_trk_phi->GetEntry(entry);
    b_trk_nSCTHits->GetEntry(entry);
    b_trk_nPixHits->GetEntry(entry);
    b_trk_eta->GetEntry(entry);
    b_trk_expectBLayerHit->GetEntry(entry);
    b_trk_nBLHits->GetEntry(entry);
    b_trk_d0_wrtPV->GetEntry(entry);
    b_trk_err_d0_wrtPV->GetEntry(entry);
    b_trk_theta->GetEntry(entry);
    b_trk_err_theta->GetEntry(entry);
    b_trk_z0_wrtPV->GetEntry(entry);
    b_trk_err_z0_wrtPV->GetEntry(entry);
    b_trk_cov_z0_theta->GetEntry(entry);
    b_trk_patternReco1->GetEntry(entry);
    b_trk_patternReco2->GetEntry(entry);
    b_trk_qoverp->GetEntry(entry);
}

void HeavyIonD3PD::ActivateFCalBranches(Long64_t entry) {
    
    b_cccEt_n_Eh_FCal->GetEntry(entry);
    b_cccEt_p_Eh_FCal->GetEntry(entry);
}

void HeavyIonD3PD::ActivateEventBranches(Long64_t entry) {
    b_RunNumber->GetEntry(entry);
    b_EventNumber->GetEntry(entry);
    b_lbn->GetEntry(entry);
    b_bcid->GetEntry(entry);
    b_vx_n->GetEntry(entry);
    b_trig_EF_passedPhysics->GetEntry(entry);
}

void HeavyIonD3PD::ActivateVtxBranches(Long64_t entry) {
    b_vx_x->GetEntry(entry);
    b_vx_y->GetEntry(entry);
    b_vx_z->GetEntry(entry);
    b_vx_nTracks->GetEntry(entry);
    b_mbtime_timeA->GetEntry(entry);
    b_mbtime_timeC->GetEntry(entry);
    b_vx_sumPt->GetEntry(entry);
    /*if(m_doTruth) {
        b_mcVx_x->GetEntry(entry);
        b_mcVx_y->GetEntry(entry);
        b_mcVx_z->GetEntry(entry);
    }*/

}

bool HeavyIonD3PD::SelectEvent() {
    GoodLumiEvent lumiEvt(RunNumber, lbn, bcid);
    if( (!m_doTruth) && (!lumiEvt.isGoodEvent()) ) return false;
    // Pile-up rejection
/*    int ipileup = 0;
    // Skip the primary vertex
    for (int ivx=1; ivx<vx_n; ++ivx){

        // Event with two (real) vertices
        // i.e. not including the dummy vertex
        if(vx_n>2){
           // If the secondary vertex has sumPt > 5.0 GeV or > 10 tracks
           // classify the event as a pileup event
           if( (vx_sumPt->at(ivx)/1000.0 > 5.0) || (vx_nTracks->at(ivx) > 10) ) ++ipileup;
        }
    }//ivx
    if(ipileup>0) return false;
*/
    if(!(vx_n > 1 &&
        vx_nTracks->at(0) > 2 &&
        fabs(mbtime_timeA-mbtime_timeC)< 10.0 &&
        vx_z->at(0) <200.0)
      ) return false;


    // Diffractive Event rejection
    // Only use if diffractive part of
    // the cross-section is not needed.
    //for the rapidity gap calculation tool make a vector of the eta values of all the good tracks
/*    std::vector<float> good_track_eta;
    good_track_eta.clear();
    for (int itr = 0;itr<trk_n;itr++){
        if (isGoodTrack(itr))
        {
            good_track_eta.push_back(trk_eta->at(itr));
        }
    }

    //Calculate the rapidity gap
    centralityTool.CalculateGap(RunNumber,cl_hadTopo_eta,cl_hadTopo_phi,cl_hadTopo_pt,cl_hadTopo_cellSignificance,cl_hadTopo_cellSigSampling,&good_track_eta);
    double gapB = centralityTool.GetNuclearGap();
    double gapF = centralityTool.GetProtonGap();
    
    if(gapB>2.1) return false; //looks like a diffractive event
*/
    // This is not a diffractive or pile-up event
    // Now select on the trigger
    hNEvtAll->Fill(RunNumber);
    ++evtCountBefTrig;
    // Does event have a high pT online muon?
    //if(!m_doMinBias && !m_doTruth && EF_mu8==0) return false;
    // If selecting on minbias
    //if(m_doMinBias && !m_doTruth && EF_mbMbts_1_1==0) return false;
    // Tot # of muon trigger-selected events
    hNEvtSel->Fill(RunNumber);
    ++evtCountAftTrig;
    return true;
}

bool HeavyIonD3PD::isPileUpEvent() {
    // Pile-up rejection
    int ipileup = 0;
    // Skip the primary vertex
    for (int ivx=1; ivx<vx_n; ++ivx){

        // Event with two (real) vertices
        // i.e. not including the dummy vertex
        if(vx_n>2){
           // If the secondary vertex has sumPt > 5.0 GeV or > 10 tracks
           // classify the event as a pileup event
           if( (vx_sumPt->at(ivx)/1000.0 > 5.0) || (vx_nTracks->at(ivx) > 10) ) ++ipileup;
        }
    }//ivx
    if(ipileup>0) return false;

    return true;
}

bool HeavyIonD3PD::isDiffractiveEvent() {

    // Diffractive Event rejection
    // Only use if diffractive part of
    // the cross-section is not needed.
    //for the rapidity gap calculation tool make a vector of the eta values of all the good tracks
    std::vector<float> good_track_eta;
    good_track_eta.clear();
    for (int itr = 0;itr<trk_n;itr++){
        if (isGoodTrack(itr))
        {
            good_track_eta.push_back(trk_eta->at(itr));
        }
    }

    //Calculate the rapidity gap
    centralityTool.CalculateGap(RunNumber,cl_hadTopo_eta,cl_hadTopo_phi,cl_hadTopo_pt,cl_hadTopo_cellSignificance,cl_hadTopo_cellSigSampling,&good_track_eta);
    double gapB = centralityTool.GetNuclearGap();
    double gapF = centralityTool.GetProtonGap();
    
    if(gapB>2.1) return false; //looks like a diffractive event

    return true;
}


// From Peter and Dennis
// this function checks whether a given track is good enough to be included in the rapdity gap calcualtion
bool HeavyIonD3PD::isGoodTrack(Int_t t)
{

  float pt =  trk_pt->at(t) * 1e-3;
  int si = trk_nSCTHits->at(t);
  int pi = trk_nPixHits->at(t);

  if (fabs(trk_eta->at(t)) > 2.5) return false;
  if (pt < 0.100) return false;
  if (pt > 0.100 && pt < 0.200) {
    if (si < 2) return false;
  }
  if (pt > 0.200 && pt < 0.300) {
    if (si < 4) return false;
  }
  if (pt > 0.300) {
    if (si < 6) return false;
  }
  if (pi < 1) return false;
  
  if (trk_expectBLayerHit->at(t) == 1 && trk_nBLHits->at(t) == 0) return false;

  double d0 = trk_d0_wrtPV->at(t);
  double err_d0 = trk_err_d0_wrtPV->at(t);
  double sig_d0 = fabs(d0 / err_d0);
  
  double theta = trk_theta->at(t);
  double err_theta = trk_err_theta->at(t);
  
  double z0 = trk_z0_wrtPV->at(t);
  double err_z0 = trk_err_z0_wrtPV->at(t);
  
  double covariance_z0_theta = trk_cov_z0_theta->at(t);
  
  double z0sintheta = z0 * sin( theta );
  
  double error_1 = pow(err_z0 * sin( theta ), 2);
  double error_2 = pow(z0 * cos( theta ) * err_theta, 2);
  
  double error_3 = 2 * ( sin(theta) ) * ( z0 * cos(theta) ) * covariance_z0_theta;
  double err_z0sintheta = sqrt( error_1 + error_2 + error_3);
  
  double sig_z0sintheta = fabs(z0sintheta / err_z0sintheta);

  if (fabs(sig_d0) > 3) return false;
  if (fabs(sig_z0sintheta) > 3) return false;
  
  if (fabs(d0) > 1.5) return false;
  if (fabs(z0sintheta) > 1.5) return false;
  
  int p1 = trk_patternReco1->at(t) ;
  int p2 = trk_patternReco2->at(t) ;
  
  bool fire_p1 = ((p1 & 1) == 1);
  bool fire_p2 = ((p2 & 16) == 16);
  
  if (!fire_p1 && !fire_p2) {
    return false;
  }
  
  return true;
}


