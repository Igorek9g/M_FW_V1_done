//
// Created by idalov on 10.05.17.
//

#include <Action.hh>
#include <PrimaryPart.hh>
#include <Logger.hh>
#include <SteppingAction.hh>

Action::Action(){
    Logger::Info("\"General actions\" have been built");
}

Action::~Action(){
    Logger::Info("\"General actions\" have been destroyed");
}

void Action::Build()const {
    SetUserAction(new PrimaryPart);
    SetUserAction(new SteppingAction);



}