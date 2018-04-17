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
  samples.push_back(make_pair("MET_Data" , data_MET));

  TH1D* histo[2] = {0};  
  const int nBins  = 1;
  float bins[nBins+1] = {100,1200};  // tauPt binning

  for (unsigned int i=0; i<samples.size(); ++i) {

    // filling histograms
    histo[i]  = new TH1D("h_" + samples[i].first,"",nBins,bins); 

    TString var = "tauPt";
    for(unsigned int idx_list=0; idx_list<samples[i].second.size(); idx_list++){
      cout<<"---------- Processing ... "<<samples[i].second[idx_list]<<" ---------- "<<endl;

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

  std::cout << std::endl;
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
  double *fraction     = new double[h_fEWK->GetNbinsX()];
  double *fraction_err = new double[h_fEWK->GetNbinsX()];
  for(int i=0; i<h_fEWK->GetNbinsX(); i++){
    fraction[i]     = h_fEWK->GetBinContent(i+1);
    fraction_err[i] = h_fEWK->GetBinError(i+1);
  }

  // Read single fake rates
  TFile *DataFileJetHT         = new TFile("output/JetHT_fakeRate.root");
  TFile *DataFileJetHT_Up      = new TFile("output/JetHT_fakeRate_Up.root");
  TFile *DataFileJetHT_Down    = new TFile("output/JetHT_fakeRate_Down.root");
  TFile *DataFileSingleMu      = new TFile("output/SingleMuon_fakeRate.root");
  TFile *DataFileSingleMu_Up   = new TFile("output/SingleMuon_fakeRate_Up.root");
  TFile *DataFileSingleMu_Down = new TFile("output/SingleMuon_fakeRate_Down.root");

  TFile* out_FakeRates      = new TFile("output/fakerates.root","RECREATE");
  TFile* out_FakeRates_Up   = new TFile("output/fakerates_Up.root","RECREATE");
  TFile* out_FakeRates_Down = new TFile("output/fakerates_Down.root","RECREATE");

  for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){

    if( !(DataFileJetHT->GetListOfKeys()->Contains(iso[idx_iso])) ) continue;

    TH2D *effJetHT         = (TH2D*) DataFileJetHT->Get(iso[idx_iso]);
    TH2D *effJetHT_Up      = (TH2D*) DataFileJetHT_Up->Get(iso[idx_iso]);
    TH2D *effJetHT_Down    = (TH2D*) DataFileJetHT_Down->Get(iso[idx_iso]);
    TH2D *effSingleMu      = (TH2D*) DataFileSingleMu->Get(iso[idx_iso]);
    TH2D *effSingleMu_Up   = (TH2D*) DataFileSingleMu_Up->Get(iso[idx_iso]);
    TH2D *effSingleMu_Down = (TH2D*) DataFileSingleMu_Down->Get(iso[idx_iso]);
    TH2D *effCombined      = (TH2D*) effJetHT->Clone();
    TH2D *effCombined_Up   = (TH2D*) effJetHT_Up->Clone();
    TH2D *effCombined_Down = (TH2D*) effJetHT_Down->Clone();

    for(int i=1; i<=effJetHT->GetNbinsX(); i++){
      for(int j=1; j<=effJetHT->GetNbinsY(); j++){

	double FFJetHT            = effJetHT->GetBinContent(i,j);
	double FFJetHTErr_Up      = effJetHT_Up->GetBinContent(i,j) - effJetHT->GetBinContent(i,j);
	double FFJetHTErr_Down    = effJetHT->GetBinContent(i,j) - effJetHT_Down->GetBinContent(i,j);
	double FFSingleMu         = effSingleMu->GetBinContent(i,j);
	double FFSingleMuErr_Up   = effSingleMu_Up->GetBinContent(i,j) - effSingleMu->GetBinContent(i,j);
	double FFSingleMuErr_Down = effSingleMu->GetBinContent(i,j) - effSingleMu_Down->GetBinContent(i,j);

	double comb = (1-fraction[0])*FFJetHT+fraction[0]*FFSingleMu;
	double combErr_Up   = sqrt( pow(FFSingleMu-FFJetHT,2)*pow(fraction_err[0],2) + pow(fraction[0],2)*(pow(FFSingleMuErr_Up,2) + pow(FFJetHTErr_Up,2)) );
	double combErr_Down = sqrt( pow(FFSingleMu-FFJetHT,2)*pow(fraction_err[0],2) + pow(fraction[0],2)*(pow(FFSingleMuErr_Down,2) + pow(FFJetHTErr_Down,2)) );
	if(combErr_Down > comb) combErr_Down = comb;

	effCombined      -> SetBinContent(i , j , comb);
	effCombined      -> SetBinError(i , j , 0);
	effCombined_Up   -> SetBinContent(i , j , comb+combErr_Up);
	effCombined_Up   -> SetBinError(i , j , 0);
	effCombined_Down -> SetBinContent(i , j , comb-combErr_Down);
	effCombined_Down -> SetBinError(i , j , 0);
      }
    }

    cout<<"Used EWK fraction = "<<fraction[0]<<endl;

    out_FakeRates       -> cd();
    effCombined         -> SetName(iso[idx_iso]);
    effCombined         -> Write(iso[idx_iso]);
    out_FakeRates_Up    -> cd();
    effCombined_Up      -> SetName(iso[idx_iso]);
    effCombined_Up      -> Write(iso[idx_iso]);
    out_FakeRates_Down  -> cd();
    effCombined_Down    -> SetName(iso[idx_iso]);
    effCombined_Down    -> Write(iso[idx_iso]);
  }

}
