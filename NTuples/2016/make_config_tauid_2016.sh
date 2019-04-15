#!/bin/bash

year=2016

cp analysisNTupleProducer_tauid_MC_2016.conf analysisNTupleProducer_tauid_MC_2016_backup.conf

# systematic uncertainties

# WStarMuNu

sed 's/JetES = 0/JetES = -1/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_jesDown_WStarMuNu.conf

sed 's/JetES = 0/JetES = 1/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_jesUp_WStarMuNu.conf

sed 's/UnclusteredES = 0/UnclusteredES = -1/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_uesDown_WStarMuNu.conf

sed 's/UnclusteredES = 0/UnclusteredES = 1/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_uesUp_WStarMuNu.conf

sed 's/MuonMomScale = 1./MuonMomScale = 0.98/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_muDown_WStarMuNu.conf

sed 's/MuonMomScale = 1./MuonMomScale = 1.02/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_muUp_WStarMuNu.conf

# WStarTauNu

sed 's/JetES = 0/JetES = -1/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_jesDown_WStarTauNu.conf

sed 's/JetES = 0/JetES = 1/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_jesUp_WStarTauNu.conf

sed 's/UnclusteredES = 0/UnclusteredES = -1/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_uesDown_WStarTauNu.conf

sed 's/UnclusteredES = 0/UnclusteredES = 1/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_uesUp_WStarTauNu.conf

sed 's/TauMomScale = 1./TauMomScale = 0.98/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_tauesDown_WStarTauNu.conf

sed 's/TauMomScale = 1./TauMomScale = 1.02/' analysisNTupleProducer_tauid_MC_2016.conf > analysisNTupleProducer_tauid_MC_2016_tauesUp_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 1prong0pizeros/' analysisNTupleProducer_tauid_MC_2016_tauesDown_WStarTauNu.conf > analysisNTupleProducer_tauid_MC_2016_taues_1prong0pizerosDown_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 1prongUpTo4pizeros/' analysisNTupleProducer_tauid_MC_2016_tauesDown_WStarTauNu.conf > analysisNTupleProducer_tauid_MC_2016_taues_1prongUpTo4pizerosDown_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 3prong0pizeros/' analysisNTupleProducer_tauid_MC_2016_tauesDown_WStarTauNu.conf > analysisNTupleProducer_tauid_MC_2016_taues_3prong0pizerosDown_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 1prong0pizeros/' analysisNTupleProducer_tauid_MC_2016_tauesUp_WStarTauNu.conf > analysisNTupleProducer_tauid_MC_2016_taues_1prong0pizerosUp_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 1prongUpTo4pizeros/' analysisNTupleProducer_tauid_MC_2016_tauesUp_WStarTauNu.conf > analysisNTupleProducer_tauid_MC_2016_taues_1prongUpTo4pizerosUp_WStarTauNu.conf

sed 's/TauDecayMode =/TauDecayMode = 3prong0pizeros/' analysisNTupleProducer_tauid_MC_2016_tauesUp_WStarTauNu.conf > analysisNTupleProducer_tauid_MC_2016_taues_3prong0pizerosUp_WStarTauNu.conf



#for file in $(ls *.conf)
#do
#    echo "**********************************"
#    echo $file
#    echo "**********************************"
#
#    diff analysisNTupleProducer_tauid_MC_backup.conf $file
#done