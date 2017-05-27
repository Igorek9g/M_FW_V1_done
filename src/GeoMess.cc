//
// Created by idalov on 26.05.17.
//


#include <GeoMess.hh>

GeoMess::GeoMess(Geometry *geometry) :detGeom(geometry){

    change_H = new G4UIcmdWithADouble (" new_commands/ch_H_detector", this);
    change_H->SetGuidance("change H of detector (tubs) ");


}

GeoMess::~GeoMess(){

}

void GeoMess::SetNewValue(G4UIcommand *cmd, G4String newValue){
    if (cmd == change_H)
        detGeom->SetH(change_H->GetNewDoubleValue(newValue));

}