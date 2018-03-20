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

  double luminosity = 10000;

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

  const int nbins  = 21;
  float bins[nbins+1] = {0,30,60,90,120,140,160,180,200,220,240,260,280,300,340,380,420,460,500,600,800,1500};
  
  TString var = "metNoMu";

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
      TTreeReaderValue< Bool_t  >  IsW(              *myReader,       "IsW");
      TTreeReaderValue< Bool_t  >  trigger(          *myReader,       "trigger");
      TTreeReaderValue< UInt_t  >  npartons(         *myReader,       "npartons");
      TTreeReaderValue< Float_t >  mtmuon(           *myReader,       "mtmuon");
      TTreeReaderValue< Float_t >  muonPt(           *myReader,       "muonPt");      

      cout<<"---------- Sample "<<samples[i].second[idx_list]<<" processing. ---------- "<<endl;

      while(myReader->Next()){

	if(*IsW != true)   continue;
	//if(*mhtNoMu < 100) continue;
	if(*mtmuon < 50)   continue;
	if(*muonPt < 28)   continue;

	double weight = 1.;
	double norm = 1.;
	if(samples[i].first.Contains("MC") && samples[i].second.size()>1){
	  if(*npartons == 0)      norm=luminosity/( nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 1)norm=luminosity/( nevtsProcessed1Jet/xsec1Jet + nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 2) norm=luminosity/( nevtsProcessed2Jet/xsec2Jet + nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 3) norm=luminosity/( nevtsProcessed3Jet/xsec3Jet + nevtsProcessedIncl/xsecIncl );
	  else if(*npartons == 4){
	    norm=luminosity/( nevtsProcessed4Jet/xsec4Jet + nevtsProcessedIncl/xsecIncl );

	  }
	  else                    norm=luminosity/( nevtsProcessedIncl/xsecIncl );
	}
	
	histo_den  -> Fill( *metNoMu, weight*norm );
	
	if(*trigger != true) continue;

	histo_num  -> Fill( *metNoMu, weight*norm );
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

  effData -> Divide(histoMap["Data_num"],histoMap["Data_den"]);
  effMC   -> Divide(histoMap["MC_num"],histoMap["MC_den"]);

  effData->SetMarkerStyle(20);
  effData->SetMarkerColor(1);
  effData->SetMarkerSize(0.7);
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
  //effData->Fit("dataFunc","RB");
 
  effMC->SetMarkerStyle(21);
  effMC->SetMarkerColor(2);
  effMC->SetLineColor(2);
  effMC->SetMarkerSize(1);
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
  //effMC->Fit("mcFunc","RB");

  TCanvas * canv = new TCanvas("canv","",1400,1000);
  effData->GetYaxis()->SetTitle("Trigger Efficiency");
  effData->GetXaxis()->SetTitle("E_{T,no#mu}^{mis} [GeV]");
  effData->GetYaxis()->SetTitleOffset(1.2);
  effData->GetXaxis()->SetTitleOffset(1.1);
  effData->SetMaximum(1.0);
  effData->SetMinimum(0.0);
  effData->GetXaxis()->SetRangeUser(bins[0],bins[nbins]);
  effData->Draw("ap");
  effMC->Draw("psame");

  TLegend * leg = NULL; 
  leg = new TLegend(0.6,0.2,0.9,0.45);
  SetLegendStyle(leg);
  leg->SetTextSize(0.05);
  leg->SetHeader("single #mu events, ");
  leg->AddEntry(effData,"data","lp");
  leg->AddEntry(effMC,"simulation","lp");
  leg->Draw();
  canv->Update();
  canv->Print("figures/trigger_turnon.pdf","Portrait pdf");
  canv->Print("figures/trigger_turnon.png");
  
  TFile * fileOutput = new TFile("output/trigger_eff.root","recreate");
  fileOutput->cd("");  
  //TF1 * funcDataMhtGt100 = (TF1*)dataFunc->Clone("data");
  //TF1 * funcMcMhtGt100 = (TF1*)mcFunc->Clone("mc");
  //funcDataMhtGt100->Write("data");
  //funcMcMhtGt100->Write("mc");
  effData->Write("data");
  effMC->Write("mc");
  fileOutput->Close();

}
