#include <GapCalculator.h>
#include <iostream>

void GapCalculator::SetData(const std::vector<float>& clusterEta, const std::vector<float>& clusterPt, 
			    const std::vector<float>& clusterMaxCellSig, const std::vector<int>& clusterMaxSigSampling,
			    const std::vector<float>& trackEta, const std::vector<float>& trackPt)
{
  Clear();

  // read in event clusters and tracks
  for (size_t cl = 0; cl < clusterEta.size(); cl++) {
    float cellSigThresh = _samplingMinCellSig.at(clusterMaxSigSampling[cl]);

    if (clusterPt[cl] > _minPtClus && clusterMaxCellSig[cl] > cellSigThresh) {
      int bin = _eta_to_bin( clusterEta[cl] );
      _ncl[bin]++;
      _ptSumClus[bin] += clusterPt[cl]; 
    }
  }

  for (size_t tr = 0; tr < trackEta.size(); tr++) {
    if (trackPt[tr] > _minPtTrk) {
      int bin = _eta_to_bin( trackEta[tr] );
      _ntrk[bin]++;
      _ptSumTrk[bin] += trackPt[tr];
    }
  }
}

int GapCalculator::AnalyzeGaps()
{
  int currentGapStart = -1;
  int lastFilledType = EdgeGap;

  // iterate through every ring, determining if it is full or empty
  for (int n = 0; n < _nBins; n++) {
    // assume ring is empty by default
    //
    bool ring_nonempty = false;
    bool filledTrk = false;
    bool filledClus = false;

    // depending on the scheme, decide if the ring is filled
    if ( _scheme == 0) {
      filledTrk = _ntrk[n] > 0;
      filledClus = _ncl[n] > 0;
      ring_nonempty = filledTrk || filledClus;
    }
    else if ( _scheme == 1) {
      filledTrk = _ntrk[n] > 1;
      filledClus = _ncl[n] > 1;
      ring_nonempty = ( _ncl[n] + _ntrk[n] >= 2);
    }
    else if (_scheme == 2) {
      filledTrk = _ntrk[n] > 0;
      filledClus = _ncl[n] > 1;
      ring_nonempty = filledTrk || filledClus;
    }
    else if (_scheme == 3) {
      filledClus = _ncl[n] > 1;
      ring_nonempty = filledClus;
    }

    // perform logic depending on ring status
    //
    if (ring_nonempty) {
      // ring is filled, figure out how
      //
      int currentFilledType = Undefined;

      if (filledTrk && !filledClus) currentFilledType = FilledTrk;
      else if (!filledTrk && filledClus) currentFilledType = FilledClus;
      else if (filledTrk && filledClus) currentFilledType = FilledBoth;
      else currentFilledType = FilledComb;

      
      // if we had a gap, add a new entry to the gaps list
      //
      if (currentGapStart != -1) {
	//	std::cout << "ending a gap at index " << n << std::endl;

	float gapLowerEdge = BinToLowerEta(currentGapStart);
	float gapUpperEdge = BinToUpperEta(n - 1);
	_gaps.insert(GapCalculator::Gap(gapLowerEdge, lastFilledType, gapUpperEdge, currentFilledType));
	currentGapStart = -1;
      }

      lastFilledType = currentFilledType;
    }
    else {
      // Ring is empty. Start a gap if we don't already have one going
      //
      if (currentGapStart == -1) {
	currentGapStart = n;
	//	std::cout << "Starting a gap at index " << n << std::endl;
      }
    }
  }
    
  //  Did we finish with a gap started? If so, add it to the list.
  //
  if (currentGapStart != -1) {
    float gapLowerEdge = BinToLowerEta(currentGapStart);
    float gapUpperEdge = BinToUpperEta(_nBins - 1);
    _gaps.insert(GapCalculator::Gap(gapLowerEdge, lastFilledType, gapUpperEdge, EdgeGap));
  }

  _gapsAnalyzed = true;
  
  return _gaps.size();
}
  
