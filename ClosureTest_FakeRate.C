#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include "settings.h"

#include <iostream>
#include "TTree.h" 
#include "TFile.h" 
#include "TH2.h"
#include "TH1.h"

using namespace std;

void ClosureTest_FakeRate() {

  TString fakerateFile  = "output/WJetsToLNu_fakeRate"+tauDecayMode+".root";

  loadWorkingPoints();
  initCuts();
  loadFakeRates(fakerateFile);

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  std::vector<TString> obs = ZJets_sample;
  std::vector<TString> pred = ZJets_sample;
  obs.insert(  obs.end() , WJets_closure_sample.begin(), WJets_closure_sample.end() );
  pred.insert( pred.end(), WJets_closure_sample.begin(), WJets_closure_sample.end() );

  std::vector<double> obs_xsec;
  for(unsigned int i=0; i<obs.size(); i++) obs_xsec.push_back( getXSec(obs[i]) );
  
  std::vector<double> pred_xsec;
  for(unsigned int i=0; i<pred.size(); i++) pred_xsec.push_back( getXSec(pred[i]) );

  // Binning and titles of axis
  TString xtitle = "m_{T} [GeV]";
  //TString xtitle = "p_{T}^{#tau} [GeV]";
  TString ytitle = "Events / 100 GeV";

  TString var1 = "mttau";
  TString var2 = var1;

  //Float_t bins[] = {100,150,200,250,300,400,500};  // tauPt binning
  //Float_t bins[] = {100,200,300,400,500,700};  // met binning
  //Float_t bins[] = {100,140,180,220,260,300,340,380,420,460,500,600,800}; // tauJetPt + tauPt + met fine binning
  Float_t bins[] = {200,300,400,500,600,800};  // mttau binning
  //Float_t bins[] = {200,250,300,350,400,450,500,550,600,650,700,750,800};  // fine mttau binning
  //Float_t bins[] = {0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8};  // tauMass binning 3prong
  //Float_t bins[] = {0.0, 0.2, 0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8, 2.0, 2.2, 2.4};  // tauMass binning
  //Float_t bins[] = {0.05,0.1,0.125,0.15,0.2,0.25,0.3}; //tauMass binning 1prong 0pizeros
  //Float_t bins[] = {0,0.5,1.1,2.3}; //tauEta binning
  //Float_t bins[] = {0.0,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95,1.0,2.0}; //ratio binning
  const int nBins = sizeof(bins)/sizeof(Float_t) - 1;
  
  for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){

    cout<<endl<<endl<<"........................... Processing "<<iso[idx_iso]<<endl;

    TH1D * observation = new TH1D("observation_"+iso[idx_iso],"",nBins,bins); 
    TH1D * prediction  = new TH1D("prediction_"+iso[idx_iso],"",nBins,bins); 

    // Make selection and fill histograms for sr and cr
    for (unsigned int i=0; i<obs.size(); ++i) { //W+jets and Znuu main backgrounds, check how many fakes we select in our SR
      TH1D* histo = new TH1D("obs_" + obs[i],"",nBins,bins);
      makeSelection(dir+"/"+obs[i]+".root","NTuple",obs_xsec[i],iso[idx_iso],sr_fakeTaus,histo,var1,var2,var2);
      observation->Add(histo);
      observation->SetName(histo->GetName());
      delete histo;
    }
    for (unsigned int i=0; i<pred.size(); ++i) {//fake factors are applied in makeselection

      loadFakeRates(fakerateFile);
      TH1D* histo = new TH1D("pred_" + pred[i],"",nBins,bins);
      makeSelection(dir+"/"+pred[i]+".root","NTuple",pred_xsec[i],iso[idx_iso],cr_antiiso,histo,var1,var2,var2);

      h_fakerate->at(iso[idx_iso]) = h_fakerate_up->at(iso[idx_iso]+"_Up");
      TH1D* histoUp = new TH1D("pred_" + pred[i] + "_Up","",nBins,bins);
      makeSelection(dir+"/"+pred[i]+".root","NTuple",pred_xsec[i],iso[idx_iso],cr_antiiso,histoUp,var1,var2,var2);

      h_fakerate->at(iso[idx_iso]) = h_fakerate_down->at(iso[idx_iso]+"_Down");
      TH1D* histoDown = new TH1D("pred_" + pred[i] + "_Down","",nBins,bins);
      makeSelection(dir+"/"+pred[i]+".root","NTuple",pred_xsec[i],iso[idx_iso],cr_antiiso,histoDown,var1,var2,var2);

      // Set correct uncertainties
      for(int i=1; i<histo->GetNbinsX(); i++){
	histo->SetBinError(i , sqrt( pow(histo->GetBinError(i),2) + pow(abs(histoUp->GetBinContent(i) - histoDown->GetBinContent(i))/2,2)) );
      }

      prediction->Add(histo);
      delete histo;
      delete histoUp;
      delete histoDown;
    }

    double obsE, predE;
    double nObs  = observation -> IntegralAndError(1,observation->GetNbinsX(),obsE);
    double nPred = prediction  -> IntegralAndError(1,prediction->GetNbinsX(),predE);

    cout<<"Observation : "<<nObs<< " +/- "<<obsE<< " (nevents = "<<observation->GetEntries()<<") "<<endl;
    cout<<"Prediction  : "<<nPred<<" +/- "<<predE<<" (nevents = "<<prediction ->GetEntries()<<") "<<endl;

    TCanvas * canv1 = MakeCanvas("canv1", "", 700, 800);
    TPad * upper = new TPad("upper", "pad",0,0.29,1,1);
    upper->Draw();
    upper->cd();
    observation->GetYaxis()->SetTitle("Events");
    prediction->SetLineColor(kRed);
    prediction->SetMarkerColor(kRed);
    prediction->SetFillStyle(0);

    observation->SetMinimum(1);
    observation->GetXaxis()->SetTitle(observation->GetName());
    observation->Draw("e1");
    prediction->Draw("sameh");
    if(prediction->GetMaximum()>observation->GetMaximum()){
      observation->SetMaximum(prediction->GetMaximum()*1.2);
    }

    TLegend * leg = new TLegend(0.45,0.65,0.85,0.9);
    SetLegendStyle(leg);
    leg->SetTextSize(0.047);
    leg->SetHeader(iso[idx_iso]);
    leg->AddEntry(observation,"observation","lp");
    leg->AddEntry(prediction,"prediction","lp");
    leg->Draw();
    writeExtraText = true;
    
    upper->Draw("SAME");
    upper->RedrawAxis();
    upper->Modified();
    upper->Update();
    canv1->cd();

    TH1D * ratioH = (TH1D*)observation->Clone("ratioH");
    ratioH->Divide(prediction);
    ratioH->SetMarkerColor(1);
    ratioH->SetMarkerStyle(20);
    ratioH->SetMarkerSize(1.2);
    ratioH->SetLineColor(1);
    ratioH->GetYaxis()->SetRangeUser(0.0,2.0);
    ratioH->GetYaxis()->SetTitle("obs/pred");
    ratioH->GetXaxis()->SetTitle("");
    ratioH->GetYaxis()->CenterTitle();
    // ------------>Primitives in pad: lower
    TPad * lower = new TPad("lower", "pad",0,0,1,0.30);
    lower->Draw();
    lower->cd();
    lower->SetGridy();
    ratioH->Draw("e1");
    TLine *line = new TLine(bins[0],1,bins[nBins],1);
    line->Draw("same");

    lower->Modified();
    lower->RedrawAxis();
    canv1->cd();
    canv1->Modified();
    canv1->cd();
    canv1->SetSelected(canv1);
    canv1->Update();
    canv1->Print("figures/"+(TString)observation->GetName()+"_"+iso[idx_iso]+tauDecayMode+"_WToTauNu_closure.png");
    delete canv1;

    // Save ratio plot as root file
    TFile *outFile = new TFile("output/"+(TString)observation->GetName()+"_"+iso[idx_iso]+"_WToTauNu_closure"+tauDecayMode+".root","RECREATE");
    outFile -> cd();
    ratioH  -> Write();
    outFile -> Close();
    delete outFile;

    delete observation;
    delete prediction;

    std::cout << std::endl;

   }
}
