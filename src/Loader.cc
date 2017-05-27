//
// Created by idalov on 10.05.17.
//

#include "Loader.hh"
#include <Geometry.hh>
#include "Logger.hh"
#include <Action.hh>
#include <QGSP_BERT_HP.hh>

Loader::Loader(int argc, char **argv) {
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    CLHEP::HepRandom::setTheSeed(time(NULL));
#ifdef G4MULTITHREADED
    runManager = new G4MTRunManager;
    runManager->SetNumberOfThreads(1);//(G4Threading::G4GetNumberOfCores());

    Logger::Info("Geant4 have been run in MT mode");
    Logger::Info("Number of cores: %i",G4Threading::G4GetNumberOfCores());
#else
    Logger::Info("Geant4 have been run in non-MT mode");
    runManager = new G4RunManager;
#endif
    runManager->SetUserInitialization(new Geometry());
//    runManager->SetUserInitialization(new QBBC);
    runManager->SetUserInitialization(new QGSP_BERT_HP);
    runManager->SetUserInitialization(new Action());
    runManager->Initialize();
#ifdef G4VIS_USE
    // Initialize visualization
    visManager = new G4VisExecutive;
    visManager->Initialize();
#endif
    G4UImanager *UImanager = G4UImanager::GetUIpointer();

    if (argc != 1) {
        Logger::Info("Geant4 have been run in batch mode");
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    } else {
        Logger::Info("Geant4 have been run in interactive mode");
        // interactive mode : define UI session
#ifdef G4UI_USE
        G4UIExecutive *ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
        UImanager->ApplyCommand("/control/execute init_vis.mac");
#else
        UImanager->ApplyCommand("/control/execute init.mac");
#endif
        ui->SessionStart();
        delete ui;
#endif
    }
}

Loader::~Loader(){
    delete runManager;
}