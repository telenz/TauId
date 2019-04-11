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
  std::vector<TString> data_MET = MET_sample;
  std::vector<TString> ewk      = WJets_sample;
  ewk.insert( ewk.end(), DYJets_sample.begin(), DYJets_sample.end() );
  ewk.insert( ewk.end(), ZJets_sample.begin() , ZJets_sample.end() );
  ewk.insert( ewk.end(), TT_ST_sample.begin() , TT_ST_sample.end() );
  ewk.insert( ewk.end(), VV_sample.begin()    , VV_sample.end() );

  samples.push_back(make_pair("EWK_MC" , ewk));
  samples.push_back(make_pair("MET_Data" , data_MET));

  TH2D* histo[2] = {0};
  TH2D* histo_norm[2] = {0};

  TH2D *effSingleMu = 0;

  // Read single fake rates
  TFile *DataFileJetHT    = new TFile("output/JetHT_fakeRate"+tauDecayMode+".root");
  TFile *DataFileSingleMu = new TFile("output/SingleMuon_fakeRate"+tauDecayMode+".root");
  TFile* out_FakeRates    = new TFile("output/fakerates"+tauDecayMode+".root","RECREATE");

  // Read binning from fake factor template
  for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){
    if(!DataFileSingleMu -> GetListOfKeys()->Contains(iso[idx_iso])){
      cout<<"Isolation working point "<<iso[idx_iso]<<" not existent in file. Exiting..."<<endl<<endl;
      exit(-1);
    }
    cout<<"Isolation working point is "<<iso[idx_iso]<<endl;
    effSingleMu = (TH2D*) DataFileSingleMu->Get(iso[idx_iso]);

    int nBinsX = effSingleMu -> GetNbinsX();
    int nBinsY = effSingleMu -> GetNbinsY();

    TString var1 = "tauPt";
    TString var2 = "tauJetPt";
    TString var3 = "tauJetPt";

    for (unsigned int i=0; i<samples.size(); ++i) {

      // filling histograms
      histo[i]       = (TH2D*) effSingleMu -> Clone("h_" + samples[i].first );
      histo_norm[i]  = (TH2D*) effSingleMu -> Clone("h_norm" + samples[i].first);
      histo[i]      -> Reset();
      histo_norm[i] -> Reset();

      for(unsigned int idx_list=0; idx_list<samples[i].second.size(); idx_list++){
	cout<<"---------- Processing ... "<<samples[i].second[idx_list]<<" ---------- "<<endl;

	// Calculate normalization factor in fakefactor region (selection=1)
	makeSelection(dir+samples[i].second[idx_list]+".root","NTuple",getXSec(samples[i].second[idx_list]),iso[idx_iso],cr_fakerate_norm,histo_norm[i],var1,var2,var3); //only very small dependence on WP, decay mode selection is applied
	makeSelection(dir+samples[i].second[idx_list]+".root","NTuple",getXSec(samples[i].second[idx_list]),iso[idx_iso],cr_ewkFraction,histo[i],var1,var2,var3);//EWK does not depend on WP, decay mode selection is applied
      }
    }

    // Calculate normalization factor and rescale MC
    double N_MC   = histo_norm[0]->Integral(0,nBinsX+1,0,nBinsY+1);
    double N_Data = histo_norm[1]->Integral(0,nBinsX+1,0,nBinsY+1);
    double norm = N_Data/N_MC;
    cout<<endl;
    cout<<"N_MC   = "<<N_MC<<endl;
    cout<<"N_Data = "<<N_Data<<endl;
    cout<<"norm   = "<<norm<<endl;
    histo[0]->Scale(norm);

    double nEWK_err;
    double nEWK  = histo[0] -> IntegralAndError(1,nBinsX,1,nBinsY,nEWK_err);
    double nData_err;
    double nData = histo[1] -> IntegralAndError(1,nBinsX,1,nBinsY,nData_err);

    TH1D *h_fEWK = (TH1D*) histo[0]->Clone();
    h_fEWK -> Divide(histo[1]);
    h_fEWK -> SetName("h_fEWK");

    // Project out tauPt/tauJetPt ratio dimension since the major dependency is only visible in taujetPt
    TH1D* histo1Dim[2] = {0};
    histo1Dim[0] = (TH1D*) histo[0] -> ProjectionY("1Dim_MC",0,nBinsX+1);
    histo1Dim[1] = (TH1D*) histo[1] -> ProjectionY("1Dim_Data",0,nBinsX+1);

    TH1D *h_fEWK_1Dim = (TH1D*) histo1Dim[0]->Clone();
    h_fEWK_1Dim -> Divide(histo1Dim[1]);
    h_fEWK_1Dim -> SetName("h_fEWK_1Dim");

    // Set fEWK to one if it is above one (and corresponding uncertainty is set to 10%)
    for(int j=1; j<=nBinsY; j++){
      if( h_fEWK_1Dim -> GetBinContent(j) > 1.0 ){
	h_fEWK_1Dim -> SetBinContent(j,1.0);
	h_fEWK_1Dim -> SetBinError(j, 1 - h_fEWK_1Dim->GetBinContent(j-1) );
      }
    }

    cout << endl;
    cout << "Fraction of electroweak events in antiisolated region (integrated over all bins) : " << endl;
    cout << "EWK (from MC)     = " << nEWK       << " +/- " << nEWK_err << endl;
    cout << "Total (from data) = " << nData      << " +/- " << nData_err << endl;
    cout << "EWK/Total         = " << nEWK/nData << " +/- " << nEWK_err/nData << endl;
    cout << endl;
    cout << "Fraction of electroweak events in antiisolated region per bin : " << endl;
    for(int j=1; j<=nBinsY; j++){
      cout << " tau jet pt bin " << j << " : ";
      cout << "fEWK 1Dim = " << h_fEWK_1Dim->GetBinContent(j) << " +/- " << h_fEWK_1Dim->GetBinError(j) << endl;
    }
    cout << endl;

    // Save fraction of EWK events in root file
    TFile* out = new TFile("output/fraction_EWK"+tauDecayMode+".root","RECREATE");
    out->cd();
    h_fEWK_1Dim->Write();

    if( !(DataFileJetHT->GetListOfKeys()->Contains(iso[idx_iso])) ) continue;

    TH2D *effJetHT         = (TH2D*) DataFileJetHT->Get(iso[idx_iso]);
    TH2D *effJetHT_Up      = (TH2D*) DataFileJetHT->Get(iso[idx_iso]+"_Up");
    TH2D *effJetHT_Down    = (TH2D*) DataFileJetHT->Get(iso[idx_iso]+"_Down");
    TH2D *effSingleMu      = (TH2D*) DataFileSingleMu->Get(iso[idx_iso]);
    TH2D *effSingleMu_Up   = (TH2D*) DataFileSingleMu->Get(iso[idx_iso]+"_Up");
    TH2D *effSingleMu_Down = (TH2D*) DataFileSingleMu->Get(iso[idx_iso]+"_Down");
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
	double fraction           = h_fEWK_1Dim -> GetBinContent(j);
	double fraction_err       = h_fEWK_1Dim -> GetBinError(j);

	double comb = (1-fraction)*FFJetHT+fraction*FFSingleMu;
	double combErr_Up   = sqrt( pow(FFSingleMu-FFJetHT,2)*pow(fraction_err,2) + pow(fraction,2)*(pow(FFSingleMuErr_Up,2) + pow(FFJetHTErr_Up,2)) );
	double combErr_Down = sqrt( pow(FFSingleMu-FFJetHT,2)*pow(fraction_err,2) + pow(fraction,2)*(pow(FFSingleMuErr_Down,2) + pow(FFJetHTErr_Down,2)) );
	if(combErr_Down > comb) combErr_Down = comb;

	effCombined      -> SetBinContent(i , j , comb);
	effCombined      -> SetBinError(i , j , 0);
	effCombined_Up   -> SetBinContent(i , j , comb+combErr_Up);
	effCombined_Up   -> SetBinError(i , j , 0);
	effCombined_Down -> SetBinContent(i , j , comb-combErr_Down);
	effCombined_Down -> SetBinError(i , j , 0);
      }
    }

    out_FakeRates       -> cd();
    effCombined         -> SetName(iso[idx_iso]);
    effCombined         -> Write(iso[idx_iso]);
    effCombined_Up      -> SetName(iso[idx_iso]+"_Up");
    effCombined_Up      -> Write(iso[idx_iso]+"_Up");
    effCombined_Down    -> SetName(iso[idx_iso]+"_Down");
    effCombined_Down    -> Write(iso[idx_iso]+"_Down");
  }
  out_FakeRates       -> Close();
}
