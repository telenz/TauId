#!bin/sh

#dir=/nfs/dust/cms/group/higgs-kit/rasp/MC_2017
dir=/nfs/dust/cms/user/rasp/ntuples/MC_2017

for subdir in $dir/*; do
    if [[ ! -d $subdir ]] ; then
	continue
    fi
    
    #echo $subdir 'is a directory'

    samplename=$(basename $subdir)
    echo 'Sample is : ' $samplename

    find $subdir/. -name "*.root" > $samplename 

done

