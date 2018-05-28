#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>
#include <map>
#include <math.h>

#include "TString.h"
#include "TTree.h"
#include "TFile.h"
#include "TTreeReader.h"
#include "TROOT.h"
#include "TKey.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TH1.h"
#include "TH2.h"
#include "TVector2.h"
#include "TLorentzVector.h"

//TString dir = "/nfs/dust/cms/user/tlenz/13TeV/2016/TauIdWithVirtualW/WTauId/NTuples/";
//TString dir = "/nfs/dust/cms/user/mameyer/TauIdAndES_2017Data/TauId/NTuples/";
//TString dir = "NTuples/ntuples_before_18_4/";
TString dir = "NTuples/";

TString tauDecayMode = "";
//TString tauDecayMode = "_3prong0pizeros";
//TString tauDecayMode = "_1prong0pizeros";
//TString tauDecayMode = "_1prongUpTo4pizeros";

double luminosity = 40991; // lumi determined by brilcalc
//double luminosity = 28289; // lumi without RunF (determined by brilcalc)
//double luminosity = 1.;
//double luminosity = 35890; // lumi used for 2016 analysis

std::vector<TString> iso;
map<TString,TH2D>* h_fakerate = 0;
map<TString,TH2D>* h_fakerate_up = 0;
map<TString,TH2D>* h_fakerate_down = 0;

map<TString, double> xsecs = {
{"WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"            , 52760*1.166}, // NNLO (1)
{"W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"           , 8104.*1.166}, // NNLO (2)
{"W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"           , 2796.*1.166}, // NNLO (3)
{"W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"           , 993.5*1.166}, // NNLO (4)
{"W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"           , 544.4*1.166}, // NNLO (5)
{"W1JetsToLNu_LHEWpT_50-150"                               , 1.0181*2661},  // NNLO (6)
{"W1JetsToLNu_LHEWpT_100-150"                              , 1.0181*286.1}, // NNLO (6a)
{"W1JetsToLNu_LHEWpT_150-250"                              , 1.0181*71.9},  // NNLO (7)
{"W1JetsToLNu_LHEWpT_250-400"                              , 1.0181*8.05},  // NNLO (8)
{"W1JetsToLNu_LHEWpT_400-inf"                              , 1.0181*0.885}, // NNLO (9)
{"ZJetsToNuNu_HT-100To200_13TeV-madgraph"                  , 304.5},    // LO (10)
{"ZJetsToNuNu_HT-200To400_13TeV-madgraph"                  , 91.82},    // LO (11)
{"ZJetsToNuNu_HT-400To600_13TeV-madgraph"                  , 13.11},    // LO (12)
{"ZJetsToNuNu_HT-600To800_13TeV-madgraph"                  , 3.260},    // LO (13)
{"ZJetsToNuNu_HT-800To1200_13TeV-madgraph"                 , 1.499},    // LO (14)
{"ZJetsToNuNu_HT-1200To2500_13TeV-madgraph"                , 0.3430},   // LO (15)
{"ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph"                 , 0.005146}, // LO (16)
{"ZZ_TuneCP5_13TeV-pythia8"                                , 12.19},  // LO (17) -> could be improved
{"WW_TuneCP5_13TeV-pythia8"                                , 118.7},  // NNLO QCD (18)
{"WZ_TuneCP5_13TeV-pythia8"                                , 27.68},  // LO (19) -> could be improved
{"DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"       , 5345*1.079},  // NNLO (20)
{"DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"      , 875.7*1.079}, // NNLO (20a)
{"DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"      , 306.9*1.079}, // NNLO (20b)
{"DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"      , 111.9*1.079}, // NNLO (20c)
{"DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"      , 43.97*1.079}, // NNLO (20d)
{"TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8"        , 88.29},  // NNLO (21)
{"TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8"     , 377.96}, // NNLO (22)
{"TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8" , 365.34}, // NNLO (23)
{"ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8"     , 44.33}, // ? (24) -> could be improved
{"ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8" , 26.38}, // ? (25) -> could be improved
{"ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8"                      , 35.85}, // ? (26) -> could be improved
{"ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8"                  , 35.85}, // ? (27) -> could be improved
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola"             , 1.3*6.206}, // NNLO-QCD NLO-EWK (28)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_jesUp"       , 1.3*6.206}, // NNLO-QCD NLO-EWK (29)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_jesDown"     , 1.3*6.206}, // NNLO-QCD NLO-EWK (30)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_1prong0pizerosUp"             , 1.3*6.206}, // NNLO-QCD NLO-EWK (31)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_1prong0pizerosDown"           , 1.3*6.206}, // NNLO-QCD NLO-EWK (32)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_1prongUpTo4pizerosUp"         , 1.3*6.206}, // NNLO-QCD NLO-EWK (33)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_1prongUpTo4pizerosDown"       , 1.3*6.206}, // NNLO-QCD NLO-EWK (34)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_3prong0pizerosUp"             , 1.3*6.206}, // NNLO-QCD NLO-EWK (35)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_3prong0pizerosDown"           , 1.3*6.206}, // NNLO-QCD NLO-EWK (36)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_uesUp"       , 1.3*6.206}, // NNLO-QCD NLO-EWK (37)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_uesDown"     , 1.3*6.206}, // NNLO-QCD NLO-EWK (38)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8"                     , 1.3*6.238}, // NNLO-QCD NLO-EWK (39)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_jesUp"               , 1.3*6.238}, // NNLO-QCD NLO-EWK (40)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_jesDown"             , 1.3*6.238}, // NNLO-QCD NLO-EWK (41)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_muUp"                , 1.3*6.238}, // NNLO-QCD NLO-EWK (42)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_muDown"              , 1.3*6.238}, // NNLO-QCD NLO-EWK (43)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_uesUp"               , 1.3*6.238}, // NNLO-QCD NLO-EWK (44)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_uesDown"             , 1.3*6.238}, // NNLO-QCD NLO-EWK (45)
};
// Sources of xsecs:
// (1) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), NNLO: https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeV -> k-factor = 61526.7/52600 = 1.17
// (2-5) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), k-factor see (1)
// (6-9) from Adinda's Mail from the 26th of March 2018, k-factor from Teresa's Email
// (10-16) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer)
// (17) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer)
// (18) from: https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeVInclusive (LO xsec = 64.3 from https://cms-gen-dev.cern.ch/xsdb (DAS=WW_TuneCUETP8M1_13TeV-pythia8))
// (19) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer)
// (20) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), NNLO: https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeV -> k-factor = 5765.4/5345 = 1.079
// (20a-20d) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), k-factor see (20)
// (21) from: https://cms-gen-dev.cern.ch/xsdb (DAS=TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8)
// (22) from: https://cms-gen-dev.cern.ch/xsdb (DAS=TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8)
// (23) from: https://cms-gen-dev.cern.ch/xsdb (DAS=TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8)
// (24-27) from: https://twiki.cern.ch/twiki/bin/viewauth/CMS/TauIDMeasurementsHelp
// (28-38) from: https://cms-gen-dev.cern.ch/xsdb (DAS=WToTauNu_M-200_TuneCUETP8M1_13TeV-pythia8-tauola), k-factor = 1.3 (valid for m_W>200GeV and m_W<1TeV, see: https://indico.cern.ch/event/712797/contributions/2928866/attachments/1615436/2567073/TauIdMomScaleW_20180312.pdf)
// (29-45) from: https://cms-gen-dev.cern.ch/xsdb (DAS=WToMuNu_M-200_TuneCUETP8M1_13TeV-pythia8), k-factor: see (28-38)
// ----------------------------------------------------------------------------------------------------
void loadWorkingPoints()
{
  iso.push_back("VTightMva");
  iso.push_back("TightMva");
  iso.push_back("MediumMva");
  iso.push_back("LooseMva");
  iso.push_back("Tight");
  iso.push_back("Medium");
  iso.push_back("Loose");
}
// ----------------------------------------------------------------------------------------------------
double getXSec(TString sampleName)
{
  if( xsecs.find(sampleName) == xsecs.end() ) return 1;
  return xsecs[sampleName];
}
// ----------------------------------------------------------------------------------------------------
struct selectionCuts {
  TString name;
  int  selection;
  bool trigger = false;
  float recoilRatioLow, recoilRatioHigh;
  float recoilDPhiLow;
  float metLow = 0;
  float tauPtLow,tauPtHigh;
  bool metFilters;
  unsigned int nMuonLow, nMuonHigh;
  unsigned int nElecLow, nElecHigh;
  unsigned int nSelTausLow, nSelTausHigh;
  unsigned int nJetsCentral30Low, nJetsCentral30High;
  unsigned int nJetsForward30Low, nJetsForward30High;
  bool tauDM, tauAntiMuonLoose3, tauAntiElectronLooseMVA6, tauIso;
  int tauGenMatchDecayLow, tauGenMatchDecayHigh;
  float mtmuonLow=0;
  float mtmuonHigh=10000.;
  float mttauLow=0;
  float mttauHigh = 1000.;
  float recoilPtLow = 0.;
  bool pfJetTrigger = false;
  float muonAbsEtaHigh = 5.0;
  float muonPtLow = 0.;
  float dPhiMetTauLow = 0;
  float mhtNoMuLow = 0;
  float metNoMuLow = 0;
} sr, sr_trueTaus, sr_fakeTaus, cr_antiiso,  cr_antiiso_trueTaus, cr_antiiso_fakeTaus, cr_ewkFraction, cr_fakerate_den, cr_fakerate_num, cr_fakerate_dijet_den, cr_fakerate_dijet_num, sr_munu;
// ----------------------------------------------------------------------------------------------------
void initCuts()
{
  // signal region
  sr.name = "sr";
  sr.selection = 3;
  sr.trigger   = true;
  sr.recoilRatioLow  = 0.00;
  sr.recoilRatioHigh = 100000.;
  sr.recoilDPhiLow = 2.8;
  sr.metLow = 120;
  sr.tauPtLow = 100;
  sr.tauPtHigh = 10000000;
  sr.metFilters = true;
  sr.nMuonLow  = 0; 
  sr.nMuonHigh = 0; 
  sr.nElecLow  = 0; 
  sr.nElecHigh = 0; 
  sr.nSelTausLow  = 1; 
  sr.nSelTausHigh = 1; 
  sr.nJetsCentral30Low  = 1;
  sr.nJetsCentral30High = 1;
  sr.nJetsForward30Low  = 0;
  sr.nJetsForward30High = 0;
  sr.tauDM = true;
  sr.tauAntiMuonLoose3 = true;
  sr.tauAntiElectronLooseMVA6 = true;
  sr.tauIso = true;
  sr.tauGenMatchDecayLow  = -1000;
  sr.tauGenMatchDecayHigh = 1000;
  sr.mtmuonLow  = 0;
  sr.mtmuonHigh = 100000000;
  sr.mttauLow  = 0;
  sr.mttauHigh = 100000000;
  sr.mhtNoMuLow = 120;
  sr.metNoMuLow = 120;

  // sr for true taus
  sr_trueTaus = sr;
  sr_trueTaus.name = "sr_trueTaus";
  sr_trueTaus.tauGenMatchDecayLow  = 0;
  sr_trueTaus.tauGenMatchDecayHigh = 1000;

  // sr for fake taus
  sr_fakeTaus = sr;
  sr_fakeTaus.name = "sr_fakeTaus";
  sr_fakeTaus.tauGenMatchDecayLow  = -1000;
  sr_fakeTaus.tauGenMatchDecayHigh = -1;
  
  // sr for W->munu selection
  sr_munu = sr;
  sr_munu.name = "sr_munu";
  sr_munu.selection = 2;
  sr_munu.nSelTausLow = 0;
  sr_munu.nSelTausHigh = 0;
  sr_munu.nMuonLow = 1;
  sr_munu.nMuonHigh = 1;
  sr_munu.metLow = 100;
  sr_munu.muonAbsEtaHigh = 2.1;
  sr_munu.muonPtLow = 120;
  sr_munu.trigger = false;
  sr_munu.nJetsCentral30Low  = 0;
  sr_munu.nJetsCentral30High = 0;
  sr_munu.tauPtLow = 0;
   
  // antiiso region
  cr_antiiso = sr;
  cr_antiiso.name = "cr_antiiso";
  cr_antiiso.tauIso = false;

  // antiiso region true taus
  cr_antiiso_trueTaus = sr_trueTaus;
  cr_antiiso_trueTaus.name = "cr_antiiso_trueTaus";
  cr_antiiso_trueTaus.tauIso = false;

  // antiiso region fake taus
  cr_antiiso_fakeTaus = sr_fakeTaus;
  cr_antiiso_fakeTaus.name = "cr_antiiso_fakeTaus";
  cr_antiiso_fakeTaus.tauIso = false;

  // cr for ewk fraction (fake factor weight is not applied)
  cr_ewkFraction = cr_antiiso;
  cr_ewkFraction.name = "cr_ewkFraction";

  // cr_fakerate_den
  cr_fakerate_den = sr;
  cr_fakerate_den.name = "cr_fakerate_den";
  cr_fakerate_den.selection = 1;
  cr_fakerate_den.nMuonLow  = 1;
  cr_fakerate_den.nMuonHigh = 1;
  cr_fakerate_den.nElecLow  = 0;
  cr_fakerate_den.nElecHigh = 0;
  cr_fakerate_den.nJetsCentral30Low  = 1;
  cr_fakerate_den.nJetsCentral30High = 1;
  cr_fakerate_den.recoilRatioLow  = 0.0;
  cr_fakerate_den.recoilRatioHigh = 10000.;
  cr_fakerate_den.mtmuonLow = 0;
  cr_fakerate_den.metLow = 120;
  cr_fakerate_den.tauIso = false;
  cr_fakerate_den.mttauLow = 0;
  cr_fakerate_den.recoilDPhiLow = 0.0;
  cr_fakerate_den.tauPtLow = 100;
  cr_fakerate_den.recoilPtLow = 0.;
  cr_fakerate_den.dPhiMetTauLow = 2.8;

  // cr_fakerate_num
  cr_fakerate_num = cr_fakerate_den;
  cr_fakerate_num.name = "cr_fakerate_num";
  cr_fakerate_num.tauIso = true;

  // cr_fakerate_dijet_den
  cr_fakerate_dijet_den.name = "cr_fakerate_dijet_den";
  cr_fakerate_dijet_den.selection = 4;
  cr_fakerate_dijet_den.nMuonLow  = 0;
  cr_fakerate_dijet_den.nMuonHigh = 0;
  cr_fakerate_dijet_den.nElecLow  = 0;
  cr_fakerate_dijet_den.nElecHigh = 0;
  cr_fakerate_dijet_den.nSelTausLow  = 1; 
  cr_fakerate_dijet_den.nSelTausHigh = 1; 
  cr_fakerate_dijet_den.nJetsCentral30Low  = 2;
  cr_fakerate_dijet_den.nJetsCentral30High = 2;
  cr_fakerate_dijet_den.nJetsForward30Low  = 0;
  cr_fakerate_dijet_den.nJetsForward30High = 1000000.;
  cr_fakerate_dijet_den.tauPtLow = 100;
  cr_fakerate_dijet_den.tauPtHigh = 10000000;
  cr_fakerate_dijet_den.recoilDPhiLow = 2.8;
  cr_fakerate_dijet_den.recoilRatioLow  = 0.0;
  cr_fakerate_dijet_den.recoilRatioHigh = 100000.;
  cr_fakerate_dijet_den.metFilters = true;
  cr_fakerate_dijet_den.tauDM = true;
  cr_fakerate_dijet_den.tauAntiMuonLoose3 = true;
  cr_fakerate_dijet_den.tauAntiElectronLooseMVA6 = true;
  cr_fakerate_dijet_den.tauIso = false;
  cr_fakerate_dijet_den.tauGenMatchDecayLow  = -1000;
  cr_fakerate_dijet_den.tauGenMatchDecayHigh = -1;
  cr_fakerate_dijet_den.recoilPtLow = 120.;
  cr_fakerate_dijet_den.pfJetTrigger  = true;

  // cr_fakerate_num
  cr_fakerate_dijet_num = cr_fakerate_dijet_den;
  cr_fakerate_dijet_num.name = "cr_fakerate_dijet_num";
  cr_fakerate_dijet_num.tauIso = true;
}
// ----------------------------------------------------------------------------------------------------
double getNEventsProcessed(TString filename)
{
  TFile * file = new TFile(filename);
  TH1D * histWeightsH = (TH1D*)file->Get("histWeightsH");
  double nevents = histWeightsH->GetSumOfWeights();
  file->Close();
  delete file;
  return nevents;
}
// ----------------------------------------------------------------------------------------------------
void loadFakeRates(TString filename)
{
  h_fakerate      = new map<TString,TH2D>();
  h_fakerate_up   = new map<TString,TH2D>();
  h_fakerate_down = new map<TString,TH2D>();

  TFile *f1 = new TFile(filename,"READ");
  if(!f1){
    cout<<"File "<<filename<<" does not exists. Exiting."<<endl;
    exit(-1);
  }

  TIter next(f1->GetListOfKeys());
  TKey *key = 0;

  while ((key = (TKey*)next())) 
    {
      TClass *c = gROOT->GetClass(key->GetClassName());
      if (!c->InheritsFrom("TH2")) continue;
      TH2D *h = (TH2D*) key->ReadObj();
      h->SetDirectory(0);
      TString hName = h->GetName();
      if(hName.Contains("_Up")){
	h_fakerate_up   -> insert( std::make_pair(h->GetName(),*h) );
      }
      else if(hName.Contains("_Down")){
	h_fakerate_down -> insert( std::make_pair(h->GetName(),*h) );
      }
      else{
	h_fakerate      -> insert( std::make_pair(h->GetName(),*h) );
      }
      delete h;
    }
  delete key;
}
// ----------------------------------------------------------------------------------------------------
double getFakeRates(float ratio, float jetPt, TString iso, TString err)
{
  for(int i=1; i<= h_fakerate->at(iso).GetNbinsX(); i++){
    if( ratio > h_fakerate->at(iso).GetXaxis()->GetBinLowEdge(i) && ratio < h_fakerate->at(iso).GetXaxis()->GetBinUpEdge(i)){
      for(int j=1; j<= h_fakerate->at(iso).GetNbinsY(); j++){
	if( jetPt > h_fakerate->at(iso).GetYaxis()->GetBinLowEdge(j) && jetPt < h_fakerate->at(iso).GetYaxis()->GetBinUpEdge(j)){
	  if( err == Form("%i%iUp",i,j))         return h_fakerate_up->at(iso).GetBinContent(i,j);
	  else if( err == Form("%i%iDown",i,j) ) return h_fakerate_down->at(iso).GetBinContent(i,j);
	  else                                   return h_fakerate->at(iso).GetBinContent(i,j);
	}
      }
    }
  }
  return 0;
}
// ----------------------------------------------------------------------------------------------------
void makeSelection(TString filename, TString treename, double xsec, TString iso, selectionCuts sel, TH1* histo, TString variableToFill_1, TString variableToFill_2, TString variableToFill_3)
{
  if(variableToFill_1 == variableToFill_2) histo->SetName(variableToFill_1);
  else                                     histo->SetName(variableToFill_1 + "_" + variableToFill_2);

  TFile * file = new TFile(filename);
  if(!file){
    cout<<"The following tree does not exit: "<<filename<<" .   Please Check."<<endl;
  }
  TTreeReader *myReader = new TTreeReader(treename, file);

  TTreeReaderValue< UInt_t  >  event(            *myReader,       "event");
  TTreeReaderValue< UInt_t  >  run(              *myReader,       "run");
  TTreeReaderValue< UInt_t  >  lumi(             *myReader,       "luminosityBlock");
  TTreeReaderValue< Float_t >  mttau(            *myReader,       "mttau");
  //TTreeReaderValue< Float_t >  mtgen(            *myReader,       "mtgen");
  TTreeReaderValue< Float_t >  puWeight(         *myReader,       "puWeight");
  TTreeReaderValue< Float_t >  genWeight(        *myReader,       "genWeight");
  TTreeReaderValue< Float_t >  trigWeight(       *myReader,       "trigWeight");
  TTreeReaderValue< Bool_t  >  trig(             *myReader,       "trigger");
  TTreeReaderValue< Float_t >  mutrigweight(     *myReader,       "mutrigweight");
  TTreeReaderValue< Float_t >  mueffweight(      *myReader,       "mueffweight");
  TTreeReaderValue< Int_t   >  Selection(        *myReader,       "Selection");
  TTreeReaderValue< Float_t >  recoilRatio(      *myReader,       "recoilRatio");
  TTreeReaderValue< Float_t >  recoilDPhi(       *myReader,       "recoilDPhi");
  TTreeReaderValue< Float_t >  dPhiMetTau(       *myReader,       "dPhiMetTau");
  TTreeReaderValue< Float_t >  met(              *myReader,       "met");
  TTreeReaderValue< Float_t >  metphi(           *myReader,       "metphi");
  TTreeReaderValue< Float_t >  tauPt(            *myReader,       "tauPt");
  TTreeReaderValue< Float_t >  tauEta(           *myReader,       "tauEta");
  TTreeReaderValue< Float_t >  tauPhi(           *myReader,       "tauPhi");
  //TTreeReaderValue< Float_t >  genTauWPt(        *myReader,       "genTauWPt");
  //TTreeReaderValue< Float_t >  genTauWEta(       *myReader,       "genTauWEta");
  //TTreeReaderValue< Float_t >  genTauWPhi(       *myReader,       "genTauWPhi");
  //TTreeReaderValue< Float_t >  genTauWE(         *myReader,       "genTauWE");
  TTreeReaderValue< Float_t >  lepWPt(           *myReader,       "lepWPt");
  TTreeReaderValue< Float_t >  lepWEta(          *myReader,       "lepWEta");
  TTreeReaderValue< Float_t >  lepWPhi(          *myReader,       "lepWPhi");
  //TTreeReaderValue< Float_t >  lepWE(            *myReader,      "lepWE");
  TTreeReaderValue< Float_t >  tauJetPt(         *myReader,       "tauJetPt");
  TTreeReaderValue< Float_t >  tauJetEta(        *myReader,       "tauJetEta");
  TTreeReaderValue< Bool_t  >  tauJetTightId(    *myReader,       "tauJetTightId");
  TTreeReaderValue< Float_t >  muonPt(           *myReader,       "muonPt");
  TTreeReaderValue< Float_t >  muonEta(          *myReader,       "muonEta");
  TTreeReaderValue< Float_t >  muonPhi(          *myReader,       "muonPhi");
  TTreeReaderValue< Bool_t  >  metFilters(       *myReader,       "metFilters");
  TTreeReaderValue< UInt_t  >  nMuon(            *myReader,       "nMuon");
  TTreeReaderValue< UInt_t  >  nElec(            *myReader,       "nElec");
  TTreeReaderValue< UInt_t  >  nSelTaus(         *myReader,       "nSelTaus");
  TTreeReaderValue< UInt_t  >  nJetsCentral30(   *myReader,       "nJetsCentral30");
  TTreeReaderValue< UInt_t  >  nJetsForward30(   *myReader,       "nJetsForward30");
  TTreeReaderValue< Bool_t  >  tauDM(            *myReader,       "tauDM");
  TTreeReaderValue< Bool_t  >  tauAntiMuonLoose3(*myReader,       "tauAntiMuonTight3");
  TTreeReaderValue< Bool_t  >  tauAntiElectronLooseMVA6(*myReader,"tauAntiElectronVTightMVA6");
  TTreeReaderValue< Bool_t  >  tauIso(           *myReader,       "tau"+iso+"Iso");
  TTreeReaderValue< Int_t   >  tauGenMatchDecay( *myReader,       "tauGenMatchDecay");
  TTreeReaderValue< UInt_t  >  tauGenMatch(      *myReader,       "tauGenMatch");
  TTreeReaderValue< Int_t   >  tauDecay(         *myReader,       "tauDecay");
  TTreeReaderValue< Float_t >  mtmuon(           *myReader,       "mtmuon");
  TTreeReaderValue< Float_t >  jetPt(            *myReader,       "jetPt");
  TTreeReaderValue< Float_t >  jetEta(           *myReader,       "jetEta");
  TTreeReaderValue< Float_t >  jetPhi(           *myReader,       "jetPhi");
  TTreeReaderValue< Float_t >  recoilPt(         *myReader,       "recoilPt");
  TTreeReaderValue< UInt_t  >  npartons(         *myReader,       "npartons");
  TTreeReaderValue< Float_t >  lheWPt(           *myReader,       "lheWPt");
  TTreeReaderValue< Float_t >  Ht(               *myReader,       "Ht");
  TTreeReaderValue< Float_t >  mhtNoMu(          *myReader,       "mhtNoMu");
  TTreeReaderValue< Float_t >  metNoMu(          *myReader,       "metNoMu");
  TTreeReaderValue< Bool_t  >  pfJet60(          *myReader,       "pfJet60");
  TTreeReaderValue< Bool_t  >  pfJet80(          *myReader,       "pfJet80");
  TTreeReaderValue< Bool_t  >  pfJet140(         *myReader,       "pfJet140");
  
  TTreeReaderValue< Bool_t  >  *pfJet200 = NULL;
  TTreeReaderValue< Bool_t  >  *pfJet260 = NULL;
  TTreeReaderValue< Bool_t  >  *pfJet320 = NULL;
  TTreeReaderValue< Bool_t  >  *pfJet400 = NULL;
  TTreeReaderValue< Bool_t  >  *pfJet450 = NULL;
  if(filename.Contains("JetHT")){
    pfJet200 = new TTreeReaderValue<Bool_t>(*myReader,"pfJet200");
    pfJet260 = new TTreeReaderValue<Bool_t>(*myReader,"pfJet260");
    pfJet320 = new TTreeReaderValue<Bool_t>(*myReader,"pfJet320");
    pfJet400 = new TTreeReaderValue<Bool_t>(*myReader,"pfJet400");
    pfJet450 = new TTreeReaderValue<Bool_t>(*myReader,"pfJet450");
  }

  TTreeReaderValue< Float_t >  var1(             *myReader,       variableToFill_1);
  TTreeReaderValue< Float_t >  var2(             *myReader,       variableToFill_2);
  TTreeReaderValue< Float_t >  var3(             *myReader,       variableToFill_3);

  int nevtsProcessed = getNEventsProcessed(filename);
  double norm = xsec*luminosity/nevtsProcessed;

  // Needed for stitching
  double nevtsProcessedWIncl = getNEventsProcessed(dir+"WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessedW1Jet = getNEventsProcessed(dir+"W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessedW2Jet = getNEventsProcessed(dir+"W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessedW3Jet = getNEventsProcessed(dir+"W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessedW4Jet = getNEventsProcessed(dir+"W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double xsecWIncl = xsecs["WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsecW1Jet = xsecs["W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsecW2Jet = xsecs["W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsecW3Jet = xsecs["W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsecW4Jet = xsecs["W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double nevtsProcessedDYIncl = getNEventsProcessed(dir+"DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessedDY1Jet = getNEventsProcessed(dir+"DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessedDY2Jet = getNEventsProcessed(dir+"DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessedDY3Jet = getNEventsProcessed(dir+"DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessedDY4Jet = getNEventsProcessed(dir+"DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double xsecDYIncl = xsecs["DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsecDY1Jet = xsecs["DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsecDY2Jet = xsecs["DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsecDY3Jet = xsecs["DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsecDY4Jet = xsecs["DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"];

  bool isData = filename.Contains("SingleMuon") || filename.Contains("JetHT") || filename.Contains("MET");
  while(myReader->Next()){

    if(*trig != sel.trigger && sel.selection == 3) continue;
    //if(sel.selection == 4 && (*pfJet40 != sel.pfJetTrigger && *pfJet60 != sel.pfJetTrigger && *pfJet80 != sel.pfJetTrigger && *pfJet140 != sel.pfJetTrigger && *(*pfJet200) != sel.pfJetTrigger && *(*pfJet260) != sel.pfJetTrigger && *(*pfJet320) != sel.pfJetTrigger && *(*pfJet400) != sel.pfJetTrigger && *(*pfJet450) != sel.pfJetTrigger && *(*pfJet500) != sel.pfJetTrigger)) continue;
    if(sel.selection == 4 && (*pfJet60 != sel.pfJetTrigger && *pfJet80 != sel.pfJetTrigger && *pfJet140 != sel.pfJetTrigger && *(*pfJet200) != sel.pfJetTrigger && *(*pfJet260) != sel.pfJetTrigger && *(*pfJet320) != sel.pfJetTrigger && *(*pfJet400) != sel.pfJetTrigger && *(*pfJet450) != sel.pfJetTrigger)) continue;

    if(*Selection != sel.selection) continue;
    if(*recoilRatio < sel.recoilRatioLow || *recoilRatio > sel.recoilRatioHigh) continue;
    if(*recoilDPhi < sel.recoilDPhiLow) continue;

    if(*mhtNoMu < sel.mhtNoMuLow) continue;
    if(*metNoMu < sel.metNoMuLow) continue;
    if(*met < sel.metLow) continue;
    if((*tauPt < sel.tauPtLow || *tauPt > sel.tauPtHigh) && sel.selection!=2) continue;
    if(*metFilters != sel.metFilters) continue;
   
    if(*nMuon<sel.nMuonLow || *nMuon>sel.nMuonHigh) continue;
    if(*nElec<sel.nElecLow || *nElec>sel.nElecHigh) continue;
    if(*nSelTaus<sel.nSelTausLow || *nSelTaus>sel.nSelTausHigh) continue;
    if(*nJetsCentral30<sel.nJetsCentral30Low || *nJetsCentral30>sel.nJetsCentral30High) continue;
    if(*nJetsForward30<sel.nJetsForward30Low || *nJetsForward30>sel.nJetsForward30High) continue;
   
    if(*tauDM != sel.tauDM && sel.selection!=2) continue;
    if(*tauAntiMuonLoose3 != sel.tauAntiMuonLoose3 && sel.selection!=2) continue;
    if(*tauAntiElectronLooseMVA6 != sel.tauAntiElectronLooseMVA6 && sel.selection!=2) continue;
    if(*tauIso != sel.tauIso && sel.selection!=2) continue;
    if((*tauGenMatchDecay<sel.tauGenMatchDecayLow || *tauGenMatchDecay>sel.tauGenMatchDecayHigh) && !isData) continue;
   
    if(*mtmuon < sel.mtmuonLow || *mtmuon > sel.mtmuonHigh ) continue;
    if(abs(*muonEta) > sel.muonAbsEtaHigh && sel.selection == 2) continue;
    if(*muonPt < sel.muonPtLow && sel.selection == 2) continue;
   
    Float_t fakerate = 1;
    if(sel.name.Contains("cr_antiiso")){
      fakerate = getFakeRates( *tauPt/(*tauJetPt),*tauJetPt,iso, sel.name(11,sel.name.Length()) );
    }
    if(sel.name.Contains("cr_fakerate") || sel.name.Contains("sr_munu")) *trigWeight = 1;
    if(!sel.name.Contains("cr_fakerate") && !sel.name.Contains("sr_munu")){*mueffweight=1;*mutrigweight=1;}

    // Stitching only for wjets MC in n-jet binned samples in npartons
    if(filename.Contains("W") && filename.Contains("JetsToLNu") && !filename.Contains("HT") && !filename.Contains("LHE")){
      if(*npartons == 1)      norm=luminosity/( nevtsProcessedW1Jet/xsecW1Jet + nevtsProcessedWIncl/xsecWIncl );
      else if(*npartons == 2) norm=luminosity/( nevtsProcessedW2Jet/xsecW2Jet + nevtsProcessedWIncl/xsecWIncl );
      else if(*npartons == 3) norm=luminosity/( nevtsProcessedW3Jet/xsecW3Jet + nevtsProcessedWIncl/xsecWIncl );
      else if(*npartons == 4) norm=luminosity/( nevtsProcessedW4Jet/xsecW4Jet + nevtsProcessedWIncl/xsecWIncl );
      else                    norm=luminosity/( nevtsProcessedWIncl/xsecWIncl );
    }

    // Stitching only for DY MC in npartons
    if(filename.Contains("DY") && filename.Contains("JetsToLL_M-50")){
      if (*npartons == 1)      norm = luminosity/( nevtsProcessedDY1Jet/xsecDY1Jet + nevtsProcessedDYIncl/xsecDYIncl );
      else if (*npartons == 2) norm = luminosity/( nevtsProcessedDY2Jet/xsecDY2Jet + nevtsProcessedDYIncl/xsecDYIncl );
      else if (*npartons == 3) norm = luminosity/( nevtsProcessedDY3Jet/xsecDY3Jet + nevtsProcessedDYIncl/xsecDYIncl );
      else if (*npartons == 4) norm = luminosity/( nevtsProcessedDY4Jet/xsecDY4Jet + nevtsProcessedDYIncl/xsecDYIncl );
      else                     norm = luminosity/( nevtsProcessedDYIncl/xsecDYIncl );
    }

    if(*recoilPt<sel.recoilPtLow) continue;
    if(*dPhiMetTau<sel.dPhiMetTauLow) continue;

    double weight = (*mueffweight)*(*mutrigweight)*(*puWeight)*(*trigWeight)*(*genWeight)*norm*fakerate;
    if(isData) weight =1;
    if(isData && sel.name.Contains("cr_antiiso")) weight = fakerate;

    if((*tauDecay < 1 || *tauDecay>4) && sel.selection != 2 && tauDecayMode == "_1prongUpTo4pizeros") continue;
    if(*tauDecay != 0 && sel.selection != 2 && tauDecayMode == "_1prong0pizeros") continue;
    if(*tauDecay != 10 && sel.selection != 2 && tauDecayMode == "_3prong0pizeros") continue;

    if( histo->InheritsFrom("TH2") ){
      if(variableToFill_1==variableToFill_2) ((TH2*) histo) -> Fill(abs(*var1), abs(*var3), weight);
      else                                   ((TH2*) histo) -> Fill(abs(*var1)/abs(*var2),abs(*var3), weight);
    }
    else{
      if(variableToFill_1==variableToFill_2) histo    -> Fill( abs(*var1), weight );
      else                                   histo    -> Fill( abs(*var1)/abs(*var2), weight );
    }
  }

  file->Close();
  delete file;
  delete myReader;

}

// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------
#endif

