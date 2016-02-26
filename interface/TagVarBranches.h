#ifndef TagVarBranches_h
#define TagVarBranches_h

#include <TTree.h>


class TagVarBranches {

  public:

    float Jet_pt;
    float Jet_genpt;
    float Jet_eta;
    float Jet_phi;
    float Jet_mass;
    float Jet_flavour;
    float Jet_nbHadrons;
    float Jet_JP;
    float Jet_JBP;
    float Jet_CSV;
    float Jet_CSVIVF;

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
    float TagVarCSV_trackSip3dSig_0;                      // highest track 3D signed IP of tracks belonging to a given jet   
    float TagVarCSV_trackSip3dSig_1;                      // second highest track 3D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip3dSig_2;                      // third highest track 3D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip3dSig_3;                      // fourth highest track 3D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackPtRel_0;                         // highest track transverse momentum, relative to the jet axis
    float TagVarCSV_trackPtRel_1;                         // second highest track transverse momentum, relative to the jet axis
    float TagVarCSV_trackPtRel_2;                         // third highest track transverse momentum, relative to the jet axis
    float TagVarCSV_trackPtRel_3;                         // fourth highest track transverse momentum, relative to the jet axis
    float TagVarCSV_trackDeltaR_0;
    float TagVarCSV_trackDeltaR_1;
    float TagVarCSV_trackDeltaR_2;
    float TagVarCSV_trackDeltaR_3;
    float TagVarCSV_trackPtRatio_0;
    float TagVarCSV_trackPtRatio_1;
    float TagVarCSV_trackPtRatio_2;
    float TagVarCSV_trackPtRatio_3;
    float TagVarCSV_trackJetDist_0;
    float TagVarCSV_trackJetDist_1;
    float TagVarCSV_trackJetDist_2;
    float TagVarCSV_trackJetDist_3;
    float TagVarCSV_trackDecayLenVal_0;
    float TagVarCSV_trackDecayLenVal_1;
    float TagVarCSV_trackDecayLenVal_2;
    float TagVarCSV_trackDecayLenVal_3;

    // per jet per etaRel track
    float TagVarCSV_trackEtaRel_0;                        // lowest track eta relative to jet axis
    float TagVarCSV_trackEtaRel_1;                        // second lowest track eta relative to jet axis
    float TagVarCSV_trackEtaRel_2;                        // third lowest track eta relative to jet axis
    float TagVarCSV_trackEtaRel_3;                        // fourth lowest track eta relative to jet axis

    void RegisterTree(TTree *tree, std::string name="")
    {
      if(name!="") name += ".";

      tree->Branch((name+"Jet_pt").c_str()          ,&Jet_pt          ,(name+"Jet_pt/F").c_str()        );
      tree->Branch((name+"Jet_genpt").c_str()          ,&Jet_genpt          ,(name+"Jet_genpt/F").c_str()        );
      tree->Branch((name+"Jet_eta").c_str()         ,&Jet_eta         ,(name+"Jet_eta/F").c_str()       );
      tree->Branch((name+"Jet_phi").c_str()         ,&Jet_phi         ,(name+"Jet_phi/F").c_str()       );
      tree->Branch((name+"Jet_mass").c_str()        ,&Jet_mass        ,(name+"Jet_mass/F").c_str()      );
      tree->Branch((name+"Jet_flavour").c_str()     ,&Jet_flavour     ,(name+"Jet_flavour/F").c_str()   );
      tree->Branch((name+"Jet_nbHadrons").c_str()   ,&Jet_nbHadrons   ,(name+"Jet_nbHadrons/F").c_str() );
      tree->Branch((name+"Jet_JP").c_str()          ,&Jet_JP          ,(name+"Jet_JP/F").c_str()        );
      tree->Branch((name+"Jet_JBP").c_str()         ,&Jet_JBP         ,(name+"Jet_JBP/F").c_str()       );
      tree->Branch((name+"Jet_CSV").c_str()         ,&Jet_CSV         ,(name+"Jet_CSV/F").c_str()       );
      tree->Branch((name+"Jet_CSVIVF").c_str()      ,&Jet_CSVIVF      ,(name+"Jet_CSVIVF/F").c_str()   );
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
      tree->Branch((name+"TagVarCSV_trackSip3dSig_0").c_str()          ,&TagVarCSV_trackSip3dSig_0          ,(name+"TagVarCSV_trackSip3dSig_0/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_1").c_str()          ,&TagVarCSV_trackSip3dSig_1          ,(name+"TagVarCSV_trackSip3dSig_1/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_2").c_str()          ,&TagVarCSV_trackSip3dSig_2          ,(name+"TagVarCSV_trackSip3dSig_2/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_3").c_str()          ,&TagVarCSV_trackSip3dSig_3          ,(name+"TagVarCSV_trackSip3dSig_3/F").c_str()         );
      tree->Branch((name+"TagVarCSV_trackPtRel_0").c_str()             ,&TagVarCSV_trackPtRel_0             ,(name+"TagVarCSV_trackPtRel_0/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackPtRel_1").c_str()             ,&TagVarCSV_trackPtRel_1             ,(name+"TagVarCSV_trackPtRel_1/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackPtRel_2").c_str()             ,&TagVarCSV_trackPtRel_2             ,(name+"TagVarCSV_trackPtRel_2/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackPtRel_3").c_str()             ,&TagVarCSV_trackPtRel_3             ,(name+"TagVarCSV_trackPtRel_3/F").c_str()            );
      tree->Branch((name+"TagVarCSV_trackDeltaR_0").c_str()		,&TagVarCSV_trackDeltaR_0	     ,(name+"TagVarCSV_trackDeltaR_0/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackDeltaR_1").c_str()		,&TagVarCSV_trackDeltaR_1	     ,(name+"TagVarCSV_trackDeltaR_1/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackDeltaR_2").c_str()		,&TagVarCSV_trackDeltaR_2	     ,(name+"TagVarCSV_trackDeltaR_2/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackDeltaR_3").c_str()		 ,&TagVarCSV_trackDeltaR_3	     ,(name+"TagVarCSV_trackDeltaR_3/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackPtRatio_0").c_str()		 ,&TagVarCSV_trackPtRatio_0	     ,(name+"TagVarCSV_trackPtRatio_0/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackPtRatio_1").c_str()		 ,&TagVarCSV_trackPtRatio_1	     ,(name+"TagVarCSV_trackPtRatio_1/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackPtRatio_2").c_str()		 ,&TagVarCSV_trackPtRatio_2	     ,(name+"TagVarCSV_trackPtRatio_2/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackPtRatio_3").c_str()		 ,&TagVarCSV_trackPtRatio_3	     ,(name+"TagVarCSV_trackPtRatio_3/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackJetDist_0").c_str()		 ,&TagVarCSV_trackJetDist_0	     ,(name+"TagVarCSV_trackJetDist_0/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackJetDist_1").c_str()		 ,&TagVarCSV_trackJetDist_1	     ,(name+"TagVarCSV_trackJetDist_1/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackJetDist_2").c_str()		 ,&TagVarCSV_trackJetDist_2	     ,(name+"TagVarCSV_trackJetDist_2/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackJetDist_3").c_str()		 ,&TagVarCSV_trackJetDist_3	     ,(name+"TagVarCSV_trackJetDist_3/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackDecayLenVal_0").c_str()	 ,&TagVarCSV_trackDecayLenVal_0	     ,(name+"TagVarCSV_trackDecayLenVal_0/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackDecayLenVal_1").c_str()	 ,&TagVarCSV_trackDecayLenVal_1	     ,(name+"TagVarCSV_trackDecayLenVal_1/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackDecayLenVal_2").c_str()	 ,&TagVarCSV_trackDecayLenVal_2	     ,(name+"TagVarCSV_trackDecayLenVal_2/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackDecayLenVal_3").c_str()	 ,&TagVarCSV_trackDecayLenVal_3	     ,(name+"TagVarCSV_trackDecayLenVal_3/F").c_str()        );
      tree->Branch((name+"TagVarCSV_trackEtaRel_0").c_str()            ,&TagVarCSV_trackEtaRel_0            ,(name+"TagVarCSV_trackEtaRel_0/F").c_str()           );
      tree->Branch((name+"TagVarCSV_trackEtaRel_1").c_str()            ,&TagVarCSV_trackEtaRel_1            ,(name+"TagVarCSV_trackEtaRel_1/F").c_str()           );
      tree->Branch((name+"TagVarCSV_trackEtaRel_2").c_str()            ,&TagVarCSV_trackEtaRel_2            ,(name+"TagVarCSV_trackEtaRel_2/F").c_str()           );
      tree->Branch((name+"TagVarCSV_trackEtaRel_3").c_str()            ,&TagVarCSV_trackEtaRel_3            ,(name+"TagVarCSV_trackEtaRel_3/F").c_str()           );

    }

    void ReadTree(TTree *tree, std::string name="")
    {
      if (name!="") name += ".";

      tree->SetBranchAddress((name+"Jet_pt").c_str()          ,&Jet_pt        );
      tree->SetBranchAddress((name+"Jet_genpt").c_str()          ,&Jet_genpt        );
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
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_0").c_str()          ,&TagVarCSV_trackSip3dSig_0         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_1").c_str()          ,&TagVarCSV_trackSip3dSig_1         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_2").c_str()          ,&TagVarCSV_trackSip3dSig_2         );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_3").c_str()          ,&TagVarCSV_trackSip3dSig_3         );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_0").c_str()             ,&TagVarCSV_trackPtRel_0            );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_1").c_str()             ,&TagVarCSV_trackPtRel_1            );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_2").c_str()             ,&TagVarCSV_trackPtRel_2            );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRel_3").c_str()             ,&TagVarCSV_trackPtRel_3            );
      tree->SetBranchAddress((name+"TagVarCSV_trackDeltaR_0").c_str()		 ,&TagVarCSV_trackDeltaR_0	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackDeltaR_1").c_str()		 ,&TagVarCSV_trackDeltaR_1	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackDeltaR_2").c_str()		 ,&TagVarCSV_trackDeltaR_2	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackDeltaR_3").c_str()		 ,&TagVarCSV_trackDeltaR_3	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRatio_0").c_str()		 ,&TagVarCSV_trackPtRatio_0	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRatio_1").c_str()		 ,&TagVarCSV_trackPtRatio_1	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRatio_2").c_str()		 ,&TagVarCSV_trackPtRatio_2	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackPtRatio_3").c_str()		 ,&TagVarCSV_trackPtRatio_3	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackJetDist_0").c_str()		 ,&TagVarCSV_trackJetDist_0	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackJetDist_1").c_str()		 ,&TagVarCSV_trackJetDist_1	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackJetDist_2").c_str()		 ,&TagVarCSV_trackJetDist_2	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackJetDist_3").c_str()		 ,&TagVarCSV_trackJetDist_3	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackDecayLenVal_0").c_str()	 ,&TagVarCSV_trackDecayLenVal_0	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackDecayLenVal_1").c_str()	 ,&TagVarCSV_trackDecayLenVal_1	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackDecayLenVal_2").c_str()	 ,&TagVarCSV_trackDecayLenVal_2	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackDecayLenVal_3").c_str()	 ,&TagVarCSV_trackDecayLenVal_3	     );
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_0").c_str()            ,&TagVarCSV_trackEtaRel_0           );
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_1").c_str()            ,&TagVarCSV_trackEtaRel_1           );
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_2").c_str()            ,&TagVarCSV_trackEtaRel_2           );
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_3").c_str()            ,&TagVarCSV_trackEtaRel_3           );

    }
};

#endif
