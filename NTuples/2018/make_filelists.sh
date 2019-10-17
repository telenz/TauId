#!bin/sh

dirDataSingleMuon=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2018/data//SingleMuon/
dirMETData=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2018/data/MET/
dirDataJetHT=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2018/data//JetHT/
dirMC=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2018/mc/

ls $dirDataSingleMuon/SingleMuon_Run2018A-17Sep2018-v2/*root > SingleMuon_Run2018A
ls $dirDataSingleMuon/SingleMuon_Run2018B-17Sep2018-v1/*root > SingleMuon_Run2018B
ls $dirDataSingleMuon/SingleMuon_Run2018C-17Sep2018-v1/*root > SingleMuon_Run2018C
ls $dirDataSingleMuon/SingleMuon_Run2018D-22Jan2019-v2/*root > SingleMuon_Run2018D

ls $dirDataJetHT/JetHT_Run2018A-17Sep2018-v1/*root > JetHT_Run2018A
ls $dirDataJetHT/JetHT_Run2018B-17Sep2018-v1/*root > JetHT_Run2018B
ls $dirDataJetHT/JetHT_Run2018C-17Sep2018-v1/*root > JetHT_Run2018C
ls $dirDataJetHT/JetHT_Run2018D-PromptReco-v2/*root > JetHT_Run2018D

ls $dirMETData/MET_Run2018A-17Sep2018-v1/*root > MET_Run2018A
ls $dirMETData/MET_Run2018B-17Sep2018-v1/*root > MET_Run2018B
ls $dirMETData/MET_Run2018C-17Sep2018-v1/*root > MET_Run2018C
ls $dirMETData/MET_Run2018D-PromptReco-v2/*root > MET_Run2018D

ls $dirMC/DYJetsToLL_M-50/*root > DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/DY1JetsToLL_M-50/*root > DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/DY2JetsToLL_M-50/*root > DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/DY3JetsToLL_M-50/*root > DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/DY4JetsToLL_M-50/*root > DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8

ls $dirMC/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8/*root > TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8
ls $dirMC/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/*root > TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8
ls $dirMC/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/*root > TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8

ls $dirMC/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/*root > W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/*root > W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/*root > W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/*root > W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8

ls $dirMC/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirMC/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8

ls $dirMC/WToMuNu_M-200_TuneCP5_13TeV-pythia8/*root > WToMuNu_M-200_TuneCP5_13TeV-pythia8
ls $dirMC/WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola/*root > WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola

ls $dirMC/ZToNuNu/ZJetsToNuNu_HT-100To200_13TeV-madgraph/*root > ZJetsToNuNu_HT-100To200_13TeV-madgraph
ls $dirMC/ZToNuNu/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/*root > ZJetsToNuNu_HT-1200To2500_13TeV-madgraph
ls $dirMC/ZToNuNu/ZJetsToNuNu_HT-200To400_13TeV-madgraph/*root > ZJetsToNuNu_HT-200To400_13TeV-madgraph
ls $dirMC/ZToNuNu/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/*root > ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph
ls $dirMC/ZToNuNu/ZJetsToNuNu_HT-400To600_13TeV-madgraph/*root > ZJetsToNuNu_HT-400To600_13TeV-madgraph
ls $dirMC/ZToNuNu/ZJetsToNuNu_HT-600To800_13TeV-madgraph/*root > ZJetsToNuNu_HT-600To800_13TeV-madgraph
ls $dirMC/ZToNuNu/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/*root > ZJetsToNuNu_HT-800To1200_13TeV-madgraph

ls $dirMC/ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8/*root > ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8
ls $dirMC/ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8/*root > ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8
ls $dirMC/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/*root > ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8
ls $dirMC/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/*root > ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8

ls $dirMC/WW_TuneCP5_13TeV-pythia8/*root > WW_TuneCP5_13TeV-pythia8
ls $dirMC/WZ_TuneCP5_13TeV-pythia8/*root > WZ_TuneCP5_13TeV-pythia8
ls $dirMC/ZZ_TuneCP5_13TeV-pythia8/*root > ZZ_TuneCP5_13TeV-pythia8

