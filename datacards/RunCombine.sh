#!/bin/bash
tauDecayMode=""
#tauDecayMode="_3prong0pizeros"
#tauDecayMode="_1prong0pizeros"
#tauDecayMode="_1prongUpTo4pizeros"


# Get all uncommented iso working points
rm iso.txt
while read -r line
do
    [[ $line != iso.* ]] && continue
    [[ $line = //* ]] && continue
    [[ $line = /* ]] && continue
    echo $line | sed -E 's/.*\("(.*)"\).*/\1/' >> iso.txt
done < ../settings.h


while read -r iso
do
    echo -e  "\n\n\n ----------------------------- ${iso} ${tauDecayMode} \n"
    # Combine datacards
    combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_VTightMva2017v2_WToTauNu${tauDecayMode}.txt > datacard_${iso}_Combined${tauDecayMode}.txt
    # Run combine
    ./Fitting.sh ${iso} $tauDecayMode | tee output_${iso}${tauDecayMode}.txt
done < iso.txt


# Read results and output it on the screen
echo -e  "\n\n\n"
echo -e " ------------- RESULTS ${tauDecayMode} --------------------------------------------------------------------------------------"
while read -r iso
do
    printf "${iso} : "
    grep "tauId" output_${iso}${tauDecayMode}.txt | tail -1
done < iso.txt
echo -e " --------------------- --------------------------------------------------------------------------------------"
echo -e  "\n\n\n"

