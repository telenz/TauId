#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include "settings.h"
#include "TStyle.h"
#include "THStack.h"
#include "TLegend.h"

void WToMuNuMeasurement() {

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  initCuts();
  loadkFactors(kfactor_mu_file);

  std::vector< std::pair<TString,std::vector<TString>> > samples;

  std::vector<TString> data    = SingleMuon_sample;
  std::vector<TString> ewk     = ZJets_sample;
  ewk.insert( ewk.end(), DYJets_sample.begin(), DYJets_sample.end() );
  ewk.insert( ewk.end(), VV_sample.begin(), VV_sample.end() );
  std::vector<TString> tt      = TT_ST_sample;
  std::vector<TString> WToMuNu = WToMuNu_sample;

  // Uncertainty samples
  std::vector<TString> WToMuNu_jesUp;
  for(auto x : WToMuNu) WToMuNu_jesUp.push_back(x + "_jesUp");
  std::vector<TString> WToMuNu_jesDown;
  for(auto x : WToMuNu) WToMuNu_jesDown.push_back(x + "_jesDown");
  std::vector<TString> WToMuNu_muUp;
  for(auto x : WToMuNu) WToMuNu_muUp.push_back(x + "_muUp");
  std::vector<TString> WToMuNu_muDown;
  for(auto x : WToMuNu) WToMuNu_muDown.push_back(x + "_muDown");
  std::vector<TString> WToMuNu_uesUp;
  for(auto x : WToMuNu) WToMuNu_uesUp.push_back(x + "_uesUp");
  std::vector<TString> WToMuNu_uesDown;
  for(auto x : WToMuNu) WToMuNu_uesDown.push_back(x + "_uesDown");

  samples.push_back(make_pair("data_obs" , data));
  samples.push_back(make_pair("EWK" , ewk));
  samples.push_back(make_pair("TT" , tt));
  samples.push_back(make_pair("W" , WToMuNu));
  samples.push_back(make_pair("W_jesUp" , WToMuNu_jesUp));
  samples.push_back(make_pair("W_jesDown" , WToMuNu_jesDown));
  samples.push_back(make_pair("W_muUp" , WToMuNu_muUp));
  samples.push_back(make_pair("W_muDown" , WToMuNu_muDown));
  samples.push_back(make_pair("W_uesUp" , WToMuNu_uesUp));
  samples.push_back(make_pair("W_uesDown" , WToMuNu_uesDown));

  TString var = "mtmuon";
  const int nbins = 10;
  const double x_low = 0;
  const double x_high = 1000;

  THStack *stack = new THStack("stack_mtmuon","");
  TH1D* h_data = 0;
  std::map<TString,TH1D*> histoMap;

  for (unsigned int i=0; i<samples.size(); ++i) {
    
    cout<<"Process "<<samples[i].first<<endl;
    
    TH1D* histoSamples = new TH1D(samples[i].first,"",nbins,x_low,x_high);
    
    for(unsigned int idx_list=0; idx_list<samples[i].second.size(); idx_list++){

      cout<<".............. Sample : "<<samples[i].second[idx_list]<<endl;

      TH1D* histo = new TH1D(samples[i].second[idx_list],samples[i].second[idx_list],nbins,x_low,x_high);
      selectionCuts select = sr_munu;
      makeSelection(dir+"/"+samples[i].second[idx_list]+".root","NTuple",getXSec(samples[i].second[idx_list]),"Tight",select,histo,var,var,var);
      histoSamples->Add(histo);
      histoSamples->SetFillStyle(1001);
      if(samples[i].first.Contains("TT"))       histoSamples->SetFillColor(TColor::GetColor("#FFCCFF"));
      else if(samples[i].first.Contains("EWK")) histoSamples->SetFillColor(TColor::GetColor("#6F2D35"));
      else if(samples[i].first.Contains("W"))   histoSamples->SetFillColor(TColor::GetColor("#FFCC66"));
    }

    histoMap[samples[i].first] = histoSamples;
    if(!samples[i].first.Contains("data_obs") && !samples[i].first.Contains("Up") && !samples[i].first.Contains("Down")){
      stack->Add(histoSamples);
    }
    else if(samples[i].first.Contains("data_obs")) h_data = (TH1D*) histoSamples->Clone(); 
    cout<<samples[i].first<<" = "<<histoSamples->GetSumOfWeights()<<" ( Entries = "<<histoSamples->GetEntries()<<" )"<<endl<<endl;
  }

  // ------------------ Computation of all uncertainties : START  -------
  TH1D * bkgdErr = (TH1D*)stack->GetStack()->Last()->Clone("bkgdErr");
  bkgdErr->SetFillStyle(3013);
  bkgdErr->SetFillColor(1);
  bkgdErr->SetMarkerStyle(21);
  bkgdErr->SetMarkerSize(0);  
  double addErr = 0;
  for(int i=1; i<=bkgdErr->GetNbinsX(); i++){
    // 1.) Uncertainty on JES, Mu, UES
    bool WjesUpExists = histoMap.find("W_jesUp") != histoMap.end();
    if(WjesUpExists){
      addErr = histoMap["W_jesUp"]->GetBinContent(i) - histoMap["W"]->GetBinContent(i);
      bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
    }
    bool WmuUpExists = histoMap.find("W_muUp") != histoMap.end();
    if(WmuUpExists){
      addErr = histoMap["W_muUp"]->GetBinContent(i) - histoMap["W"]->GetBinContent(i);
      bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
    }
    bool WuesUpExists = histoMap.find("W_uesUp") != histoMap.end();
    if(WuesUpExists){
      addErr = histoMap["W_uesUp"]->GetBinContent(i) - histoMap["W"]->GetBinContent(i);
      bkgdErr->SetBinError(i,sqrt( pow(bkgdErr->GetBinError(i),2) + pow(addErr,2)));
    }
  }
  // ------------------ Computation of all uncertainties : END  -------

  TCanvas * canv = new TCanvas("canv","",700,800);
  TPad* upper = new TPad("upper","pad",0,0.19,1,1);
  upper->Draw();
  upper->cd();
  //upper->SetLogy();

  stack->Draw("hist");
  stack->SetMaximum(stack->GetMaximum()*1.2);
  stack->GetXaxis()->SetTitle("");
  stack->GetYaxis()->SetTitle("Events");
  stack->GetXaxis()->SetLabelSize(0.);
  gPad->Modified(); 
  if(h_data){
    h_data->Draw("e1 same");
    bkgdErr->Draw("e2same");
  }

  TLegend * leg = new TLegend(0.55,0.4,0.85,0.78);
  SetLegendStyle(leg);
  leg->SetTextSize(0.047);
  if(h_data)          leg->AddEntry(h_data,"Data","lp");
  if(histoMap["W"])   leg->AddEntry(histoMap["W"],"W#rightarrow#mu#nu","f");
  if(histoMap["TT"])  leg->AddEntry(histoMap["TT"],"tt + single top","f");
  if(histoMap["EWK"]) leg->AddEntry(histoMap["EWK"],"electroweak","f");
  writeExtraText = true;
  extraText = "Internal";
  CMS_lumi(upper,iPeriod,33);
  leg->Draw("same");

  TH1D * ratioH = 0;
  if(h_data){
    ratioH = (TH1D*) h_data->Clone("ratioH");
    ratioH->Divide((TH1D*)stack->GetStack()->Last());
    ratioH->GetYaxis()->SetTitle("Obs./Exp.");
    //ratioH->GetXaxis()->SetTitle("m_{T} [GeV]");
    ratioH->GetXaxis()->SetTitle(var);
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
  TPad * lower = new TPad("lower", "pad",0,0,1,0.31);
  lower->SetBottomMargin(0.32);
  lower->SetGridy();
  lower->Draw();
  lower->cd();
  if(h_data) ratioH->Draw("e1");
  ratioErrH->Draw("e2 same");
  canv->cd();
  canv->Modified();
  canv->SetSelected(canv);
  canv->Update();
  canv->Print("figures/" + var + "_WToMuNu.pdf");
  canv->Print("figures/" + var + "_WToMuNu.png");


  // Get bin-by-bin uncertainties for WMuNu
  TH1D* histo = 0;
  for(int i =1; i<=histoMap["W"]->GetNbinsX(); i++){
    histo = (TH1D*) histoMap["W"]->Clone();
    histo->SetBinContent(i,histoMap["W"]->GetBinContent(i)+histoMap["W"]->GetBinError(i));
    histo->SetName(Form("W_Bin%i_WToMuNuUp",i));
    histoMap[histo->GetName()] = histo;
    histo = (TH1D*) histoMap["W"]->Clone();
    histo->SetBinContent(i,histoMap["W"]->GetBinContent(i)-histoMap["W"]->GetBinError(i));
    histo->SetName(Form("W_Bin%i_WToMuNuDown",i));
    histoMap[histo->GetName()] = histo;
  }
  for(int i =1; i<=histoMap["TT"]->GetNbinsX(); i++){
    histo = (TH1D*) histoMap["TT"]->Clone();
    histo->SetBinContent(i,histoMap["TT"]->GetBinContent(i)+histoMap["TT"]->GetBinError(i));
    histo->SetName(Form("TT_Bin%i_TTUp",i));
    histoMap[histo->GetName()] = histo;
    histo = (TH1D*) histoMap["TT"]->Clone();
    histo->SetBinContent(i,histoMap["TT"]->GetBinContent(i)-histoMap["TT"]->GetBinError(i));
    histo->SetName(Form("TT_Bin%i_TTDown",i));
    histoMap[histo->GetName()] = histo;
  }
  for(int i =1; i<=histoMap["EWK"]->GetNbinsX(); i++){
    histo = (TH1D*) histoMap["EWK"]->Clone();
    histo->SetBinContent(i,histoMap["EWK"]->GetBinContent(i)+histoMap["EWK"]->GetBinError(i));
    histo->SetName(Form("EWK_Bin%i_EWKUp",i));
    histoMap[histo->GetName()] = histo;
    histo = (TH1D*) histoMap["EWK"]->Clone();
    histo->SetBinContent(i,histoMap["EWK"]->GetBinContent(i)-histoMap["EWK"]->GetBinError(i));
    histo->SetName(Form("EWK_Bin%i_EWKDown",i));
    histoMap[histo->GetName()] = histo;
  }

  // Save all histograms in one file
  TFile *out = new TFile("output/" + var + "_WToMuNu_shapes.root","RECREATE");
  out->cd();

  map<TString,TH1D*>::iterator it;
  for ( it = histoMap.begin(); it != histoMap.end(); it++ )
    {
      histoMap[it->first]    ->Write(it->first);
    }
}
