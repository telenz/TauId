#!/bin/sh
tauDecayMode=""
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_LooseMva2017v2_WToTauNu${tauDecayMode}.txt > datacard_LooseMva2017v2_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_MediumMva2017v2_WToTauNu${tauDecayMode}.txt > datacard_MediumMva2017v2_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_TightMva2017v2_WToTauNu${tauDecayMode}.txt > datacard_TightMva2017v2_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_VTightMva2017v2_WToTauNu${tauDecayMode}.txt > datacard_VTightMva2017v2_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_Loose_WToTauNu${tauDecayMode}.txt > datacard_Loose_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_Medium_WToTauNu${tauDecayMode}.txt > datacard_Medium_Combined${tauDecayMode}.txt
combineCards.py ../output/datacard_mtmuon_WToMuNu.txt ../output/datacard_mttau_Tight_WToTauNu${tauDecayMode}.txt > datacard_Tight_Combined${tauDecayMode}.txt

