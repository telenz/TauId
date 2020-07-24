#!bin/sh

# Please initialize CMSSW before

# set doTauTriggerEffmeasurement = true in settings.h
sed -i 's|bool doTauTriggerEffmeasurement = false;|bool doTauTriggerEffmeasurement = true;|g' settings.h

# Make trigger efficiency curve for met trigger (afterwards you need to redo most of the ntuples)
# root -l -b -q TriggerEfficiency.C+ # commented out since this is only executed once

# Compute fake rates in W+jets and dijets events and combine them 
root -l -b -q ComputeFakeRate.C+
root -l -b -q CalculateEWKfraction.C+   # This script calculates the EWK fraction and combines the SingleMu and JetHT fake rates

# Run W -> tau nu measurement and create a root file for the tauPt distribution including all relevant systematics for events passing the single tau trigger
root -l -b -q WToTauNuMeasurement.C+"(\"tautrigger\")"

# Run W -> tau nu measurement and create a root file for the tauPt distribution including all relevant systematics for events failing the single tau trigger
root -l -b -q WToTauNuMeasurement.C+"(\"NOTtautrigger\")"

# Run W -> tau nu measurement and create a root file for the tauPt distribution including all relevant systematics, inclusively in single tau trigger
root -l -b -q WToTauNuMeasurement.C+"(\"inclusive\")"

# Make W -> tau nu datacard for events passing the single tau trigger
root -l -b -q DatacardProducer_WToTauNu.C+"(\"tautrigger\")"

# Make W -> tau nu datacard for events failing the single tau trigger
root -l -b -q DatacardProducer_WToTauNu.C+"(\"NOTtautrigger\")"

# initialize CMSSW version needed for Combine
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
cd /nfs/dust/cms/user/mameyer/SM_HiggsTauTau/CMSSW_8_1_0/src 
cmsenv
cd -

# run combine
cd datacards
sh RunCombine_TriggerMeasurement.sh
cd ..

# Make prefit plots (using fitDiagnostics.root) for passing and failing probes
root -l -b -q MakePostAndPreFitPlots.C+"(0,0,1)"
root -l -b -q MakePostAndPreFitPlots.C+"(0,1,1)"

# Make postfit plots for passing and failing probes
root -l -b -q MakePostAndPreFitPlots.C+"(1,0,1)"
root -l -b -q MakePostAndPreFitPlots.C+"(1,1,1)"

# Determine and plot the trigger efficiency and its SF
root -l -q -b DetermineTriggerEff.C+

