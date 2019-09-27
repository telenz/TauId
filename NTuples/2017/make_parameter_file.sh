#!bin/sh

echo "CONFIGFILE,FILELIST" > parameters.txt

# For trigger efficiencies
# ./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017B 20
# ./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017C 20
# ./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017D 20
# ./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017E 20
# ./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017F 20

# ./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu 40
# ./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf W1JetsToLNu 40
# ./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf W2JetsToLNu 40
# ./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf W3JetsToLNu 40
# ./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf W4JetsToLNu 40

# For the rest of measurement
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017B 20
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017C 20
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017D 20
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017E 20
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf SingleMuon_Run2017F 20

./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf JetHT_Run2017B 40
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf JetHT_Run2017C 40
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf JetHT_Run2017D 40
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf JetHT_Run2017E 40
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf JetHT_Run2017F 40

./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf MET_Run2017B 40
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf MET_Run2017C 40
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf MET_Run2017D 40
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf MET_Run2017E 40
./split_filelist.sh analysisNTupleProducer_tauid_Data_2017.conf MET_Run2017F 40

./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf W1JetsToLNu 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf W2JetsToLNu 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf W3JetsToLNu 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf W4JetsToLNu 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu_HT-70To100 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu_HT-100To200 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu_HT-200To400 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu_HT-400To600 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu_HT-600To800 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu_HT-800To1200 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu_HT-1200To2500 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WJetsToLNu_HT-2500ToInf 40

./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ZJetsToNuNu_HT-100To200 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ZJetsToNuNu_HT-200To400 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ZJetsToNuNu_HT-400To600 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ZJetsToNuNu_HT-600To800 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ZJetsToNuNu_HT-800To1200 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ZJetsToNuNu_HT-1200To2500 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ZJetsToNuNu_HT-2500ToInf 40

./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf DYJetsToLL_M-50 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf DY1JetsToLL_M-50 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf DY2JetsToLL_M-50 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf DY3JetsToLL_M-50 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf DY4JetsToLL_M-50 40

./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf TT 40

./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ST_t-channel_top_4f_inclusiveDecays 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ST_t-channel_antitop_4f_inclusiveDecays 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ST_tW_antitop_5f_inclusiveDecays 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ST_tW_top_5f_inclusiveDecays 40

./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WW 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WZ 40
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf ZZ 40

./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WToMuNu_M-200 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017.conf WToTauNu_M-200 20

# For uncertainties
cp WToMuNu_M-200 WToMuNu_M-200_jesUp
cp WToMuNu_M-200 WToMuNu_M-200_jesDown
cp WToMuNu_M-200 WToMuNu_M-200_uesUp
cp WToMuNu_M-200 WToMuNu_M-200_uesDown
cp WToMuNu_M-200 WToMuNu_M-200_muUp
cp WToMuNu_M-200 WToMuNu_M-200_muDown
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_jesUp_WStarMuNu.conf WToMuNu_M-200_jesUp 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_jesDown_WStarMuNu.conf WToMuNu_M-200_jesDown 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_uesUp_WStarMuNu.conf WToMuNu_M-200_uesUp 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_uesDown_WStarMuNu.conf WToMuNu_M-200_uesDown 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_muUp_WStarMuNu.conf WToMuNu_M-200_muUp 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_muDown_WStarMuNu.conf WToMuNu_M-200_muDown 20

cp WToTauNu_M-200 WToTauNu_M-200_jesUp
cp WToTauNu_M-200 WToTauNu_M-200_jesDown
cp WToTauNu_M-200 WToTauNu_M-200_uesUp
cp WToTauNu_M-200 WToTauNu_M-200_uesDown
cp WToTauNu_M-200 WToTauNu_M-200_taues_1prong0pizerosUp
cp WToTauNu_M-200 WToTauNu_M-200_taues_1prong0pizerosDown
cp WToTauNu_M-200 WToTauNu_M-200_taues_1prongUpTo4pizerosUp
cp WToTauNu_M-200 WToTauNu_M-200_taues_1prongUpTo4pizerosDown
cp WToTauNu_M-200 WToTauNu_M-200_taues_3prong0pizerosUp
cp WToTauNu_M-200 WToTauNu_M-200_taues_3prong0pizerosDown
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_taues_1prong0pizerosDown_WStarTauNu.conf WToTauNu_M-200_taues_1prong0pizerosDown 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_taues_1prong0pizerosUp_WStarTauNu.conf  WToTauNu_M-200_taues_1prong0pizerosUp 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_taues_1prongUpTo4pizerosDown_WStarTauNu.conf WToTauNu_M-200_taues_1prongUpTo4pizerosDown 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_taues_1prongUpTo4pizerosUp_WStarTauNu.conf WToTauNu_M-200_taues_1prongUpTo4pizerosUp 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_taues_3prong0pizerosDown_WStarTauNu.conf WToTauNu_M-200_taues_3prong0pizerosDown 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_taues_3prong0pizerosUp_WStarTauNu.conf WToTauNu_M-200_taues_3prong0pizerosUp 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_jesUp_WStarTauNu.conf WToTauNu_M-200_jesUp 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_jesDown_WStarTauNu.conf WToTauNu_M-200_jesDown 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_uesUp_WStarTauNu.conf WToTauNu_M-200_uesUp 20
./split_filelist.sh analysisNTupleProducer_tauid_MC_2017_uesDown_WStarTauNu.conf WToTauNu_M-200_uesDown 20