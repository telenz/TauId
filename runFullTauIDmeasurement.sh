#!bin/sh

# Please initialize CMSSW before
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
# Make trigger efficiency curve for met trigger (afterwards you need to redo most of the ntuples)
# root -l -b -q TriggerEfficiency.C+ # commented out since this is only executed once

# Compute fake rates in W+jets and dijets events and combine them 
while read -r line
do
    [[ $line != \#define\ ERA_* ]] && continue
    echo $line | sed -E 's/#define ERA_//g' >> era.txt
done < settings.h

while read -r era
do
  root -l -b -q ComputeFakeRate.C+
  root -l -b -q CalculateEWKfraction.C+   # This script calculates the EWK fraction and combines the SingleMu and JetHT fake rates

# Run W -> tau nu measurement and create a root file including all relevant systematics
  root -l -b -q WToTauNuMeasurement.C+
# Make W -> tau nu datacard
  root -l -b -q DatacardProducer_WToTauNu.C+

# Run W -> mu nu measurement and create a root file including all relevant systematics
  root -l -b -q WToMuNuMeasurement.C+
# Make W -> mu nu datacard
  root -l -b -q DatacardProducer_WToMuNu.C+

  # Make datacards and run Combine
  #iniCMSSW_8_1_0   # needed for Combine (definition see below)
  
  cd /nfs/dust/cms/user/mameyer/SM_HiggsTauTau/CMSSW_8_1_0/src 
  cmsenv
  cd -
  cd datacards/${era}
  sh ../RunCombine.sh
  sh ../make_pulls_impacts_plots.sh
  cd ../../

  # Make postfit plots 
  root -l -b -q MakePostAndPreFitPlots.C+"(0,0)"
  root -l -b -q MakePostAndPreFitPlots.C+"(1,0)"
  root -l -b -q MakePostAndPreFitPlots.C+"(0,1)"
  root -l -b -q MakePostAndPreFitPlots.C+"(1,1)"

done < era.txt

rm era.txt
# For the measurement the fake rates saved in output/FakeRates_FinerBinning/ are used. This can be seen in WToTauNuMeasurement.C
# If you want to change this, please change the filename in loadFakeRates();

# In case you want to do a measurement separately in the tau decay modes, you need to specify the tau decay mode in setting.h (variable tauDecayMode) and in RunCombine.sh
# Afterwards run all relevant steps again.

# If you want to do a closure test for different fake rates, please run makeClosure.sh
# If you have already the fake rate file and only want to change the tested variable please run only "root -l -b -q ClosureTest_FakeRate.C".

# To get the final results for r and the correlation between r and tauId do
# root -l mlfit_Combined_TightMva.root
# fit_s->Print()
# fit_s->correlation("r","tauId")

# iniCMSSW_8_1_0 needed for Combine and defined as
# iniCMSSW_8_1_0() {
#    cd /nfs/dust/cms/user/tlenz/13TeV/2017/CMSSW/CMSSW_8_1_0/src
#    ini6
#    eval `scram runtime -sh`
#    cd -
# }