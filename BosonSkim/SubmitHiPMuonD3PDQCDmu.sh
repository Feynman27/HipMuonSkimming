prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147760.Pythia_AUET2BCTEQ6L1_jetjet_JZ0R04.recon.NTUP_HI.e2166_d814_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J0A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J0A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147761.Pythia_AUET2BCTEQ6L1_jetjet_JZ1R04.recon.NTUP_HI.e2166_d814_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J1A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J1A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147762.Pythia_AUET2BCTEQ6L1_jetjet_JZ2R04.recon.NTUP_HI.e2166_d814_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J2A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J2A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147763.Pythia_AUET2BCTEQ6L1_jetjet_JZ3R04.recon.NTUP_HI.e2166_d814_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J3A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J3A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147764.Pythia_AUET2BCTEQ6L1_jetjet_JZ4R04.recon.NTUP_HI.e2166_d814_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J4A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J4A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147760.Pythia_AUET2BCTEQ6L1_jetjet_JZ0R04.recon.NTUP_HI.e2167_d815_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J0B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J0B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147761.Pythia_AUET2BCTEQ6L1_jetjet_JZ1R04.recon.NTUP_HI.e2167_d815_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J1B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J1B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147762.Pythia_AUET2BCTEQ6L1_jetjet_JZ2R04.recon.NTUP_HI.e2167_d815_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J2B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J2B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147763.Pythia_AUET2BCTEQ6L1_jetjet_JZ3R04.recon.NTUP_HI.e2167_d815_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J3B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J3B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe QCD "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147764.Pythia_AUET2BCTEQ6L1_jetjet_JZ4R04.recon.NTUP_HI.e2167_d815_r5069/ \
    --outDS user.tbalestr.Pythia_AUET2BCTEQ6L1_jetjet.D3PD.2014.09.26.v01.J4B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDQCDmu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "J4B : $? " >>Log.txt
echo



