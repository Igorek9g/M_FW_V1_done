//
// Created by idalov on 10.05.17.
//

#ifndef FINAL_PRIMARYPAT_HH
#define FINAL_PRIMARYPAT_HH

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include <fstream>
#include <map>
#include "PartMess.hh"
class PartMess;
class PrimaryPart: public G4VUserPrimaryGeneratorAction{
private:
    G4ParticleGun* gun;
    G4ThreeVector pat_m;
    PartMess* partMess;

    G4double def_H;

public:
    PrimaryPart();
    ~PrimaryPart();
    virtual void GeneratePrimaries(G4Event* anEvent);

};
#endif //FINAL_PRIMARYPAT_HH
