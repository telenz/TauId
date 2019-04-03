#include "HttStylesNew.cc"
#include "TStyle.h"
#include "TF2.h"
#include "settings.h"
#include "TMath.h"
#include "Math/QuantFuncMathCore.h"

void ComputeFakeRate() {

  loadWorkingPoints();
  initCuts();

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  vector<Float_t> binsJetPt;
  vector<Float_t> binsRatio;

  std::vector< std::pair<TString,std::vector<TString>> > samples;
  std::vector<TString> data_SingleMuon;
  data_SingleMuon.push_back("SingleMuon_Run2018A");
  data_SingleMuon.push_back("SingleMuon_Run2018B");
  data_SingleMuon.push_back("SingleMuon_Run2018C");
  data_SingleMuon.push_back("SingleMuon_Run2018D");
  std::vector<TString> data_JetHT;
  data_JetHT.push_back("JetHT_Run2018A");
  data_JetHT.push_back("JetHT_Run2018B");
  data_JetHT.push_back("JetHT_Run2018C");
  data_JetHT.push_back("JetHT_Run2018D");
  std::vector<TString> wjets;

  wjets.push_back("WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8");
  wjets.push_back("WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8");

  std::vector<TString> genuineTaus;
  genuineTaus.push_back("TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8");
  genuineTaus.push_back("TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8");
  genuineTaus.push_back("TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8");
  genuineTaus.push_back("ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8");
  genuineTaus.push_back("ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8");
  genuineTaus.push_back("ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8");
  genuineTaus.push_back("ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8");
  genuineTaus.push_back("ZZ_TuneCP5_13TeV-pythia8");
  genuineTaus.push_back("WW_TuneCP5_13TeV-pythia8");
  genuineTaus.push_back("WZ_TuneCP5_13TeV-pythia8");
  genuineTaus.push_back("DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");
  genuineTaus.push_back("DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");
  genuineTaus.push_back("DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");
  genuineTaus.push_back("DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");
  genuineTaus.push_back("DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8");

  samples.push_back(make_pair("WJetsToLNu" , wjets));
  samples.push_back(make_pair("GenuineTausBkg" , genuineTaus));
  samples.push_back(make_pair("SingleMuon" , data_SingleMuon));
  samples.push_back(make_pair("JetHT" , data_JetHT));

  std::map<TString,TH2D*> histoMap;

  for (unsigned int idx_sample=0; idx_sample<samples.size(); ++idx_sample) { // loop over samples

    TFile *fileOutput = new TFile("output/"+samples[idx_sample].first+"_fakeRate"+tauDecayMode+".root","recreate");

    cout<<endl<<"process  "<<samples[idx_sample].first<<" : "<<endl;

    for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){  // loop over WPs

      cout<<endl<<"tau ID :  "<<iso[idx_iso]<<" : "<<endl;

      // Definition of fake factor binning
      vector<Float_t> binsRatio =  { 0.0 , 0.7 , 0.75 , 0.80 , 2.}; // new analysis binning for 2018
      vector<Float_t> binsJetPt;
      // if( iso[idx_iso] == "VVLooseMva2017v2" || iso[idx_iso] == "VLooseMva2017v2" || iso[idx_iso] == "LooseMva2017v2" || iso[idx_iso] == "Loose"){
      // 	binsJetPt = {100 , 140 , 160 , 180 , 200 , 220 , 240 , 260 , 300 , 340 , 380 , 420 , 460 , 500 , 1200}; // analysis binning v3
      // }
      // else                                 binsJetPt = {100 , 160 , 240 , 340 , 1200}; // new analysis binning
      // binsJetPt = {100 , 160 , 240 , 340 , 1200}; // new analysis binning
      binsJetPt = {100 , 160, 240 , 1200}; // new analysis binning for 2018

      int nBinsRatio = binsRatio.size() - 1;
      int nBinsJetPt = binsJetPt.size() - 1;

      TH2D* h_fakerate_2d = new TH2D("h_fakerate_2d_"+iso[idx_iso],"h_fakerate_2d_"+iso[idx_iso],nBinsRatio,&binsRatio[0],nBinsJetPt,&binsJetPt[0]);

      // filling histograms
      TH2D* h_den = new TH2D(samples[idx_sample].first+"_"+iso[idx_iso]+"_den",samples[idx_sample].first+"_"+iso[idx_iso],nBinsRatio,&binsRatio[0],nBinsJetPt,&binsJetPt[0]);
      TH2D* h_num = new TH2D(samples[idx_sample].first+"_"+iso[idx_iso]+"_num",samples[idx_sample].first+"_"+iso[idx_iso],nBinsRatio,&binsRatio[0],nBinsJetPt,&binsJetPt[0]);
      TH2D* h_den_FineBinning = new TH2D(samples[idx_sample].first+"_"+iso[idx_iso]+"_den_FineBinning",samples[idx_sample].first+"_"+iso[idx_iso],200,0,2,110,100,1200);

      TString var1 = "tauPt";
      TString var2 = "tauJetPt";
      TString var3 = "tauJetPt";

      for(unsigned int idx_list=0; idx_list<samples[idx_sample].second.size(); idx_list++){ // loop over processes in samples
	cout<<"---------- Sample "<<samples[idx_sample].second[idx_list]<<" processing. ---------- "<<endl;
	selectionCuts select = cr_fakerate_num;
	cr_fakerate_dijet_num.pfJetTrigger = true;  //if set to true: only events that have been triggered by at least one dijet trigger pass selection
	if(samples[idx_sample].second[idx_list].Contains("JetHT")) select =  cr_fakerate_dijet_num;
	if(samples[idx_sample].first.Contains("Genuine")){
	  select.tauGenMatchDecayLow   = 0;  // a matching to real tau is implicity done
	  select.tauGenMatchDecayHigh  = 100000;
	}
	makeSelection(dir+samples[idx_sample].second[idx_list]+".root","NTuple",getXSec(samples[idx_sample].second[idx_list]),iso[idx_iso],select,h_num,var1,var2,var3);
	select = cr_fakerate_den;
	cr_fakerate_dijet_den.pfJetTrigger = true;
	if(samples[idx_sample].second[idx_list].Contains("JetHT")) select =  cr_fakerate_dijet_den;
	if(samples[idx_sample].first.Contains("Genuine")){
	  select.tauGenMatchDecayLow   = 0;
	  select.tauGenMatchDecayHigh  = 100000;
	}
	makeSelection(dir+samples[idx_sample].second[idx_list]+".root","NTuple",getXSec(samples[idx_sample].second[idx_list]),iso[idx_iso],select,h_den,var1,var2,var3);
	makeSelection(dir+samples[idx_sample].second[idx_list]+".root","NTuple",getXSec(samples[idx_sample].second[idx_list]),iso[idx_iso],select,h_den_FineBinning,var1,var2,var3);
      }

      histoMap[samples[idx_sample].first + "_" + iso[idx_iso]] = (TH2D*) h_num -> Clone();
      histoMap[samples[idx_sample].first + "_" + iso[idx_iso]] -> SetDirectory(0);
      
      double numE = 0;
      double denE = 0;
      double num  = h_num -> IntegralAndError(1,h_num->GetNbinsX(),1,h_num->GetNbinsY(),numE);
      double den  = h_den -> IntegralAndError(1,h_den->GetNbinsX(),1,h_den->GetNbinsY(),denE);

      cout<<samples[idx_sample].first<<" : "<<num<<"/"<<den<<" = "<<num/den<<" +/- "<<numE/den<<" (nevents = "<<h_num->GetEntries()<<"/"<<h_den->GetEntries()<<")"<<endl<<endl;
      
      // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      // Get mean value of ratio or tauJetPt for each defined bin at the beginning of the script

      TH2D* meanValuesRatio = new TH2D("meanValuesRatio"+samples[idx_sample].first+"_"+iso[idx_iso],"meanValuesRatio"+samples[idx_sample].first+"_"+iso[idx_iso],nBinsRatio,&binsRatio[0],nBinsJetPt,&binsJetPt[0]);
      TH2D* meanValuesTauJetPt = new TH2D("meanValuesTauJetPt"+samples[idx_sample].first+"_"+iso[idx_iso],"meanValuesTauJetPt"+samples[idx_sample].first+"_"+iso[idx_iso],nBinsRatio,&binsRatio[0],nBinsJetPt,&binsJetPt[0]);
      for(int i=1; i<=h_den->GetNbinsX(); i++){
	for(int j=1; j<=h_den->GetNbinsY(); j++){
	    h_den_FineBinning  -> GetXaxis()-> SetRangeUser( h_den->GetXaxis() -> GetBinLowEdge(i) , h_den->GetXaxis() -> GetBinLowEdge(i+1));
	    h_den_FineBinning  -> GetYaxis()-> SetRangeUser( h_den->GetYaxis() -> GetBinLowEdge(j) , h_den->GetYaxis() -> GetBinLowEdge(j+1));

	    meanValuesRatio    -> SetBinContent(i,j,h_den_FineBinning -> GetMean(1));
	    meanValuesRatio    -> SetBinError(  i,j,h_den_FineBinning -> GetMeanError(1));
	    meanValuesTauJetPt -> SetBinContent(i,j,h_den_FineBinning -> GetMean(2));
	    meanValuesTauJetPt -> SetBinError(  i,j,h_den_FineBinning -> GetMeanError(2));

	    h_den_FineBinning  -> GetYaxis()-> SetRange();
	    h_den_FineBinning  -> GetXaxis()-> SetRange();
	    // cout<<"mean value ratio  of    "<<i<<". x-bin (ratio) and "<<j<<". y-bin (tauJetPt) : = "<< meanValuesRatio -> GetBinContent(i,j) << " +/- " << meanValuesRatio -> GetBinError(i,j) <<endl;
	    // cout<<"mean value tauJetPt  of "<<i<<". x-bin (ratio) and "<<j<<". y-bin (tauJetPt) : = "<< meanValuesTauJetPt -> GetBinContent(i,j) << " +/- " << meanValuesTauJetPt -> GetBinError(i,j) <<endl;
	}
      }
      // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

      // Subtract genuine taus and get correct error estimates
      bool genuineTauHistoExists = histoMap.find("GenuineTausBkg_"+iso[idx_iso]) != histoMap.end();
      if(samples[idx_sample].first.Contains("SingleMuon") && genuineTauHistoExists) h_num -> Add(histoMap["GenuineTausBkg_"+iso[idx_iso]],-1);

      // Ckeck negative values
      for(int i=1; i<=h_num->GetNbinsX(); i++){
	for(int j=1; j<=h_num->GetNbinsY(); j++){

	  if(h_num->GetBinContent(i,j)<0)  h_num->SetBinContent(i,j,0);
	  if(h_den->GetBinContent(i,j)<0)  h_den->SetBinContent(i,j,0);

	}
      }

      h_fakerate_2d -> Divide(h_num,h_den);

      // %%%%%%%%%%%%%%%%%%%%%%%%%  Get correct error estimates  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      // Calculate statistical uncertainty with correct poisson errors for data samples
      // (see : https://twiki.cern.ch/twiki/bin/viewauth/CMS/PoissonErrorBars)

      TH2D* h_num_up    = (TH2D*) h_num->Clone();
      TH2D* h_num_down  = (TH2D*) h_num->Clone();
      TH2D* h_fakerate_2d_up   = (TH2D*) h_fakerate_2d->Clone();
      TH2D* h_fakerate_2d_down = (TH2D*) h_fakerate_2d->Clone();
      const double alpha = 1 - 0.6827;

      for(int i=1; i<=h_num->GetNbinsX(); i++){
	for(int j=1; j<=h_num->GetNbinsY(); j++){

	  h_num_up   -> SetBinContent(i,j, h_num->GetBinContent(i,j) + h_num->GetBinError(i,j) );
	  h_num_down -> SetBinContent(i,j, h_num->GetBinContent(i,j) - h_num->GetBinError(i,j) );

	  if(samples[idx_sample].first.Contains("WJetsToLNu")){
	    if(h_num->GetBinError(i,j)==0){
	      h_num_up->SetBinContent(i,j,1);
	      h_num_down->SetBinContent(i,j,0);
	    }
	  }
	  else if(samples[idx_sample].first.Contains("JetHT")){
	    int N    = h_num->GetBinContent(i,j);
	    double L =  (N==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2,N,1.));
	    double U =  ROOT::Math::gamma_quantile_c(alpha/2,N+1,1);
	    h_num_up   -> SetBinContent(i,j , U );
	    h_num_down -> SetBinContent(i,j , L );
	  }
	  else if(samples[idx_sample].first.Contains("SingleMuon")){
	    int N    = histoMap["SingleMuon_"+iso[idx_iso]]->GetBinContent(i,j);
	    double L =  (N==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2,N,1.));
	    double U =  ROOT::Math::gamma_quantile_c(alpha/2,N+1,1);
	    double errUp   = U-N;
	    double errDown = N-L;
	    // Now add GenuineTausBkg uncertainy
	    if(genuineTauHistoExists){
	      errUp   = TMath::Sqrt( pow(errUp,2)   + pow(histoMap["GenuineTausBkg_"+iso[idx_iso]]->GetBinError(i,j),2) );
	      errDown = TMath::Sqrt( pow(errDown,2) + pow(histoMap["GenuineTausBkg_"+iso[idx_iso]]->GetBinError(i,j),2) );
	    }
	    if( errDown > h_num->GetBinContent(i,j)) errDown = h_num->GetBinContent(i,j);
	    h_num_up   -> SetBinContent(i,j , h_num->GetBinContent(i,j) + errUp );
	    h_num_down -> SetBinContent(i,j , h_num->GetBinContent(i,j) - errDown );
	  }

	}
      }

      h_fakerate_2d_up   -> Divide(h_num_up,h_den);    // gaussian error propagation not valid -> denominator error has negligible impact
      h_fakerate_2d_down -> Divide(h_num_down,h_den);

      // Statistical precision of fakerate:
      for(int i=1; i<=h_num->GetNbinsX(); i++){
	for(int j=1; j<=h_num->GetNbinsY(); j++){
	  double num_bin      = h_num -> GetBinContent(i,j);
	  double numEup_bin   = h_num_up->GetBinContent(i,j) - h_num->GetBinContent(i,j);
	  double numEdown_bin = h_num->GetBinContent(i,j)    - h_num_down->GetBinContent(i,j);
	  double denE_bin = 0;
	  double den_bin  = h_den -> IntegralAndError(i,i,j,j,denE_bin);
	  cout<<"Numerator   of "<<i<<". x-bin (ratio) and "<<j<<". y-bin (tauJetPt) : "<<num_bin<<" + "<<numEup_bin<<" - "<<numEdown_bin<<endl;
	  //cout<<"Denominator of "<<i<<". x-bin (ratio) and "<<j<<". y-bin (tauJetPt) : "<<den_bin<<" +/- "<<denE_bin<<endl;
	}
      }

      // %%%%%%%%%%%%%%%%%% Plotting %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      h_fakerate_2d->GetXaxis()->SetTitle("pt (tau) / pt (jet faking the tau)");
      h_fakerate_2d->GetYaxis()->SetTitle("pt (jet faking the tau)");
      h_fakerate_2d->GetZaxis()->SetTitle("fake rate");
      h_fakerate_2d->SetTitle("");
      h_fakerate_2d->SetMarkerSize(2);
      h_fakerate_2d->SetMaximum(1);
      h_fakerate_2d->SetMinimum(0);

      gStyle -> SetPadBottomMargin(0.17);
      gStyle -> SetPadLeftMargin(0.17);
      gStyle -> SetPadTopMargin(0.12);
      gStyle -> SetPadRightMargin(0.20);

      TCanvas * canv = new TCanvas("canv","",700,600);
      h_fakerate_2d->Draw("COLZ");

      TLegend * leg = new TLegend(0.25,0.7,0.85,0.9);
      SetLegendStyle(leg);
      leg->SetTextSize(0.05);
      leg->SetHeader(iso[idx_iso]);
      leg->AddEntry(h_fakerate_2d,samples[idx_sample].first,"lp");
      leg->Draw();
      canv->Update();
      //canv->Print("figures/fakerate_"+samples[idx_sample].first+"_"+iso[idx_iso]+tauDecayMode+".png");

      // Make 1d plots dependent on tauPt/tauJetPt 
      TH1D* h_num_1D_x        = h_num -> ProjectionX("fakerate_projection_withTrig_num_x",1,nBinsRatio);
      TH1D* h_den_1D_x        = h_den -> ProjectionX("fakerate_projection_withTrig_den_x",1,nBinsRatio);
      TH1D* h_num_1D_y        = h_num -> ProjectionY("fakerate_projection_withTrig_num_y",1,nBinsJetPt);
      TH1D* h_den_1D_y        = h_den -> ProjectionY("fakerate_projection_withTrig_den_y",1,nBinsJetPt);

      TH1D* h_x = (TH1D*) h_num_1D_x->Clone();
      h_x->Divide(h_den_1D_x);
      TH1D* h_y = (TH1D*) h_num_1D_y->Clone();
      h_y->Divide(h_den_1D_y);

      h_x->SetMaximum(1.);
      h_x->SetMinimum(0.000001);
      h_y->SetMaximum(1.);
      h_y->SetMinimum(0.000001);
      h_x->Draw();

      //canv->SetLogy();
      TLegend * leg1 = new TLegend(0.35,0.2,0.89,0.4);
      SetLegendStyle(leg1);
      leg1->SetHeader(iso[idx_iso]);
      leg1->AddEntry(h_x,"fake factors","lp");
      leg1->Draw();
      //canv->Print("figures/fakerate_"+samples[idx_sample].first+"_"+iso[idx_iso]+tauDecayMode+"_projectionX_ratioDependence.png");

      canv->cd();
      h_y->Draw();
      leg1->Draw();
      //canv->Print("figures/fakerate_"+samples[idx_sample].first+"_"+iso[idx_iso]+tauDecayMode+"_projectionY_tauJetPtDependence.png");

       TH1D* h_unrolled = new TH1D("h_unrolled_"+samples[idx_sample].first+"_"+iso[idx_iso],"unrolled distribution",nBinsRatio*nBinsJetPt,1,nBinsRatio*nBinsJetPt+1);

       int index=1;
       for(int i=1; i<=nBinsRatio; i++){
          for(int j=1; j<=nBinsJetPt; j++){
             double b    = h_fakerate_2d->GetBinContent(i,j);
             double bErr = h_fakerate_2d->GetBinError(i,j);

             h_unrolled        -> SetBinContent(index,b);
             h_unrolled        -> SetBinError(index,bErr);

	  index += 1;
	}
      }
      canv->cd();
      canv->Clear();
      TPad * upper = new TPad("upper", "pad",0,0.29,1,1);
      upper->Draw();
      upper->cd();
      h_unrolled->GetYaxis()->SetTitle("fake rate");
      h_unrolled->GetXaxis()->SetTitle("bin number");
      h_unrolled->Draw();

      leg1->Draw("same");
      upper->SetLogy();
      upper->Draw("same");
      upper->RedrawAxis();
      upper->Modified();
      upper->Update();
      canv->cd();
      TH1D* ratio = (TH1D*) h_unrolled->Clone("ratio_"+samples[idx_sample].first+"_"+iso[idx_iso]);
      ratio->GetYaxis()->SetTitle("low pt/all");
      ratio->GetXaxis()->SetTitle("");
      ratio->GetYaxis()->CenterTitle();
      ratio->GetYaxis()->SetRangeUser(0,4);
      TPad * lower = new TPad("lower", "pad",0,0,1,0.29);
      lower->Draw();
      lower->cd();
      lower->SetGridy();
      ratio->SetLineColor(kBlack);
      ratio->SetMarkerColor(kBlack);
      ratio->Draw();
      lower->Modified();
      lower->RedrawAxis();
      canv->cd();
      canv->Modified();
      canv->cd();
      canv->SetSelected(canv);
      canv->Update();
      canv->Print("figures/Unrolled_fakerate_differences_" + iso[idx_iso] + tauDecayMode+ ".png");

      // %%%%%%%%%%%%%%%%%%%%%%%%%  Write fake rates to root file %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
      fileOutput->cd("");
      h_fakerate_2d->SetName(iso[idx_iso]);
      h_fakerate_2d->Write(iso[idx_iso]);
      h_fakerate_2d_up->SetName(iso[idx_iso]+"_Up");
      h_fakerate_2d_up->Write(iso[idx_iso]+"_Up");
      h_fakerate_2d_down->SetName(iso[idx_iso]+"_Down");
      h_fakerate_2d_down->Write(iso[idx_iso]+"_Down");
      h_x->SetName(iso[idx_iso]+"_ProjX");
      h_x->Write(iso[idx_iso]+"_ProjX");
      h_y->SetName(iso[idx_iso]+"_ProjY");
      h_y->Write(iso[idx_iso]+"_ProjY");
      meanValuesRatio->SetName(iso[idx_iso]+"meanValuesRatio");
      meanValuesRatio->Write(iso[idx_iso]+"meanValuesRatio");
      meanValuesTauJetPt->SetName(iso[idx_iso]+"meanValuesTauJetPt");
      meanValuesTauJetPt->Write(iso[idx_iso]+"meanValuesTauJetPt");
      delete canv;
      cout<<endl;

      delete h_num;
      delete h_den;
      delete h_num_1D_x;
      delete h_den_1D_x;
      delete h_num_1D_y;
      delete h_den_1D_y;
      delete h_x;
      delete h_y;
    } // end of loop over WPs
    fileOutput->Close();
  } // end of loop over samples
} // end of program
