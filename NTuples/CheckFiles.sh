#!bin/bash

cd WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 12'

cd ../W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 17'

cd ../W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 11'

cd ../W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 10'

cd ../W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 14'

cd ../SingleMuon_Run2017_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files SingleMuon_Run2017: '$file_num', should be: 217'

cd ../JetHT_Run2017_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files JetHT_Run2017: '$file_num', should be: 112'

cd ../MET_Run2017_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files MET_Run2017: '$file_num', should be: 127'

cd ../TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8: '$file_num', should be: 30'

cd ../TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8: '$file_num', should be: 60'

cd ../TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8: '$file_num', should be: 49'

cd ../ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8: '$file_num', should be: 13'

cd ../ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8: '$file_num', should be: 8'

cd ../ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8: '$file_num', should be: 9'

cd ../ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8: '$file_num', should be: 5'

cd ../WW_TuneCP5_13TeV-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files WW_TuneCP5_13TeV-pythia8: '$file_num', should be: 5'


cd ../WZ_TuneCP5_13TeV-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files WZ_TuneCP5_13TeV-pythia8: '$file_num', should be: 3'


cd ../ZZ_TuneCP5_13TeV-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ZZ_TuneCP5_13TeV-pythia8: '$file_num', should be: 3'


cd ../DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 32'

cd ../DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 14'


cd ../DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 11'


cd ../DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 12'


cd ../DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8: '$file_num', should be: 51'

cd ../W1JetsToLNu_LHEWpT_50-150_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files W1JetsToLNu_LHEWpT_50-150: '$file_num', should be: 42'

cd ../W1JetsToLNu_LHEWpT_150-250_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files W1JetsToLNu_LHEWpT_150-250: '$file_num', should be: 73'

cd ../W1JetsToLNu_LHEWpT_250-400_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files W1JetsToLNu_LHEWpT_250-400: '$file_num', should be: 12'

cd ../W1JetsToLNu_LHEWpT_400-inf_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files W1JetsToLNu_LHEWpT_400-inf: '$file_num', should be: 6'

cd ../ZJetsToNuNu_HT-100To200_13TeV-madgraph_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ZJetsToNuNu_HT-100To200_13TeV-madgraph: '$file_num', should be: 15'

cd ../ZJetsToNuNu_HT-200To400_13TeV-madgraph_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ZJetsToNuNu_HT-200To400_13TeV-madgraph: '$file_num', should be: 17'

cd ../ZJetsToNuNu_HT-400To600_13TeV-madgraph_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ZJetsToNuNu_HT-400To600_13TeV-madgraph: '$file_num', should be: 10'

cd ../ZJetsToNuNu_HT-600To800_13TeV-madgraph_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ZJetsToNuNu_HT-600To800_13TeV-madgraph_files: '$file_num', should be: 6'

cd ../ZJetsToNuNu_HT-800To1200_13TeV-madgraph_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ZJetsToNuNu_HT-800To1200_13TeV-madgraph: '$file_num', should be: 3'

cd ../ZJetsToNuNu_HT-1200To2500_13TeV-madgraph_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ZJetsToNuNu_HT-1200To2500_13TeV-madgrap: '$file_num', should be: 2'

cd ../ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph_files
file_num=$(ls -1 --file-type | grep -r "Total number of events in Tree" * | wc -l)
print 'Number of files ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph: '$file_num', should be: 1'

cd ..