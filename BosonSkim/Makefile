#CC        = /afs/cern.ch/sw/lcg/external/gcc/4.3.2/x86_64/bin/g++
#CC        = /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Gcc/gcc472p1_x86_64_slc6/slc6/x86_64-slc6-gcc47-opt/bin/g++
CC        = g++
CCFLAGS   = -Wall -g  
INCS      = `root-config --cflags` -I.  
#LIBS      = `root-config --libs` -lTreePlayer -lCintex 
LIBS      = `root-config --libs` -lTreePlayer 

SkimMain.exe : SkimMain.cpp GoodLumiEvent.o HeavyIonD3PD.o EventAnalysis.o pPbMinBiasUtil.o MuonAnalysis.o TruthAnalysis.o Dict.o 
#SkimMain.exe : SkimMain.cpp GoodLumiEvent.o HeavyIonD3PD.o EventAnalysis.o TruthAnalysis.o MuonAnalysis.o Dict.o 
	$(CC) $(CCFLAGS) $< GoodLumiEvent.o HeavyIonD3PD.o EventAnalysis.o pPbMinBiasUtil.o MuonAnalysis.o TruthAnalysis.o Dict.o -o $@ $(INCS) $(LIBS)
	#$(CC) $(CCFLAGS) $< GoodLumiEvent.o HeavyIonD3PD.o EventAnalysis.o TruthAnalysis.o MuonAnalysis.o Dict.o -o $@ $(INCS) $(LIBS)

#MuonAnalysis.o : MuonAnalysis.cpp MuonAnalysis.h TruthAnalysis.o HeavyIonD3PD.o
#	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)
MuonAnalysis.o : MuonAnalysis.cpp MuonAnalysis.h HeavyIonD3PD.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

TruthAnalysis.o : TruthAnalysis.cpp TruthAnalysis.h HeavyIonD3PD.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

EventAnalysis.o : EventAnalysis.cpp EventAnalysis.h HeavyIonD3PD.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

#HeavyIonD3PD : Dict.o 
#	 $(CC) $(CCFLAGS) Dict.o -o $@ $(INCS) $(LIBS) 

HeavyIonD3PD.o : HeavyIonD3PD.cpp HeavyIonD3PD.h GoodLumiEvent.o pPbMinBiasUtil.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

Dict.o : Dict.cxx 
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS) 

Dict.cxx : HeavyIonD3PD.h EventAnalysis.h MuonAnalysis.h 
	rootcint -f $@ -c $<+

GoodLumiEvent.o : GoodLumiEvent.cpp GoodLumiEvent.h  
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

pPbMinBiasUtil.o : pPbCentrality/Root/pPbMinBiasUtil.cxx pPbCentrality/pPbCentrality/pPbMinBiasUtil.h
	 $(CC) $(CCFLAGS) -c pPbCentrality/Root/pPbMinBiasUtil.cxx pPbCentrality/pPbCentrality/pPbMinBiasUtil.h $(INCS) $(LIBS)

clean :
	rm -f Dict.o Dict.cxx Dict.h *.o SkimMain.exe skimmed.root 
