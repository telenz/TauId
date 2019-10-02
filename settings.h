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
//#define ERA_2018
#define ERA_2017
//#define ERA_2016

#ifdef ERA_2018
    #include"settings_era_specific_2018.h"
#endif
#ifdef ERA_2017
    #include"settings_era_specific_2017.h"
#endif
#ifdef ERA_2016
    #include"settings_era_specific_2016.h"
#endif

TString tauDecayMode = "";
//TString tauDecayMode = "_3prong0pizeros";
//TString tauDecayMode = "_1prong0pizeros";
//TString tauDecayMode = "_1prongUpTo4pizeros";
double tauMomScale = 1.00;
bool doTauESmeasurement = false; //if set to true: tau mass cuts depending on the studied decay mode are applied

// Introduce global variables for tau pt dependent measurement
double tau_pt_low = 100;
double tau_pt_high = 1000000;

std::vector<TString> iso;
map<TString,TH2D>* h_fakerate      = new map<TString,TH2D>();
map<TString,TH2D>* h_fakerate_up   = new map<TString,TH2D>();
map<TString,TH2D>* h_fakerate_down = new map<TString,TH2D>();

TH1D* h_kFactor= 0;

// Definition of mttau and mtmuon bins
vector<Float_t> mtmuon_bins = { 0 , 100 , 200 , 300 , 400 , 500 , 600 , 700 , 1000};
//vector<Float_t> mttau_bins  = { 0 , 100 , 200 , 300 , 400 , 500 , 600 , 700 , 800 , 900 , 1000};
vector<Float_t> mttau_bins  = { 0 , 50, 100 , 150, 200 , 250, 300 , 350, 400 , 450, 500 , 550, 600 ,650, 700 ,750, 800 , 850, 900 , 950, 1000};

//Float_t bins[] = { 200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500};
//Float_t bins[] = { 100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};
//Float_t bins[] = {0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8};  // tauMass binning 3prong
//Float_t bins[] = {0.0, 0.1,0.2, 0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9, 2.0,2.1, 2.2,2.2, 2.4};  // tauMass binning

// ----------------------------------------------------------------------------------------------------
void loadWorkingPoints()
{
  iso.push_back("VVLooseDeepTau2017v2p1");
  iso.push_back("VLooseDeepTau2017v2p1");
  iso.push_back("LooseDeepTau2017v2p1");
  iso.push_back("MediumDeepTau2017v2p1");
  iso.push_back("TightDeepTau2017v2p1");
  iso.push_back("VTightDeepTau2017v2p1");
  iso.push_back("VVTightDeepTau2017v2p1");
  iso.push_back("VLooseMva2017v2");
  iso.push_back("LooseMva2017v2");
  iso.push_back("MediumMva2017v2");
  iso.push_back("TightMva2017v2");
  iso.push_back("VTightMva2017v2");
  iso.push_back("VVTightMva2017v2");
  /* iso.push_back("Tight"); */
  /* iso.push_back("Medium"); */
  /* iso.push_back("Loose"); */
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
} sr, sr_trueTaus, sr_fakeTaus, cr_antiiso,  cr_antiiso_trueTaus, cr_antiiso_fakeTaus, cr_ewkFraction, cr_fakerate_den, cr_fakerate_num, cr_fakerate_norm, cr_fakerate_dijet_den, cr_fakerate_dijet_num, sr_munu;
// ----------------------------------------------------------------------------------------------------
void initCuts()
{
  // signal region
  sr.name = "sr";
  sr.selection = 3;
  sr.trigger   = true;
  sr.recoilDPhiLow = 2.8;
  sr.metLow = 130;
  sr.tauPtLow = tau_pt_low;
  sr.tauPtHigh = tau_pt_high;
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
  sr.mhtNoMuLow = 130;
  sr.metNoMuLow = 130;

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
  sr_munu.metLow = 130;
  sr_munu.muonAbsEtaHigh = 2.1;
  sr_munu.muonPtLow = 120;
  sr_munu.trigger = false;
  sr_munu.nJetsCentral30Low  = 0;
  sr_munu.nJetsCentral30High = 0;
  sr_munu.tauPtLow = 0;
  sr_munu.mhtNoMuLow = 0;
  sr_munu.metNoMuLow = 0;

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
  cr_fakerate_den.mtmuonLow = 0;
  cr_fakerate_den.metLow = 130;
  cr_fakerate_den.tauIso = false;
  cr_fakerate_den.mttauLow = 0;
  cr_fakerate_den.recoilDPhiLow = 0.0;
  cr_fakerate_den.tauPtLow = 100;
  cr_fakerate_den.tauPtHigh = 1000000;
  cr_fakerate_den.recoilPtLow = 0.;
  cr_fakerate_den.dPhiMetTauLow = 2.8;
  
  // cr_fakerate_num
  cr_fakerate_num = cr_fakerate_den;
  cr_fakerate_num.name = "cr_fakerate_num";
  cr_fakerate_num.tauIso = true;

  // cr_fakerate for WJets and ZJets normalization
  cr_fakerate_norm = cr_fakerate_den;
  cr_fakerate_norm.name = "cr_fakerate_norm";
  cr_fakerate_norm.trigger = true;
  cr_fakerate_norm.mhtNoMuLow = 130.;
  cr_fakerate_norm.metNoMuLow = 130.;


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
  cr_fakerate_dijet_den.nJetsForward30High = 0;
  cr_fakerate_dijet_den.tauPtLow = 100;
  cr_fakerate_dijet_den.tauPtHigh = 1000000;
  cr_fakerate_dijet_den.recoilDPhiLow = 2.8;
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
  if( !file->GetListOfKeys()->Contains("histWeightsH") ){
    cout << " File "<<filename<<" not available -> nevents set to 0 !!!!!!" << endl;
    return 0;
  }
  TH1D * histWeightsH = (TH1D*)file->Get("histWeightsH");
  double nevents = histWeightsH->GetSumOfWeights();
  file->Close();
  delete file;
  return nevents;
}
// Needed for stitching
double xsecWIncl = xsecs[wjets];
double xsecW1Jet = xsecs[w1jets];
double xsecW2Jet = xsecs[w2jets];
double xsecW3Jet = xsecs[w3jets];
double xsecW4Jet = xsecs[w4jets];
double nevtsProcessedWIncl = getNEventsProcessed(dir+wjets+".root");
double nevtsProcessedW1Jet = getNEventsProcessed(dir+w1jets+".root");
double nevtsProcessedW2Jet = getNEventsProcessed(dir+w2jets+".root");
double nevtsProcessedW3Jet = getNEventsProcessed(dir+w3jets+".root");
double nevtsProcessedW4Jet = getNEventsProcessed(dir+w4jets+".root");
double xsecWHT70To100    = 0;
double xsecWHT100To200   = 0;
double xsecWHT200To400   = 0;
double xsecWHT400To600   = 0;
double xsecWHT600To800   = 0;
double xsecWHT800To1200  = 0;
double xsecWHT1200To2500 = 0;
double xsecWHT2500ToInf  = 0;
double nevtsProcessedWHT70To100    = 0;
double nevtsProcessedWHT100To200   = 0;
double nevtsProcessedWHT200To400   = 0;
double nevtsProcessedWHT400To600   = 0;
double nevtsProcessedWHT600To800   = 0;
double nevtsProcessedWHT800To1200  = 0;
double nevtsProcessedWHT1200To2500 = 0;
double nevtsProcessedWHT2500ToInf  = 0;
double xsecDYIncl = xsecs[dyjets];
double xsecDY1Jet = xsecs[dy1jets];
double xsecDY2Jet = xsecs[dy2jets];
double xsecDY3Jet = xsecs[dy3jets];
double xsecDY4Jet = xsecs[dy4jets];
double nevtsProcessedDYIncl = getNEventsProcessed(dir+dyjets+".root");
double nevtsProcessedDY1Jet = getNEventsProcessed(dir+dy1jets+".root");
double nevtsProcessedDY2Jet = getNEventsProcessed(dir+dy2jets+".root");
double nevtsProcessedDY3Jet = getNEventsProcessed(dir+dy3jets+".root");
double nevtsProcessedDY4Jet = getNEventsProcessed(dir+dy4jets+".root");
// ----------------------------------------------------------------------------------------------------
void loadFakeRates(TString filename)
{
 
  h_fakerate->clear();
  h_fakerate_up->clear();
  h_fakerate_down->clear();

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
               if( err == Form("%i%iUp",i,j))         return h_fakerate_up->at(iso+"_Up").GetBinContent(i,j);
               else if( err == Form("%i%iDown",i,j) ) return h_fakerate_down->at(iso+"_Down").GetBinContent(i,j);
               else                                   return h_fakerate->at(iso).GetBinContent(i,j);
            }
      }
    }
  }
  return 0;
}
// ----------------------------------------------------------------------------------------------------
void loadkFactors(TString filename){
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
         if (!c->InheritsFrom("TH1")) continue;
         TH1D *h = (TH1D*) key->ReadObj();
         h->SetDirectory(0);
         h_kFactor = (TH1D*)h->Clone();
         delete h;
      }
   delete key;
}
// ----------------------------------------------------------------------------------------------------
double GetkFactor(TString filename, float_t wmass){
   TString hname = h_kFactor->GetName();
   if (filename.Contains("WToMuNu") && !hname.Contains("kfactor_mu"))
      {
         cout<<"Wrong k factor hist provided. Exiting."<<endl;
         exit(-1);
      }
   if (filename.Contains("WToTauNu") && !hname.Contains("kfactor_tau"))
      {
         cout<<"Wrong k factor hist provided. Exiting."<<endl;
         exit(-1);
      }
   if (wmass > 1000) wmass = 1000;
   for(int i=1; i<= h_kFactor->GetNbinsX(); i++){
      if( wmass > h_kFactor->GetXaxis()->GetBinLowEdge(i) && wmass <= h_kFactor->GetXaxis()->GetBinUpEdge(i)){
         return h_kFactor->GetBinContent(i);
      }
   }
   return 0;
}
// ----------------------------------------------------------------------------------------------------
float dPhiFrom2P(float Px1, float Py1, float Px2, float Py2) {
	float prod = Px1*Px2 + Py1*Py2;
	float mod1 = TMath::Sqrt(Px1*Px1+Py1*Py1);
	float mod2 = TMath::Sqrt(Px2*Px2+Py2*Py2);

	float cosDPhi = prod/(mod1*mod2);

	return TMath::ACos(cosDPhi);
}
// ----------------------------------------------------------------------------------------------------
double dPhiFromLV(TLorentzVector v1, TLorentzVector v2) {

  return dPhiFrom2P(v1.Px(),v1.Py(),v2.Px(),v2.Py());

}
// ----------------------------------------------------------------------------------------------------
double mT (TLorentzVector v1, TLorentzVector Metv){

  double dPhimT=dPhiFrom2P( v1.Px(), v1.Py(), Metv.Px(),  Metv.Py() );

  double MT = TMath::Sqrt(2*v1.Pt()*Metv.Pt()*(1-TMath::Cos(dPhimT)));
  return MT;
}
// ----------------------------------------------------------------------------------------------------
void makeSelection(TString fullPath, TString treename, double xsec, TString iso, selectionCuts sel, TH1* histo, TString variableToFill_1, TString variableToFill_2, TString variableToFill_3)
{

  if(era != "2017"){
    xsecWHT70To100    = xsecs[wjets_HT70To100];
    xsecWHT100To200   = xsecs[wjets_HT100To200];
    xsecWHT200To400   = xsecs[wjets_HT200To400];
    xsecWHT400To600   = xsecs[wjets_HT400To600];
    xsecWHT600To800   = xsecs[wjets_HT600To800];
    xsecWHT800To1200  = xsecs[wjets_HT800To1200];
    xsecWHT1200To2500 = xsecs[wjets_HT1200To2500];
    xsecWHT2500ToInf  = xsecs[wjets_HT2500ToInf];
    nevtsProcessedWHT70To100    = getNEventsProcessed(dir+wjets_HT70To100+".root");
    nevtsProcessedWHT100To200   = getNEventsProcessed(dir+wjets_HT100To200+".root");
    nevtsProcessedWHT200To400   = getNEventsProcessed(dir+wjets_HT200To400+".root");
    nevtsProcessedWHT400To600   = getNEventsProcessed(dir+wjets_HT400To600+".root");
    nevtsProcessedWHT600To800   = getNEventsProcessed(dir+wjets_HT600To800+".root");
    nevtsProcessedWHT800To1200  = getNEventsProcessed(dir+wjets_HT800To1200+".root");
    nevtsProcessedWHT1200To2500 = getNEventsProcessed(dir+wjets_HT1200To2500+".root");
    nevtsProcessedWHT2500ToInf  = getNEventsProcessed(dir+wjets_HT2500ToInf+".root");
  }

  TString filename = fullPath(fullPath.Last('/') + 1 , fullPath.Length());

  if(variableToFill_1 == variableToFill_2) histo->SetName(variableToFill_1);
  else                                     histo->SetName(variableToFill_1 + "_" + variableToFill_2);

  TFile * file = new TFile(fullPath);
  if(!file){
    cout<<"The following tree does not exit: "<<fullPath<<" .   Please Check."<<endl;
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
  TTreeReaderValue< Float_t >  recoilDPhi(       *myReader,       "recoilDPhi");
  TTreeReaderValue< Float_t >  dPhiMetTau(       *myReader,       "dPhiMetTau");
  TTreeReaderValue< Float_t >  met(              *myReader,       "met");
  TTreeReaderValue< Float_t >  metphi(           *myReader,       "metphi");
  TTreeReaderValue< Float_t >  tauPt(            *myReader,       "tauPt");
  TTreeReaderValue< Float_t >  tauPz(            *myReader,       "tauPz");
  TTreeReaderValue< Float_t >  tauEta(           *myReader,       "tauEta");
  TTreeReaderValue< Float_t >  tauPhi(           *myReader,       "tauPhi");
  TTreeReaderValue< Float_t >  tauMass(          *myReader,       "tauMass");
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
  TTreeReaderValue< Float_t >  muonPz(           *myReader,       "muonPz");
  TTreeReaderValue< Float_t >  muonEta(          *myReader,       "muonEta");
  TTreeReaderValue< Float_t >  muonPhi(          *myReader,       "muonPhi");
  TTreeReaderValue< Bool_t  >  metFilters(       *myReader,       "metFilters");
  TTreeReaderValue< UInt_t  >  nMuon(            *myReader,       "nMuon");
  TTreeReaderValue< UInt_t  >  nElec(            *myReader,       "nElec");
  TTreeReaderValue< UInt_t  >  nSelTaus(         *myReader,       "nSelTaus");
  TTreeReaderValue< UInt_t  >  nJetsCentral30(   *myReader,       "nJetsCentral30");
  TTreeReaderValue< UInt_t  >  nJetsForward30(   *myReader,       "nJetsForward30");
  TTreeReaderValue< Bool_t  >  tauDM(            *myReader,       "tauDM");
  TTreeReaderValue< Bool_t  >  tauNewDM(         *myReader,       "tauNewDM");
  TTreeReaderValue< Bool_t  >  *tauIso = NULL;
  TTreeReaderValue< Bool_t  >  *tauAntiMuonLoose3 = NULL;
  TTreeReaderValue< Bool_t  >  *tauAntiElectronLooseMVA6 = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoLooseMva = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoMediumMva = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoTightMva = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoVTightMva = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoVVTightMva = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoVVLooseDeep = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoVLooseDeep = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoLooseDeep = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoMediumDeep= NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoTightDeep = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoVTightDeep = NULL;
  TTreeReaderValue< Bool_t  >  *tauIsoVVTightDeep = NULL;
  if(iso.Contains("Deep")){
     tauIso             = new TTreeReaderValue<Bool_t>(       *myReader,       "tauby"+iso+"VSjet");
     tauIsoVVLooseDeep  = new TTreeReaderValue<Bool_t>(       *myReader,       "taubyVVLooseDeepTau2017v2p1VSjet");
     tauIsoVLooseDeep   = new TTreeReaderValue<Bool_t>(       *myReader,       "taubyVLooseDeepTau2017v2p1VSjet");
     tauIsoLooseDeep    = new TTreeReaderValue<Bool_t>(       *myReader,       "taubyLooseDeepTau2017v2p1VSjet");
     tauIsoMediumDeep   = new TTreeReaderValue<Bool_t>(       *myReader,       "taubyMediumDeepTau2017v2p1VSjet");
     tauIsoTightDeep    = new TTreeReaderValue<Bool_t>(       *myReader,       "taubyTightDeepTau2017v2p1VSjet");
     tauIsoVTightDeep   = new TTreeReaderValue<Bool_t>(       *myReader,       "taubyVTightDeepTau2017v2p1VSjet");
     tauIsoVVTightDeep  = new TTreeReaderValue<Bool_t>(       *myReader,       "taubyVVTightDeepTau2017v2p1VSjet");
     tauAntiMuonLoose3  = new TTreeReaderValue<Bool_t>(       *myReader,       "taubyTightDeepTau2017v2p1VSmu");
     tauAntiElectronLooseMVA6 = new TTreeReaderValue<Bool_t>( *myReader,       "taubyVVTightDeepTau2017v2p1VSe");
  }
  else{
     tauAntiMuonLoose3 = new TTreeReaderValue<Bool_t> (*myReader,       "tauAntiMuonTight3");
     tauAntiElectronLooseMVA6 = new TTreeReaderValue<Bool_t>(*myReader,"tauAntiElectronVTightMVA6");
     tauIso = new TTreeReaderValue<Bool_t>(           *myReader,       "tau"+iso+"Iso");
     tauIsoLooseMva = new TTreeReaderValue<Bool_t>(   *myReader,       "tauLooseMva2017v2Iso");
     tauIsoMediumMva = new TTreeReaderValue<Bool_t>(  *myReader,       "tauMediumMva2017v2Iso");
     tauIsoTightMva = new TTreeReaderValue<Bool_t>(   *myReader,       "tauTightMva2017v2Iso");
     tauIsoVTightMva = new TTreeReaderValue<Bool_t>(  *myReader,       "tauVTightMva2017v2Iso");
     tauIsoVVTightMva = new TTreeReaderValue<Bool_t>( *myReader,       "tauVVTightMva2017v2Iso");
  }
  TTreeReaderValue< Bool_t  >  *tauIsoLoose = NULL;
  /* tauIsoLoose = new TTreeReaderValue<Bool_t>(*myReader,"tauVVLooseMva2017v2Iso"); */
  if(iso.Contains("Mva")) tauIsoLoose = new TTreeReaderValue<Bool_t>(*myReader,"tauVVLooseMva2017v2Iso");
  else if(iso.Contains("Deep")) tauIsoLoose = new TTreeReaderValue<Bool_t>(*myReader,"taubyVVVLooseDeepTau2017v2p1VSjet");
  else                    tauIsoLoose = new TTreeReaderValue<Bool_t>(*myReader,"tauLooseIso");
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
  TTreeReaderValue< Float_t >  genHt(            *myReader,       "genHt");
  TTreeReaderValue< Float_t >  Ht(               *myReader,       "Ht");
  TTreeReaderValue< Float_t >  wmass(            *myReader,       "WMass");
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

  int nevtsProcessed = getNEventsProcessed(fullPath);
  double norm = xsec*luminosity/nevtsProcessed;

  bool isData = filename.Contains("SingleMuon") || filename.Contains("JetHT") || filename.Contains("MET");
  
  double metx = 0.;
  double mety = 0.;
  double tauPx= 0.;
  double tauPy= 0.;
  double tauPx_ms= 0.;
  double tauPy_ms= 0.;
  double muonPx= 0.;
  double muonPy= 0.;
  double metx_ms= 0.;
  double mety_ms= 0.;
  TLorentzVector lorentzVectorTau_ms;
  TLorentzVector lorentzVectorMet_ms;
  TLorentzVector lorentzVectorMu;
  double k_factor = 1.;

  while(myReader->Next()){
    
     if (doTauESmeasurement && !isData && *tauGenMatchDecay > 0 && *tauGenMatchDecay<1000 && sel.selection == 3){

        metx = *met*TMath::Cos(*metphi);
        mety = *met*TMath::Sin(*metphi);
        tauPx = *tauPt*TMath::Cos(*tauPhi);
        tauPy = *tauPt*TMath::Sin(*tauPhi);
        
        tauPx_ms = tauPx*tauMomScale;
        tauPy_ms = tauPy*tauMomScale;
        metx_ms = metx - (tauPx_ms-tauPx);
        mety_ms = mety - (tauPy_ms-tauPy);

        lorentzVectorTau_ms.SetXYZM(tauPx_ms,
                                    tauPy_ms,
                                    *tauPz*tauMomScale,
                                    *tauMass*tauMomScale);
        lorentzVectorMet_ms.SetXYZT(metx_ms,mety_ms,0,TMath::Sqrt(metx_ms*metx_ms+mety_ms*mety_ms));
   
        *recoilDPhi = dPhiFromLV(lorentzVectorTau_ms,lorentzVectorMet_ms);
        *met = TMath::Sqrt(metx_ms*metx_ms+mety_ms*mety_ms);
        *tauPt   *= tauMomScale;
        *tauJetPt*= tauMomScale;
        *tauMass *= tauMomScale;
        *dPhiMetTau = *recoilDPhi = dPhiFromLV(lorentzVectorTau_ms,lorentzVectorMet_ms);
        *mttau = mT(lorentzVectorTau_ms,lorentzVectorMet_ms);
        //metnomu and mhtnomu are not varied
     }

     if(*trig != sel.trigger && (sel.selection == 3 || sel.name == "cr_fakerate_norm" || sel.name == "cr_fakerate_den" || sel.name == "cr_fakerate_num" )) continue;
    //if(sel.selection == 4 && (*pfJet40 != sel.pfJetTrigger && *pfJet60 != sel.pfJetTrigger && *pfJet80 != sel.pfJetTrigger && *pfJet140 != sel.pfJetTrigger && *(*pfJet200) != sel.pfJetTrigger && *(*pfJet260) != sel.pfJetTrigger && *(*pfJet320) != sel.pfJetTrigger && *(*pfJet400) != sel.pfJetTrigger && *(*pfJet450) != sel.pfJetTrigger && *(*pfJet500) != sel.pfJetTrigger)) continue;
    if(sel.selection == 4 && (*pfJet60 != sel.pfJetTrigger && *pfJet80 != sel.pfJetTrigger && *pfJet140 != sel.pfJetTrigger && *(*pfJet200) != sel.pfJetTrigger && *(*pfJet260) != sel.pfJetTrigger && *(*pfJet320) != sel.pfJetTrigger && *(*pfJet400) != sel.pfJetTrigger && *(*pfJet450) != sel.pfJetTrigger)) continue;

    if(*Selection != sel.selection) continue;
    if(*recoilDPhi < sel.recoilDPhiLow) continue;

    if(*mhtNoMu < sel.mhtNoMuLow) continue;
    if(*metNoMu < sel.metNoMuLow) continue;
    if(*met < sel.metLow) continue;
    if((*tauPt < sel.tauPtLow || *tauPt > sel.tauPtHigh) && sel.selection!=2) continue;

    if (doTauESmeasurement){
       if (tauDecayMode == "_3prong0pizeros" && (*tauMass < 0.9 || *tauMass > 1.4) && sel.selection!=2) continue;
       if (tauDecayMode == "_1prongUpTo4pizeros" && (*tauMass < 0.4 || *tauMass > 1.8) && sel.selection!=2) continue;
    }

    if(*metFilters != sel.metFilters) continue;

    if(*nMuon<sel.nMuonLow || *nMuon>sel.nMuonHigh) continue;
    if(*nElec<sel.nElecLow || *nElec>sel.nElecHigh) continue;
    if(*nSelTaus<sel.nSelTausLow || *nSelTaus>sel.nSelTausHigh) continue;
    if(*nJetsCentral30<sel.nJetsCentral30Low || *nJetsCentral30>sel.nJetsCentral30High) continue;
    if(*nJetsForward30<sel.nJetsForward30Low || *nJetsForward30>sel.nJetsForward30High) continue;

    if (iso.Contains("Deep")){
       if(*tauNewDM != sel.tauDM && sel.selection!=2) continue;
    }
    else{
       if(*tauDM != sel.tauDM && sel.selection!=2) continue;
    }
    if(*(*tauAntiMuonLoose3) != sel.tauAntiMuonLoose3 && sel.selection!=2) continue;
    if(*(*tauAntiElectronLooseMVA6) != sel.tauAntiElectronLooseMVA6 && sel.selection!=2) continue;
    //if(*(*tauIsoVLooseDeep) == true && sel.selection!=2) continue;
    if(*(*tauIso) != sel.tauIso && sel.selection!=2 && sel.name != "cr_fakerate_norm") continue;
    if(*(*tauIsoLoose) != true && sel.name.Contains("cr_fakerate") ) continue;
    if((*tauGenMatchDecay<sel.tauGenMatchDecayLow || *tauGenMatchDecay>sel.tauGenMatchDecayHigh) && !isData) continue;

    if(*mtmuon < sel.mtmuonLow || *mtmuon > sel.mtmuonHigh ) continue;
    if(abs(*muonEta) > sel.muonAbsEtaHigh && sel.selection == 2) continue;
    if(*muonPt < sel.muonPtLow && sel.selection == 2) continue;
   
    Float_t fakerate = 1;
    if(sel.name.Contains("cr_antiiso") || sel.name.Contains("cr_ewkFraction")){
      if(*(*tauIsoLoose) != true ) continue;
    }
    if(sel.name.Contains("cr_antiiso")){
      fakerate = getFakeRates( *tauPt/(*tauJetPt),*tauJetPt,iso, sel.name(11,sel.name.Length()) );
    }
    if(sel.name.Contains("cr_fakerate_num") || sel.name.Contains("cr_fakerate_den") || sel.name.Contains("sr_munu")) *trigWeight = 1;
    if(!sel.name.Contains("cr_fakerate") && !sel.name.Contains("sr_munu")){*mueffweight=1;*mutrigweight=1;}

    // Stitching only for wjets MC in n-jet binned samples in npartons
    if(filename.Contains("W") && filename.Contains("JetsToLNu") && !filename.Contains("LHE")){

       double add_NEvtsOverXsec = 0;
       add_NEvtsOverXsec += nevtsProcessedWIncl/xsecWIncl;

       if(*npartons == 1)       add_NEvtsOverXsec += nevtsProcessedW1Jet/xsecW1Jet ;
       else if(*npartons == 2)  add_NEvtsOverXsec += nevtsProcessedW2Jet/xsecW2Jet ;
       else if(*npartons == 3)  add_NEvtsOverXsec += nevtsProcessedW3Jet/xsecW3Jet ;
       else if(*npartons == 4)  add_NEvtsOverXsec += nevtsProcessedW4Jet/xsecW4Jet ;

       if (*genHt >= 70 && era != "2017"){
          if (*genHt < 100)       add_NEvtsOverXsec += nevtsProcessedWHT70To100/xsecWHT70To100;
          else if (*genHt < 200)  add_NEvtsOverXsec += nevtsProcessedWHT100To200/xsecWHT100To200;
          else if (*genHt < 400)  add_NEvtsOverXsec += nevtsProcessedWHT200To400/xsecWHT200To400;
          else if (*genHt < 600)  add_NEvtsOverXsec += nevtsProcessedWHT400To600/xsecWHT400To600;
          else if (*genHt < 800)  add_NEvtsOverXsec += nevtsProcessedWHT600To800/xsecWHT600To800;
          else if (*genHt < 1200) add_NEvtsOverXsec += nevtsProcessedWHT800To1200/xsecWHT800To1200;
          else if (*genHt < 2500) add_NEvtsOverXsec += nevtsProcessedWHT1200To2500/xsecWHT1200To2500;
          else add_NEvtsOverXsec += nevtsProcessedWHT2500ToInf/xsecWHT2500ToInf;
       }
       if(add_NEvtsOverXsec !=0 ) norm = luminosity/add_NEvtsOverXsec;
    }


    // Stitching only for DY MC in npartons
    if(filename.Contains("DY") && filename.Contains("JetsToLL_M-50")){
      if (*npartons == 1)      norm = luminosity/( nevtsProcessedDY1Jet/xsecDY1Jet + nevtsProcessedDYIncl/xsecDYIncl );
      else if (*npartons == 2) norm = luminosity/( nevtsProcessedDY2Jet/xsecDY2Jet + nevtsProcessedDYIncl/xsecDYIncl );
      else if (*npartons == 3) norm = luminosity/( nevtsProcessedDY3Jet/xsecDY3Jet + nevtsProcessedDYIncl/xsecDYIncl );
      else if (*npartons == 4) norm = luminosity/( nevtsProcessedDY4Jet/xsecDY4Jet + nevtsProcessedDYIncl/xsecDYIncl );
      else                     norm = luminosity/( nevtsProcessedDYIncl/xsecDYIncl );
    }

    // apply mass dependent k-factors
    if(filename.Contains("WToTauNu") || filename.Contains("WToMuNu")) k_factor = GetkFactor(fullPath,*wmass);

    if(*recoilPt<sel.recoilPtLow) continue;
    if(*dPhiMetTau<sel.dPhiMetTauLow) continue;
    
    double weight = (*mueffweight)*(*mutrigweight)*(*puWeight)*(*trigWeight)*(*genWeight)*norm*k_factor*fakerate;
    if(isData) weight =1;
    if(isData && sel.name.Contains("cr_antiiso")) weight = fakerate;

    if((*tauDecay < 1 || *tauDecay>4) && sel.selection != 2 && tauDecayMode == "_1prongUpTo4pizeros") continue;
    if(*tauDecay != 0 && sel.selection != 2 && tauDecayMode == "_1prong0pizeros") continue;
    if(*tauDecay != 10 && *tauDecay != 11 && *tauDecay != 7 && sel.selection != 2 && tauDecayMode == "_3prong0pizeros") continue;

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

