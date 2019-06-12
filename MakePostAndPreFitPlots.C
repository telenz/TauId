#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include "THStack.h"
#include "TColor.h"
#include "settings.h"

void MakePostAndPreFitPlots(bool make_postfit = true) {

  cout << "make_postfit = "<< make_postfit << endl;

  SetStyle();
  loadWorkingPoints();
  TString path = "shapes_fit_s";
  if(!make_postfit) path = "shapes_prefit";

  TString xtitle = "m_{T} (GeV)";
  TString ytitle = "Events";

  for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){

    cout<<endl<<endl<<"........................... Processing "<<iso[idx_iso]<<endl;

    // Read fitDiagnostics.root file
    TString mlfitFileName = "fitDiagnostics_"+iso[idx_iso];
    TFile * mlfit  = new TFile("datacards/"+mlfitFileName+tauDecayMode+".root");
    if(!mlfit){
      cout<<"File "<<mlfitFileName<<".root not available. Please Check."<<endl;
      exit(-1);      
    }

    // Read histograms from fitDiagnostics
    TGraphAsymmErrors * h_Data = (TGraphAsymmErrors*)mlfit->Get(path+"/ch2/data");
    TH1F * h_FakeTaus = (TH1F*)mlfit->Get(path+"/ch2/FakeTaus");
    TH1F * h_TrueTaus = (TH1F*)mlfit->Get(path+"/ch2/TrueTaus");
    TH1F * h_WToTauNu = (TH1F*)mlfit->Get(path+"/ch2/W");
    TH1F * h_total    = (TH1F*)mlfit->Get(path+"/ch2/total");

    // Set styles
    h_total->SetFillStyle(3013);

    h_total->SetFillColor(1);
    h_total->SetMarkerStyle(21);
    h_total->SetMarkerSize(0);
    //h_total->SetBinError(1,0);
    //h_total->SetBinError(2,0);
    h_WToTauNu->SetFillColor(TColor::GetColor("#FFCC66"));
    h_FakeTaus->SetFillColor(TColor::GetColor("#FFCCFF"));
    h_TrueTaus->SetFillColor(TColor::GetColor("#6F2D35"));
    h_Data->SetTitle("");
    h_Data->GetXaxis()->SetTitle("");
    h_Data->GetYaxis()->SetTitle(ytitle);
    h_Data->GetXaxis()->SetLabelSize(0.);
    h_Data->SetMaximum(h_Data->GetHistogram()->GetMaximum()*1.3);

    // Make stack from all contributions
    THStack *stack = new THStack(iso[idx_iso],"");
    stack->Add(h_TrueTaus);
    stack->Add(h_FakeTaus);
    stack->Add(h_WToTauNu);

    TCanvas * canv1 = MakeCanvas("canv1", "", 700, 800);
    TPad * upper = new TPad("upper", "pad",0,0.19,1,1);
    upper->Draw();
    upper->cd();
    h_Data  -> Draw("AP");
    stack   -> Draw("hist same");
    h_Data  -> Draw("P same");
    h_total -> Draw("e2 same");

    TLegend * leg = new TLegend(0.56,0.49,0.83,0.83);
    //TLegend * leg = new TLegend(0.19,0.49,0.45,0.83); // for last tau pt bin figure
    SetLegendStyle(leg);
    leg->SetHeader(iso[idx_iso]);
    leg->AddEntry(h_Data,"Data","lp");
    leg->AddEntry(h_WToTauNu,"W#rightarrow#tau#nu","f");
    leg->AddEntry(h_FakeTaus,"bkgd (fake taus)","f");
    leg->AddEntry(h_TrueTaus,"bkgd (true taus)","f");
    leg->Draw();
    writeExtraText = true;
    extraText = "Preliminary";
    CMS_lumi(upper,iPeriod,33);

    upper->Draw("SAME");
    upper->RedrawAxis();
    upper->Modified();
    upper->Update();
    canv1->cd();

    // Divide data by central value of stacks
    TGraphAsymmErrors *ratioH = (TGraphAsymmErrors*)h_Data->Clone("ratioH");
    for(int i_bin = 0; i_bin < h_Data->GetN(); i_bin++){
      double scale = h_total->GetBinContent(i_bin+1);
      double x,y;
      h_Data->GetPoint(i_bin,x,y);
      ratioH->SetPoint(i_bin,x,y/scale);
      ratioH->SetPointEYhigh(i_bin,h_Data->GetErrorYhigh(i_bin)/scale);
      ratioH->SetPointEYlow(i_bin,h_Data->GetErrorYlow(i_bin)/scale);
    }

    ratioH->GetYaxis()->SetRangeUser(0.4,1.6);
    ratioH->GetYaxis()->SetNdivisions(505);
    ratioH->GetXaxis()->SetTitle("bin number");
    //ratioH->GetXaxis()->SetTitle("m_{T} [GeV]");
    ratioH->GetYaxis()->SetTitle("Obs./Exp.");
    ratioH->GetYaxis()->CenterTitle();
    ratioH->GetXaxis()->SetTitleOffset(3.5);
    ratioH->GetXaxis()->SetLabelSize(30);

    TH1D * ratioErrH = (TH1D*)h_total->Clone("ratioErrH");
    for(int i=1; i<=h_total->GetNbinsX(); i++){
      ratioErrH->SetBinContent(i,1);
      ratioErrH->SetBinError(i,h_total->GetBinError(i)/h_total->GetBinContent(i));
      if(h_total->GetBinContent(i)<0.001) ratioErrH->SetBinError(i,0);
    }
    
    // ------------>Primitives in pad: lower
    TPad * lower = new TPad("lower", "pad",0,0,1,0.31);
    lower->SetBottomMargin(0.32);
    lower->Draw();
    lower->cd();
    lower->SetGridy();
    ratioH->Draw("AP");
    ratioErrH->Draw("e2same");
    
    lower->Modified();
    lower->RedrawAxis();
    canv1->cd();
    canv1->Modified();
    canv1->cd();
    canv1->SetSelected(canv1);
    canv1->Update();
    TString outname = "postfit";
    if(!make_postfit) outname = "prefit";
    canv1->Print("figures/mttau_"+iso[idx_iso]+"_WToTauNu_" + outname + ".png");
  }
}
