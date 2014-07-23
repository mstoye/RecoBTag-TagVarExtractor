// -*- C++ -*-
//
// Package:    TagVarExtractor
// Class:      TagVarExtractor
// 
/**\class TagVarExtractor TagVarExtractor.cc MyAnalysis/TagVarExtractor/src/TagVarExtractor.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Dinko Ferencek
//         Created:  Sun Jul 13 18:01:39 EDT 2014
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "DataFormats/Math/interface/deltaR.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "RecoBTag/PerformanceMeasurements/interface/JetInfoBranches.h"
#include "RecoBTag/PerformanceMeasurements/interface/EventInfoBranches.h"

#include "MyAnalysis/TagVarExtractor/interface/TagVarBranches.h"

#include <TString.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TLorentzVector.h>
#include <TF1.h>

#include <string>
#include <map>
#include <vector>
//
// class declaration
//

class TagVarExtractor : public edm::EDAnalyzer {
   public:
      explicit TagVarExtractor(const edm::ParameterSet&);
      ~TagVarExtractor();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      virtual void endRun(edm::Run const&, edm::EventSetup const&);
      virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

      // ----------member data ---------------------------

      // input branches
      EventInfoBranches EvtInfo;
      JetInfoBranches   FatJetInfo;

      // input trees
      TChain* JetTree;

      // output branches
      TagVarBranches TagVarInfo;
      // output tree
      TTree *TagVarTree;
      // TFileService for output file
      edm::Service<TFileService> fs;

      // configurables
      const int                       maxEvents_;
      const int                       reportEvery_;
      const std::string               inputTTree_;
      const std::vector<std::string>  inputFiles_;
      const double                    jetPtMin_;
      const double                    jetPtMax_;
      const double                    jetAbsEtaMin_;
      const double                    jetAbsEtaMax_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
TagVarExtractor::TagVarExtractor(const edm::ParameterSet& iConfig) :

  maxEvents_(iConfig.getParameter<int>("MaxEvents")),
  reportEvery_(iConfig.getParameter<int>("ReportEvery")),
  inputTTree_(iConfig.getParameter<std::string>("InputTTree")),
  inputFiles_(iConfig.getParameter<std::vector<std::string> >("InputFiles")),
  jetPtMin_(iConfig.getParameter<double>("JetPtMin")),
  jetPtMax_(iConfig.getParameter<double>("JetPtMax")),
  jetAbsEtaMin_(iConfig.getParameter<double>("JetAbsEtaMin")),
  jetAbsEtaMax_(iConfig.getParameter<double>("JetAbsEtaMax"))

{
   //now do what ever initialization is needed

   // create output tree
   TagVarTree = fs->make<TTree>("ttree", "ttree");

   // register output branches
   TagVarInfo.RegisterTree(TagVarTree);
}


TagVarExtractor::~TagVarExtractor()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//
// ------------ method called once each job just before starting event loop  ------------
void 
TagVarExtractor::beginJob()
{
  // add input trees
  JetTree = new TChain(inputTTree_.c_str());

  for(unsigned i=0; i<inputFiles_.size(); ++i)
    JetTree->Add(inputFiles_.at(i).c_str());

  // read input branches
  EvtInfo.ReadTree(JetTree);
  FatJetInfo.ReadTree(JetTree,"FatJetInfo");
  FatJetInfo.ReadCSVTagVarTree(JetTree,"FatJetInfo");
}

// ------------ method called for each event  ------------
void
TagVarExtractor::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  if(JetTree == 0) return;

  Long64_t nEntries = JetTree->GetEntries();
  if(maxEvents_>=0) nEntries = ( nEntries>=maxEvents_ ? maxEvents_ : nEntries );

  //---------------------------- Start event loop ---------------------------------------//
  for(Long64_t iEntry = 0; iEntry < nEntries; ++iEntry)
  {
    JetTree->GetEntry(iEntry);
    if((iEntry%reportEvery_) == 0) edm::LogInfo("EventNumber") << "Processing event " << iEntry << " of " << nEntries;

    if(FatJetInfo.nJet <= 0) continue; // require at least 1 fat jet in the event

    //---------------------------- Start fat jet loop ---------------------------------------//
    for(int iJet = 0; iJet < FatJetInfo.nJet; ++iJet)
    {
      if ( FatJetInfo.Jet_pt[iJet] < jetPtMin_ ||
           FatJetInfo.Jet_pt[iJet] > jetPtMax_ ) continue;                  // apply jet pT cut
      if ( fabs(FatJetInfo.Jet_eta[iJet]) < fabs(jetAbsEtaMin_) ||
           fabs(FatJetInfo.Jet_eta[iJet]) > fabs(jetAbsEtaMax_) ) continue; // apply jet eta cut

      memset(&TagVarInfo,0x00,sizeof(TagVarInfo));

      TagVarInfo.Jet_pt        = FatJetInfo.Jet_pt[iJet];
      TagVarInfo.Jet_eta       = FatJetInfo.Jet_eta[iJet];
      TagVarInfo.Jet_phi       = FatJetInfo.Jet_phi[iJet];
      TagVarInfo.Jet_mass      = FatJetInfo.Jet_mass[iJet];
      TagVarInfo.Jet_flavour   = FatJetInfo.Jet_flavour[iJet];
      TagVarInfo.Jet_nbHadrons = FatJetInfo.Jet_nbHadrons[iJet];
      TagVarInfo.Jet_JP        = FatJetInfo.Jet_Proba[iJet];
      TagVarInfo.Jet_JBP       = FatJetInfo.Jet_Bprob[iJet];
      TagVarInfo.Jet_CSV       = FatJetInfo.Jet_CombSvx[iJet];
      TagVarInfo.Jet_CSVIVF    = FatJetInfo.Jet_CombIVF[iJet];

      TagVarInfo.TagVarCSV_trackJetPt              = FatJetInfo.TagVarCSV_trackJetPt[iJet];
      TagVarInfo.TagVarCSV_jetNTracks              = FatJetInfo.TagVarCSV_jetNTracks[iJet];
      TagVarInfo.TagVarCSV_jetNTracksEtaRel        = FatJetInfo.TagVarCSV_jetNTracksEtaRel[iJet];
      TagVarInfo.TagVarCSV_trackSumJetEtRatio      = FatJetInfo.TagVarCSV_trackSumJetEtRatio[iJet];
      TagVarInfo.TagVarCSV_trackSumJetDeltaR       = FatJetInfo.TagVarCSV_trackSumJetDeltaR[iJet];
      TagVarInfo.TagVarCSV_trackSip2dValAboveCharm = FatJetInfo.TagVarCSV_trackSip2dValAboveCharm[iJet];
      TagVarInfo.TagVarCSV_trackSip2dSigAboveCharm = FatJetInfo.TagVarCSV_trackSip2dSigAboveCharm[iJet];
      TagVarInfo.TagVarCSV_trackSip3dValAboveCharm = FatJetInfo.TagVarCSV_trackSip3dValAboveCharm[iJet];
      TagVarInfo.TagVarCSV_trackSip3dSigAboveCharm = FatJetInfo.TagVarCSV_trackSip3dSigAboveCharm[iJet];
      TagVarInfo.TagVarCSV_vertexCategory          = FatJetInfo.TagVarCSV_vertexCategory[iJet];
      TagVarInfo.TagVarCSV_jetNSecondaryVertices   = FatJetInfo.TagVarCSV_jetNSecondaryVertices[iJet];
      TagVarInfo.TagVarCSV_vertexMass              = FatJetInfo.TagVarCSV_vertexMass[iJet];
      TagVarInfo.TagVarCSV_vertexNTracks           = FatJetInfo.TagVarCSV_vertexNTracks[iJet];
      TagVarInfo.TagVarCSV_vertexEnergyRatio       = FatJetInfo.TagVarCSV_vertexEnergyRatio[iJet];
      TagVarInfo.TagVarCSV_vertexJetDeltaR         = FatJetInfo.TagVarCSV_vertexJetDeltaR[iJet];
      TagVarInfo.TagVarCSV_flightDistance2dVal     = FatJetInfo.TagVarCSV_flightDistance2dVal[iJet];
      TagVarInfo.TagVarCSV_flightDistance2dSig     = FatJetInfo.TagVarCSV_flightDistance2dSig[iJet];
      TagVarInfo.TagVarCSV_flightDistance3dVal     = FatJetInfo.TagVarCSV_flightDistance3dVal[iJet];
      TagVarInfo.TagVarCSV_flightDistance3dSig     = FatJetInfo.TagVarCSV_flightDistance3dSig[iJet];

      //loop over tracks to get IPs
      std::vector<float> IP2Ds;
      std::vector<float> IP3Ds;
      for (int iTrk = FatJetInfo.Jet_nFirstTrkTagVarCSV[iJet]; iTrk < FatJetInfo.Jet_nLastTrkTagVarCSV[iJet]; ++iTrk){
        IP2Ds.push_back( FatJetInfo.TagVarCSV_trackSip2dSig[iTrk] );
        IP3Ds.push_back( FatJetInfo.TagVarCSV_trackSip3dSig[iTrk] );
      }

      //loop over tracks to get trackEtaRel
      std::vector<float> etaRels; //stores |trackEtaRel|!
      for (int iTrk = FatJetInfo.Jet_nFirstTrkEtaRelTagVarCSV[iJet]; iTrk < FatJetInfo.Jet_nLastTrkEtaRelTagVarCSV[iJet]; ++iTrk)
        etaRels.push_back( fabs(FatJetInfo.TagVarCSV_trackEtaRel[iTrk]) );

      //sort the IP vectors in descending order and fill the branches based on the number of tracks
      std::sort( IP2Ds.begin(),IP2Ds.end(),std::greater<float>() );
      std::sort( IP3Ds.begin(),IP3Ds.end(),std::greater<float>() );
      //sort etaRels in ascending order
      std::sort( etaRels.begin(),etaRels.end() ); //std::sort sorts in ascending order by default
      int numTracks = FatJetInfo.TagVarCSV_jetNTracks[iJet];
      int numEtaRelTracks = FatJetInfo.TagVarCSV_jetNTracksEtaRel[iJet];
      float dummyTrack = -99.;
      float dummyEtaRel = -1.;
      //switch on the number of tracks in order to fill branches with a dummy if needed
      switch(numTracks){
        // if there are no selected tracks
        case 0:

          TagVarInfo.TagVarCSV_trackSip2dSig_Leading = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_SecondLeading = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_ThirdLeading = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_Leading = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_SecondLeading = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_ThirdLeading = dummyTrack;
          break;

        case 1:

          TagVarInfo.TagVarCSV_trackSip2dSig_Leading = IP2Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip2dSig_SecondLeading = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_ThirdLeading = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_Leading = IP3Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip3dSig_SecondLeading = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_ThirdLeading = dummyTrack;
          break;

        case 2:

          TagVarInfo.TagVarCSV_trackSip2dSig_Leading = IP2Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip2dSig_SecondLeading = IP2Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip2dSig_ThirdLeading = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_Leading = IP3Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip3dSig_SecondLeading = IP3Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip3dSig_ThirdLeading = dummyTrack;
          break;

        default:

          TagVarInfo.TagVarCSV_trackSip2dSig_Leading = IP2Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip2dSig_SecondLeading = IP2Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip2dSig_ThirdLeading = IP2Ds.at(2);
          TagVarInfo.TagVarCSV_trackSip3dSig_Leading = IP3Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip3dSig_SecondLeading = IP3Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip3dSig_ThirdLeading = IP3Ds.at(2);

      } //end switch on number of tracks for IP

      //switch on the number of etarel tracks in order to fill branches with a dummy if needed
      switch(numEtaRelTracks){
        // if there are no etarel tracks
        case 0:

          TagVarInfo.TagVarCSV_trackEtaRel_Lowest = dummyEtaRel;
          TagVarInfo.TagVarCSV_trackEtaRel_SecondLowest = dummyEtaRel;
          TagVarInfo.TagVarCSV_trackEtaRel_ThirdLowest = dummyEtaRel;
          break;

        case 1:

          TagVarInfo.TagVarCSV_trackEtaRel_Lowest = etaRels.at(0);
          TagVarInfo.TagVarCSV_trackEtaRel_SecondLowest = dummyEtaRel;
          TagVarInfo.TagVarCSV_trackEtaRel_ThirdLowest = dummyEtaRel;
          break;

        case 2:

          TagVarInfo.TagVarCSV_trackEtaRel_Lowest = etaRels.at(0);
          TagVarInfo.TagVarCSV_trackEtaRel_SecondLowest = etaRels.at(1);
          TagVarInfo.TagVarCSV_trackEtaRel_ThirdLowest = dummyEtaRel;
          break;

        default:

          TagVarInfo.TagVarCSV_trackEtaRel_Lowest = etaRels.at(0);
          TagVarInfo.TagVarCSV_trackEtaRel_SecondLowest = etaRels.at(1);
          TagVarInfo.TagVarCSV_trackEtaRel_ThirdLowest = etaRels.at(2);

      } //end switch on number of etarel tracks


      TagVarTree->Fill();
    }
    //----------------------------- End fat jet loop ----------------------------------------//

  }
  //----------------------------- End event loop ----------------------------------------//
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TagVarExtractor::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void 
TagVarExtractor::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
TagVarExtractor::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
TagVarExtractor::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
TagVarExtractor::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
TagVarExtractor::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(TagVarExtractor);
