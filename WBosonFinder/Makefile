#CC        = /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Gcc/gcc472p1_x86_64_slc6/slc6/x86_64-slc6-gcc47-opt/bin/g++
CC        = g++
CCFLAGS   = -Wall -g  
INCS      = `root-config --cflags` -I.  
LIBS      = `root-config --libs` -lTreePlayer -lCintex 

main.exe : main.cc BranchBase.o WBosonFinder.o TagAndProbe.o WBosonTruth.o ZBosonTruth.o WTauTruth.o QCDTruth.o
	$(CC) $(CCFLAGS) $< BranchBase.o WBosonFinder.o TagAndProbe.o WBosonTruth.o ZBosonTruth.o WTauTruth.o QCDTruth.o -o $@ $(INCS) $(LIBS)

WBosonFinder.o : WBosonFinder.cc WBosonFinder.h BranchBase.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

TagAndProbe.o : TagAndProbe.cc TagAndProbe.h BranchBase.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

WBosonTruth.o : WBosonTruth.cc WBosonTruth.h BranchBase.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

ZBosonTruth.o : ZBosonTruth.cc ZBosonTruth.h BranchBase.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

WTauTruth.o : WTauTruth.cc WTauTruth.h BranchBase.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

QCDTruth.o : QCDTruth.cc QCDTruth.h BranchBase.o
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

BranchBase.o : BranchBase.cc BranchBase.h 
	$(CC) $(CCFLAGS) -c $< $(INCS) $(LIBS)

clean :
	rm -f Dict.o Dict.cxx Dict.h *.o main.exe WBosonMuon.root 
