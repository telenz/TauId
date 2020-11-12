import ROOT as rt

def plot_comparison(hist_1, hist_2, name, titlex, titley, leg1, leg2) :
    
    
    rt.gStyle.SetPadTopMargin(0.05)
    rt.gStyle.SetPadBottomMargin(0.15)
    rt.gStyle.SetPadLeftMargin(0.15)
    rt.gStyle.SetPadRightMargin(0.07)
    
    c1 = rt.TCanvas("c1","c1",700,700)
    
    hist_1.SetLineColor(rt.kOrange+1)
    hist_2.SetLineColor(rt.kBlack)
    
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
    hist_1.Draw("e1")
    hist_2.Draw("e1same")

    leg=rt.TLegend(0.65,0.2,0.9,0.35)
    leg.AddEntry(hist_1, leg1, "lp")
    leg.AddEntry(hist_2, leg2, "lp")
    leg.Draw("same")
    
    rt.gPad.SaveAs(name+".png")


f1 = rt.TFile("../output/SingleTauTriggerEff_MediumDeepTau2017v2p1_nominal_postfit.root","READ")
f2 = rt.TFile("../output/SingleTauTriggerEff_MediumDeepTau2017v2p1_prefit.root","READ")

h_postfit = f1.Get("SF")
h_prefit = f2.Get("SF")

plot_comparison(h_postfit, h_prefit,"SF_preandpostfit","#tau p_{T} [GeV]","SF","postfit","prefit")

h_MCpostfit = f1.Get("MC")
h_MCprefit = f2.Get("MC")

plot_comparison(h_MCpostfit, h_MCprefit,"MCEff_preandpostfit","#tau p_{T} [GeV]","Eff","postfit","prefit")  

h_Datapostfit = f1.Get("Data")
h_Dataprefit = f2.Get("Data")

plot_comparison(h_Datapostfit, h_Dataprefit,"DataEff_preandpostfit","#tau p_{T} [GeV]","Eff","postfit","prefit")    
    
f3 = rt.TFile("../output/SingleTauTriggerEff_MediumDeepTau2017v2p1_nominal_postfit.root","READ")
f4 = rt.TFile("../output/SingleTauTriggerEff_MediumDeepTau2017v2p1_postfitwithoutjetveto.root","READ")

h_nominal = f3.Get("SF")
h_wojetveto = f4.Get("SF")

plot_comparison(h_nominal, h_wojetveto,"SF_comparisonjetveto","#tau p_{T} [GeV]","SF","nominal","without jet veto")

h_MCnominal = f3.Get("MC")
h_MCwojetveto = f4.Get("MC")

plot_comparison(h_MCnominal, h_MCwojetveto,"MCEff_comparisonjetveto","#tau p_{T} [GeV]","Eff","nominal","without jet veto")

h_Datanominal = f3.Get("Data")
h_Datawojetveto = f4.Get("Data")

plot_comparison(h_Datanominal, h_Datawojetveto,"DataEff_comparisonjetveto","#tau p_{T} [GeV]","Eff","nominal","without jet veto")






    