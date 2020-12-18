import ROOT as rt

def plot_comparison(hist_1, hist_2, hist_3, name, titlex, titley, leg1, leg2, leg3, threehists) :
    
    
    rt.gStyle.SetPadTopMargin(0.05)
    rt.gStyle.SetPadBottomMargin(0.15)
    rt.gStyle.SetPadLeftMargin(0.15)
    rt.gStyle.SetPadRightMargin(0.07)
    
    c1 = rt.TCanvas("c1","c1",700,700)
    
    hist_1.SetLineColor(rt.kOrange+1)
    hist_2.SetLineColor(rt.kBlack)
    
    if threehists:
        hist_3.SetLineColor(rt.kGreen+1)
        hist_3.SetMarkerColor(rt.kGreen+1)
    else:
        hist_3.SetLineColor(rt.kOrange+1)
        hist_3.SetMarkerColor(rt.kOrange+1)
        
    hist_1.GetXaxis().SetTitle(titlex)
    hist_1.GetYaxis().SetTitle(titley)
    hist_1.GetYaxis().SetTitleOffset(1.18)
    if "SF" in name :
        hist_1.GetYaxis().SetRangeUser(0.,2.0)
    else:
        hist_1.GetYaxis().SetRangeUser(0.,1.0)
    
    c1.SetLogx()
    hist_1.SetMarkerSize(0.8)
    hist_1.SetMarkerColor(rt.kOrange+1)
    hist_2.SetMarkerColor(rt.kBlack)
    hist_2.SetMarkerSize(0.8)
    hist_3.SetMarkerSize(0.8)
    hist_1.Draw("e1")
    hist_2.Draw("e1same")
    hist_3.Draw("e1same")
    

    leg=rt.TLegend(0.65,0.2,0.9,0.35)
    leg.AddEntry(hist_1, leg1, "lp")
    leg.AddEntry(hist_2, leg2, "lp")
    if threehists:
        leg.AddEntry(hist_3, leg3, "lp")
    leg.Draw("same")
    
    rt.gPad.SaveAs(name+".png")


#f1 = rt.TFile("../output/SingleTauTriggerEff_MediumDeepTau2017v2p1_nominal_postfit.root","READ")
#f2 = rt.TFile("../output/SingleTauTriggerEff_MediumDeepTau2017v2p1_prefit.root","READ")

#h_postfit = f1.Get("SF")
#h_prefit = f2.Get("SF")

#plot_comparison(h_postfit, h_prefit,"SF_preandpostfit","#tau p_{T} [GeV]","SF","postfit","prefit")

#h_MCpostfit = f1.Get("MC")
#h_MCprefit = f2.Get("MC")

#plot_comparison(h_MCpostfit, h_MCprefit,"MCEff_preandpostfit","#tau p_{T} [GeV]","Eff","postfit","prefit")  

#h_Datapostfit = f1.Get("Data")
#h_Dataprefit = f2.Get("Data")

#plot_comparison(h_Datapostfit, h_Dataprefit,"DataEff_preandpostfit","#tau p_{T} [GeV]","Eff","postfit","prefit")    
    
#f3 = rt.TFile("../output/SingleTauTriggerEff_MediumDeepTau2017v2p1_nominal_postfit.root","READ")
#f4 = rt.TFile("../output/SingleTauTriggerEff_MediumDeepTau2017v2p1_postfitwithoutjetveto.root","READ")

#h_nominal = f3.Get("SF")
#h_wojetveto = f4.Get("SF")

#plot_comparison(h_nominal, h_wojetveto,"SF_comparisonjetveto","#tau p_{T} [GeV]","SF","nominal","without jet veto")

#h_MCnominal = f3.Get("MC")
#h_MCwojetveto = f4.Get("MC")

#plot_comparison(h_MCnominal, h_MCwojetveto,"MCEff_comparisonjetveto","#tau p_{T} [GeV]","Eff","nominal","without jet veto")

#h_Datanominal = f3.Get("Data")
#h_Datawojetveto = f4.Get("Data")

#plot_comparison(h_Datanominal, h_Datawojetveto,"DataEff_comparisonjetveto","#tau p_{T} [GeV]","Eff","nominal","without jet veto")

#f1 = rt.TFile("../output/2018/SingleTauTriggerEff_MediumDeepTau2017v2p1.root","READ")
#f2 = rt.TFile("../output/2018_withounonclosurecorrection/SingleTauTriggerEff_MediumDeepTau2017v2p1.root","READ")

#h_MCnominal = f1.Get("MC")
#h_MCwoclosurecorr = f2.Get("MC")

#plot_comparison(h_MCnominal, h_MCwoclosurecorr, h_MCnominal, "MCEff_comparisonclosurecorr","#tau p_{T} [GeV]","Eff","nominal","no closure corr", "", False)

#h_Datanominal = f1.Get("Data")
#h_Datawoclosurecorr = f2.Get("Data")

#plot_comparison(h_Datanominal, h_Datawoclosurecorr, h_Datanominal, "DataEff_comparisonclosurecorr","#tau p_{T} [GeV]","Eff","nominal","no closure corr",  "", False)

#h_SFnominal = f1.Get("SF")
#h_SFwoclosurecorr = f2.Get("SF")

#plot_comparison(h_SFnominal, h_SFwoclosurecorr, h_SFnominal, "SFEff_comparisonclosurecorr","#tau p_{T} [GeV]","SF","nominal","no closure corr",  "", False)

#f3 = rt.TFile("../output/2018/SingleTauTriggerEff_MediumDeepTau2017v2p1.root","READ")
#f4 = rt.TFile("../output/2018/SingleTauTriggerEff_TightDeepTau2017v2p1.root","READ")
#f5 = rt.TFile("../output/2018/SingleTauTriggerEff_VTightDeepTau2017v2p1.root","READ")

#h_DataMedium2018 = f3.Get("Data")
#h_DataTight2018 = f4.Get("Data")
#h_DataVTight2018 = f5.Get("Data")

#plot_comparison(h_DataMedium2018, h_DataTight2018, h_DataVTight2018, "DataEff_comparisonWPs2018","#tau p_{T} [GeV]","Eff","Medium","Tight",  "VTight", True)

#h_MCMedium2018 = f3.Get("MC")
#h_MCTight2018 = f4.Get("MC")
#h_MCVTight2018 = f5.Get("MC")

#plot_comparison(h_MCMedium2018, h_MCTight2018, h_MCVTight2018, "MCEff_comparisonWPs2018","#tau p_{T} [GeV]","Eff","Medium","Tight",  "VTight", True)

#h_SFMedium2018 = f3.Get("SF")
#h_SFTight2018 = f4.Get("SF")
#h_SFVTight2018 = f5.Get("SF")

#plot_comparison(h_SFMedium2018, h_SFTight2018, h_SFVTight2018, "SFEff_comparisonWPs2018","#tau p_{T} [GeV]","SF","Medium","Tight",  "VTight", True)

#f6 = rt.TFile("../output/2017/SingleTauTriggerEff_MediumDeepTau2017v2p1.root","READ")
#f7 = rt.TFile("../output/2017/SingleTauTriggerEff_TightDeepTau2017v2p1.root","READ")
#f8 = rt.TFile("../output/2017/SingleTauTriggerEff_VTightDeepTau2017v2p1.root","READ")

#h_DataMedium2017 = f6.Get("Data")
#h_DataTight2017 = f7.Get("Data")
#h_DataVTight2017 = f8.Get("Data")

#plot_comparison(h_DataMedium2017, h_DataTight2017, h_DataVTight2017, "DataEff_comparisonWPs2017","#tau p_{T} [GeV]","Eff","Medium","Tight",  "VTight", True)

#h_MCMedium2017 = f6.Get("MC")
#h_MCTight2017 = f7.Get("MC")
#h_MCVTight2017 = f8.Get("MC")

#plot_comparison(h_MCMedium2017, h_MCTight2017, h_MCVTight2017, "MCEff_comparisonWPs2017","#tau p_{T} [GeV]","Eff","Medium","Tight",  "VTight", True)

#h_SFMedium2017 = f6.Get("SF")
#h_SFTight2017 = f7.Get("SF")
#h_SFVTight2017 = f8.Get("SF")

#plot_comparison(h_SFMedium2017, h_SFTight2017, h_SFVTight2017, "SFEff_comparisonWPs2017","#tau p_{T} [GeV]","SF","Medium","Tight",  "VTight", True)

#f9 = rt.TFile("../output/2016/SingleTauTriggerEff_MediumDeepTau2017v2p1.root","READ")
#f10 = rt.TFile("../output/2016/SingleTauTriggerEff_TightDeepTau2017v2p1.root","READ")
#f11 = rt.TFile("../output/2016/SingleTauTriggerEff_VTightDeepTau2017v2p1.root","READ")

#h_DataMedium2016 = f9.Get("Data")
#h_DataTight2016 = f10.Get("Data")
#h_DataVTight2016 = f11.Get("Data")

#plot_comparison(h_DataMedium2016, h_DataTight2016, h_DataVTight2016, "DataEff_comparisonWPs2016","#tau p_{T} [GeV]","Eff","Medium","Tight",  "VTight", True)

#h_MCMedium2016 = f9.Get("MC")
#h_MCTight2016 = f10.Get("MC")
#h_MCVTight2016 = f11.Get("MC")

#plot_comparison(h_MCMedium2016, h_MCTight2016, h_MCVTight2016, "MCEff_comparisonWPs2016","#tau p_{T} [GeV]","Eff","Medium","Tight",  "VTight", True)

#h_SFMedium2016 = f9.Get("SF")
#h_SFTight2016 = f10.Get("SF")
#h_SFVTight2016 = f11.Get("SF")

#plot_comparison(h_SFMedium2016, h_SFTight2016, h_SFVTight2016, "SFEff_comparisonWPs2016","#tau p_{T} [GeV]","SF","Medium","Tight",  "VTight", True)

#plot_comparison(h_SFMedium2016, h_SFMedium2017, h_SFMedium2018, "SFEff_comparsionyears","#tau p_{T} [GeV]","SF","2016","2017","2018", True)
#plot_comparison(h_MCMedium2016, h_MCMedium2017, h_MCMedium2018, "MCEff_comparsionyears","#tau p_{T} [GeV]","Eff","2016","2017","2018", True)
#plot_comparison(h_DataMedium2016, h_DataMedium2017, h_DataMedium2018, "DataEff_comparsionyears","#tau p_{T} [GeV]","Eff","2016","2017","2018", True)


f1 = rt.TFile("../output/2018/SingleTauTriggerEff_MediumDeepTau2017v2p1_2018.root","READ")
f2 = rt.TFile("../output/2018/SingleTauTriggerEff_MediumDeepTau2017v2p1_2018_prefit.root","READ")

h_postfit_2018 = f1.Get("SF")
h_prefit_2018 = f2.Get("SF")

plot_comparison(h_postfit_2018, h_prefit_2018, h_postfit_2018, "SF_comp_prepostfit_2018","#tau p_{T} [GeV]","SF","postfit","prefit",  "", False)

f3 = rt.TFile("../output/2017/SingleTauTriggerEff_MediumDeepTau2017v2p1_2017.root","READ")
f4 = rt.TFile("../output/2017/SingleTauTriggerEff_MediumDeepTau2017v2p1_2017_prefit.root","READ")

h_postfit_2017 = f3.Get("SF")
h_prefit_2017 = f4.Get("SF")

plot_comparison(h_postfit_2017, h_prefit_2017, h_postfit_2017, "SF_comp_prepostfit_2017","#tau p_{T} [GeV]","SF","postfit","prefit",  "", False)

f5 = rt.TFile("../output/2016/SingleTauTriggerEff_MediumDeepTau2017v2p1_2016.root","READ")
f6 = rt.TFile("../output/2016/SingleTauTriggerEff_MediumDeepTau2017v2p1_2016_prefit.root","READ")

h_postfit_2016 = f5.Get("SF")
h_prefit_2016 = f6.Get("SF")

plot_comparison(h_postfit_2016, h_prefit_2016, h_postfit_2016, "SF_comp_prepostfit_2016","#tau p_{T} [GeV]","SF","postfit","prefit",  "", False)





    