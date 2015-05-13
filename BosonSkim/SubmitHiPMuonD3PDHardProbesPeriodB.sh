prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218677.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site IN2P3-CC_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218677 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218677 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218679.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site BNL-OSG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218679 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218679 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218716.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site BNL-OSG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218716 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218716 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218751.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site RAL-LCG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218751 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218751 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218771.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site RAL-LCG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218771 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218771 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218783.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site WEIZMANN-LCG2_PHYS-HI \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218783 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218783 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218829.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site WEIZMANN-LCG2_PHYS-HI \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218829 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218829 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218898.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site BNL-OSG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218898 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218898 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218940.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site RAL-LCG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218940 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218940 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00218968.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site NIKHEF-ELPROD_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.218968 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "218968 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00219001.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site IN2P3-CC_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.219001 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "219001 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00219028.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site WEIZMANN-LCG2_PHYS-HI \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.219028 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "219028 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00219055.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site TAIWAN-LCG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.219055 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "219055 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00219089.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site FZK-LCG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.219089 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "219089 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00219111.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site BNL-OSG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.219111 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "219111 : $? " >>Log.txt
echo



prun --exec "echo %IN > input.txt; ./SkimMain.exe DATA "  \
    --outputs skimmed.root \
    --athenaTag 20.1.4 \
    --cmtConfig x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
     --inDS data13_hip.00219114.physics_HardProbes.merge.NTUP_HI.f516_m1312 \
     --site TAIWAN-LCG2_DATADISK \
    --outDS user.tbalestr.HiPMuonHardProbes.PeriodB.D3PD.2015.05.08.v02.219114 \
    --excludeFile skimmed.root,check.sh,*.o,*.h,*.C SubmitHiPMuonD3PDHardProbesPeriodB.sh \
    --extFile SkimMain.exe,input.txt,pPbMinBiasUtil_config_v1.root,Dict.cxx \
    --noBuild \
    --nGBPerJob 10 \
echo "219114 : $? " >>Log.txt
echo



