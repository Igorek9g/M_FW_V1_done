//
// Created by idalov on 10.05.17.
//
#include <Run.hh>
#include <G4RunManager.hh>
#include <Logger.hh>
#include <RunAction.hh>
#include "EventAct.hh"
#include "G4SystemOfUnits.hh"
EventAct::EventAct() {
}

EventAct::~EventAct() {

}

void EventAct::BeginOfEventAction(const G4Event* anEvent){

    flag = 0;

    if(anEvent->GetEventID()%5000==0)
        G4cout<<"Start of Event #"<<anEvent->GetEventID()<<G4endl;

}

void EventAct::EndOfEventAction(const G4Event* anEvent) {
    Run *run = static_cast<Run *>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    run->SetNewEvent();
}






