#!/bin/sh

echo @CONFIGFILE@

cat makeNTuples.sh

NtupleMaker_TauID_all_eras @CONFIGFILE@ @FILELIST@

