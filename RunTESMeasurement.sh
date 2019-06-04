#!bin/bash

# set decay mode and era in settings.h 
# set decay mode in datacards/RunCombine_TES.sh
# set variable to tauMass in WToTauNuMeasurement.C and in datacards/RunCombine_TES.sh,

root -l -b -q ComputeFakeRate.C+
root -l -b -q CalculateEWKfraction.C+ 

# Run W -> mu nu measurement and create a root file including all relevant systematics
root -l -b -q WToMuNuMeasurement.C+
# Make W -> mu nu datacard
root -l -b -q DatacardProducer_WToMuNu.C+

for i in {90..95}  
do
    sed -i 's/bool doTauESmeasurement = false;/bool doTauESmeasurement = true;/g' settings.h
    sed -i "s/double tauMomScale = 1.00;/double tauMomScale = $i.\/100.;/g" settings.h

    root -l -b -q WToTauNuMeasurement.C+
    mv figures/tauMass_Loose_WToTauNu_3prong0pizeros_prefit.pdf figures/tauMass_Loose_WToTauNu_3prong0pizeros_prefit_TES${i}.pdf
    mv output/tauMass_Loose_WToTauNu_shapes_3prong0pizeros.root output/tauMass_Loose_WToTauNu_shapes_3prong0pizeros_TES${i}.root
    sed -i -e "s/_TES92/_TES$i/g" DatacardProducer_WToTauNu_TES.C 
   
    root -l -b -q DatacardProducer_WToTauNu_TES.C+
    mv output/datacard_tauMass_Loose_WToTauNu_3prong0pizeros.txt output/datacard_tauMass_Loose_WToTauNu_3prong0pizeros_TES${i}.txt

   
    cd /nfs/dust/cms/user/tlenz/13TeV/2017/CMSSW/CMSSW_8_1_0/src
    eval `scram runtime -sh`
    cd -
   
    cd datacards
    sed -i -e "s/_TES92/_TES$i/g" RunCombine_TES.sh
    source RunCombine_TES.sh
    cd ..
   
    sed -i "s/double tauMomScale = $i.\/100.;/double tauMomScale = 1.00;/g" settings.h
    sed -i -e "s/_TES$i/_TES92/g" DatacardProducer_WToTauNu_TES.C 
    sed -i -e "s/_TES$i/_TES92/g" datacards/RunCombine_TES.sh
done

