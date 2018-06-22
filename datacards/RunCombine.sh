#!/bin/bash
tauDecayMode=""
#tauDecayMode="_3prong0pizeros"
#tauDecayMode="_1prong0pizeros"
#tauDecayMode="_1prongUpTo4pizeros"

# Combine datacards
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_VTightMva2017v2_WToTauNu${tauDecayMode}.txt > datacard_VTightMva2017v2_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_TightMva2017v2_WToTauNu${tauDecayMode}.txt > datacard_TightMva2017v2_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_MediumMva2017v2_WToTauNu${tauDecayMode}.txt > datacard_MediumMva2017v2_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_LooseMva2017v2_WToTauNu${tauDecayMode}.txt > datacard_LooseMva2017v2_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_Tight_WToTauNu${tauDecayMode}.txt > datacard_Tight_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_Medium_WToTauNu${tauDecayMode}.txt > datacard_Medium_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_Loose_WToTauNu${tauDecayMode}.txt > datacard_Loose_Combined${tauDecayMode}.txt

# Run Combine
echo -e  "\n\n\n ----------------------------- VTightMva2017v2 ${tauDecayMode} \n"
./Fitting.sh VTightMva2017v2 $tauDecayMode | tee output_VTightMva2017v2${tauDecayMode}.txt
echo -e  "\n\n\n ----------------------------- TightMva ${tauDecayMode} \n"
./Fitting.sh TightMva2017v2 $tauDecayMode | tee output_TightMva2017v2${tauDecayMode}.txt
echo -e  "\n\n\n ----------------------------- MediumMva ${tauDecayMode} \n"
./Fitting.sh MediumMva2017v2 $tauDecayMode | tee output_MediumMva2017v2${tauDecayMode}.txt
echo -e  "\n\n\n ----------------------------- LooseMva ${tauDecayMode} \n"
./Fitting.sh LooseMva2017v2 $tauDecayMode | tee output_LooseMva2017v2${tauDecayMode}.txt
echo -e  "\n\n\n ----------------------------- Tight ${tauDecayMode} \n"
./Fitting.sh Tight $tauDecayMode | tee output_Tight${tauDecayMode}.txt
echo -e  "\n\n\n ----------------------------- Medium ${tauDecayMode} \n"
./Fitting.sh Medium $tauDecayMode | tee output_Medium${tauDecayMode}.txt
echo -e  "\n\n\n ----------------------------- Loose ${tauDecayMode} \n"
./Fitting.sh Loose $tauDecayMode | tee output_Loose${tauDecayMode}.txt

# Read results and output it on the screen
echo -e  "\n\n\n"
echo -e " ------------- RESULTS ${tauDecayMode} --------------------------------------------------------------------------------------"
printf "VTightMva2017v2 : " 
grep "tauId" output_VTightMva2017v2${tauDecayMode}.txt | tail -1
printf "TightMva2017v2  : " 
grep "tauId" output_TightMva2017v2${tauDecayMode}.txt | tail -1
printf "MediumMva2017v2 : " 
grep "tauId" output_MediumMva2017v2${tauDecayMode}.txt | tail -1
printf "LooseMva2017v2  : " 
grep "tauId" output_LooseMva2017v2${tauDecayMode}.txt | tail -1
printf "Tight     : " 
grep "tauId" output_Tight${tauDecayMode}.txt | tail -1
printf "Medium    : " 
grep "tauId" output_Medium${tauDecayMode}.txt | tail -1
printf "Loose     : " 
grep "tauId" output_Loose${tauDecayMode}.txt | tail -1
echo -e " --------------------- --------------------------------------------------------------------------------------"
echo -e  "\n\n\n"

