#include "HttStylesNew.cc"
#include "settings_era_specific_2018.h"
// taubyMediumDeepTau2017v2p1VSjet
// taubyTightDeepTau2017v2p1VSjet

void CombineFakeRate_TauPt(TString iso="taubyMediumDeepTau2017v2p1VSjet",
			   int decayMode = 3,
			   bool fit = false,
			   bool logX = true,
			   float ymax = 0.3,
			   float xLego = 0.4,
			   bool applyNorm = false) {

  float normFactor = 1.0;
  float xmin =  100;
  float xmax = 2000;

  TString variable="tauPt";
  TString xtitle("tau p_{T} [GeV]");
  TString ytitle("FF");

  TString antiMuDiscriminant("taubyLooseDeepTau2017v2p1VSmu");
  TString antiEleDiscriminant("taubyTightDeepTau2017v2p1VSe");

  std::map<int,TString> postfixDM = {
    {0,"_inclusive"},
    {1,"_1prong"},
    {2,"_1prongpi0s"},
    {3,"_3prong"},
  };

  std::map<int,TString> dmDM = {
    {0,"inclusive"},
    {1,"1-prong"},
    {2,"1-prong+#pi^{0}'s"},
    {3,"3-prong"},
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
  TString DecayMode = dmDM[decayMode];
  std::cout << std::endl;
  std::cout << "tau ID  : " << iso << std::endl;
  std::cout << "Postfix : " << postfix << std::endl;
  std::cout << "CutDM   : " << cutDM[decayMode] << std::endl;
  std::cout << "HPS DM  : " << DecayMode << std::endl;
  std::cout << std::endl;

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

  TString dir = "./";

  TString DataFile("MET_Run2018");

  // ****************** Cuts for W->tau+v ************************
  TString   selCuts("trigger>0.5&&Selection==3&&recoilDPhi>2.4&&met>120&&tauPt>100&&nMuon==0&&nElec==0&&nSelTaus==1&&nJetsCentral30<=1&&nJetsForward30==0"); 
  TString selCutsMC("trigger>0.5&&Selection==3&&recoilDPhi>2.4&&met>120&&tauPt>100&&nMuon==0&&nElec==0&&nSelTaus==1&&nJetsCentral30<=1&&nJetsForward30==0");

  selCuts += cutDM[decayMode];
  selCutsMC += cutDM[decayMode];

  TString numCuts("&&tauNewDM>0.5&&"+antiMuDiscriminant+">0.5&&"+antiEleDiscriminant+">0.5&&"+iso+">0.5&&taubyVVVLooseDeepTau2017v2p1VSjet>0.5");
  TString denCuts("&&tauNewDM>0.5&&"+antiMuDiscriminant+">0.5&&"+antiEleDiscriminant+">0.5&&"+iso+"<0.5&&taubyVVVLooseDeepTau2017v2p1VSjet>0.5");
  //  TString numCuts("&&tauDM>0.5&&tauAntiMuonLoose3&&tauAntiElectronLooseMVA6&&tau"+iso+">0.5");
  //  TString denCuts("&&tauDM>0.5&&tauAntiMuonLoose3&&tauAntiElectronLooseMVA6&&tau"+iso+"<0.5");
  TString fakeTauMCCuts("&&tauGenMatchDecay<0");
  TString genuineTauMCCuts("&&tauGenMatchDecay>=0");

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  if ( fit )
    gStyle->SetOptFit(111);
  

  bool logY = false;
  double lumi = 59740;

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
    cutsNum[i] = "puWeight*genWeight*trigWeight*("+selCutsMC+numCuts+fakeTauMCCuts+")";
    cutsDen[i] = "puWeight*genWeight*trigWeight*("+selCutsMC+denCuts+fakeTauMCCuts+")";
    cutsNumSub[i] = "puWeight*genWeight*trigWeight*("+selCutsMC+numCuts+genuineTauMCCuts+")";
    cutsDenSub[i] = "puWeight*genWeight*trigWeight*("+selCutsMC+denCuts+genuineTauMCCuts+")";
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
    histNumSub[1]->Add(histNumSub[1],histNumSub[i]);
    histDenSub[1]->Add(histDenSub[1],histDenSub[i]);

  }

  histNum[0]->Add(histNum[0],histNumSub[1],1,-1);
  histDen[0]->Add(histDen[0],histDenSub[1],1,-1);
  
  TFile * fileEWK = new TFile("fakeRates/fakeRate_"+variable+"_"+iso+"_wjets"+postfix+".root");
  TFile * fileQCD = new TFile("fakeRates/fakeRate_"+variable+"_"+iso+"_dijet"+postfix+".root");
  TH1D * fakeRateEWK = (TH1D*)fileEWK->Get("data_fakeRate");
  TH1D * fakeRateQCD = (TH1D*)fileQCD->Get("data_fakeRate");
  TH1D * fakeRateMC  = (TH1D*)fileEWK->Get("mc_fakeRate");

  TH1D * fakeRate = new TH1D("fakeRate","",nBins,bins);

  fakeRateEWK->SetLineColor(2);
  fakeRateEWK->SetMarkerColor(2);
  fakeRateEWK->SetMarkerSize(1.7);
  fakeRateEWK->SetMarkerStyle(21);

  fakeRateQCD->SetLineColor(4);
  fakeRateQCD->SetMarkerColor(4);
  fakeRateQCD->SetMarkerSize(1.7);
  fakeRateQCD->SetMarkerStyle(22);

  fakeRate->SetLineColor(1);
  fakeRate->SetMarkerColor(1);
  fakeRate->SetMarkerSize(1.1);
  fakeRate->SetMarkerStyle(20);

  for (int iB=1; iB<=nBins; ++iB)
  {
    double nQCD = histDen[0]->GetBinContent(iB);
    double nEWK = histDen[1]->GetBinContent(iB);
    double effEWK = fakeRateEWK->GetBinContent(iB);
    double effQCD = fakeRateQCD->GetBinContent(iB);
    double effEWKE = fakeRateEWK->GetBinError(iB);
    double effQCDE = fakeRateQCD->GetBinError(iB);
    if (applyNorm) {
      effEWKE *= normFactor;
      effEWK *= normFactor;
    }
    fakeRateEWK->SetBinContent(iB,effEWK);
    fakeRateEWK->SetBinError(iB,effEWKE);
    fakeRateQCD->SetBinContent(iB,effQCD);
    fakeRateQCD->SetBinError(iB,effQCDE);
    if (nEWK>nQCD) nEWK = nQCD;
    double rEWK = nEWK/nQCD;
    double rQCD = 1.0 - rEWK;
    double FR = rEWK*effEWK + rQCD*effQCD;
    double eFR = TMath::Sqrt(effEWKE*effEWKE*rEWK*rEWK+effQCDE*effQCDE*rQCD*rQCD);
    std::cout << "[" << fakeRate->GetBinLowEdge(iB) << "," << fakeRate->GetBinLowEdge(iB+1) << "] : "
	      << "  nEWK=" << nEWK 
	      << "  nDATA=" << nQCD 
	      << "  rEWK=" << rEWK 
	      << "  -> FR=" << FR
	      << "+/-"  << eFR 
	      << "  ewk=" << effEWK 
	      << "  qcd=" << effQCD << std::endl; 
    fakeRate->SetBinError(iB,eFR);
    fakeRate->SetBinContent(iB,FR);
  }

  if ( fit ) fakeRate->Fit("pol0");

  delete dummy;

  TCanvas * canv = new TCanvas("canv","",700,600);
  TH2F * frame = new TH2F("frame","",2,xmin,xmax,2,0,ymax);
  frame->GetYaxis()->SetTitle("Fake Rate");
  frame->GetXaxis()->SetTitle(xtitle);
  frame->SetLineColor(0);
  frame->Draw();
  fakeRate->Draw("epsame");
  if (!fit) {
    fakeRateEWK->Draw("epsame");
    fakeRateQCD->Draw("epsame");
  }
  fakeRate->Draw("epsame");
  TLegend * leg = new TLegend(xLego,0.6,xLego+0.4,0.9);
  SetLegendStyle(leg);
  leg->SetHeader(iso);
  leg->SetTextSize(0.04);
  leg->AddEntry(frame,DecayMode,"l");
  leg->AddEntry(fakeRate,"combination","lp");
  leg->AddEntry(fakeRateEWK,"EWK","lp");
  leg->AddEntry(fakeRateQCD,"QCD","lp");
  
  leg->Draw();
  canv->SetLogx(logX);
  canv->Update(); 
  TFile * fileOutput = new TFile("fakeRates/fakerate_"+variable+"_"+iso+"_comb"+postfix+".root","recreate");
  fileOutput->cd();
  fakeRate->Write("fakeRate");
  fileOutput->Close();

  if (fit) 
    canv->Print("figures/fakerate_"+variable+"_"+iso+"_mc_fit"+postfix+".png");
  else 
    canv->Print("figures/fakerate_"+variable+"_"+iso+"_comb"+postfix+".png");

}
