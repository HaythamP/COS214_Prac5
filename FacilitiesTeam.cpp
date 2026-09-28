#include "FacilitiesTeam.h"
#include <iostream>

FacilitiesTeam::FacilitiesTeam(const std::string& sign, DispatcherMediator* med):ResponseUnit(sign, "FACILITIES", med) {}

FacilitiesTeam::~FacilitiesTeam() {}

void FacilitiesTeam::deploy(const std::string& location) {
    std::cout << "[FacilitiesTeam "<<callsign<<"] Dispatching structural & utility crew to " << location << ".\n";
}

void FacilitiesTeam::receiveInstruction(const std::string& instruction) {
    std::cout<<"[FacilitiesTeam "<< callsign << "] Order received: " << instruction <<".\n";
}