#ifndef SETTINGS_ERA_SPECIFIC_2017_H
#define SETTINGS_ERA_SPECIFIC_2017_H

TString era = "2017";

TString dir = "/nfs/dust/cms/user/tlenz/13TeV/2018/TauIDWithVirtualW/redo_all_years_with_bug_fix/TauId/NTuples/2017/";
TString dir_trigger = "/nfs/dust/cms/user/mameyer/TauIdAndES_ULData/TauId/NTuples/2017/TriggerEfficiencyMeasurement/";

double luminosity = 40991; // lumi determined by brilcalc
double lumi_unc = 1.023;

TString triggerfile_output_name = "trigger_eff_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_2017_v1.root";

TString kfactor_tau_file = "kfactor_tau.root";
TString kfactor_mu_file  = "kfactor_mu.root";

const int iPeriod = 6;

const vector<TString> SingleMuon_sample = { "SingleMuon_Run2017B",
					    "SingleMuon_Run2017C",
					    "SingleMuon_Run2017D",
					    "SingleMuon_Run2017E",
					    "SingleMuon_Run2017F"};

const vector<TString> JetHT_sample = { "JetHT_Run2017B",
                                       "JetHT_Run2017C",
                                       "JetHT_Run2017D",
                                       "JetHT_Run2017E",
                                       "JetHT_Run2017F"};

const vector<TString> MET_sample = { "MET_Run2017B",
                                     "MET_Run2017C",
                                     "MET_Run2017D",
                                     "MET_Run2017E",
                                     "MET_Run2017F"};

const vector<TString> WToTauNu_sample = { "WToTauNu_M-200" };

const vector<TString> WToMuNu_sample = { "WToMuNu_M-200" };

const TString wjets  = "WJetsToLNu";
const TString w1jets = "W1JetsToLNu";
const TString w2jets = "W2JetsToLNu";
const TString w3jets = "W3JetsToLNu";
const TString w4jets = "W4JetsToLNu";

const TString wjets_1Jets_LHEWpT_100To150 = "W1JetsToLNu_LHEWpT_100-150";
const TString wjets_1Jets_LHEWpT_150To250 = "W1JetsToLNu_LHEWpT_150-250";
const TString wjets_1Jets_LHEWpT_250To400 = "W1JetsToLNu_LHEWpT_250-400";
const TString wjets_1Jets_LHEWpT_400Toinf = "W1JetsToLNu_LHEWpT_400-inf";
const TString wjets_2Jets_LHEWpT_100To150 = "W2JetsToLNu_LHEWpT_100-150";
const TString wjets_2Jets_LHEWpT_150To250 = "W2JetsToLNu_LHEWpT_150-250";
const TString wjets_2Jets_LHEWpT_250To400 = "W2JetsToLNu_LHEWpT_250-400";
const TString wjets_2Jets_LHEWpT_400Toinf = "W2JetsToLNu_LHEWpT_400-inf";

const TString wjets_HT70To100    = "";
const TString wjets_HT100To200   = "";
const TString wjets_HT200To400   = "";
const TString wjets_HT400To600   = "";
const TString wjets_HT600To800   = "";
const TString wjets_HT800To1200  = "";
const TString wjets_HT1200To2500 = "";
const TString wjets_HT2500ToInf  = "";

const vector<TString> WJets_Trigger_sample = { wjets, w1jets, w2jets, w3jets, w4jets };
const vector<TString> WJets_sample = WJets_Trigger_sample;
const vector<TString> WJets_closure_sample = { wjets_1Jets_LHEWpT_100To150, wjets_1Jets_LHEWpT_150To250, wjets_1Jets_LHEWpT_250To400, wjets_1Jets_LHEWpT_400Toinf, wjets_2Jets_LHEWpT_100To150, wjets_2Jets_LHEWpT_150To250, wjets_2Jets_LHEWpT_250To400, wjets_2Jets_LHEWpT_400Toinf};

const TString dyjets  = "DYJetsToLL_M-50";
const TString dy1jets = "DY1JetsToLL_M-50";
const TString dy2jets = "DY2JetsToLL_M-50";
const TString dy3jets = "DY3JetsToLL_M-50";
const TString dy4jets = "DY4JetsToLL_M-50";

const vector<TString> DYJets_sample = { dyjets, dy1jets, dy2jets, dy3jets, dy4jets };

const vector<TString>  ZJets_sample = { "ZJetsToNuNu_HT-100To200",
					"ZJetsToNuNu_HT-200To400",
					"ZJetsToNuNu_HT-400To600",
					"ZJetsToNuNu_HT-600To800",
					"ZJetsToNuNu_HT-800To1200",
					"ZJetsToNuNu_HT-1200To2500",
					"ZJetsToNuNu_HT-2500ToInf" };


const vector<TString> TT_ST_sample = { "TTTo2L2Nu",
				       "TTToHadronic",
				       "TTToSemiLeptonic",
				       "ST_t-channel_top_4f_inclusiveDecays",
				       "ST_t-channel_antitop_4f_inclusiveDecays",
				       "ST_tW_top_5f_inclusiveDecays",
				       "ST_tW_antitop_5f_inclusiveDecays" };

const vector<TString> VV_sample = { "WW",
				    "WZ",
				    "ZZ" };


map<TString, double> xsecs = {
{"WJetsToLNu"  , 52760*1.166}, // NNLO (1)
{"W1JetsToLNu" , 8104.*1.166}, // NNLO (2)
{"W2JetsToLNu" , 2796.*1.166}, // NNLO (3)
{"W3JetsToLNu" , 993.5*1.166}, // NNLO (4)
{"W4JetsToLNu" , 544.4*1.166}, // NNLO (5)
{"W1JetsToLNu_LHEWpT_50-150"  , 1.0181*2661},  // NNLO (6)
{"W1JetsToLNu_LHEWpT_100-150" , 1.0181*286.1}, // NNLO (6a)
{"W1JetsToLNu_LHEWpT_150-250" , 1.0181*71.9},  // NNLO (7)
{"W1JetsToLNu_LHEWpT_250-400" , 1.0181*8.05},  // NNLO (8)
{"W1JetsToLNu_LHEWpT_400-inf" , 1.0181*0.885}, // NNLO (9)
{"ZJetsToNuNu_HT-100To200"    , 304.5},    // LO (10)
{"ZJetsToNuNu_HT-200To400"    , 91.82},    // LO (11)
{"ZJetsToNuNu_HT-400To600"    , 13.11},    // LO (12)
{"ZJetsToNuNu_HT-600To800"    , 3.260},    // LO (13)
{"ZJetsToNuNu_HT-800To1200"   , 1.499},    // LO (14)
{"ZJetsToNuNu_HT-1200To2500"  , 0.3430},   // LO (15)
{"ZJetsToNuNu_HT-2500ToInf"   , 0.005146}, // LO (16)
{"ZZ" , 12.19},  // LO (17) -> could be improved
{"WW" , 118.7},  // NNLO QCD (18)
{"WZ" , 27.68},  // LO (19) -> could be improved
{"DYJetsToLL_M-10to50"   , 15820*1.137}, // NNLO (20e)
{"DYJetsToLL_M-50"       , 6077.22},  // NNLO (20)
{"DY1JetsToLL_M-50"      , 875.7*1.137}, // NNLO (20a)
{"DY2JetsToLL_M-50"      , 306.9*1.137}, // NNLO (20b)
{"DY3JetsToLL_M-50"      , 111.9*1.137}, // NNLO (20c)
{"DY4JetsToLL_M-50"      , 43.97*1.137}, // NNLO (20d)
//{"TTTo2L2Nu"        , 88.29},  // NNLO (21)
//{"TTToHadronic"     , 377.96}, // NNLO (22)
//{"TTToSemiLeptonic" , 365.34}, // NNLO (23)
{"ST_t-channel_top_4f_inclusiveDecays"     , 44.33}, // ? (24) -> could be improved
{"ST_t-channel_antitop_4f_inclusiveDecays" , 26.38}, // ? (25) -> could be improved
{"ST_tW_top_5f_inclusiveDecays"            , 35.85}, // ? (26) -> could be improved
{"ST_tW_antitop_5f_inclusiveDecays"        , 35.85}, // ? (27) -> could be improved
{"WToTauNu_M-200"             , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK mass dependent k factor applied later (28)
{"WToTauNu_M-200_jesUp"       , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (29)
{"WToTauNu_M-200_jesDown"     , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (30)
{"WToTauNu_M-200_taues_1prong0pizerosUp"             , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (31)
{"WToTauNu_M-200_taues_1prong0pizerosDown"           , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (32)
{"WToTauNu_M-200_taues_1prongUpTo4pizerosUp"         , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (33)
{"WToTauNu_M-200_taues_1prongUpTo4pizerosDown"       , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (34)
{"WToTauNu_M-200_taues_3prong0pizerosUp"             , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (35)
{"WToTauNu_M-200_taues_3prong0pizerosDown"           , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (36)
{"WToTauNu_M-200_uesUp"       , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (37)
{"WToTauNu_M-200_uesDown"     , 1.0*7.246}, // LO, NNLO-QCD NLO-EWK (38)
{"WToMuNu_M-200"                     , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (39)
{"WToMuNu_M-200_jesUp"               , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (40)
{"WToMuNu_M-200_jesDown"             , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (41)
{"WToMuNu_M-200_muUp"                , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (42)
{"WToMuNu_M-200_muDown"              , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (43)
{"WToMuNu_M-200_uesUp"               , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (44)
{"WToMuNu_M-200_uesDown"             , 1.0*7.273}, // LO, NNLO-QCD NLO-EWK (45)
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

map<TString, int> n_events_per_sample = {
{"WJetsToLNu"  , 74635450},
{"W1JetsToLNu" , 54988117},
{"W2JetsToLNu" , 32368249},
{"W3JetsToLNu" , 19700377},
{"W4JetsToLNu" , 11333705},
{"W1JetsToLNu_LHEWpT_100-150" , 61651108},
{"W1JetsToLNu_LHEWpT_150-250" , 126166905},
{"W1JetsToLNu_LHEWpT_250-400" , 20841145},
{"W1JetsToLNu_LHEWpT_400-inf" , 4465538},
{"W2JetsToLNu_LHEWpT_100-150" , 36719823},
{"W2JetsToLNu_LHEWpT_150-250" , 170437978},
{"W2JetsToLNu_LHEWpT_250-400" , 81630276},
{"W2JetsToLNu_LHEWpT_400-inf" , 30340311},
{"ZJetsToNuNu_HT-100To200"    , 22737266},
{"ZJetsToNuNu_HT-200To400"    , 21675916},
{"ZJetsToNuNu_HT-400To600"    , 9134120},
{"ZJetsToNuNu_HT-600To800"    , 5697594},
{"ZJetsToNuNu_HT-800To1200"   , 2058077},
{"ZJetsToNuNu_HT-1200To2500"  , 338948},
{"ZJetsToNuNu_HT-2500ToInf"   , 6734},
{"ZZ" , 1949768},
{"WW" , 7791498},
{"WZ" , 3928630},
{"DYJetsToLL_M-10to50" , 39521230},
{"DYJetsToLL_M-50"     , 97800939},
{"DY1JetsToLL_M-50"    , 34859434},
{"DY2JetsToLL_M-50"    , 9790490},
{"DY3JetsToLL_M-50"    , 6897933},
{"DY4JetsToLL_M-50"    , 4346952},
{"TTTo2L2Nu"        , 960752},
{"TTToHadronic"     , 41729120},
{"TTToSemiLeptonic" , 41221873},
{"ST_t-channel_top_4f_inclusiveDecays"     , 3675910},
{"ST_t-channel_antitop_4f_inclusiveDecays" , 5982064},
{"ST_tW_top_5f_inclusiveDecays"            , 7977430},
{"ST_tW_antitop_5f_inclusiveDecays"        , 7794186},
{"WToTauNu_M-200"         , 2000000},
{"WToTauNu_M-200_jesUp"   , 2000000},
{"WToTauNu_M-200_jesDown" , 2000000},
{"WToTauNu_M-200_taues_1prong0pizerosUp"       , 2000000},
{"WToTauNu_M-200_taues_1prong0pizerosDown"     , 2000000},
{"WToTauNu_M-200_taues_1prongUpTo4pizerosUp"   , 2000000},
{"WToTauNu_M-200_taues_1prongUpTo4pizerosDown" , 2000000},
{"WToTauNu_M-200_taues_3prong0pizerosUp"       , 2000000},
{"WToTauNu_M-200_taues_3prong0pizerosDown"     , 2000000},
{"WToTauNu_M-200_uesUp"   , 2000000},
{"WToTauNu_M-200_uesDown" , 2000000},
{"WToMuNu_M-200"          , 1953601},
{"WToMuNu_M-200_jesUp"    , 1953601},
{"WToMuNu_M-200_jesDown"  , 1953601},
{"WToMuNu_M-200_muUp"     , 1953601},
{"WToMuNu_M-200_muDown"   , 1953601},
{"WToMuNu_M-200_uesUp"    , 1953601},
{"WToMuNu_M-200_uesDown"  , 1953601},
};


#endif
