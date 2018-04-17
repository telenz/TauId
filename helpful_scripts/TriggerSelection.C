#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include "settings.h"
#include "TStyle.h"
#include "THStack.h"
#include "TLegend.h"

void TriggerSelection() {

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  initCuts();

  std::vector< std::pair<TString,std::vector<TString>> > samples;
  std::vector<TString> data;
  data.push_back("SingleMuon_Run2017");

  std::vector<TString> WToMuNu;
  WToMuNu.push_back("WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  WToMuNu.push_back("W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  WToMuNu.push_back("W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  WToMuNu.push_back("W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  WToMuNu.push_back("W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");

  std::vector<TString> ewk;
  ewk.push_back("WW_TuneCP5_13TeV-pythia8");
  ewk.push_back("WZ_TuneCP5_13TeV-pythia8");
  ewk.push_back("ZZ_TuneCP5_13TeV-pythia8");
  ewk.push_back("DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");
  ewk.push_back("ZJetsToNuNu_HT-100To200_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-200To400_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-400To600_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-600To800_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-800To1200_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-1200To2500_13TeV-madgraph");
  ewk.push_back("ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph");

  std::vector<TString> tt;
  tt.push_back("TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8");
  tt.push_back("TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8");
  tt.push_back("TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8");
  tt.push_back("ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8");
  tt.push_back("ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8");
  tt.push_back("ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8");
  tt.push_back("ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8");

  samples.push_back(make_pair("data_obs" , data));
  samples.push_back(make_pair("W" , WToMuNu));
  samples.push_back(make_pair("EWK" , ewk));
  samples.push_back(make_pair("TT" , tt));

  // Needed for stitching
  double xsecIncl = xsecs["WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsec1Jet = xsecs["W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsec2Jet = xsecs["W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsec3Jet = xsecs["W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsec4Jet = xsecs["W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double nevtsProcessedIncl = getNEventsProcessed(dir+"WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessed1Jet = getNEventsProcessed(dir+"W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessed2Jet = getNEventsProcessed(dir+"W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessed3Jet = getNEventsProcessed(dir+"W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessed4Jet = getNEventsProcessed(dir+"W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");

  THStack *stack = new THStack("stack_met","");
  TH1D* h_data = 0;
  std::map<TString,TH1D*> histoMap;

  for (unsigned int i=0; i<samples.size(); ++i) {
    
    cout<<"Process "<<samples[i].first<<endl;
    
    TH1D* histoSamples = new TH1D(samples[i].first,"",10,0,1000);
    
    for(unsigned int idx_list=0; idx_list<samples[i].second.size(); idx_list++){


      TH1D* histo = new TH1D(samples[i].second[idx_list],samples[i].second[idx_list],10,0,1000);

      TString filename = dir+samples[i].second[idx_list]+".root";
      TFile * file = new TFile(filename);
      if(!file)	cout<<"The following tree does not exit: "<<filename<<" .   Please Check."<<endl;

      TTreeReader *myReader = new TTreeReader("TriggerNTuple",file);
      
      TTreeReaderValue< Float_t >  mhtNoMu(          *myReader,       "mhtNoMu");
      TTreeReaderValue< Float_t >  metNoMu(          *myReader,       "metNoMu");
      TTreeReaderValue< Float_t >  mht(              *myReader,       "mht");
      TTreeReaderValue< Float_t >  met(              *myReader,       "met");
      TTreeReaderValue< Bool_t  >  IsW(              *myReader,       "IsW");
      TTreeReaderValue< Bool_t  >  trigger(          *myReader,       "trigger");
      TTreeReaderValue< UInt_t  >  npartons(         *myReader,       "npartons");
      TTreeReaderValue< Float_t >  mtmuon(           *myReader,       "mtmuon");
      TTreeReaderValue< Float_t >  muonPt(           *myReader,       "muonPt");
      TTreeReaderValue< Float_t >  muonEta(          *myReader,       "muonEta");
      TTreeReaderValue< Float_t >  dPhiMetMuon(      *myReader,       "dPhiMetMuon");

      cout<<".............. Sample : "<<samples[i].second[idx_list]<<endl;
      
      bool isData = filename.Contains("SingleMuon") || filename.Contains("JetHT") || filename.Contains("MET");
      int nevtsProcessed = getNEventsProcessed(filename);
      double xsec        = getXSec(samples[i].second[idx_list]);
      double norm        = xsec*luminosity/nevtsProcessed;
      if(isData) norm = 1;

      while(myReader->Next()){

	//if(*IsW != true)   continue; // this includes an mtmuon cut of 40GeV
	//if(*mtmuon < 50)   continue;
	
	if(samples[i].first.EqualTo("W") && samples[i].second.size()>1){
	  if(*npartons == 0)      norm=luminosity/( nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 1) norm=luminosity/( nevtsProcessed1Jet/xsec1Jet + nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 2) norm=luminosity/( nevtsProcessed2Jet/xsec2Jet + nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 3) norm=luminosity/( nevtsProcessed3Jet/xsec3Jet + nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 4) norm=luminosity/( nevtsProcessed4Jet/xsec4Jet + nevtsProcessedIncl/xsecIncl );
	  else                    norm=luminosity/( nevtsProcessedIncl/xsecIncl );
	}
	
	double weight = norm;
	
	// CUTS

	if(*mht < 120 )        continue;
	if(*muonPt < 30)       continue;
	if(*dPhiMetMuon > 1.5) continue;

	//if(*trigger != true)   continue;

	histo -> Fill( *met, weight );
      }

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
  CMS_lumi(upper,4,33); 
  leg->Draw("same");

  TH1D * ratioH = 0;
  if(h_data){
    ratioH = (TH1D*) h_data->Clone("ratioH");
    ratioH->Divide((TH1D*)stack->GetStack()->Last());
    ratioH->GetYaxis()->SetTitle("Obs./Exp.");
    ratioH->GetXaxis()->SetTitle("MET [GeV]");
    //ratioH->GetXaxis()->SetTitle(var);
    ratioH->GetXaxis()->SetTitleOffset(3.5);
    ratioH->GetYaxis()->SetNdivisions(505);
    ratioH->GetYaxis()->SetRangeUser(0.4,1.6);
    ratioH->GetYaxis()->CenterTitle();
    ratioH->GetXaxis()->SetLabelSize(30);
  }

  canv->cd();
  TPad * lower = new TPad("lower", "pad",0,0,1,0.31);
  lower->SetBottomMargin(0.32);
  lower->SetGridy();
  lower->Draw();
  lower->cd();
  if(h_data) ratioH->Draw("e1");
  canv->cd();
  canv->Modified();
  canv->SetSelected(canv);
  canv->Update();
  canv->Print("figures/MET_Trigger.pdf");


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
  TFile *out = new TFile("output/MET_Trigger.root","RECREATE");
  out->cd();

  map<TString,TH1D*>::iterator it;
  for ( it = histoMap.begin(); it != histoMap.end(); it++ )
    {
      histoMap[it->first]    ->Write(it->first);
    }    
}
