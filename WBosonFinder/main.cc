#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

#include "TH1.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"

#include "WBosonFinder.h"
#include "TagAndProbe.h"
#include "WBosonTruth.h"
#include "ZBosonTruth.h"
#include "WTauTruth.h"
#include "QCDTruth.h"

int main(int argc, char* argv[]){

    bool submitToGrid= false;
    bool doTruth     = false;
    bool doTruthW    = false;
    bool doTruthZ    = false;
    bool doTruthWtau = false;
    bool doTruthQCD  = false;
    std::string beam = "";
    std::string period = "";
    bool doTP        = false;
    bool doInputFile = false;
    bool doRunLocal = true;
    const char* input      = NULL;
    const char* output     = NULL;

    std::cout << "Input parameters: 1) Input file name 2) Output file name 3) Beam Config(Period A/B) 4) Beam Type(pp,np,pn,data) 5) Tag and Probe Y/N " 
            << " 6) MC Type(W,Z,tau,QCD)" 
            << " 7) Submit to grid Y/N" << std::endl;

    if(argc<2){
        //std::cout << "Using input.txt as source of input file names. If you did not intend to do this, please give the filename to the command prompt as designated above" << std::endl;
        //doInputFile = false;
        exit(EXIT_SUCCESS);
    }
    else {
        doInputFile = true;
        input = argv[1];
    }
    //if(argv[2]==NULL) strcpy(output,"didNotNameOutput.root"); 
    std::cout << argc << " input parameters." << std::endl;
    if(argc<3) {
        output = "didNotNameOutput.root";
    }
    else output = argv[2];
    std::cout << "Output file name: " << output << std::endl; 
    
    if(argc>3){
        if(strcmp(argv[3],"A")==0)       {period=argv[3];}
        else if(strcmp(argv[3],"B")==0)  {period=argv[3];}
        else {
            std::cout << "WARNING: No beam configuration specified. Assuming merged periods. " << std::endl;
        }
    }
    if(argc>4){
        if(strcmp(argv[4],"np")==0)       {doTruth=true; beam=argv[4];}
        else if(strcmp(argv[4],"pn")==0)  {doTruth=true; beam=argv[4];}
        else if(strcmp(argv[4],"pp")==0)  {doTruth=true; beam=argv[4];}
        else if(strcmp(argv[4],"data")==0){doTruth=false;beam=argv[4];}
        else {
            std::cout << "Please select beam type or give no argument for input parameter 4). " << std::endl;
            exit(0);
        }
    }

    if(argc>5){
        if(strcmp(argv[5],"Y")==0 ) {
            std::cout << "Will perform T&P analysis." << std::endl;
            doTP = true;
        }
        else if(strcmp(argv[5],"N")==0 ){ doTP = false;}
        else{
            std::cout << "Please select TP or give no argument for input parameter 5). " << std::endl;
            exit(0);
        }
    }

    if(argc>6){
        if(strcmp(argv[6],"W")==0){
            doTruthW=true;
        }
        else if(strcmp(argv[6],"Z")==0){
            doTruthZ=true;
        }
        else if(strcmp(argv[6],"tau")==0){
            doTruthWtau=true;
        }
        else if(strcmp(argv[6],"QCD")==0){
            doTruthQCD=true;
        }
    }
    // Default when truth is ON
    else if(doTruth) {
        std::cout << "Running truth with default: W-->munu." << std::endl;
        doTruthW=true;
    }
    if(argc>7){
         if(strcmp(argv[7],"Y")==0){
             std::cout << "Running on the grid." << std::endl;
             submitToGrid=true;
         }
         else submitToGrid=false;
    }
    int truthIndicator=0;
    if(doTruthW) {std::cout << "Will create tree with W variables at truth level." << std::endl; ++truthIndicator;}
    if(doTruthZ) {std::cout << "Will create tree with Z variables at truth level." << std::endl;++truthIndicator;}
    if(doTruthWtau) {std::cout << "Will create tree with W-->tau variables at truth level." << std::endl;++truthIndicator;}
    if(doTruthQCD) {std::cout << "Will create tree with B/C/pi/K-->mu variables at truth level." << std::endl;++truthIndicator;}
    if(truthIndicator>1) {
        std::cout << "An error has occured. Unable to run >1 MC at a time. Please check your macro." << std::endl; 
        exit(0);
    }
    std::string argStr;
    std::ifstream ifs;

    // Open the input file given as an argument
    if(doInputFile) ifs.open(input);
    else ifs.open("input.txt");

    std::vector<std::string> fileList;
    // split by '/n'
    if(!submitToGrid&&!doRunLocal){
        while(true){
            std::string filen;
            std::getline(ifs,filen);
            if(ifs.eof()) break;
            fileList.push_back(filen);
            std::cout << "Adding file named: " << filen << std::endl;

        }
    }
    else if(doRunLocal) fileList.push_back(input);
    // split by ','
    else {
        std::getline(ifs,argStr);
        for(size_t i=0,n; i<=argStr.length(); i=n+1){

            n = argStr.find_first_of(',',i);
            if (n == std::string::npos) n = argStr.length();
            std::string tmp = argStr.substr(i,n-i);
            fileList.push_back(tmp);
        }//i
    }

    std::cout << "Number of files being processed: " << fileList.size() << std::endl;

    // Open input
    TChain* fChain = new TChain("MuonD3PD");
    std::vector<TH1*> vNEvtAll;
    std::vector<TH1*> vNEvtSel;

    for(unsigned int iFile=0; iFile<fileList.size(); ++iFile){


        TFile::Open(fileList[iFile].c_str());
        std::stringstream name;
        name << "hNEvtAll" << iFile;
        TH1F* hNEvtAll = (TH1F*)gDirectory->Get("hNEvtAll");
        hNEvtAll->SetName(name.str().c_str());
        vNEvtAll.push_back(hNEvtAll);
        name.str("");
        name << "hNEvtSel" << iFile;
        TH1F* hNEvtSel = (TH1F*)gDirectory->Get("hNEvtSel");
        hNEvtSel->SetName(name.str().c_str());
        vNEvtSel.push_back(hNEvtSel);
        //_file->Close();

        fChain->Add(fileList[iFile].c_str());

    }//iFile
    std::cout << "Events in chain: " << fChain->GetEntries() << std::endl;

    for(unsigned int i=0; i<vNEvtAll.size(); ++i){
        vNEvtAll[i]->Sumw2();
        vNEvtSel[i]->Sumw2();
        if(i!=0) {
            vNEvtAll[0]->Add(vNEvtAll[i]);
            vNEvtSel[0]->Add(vNEvtSel[i]);
        }

    }//i

    TFile* fout = NULL;
    fout = new TFile(output,"RECREATE");
    TTree* outTree   = new TTree("treeW","treeW");
    TTree* truthTree = new TTree("treeGen","treeGen");
    TTree* IDTree = new TTree("tIDprobes","tIDprobes");
    TTree* MSTree = new TTree("tMSprobes","tMSprobes");
    TTree* trigTree = new TTree("tTrigprobes","tTrigprobes");
    if(!doTP){
        delete IDTree;
        delete MSTree;
        delete trigTree;
    }
    if(!doTruth) delete truthTree;

    WBosonFinder* bosonHandle = new WBosonFinder(fChain, doTruth, period);
    bosonHandle->setOutputBranches(outTree);

/*    std::vector<double> ptBins, etaBins, centBins;
    ptBins.push_back(10.0);
    ptBins.push_back(15.0);
    ptBins.push_back(20.0);
    ptBins.push_back(30.0);
    ptBins.push_back(40.0);
    ptBins.push_back(60.0);
    ptBins.push_back(100.0);
    ptBins.push_back(200.);
    const int nPtBins = ptBins.size()-1;

    etaBins.push_back(-2.5);
    etaBins.push_back(-2.1);
    etaBins.push_back(-1.55);
    etaBins.push_back(-1.05);
    etaBins.push_back(-0.6);
    etaBins.push_back(-0.1);
    etaBins.push_back(0.1);
    etaBins.push_back(0.6);
    etaBins.push_back(1.05);
    etaBins.push_back(1.55);
    etaBins.push_back(2.1);
    etaBins.push_back(2.5);
    const int nEtaBins = etaBins.size()-1;
    centBins.push_back(0.0);
    centBins.push_back(0.9);
    int nCentBins = centBins.size()-1;
*/
    TagAndProbe* tpHandle = NULL;
    if(doTP){
        tpHandle = new TagAndProbe(period,doTruth);
        tpHandle->setOutputTriggerBranches(trigTree);
        tpHandle->setOutputIDProbeBranches(IDTree);
        tpHandle->setOutputMSProbeBranches(MSTree);
    }
    WBosonTruth* truthHandleW = NULL;
    ZBosonTruth* truthHandleZ = NULL;
    WTauTruth*   truthHandleWtau = NULL;
    QCDTruth*    truthHandleQCD = NULL;
    if(doTruth) { 
        // Save tree every 5 GB
        truthTree->SetAutoSave(5000000000);
        if(doTruthW){
            truthHandleW = new WBosonTruth(period);
            truthHandleW->setOutputBranches(truthTree);
        }
        else if(doTruthZ){
            truthHandleZ = new ZBosonTruth(period);
            truthHandleZ->setOutputBranches(truthTree);
        }
        else if(doTruthWtau){
            truthHandleWtau = new WTauTruth(period);
            truthHandleWtau->setOutputBranches(truthTree);
        }
        else if(doTruthQCD){
            truthHandleQCD = new QCDTruth(period);
            truthHandleQCD->setOutputBranches(truthTree);
        }
    }

    // Event loop
    for(int iev=0; iev<fChain->GetEntries(); ++iev){
        Long64_t entry = bosonHandle->LoadTree(iev);
        if(entry<0) break;
        if(iev%1000==0) {
            std::cout << " Event no: " << iev << std::endl;
        }

        // Loop over generated muons
        if(doTruth) {
            if(doTruthW) { 
                bosonHandle->LoopMuons(entry,outTree,"W");
                truthHandleW->LoopTruth(entry,bosonHandle,truthTree);
            }
            else if(doTruthZ) {
                bosonHandle->LoopMuons(entry,outTree,"Z");
                truthHandleZ->LoopTruth(entry,bosonHandle,truthTree);
            }
            else if(doTruthWtau) {
                bosonHandle->LoopMuons(entry,outTree,"tau");
                truthHandleWtau->LoopTruth(entry,bosonHandle,truthTree);
            }
            else if(doTruthQCD) {
                bosonHandle->LoopMuons(entry,outTree,"QCD");
                truthHandleQCD->LoopTruth(entry,bosonHandle,truthTree);
            }
            
        }
        else bosonHandle->LoopMuons(entry,outTree);

        if(doTP) {
            bool flag=tpHandle->LoopProbes(entry,bosonHandle,true,true,IDTree,MSTree,trigTree);
            if(flag==false) exit(0);
        }

    }//iev


    //tpHandle->BinHistos(PtBins,EtaBins);
    fout->cd();
    std::cout << "Writing." << std::endl;
    outTree->Write();
    if(doTP){
        IDTree->Write();
        MSTree->Write();
        trigTree->Write();
    }
    if(doTruth) {
        truthTree->Write(); 
        bosonHandle->getTotalHisto()->Write();
        bosonHandle->getPassedHisto()->Write();
    }
    vNEvtAll[0]->Write();
    vNEvtSel[0]->Write();
    std::cout << "Closing." << std::endl;
    //delete bosonHandle;
    //delete tpHandle;
    fout->Close();

    return 0;

}
