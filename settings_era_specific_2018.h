#ifndef SETTINGS_ERA_SPECIFIC_2018_H
#define SETTINGS_ERA_SPECIFIC_2018_H

TString era = "2018";

TString dir = "/nfs/dust/cms/user/rasp/Run/Run2018/TauTrigger/";

double luminosity = 59740; // lumi determined by brilcalc
double lumi_unc = 1.025;

TString triggerfile_output_name = "trigger_eff_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_2018_v2.root";

TString kfactor_tau_file = "kfactor_tau.root";
TString kfactor_mu_file  = "kfactor_mu.root";

const int iPeriod = 8;

const vector<TString> SingleMuon_sample = { "SingleMuon_Run2018A",
					    "SingleMuon_Run2018B",
					    "SingleMuon_Run2018C",
					    "SingleMuon_Run2018D" };

const vector<TString> JetHT_sample = { "JetHT_Run2018A",
				       "JetHT_Run2018B",
				       "JetHT_Run2018C",
				       "JetHT_Run2018D" };

const vector<TString> MET_sample = { "MET_Run2018A",
				     "MET_Run2018B",
				     "MET_Run2018C",
				     "MET_Run2018D" };

const vector<TString> WToTauNu_sample = { "WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola" };

const vector<TString> WToMuNu_sample = { "WToMuNu_M-200_TuneCP5_13TeV-pythia8" };

const TString wjets  = "WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString w1jets = "W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString w2jets = "W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString w3jets = "W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString w4jets = "W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString wjets_HT70To100    = "WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString wjets_HT100To200   = "WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString wjets_HT200To400   = "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString wjets_HT400To600   = "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString wjets_HT600To800   = "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString wjets_HT800To1200  = "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString wjets_HT1200To2500 = "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString wjets_HT2500ToInf  = "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8";

const vector<TString> WJets_Trigger_sample = { wjets, w1jets, w2jets, w3jets, w4jets };
const vector<TString> WJets_sample = { wjets, w1jets, w2jets, w3jets, w4jets, wjets_HT70To100, wjets_HT100To200, wjets_HT200To400, wjets_HT400To600, wjets_HT600To800, wjets_HT800To1200, wjets_HT1200To2500, wjets_HT2500ToInf };
const vector<TString> WJets_closure_sample = WJets_sample;

const TString dyjets  = "DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString dy1jets = "DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString dy2jets = "DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString dy3jets = "DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8";
const TString dy4jets = "DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8";

const vector<TString> DYJets_sample = { dyjets, dy1jets, dy2jets, dy3jets, dy4jets };

const vector<TString>  ZJets_sample = { "ZJetsToNuNu_HT-100To200_13TeV-madgraph",
					"ZJetsToNuNu_HT-200To400_13TeV-madgraph",
					"ZJetsToNuNu_HT-400To600_13TeV-madgraph",
					"ZJetsToNuNu_HT-600To800_13TeV-madgraph",
					"ZJetsToNuNu_HT-800To1200_13TeV-madgraph",
					"ZJetsToNuNu_HT-1200To2500_13TeV-madgraph",
					"ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph" };


const vector<TString> TT_ST_sample = { "TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8",
				       "TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8",
				       "TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8",
				       "ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8",
				       "ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8",
				       "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",
				       "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8" };

const vector<TString> VV_sample = { "WW_TuneCP5_13TeV-pythia8",
				    "WZ_TuneCP5_13TeV-pythia8",
				    "ZZ_TuneCP5_13TeV-pythia8" };


map<TString, double> xsecs = {                             // numbers from 2017, maybe check if cross sections are still valid for 2018
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
{"DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"       , 6077.22},  // NNLO (20)
{"DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"      , 875.7*1.137}, // NNLO (20a)
{"DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"      , 306.9*1.137}, // NNLO (20b)
{"DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"      , 111.9*1.137}, // NNLO (20c)
{"DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8"      , 43.97*1.137}, // NNLO (20d)
{"DYJetsToLL_M-10to50_TuneCP5_13TeV-madgraphMLM-pythia8"   , 15820*1.137}, // NNLO (20e)
{"TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8"        , 88.29},  // NNLO (21)
{"TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8"     , 377.96}, // NNLO (22)
{"TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8" , 365.34}, // NNLO (23)
{"ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8"     , 44.33}, // ? (24) -> could be improved
{"ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8" , 26.38}, // ? (25) -> could be improved
{"ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8"                      , 35.85}, // ? (26) -> could be improved
{"ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8"                  , 35.85}, // ? (27) -> could be improved
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola"             , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK mass dependent k factor applied later (28)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_jesUp"       , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (29)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_jesDown"     , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (30)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_1prong0pizerosUp"             , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (31)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_1prong0pizerosDown"           , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (32)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_1prongUpTo4pizerosUp"         , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (33)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_1prongUpTo4pizerosDown"       , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (34)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_3prong0pizerosUp"             , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (35)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_taues_3prong0pizerosDown"           , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (36)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_uesUp"       , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (37)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_uesDown"     , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (38)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_tauesUp"     , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (37)
{"WToTauNu_M-200_TuneCP5_13TeV-pythia8-tauola_tauesDown"   , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (38)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8"                     , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (39)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_jesUp"               , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (40)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_jesDown"             , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (41)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_muUp"                , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (42)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_muDown"              , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (43)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_uesUp"               , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (44)
{"WToMuNu_M-200_TuneCP5_13TeV-pythia8_uesDown"             , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (45)
{"DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8" , 160.5}, // (46)
{"DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8", 48.37}, // (47)
{"DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8", 6.972}, // (48)
{"DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8", 1.746}, // (49)
{"DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8",  0.8101 }, // (50)
{"WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8",1286*1.166}, // (51)
{"WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8", 1395.0*1.166},// (52)
{"WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8", 407.9*1.166},// (53)
{"WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8", 57.48*1.166},// (54)
{"WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8", 12.87*1.166},// (55)
{"WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8", 5.366*1.166},// (56)
{"WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8", 1.074*1.166},// (57)
{"WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8", 0.008001*1.166}};// (58)
// Sources of xsecs:
// (1) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), NNLO: https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeV -> k-factor = 61526.7/52600 = 1.17
// (2-5) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), k-factor see (1)
// (6-9) from Adinda's Mail from the 26th of March 2018, k-factor from Teresa's Email
// (10-16) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer)
// (17) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer)
// (18) from: https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeVInclusive (LO xsec = 64.3 from https://cms-gen-dev.cern.ch/xsdb (DAS=WW_TuneCUETP8M1_13TeV-pythia8))
// (19) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer)
// (20) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), NNLO: https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeV -> k-factor = 6077.22/5345 = 1.137
// (20a-20e) from: LO: GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), k-factor see (20)
// (21) from: https://cms-gen-dev.cern.ch/xsdb (DAS=TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8)
// (22) from: https://cms-gen-dev.cern.ch/xsdb (DAS=TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8)
// (23) from: https://cms-gen-dev.cern.ch/xsdb (DAS=TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8)
// (24-27) from: https://twiki.cern.ch/twiki/bin/viewauth/CMS/TauIDMeasurementsHelp
// (28-38) LO GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), NNLO-QCD NLO-EWK from: https://cms-gen-dev.cern.ch/xsdb (DAS=WToTauNu_M-200_TuneCUETP8M1_13TeV-pythia8-tauola), k-factor = 1.3 (valid for m_W>200GeV and m_W<1TeV, see: https://indico.cern.ch/event/712797/contributions/2928866/attachments/1615436/2567073/TauIdMomScaleW_20180312.pdf)
// (29-45) LO GenXSec analyzer (https://twiki.cern.ch/twiki/bin/view/CMS/HowToGenXSecAnalyzer), NNLO-QCD NLO-EWK from: https://cms-gen-dev.cern.ch/xsdb (DAS=WToMuNu_M-200_TuneCUETP8M1_13TeV-pythia8), k-factor: see (28-38)
// (46) from GenXSec analyzer, k-factor: see (1)
// (46-50) from DAS, k-factor: see (1)

map<TString, int> n_events_per_sample = {};

#endif
