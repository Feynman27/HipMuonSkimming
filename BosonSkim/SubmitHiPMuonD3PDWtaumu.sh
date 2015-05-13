prun --exec "echo %IN > input.txt; ./SkimMain.exe TAU "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.209110.PowhegPythia8_AU2CT10_Wmintaunu_np_LeptonFilter.recon.NTUP_HI.e2583_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Wtauminmunu_np.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWtaumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wtauminmunu_np.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe TAU "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.209005.PowhegPythia8_AU2CT10_Wmintaunu_LeptonFilter.recon.NTUP_HI.e2582_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Wtauminmunu_pp.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWtaumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wtauminmunu_pp.A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe TAU "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.209005.PowhegPythia8_AU2CT10_Wmintaunu_LeptonFilter.recon.NTUP_HI.e2583_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Wtauminmunu_pp.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWtaumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wtauminmunu_pp.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe TAU "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.209107.PowhegPythia8_AU2CT10_Wmintaunu_pn_LeptonFilter.recon.NTUP_HI.e2582_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Wtauminmunu_pn.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWtaumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wtauminmunu_pn.A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe TAU "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.209109.PowhegPythia8_AU2CT10_Wplustaunu_np_LeptonFilter.recon.NTUP_HI.e2583_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Wtauplusmunu_np.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWtaumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wtauplusmunu_np.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe TAU "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.209004.PowhegPythia8_AU2CT10_Wplustaunu_LeptonFilter.recon.NTUP_HI.e2582_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Wtauplusmunu_pp.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWtaumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wtauplusmunu_pp.A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe TAU "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.209004.PowhegPythia8_AU2CT10_Wplustaunu_LeptonFilter.recon.NTUP_HI.e2583_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Wtauplusmunu_pp.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWtaumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wtauplusmunu_pp.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe TAU "  \
    --outputs skimmed.root \
    --athenaTag 19.2.0 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.209106.PowhegPythia8_AU2CT10_Wplustaunu_pn_LeptonFilter.recon.NTUP_HI.e2582_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.03.16.v02.Wtauplusmunu_pn.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWtaumu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wtauplusmunu_pn.A : $? " >>Log.txt
echo



