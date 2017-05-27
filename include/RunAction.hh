//
// Created by idalov on 23.05.17.
//

#ifndef TNT_RUNACTION_HH
#define TNT_RUNACTION_HH


#include <G4UserRunAction.hh>
#include <map>


class RunAction : public G4UserRunAction{
public:
    RunAction();
    G4Run* GenerateRun();
   // ~RunAct(){}
    //void BeginOfRunAction (const G4Run* aRun);
    void EndOfRunAction (const G4Run* aRun);


private:

};

#endif //TNT_RUNACTION_HH
