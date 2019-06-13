

iso_wps = []

file = open("iso.txt")
for line in file :
    line = line.rstrip('\n') 
    iso_wps.append(line)

#print iso_wps

for iso in iso_wps:
    ofile = open("output_" + iso + ".txt")
    lines = ofile.readlines()
    for line in lines:
        if not line.startswith("Best fit tauId: "):
            continue
        #print line
        aux,line = line.split(": ",1)
        line,aux = line.split("(68% CL)",1)
        central_value , error = line.split("-",1)
        central_value = round(float(central_value),2)
        error_down, error_up = error.split("/+",1)
        error_down = round(float(error_down),2)
        error_up = round(float(error_up),2)
        print '%20s'% iso + str(" : $%.2f^{+%.2f}_{-%.2f}$" % (central_value, error_up, error_down))
        
        # for line in lines:
        #     if not line.startswith("                     r    1.0000e+00"):
        #         continue
        #     line_r = line
        # print line_r
