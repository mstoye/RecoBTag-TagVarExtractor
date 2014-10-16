// -*- C++ -*-
//
// Package:    TagVarExtractor
// Class:      TagVarExtractor
// 
/**\class TagVarExtractor TagVarExtractor.cc RecoBTag/TagVarExtractor/src/TagVarExtractor.cc

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

#include "RecoBTag/TagVarExtractor/interface/TagVarBranches.h"

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

#include <TLorentzVector.h>

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
      JetInfoBranches   JetInfo;
      JetInfoBranches   SubJetInfo;

      // input trees
      TChain* JetTree;
      TChain* EventTree;

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
      const std::string               inputEventTTree_;
      const bool                      separateEventTree_;
      const std::string               varPrefix_;
      const std::string               varPrefixSubjets_;
      const std::vector<std::string>  inputFiles_;
      const double                    jetPtMin_;
      const double                    jetPtMax_;
      const double                    jetAbsEtaMin_;
      const double                    jetAbsEtaMax_;
      const double                    jetMassMin_;
      const double                    jetMassMax_;
      const bool                      doBosonMatching_;
      const double                    bosonMatchingRadius_;
      const int                       bosonPdgId_;
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
  inputEventTTree_(iConfig.exists("InputEventTTree") ? iConfig.getParameter<std::string>("InputEventTTree") : ""),
  separateEventTree_(iConfig.exists("InputEventTTree") ? true : false),
  varPrefix_(iConfig.getParameter<std::string>("VarPrefix")),
  varPrefixSubjets_(iConfig.getParameter<std::string>("VarPrefixSubjets")),
  inputFiles_(iConfig.getParameter<std::vector<std::string> >("InputFiles")),
  jetPtMin_(iConfig.getParameter<double>("JetPtMin")),
  jetPtMax_(iConfig.getParameter<double>("JetPtMax")),
  jetAbsEtaMin_(iConfig.getParameter<double>("JetAbsEtaMin")),
  jetAbsEtaMax_(iConfig.getParameter<double>("JetAbsEtaMax")),
  jetMassMin_(iConfig.getParameter<double>("JetMassMin")),
  jetMassMax_(iConfig.getParameter<double>("JetMassMax")),
  doBosonMatching_(iConfig.getParameter<bool>("DoBosonMatching")),
  bosonMatchingRadius_(iConfig.getParameter<double>("BosonMatchingRadius")),
  bosonPdgId_(iConfig.getParameter<int>("BosonPdgId"))

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
  if(separateEventTree_) EventTree = new TChain(inputEventTTree_.c_str());

  for(unsigned i=0; i<inputFiles_.size(); ++i)
  {
    JetTree->Add(inputFiles_.at(i).c_str());
    if(separateEventTree_) EventTree->Add(inputFiles_.at(i).c_str());
  }

  // read input branches
  if(separateEventTree_)
    EvtInfo.ReadTree(EventTree);
  else
    EvtInfo.ReadTree(JetTree);
  JetInfo.ReadTree(JetTree,varPrefix_);
  JetInfo.ReadCSVTagVarTree(JetTree,varPrefix_);
  JetInfo.ReadFatJetSpecificTree(JetTree,varPrefix_);
  SubJetInfo.ReadTree(JetTree,varPrefixSubjets_);
  SubJetInfo.ReadCSVTagVarTree(JetTree,varPrefixSubjets_);
  SubJetInfo.ReadSubJetSpecificTree(JetTree,varPrefixSubjets_);
}

// ------------ method called for each event  ------------
void
TagVarExtractor::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  Long64_t nEntries = JetTree->GetEntries();

  if(separateEventTree_ && nEntries != EventTree->GetEntries())
  {
    edm::LogError("TreeSizeMismatch") << "Mismatch in the size of jet and event trees. Aborting.";
    return;
  }
  if(maxEvents_>=0) nEntries = ( nEntries>=maxEvents_ ? maxEvents_ : nEntries );

  //---------------------------- Start event loop ---------------------------------------//
  for(Long64_t iEntry = 0; iEntry < nEntries; ++iEntry)
  {
    JetTree->GetEntry(iEntry);
    if(separateEventTree_) EventTree->GetEntry(iEntry);

    if((iEntry%reportEvery_) == 0) edm::LogInfo("EventNumber") << "Processing event " << iEntry << " of " << nEntries;

    if(JetInfo.nJet <= 0) continue; // require at least 1 fat jet in the event

    std::vector<TLorentzVector> bosons;
    // select bosons used for matching
    if( doBosonMatching_ )
    {
      for(int iPart = 0; iPart < EvtInfo.nGenPruned; ++iPart)
      {
        if(abs(EvtInfo.GenPruned_pdgID[iPart]) == abs(bosonPdgId_) && (EvtInfo.GenPruned_status[iPart]==3 || EvtInfo.GenPruned_status[iPart]==22))
        {
          TLorentzVector boson;
          boson.SetPtEtaPhiM(EvtInfo.GenPruned_pT[iPart],EvtInfo.GenPruned_eta[iPart],EvtInfo.GenPruned_phi[iPart],EvtInfo.GenPruned_mass[iPart]);
          bosons.push_back(boson);
        }
      }
    }

    //---------------------------- Start fat jet loop ---------------------------------------//
    for(int iJet = 0; iJet < JetInfo.nJet; ++iJet)
    {
      if ( JetInfo.Jet_pt[iJet] < jetPtMin_ ||
           JetInfo.Jet_pt[iJet] > jetPtMax_ ) continue;                  // apply jet pT cut
      if ( fabs(JetInfo.Jet_eta[iJet]) < fabs(jetAbsEtaMin_) ||
           fabs(JetInfo.Jet_eta[iJet]) > fabs(jetAbsEtaMax_) ) continue; // apply jet eta cut
      if ( JetInfo.Jet_massGroomed[iJet] < jetMassMin_ ||
           JetInfo.Jet_massGroomed[iJet] > jetMassMax_ ) continue;       // apply jet mass cut
      if ( JetInfo.Jet_nSubJets[iJet] != 2 ) continue;                   // require exactly 2 subjets

      bool isBosonMatched = false;
      // perform boson matching
      if( doBosonMatching_ )
      {
        for(size_t i=0; i<bosons.size(); ++i)
        {
          if( reco::deltaR( bosons.at(i).Eta(), bosons.at(i).Phi(), JetInfo.Jet_eta[iJet], JetInfo.Jet_phi[iJet] ) < bosonMatchingRadius_ )
          {
            isBosonMatched = true;
            break;
          }
        }
      }
      else
        isBosonMatched = true;
 
      // skip the jet if not matched to a boson
      if( !isBosonMatched ) continue;

      memset(&TagVarInfo,0x00,sizeof(TagVarInfo));

      //######################################
      // Fat jet variables
      //######################################
      TagVarInfo.Jet_pt          = JetInfo.Jet_pt[iJet];
      TagVarInfo.Jet_eta         = JetInfo.Jet_eta[iJet];
      TagVarInfo.Jet_phi         = JetInfo.Jet_phi[iJet];
      TagVarInfo.Jet_mass        = JetInfo.Jet_mass[iJet];
      TagVarInfo.Jet_massGroomed = JetInfo.Jet_massGroomed[iJet];
      TagVarInfo.Jet_flavour     = JetInfo.Jet_flavour[iJet];
      TagVarInfo.Jet_nbHadrons   = JetInfo.Jet_nbHadrons[iJet];
      TagVarInfo.Jet_JP          = JetInfo.Jet_Proba[iJet];
      TagVarInfo.Jet_JBP         = JetInfo.Jet_Bprob[iJet];
      TagVarInfo.Jet_CSV         = JetInfo.Jet_CombSvx[iJet];
      TagVarInfo.Jet_CSVIVF      = JetInfo.Jet_CombIVF[iJet];
      TagVarInfo.Jet_tau1        = JetInfo.Jet_tau1[iJet];
      TagVarInfo.Jet_tau2        = JetInfo.Jet_tau2[iJet];

      TagVarInfo.TagVarCSV_jetNTracks              = JetInfo.TagVarCSV_jetNTracks[iJet];
      TagVarInfo.TagVarCSV_jetNTracksEtaRel        = JetInfo.TagVarCSV_jetNTracksEtaRel[iJet];
      TagVarInfo.TagVarCSV_trackSumJetEtRatio      = (JetInfo.TagVarCSV_trackSumJetEtRatio[iJet] < -1000. ? -1. : JetInfo.TagVarCSV_trackSumJetEtRatio[iJet]);
      TagVarInfo.TagVarCSV_trackSumJetDeltaR       = (JetInfo.TagVarCSV_trackSumJetDeltaR[iJet] < -1000. ? -1. : JetInfo.TagVarCSV_trackSumJetDeltaR[iJet]);
      TagVarInfo.TagVarCSV_trackSip2dValAboveCharm = (JetInfo.TagVarCSV_trackSip2dValAboveCharm[iJet] < -1000. ?  -9. : JetInfo.TagVarCSV_trackSip2dValAboveCharm[iJet]);
      TagVarInfo.TagVarCSV_trackSip2dSigAboveCharm = (JetInfo.TagVarCSV_trackSip2dSigAboveCharm[iJet] < -1000. ? -99. : JetInfo.TagVarCSV_trackSip2dSigAboveCharm[iJet]);
      TagVarInfo.TagVarCSV_trackSip3dValAboveCharm = (JetInfo.TagVarCSV_trackSip3dValAboveCharm[iJet] < -1000. ?  -9. : JetInfo.TagVarCSV_trackSip3dValAboveCharm[iJet]);
      TagVarInfo.TagVarCSV_trackSip3dSigAboveCharm = (JetInfo.TagVarCSV_trackSip3dSigAboveCharm[iJet] < -1000. ? -99. : JetInfo.TagVarCSV_trackSip3dSigAboveCharm[iJet]);
      TagVarInfo.TagVarCSV_vertexCategory          = (JetInfo.TagVarCSV_vertexCategory[iJet] < -1000. ? -1. : JetInfo.TagVarCSV_vertexCategory[iJet]);
      TagVarInfo.TagVarCSV_jetNSecondaryVertices   = JetInfo.TagVarCSV_jetNSecondaryVertices[iJet];
      TagVarInfo.TagVarCSV_vertexMass              = (JetInfo.TagVarCSV_vertexMass[iJet] < -1000. ? -1. : JetInfo.TagVarCSV_vertexMass[iJet]);
      TagVarInfo.TagVarCSV_vertexNTracks           = JetInfo.TagVarCSV_vertexNTracks[iJet];
      TagVarInfo.TagVarCSV_vertexEnergyRatio       = (JetInfo.TagVarCSV_vertexEnergyRatio[iJet] < -1000. ? -1. : JetInfo.TagVarCSV_vertexEnergyRatio[iJet]);
      TagVarInfo.TagVarCSV_vertexJetDeltaR         = (JetInfo.TagVarCSV_vertexJetDeltaR[iJet] < -1000. ? -1. : JetInfo.TagVarCSV_vertexJetDeltaR[iJet]);
      TagVarInfo.TagVarCSV_flightDistance2dVal     = (JetInfo.TagVarCSV_flightDistance2dVal[iJet] = -9999. ? -1. : JetInfo.TagVarCSV_flightDistance2dVal[iJet]);
      TagVarInfo.TagVarCSV_flightDistance2dSig     = (JetInfo.TagVarCSV_flightDistance2dSig[iJet] < -1000. ? -1. : JetInfo.TagVarCSV_flightDistance2dSig[iJet]);
      TagVarInfo.TagVarCSV_flightDistance3dVal     = (JetInfo.TagVarCSV_flightDistance3dVal[iJet] < -1000. ? -1. : JetInfo.TagVarCSV_flightDistance3dVal[iJet]);
      TagVarInfo.TagVarCSV_flightDistance3dSig     = (JetInfo.TagVarCSV_flightDistance3dSig[iJet] < -1000. ? -1. : JetInfo.TagVarCSV_flightDistance3dSig[iJet]);

      // loop over tracks to get IPs
      std::vector<float> IP2Ds;
      std::vector<float> IP3Ds;
      std::vector<float> PtRel;
      for (int iTrk = JetInfo.Jet_nFirstTrkTagVarCSV[iJet]; iTrk < JetInfo.Jet_nLastTrkTagVarCSV[iJet]; ++iTrk){
        IP2Ds.push_back( JetInfo.TagVarCSV_trackSip2dSig[iTrk] );
        IP3Ds.push_back( JetInfo.TagVarCSV_trackSip3dSig[iTrk] );
        PtRel.push_back( JetInfo.TagVarCSV_trackPtRel[iTrk] );
      }

      // loop over tracks to get trackEtaRel
      std::vector<float> etaRels; // stores |trackEtaRel|!
      for (int iTrk = JetInfo.Jet_nFirstTrkEtaRelTagVarCSV[iJet]; iTrk < JetInfo.Jet_nLastTrkEtaRelTagVarCSV[iJet]; ++iTrk)
        etaRels.push_back( fabs(JetInfo.TagVarCSV_trackEtaRel[iTrk]) );

      // sort the IP vectors in descending order and fill the branches based on the number of tracks
      std::sort( IP2Ds.begin(),IP2Ds.end(),std::greater<float>() );
      std::sort( IP3Ds.begin(),IP3Ds.end(),std::greater<float>() );
      std::sort( PtRel.begin(),PtRel.end(),std::greater<float>() );
      // sort etaRels in ascending order
      std::sort( etaRels.begin(),etaRels.end() ); //std::sort sorts in ascending order by default

      int numTracks = JetInfo.TagVarCSV_jetNTracks[iJet];
      int numEtaRelTracks = JetInfo.TagVarCSV_jetNTracksEtaRel[iJet];
      float dummyTrack = -99.;
      float dummyPtRel = -1.;
      float dummyEtaRel = -1.;
      // switch on the number of tracks in order to fill branches with a dummy if needed
      switch(numTracks){
        // if there are no selected tracks
        case 0:

          TagVarInfo.TagVarCSV_trackSip2dSig_0 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_1 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_2 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_3 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackSip3dSig_0 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_1 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_2 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_3 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackPtRel_0 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_1 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_2 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_3 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_4 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_5 = dummyPtRel;
          break;

        case 1:

          TagVarInfo.TagVarCSV_trackSip2dSig_0 = IP2Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip2dSig_1 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_2 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_3 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackSip3dSig_0 = IP3Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip3dSig_1 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_2 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_3 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackPtRel_0 = PtRel.at(0);
          TagVarInfo.TagVarCSV_trackPtRel_1 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_2 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_3 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_4 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_5 = dummyPtRel;
          break;

        case 2:

          TagVarInfo.TagVarCSV_trackSip2dSig_0 = IP2Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip2dSig_1 = IP2Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip2dSig_2 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_3 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackSip3dSig_0 = IP3Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip3dSig_1 = IP3Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip3dSig_2 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_3 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackPtRel_0 = PtRel.at(0);
          TagVarInfo.TagVarCSV_trackPtRel_1 = PtRel.at(1);
          TagVarInfo.TagVarCSV_trackPtRel_2 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_3 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_4 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_5 = dummyPtRel;
          break;

        case 3:

          TagVarInfo.TagVarCSV_trackSip2dSig_0 = IP2Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip2dSig_1 = IP2Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip2dSig_2 = IP2Ds.at(2);
          TagVarInfo.TagVarCSV_trackSip2dSig_3 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackSip3dSig_0 = IP3Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip3dSig_1 = IP3Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip3dSig_2 = IP3Ds.at(2);
          TagVarInfo.TagVarCSV_trackSip3dSig_3 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackPtRel_0 = PtRel.at(0);
          TagVarInfo.TagVarCSV_trackPtRel_1 = PtRel.at(1);
          TagVarInfo.TagVarCSV_trackPtRel_2 = PtRel.at(2);
          TagVarInfo.TagVarCSV_trackPtRel_3 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_4 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_5 = dummyPtRel;
          break;

        case 4:

          TagVarInfo.TagVarCSV_trackSip2dSig_0 = IP2Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip2dSig_1 = IP2Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip2dSig_2 = IP2Ds.at(2);
          TagVarInfo.TagVarCSV_trackSip2dSig_3 = IP2Ds.at(3);
          TagVarInfo.TagVarCSV_trackSip2dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip2dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackSip3dSig_0 = IP3Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip3dSig_1 = IP3Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip3dSig_2 = IP3Ds.at(2);
          TagVarInfo.TagVarCSV_trackSip3dSig_3 = IP3Ds.at(3);
          TagVarInfo.TagVarCSV_trackSip3dSig_4 = dummyTrack;
          TagVarInfo.TagVarCSV_trackSip3dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackPtRel_0 = PtRel.at(0);
          TagVarInfo.TagVarCSV_trackPtRel_1 = PtRel.at(1);
          TagVarInfo.TagVarCSV_trackPtRel_2 = PtRel.at(2);
          TagVarInfo.TagVarCSV_trackPtRel_3 = PtRel.at(3);
          TagVarInfo.TagVarCSV_trackPtRel_4 = dummyPtRel;
          TagVarInfo.TagVarCSV_trackPtRel_5 = dummyPtRel;
          break;

        case 5:

          TagVarInfo.TagVarCSV_trackSip2dSig_0 = IP2Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip2dSig_1 = IP2Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip2dSig_2 = IP2Ds.at(2);
          TagVarInfo.TagVarCSV_trackSip2dSig_3 = IP2Ds.at(3);
          TagVarInfo.TagVarCSV_trackSip2dSig_4 = IP2Ds.at(4);
          TagVarInfo.TagVarCSV_trackSip2dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackSip3dSig_0 = IP3Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip3dSig_1 = IP3Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip3dSig_2 = IP3Ds.at(2);
          TagVarInfo.TagVarCSV_trackSip3dSig_3 = IP3Ds.at(3);
          TagVarInfo.TagVarCSV_trackSip3dSig_4 = IP3Ds.at(4);
          TagVarInfo.TagVarCSV_trackSip3dSig_5 = dummyTrack;

          TagVarInfo.TagVarCSV_trackPtRel_0 = PtRel.at(0);
          TagVarInfo.TagVarCSV_trackPtRel_1 = PtRel.at(1);
          TagVarInfo.TagVarCSV_trackPtRel_2 = PtRel.at(2);
          TagVarInfo.TagVarCSV_trackPtRel_3 = PtRel.at(3);
          TagVarInfo.TagVarCSV_trackPtRel_4 = PtRel.at(4);
          TagVarInfo.TagVarCSV_trackPtRel_5 = dummyPtRel;
          break;

        default:

          TagVarInfo.TagVarCSV_trackSip2dSig_0 = IP2Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip2dSig_1 = IP2Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip2dSig_2 = IP2Ds.at(2);
          TagVarInfo.TagVarCSV_trackSip2dSig_3 = IP2Ds.at(3);
          TagVarInfo.TagVarCSV_trackSip2dSig_4 = IP2Ds.at(4);
          TagVarInfo.TagVarCSV_trackSip2dSig_5 = IP2Ds.at(5);

          TagVarInfo.TagVarCSV_trackSip3dSig_0 = IP3Ds.at(0);
          TagVarInfo.TagVarCSV_trackSip3dSig_1 = IP3Ds.at(1);
          TagVarInfo.TagVarCSV_trackSip3dSig_2 = IP3Ds.at(2);
          TagVarInfo.TagVarCSV_trackSip3dSig_3 = IP3Ds.at(3);
          TagVarInfo.TagVarCSV_trackSip3dSig_4 = IP3Ds.at(4);
          TagVarInfo.TagVarCSV_trackSip3dSig_5 = IP3Ds.at(5);

          TagVarInfo.TagVarCSV_trackPtRel_0 = PtRel.at(0);
          TagVarInfo.TagVarCSV_trackPtRel_1 = PtRel.at(1);
          TagVarInfo.TagVarCSV_trackPtRel_2 = PtRel.at(2);
          TagVarInfo.TagVarCSV_trackPtRel_3 = PtRel.at(3);
          TagVarInfo.TagVarCSV_trackPtRel_4 = PtRel.at(4);
          TagVarInfo.TagVarCSV_trackPtRel_5 = PtRel.at(5);

      } // end switch on number of tracks for IP

      // switch on the number of etarel tracks in order to fill branches with a dummy if needed
      switch(numEtaRelTracks){
        // if there are no etarel tracks
        case 0:

          TagVarInfo.TagVarCSV_trackEtaRel_0 = dummyEtaRel;
          TagVarInfo.TagVarCSV_trackEtaRel_1 = dummyEtaRel;
          TagVarInfo.TagVarCSV_trackEtaRel_2 = dummyEtaRel;
          break;

        case 1:

          TagVarInfo.TagVarCSV_trackEtaRel_0 = etaRels.at(0);
          TagVarInfo.TagVarCSV_trackEtaRel_1 = dummyEtaRel;
          TagVarInfo.TagVarCSV_trackEtaRel_2 = dummyEtaRel;
          break;

        case 2:

          TagVarInfo.TagVarCSV_trackEtaRel_0 = etaRels.at(0);
          TagVarInfo.TagVarCSV_trackEtaRel_1 = etaRels.at(1);
          TagVarInfo.TagVarCSV_trackEtaRel_2 = dummyEtaRel;
          break;

        default:

          TagVarInfo.TagVarCSV_trackEtaRel_0 = etaRels.at(0);
          TagVarInfo.TagVarCSV_trackEtaRel_1 = etaRels.at(1);
          TagVarInfo.TagVarCSV_trackEtaRel_2 = etaRels.at(2);

      } // end switch on number of etarel tracks

      // get the indices of the two subjets
      int iSubJet1 = JetInfo.SubJetIdx[JetInfo.Jet_nFirstSJ[iJet]];
      int iSubJet2 = JetInfo.SubJetIdx[JetInfo.Jet_nFirstSJ[iJet]+1];
      //  order subjets by pT if that's not the case already
      if( SubJetInfo.Jet_pt[iSubJet1] < SubJetInfo.Jet_pt[iSubJet2] )
      {
        iSubJet1 = iSubJet1 + iSubJet2;
        iSubJet2 = iSubJet1 - iSubJet2; // iSubJet2 = iSubJet1
        iSubJet1 = iSubJet1 - iSubJet2;
      }

      //######################################
      // Subjet1 variables
      //######################################
      TagVarInfo.SubJet1_pt        = SubJetInfo.Jet_pt[iSubJet1];
      TagVarInfo.SubJet1_eta       = SubJetInfo.Jet_eta[iSubJet1];
      TagVarInfo.SubJet1_phi       = SubJetInfo.Jet_phi[iSubJet1];
      TagVarInfo.SubJet1_mass      = SubJetInfo.Jet_mass[iSubJet1];
      TagVarInfo.SubJet1_flavour   = SubJetInfo.Jet_flavour[iSubJet1];
      TagVarInfo.SubJet1_nbHadrons = SubJetInfo.Jet_nbHadrons[iSubJet1];
      TagVarInfo.SubJet1_JP        = SubJetInfo.Jet_Proba[iSubJet1];
      TagVarInfo.SubJet1_JBP       = SubJetInfo.Jet_Bprob[iSubJet1];
      TagVarInfo.SubJet1_CSV       = SubJetInfo.Jet_CombSvx[iSubJet1];
      TagVarInfo.SubJet1_CSVIVF    = SubJetInfo.Jet_CombIVF[iSubJet1];

      TagVarInfo.TagVarCSV1_jetNTracks              = SubJetInfo.TagVarCSV_jetNTracks[iSubJet1];
      TagVarInfo.TagVarCSV1_jetNTracksEtaRel        = SubJetInfo.TagVarCSV_jetNTracksEtaRel[iSubJet1];
      TagVarInfo.TagVarCSV1_trackSumJetEtRatio      = (SubJetInfo.TagVarCSV_trackSumJetEtRatio[iSubJet1] < -1000. ? -1. : SubJetInfo.TagVarCSV_trackSumJetEtRatio[iSubJet1]);
      TagVarInfo.TagVarCSV1_trackSumJetDeltaR       = (SubJetInfo.TagVarCSV_trackSumJetDeltaR[iSubJet1] < -1000. ? -1. : SubJetInfo.TagVarCSV_trackSumJetDeltaR[iSubJet1]);
      TagVarInfo.TagVarCSV1_trackSip2dValAboveCharm = (SubJetInfo.TagVarCSV_trackSip2dValAboveCharm[iSubJet1] < -1000. ?  -9. : SubJetInfo.TagVarCSV_trackSip2dValAboveCharm[iSubJet1]);
      TagVarInfo.TagVarCSV1_trackSip2dSigAboveCharm = (SubJetInfo.TagVarCSV_trackSip2dSigAboveCharm[iSubJet1] < -1000. ? -99. : SubJetInfo.TagVarCSV_trackSip2dSigAboveCharm[iSubJet1]);
      TagVarInfo.TagVarCSV1_trackSip3dValAboveCharm = (SubJetInfo.TagVarCSV_trackSip3dValAboveCharm[iSubJet1] < -1000. ?  -9. : SubJetInfo.TagVarCSV_trackSip3dValAboveCharm[iSubJet1]);
      TagVarInfo.TagVarCSV1_trackSip3dSigAboveCharm = (SubJetInfo.TagVarCSV_trackSip3dSigAboveCharm[iSubJet1] < -1000. ? -99. : SubJetInfo.TagVarCSV_trackSip3dSigAboveCharm[iSubJet1]);
      TagVarInfo.TagVarCSV1_vertexCategory          = (SubJetInfo.TagVarCSV_vertexCategory[iSubJet1] < -1000. ? -1. : SubJetInfo.TagVarCSV_vertexCategory[iSubJet1]);
      TagVarInfo.TagVarCSV1_jetNSecondaryVertices   = SubJetInfo.TagVarCSV_jetNSecondaryVertices[iSubJet1];
      TagVarInfo.TagVarCSV1_vertexMass              = (SubJetInfo.TagVarCSV_vertexMass[iSubJet1] < -1000. ? -1. : SubJetInfo.TagVarCSV_vertexMass[iSubJet1]);
      TagVarInfo.TagVarCSV1_vertexNTracks           = SubJetInfo.TagVarCSV_vertexNTracks[iSubJet1];
      TagVarInfo.TagVarCSV1_vertexEnergyRatio       = (SubJetInfo.TagVarCSV_vertexEnergyRatio[iSubJet1] < -1000. ? -1. : SubJetInfo.TagVarCSV_vertexEnergyRatio[iSubJet1]);
      TagVarInfo.TagVarCSV1_vertexJetDeltaR         = (SubJetInfo.TagVarCSV_vertexJetDeltaR[iSubJet1] < -1000. ? -1. : SubJetInfo.TagVarCSV_vertexJetDeltaR[iSubJet1]);
      TagVarInfo.TagVarCSV1_flightDistance2dVal     = (SubJetInfo.TagVarCSV_flightDistance2dVal[iSubJet1] = -9999. ? -1. : SubJetInfo.TagVarCSV_flightDistance2dVal[iSubJet1]);
      TagVarInfo.TagVarCSV1_flightDistance2dSig     = (SubJetInfo.TagVarCSV_flightDistance2dSig[iSubJet1] < -1000. ? -1. : SubJetInfo.TagVarCSV_flightDistance2dSig[iSubJet1]);
      TagVarInfo.TagVarCSV1_flightDistance3dVal     = (SubJetInfo.TagVarCSV_flightDistance3dVal[iSubJet1] < -1000. ? -1. : SubJetInfo.TagVarCSV_flightDistance3dVal[iSubJet1]);
      TagVarInfo.TagVarCSV1_flightDistance3dSig     = (SubJetInfo.TagVarCSV_flightDistance3dSig[iSubJet1] < -1000. ? -1. : SubJetInfo.TagVarCSV_flightDistance3dSig[iSubJet1]);

      // loop over tracks to get trackEtaRel
      std::vector<float> etaRels1; // stores |trackEtaRel|!
      for (int iTrk = SubJetInfo.Jet_nFirstTrkEtaRelTagVarCSV[iSubJet1]; iTrk < SubJetInfo.Jet_nLastTrkEtaRelTagVarCSV[iSubJet1]; ++iTrk)
        etaRels1.push_back( fabs(SubJetInfo.TagVarCSV_trackEtaRel[iTrk]) );

      // sort etaRels in ascending order
      std::sort( etaRels1.begin(),etaRels1.end() ); //std::sort sorts in ascending order by default

      int numEtaRelTracks1 = SubJetInfo.TagVarCSV_jetNTracksEtaRel[iSubJet1];

      // switch on the number of etarel tracks in order to fill branches with a dummy if needed
      switch(numEtaRelTracks1){
        // if there are no etarel tracks
        case 0:

          TagVarInfo.TagVarCSV1_trackEtaRel_0 = dummyEtaRel;
          TagVarInfo.TagVarCSV1_trackEtaRel_1 = dummyEtaRel;
          TagVarInfo.TagVarCSV1_trackEtaRel_2 = dummyEtaRel;
          break;

        case 1:

          TagVarInfo.TagVarCSV1_trackEtaRel_0 = etaRels1.at(0);
          TagVarInfo.TagVarCSV1_trackEtaRel_1 = dummyEtaRel;
          TagVarInfo.TagVarCSV1_trackEtaRel_2 = dummyEtaRel;
          break;

        case 2:

          TagVarInfo.TagVarCSV1_trackEtaRel_0 = etaRels1.at(0);
          TagVarInfo.TagVarCSV1_trackEtaRel_1 = etaRels1.at(1);
          TagVarInfo.TagVarCSV1_trackEtaRel_2 = dummyEtaRel;
          break;

        default:

          TagVarInfo.TagVarCSV1_trackEtaRel_0 = etaRels1.at(0);
          TagVarInfo.TagVarCSV1_trackEtaRel_1 = etaRels1.at(1);
          TagVarInfo.TagVarCSV1_trackEtaRel_2 = etaRels1.at(2);

      } // end switch on number of etarel tracks

      //######################################
      // Subjet2 variables
      //######################################
      TagVarInfo.SubJet2_pt        = SubJetInfo.Jet_pt[iSubJet2];
      TagVarInfo.SubJet2_eta       = SubJetInfo.Jet_eta[iSubJet2];
      TagVarInfo.SubJet2_phi       = SubJetInfo.Jet_phi[iSubJet2];
      TagVarInfo.SubJet2_mass      = SubJetInfo.Jet_mass[iSubJet2];
      TagVarInfo.SubJet2_flavour   = SubJetInfo.Jet_flavour[iSubJet2];
      TagVarInfo.SubJet2_nbHadrons = SubJetInfo.Jet_nbHadrons[iSubJet2];
      TagVarInfo.SubJet2_JP        = SubJetInfo.Jet_Proba[iSubJet2];
      TagVarInfo.SubJet2_JBP       = SubJetInfo.Jet_Bprob[iSubJet2];
      TagVarInfo.SubJet2_CSV       = SubJetInfo.Jet_CombSvx[iSubJet2];
      TagVarInfo.SubJet2_CSVIVF    = SubJetInfo.Jet_CombIVF[iSubJet2];

      TagVarInfo.TagVarCSV2_jetNTracks              = SubJetInfo.TagVarCSV_jetNTracks[iSubJet2];
      TagVarInfo.TagVarCSV2_jetNTracksEtaRel        = SubJetInfo.TagVarCSV_jetNTracksEtaRel[iSubJet2];
      TagVarInfo.TagVarCSV2_trackSumJetEtRatio      = (SubJetInfo.TagVarCSV_trackSumJetEtRatio[iSubJet2] < -1000. ? -1. : SubJetInfo.TagVarCSV_trackSumJetEtRatio[iSubJet2]);
      TagVarInfo.TagVarCSV2_trackSumJetDeltaR       = (SubJetInfo.TagVarCSV_trackSumJetDeltaR[iSubJet2] < -1000. ? -1. : SubJetInfo.TagVarCSV_trackSumJetDeltaR[iSubJet2]);
      TagVarInfo.TagVarCSV2_trackSip2dValAboveCharm = (SubJetInfo.TagVarCSV_trackSip2dValAboveCharm[iSubJet2] < -1000. ?  -9. : SubJetInfo.TagVarCSV_trackSip2dValAboveCharm[iSubJet2]);
      TagVarInfo.TagVarCSV2_trackSip2dSigAboveCharm = (SubJetInfo.TagVarCSV_trackSip2dSigAboveCharm[iSubJet2] < -1000. ? -99. : SubJetInfo.TagVarCSV_trackSip2dSigAboveCharm[iSubJet2]);
      TagVarInfo.TagVarCSV2_trackSip3dValAboveCharm = (SubJetInfo.TagVarCSV_trackSip3dValAboveCharm[iSubJet2] < -1000. ?  -9. : SubJetInfo.TagVarCSV_trackSip3dValAboveCharm[iSubJet2]);
      TagVarInfo.TagVarCSV2_trackSip3dSigAboveCharm = (SubJetInfo.TagVarCSV_trackSip3dSigAboveCharm[iSubJet2] < -1000. ? -99. : SubJetInfo.TagVarCSV_trackSip3dSigAboveCharm[iSubJet2]);
      TagVarInfo.TagVarCSV2_vertexCategory          = (SubJetInfo.TagVarCSV_vertexCategory[iSubJet2] < -1000. ? -1. : SubJetInfo.TagVarCSV_vertexCategory[iSubJet2]);
      TagVarInfo.TagVarCSV2_jetNSecondaryVertices   = SubJetInfo.TagVarCSV_jetNSecondaryVertices[iSubJet2];
      TagVarInfo.TagVarCSV2_vertexMass              = (SubJetInfo.TagVarCSV_vertexMass[iSubJet2] < -1000. ? -1. : SubJetInfo.TagVarCSV_vertexMass[iSubJet2]);
      TagVarInfo.TagVarCSV2_vertexNTracks           = SubJetInfo.TagVarCSV_vertexNTracks[iSubJet2];
      TagVarInfo.TagVarCSV2_vertexEnergyRatio       = (SubJetInfo.TagVarCSV_vertexEnergyRatio[iSubJet2] < -1000. ? -1. : SubJetInfo.TagVarCSV_vertexEnergyRatio[iSubJet2]);
      TagVarInfo.TagVarCSV2_vertexJetDeltaR         = (SubJetInfo.TagVarCSV_vertexJetDeltaR[iSubJet2] < -1000. ? -1. : SubJetInfo.TagVarCSV_vertexJetDeltaR[iSubJet2]);
      TagVarInfo.TagVarCSV2_flightDistance2dVal     = (SubJetInfo.TagVarCSV_flightDistance2dVal[iSubJet2] = -9999. ? -1. : SubJetInfo.TagVarCSV_flightDistance2dVal[iSubJet2]);
      TagVarInfo.TagVarCSV2_flightDistance2dSig     = (SubJetInfo.TagVarCSV_flightDistance2dSig[iSubJet2] < -1000. ? -1. : SubJetInfo.TagVarCSV_flightDistance2dSig[iSubJet2]);
      TagVarInfo.TagVarCSV2_flightDistance3dVal     = (SubJetInfo.TagVarCSV_flightDistance3dVal[iSubJet2] < -1000. ? -1. : SubJetInfo.TagVarCSV_flightDistance3dVal[iSubJet2]);
      TagVarInfo.TagVarCSV2_flightDistance3dSig     = (SubJetInfo.TagVarCSV_flightDistance3dSig[iSubJet2] < -1000. ? -1. : SubJetInfo.TagVarCSV_flightDistance3dSig[iSubJet2]);

      // loop over tracks to get trackEtaRel
      std::vector<float> etaRels2; // stores |trackEtaRel|!
      for (int iTrk = SubJetInfo.Jet_nFirstTrkEtaRelTagVarCSV[iSubJet2]; iTrk < SubJetInfo.Jet_nLastTrkEtaRelTagVarCSV[iSubJet2]; ++iTrk)
        etaRels2.push_back( fabs(SubJetInfo.TagVarCSV_trackEtaRel[iTrk]) );

      // sort etaRels in ascending order
      std::sort( etaRels2.begin(),etaRels2.end() ); //std::sort sorts in ascending order by default

      int numEtaRelTracks2 = SubJetInfo.TagVarCSV_jetNTracksEtaRel[iSubJet2];

      // switch on the number of etarel tracks in order to fill branches with a dummy if needed
      switch(numEtaRelTracks2){
        // if there are no etarel tracks
        case 0:

          TagVarInfo.TagVarCSV2_trackEtaRel_0 = dummyEtaRel;
          TagVarInfo.TagVarCSV2_trackEtaRel_1 = dummyEtaRel;
          TagVarInfo.TagVarCSV2_trackEtaRel_2 = dummyEtaRel;
          break;

        case 1:

          TagVarInfo.TagVarCSV2_trackEtaRel_0 = etaRels2.at(0);
          TagVarInfo.TagVarCSV2_trackEtaRel_1 = dummyEtaRel;
          TagVarInfo.TagVarCSV2_trackEtaRel_2 = dummyEtaRel;
          break;

        case 2:

          TagVarInfo.TagVarCSV2_trackEtaRel_0 = etaRels2.at(0);
          TagVarInfo.TagVarCSV2_trackEtaRel_1 = etaRels2.at(1);
          TagVarInfo.TagVarCSV2_trackEtaRel_2 = dummyEtaRel;
          break;

        default:

          TagVarInfo.TagVarCSV2_trackEtaRel_0 = etaRels2.at(0);
          TagVarInfo.TagVarCSV2_trackEtaRel_1 = etaRels2.at(1);
          TagVarInfo.TagVarCSV2_trackEtaRel_2 = etaRels2.at(2);

      } // end switch on number of etarel tracks

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
