//
// Created by idalov on 26.05.17.
//

#ifndef M_FW_V1_DETMESS_HH
#define M_FW_V1_DETMESS_HH

#include <Geometry.hh>
#include <G4UImessenger.hh>
#include <G4UIcmdWithADoubleAndUnit.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIcmdWithADouble.hh>


class Geometry;
class GeoMess : public G4UImessenger{
public:
    GeoMess(Geometry* geometry);
    ~GeoMess();
    void SetNewValue(G4UIcommand *command, G4String newValue);
    Geometry* detGeom;


private:
    Geometry* det;
    G4UIdirectory* geom_dir;
    //G4UIdirectory* fDirectory;
    G4UIcmdWithADouble* change_H;
};
#endif //M_FW_V1_DETMESS_HH
