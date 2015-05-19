RecoBTag-TagVarExtractor
=========================
This package depends on the RecoBTag/PerformanceMeasurements package. First follow the
instructions at https://github.com/cms-btv-pog/RecoBTag-PerformanceMeasurements/tree/7_4_X
and then add the TagVarExtractor package

git clone -b 7_4_X git@github.com:cms-btv-pog/RecoBTag-TagVarExtractor.git RecoBTag/TagVarExtractor

scram b -j8

cd RecoBTag/TagVarExtractor/test/

cmsRun tagvarextractor_cfg.py maxEvents=20000 reportEvery=1000 wantSummary=True

This will produce a ROOT file called JetTaggingVariables.root that can be used for TMVA training.

-------------------------
At FNAL:

To create and submit Condor jobs that will process all files stored in an EOS directory, you can
use the createAndSubmitJobs.py script as in the following example

./createAndSubmitJobs.py -i /eos/uscms/store/user/rsyarif/RadionToHHTo4B_M-1500_TuneZ2star_8TeV-nm-madgraph/Summer12_DR53X-PU_S10_START53_V19-v1_BTagAnalyzerLite_5_3_X_v1.01/ \
-c tagvarextractor_cfg.py -o output_dir -n 60 -p maxEvents=-1,reportEvery=1000,wantSummary=True --fnal

Run

./createAndSubmitJobs.py --help

for more information on the available input parameters and their meaning.
