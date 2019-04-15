#ifndef SETTINGS_ERA_SPECIFIC_2016_H
#define SETTINGS_ERA_SPECIFIC_2016_H

TString dir = "NTuples/2016//";

double luminosity = 35890; // lumi used for 2016 analysis

TString triggerfile_output_name = "trigger_eff_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_2016-legacy_v1.root";

const vector<TString> SingleMuon_sample = { "SingleMuon_Run2016B",
					    "SingleMuon_Run2016C",
					    "SingleMuon_Run2016D",
					    "SingleMuon_Run2016E",
					    "SingleMuon_Run2016F",
					    "SingleMuon_Run2016G",
					    "SingleMuon_Run2016H" };

const vector<TString> JetHT_sample = { "JetHT_Run2016B",
				       "JetHT_Run2016C",
				       "JetHT_Run2016D",
				       "JetHT_Run2016E",
				       "JetHT_Run2016F",
				       "JetHT_Run2016G",
				       "JetHT_Run2016H" };

const vector<TString> MET_sample = { "MET_Run2016B",
				     "MET_Run2016C",
				     "MET_Run2016D",
				     "MET_Run2016E",
				     "MET_Run2016F",
				     "MET_Run2016G",
				     "MET_Run2016H" };

const TString wjets  = "WJetsToLNu";
const TString w1jets = "W1JetsToLNu";
const TString w2jets = "W2JetsToLNu";
const TString w3jets = "W3JetsToLNu";
const TString w4jets = "W4JetsToLNu";
const TString wjets_HT70To100    = "WJetsToLNu_HT-70To100";
const TString wjets_HT100To200   = "WJetsToLNu_HT-100To200";
const TString wjets_HT200To400   = "WJetsToLNu_HT-200To400";
const TString wjets_HT400To600   = "WJetsToLNu_HT-400To600";
const TString wjets_HT600To800   = "WJetsToLNu_HT-600To800";
const TString wjets_HT800To1200  = "WJetsToLNu_HT-800To1200";
const TString wjets_HT1200To2500 = "WJetsToLNu_HT-1200To2500";
const TString wjets_HT2500ToInf  = "WJetsToLNu_HT-2500ToInf";

const vector<TString> WJets_Trigger_sample = { wjets, w1jets, w2jets, w3jets, w4jets };
const vector<TString> WJets_sample = { wjets, w1jets, w2jets, w3jets, w4jets, wjets_HT70To100, wjets_HT100To200, wjets_HT200To400, wjets_HT400To600, wjets_HT600To800, wjets_HT800To1200, wjets_HT1200To2500, wjets_HT2500ToInf };

const TString dyjets  = "DYJetsToLL_M-50";
const TString dy1jets = "DY1JetsToLL_M-50";
const TString dy2jets = "DY2JetsToLL_M-50";
const TString dy3jets = "DY3JetsToLL_M-50";
const TString dy4jets = "DY4JetsToLL_M-50";

const vector<TString> DYJets_sample = { dyjets, dy1jets, dy2jets, dy3jets, dy4jets };

const vector<TString> ZJets_sample = { "ZJetsToNuNu_HT-100To200",
				       "ZJetsToNuNu_HT-200To400",
				       "ZJetsToNuNu_HT-400To600",
				       "ZJetsToNuNu_HT-600To800",
				       "ZJetsToNuNu_HT-800To1200",
				       "ZJetsToNuNu_HT-1200To2500",
				       "ZJetsToNuNu_HT-2500ToInf" };

const vector<TString> TT_ST_sample = { "TT",
				       "ST_t-channel_top_4f_inclusiveDecays",
				       "ST_t-channel_antitop_4f_inclusiveDecays",
				       "ST_tW_antitop_5f_inclusiveDecays",
				       "ST_tW_top_5f_inclusiveDecays" };

const vector<TString> VV_sample = { "WW",
				    "WZ",
				    "ZZ" };

map<TString, double> xsecs = {

{"WJetsToLNu"                   , 61526.7}, // NNLO (1)
{"W1JetsToLNu"                  , 9625.0*1.224}, // NNLO (2)
{"W2JetsToLNu"                  , 3161.0*1.224}, // NNLO (3)
{"W3JetsToLNu"                  , 954.8*1.224},  // NNLO (4)
{"W4JetsToLNu"                  , 494.6*1.224},  // NNLO (5)
{"WJetsToLNu_HT-70To100"        , 1353.0*1.224}, // NNLO (6)
{"WJetsToLNu_HT-100To200"       , 1346.0*1.224}, // NNLO (7)
{"WJetsToLNu_HT-200To400"       , 360.1*1.224},  // NNLO (8)
{"WJetsToLNu_HT-400To600"       , 48.8*1.224},   // NNLO (9)
{"WJetsToLNu_HT-600To800"       , 12.07*1.224},  // NNLO (10)
{"WJetsToLNu_HT-800To1200"      , 5.497*1.224},  // NNLO (11)
{"WJetsToLNu_HT-1200To2500"     , 1.329*1.224},  // NNLO (12)
{"WJetsToLNu_HT-2500ToInf"      , 0.03209*1.224}, // NNLO (13)
{"ZJetsToNuNu_HT-100To200"      , 280.05},   // LO (14)
{"ZJetsToNuNu_HT-200To400"      , 77.55},    // LO (15)
{"ZJetsToNuNu_HT-400To600"      , 10.752},   // LO (16)
{"ZJetsToNuNu_HT-600To800"      , 2.559},    // LO (17)
{"ZJetsToNuNu_HT-800To1200"     , 1.1802},   // LO (18)
{"ZJetsToNuNu_HT-1200To2500"    , 0.28629},  // LO (19)
{"ZJetsToNuNu_HT-2500ToInf"     , 0.006912}, // LO (20)
{"DYJetsToLL_M-50"              , 6225.42},  // NNLO (21)
{"DY1JetsToLL_M-50"             , 1012.0*1.254}, // NNLO (22)
{"DY2JetsToLL_M-50"             , 334.7*1.254},  // NNLO (23)
{"DY3JetsToLL_M-50"             , 102.3*1.254},  // NNLO (24)
{"DY4JetsToLL_M-50"             , 54.52*1.254},  // NNLO (25)
{"ZZ"                           , 10.16},  // LO (26)
{"WW"                           , 64.3},   // LO (27)
{"WZ"                           , 23.43},  // LO (28)
{"TT"                           , 831.76}, // NNLO (29)
{"ST_t-channel_top_4f_inclusiveDecays"     , 35.85}, // approx. NNLO (30)
{"ST_t-channel_antitop_4f_inclusiveDecays" , 35.85}, // approx. NNLO (31)
{"ST_tW_top_5f_inclusiveDecays"            , 35.85}, // approx. NNLO (32)
{"ST_tW_antitop_5f_inclusiveDecays"        , 35.85}, // approx. NNLO (33)
{"WToTauNu_M-200"               , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK mass dependent k factor applied later (34)
{"WToTauNu_M-200_jesUp"         , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (35)
{"WToTauNu_M-200_jesDown"       , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (36)
{"WToTauNu_M-200_uesUp"         , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (37)
{"WToTauNu_M-200_uesDown"       , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (38)
{"WToTauNu_M-200_taues_1prong0pizerosUp"       , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (39)
{"WToTauNu_M-200_taues_1prong0pizerosDown"     , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (40)
{"WToTauNu_M-200_taues_1prongUpTo4pizerosUp"   , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (41)
{"WToTauNu_M-200_taues_1prongUpTo4pizerosDown" , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (42)
{"WToTauNu_M-200_taues_3prong0pizerosUp"       , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (43)
{"WToTauNu_M-200_taues_3prong0pizerosDown"     , 1.0*6.206}, // LO, NNLO-QCD NLO-EWK (44)
{"WToMuNu_M-200"                , 1.0*6.238}, // LO, NNLO-QCD NLO-EWK (45)
{"WToMuNu_M-200_jesUp"          , 1.0*6.238}, // LO, NNLO-QCD NLO-EWK (46)
{"WToMuNu_M-200_jesDown"        , 1.0*6.238}, // LO, NNLO-QCD NLO-EWK (47)
{"WToMuNu_M-200_muUp"           , 1.0*6.238}, // LO, NNLO-QCD NLO-EWK (48)
{"WToMuNu_M-200_muDown"         , 1.0*6.238}, // LO, NNLO-QCD NLO-EWK (49)
{"WToMuNu_M-200_uesUp"          , 1.0*6.238}, // LO, NNLO-QCD NLO-EWK (50)
{"WToMuNu_M-200_uesDown"        , 1.0*6.238}}; // LO, NNLO-QCD NLO-EWK (51)

// Sources of xsecs:
// (1) NNLO: https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeV; LO: https://cms-gen-dev.cern.ch/xsdb (DAS=WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8) -> k-factor=61526.7/50260.0 = 1.224
// (2-13) LO: https://cms-gen-dev.cern.ch/xsdb (e.g. DAS=W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8) for W3Jets from old measurement, k-factor see (1)
// (14-20) LO: https://cms-gen-dev.cern.ch/xsdb (e.g. DAS=ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph)
// (21) NNLO: https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeV; LO: https://cms-gen-dev.cern.ch/xsdb (DAS=DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM) -> k-factor = 6225.42/4963.0 = 1.254
// (22-25) LO: https://cms-gen-dev.cern.ch/xsdb (e.g. DAS=DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM)
// (26-28) LO: https://cms-gen-dev.cern.ch/xsdb (e.g. DAS=WZ_TuneCUETP8M1_13TeV-pythia8)
// (29) https://twiki.cern.ch/twiki/bin/view/LHCPhysics/TtbarNNLO#Top_quark_pair_cross_sections_at
// (30-33) https://twiki.cern.ch/twiki/bin/view/CMS/HiggsToTauTauWorking2017#MC_and_data_samples 
// (34-44) LO: https://cms-gen-dev.cern.ch/xsdb (DAS=WToTauNu_M-200_TuneCUETP8M1_13TeV-pythia8-tauola) - mass-dependent k-factors applied later
// (45-51) LO: https://cms-gen-dev.cern.ch/xsdb (DAS=WToMuNu_M-200_TuneCUETP8M1_13TeV-pythia8) - mass-dependent k-factors applied later


#endif
