#include "HttStylesNew.cc"
#include "settings.h"
#include "TF1.h"

Double_t FitFunc(Double_t * x,Double_t * par) {
  
  Double_t a1 = (x[0] - par[1])/par[2];
  Double_t a2 = (x[0] - par[3])/par[4];

  return par[0]*(par[5]*TMath::Erf(a1)+(1-par[5])*TMath::Erf(a2));
 
}

Double_t FitFunc_simple(Double_t * x,Double_t * par) {

  Double_t a1 = (x[0] - par[1])/par[2];
  return 0.5*par[0] * ( 1 + TMath::Erf(a1));

}

void TriggerEfficiency() {

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  double luminosity = 40400;

  std::vector< std::pair<TString,std::vector<TString>> > samples;

  std::vector<TString> MC;
  MC.push_back("WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  MC.push_back("W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  MC.push_back("W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  MC.push_back("W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  MC.push_back("W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  std::vector<TString> Data;
  Data.push_back("SingleMuon_Run2017");
  samples.push_back(make_pair("MC"   , MC));
  samples.push_back(make_pair("Data" , Data));

  std::map<TString,TH1D*> histoMap;

  const int nbins  = 20;
  float bins[nbins+1] = {60,90,100,110,120,130,140,150,160,170,180,190,200,220,240,280,320,380,480,600,800};

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

  for (unsigned int i=0; i<samples.size(); ++i) {

    TH1D* histo_num = new TH1D(samples[i].first + "_num","",nbins,bins);
    TH1D* histo_den = new TH1D(samples[i].first + "_den","",nbins,bins);

    for(unsigned int idx_list=0; idx_list<samples[i].second.size(); idx_list++){

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

      cout<<"---------- Processing  "<<samples[i].second[idx_list]<<"  ---------- "<<endl;

      while(myReader->Next()){

	//if(*IsW != true)   continue; // this includes an mtmuon cut of 40GeV
	//if(*mtmuon < 50)   continue;
	
	double weight = 1.;
	double norm = 1.;
	if(samples[i].first.Contains("MC") && samples[i].second.size()>1){
	  if(*npartons == 0)      norm=luminosity/( nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 1) norm=luminosity/( nevtsProcessed1Jet/xsec1Jet + nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 2) norm=luminosity/( nevtsProcessed2Jet/xsec2Jet + nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 3) norm=luminosity/( nevtsProcessed3Jet/xsec3Jet + nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 4) norm=luminosity/( nevtsProcessed4Jet/xsec4Jet + nevtsProcessedIncl/xsecIncl );
	  else                    norm=luminosity/( nevtsProcessedIncl/xsecIncl );
	}
	
	// CUTS

	if(*mht < 60 )         continue;
	if(*muonPt < 30)       continue;
	if(*dPhiMetMuon > 1.5) continue;

	histo_den  -> Fill( *met, weight*norm );
	
	if(*trigger != true)   continue;

	histo_num  -> Fill( *met, weight*norm );
      }
    }
    histoMap[samples[i].first + "_num"] = (TH1D*) histo_num -> Clone();
    histoMap[samples[i].first + "_num"] -> SetDirectory(0);
    histoMap[samples[i].first + "_den"] = (TH1D*) histo_den -> Clone();
    histoMap[samples[i].first + "_den"] -> SetDirectory(0);
  }

  TGraphAsymmErrors * effData = new TGraphAsymmErrors();
  TGraphAsymmErrors * effMC   = new TGraphAsymmErrors();
  TF1 * dataFunc;
  TF1 * mcFunc;

  effData -> Divide(histoMap["Data_num"],histoMap["Data_den"] , "n");
  effMC   -> Divide(histoMap["MC_num"],histoMap["MC_den"]     , "n");


  // ################################# Fitting Starts ############
  /*
  dataFunc = new TF1("dataFunc",FitFunc,bins[0],bins[nbins],6);
  dataFunc->SetParameter(0,0.5);
  dataFunc->SetParameter(1,80.);
  dataFunc->SetParameter(2,50.);
  dataFunc->SetParameter(3,120.);
  dataFunc->SetParameter(4,100.);
  dataFunc->SetParameter(5,0.5);
  dataFunc->SetParLimits(0,0.00001,0.99999);
  dataFunc->SetParLimits(5,0.00001,0.99999);
  dataFunc->SetLineColor(1);
  effData->Fit("dataFunc","RB");
 
  mcFunc = new TF1("mcFunc",FitFunc,bins[0],bins[nbins],6);
  mcFunc->SetParameter(0,0.5);
  mcFunc->SetParameter(1,80.);
  mcFunc->SetParameter(2,50.);
  mcFunc->SetParameter(3,120.);
  mcFunc->SetParameter(4,100.);
  mcFunc->SetParameter(5,0.5);
  mcFunc->SetParLimits(0,0.00001,0.99999);
  mcFunc->SetParLimits(5,0.00001,0.99999);
  mcFunc->SetLineColor(2);
  effMC->Fit("mcFunc","RB");
  cout<<endl;
  cout<<endl;
  cout<<"Data results : "<<endl;
  cout<<"Propability = "<<dataFunc->GetProb()<<endl;
  cout<<"Chi**2      = "<<dataFunc->GetChisquare()<<endl;
  cout<<"NDF         = "<<dataFunc->GetNDF()<<endl;
  cout<<endl;
  cout<<"MC results : "<<endl;
  cout<<"Propability = "<<mcFunc->GetProb()<<endl;
  cout<<"Chi**2      = "<<mcFunc->GetChisquare()<<endl;
  cout<<"NDF         = "<<mcFunc->GetNDF()<<endl;
  cout<<endl;
  */
  // ################################# Fitting Ends ############


  // ################################ Plotting Starts ###########
  effData->SetMarkerStyle(20);
  effData->SetMarkerColor(1);
  effData->SetLineColor(1);
  effData->SetMarkerSize(0.7);
  effMC->SetMarkerStyle(21);
  effMC->SetMarkerColor(2);
  effMC->SetLineColor(2);
  effMC->SetMarkerSize(1);

  TCanvas * canv = new TCanvas("canv","",1000,700);
  effData->GetYaxis()->SetTitle("Trigger Efficiency");
  effData->GetXaxis()->SetTitle("E_{T}^{mis} [GeV]");
  effData->GetYaxis()->SetTitleOffset(1.2);
  effData->GetXaxis()->SetTitleOffset(1.1);
  effData->SetMaximum(1.0);
  effData->SetMinimum(0.0);
  effData->GetXaxis()->SetRangeUser(bins[0],bins[nbins]);
  effData->Draw("ap");
  effMC->Draw("psame");

  histoMap["Data_den"] -> SetMarkerStyle(20);
  histoMap["Data_den"] -> SetMarkerColor(1);
  histoMap["Data_den"] -> SetLineColor(1);
  histoMap["MC_den"]   -> SetMarkerStyle(20);
  histoMap["MC_den"]   -> SetMarkerColor(2);
  histoMap["MC_den"]   -> SetLineColor(2);
  
  //histoMap["Data_den"] -> GetXaxis()->SetTitle("MET");
  //histoMap["Data_den"] -> SetTitle("mht>120 & muonPt>30 & dPhi<1.5 & mt>0");
  //histoMap["Data_den"] -> Draw("");
  //histoMap["MC_den"]   -> Draw("same");

  TLegend * leg = NULL; 
  leg = new TLegend(0.6,0.2,0.9,0.45);
  SetLegendStyle(leg);
  leg->SetTextSize(0.05);
  leg->SetHeader("single #mu events, ");
  leg->AddEntry(effData,"data","lp");
  leg->AddEntry(effMC,"simulation","lp");
  leg->Draw();
  canv->Update();
  //canv->Print("figures/trigger_turnon.pdf","Portrait pdf");
  canv->Print("figures/trigger_turnon.png");
  //canv->Print("figures/histo_MET.png");
  //canv -> SetLogy();
  //canv->Print("figures/histo_MET_log.png");
  // ################################ Plotting Ends ###########
  

  // ################################ Saving Starts ###########
  TFile * fileOutput = new TFile("output/trigger_eff.root","recreate");
  fileOutput-> cd("");  
  //dataFunc  -> Write("dataFunc");
  //mcFunc    -> Write("mcFunc");
  effData   -> Write("data");
  effMC     -> Write("mc");
  fileOutput-> Close();
  // ################################ Saving End ###########

}
