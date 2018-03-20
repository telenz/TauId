#include "HttStylesNew.cc"
#include "settings.h"

TGraphAsymmErrors * ComputeTriggerEfficiency(TTree * tree,
					     TString variable,
					     int nBins,
					     float * bins,
					     TString cutsNum,
					     TString cutsDen,
					     TString histName) {


  TCanvas * dummy = new TCanvas("dummy","",400,400);
  TString histNameNum = histName + "_Num";
  TString histNameDen = histName + "_Den";
  TH1D * histNum = new TH1D(histNameNum,"",nBins,bins);
  TH1D * histDen = new TH1D(histNameDen,"",nBins,bins);
  histNum->Sumw2();
  histDen->Sumw2();
  tree->Draw(variable+">>"+histNameNum,cutsNum);
  tree->Draw(variable+">>"+histNameDen,cutsDen);
  std::cout << "Eff : " << histNum->GetSumOfWeights()/histDen->GetSumOfWeights() << std::endl;
  delete dummy;
  TGraphAsymmErrors * eff = new TGraphAsymmErrors();
  eff->Divide(histNum,histDen);
  return eff;

}

Double_t FitFunc(Double_t * x,Double_t * par) {
  
  Double_t a1 = (x[0] - par[1])/par[2];
  Double_t a2 = (x[0] - par[3])/par[4];

  return par[0]*(par[5]*TMath::Erf(a1)+(1-par[5])*TMath::Erf(a2));
 
}

void PlotTrigger() {

  TString numerator   = "IsW>0.5&&mtmuon>50&&trigger>0.5";
  TString denominator = "IsW>0.5&&mtmuon>50";
  //TString mhtRange[4] = {"&&mhtNoMu<120","&&mhtNoMu>=120","",""};
  TString mhtRange[4] = {"&&mhtNoMu>120","","",""};
  
  TString bins[4] = {"MhtLt120","MhtGt120","",""};

  TString HTlabel[2] = {"H_{T,no#mu} < 120 GeV","H_{T,no#mu} > 120 GeV"};

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  TFile * fileData = new TFile(dir+"/SingleMuon_Run2017.root");
  TFile * fileMC   = new TFile(dir+"/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");


  TTree * ntupleData = (TTree*)fileData -> Get("TriggerNTuple");
  TTree * ntupleMC   = (TTree*)fileMC   -> Get("TriggerNTuple");

  const int nBins = 17;
  float xbins[nBins+1] = {120,140,160,180,200,220,240,260,280,300,340,380,420,460,500,600,700,800};
  
  TGraphAsymmErrors * effData[4];
  TGraphAsymmErrors * effMC[4];
  TF1 * dataFunc[4];
  TF1 * mcFunc[4];
  
  for (int i=0; i<1; i++) {

    TString cutsNum = numerator+mhtRange[i];
    TString cutsDen = denominator+mhtRange[i];

    effData[i] = ComputeTriggerEfficiency(ntupleData,"metNoMu",nBins,xbins,cutsNum,cutsDen,"DataEff"+bins[i]);

    effData[i]->SetMarkerStyle(20);
    effData[i]->SetMarkerColor(1);
    effData[i]->SetMarkerSize(0.7);
    dataFunc[i] = new TF1("dataFunc"+bins[i],FitFunc,xbins[0],xbins[nBins],6);
    dataFunc[i]->SetParameter(0,1.);
    dataFunc[i]->SetParameter(1,80.);
    dataFunc[i]->SetParameter(2,50.);
    dataFunc[i]->SetParameter(3,120.);
    dataFunc[i]->SetParameter(4,100.);
    dataFunc[i]->SetParameter(5,0.5);
    dataFunc[i]->SetParLimits(5,0.01,0.99);
    dataFunc[i]->SetLineColor(1);
    effData[i]->Fit("dataFunc"+bins[i],"R");
 
    effMC[i] = ComputeTriggerEfficiency(ntupleMC,
					"metNoMu",
					nBins,
					xbins,
					cutsNum,
					cutsDen,
					"MCEff"+bins[i]);

    effMC[i]->SetMarkerStyle(21);
    effMC[i]->SetMarkerColor(2);
    effMC[i]->SetLineColor(2);
    effMC[i]->SetMarkerSize(1);
    mcFunc[i] = new TF1("mcFunc"+bins[i],FitFunc,xbins[0],xbins[nBins],6);
    mcFunc[i]->SetParameter(0,1.);
    mcFunc[i]->SetParameter(1,80.);
    mcFunc[i]->SetParameter(2,50.);
    mcFunc[i]->SetParameter(3,120.);
    mcFunc[i]->SetParameter(4,100.);
    mcFunc[i]->SetParameter(5,0.5);
    mcFunc[i]->SetParLimits(5,0.01,0.99);
    mcFunc[i]->SetLineColor(2);
    effMC[i]->Fit("mcFunc"+bins[i],"R");

    TCanvas * canv = new TCanvas("canv"+bins[i],"",700,500);
    effData[i]->GetYaxis()->SetTitle("Trigger Efficiency");
    effData[i]->GetXaxis()->SetTitle("E_{T,no#mu}^{mis} [GeV]");
    effData[i]->GetYaxis()->SetTitleOffset(1.2);
    effData[i]->GetXaxis()->SetTitleOffset(1.1);
    effData[i]->SetMaximum(1.0);
    effData[i]->SetMinimum(0.0);
    effData[i]->Draw("ap");
    effMC[i]->Draw("psame");

    TLegend * leg = NULL; 
    leg = new TLegend(0.6,0.2,0.9,0.45);
    SetLegendStyle(leg);
    leg->SetTextSize(0.05);
    leg->SetHeader("single #mu events, ");
    leg->SetHeader(HTlabel[i]);
    leg->AddEntry(effData[i],"data","lp");
    leg->AddEntry(effMC[i],"simulation","lp");
    leg->Draw();
    canv->Update();
    //canv->Print("figures/trigger_"+bins[i]+".pdf","Portrait pdf");
    canv->Print("figures/trigger_"+bins[i]+".png");

  }

  TFile * fileOutput = new TFile("output/trigger_eff.root","recreate");
  fileOutput->cd("");  
  TF1 * funcDataMhtLt100 = (TF1*)dataFunc[0]->Clone(bins[0]+"_data");
  TF1 * funcDataMhtGt100 = (TF1*)dataFunc[1]->Clone(bins[1]+"_data");
  TF1 * funcMcMhtLt100 = (TF1*)mcFunc[0]->Clone(bins[0]+"_mc");
  TF1 * funcMcMhtGt100 = (TF1*)mcFunc[1]->Clone(bins[1]+"_mc");
  funcDataMhtLt100->Write(bins[0]+"_data");
  funcDataMhtGt100->Write(bins[1]+"_data");
  funcMcMhtLt100->Write(bins[0]+"_mc");
  funcMcMhtGt100->Write(bins[1]+"_mc");
  fileOutput->Close();


}
