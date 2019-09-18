#!bin/bash

#define the taupt bins here:
tauptlow=("150" "200" "250")
taupthigh=("200" "250" "1000000")

CMSSW_Combine=/nfs/dust/cms/user/mameyer/SM_HiggsTauTau/CMSSW_8_1_0

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc530
cd $CMSSW_Combine/src
cmsenv
cd -

root -l -b -q ComputeFakeRate.C+
root -l -b -q CalculateEWKfraction.C+ 

root -l -b -q WToMuNuMeasurement.C+
root -l -b -q DatacardProducer_WToMuNu.C+

rm iso.txt
while read -r line
do
    [[ $line != iso.* ]] && continue
    [[ $line = //* ]] && continue
    [[ $line = /* ]] && continue
    echo $line | sed -E 's/.*\("(.*)"\).*/\1/' >> iso.txt
done < ../settings.h

for ((i=1;i<${#tauptlow[@]}+1;++i)); 
do
    echo "------------------------------------------------------------------------"
    printf "Processing tau Pt bin from  %s to %s\n" "${tauptlow[i]}" "${taupthigh[i]}"

    sed -i "s|double tau_pt_low = 100;|double tau_pt_low = ${tauptlow[i]};|g" settings.h
    sed -i "s|double tau_pt_high = 1000000;|double tau_pt_high = ${taupthigh[i]};|g" settings.h 

    root -l -b -q WToTauNuMeasurement.C+
    root -l -b -q DatacardProducer_WToTauNu.C+

    cd datacards
    source RunCombine.sh
    #source make_pulls_impacts_plots.sh
    python readTauIDs.py >results.txt
    cd ..

    root -l -b -q MakePostAndPreFitPlots.C+"(0,0)"
    root -l -b -q MakePostAndPreFitPlots.C+"(1,0)"
    root -l -b -q MakePostAndPreFitPlots.C+"(0,1)"
    root -l -b -q MakePostAndPreFitPlots.C+"(1,1)"


    #loop here over WPs
    while read -r iso
    do
        cd output
        mkdir TauPt_${tauptlow[i]}_${taupthigh[i]}
        mv mttau_${iso}_WToTauNu_shapes.root TauPt_${tauptlow[i]}_${taupthigh[i]}
        mv tauPt_${iso}.root TauPt_${tauptlow[i]}_${taupthigh[i]}
        mv  datacard_mttau_${iso}_WToTauNu.txt TauPt_${tauptlow[i]}_${taupthigh[i]}
        cd ..

        cd figures
        mkdir  TauPt_${tauptlow[i]}_${taupthigh[i]}
        mv mtmuon_${iso}_WToMuNu_prefit.png  TauPt_${tauptlow[i]}_${taupthigh[i]}
        mv mtmuon_${iso}_WToMuNu_postfit.png  TauPt_${tauptlow[i]}_${taupthigh[i]}
        mv mttau_${iso}_WToTauNu_prefit.png   TauPt_${tauptlow[i]}_${taupthigh[i]}
        mv mttau_${iso}_WToTauNu_postfit.png  TauPt_${tauptlow[i]}_${taupthigh[i]}
        cd ..

        cd datacards
        mkdir  TauPt_${tauptlow[i]}_${taupthigh[i]}
        mv impacts_${iso}.pdf  TauPt_${tauptlow[i]}_${taupthigh[i]}
        mv results.txt   TauPt_${tauptlow[i]}_${taupthigh[i]}
        cd ..
    done <iso.txt
    
    sed -i "s|double tau_pt_low = ${tauptlow[i]};|double tau_pt_low = 100;|g" settings.h
    sed -i "s|double tau_pt_high = ${taupthigh[i]};|double tau_pt_high = 1000000;|g" settings.h
done


