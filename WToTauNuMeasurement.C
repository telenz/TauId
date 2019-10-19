#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include "settings.h"
#include "TStyle.h"
#include "THStack.h"
#include "TLegend.h"
#include "TColor.h"

void WToTauNuMeasurement() {

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  loadWorkingPoints();
  initCuts();
  loadFakeRates("output/fakerates" + tauDecayMode + ".root");
  loadkFactors(kfactor_tau_file);

  for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){

    std::vector< std::pair<TString,std::vector<TString>> > samples;
    std::vector<TString> data_MET = MET_sample;
    std::vector<TString> trueTaus = DYJets_sample;
    trueTaus.insert( trueTaus.end(), TT_ST_sample.begin(), TT_ST_sample.end() );
    trueTaus.insert( trueTaus.end(), VV_sample.begin()   , VV_sample.end() );
    std::vector<TString> fakeTaus = MET_sample;
    std::vector<TString> WToTauNu = WToTauNu_sample;

    // Uncertainty samples
    std::vector<TString> WToTauNu_jesUp;
    for(auto x : WToTauNu) WToTauNu_jesUp.push_back(x + "_jesUp");
    std::vector<TString> WToTauNu_jesDown;
    for(auto x : WToTauNu) WToTauNu_jesDown.push_back(x + "_jesDown");
    std::vector<TString> WToTauNu_taues_1prong0pizerosUp;
    for(auto x : WToTauNu) WToTauNu_taues_1prong0pizerosUp.push_back(x + "_taues_1prong0pizerosUp");
    std::vector<TString> WToTauNu_taues_1prong0pizerosDown;
    for(auto x : WToTauNu) WToTauNu_taues_1prong0pizerosDown.push_back(x + "_taues_1prong0pizerosDown");
    std::vector<TString> WToTauNu_taues_1prongUpTo4pizerosUp;
    for(auto x : WToTauNu) WToTauNu_taues_1prongUpTo4pizerosUp.push_back(x + "_taues_1prongUpTo4pizerosUp");
    std::vector<TString> WToTauNu_taues_1prongUpTo4pizerosDown;
    for(auto x : WToTauNu) WToTauNu_taues_1prongUpTo4pizerosDown.push_back(x + "_taues_1prongUpTo4pizerosDown");
    std::vector<TString> WToTauNu_taues_3prong0pizerosUp;
    for(auto x : WToTauNu) WToTauNu_taues_3prong0pizerosUp.push_back(x + "_taues_3prong0pizerosUp");
    std::vector<TString> WToTauNu_taues_3prong0pizerosDown;
    for(auto x : WToTauNu) WToTauNu_taues_3prong0pizerosDown.push_back(x + "_taues_3prong0pizerosDown");
    std::vector<TString> WToTauNu_uesUp;
    for(auto x : WToTauNu) WToTauNu_uesUp.push_back(x + "_uesUp");
    std::vector<TString> WToTauNu_uesDown;
    for(auto x : WToTauNu) WToTauNu_uesDown.push_back(x + "_uesDown");

    for(int i=1; i<=h_fakerate->at(iso[idx_iso]).GetNbinsX(); i++){
      for(int j=1; j<=h_fakerate->at(iso[idx_iso]).GetNbinsY(); j++){
	std::vector<TString> fakeTaus_FRUp = MET_sample;
	std::vector<TString> fakeTaus_FRDown = MET_sample;
	samples.push_back(make_pair(Form("FakeTaus_FR%i%iUp",i,j) , fakeTaus_FRUp));
	samples.push_back(make_pair(Form("FakeTaus_FR%i%iDown",i,j) , fakeTaus_FRDown));
      }
    }
    samples.push_back(make_pair("TrueTaus" , trueTaus));
    samples.push_back(make_pair("FakeTaus" , fakeTaus));
    samples.push_back(make_pair("W" , WToTauNu));
    samples.push_back(make_pair("data_obs" , data_MET));
    samples.push_back(make_pair("W_jesUp" , WToTauNu_jesUp));
    samples.push_back(make_pair("W_jesDown" , WToTauNu_jesDown));
    samples.push_back(make_pair("W_taues_1prong0pizerosUp" , WToTauNu_taues_1prong0pizerosUp));
    samples.push_back(make_pair("W_taues_1prong0pizerosDown" , WToTauNu_taues_1prong0pizerosDown));
    samples.push_back(make_pair("W_taues_1prongUpTo4pizerosUp" , WToTauNu_taues_1prongUpTo4pizerosUp));
    samples.push_back(make_pair("W_taues_1prongUpTo4pizerosDown" , WToTauNu_taues_1prongUpTo4pizerosDown));
    samples.push_back(make_pair("W_taues_3prong0pizerosUp" , WToTauNu_taues_3prong0pizerosUp));
    samples.push_back(make_pair("W_taues_3prong0pizerosDown" , WToTauNu_taues_3prong0pizerosDown));
    samples.push_back(make_pair("W_uesUp" , WToTauNu_uesUp));
    samples.push_back(make_pair("W_uesDown" , WToTauNu_uesDown));

    if(tau_pt_low == 100 && tau_pt_high == 150)      mttau_bins  = mttau_bins_ptbin1;
    else if(tau_pt_low == 150 && tau_pt_high == 200) mttau_bins  = mttau_bins_ptbin2;
    else if(tau_pt_low == 200 )                      mttau_bins  = mttau_bins_ptbin3;

    TString var1 = "mttau";
    TString var2 = var1;
    TString var3 = "tauPt";
    TString var4 = var3;

    const int nBins = mttau_bins.size() - 1;


    cout<<endl<<endl<<"--------------------------------------  "<<iso[idx_iso]<<"  ------------------------------------"<<endl;

    THStack *stack = new THStack(iso[idx_iso],"");

    TH1D* h_data = 0;
    TH1D* h_data_tauPt = 0;

    std::map<TString,TH1D*> histoMap;
    std::map<TString,TH1D*> histoMap_tauPt;

    for (unsigned int i=0; i<samples.size(); ++i) {

      cout<<"Process "<<samples[i].first<<endl;

      TH1D* histoSamples = new TH1D(samples[i].first + "_" + iso[idx_iso],"",nBins,&mttau_bins[0]);
      TH1D* histoSamples_tauPt = new TH1D(samples[i].first + "_" + iso[idx_iso]+"_tauPt","",100,100,1000);

      for(unsigned int idx_list=0; idx_list<samples[i].second.size(); idx_list++){

	cout<<".............. Sample : "<<samples[i].second[idx_list]<<endl;

	TH1D* histo = new TH1D(samples[i].second[idx_list],samples[i].second[idx_list],nBins,&mttau_bins[0]);
        TH1D* histo_tauPt = new TH1D(samples[i].second[idx_list]+"_tauPt",samples[i].second[idx_list]+"_tauPt",100,100,1000);

	selectionCuts select = sr_trueTaus;
	if( samples[i].first.Contains("FakeTaus") ){
	  select =  cr_antiiso;
	  select.name = "cr_antiiso_" + samples[i].first(11,samples[i].first.Length()); 
	}
	makeSelection(dir+"/"+samples[i].second[idx_list]+".root","NTuple",getXSec(samples[i].second[idx_list]),iso[idx_iso],select,histo,var1,var2,var2);
   makeSelection(dir+"/"+samples[i].second[idx_list]+".root","NTuple",getXSec(samples[i].second[idx_list]),iso[idx_iso],select,histo_tauPt,var3,var4,var4);

	histoSamples->Add(histo);
        histoSamples_tauPt->Add(histo_tauPt);
	histoSamples->SetName(histo->GetName());
	histoSamples->SetFillStyle(1001);
	if(samples[i].first.Contains("FakeTaus")) histoSamples->SetFillColor(TColor::GetColor("#FFCCFF"));
	else if(samples[i].first.Contains("TrueTaus")) histoSamples->SetFillColor(TColor::GetColor("#6F2D35"));
	else if(samples[i].first.Contains("W")) histoSamples->SetFillColor(TColor::GetColor("#FFCC66"));
	delete histo;
        delete histo_tauPt;
      }

      histoMap[samples[i].first] = histoSamples;
      histoMap_tauPt[samples[i].first] = histoSamples_tauPt;
      if(!samples[i].first.Contains("data_obs") && !samples[i].first.Contains("Up") && !samples[i].first.Contains("Down")){
	stack->Add(histoSamples);
      }
      else if(samples[i].first.Contains("data_obs")){
	h_data = (TH1D*) histoSamples->Clone();
   h_data_tauPt = (TH1D*) histoSamples_tauPt->Clone();
	h_data -> SetDirectory(0);
   h_data_tauPt -> SetDirectory(0);
      }
      cout<<samples[i].first<<" = "<<histoSamples->Integral()<<" ( Entries = "<<histoSamples->GetEntries()<<" ) "<<endl<<endl;
    }
    cout<<"mean pt Data : "<<h_data_tauPt->GetMean(1)<<std::endl;
    // ------------------ Computation of all uncertainties : START  -------
    TH1D * bkgdErr = (TH1D*)stack->GetStack()->Last()->Clone("bkgdErr");
    bkgdErr->SetFillStyle(3013);
    bkgdErr->SetFillColor(1);
    bkgdErr->SetMarkerStyle(21);
    bkgdErr->SetMarkerSize(0);
    double addErr = 0;
    for(int i=1; i<=bkgdErr->GetNbinsX(); i++){
      // 1.) Uncertainty on JES, TauES, UES
      if( histoMap.find("W_jesUp") != histoMap.end() ){
	addErr = histoMap["W_jesUp"]->GetBinContent(i) - histoMap["W"]->GetBinContent(i);
	bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
      }
      if( histoMap.find("W_taues_1prong0pizerosUp") != histoMap.end() ){
	addErr = histoMap["W_taues_1prong0pizerosUp"]->GetBinContent(i) - histoMap["W"]->GetBinContent(i);
	bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
      }
      if( histoMap.find("W_taues_1prongUpTo4pizerosUp") != histoMap.end() ){
	addErr = histoMap["W_taues_1prongUpTo4pizerosUp"]->GetBinContent(i) - histoMap["W"]->GetBinContent(i);
	bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
      }
      if( histoMap.find("W_taues_3prong0pizerosUp") != histoMap.end() ){
	addErr = histoMap["W_taues_3prong0pizerosUp"]->GetBinContent(i) - histoMap["W"]->GetBinContent(i);
	bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
      }
      if( histoMap.find("W_uesUp") != histoMap.end() ){
	addErr = histoMap["W_uesUp"]->GetBinContent(i) - histoMap["W"]->GetBinContent(i);
	bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
      }
      // 2.) Tau normalization uncertainty
      addErr = 0.3*histoMap["TrueTaus"]->GetBinContent(i);
      bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
      // 3.) Fake rate uncertainty
      map<TString,TH1D*>::iterator it;
      for ( it = histoMap.begin(); it != histoMap.end(); it++ )
	{
	  if(it->first.Contains("FR") && it->first.Contains("Up")){
	    addErr = it->second->GetBinContent(i) - histoMap["FakeTaus"]->GetBinContent(i);
	    bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
	  }
	}
    }
    // ------------------ Computation of all uncertainties : END  -------
    TCanvas * canv = new TCanvas("canv","",700,800);
    TPad* upper = new TPad("upper","pad",0,0.19,1,1);
    upper->Draw();
    upper->cd();
    //upper->SetLogy();

    if(stack->GetMaximum()>h_data->GetMaximum()){    
      h_data->SetMaximum(stack->GetMaximum()*1.2);
    }
    h_data->GetXaxis()->SetTitle("");
    h_data->GetYaxis()->SetTitle("Events");
    h_data->GetXaxis()->SetLabelSize(0.);
    //h_data->SetMaximum(1400);
    h_data->Draw("e1");
    stack->Draw("hist same");
    gPad->Modified(); 
    if(h_data){
      h_data->Draw("e1 same");
      bkgdErr->Draw("e2same");
    }

    TLegend * leg = new TLegend(0.56,0.49,0.83,0.83);
    SetLegendStyle(leg);
    leg->SetHeader(iso[idx_iso]);
    if(h_data)               leg->AddEntry(h_data,"Data","lp");
    if(histoMap["W"])        leg->AddEntry(histoMap["W"],"W#rightarrow#tau#nu","f");
    if(histoMap["FakeTaus"]) leg->AddEntry(histoMap["FakeTaus"],"bkgd (fake taus)","f");
    if(histoMap["TrueTaus"]) leg->AddEntry(histoMap["TrueTaus"],"bkgd (true taus)","f");
    writeExtraText = true;
    extraText = "Preliminary";
    CMS_lumi(upper,iPeriod,33);
    leg->Draw("same");

    TH1D * ratioH = 0;
    if(h_data){
      ratioH = (TH1D*) h_data->Clone("ratioH");
      ratioH->Divide((TH1D*)stack->GetStack()->Last());
      ratioH->GetYaxis()->SetTitle("Obs./Exp.");
      //ratioH->GetXaxis()->SetTitle("m_{T} [GeV]");
      //ratioH->GetXaxis()->SetTitle("p_{T}^{#tau} [GeV]");
      ratioH->GetXaxis()->SetTitle(h_data->GetName());
      ratioH->GetXaxis()->SetTitleOffset(3.5);
      ratioH->GetYaxis()->SetNdivisions(505);
      ratioH->GetYaxis()->SetRangeUser(0.4,1.6);
      ratioH->GetYaxis()->CenterTitle();
      ratioH->GetXaxis()->SetLabelSize(30);
    }
    TH1D * ratioErrH = (TH1D*)bkgdErr->Clone("ratioErrH");
    for(int i=1; i<=bkgdErr->GetNbinsX(); i++){
      ratioErrH->SetBinError(i,bkgdErr->GetBinError(i)/bkgdErr->GetBinContent(i));
      if(bkgdErr->GetBinContent(i)==0) ratioErrH->SetBinError(i,0);
      ratioErrH->SetBinContent(i,1);
    }
    ratioErrH->SetFillStyle(3013);
    ratioErrH->SetFillColor(1);
    ratioErrH->SetMarkerStyle(21);
    ratioErrH->SetMarkerSize(0);  

    canv->cd();
    TPad * lower = new TPad("lower", "pad",0,0.0,1,0.31);
    lower->SetBottomMargin(0.32);
    lower->SetGridy();
    lower->Draw();
    lower->cd();
    if(h_data) ratioH->Draw("e1");
    ratioErrH->Draw("e2 same");
    //ratioErrH->Draw("same");
    canv->cd();
    canv->Modified();
    canv->SetSelected(canv);
    canv->Update();
    canv->Print("figures/" + (TString) h_data->GetName() + "_" + iso[idx_iso] + "_WToTauNu" + tauDecayMode + "_prefit.png");

    // Get bin-by-bin uncertainties for WTauNu
    TH1D* histo = 0;
    for(int i =1; i<=histoMap["W"]->GetNbinsX(); i++){
      histo = (TH1D*) histoMap["W"]->Clone();
      histo->SetBinContent(i,histoMap["W"]->GetBinContent(i)+histoMap["W"]->GetBinError(i));
      histo->SetName(Form("W_Bin%i_WToTauNuUp",i));
      histoMap[histo->GetName()] = histo;
      histo = (TH1D*) histoMap["W"]->Clone();
      histo->SetBinContent(i,histoMap["W"]->GetBinContent(i)-histoMap["W"]->GetBinError(i));
      histo->SetName(Form("W_Bin%i_WToTauNuDown",i));
      histoMap[histo->GetName()] = histo;
    }
    for(int i =1; i<=histoMap["FakeTaus"]->GetNbinsX(); i++){
      histo = (TH1D*) histoMap["FakeTaus"]->Clone();
      histo->SetBinContent(i,histoMap["FakeTaus"]->GetBinContent(i)+histoMap["FakeTaus"]->GetBinError(i));
      histo->SetName(Form("FakeTaus_Bin%i_FakeTausUp",i));
      histoMap[histo->GetName()] = histo;
      histo = (TH1D*) histoMap["FakeTaus"]->Clone();
      histo->SetBinContent(i,histoMap["FakeTaus"]->GetBinContent(i)-histoMap["FakeTaus"]->GetBinError(i));
      histo->SetName(Form("FakeTaus_Bin%i_FakeTausDown",i));
      histoMap[histo->GetName()] = histo;
    }
    for(int i =1; i<=histoMap["TrueTaus"]->GetNbinsX(); i++){
      histo = (TH1D*) histoMap["TrueTaus"]->Clone();
      histo->SetBinContent(i,histoMap["TrueTaus"]->GetBinContent(i)+histoMap["TrueTaus"]->GetBinError(i));
      histo->SetName(Form("TrueTaus_Bin%i_TrueTausUp",i));
      histoMap[histo->GetName()] = histo;
      histo = (TH1D*) histoMap["TrueTaus"]->Clone();
      histo->SetBinContent(i,histoMap["TrueTaus"]->GetBinContent(i)-histoMap["TrueTaus"]->GetBinError(i));
      histo->SetName(Form("TrueTaus_Bin%i_TrueTausDown",i));
      histoMap[histo->GetName()] = histo;
    }

    // Save all histograms in one file
    TFile *out = new TFile("output/" + (TString) h_data->GetName() + "_" + iso[idx_iso] + "_WToTauNu_shapes" + tauDecayMode + ".root","RECREATE");
    out->cd();

    map<TString,TH1D*>::iterator it;
    for ( it = histoMap.begin(); it != histoMap.end(); it++ )
      {
	histoMap[it->first] -> SetName(it->first);
	histoMap[it->first] -> Write(it->first);
      }    

    TFile *out_tauPt = new TFile("output/tauPt_" + iso[idx_iso] + tauDecayMode + ".root","RECREATE");
    out_tauPt->cd();
    for ( it = histoMap_tauPt.begin(); it != histoMap_tauPt.end(); it++ )
      {
         if (it->first.Contains("data")){
            histoMap_tauPt[it->first] -> SetName(it->first);
            histoMap_tauPt[it->first] -> Write(it->first);
         }
      }
    delete canv;
  }
}
