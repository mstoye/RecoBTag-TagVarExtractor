#ifndef TagVarBranches_h
#define TagVarBranches_h

#include <TTree.h>


class TagVarBranches {

  public:

    float Jet_pt;
    float Jet_eta;
    float Jet_phi;
    float Jet_mass;
    int   Jet_flavour;
    int   Jet_nbHadrons;
    float Jet_JP;
    float Jet_JBP;
    float Jet_CSV;
    float Jet_CSVIVF;

    // CSV TaggingVariables
    // per jet
    float TagVarCSV_trackJetPt;                           // track-based jet transverse momentum
    float TagVarCSV_jetNTracks;                           // tracks associated to jet
    float TagVarCSV_jetNTracksEtaRel;                     // tracks associated to jet for which trackEtaRel is calculated
    float TagVarCSV_trackSumJetEtRatio;                   // ratio of track sum transverse energy over jet energy
    float TagVarCSV_trackSumJetDeltaR;                    // pseudoangular distance between jet axis and track fourvector sum
    float TagVarCSV_trackSip2dValAboveCharm;              // track 2D signed impact parameter of first track lifting mass above charm
    float TagVarCSV_trackSip2dSigAboveCharm;              // track 2D signed impact parameter significance of first track lifting mass above charm
    float TagVarCSV_trackSip3dValAboveCharm;              // track 3D signed impact parameter of first track lifting mass above charm
    float TagVarCSV_trackSip3dSigAboveCharm;              // track 3D signed impact parameter significance of first track lifting mass above charm
    float TagVarCSV_vertexCategory;                       // category of secondary vertex (Reco, Pseudo, No)
    float TagVarCSV_jetNSecondaryVertices;                // number of reconstructed possible secondary vertices in jet
    float TagVarCSV_vertexMass;                           // mass of track sum at secondary vertex
    float TagVarCSV_vertexNTracks;                        // number of tracks at secondary vertex
    float TagVarCSV_vertexEnergyRatio;                    // ratio of energy at secondary vertex over total energy
    float TagVarCSV_vertexJetDeltaR;                      // pseudoangular distance between jet axis and secondary vertex direction
    float TagVarCSV_flightDistance2dVal;                  // transverse distance between primary and secondary vertex
    float TagVarCSV_flightDistance2dSig;                  // transverse distance significance between primary and secondary vertex
    float TagVarCSV_flightDistance3dVal;                  // distance between primary and secondary vertex
    float TagVarCSV_flightDistance3dSig;                  // distance significance between primary and secondary vertex
    // per jet per track
//     int   nTrkTagVarCSV;
//     int   nTrkEtaRelTagVarCSV;
//     float TagVarCSV_trackMomentum[nMaxTrk_];                         // track momentum
//     float TagVarCSV_trackEta[nMaxTrk_];                              // track pseudorapidity
//     float TagVarCSV_trackPhi[nMaxTrk_];                              // track polar angle
//     float TagVarCSV_trackPtRel[nMaxTrk_];                            // track transverse momentum, relative to the jet axis
//     float TagVarCSV_trackPPar[nMaxTrk_];                             // track parallel momentum, along the jet axis
//     float TagVarCSV_trackDeltaR[nMaxTrk_];                           // track pseudoangular distance from the jet axis
//     float TagVarCSV_trackPtRatio[nMaxTrk_];                          // track transverse momentum, relative to the jet axis, normalized to its energy
//     float TagVarCSV_trackPParRatio[nMaxTrk_];                        // track parallel momentum, along the jet axis, normalized to its energy
//     float TagVarCSV_trackSip2dVal[nMaxTrk_];                         // track 2D signed impact parameter
//     float TagVarCSV_trackSip2dSig[nMaxTrk_];                         // track 2D signed impact parameter significance
//     float TagVarCSV_trackSip3dVal[nMaxTrk_];                         // track 3D signed impact parameter
//     float TagVarCSV_trackSip3dSig[nMaxTrk_];                         // track 3D signed impact parameter significance
//     float TagVarCSV_trackDecayLenVal[nMaxTrk_];                      // track decay length
//     float TagVarCSV_trackDecayLenSig[nMaxTrk_];                      // track decay length significance
//     float TagVarCSV_trackJetDistVal[nMaxTrk_];                       // minimum track approach distance to jet axis
//     float TagVarCSV_trackJetDistSig[nMaxTrk_];                       // minimum track approach distance to jet axis significance
//     float TagVarCSV_trackEtaRel[nMaxTrk_];                           // track pseudorapidity, relative to the jet axis

    void RegisterTree(TTree *tree, std::string name="")
    {
      if(name!="") name += ".";

      tree->Branch((name+"Jet_pt").c_str()          ,&Jet_pt          ,(name+"Jet_pt/F").c_str()        );
      tree->Branch((name+"Jet_eta").c_str()         ,&Jet_eta         ,(name+"Jet_eta/F").c_str()       );
      tree->Branch((name+"Jet_phi").c_str()         ,&Jet_phi         ,(name+"Jet_phi/F").c_str()       );
      tree->Branch((name+"Jet_mass").c_str()        ,&Jet_mass        ,(name+"Jet_mass/F").c_str()      );
      tree->Branch((name+"Jet_flavour").c_str()     ,&Jet_flavour     ,(name+"Jet_flavour/I").c_str()   );
      tree->Branch((name+"Jet_nbHadrons").c_str()   ,&Jet_nbHadrons   ,(name+"Jet_nbHadrons/I").c_str() );
      tree->Branch((name+"Jet_JP").c_str()          ,&Jet_JP          ,(name+"Jet_JP/F").c_str()        );
      tree->Branch((name+"Jet_JBP").c_str()         ,&Jet_JBP         ,(name+"Jet_JBP/F").c_str()       );
      tree->Branch((name+"Jet_CSV").c_str()         ,&Jet_CSV         ,(name+"Jet_CSV/F").c_str()       );
      tree->Branch((name+"Jet_CSVIVF").c_str()      ,&Jet_CSVIVF      ,(name+"Jet_CSVIVF/F").c_str()   );
      //--------------------------------------
      // CSV TaggingVariables
      //--------------------------------------
      tree->Branch((name+"TagVarCSV_trackJetPt").c_str()               ,&TagVarCSV_trackJetPt               ,(name+"TagVarCSV_trackJetPt/F").c_str()              );
      tree->Branch((name+"TagVarCSV_jetNTracks").c_str()               ,&TagVarCSV_jetNTracks               ,(name+"TagVarCSV_jetNTracks/F").c_str()              );
      tree->Branch((name+"TagVarCSV_jetNTracksEtaRel").c_str()         ,&TagVarCSV_jetNTracksEtaRel         ,(name+"TagVarCSV_jetNTracksEtaRel/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackSumJetEtRatio").c_str()       ,&TagVarCSV_trackSumJetEtRatio       ,(name+"TagVarCSV_trackSumJetEtRatio/F").c_str()      );
      tree->Branch((name+"TagVarCSV_trackSumJetDeltaR").c_str()        ,&TagVarCSV_trackSumJetDeltaR        ,(name+"TagVarCSV_trackSumJetDeltaR/F").c_str()       );
      tree->Branch((name+"TagVarCSV_trackSip2dValAboveCharm").c_str()  ,&TagVarCSV_trackSip2dValAboveCharm  ,(name+"TagVarCSV_trackSip2dValAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV_trackSip2dSigAboveCharm").c_str()  ,&TagVarCSV_trackSip2dSigAboveCharm  ,(name+"TagVarCSV_trackSip2dSigAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV_trackSip3dValAboveCharm").c_str()  ,&TagVarCSV_trackSip3dValAboveCharm  ,(name+"TagVarCSV_trackSip3dValAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV_trackSip3dSigAboveCharm").c_str()  ,&TagVarCSV_trackSip3dSigAboveCharm  ,(name+"TagVarCSV_trackSip3dSigAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV_vertexCategory").c_str()           ,&TagVarCSV_vertexCategory           ,(name+"TagVarCSV_vertexCategory/F").c_str()          );
      tree->Branch((name+"TagVarCSV_jetNSecondaryVertices").c_str()    ,&TagVarCSV_jetNSecondaryVertices    ,(name+"TagVarCSV_jetNSecondaryVertices/F").c_str()   );
      tree->Branch((name+"TagVarCSV_vertexMass").c_str()               ,&TagVarCSV_vertexMass               ,(name+"TagVarCSV_vertexMass/F").c_str()              );
      tree->Branch((name+"TagVarCSV_vertexNTracks").c_str()            ,&TagVarCSV_vertexNTracks            ,(name+"TagVarCSV_vertexNTracks/F").c_str()           );
      tree->Branch((name+"TagVarCSV_vertexEnergyRatio").c_str()        ,&TagVarCSV_vertexEnergyRatio        ,(name+"TagVarCSV_vertexEnergyRatio/F").c_str()       );
      tree->Branch((name+"TagVarCSV_vertexJetDeltaR").c_str()          ,&TagVarCSV_vertexJetDeltaR          ,(name+"TagVarCSV_vertexJetDeltaR/F").c_str()         );
      tree->Branch((name+"TagVarCSV_flightDistance2dVal").c_str()      ,&TagVarCSV_flightDistance2dVal      ,(name+"TagVarCSV_flightDistance2dVal/F").c_str()     );
      tree->Branch((name+"TagVarCSV_flightDistance2dSig").c_str()      ,&TagVarCSV_flightDistance2dSig      ,(name+"TagVarCSV_flightDistance2dSig/F").c_str()     );
      tree->Branch((name+"TagVarCSV_flightDistance3dVal").c_str()      ,&TagVarCSV_flightDistance3dVal      ,(name+"TagVarCSV_flightDistance3dVal/F").c_str()     );
      tree->Branch((name+"TagVarCSV_flightDistance3dSig").c_str()      ,&TagVarCSV_flightDistance3dSig      ,(name+"TagVarCSV_flightDistance3dSig/F").c_str()     );

//       tree->Branch((name+"nTrkTagVarCSV").c_str()               ,&nTrkTagVarCSV              ,(name+"nTrkTagVarCSV/I").c_str()                                      );
//       tree->Branch((name+"nTrkEtaRelTagVarCSV").c_str()         ,&nTrkEtaRelTagVarCSV        ,(name+"nTrkEtaRelTagVarCSV/I").c_str()                                );
//       tree->Branch((name+"TagVarCSV_trackMomentum").c_str()     ,&TagVarCSV_trackMomentum     ,(name+"TagVarCSV_trackMomentum["+name+"nTrkTagVarCSV]/F").c_str()     );
//       tree->Branch((name+"TagVarCSV_trackEta").c_str()          ,&TagVarCSV_trackEta          ,(name+"TagVarCSV_trackEta["+name+"nTrkTagVarCSV]/F").c_str()          );
//       tree->Branch((name+"TagVarCSV_trackPhi").c_str()          ,&TagVarCSV_trackPhi          ,(name+"TagVarCSV_trackPhi["+name+"nTrkTagVarCSV]/F").c_str()          );
//       tree->Branch((name+"TagVarCSV_trackPtRel").c_str()        ,&TagVarCSV_trackPtRel        ,(name+"TagVarCSV_trackPtRel["+name+"nTrkTagVarCSV]/F").c_str()        );
//       tree->Branch((name+"TagVarCSV_trackPPar").c_str()         ,&TagVarCSV_trackPPar         ,(name+"TagVarCSV_trackPPar["+name+"nTrkTagVarCSV]/F").c_str()         );
//       tree->Branch((name+"TagVarCSV_trackDeltaR").c_str()       ,&TagVarCSV_trackDeltaR       ,(name+"TagVarCSV_trackDeltaR["+name+"nTrkTagVarCSV]/F").c_str()       );
//       tree->Branch((name+"TagVarCSV_trackPtRatio").c_str()      ,&TagVarCSV_trackPtRatio      ,(name+"TagVarCSV_trackPtRatio["+name+"nTrkTagVarCSV]/F").c_str()      );
//       tree->Branch((name+"TagVarCSV_trackPParRatio").c_str()    ,&TagVarCSV_trackPParRatio    ,(name+"TagVarCSV_trackPParRatio["+name+"nTrkTagVarCSV]/F").c_str()    );
//       tree->Branch((name+"TagVarCSV_trackSip2dVal").c_str()     ,&TagVarCSV_trackSip2dVal     ,(name+"TagVarCSV_trackSip2dVal["+name+"nTrkTagVarCSV]/F").c_str()     );
//       tree->Branch((name+"TagVarCSV_trackSip2dSig").c_str()     ,&TagVarCSV_trackSip2dSig     ,(name+"TagVarCSV_trackSip2dSig["+name+"nTrkTagVarCSV]/F").c_str()     );
//       tree->Branch((name+"TagVarCSV_trackSip3dVal").c_str()     ,&TagVarCSV_trackSip3dVal     ,(name+"TagVarCSV_trackSip3dVal["+name+"nTrkTagVarCSV]/F").c_str()     );
//       tree->Branch((name+"TagVarCSV_trackSip3dSig").c_str()     ,&TagVarCSV_trackSip3dSig     ,(name+"TagVarCSV_trackSip3dSig["+name+"nTrkTagVarCSV]/F").c_str()     );
//       tree->Branch((name+"TagVarCSV_trackDecayLenVal").c_str()  ,&TagVarCSV_trackDecayLenVal  ,(name+"TagVarCSV_trackDecayLenVal["+name+"nTrkTagVarCSV]/F").c_str()  );
//       tree->Branch((name+"TagVarCSV_trackDecayLenSig").c_str()  ,&TagVarCSV_trackDecayLenSig  ,(name+"TagVarCSV_trackDecayLenSig["+name+"nTrkTagVarCSV]/F").c_str()  );
//       tree->Branch((name+"TagVarCSV_trackJetDistVal").c_str()   ,&TagVarCSV_trackJetDistVal   ,(name+"TagVarCSV_trackJetDistVal["+name+"nTrkTagVarCSV]/F").c_str()   );
//       tree->Branch((name+"TagVarCSV_trackJetDistSig").c_str()   ,&TagVarCSV_trackJetDistSig   ,(name+"TagVarCSV_trackJetDistSig["+name+"nTrkTagVarCSV]/F").c_str()   );
//       tree->Branch((name+"TagVarCSV_trackEtaRel").c_str()       ,&TagVarCSV_trackEtaRel       ,(name+"TagVarCSV_trackEtaRel["+name+"nTrkEtaRelTagVarCSV]/F").c_str() );
    }

    void ReadTree(TTree *tree, std::string name="")
    {
      if (name!="") name += ".";

      tree->SetBranchAddress((name+"Jet_pt").c_str()          ,&Jet_pt        );
      tree->SetBranchAddress((name+"Jet_eta").c_str()         ,&Jet_eta       );
      tree->SetBranchAddress((name+"Jet_phi").c_str()         ,&Jet_phi       );
      tree->SetBranchAddress((name+"Jet_mass").c_str()        ,&Jet_mass      );
      tree->SetBranchAddress((name+"Jet_flavour").c_str()     ,&Jet_flavour   );
      tree->SetBranchAddress((name+"Jet_nbHadrons").c_str()   ,&Jet_nbHadrons );
      tree->SetBranchAddress((name+"Jet_JP").c_str()          ,&Jet_JP        );
      tree->SetBranchAddress((name+"Jet_JBP").c_str()         ,&Jet_JBP       );
      tree->SetBranchAddress((name+"Jet_CSV").c_str()         ,&Jet_CSV       );
      tree->SetBranchAddress((name+"Jet_CSVIVF").c_str()      ,&Jet_CSVIVF   );
      //--------------------------------------
      // CSV TaggingVariables
      //--------------------------------------
      tree->SetBranchAddress((name+"TagVarCSV_trackJetPt").c_str()               ,&TagVarCSV_trackJetPt              );
      tree->SetBranchAddress((name+"TagVarCSV_jetNTracks").c_str()               ,&TagVarCSV_jetNTracks              );
      tree->SetBranchAddress((name+"TagVarCSV_jetNTracksEtaRel").c_str()         ,&TagVarCSV_jetNTracksEtaRel        );
      tree->SetBranchAddress((name+"TagVarCSV_trackSumJetEtRatio").c_str()       ,&TagVarCSV_trackSumJetEtRatio      );
      tree->SetBranchAddress((name+"TagVarCSV_trackSumJetDeltaR").c_str()        ,&TagVarCSV_trackSumJetDeltaR       );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dValAboveCharm").c_str()  ,&TagVarCSV_trackSip2dValAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSigAboveCharm").c_str()  ,&TagVarCSV_trackSip2dSigAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dValAboveCharm").c_str()  ,&TagVarCSV_trackSip3dValAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSigAboveCharm").c_str()  ,&TagVarCSV_trackSip3dSigAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV_vertexCategory").c_str()           ,&TagVarCSV_vertexCategory          );
      tree->SetBranchAddress((name+"TagVarCSV_jetNSecondaryVertices").c_str()    ,&TagVarCSV_jetNSecondaryVertices   );
      tree->SetBranchAddress((name+"TagVarCSV_vertexMass").c_str()               ,&TagVarCSV_vertexMass              );
      tree->SetBranchAddress((name+"TagVarCSV_vertexNTracks").c_str()            ,&TagVarCSV_vertexNTracks           );
      tree->SetBranchAddress((name+"TagVarCSV_vertexEnergyRatio").c_str()        ,&TagVarCSV_vertexEnergyRatio       );
      tree->SetBranchAddress((name+"TagVarCSV_vertexJetDeltaR").c_str()          ,&TagVarCSV_vertexJetDeltaR         );
      tree->SetBranchAddress((name+"TagVarCSV_flightDistance2dVal").c_str()      ,&TagVarCSV_flightDistance2dVal     );
      tree->SetBranchAddress((name+"TagVarCSV_flightDistance2dSig").c_str()      ,&TagVarCSV_flightDistance2dSig     );
      tree->SetBranchAddress((name+"TagVarCSV_flightDistance3dVal").c_str()      ,&TagVarCSV_flightDistance3dVal     );
      tree->SetBranchAddress((name+"TagVarCSV_flightDistance3dSig").c_str()      ,&TagVarCSV_flightDistance3dSig     );

//       tree->SetBranchAddress((name+"nTrkTagVarCSV").c_str()               ,&nTrkTagVarCSV             );
//       tree->SetBranchAddress((name+"nTrkEtaRelTagVarCSV").c_str()         ,&nTrkEtaRelTagVarCSV       );
//       tree->SetBranchAddress((name+"TagVarCSV_trackMomentum").c_str()     ,&TagVarCSV_trackMomentum    );
//       tree->SetBranchAddress((name+"TagVarCSV_trackEta").c_str()          ,&TagVarCSV_trackEta         );
//       tree->SetBranchAddress((name+"TagVarCSV_trackPhi").c_str()          ,&TagVarCSV_trackPhi         );
//       tree->SetBranchAddress((name+"TagVarCSV_trackPtRel").c_str()        ,&TagVarCSV_trackPtRel       );
//       tree->SetBranchAddress((name+"TagVarCSV_trackPPar").c_str()         ,&TagVarCSV_trackPPar        );
//       tree->SetBranchAddress((name+"TagVarCSV_trackDeltaR").c_str()       ,&TagVarCSV_trackDeltaR      );
//       tree->SetBranchAddress((name+"TagVarCSV_trackPtRatio").c_str()      ,&TagVarCSV_trackPtRatio     );
//       tree->SetBranchAddress((name+"TagVarCSV_trackPParRatio").c_str()    ,&TagVarCSV_trackPParRatio   );
//       tree->SetBranchAddress((name+"TagVarCSV_trackSip2dVal").c_str()     ,&TagVarCSV_trackSip2dVal    );
//       tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig").c_str()     ,&TagVarCSV_trackSip2dSig    );
//       tree->SetBranchAddress((name+"TagVarCSV_trackSip3dVal").c_str()     ,&TagVarCSV_trackSip3dVal    );
//       tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig").c_str()     ,&TagVarCSV_trackSip3dSig    );
//       tree->SetBranchAddress((name+"TagVarCSV_trackDecayLenVal").c_str()  ,&TagVarCSV_trackDecayLenVal );
//       tree->SetBranchAddress((name+"TagVarCSV_trackDecayLenSig").c_str()  ,&TagVarCSV_trackDecayLenSig );
//       tree->SetBranchAddress((name+"TagVarCSV_trackJetDistVal").c_str()   ,&TagVarCSV_trackJetDistVal  );
//       tree->SetBranchAddress((name+"TagVarCSV_trackJetDistSig").c_str()   ,&TagVarCSV_trackJetDistSig  );
//       tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel").c_str()       ,&TagVarCSV_trackEtaRel      );
    }
};

#endif