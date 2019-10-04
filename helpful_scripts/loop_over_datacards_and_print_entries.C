#include "HttStylesNew.cc"
#include "settings.h"
#include <sstream> 

void loop_over_datacards_and_print_entries() {


  TFile *in = new TFile("output/mtmuon_WToMuNu_shapes.root","READ");
  //TFile *in = new TFile("output/mttau_TightMva2017v2_WToTauNu_shapes.root","READ");
  TIter next(in->GetListOfKeys());
  TKey *key = 0;
  while ((key = (TKey*)next()))
    {
      TClass *c = gROOT->GetClass(key->GetClassName());
      if (!c->InheritsFrom("TH1")) continue;
      TH1D *h = (TH1D*) key->ReadObj();
      h->SetDirectory(0);
      TString hName = h->GetName();
      
      for(int i=1; i<=h->GetNbinsX(); i++){
	cout<<hName<<" bin " << i << " = "<<h->GetBinContent(i)<<endl;
      }
      cout<<endl;
      delete h;
    }
  delete key;
  
}
