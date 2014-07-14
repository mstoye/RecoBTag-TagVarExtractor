import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing('python')

options.register('outFilename', 'JetTaggingVariables.root',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Output file name"
)
options.register('reportEvery', 1000,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.int,
    "Report every N events (default is N=1000)"
)
options.register('wantSummary', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Print out trigger and timing summary"
)
options.register('jetPtMin', 100.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum jet Pt"
)
options.register('jetPtMax', 170.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum jet Pt"
)
options.register('jetAbsEtaMin', 0.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum jet |eta|"
)
options.register('jetAbsEtaMax', 1.2,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum jet |eta|"
)

## 'maxEvents' is already registered by the Framework, changing default value
options.setDefault('maxEvents', 2000)

options.parseArguments()

#print options

process = cms.Process("TagVar")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cout = cms.untracked.PSet(
    threshold = cms.untracked.string('INFO')
)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) ) # Keep as such

process.source = cms.Source("EmptySource")

## Options and Output Report
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(options.wantSummary) )

## Input files
inputFiles = [
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_1_1_I7w.root',
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_2_1_esB.root',
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_3_1_zUJ.root',
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_4_1_7KC.root',
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_5_1_xMY.root',
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_6_1_klp.root',
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_7_1_qzV.root',
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_8_1_IcJ.root',
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_9_1_EG4.root',
    '/cms/ferencek/store/skaplan/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3/AODSIM/outfile_mc_10_1_H5s.root'
]

## Output file
process.TFileService = cms.Service("TFileService",
    fileName = cms.string(options.outFilename)
)

process.tagvar = cms.EDAnalyzer('TagVarExtractor',
    MaxEvents    = cms.int32(options.maxEvents),
    ReportEvery  = cms.int32(options.reportEvery),
    InputTTree   = cms.string('btagana/ttree'),
    InputFiles   = cms.vstring(inputFiles),
    JetPtMin     = cms.double(options.jetPtMin),
    JetPtMax     = cms.double(options.jetPtMax),
    JetAbsEtaMin = cms.double(options.jetAbsEtaMin),
    JetAbsEtaMax = cms.double(options.jetAbsEtaMax)
)

process.p = cms.Path(process.tagvar)
