#include "TH1.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "../HttStylesNew.cc"

void compare_results_across_years(){

  SetStyle();

  const char *wps[6] = { "VLoose", "Loose", "Medium", "Tight", "VTight", "VVTight" };

  double x[6]     = {0.5,1.5,2.5,3.5,4.5,5.5};
  double x_err[6] = {0,0,0,0,0,0};

  double id_sfs_2016[6]     = { 1.04, 0.97, 0.91, 0.94, 0.85, 0.82 };
  double id_sfs_err_2016[6] = { 0.09, 0.07, 0.06, 0.06, 0.06, 0.06 };

  double id_sfs_2017[6]     = { 1.04, 0.97, 0.91, 0.94, 0.85, 0.82 };
  double id_sfs_err_2017[6] = { 0.09, 0.07, 0.06, 0.06, 0.06, 0.06 };

  double id_sfs_2018[6]     = { 1.10, 1.01, 1.02, 1.04, 1.01, 0.87 };
  double id_sfs_err_2018[6] = { 0.09, 0.07, 0.07, 0.07, 0.07, 0.06 };

  TH1D* h = new TH1D("h","",6,0,6);
  h->SetMaximum(1.6);
  h->SetMinimum(0.6);
  h->GetYaxis()->SetTitle("Scale Factor");
  h->GetYaxis()->SetTitleOffset(1.0);
  for (int i=0;i<6;i++) h->GetXaxis()->SetBinLabel(i+1,wps[i]);

  TGraphErrors* g_2016 = new TGraphErrors( 6, x, id_sfs_2016, x_err, id_sfs_err_2016);
  g_2016->SetTitle("");
  g_2016->SetLineColor(kBlack);
  g_2016->SetMarkerColor(kBlack);
  g_2016->SetMarkerStyle(21);

  TGraphErrors* g_2017 = new TGraphErrors( 6, x, id_sfs_2017, x_err, id_sfs_err_2017);
  g_2017->SetTitle("");
  g_2017->SetLineColor(kRed);
  g_2017->SetMarkerColor(kRed);
  g_2017->SetMarkerStyle(21);

  TGraphErrors* g_2018 = new TGraphErrors( 6, x, id_sfs_2018, x_err, id_sfs_err_2018);
  g_2018->SetTitle("");
  g_2018->SetLineColor(kBlue);
  g_2018->SetMarkerColor(kBlue);
  g_2018->SetMarkerStyle(21);

  TLegend* leg = new TLegend(0.70,0.70,0.90,0.90);
  SetLegendStyle(leg);
  leg->SetTextSize(0.06);
  //leg->AddEntry(g_2016,"2016 (non-legacy)","lp");
  leg->AddEntry(g_2017,"2017","lp");
  leg->AddEntry(g_2018,"2018","lp");

  TCanvas *c1 = new TCanvas("tau_id_sfs","Tau ID SFs comparison across years",10,10,800,500);
  h->Draw();
  g_2017->Draw("P");
  g_2018->Draw("P");
  leg->Draw();

  c1->SaveAs("../figures/tau_id_sfs_comparison_across_years.png");
  c1->SaveAs("../figures/tau_id_sfs_comparison_across_years.pdf");

}
