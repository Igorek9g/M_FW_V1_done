//
// Created by idalov on 10.05.17.
//

#include <PrimaryPart.hh>
#include <G4Gamma.hh>
#include <G4SystemOfUnits.hh>
#include <Logger.hh>
#include <G4Neutron.hh>
#include <Randomize.hh>

PrimaryPart::PrimaryPart() {
    gun = new G4ParticleGun(1);
    gun->SetParticleDefinition(G4Neutron::NeutronDefinition());

    pat_m=G4ThreeVector(1,0, 0);
    partMess= new PartMess(this);
    Logger::Info("\"Primary particles generation actions\" have been built");
}

PrimaryPart::~PrimaryPart() {
    Logger::Info("\"Primary particles generation actions\" have been destroyed");
    delete gun;
    delete partMess;
}



void PrimaryPart::GeneratePrimaries(G4Event* anEvent) {
    gun->SetParticleEnergy(14 * MeV);
    gun->SetParticlePosition(G4ThreeVector(0,20*(2*G4UniformRand()-1)*cm, 0));
    gun->SetParticleMomentumDirection(G4ThreeVector(pat_m));
    gun->GeneratePrimaryVertex(anEvent);
}
