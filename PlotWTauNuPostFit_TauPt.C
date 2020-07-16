#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include <map>
#include <vector>
// iso : taubyMediumDeepTau2017v2p1VSjet, taubyTightDeepTau2017v2p1VSjet 
// TauMode : inclusive, 1prong, 1prongpi0s, 3prong
// triggerOption : 0 (inclusive), 1 (passing trigger), 2 (failing trigger)
void PlotWTauNuPostFit_TauPt(TString iso="taubyTightDeepTau2017v2p1VSjet",
			     TString TauMode = "inclusive",
			     int triggerOption = 1,
			     bool prefit = true) {

  bool logX = true;
  bool logY = true;
  bool plotLeg = true;
  float scale = 1;

  SetStyle();
  std::map<int,TString> category = {
    {1,"ch1"},
    {2,"ch2"},
    {0,"ch1"}
  };
  std::map<bool,TString> shapeDir = {
    {false,"shapes_fit_s"},
    {true,"shapes_prefit"}
  };
  std::map<TString,TString> tauIDiso = {
    {"taubyMediumDeepTau2017v2p1VSjet","Medium"},
    {"taubyTightDeepTau2017v2p1VSjet","Tight"},
  };
  std::map<TString,TString> decayMode = {
    {"inclusive","inclusive"},
    {"1prong","1-prong"},
    {"1prongpi0s","1-prong+#pi^{0}'s"},
    {"3prong","3-prong"}
  };
  std::map<int,TString> postfixTrigger = {
    {0,"inclusive"},
    {1,"Trigger"},
    {2,"notTrigger"}
  };

  TString channel = category[triggerOption];
  TString shapes  = shapeDir[prefit];
  TString WorkPoint = tauIDiso[iso];
  TString hpsDM = decayMode[TauMode];
  TString Trigger = postfixTrigger[triggerOption];

  TString xtitle = "#tau p_{T} (GeV)";
  TString ytitle = "Events / bin";

  TString inputFileName = "inputs/tauPt_"+iso+"_"+TauMode+"_WTauNu_"+Trigger+".root";
  TString mlfitFileName = "inputs/fitDiagnostics_tauPt_"+iso+"_"+TauMode+".root";

  float uncert = 0.0;
  TString legHeader = WorkPoint+"  "+hpsDM;

  TFile * inputs = new TFile(inputFileName);
  TFile * mlfit  = new TFile(mlfitFileName); 
  
  TH1F * histData = (TH1F*)inputs->Get("data_obs");
  TH1F * QCD   = (TH1F*)inputs->Get("Fakes");
  TH1F * W     = (TH1F*)inputs->Get("W");

  TH1F * QCDx  = (TH1F*)mlfit->Get(shapes+"/"+channel+"/Fakes");
  TH1F * Wx    = (TH1F*)mlfit->Get(shapes+"/"+channel+"/W");
  TH1F * tot   = (TH1F*)mlfit->Get(shapes+"/"+channel+"/total");

  float total  = QCDx->GetSumOfWeights()+Wx->GetSumOfWeights();

  std::cout << "QCD  : " << scale*QCDx->GetSumOfWeights() << std::endl;
  std::cout << "W    : " << scale*Wx->GetSumOfWeights() << std::endl;
  std::cout << "SUM  : " << scale*total << std::endl;
  std::cout << "Tot  : " << scale*tot->GetSumOfWeights() << std::endl;
  std::cout << "DAT  : " << histData->GetSumOfWeights() << std::endl;

  TH1F * bkgdErr = (TH1F*)W->Clone("bkgdErr");
  bkgdErr->SetFillStyle(3013);
  bkgdErr->SetFillColor(1);
  bkgdErr->SetMarkerStyle(21);
  bkgdErr->SetMarkerSize(0);  
  
  int nBins = histData->GetNbinsX();

  for (int iB=1; iB<=nBins; ++iB) {
    float QDC_E = scale*QCDx->GetBinError(iB);
    float W_E   = scale*Wx->GetBinError(iB);

    float QCD_X  = scale*QCDx->GetBinContent(iB); 
    float W_X    = scale*Wx->GetBinContent(iB); 
    float total_X = QCD_X + W_X;

    QCD->SetBinError(iB,0);
    W->SetBinError(iB,0);

    float errSubtr = uncert*W_X;
    float fitErr = tot->GetBinError(iB);

    float error = TMath::Sqrt(fitErr*fitErr-errSubtr*errSubtr);

    QCD->SetBinContent(iB,QCD_X);
    W->SetBinContent(iB,total_X);

    bkgdErr->SetBinContent(iB,total_X);
    bkgdErr->SetBinError(iB,error);

    if (histData->GetBinContent(iB)<1)
      bkgdErr->SetBinError(iB,0);

  }

  InitData(histData);
  InitHist(QCD,"","",TColor::GetColor(192,232,100),1001);
  InitHist(W,"","",TColor::GetColor("#FFCC66"),1001);
  histData->GetXaxis()->SetTitle(xtitle);
  histData->GetYaxis()->SetTitle(ytitle);
  histData->GetYaxis()->SetTitleOffset(1.3);
  histData->GetYaxis()->SetTitleSize(0.06);

  histData->SetMarkerSize(1.2);
  histData->GetXaxis()->SetLabelSize(0);
  histData->GetYaxis()->SetLabelSize(0.06);

  TCanvas * canv1 = MakeCanvas("canv1", "", 700, 800);
  TPad * upper = new TPad("upper", "pad",0,0.31,1,1);
  upper->Draw();
  upper->cd();
  upper->SetFillColor(0);
  upper->SetBorderMode(0);
  upper->SetBorderSize(10);
  upper->SetTickx(1);
  upper->SetTicky(1);
  upper->SetLeftMargin(0.17);
  upper->SetRightMargin(0.05);
  upper->SetBottomMargin(0.02);
  upper->SetFrameFillStyle(0);
  upper->SetFrameLineStyle(0);
  upper->SetFrameLineWidth(2);
  upper->SetFrameBorderMode(0);
  upper->SetFrameBorderSize(10);
  upper->SetFrameFillStyle(0);
  upper->SetFrameLineStyle(0);
  upper->SetFrameLineWidth(2);
  upper->SetFrameBorderMode(0);
  upper->SetFrameBorderSize(10);

  float yUpper = histData->GetMaximum();
  if (W->GetMaximum()>yUpper)
    yUpper = W->GetMaximum();

  histData->GetYaxis()->SetRangeUser(0.,1.2*yUpper);
  if (logY)
    histData->GetYaxis()->SetRangeUser(1.0,10.0*yUpper);

  histData->Draw("e1");
  W->Draw("sameh");
  QCD->Draw("sameh");
  histData->Draw("e1same");
  bkgdErr->Draw("e2same");
  float chi2 = 0;
  for (int iB=1; iB<=nBins; ++iB) {
    float xData = histData->GetBinContent(iB);
    float xMC = W->GetBinContent(iB);
    float eData = histData->GetBinError(iB);
    float eMC = bkgdErr->GetBinError(iB);
    if (xMC>1e-1) {
      float diff2 = (xData-xMC)*(xData-xMC);
      chi2 += diff2/(eMC*eMC+eData*eData);
    }
  }
  double prob = TMath::Prob(double(chi2),double(nBins));
  std::cout << std::endl;
  std::cout << "Chi2 = " << chi2 << "   p-value =" << prob << std::endl;
  std::cout << std::endl;

  TLegend * leg = new TLegend(0.60,0.48,0.90,0.76);
  SetLegendStyle(leg);
  leg->SetTextSize(0.04);
  leg->SetHeader(legHeader);
  leg->AddEntry(histData,"Observed","lp");
  leg->AddEntry(W,"genuine #tau","f");
  leg->AddEntry(QCD,"misidentified j#rightarrow#tau","f");
  if (plotLeg) leg->Draw();
  writeExtraText = true;
  extraText = "Preliminary";
  CMS_lumi(upper,4,33); 
  //  plotchannel("#tau#nu");

  if (logY) upper->SetLogy(true);
  if (logX) upper->SetLogx(true);
    
  upper->Draw("SAME");
  upper->RedrawAxis();
  upper->Modified();
  upper->Update();
  canv1->cd();

  TH1F * ratioH = (TH1F*)histData->Clone("ratioH");
  TH1F * ratioErrH = (TH1F*)bkgdErr->Clone("ratioErrH");
  ratioH->SetMarkerColor(1);
  ratioH->SetMarkerStyle(20);
  ratioH->SetMarkerSize(1.2);
  ratioH->SetLineColor(1);
  ratioH->GetYaxis()->SetRangeUser(0.2,1.8);
  ratioH->GetYaxis()->SetNdivisions(505);
  ratioH->GetXaxis()->SetLabelFont(42);
  ratioH->GetXaxis()->SetLabelOffset(0.04);
  ratioH->GetXaxis()->SetLabelSize(0.14);
  ratioH->GetXaxis()->SetTitleSize(0.13);
  ratioH->GetXaxis()->SetTitleOffset(1.2);
  ratioH->GetYaxis()->SetTitle("Obs./Exp.");
  ratioH->GetYaxis()->SetLabelFont(42);
  ratioH->GetYaxis()->SetLabelOffset(0.015);
  ratioH->GetYaxis()->SetLabelSize(0.13);
  ratioH->GetYaxis()->SetTitleSize(0.14);
  ratioH->GetYaxis()->SetTitleOffset(0.5);
  ratioH->GetXaxis()->SetTickLength(0.07);
  ratioH->GetYaxis()->SetTickLength(0.04);
  ratioH->GetYaxis()->SetLabelOffset(0.01);

  for (int iB=1; iB<=nBins; ++iB) {
    float x1 = histData->GetBinContent(iB);
    float x2 = W->GetBinContent(iB);
    ratioErrH->SetBinContent(iB,1.0);
    ratioErrH->SetBinError(iB,0.0);
    float xBkg = bkgdErr->GetBinContent(iB);
    float errBkg = bkgdErr->GetBinError(iB);
    if (xBkg>0) {
      float relErr = errBkg/xBkg;
      ratioErrH->SetBinError(iB,relErr);

    }
    if (x1>0&&x2>0) {
      float e1 = histData->GetBinError(iB);
      float ratio = x1/x2;
      float eratio = e1/x2;
      ratioH->SetBinContent(iB,ratio);
      ratioH->SetBinError(iB,eratio);
    }
    else {
      ratioH->SetBinContent(iB,1000);
    }
  }

  // ------------>Primitives in pad: lower
  TPad * lower = new TPad("lower", "pad",0,0,1,0.30);
  lower->Draw();
  lower->cd();
  lower->SetFillColor(0);
  lower->SetBorderMode(0);
  lower->SetBorderSize(10);
  lower->SetGridy();
  lower->SetTickx(1);
  lower->SetTicky(1);
  lower->SetLeftMargin(0.17);
  lower->SetRightMargin(0.05);
  lower->SetTopMargin(0.026);
  lower->SetBottomMargin(0.35);
  lower->SetFrameFillStyle(0);
  lower->SetFrameLineStyle(0);
  lower->SetFrameLineWidth(2);
  lower->SetFrameBorderMode(0);
  lower->SetFrameBorderSize(10);
  lower->SetFrameFillStyle(0);
  lower->SetFrameLineStyle(0);
  lower->SetFrameLineWidth(2);
  lower->SetFrameBorderMode(0);
  lower->SetFrameBorderSize(10);

  ratioH->Draw("e1");
  ratioErrH->Draw("e2same");

  if (logX) lower->SetLogx(true);
  lower->Modified();
  lower->RedrawAxis();
  canv1->cd();
  canv1->Modified();
  canv1->cd();
  canv1->SetSelected(canv1);
  canv1->Update();
  if (prefit) {
    canv1->Print("figures/tauPt_"+iso+"_"+TauMode+"_"+channel+"_prefit.png");
  }
  else {
    canv1->Print("figures/tauPt_"+iso+"_"+TauMode+"_"+channel+"_postfit.png");
  }
  
}
