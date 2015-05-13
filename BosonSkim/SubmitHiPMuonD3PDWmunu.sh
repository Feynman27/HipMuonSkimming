prun --exec "echo %IN > input.txt; ./SkimMain.exe W "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147737.PowhegPythia8_AU2CT10_Wminmunu_np.recon.NTUP_HI.e2583_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.04.27.v01.Wminmunu_np.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWmunu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wminmunu_np.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe W "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147804.PowhegPythia8_AU2CT10_Wminmunu.recon.NTUP_HI.e2582_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.04.27.v01.Wminmunu_pp.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWmunu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wminmunu_pp.A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe W "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147804.PowhegPythia8_AU2CT10_Wminmunu.recon.NTUP_HI.e2583_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.04.27.v01.Wminmunu_pp.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWmunu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wminmunu_pp.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe W "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147731.PowhegPythia8_AU2CT10_Wminmunu_pn.recon.NTUP_HI.e2582_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.04.27.v01.Wminmunu_pn.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWmunu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wminmunu_pn.A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe W "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147735.PowhegPythia8_AU2CT10_Wplusmunu_np.recon.NTUP_HI.e2583_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.04.27.v01.Wplusmunu_np.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWmunu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wplusmunu_np.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe W "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147801.PowhegPythia8_AU2CT10_Wplusmunu.recon.NTUP_HI.e2582_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.04.27.v01.Wplusmunu_pp.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWmunu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wplusmunu_pp.A : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe W "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147801.PowhegPythia8_AU2CT10_Wplusmunu.recon.NTUP_HI.e2583_d815_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.04.27.v01.Wplusmunu_pp.B \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWmunu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wplusmunu_pp.B : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe W "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --match '*NTUP*' \
    --inDS mc12_5TeV.147729.PowhegPythia8_AU2CT10_Wplusmunu_pn.recon.NTUP_HI.e2582_d814_r5069/ \
    --outDS user.tbalestr.PowhegPythia8_AU2CT10.D3PD.2015.04.27.v01.Wplusmunu_pn.A \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDWmunu.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "Wplusmunu_pn.A : $? " >>Log.txt
echo



