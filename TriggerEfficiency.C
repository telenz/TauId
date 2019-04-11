#include "HttStylesNew.cc"
#include "settings.h"
#include "boost/algorithm/string.hpp"
#include <iomanip>

void TriggerEfficiency() {

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  std::vector< std::pair<string,std::vector<TString>> > samples;

  std::vector<TString> MC = WJets_Trigger_sample;
  std::vector<TString> Data = SingleMuon_sample;
  samples.push_back(make_pair("MC"   , MC));
  samples.push_back(make_pair("Data" , Data));

  // Needed for stitching
  double xsecWIncl = xsecs[wjets];
  double xsecW1Jet = xsecs[w1jets];
  double xsecW2Jet = xsecs[w2jets];
  double xsecW3Jet = xsecs[w3jets];
  double xsecW4Jet = xsecs[w4jets];
  double xsecWHT70To100    = xsecs[wjets_HT70To100];
  double xsecWHT100To200   = xsecs[wjets_HT100To200];
  double xsecWHT200To400   = xsecs[wjets_HT200To400];
  double xsecWHT400To600   = xsecs[wjets_HT400To600];
  double xsecWHT600To800   = xsecs[wjets_HT600To800];
  double xsecWHT800To1200  = xsecs[wjets_HT800To1200];
  double xsecWHT1200To2500 = xsecs[wjets_HT1200To2500];
  double xsecWHT2500ToInf  = xsecs[wjets_HT2500ToInf];
  double nevtsProcessedWIncl = getNEventsProcessed(dir+wjets+".root");
  double nevtsProcessedW1Jet = getNEventsProcessed(dir+w1jets+".root");
  double nevtsProcessedW2Jet = getNEventsProcessed(dir+w2jets+".root");
  double nevtsProcessedW3Jet = getNEventsProcessed(dir+w3jets+".root");
  double nevtsProcessedW4Jet = getNEventsProcessed(dir+w4jets+".root");
  double nevtsProcessedWHT70To100    = getNEventsProcessed(dir+wjets_HT70To100+".root");
  double nevtsProcessedWHT100To200   = getNEventsProcessed(dir+wjets_HT100To200+".root");
  double nevtsProcessedWHT200To400   = getNEventsProcessed(dir+wjets_HT200To400+".root");
  double nevtsProcessedWHT400To600   = getNEventsProcessed(dir+wjets_HT400To600+".root");
  double nevtsProcessedWHT600To800   = getNEventsProcessed(dir+wjets_HT600To800+".root");
  double nevtsProcessedWHT800To1200  = getNEventsProcessed(dir+wjets_HT800To1200+".root");
  double nevtsProcessedWHT1200To2500 = getNEventsProcessed(dir+wjets_HT1200To2500+".root");
  double nevtsProcessedWHT2500ToInf  = getNEventsProcessed(dir+wjets_HT2500ToInf+".root");

  std::map<string,TGraphAsymmErrors*> effMapData;
  std::map<string,TGraphAsymmErrors*> effMapMC;

  Float_t binsMET[]  = {120,130,140,150,160,170,180,190,200,220,240,280,320,360,1000}; // the upper bound can be lower than for mhtNoMu since the trigger turn-on is read with the Eval() function which extrapolates also outside the TGraphAsymmError
  const int nbinsMET = sizeof(binsMET)/sizeof(Float_t) - 1;

  Float_t binsMHT[]  = {120,160,200,300,2000};
  const int nbinsMHT = sizeof(binsMHT)/sizeof(Float_t) - 1;

  for (unsigned int i=0; i<samples.size(); ++i) {

    TH2D* histo_num = new TH2D((samples[i].first + "_num").c_str() ,"",nbinsMET,binsMET,nbinsMHT,binsMHT);
    TH2D* histo_den = new TH2D((samples[i].first + "_den").c_str() ,"",nbinsMET,binsMET,nbinsMHT,binsMHT);

    for(unsigned int idx_list=0; idx_list<samples[i].second.size(); idx_list++){

      string filename = string(dir) + string(samples[i].second[idx_list]) + ".root";
      TFile * file = new TFile( filename.c_str() );
      if(!file)	cout<<"The following tree does not exit: "<<filename<<" .   Please Check."<<endl;

      TTreeReader *myReader = new TTreeReader("TriggerNTuple",file);

      TTreeReaderValue< Float_t >  mhtNoMu(          *myReader,       "mhtNoMu");
      TTreeReaderValue< Float_t >  metNoMu(          *myReader,       "metNoMu");
      TTreeReaderValue< Float_t >  mht(              *myReader,       "mht");
      TTreeReaderValue< Float_t >  met(              *myReader,       "met");
      TTreeReaderValue< Bool_t  >  IsW(              *myReader,       "IsW");
      TTreeReaderValue< Bool_t  >  trigger(          *myReader,       "trigger");
      TTreeReaderValue< Bool_t  >  metFilters(       *myReader,       "metFilters");
      TTreeReaderValue< UInt_t  >  npartons(         *myReader,       "npartons");
      TTreeReaderValue< UInt_t  >  npartonsNLO(      *myReader,       "npartonsNLO");
      TTreeReaderValue< Float_t >  lheWPt(           *myReader,       "lheWPt");
      TTreeReaderValue< Float_t >  mtmuon(           *myReader,       "mtmuon");
      TTreeReaderValue< Float_t >  muonPt(           *myReader,       "muonPt");
      TTreeReaderValue< Float_t >  muonEta(          *myReader,       "muonEta");
      TTreeReaderValue< Float_t >  dPhiMetMuon(      *myReader,       "dPhiMetMuon");
      TTreeReaderValue< Float_t >  WMass(            *myReader,       "WMass");
      TTreeReaderValue< UInt_t  >  nSelMuon(         *myReader,       "nSelMuon");
      TTreeReaderValue< UInt_t  >  nMuon(            *myReader,       "nMuon");
      TTreeReaderValue< Float_t >  puWeight(         *myReader,       "puWeight");
      TTreeReaderValue< Float_t >  genWeight(        *myReader,       "genWeight");
      // TTreeReaderValue< Float_t >  genHt(            *myReader,       "genHt");


      cout<<"---------- Processing  "<<samples[i].second[idx_list]<<"  ---------- "<<endl;

      double xsec = getXSec(samples[i].second[idx_list]);
      double nevtsProcessed = getNEventsProcessed(dir + samples[i].second[idx_list] + ".root");
      double norm = luminosity*xsec/nevtsProcessed;

      while(myReader->Next()){

	double weight = (*genWeight)*(*puWeight);

	if( boost::contains(samples[i].first,"Data") ){
	  weight = 1;
	  norm = 1;
	}

	// STITCHING
	if( boost::contains(samples[i].first,"MC") && samples[i].second.size()>1){

	  norm =0;
	  double add_NEvtsOverXsec = 0;
	  add_NEvtsOverXsec += nevtsProcessedWIncl/xsecWIncl;

	  if(*npartons == 1)       add_NEvtsOverXsec += nevtsProcessedW1Jet/xsecW1Jet ;
	  else if(*npartons == 2)  add_NEvtsOverXsec += nevtsProcessedW2Jet/xsecW2Jet ;
	  else if(*npartons == 3)  add_NEvtsOverXsec += nevtsProcessedW3Jet/xsecW3Jet ;
	  else if(*npartons == 4)  add_NEvtsOverXsec += nevtsProcessedW4Jet/xsecW4Jet ;

	  // if (*genHt >= 70){
	  //   if (*genHt < 100)       add_NEvtsOverXsec += nevtsProcessedWHT70To100/xsecWHT70To100;
	  //   else if (*genHt < 200)  add_NEvtsOverXsec += nevtsProcessedWHT100To200/xsecWHT100To200;
	  //   else if (*genHt < 400)  add_NEvtsOverXsec += nevtsProcessedWHT200To400/xsecWHT200To400;
	  //   else if (*genHt < 600)  add_NEvtsOverXsec += nevtsProcessedWHT400To600/xsecWHT400To600;
	  //   else if (*genHt < 800)  add_NEvtsOverXsec += nevtsProcessedWHT600To800/xsecWHT600To800;
	  //   else if (*genHt < 1200) add_NEvtsOverXsec += nevtsProcessedWHT800To1200/xsecWHT800To1200;
	  //   else if (*genHt < 2500) add_NEvtsOverXsec += nevtsProcessedWHT1200To2500/xsecWHT1200To2500;
	  //   else add_NEvtsOverXsec += nevtsProcessedWHT2500ToInf/xsecWHT2500ToInf;
	  // }
	  if(add_NEvtsOverXsec !=0 ) norm = luminosity/add_NEvtsOverXsec;

	}

	// CUTS
	if(*mhtNoMu<120)           continue;
	if(*metNoMu<120)           continue;
       if(*IsW != true)           continue; // this includes an mtmuon cut of 40GeV
       if(*mtmuon < 50)           continue;
       if(*muonPt < 120)          continue;
       if(abs(*muonEta) > 2.1)    continue;
       if(*nMuon!=1)              continue;
       if(*metFilters != true)    continue;

       histo_den -> Fill( *metNoMu , *mhtNoMu , weight*norm );

	if(*trigger != true)   continue;

	histo_num -> Fill( *metNoMu , *mhtNoMu , weight*norm );
      }
    }

    for(int ibin=1; ibin<=histo_den->GetNbinsY(); ibin++){

      TGraphAsymmErrors *eff = new TGraphAsymmErrors();
      eff -> Divide( (TH1D*) histo_num->ProjectionX(histo_num->GetName()+ibin,ibin,ibin) , (TH1D*) histo_den->ProjectionX(histo_den->GetName()+ibin,ibin,ibin) , "n");

      int lowEdge    = static_cast<int>(histo_den->GetYaxis() -> GetBinLowEdge(ibin));
      int upEdge     = static_cast<int>(histo_den->GetYaxis() -> GetBinUpEdge(ibin));
      cout<<"MHTNoMu bin "<<ibin<<" = "<<lowEdge<<" to "<<upEdge<<endl;

      string keyname = samples[i].first + "_" + to_string(lowEdge) + "To" + to_string(upEdge);

      if( boost::contains(samples[i].first , "Data") )	effMapData[ keyname ] = (TGraphAsymmErrors*) eff -> Clone();
      else                                              effMapMC[ keyname ]   = (TGraphAsymmErrors*) eff -> Clone();

    }

  } // end: loop over samples vector (contains Data and MC)


  TFile * fileOutput = new TFile("output/" + triggerfile_output_name,"recreate");
  fileOutput         -> cd("");    

  for (auto const& x : effMapData){

    std::cout << x.first  // string (key)
              << std::endl ;

    size_t pos = x.first.find("_");
    string mhtNoMuRangeName = x.first.substr (pos+1);

    // ################################ Plotting Starts ###########
    TCanvas * canv = new TCanvas("canv","",1000,700);

    TLegend * leg = NULL; 
    leg = new TLegend(0.6,0.2,0.9,0.45);
    SetLegendStyle(leg);
    leg->SetTextSize(0.05);
    leg->SetHeader("single #mu events, ");
    leg->Draw();
    
    x.second->SetMarkerStyle(20);
    x.second->SetMarkerColor(1);
    x.second->SetLineColor(1);
    x.second->SetMarkerSize(1);
    x.second->GetYaxis()->SetTitle("Trigger Efficiency");
    x.second->GetXaxis()->SetTitle("E_{T, no #mu}^{mis} [GeV]");
    x.second->GetYaxis()->SetTitleOffset(1.2);
    x.second->GetXaxis()->SetTitleOffset(1.1);
    x.second->SetMaximum(1.1);
    x.second->SetMinimum(0.0);
    x.second->GetXaxis()->SetRangeUser(binsMET[0],binsMET[nbinsMET]);
    x.second->SetTitle( ("MHTNoMu =" + mhtNoMuRangeName).c_str());
    x.second->Draw("ap");
    leg->AddEntry(x.second,"data","lp");
    
    string keyMC = "MC_" + mhtNoMuRangeName;
    effMapMC[keyMC]->SetMarkerStyle(21);
    effMapMC[keyMC]->SetMarkerColor(2);
    effMapMC[keyMC]->SetLineColor(2);
    effMapMC[keyMC]->SetMarkerSize(1);
    effMapMC[keyMC]->Draw("psame");    
    leg->AddEntry(effMapMC[keyMC],"simulation","lp");
    leg->Draw();
    canv->Update();
    canv->Print( ("figures/trigger_turnon_" + mhtNoMuRangeName + ".png").c_str() );
    // ################################ Plotting Ends ###########

    // ################################ Saving Starts ###########
    x.second        -> SetName( ("data_" +  mhtNoMuRangeName).c_str() );
    x.second        -> Write( ("data_" +  mhtNoMuRangeName).c_str() );
    effMapMC[keyMC] -> SetName( ("mc_" +  mhtNoMuRangeName).c_str() );
    effMapMC[keyMC] -> Write( ("mc_" +  mhtNoMuRangeName).c_str() );
    // ################################ Saving End ###########
  }
  fileOutput         -> Close();
}
