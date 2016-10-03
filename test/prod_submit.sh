#!/bin/bash
export SCRAM_ARCH=slc6_amd64_gcc530
cd  $CMSSW_BASE/src
eval `scram runtime -sh`
cd MYPATH
cp ../XXX_cff .
cmsRun XXX.py