#ifndef _GapCalculator_h_
#define _GapCalculator_h_

#include <cmath>
#include <vector>
#include <set>

class GapCalculator 
{
public:
  enum GapEdgeTypes {Undefined = -1, EdgeGap = 0, FilledTrk, FilledClus, FilledComb, FilledBoth};

  struct Gap
  {
    float _lowerEta;
    float _upperEta;
    int _lowerEdgeType;
    int _upperEdgeType;
    
    Gap() : _lowerEta(-10), _upperEta(-10), _lowerEdgeType(Undefined), _upperEdgeType(Undefined) {}
    
    Gap(float lowerEta, int lowerEdgeType, float upperEta, int upperEdgeType) :
      _lowerEta(lowerEta), _lowerEdgeType(lowerEdgeType), 
      _upperEta(upperEta), _upperEdgeType(upperEdgeType) 
    {}
    
    float Size() const {return _upperEta - _lowerEta;}
  };

  struct GapPredicate
  {
    bool operator()(const Gap& a, const Gap& b) 
    {
      return (a.Size() > b.Size());
    }
  };


private:

  // these keep track of the number of tracks and clusters in each eta
  // ring. bin #0 is -4.9 to -4.7, #48 is +4.7 to +4.9, etc.
  int _scheme;
  int _nBins;
  float _minPtTrk;
  float _minPtClus;
  float _minCellSig;

  float _binSize;
  std::vector<float> _samplingMinCellSig;

  std::vector<int> _ncl;
  std::vector<int> _ntrk;
  std::vector<float> _ptSumTrk;
  std::vector<float> _ptSumClus;

  Gap _nullGap;

  bool _gapsAnalyzed;
  std::multiset<GapCalculator::Gap, GapPredicate> _gaps;  

  int _eta_to_bin(float eta) {
    // this helper function converts a pseudorapidity value into the
    // ring index
    
    // casting to int after floor is safe
    return (int) std::floor( ( eta + 4.9 ) / _binSize );
    
    // e.g. eta from -4.9 to -4.7 will be bin 0
    //      eta from -4.7 to -4.5 will be bin 1, etc.
  }

  // this helper function converts a ring index to lower ring edge
  //
  float BinToLowerEta(int n) 
  {
    return -4.9 + n*_binSize;
  }

  // this helper function converts a ring index to lower ring edge
  //
  float BinToUpperEta(int n) 
  {
    return -4.9 + (n + 1)*_binSize;
  }

public:

  GapCalculator(int scheme, int nBins, float minPtTrk = 0.2, float minPtClus = 0.2, float minCellSig = 5) :
    _scheme(scheme), _nBins(nBins),
    _minPtTrk(minPtTrk), _minPtClus(minPtClus), _minCellSig(minCellSig)
  {
    _binSize = 9.8/_nBins;
    _samplingMinCellSig.assign(25, minCellSig); 
  }

  void SetSamplingMinCellSig(int sampling, float minCellSig) {_samplingMinCellSig.at(sampling) = minCellSig;}
 
  int GetGapCount() const {return _gaps.size();}

  float GetMaxGapSize() const
  {
    if (!_gapsAnalyzed || _gaps.size() == 0) return -1;
    return _gaps.begin()->Size();
  }

  const Gap& GetMaxGap() const
  {
    if (!_gapsAnalyzed || _gaps.size() == 0) return _nullGap;
    return *(_gaps.begin());
  }

  std::vector<GapCalculator::Gap> GetSortedGapList(float minGapSize) const
  {
    std::vector<GapCalculator::Gap> list;

    for (std::multiset<GapCalculator::Gap, GapPredicate>::const_iterator iter = _gaps.begin();
	 iter != _gaps.end(); iter++) {
      if (iter->Size() > minGapSize) list.push_back(*iter);
      else break;
    }

    return list;
  }

  void Clear() 
  {
    _ncl.assign(_nBins, 0);
    _ntrk.assign(_nBins, 0);

    _ptSumTrk.assign(_nBins, 0);
    _ptSumClus.assign(_nBins, 0);

    _gapsAnalyzed = false;
    _gaps.clear();
  }

  void SetData(const std::vector<float>& clusterEta, const std::vector<float>& clusterPt, 
	       const std::vector<float>& clusterMaxCellSig, const std::vector<int>& clusterMaxSigSampling,
	       const std::vector<float>& trackEta, const std::vector<float>& trackPt);

  int AnalyzeGaps();
};

#endif
