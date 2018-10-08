#!/bin/bash


cp analysisNTupleProducer_tauid_MC.conf analysisNTupleProducer_tauid_MC_backup.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_DY1Jets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_DY2Jets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_DY3Jets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_DY4Jets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_DYJets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ST_t-ch_antitop.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ST_t-ch_top.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ST_tW_antitop.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ST_tW_top.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_TTbarHad.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_TTbarLep.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_TTbarSemiLep.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W1JetsToLNu_LHEWpT_100-150/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W1JetspT100-150.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W1JetsToLNu_LHEWpT_150-250/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W1JetspT150-250.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W1JetsToLNu_LHEWpT_250-400/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W1JetspT250-400.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W1JetsToLNu_LHEWpT_400-inf/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W1JetspT400-inf.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W2JetsToLNu_LHEWpT_100-150/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W2JetspT100-150.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W2JetsToLNu_LHEWpT_150-250/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W2JetspT150-250.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W2JetsToLNu_LHEWpT_250-400/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W2JetspT250-400.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W2JetsToLNu_LHEWpT_400-inf/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W2JetspT400-inf.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W1Jets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W2Jets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W3Jets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_W4Jets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_WJets.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = WToMuNu_M-200_TuneCP5_13TeV-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_WStarMuNu.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_WStarTauNu.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ZJetsToNuNu_HT-100To200_13TeV-madgraph/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ZToNuNuHT-100To200.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ZJetsToNuNu_HT-200To400_13TeV-madgraph/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ZToNuNuHT-200To400.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ZJetsToNuNu_HT-400To600_13TeV-madgraph/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ZToNuNuHT-400To600.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ZJetsToNuNu_HT-600To800_13TeV-madgraph/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ZToNuNuHT-600To800.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ZJetsToNuNu_HT-800To1200_13TeV-madgraph/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ZToNuNuHT-800To1200.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ZToNuNuHT-1200To2500.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ZToNuNuHT-2500ToInf.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = WW_TuneCP5_13TeV-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_WW.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = WZ_TuneCP5_13TeV-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_WZ.conf

sed 's/SampleNameForPUHist =/SampleNameForPUHist = ZZ_TuneCP5_13TeV-pythia8/' analysisNTupleProducer_tauid_MC.conf > analysisNTupleProducer_tauid_MC_ZZ.conf

# systematic uncertainties

# WStarMuNu

sed 's/JetES = 0/JetES = -1/' analysisNTupleProducer_tauid_MC_WStarMuNu.conf > analysisNTupleProducer_tauid_MC_jesDown_WStarMuNu.conf

sed 's/JetES = 0/JetES = 1/' analysisNTupleProducer_tauid_MC_WStarMuNu.conf > analysisNTupleProducer_tauid_MC_jesUp_WStarMuNu.conf

sed 's/UnclusteredES = 0/UnclusteredES = -1/' analysisNTupleProducer_tauid_MC_WStarMuNu.conf > analysisNTupleProducer_tauid_MC_uesDown_WStarMuNu.conf

sed 's/UnclusteredES = 0/UnclusteredES = 1/' analysisNTupleProducer_tauid_MC_WStarMuNu.conf > analysisNTupleProducer_tauid_MC_uesUp_WStarMuNu.conf

sed 's/MuonMomScale = 1./MuonMomScale = 0.98/' analysisNTupleProducer_tauid_MC_WStarMuNu.conf > analysisNTupleProducer_tauid_MC_muDown_WStarMuNu.conf

sed 's/MuonMomScale = 1./MuonMomScale = 1.02/' analysisNTupleProducer_tauid_MC_WStarMuNu.conf > analysisNTupleProducer_tauid_MC_muUp_WStarMuNu.conf

# WStarTauNu

sed 's/JetES = 0/JetES = -1/' analysisNTupleProducer_tauid_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_jesDown_MC_WStarTauNu.conf

sed 's/JetES = 0/JetES = 1/' analysisNTupleProducer_tauid_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_jesUp_MC_WStarTauNu.conf

sed 's/UnclusteredES = 0/UnclusteredES = -1/' analysisNTupleProducer_tauid_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_uesDown_MC_WStarTauNu.conf

sed 's/UnclusteredES = 0/UnclusteredES = 1/' analysisNTupleProducer_tauid_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_uesUp_MC_WStarTauNu.conf

sed 's/TauMomScale = 1./TauMomScale = 0.98/' analysisNTupleProducer_tauid_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_tauesDown_MC_WStarTauNu.conf

sed 's/TauMomScale = 1./TauMomScale = 1.02/' analysisNTupleProducer_tauid_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_tauesUp_MC_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 1prong0pizeros/' analysisNTupleProducer_tauid_tauesDown_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_taues_1prong0pizerosDown_MC_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 1prongUpTo4pizeros/' analysisNTupleProducer_tauid_tauesDown_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_taues_1prongUpTo4pizerosDown_MC_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 3prong0pizeros/' analysisNTupleProducer_tauid_tauesDown_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_taues_3prong0pizerosDown_MC_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 1prong0pizeros/' analysisNTupleProducer_tauid_tauesUp_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_taues_1prong0pizerosUp_MC_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 1prongUpTo4pizeros/' analysisNTupleProducer_tauid_tauesUp_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_taues_1prongUpTo4pizerosUp_MC_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 3prong0pizeros/' analysisNTupleProducer_tauid_tauesUp_MC_WStarTauNu.conf > analysisNTupleProducer_tauid_taues_3prong0pizerosUp_MC_WStarTauNu.conf



for file in $(ls *.conf)
do
    echo "**********************************"
    echo $file
    echo "**********************************"

    diff analysisNTupleProducer_tauid_MC_backup.conf $file
done