#!/bin/bash

for dir in $(find -maxdepth 1 -type d -name "*_files")
do
    filename=${dir:2:${#dir}-8}
    echo $filename
    if [ "$filename" == "SingleMuon_Run2017" ]; then
        for i in {0..9}
        do
            hadd -f ${filename}_${i}.root ${filename}_files/*${i}.root
        done
    else
        hadd -f ${filename}.root ${filename}_files/*.root
    fi
    checkRoot ${filename}.root
    exit=$?
    if [[ $exit -ne 0 ]]; then
        echo "File ${filename}.root is corrupted. Quitting..."
        exit 1
    fi
done

