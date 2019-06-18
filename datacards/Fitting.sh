# $1 working point (e.g. VTightMva)
# $2 tauDecayMode (_3prong0pizeros, _1prong0pizeros, _1prongUpTo4pizeros or empty)

#combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --saveNLL --robustFit=1 --rMin=-1 --rMax=1 -m 81 datacard_$1_Combined$2.txt -v2
#combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --saveNLL --robustFit=1 --rMin=-1 --rMax=1 -m 81 datacard_$1_Combined$2.txt -v2 --cminDefaultMinimizerStrategy 0 --robustHesse 1
combine -M FitDiagnostics --saveNormalizations --saveShapes --saveWithUncertainties --saveNLL --robustFit=1 --rMin=0.4 --rMax=2.5 -m 81 datacard_$1_Combined$2.txt --redefineSignalPOIs tauId --setParameters r=1.0 -s 1234

# some scale factors were determined with rMin=0.0, some with rMin=0.3

mv fitDiagnostics.root  fitDiagnostics_$1$2.root


# redefien signal pois
# multiDimFit 