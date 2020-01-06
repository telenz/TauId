#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include "THStack.h"
#include "TColor.h"
#include "settings.h"

void MakePostAndPreFitPlots(bool make_postfit = true, bool is_wtotaunu = true) {

  cout << "make_postfit = "<< make_postfit << endl;

  SetStyle();
  loadWorkingPoints();
  TString path = "shapes_fit_s";
  if(!make_postfit) path = "shapes_prefit";

  TString xtitle = "m_{T} (GeV)";
  TString ytitle = "Events";

  if(tau_pt_low == 100 && tau_pt_high == 200)      mttau_bins  = mttau_bins_ptbin1;
  //else if(tau_pt_low == 100 && tau_pt_high == 200) mttau_bins  = mttau_bins_ptbin2;
  //else if(tau_pt_low == 150 && tau_pt_high == 200) mttau_bins  = mttau_bins_ptbin2;
  else if(tau_pt_low == 200 )                      mttau_bins  = mttau_bins_ptbin2;

  vector<Float_t> bins;
  if(is_wtotaunu) bins = mttau_bins;
  else            bins = mtmuon_bins;
  const int nBins  = bins.size()-1;

  for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){

    cout<<endl<<endl<<"........................... Processing "<<iso[idx_iso]<<endl;

    // Read fitDiagnostics.root file
    TString mlfitFileName = "fitDiagnostics_"+iso[idx_iso];
    TFile * mlfit  = new TFile("datacards/"+mlfitFileName+tauDecayMode+".root");
    if(!mlfit){
      cout<<"File "<<mlfitFileName<<".root not available. Please Check."<<endl;
      exit(-1);      
    }

    // Define helper histogram
    TH1D* h_aux   = new TH1D("h_aux","",nBins,&bins[0]);
    TH1D* h_W     = new TH1D("h_W","",nBins,&bins[0]);
    TH1D* h_bkg1  = new TH1D("h_bkg1","",nBins,&bins[0]);
    TH1D* h_bkg2  = new TH1D("h_bkg2","",nBins,&bins[0]);
    TH1D* h_total = new TH1D("h_total","",nBins,&bins[0]);
    TGraphAsymmErrors * h_Data = new TGraphAsymmErrors(h_aux);

    TString channel = "ch2";
    if(!is_wtotaunu) channel = "ch1";

    // Read histograms from fitDiagnostics
    TString bkg1_name = "TrueTaus";
    if(!is_wtotaunu) bkg1_name = "EWK";
    TH1F * h_bkg1_ = (TH1F*)mlfit->Get(path+"/"+channel+"/"+bkg1_name);

    TString bkg2_name = "FakeTaus";
    if(!is_wtotaunu) bkg2_name = "TT";
    TH1F * h_bkg2_ = (TH1F*)mlfit->Get(path+"/"+channel+"/"+bkg2_name);

    TH1F * h_W_ = (TH1F*)mlfit->Get(path+"/"+channel+"/W");
    TH1F * h_total_    = (TH1F*)mlfit->Get(path+"/"+channel+"/total");
    TGraphAsymmErrors * h_Data_ = (TGraphAsymmErrors*)mlfit->Get(path+"/"+channel+"/data");
    double *y_data = h_Data_->GetY();
    double *eyh_data = h_Data_->GetEYhigh();
    double *eyl_data = h_Data_->GetEYlow();

    for(int i=1; i<=h_aux->GetNbinsX(); i++)
      {
	h_bkg1 -> SetBinContent(i,h_bkg1_->GetBinContent(i));
	h_bkg1 -> SetBinError(i,h_bkg1_->GetBinError(i));
	h_bkg2 -> SetBinContent(i,h_bkg2_->GetBinContent(i));
	h_bkg2 -> SetBinError(i,h_bkg2_->GetBinError(i));
	h_W -> SetBinContent(i,h_W_->GetBinContent(i));
	h_W -> SetBinError(i,h_W_->GetBinError(i));
	h_total    -> SetBinContent(i,h_total_->GetBinContent(i));
	h_total    -> SetBinError(i,h_total_->GetBinError(i));
	h_Data     -> SetPoint(i-1 , h_aux->GetBinCenter(i) , y_data[i-1]);
	h_Data     -> SetPointError(i-1, h_aux->GetBinWidth(i)/2. , h_aux->GetBinWidth(i)/2.  , eyl_data[i-1] , eyh_data[i-1]);
      }

    // Set styles
    h_total->SetFillStyle(3013);
    h_total->SetFillColor(1);
    h_total->SetMarkerStyle(21);
    h_total->SetMarkerSize(0);
    h_W   ->SetFillColor(TColor::GetColor("#FFCC66"));
    h_bkg1->SetFillColor(TColor::GetColor("#6F2D35")); // true taus and ewk
    h_bkg2->SetFillColor(TColor::GetColor("#FFCCFF"));
    if(!is_wtotaunu)  h_bkg2->SetFillColor(TColor::GetColor("#BEE6E7"));
    h_Data->SetTitle("");
    h_Data->GetXaxis()->SetTitle("");
    h_Data->GetYaxis()->SetTitle(ytitle);
    h_Data->GetXaxis()->SetLabelSize(0.);
    h_Data->SetMaximum(h_Data->GetHistogram()->GetMaximum()*1.3);
    h_Data->GetXaxis()->SetRangeUser(bins[0],bins[nBins]);

    // Make stack from all contributions
    THStack *stack = new THStack(iso[idx_iso],"");
    stack->Add(h_bkg1);
    stack->Add(h_bkg2);
    stack->Add(h_W);

    TCanvas * canv1 = MakeCanvas("canv1", "", 700, 800);
    TPad * upper = new TPad("upper", "pad",0,0.19,1,1);
    upper->Draw();
    upper->cd();
    h_Data  -> Draw("AP");
    stack   -> Draw("hist same");
    h_Data  -> Draw("P same");
    h_total -> Draw("e2 same");

    TLegend * leg = 0;
    if(is_wtotaunu)  leg = new TLegend(0.43,0.49,0.83,0.83);
    else             leg = new TLegend(0.6,0.49,0.83,0.83);
    //TLegend * leg = new TLegend(0.19,0.49,0.45,0.83); // for last tau pt bin figure
    SetLegendStyle(leg);
    if(is_wtotaunu) leg->SetHeader(iso[idx_iso]);
    leg->AddEntry(h_Data,"Data","lp");
    if(is_wtotaunu){
      leg->AddEntry(h_W,"W#rightarrow#tau#nu","f");
      leg->AddEntry(h_bkg1,"bkgd (true taus)","f");
      leg->AddEntry(h_bkg2,"bkgd (fake taus)","f");
    }
    else{
      leg->AddEntry(h_W,"W#rightarrow#mu#nu","f");
      leg->AddEntry(h_bkg1,"electroweak","f");
      leg->AddEntry(h_bkg2,"tt + single top","f");
    }
    leg->Draw();
    writeExtraText = true;
    extraText = "Preliminary";
    CMS_lumi(upper,iPeriod,33);
    TLatex latex;
    latex.SetNDC();
    latex.SetTextAngle(0);
    latex.SetTextColor(kBlack);
    latex.SetTextFont(42);
    latex.SetTextAlign(31);
    latex.SetTextSize(10);
    float r = upper->GetRightMargin();
    float t = upper->GetTopMargin();
    latex.SetTextSize(lumiTextSize*t);
    if(make_postfit) latex.DrawLatex(r+0.25,1-2.2*t,"Post-fit");
    else             latex.DrawLatex(r+0.23,1-2.2*t,"Pre-fit");


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
    ratioH->GetXaxis()->SetTitle("m_{T} [GeV]");
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
    ratioH->GetXaxis()->SetRangeUser(bins[0],bins[nBins]);
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
    TString filename = "mttau_"+iso[idx_iso]+"_WToTauNu_";
    if(!is_wtotaunu) filename = "mtmuon_"+iso[idx_iso]+"_WToMuNu_";
    canv1->Print("figures/" + filename + outname + ".png");
    //if(!is_wtotaunu) break;
  }
}
