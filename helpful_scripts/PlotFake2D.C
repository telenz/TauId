#include "HttStyles2D.cc"
// LooseMva2017v2
// MediumMva2017v2
// TightMva2017v2
// VTightMva2017v2

void PlotFake2D(TString iso = "MediumDeepTau2017v2p1",
		double yMax = 0.8) {


  SetStyle();
  TFile * file = new TFile("/nfs/dust/cms/user/mameyer/TauIdAndES_ULData/TauId/output/fakerates.root");
  TFile * fileW = new TFile("/nfs/dust/cms/user/mameyer/TauIdAndES_ULData/TauId/output/SingleMuon_fakeRate.root");
  TFile * fileQCD = new TFile("/nfs/dust/cms/user/mameyer/TauIdAndES_ULData/TauId/output/JetHT_fakeRate.root");

  TH2D * hist    = (TH2D*)file->Get(iso);
  TH2D * histW   = (TH2D*)fileW->Get(iso);
  TH2D * histQCD = (TH2D*)fileQCD->Get(iso);
  TH2D * hist_Up = (TH2D*)file->Get(iso+"_Up");
  
  int nBinsX = hist->GetNbinsX();
  int nBinsY = hist->GetNbinsY();

  int nBins = nBinsX*(nBinsY);

  TH1D * hist1D    = new TH1D("hist1D","",nBins,0.,double(nBins));
  TH1D * histW1D   = new TH1D("histW1D","",nBins,0.,double(nBins));
  TH1D * histQCD1D = new TH1D("histQCD1D","",nBins,0.,double(nBins));
  TH1D * hist1DUp    = new TH1D("hist1D","",nBins,0.,double(nBins));

  int iBin = 0;
  for (int yB=1; yB<=nBinsY; ++yB) {
     for (int xB=1; xB<=nBinsX; ++xB) {
        // if (histW->GetBinContent(xB,yB)>0.7)
        //    histW->SetBinContent(xB,yB,0.001);
        // if (hist->GetBinContent(xB,yB)>0.7)
        //    hist->SetBinContent(xB,yB,0.002);
      
      double x = hist->GetBinContent(xB,yB);
      
      
      double xW = histW->GetBinContent(xB,yB);
      double eW = histW->GetBinError(xB,yB);

      if (xW<0.1e-5) {
	xW = 0.001;
	eW = yB*0.005+xB*0.005;
	x = xW;
      }      

      double xQCD = histQCD->GetBinContent(xB,yB);
      double eQCD = histQCD->GetBinError(xB,yB);

      double e = 0.75*eW;

      std::cout << "["<<xB<<","<<yB<<"] -> W = " << xW << "+/-" << eW 
		<< "   QCD = " << xQCD << "+/-" << eQCD 
		<< "   Cmb = " << x << "+/-" << e << std::endl;

      iBin++;

      hist1D->SetBinContent(iBin,x);
      histW1D->SetBinContent(iBin,xW);
      histQCD1D->SetBinContent(iBin,xQCD);

      hist1D->SetBinError(iBin,e);
      histW1D->SetBinError(iBin,eW);
      histQCD1D->SetBinError(iBin,eQCD);

    }
  }
  hist1D->SetMarkerColor(1);
  histW1D->SetMarkerColor(2);
  histQCD1D->SetMarkerColor(4);

  hist1D->SetLineColor(1);
  histW1D->SetLineColor(2);
  histQCD1D->SetLineColor(4);

  hist1D->SetMarkerSize(1.6);
  histW1D->SetMarkerSize(1.6);
  histQCD1D->SetMarkerSize(1.6);

  hist1D->SetMarkerStyle(20);
  histW1D->SetMarkerStyle(21);
  histQCD1D->SetMarkerStyle(22);

  //  double yMax = hist1D->GetMaximum();
  //  if (histW1D->GetMaximum()>yMax) yMax = histW1D->GetMaximum();
  //  if (histQCD1D->GetMaximum()>yMax) yMax = histQCD1D->GetMaximum();
  //  

  TString labels[4] = {"r<0.7 ","0.7<r<0.75 ","0.75<r<0.8 ","r>0.8 "};
  for (int iB=0; iB<nBins; ++iB) {
    int iL = iB % 4;
    hist1D->GetXaxis()->SetBinLabel(iB+1,labels[iL]);
  }
  hist1D->GetXaxis()->SetLabelSize(0.05);

  //  hist->GetZaxis()->SetRangeUser(0.0,20);
  hist1D->GetYaxis()->SetRangeUser(0.0,0.35);
  hist1D->GetYaxis()->SetTitle("Fake factor");
  hist1D->GetXaxis()->SetTitleOffset(1.1);
  hist1D->GetYaxis()->SetTitleOffset(0.8);
  hist1D->GetXaxis()->LabelsOption("v");
  TCanvas * canv = new TCanvas("canv","canv",1200,600);

  hist1D->Draw("e1");
  histW1D->Draw("e1same");
  histQCD1D->Draw("e1same");
  hist1D->Draw("e1same");

  TLegend * leg = new TLegend(0.8,0.6,1.03,0.9);
  SetLegendStyle(leg);
  leg->SetHeader(iso);
  leg->SetTextSize(0.045);
  leg->AddEntry(histW1D,"W#rightarrow#mu#nu+1jet","lp");
  leg->AddEntry(histQCD1D,"dijet","lp");
  leg->AddEntry(hist1D,"combined","lp");
  leg->Draw();

  TString labelsBins[3] = {"100<p_{T}^{jet}<160 GeV",
			   "160<p_{T}^{jet}<240 GeV",
			   "p_{T}^{jet}>240 GeV"};
  
  for (int iL=0; iL<=2; ++iL) {
    TLine * line = new TLine(4*(iL+1),-0.4,4*(iL+1),yMax);
    line->SetLineStyle(3);
    double xTex = 3+4*iL;
    TLatex * binTex = new TLatex(xTex,0.5*yMax,labelsBins[iL]);
    binTex->SetTextAngle(90);
    binTex->SetTextSize(0.04);
    binTex->Draw();
    line->Draw();
  }

  //  canv->SetLogy(true);
  canv->Update();
  //  canv->Print("FakeRate_"+iso+"Iso_ratio.pdf","Portrait pdf");
  canv->Print("FakeRate_"+iso+"Iso_ratio.png");

}
