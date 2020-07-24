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
    combineCards.py ../output/datacard_tauPt_${iso}_WToTauNu_passingprobes${tauDecayMode}.txt ../output/datacard_tauPt_${iso}_WToTauNu_failingprobes${tauDecayMode}.txt > datacard_tauPt_${iso}_WToTauNu${tauDecayMode}.txt
    # Run combine
    ./Fitting_TriggerMeasurement.sh ${iso} $tauDecayMode | tee output_trigger_${iso}${tauDecayMode}.txt
done < iso.txt