#include "HttStylesNew.cc"
#include "settings_era_specific_2018.h"
#include <vector>
#include <map> 
// decayMode = 0 : inclusive
// decayMode = 1 : 1prong
// decayMode = 2 : 1prong1pizero
// decayMode = 3 : 3prong
// taubyMediumDeepTau2017v2p1VSjet
// taubyTightDeepTau2017v2p1VSjet
void ComputeFakeRate_TauPt(TString iso="taubyMediumDeepTau2017v2p1VSjet",
			   float ymax = 1.0, 
			   bool withTrigger = false,
			   bool subtractGenuineTaus = true,
			   int decayMode = 0,
			   bool logX = true,
			   bool isDijet = true) {

  TString antiMuDiscriminant("taubyLooseDeepTau2017v2p1VSmu");
  TString antiEleDiscriminant("taubyTightDeepTau2017v2p1VSe");

  std::map<int,TString> postfixDM = {
    {0,"_inclusive"},
    {1,"_1prong"},
    {2,"_1prongpi0s"},
    {3,"_3prong"},
  };

  std::map<int,TString> cutDM = {
    {0,""},
    {1,"&&tauDecay==0"},
    {2,"&&(tauDecay==1||tauDecay==2||tauDecay==3)"},
    {3,"&&(tauDecay==10||tauDecay==11)"},
  };

  if (decayMode<0||decayMode>3) {
    std::cout << "Unspecified DM : " << decayMode << std::endl;
  }

  TString postfix = postfixDM[decayMode];
  std::cout << std::endl;
  std::cout << "Postfix = " << postfix << std::endl;
  std::cout << "CutDM = " << cutDM[decayMode] << std::endl;
  std::cout << std::endl;

  bool logY = false;
  double lumi = 59740;
    
  int nBins = 9;
  double bins[10] = {100,120,140,160,180,200,225,250,300,2000};
  if (decayMode==1) {
    nBins = 3;
    bins[1] = 140;
    bins[2] = 250;
    bins[3] = 2000;
  }
  if (decayMode==2) {
    nBins = 5;
    bins[1] = 140;
    bins[2] = 180;
    bins[3] = 225;
    bins[4] = 300;
    bins[5] = 2000;
  }
  if (decayMode==3) {
    nBins = 5;
    bins[1] = 140;
    bins[2] = 180;
    bins[3] = 225;
    bins[4] = 300;
    bins[5] = 2000;
  }


  TString variable="tauPt";
  TString xtitle="p_{T} [GeV]";

  //TString dir = "./";

  float xmin =  100.;
  float xmax = 2000.;

  TString DataFile("SingleMuon_Run2018");
  TString suffix("_wjets");
  if (isDijet) {
      DataFile="JetHT_Run2018";
      suffix = "_dijet";
  }

  // ****************** Cuts for W->muv+jet ************************
  TString   selCuts("Selection==1&&metFilters&&nMuon==1&&nElec==0&&nJetsCentral30<=1&&nSelTaus==1&&tauPt>100&&recoilDPhi>2.8&&mttau>40"); 
  TString selCutsMC("Selection==1&&metFilters&&nMuon==1&&nElec==0&&nJetsCentral30<=1&&nSelTaus==1&&tauPt>100&&recoilDPhi>2.8&&mttau>40");

  selCuts += cutDM[decayMode];
  selCutsMC += cutDM[decayMode];

  if (isDijet) {
  // ****************** Cuts for dijet events ************************
    selCuts =   "Selection==4&&nMuon==0&&nElec==0&&nSelTaus==1&&nJetsCentral30<=2&&tauPt>100&&recoilDPhi>2.8&&tauPt>100";
    selCutsMC = "Selection==4&&nMuon==0&&nElec==0&&nSelTaus==1&&nJetsCentral30<=2&&tauPt>100&&recoilDPhi>2.8&&tauPt>100";
  }

  if (withTrigger) {
    //             tauSinglePFTau180Trk50  tauSinglePFTau180Trk50oneprong
    selCuts += "&&(tauSinglePFTau180Trk50||tauSinglePFTau180Trk50oneprong)";
    selCutsMC += "&&(tauSinglePFTau180Trk50||tauSinglePFTau180Trk50oneprong)";
  }

  TString numCuts("&&tauNewDM>0.5&&"+antiMuDiscriminant+">0.5&&"+antiEleDiscriminant+">0.5&&"+iso+">0.5&&taubyVVVLooseDeepTau2017v2p1VSjet>0.5");
  TString denCuts("&&tauNewDM>0.5&&"+antiMuDiscriminant+">0.5&&"+antiEleDiscriminant+"&&"+iso+"<0.5&&taubyVVVLooseDeepTau2017v2p1VSjet>0.5");

  TString fakeTauMCCuts   ("&&tauGenMatchDecay<0");
  TString genuineTauMCCuts("&&tauGenMatchDecay>=0");

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  TString sampleNames[30] = {
    DataFile, // data (0)
    "WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8",// 1
    "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",// 2
    "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",// 3
    "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",// 4
    "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",// 5
    "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",// 6
    "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",// 7
    "DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",// 8
    "DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",// 9
    "DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",// 10
    "DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",// 11
    "ZJetsToNuNu_HT-100To200_13TeV-madgraph",// 12
    "ZJetsToNuNu_HT-200To400_13TeV-madgraph",// 13
    "ZJetsToNuNu_HT-400To600_13TeV-madgraph",// 14
    "ZJetsToNuNu_HT-600To800_13TeV-madgraph",// 15
    "ZJetsToNuNu_HT-800To1200_13TeV-madgraph",// 16
    "ZJetsToNuNu_HT-1200To2500_13TeV-madgraph",// 17
    "ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph",// 18
    "TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8",// 19
    "TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8",// 20
    "TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8",// 21
    "ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8", // 22
    "ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8", // 23
    "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8", // 24
    "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8", // 25
    "WW_TuneCP5_13TeV-pythia8", // 26
    "WW_TuneCP5_13TeV-pythia8", // 27
    "ZZ_TuneCP5_13TeV-pythia8",  // 28
    "",
  };

  TString cutsNum[30];
  TString cutsDen[30];
  TString cutsNumSub[30];
  TString cutsDenSub[30];
  for (int i=1; i<30; ++i) {
    cutsNum[i] = "puWeight*genWeight*("+selCutsMC+numCuts+fakeTauMCCuts+")";
    cutsDen[i] = "puWeight*genWeight*("+selCutsMC+denCuts+fakeTauMCCuts+")";
    cutsNumSub[i] = "puWeight*genWeight*("+selCutsMC+numCuts+genuineTauMCCuts+")";
    cutsDenSub[i] = "puWeight*genWeight*("+selCutsMC+denCuts+genuineTauMCCuts+")";
  }
  cutsNum[0] = selCuts+numCuts;
  cutsDen[0] = selCuts+denCuts;

  TH1D * histNum[30];
  TH1D * histDen[30];
  TH1D * histNumSub[30];
  TH1D * histDenSub[30];

  TCanvas * dummy = new TCanvas("dummy","",500,500);

  int nSamples = 29;
  // filling histograms

  for (int i=0; i<nSamples; ++i) {
    TString DIR = dir;
    TFile * file = new TFile(DIR+"/"+sampleNames[i]+".root");
    TH1D * histWeightsH = (TH1D*)file->Get("histWeightsH");
    TTree * tree = (TTree*)file->Get("NTuple");
    double norm = 1;
    if (i>1) norm = xsecs[sampleNames[i]]*lumi/histWeightsH->GetSumOfWeights();
    TString histNameNum = sampleNames[i] + "_Num";
    TString histNameDen = sampleNames[i] + "_Den";
    TString histNameNumSub = sampleNames[i] + "_NumSub";
    TString histNameDenSub = sampleNames[i] + "_DenSub";
    histNum[i] = new TH1D(histNameNum,"",nBins,bins);
    histDen[i] = new TH1D(histNameDen,"",nBins,bins);
    histNumSub[i] = new TH1D(histNameNumSub,"",nBins,bins);
    histDenSub[i] = new TH1D(histNameDenSub,"",nBins,bins);
    histNum[i]->Sumw2();
    histDen[i]->Sumw2();
    histNumSub[i]->Sumw2();
    histDenSub[i]->Sumw2();
    tree->Draw(variable+">>"+histNameNum,cutsNum[i]);
    tree->Draw(variable+">>"+histNameDen,cutsDen[i]);
    tree->Draw(variable+">>"+histNameNumSub,cutsNumSub[i]);
    tree->Draw(variable+">>"+histNameDenSub,cutsDenSub[i]);
    std::cout << sampleNames[i] << " : " << "  norm=" << norm  << "    num=" << histNum[i]->GetEntries() << "    den=" << histDen[i]->GetEntries() << std::endl;
    if (i==0) norm = 1;
    if (i>0) {
      for (int iB=1; iB<=nBins; ++iB) {
	double x = histNum[i]->GetBinContent(iB);
	double e = histNum[i]->GetBinError(iB);
    	histNum[i]->SetBinContent(iB,norm*x);
    	histNum[i]->SetBinError(iB,norm*e);

	x = histDen[i]->GetBinContent(iB);
	e = histDen[i]->GetBinError(iB);
    	histDen[i]->SetBinContent(iB,norm*x);
    	histDen[i]->SetBinError(iB,norm*e);

	x = histNumSub[i]->GetBinContent(iB);
	e = histNumSub[i]->GetBinError(iB);
    	histNumSub[i]->SetBinContent(iB,norm*x);
    	histNumSub[i]->SetBinError(iB,norm*e);

	x = histDenSub[i]->GetBinContent(iB);
	e = histDenSub[i]->GetBinError(iB);
    	histDenSub[i]->SetBinContent(iB,norm*x);
    	histDenSub[i]->SetBinError(iB,norm*e);
      }
    }
  }

  for (int i=2; i<nSamples; ++i) {
    histNum[1]->Add(histNum[1],histNum[i]);
    histDen[1]->Add(histDen[1],histDen[i]);
  }
 
  
  if (subtractGenuineTaus) {
    for (int i=1; i<nSamples; ++i) {
      histNum[0]->Add(histNum[0],histNumSub[i],1,-1);
      histDen[0]->Add(histDen[0],histDenSub[i],1,-1);
    }
  }
  

  double dataNum = histNum[0]->GetSumOfWeights();
  double dataDen = histDen[0]->GetSumOfWeights(); 

  double wjetsNum = histNum[1]->GetSumOfWeights();
  double wjetsDen = histDen[1]->GetSumOfWeights();
  double wjetsE2 = 0;
  for (int iB=1;iB<=nBins;++iB) {
    double error = histNum[1]->GetBinError(iB);
    wjetsE2 += error*error;
  }
  double wjetsE = TMath::Sqrt(wjetsE2);

  delete dummy;

  std::cout << std::endl;
  std::cout << "Fake rates -> " << std::endl;
  std::cout << "Data      : " << int(dataNum) << "/" 
	    << int(dataDen) << " = " << dataNum/(dataDen+1e-4) 
	    << "+/-" << TMath::Sqrt(dataNum)/(dataDen+1e-4) << std::endl;
  std::cout << "W->lv     : " << int(wjetsNum)
	    << "/" << int(wjetsDen) << " = " << wjetsNum/(wjetsDen+1e-4) 
	    << " +/- " << wjetsE/(wjetsDen+1e-4) << std::endl;
  std::cout << std::endl;  

  TH1D * eff = (TH1D*)histNum[0]->Clone("eff");
  eff->Divide(histNum[0],histDen[0]);
  eff->SetMarkerStyle(20);
  eff->SetMarkerColor(1);
  eff->SetMarkerSize(2);

  TH1D * effMC = (TH1D*)histNum[1]->Clone("effMC");
  effMC->Divide(histNum[1],histDen[1]);
  effMC->SetMarkerStyle(21);
  effMC->SetMarkerColor(2);
  effMC->SetLineColor(2);
  effMC->SetMarkerSize(2);

  for (int iB=1;iB<=nBins;++iB) {
    std::cout << "[" << eff->GetBinLowEdge(iB) << "," << eff->GetBinLowEdge(iB+1) << "] : "
	      << "  data = " << eff->GetBinContent(iB) 
	      << " +/- " << eff->GetBinError(iB)
	      << "  mc = " << effMC->GetBinContent(iB) 
	      << " +/- " << effMC->GetBinError(iB) << std::endl;
  }

  TCanvas * canv = new TCanvas("canv","",700,600);
  TH2F * frame = new TH2F("frame","",2,xmin,xmax,2,0,ymax);
  frame->GetYaxis()->SetTitle("Fake Rate");
  frame->GetXaxis()->SetTitle(xtitle);
  frame->Draw();
  eff->Draw("epsame");
  if (!isDijet)
    effMC->Draw("epsame");
  //  canv->SetLogx(true);
  //  canv->SetLogy(true);
  TLegend * leg = new TLegend(0.4,0.7,0.65,0.9);
  SetLegendStyle(leg);
  leg->SetHeader(iso);
  leg->SetTextSize(0.04);
  if (!isDijet) {
    leg->AddEntry(eff,"Data","lp");
    leg->AddEntry(effMC,"Simulation","lp");
  }
  leg->Draw();
  canv->SetLogx(logX);
  canv->Update();
  canv->Print("figures/fakerate_"+variable+"_"+iso+suffix+postfix+".png");

  TFile * fileOutput = new TFile("fakeRates/fakeRate_"+variable+"_"+iso+suffix+postfix+".root","recreate");
  fileOutput->cd("");
  eff->Write("data_fakeRate");
  effMC->Write("mc_fakeRate");
  fileOutput->Close();

}
