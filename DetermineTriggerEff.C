#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include "TH1.h"
#include "TGraphAsymmErrors.h"
#include "settings.h"

void DetermineTriggerEff( bool prefit = false) {

  SetStyle();
  loadWorkingPoints();
  
  std::map<bool,TString> shapeDir = {
    {false,"shapes_fit_s"},
    {true,"shapes_prefit"}
  };
  TString dir = shapeDir[prefit];
  TH1::SetDefaultSumw2();
  
  for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){
    
    TFile * inputPass = new TFile("output/"+era+ "/"+"tauPt_"+iso[idx_iso]+tauDecayMode+"_WToTauNu_shapes_trigger_passingprobes.root");
    TFile * inputFail = new TFile("output/"+era+ "/"+"tauPt_"+iso[idx_iso]+tauDecayMode+"_WToTauNu_shapes_trigger_failingprobes.root");
    TFile * mlfit = new TFile("datacards/"+era+ "/"+"fitDiagnostics_tauPt_"+iso[idx_iso]+tauDecayMode+".root");
    
    TH1D * dataPassH = (TH1D*)inputPass->Get("data_obs");
    TH1D * dataFailH = (TH1D*)inputFail->Get("data_obs");
    
    TH1D * fakesPassH = (TH1D*)mlfit->Get(dir+"/ch1/FakeTaus");
    TH1D * fakesFailH = (TH1D*)mlfit->Get(dir+"/ch2/FakeTaus");
    TH1D * sigPassH = (TH1D*)mlfit->Get(dir+"/ch1/W");
    TH1D * sigFailH = (TH1D*)mlfit->Get(dir+"/ch2/W");

    int nBins = dataPassH->GetNbinsX();
    
    //binning of data histograms is different than binning of fakes & signal histograms, has to be changed
    TH1D *fakesPassH_rebinned = new TH1D("fakes passing trigger", "fakes passing trigger", 10, &pttau_bins[0]);
    TH1D *fakesFailH_rebinned = new TH1D("fakes failing trigger", "fakes failing trigger", 10, &pttau_bins[0]);
    TH1D *sigPassH_rebinned = new TH1D("signal passing trigger", "signal passing trigger", 10, &pttau_bins[0]);
    TH1D *sigFailH_rebinned = new TH1D("signal failing trigger", "signal failing trigger", 10, &pttau_bins[0]); 
    
    for(int iB=0; iB<nBins+1; iB++){
        fakesPassH_rebinned->SetBinContent(iB,fakesPassH->GetBinContent(iB));
        fakesPassH_rebinned->SetBinError(iB,fakesPassH->GetBinError(iB));
        fakesFailH_rebinned->SetBinContent(iB,fakesFailH->GetBinContent(iB));
        fakesFailH_rebinned->SetBinError(iB,fakesFailH->GetBinError(iB));
        sigPassH_rebinned->SetBinContent(iB,sigPassH->GetBinContent(iB));
        sigPassH_rebinned->SetBinError(iB,sigPassH->GetBinError(iB));
        sigFailH_rebinned->SetBinContent(iB,sigFailH->GetBinContent(iB));
        sigFailH_rebinned->SetBinError(iB,sigFailH->GetBinError(iB));
    }
    //subtract fake background from data
    dataPassH->Add(fakesPassH_rebinned,-1);
    dataFailH->Add(fakesFailH_rebinned,-1);

    // errors are not calculated correctly with TGraphAsymmErrors
    // determine data efficiency
    // TH1D * denominator_data =  (TH1D*) dataFailH->Clone();
    // denominator_data->Add(dataPassH,1.);
    // TGraphAsymmErrors *eff_data = new TGraphAsymmErrors();
    // eff_data -> Divide(dataPassH, denominator_data, "b");
    
    // determine MC efficiency
    // TH1D * denominator_mc =  (TH1D*) sigFailH_rebinned->Clone();
    // denominator_mc->Add(sigPassH_rebinned,1.);
    // TGraphAsymmErrors *eff_mc = new TGraphAsymmErrors();
    // eff_mc -> Divide(sigPassH_rebinned, denominator_mc);

    TH1D * eff_data =  (TH1D*) dataFailH->Clone();
    TH1D * eff_mc =  (TH1D*) dataFailH->Clone();
    for (int iB=1; iB<=nBins; ++iB) {
      double xPass = dataPassH->GetBinContent(iB);
      double ePass = dataPassH->GetBinError(iB);
      double xFail = dataFailH->GetBinContent(iB);
      double eFail = dataFailH->GetBinError(iB);
      if (xPass<0.0) xPass = 1e-5;
      if (xFail<0.0) xFail = 1e-5;
      double xTotal = xPass + xFail;
      double xTotal2 = xTotal*xTotal;
      double e1 = xFail*ePass/xTotal2;
      double e2 = eFail*xPass/xTotal2;
      double err = TMath::Sqrt(e1*e1+e2*e2);
      double eff = xPass / xTotal;
      eff_data->SetBinContent(iB,eff);
      eff_data->SetBinError(iB,err);
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
      eff_mc->SetBinContent(iB,eff);
      eff_mc->SetBinError(iB,err);
    }
  
    eff_mc->SetLineColor(2);
    eff_mc->SetMarkerColor(2);
    eff_mc->SetMarkerSize(0);
    eff_data->SetMarkerSize(1.6);
    
    TH2D * frame = new TH2D("frame","",2,100,2000,2,0,1);
    frame->GetXaxis()->SetTitle("#tau p_{T} [GeV]");
    frame->GetYaxis()->SetTitle("single-#tau trigger efficiency");
    frame->GetYaxis()->SetTitleOffset(1.28);
    frame->GetYaxis()->SetRangeUser(0,1.);
    
    TCanvas * canv = new TCanvas("canv","",700,700);
    frame->Draw();
    eff_data->Draw("p same");
    eff_mc->Draw("p same");
    
    TLegend * leg = new TLegend(0.5,0.2,0.9,0.4);
    leg->AddEntry(eff_data,"Data","Aelp");
    leg->AddEntry(eff_mc,"Simulation","Aelp");
    leg->Draw();
    writeExtraText = true;
    extraText = "Preliminary";
    CMS_lumi(canv,iPeriod,33); 
    canv->SetLogx(); 
    canv->Update();
    canv->Print("figures/"+era+ "/"+"trigEff"+iso[idx_iso]+tauDecayMode+"_"+dir+".png");


    //calculate SF
    TH1D * SF = (TH1D*)dataPassH->Clone("SF");
    for (int iB=0; iB<nBins+1; ++iB) {
      double num  = eff_data->GetBinContent(iB);
      double numE = eff_data->GetBinError(iB);
      double den  = eff_mc->GetBinContent(iB);
      double denE = eff_mc->GetBinError(iB);
      double numR = numE/num;
      double denR = denE/den;
      double R = TMath::Sqrt(numR*numR+denR*denR);
      double sf = num/den;
      double sfE = sf*R;
      SF->SetBinContent(iB,sf);
      SF->SetBinError(iB,sfE);
    }
  
    TH2D * frame1 = new TH2D("frame1","",2,100,2000,2,0.0,2.0);
    frame1->GetXaxis()->SetTitle("#tau p_{T} [GeV]");
    frame1->GetYaxis()->SetTitle("SF");
    frame1->GetYaxis()->SetTitleOffset(1.18);
    frame1->GetYaxis()->SetRangeUser(0.5,2.0);
    TCanvas * canv1 = new TCanvas("canv1","",700,700);
    frame1->Draw();
    SF->Draw("e1same");
    writeExtraText = true;
    extraText = "Preliminary";
    CMS_lumi(canv1,iPeriod,33);
    canv1->Update();
    canv1->SetLogx();
    canv1->Print("figures/"+era+ "/"+"SF_"+iso[idx_iso]+tauDecayMode+"_"+dir+".png");
    
    TFile *f = new TFile("output/"+era+ "/"+"SingleTauTriggerEff_"+iso[idx_iso]+".root","RECREATE");
    f->cd();
    eff_data->SetName("Data");
    eff_data->Write();
    eff_mc->SetName("MC");
    eff_mc->Write();
    SF->Write();
  }
}