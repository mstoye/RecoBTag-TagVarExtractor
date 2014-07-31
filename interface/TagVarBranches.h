#ifndef TagVarBranches_h
#define TagVarBranches_h

#include <TTree.h>


class TagVarBranches {

  public:

    float Jet_pt;
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
    float TagVarCSV_trackSip2dSig_Leading;                // highest track 2D signed IP of tracks belonging to a given jet   
    float TagVarCSV_trackSip2dSig_SecondLeading;          // second highest track 2D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip2dSig_ThirdLeading;           // third highest track 2D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip3dSig_Leading;                // highest track 3D signed IP of tracks belonging to a given jet   
    float TagVarCSV_trackSip3dSig_SecondLeading;          // second highest track 3D signed IP of tracks belonging to a given jet
    float TagVarCSV_trackSip3dSig_ThirdLeading;           // third highest track 3D signed IP of tracks belonging to a given jet
    // per jet per etaRel track
    float TagVarCSV_trackEtaRel_Lowest;                   // lowest track eta relative to jet axis
    float TagVarCSV_trackEtaRel_SecondLowest;             // second lowest track eta relative to jet axis
    float TagVarCSV_trackEtaRel_ThirdLowest;              // third lowest track eta relative to jet axis

    void RegisterTree(TTree *tree, std::string name="")
    {
      if(name!="") name += ".";

      tree->Branch((name+"Jet_pt").c_str()          ,&Jet_pt          ,(name+"Jet_pt/F").c_str()        );
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
      tree->Branch((name+"TagVarCSV_trackSip2dSig_Leading").c_str()      ,&TagVarCSV_trackSip2dSig_Leading      ,(name+"TagVarCSV_trackSip2dSig_Leading/F").c_str()     );
      tree->Branch((name+"TagVarCSV_trackSip2dSig_SecondLeading").c_str()      ,&TagVarCSV_trackSip2dSig_SecondLeading      ,(name+"TagVarCSV_trackSip2dSig_SecondLeading/F").c_str()     );
      tree->Branch((name+"TagVarCSV_trackSip2dSig_ThirdLeading").c_str()      ,&TagVarCSV_trackSip2dSig_ThirdLeading      ,(name+"TagVarCSV_trackSip2dSig_ThirdLeading/F").c_str()     );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_Leading").c_str()      ,&TagVarCSV_trackSip3dSig_Leading      ,(name+"TagVarCSV_trackSip3dSig_Leading/F").c_str()     );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_SecondLeading").c_str()      ,&TagVarCSV_trackSip3dSig_SecondLeading      ,(name+"TagVarCSV_trackSip3dSig_SecondLeading/F").c_str()     );
      tree->Branch((name+"TagVarCSV_trackSip3dSig_ThirdLeading").c_str()      ,&TagVarCSV_trackSip3dSig_ThirdLeading      ,(name+"TagVarCSV_trackSip3dSig_ThirdLeading/F").c_str()     );
      tree->Branch((name+"TagVarCSV_trackEtaRel_Lowest").c_str()      ,&TagVarCSV_trackEtaRel_Lowest      ,(name+"TagVarCSV_trackEtaRel_Lowest/F").c_str()     );
      tree->Branch((name+"TagVarCSV_trackEtaRel_SecondLowest").c_str()      ,&TagVarCSV_trackEtaRel_SecondLowest      ,(name+"TagVarCSV_trackEtaRel_SecondLowest/F").c_str()     );
      tree->Branch((name+"TagVarCSV_trackEtaRel_ThirdLowest").c_str()      ,&TagVarCSV_trackEtaRel_ThirdLowest      ,(name+"TagVarCSV_trackEtaRel_ThirdLowest/F").c_str()     );

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
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig_Leading").c_str()    ,&TagVarCSV_trackSip2dSig_Leading   );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig_SecondLeading").c_str(),&TagVarCSV_trackSip2dSig_SecondLeading);
      tree->SetBranchAddress((name+"TagVarCSV_trackSip2dSig_ThirdLeading").c_str(),&TagVarCSV_trackSip2dSig_ThirdLeading);
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_Leading").c_str()    ,&TagVarCSV_trackSip3dSig_Leading   );
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_SecondLeading").c_str(),&TagVarCSV_trackSip3dSig_SecondLeading);
      tree->SetBranchAddress((name+"TagVarCSV_trackSip3dSig_ThirdLeading").c_str(),&TagVarCSV_trackSip3dSig_ThirdLeading);
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_Lowest").c_str(),&TagVarCSV_trackEtaRel_Lowest);
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_SecondLowest").c_str(),&TagVarCSV_trackEtaRel_SecondLowest);
      tree->SetBranchAddress((name+"TagVarCSV_trackEtaRel_ThirdLowest").c_str(),&TagVarCSV_trackEtaRel_ThirdLowest);

    }
};

#endif