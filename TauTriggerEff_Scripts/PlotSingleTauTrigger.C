#include "HttStylesNew.cc"
//#include "HtoH.h"
#include "CMS_lumi.C"

void PlotSingleTauTrigger(TString iso = "taubyTightDeepTau2017v2p1VSjet",
			  bool prefit = false,
			  TString decayMode = "inclusive") {

  SetStyle();

  std::map<bool,TString> shapeDir = {
    {false,"shapes_fit_s"},
    {true,"shapes_prefit"}
  };

  TString dir = shapeDir[prefit];

  TH1::SetDefaultSumw2();

  TFile * inputPass = new TFile("inputs/tauPt_"+iso+"_"+decayMode+"_WTauNu_Trigger.root");
  TFile * inputFail = new TFile("inputs/tauPt_"+iso+"_"+decayMode+"_WTauNu_notTrigger.root");
  TFile * mlfit = new TFile("inputs/fitDiagnostics_tauPt_"+iso+"_"+decayMode+".root");

  TH1D * dataPassH = (TH1D*)inputPass->Get("data_obs");
  TH1D * dataFailH = (TH1D*)inputFail->Get("data_obs");

  TH1D * sigEffH = (TH1D*)inputPass->Get("W");

  TH1D * fakesPassFitH = (TH1D*)mlfit->Get(dir+"/ch1/Fakes");
  TH1D * fakesFailFitH = (TH1D*)mlfit->Get(dir+"/ch2/Fakes");

  TH1D * sigPassH = (TH1D*)mlfit->Get(dir+"/ch1/W");
  TH1D * sigFailH = (TH1D*)mlfit->Get(dir+"/ch2/W");

  int nBins = dataPassH->GetNbinsX();

  for (int iB=1; iB<=nBins; ++iB) {
    // passing probes
    double dataX = dataPassH->GetBinContent(iB);
    double dataE = dataPassH->GetBinError(iB);
    double fakeX = fakesPassFitH->GetBinContent(iB);
    double fakeE = fakesPassFitH->GetBinError(iB);
    double err = TMath::Sqrt(dataE*dataE+fakeE*fakeE);
    double x = dataX - fakeX;
    dataPassH->SetBinContent(iB,x);
    dataPassH->SetBinError(iB,err);

    // passing probes
    dataX = dataFailH->GetBinContent(iB);
    dataE = dataFailH->GetBinError(iB);
    fakeX = fakesFailFitH->GetBinContent(iB);
    fakeE = fakesFailFitH->GetBinError(iB);
    err = TMath::Sqrt(dataE*dataE+fakeE*fakeE);
    x = dataX - fakeX;
    dataFailH->SetBinContent(iB,x);
    dataFailH->SetBinError(iB,err);


  }

  TH1D * dataEffH = (TH1D*)dataPassH->Clone("dataEffH");

  for (int iB=1; iB<=nBins; ++iB) {
    double xPass = dataPassH->GetBinContent(iB); 
    double ePass = dataPassH->GetBinError(iB); 
    double xFail = dataFailH->GetBinContent(iB); 
    double eFail = dataFailH->GetBinError(iB);
    std::cout << xPass << ":" << xFail << std::endl;
    if (xPass<0.0) xPass = 1e-5;
    if (xFail<0.0) xFail = 1e-5;
    double xTotal = xPass + xFail;
    double xTotal2 = xTotal*xTotal;
    double e1 = xFail*ePass/xTotal2;
    double e2 = eFail*xPass/xTotal2;
    double err = TMath::Sqrt(e1*e1+e2*e2);
    double eff = xPass / xTotal;
    dataEffH->SetBinContent(iB,eff);
    dataEffH->SetBinError(iB,err);
  }

  for (int iB=1; iB<=nBins; ++iB) {
    double xPass = sigPassH->GetBinContent(iB); 
    double ePass = sigPassH->GetBinError(iB); 
    double xFail = sigFailH->GetBinContent(iB); 
    double eFail = sigFailH->GetBinError(iB); 
    double xTotal = xPass + xFail;
    double xTotal2 = xTotal*xTotal;
    double e1 = xFail*ePass/xTotal2;
    double e2 = eFail*xPass/xTotal2;
    double err = TMath::Sqrt(e1*e1+e2*e2);
    double eff = xPass / xTotal;
    sigEffH->SetBinContent(iB,eff);
    sigEffH->SetBinError(iB,err);
  }

  InitData(dataEffH);
  sigEffH->SetLineColor(2);
  sigEffH->SetMarkerColor(2);
  sigEffH->SetMarkerSize(0);
  dataEffH->SetMarkerSize(1.6);

  TH2D * frame = new TH2D("frame","",2,100,2000,2,0,1);
  frame->GetXaxis()->SetTitle("#tau p_{T} [GeV]");
  frame->GetYaxis()->SetTitle("single-#tau trigger efficiency");
  
  TCanvas * canv = new TCanvas("canv","",700,700);  
  frame->Draw();
  dataEffH->Draw("e1same");
  sigEffH->Draw("e1same");
  TLegend * leg = new TLegend(0.5,0.2,0.9,0.4);
  leg->AddEntry(dataEffH,"Data","elp");
  leg->AddEntry(sigEffH,"Simulation","elp");
  leg->Draw();
  writeExtraText = true;
  extraText = "Preliminary";
  CMS_lumi(canv,4,33); 
  canv->SetLogx(true); 
  canv->Update();
  canv->Print("figures/trigEff"+iso+"_"+decayMode+"_"+dir+".png");
  
  TH1D * SF = (TH1D*)dataEffH->Clone("SF");
  for (int iB=1; iB<=nBins; ++iB) {
    int low  = int(dataEffH->GetBinLowEdge(iB)); 
    int high = int(dataEffH->GetBinLowEdge(iB+1)); 
    double num  = dataEffH->GetBinContent(iB);
    double numE = dataEffH->GetBinError(iB);
    double den  = sigEffH->GetBinContent(iB);
    double denE = sigEffH->GetBinError(iB);
    double numR = numE/num;
    double denR = denE/den;
    double R = TMath::Sqrt(numR*numR+denR*denR);
    double sf = num/den;
    double sfE = sf*R;
    double relE = sfE/sf;
    printf("pT = [%3i,%4i] GeV: SF = %5.3f +/- %5.3f  (%2.0f%)\n",low,high,sf,sfE,100*relE);
    SF->SetBinContent(iB,sf);
    SF->SetBinError(iB,sfE);
  }
  /*
  TH2D * frame1 = new TH2D("frame1","",2,100,2000,2,0.0,2.0);
  frame1->GetXaxis()->SetTitle("#tau p_{T} [GeV]");
  frame1->GetYaxis()->SetTitle("SF");
  
  TCanvas * canv1 = new TCanvas("canv1","",700,700);  
  frame1->Draw();
  SF->Draw("e1same");
  writeExtraText = true;
  extraText = "Preliminary";
  CMS_lumi(canv1,4,33); 
  canv1->SetLogx(true); 
  canv1->Update();
  canv1->Print("figures/SF_"+iso+"_"+decayMode+"_"+dir+".png");
  */

}
