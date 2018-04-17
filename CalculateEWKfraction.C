#include "HttStylesNew.cc"
#include "TStyle.h"
#include "settings.h"

void CalculateEWKfraction() {

  loadWorkingPoints();
  initCuts();

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  std::vector< std::pair<TString,std::vector<TString>> > samples;
  std::vector<TString> data_MET;
  data_MET.push_back("MET_Run2017");
  std::vector<TString> ewk;
  ewk.push_back("WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  ewk.push_back("W1JetsToLNu_LHEWpT_50-150");
  ewk.push_back("W1JetsToLNu_LHEWpT_150-250");
  ewk.push_back("W1JetsToLNu_LHEWpT_250-400");
  ewk.push_back("W1JetsToLNu_LHEWpT_400-inf");
  ewk.push_back("ZJetsToNuNu_HT-100To200_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-200To400_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-400To600_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-600To800_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-800To1200_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-1200To2500_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph");
  ewk.push_back("TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8");
  ewk.push_back("TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8");
  ewk.push_back("TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8");
  ewk.push_back("ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8");
  ewk.push_back("ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8");
  ewk.push_back("ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8");
  ewk.push_back("ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8");
  ewk.push_back("ZZ_TuneCP5_13TeV-pythia8");
  ewk.push_back("WW_TuneCP5_13TeV-pythia8");
  ewk.push_back("WZ_TuneCP5_13TeV-pythia8");
  ewk.push_back("DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");
  ewk.push_back("DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");
  ewk.push_back("DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");
  ewk.push_back("DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");
  ewk.push_back("DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");

  samples.push_back(make_pair("EWK_MC" , ewk));
  samples.push_back(make_pair("MET_Run2016" , data_MET));

  TH1D* histo[2] = {0};  
  const int nBins  = 1;
  float bins[nBins+1] = {100,1000};  // tauPt binning

  for (unsigned int i=0; i<samples.size(); ++i) {

    // filling histograms
    histo[i]  = new TH1D("h_" + samples[i].first,"",nBins,bins); 

    TString var = "tauPt";
    for(unsigned int idx_list=0; idx_list<samples[i].second.size(); idx_list++){
      cout<<"---------- Sample "<<samples[i].second[idx_list]<<" processing. ---------- "<<endl;

      makeSelection(dir+samples[i].second[idx_list]+".root","NTuple",getXSec(samples[i].second[idx_list]),(TString) "VTightMva",cr_ewkFraction,histo[i],var,var,var);
    }
  }
  double nEWK_err;
  double nEWK  = histo[0] -> IntegralAndError(1,nBins,nEWK_err);
  double nData_err;
  double nData = histo[1] -> IntegralAndError(1,nBins,nData_err);
      
  TH1D *h_fEWK = (TH1D*) histo[0]->Clone();
  h_fEWK->Divide(histo[1]);
  h_fEWK->SetName("h_fEWK");
      
  std::cout << "Fraction of electroweak events in antiisolated region -> " << std::endl;
  std::cout << "EWK (from MC)     = " << nEWK       << " +/- " << nEWK_err << std::endl;
  std::cout << "Total (from data) = " << nData      << " +/- " << nData_err << std::endl;
  std::cout << "EWK/Total         = " << nEWK/nData << " +/- " << nEWK_err/nData << std::endl;
  std::cout << "  pt > 100 GeV    = " << h_fEWK->GetBinContent(1) << " +/- " << h_fEWK->GetBinError(1) << endl;
  std::cout << "  pt > 150 GeV    = " << h_fEWK->GetBinContent(2) << " +/- " << h_fEWK->GetBinError(2) << endl;
  std::cout << "  pt > 200 GeV    = " << h_fEWK->GetBinContent(3) << " +/- " << h_fEWK->GetBinError(3) << endl;
  std::cout << std::endl;
      
  // Save fraction of EWK events in root file
  TFile* out = new TFile("output/fraction_EWK.root","RECREATE");
  out->cd();
  h_fEWK->Write();
  
  // Read it again
  double *ratio  = new double[h_fEWK->GetNbinsX()];
  double *eratio = new double[h_fEWK->GetNbinsX()];
  for(int i=0; i<h_fEWK->GetNbinsX(); i++){
    ratio[i]  = h_fEWK->GetBinContent(i+1); 
    eratio[i] = h_fEWK->GetBinError(i+1); 
  }

  // Read single fake rates
  TFile *DataFileJetHT = new TFile("output/JetHT_Run2016_fakeRate.root");
  TFile *DataFileSingleMu = new TFile("output/SingleMuon_Run2016_fakeRate.root");
  
  TFile* out_FakeRates = new TFile("output/fakerates.root","RECREATE");

  cout<<endl<<endl<<"Calculation of combined fake rate"<<endl<<endl;
  for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){
    
    TH2D *effJetHT    = (TH2D*) DataFileJetHT->Get(iso[idx_iso]);
    TH2D *effSingleMu = (TH2D*) DataFileSingleMu->Get(iso[idx_iso]);
    TH2D *effCombined = (TH2D*) effJetHT->Clone();

    for(int i=1; i<=effJetHT->GetNbinsX(); i++){
      for(int j=1; j<=effJetHT->GetNbinsY(); j++){
 
	double FRJetHT       = effJetHT->GetBinContent(i,j);
	double FRJetHTErr    = effJetHT->GetBinError(i,j);
	double FRSingleMu    = effSingleMu->GetBinContent(i,j);
	double FRSingleMuErr = effSingleMu->GetBinError(i,j);

	double comb = (1-ratio[0])*FRJetHT+ratio[0]*FRSingleMu;
	double combErr = sqrt( pow(FRSingleMu-FRJetHT,2)*pow(eratio[0],2) + pow(ratio[0],2)*(pow(FRSingleMuErr,2) + pow(FRJetHTErr,2)) );

	effCombined->SetBinContent(i , j , comb);
	effCombined->SetBinError(i , j , combErr);
      }
    }

    cout<<"Used EWK fraction = "<<ratio[0]<<endl;
    
    out_FakeRates->cd();
    effCombined -> SetName(iso[idx_iso]);
    effCombined -> Write(iso[idx_iso]);
  }
}
