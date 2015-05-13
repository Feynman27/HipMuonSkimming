#ifndef TRUTHANALYSIS_H_
#define TRUTHANALYSIS_H_

#include <iostream>
#include "HeavyIonD3PD.h"
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>

class TruthAnalysis{
 public:
    TruthAnalysis();
    virtual ~TruthAnalysis();
    virtual void LoopEvent(HeavyIonD3PD* HID3PD,int entry, int thisMother=-1, int thisChild1=-1, int thisChild2=-1);
    void LoopEventQCD(HeavyIonD3PD* HID3PD, int entry, int thisChild1=-1); 
    virtual void SetOutputBranches(TTree* outputTree);
    virtual void ActivateTruthBranches(HeavyIonD3PD* HID3PD, int entry);
    int GetNumTruthMuon() const { return m_nSignalMuons; }
    bool isBottomMeson(int mother);
    bool isCharmedMeson(int mother);
    bool isBBBAR(int mother);
    bool isCCBAR(int mother);
    bool isBottomBaryon(int mother);
    bool isCharmedBaryon(int mother);
    bool isPion(int mother);
    bool isKaon(int mother);
 private:
     int m_nSignalMuons;
     std::map<std::string, std::vector<float>* > m_fBranches;
     std::map<std::string, std::vector<int>* > m_iBranches;
     void ClearVectors(); 

};
#endif
