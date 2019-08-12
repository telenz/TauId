#!bin/bash


# root -b -l <<EOF > results_Loose.txt
# TFile *_file0 = TFile::Open("fitDiagnostics_Loose.root")
# fit_s->Print()
# fit_s->correlation("tauId","r")
# EOF

# root -b -l <<EOF > results_Medium.txt
# TFile *_file0 = TFile::Open("fitDiagnostics_Medium.root")
# fit_s->Print()
# fit_s->correlation("tauId","r")
# EOF

# root -b -l <<EOF > results_Tight.txt
# TFile *_file0 = TFile::Open("fitDiagnostics_Tight.root")
# fit_s->Print()
# fit_s->correlation("tauId","r")
# EOF

# root -b -l <<EOF > results_VVLooseMva2017v2.txt
# TFile *_file0 = TFile::Open("fitDiagnostics_VVLooseMva2017v2.root")
# fit_s->Print()
# fit_s->correlation("tauId","r")
# EOF

root -b -l <<EOF > results_VLooseMva2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_VLooseMva2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF


root -b -l <<EOF > results_LooseMva2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_LooseMva2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_MediumMva2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_MediumMva2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_TightMva2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_TightMva2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_VTightMva2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_VTightMva2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_VVTightMva2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_VVTightMva2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_VVLooseDeepTau2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_VVLooseDeepTau2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_VLooseDeepTau2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_VLooseDeepTau2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_LooseDeepTau2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_LooseDeepTau2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_MediumDeepTau2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_MediumDeepTau2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_TightDeepTau2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_TightDeepTau2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_VTightDeepTau2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_VTightDeepTau2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_VVTightDeepTau2017v2.txt
TFile *_file0 = TFile::Open("fitDiagnostics_VVTightDeepTau2017v2.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF


#wps=("Loose" "Medium" "Tight" "VVLooseMva2017v2" "VLooseMva2017v2" "LooseMva2017v2" "MediumMva2017v2" "TightMva2017v2" "VTightMva2017v2" "VVTightMva2017v2")
wps=("VLooseMva2017v2" "LooseMva2017v2" "MediumMva2017v2" "TightMva2017v2" "VTightMva2017v2" "VVTightMva2017v2")
#wps=("VVLooseDeepTau2017v2" "VLooseDeepTau2017v2" "LooseDeepTau2017v2" "MediumDeepTau2017v2" "TightDeepTau2017v2" "VTightDeepTau2017v2" "VVTightDeepTau2017v2")

for i in "${wps[@]}"
do
   echo "------------------------------------------------------------------------"
   echo "$i"
   grep "tauId" results_$i.txt
   grep "       r" results_$i.txt
   echo "correlation = "
   grep "(double)" results_$i.txt
   grep "(Double_t)" results_$i.txt
   echo "------------------------------------------------------------------------"

done