//
// Created by idalov on 23.05.17.
//
#include "SteppingAction.hh"
#include <EventAct.hh>
#include <G4Track.hh>
#include <Logger.hh>
#include <Run.hh>
#include <RunAction.hh>
#include "G4SystemOfUnits.hh"
/*
SteppingAction::SteppingAction(EventAct * event)
        :EvAct(event)
{}
*/

void SteppingAction::UserSteppingAction(const G4Step * aStep) {
    G4String pname = aStep->GetTrack()->GetDefinition()->GetParticleName();
    G4String volname = aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName();
    int run=1000;
    static int j=0;
   /* if(pname=="neutron"&& volname=="poly_1_log"){
        I++;
        std::cout<<"___________________|||||||||||||||||||||_______jjjj_________"<<I<<"\n";
    }
*/

    //int i=0;
    if(pname=="neutron"&& volname=="det_log"){
        j++;
        //Run::A++;
        //std::cout<<"_____|||||||||||||||||||||_________"<<j<<"\n";
        std::cout<<"otnositelnoe chislo neutronov = "<<j*100/run<<"\n";
        //G4cout<<"_____|||||||||||||||||||||_________"<<j<<"\n";
        /*Run::Number(j);
        Run::Counter();*/
        //EvAct->SetFlag();
    }





}
