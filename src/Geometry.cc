//
// Created by idalov on 25.05.17.
//

#include <Geometry.hh>
#include <G4VisAttributes.hh>
#include <G4PVPlacement.hh>
#include <G4SolidStore.hh>
#include <G4GeometryManager.hh>
#include <Logger.hh>
#include <PartMess.hh>


Geometry::Geometry() {
    nist = G4NistManager::Instance();
    world_mat = nist->FindOrBuildMaterial("G4_AIR");
    water_mat = nist->FindOrBuildMaterial("G4_WATER");
    poly_mat = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
    det_mat = nist->FindOrBuildMaterial("G4_Galactic");
    det_pos = G4ThreeVector(60*cm,0,0);
    geoMess = new GeoMess(this);

    det_H=30;
}

Geometry::~Geometry() {
    delete geoMess;
}

G4VPhysicalVolume* Geometry::Construct() {
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();
    G4double size = 3 * m;
    G4Box *world = new G4Box("world", size / 2., size / 2., size / 2.);
    G4LogicalVolume *world_log = new G4LogicalVolume(world, world_mat, "world_log");
    world_log->SetVisAttributes(G4VisAttributes::Invisible);

    // material creation
    G4Material* BGO_std  = nist->FindOrBuildMaterial("G4_BGO");

    G4Material* stdBi  = nist->FindOrBuildMaterial("G4_Bi");
    G4Material* stdGe  = nist->FindOrBuildMaterial("G4_Ge");
    G4Material* stdO  = nist->FindOrBuildMaterial("G4_O");

    G4Material *BGO_my = new G4Material ("BGO_my", 7.1*g/cm3,3);
    BGO_my->AddMaterial(stdBi,0.21);
    BGO_my->AddMaterial(stdGe,0.15);
    BGO_my->AddMaterial(stdO,0.63);

    Logger::Info(" \n ");
    Logger::Info("  NumberOfMaterials MY %i", BGO_my->GetNumberOfMaterials());
    Logger::Info("  NumberOfMaterials STD %i", BGO_std->GetNumberOfMaterials());
    Logger::Info("  Densuty MY %g", BGO_my->GetDensity());
    Logger::Info("  Density STD %g", BGO_std->GetDensity());
    Logger::Info("  NumberOfAtomsPerVolume MY %g", BGO_my->GetTotNbOfAtomsPerVolume());
    Logger::Info("  NumberOfAtomsPerVolume STD %g \n", BGO_my->GetTotNbOfAtomsPerVolume());


    G4Tubs* water = new G4Tubs("tube",3*cm,10*cm,40/2*cm,0,360*deg);
    G4LogicalVolume * water_log = new G4LogicalVolume(water,water_mat,"water_log");
    water_log->SetVisAttributes(G4Colour::Blue());
    new G4PVPlacement(new G4RotationMatrix(0,90*deg,0),G4ThreeVector(),water_log,"water_PVP",world_log,false,0);

    G4Tubs* poly_1 = new G4Tubs("poly_1",15*cm,(15+det_H)*cm,40/2*cm,-30*deg,60*deg);
    G4LogicalVolume * poly_1_log = new G4LogicalVolume(poly_1,poly_mat,"poly_1_log");
    new G4PVPlacement(new G4RotationMatrix(0,90*deg,0),G4ThreeVector(),poly_1_log,"poly_1_PVP",world_log,false,0);

    G4Tubs* poly_2 = new G4Tubs("poly_2",16*cm,25*cm,40/2*cm,90*deg,60*deg);
    G4LogicalVolume * poly_2_log = new G4LogicalVolume(poly_2,poly_mat,"poly_2_log");
    new G4PVPlacement(new G4RotationMatrix(0,90*deg,0),G4ThreeVector(),poly_2_log,"poly_2_PVP",world_log,false,0);

    G4Tubs* poly_3 = new G4Tubs("poly_3",13*cm,15*cm,40/2*cm,210*deg,60*deg);
    G4LogicalVolume * poly_3_log = new G4LogicalVolume(poly_3,poly_mat,"poly_3_log");
    new G4PVPlacement(new G4RotationMatrix(0,90*deg,0),G4ThreeVector(),poly_3_log,"poly_3_PVP",world_log,false,0);

    G4Box* det = new G4Box("det", 76/2,40/2*cm,250/2);
    G4LogicalVolume * det_log = new G4LogicalVolume(det,det_mat,"det_log");
    det_log->SetVisAttributes(G4Colour::Red());

    new G4PVPlacement(new G4RotationMatrix(0,0,0),det_pos,det_log,"det_PVP",world_log,false,0);

    return new G4PVPlacement(0, G4ThreeVector(), world_log, "world_PVP", 0, false, 0);
}

void Geometry::SetH (G4double newH){
    det_H = newH;
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
    G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");
}