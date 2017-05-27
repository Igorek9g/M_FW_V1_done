//
// Created by idalov on 23.05.17.
//

#include <RunAction.hh>
#include <Run.hh>
#include <Logger.hh>
#include <G4RunManager.hh>
#include <EventAct.hh>

RunAction::RunAction() {

}

G4Run* RunAction::GenerateRun() {
    return new Run;
}


void RunAction::EndOfRunAction(const G4Run* aRun){
    const Run* run = static_cast<const Run*>(aRun);

    G4int result;
    std::cout<<"\n\n STD number of threads = "<<"\n";




   // const  Run* run2 = static_cast<const Run*>(aRun);

//    std::cout<<"number of threads = "<<result<<"\n";


    //Logger::Info("End of Run");
}

/*int B=0;
void EventAct::Counter() {
    //int A=0;
    B++;
    //A++;
    G4cout<<"_______________Number of neutrons=____"<<B<<"\n";
}*/