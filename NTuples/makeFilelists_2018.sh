#!bin/sh

dirDataSingleMuon=/nfs/dust/cms/user/ywen/Storage/SingleMuon
dirDYandTT=/nfs/dust/cms/user/ywen/Storage/MC
dirWVVandST=/nfs/dust/cms/user/cardinia/gridjobs/2018/NTuples/MC/RunIIAutumn18
dirDataJetHT=/nfs/dust/cms/user/mameyer/SM_HiggsTauTau/ntuples/2018Data_17Sep2018/
dirWandZtoNuNuMC=/nfs/dust/cms/user/mameyer/SM_HiggsTauTau/ntuples/Autumn18/
dirMETData=/nfs/dust/cms/group/higgs-kit/2018/MET

ls $dirDataSingleMuon/SingleMuon_Run2018A_17Sep2018v2/*root > SingleMuon_Run2018A
ls $dirDataSingleMuon/SingleMuon_Run2018B_17Sep2018v1/*root > SingleMuon_Run2018B
ls $dirDataSingleMuon/SingleMuon_Run2018C_17Sep2018v1/*root > SingleMuon_Run2018C
ls $dirDataSingleMuon/SingleMuon_Run2018D_PromptRecov2/*root > SingleMuon_Run2018D

ls $dirDataJetHT/JetHT_Run2018A/*root > JetHT_Run2018A
ls $dirDataJetHT/JetHT_Run2018B/*root > JetHT_Run2018B
ls $dirDataJetHT/JetHT_Run2018C/*root > JetHT_Run2018C
ls $dirDataJetHT/JetHT_Run2018D_v1/*root > JetHT_Run2018D
ls $dirDataJetHT/JetHT_Run2018D_v2/*root >> JetHT_Run2018D

ls $dirMETData/MET_Run2018A-17Sep2018-v1 > MET_Run2018A
ls $dirMETData/MET_Run2018B-17Sep2018-v1 > MET_Run2018B
ls $dirMETData/MET_Run2018C-17Sep2018-v1 > MET_Run2018C
ls $dirMETData/MET_Run2018D-PromptReco-v1 > MET_Run2018D
ls $dirMETData/MET_Run2018D-PromptReco-v2 >> MET_Run2018D

ls $dirDYandTT/DYJetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8/*root > DYJetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8
ls $dirDYandTT/DY1JetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8/*root > DY1JetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8
ls $dirDYandTT/DY2JetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8/*root > DY2JetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8
ls $dirDYandTT/DY3JetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8/*root > DY3JetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8
ls $dirDYandTT/DY4JetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8/*root > DY4JetsToLL_M-50_TuneCP5_13TeV_madgraphMLM_pythia8

ls $dirDYandTT/TTTo2L2Nu_TuneCP5_13TeV_powheg_pythia8/*root > TTTo2L2Nu_TuneCP5_13TeV_powheg_pythia8
ls $dirDYandTT/TTToSemiLeptonic_TuneCP5_13TeV_powheg_pythia8/*root > TTToSemiLeptonic_TuneCP5_13TeV_powheg_pythia8
ls $dirDYandTT/TTToHadronic_TuneCP5_13TeV_powheg_pythia8/*root > TTToHadronic_TuneCP5_13TeV_powheg_pythia8

ls $dirWandZtoNuNuMC/WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWandZtoNuNuMC/WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWandZtoNuNuMC/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWandZtoNuNuMC/WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWandZtoNuNuMC/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWandZtoNuNuMC/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWandZtoNuNuMC/WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWandZtoNuNuMC/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8/*root > WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWandZtoNuNuMC/WToMuNu_M-200_TuneCP5_13TeV-pythia8/*root > WToMuNu_M-200_TuneCP5_13TeV-pythia8
ls $dirWandZtoNuNuMC/WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola/*root > WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola
ls $dirWandZtoNuNuMC/ZJetsToNuNu_HT-100To200_13TeV-madgraph/*root > ZJetsToNuNu_HT-100To200_13TeV-madgraph
ls $dirWandZtoNuNuMC/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/*root > ZJetsToNuNu_HT-1200To2500_13TeV-madgraph
ls $dirWandZtoNuNuMC/ZJetsToNuNu_HT-200To400_13TeV-madgraph/*root > ZJetsToNuNu_HT-200To400_13TeV-madgraph
ls $dirWandZtoNuNuMC/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/*root > ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph
ls $dirWandZtoNuNuMC/ZJetsToNuNu_HT-400To600_13TeV-madgraph/*root > ZJetsToNuNu_HT-400To600_13TeV-madgraph
ls $dirWandZtoNuNuMC/ZJetsToNuNu_HT-600To800_13TeV-madgraph/*root > ZJetsToNuNu_HT-600To800_13TeV-madgraph
ls $dirWandZtoNuNuMC/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/*root > ZJetsToNuNu_HT-800To1200_13TeV-madgraph

ls $dirWVVandST/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/*root > WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWVVandST/W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/*root > W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWVVandST/W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/*root > W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWVVandST/W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/*root > W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8
ls $dirWVVandST/W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/*root > W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8

ls $dirWVVandST/ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/*root > ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8
ls $dirWVVandST/ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/*root > ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8
ls $dirWVVandST/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v1/*root > ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8
ls $dirWVVandST/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v1/*root > ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8


ls $dirWVVandST/WW_TuneCP5_13TeV-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/*root > WW_TuneCP5_13TeV-pythia8
ls $dirWVVandST/WZ_TuneCP5_13TeV-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v3/*root > WZ_TuneCP5_13TeV-pythia8
ls $dirWVVandST/ZZ_TuneCP5_13TeV-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v2/*root > ZZ_TuneCP5_13TeV-pythia8

