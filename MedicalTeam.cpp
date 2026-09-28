#include "MedicalTeam.h"
#include <iostream>

MedicalTeam::MedicalTeam(const std::string& sign, DispatcherMediator* med):ResponseUnit(sign,"MEDICAL",med){

}

MedicalTeam::~MedicalTeam(){}

void MedicalTeam::deploy(const std::string& location){
    std::cout << "[MedicalTeam "<<callsign << "] Field ambulance deployed to "<<location<<".\n";

}

void MedicalTeam::receiveInstruction(const std::string& instruction){
    std::cout << "[MedicalTeam "<<callsign <<"] Order received: "<<instruction<<".\n";
}