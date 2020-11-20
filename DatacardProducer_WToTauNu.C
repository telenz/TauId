#include "HttStylesNew.cc"
#include "settings.h"
#include <sstream> 

void DatacardProducer_WToTauNu(TString selection = "inclusive") {
  // selection can be
  //      - "inclusive"     (no single tau trigger selection is applied, needed for tauID measurement),
  //      - "tautrigger"    (for probes passing single tau trigger selection),
  //      - "NOTtautrigger" (for probes failing single tau trigger selection)

  if (!doTauTriggerEffmeasurement) selection = "inclusive";

  loadWorkingPoints();
  SetDir();
  TString Variable;
  if(doTauTriggerEffmeasurement) Variable = "tauPt";
  else Variable = "mttau";

  for(unsigned int idx_iso=0; idx_iso<iso.size(); idx_iso++){

    // ***************
    // Creating datacard inputs
    // *************** 
    TString BaseName;
    if (selection == "tautrigger") BaseName = "datacard_"+Variable+"_"+iso[idx_iso]+"_WToTauNu_passingprobes";
    else if (selection == "NOTtautrigger") BaseName = "datacard_"+Variable+"_"+iso[idx_iso]+"_WToTauNu_failingprobes";
    else BaseName = "datacard_"+Variable+"_"+iso[idx_iso]+"_WToTauNu";

    TString rootFileName;
    if (selection == "tautrigger") rootFileName =  Variable+"_"+iso[idx_iso]+"_WToTauNu_shapes" + tauDecayMode + "_trigger_passingprobes.root";
    else if (selection == "NOTtautrigger") rootFileName =  Variable+"_"+iso[idx_iso]+"_WToTauNu_shapes" + tauDecayMode + "_trigger_failingprobes.root";
    else rootFileName =  Variable+"_"+iso[idx_iso]+"_WToTauNu_shapes" + tauDecayMode + ".root";

    ostringstream str;
    str << "output/"+era+ "/" << BaseName << tauDecayMode << ".txt";
    string nn = str.str();
    const char * p = nn.c_str();

    // Open histogram with all information
    TFile *in = new TFile("output/"+era+ "/"+ rootFileName,"READ");
    TH1D* h_data     = 0;
    TH1D* h_WToTauNu = 0;
    TH1D* h_FakeTaus = 0;
    TH1D* h_TrueTaus = 0;
    if(in){
      in -> GetObject("data_obs",h_data);
      in -> GetObject("W"       ,h_WToTauNu);
      in -> GetObject("FakeTaus",h_FakeTaus);
      in -> GetObject("TrueTaus",h_TrueTaus);
    }

    std::ofstream textFile(p);
    textFile << left;

    textFile << "imax 1   number of channels" << endl;
    textFile << "jmax *   number of backgrounds" << endl;
    textFile << "kmax *   number of nuisance parameters" << endl;
    textFile << "-----------------" << endl;
    textFile << "observation " << h_data->Integral() << endl;
    textFile << "-----------------" << endl;
    textFile << "shapes * * " <<rootFileName << "  $PROCESS    $PROCESS_$SYSTEMATIC " << endl;
    textFile << "-----------------" << endl;
    if (selection == "tautrigger") textFile << setw(45) << "bin"     << setw(15) << "WTauNu_pass" << setw(15) << "WTauNu_pass"   << setw(15) << "WTauNu_pass"   << endl;
    else if (selection == "NOTtautrigger") textFile << setw(45) << "bin"     << setw(15) << "WTauNu_fail" << setw(15) << "WTauNu_fail"   << setw(15) << "WTauNu_fail"   << endl;
    else textFile << setw(45) << "bin"     << setw(15) << "WTauNu" << setw(15) << "WTauNu"   << setw(15) << "WTauNu"   << endl;
    textFile << setw(45) << "process" << setw(15) << "W"      << setw(15) << "FakeTaus" << setw(15) << "TrueTaus" << endl;
    textFile << setw(45) << "process" << setw(15) << "0"      << setw(15) << "1"        << setw(15) << "2"        << endl;
    textFile << setw(45) << "rate"    << setw(15) << h_WToTauNu->Integral() << setw(15) << h_FakeTaus->Integral() << setw(15) << h_TrueTaus->Integral() << endl;
    textFile << "-----------------" << endl;
    textFile << setw(30) << "taues_1prong0pizeros"     << setw(15) << "shape" << setw(15) << "1.00" << setw(15) << "-" << setw(15) << "-" << endl;
    textFile << setw(30) << "taues_1prongUpTo4pizeros" << setw(15) << "shape" << setw(15) << "1.00" << setw(15) << "-" << setw(15) << "-" << endl;
    textFile << setw(30) << "taues_3prong0pizeros"     << setw(15) << "shape" << setw(15) << "1.00" << setw(15) << "-" << setw(15) << "-" << endl;
    textFile << setw(30) << "jes"                      << setw(15) << "shape" << setw(15) << "1.00" << setw(15) << "-" << setw(15) << "-" << endl;
    textFile << setw(30) << "ues"                      << setw(15) << "shape" << setw(15) << "1.00" << setw(15) << "-" << setw(15) << "-" << endl;
    for (int iB=3; iB<=h_data->GetNbinsX(); ++iB) {
      textFile << setw(30) << Form("Bin%i_WToTauNu",iB) << setw(15) << "shape" << setw(15) << "1.00" << setw(15) << "-"    << setw(15) << "-"    << endl;
      textFile << setw(30) << Form("Bin%i_FakeTaus",iB) << setw(15) << "shape" << setw(15) << "-"    << setw(15) << "1.00" << setw(15) << "-"    << endl;
      textFile << setw(30) << Form("Bin%i_TrueTaus",iB) << setw(15) << "shape" << setw(15) << "-"    << setw(15) << "-"    << setw(15) << "1.00" << endl;
    }


    // Get number of bins of fake factor template
    int nBinX = 0;
    int nBinY = 0;
    TIter next(in->GetListOfKeys());
    TKey *key = 0;
    while ((key = (TKey*)next()))
      {
	TClass *c = gROOT->GetClass(key->GetClassName());
	if (!c->InheritsFrom("TH1")) continue;
	TH1D *h = (TH1D*) key->ReadObj();
	h->SetDirectory(0);
	TString hName = h->GetName();
	if(!hName.Contains("FakeTaus_FR")) continue;
	TString sbinX = hName(11,1);
	TString sbinY = hName(12,1);
	int binX = sbinX.Atoi();
	int binY = sbinY.Atoi();
	if(binX > nBinX) nBinX = binX;
	if(binY > nBinY) nBinY = binY;
	delete h;
      }
    delete key;

    for (int i=1; i<=nBinX; ++i) {
      for (int j=1; j<=nBinY; ++j) {
	textFile << setw(30) << Form("FR%i%i",i,j) << setw(15) << "shape" << setw(15) << "-" << setw(15) << "1.00" << setw(15) << "-" << endl;
      }
    }
    textFile << setw(30) << "BkgdNorm" << setw(15) << "lnN" << setw(15) << "-"      << setw(15) << "-"      << setw(15) << "1.30"   << endl;
    textFile << setw(30) << "lumi"     << setw(15) << "lnN" << setw(15) << lumi_unc << setw(15) << "-"      << setw(15) << lumi_unc << endl;
    if (!doTauTriggerEffmeasurement) textFile << "tauId  rateParam WTauNu W  1  [0.0,2.0]" << endl;
  
    // *******************
    // end creating datacard inputs
    // *******************
  }
}
