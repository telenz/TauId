#!bin/sh

# For trigger efficiencies
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_Data.conf SingleMuon_Run2017 20

./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_WJets.conf WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_W1Jets.conf W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_W2Jets.conf W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_W3Jets.conf W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_W4Jets.conf W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10


# For fake rate (no trigger efficiencies need to be included)
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_Data.conf JetHT_Run2017 20

# For n_EWK (including trigger efficiencies)

./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_Data.conf MET_Run2017 20
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_WJets.conf WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_TTbarLep.conf TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8  10 
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_TTbarHad.conf TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_TTbarSemiLep.conf TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_ST_t-ch_top.conf ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_ST_t-ch_antitop.conf ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_ST_tW_top.conf ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_ST_tW_antitop.conf ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_WW.conf WW_TuneCP5_13TeV-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_WZ.conf WZ_TuneCP5_13TeV-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_ZZ.conf ZZ_TuneCP5_13TeV-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_DY1Jets.conf DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_DY2Jets.conf DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_DY3Jets.conf DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_DY4Jets.conf DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8 10
./qsub_seq.sh AnalysisNTupleProducer_TauID analysisNTupleProducer_tauid_MC_DYJets.conf  DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8 10


# missing files: 
#     - virtual W -> tau/mu nu --> use old (Summer17 MC) for now
#     - HT binned Z+jets / W+jets 
#     - Z to nunu +jets, HT binned 