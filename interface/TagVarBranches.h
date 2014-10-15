#ifndef TagVarBranches_h
#define TagVarBranches_h

#include <TTree.h>


class TagVarBranches {

  public:
    //######################################
    // Fat jet variables
    //######################################
    float Jet_pt;
    float Jet_eta;
    float Jet_phi;
    float Jet_mass;
    float Jet_massGroomed;
    float Jet_flavour;
    float Jet_nbHadrons;
    float Jet_JP;
    float Jet_JBP;
    float Jet_CSV;
    float Jet_CSVIVF;
    float Jet_tau1;
    float Jet_tau2;

    // CSV TaggingVariables
    // per jet
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
    float TagVarCSV_trackSip2dSig_0;                      // highest track 2D signed IP of tracks belonging to a given jet   
    float TagVarCSV_trackSip2dSig_1;                      // second highest track 2D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip2dSig_2;                      // third highest track 2D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip2dSig_3;                      // fourth highest track 2D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip2dSig_4;                      // fifth highest track 2D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip2dSig_5;                      // sixth highest track 2D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip3dSig_0;                      // highest track 3D signed IP of tracks belonging to a given jet   
    float TagVarCSV_trackSip3dSig_1;                      // second highest track 3D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip3dSig_2;                      // third highest track 3D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip3dSig_3;                      // fourth highest track 3D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip3dSig_4;                      // fifth highest track 3D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip3dSig_5;                      // sixth highest track 3D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackPtRel_0;                         // highest track transverse momentum, relative to the jet axis
    float TagVarCSV_trackPtRel_1;                         // second highest track transverse momentum, relative to the jet axis
    float TagVarCSV_trackPtRel_2;                         // third highest track transverse momentum, relative to the jet axis
    float TagVarCSV_trackPtRel_3;                         // fourth highest track transverse momentum, relative to the jet axis
    float TagVarCSV_trackPtRel_4;                         // fifth highest track transverse momentum, relative to the jet axis
    float TagVarCSV_trackPtRel_5;                         // sixth highest track transverse momentum, relative to the jet axis
    // per jet per etaRel track
    float TagVarCSV_trackEtaRel_0;                        // lowest track eta relative to jet axis
    float TagVarCSV_trackEtaRel_1;                        // second lowest track eta relative to jet axis
    float TagVarCSV_trackEtaRel_2;                        // third lowest track eta relative to jet axis

    //######################################
    // Subjet1 variables
    //######################################
    float SubJet1_pt;
    float SubJet1_eta;
    float SubJet1_phi;
    float SubJet1_mass;
    float SubJet1_flavour;
    float SubJet1_nbHadrons;
    float SubJet1_JP;
    float SubJet1_JBP;
    float SubJet1_CSV;
    float SubJet1_CSVIVF;

    // CSV TaggingVariables
    // per jet
    float TagVarCSV1_jetNTracks;                           // tracks associated to jet
    float TagVarCSV1_jetNTracksEtaRel;                     // tracks associated to jet for which trackEtaRel is calculated
    float TagVarCSV1_trackSumJetEtRatio;                   // ratio of track sum transverse energy over jet energy
    float TagVarCSV1_trackSumJetDeltaR;                    // pseudoangular distance between jet axis and track fourvector sum
    float TagVarCSV1_trackSip2dValAboveCharm;              // track 2D signed impact parameter of first track lifting mass above charm
    float TagVarCSV1_trackSip2dSigAboveCharm;              // track 2D signed impact parameter significance of first track lifting mass above charm
    float TagVarCSV1_trackSip3dValAboveCharm;              // track 3D signed impact parameter of first track lifting mass above charm
    float TagVarCSV1_trackSip3dSigAboveCharm;              // track 3D signed impact parameter significance of first track lifting mass above charm
    float TagVarCSV1_vertexCategory;                       // category of secondary vertex (Reco, Pseudo, No)
    float TagVarCSV1_jetNSecondaryVertices;                // number of reconstructed possible secondary vertices in jet
    float TagVarCSV1_vertexMass;                           // mass of track sum at secondary vertex
    float TagVarCSV1_vertexNTracks;                        // number of tracks at secondary vertex
    float TagVarCSV1_vertexEnergyRatio;                    // ratio of energy at secondary vertex over total energy
    float TagVarCSV1_vertexJetDeltaR;                      // pseudoangular distance between jet axis and secondary vertex direction
    float TagVarCSV1_flightDistance2dVal;                  // transverse distance between primary and secondary vertex
    float TagVarCSV1_flightDistance2dSig;                  // transverse distance significance between primary and secondary vertex
    float TagVarCSV1_flightDistance3dVal;                  // distance between primary and secondary vertex
    float TagVarCSV1_flightDistance3dSig;                  // distance significance between primary and secondary vertex
    // per jet per etaRel track
    float TagVarCSV1_trackEtaRel_0;                        // lowest track eta relative to jet axis
    float TagVarCSV1_trackEtaRel_1;                        // second lowest track eta relative to jet axis
    float TagVarCSV1_trackEtaRel_2;                        // third lowest track eta relative to jet axis

    //######################################
    // Subjet2 variables
    //######################################
    float SubJet2_pt;
    float SubJet2_eta;
    float SubJet2_phi;
    float SubJet2_mass;
    float SubJet2_flavour;
    float SubJet2_nbHadrons;
    float SubJet2_JP;
    float SubJet2_JBP;
    float SubJet2_CSV;
    float SubJet2_CSVIVF;

    // CSV TaggingVariables
    // per jet
    float TagVarCSV2_jetNTracks;                           // tracks associated to jet
    float TagVarCSV2_jetNTracksEtaRel;                     // tracks associated to jet for which trackEtaRel is calculated
    float TagVarCSV2_trackSumJetEtRatio;                   // ratio of track sum transverse energy over jet energy
    float TagVarCSV2_trackSumJetDeltaR;                    // pseudoangular distance between jet axis and track fourvector sum
    float TagVarCSV2_trackSip2dValAboveCharm;              // track 2D signed impact parameter of first track lifting mass above charm
    float TagVarCSV2_trackSip2dSigAboveCharm;              // track 2D signed impact parameter significance of first track lifting mass above charm
    float TagVarCSV2_trackSip3dValAboveCharm;              // track 3D signed impact parameter of first track lifting mass above charm
    float TagVarCSV2_trackSip3dSigAboveCharm;              // track 3D signed impact parameter significance of first track lifting mass above charm
    float TagVarCSV2_vertexCategory;                       // category of secondary vertex (Reco, Pseudo, No)
    float TagVarCSV2_jetNSecondaryVertices;                // number of reconstructed possible secondary vertices in jet
    float TagVarCSV2_vertexMass;                           // mass of track sum at secondary vertex
    float TagVarCSV2_vertexNTracks;                        // number of tracks at secondary vertex
    float TagVarCSV2_vertexEnergyRatio;                    // ratio of energy at secondary vertex over total energy
    float TagVarCSV2_vertexJetDeltaR;                      // pseudoangular distance between jet axis and secondary vertex direction
    float TagVarCSV2_flightDistance2dVal;                  // transverse distance between primary and secondary vertex
    float TagVarCSV2_flightDistance2dSig;                  // transverse distance significance between primary and secondary vertex
    float TagVarCSV2_flightDistance3dVal;                  // distance between primary and secondary vertex
    float TagVarCSV2_flightDistance3dSig;                  // distance significance between primary and secondary vertex
    // per jet per etaRel track
    float TagVarCSV2_trackEtaRel_0;                        // lowest track eta relative to jet axis
    float TagVarCSV2_trackEtaRel_1;                        // second lowest track eta relative to jet axis
    float TagVarCSV2_trackEtaRel_2;                        // third lowest track eta relative to jet axis

    void RegisterTree(TTree *tree, std::string name="")
    {
      if(name!="") name += ".";
      //######################################
      // Fat jet variables
      //######################################
      tree->Branch((name+"Jet_pt").c_str()          ,&Jet_pt          ,(name+"Jet_pt/F").c_str()          );
      tree->Branch((name+"Jet_eta").c_str()         ,&Jet_eta         ,(name+"Jet_eta/F").c_str()         );
      tree->Branch((name+"Jet_phi").c_str()         ,&Jet_phi         ,(name+"Jet_phi/F").c_str()         );
      tree->Branch((name+"Jet_mass").c_str()        ,&Jet_mass        ,(name+"Jet_mass/F").c_str()        );
      tree->Branch((name+"Jet_massGroomed").c_str() ,&Jet_massGroomed ,(name+"Jet_massGroomed/F").c_str() );
      tree->Branch((name+"Jet_flavour").c_str()     ,&Jet_flavour     ,(name+"Jet_flavour/F").c_str()     );
      tree->Branch((name+"Jet_nbHadrons").c_str()   ,&Jet_nbHadrons   ,(name+"Jet_nbHadrons/F").c_str()   );
      tree->Branch((name+"Jet_JP").c_str()          ,&Jet_JP          ,(name+"Jet_JP/F").c_str()          );
      tree->Branch((name+"Jet_JBP").c_str()         ,&Jet_JBP         ,(name+"Jet_JBP/F").c_str()         );
      tree->Branch((name+"Jet_CSV").c_str()         ,&Jet_CSV         ,(name+"Jet_CSV/F").c_str()         );
      tree->Branch((name+"Jet_CSVIVF").c_str()      ,&Jet_CSVIVF      ,(name+"Jet_CSVIVF/F").c_str()      );
      tree->Branch((name+"Jet_tau1").c_str()        ,&Jet_tau1        ,(name+"Jet_tau1/F").c_str()        );
      tree->Branch((name+"Jet_tau2").c_str()        ,&Jet_tau2        ,(name+"Jet_tau2/F").c_str()        );
      //--------------------------------------
      // CSV TaggingVariables
      //--------------------------------------
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
      tree->Branch((name+"TagVarCSV_trackSip2dSig_0").c_str()          ,&TagVarCSV_trackSip2dSig_0          ,(name+"TagVarCSV_trackSip2dSig_0/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip2dSig_1").c_str()          ,&TagVarCSV_trackSip2dSig_1          ,(name+"TagVarCSV_trackSip2dSig_1/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip2dSig_2").c_str()          ,&TagVarCSV_trackSip2dSig_2          ,(name+"TagVarCSV_trackSip2dSig_2/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip2dSig_3").c_str()          ,&TagVarCSV_trackSip2dSig_3          ,(name+"TagVarCSV_trackSip2dSig_3/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip2dSig_4").c_str()          ,&TagVarCSV_trackSip2dSig_4          ,(name+"TagVarCSV_trackSip2dSig_4/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip2dSig_5").c_str()          ,&TagVarCSV_trackSip2dSig_5          ,(name+"TagVarCSV_trackSip2dSig_5/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_0").c_str()          ,&TagVarCSV_trackSip3dSig_0          ,(name+"TagVarCSV_trackSip3dSig_0/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_1").c_str()          ,&TagVarCSV_trackSip3dSig_1          ,(name+"TagVarCSV_trackSip3dSig_1/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_2").c_str()          ,&TagVarCSV_trackSip3dSig_2          ,(name+"TagVarCSV_trackSip3dSig_2/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_3").c_str()          ,&TagVarCSV_trackSip3dSig_3          ,(name+"TagVarCSV_trackSip3dSig_3/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_4").c_str()          ,&TagVarCSV_trackSip3dSig_4          ,(name+"TagVarCSV_trackSip3dSig_4/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_5").c_str()          ,&TagVarCSV_trackSip3dSig_5          ,(name+"TagVarCSV_trackSip3dSig_5/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackPtRel_0").c_str()             ,&TagVarCSV_trackPtRel_0             ,(name+"TagVarCSV_trackPtRel_0/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackPtRel_1").c_str()             ,&TagVarCSV_trackPtRel_1             ,(name+"TagVarCSV_trackPtRel_1/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackPtRel_2").c_str()             ,&TagVarCSV_trackPtRel_2             ,(name+"TagVarCSV_trackPtRel_2/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackPtRel_3").c_str()             ,&TagVarCSV_trackPtRel_3             ,(name+"TagVarCSV_trackPtRel_3/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackPtRel_4").c_str()             ,&TagVarCSV_trackPtRel_4             ,(name+"TagVarCSV_trackPtRel_4/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackPtRel_5").c_str()             ,&TagVarCSV_trackPtRel_5             ,(name+"TagVarCSV_trackPtRel_5/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackEtaRel_0").c_str()            ,&TagVarCSV_trackEtaRel_0            ,(name+"TagVarCSV_trackEtaRel_0/F").c_str()           );
      tree->Branch((name+"TagVarCSV_trackEtaRel_1").c_str()            ,&TagVarCSV_trackEtaRel_1            ,(name+"TagVarCSV_trackEtaRel_1/F").c_str()           );
      tree->Branch((name+"TagVarCSV_trackEtaRel_2").c_str()            ,&TagVarCSV_trackEtaRel_2            ,(name+"TagVarCSV_trackEtaRel_2/F").c_str()           );
      //######################################
      // Subjet1 variables
      //######################################
      tree->Branch((name+"SubJet1_pt").c_str()          ,&SubJet1_pt          ,(name+"SubJet1_pt/F").c_str()          );
      tree->Branch((name+"SubJet1_eta").c_str()         ,&SubJet1_eta         ,(name+"SubJet1_eta/F").c_str()         );
      tree->Branch((name+"SubJet1_phi").c_str()         ,&SubJet1_phi         ,(name+"SubJet1_phi/F").c_str()         );
      tree->Branch((name+"SubJet1_mass").c_str()        ,&SubJet1_mass        ,(name+"SubJet1_mass/F").c_str()        );
      tree->Branch((name+"SubJet1_flavour").c_str()     ,&SubJet1_flavour     ,(name+"SubJet1_flavour/F").c_str()     );
      tree->Branch((name+"SubJet1_nbHadrons").c_str()   ,&SubJet1_nbHadrons   ,(name+"SubJet1_nbHadrons/F").c_str()   );
      tree->Branch((name+"SubJet1_JP").c_str()          ,&SubJet1_JP          ,(name+"SubJet1_JP/F").c_str()          );
      tree->Branch((name+"SubJet1_JBP").c_str()         ,&SubJet1_JBP         ,(name+"SubJet1_JBP/F").c_str()         );
      tree->Branch((name+"SubJet1_CSV").c_str()         ,&SubJet1_CSV         ,(name+"SubJet1_CSV/F").c_str()         );
      tree->Branch((name+"SubJet1_CSVIVF").c_str()      ,&SubJet1_CSVIVF      ,(name+"SubJet1_CSVIVF/F").c_str()      );
      //--------------------------------------
      // CSV TaggingVariables
      //--------------------------------------
      tree->Branch((name+"TagVarCSV1_jetNTracks").c_str()               ,&TagVarCSV1_jetNTracks               ,(name+"TagVarCSV1_jetNTracks/F").c_str()              );
      tree->Branch((name+"TagVarCSV1_jetNTracksEtaRel").c_str()         ,&TagVarCSV1_jetNTracksEtaRel         ,(name+"TagVarCSV1_jetNTracksEtaRel/F").c_str()        );
      tree->Branch((name+"TagVarCSV1_trackSumJetEtRatio").c_str()       ,&TagVarCSV1_trackSumJetEtRatio       ,(name+"TagVarCSV1_trackSumJetEtRatio/F").c_str()      );
      tree->Branch((name+"TagVarCSV1_trackSumJetDeltaR").c_str()        ,&TagVarCSV1_trackSumJetDeltaR        ,(name+"TagVarCSV1_trackSumJetDeltaR/F").c_str()       );
      tree->Branch((name+"TagVarCSV1_trackSip2dValAboveCharm").c_str()  ,&TagVarCSV1_trackSip2dValAboveCharm  ,(name+"TagVarCSV1_trackSip2dValAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV1_trackSip2dSigAboveCharm").c_str()  ,&TagVarCSV1_trackSip2dSigAboveCharm  ,(name+"TagVarCSV1_trackSip2dSigAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV1_trackSip3dValAboveCharm").c_str()  ,&TagVarCSV1_trackSip3dValAboveCharm  ,(name+"TagVarCSV1_trackSip3dValAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV1_trackSip3dSigAboveCharm").c_str()  ,&TagVarCSV1_trackSip3dSigAboveCharm  ,(name+"TagVarCSV1_trackSip3dSigAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV1_vertexCategory").c_str()           ,&TagVarCSV1_vertexCategory           ,(name+"TagVarCSV1_vertexCategory/F").c_str()          );
      tree->Branch((name+"TagVarCSV1_jetNSecondaryVertices").c_str()    ,&TagVarCSV1_jetNSecondaryVertices    ,(name+"TagVarCSV1_jetNSecondaryVertices/F").c_str()   );
      tree->Branch((name+"TagVarCSV1_vertexMass").c_str()               ,&TagVarCSV1_vertexMass               ,(name+"TagVarCSV1_vertexMass/F").c_str()              );
      tree->Branch((name+"TagVarCSV1_vertexNTracks").c_str()            ,&TagVarCSV1_vertexNTracks            ,(name+"TagVarCSV1_vertexNTracks/F").c_str()           );
      tree->Branch((name+"TagVarCSV1_vertexEnergyRatio").c_str()        ,&TagVarCSV1_vertexEnergyRatio        ,(name+"TagVarCSV1_vertexEnergyRatio/F").c_str()       );
      tree->Branch((name+"TagVarCSV1_vertexJetDeltaR").c_str()          ,&TagVarCSV1_vertexJetDeltaR          ,(name+"TagVarCSV1_vertexJetDeltaR/F").c_str()         );
      tree->Branch((name+"TagVarCSV1_flightDistance2dVal").c_str()      ,&TagVarCSV1_flightDistance2dVal      ,(name+"TagVarCSV1_flightDistance2dVal/F").c_str()     );
      tree->Branch((name+"TagVarCSV1_flightDistance2dSig").c_str()      ,&TagVarCSV1_flightDistance2dSig      ,(name+"TagVarCSV1_flightDistance2dSig/F").c_str()     );
      tree->Branch((name+"TagVarCSV1_flightDistance3dVal").c_str()      ,&TagVarCSV1_flightDistance3dVal      ,(name+"TagVarCSV1_flightDistance3dVal/F").c_str()     );
      tree->Branch((name+"TagVarCSV1_flightDistance3dSig").c_str()      ,&TagVarCSV1_flightDistance3dSig      ,(name+"TagVarCSV1_flightDistance3dSig/F").c_str()     );
      tree->Branch((name+"TagVarCSV1_trackEtaRel_0").c_str()            ,&TagVarCSV1_trackEtaRel_0            ,(name+"TagVarCSV1_trackEtaRel_0/F").c_str()           );
      tree->Branch((name+"TagVarCSV1_trackEtaRel_1").c_str()            ,&TagVarCSV1_trackEtaRel_1            ,(name+"TagVarCSV1_trackEtaRel_1/F").c_str()           );
      tree->Branch((name+"TagVarCSV1_trackEtaRel_2").c_str()            ,&TagVarCSV1_trackEtaRel_2            ,(name+"TagVarCSV1_trackEtaRel_2/F").c_str()           );
      //######################################
      // Subjet2 variables
      //######################################
      tree->Branch((name+"SubJet2_pt").c_str()          ,&SubJet2_pt          ,(name+"SubJet2_pt/F").c_str()          );
      tree->Branch((name+"SubJet2_eta").c_str()         ,&SubJet2_eta         ,(name+"SubJet2_eta/F").c_str()         );
      tree->Branch((name+"SubJet2_phi").c_str()         ,&SubJet2_phi         ,(name+"SubJet2_phi/F").c_str()         );
      tree->Branch((name+"SubJet2_mass").c_str()        ,&SubJet2_mass        ,(name+"SubJet2_mass/F").c_str()        );
      tree->Branch((name+"SubJet2_flavour").c_str()     ,&SubJet2_flavour     ,(name+"SubJet2_flavour/F").c_str()     );
      tree->Branch((name+"SubJet2_nbHadrons").c_str()   ,&SubJet2_nbHadrons   ,(name+"SubJet2_nbHadrons/F").c_str()   );
      tree->Branch((name+"SubJet2_JP").c_str()          ,&SubJet2_JP          ,(name+"SubJet2_JP/F").c_str()          );
      tree->Branch((name+"SubJet2_JBP").c_str()         ,&SubJet2_JBP         ,(name+"SubJet2_JBP/F").c_str()         );
      tree->Branch((name+"SubJet2_CSV").c_str()         ,&SubJet2_CSV         ,(name+"SubJet2_CSV/F").c_str()         );
      tree->Branch((name+"SubJet2_CSVIVF").c_str()      ,&SubJet2_CSVIVF      ,(name+"SubJet2_CSVIVF/F").c_str()      );
      //--------------------------------------
      // CSV TaggingVariables
      //--------------------------------------
      tree->Branch((name+"TagVarCSV2_jetNTracks").c_str()               ,&TagVarCSV2_jetNTracks               ,(name+"TagVarCSV2_jetNTracks/F").c_str()              );
      tree->Branch((name+"TagVarCSV2_jetNTracksEtaRel").c_str()         ,&TagVarCSV2_jetNTracksEtaRel         ,(name+"TagVarCSV2_jetNTracksEtaRel/F").c_str()        );
      tree->Branch((name+"TagVarCSV2_trackSumJetEtRatio").c_str()       ,&TagVarCSV2_trackSumJetEtRatio       ,(name+"TagVarCSV2_trackSumJetEtRatio/F").c_str()      );
      tree->Branch((name+"TagVarCSV2_trackSumJetDeltaR").c_str()        ,&TagVarCSV2_trackSumJetDeltaR        ,(name+"TagVarCSV2_trackSumJetDeltaR/F").c_str()       );
      tree->Branch((name+"TagVarCSV2_trackSip2dValAboveCharm").c_str()  ,&TagVarCSV2_trackSip2dValAboveCharm  ,(name+"TagVarCSV2_trackSip2dValAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV2_trackSip2dSigAboveCharm").c_str()  ,&TagVarCSV2_trackSip2dSigAboveCharm  ,(name+"TagVarCSV2_trackSip2dSigAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV2_trackSip3dValAboveCharm").c_str()  ,&TagVarCSV2_trackSip3dValAboveCharm  ,(name+"TagVarCSV2_trackSip3dValAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV2_trackSip3dSigAboveCharm").c_str()  ,&TagVarCSV2_trackSip3dSigAboveCharm  ,(name+"TagVarCSV2_trackSip3dSigAboveCharm/F").c_str() );
      tree->Branch((name+"TagVarCSV2_vertexCategory").c_str()           ,&TagVarCSV2_vertexCategory           ,(name+"TagVarCSV2_vertexCategory/F").c_str()          );
      tree->Branch((name+"TagVarCSV2_jetNSecondaryVertices").c_str()    ,&TagVarCSV2_jetNSecondaryVertices    ,(name+"TagVarCSV2_jetNSecondaryVertices/F").c_str()   );
      tree->Branch((name+"TagVarCSV2_vertexMass").c_str()               ,&TagVarCSV2_vertexMass               ,(name+"TagVarCSV2_vertexMass/F").c_str()              );
      tree->Branch((name+"TagVarCSV2_vertexNTracks").c_str()            ,&TagVarCSV2_vertexNTracks            ,(name+"TagVarCSV2_vertexNTracks/F").c_str()           );
      tree->Branch((name+"TagVarCSV2_vertexEnergyRatio").c_str()        ,&TagVarCSV2_vertexEnergyRatio        ,(name+"TagVarCSV2_vertexEnergyRatio/F").c_str()       );
      tree->Branch((name+"TagVarCSV2_vertexJetDeltaR").c_str()          ,&TagVarCSV2_vertexJetDeltaR          ,(name+"TagVarCSV2_vertexJetDeltaR/F").c_str()         );
      tree->Branch((name+"TagVarCSV2_flightDistance2dVal").c_str()      ,&TagVarCSV2_flightDistance2dVal      ,(name+"TagVarCSV2_flightDistance2dVal/F").c_str()     );
      tree->Branch((name+"TagVarCSV2_flightDistance2dSig").c_str()      ,&TagVarCSV2_flightDistance2dSig      ,(name+"TagVarCSV2_flightDistance2dSig/F").c_str()     );
      tree->Branch((name+"TagVarCSV2_flightDistance3dVal").c_str()      ,&TagVarCSV2_flightDistance3dVal      ,(name+"TagVarCSV2_flightDistance3dVal/F").c_str()     );
      tree->Branch((name+"TagVarCSV2_flightDistance3dSig").c_str()      ,&TagVarCSV2_flightDistance3dSig      ,(name+"TagVarCSV2_flightDistance3dSig/F").c_str()     );
      tree->Branch((name+"TagVarCSV2_trackEtaRel_0").c_str()            ,&TagVarCSV2_trackEtaRel_0            ,(name+"TagVarCSV2_trackEtaRel_0/F").c_str()           );
      tree->Branch((name+"TagVarCSV2_trackEtaRel_1").c_str()            ,&TagVarCSV2_trackEtaRel_1            ,(name+"TagVarCSV2_trackEtaRel_1/F").c_str()           );
      tree->Branch((name+"TagVarCSV2_trackEtaRel_2").c_str()            ,&TagVarCSV2_trackEtaRel_2            ,(name+"TagVarCSV2_trackEtaRel_2/F").c_str()           );
    }

    void ReadTree(TTree *tree, std::string name="")
    {
      if (name!="") name += ".";
      //######################################
      // Fat jet variables
      //######################################
      tree->SetBranchAddress((name+"Jet_pt").c_str()          ,&Jet_pt          );
      tree->SetBranchAddress((name+"Jet_eta").c_str()         ,&Jet_eta         );
      tree->SetBranchAddress((name+"Jet_phi").c_str()         ,&Jet_phi         );
      tree->SetBranchAddress((name+"Jet_mass").c_str()        ,&Jet_mass        );
      tree->SetBranchAddress((name+"Jet_massGroomed").c_str() ,&Jet_massGroomed );
      tree->SetBranchAddress((name+"Jet_flavour").c_str()     ,&Jet_flavour     );
      tree->SetBranchAddress((name+"Jet_nbHadrons").c_str()   ,&Jet_nbHadrons   );
      tree->SetBranchAddress((name+"Jet_JP").c_str()          ,&Jet_JP          );
      tree->SetBranchAddress((name+"Jet_JBP").c_str()         ,&Jet_JBP         );
      tree->SetBranchAddress((name+"Jet_CSV").c_str()         ,&Jet_CSV         );
      tree->SetBranchAddress((name+"Jet_CSVIVF").c_str()      ,&Jet_CSVIVF      );
      tree->SetBranchAddress((name+"Jet_tau1").c_str()        ,&Jet_tau1        );
      tree->SetBranchAddress((name+"Jet_tau2").c_str()        ,&Jet_tau2        );
      //--------------------------------------
      // CSV TaggingVariables
      //--------------------------------------
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
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig_0").c_str()          ,&TagVarCSV_trackSip2dSig_0         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig_1").c_str()          ,&TagVarCSV_trackSip2dSig_1         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig_2").c_str()          ,&TagVarCSV_trackSip2dSig_2         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig_3").c_str()          ,&TagVarCSV_trackSip2dSig_3         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig_4").c_str()          ,&TagVarCSV_trackSip2dSig_4         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig_5").c_str()          ,&TagVarCSV_trackSip2dSig_5         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_0").c_str()          ,&TagVarCSV_trackSip3dSig_0         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_1").c_str()          ,&TagVarCSV_trackSip3dSig_1         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_2").c_str()          ,&TagVarCSV_trackSip3dSig_2         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_3").c_str()          ,&TagVarCSV_trackSip3dSig_3         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_4").c_str()          ,&TagVarCSV_trackSip3dSig_4         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_5").c_str()          ,&TagVarCSV_trackSip3dSig_5         );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_0").c_str()             ,&TagVarCSV_trackPtRel_0            );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_1").c_str()             ,&TagVarCSV_trackPtRel_1            );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_2").c_str()             ,&TagVarCSV_trackPtRel_2            );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_3").c_str()             ,&TagVarCSV_trackPtRel_3            );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_4").c_str()             ,&TagVarCSV_trackPtRel_4            );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_5").c_str()             ,&TagVarCSV_trackPtRel_5            );
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_0").c_str()            ,&TagVarCSV_trackEtaRel_0           );
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_1").c_str()            ,&TagVarCSV_trackEtaRel_1           );
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_2").c_str()            ,&TagVarCSV_trackEtaRel_2           );
      //######################################
      // Subjet1 variables
      //######################################
      tree->SetBranchAddress((name+"SubJet1_pt").c_str()          ,&SubJet1_pt          );
      tree->SetBranchAddress((name+"SubJet1_eta").c_str()         ,&SubJet1_eta         );
      tree->SetBranchAddress((name+"SubJet1_phi").c_str()         ,&SubJet1_phi         );
      tree->SetBranchAddress((name+"SubJet1_mass").c_str()        ,&SubJet1_mass        );
      tree->SetBranchAddress((name+"SubJet1_flavour").c_str()     ,&SubJet1_flavour     );
      tree->SetBranchAddress((name+"SubJet1_nbHadrons").c_str()   ,&SubJet1_nbHadrons   );
      tree->SetBranchAddress((name+"SubJet1_JP").c_str()          ,&SubJet1_JP          );
      tree->SetBranchAddress((name+"SubJet1_JBP").c_str()         ,&SubJet1_JBP         );
      tree->SetBranchAddress((name+"SubJet1_CSV").c_str()         ,&SubJet1_CSV         );
      tree->SetBranchAddress((name+"SubJet1_CSVIVF").c_str()      ,&SubJet1_CSVIVF      );
      //--------------------------------------
      // CSV TaggingVariables
      //--------------------------------------
      tree->SetBranchAddress((name+"TagVarCSV1_jetNTracks").c_str()               ,&TagVarCSV1_jetNTracks              );
      tree->SetBranchAddress((name+"TagVarCSV1_jetNTracksEtaRel").c_str()         ,&TagVarCSV1_jetNTracksEtaRel        );
      tree->SetBranchAddress((name+"TagVarCSV1_trackSumJetEtRatio").c_str()       ,&TagVarCSV1_trackSumJetEtRatio      );
      tree->SetBranchAddress((name+"TagVarCSV1_trackSumJetDeltaR").c_str()        ,&TagVarCSV1_trackSumJetDeltaR       );
      tree->SetBranchAddress((name+"TagVarCSV1_trackSip2dValAboveCharm").c_str()  ,&TagVarCSV1_trackSip2dValAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV1_trackSip2dSigAboveCharm").c_str()  ,&TagVarCSV1_trackSip2dSigAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV1_trackSip3dValAboveCharm").c_str()  ,&TagVarCSV1_trackSip3dValAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV1_trackSip3dSigAboveCharm").c_str()  ,&TagVarCSV1_trackSip3dSigAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV1_vertexCategory").c_str()           ,&TagVarCSV1_vertexCategory          );
      tree->SetBranchAddress((name+"TagVarCSV1_jetNSecondaryVertices").c_str()    ,&TagVarCSV1_jetNSecondaryVertices   );
      tree->SetBranchAddress((name+"TagVarCSV1_vertexMass").c_str()               ,&TagVarCSV1_vertexMass              );
      tree->SetBranchAddress((name+"TagVarCSV1_vertexNTracks").c_str()            ,&TagVarCSV1_vertexNTracks           );
      tree->SetBranchAddress((name+"TagVarCSV1_vertexEnergyRatio").c_str()        ,&TagVarCSV1_vertexEnergyRatio       );
      tree->SetBranchAddress((name+"TagVarCSV1_vertexJetDeltaR").c_str()          ,&TagVarCSV1_vertexJetDeltaR         );
      tree->SetBranchAddress((name+"TagVarCSV1_flightDistance2dVal").c_str()      ,&TagVarCSV1_flightDistance2dVal     );
      tree->SetBranchAddress((name+"TagVarCSV1_flightDistance2dSig").c_str()      ,&TagVarCSV1_flightDistance2dSig     );
      tree->SetBranchAddress((name+"TagVarCSV1_flightDistance3dVal").c_str()      ,&TagVarCSV1_flightDistance3dVal     );
      tree->SetBranchAddress((name+"TagVarCSV1_flightDistance3dSig").c_str()      ,&TagVarCSV1_flightDistance3dSig     );
      tree->SetBranchAddress((name+"TagVarCSV1_trackEtaRel_0").c_str()            ,&TagVarCSV1_trackEtaRel_0           );
      tree->SetBranchAddress((name+"TagVarCSV1_trackEtaRel_1").c_str()            ,&TagVarCSV1_trackEtaRel_1           );
      tree->SetBranchAddress((name+"TagVarCSV1_trackEtaRel_2").c_str()            ,&TagVarCSV1_trackEtaRel_2           );
      //######################################
      // Subjet2 variables
      //######################################
      tree->SetBranchAddress((name+"SubJet2_pt").c_str()          ,&SubJet2_pt          );
      tree->SetBranchAddress((name+"SubJet2_eta").c_str()         ,&SubJet2_eta         );
      tree->SetBranchAddress((name+"SubJet2_phi").c_str()         ,&SubJet2_phi         );
      tree->SetBranchAddress((name+"SubJet2_mass").c_str()        ,&SubJet2_mass        );
      tree->SetBranchAddress((name+"SubJet2_flavour").c_str()     ,&SubJet2_flavour     );
      tree->SetBranchAddress((name+"SubJet2_nbHadrons").c_str()   ,&SubJet2_nbHadrons   );
      tree->SetBranchAddress((name+"SubJet2_JP").c_str()          ,&SubJet2_JP          );
      tree->SetBranchAddress((name+"SubJet2_JBP").c_str()         ,&SubJet2_JBP         );
      tree->SetBranchAddress((name+"SubJet2_CSV").c_str()         ,&SubJet2_CSV         );
      tree->SetBranchAddress((name+"SubJet2_CSVIVF").c_str()      ,&SubJet2_CSVIVF      );
      //--------------------------------------
      // CSV TaggingVariables
      //--------------------------------------
      tree->SetBranchAddress((name+"TagVarCSV2_jetNTracks").c_str()               ,&TagVarCSV2_jetNTracks              );
      tree->SetBranchAddress((name+"TagVarCSV2_jetNTracksEtaRel").c_str()         ,&TagVarCSV2_jetNTracksEtaRel        );
      tree->SetBranchAddress((name+"TagVarCSV2_trackSumJetEtRatio").c_str()       ,&TagVarCSV2_trackSumJetEtRatio      );
      tree->SetBranchAddress((name+"TagVarCSV2_trackSumJetDeltaR").c_str()        ,&TagVarCSV2_trackSumJetDeltaR       );
      tree->SetBranchAddress((name+"TagVarCSV2_trackSip2dValAboveCharm").c_str()  ,&TagVarCSV2_trackSip2dValAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV2_trackSip2dSigAboveCharm").c_str()  ,&TagVarCSV2_trackSip2dSigAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV2_trackSip3dValAboveCharm").c_str()  ,&TagVarCSV2_trackSip3dValAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV2_trackSip3dSigAboveCharm").c_str()  ,&TagVarCSV2_trackSip3dSigAboveCharm );
      tree->SetBranchAddress((name+"TagVarCSV2_vertexCategory").c_str()           ,&TagVarCSV2_vertexCategory          );
      tree->SetBranchAddress((name+"TagVarCSV2_jetNSecondaryVertices").c_str()    ,&TagVarCSV2_jetNSecondaryVertices   );
      tree->SetBranchAddress((name+"TagVarCSV2_vertexMass").c_str()               ,&TagVarCSV2_vertexMass              );
      tree->SetBranchAddress((name+"TagVarCSV2_vertexNTracks").c_str()            ,&TagVarCSV2_vertexNTracks           );
      tree->SetBranchAddress((name+"TagVarCSV2_vertexEnergyRatio").c_str()        ,&TagVarCSV2_vertexEnergyRatio       );
      tree->SetBranchAddress((name+"TagVarCSV2_vertexJetDeltaR").c_str()          ,&TagVarCSV2_vertexJetDeltaR         );
      tree->SetBranchAddress((name+"TagVarCSV2_flightDistance2dVal").c_str()      ,&TagVarCSV2_flightDistance2dVal     );
      tree->SetBranchAddress((name+"TagVarCSV2_flightDistance2dSig").c_str()      ,&TagVarCSV2_flightDistance2dSig     );
      tree->SetBranchAddress((name+"TagVarCSV2_flightDistance3dVal").c_str()      ,&TagVarCSV2_flightDistance3dVal     );
      tree->SetBranchAddress((name+"TagVarCSV2_flightDistance3dSig").c_str()      ,&TagVarCSV2_flightDistance3dSig     );
      tree->SetBranchAddress((name+"TagVarCSV2_trackEtaRel_0").c_str()            ,&TagVarCSV2_trackEtaRel_0           );
      tree->SetBranchAddress((name+"TagVarCSV2_trackEtaRel_1").c_str()            ,&TagVarCSV2_trackEtaRel_1           );
      tree->SetBranchAddress((name+"TagVarCSV2_trackEtaRel_2").c_str()            ,&TagVarCSV2_trackEtaRel_2           );
    }
};

#endif