# TauId

##########################################################
##########################################################

### Measurement of the Tau ID (MC to Data) scale factors. 

##########################################################
##########################################################

###########################################
## Instruction to run the Tau ID analysis

You can run runFullTauIDmeasurement.sh

This file includes the execution of a collection of RooT macros used to perform measurements of the tauId efficiency with W*->tau+v events.

PlotTrigger.C - Macro to compute trigger turn on curves for MET trigger. 
                The macro produces as an output RooT file output/trigger_eff.root with functions describing efficiency of the MET trigger in dependence of offline MET and MHT variable. 
                The newly created file should be placed in the directory $CMSSW_BASE/src/src/DesyTauAnalyses/NTupleMaker/data and specified in the configuration file. 
                The MET sample should be redone with this trigger efficiency file where then the calculated trigger weight is added to the overall weight.

ComputeFakeRate.C - Computes fake factor as a function of tau jet Pt (pt of the corresponding jet) and tau Pt/ tau jet Pt. 
                    The fake factor is determined in data for the analysis. 
                    The script calculates also fake factors on MC to make a closure test.
                    The macro produces as an output the RooT file output/${dataset}_fakeRate.root where ${dataset} is either SingleMuon_Run2016 or JetHT_Run2016, or MC sample names.

CalculateEWKfraction.C - Calculates the EWK fraction (n_EWK^MC/n_Data in the anti-isolated signal region) and combines the SingleMu and JetHT fake rates
                         Output: Root file output/fakerates.root

WToTauNuMeasurement.C - Creates root file with final histogram and all relevant systematic uncertainties.
                        Is used as input for Combine.

DatacardProducer_WToTauNu.C - Creates datacard for Combine

WToMuNuMeasurement.C - Creates root file with final histogram for W*->mu nu analysis and all relevant systematic uncertainties.
                       Is used as input for Combine.

DatacardProducer_WToMuNu.C - Creates root file with final histogram and all relevant systematic uncertainties.
                        Is used as input for Combine.


MakePostFitPlots.C - Makes post fit plots.

###########################################
## Instructions to make NTuples

All ntuples are located in
/nfs/dust/cms/user/mameyer/TauIdAndES_2017Data/TauId/NTuples

### Instructions for running NTuple producer AnalysisNTupleProducer_TauID.cpp macro.

The macro AnalysisNTupleProducer_TauID.cpp is located in DesyTauAnalysesRun2/NTupleMaker/bin executed with two arguments: the configuration file and the filelist.
An instruction to setup a CMSSW area including the DesyTauAnalysesRun2 package can be found [here](https://twiki.cern.ch/twiki/bin/viewauth/CMS/DesyTauAnalysesRun2#Instructions_to_synchronize_your)

Examples of configuration files are

- NTuples/analysisNTupleProducer_tauid_Data.conf (to run on data)

- NTuples/analysisNTupleProducer_tauid_MC_DY2Jets.conf (to run on MC)


Example of filelist :

- NTuples/


Examples of running the macro

> AnalysisNTupleProducer_TauID [analysisNTupleProducer_tauid_Data.conf](NTuples/analysisNTupleProducer_tauid_Data.conf) MET_Run2016G

> AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_DY2Jets.conf WToMuNu_M-200_13TeV-pythia8

Useful scripts :

qsub.sh - submits job to batch system. This script
requires three arguments :

1) code name

2) config file

3) filelist

Example :

> qsub.sh AnalysisNTupleProducer_TauID [analysisNTupleProducer_tauid_Data.conf](NTuples/analysisNTupleProducer_tauid_Data.conf) MET_Run2016G


qsub_seq.sh - submits several jobs per filelist. The script requires
four arguments :

1) code name

2) config file

3) filelist

4) files per job

The script creates a directory named $filelist_files.
The directory will contain all RooT and output files
created by separate jobs. Once all jobs are finished,
all RooT files can be merged by executing script hadd.sh

> hadd.sh $filelist.
 
###########################################
## Instruction to run fits

The directory datacards contains all datacards for
statistical inference and results of the fits.

The datacards from two regions - signal (W*->tau+v) 
and control region (W*->mu+v) are combined using script
CombineCards.sh. This will produce datacards for various
tau ID working points

tauId_LooseMvaIso.txt

tauId_MediumMvaIso.txt

tauId_TightMvaIso.txt

tauId_LooseIso.txt

tauId_MediumIso.txt

tauId_TightIso.txt


To run computation of the tauId, one needs to execute script 

Fitting.csh

and pass as an argument tau isolation working point
(LooseMvaIso, MediumMvaIso, TightMvaIso, LooseIso, MediumIso or TightIso)

Example :

./Fitting.sh MediumIso

This will create mlfit_tauId_MediumIso.root. This file
is then used to plot posfit distributions of fitted variables
(mT(mu,MET) in the W*->mu+v control region and mT(tau,MET) 
in the W*->tau+v signal region).
