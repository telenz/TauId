#include "HttStylesNew.cc"
#include "settings.h"
#include "boost/algorithm/string.hpp"


void TriggerEfficiency() {

  SetStyle();
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();

  std::vector< std::pair<string,std::vector<string>> > samples;

  std::vector<string> MC;
  MC.push_back("WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  MC.push_back("W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  MC.push_back("W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  MC.push_back("W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  MC.push_back("W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8");
  MC.push_back("W1JetsToLNu_LHEWpT_100-150");
  MC.push_back("W1JetsToLNu_LHEWpT_150-250");
  MC.push_back("W1JetsToLNu_LHEWpT_250-400");
  MC.push_back("W1JetsToLNu_LHEWpT_400-inf");
  MC.push_back("WToMuNu_M-200_TuneCP5_13TeV-pythia8");
  std::vector<string> Data;
  Data.push_back("SingleMuon_Run2017");
  samples.push_back(make_pair("MC"   , MC));
  samples.push_back(make_pair("Data" , Data));


  // Needed for stitching
  double xsecIncl = xsecs["WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsec1Jet = xsecs["W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsec2Jet = xsecs["W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsec3Jet = xsecs["W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsec4Jet = xsecs["W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8"];
  double xsec1JetLHEWpT_100to150 = xsecs["W1JetsToLNu_LHEWpT_100-150"];
  double xsec1JetLHEWpT_150to250 = xsecs["W1JetsToLNu_LHEWpT_150-250"];
  double xsec1JetLHEWpT_250to400 = xsecs["W1JetsToLNu_LHEWpT_250-400"];
  double xsec1JetLHEWpT_400toinf = xsecs["W1JetsToLNu_LHEWpT_400-inf"];
  double xsecWToMuNu_M200 = xsecs["WToMuNu_M-200_TuneCP5_13TeV-pythia8"];
  double nevtsProcessedIncl = getNEventsProcessed(dir+"WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessed1Jet = getNEventsProcessed(dir+"W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessed2Jet = getNEventsProcessed(dir+"W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessed3Jet = getNEventsProcessed(dir+"W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessed4Jet = getNEventsProcessed(dir+"W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8.root");
  double nevtsProcessed1JetLHEWpT_100to150 = getNEventsProcessed(dir+"W1JetsToLNu_LHEWpT_100-150.root");
  double nevtsProcessed1JetLHEWpT_150to250 = getNEventsProcessed(dir+"W1JetsToLNu_LHEWpT_150-250.root");
  double nevtsProcessed1JetLHEWpT_250to400 = getNEventsProcessed(dir+"W1JetsToLNu_LHEWpT_250-400.root");
  double nevtsProcessed1JetLHEWpT_400toinf = getNEventsProcessed(dir+"W1JetsToLNu_LHEWpT_400-inf.root");
  double nevtsProcessedWToMuNu_M200 = getNEventsProcessed(dir+"WToMuNu_M-200_TuneCP5_13TeV-pythia8.root");

  std::map<string,TGraphAsymmErrors*> effMapData;
  std::map<string,TGraphAsymmErrors*> effMapMC;

  Float_t bins[]  = {0,120,130,140,150,160,170,180,190,200,220,240,280,320,380,800};
  const int nbins = sizeof(bins)/sizeof(Float_t) - 1;

  for (unsigned int i=0; i<samples.size(); ++i) {

    TH1D* histo_num_120ToInf = new TH1D( (samples[i].first + "_num_120ToInf").c_str() ,"",nbins,bins);
    TH1D* histo_den_120ToInf = new TH1D( (samples[i].first + "_den_120ToInf").c_str() ,"",nbins,bins);
    TH1D* histo_num_0To120   = new TH1D( (samples[i].first + "_num_0To120").c_str() ,"",nbins,bins);
    TH1D* histo_den_0To120   = new TH1D( (samples[i].first + "_den_0To120").c_str() ,"",nbins,bins);
    TH1D* histo_num_120To160 = new TH1D( (samples[i].first + "_num_120To160").c_str() ,"",nbins,bins);
    TH1D* histo_den_120To160 = new TH1D( (samples[i].first + "_den_120To160").c_str() ,"",nbins,bins);
    TH1D* histo_num_160To200 = new TH1D( (samples[i].first + "_num_160To200").c_str() ,"",nbins,bins);
    TH1D* histo_den_160To200 = new TH1D( (samples[i].first + "_den_160To200").c_str() ,"",nbins,bins);
    TH1D* histo_num_200ToInf = new TH1D( (samples[i].first + "_num_200ToInf").c_str() ,"",nbins,bins);
    TH1D* histo_den_200ToInf = new TH1D( (samples[i].first + "_den_200ToInf").c_str() ,"",nbins,bins);

    for(unsigned int idx_list=0; idx_list<samples[i].second.size(); idx_list++){

      string filename = string(dir) + samples[i].second[idx_list] + ".root";
      TFile * file = new TFile( filename.c_str() );
      if(!file)	cout<<"The following tree does not exit: "<<filename<<" .   Please Check."<<endl;

      TTreeReader *myReader = new TTreeReader("TriggerNTuple",file);

      TTreeReaderValue< Float_t >  mhtNoMu(          *myReader,       "mhtNoMu");
      TTreeReaderValue< Float_t >  metNoMu(          *myReader,       "metNoMu");
      TTreeReaderValue< Float_t >  mht(              *myReader,       "mht");
      TTreeReaderValue< Float_t >  met(              *myReader,       "met");
      TTreeReaderValue< Bool_t  >  IsW(              *myReader,       "IsW");
      TTreeReaderValue< Bool_t  >  trigger(          *myReader,       "trigger");
      TTreeReaderValue< UInt_t  >  npartons(         *myReader,       "npartons");
      TTreeReaderValue< UInt_t  >  npartonsNLO(      *myReader,       "npartonsNLO");
      TTreeReaderValue< Float_t >  lheWPt(           *myReader,       "lheWPt");
      TTreeReaderValue< Float_t >  mtmuon(           *myReader,       "mtmuon");
      TTreeReaderValue< Float_t >  muonPt(           *myReader,       "muonPt");
      TTreeReaderValue< Float_t >  muonEta(          *myReader,       "muonEta");
      TTreeReaderValue< Float_t >  dPhiMetMuon(      *myReader,       "dPhiMetMuon");
      TTreeReaderValue< Float_t >  WMass(            *myReader,       "WMass");
      TTreeReaderValue< Float_t >  puWeight(         *myReader,       "puWeight");
      TTreeReaderValue< Float_t >  genWeight(        *myReader,       "genWeight");


      cout<<"---------- Processing  "<<samples[i].second[idx_list]<<"  ---------- "<<endl;

      while(myReader->Next()){

	double weight = (*genWeight)*(*puWeight);
	double norm   = 1.;

	// STITCHING
	if( boost::contains(samples[i].first,"MC") && samples[i].second.size()>1){

	  norm =0;
	  double add_NEvtsOverXsec = 0;

	  add_NEvtsOverXsec += nevtsProcessedIncl/xsecIncl;

	  if(*npartons==1)        add_NEvtsOverXsec += nevtsProcessed1Jet/xsec1Jet;
	  else if(*npartons==2)   add_NEvtsOverXsec += nevtsProcessed2Jet/xsec2Jet;
	  else if(*npartons==3)   add_NEvtsOverXsec += nevtsProcessed3Jet/xsec3Jet;
	  else if(*npartons==4)   add_NEvtsOverXsec += nevtsProcessed4Jet/xsec4Jet;

	  if(*npartonsNLO==1){
	    if      ( *lheWPt >= 100  && *lheWPt < 150 ) add_NEvtsOverXsec += nevtsProcessed1JetLHEWpT_100to150/xsec1JetLHEWpT_100to150;
	    else if ( *lheWPt >= 150  && *lheWPt < 250 ) add_NEvtsOverXsec += nevtsProcessed1JetLHEWpT_150to250/xsec1JetLHEWpT_150to250;
	    else if ( *lheWPt >= 250  && *lheWPt < 400 ) add_NEvtsOverXsec += nevtsProcessed1JetLHEWpT_250to400/xsec1JetLHEWpT_250to400;
	    else if ( *lheWPt >= 400 )                   add_NEvtsOverXsec += nevtsProcessed1JetLHEWpT_400toinf/xsec1JetLHEWpT_400toinf;
	  }

	  if(*WMass >= 200) add_NEvtsOverXsec += nevtsProcessedWToMuNu_M200/xsecWToMuNu_M200;

	  if(add_NEvtsOverXsec !=0 ) norm = luminosity/add_NEvtsOverXsec;

	}

	// CUTS
	if(*IsW != true)    continue; // this includes an mtmuon cut of 40GeV
	if(*mtmuon < 50)    continue;
	if(*muonPt < 30)    continue;
	//if(*mhtNoMu < 120 ) continue;
	//if(*metNoMu < 120 ) continue;

	if(*mhtNoMu < 120)                        histo_den_0To120   -> Fill( *metNoMu, weight*norm );
	else if(*mhtNoMu > 120 && *mhtNoMu < 160) histo_den_120To160 -> Fill( *metNoMu, weight*norm );
	else if(*mhtNoMu > 160 && *mhtNoMu < 200) histo_den_160To200 -> Fill( *metNoMu, weight*norm );
	else if(*mhtNoMu > 200 )                  histo_den_200ToInf -> Fill( *metNoMu, weight*norm );

	histo_den_120ToInf -> Fill( *metNoMu, weight*norm );
	
	if(*trigger != true)   continue;

	histo_num_120ToInf -> Fill( *metNoMu, weight*norm );

	if(*mhtNoMu < 120)                        histo_num_0To120   -> Fill( *metNoMu, weight*norm );
	else if(*mhtNoMu > 120 && *mhtNoMu < 160) histo_num_120To160 -> Fill( *metNoMu, weight*norm );
	else if(*mhtNoMu > 160 && *mhtNoMu < 200) histo_num_160To200 -> Fill( *metNoMu, weight*norm );
	else if(*mhtNoMu > 200 )                  histo_num_200ToInf -> Fill( *metNoMu, weight*norm );
      }
    }

    TGraphAsymmErrors * eff_120ToInf = new TGraphAsymmErrors();
    TGraphAsymmErrors * eff_0To120   = new TGraphAsymmErrors();
    TGraphAsymmErrors * eff_120To160 = new TGraphAsymmErrors();
    TGraphAsymmErrors * eff_160To200 = new TGraphAsymmErrors();
    TGraphAsymmErrors * eff_200ToInf = new TGraphAsymmErrors();

    eff_120ToInf -> Divide( histo_num_120ToInf , histo_den_120ToInf , "n");
    eff_0To120   -> Divide( histo_num_0To120   , histo_den_0To120   , "n");
    eff_120To160 -> Divide( histo_num_120To160 , histo_den_120To160 , "n");
    eff_160To200 -> Divide( histo_num_160To200 , histo_den_160To200 , "n");
    eff_200ToInf -> Divide( histo_num_200ToInf , histo_den_200ToInf , "n");


    if( boost::contains(samples[i].first , "Data") ){
	effMapData[ samples[i].first + "_120ToInf" ] = (TGraphAsymmErrors*) eff_120ToInf -> Clone();
	effMapData[ samples[i].first + "_0To120" ]   = (TGraphAsymmErrors*) eff_0To120   -> Clone();
	effMapData[ samples[i].first + "_120To160" ] = (TGraphAsymmErrors*) eff_120To160 -> Clone();
	effMapData[ samples[i].first + "_160To200" ] = (TGraphAsymmErrors*) eff_160To200 -> Clone();
	effMapData[ samples[i].first + "_200ToInf" ] = (TGraphAsymmErrors*) eff_200ToInf -> Clone();
      }
      else{
	effMapMC[ samples[i].first + "_120ToInf" ]   = (TGraphAsymmErrors*) eff_120ToInf -> Clone();
	effMapMC[ samples[i].first + "_0To120" ]     = (TGraphAsymmErrors*) eff_0To120   -> Clone();
	effMapMC[ samples[i].first + "_120To160" ]   = (TGraphAsymmErrors*) eff_120To160 -> Clone();
	effMapMC[ samples[i].first + "_160To200" ]   = (TGraphAsymmErrors*) eff_160To200 -> Clone();
	effMapMC[ samples[i].first + "_200ToInf" ]   = (TGraphAsymmErrors*) eff_200ToInf -> Clone();
      }
  }


  TFile * fileOutput = new TFile("output/trigger_eff.root","recreate");
  fileOutput         -> cd("");    

  for (auto const& x : effMapData){

    std::cout << x.first  // string (key)
              << std::endl ;

    size_t pos = x.first.find("_");
    string mhtNoMuRangeName = x.first.substr (pos+1);
    cout<<"mhtNoMu Range Name = "<<mhtNoMuRangeName<<endl;

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
    x.second->SetMarkerSize(0.7);
    x.second->GetYaxis()->SetTitle("Trigger Efficiency");
    x.second->GetXaxis()->SetTitle("E_{T, no #mu}^{mis} [GeV]");
    x.second->GetYaxis()->SetTitleOffset(1.2);
    x.second->GetXaxis()->SetTitleOffset(1.1);
    x.second->SetMaximum(1.0);
    x.second->SetMinimum(0.0);
    x.second->GetXaxis()->SetRangeUser(bins[0],bins[nbins]);
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
    canv->Update();
    canv->Print( ("figures/trigger_turnon_" + mhtNoMuRangeName + ".png").c_str() );
    // ################################ Plotting Ends ###########

    // ################################ Saving Starts ###########
    x.second           -> Write( ("data_" +  mhtNoMuRangeName).c_str() );
    effMapMC[keyMC]    -> Write( ("mc_" +  mhtNoMuRangeName).c_str() );
    // ################################ Saving End ###########
  }
  fileOutput         -> Close();
}
