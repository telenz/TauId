#!/bin/csh
# $1 : isolation : taubyMediumDeepTau2017v2p1VSjet, taubyTightDeepTau2017v2p1VSjet
# $2 : tau decay mode : inclusive, 1prong, 1prongpi0s, 3prong

cd inputs
combineCards.py tauPt_${1}_${2}_WTauNu_Trigger.txt tauPt_${1}_${2}_WTauNu_notTrigger.txt > tauPt_${1}_${2}_WTauNu.txt
combine -M FitDiagnostics --plots --saveNormalizations --saveShapes --saveWithUncertainties --saveNLL --robustFit 1 --cminDefaultMinimizerStrategy=0 --rMin=0.5 --rMax=1.5 tauPt_${1}_${2}_WTauNu.txt -v3
mv fitDiagnostics.root fitDiagnostics_tauPt_${1}_${2}.root
cd ../
