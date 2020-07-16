#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include "../settings_era_specific_2018.h"
// iso ->
// taubyMediumDeepTau2017v2p1VSjet
// taubyTightDeepTau2017v2p1VSjet
// triggerOption ->
// 0 : inclusive
// 1 : passing probes
// 2 : failing probes
// decayMode ->
// 0 : inclusive
// 1 : 1-prong
// 2 : 1-prong+pi0's
// 3 : 3-prong
void PlotWTauNu_TauPt(TString iso = "taubyTightDeepTau2017v2p1VSjet",
		      int decayMode = 0,
		      int triggerOption = 1,
		      bool plot = true 
		      ) {

  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  bool plotLegend = true;
  bool logX = true;
  bool logY = true;

  TString antiMuDiscriminant("taubyLooseDeepTau2017v2p1VSmu");
  TString antiEleDiscriminant("taubyTightDeepTau2017v2p1VSe");

  std::map<TString,TString> tauIDiso = {
    {"taubyMediumDeepTau2017v2p1VSjet","Medium"},
    {"taubyTightDeepTau2017v2p1VSjet","Tight"},
  };

  std::map<int,TString> postfixTriggerOption = {
    {0,"_inclusive"},
    {1,"_Trigger"},
    {2,"_notTrigger"}
  };
  std::map<int,TString> cutTriggerOption = {
    {0,""},
    {1,"&&(tauSinglePFTau180Trk50>0.5||tauSinglePFTau180Trk50oneprong>0.5)"},
    {2,"&&!(tauSinglePFTau180Trk50>0.5||tauSinglePFTau180Trk50oneprong>0.5)"}
  };


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

  TString tauID = tauIDiso[iso];
  TString postfix = postfixDM[decayMode];
  TString DecayMode = dmDM[decayMode]; 
  TString CutTauTrigger = cutTriggerOption[triggerOption];
  TString postfixTrigger = postfixTriggerOption[triggerOption];
  std::cout << std::endl;
  std::cout << "WP      : " << tauID << std::endl;
  std::cout << "tau ID  : " << iso << std::endl;
  std::cout << "Postfix : " << postfix << std::endl;
  std::cout << "CutDM   : " << cutDM[decayMode] << std::endl;
  std::cout << "HPS DM  : " << DecayMode << std::endl;
  std::cout << std::endl;

  TString DataFile = "MET_Run2018";
  TString Variable = "tauPt";

  float xmin = 100;
  float xmax = 2000;

  int nBins  = 10;
  float bins[11] = {100,120,140,160,180,200,225,250,300,400,2000};
  TString xtitle = "p_{T} [GeV]";
  TString ytitle = "Events / bin";

  // fake factors and systematics
  TFile * fakeRateFile = new TFile("fakeRates/fakerate_"+Variable+"_"+iso+"_comb"+postfix+".root");
  TH1D * fakeRateHist = (TH1D*)fakeRateFile->Get("fakeRate");
  int nFakeBins = fakeRateHist->GetNbinsX();
  std::vector<TString> binName = {
    "0","1","2","3","4","5","6","7","8","9","10","11","12"
  };
  std::vector<TString> sysUpDown = {"Up","Down"};

  TString Weight = "puWeight*genWeight*trigWeight*";

  TString cutsTrigger("trigger>0.5&&metFilters&&");
  TString cutsTopology("Selection==3&&recoilDPhi>2.4&&met>120&&tauPt>100&&TMath::Abs(tauEta)<2.1&&");
  TString cutsLeptonVeto("nMuon==0&&nElec==0&&");
  TString cutsJetVeto("nSelTaus==1&&nJetsCentral30<=1&&nJetsForward30==0&&");

  TString cutsTauId        ("tauNewDM>0.5&&"+antiMuDiscriminant+">0.5&&"+antiEleDiscriminant+">0.5&&"+iso+">0.5");
  TString cutsInverseTauIso("tauNewDM>0.5&&"+antiMuDiscriminant+">0.5&&"+antiEleDiscriminant+">0.5&&"+iso+"<0.5&&taubyVVVLooseDeepTau2017v2p1VSjet>0.5");
  
  TString CutsBkg = cutsTrigger+cutsTopology+cutsLeptonVeto+cutsJetVeto+cutsInverseTauIso+CutTauTrigger;
  TString CutsSig = cutsTrigger+cutsTopology+cutsLeptonVeto+cutsJetVeto+cutsTauId+CutTauTrigger;
  TString CutsBkgData = CutsBkg + CutTauTrigger;
  TString CutsSigData = CutsSig + CutTauTrigger;

  SetStyle();

  std::cout << std::endl;
  std::cout << "Luminosity = " << luminosity << std::endl;
  std::cout << std::endl;


  TString sampleNames[23] = {
    DataFile, // data (0)
    "WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola",          // (1)  W->TauNu
    "WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8",         // (2)  WJets (fake taus)
    "WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_jesUp",    // (3)  W->TauNu (JES Up) 
    "WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_jesDown",  // (4)  W->TauNu (JES Down) 
    "WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_uesUp",    // (5)  W->TauNu (UES Up) 
    "WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_uesDown",  // (6)  W->TauNu (UES Down) 
    "WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_tauesUp",  // (7)  W->TauNu (UES Up) 
    "WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_tauesDown",// (8)  W->TauNu (UES Down) 
    "DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8", //  (9)  DY1Jets
    "DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8", // (10)  DY2Jets
    "DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8", // (11)  DY3Jets
    "DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8", // (12)  DY4Jets
    "TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8",        // (13) TT (leptonic)
    "TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8", // (14) TT (semileptonic)
    "TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8",     // (15) TT (hadronic)
    "ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8",     // (16) s-top
    "ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8", // (17) s-atop
    "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",     // (18) topW
    "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8", // (19) atopW
    "WW_TuneCP5_13TeV-pythia8", // (20) WW
    "WW_TuneCP5_13TeV-pythia8", // (21) WZ
    "ZZ_TuneCP5_13TeV-pythia8"  // (22) ZZ
  };

  TString cuts[40];
  TString cutsSB[40];
  for (int i=0; i<40; ++i) {
    cuts[i]   = Weight+"("+CutsSig+")&&tauGenMatchDecay>=0";
    cutsSB[i] = Weight+"("+CutsBkg+")&&tauGenMatchDecay>=0";
  }
  cuts[0] = CutsSigData;
  cutsSB[0] = CutsBkgData;

  TH1D * hist[40];
  TH1D * histSB[40];

  TCanvas * dummy = new TCanvas("dummy","",400,400);

  // filling histograms
  float ewkNorm = 0;
  int nSamples = 23;
  for (int i=0; i<nSamples; ++i) {
    TString DIR = dir;
    TFile * file = new TFile(DIR+"/"+sampleNames[i]+".root");
    TH1D * histWeightsH = (TH1D*)file->Get("histWeightsH");
    TTree * tree = (TTree*)file->Get("NTuple");
    double norm = 1;
    if (i>0)
      norm = xsecs[sampleNames[i]]*luminosity/histWeightsH->GetSumOfWeights();
    TString histName     = sampleNames[i];
    TString histNameSB   = sampleNames[i]+"_SB";

    hist[i]  = new TH1D(histName,"",nBins,bins);
    histSB[i] = new TH1D(histNameSB,"",nBins,bins);
    hist[i]->Sumw2();
    histSB[i]->Sumw2();

    tree->Draw(Variable+">>"+histName,cuts[i]);
    tree->Draw(Variable+">>"+histNameSB,cutsSB[i]);

    std::cout << sampleNames[i] << " : " << norm*hist[i]->GetSumOfWeights() << std::endl;  
    if (i>0) {
      for (int iB=1; iB<=nBins; ++iB) {
	double x = hist[i]->GetBinContent(iB);
	double e = hist[i]->GetBinError(iB);
    	hist[i]->SetBinContent(iB,norm*x);
    	hist[i]->SetBinError(iB,norm*e);
	x = histSB[i]->GetBinContent(iB);
	e = histSB[i]->GetBinError(iB);
    	histSB[i]->SetBinContent(iB,norm*x);
    	histSB[i]->SetBinError(iB,norm*e);
      }
    }
  }

  delete dummy;
  
  std::cout << std::endl;
  std::cout << "Average tau pT = " << hist[1]->GetMean() << std::endl;
  std::cout << std::endl;

  TH1D * histData = (TH1D*)hist[0]->Clone("data_obs");
  TH1D * QCD = (TH1D*)histSB[0]->Clone("Fakes");

  QCD->Add(QCD,histSB[1],1,-1);
  for (int iS=9; iS<nSamples; ++iS) {
    QCD->Add(QCD,histSB[iS],1,-1);    
  }
  for (int iS=10;iS<nSamples; ++iS)
    hist[9]->Add(hist[9],hist[iS]);

  // fake factors
  for (int iB=1; iB<=nBins; ++iB) {
    double var = QCD->GetBinCenter(2);
    int jB = fakeRateHist->FindBin(2);
    double xF = fakeRateHist->GetBinContent(2);
    double xB = QCD->GetBinContent(iB);
    double eB = QCD->GetBinError(iB);
    double x = xF*xB;
    double e = xF*eB;
    QCD->SetBinContent(iB,x);
    QCD->SetBinError(iB,e);
  }

  TH1D * QCDsys[5][2];

  for (int iF=0; iF<nFakeBins; ++iF) {
    for (int iS=0; iS<2; ++iS)
      QCDsys[iF][iS] = (TH1D*)QCD->Clone("QCD_fakeRate_bin"+binName[iF]+sysUpDown[iS]);
  }
  for (int iB=1; iB<=nBins; ++iB) {
    double var = QCD->GetBinCenter(iB);
    int jB = fakeRateHist->FindBin(var);
    int jIndex = jB-1;
    double xF = fakeRateHist->GetBinContent(jB);
    double eF = fakeRateHist->GetBinError(jB);
    double xUp = 1+eF/xF;
    double xDown = 1/xUp;
    double xB = QCD->GetBinContent(iB);
    double eB = QCD->GetBinError(iB);
    double bUp = xB * xUp;
    double eUp = eB * xUp;
    double bDown = xB * xDown;
    double eDown = eB * xDown;
    QCDsys[jIndex][0]->SetBinContent(iB,bUp);
    QCDsys[jIndex][0]->SetBinError(iB,eUp);
    QCDsys[jIndex][1]->SetBinContent(iB,bDown);
    QCDsys[jIndex][1]->SetBinError(iB,eDown);
  }


  TH1D * W   = (TH1D*)hist[1]->Clone("W");
  TH1D * Bkgd = (TH1D*)hist[9]->Clone("Bkgd");
  
  TH1D * WJESUp     = (TH1D*)hist[3]->Clone("W_JESUp");
  TH1D * WJESDown   = (TH1D*)hist[4]->Clone("W_JESDown");
  TH1D * WUESUp     = (TH1D*)hist[5]->Clone("W_UESUp");
  TH1D * WUESDown   = (TH1D*)hist[6]->Clone("W_UESDown");
  TH1D * WTESUp     = (TH1D*)hist[7]->Clone("W_TESUp");
  TH1D * WTESDown   = (TH1D*)hist[8]->Clone("W_TESDown");

  // **************************
  // *** combine genuine taus *
  // **************************
  W->Add(W,Bkgd);
  WJESUp->Add(WJESUp,Bkgd);
  WJESDown->Add(WJESDown,Bkgd);
  WUESUp->Add(WUESUp,Bkgd);
  WUESDown->Add(WUESDown,Bkgd);
  WTESUp->Add(WTESUp,Bkgd);
  WTESDown->Add(WTESDown,Bkgd);

  // ***************
  // Creating inputs
  // *************** 
  TString BaseName = Variable+"_"+iso+postfix+"_WTauNu"+postfixTrigger;
  TString rootFileName = BaseName+".root";
  TFile * fileInputs = new TFile("inputs/"+rootFileName,"recreate"); 
  fileInputs->cd("");
  histData->Write("data_obs");
  W->Write("W");
  QCD->Write("Fakes");
  
  WJESUp->Write("W_JESUp");
  WJESDown->Write("W_JESDown");
  WUESUp->Write("W_UESUp");
  WUESDown->Write("W_UESDown");
  WTESUp->Write("W_TESUp");
  WTESDown->Write("W_TESDown");
  for (int iF=0; iF<nFakeBins; ++iF) {
    for (int iS=0; iS<2; ++iS)
      QCDsys[iF][iS]->Write("Fakes_fakeRate_bin"+binName[iF]+sysUpDown[iS]);
  }
  fileInputs->Close();
  
  double jesUp = WJESUp->GetSumOfWeights()/W->GetSumOfWeights();
  double jesDown = WJESDown->GetSumOfWeights()/W->GetSumOfWeights();
  double uesUp = WUESUp->GetSumOfWeights()/W->GetSumOfWeights();
  double uesDown = WUESDown->GetSumOfWeights()/W->GetSumOfWeights();
  double tesUp = WTESUp->GetSumOfWeights()/W->GetSumOfWeights();
  double tesDown = WTESDown->GetSumOfWeights()/W->GetSumOfWeights();
  
  std::cout << "jes = "  << jesDown << "/" << jesUp << std::endl;
  std::cout << "ues = "  << uesDown << "/" << uesUp << std::endl;
  std::cout << "tes = "  << tesDown << "/" << tesUp << std::endl;
  std::cout << std::endl;

  ostringstream str;
  str << "inputs/" <<  BaseName << ".txt";
  string nn = str.str();
  const char * p = nn.c_str();

  std::ofstream textFile(p);
  textFile << "imax 1   number of channels" << std::endl;
  textFile << "jmax *   number of backgrounds" << std::endl;
  textFile << "kmax *   number of nuisance parameters" << std::endl;
  textFile << "-----------------" << std::endl;
  textFile << "observation " << histData->GetSumOfWeights() << std::endl;
  textFile << "-----------------" << std::endl;
  textFile << "shapes * * " << rootFileName << "  $PROCESS    $PROCESS_$SYSTEMATIC " << std::endl;
  textFile << "-----------------" << std::endl;

  if (triggerOption==0) 
    textFile << "bin             WtoTauNu  WtoTauNu" << std::endl;
  else if (triggerOption==1)
    textFile << "bin             WtoTauNu_pass  WtoTauNu_pass" << std::endl;
  else if (triggerOption==2)
    textFile << "bin             WtoTauNu_fail  WtoTauNu_fail" << std::endl;

  textFile << "process              W       Fakes" << std::endl;
  textFile << "process              0         1  " << std::endl;
  textFile << "rate    " << W->GetSumOfWeights() << " " << QCD->GetSumOfWeights() << std::endl;
  textFile << "JES         shape   1.00       -  " << std::endl;
  //  textFile << "UES           lnN   " << uesDown << "/" << uesUp << "       -  " << std::endl;
  textFile << "TES         shape   1.00       -  " << std::endl;
  for (int iF=0; iF<nFakeBins; ++iF)
    textFile << "fakeRate_bin" << binName[iF] << "         shape   -      1.0" << std::endl;  
  textFile << "* autoMCStats 0" << std::endl;

  // *******************
  // end creating inputs
  // *******************

  std::cout << "W     : " << W->GetSumOfWeights()  << std::endl;
  std::cout << "fakes : " << QCD->GetSumOfWeights() << std::endl;

  // ************************
  // Systematic uncertainties
  // ************************
  for (int iB=1; iB<=nBins; ++iB) {
    float eStat = W->GetBinError(iB);

    float eUp = fabs(W->GetBinContent(iB)-WJESUp->GetBinContent(iB));
    float eDown = fabs(W->GetBinContent(iB)-WJESDown->GetBinContent(iB));
    float eJES = TMath::Max(eUp,eDown); 

    eUp = fabs(W->GetBinContent(iB)-WUESUp->GetBinContent(iB));
    eDown = fabs(W->GetBinContent(iB)-WUESDown->GetBinContent(iB));
    float eUES = TMath::Max(eUp,eDown); 

    eUp = fabs(W->GetBinContent(iB)-WTESUp->GetBinContent(iB));
    eDown = fabs(W->GetBinContent(iB)-WTESDown->GetBinContent(iB));
    float eTES = TMath::Max(eUp,eDown); 
    
    float eW = TMath::Sqrt(eJES*eJES+eUES*eUES+eTES*eTES+eStat*eStat);
    W->SetBinError(iB,eW);

    eStat = QCD->GetBinError(iB);
    float eQCD2 = eStat*eStat;
    for (int iF=0; iF<nFakeBins; ++iF) {
      float eFakeUp = fabs(QCD->GetBinContent(iB)-QCDsys[iF][0]->GetBinContent(iB));
      float eFakeDown = fabs(QCD->GetBinContent(iB)-QCDsys[iF][1]->GetBinContent(iB));
      float e = 0.5*(eFakeUp+eFakeDown);
      eQCD2 += e*e;
    }
    float eQCD = TMath::Sqrt(eQCD2);
    QCD->SetBinError(iB,eQCD);
  }


  QCD->Add(QCD,Bkgd);
  W->Add(W,QCD);
  std::cout << "Total : " << W->GetSumOfWeights() << std::endl;
  std::cout << "Data  : " << histData->GetSumOfWeights() << std::endl;

  if (!plot) return;

  
  TH1D * bkgdErr = (TH1D*)W->Clone("bkgdErr");
  bkgdErr->SetFillStyle(3013);
  bkgdErr->SetFillColor(1);
  bkgdErr->SetMarkerStyle(21);
  bkgdErr->SetMarkerSize(0);  
  
  for (int iB=1; iB<=nBins; ++iB) {
    Bkgd->SetBinError(iB,0);
    QCD->SetBinError(iB,0);
    W->SetBinError(iB,0);
  }

  InitData(histData);
  InitHist(QCD,"","",TColor::GetColor(192,232,100),1001);
  InitHist(W,"","",TColor::GetColor("#FFCC66"),1001);
  histData->GetXaxis()->SetTitle(xtitle);
  histData->GetYaxis()->SetTitle(ytitle);
  histData->GetYaxis()->SetTitleOffset(1.3);
  histData->GetYaxis()->SetTitleSize(0.06);

  histData->SetMarkerSize(1.6);
  histData->GetXaxis()->SetLabelSize(0);
  histData->GetYaxis()->SetLabelSize(0.06);

  TCanvas * canv1 = MakeCanvas("canv1", "", 600, 700);
  TPad * upper = new TPad("upper", "pad",0,0.31,1,1);
  upper->Draw();
  upper->cd();
  upper->SetFillColor(0);
  upper->SetBorderMode(0);
  upper->SetBorderSize(10);
  upper->SetTickx(1);
  upper->SetTicky(1);
  upper->SetLeftMargin(0.17);
  upper->SetRightMargin(0.05);
  upper->SetBottomMargin(0.02);
  upper->SetFrameFillStyle(0);
  upper->SetFrameLineStyle(0);
  upper->SetFrameLineWidth(2);
  upper->SetFrameBorderMode(0);
  upper->SetFrameBorderSize(10);
  upper->SetFrameFillStyle(0);
  upper->SetFrameLineStyle(0);
  upper->SetFrameLineWidth(2);
  upper->SetFrameBorderMode(0);
  upper->SetFrameBorderSize(10);

  histData->GetYaxis()->SetRangeUser(0.,1.3*histData->GetMaximum());
  if (logY) 
    histData->GetYaxis()->SetRangeUser(1.,7.0*histData->GetMaximum());
  histData->Draw("e1");
  W->Draw("sameh");
  QCD->Draw("sameh");
  histData->Draw("e1same");
  bkgdErr->Draw("e2same");
  float chi2 = 0;
  for (int iB=1; iB<=nBins; ++iB) {
    float xData = histData->GetBinContent(iB);
    float eData = histData->GetBinError(iB);
    float xMC = W->GetBinContent(iB);
    float eMC = W->GetBinError(iB);
    if (xMC>1e-1) {
      float diff2 = (xData-xMC)*(xData-xMC);
      chi2 += diff2/(eMC*eMC+eData*eData);
    }
  }
  double prob = TMath::Prob(double(chi2),double(nBins));
  std::cout << std::endl;
  std::cout << "Chi2 = " << chi2 << "   p-value = " << prob << std::endl;
  std::cout << std::endl;

  TLegend * leg = new TLegend(0.60,0.48,0.90,0.76);
  SetLegendStyle(leg);
  leg->SetTextSize(0.04);
  leg->SetHeader(tauID+"  "+DecayMode);
  leg->AddEntry(histData,"Data","lp");
  leg->AddEntry(W,"genuine #tau","f");
  leg->AddEntry(QCD,"misidentified j#rightarrow#tau","f");
  if (plotLegend)
    leg->Draw();
  writeExtraText = true;
  extraText = "Preliminary";
  CMS_lumi(upper,4,33); 
  plotchannel("#tau#nu");

  if (logY) upper->SetLogy(true);
  if (logX) upper->SetLogx(true);

  upper->Draw("SAME");
  upper->RedrawAxis();
  upper->Modified();
  upper->Update();
  canv1->cd();

  TH1D * ratioH = (TH1D*)histData->Clone("ratioH");
  TH1D * ratioErrH = (TH1D*)bkgdErr->Clone("ratioErrH");
  ratioH->SetMarkerColor(1);
  ratioH->SetMarkerStyle(20);
  ratioH->SetMarkerSize(1.6);
  ratioH->SetLineColor(1);
  ratioH->GetYaxis()->SetRangeUser(0.21,1.799);
  ratioH->GetYaxis()->SetNdivisions(505);
  ratioH->GetXaxis()->SetLabelFont(42);
  ratioH->GetXaxis()->SetLabelOffset(0.04);
  ratioH->GetXaxis()->SetLabelSize(0.14);
  ratioH->GetXaxis()->SetTitleSize(0.13);
  ratioH->GetXaxis()->SetTitleOffset(1.2);
  ratioH->GetYaxis()->SetTitle("obs/exp");
  ratioH->GetYaxis()->SetLabelFont(42);
  ratioH->GetYaxis()->SetLabelOffset(0.015);
  ratioH->GetYaxis()->SetLabelSize(0.13);
  ratioH->GetYaxis()->SetTitleSize(0.14);
  ratioH->GetYaxis()->SetTitleOffset(0.5);
  ratioH->GetXaxis()->SetTickLength(0.07);
  ratioH->GetYaxis()->SetTickLength(0.04);
  ratioH->GetYaxis()->SetLabelOffset(0.01);

  for (int iB=1; iB<=nBins; ++iB) {
    float X1 = histData->GetBinContent(iB);
    float X2 = W->GetBinContent(iB);
    ratioErrH->SetBinContent(iB,1.0);
    ratioErrH->SetBinError(iB,0.0);
    float xBkg = bkgdErr->GetBinContent(iB);
    float errBkg = bkgdErr->GetBinError(iB);
    if (xBkg>0) {
      float relErr = errBkg/xBkg;
      ratioErrH->SetBinError(iB,relErr);

    }
    if (X1>0&&X2>0) {
      float e1 = histData->GetBinError(iB);
      float ratio = X1/X2;
      float eratio = e1/X2;
      ratioH->SetBinContent(iB,ratio);
      ratioH->SetBinError(iB,eratio);
    }
    else {
      ratioH->SetBinContent(iB,1000);
    }
  }

  // ------------>Primitives in pad: lower
  TPad * lower = new TPad("lower", "pad",0,0,1,0.30);
  lower->Draw();
  lower->cd();
  lower->SetFillColor(0);
  lower->SetBorderMode(0);
  lower->SetBorderSize(10);
  lower->SetGridy();
  lower->SetTickx(1);
  lower->SetTicky(1);
  lower->SetLeftMargin(0.17);
  lower->SetRightMargin(0.05);
  lower->SetTopMargin(0.026);
  lower->SetBottomMargin(0.35);
  lower->SetFrameFillStyle(0);
  lower->SetFrameLineStyle(0);
  lower->SetFrameLineWidth(2);
  lower->SetFrameBorderMode(0);
  lower->SetFrameBorderSize(10);
  lower->SetFrameFillStyle(0);
  lower->SetFrameLineStyle(0);
  lower->SetFrameLineWidth(2);
  lower->SetFrameBorderMode(0);
  lower->SetFrameBorderSize(10);

  ratioH->Draw("e1");
  ratioErrH->Draw("e2same");

  lower->Modified();
  lower->RedrawAxis();
  if (logX) lower->SetLogx(true);
  canv1->cd();
  canv1->Modified();
  canv1->cd();
  canv1->SetSelected(canv1);
  canv1->Update();
  canv1->Print("figures/"+Variable+"_"+iso+postfix+"_WTauNu"+postfixTrigger+".png");

}
