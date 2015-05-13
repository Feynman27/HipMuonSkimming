#ifndef pPbMinBiasUtil_h
#define pPbMinBiasUtil_h

#include <TROOT.h>

#include <TFile.h>
#include <TH1D.h>
#include <TGraph.h>

#include <vector>
#include <iostream>

#include <cmath>
#include <string>

class pPbMinBiasUtil {

 public:
  pPbMinBiasUtil();
  ~pPbMinBiasUtil(){if (_file) delete _file;};

  void Configure(std::string fn);

  void CalculateGap( int run, std::vector<float> *cl_hadTopo_eta,	\
		     std::vector<float> *cl_hadTopo_phi,\
		     std::vector<float> *cl_hadTopo_pt,\
		     std::vector<float> *cl_hadTopo_cellSignificance,\
		     std::vector<float> *cl_hadTopo_cellSigSampling,\
		     std::vector<float> *good_track_eta ) ;

  double GetCorrectedFCalET(int run, double fcal_ET, float vx_z);

  void SetVerbosityLevel(int level = 2) {
    _verbosity = level;
  }

  double GetProtonGap() {
    return _protonGap;
  }
  double GetNuclearGap() { 
    return _nuclearGap;
  }

  

 private:
  void CalibrateRun(int run);

  bool passClusterMask(double samp, double eta, double phi);
  bool passClusterSigThreshold(double samp, double cellsig);

  int eta2bin(double eta) {
    return floor( (+4.9 + eta) / 0.1 );
  }
  
  int phi2bin(double phi) {
    return floor( (+3.14159 + phi) / ( 2 * 3.14159 / 64.0) );
  }

  int _verbosity;

  int _run;
  TFile* _file;

  TH1D *_h1_particle_eta;
  double _protonGap;
  double _nuclearGap;

  double _fcal_pedestal_A;
  double _fcal_pedestal_C;
  bool _orientation_pPb;

  std::vector<int> *_hotmask_layer;
  std::vector<int> *_hotmask_phibin;
  std::vector<int> *_hotmask_etabin;

  double _cellsigthreshold_EMB;
  double _cellsigthreshold_EME;
  double _cellsigthreshold_HEC;
  double _cellsigthreshold_Tile;
  double _cellsigthreshold_FCAL;

  double _fcal_vtxCorrScale_A;
  double _fcal_vtxCorrScale_C;
  double _fcal_FCalCA_Scale;

  double _corrected_fcal_ET;

  TGraph* _pPbMinBiasUtil_Config_CellSigThresholds;
  TGraph* _pPbMinBiasUtil_Config_pedestals_A;
  TGraph* _pPbMinBiasUtil_Config_pedestals_C;

};


#endif


