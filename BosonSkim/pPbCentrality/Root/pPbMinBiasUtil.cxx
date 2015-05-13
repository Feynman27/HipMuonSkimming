#define pPbMinBiasUtil_cxx

#include "../pPbCentrality/pPbMinBiasUtil.h"


pPbMinBiasUtil::pPbMinBiasUtil() {

  _fcal_vtxCorrScale_A = 0;
  _fcal_vtxCorrScale_C= 0;
  _fcal_FCalCA_Scale = 0;

  _protonGap = 0;
  _nuclearGap = 0;

  _h1_particle_eta = new TH1D("_pPbMinBiasUtil_h1_temp_particle_eta","",49,-4.9,+4.9);

  _hotmask_layer = new std::vector<int>();
  _hotmask_phibin = new std::vector<int>();
  _hotmask_etabin = new std::vector<int>();

  _cellsigthreshold_EMB = 4.0;
  _cellsigthreshold_EME = 4.0;
  _cellsigthreshold_HEC = 4.0;
  _cellsigthreshold_Tile = 4.0;
  _cellsigthreshold_FCAL = 4.0;

  _fcal_pedestal_A = 0;
  _fcal_pedestal_C = 0;

  _run = 0;
  _file = 0;

  _verbosity = 1;

  _orientation_pPb = true;

}

void pPbMinBiasUtil::CalibrateRun(int run)
{

  if (run==_run) return;

  _run = run;

  // determine orientation
  if (_run > 217000 && _run <= 218589) {
    _orientation_pPb = true;
    if (_verbosity >= 1)
      std::cout << "[pPbMinBiasUtil::Configure] run #" << _run << " has p+Pb (period A / pilot) orientation" << std::endl;
  } 
  else if (_run >= 218677 && _run <= 219114) {
    _orientation_pPb = false;
    if (_verbosity >= 1)
      std::cout << "[pPbMinBiasUtil::Configure] run #" << _run << " has Pb+p (period B) orientation" << std::endl;
    
  }
  else if (_run > 219114) {
    _orientation_pPb = false;
    if (_verbosity >= 1) {
      std::cout << "[pPbMinBiasUtil::Configure] run #" << _run << " has p+p (period C) orientation" << std::endl;
      std::cout << "[pPbMinBiasUtil::Configure] \"p-\" and \"Pb-\"-side gaps mean A- and C-side, respectively" << std::endl;
    }    
  }


  // let these be the default values if I can't find the run
  _fcal_pedestal_A = 0;
  _fcal_pedestal_C = 0;

  // read in run-by-run pedestal values

  for (int n = 0; n < _pPbMinBiasUtil_Config_pedestals_A->GetN(); n++) {
    double dummy_run, dummy_fcal_A;
    _pPbMinBiasUtil_Config_pedestals_A->GetPoint(n, dummy_run, dummy_fcal_A);
    if (fabs( dummy_run - run) < 0.5) {
      _fcal_pedestal_A = dummy_fcal_A;
      if (_verbosity >= 1)
	std::cout << "[pPbMinBiasUtil::CalibrateRun] found FCal A pedestal for run #" << _run << " : " << _fcal_pedestal_A << " GeV" << std::endl;
    }
  }


  for (int n = 0; n < _pPbMinBiasUtil_Config_pedestals_C->GetN(); n++) {
    double dummy_run, dummy_fcal_C;
    _pPbMinBiasUtil_Config_pedestals_C->GetPoint(n, dummy_run, dummy_fcal_C);
    if (fabs( dummy_run - run) < 0.5) {
      _fcal_pedestal_C = dummy_fcal_C;
      if (_verbosity >= 1)
	std::cout << "[pPbMinBiasUtil::CalibrateRun] found FCal C pedestal for run #" << _run << " : " << _fcal_pedestal_C << " GeV" << std::endl;
    }
  }


}
void pPbMinBiasUtil::Configure(std::string fn) {

  _file = TFile::Open(fn.data());


  // read in all hotmasks 

  _hotmask_layer->clear();
  _hotmask_etabin->clear();
  _hotmask_phibin->clear();
  
  TGraph *pPbMinBiasUtil_Config_HotMask_Layer = (TGraph*) _file->Get("pPbMinBiasUtil_Config_HotMask_Layer");
  TGraph *pPbMinBiasUtil_Config_HotMask_EtaBin = (TGraph*) _file->Get("pPbMinBiasUtil_Config_HotMask_EtaBin");
  TGraph *pPbMinBiasUtil_Config_HotMask_PhiBin = (TGraph*) _file->Get("pPbMinBiasUtil_Config_HotMask_PhiBin");
  for (int n = 0; n < pPbMinBiasUtil_Config_HotMask_Layer->GetN(); n++) {
    double dummy_index, dummy_layer, dummy_etabin, dummy_phibin;
    pPbMinBiasUtil_Config_HotMask_Layer->GetPoint(n, dummy_index, dummy_layer);
    pPbMinBiasUtil_Config_HotMask_EtaBin->GetPoint(n, dummy_index, dummy_etabin);
    pPbMinBiasUtil_Config_HotMask_PhiBin->GetPoint(n, dummy_index, dummy_phibin);

    _hotmask_layer->push_back( std::floor(dummy_layer + 0.001) );
    _hotmask_etabin->push_back( std::floor(dummy_etabin + 0.001) );
    _hotmask_phibin->push_back( std::floor(dummy_phibin + 0.001) );

    if (_verbosity >= 1)
      std::cout << "[pPbMinBiasUtil::Configure] total hot regions : " <<  _hotmask_layer->size() << " , latest has layer / etabin / phibin = " << _hotmask_layer->at(_hotmask_layer->size() - 1) << " / " << _hotmask_etabin->at(_hotmask_etabin->size() - 1) << " / " << _hotmask_phibin->at(_hotmask_phibin->size() - 1) << std::endl;

  }

  // read in cell significance values
  
  _pPbMinBiasUtil_Config_CellSigThresholds = (TGraph*) _file->Get("pPbMinBiasUtil_Config_CellSigThresholds");
  double dummy_index;
  _pPbMinBiasUtil_Config_CellSigThresholds->GetPoint(0, dummy_index, _cellsigthreshold_EMB);
  _pPbMinBiasUtil_Config_CellSigThresholds->GetPoint(1, dummy_index, _cellsigthreshold_EME);
  _pPbMinBiasUtil_Config_CellSigThresholds->GetPoint(2, dummy_index, _cellsigthreshold_HEC);
  _pPbMinBiasUtil_Config_CellSigThresholds->GetPoint(3, dummy_index, _cellsigthreshold_Tile);
  _pPbMinBiasUtil_Config_CellSigThresholds->GetPoint(4, dummy_index, _cellsigthreshold_FCAL);

  if (_verbosity >= 1) {
    std::cout << "[pPbMinBiasUtil::Configure] EMB cellsig threshold set to " << _cellsigthreshold_EMB << std::endl;
    std::cout << "[pPbMinBiasUtil::Configure] EME cellsig threshold set to " << _cellsigthreshold_EME << std::endl;
    std::cout << "[pPbMinBiasUtil::Configure] HEC cellsig threshold set to " << _cellsigthreshold_HEC << std::endl;
    std::cout << "[pPbMinBiasUtil::Configure] Tile cellsig threshold set to " << _cellsigthreshold_Tile << std::endl;
    std::cout << "[pPbMinBiasUtil::Configure] FCAL cellsig threshold set to " << _cellsigthreshold_FCAL << std::endl;

  }

  _pPbMinBiasUtil_Config_pedestals_A = (TGraph*) _file->Get("pPbMinBiasUtil_Config_pedestals_A");
  _pPbMinBiasUtil_Config_pedestals_C = (TGraph*) _file->Get("pPbMinBiasUtil_Config_pedestals_C");

  TGraph *pPbMinBiasUtil_Config_VtxCorrection_FCalA = (TGraph*) _file->Get("pPbMinBiasUtil_Config_VtxCorrection_FCalA");
  TGraph *pPbMinBiasUtil_Config_VtxCorrection_FCalC = (TGraph*) _file->Get("pPbMinBiasUtil_Config_VtxCorrection_FCalC");
  TGraph *pPbMinBiasUtil_Config_FCalCA_Scale_Factor = (TGraph*) _file->Get("pPbMinBiasUtil_Config_FCalCA_Scale_Factor");

  pPbMinBiasUtil_Config_VtxCorrection_FCalA->GetPoint(0, dummy_index, _fcal_vtxCorrScale_A);
  pPbMinBiasUtil_Config_VtxCorrection_FCalC->GetPoint(0, dummy_index, _fcal_vtxCorrScale_C);
  pPbMinBiasUtil_Config_FCalCA_Scale_Factor->GetPoint(0, dummy_index, _fcal_FCalCA_Scale);

  if (_verbosity >= 1) {
    std::cout << "[pPbMinBiasUtil::Configure] vtx-dependent scale correction for FCal A: " << _fcal_vtxCorrScale_A << std::endl;
    std::cout << "[pPbMinBiasUtil::Configure] vtx-dependent scale correction for FCal C: " << _fcal_vtxCorrScale_C << std::endl;
    std::cout << "[pPbMinBiasUtil::Configure] FCal C --> FCal A energy scale correction factor: " << _fcal_FCalCA_Scale << std::endl;

  }

}

void pPbMinBiasUtil::CalculateGap(int run,
				  std::vector<float> *cl_hadTopo_eta,\
				  std::vector<float> *cl_hadTopo_phi,\
				  std::vector<float> *cl_hadTopo_pt,\
				  std::vector<float> *cl_hadTopo_cellSignificance,\
				  std::vector<float> *cl_hadTopo_cellSigSampling,
				  std::vector<float> *good_track_eta) 
{
  
  CalibrateRun(run);

  _h1_particle_eta->Reset();
  
  for (unsigned int cl = 0; cl < cl_hadTopo_eta->size(); cl++) {
    double pt = cl_hadTopo_pt->at(cl) * 1e-3;
    if (pt < 0.2) continue;
    double eta = cl_hadTopo_eta->at(cl);
    double phi = cl_hadTopo_phi->at(cl);
    double sampling = cl_hadTopo_cellSigSampling->at(cl);
    
    if (!passClusterMask(sampling, eta, phi))
      continue;

    double cellsig = cl_hadTopo_cellSignificance->at(cl);
    
    if (!passClusterSigThreshold(sampling, cellsig))
      continue;

    // at this point, it is a good cluster
    _h1_particle_eta->Fill( eta );

  }
 
  // read in all tracks
  for (unsigned int tr = 0; tr < good_track_eta->size(); tr++) {
    double eta = good_track_eta->at(tr);
    _h1_particle_eta->Fill( eta );
  }

  // ready to calculate gaps!
  
  int n_gap_A = 0;
  int n_gap_C = 0;
  
  for (int n = 0; n < 49; n++) {
    if (_h1_particle_eta->GetBinContent(n+1) < 0.5)
      n_gap_C++;
    else
      break;
  }
  
  for (int n = 48; n > -1; n--) {
    if (_h1_particle_eta->GetBinContent(n+1) < 0.5)
      n_gap_A++;
    else
      break;
  }
  
  if (_orientation_pPb) {
    _nuclearGap = n_gap_A * 0.20;
    _protonGap = n_gap_C * 0.20;
  } else {
    _nuclearGap = n_gap_C * 0.20;
    _protonGap = n_gap_A * 0.20;

  }
 
}


double pPbMinBiasUtil::GetCorrectedFCalET(int run, double fcal_ET, float vx_z) {

  CalibrateRun(run);

  _corrected_fcal_ET = fcal_ET;

  if (_orientation_pPb) {
    // this is the FCal A
    _corrected_fcal_ET -= _fcal_pedestal_A;
    _corrected_fcal_ET = _corrected_fcal_ET * (1.0 + _fcal_vtxCorrScale_A * vx_z);
  } else {
    // this is the FCal C
    _corrected_fcal_ET -= _fcal_pedestal_C;
    _corrected_fcal_ET = _corrected_fcal_ET * (1.0 + _fcal_vtxCorrScale_C * vx_z);
    _corrected_fcal_ET = _corrected_fcal_ET * _fcal_FCalCA_Scale;
  }

  return _corrected_fcal_ET;
}


bool pPbMinBiasUtil::passClusterSigThreshold(double layer, double cellsig) {

  if (layer > -0.5 && layer < 3.5) {
    return (cellsig > _cellsigthreshold_EMB);
  }
  else if (layer > 3.5 && layer < 7.5) {
    return (cellsig > _cellsigthreshold_EME);
  }
  else if (layer > 7.5 && layer < 11.5) {
    return (cellsig > _cellsigthreshold_HEC);
  }
  else if (layer > 11.5 && layer < 20.5) {
    return (cellsig > _cellsigthreshold_Tile);
  }
  else if (layer > 20.5 && layer < 23.5) {
    return (cellsig > _cellsigthreshold_FCAL);
  }
  else {
    // this is an alien cellsigsampling value
    // --> kill this cluster
    return false;

  }
}

bool pPbMinBiasUtil::passClusterMask(double layer, double eta, double phi) {

  int etabin = eta2bin(eta);
  int phibin = phi2bin(phi);
  int layerbin = std::floor( layer + 0.001 );

  for (unsigned int n = 0; n < _hotmask_layer->size(); n++) {
    int this_layer = _hotmask_layer->at(n);
    if ( this_layer != layerbin )
      continue;
    int this_etabin = _hotmask_etabin->at(n);
    if ( this_etabin != etabin )
      continue;
    int this_phibin = _hotmask_phibin->at(n);
    if ( this_phibin != phibin )
      continue;
    
    return false;
  }
  
  // if we have fallen through all of the possible hot regions
  return true;

}
