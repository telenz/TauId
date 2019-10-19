#!bin/sh

#--------------------------------------------------------------------------------------------------------------------
#define the taupt bins here:
tauptlow=("100" "150" "200")
taupthigh=("150" "200" "1000000")

# define which working point should be used for determination of mean pT
isoWPMeanPt=MediumDeepTau2017v2p1

# set the CMSSW versionf or combine
CMSSW_Combine=/nfs/dust/cms/user/mameyer/SM_HiggsTauTau/CMSSW_8_1_0

#--------------------------------------------------------------------------------------------------------------------

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
done < settings.h

for ((i=0;i<${#tauptlow[@]};++i));
do
    echo "------------------------------------------------------------------------"
    printf "Processing tau Pt bin from  %s to %s\n" "${tauptlow[i]}" "${taupthigh[i]}"

    sed -i "s|double tau_pt_low =.*|double tau_pt_low = ${tauptlow[i]};|g" settings.h
    sed -i "s|double tau_pt_high =.*|double tau_pt_high = ${taupthigh[i]};|g" settings.h

    root -l -b -q WToTauNuMeasurement.C+
    root -l -b -q DatacardProducer_WToTauNu.C+

    cd datacards
    sh RunCombine.sh
   #sh make_pulls_impacts_plots.sh
    python readTauIDs.py >results.txt
    cd ..

    root -l -b -q MakePostAndPreFitPlots.C+"(0,0)"
    root -l -b -q MakePostAndPreFitPlots.C+"(1,0)"
    root -l -b -q MakePostAndPreFitPlots.C+"(0,1)"
    root -l -b -q MakePostAndPreFitPlots.C+"(1,1)"

    rm -r output/TauPt_${tauptlow[i]}_${taupthigh[i]}
    rm -r figures/TauPt_${tauptlow[i]}_${taupthigh[i]}
    rm -r datacards/TauPt_${tauptlow[i]}_${taupthigh[i]}
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
       cd ..
   done <iso.txt

   cd datacards
   mv results.txt   TauPt_${tauptlow[i]}_${taupthigh[i]}
   cd ..

   sed -i "s|double tau_pt_low = ${tauptlow[i]};|double tau_pt_low = 100;|g" settings.h
   sed -i "s|double tau_pt_high = ${taupthigh[i]};|double tau_pt_high = 1000000;|g" settings.h
done


#determine mean pT
for ((i=0;i<${#tauptlow[@]};++i));
do
cd output/TauPt_${tauptlow[i]}_${taupthigh[i]}
root -b -l tauPt_${isoWPMeanPt}.root <<EOF > mean_${tauptlow[i]}_${taupthigh[i]}.txt
std::cout<<"  "<<data_obs->GetMean(1)<<std::endl;
EOF
cd -
done

#put results into a table
rm TauPtDependentSFs.txt
echo -n '\begin{tabular}{|l|'>>TauPtDependentSFs.txt
for ((i=0;i<${#tauptlow[@]};++i));
do
    echo -n 'c|' >>TauPtDependentSFs.txt
done
echo '}' >>TauPtDependentSFs.txt  
echo "\hline" >>TauPtDependentSFs.txt
echo -n "Discriminant                                " >>TauPtDependentSFs.txt      
for ((i=0;i<${#tauptlow[@]};++i));
do
  echo -n "& \$${tauptlow[i]}<p_{T}^{\\tau}<${taupthigh[i]}\$" >>TauPtDependentSFs.txt
done
echo "\\\\">>TauPtDependentSFs.txt
echo -n "$\langle p_{T}\\rangle\\left[\\textrm{GeV}\\right]\$ " >>TauPtDependentSFs.txt
for ((i=0;i<${#tauptlow[@]};++i));
do
    echo -n "&" >>TauPtDependentSFs.txt
    echo -n "$(<output/TauPt_${tauptlow[i]}_${taupthigh[i]}/mean_${tauptlow[i]}_${taupthigh[i]}.txt)" | grep "  " | tr "\n" "\t" >>TauPtDependentSFs.txt
done
echo "\\\\" >>TauPtDependentSFs.txt
echo "\hline" >>TauPtDependentSFs.txt

while read -r iso
do
    echo -n "${iso}                " >>TauPtDependentSFs.txt
    for ((i=0;i<${#tauptlow[@]};++i));
    do
        echo -n "&" >>TauPtDependentSFs.txt
        fgrep -w ${iso}  datacards/TauPt_${tauptlow[i]}_${taupthigh[i]}/results.txt | sed "s/${iso} : //g" | tr '\n' ' ' >>TauPtDependentSFs.txt
    done
    echo "\\\\" >>TauPtDependentSFs.txt
done <iso.txt
echo '\hline' >>TauPtDependentSFs.txt
echo '\end{tabular}' >>TauPtDependentSFs.txt
