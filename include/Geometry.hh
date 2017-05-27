//
// Created by idalov on 25.05.17.
//

#ifndef BGO_AND_GAMMA_GEOMETRY_HH
#define BGO_AND_GAMMA_GEOMETRY_HH
#include <G4VUserDetectorConstruction.hh>
#include <G4Box.hh>
#include <G4NistManager.hh>
#include <G4SystemOfUnits.hh>
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "GeoMess.hh"
#include <G4Tubs.hh>
#include <G4RunManager.hh>
#include <G4UImanager.hh>

class GeoMess;

class Geometry: public G4VUserDetectorConstruction {
public:
    Geometry();
    ~Geometry();
    virtual G4VPhysicalVolume *Construct();

    void SetH (G4double newH);




private:
    G4NistManager* nist;
    G4Material* world_mat;

    G4Material* water_mat;

    G4Material* poly_mat;

    G4Material* det_mat;

    G4ThreeVector det_pos;
    GeoMess* geoMess;

    G4double det_H;

};

#endif //BGO_AND_GAMMA_GEOMETRY_HH
