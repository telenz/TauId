#include "TH1.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "../HttStylesNew.cc"
#include <iostream>

void plot_pt_dependent_tau_id_sfs(TString year = "2018"){

  SetStyle();

  const char *wps[4] = { "100-150 GeV", "150-200 GeV", "200-250 GeV", "> 250 GeVt" };

  double x[4]     = { 0.5, 1.5, 2.5, 3.5 };
  double x_err[4] = { 0, 0, 0, 0 };

  // 2017 numbers
  double vloose_2017[4]     = { 1.12, 0.94, 1.05, 0.96 };
  double vloose_err_2017[4] = { 0.13, 0.12, 0.15, 0.15 };

  double medium_2017[4]     = { 0.97, 0.96, 0.69, 0.82 };
  double medium_err_2017[4] = { 0.09, 0.09, 0.12, 0.12 };

  double vtight_2017[4]     = { 0.84, 0.93, 0.58, 0.71 };
  double vtight_err_2017[4] = { 0.08, 0.09, 0.12, 0.12 };

  // 2018 numbers
  double vloose_2018[4]     = { 1.03, 1.28, 0.83, 0.87 };
  double vloose_err_2018[4] = { 0.12, 0.12, 0.13, 0.12 };

  double medium_2018[4]     = { 1.10, 1.03, 0.76, 0.86 };
  double medium_err_2018[4] = { 0.08, 0.09, 0.10, 0.11 };

  double vtight_2018[4]     = { 1.02, 1.04, 0.89, 0.92 };
  double vtight_err_2018[4] = { 0.08, 0.09, 0.12, 0.12 };


  double *vloose, *vloose_err, *medium, *medium_err, *vtight, *vtight_err;

  if( year == "2017" ){
    vloose     = vloose_2017;
    vloose_err = vloose_err_2017;
    medium     = medium_2017;
    medium_err = medium_err_2017;
    vtight     = vtight_2017;
    vtight_err = vtight_err_2017;
  }
  else if( year == "2018" ){
    vloose     = vloose_2018;
    vloose_err = vloose_err_2018;
    medium     = medium_2018;
    medium_err = medium_err_2018;
    vtight     = vtight_2018;
    vtight_err = vtight_err_2018;
  }
  else{
    cout << "No values available for this year. Exit." << endl;
    exit(-1);
  }

  TH1D* h = new TH1D("h","",4,0,4);
  h->SetMaximum(2.0);
  h->SetMinimum(0.3);
  h->GetYaxis()->SetTitle("Scale Factor");
  h->GetYaxis()->SetTitleOffset(1.0);
  for (int i=0;i<4;i++) h->GetXaxis()->SetBinLabel(i+1,wps[i]);

  TGraphErrors* g_vloose = new TGraphErrors( 4, x, vloose, x_err, vloose_err);
  g_vloose->SetTitle("");
  g_vloose->SetLineColor(TColor::GetColor("#FFCC66"));
  g_vloose->SetMarkerColor(TColor::GetColor("#FFCC66"));
  g_vloose->SetMarkerStyle(20);

  TGraphErrors* g_medium = new TGraphErrors( 4, x, medium, x_err, medium_err);
  g_medium->SetTitle("");
  g_medium->SetLineColor(TColor::GetColor("#DE5A6A"));
  g_medium->SetMarkerColor(TColor::GetColor("#DE5A6A"));
  g_medium->SetMarkerStyle(21);

  TGraphErrors* g_vtight = new TGraphErrors( 4, x, vtight, x_err, vtight_err);
  g_vtight->SetTitle("");
  g_vtight->SetLineColor(TColor::GetColor("#03A8F5"));
  g_vtight->SetMarkerColor(TColor::GetColor("#03A8F5"));
  g_vtight->SetMarkerSize(2.5);
  g_vtight->SetMarkerStyle(33);

  TLegend* leg = new TLegend(0.60,0.65,0.90,0.90);
  SetLegendStyle(leg);
  leg->SetTextSize(0.06);
  leg->AddEntry(g_vloose,"VLoose (" + year + ")","lp");
  leg->AddEntry(g_medium,"Medium (" + year + ")","lp");
  leg->AddEntry(g_vtight,"VTight (" + year + ")","lp");

  TCanvas *c1 = new TCanvas("tau_id_sfs","Tau ID SFs comparison across years",10,10,1000,500);
  h->Draw();
  g_vloose->Draw("PL");
  g_medium->Draw("PL");
  g_vtight->Draw("PL");
  leg->Draw();

  c1->SaveAs("../figures/tau_id_sfs_pt_dependece_" + year + ".png");
  c1->SaveAs("../figures/tau_id_sfs_pt_dependece_" + year + ".pdf");

}
