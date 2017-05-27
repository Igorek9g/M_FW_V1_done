//
// Created by idalov on 23.05.17.
//

#ifndef TNT_RUN_HH
#define TNT_RUN_HH

#include <G4Run.hh>
#include <map>

class Run: public G4Run{
public:
    Run();
    ~Run();
    void SetNewEvent(){result++;}
    //static G4int A=0;
    static int Counter ();
    static void Number (int A);

private:
    G4int result;

};

#endif //TNT_RUN_HH
