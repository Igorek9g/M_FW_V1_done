//
// Created by idalov on 10.05.17.
//

#ifndef FINAL_EVENTACT_HH
#define FINAL_EVENTACT_HH

#include <G4UserEventAction.hh>
#include <pwdefs.hh>
#include <map>
#include <vector>
class EventAct: public G4UserEventAction{
public:
    EventAct();
    ~EventAct();
    void SetFlag(){flag=1;}
    void BeginOfEventAction(const G4Event* anEvent);
    void EndOfEventAction(const G4Event* anEvent);


private:
    std::vector<G4double>* EnTable;
    bool flag;
};
#endif //FINAL_EVENTACT_HH
