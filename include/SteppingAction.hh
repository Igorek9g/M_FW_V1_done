//
// Created by idalov on 23.05.17.
//

#ifndef TNT_STEPPINGACTION_HH
#define TNT_STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class EventAct;


class SteppingAction : public G4UserSteppingAction
{
public:
//    SteppingAction(EventAct*);
    virtual ~SteppingAction(){}
    void UserSteppingAction(const G4Step*);
    int I=0,J=0;
private:
    EventAct* EvAct;
};


#endif //TNT_STEPPINGACTION_HH
