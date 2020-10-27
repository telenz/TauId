#!bin/sh

# this script creates filelists for 2017 data

dirDataSingleMuon=/pnfs/desy.de/cms/tier2/store/user/ywen/ntuples_Apr2020/2017/data/
dirDataJetHT=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2017/data/JetHT/
dirDataMET=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2017/data/MET/
dirMC=/pnfs/desy.de/cms/tier2/store/user/mmeyer/ntuples/2017/mc_v3/
dirtt_st=/pnfs/desy.de/cms/tier2/store/user/ywen/ntuples_Apr2020/2017/mc/

ls $dirDataSingleMuon/SingleMuon_Run2017B-31Mar2018*/*root > SingleMuon_Run2017B
ls $dirDataSingleMuon/SingleMuon_Run2017C-31Mar2018*/*root > SingleMuon_Run2017C
ls $dirDataSingleMuon/SingleMuon_Run2017D-31Mar2018*/*root > SingleMuon_Run2017D
ls $dirDataSingleMuon/SingleMuon_Run2017E-31Mar2018*/*root > SingleMuon_Run2017E
ls $dirDataSingleMuon/SingleMuon_Run2017F-31Mar2018*/*root > SingleMuon_Run2017F

ls $dirDataJetHT/JetHT_Run2017B-31Mar2018*/*root > JetHT_Run2017B
ls $dirDataJetHT/JetHT_Run2017C-31Mar2018*/*root > JetHT_Run2017C
ls $dirDataJetHT/JetHT_Run2017D-31Mar2018*/*root > JetHT_Run2017D
ls $dirDataJetHT/JetHT_Run2017E-31Mar2018*/*root > JetHT_Run2017E
ls $dirDataJetHT/JetHT_Run2017F-31Mar2018*/*root > JetHT_Run2017F

ls $dirDataMET/MET_Run2017B-31Mar2018*/*root > MET_Run2017B
ls $dirDataMET/MET_Run2017C-31Mar2018*/*root > MET_Run2017C
ls $dirDataMET/MET_Run2017D-31Mar2018*/*root > MET_Run2017D
ls $dirDataMET/MET_Run2017E-31Mar2018*/*root > MET_Run2017E
ls $dirDataMET/MET_Run2017F-31Mar2018*/*root > MET_Run2017F

ls $dirMC/WToMuNu_M-200_TuneCP5_13TeV-pythia8*/*root > WToMuNu_M-200
ls $dirMC/WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola*/*root > WToTauNu_M-200

ls $dirMC/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > WJetsToLNu
ls $dirMC/W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > W1JetsToLNu
ls $dirMC/W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > W2JetsToLNu
ls $dirMC/W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > W3JetsToLNu
ls $dirMC/W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > W4JetsToLNu
ls $dirMC/W1JetsToLNu_LHEWpT_100-150_TuneCP5_13TeV-amcnloFXFX-pythia8*/*root > W1JetsToLNu_LHEWpT_100-150
ls $dirMC/W1JetsToLNu_LHEWpT_150-250_TuneCP5_13TeV-amcnloFXFX-pythia8*/*root > W1JetsToLNu_LHEWpT_150-250
ls $dirMC/W1JetsToLNu_LHEWpT_250-400_TuneCP5_13TeV-amcnloFXFX-pythia8*/*root > W1JetsToLNu_LHEWpT_250-400
ls $dirMC/W1JetsToLNu_LHEWpT_400-inf_TuneCP5_13TeV-amcnloFXFX-pythia8*/*root > W1JetsToLNu_LHEWpT_400-inf
ls $dirMC/W2JetsToLNu_LHEWpT_100-150_TuneCP5_13TeV-amcnloFXFX-pythia8*/*root > W2JetsToLNu_LHEWpT_100-150
ls $dirMC/W2JetsToLNu_LHEWpT_150-250_TuneCP5_13TeV-amcnloFXFX-pythia8*/*root > W2JetsToLNu_LHEWpT_150-250
ls $dirMC/W2JetsToLNu_LHEWpT_250-400_TuneCP5_13TeV-amcnloFXFX-pythia8*/*root > W2JetsToLNu_LHEWpT_250-400
ls $dirMC/W2JetsToLNu_LHEWpT_400-inf_TuneCP5_13TeV-amcnloFXFX-pythia8*/*root > W2JetsToLNu_LHEWpT_400-inf

ls $dirMC/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > DYJetsToLL_M-50
ls $dirMC/DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > DY1JetsToLL_M-50
ls $dirMC/DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > DY2JetsToLL_M-50
ls $dirMC/DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > DY3JetsToLL_M-50
ls $dirMC/DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8*/*root > DY4JetsToLL_M-50

ls $dirMC/ZJetsToNuNu_HT-100To200_13TeV-madgraph*/*root > ZJetsToNuNu_HT-100To200
ls $dirMC/ZJetsToNuNu_HT-200To400_13TeV-madgraph*/*root > ZJetsToNuNu_HT-200To400
ls $dirMC/ZJetsToNuNu_HT-400To600_13TeV-madgraph*/*root > ZJetsToNuNu_HT-400To600
ls $dirMC/ZJetsToNuNu_HT-600To800_13TeV-madgraph*/*root > ZJetsToNuNu_HT-600To800
ls $dirMC/ZJetsToNuNu_HT-800To1200_13TeV-madgraph*/*root > ZJetsToNuNu_HT-800To1200
ls $dirMC/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph*/*root > ZJetsToNuNu_HT-1200To2500
ls $dirMC/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph*/*root > ZJetsToNuNu_HT-2500ToInf

#ls $dirMC/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/*root > TTToHadronic
#ls $dirMC/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/*root > TTToSemiLeptonic
#ls $dirMC/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8/*root > TTTo2L2Nu
ls $dirtt_st/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8/*root > TTTo2L2Nu_part2
ls $dirtt_st/TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8/*root > TTTo2L2Nu
ls $dirtt_st/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/*root > TTToHadronic_part2
ls $dirtt_st/TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8/*root > TTToHadronic
ls $dirtt_st/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/*root > TTToSemiLeptonic_part2
ls $dirtt_st/TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8/*root > TTToSemiLeptonic

ls $dirtt_st/ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8/*root > ST_t-channel_antitop_4f_inclusiveDecays
ls $dirtt_st/ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8/*root > ST_t-channel_top_4f_inclusiveDecays
ls $dirtt_st/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/*root > ST_tW_antitop_5f_inclusiveDecays
ls $dirtt_st/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/*root > ST_tW_top_5f_inclusiveDecays

#ls $dirMC/ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8/*root > ST_t-channel_top_4f_inclusiveDecays
#ls $dirMC/ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8/*root > ST_t-channel_antitop_4f_inclusiveDecays
#ls $dirMC/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/*root > ST_tW_top_5f_inclusiveDecays
#ls $dirMC/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/*root > ST_tW_antitop_5f_inclusiveDecays

ls $dirMC/WW_TuneCP5_13TeV-pythia8/*root > WW
ls $dirMC/WZ_TuneCP5_13TeV-pythia8/*root > WZ
ls $dirMC/ZZ_TuneCP5_13TeV-pythia8/*root > ZZ
