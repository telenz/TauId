#!bin/sh

# this script creates filelists for 2016-legacy data

dirDataSingleMuon=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2016/data/SingleMuon/
dirDataJetHT=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2016/data/JetHT_v2/
dirDataMET=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2016/data/MET_v2/
dirMC=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2016/mc/

ls $dirDataSingleMuon/SingleMuon_Run2016B-17Jul2018*/*root > SingleMuon_Run2016B
ls $dirDataSingleMuon/SingleMuon_Run2016C-17Jul2018*/*root > SingleMuon_Run2016C
ls $dirDataSingleMuon/SingleMuon_Run2016D-17Jul2018*/*root > SingleMuon_Run2016D
ls $dirDataSingleMuon/SingleMuon_Run2016E-17Jul2018*/*root > SingleMuon_Run2016E
ls $dirDataSingleMuon/SingleMuon_Run2016F-17Jul2018*/*root > SingleMuon_Run2016F
ls $dirDataSingleMuon/SingleMuon_Run2016G-17Jul2018*/*root > SingleMuon_Run2016G
ls $dirDataSingleMuon/SingleMuon_Run2016H-17Jul2018*/*root > SingleMuon_Run2016H

ls $dirDataJetHT/JetHT_Run2016B-17Jul2018*/*root > JetHT_Run2016B
ls $dirDataJetHT/JetHT_Run2016C-17Jul2018*/*root > JetHT_Run2016C
ls $dirDataJetHT/JetHT_Run2016D-17Jul2018*/*root > JetHT_Run2016D
ls $dirDataJetHT/JetHT_Run2016E-17Jul2018*/*root > JetHT_Run2016E
ls $dirDataJetHT/JetHT_Run2016F-17Jul2018*/*root > JetHT_Run2016F
ls $dirDataJetHT/JetHT_Run2016G-17Jul2018*/*root > JetHT_Run2016G
ls $dirDataJetHT/JetHT_Run2016H-17Jul2018*/*root > JetHT_Run2016H

ls $dirDataMET/MET_Run2016B-17Jul2018*/*root > MET_Run2016B
ls $dirDataMET/MET_Run2016C-17Jul2018*/*root > MET_Run2016C
ls $dirDataMET/MET_Run2016D-17Jul2018*/*root > MET_Run2016D
ls $dirDataMET/MET_Run2016E-17Jul2018*/*root > MET_Run2016E
ls $dirDataMET/MET_Run2016F-17Jul2018*/*root > MET_Run2016F
ls $dirDataMET/MET_Run2016G-17Jul2018*/*root > MET_Run2016G
ls $dirDataMET/MET_Run2016H-17Jul2018*/*root > MET_Run2016H

ls $dirMC/WToMuNu_M-200_TuneCUETP8M1_13TeV-pythia8/*root > WToMuNu_M-200
ls $dirMC/WToTauNu_M-200_TuneCUETP8M1_13TeV-pythia8-tauola/*root > WToTauNu_M-200

ls $dirMC/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > WJetsToLNu
ls $dirMC/WJetsToLNu_HT-70To100*/*root > WJetsToLNu_HT-70To100
ls $dirMC/WJetsToLNu_HT-100To200*/*root > WJetsToLNu_HT-100To200
ls $dirMC/WJetsToLNu_HT-200To400*/*root > WJetsToLNu_HT-200To400
ls $dirMC/WJetsToLNu_HT-400To600*/*root > WJetsToLNu_HT-400To600
ls $dirMC/WJetsToLNu_HT-600To800*/*root > WJetsToLNu_HT-600To800
ls $dirMC/WJetsToLNu_HT-800To1200*/*root > WJetsToLNu_HT-800To1200
ls $dirMC/WJetsToLNu_HT-1200To2500*/*root > WJetsToLNu_HT-1200To2500
ls $dirMC/WJetsToLNu_HT-2500ToInf*/*root > WJetsToLNu_HT-2500ToInf
ls $dirMC/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > W1JetsToLNu
ls $dirMC/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > W2JetsToLNu
ls $dirMC/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > W3JetsToLNu
ls $dirMC/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > W4JetsToLNu

ls $dirMC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DYJetsToLL_M-50
ls $dirMC/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DY1JetsToLL_M-50
ls $dirMC/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DY2JetsToLL_M-50
ls $dirMC/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DY3JetsToLL_M-50
ls $dirMC/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DY4JetsToLL_M-50

ls $dirMC/ZJetsToNuNu_HT-100To200_13TeV-madgraph*/*root > ZJetsToNuNu_HT-100To200
ls $dirMC/ZJetsToNuNu_HT-200To400_13TeV-madgraph*/*root > ZJetsToNuNu_HT-200To400
ls $dirMC/ZJetsToNuNu_HT-400To600_13TeV-madgraph*/*root > ZJetsToNuNu_HT-400To600
ls $dirMC/ZJetsToNuNu_HT-600To800_13TeV-madgraph*/*root > ZJetsToNuNu_HT-600To800
ls $dirMC/ZJetsToNuNu_HT-800To1200_13TeV-madgraph*/*root > ZJetsToNuNu_HT-800To1200
ls $dirMC/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph*/*root > ZJetsToNuNu_HT-1200To2500
ls $dirMC/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph*/*root > ZJetsToNuNu_HT-2500ToInf

ls $dirMC/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/*root > TT

ls $dirMC/ST_t-channel_antitop_4f*/*root > ST_t-channel_top_4f_inclusiveDecays
ls $dirMC/ST_t-channel_top_4f*/*root > ST_t-channel_antitop_4f_inclusiveDecays
ls $dirMC/ST_tW_antitop_5f*/*root > ST_tW_antitop_5f_inclusiveDecays
ls $dirMC/ST_tW_top_5f*/*root > ST_tW_top_5f_inclusiveDecays

ls $dirMC/WW_TuneCUETP8M1_13TeV-pythia8*/*root > WW
ls $dirMC/WZ_TuneCUETP8M1_13TeV-pythia8*/*root > WZ
ls $dirMC/ZZ_TuneCUETP8M1_13TeV*/*root > ZZ
