#!bin/sh

# this script creates filelists for 2016-legacy data

dirData=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/ntuples_Oct2020/2016/data/
dirMC=/pnfs/desy.de/cms/tier2/store/user/rasp/ntuples_Oct2020/2016/mc
dirMC2=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/ntuples_Oct2020/2016/mc
dirMCold=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2016/mc/

ls $dirData/SingleMuon_Run2016B_ver1/*root > SingleMuon_Run2016B
ls $dirData/SingleMuon_Run2016B_ver2/*root >> SingleMuon_Run2016B
ls $dirData/SingleMuon_Run2016C/*root > SingleMuon_Run2016C
ls $dirData/SingleMuon_Run2016D/*root > SingleMuon_Run2016D
ls $dirData/SingleMuon_Run2016E/*root > SingleMuon_Run2016E
ls $dirData/SingleMuon_Run2016F/*root > SingleMuon_Run2016F
ls $dirData/SingleMuon_Run2016G/*root > SingleMuon_Run2016G
ls $dirData/SingleMuon_Run2016H/*root > SingleMuon_Run2016H

ls $dirData/JetHT_Run2016B_ver1/*root > JetHT_Run2016B
ls $dirData/JetHT_Run2016B_ver2/*root >> JetHT_Run2016B
ls $dirData/JetHT_Run2016C/*root > JetHT_Run2016C
ls $dirData/JetHT_Run2016D/*root > JetHT_Run2016D
ls $dirData/JetHT_Run2016E/*root > JetHT_Run2016E
ls $dirData/JetHT_Run2016F/*root > JetHT_Run2016F
ls $dirData/JetHT_Run2016G/*root > JetHT_Run2016G
ls $dirData/JetHT_Run2016H/*root > JetHT_Run2016H

ls $dirData/MET_Run2016B_ver1/*root > MET_Run2016B
ls $dirData/MET_Run2016B_ver2/*root >> MET_Run2016B
ls $dirData/MET_Run2016C/*root > MET_Run2016C
ls $dirData/MET_Run2016D/*root > MET_Run2016D
ls $dirData/MET_Run2016E/*root > MET_Run2016E
ls $dirData/MET_Run2016F/*root > MET_Run2016F
ls $dirData/MET_Run2016G/*root > MET_Run2016G
ls $dirData/MET_Run2016H/*root > MET_Run2016H

ls $dirMCold/WToMuNu_M-200_TuneCUETP8M1_13TeV-pythia8/*root > WToMuNu_M-200
ls $dirMC/WToTauNu_M-200_TuneCUETP8M1_13TeV-pythia8-tauola/*root > WToTauNu_M-200

ls $dirMC2/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > WJetsToLNu
ls $dirMC/WJetsToLNu_HT-70To100*/*root > WJetsToLNu_HT-70To100
ls $dirMC/WJetsToLNu_HT-100To200*/*root > WJetsToLNu_HT-100To200
ls $dirMC/WJetsToLNu_HT-200To400*/*root > WJetsToLNu_HT-200To400
ls $dirMC/WJetsToLNu_HT-400To600*/*root > WJetsToLNu_HT-400To600
ls $dirMC/WJetsToLNu_HT-600To800*/*root > WJetsToLNu_HT-600To800
ls $dirMC/WJetsToLNu_HT-800To1200*/*root > WJetsToLNu_HT-800To1200
ls $dirMC/WJetsToLNu_HT-1200To2500*/*root > WJetsToLNu_HT-1200To2500
ls $dirMC/WJetsToLNu_HT-2500ToInf*/*root > WJetsToLNu_HT-2500ToInf
ls $dirMC2/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > W1JetsToLNu
ls $dirMC/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > W2JetsToLNu
ls $dirMC/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > W3JetsToLNu
ls $dirMC/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > W4JetsToLNu

ls $dirMC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DYJetsToLL_M-50
ls $dirMC/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DY1JetsToLL_M-50
ls $dirMC/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DY2JetsToLL_M-50
ls $dirMC/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DY3JetsToLL_M-50
ls $dirMC/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8*/*root > DY4JetsToLL_M-50

ls $dirMC2/ZJetsToNuNu_HT-100To200_13TeV-madgraph*/*root > ZJetsToNuNu_HT-100To200
ls $dirMC2/ZJetsToNuNu_HT-200To400_13TeV-madgraph*/*root > ZJetsToNuNu_HT-200To400
ls $dirMC2/ZJetsToNuNu_HT-400To600_13TeV-madgraph*/*root > ZJetsToNuNu_HT-400To600
ls $dirMC2/ZJetsToNuNu_HT-600To800_13TeV-madgraph*/*root > ZJetsToNuNu_HT-600To800
ls $dirMC2/ZJetsToNuNu_HT-800To1200_13TeV-madgraph*/*root > ZJetsToNuNu_HT-800To1200
ls $dirMC2/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph*/*root > ZJetsToNuNu_HT-1200To2500
ls $dirMC2/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph*/*root > ZJetsToNuNu_HT-2500ToInf

ls $dirMC2/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/*root > TT

ls $dirMC2/ST_t-channel_antitop_4f*/*root > ST_t-channel_top_4f_inclusiveDecays
ls $dirMC2/ST_t-channel_top_4f*/*root > ST_t-channel_antitop_4f_inclusiveDecays
ls $dirMC2/ST_tW_antitop_5f*/*root > ST_tW_antitop_5f_inclusiveDecays
ls $dirMC2/ST_tW_top_5f*/*root > ST_tW_top_5f_inclusiveDecays

ls $dirMC2/WW_TuneCUETP8M1_13TeV-pythia8*/*root > WW
ls $dirMC2/WZ_TuneCUETP8M1_13TeV-pythia8*/*root > WZ
ls $dirMC2/ZZ_TuneCUETP8M1_13TeV*/*root > ZZ
