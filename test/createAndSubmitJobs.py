#!/usr/bin/env python

import os, sys, optparse, subprocess, string, re, shutil


def make_filenamelist(inputDir):
    if not os.path.isdir(inputDir):
        print ('%s is not a directory'%(inputDir))
        sys.exit(1)

    filenamelist = []
    for filename in os.listdir(inputDir):
        if not os.path.isfile(os.path.join(inputDir,filename)):
            continue
        filenamelist.append(filename)

    return filenamelist


def process_input_dir(inputDir, match, filelist):
    inputDir = inputDir.rstrip('/')+'/'
    filenamelist = make_filenamelist(inputDir)

    path = inputDir;
    name = ''
    jobdict = {}

    for filename in filenamelist:
        if( not re.search('.root$', filename) ):
            continue
        if ( match!=None and not re.search(match, filename) ):
            continue
        m1 = re.search('_\d+_\d+_\w+.root', filename)
        if name=='':
            name = re.split('_\d+_\d+_\w+.root', filename)[0]
        jobstring = filename[m1.start():].lstrip('_').replace('.root','').split('_')
        job = int(jobstring[0])
        if job not in jobdict.keys():
            jobdict[job] = []
            jobdict[job].append([int(jobstring[1])])
            jobdict[job].append([jobstring[2]])
        else:
            jobdict[job][0].append(int(jobstring[1]))
            jobdict[job][1].append(jobstring[2])

    jobs = jobdict.keys()
    if( len(jobs)==0 ):
        print 'No matching .root files found'
        sys.exit()

    jobs.sort()
    for job in jobs:
        maxsub = max(jobdict[job][0])
        filename = (path+name+'_%i_%i_%s.root')%(job, maxsub, jobdict[job][1][jobdict[job][0].index(maxsub)])
        filelist.append(filename)

    return


jdl_template = """universe = vanilla
Notification = never
Executable = DUMMY_OUTPUTDIR/CMSSW.sh
Output = DUMMY_OUTPUTDIR/logs/condor_$(Cluster)_$(Process).stdout
Error = DUMMY_OUTPUTDIR/logs/condor_$(Cluster)_$(Process).stderr
Log = DUMMY_OUTPUTDIR/logs/condor_$(Cluster)_$(Process).log
Arguments = $(Process) DUMMY_OUTPUTDIR DUMMY_PARAMS
+RULength="short"
Queue DUMMY_NJOBS
"""

jdl_template_fnal = """universe = vanilla
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Notification = never
x509userproxy = $ENV(X509_USER_PROXY)
Executable = DUMMY_OUTPUTDIR/CMSSW.sh
Output = condor_$(Cluster)_$(Process).stdout
Error = condor_$(Cluster)_$(Process).stderr
Log = condor_$(Cluster)_$(Process).log
Arguments = $(Process) DUMMY_OUTPUTDIR DUMMY_PARAMS
+LENGTH="SHORT"
Queue DUMMY_NJOBS
"""

bash_template = """#!/bin/bash

CONDOR_PROCESS=$1
OUTPUTDIR=$2
PARAMS=$3

START_TIME=`/bin/date`
echo "Started at $START_TIME"
echo ""

export SCRAM_ARCH=slc5_amd64_gcc462
source /cms/base/cmssoft/cmsset_default.sh
cd $OUTPUTDIR
eval `scramv1 runtime -sh`

# define output log file
LOG="${OUTPUTDIR}/logs/CMSSW_Job_${CONDOR_PROCESS}.log"
# separate individual input parameters
PARAMS_MOD=${PARAMS//,/ }

# rewrite cfg file with input parameters applied
python ${OUTPUTDIR}/CMSSW_cfg.py outFilename=${OUTPUTDIR}/output/CMSSW_Job_${CONDOR_PROCESS}.root \\
useExternalInput=True externalInput=${OUTPUTDIR}/input/files_${CONDOR_PROCESS}.txt \\
dumpPythonCfg=${OUTPUTDIR}/cfgs/CMSSW_Job_${CONDOR_PROCESS}_cfg.py \\
$PARAMS_MOD

echo "Running CMSSW job $CONDOR_PROCESS using the following input parameters: $PARAMS_MOD"
cmsRun -p ${OUTPUTDIR}/cfgs/CMSSW_Job_${CONDOR_PROCESS}_cfg.py > $LOG 2>&1
exitcode=$?

echo ""
END_TIME=`/bin/date`
echo "Finished at $END_TIME"
exit $exitcode
"""

bash_template_fnal = """#!/bin/bash

CONDOR_PROCESS=$1
OUTPUTDIR=$2
PARAMS=$3

START_TIME=`/bin/date`
echo "Started at $START_TIME"
echo ""

export SCRAM_ARCH=slc6_amd64_gcc472
source /cvmfs/cms.cern.ch/cmsset_default.sh
cd $OUTPUTDIR
eval `scramv1 runtime -sh`

# change to Condor scratch directory
cd ${_CONDOR_SCRATCH_DIR}

# define output log file
LOG="CMSSW_Job_${CONDOR_PROCESS}.log"
# separate individual input parameters
PARAMS_MOD=${PARAMS//,/ }

# rewrite cfg file with input parameters applied
python ${OUTPUTDIR}/CMSSW_cfg.py outFilename=CMSSW_Job_${CONDOR_PROCESS}.root \\
useExternalInput=True externalInput=${OUTPUTDIR}/input/files_${CONDOR_PROCESS}.txt \\
dumpPythonCfg=CMSSW_Job_${CONDOR_PROCESS}_cfg.py \\
$PARAMS_MOD

echo "Running CMSSW job $CONDOR_PROCESS using the following input parameters: $PARAMS_MOD"
cmsRun -p CMSSW_Job_${CONDOR_PROCESS}_cfg.py > $LOG 2>&1
exitcode=$?

echo ""
END_TIME=`/bin/date`
echo "Finished at $END_TIME"
exit $exitcode
"""


usage = """Usage: %prog [-m MATCH] -i INPUTDIR -c CMSSW_CFG -o OUTPUTDIR -n NJOBS [-p PARAMS -f 1.0 --create-only]\n
Example: ./createAndSubmitJobs.py -i /cms/ferencek/store/ferencek/QCD_Pt-120to170_TuneZ2star_8TeV_pythia6/Summer12_DR53X-PU_S10_START53_V7A-v3_BTagAnalyzer_V02-05-03/ -c tagvarextractor_cfg.py -o output_dir -n 60 -p maxEvents=-1,reportEvery=1000,wantSummary=True"""


def main():

    parser = optparse.OptionParser(usage=usage)

    parser.add_option('-m', '--match', metavar='MATCH', action='store', help='Only files containing the MATCH string in their names will be considered (This parameter is optional)')
    parser.add_option('-i', '--inputdir', metavar='INPUTDIR', dest='inputdir', action='store', help='Input directory containing .root files')
    parser.add_option('-c', '--cmssw_cfg', metavar="CMSSW_CFG", dest='cmssw_cfg', action='store', help='CMSSW configuration file template')
    parser.add_option('-o', '--outputdir', metavar='OUTPUTDIR', dest='outputdir', action='store', help='Main output directory for Condor jobs')
    parser.add_option('-n', '--njobs', metavar='NJOBS', action='store', dest='njobs', help='Number of jobs')
    parser.add_option('-p', '--params', metavar='PARAMS', action='store', dest='params', default='', help='Comma separated list of job input parameters (This parameter is optional)')
    parser.add_option('-f', '--fraction', metavar='FRACTION', action='store', dest='fraction', default='1.0', help='Fraction of files to be processed. Default value is 1 (This parameter is optional)')
    parser.add_option('--create-only', action="store_true", dest="create_only", default=False, help="Create the necessary configuration files but skip the job submission (This parameter is optional)")
    parser.add_option('--fnal', action="store_true", dest="fnal", default=False, help="This switch is mandatory if submitting jobs at FNAL")

    (options, args) = parser.parse_args(args=None)

    if ( options.inputdir==None or options.cmssw_cfg==None or options.outputdir==None or options.njobs==None ):
        print ('\nOptions -i, -c, -o, and -n  are required\n')
        parser.print_help()
        sys.exit()

    # process input directory
    filelist = []
    process_input_dir(options.inputdir, options.match, filelist)

    ################################################
    pwd = os.getcwd()
    # redefine main output directory as an absolute path (if not defined in such form already)
    outputmain = options.outputdir.rstrip('/')
    if not re.search('^/', outputmain):
	outputmain = pwd + '/' + outputmain

    os.mkdir(outputmain)
    os.mkdir(os.path.join(outputmain,'cfgs'))
    os.mkdir(os.path.join(outputmain,'input'))
    os.mkdir(os.path.join(outputmain,'logs'))
    os.mkdir(os.path.join(outputmain,'output'))
    #################################################
    numfiles = int(len(filelist)*float(options.fraction))
    ijobmax=int(options.njobs)
    if ijobmax > numfiles:
	ijobmax=numfiles
	print 'Number of jobs requested exceeds the total number of input files.\nThe number of jobs set to ' + str(ijobmax) + ' to match the number of input files'
    filesperjob = int(numfiles/ijobmax)
    if numfiles%ijobmax!=0:
	filesperjob = filesperjob + 1
	ijobmax = int(numfiles/filesperjob)
	if numfiles%filesperjob!=0:
	    ijobmax = ijobmax + 1
        if ijobmax != int(options.njobs):
            print 'Could not create the exact number of jobs requested.\nFor optimal job splitting, the number of jobs set to '+ str(ijobmax)
    #################################################
    # process input parameters
    maxEvents='-1'
    reportEvery='1000'
    params_list = []
    if options.params != None:
      for par in options.params.split(','):
	par_name = par.split('=')[0]
	if par_name == 'maxEvents':
	  maxEvents = par.split('=')[1]
	elif par_name == 'reportEvery':
	  reportEvery = par.split('=')[1]
	elif (par_name != 'useExternalInput' and par_name != 'externalInput' and par_name != 'dumpPythonCfg'): # 'useExternalInput','externalInput', and 'dumpPythonCfg' should not be redefined
	  params_list.append(par)

    params = 'maxEvents=' + maxEvents + ',reportEvery=' + reportEvery
    for par in params_list:
      params += (',' + par)
    #################################################
    # copy CMSSW cfg file to the cfg_files_dir
    shutil.copyfile(options.cmssw_cfg,os.path.join(outputmain,'CMSSW_cfg.py'))
    # create jdl file
    jdl_file = open(os.path.join(outputmain,'CMSSW.jdl'),'w')
    jdl_content = jdl_template
    if options.fnal:
        jdl_content = jdl_template_fnal
    jdl_content = re.sub('DUMMY_OUTPUTDIR',outputmain,jdl_content)
    jdl_content = re.sub('DUMMY_NJOBS',str(ijobmax),jdl_content)
    jdl_content = re.sub('DUMMY_PARAMS',params,jdl_content)
    jdl_file.write(jdl_content)
    jdl_file.close()
    # create Bash script
    bash_script = open(os.path.join(outputmain,'CMSSW.sh'),'w')
    bash_content = bash_template
    if options.fnal:
        bash_content = bash_template_fnal
    bash_script.write(bash_content)
    bash_script.close()
    os.system('chmod +x '+ os.path.join(outputmain,'CMSSW.sh'))
    ################################################
    ifile = 0
    for ijob in range(ijobmax):
	# prepare the list of input files
	inputfiles = (filelist[ifile].replace('/eos/uscms/store/user/','root://cmsxrootd-site.fnal.gov//store/user/') if options.fnal else filelist[ifile])
	for i in range(filesperjob-1):
	    if ifile>(numfiles-2):
	        break
	    ifile = ifile + 1
	    inputfiles += ( '\n' + (filelist[ifile].replace('/eos/uscms/store/user/','root://cmsxrootd-site.fnal.gov//store/user/') if options.fnal else filelist[ifile]) )
	ifile = ifile + 1
	
	# create a text file containing input files
	open(os.path.join(outputmain,'input','files_' + str(ijob) + '.txt'),'w').write(inputfiles)
	
    if not options.create_only:
      if options.fnal:
        os.chdir(os.path.join(outputmain,'output'))
      # submit Condor jobs
      os.system('condor_submit ' + os.path.join(outputmain,'CMSSW.jdl'))


if __name__ == '__main__':
    main()
