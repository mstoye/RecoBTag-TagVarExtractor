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
options.register('useExternalInput', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Use external input"
)
options.register('externalInput', '',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Path of an external list of input files"
)
options.register('dumpPythonCfg', '',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Name of the rewritten cfg file"
)
options.register('inputTDir', 'btaganaSubJets',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "TDirectory containing the input jet TTree"
)
options.register('inputEventTDir', 'btagana',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "TDirectory containing the input event TTree"
)
options.register('varPrefix', 'FatJetInfo',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Variable name prefix such as 'JetInfo', 'FatJetInfo' or an empty string"
)
options.register('varPrefixSubjets', 'JetInfo',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Variable name prefix for subjets"
)
options.register('jetPtMin', 300.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum jet Pt"
)
options.register('jetPtMax', 500.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum jet Pt"
)
options.register('jetAbsEtaMin', 0.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum jet |eta|"
)
options.register('jetAbsEtaMax', 1.5,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum jet |eta|"
)
options.register('doBosonMatching', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Do boson matching"
)

## 'maxEvents' is already registered by the Framework, changing default value
options.setDefault('maxEvents', 2000)

options.parseArguments()

#print options

process = cms.Process("TagVars")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cout = cms.untracked.PSet(
    threshold = cms.untracked.string('INFO')
)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) ) # Keep as such

process.source = cms.Source("EmptySource")

## Options and Output Report
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(options.wantSummary) )

## Input files
inputFiles = []
## If using external input files
if options.useExternalInput:
    inputFiles = open(options.externalInput,"r").read().splitlines()
else:
    import QCDFiles_cff
    inputFiles = QCDFiles_cff.inputFiles

## Output file
process.TFileService = cms.Service("TFileService",
    fileName = cms.string(options.outFilename)
)

process.tagVars = cms.EDAnalyzer('TagVarExtractor',
    MaxEvents           = cms.int32(options.maxEvents),
    ReportEvery         = cms.int32(options.reportEvery),
    InputTTree          = cms.string(options.inputTDir+'/ttree'),
    InputEventTTree     = cms.string(options.inputEventTDir+'/ttree'),
    VarPrefix           = cms.string(options.varPrefix),
    VarPrefixSubjets    = cms.string(options.varPrefixSubjets),
    InputFiles          = cms.vstring(inputFiles),
    JetPtMin            = cms.double(options.jetPtMin),
    JetPtMax            = cms.double(options.jetPtMax),
    JetAbsEtaMin        = cms.double(options.jetAbsEtaMin),
    JetAbsEtaMax        = cms.double(options.jetAbsEtaMax),
    DoBosonMatching     = cms.bool(options.doBosonMatching),
    BosonMatchingRadius = cms.double(0.5),
    BosonPdgId          = cms.int32(25)
)

process.p = cms.Path(process.tagVars)

## Rewrite the cfg file
if options.dumpPythonCfg != '':
    open(options.dumpPythonCfg,'w').write(process.dumpPython())
