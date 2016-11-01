#!/usr/bin/python
import os
import sys

#theFiles = ['ttbar','QCD_Pt_120to170','QCD_Pt_170to300','QCD_Pt_300to470','QCD_Pt_470to600']
theFiles = ['QCD_Pt_50to80']


initialDir = os.getcwd()

for i in range(len(theFiles)):
    print os.getcwd()
    f = open('prod_tagvarextractor_cfg.py','r')
    batch = open('prod_submit.sh','r')
    os.mkdir(theFiles[i])
    os.chdir(theFiles[i])
    print os.getcwd()
    b =  open('btagvarextractor_cfg.py','w')
    c =  open('ctagvarextractor_cfg.py','w')
    u =  open('utagvarextractor_cfg.py','w')
    bb =  open('bbtagvarextractor_cfg.py','w')
    cc =  open('cctagvarextractor_cfg.py','w')

   # print os.list()
# prepare .py files from prod_tagvarextractor_cfg.py
    for line in f:
       # print line
        if 'InputXXX_cff' in line:
            line = line.replace('InputXXX_cff',theFiles[i]+'_cff')
            b.write(line)
            c.write(line)
            u.write(line)
            bb.write(line)
            cc.write(line)
        elif 'JetFlavor = cms.int32(0)' in line:
            b.write(line.replace('JetFlavor = cms.int32(0)', 'JetFlavor = cms.int32(1)'))
            c.write(line.replace('JetFlavor = cms.int32(0)', 'JetFlavor = cms.int32(2)'))
            u.write(line.replace('JetFlavor = cms.int32(0)', 'JetFlavor = cms.int32(3)'))
            bb.write(line.replace('JetFlavor = cms.int32(0)', 'JetFlavor = cms.int32(4)'))
            cc.write(line.replace('JetFlavor = cms.int32(0)', 'JetFlavor = cms.int32(5)'))
        elif 'JetTaggingVariables.root' in line:
            b.write(line.replace('JetTaggingVariables.','JetTaggingVariablesb.'))
            c.write(line.replace('JetTaggingVariables.','JetTaggingVariablesc.'))
            u.write(line.replace('JetTaggingVariables.','JetTaggingVariablesu.'))
            cc.write(line.replace('JetTaggingVariables.','JetTaggingVariablescc.'))
            bb.write(line.replace('JetTaggingVariables.','JetTaggingVariablesbb.'))
        else:
            b.write(line)
            c.write(line)
            u.write(line)   
            cc.write(line)
            bb.write(line)   
            



    b.close()
    c.close()
    u.close()   
    bb.close()
    cc.close()
                       
# prepare .sh files from prod_submit.sh
    bs =  open('bsubmit.sh','w')
    cs =  open('csubmit.sh','w')
    us =  open('usubmit.sh','w')
    bbs =  open('bbsubmit.sh','w')
    ccs =  open('ccsubmit.sh','w')
  


  
    PWD = os.getcwd()

    for line in batch:
    #print line
        if 'MYPATH' in line:
            line = line.replace('MYPATH',PWD)
            bs.write(line)
            cs.write(line)
            us.write(line)
            bbs.write(line)
            ccs.write(line)
        elif 'cp ../XXX_cff .' in line:
            line = line.replace('cp ../XXX_cff .','cp ../'+theFiles[i]+'_cff.py .')
            bs.write(line)
            cs.write(line)
            us.write(line)
            bbs.write(line)
            ccs.write(line)

        elif 'cmsRun XXX.py' in line:
            bs.write(line.replace('cmsRun XXX.py','cmsRun btagvarextractor_cfg.py maxEvents=-1'))
            cs.write(line.replace('cmsRun XXX.py','cmsRun ctagvarextractor_cfg.py maxEvents=-1'))
            us.write(line.replace('cmsRun XXX.py','cmsRun utagvarextractor_cfg.py maxEvents=4000000'))
            bbs.write(line.replace('cmsRun XXX.py','cmsRun bbtagvarextractor_cfg.py maxEvents=-1'))
            ccs.write(line.replace('cmsRun XXX.py','cmsRun cctagvarextractor_cfg.py maxEvents=-1'))

        else:
            bs.write(line)
            cs.write(line)
            us.write(line)
            bbs.write(line)
            ccs.write(line)

    bs.close()
    cs.close()
    us.close()   
    bbs.close()
    ccs.close()

    os.system('chmod u+x bsubmit.sh')
    os.system('chmod u+x csubmit.sh')
    os.system('chmod u+x usubmit.sh')
    os.system('chmod u+x bbsubmit.sh')
    os.system('chmod u+x ccsubmit.sh')

    os.system('bsub -q 1nd -J b -o doutput.txt < bsubmit.sh')
    os.system('bsub -q 1nd -J c -o coutput.txt < csubmit.sh')
    os.system('bsub -q 1nd -J udsg -o uoutput.txt < usubmit.sh')
    os.system('bsub -q 1nd -J udsg -o bboutput.txt < bbsubmit.sh')
    os.system('bsub -q 1nd -J udsg -o ccoutput.txt < ccsubmit.sh')


    os.chdir(initialDir)





        
