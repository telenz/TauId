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

cd ..