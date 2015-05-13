prun --exec "echo %IN > input.txt; ./SkimMain.exe Z "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147739.PowhegPythia8_AU2CT10_Zmumu_np.recon.NTUP_HI.e2213_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Zmumu_np.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDZmumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Zmumu_np.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe Z "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147807.PowhegPythia8_AU2CT10_Zmumu.recon.NTUP_HI.e2212_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Zmumu_pp.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDZmumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Zmumu_pp.A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe Z "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147807.PowhegPythia8_AU2CT10_Zmumu.recon.NTUP_HI.e2213_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Zmumu_pp.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDZmumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Zmumu_pp.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe Z "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147733.PowhegPythia8_AU2CT10_Zmumu_pn.recon.NTUP_HI.e2212_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Zmumu_pn.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDZmumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Zmumu_pn.A : $? " >>Log.txt
echo



