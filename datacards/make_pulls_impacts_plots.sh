# Set of commands to make pulls/impact plots

# Get all uncommented iso working points
rm iso.txt
rm *.pdf
while read -r line
do
    [[ $line != iso.* ]] && continue
    [[ $line = //* ]] && continue
    [[ $line = /* ]] && continue
    echo $line | sed -E 's/.*\("(.*)"\).*/\1/' >> iso.txt
done < ../settings.h


while read -r iso
do

text2workspace.py datacard_${iso}_Combined.txt
combineTool.py -M Impacts -d datacard_${iso}_Combined.root -m 125 --doInitialFit --robustFit 1  --redefineSignalPOIs tauId
combineTool.py -M Impacts -d datacard_${iso}_Combined.root -m 125 --robustFit 1 --doFits   --redefineSignalPOIs tauId --parallel 5
combineTool.py -M Impacts -d datacard_${iso}_Combined.root -m 125 -o impacts_${iso}.json --redefineSignalPOIs tauId
plotImpacts.py -i impacts_${iso}.json -o impacts_${iso}

done < iso.txt