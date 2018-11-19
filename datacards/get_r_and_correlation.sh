#!bin/bash

root -b -l <<EOF > results_Loose.txt
TFile *_file0 = TFile::Open("fitDiagnostics_Loose.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_Medium.txt
TFile *_file0 = TFile::Open("fitDiagnostics_Medium.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

root -b -l <<EOF > results_Tight.txt
TFile *_file0 = TFile::Open("fitDiagnostics_Tight.root")
fit_s->Print()
fit_s->correlation("tauId","r")
EOF

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

wps=("Loose" "Medium" "Tight" "VLooseMva2017v2" "LooseMva2017v2" "MediumMva2017v2" "TightMva2017v2" "VTightMva2017v2" "VVTightMva2017v2") 

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