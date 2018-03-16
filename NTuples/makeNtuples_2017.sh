#!bin/sh

# For trigger efficiencies
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_Data.conf SingleMuon_Run2017 20

./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_WJets.conf WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_W1Jets.conf W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_W2Jets.conf W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_W3Jets.conf W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_W4Jets.conf W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10


# For fake rate (no trigger efficiencies need to be included)
./qsub_seq.sh AnalysisNTupleProducer analysisNTupleProducer_tauid_Data.conf JetHT_Run2017 20
