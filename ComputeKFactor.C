#include "HttStylesNew.cc"
#include "TFile.h"
#include "TH1.h"
#include <iostream>

// sigma(mu) = 5.92
// sigma(tau) = 6.37
void ComputeKFactor(TString lepton = "mu",
		    TString inputFileName = "NTuples/WToMuNu_M-200_TuneCP5_13TeV-pythia8",
		    float xsec=7.273) {
  
  SetStyle();
  TFile * fileNNLO = new TFile("StoredN_NLO_hists.root"); // comes from Klaas Padeken (see here : https://github.com/padeken/k-Factor_calulations)
  TH1D * qcd_nnlo  = (TH1D*)fileNNLO->Get("QCD_NNLO_FEWZ");  // FEWZ QCD corrections -> What is stored here ?? is it a cross section ??
  TH1D * ewk_nlo   = (TH1D*)fileNNLO->Get("QCD_LO_EW_NLO_PhotonPDF_"+lepton+"_mcsanc"); // comes this from MCFM ???
  TH1D * lo        = (TH1D*)fileNNLO->Get("QCD_LO_EW_LO_PhotonPDF_mcsanc");   // can this be replaced by our LO distribution ??   

  TFile * fileW = new TFile(inputFileName+".root");
  TH1D * wmass  = (TH1D*)fileW->Get("WMassH"); // Comes from our W* sample (no cuts applied on this)
  TH1D * inputEventsH = (TH1D*)fileW->Get("histWeightsH"); // Total number of events in the W* sample before any cuts
  double norm   = xsec/inputEventsH->GetSumOfWeights(); // Get relative cross section fraction of each bin
  wmass    -> Scale(norm);

  qcd_nnlo -> Rebin(10);
  ewk_nlo  -> Rebin(10);
  lo       -> Rebin(10);
  wmass    -> Rebin(10);

  TH1D * kfactor = (TH1D*) wmass -> Clone("kfactor");

  for (int i=3; i<=10; ++i) {

    double xsec_qcd_nnlo = qcd_nnlo->GetBinContent(i);
    double xsec_ewk_nlo  = ewk_nlo->GetBinContent(i);
    double xsec_lo       = lo->GetBinContent(i);
    double xsec_sum  = xsec_qcd_nnlo + xsec_ewk_nlo - xsec_lo; // sum up NNLO QCD, NLO EWK, and LO cross sections
    double xsec_prod = xsec_qcd_nnlo*xsec_ewk_nlo/xsec_lo; // Calculate the relative NNLO/NLO to LO cross section
    double xsec_nnlo = 0.5*(xsec_sum+xsec_prod);
    double xsec_err  = 0.5*fabs(xsec_sum-xsec_prod);
    double reference = wmass->GetBinContent(i);

    cout << i << " : NNLO = " << xsec_nnlo << "   MG5LO = " << reference << "  k-factor = " << xsec_nnlo/reference << " +/- " << xsec_err/reference << endl;

    kfactor -> SetBinError(i,0);
    kfactor -> SetBinContent(i,xsec_nnlo/reference);
    kfactor -> SetBinError(i,0.5*xsec_err/reference);
  }

  kfactor -> Draw("e1");
  TFile * file = new TFile("kfactor_"+lepton+".root","recreate");
  kfactor->SetName("kfactor_"+lepton);
  kfactor->Write("kfactor_"+lepton);
  file->Write();
  file->Close();
  kfactor->GetXaxis()->SetRangeUser(0,1000);
  kfactor->GetXaxis()->SetTitle("m_{W} [GeV]");
  kfactor->GetYaxis()->SetTitle("k factor");
  gPad->SaveAs("kfactor_"+lepton+".pdf");
}
