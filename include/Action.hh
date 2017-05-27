//
// Created by idalov on 10.05.17.
//

#ifndef FINAL_ACTION_HH
#define FINAL_ACTION_HH

#include <G4VUserActionInitialization.hh>



class Action: public G4VUserActionInitialization{
public:
    Action();
    ~Action();
    virtual void Build() const;


private:

};
#endif //FINAL_ACTION_HH
