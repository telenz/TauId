# $1 working point (e.g. VTightMva)
# $2 tauDecayMode (_3prong0pizeros, _1prong0pizeros, _1prongUpTo4pizeros or empty)

combine -M FitDiagnostics \
    --plots \
    --saveNormalizations \
    --saveShapes \
    --saveWithUncertainties \
    --saveNLL  \
    --robustFit 1 \
    --cminDefaultMinimizerStrategy=0 \
    --rMin=0.5 \
    --rMax=1.5 datacard_tauPt_${1}_WToTauNu${2}.txt \
    -v3
mv fitDiagnostics.root fitDiagnostics_tauPt_${1}${2}.root

